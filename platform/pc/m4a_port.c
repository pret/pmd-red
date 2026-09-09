// platform/pc/m4a_port.c — host port of the GBA m4a music player (part 1).
//
// The game (src/music.c, src/dungeon_music.c, ...) drives music through the
// m4a API in include/m4a.h. On GBA that API is src/m4a.c (C player logic,
// excluded from host builds) + src/m4a_1.s (ARM scheduler/mixer, excluded).
// This file reimplements both in portable C against the real song/voice data
// from build/bin/gen/audio_data.c (chunk 1). It is NOT emulation: no
// FIFO/DMA/timers/VCOUNT, no ARM. Sample rendering of the resulting channel
// state is chunk 3 (audio_pc.c reads Pc_SoundChans/Pc_CgbChans).
//
// Fidelity notes (all verified against src/m4a.c + src/m4a_1.s):
//  - same track scheduler, tempo math (tempoC += tempoI; tick while >= 150),
//    wait/gate/LFO/mod handling, status bits (IsMusicPlayerPlaying reads
//    (u16)status == 0), fade curves, and volume/pitch computation.
//  - GOTO/PATT words in the emitted streams are track-relative offsets, so
//    ply_goto/ply_patt add the track base (kept in pcTrackBasePtr).
//  - ply_voice resolves a voice-group index; invalid indices, KeySplit map
//    overruns and drum overruns are clamped/ignored (the GBA would read
//    adjacent ROM; songs never do).
//  - ply_port (direct PSG register pokes) is a noop; no song uses PORT.
//  - CgbOscOff is a noop: TrackStop already clears channel status.
//  - struct layouts may differ by host pointer width; only field access is
//    used, never raw offsets. Pc_TrackStartInit preserves cmdPtr/pattern
//    stack across the 64-byte clear exactly like the GBA (where cmdPtr sits
//    at offset 64, just past the cleared range).
#include <string.h>

#include "global.h"
#include "m4a.h"
#include "music.h"
#include "audio_data.h"
#include "m4a_port.h"

// Forward declaration (defined below; m4a.h does not declare it).
void m4aSoundMode(u32 mode);

