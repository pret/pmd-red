// platform/pc/stubs_pc.c — host stubs for not-yet-ported HW-coupled units.
//
// These satisfy the link so real game modules run on host. Each stub is a
// documented deep-port backlog item (audio sequencer, boot ISR, link play):
// called stubs abort via Pc_StubAbort; pure data placeholders are zero-sized.
#include "global.h"
#include "cpu_pc.h"
#include "m4a.h"
#include "music.h"
#include "gba/m4a_internal.h"

// ---- Boot / interrupt vectors (replaced by the host 60Hz loop) ----
u32 IntrMain[0x120 / sizeof(u32)]; // crt0.s never assembles on host; address-taken only
u32 gUnknown_3004000;              // IWRAM scratch (ld_script 0x3002090); address-taken only

u32 sub_80001E8(void) { return 0; } // arm_funcs.s link-play copy source; host has no link play
void sub_8000228(void) {}           // arm_funcs.s SIO ISR; host has no link play

// ---- m4a sound engine (replaced by the SDL_Audio sequencer in audio_pc.c) ----
void m4aSoundVSyncOn(void) {}
void m4aSoundVSyncOff(void) {}
void m4aSoundInit(void) {}
void m4aSoundMain(void) {}
void m4aSongNumStart(u16 n) { (void)n; }
void m4aSongNumStartOrChange(u16 n) { (void)n; }
void m4aSongNumStop(u16 n) { (void)n; }
void m4aMPlayAllStop(void) {}
void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo) { (void)mplayInfo; }
void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed) { (void)mplayInfo; (void)speed; }
void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed) { (void)mplayInfo; (void)speed; }
void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed) { (void)mplayInfo; (void)speed; }
void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo) { (void)mplayInfo; }
void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo) { (void)mplayInfo; }
void m4aMPlayVolumeControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 volume)
{
    (void)mplayInfo; (void)trackBits; (void)volume;
}
void m4aSoundVSync(void) {}

// m4a_1.s mixer entry points referenced by gMPlayJumpTableTemplate.
void SoundMainBTM(void) {}
void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo; (void)track;
}
void RealClearChain(void *x) { (void)x; }
void FadeOutBody(struct MusicPlayerInfo *mplayInfo) { (void)mplayInfo; }
void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)mplayInfo; (void)track;
}
void SampleFreqSet(u32 freq) { (void)freq; }

// Sound command handlers (m4a_tables.c jump table holds them as void *).
#define PLY_STUB(name) \
    void name(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track) \
    { (void)mplayInfo; (void)track; }
PLY_STUB(ply_fine)
PLY_STUB(ply_goto)
PLY_STUB(ply_patt)
PLY_STUB(ply_pend)
PLY_STUB(ply_rept)
PLY_STUB(ply_memacc)
PLY_STUB(ply_prio)
PLY_STUB(ply_tempo)
PLY_STUB(ply_keysh)
PLY_STUB(ply_voice)
PLY_STUB(ply_vol)
PLY_STUB(ply_pan)
PLY_STUB(ply_bend)
PLY_STUB(ply_bendr)
PLY_STUB(ply_lfos)
PLY_STUB(ply_lfodl)
PLY_STUB(ply_mod)
PLY_STUB(ply_modt)
PLY_STUB(ply_tune)
PLY_STUB(ply_port)
PLY_STUB(ply_xcmd)
PLY_STUB(ply_endtie)
PLY_STUB(ply_xxx)
PLY_STUB(ply_xwave)
PLY_STUB(ply_xtype)
PLY_STUB(ply_xatta)
PLY_STUB(ply_xdeca)
PLY_STUB(ply_xsust)
PLY_STUB(ply_xrele)
PLY_STUB(ply_xiecv)
PLY_STUB(ply_xiecl)
PLY_STUB(ply_xleng)
PLY_STUB(ply_xswee)
void ply_note(u32 note_cmd, struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    (void)note_cmd; (void)mplayInfo; (void)track;
}

// Song/player tables (sound_data.s on GBA; host dummies until the sequencer
// loads real songs from sound/songs/midi). Sizes cover every index the game
// uses: gSongTable by song id (up to ~128), gMPlayTable by player index.
// All dummy players report status 0 ("stopped") so UpdateSound takes the
// stop paths into the m4a noops above.
#define HOST_SONG_COUNT 128
const struct Song gSongTable[HOST_SONG_COUNT] = {{{0}}};
struct MusicPlayerInfo gMPlayInfo_BGM = {0};
struct MusicPlayerInfo gMPlayInfo_Fanfare = {0};
static struct MusicPlayerInfo sDummyPlayer;
const struct MusicPlayer gMPlayTable[MUSIC_PLAYERS_COUNT] = {
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
    { .info = &sDummyPlayer },
};