// xcmd sub-handlers (defined below ply_xcmd).
void ply_xxx(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xtype(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xatta(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xdeca(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xsust(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xrele(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xiecv(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xiecl(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xleng(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ply_xswee(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);

// ---- engine state (host equivalents of m4a.c EWRAM/IWRAM) ----
struct MusicPlayerInfo gMPlayInfo_BGM = {0};
struct MusicPlayerInfo gMPlayInfo_Fanfare = {0};
struct MusicPlayerInfo gMPlayInfo_SE1 = {0};
struct MusicPlayerInfo gMPlayInfo_SE2 = {0};
struct MusicPlayerInfo gMPlayInfo_SE3 = {0};
struct MusicPlayerInfo gMPlayInfo_SE4 = {0};
struct MusicPlayerInfo gMPlayInfo_SE5 = {0};
struct MusicPlayerInfo gMPlayInfo_SE6 = {0};

u8 gMPlayMemAccArea[0x10] = {0};

// Declared nowhere in headers (m4a_1.s referenced it straight from the
// object); defined in src/m4a_tables.c which the host links.
extern const u8 gClockTable[];

// Track counts per player (sound/music_player_table.inc).
static struct MusicPlayerTrack pcTracks[27];
static const u32 pcTrackBase[8] = {0, 12, 18, 19, 20, 22, 24, 26};

const struct MusicPlayer gMPlayTable[MUSIC_PLAYERS_COUNT] = {
    { &gMPlayInfo_BGM, &pcTracks[0], 12, 0 },
    { &gMPlayInfo_Fanfare, &pcTracks[12], 6, 0 },
    { &gMPlayInfo_SE1, &pcTracks[18], 1, 0 },
    { &gMPlayInfo_SE2, &pcTracks[19], 1, 0 },
    { &gMPlayInfo_SE3, &pcTracks[20], 2, 0 },
    { &gMPlayInfo_SE4, &pcTracks[22], 2, 0 },
    { &gMPlayInfo_SE5, &pcTracks[24], 2, 0 },
    { &gMPlayInfo_SE6, &pcTracks[26], 1, 0 },
};

// Resolved VOICE per flat track index + track stream base for GOTO/PATT.
static const PcVoice *pcTrackVoice[27];
static const u8 *pcTrackBasePtr[27];

// Channels (rendered by chunk 3).
static struct SoundChannel pcChans[MAX_DIRECTSOUND_CHANNELS];
static struct CgbChannel pcCgb[4];

// Host sound parameters (replaces the SoundInfo fields the player needs).
static u32 pcIdent = 0;
static u8 pcReverb = 0;
static u8 pcMaxChans = 8;
static u8 pcMasterVolume = 15;
static u8 pcFreqIdx = 6;
static u16 pcSamplesPerVBlank = 304;
static s32 pcPcmFreq = 18157;
static s32 pcDivFreq = 462;

struct SoundChannel *Pc_SoundChans(unsigned *n)
{
    if (n != NULL)
        *n = MAX_DIRECTSOUND_CHANNELS;
    return pcChans;
}

struct CgbChannel *Pc_CgbChans(unsigned *n)
{
    if (n != NULL)
        *n = 4;
    return pcCgb;
}

u8 Pc_MasterVolume(void)
{
    return pcMasterVolume;
}

u16 Pc_SamplesPerVBlank(void)
{
    return pcSamplesPerVBlank;
}

u8 Pc_Reverb(void)
{
    return pcReverb;
}

u8 Pc_FreqIdx(void)
{
    return pcFreqIdx;
}

s32 Pc_PcmFreq(void)
{
    return pcPcmFreq;
}

s32 Pc_DivFreq(void)
{
    return pcDivFreq;
}

static unsigned pcSongCount = 0;

static int Pc_PlayerIndex(const struct MusicPlayerInfo *info)
{
    int i;
    for (i = 0; i < MUSIC_PLAYERS_COUNT; i++)
    {
        if (gMPlayTable[i].info == info)
            return i;
    }
    return -1;
}

static int Pc_TrackFlat(const struct MusicPlayerInfo *info,
                        const struct MusicPlayerTrack *track)
{
    int p;
    s32 d;
    p = Pc_PlayerIndex(info);
    if (p < 0)
        return -1;
    d = (s32)(track - gMPlayTable[p].track);
    if (d < 0 || d >= gMPlayTable[p].numTracks)
        return -1;
    return (int)(pcTrackBase[p] + (u32)d);
}

// Voice currently selected by a track (NULL until the first VOICE command).
const PcVoice *Pc_TrackVoice(const struct MusicPlayerInfo *info,
                             const struct MusicPlayerTrack *track)
{
    int f = Pc_TrackFlat(info, track);
    if (f < 0)
        return NULL;
    return pcTrackVoice[f];
}

// Voice behind a sounding channel (follows chan->track).
const PcVoice *Pc_ChanVoice(const struct SoundChannel *chan)
{
    int i, p;
    if (chan == NULL || chan->track == NULL)
        return NULL;
    for (p = 0; p < MUSIC_PLAYERS_COUNT; p++)
    {
        const struct MusicPlayerTrack *base = gMPlayTable[p].track;
        s32 d = (s32)(chan->track - base);
        if (d >= 0 && d < gMPlayTable[p].numTracks)
        {
            i = (int)(pcTrackBase[p] + (u32)d);
            return pcTrackVoice[i];
        }
    }
    return NULL;
}

static u32 Pc_Umul3232H32(u32 multiplier, u32 multiplicand)
{
    return (u32)(((unsigned long long)multiplier * multiplicand) >> 32);
}

// Adapted from m4a.c:MidiKeyToFreq (wav->freq in the same fixed-point units).
u32 Pc_MidiKeyToFreq(const PcWave *wav, u8 key, u8 fineAdjust)
{
    u32 val1;
    u32 val2;
    u32 fineAdjustShifted = fineAdjust << 24;
    if (key > 178)
    {
        key = 178;
        fineAdjustShifted = 255 << 24;
    }
    val1 = gScaleTable[key];
    val1 = gFreqTable[val1 & 0xF] >> (val1 >> 4);
    val2 = gScaleTable[key + 1];
    val2 = gFreqTable[val2 & 0xF] >> (val2 >> 4);
    return Pc_Umul3232H32(wav->freq, val1 + Pc_Umul3232H32(val2 - val1,
                                                          fineAdjustShifted));
}

// Adapted from m4a.c:MidiKeyToCgbFreq (chanNum 1-4 = square1/square2/wave/noise).
u32 Pc_MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust)
{
    s32 val1;
    s32 val2;
    if (chanNum == 4)
    {
        if (key <= 20)
            key = 0;
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }
        return gNoiseTable[key];
    }
    if (key <= 35)
    {
        fineAdjust = 0;
        key = 0;
    }
    else
    {
        key -= 36;
        if (key > 130)
        {
            key = 130;
            fineAdjust = 255;
        }
    }
    val1 = gCgbScaleTable[key];
    val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);
    val2 = gCgbScaleTable[key + 1];
    val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);
    return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
}

// Adapted from m4a.c:ClearModM (= clear_modM in m4a_1.s).
static void Pc_ClearModM(struct MusicPlayerTrack *track)
{
    track->lfoSpeedC = 0;
    track->modM = 0;
    if (track->modT == 0)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}

// 64-byte clear that preserves cmdPtr/patternStack (GBA: cmdPtr sits at
// offset 64, just past the cleared range).
static void Pc_Clear64byte(struct MusicPlayerTrack *track)
{
    u8 *savedPtr = track->cmdPtr;
    u8 *savedStack[3];
    savedStack[0] = track->patternStack[0];
    savedStack[1] = track->patternStack[1];
    savedStack[2] = track->patternStack[2];
    memset(track, 0, 64);
    track->cmdPtr = savedPtr;
    track->patternStack[0] = savedStack[0];
    track->patternStack[1] = savedStack[1];
    track->patternStack[2] = savedStack[2];
}

// Port of m4a_1.s:RealClearChain (unlink channel from its track).
void RealClearChain(void *x)
{
    struct SoundChannel *chan = (struct SoundChannel *)x;
    struct MusicPlayerTrack *track = chan->track;
    struct SoundChannel *next;
    struct SoundChannel *prev;
    if (track == NULL)
        return;
    next = chan->nextChannelPointer;
    prev = chan->prevChannelPointer;
    if (prev == NULL)
        track->chan = next;
    else
        prev->nextChannelPointer = next;
    if (next != NULL)
        next->prevChannelPointer = prev;
    chan->track = NULL;
}

// No-op on host: TrackStop already clears channel status, and there is no
// PSG hardware to silence (chunk 3 reads statusFlags).
static void Pc_CgbOscOff(u8 chanNum)
{
    (void)chanNum;
}

// Port of m4a_1.s:TrackStop.
void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundChannel *chan;
    (void)mplayInfo;
    if (!(track->flags & MPT_FLG_EXIST))
        return;
    chan = track->chan;
    while (chan != NULL)
    {
        struct SoundChannel *next = chan->nextChannelPointer;
        if (chan->statusFlags != 0)
        {
            if (chan->type & TONEDATA_TYPE_CGB)
                Pc_CgbOscOff(0);
            chan->statusFlags = 0;
        }
        chan->track = NULL;
        chan = next;
    }
    track->chan = NULL;
}

// Port of m4a_1.s:ChnVolSetAsm.
static void Pc_ChnVolSet(struct MusicPlayerTrack *track,
                         struct SoundChannel *chan)
{
    s32 pan = (s8)chan->rhythmPan;
    s32 right = (0x80 + pan) * chan->velocity;
    right = (track->volMR * right) >> 14;
    if (right > 0xFF)
        right = 0xFF;
    chan->rightVolume = (u8)right;
    {
        s32 left = (0x7F - pan) * chan->velocity;
        left = (track->volML * left) >> 14;
        if (left > 0xFF)
            left = 0xFF;
        chan->leftVolume = (u8)left;
    }
}

// Adapted from m4a.c:TrkVolPitSet.
void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    if (track->flags & MPT_FLG_VOLSET)
    {
        s32 x;
        s32 y;
        x = (u32)(track->vol * track->volX) >> 5;
        if (track->modT == 1)
            x = (u32)(x * (track->modM + 128)) >> 7;
        y = 2 * track->pan + track->panX;
        if (track->modT == 2)
            y += track->modM;
        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;
        track->volMR = (u32)((y + 128) * x) >> 8;
        track->volML = (u32)((127 - y) * x) >> 8;
    }
    if (track->flags & MPT_FLG_PITSET)
    {
        s32 bend = track->bend * track->bendRange;
        s32 x = (track->tune + bend)
              * 4
              + (track->keyShift << 8)
              + (track->keyShiftX << 8)
              + track->pitX;
        if (track->modT == 0)
            x += 16 * track->modM;
        track->keyM = x >> 8;
        track->pitM = x;
    }
    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

// Adapted from m4a.c:FadeOutBody.
void FadeOutBody(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u16 fadeOV;
    if (mplayInfo->fadeOI == 0)
        return;
    if (--mplayInfo->fadeOC != 0)
        return;
    mplayInfo->fadeOC = mplayInfo->fadeOI;
    if (mplayInfo->fadeOV & FADE_IN)
    {
        if ((u16)(mplayInfo->fadeOV += (4 << FADE_VOL_SHIFT)) >= (64 << FADE_VOL_SHIFT))
        {
            mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
            mplayInfo->fadeOI = 0;
        }
    }
    else
    {
        if ((s16)(mplayInfo->fadeOV -= (4 << FADE_VOL_SHIFT)) <= 0)
        {
            i = mplayInfo->trackCount;
            track = mplayInfo->tracks;
            while (i > 0)
            {
                u32 val;
                TrackStop(mplayInfo, track);
                val = TEMPORARY_FADE;
                fadeOV = mplayInfo->fadeOV;
                val &= fadeOV;
                if (!val)
                    track->flags = 0;
                i--;
                track++;
            }
            if (mplayInfo->fadeOV & TEMPORARY_FADE)
                mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;
            mplayInfo->fadeOI = 0;
            return;
        }
    }
    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    while (i > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            fadeOV = mplayInfo->fadeOV;
            track->volX = (fadeOV >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }
        i--;
        track++;
    }
}

// ---- track command handlers (ported from m4a_1.s / m4a.c) ----

static u8 Pc_NextByte(struct MusicPlayerTrack *track)
{
    u8 b = *track->cmdPtr;
    track->cmdPtr++;
    return b;
}

// Track stream base for GOTO/PATT (emitted words are track-relative).
static const u8 *Pc_TrackBasePtr(const struct MusicPlayerInfo *info,
                                 const struct MusicPlayerTrack *track)
{
    int f = Pc_TrackFlat(info, track);
    if (f < 0)
        return track->cmdPtr;
    return pcTrackBasePtr[f];
}

// Port of m4a_1.s:ply_fine.
void ply_fine(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundChannel *chan = track->chan;
    (void)mplayInfo;
    while (chan != NULL)
    {
        struct SoundChannel *next = chan->nextChannelPointer;
        if (chan->statusFlags & SOUND_CHANNEL_SF_ON)
            chan->statusFlags |= SOUND_CHANNEL_SF_STOP;
        RealClearChain(chan);
        chan = next;
    }
    track->flags = 0;
}

// Port of m4a_1.s:ply_goto (word = track-relative offset on host).
void ply_goto(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    const u8 *base = Pc_TrackBasePtr(mplayInfo, track);
    const u8 *p = track->cmdPtr;
    u32 off = (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
    track->cmdPtr = (u8 *)(base + off);
}

// Port of m4a_1.s:ply_patt (pattern call; level >= 3 ends the track).
void ply_patt(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    if (track->patternLevel >= 3)
    {
        ply_fine(mplayInfo, track);
        return;
    }
    track->patternStack[track->patternLevel] = track->cmdPtr + 4;
    track->patternLevel++;
    ply_goto(mplayInfo, track);
}

// Port of m4a_1.s:ply_pend (pattern return).
void ply_pend(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    if (track->patternLevel == 0)
        return;
    track->patternLevel--;
    track->cmdPtr = track->patternStack[track->patternLevel];
}

// Port of m4a_1.s:ply_rept (no song uses REPT; kept literal).
void ply_rept(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 count = *track->cmdPtr;
    if (count == 0)
    {
        track->cmdPtr++;
        ply_goto(mplayInfo, track);
        return;
    }
    track->repN++;
    if (track->repN >= *track->cmdPtr)
    {
        track->repN = 0;
        track->cmdPtr += 5;
        return;
    }
    track->cmdPtr++;
    ply_goto(mplayInfo, track);
}

// Port of m4a_1.s:ply_prio.
void ply_prio(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->priority = Pc_NextByte(track);
}

// Port of m4a_1.s:ply_tempo (arg = BPM/2; see MPlayMain for the 150-tick clock).
void ply_tempo(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 arg = Pc_NextByte(track);
    (void)mplayInfo;
    arg <<= 1;
    mplayInfo->tempoD = (u16)arg;
    mplayInfo->tempoI = (u16)((arg * mplayInfo->tempoU) >> 8);
}

// Port of m4a_1.s:ply_keysh.
void ply_keysh(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->keyShift = (s8)Pc_NextByte(track);
    track->flags |= 0x0C;
}

// Resolve a VOICE number to a voice definition (NULL when out of range).
static const PcVoice *Pc_ResolveVoice(struct MusicPlayerInfo *info, u8 n)
{
    const PcSong *song = Pc_SongHeader(info->songHeader);
    unsigned int ngroups;
    const PcVoiceGroup *groups;
    if (song == NULL)
        return NULL;
    groups = Pc_VoiceGroups(&ngroups);
    if (song->toneBank >= ngroups)
        return NULL;
    if (n >= groups[song->toneBank].count)
        return NULL;
    return &groups[song->toneBank].voices[n];
}

// Port of m4a_1.s:ply_voice (copies tone scalars; keeps the PcVoice link).
void ply_voice(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 n = Pc_NextByte(track);
    const PcVoice *v = Pc_ResolveVoice(mplayInfo, n);
    int f;
    if (v == NULL)
        return;
    track->tone.type = v->type;
    track->tone.key = v->key;
    track->tone.length = v->p2;
    track->tone.pan_sweep = v->p3;
    track->tone.wav = NULL;
    track->tone.attack = v->attack;
    track->tone.decay = v->decay;
    track->tone.sustain = v->sustain;
    track->tone.release = v->release;
    f = Pc_TrackFlat(mplayInfo, track);
    if (f >= 0)
        pcTrackVoice[f] = v;
}

// Port of m4a_1.s:ply_vol.
void ply_vol(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->vol = Pc_NextByte(track);
    track->flags |= MPT_FLG_VOLCHG;
}

// Port of m4a_1.s:ply_pan (arg is center-relative, C_V = 0x40).
void ply_pan(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->pan = (s8)(Pc_NextByte(track) - C_V);
    track->flags |= MPT_FLG_VOLCHG;
}

// Port of m4a_1.s:ply_bend.
void ply_bend(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->bend = (s8)(Pc_NextByte(track) - C_V);
    track->flags |= MPT_FLG_PITCHG;
}

// Port of m4a_1.s:ply_bendr.
void ply_bendr(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->bendRange = Pc_NextByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

// Port of m4a_1.s:ply_lfos.
void ply_lfos(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->lfoSpeed = Pc_NextByte(track);
    if (track->lfoSpeed == 0)
        Pc_ClearModM(track);
}

// Port of m4a_1.s:ply_lfodl.
void ply_lfodl(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->lfoDelay = Pc_NextByte(track);
}

// Port of m4a_1.s:ply_mod.
void ply_mod(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->mod = Pc_NextByte(track);
    if (track->mod == 0)
        Pc_ClearModM(track);
}

// Port of m4a_1.s:ply_modt.
void ply_modt(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 v = Pc_NextByte(track);
    (void)mplayInfo;
    if (track->modT != v)
    {
        track->modT = v;
        track->flags |= MPT_FLG_VOLCHG | MPT_FLG_PITCHG;
    }
}

// Port of m4a_1.s:ply_tune.
void ply_tune(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tune = (s8)(Pc_NextByte(track) - C_V);
    track->flags |= MPT_FLG_PITCHG;
}

// No host equivalent: direct PSG register pokes. No song uses PORT.
void ply_port(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    (void)track;
}

// Port of m4a_1.s:ply_endtie (stop this track's channel playing the key).
void ply_endtie(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 key;
    struct SoundChannel *chan;
    (void)mplayInfo;
    if (*track->cmdPtr < 0x80)
        key = Pc_NextByte(track);
    else
        key = track->key;
    chan = track->chan;
    while (chan != NULL)
    {
        u8 flags = chan->statusFlags;
        if ((flags & (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_ENV)) != 0
            && !(flags & SOUND_CHANNEL_SF_STOP)
            && chan->midiKey == key)
        {
            chan->statusFlags = flags | SOUND_CHANNEL_SF_STOP;
            break;
        }
        chan = chan->nextChannelPointer;
    }
}

// Adapted from m4a.c:ply_memacc (cond_true dispatches to ply_goto).
void ply_memacc(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 op = Pc_NextByte(track);
    u8 *addr = &gMPlayMemAccArea[Pc_NextByte(track) & 0x0F];
    u8 data = Pc_NextByte(track);
    switch (op)
    {
    case 0: *addr = data; return;
    case 1: *addr += data; return;
    case 2: *addr -= data; return;
    case 3: *addr = gMPlayMemAccArea[data]; return;
    case 4: *addr += gMPlayMemAccArea[data]; return;
    case 5: *addr -= gMPlayMemAccArea[data]; return;
    case 6: if (*addr == data) goto cond_true; goto cond_false;
    case 7: if (*addr != data) goto cond_true; goto cond_false;
    case 8: if (*addr > data) goto cond_true; goto cond_false;
    case 9: if (*addr >= data) goto cond_true; goto cond_false;
    case 10: if (*addr <= data) goto cond_true; goto cond_false;
    case 11: if (*addr < data) goto cond_true; goto cond_false;
    case 12: if (*addr == gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    case 13: if (*addr != gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    case 14: if (*addr > gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    case 15: if (*addr >= gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    case 16: if (*addr <= gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    case 17: if (*addr < gMPlayMemAccArea[data]) goto cond_true; goto cond_false;
    default: return;
    }
cond_true:
    ply_goto(mplayInfo, track);
    return;
cond_false:
    track->cmdPtr += 4;
}

// No song uses XCMD; handlers still update state faithfully.
void ply_xcmd(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 n = Pc_NextByte(track);
    switch (n)
    {
    case 0:
    case 3: ply_xxx(mplayInfo, track); break;
    case 1: ply_xwave(mplayInfo, track); break;
    case 2: ply_xtype(mplayInfo, track); break;
    case 4: ply_xatta(mplayInfo, track); break;
    case 5: ply_xdeca(mplayInfo, track); break;
    case 6: ply_xsust(mplayInfo, track); break;
    case 7: ply_xrele(mplayInfo, track); break;
    case 8: ply_xiecv(mplayInfo, track); break;
    case 9: ply_xiecl(mplayInfo, track); break;
    case 10: ply_xleng(mplayInfo, track); break;
    case 11: ply_xswee(mplayInfo, track); break;
    default: break;
    }
}

void ply_xxx(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    ply_fine(mplayInfo, track);
}

void ply_xwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.wav = NULL;
    track->cmdPtr += 4;
}

void ply_xtype(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.type = Pc_NextByte(track);
}

void ply_xatta(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.attack = Pc_NextByte(track);
}

void ply_xdeca(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.decay = Pc_NextByte(track);
}

void ply_xsust(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.sustain = Pc_NextByte(track);
}

void ply_xrele(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.release = Pc_NextByte(track);
}

void ply_xiecv(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->pseudoEchoVolume = Pc_NextByte(track);
}

void ply_xiecl(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->pseudoEchoLength = Pc_NextByte(track);
}

void ply_xleng(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.length = Pc_NextByte(track);
}

void ply_xswee(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo;
    track->tone.pan_sweep = Pc_NextByte(track);
}

// Per-channel voice reference for the chunk-3 renderer (flat: 0-11 DS,
// 12-15 CGB). Set at note-on from the resolved sub-voice.
u8 gPcChanRefKind[16];
u16 gPcChanRefA[16];

static int Pc_ChanFlat(struct SoundChannel *chan)
{
    s32 d = (s32)(chan - pcChans);
    if (d >= 0 && d < MAX_DIRECTSOUND_CHANNELS)
        return (int)d;
    {
        s32 e = (s32)((struct CgbChannel *)chan - pcCgb);
        if (e >= 0 && e < 4)
            return 12 + (int)e;
    }
    return -1;
}

// Port of m4a_1.s:ply_note (note on: voice resolve, channel alloc, setup).
void ply_note(u32 note_cmd, struct MusicPlayerInfo *info,
              struct MusicPlayerTrack *track)
{
    u8 b;
    const PcVoice *v;
    const PcVoice *sub;
    u8 midiKey;
    s8 rhythmPan = 0;
    u8 prio;
    unsigned int sum;
    int isCgb;
    struct SoundChannel *chan = NULL;
    const PcWave *waves;
    unsigned int nwaves;
    const PcVoiceGroup *groups;
    unsigned int ngroups;
    const PcKeyMap *maps;
    unsigned int nmaps;
    unsigned int keyIdx;

    track->gateTime = gClockTable[note_cmd];
    b = *track->cmdPtr;
    if (b < 0x80)
    {
        track->key = b;
        track->cmdPtr++;
        b = *track->cmdPtr;
        if (b < 0x80)
        {
            track->velocity = b;
            track->cmdPtr++;
            b = *track->cmdPtr;
            if (b < 0x80)
            {
                track->gateTime += b;
                track->cmdPtr++;
            }
        }
    }

    // Resolve the sounding sub-voice (KeySplit map / drum bank / direct).
    v = Pc_TrackVoice(info, track);
    if (v == NULL)
        return;
    if ((track->tone.type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL)) != 0)
    {
        if (v->refKind == PC_VOICE_KEYMAP)
        {
            maps = Pc_KeyMaps(&nmaps);
            if (v->refB >= nmaps || maps[v->refB].length == 0)
                return;
            keyIdx = track->key;
            if (keyIdx >= maps[v->refB].length)
                keyIdx = maps[v->refB].length - 1;
            keyIdx = maps[v->refB].keys[keyIdx];
        }
        else if (v->refKind == PC_VOICE_DRUMS)
        {
            keyIdx = track->key;
        }
        else
        {
            return;
        }
        groups = Pc_VoiceGroups(&ngroups);
        if (v->refA >= ngroups)
            return;
        if (keyIdx >= groups[v->refA].count)
            return;
        sub = &groups[v->refA].voices[keyIdx];
        if (sub->type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL))
            return;
        midiKey = track->key;
        if (track->tone.type & TONEDATA_TYPE_RHY)
        {
            u8 ps = sub->p3;
            if (ps & 0x80)
                rhythmPan = (s8)((ps - TONEDATA_P_S_PAN) * 2);
        }
    }
    else
    {
        sub = v;
        midiKey = track->key;
    }

    sum = (unsigned int)info->priority + track->priority;
    prio = (sum > 0xFF) ? 0xFF : (u8)sum;
    isCgb = (sub->type & TONEDATA_TYPE_CGB) != 0;

    if (isCgb)
    {
        struct CgbChannel *cch = &pcCgb[(sub->type & 7) - 1];
        if (cch->statusFlags & SOUND_CHANNEL_SF_ON)
        {
            if (cch->statusFlags & SOUND_CHANNEL_SF_STOP)
            {
                chan = (struct SoundChannel *)cch;
            }
            else if (cch->priority < prio)
            {
                chan = (struct SoundChannel *)cch;
            }
            else if (cch->priority == prio)
            {
                if (cch->track >= track)
                    chan = (struct SoundChannel *)cch;
                else
                    return;
            }
            else
            {
                return;
            }
        }
        else
        {
            chan = (struct SoundChannel *)cch;
        }
    }
    else
    {
        unsigned int ci;
        unsigned int lim;
        struct SoundChannel *victim = NULL;
        u8 bestPrio = prio;
        struct MusicPlayerTrack *bestTrack = track;
        int foundStopped = 0;
        if (sub->refKind != PC_VOICE_WAVE)
            return;
        waves = Pc_Waves(&nwaves);
        if (sub->refA >= nwaves)
            return;
        lim = pcMaxChans;
        if (lim > MAX_DIRECTSOUND_CHANNELS)
            lim = MAX_DIRECTSOUND_CHANNELS;
        for (ci = 0; ci < lim; ci++)
        {
            struct SoundChannel *ch = &pcChans[ci];
            if (!(ch->statusFlags & SOUND_CHANNEL_SF_ON))
            {
                victim = ch;
                break;
            }
            if (ch->statusFlags & SOUND_CHANNEL_SF_STOP)
            {
                if (!foundStopped)
                {
                    foundStopped = 1;
                    bestPrio = ch->priority;
                    bestTrack = ch->track;
                }
            }
            else if (foundStopped)
            {
                continue;
            }
            if (ch->priority < bestPrio)
            {
                bestPrio = ch->priority;
                bestTrack = ch->track;
                victim = ch;
            }
            else if (ch->priority == bestPrio)
            {
                if (ch->track > bestTrack)
                {
                    bestTrack = ch->track;
                    victim = ch;
                }
                else if (ch->track == bestTrack)
                {
                    victim = ch;
                }
            }
        }
        chan = victim;
        if (chan == NULL)
            return;
    }

    // Link at the head of this track's channel list.
    RealClearChain(chan);
    chan->prevChannelPointer = NULL;
    chan->nextChannelPointer = track->chan;
    if (track->chan != NULL)
        track->chan->prevChannelPointer = chan;
    track->chan = chan;
    chan->track = track;
    track->lfoDelayC = track->lfoDelay;
    if (track->lfoDelay != 0)
        Pc_ClearModM(track);
    TrkVolPitSet(info, track);
    chan->gateTime = track->gateTime;
    chan->priority = prio;
    chan->key = midiKey;
    chan->midiKey = midiKey;
    chan->velocity = track->velocity;
    chan->rhythmPan = (u8)rhythmPan;
    chan->type = sub->type;
    chan->attack = sub->attack;
    chan->decay = sub->decay;
    chan->sustain = sub->sustain;
    chan->release = sub->release;
    chan->echoVolume = track->pseudoEchoVolume;
    chan->echoLength = track->pseudoEchoLength;
    Pc_ChnVolSet(track, chan);
    {
        int flat = Pc_ChanFlat(chan);
        if (flat >= 0)
        {
            gPcChanRefKind[flat] = sub->refKind;
            gPcChanRefA[flat] = sub->refA;
        }
    }
    if (isCgb)
    {
        struct CgbChannel *cch = (struct CgbChannel *)chan;
        u8 ps = sub->p3;
        int k = (int)midiKey + (s8)track->keyM;
        cch->length = sub->p2;
        if (ps & 0x80)
            cch->sweep = 8;
        else if (ps & 0x70)
            cch->sweep = ps;
        else
            cch->sweep = 8;
        if (k < 0)
            k = 0;
        cch->frequency = Pc_MidiKeyToCgbFreq((u8)(sub->type & 7), (u8)k,
                                             track->pitM);
    }
    else
    {
        int k = (int)midiKey + (s8)track->keyM;
        waves = Pc_Waves(&nwaves);
        if (k < 0)
            k = 0;
        chan->frequency = Pc_MidiKeyToFreq(&waves[sub->refA], (u8)k,
                                           track->pitM);
    }
    chan->statusFlags = SOUND_CHANNEL_SF_START;
    track->flags &= 0xF0;
}

// Track init on MPT_FLG_START (m4a_1.s:MPlayMain; preserves cmdPtr/stack).
static void Pc_TrackStartInit(struct MusicPlayerTrack *track)
{
    Pc_Clear64byte(track);
    track->flags = MPT_FLG_EXIST;
    track->bendRange = 2;
    track->volX = 0x40;
    track->lfoSpeed = 0x16;
    track->tone.type = 1;
}

// Command dispatch (live jump-table mapping after MPlayExtender's patches:
// slot 8 = memacc, 28 = xcmd, 29 = endtie).
static void Pc_DispatchCmd(struct MusicPlayerInfo *info,
                           struct MusicPlayerTrack *track, u8 cmd)
{
    switch (cmd)
    {
    case 0: ply_fine(info, track); break;
    case 1: ply_goto(info, track); break;
    case 2: ply_patt(info, track); break;
    case 3: ply_pend(info, track); break;
    case 4: ply_rept(info, track); break;
    case 5:
    case 6:
    case 7: ply_fine(info, track); break;
    case 8: ply_memacc(info, track); break;
    case 9: ply_prio(info, track); break;
    case 10: ply_tempo(info, track); break;
    case 11: ply_keysh(info, track); break;
    case 12: ply_voice(info, track); break;
    case 13: ply_vol(info, track); break;
    case 14: ply_pan(info, track); break;
    case 15: ply_bend(info, track); break;
    case 16: ply_bendr(info, track); break;
    case 17: ply_lfos(info, track); break;
    case 18: ply_lfodl(info, track); break;
    case 19: ply_mod(info, track); break;
    case 20: ply_modt(info, track); break;
    case 21:
    case 22: ply_fine(info, track); break;
    case 23: ply_tune(info, track); break;
    case 24:
    case 25:
    case 26: ply_fine(info, track); break;
    case 27: ply_port(info, track); break;
    case 28: ply_xcmd(info, track); break;
    case 29: ply_endtie(info, track); break;
    default: ply_fine(info, track); break;
    }
}

// One scheduler tick over a player's tracks (m4a_1.s:MPlayMain core).
static void Pc_TickTracks(struct MusicPlayerInfo *info)
{
    u32 active = 0;
    u32 bit = 1;
    u8 n;
    struct MusicPlayerTrack *track = info->tracks;
    for (n = 0; n < info->trackCount; n++, track++, bit <<= 1)
    {
        u8 cmd;
        struct SoundChannel *chan;
        if (!(track->flags & MPT_FLG_EXIST))
            continue;
        active |= bit;
        chan = track->chan;
        while (chan != NULL)
        {
            struct SoundChannel *next = chan->nextChannelPointer;
            if (chan->statusFlags & SOUND_CHANNEL_SF_ON)
            {
                if (chan->gateTime != 0)
                {
                    chan->gateTime--;
                    if (chan->gateTime == 0)
                        chan->statusFlags |= SOUND_CHANNEL_SF_STOP;
                }
            }
            else
            {
                RealClearChain(chan);
            }
            chan = next;
        }
        if (track->flags & MPT_FLG_START)
            Pc_TrackStartInit(track);
        for (;;)
        {
            if (*track->cmdPtr < 0x80)
            {
                cmd = track->runningStatus;
            }
            else
            {
                cmd = *track->cmdPtr;
                track->cmdPtr++;
                if (cmd >= 0xBD)
                    track->runningStatus = cmd;
            }
            if (cmd >= 0xCF)
            {
                ply_note((u32)(cmd - 0xCF), info, track);
                goto waitcheck;
            }
            if (cmd > 0xB0)
            {
                info->cmd = (u8)(cmd - 0xB1);
                Pc_DispatchCmd(info, track, info->cmd);
                if (track->flags == 0)
                    goto next_track;
                continue;
            }
            track->wait = gClockTable[cmd - 0x80];
        waitcheck:
            if (track->wait == 0)
                continue;
            track->wait--;
            break;
        }
        if (track->lfoSpeed != 0 && track->mod != 0)
        {
            if (track->lfoDelayC != 0)
            {
                track->lfoDelayC--;
            }
            else
            {
                unsigned int sumFull = (unsigned int)track->lfoSpeedC
                                     + track->lfoSpeed;
                s32 tri;
                s32 m;
                track->lfoSpeedC = (u8)sumFull;
                if (((sumFull - 0x40) & 0xFF) < 0x80)
                    tri = 0x80 - (s32)sumFull;
                else
                    tri = (s32)(s8)sumFull;
                m = (track->mod * tri) >> 6;
                if (((m ^ track->modM) & 0xFF) != 0)
                {
                    track->modM = (s8)m;
                    if (track->modT == 0)
                        track->flags |= MPT_FLG_PITCHG;
                    else
                        track->flags |= MPT_FLG_VOLCHG;
                }
            }
        }
    next_track:;
    }
    info->clock++;
    if (active != 0)
        info->status = active;
    else
        info->status = (u32)0x80000000;
}

// Volume/pitch refresh pass (runs every MPlayMain call, even with 0 ticks).
static void Pc_VolPitPass(struct MusicPlayerInfo *info)
{
    u8 remaining = info->trackCount;
    struct MusicPlayerTrack *track = info->tracks;
    while (remaining > 0)
    {
        if ((track->flags & MPT_FLG_EXIST) != 0
            && (track->flags & (MPT_FLG_VOLCHG | MPT_FLG_PITCHG)) != 0)
        {
            struct SoundChannel *chan;
            TrkVolPitSet(info, track);
            chan = track->chan;
            while (chan != NULL)
            {
                struct SoundChannel *next = chan->nextChannelPointer;
                if (!(chan->statusFlags & SOUND_CHANNEL_SF_ON))
                {
                    RealClearChain(chan);
                }
                else
                {
                    int cgb = (chan->type & TONEDATA_TYPE_CGB) != 0;
                    if (track->flags & MPT_FLG_VOLCHG)
                    {
                        Pc_ChnVolSet(track, chan);
                        if (cgb)
                            ((struct CgbChannel *)chan)->modify |=
                                CGB_CHANNEL_MO_VOL;
                    }
                    if (track->flags & MPT_FLG_PITCHG)
                    {
                        int k = (int)chan->key + (s8)track->keyM;
                        if (k < 0)
                            k = 0;
                        if (cgb)
                        {
                            struct CgbChannel *cch = (struct CgbChannel *)chan;
                            cch->frequency = Pc_MidiKeyToCgbFreq(
                                chan->type & 7, (u8)k, track->pitM);
                            cch->modify |= CGB_CHANNEL_MO_PIT;
                        }
                        else
                        {
                            int flat = Pc_ChanFlat(chan);
                            const PcWave *waves;
                            unsigned int nw;
                            waves = Pc_Waves(&nw);
                            if (flat >= 0 && flat < 12
                                && gPcChanRefKind[flat] == PC_VOICE_WAVE
                                && gPcChanRefA[flat] < nw)
                            {
                                chan->frequency = Pc_MidiKeyToFreq(
                                    &waves[gPcChanRefA[flat]], (u8)k,
                                    track->pitM);
                            }
                        }
                    }
                }
                chan = next;
            }
            track->flags &= 0xF0;
        }
        remaining--;
        track++;
    }
}

// Port of m4a_1.s:MPlayMain (one player's scheduler step).
void MPlayMain(struct MusicPlayerInfo *info)
{
    if (info->ident != ID_NUMBER)
        return;
    info->ident++;
    if ((s32)info->status < 0)
    {
        info->ident = ID_NUMBER;
        return;
    }
    FadeOutBody(info);
    if ((s32)info->status < 0)
    {
        info->ident = ID_NUMBER;
        return;
    }
    info->tempoC = (u16)(info->tempoC + info->tempoI);
    while (info->tempoC >= 150)
    {
        Pc_TickTracks(info);
        info->tempoC = (u16)(info->tempoC - 150);
    }
    Pc_VolPitPass(info);
    info->ident = ID_NUMBER;
}

// Advance all players one 60 Hz frame (host SoundMain minus the mixer).
void Pc_AudioTick(void)
{
    int i;
    if (pcIdent != ID_NUMBER)
        return;
    pcIdent++;
    for (i = 0; i < MUSIC_PLAYERS_COUNT; i++)
        MPlayMain(gMPlayTable[i].info);
    pcIdent = ID_NUMBER;
}

// ---- player open/start/stop (adapted from m4a.c) ----

void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks,
               u8 trackCount)
{
    if (trackCount == 0)
        return;
    if (trackCount > MAX_MUSICPLAYER_TRACKS)
        trackCount = MAX_MUSICPLAYER_TRACKS;
    if (pcIdent != ID_NUMBER)
        return;
    pcIdent++;
    memset(mplayInfo, 0, sizeof(*mplayInfo));
    mplayInfo->tracks = tracks;
    mplayInfo->trackCount = trackCount;
    mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;
    while (trackCount != 0)
    {
        tracks->flags = 0;
        trackCount--;
        tracks++;
    }
    pcIdent = ID_NUMBER;
    mplayInfo->ident = ID_NUMBER;
}

void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader)
{
    s32 i;
    u8 unk_B;
    struct MusicPlayerTrack *track;
    const PcSong *song = Pc_SongHeader(songHeader);
    int p;
    if (mplayInfo->ident != ID_NUMBER)
        return;
    if (song == NULL)
        return;
    unk_B = mplayInfo->unk_B;
    if (!unk_B
        || ((!mplayInfo->songHeader || !(mplayInfo->tracks[0].flags & MPT_FLG_START))
            && ((mplayInfo->status & MUSICPLAYER_STATUS_TRACK) == 0
                || (mplayInfo->status & MUSICPLAYER_STATUS_PAUSE)))
        || (mplayInfo->priority <= song->priority))
    {
        mplayInfo->ident++;
        mplayInfo->status = 0;
        mplayInfo->songHeader = songHeader;
        mplayInfo->priority = song->priority;
        mplayInfo->clock = 0;
        mplayInfo->tempoD = 150;
        mplayInfo->tempoI = 150;
        mplayInfo->tempoU = 0x100;
        mplayInfo->tempoC = 0;
        mplayInfo->fadeOI = 0;
        p = Pc_PlayerIndex(mplayInfo);
        if (p >= 0)
        {
            u8 t;
            for (t = 0; t < mplayInfo->trackCount; t++)
                pcTrackVoice[pcTrackBase[p] + t] = NULL;
        }
        i = 0;
        track = mplayInfo->tracks;
        while (i < song->trackCount && i < mplayInfo->trackCount)
        {
            TrackStop(mplayInfo, track);
            track->flags = MPT_FLG_EXIST | MPT_FLG_START;
            track->chan = 0;
            track->cmdPtr = (u8 *)song->parts[i];
            if (p >= 0)
                pcTrackBasePtr[pcTrackBase[p] + i] = song->parts[i];
            i++;
            track++;
        }
        while (i < mplayInfo->trackCount)
        {
            TrackStop(mplayInfo, track);
            track->flags = 0;
            i++;
            track++;
        }
        if (song->reverb & SOUND_MODE_REVERB_SET)
            m4aSoundMode(song->reverb);
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;
    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident++;
    mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;
    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    while (i > 0)
    {
        TrackStop(mplayInfo, track);
        i--;
        track++;
    }
    mplayInfo->ident = ID_NUMBER;
}

void MPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    MPlayContinue(mplayInfo);
}

void m4aMPlayAllStop(void)
{
    s32 i;
    for (i = 0; i < MUSIC_PLAYERS_COUNT; i++)
        m4aMPlayStop(gMPlayTable[i].info);
}

void m4aMPlayAllContinue(void)
{
    s32 i;
    for (i = 0; i < MUSIC_PLAYERS_COUNT; i++)
        MPlayContinue(gMPlayTable[i].info);
}

void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    MPlayFadeOut(mplayInfo, speed);
}

void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (0 << FADE_VOL_SHIFT) | FADE_IN;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount = mplayInfo->trackCount;
    struct MusicPlayerTrack *track = mplayInfo->tracks;
    while (trackCount > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                Pc_Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }
        }
        trackCount--;
        track++;
    }
}

void m4aMPlayVolumeControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits,
                           u16 volume)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;
    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident++;
    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;
    while (i > 0)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->volX = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    mplayInfo->ident = ID_NUMBER;
}

// ---- sound init/mode/vsync (adapted from m4a.c; no hardware) ----

void SampleFreqSet(u32 freq)
{
    freq = (freq & SOUND_MODE_FREQ) >> SOUND_MODE_FREQ_SHIFT;
    pcFreqIdx = (u8)freq;
    pcSamplesPerVBlank = gPcmSamplesPerVBlankTable[freq - 1];
    pcPcmFreq = (597275 * pcSamplesPerVBlank + 5000) / 10000;
    pcDivFreq = (16777216 / pcPcmFreq + 1) >> 1;
    m4aSoundVSyncOn();
}

void m4aSoundMode(u32 mode)
{
    u32 temp;
    if (pcIdent != ID_NUMBER)
        return;
    pcIdent++;
    temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL);
    if (temp)
        pcReverb = temp & SOUND_MODE_REVERB_VAL;
    temp = mode & SOUND_MODE_MAXCHN;
    if (temp)
    {
        s32 n = MAX_DIRECTSOUND_CHANNELS;
        struct SoundChannel *chan = pcChans;
        pcMaxChans = temp >> SOUND_MODE_MAXCHN_SHIFT;
        while (n != 0)
        {
            chan->statusFlags = 0;
            n--;
            chan++;
        }
    }
    temp = mode & SOUND_MODE_MASVOL;
    if (temp)
        pcMasterVolume = temp >> SOUND_MODE_MASVOL_SHIFT;
    temp = mode & SOUND_MODE_FREQ;
    if (temp)
    {
        m4aSoundVSyncOff();
        SampleFreqSet(temp);
    }
    pcIdent = ID_NUMBER;
}

void m4aSoundVSyncOff(void)
{
    if (pcIdent >= ID_NUMBER && pcIdent <= ID_NUMBER + 1)
        pcIdent += 10;
}

void m4aSoundVSyncOn(void)
{
    u32 ident = pcIdent;
    if (ident == ID_NUMBER)
        return;
    pcIdent = ident - 10;
}

// Per-frame DMA feed on GBA; nothing to do on host (the tick renders).
void m4aSoundVSync(void)
{
}

static void Pc_SoundInit(void)
{
    int i;
    pcIdent = 0;
    for (i = 0; i < MAX_DIRECTSOUND_CHANNELS; i++)
    {
        memset(&pcChans[i], 0, sizeof(pcChans[i]));
        gPcChanRefKind[i] = 0;
        gPcChanRefA[i] = 0;
    }
    for (i = 0; i < 4; i++)
    {
        memset(&pcCgb[i], 0, sizeof(pcCgb[i]));
        gPcChanRefKind[12 + i] = 0;
        gPcChanRefA[12 + i] = 0;
    }
    pcCgb[0].type = 1;
    pcCgb[0].panMask = 0x11;
    pcCgb[1].type = 2;
    pcCgb[1].panMask = 0x22;
    pcCgb[2].type = 3;
    pcCgb[2].panMask = 0x44;
    pcCgb[3].type = 4;
    pcCgb[3].panMask = 0x88;
    pcMaxChans = 8;
    pcMasterVolume = 15;
    SampleFreqSet(SOUND_MODE_FREQ_13379);
    pcIdent = ID_NUMBER;
}

void m4aSoundInit(void)
{
    s32 i;
    Pc_Songs(&pcSongCount);
    Pc_SoundInit();
    m4aSoundMode(SOUND_MODE_DA_BIT_8
               | SOUND_MODE_FREQ_18157
               | (14 << SOUND_MODE_MASVOL_SHIFT)
               | (5 << SOUND_MODE_MAXCHN_SHIFT));
    for (i = 0; i < MUSIC_PLAYERS_COUNT; i++)
    {
        struct MusicPlayerInfo *mplayInfo = gMPlayTable[i].info;
        MPlayOpen(mplayInfo, gMPlayTable[i].track, gMPlayTable[i].numTracks);
        mplayInfo->unk_B = gMPlayTable[i].unk_A;
        mplayInfo->memAccArea = gMPlayMemAccArea;
    }
}

void m4aSoundMain(void)
{
    Pc_AudioTick();
    Pc_MixerRender();
}

int Pc_AudioHalted(void)
{
    return pcIdent != ID_NUMBER;
}

// Chunk 3 fills this in with the mixer feed (replaces SoundMainBTM's DMA).
void SoundMainBTM(void)
{
}

// ---- song start/stop (adapted from m4a.c) ----

static const struct MusicPlayer *Pc_SongPlayer(u16 n)
{
    if (n >= pcSongCount)
        return NULL;
    return &gMPlayTable[gSongTable[n].ms];
}

void m4aSongNumStart(u16 n)
{
    const struct MusicPlayer *mplay = Pc_SongPlayer(n);
    if (mplay == NULL)
        return;
    MPlayStart(mplay->info, gSongTable[n].header);
}

void m4aSongNumStartOrChange(u16 n)
{
    const struct MusicPlayer *mplay = Pc_SongPlayer(n);
    if (mplay == NULL)
        return;
    if (mplay->info->songHeader != gSongTable[n].header)
    {
        MPlayStart(mplay->info, gSongTable[n].header);
    }
    else
    {
        if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0
         || (mplay->info->status & MUSICPLAYER_STATUS_PAUSE))
        {
            MPlayStart(mplay->info, gSongTable[n].header);
        }
    }
}

void m4aSongNumStartOrContinue(u16 n)
{
    const struct MusicPlayer *mplay = Pc_SongPlayer(n);
    if (mplay == NULL)
        return;
    if (mplay->info->songHeader != gSongTable[n].header)
        MPlayStart(mplay->info, gSongTable[n].header);
    else if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        MPlayStart(mplay->info, gSongTable[n].header);
    else if (mplay->info->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(mplay->info);
}

void m4aSongNumStop(u16 n)
{
    const struct MusicPlayer *mplay = Pc_SongPlayer(n);
    if (mplay == NULL)
        return;
    if (mplay->info->songHeader == gSongTable[n].header)
        m4aMPlayStop(mplay->info);
}

void m4aSongNumContinue(u16 n)
{
    const struct MusicPlayer *mplay = Pc_SongPlayer(n);
    if (mplay == NULL)
        return;
    if (mplay->info->songHeader == gSongTable[n].header)
        MPlayContinue(mplay->info);
}
