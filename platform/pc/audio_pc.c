// platform/pc/audio_pc.c — SDL2 audio renderer (chunk 3).
//
// Renders the m4a_port.c channel state to host audio. Design mirrors the GBA
// driver (src/m4a_1.s SoundMainRAM mixer + src/m4a.c CgbSound) at 60 Hz
// tick granularity, retargeted to a 44100 Hz stereo SDL stream:
//
//  - DirectSound voices: linear-interpolated wavetable with the exact GBA
//    advance math (divFreq * chanFrequency / 2^23 wave samples per GBA
//    output sample, scaled by 18157/44100), ADSR/sustain/release/echo
//    envelope machine, loop wrap with overshoot, one-shot kill.
//    DirectSoundFix (type & 8) plays 1:1 (no resampling), like the GBA.
//  - CGB voices: square (duty from the voice word), 4-bit wave loop, and
//    LFSR noise synthesized at GBA hardware rates; CGB envelope machine
//    (attack/decay/sustain/release/IEC echo, 15-frame double step).
//  - Reverb: single feedback comb approximating the GBA's 87 ms buffer echo,
//    gain from the song's reverb value. Not bit-exact; documented.
//
// This is NOT emulation: no FIFO/DMA/timers. Timing of composition (tempo,
// gates, fades) comes from the ported scheduler; only sample math follows
// the driver. Push model: each 60 Hz tick renders 735 samples and queues
// them via SDL_QueueAudio (no callback thread, no locking). Without SDL2
// the renderer compiles to a headless no-op (players still advance).
#include <string.h>
#include <time.h>

#include "gba/gba.h"
#include "gba_shim.h"
#include "audio_data.h"
#include "m4a_port.h"

#define PC_AUDIO_RATE 44100
#define PC_AUDIO_BLOCK_MAX 4096             // largest single render block
#define PC_MASTER_GAIN 8.0f                 // 8-bit-scale mix -> 16-bit loudness
#define PC_AUDIO_GBA_RATE 18157

#ifdef HAVE_SDL2
#include <SDL2/SDL.h>
static SDL_AudioDeviceID sAudioDev = 0;
#endif
static int sAudioRate = PC_AUDIO_RATE;

// Forward declarations (defined below the render core).
static void Pc_CgbFrame(void);
static void Pc_DsEnvelope(struct SoundChannel *chan, int flat);
static void Pc_RenderDs(struct SoundChannel *chan, int flat,
                        float *mixL, float *mixR, int n, int rate);
static void Pc_RenderCgb(struct CgbChannel *chan, int ci,
                         float *mixL, float *mixR, int n, int rate);

// ---- per-tick render cursors (renderer-owned; SoundChannel holds the rest)
static double pcDsPos[MAX_DIRECTSOUND_CHANNELS];
static int pcDsRemain[MAX_DIRECTSOUND_CHANNELS];
static double pcCgbPhase[4];
static double pcCgbLenLeft[4];
static unsigned int pcNoiseLfsr = 0x7FFF;
static double pcNoisePhase = 0.0;

// Reverb delay (87 ms like the GBA's 1584-sample buffer at 18157 Hz).
#define PC_REV_DELAY 3840
static float pcRevL[PC_REV_DELAY];
static float pcRevR[PC_REV_DELAY];
static unsigned pcRevPos = 0;

// GBA advance per output sample, scaled from 18157 Hz to the host rate:
// advance = divFreq * chanFrequency / 2^23 wave samples per GBA sample.
static double Pc_DsStep(const struct SoundChannel *chan, int rate)
{
    return (double)Pc_DivFreq() * (double)chan->frequency
         * ((double)PC_AUDIO_GBA_RATE / (double)rate) / 8388608.0;
}

// Render one DirectSound voice into the float mix (n samples).
static void Pc_RenderDs(struct SoundChannel *chan, int flat,
                        float *mixL, float *mixR, int n, int rate)
{
    const PcWave *waves;
    unsigned int nw;
    const signed char *data;
    unsigned int len;
    unsigned int loopStart;
    unsigned int loopLen;
    int loop;
    double step;
    double pos;
    int remain;
    int volL;
    int volR;
    int i;
    if (!(chan->statusFlags & SOUND_CHANNEL_SF_ON))
        return;
    if (gPcChanRefKind[flat] != PC_VOICE_WAVE)
        return;
    waves = Pc_Waves(&nw);
    if (gPcChanRefA[flat] >= nw)
        return;
    data = waves[gPcChanRefA[flat]].data;
    len = waves[gPcChanRefA[flat]].length;
    loopStart = waves[gPcChanRefA[flat]].loopStart;
    loopLen = waves[gPcChanRefA[flat]].loopEnd
            - waves[gPcChanRefA[flat]].loopStart;
    loop = waves[gPcChanRefA[flat]].loop;
    if (len == 0)
    {
        chan->statusFlags = 0;
        return;
    }
    if (chan->type & 8)
        step = (double)PC_AUDIO_GBA_RATE / (double)rate; // Fix: 1:1 at GBA rate
    else
        step = Pc_DsStep(chan, rate);
    pos = pcDsPos[flat];
    remain = pcDsRemain[flat];
    volL = chan->envelopeVolumeLeft;
    volR = chan->envelopeVolumeRight;
    for (i = 0; i < n; i++)
    {
        double newPos = pos + step;
        int adv = (int)newPos - (int)pos;
        int idx = (int)pos;
        double frac;
        int s0;
        int s1;
        int s;
        if (idx < 0)
            idx = 0;
        if ((unsigned int)idx >= len)
            idx = (int)len - 1;
        frac = pos - (int)pos;
        if (frac < 0.0)
            frac = 0.0;
        s0 = data[idx];
        if ((unsigned int)(idx + 1) < len)
            s1 = data[idx + 1];
        else if (loop && loopLen > 0)
            s1 = data[loopStart];
        else
            s1 = s0;
        s = s0 + (int)(frac * (s1 - s0));
        mixL[i] += (float)(s * volL / 256);
        mixR[i] += (float)(s * volR / 256);
        pos = newPos;
        remain -= adv;
        if (remain <= 0)
        {
            int over;
            if (!loop || loopLen == 0)
            {
                chan->statusFlags = 0;
                break;
            }
            over = -remain % (int)loopLen;
            pos = (double)loopStart + over + (newPos - (int)newPos);
            remain = (int)loopLen - over;
        }
    }
    pcDsPos[flat] = pos;
    pcDsRemain[flat] = remain > 0 ? remain : 0;
    chan->count = remain > 0 ? (u32)remain : 0;
}

// Square duty cycles by WaveDuty value (12.5/25/50/75%).
static double Pc_SquareDuty(int duty)
{
    switch (duty & 3)
    {
    case 0: return 0.125;
    case 1: return 0.25;
    case 3: return 0.75;
    default: return 0.5;
    }
}

// Wave-channel volume code (NR32 bits 6-5 via gCgb3Vol).
static double Pc_WaveVol(int env)
{
    switch (env & 15)
    {
    case 2:
    case 3:
    case 4:
    case 5: return 1.0;
    case 6:
    case 7:
    case 8:
    case 9: return 0.5;
    case 14:
    case 15: return 1.0;
    default: return 0.0;
    }
}

// Render one CGB voice into the float mix (n samples).
static void Pc_RenderCgb(struct CgbChannel *chan, int ci,
                         float *mixL, float *mixR, int n, int rate)
{
    int type;
    int env;
    int allowL;
    int allowR;
    int i;
    if (!(chan->statusFlags & SOUND_CHANNEL_SF_ON))
        return;
    type = chan->type & 7;
    if (type < 1 || type > 4)
        return;
    env = chan->envelopeVolume;
    if (env < 0)
        env = 0;
    if (env > 15)
        env = 15;
    allowR = (chan->pan & chan->panMask) & 0x0F;
    allowL = (chan->pan & chan->panMask) & 0xF0;
    if (!allowL && !allowR)
        return;
    if (type == 1 || type == 2)
    {
        double hz = 131072.0 / (2048 - (chan->frequency & 0x7FF));
        double duty = 0.5;
        double amp = env / 15.0;
        if (gPcChanRefKind[12 + ci] == PC_VOICE_DUTY)
            duty = Pc_SquareDuty(gPcChanRefA[12 + ci]);
        for (i = 0; i < n; i++)
        {
            double s = 0.0;
            if (amp > 0.0 && (chan->length == 0 || pcCgbLenLeft[ci] > 0))
            {
                pcCgbPhase[ci] += hz / rate;
                if (pcCgbPhase[ci] >= 1.0)
                    pcCgbPhase[ci] -= 1.0;
                s = (pcCgbPhase[ci] < duty) ? amp : -amp;
            }
            if (chan->length)
                pcCgbLenLeft[ci] -= 1.0;
            if (allowL)
                mixL[i] += (float)(s * 127);
            if (allowR)
                mixR[i] += (float)(s * 127);
        }
    }
    else if (type == 3)
    {
        const PcGbWave *gb;
        unsigned int ngb;
        double hz = 65536.0 / (2048 - (chan->frequency & 0x7FF));
        double amp;
        gb = Pc_GbWaves(&ngb);
        amp = Pc_WaveVol(env);
        for (i = 0; i < n; i++)
        {
            double s = 0.0;
            if (amp > 0.0 && (chan->length == 0 || pcCgbLenLeft[ci] > 0)
                && gPcChanRefKind[12 + ci] == PC_VOICE_GBWAVE
                && gPcChanRefA[12 + ci] < ngb)
            {
                int idx;
                int nib;
                pcCgbPhase[ci] += hz / rate;
                if (pcCgbPhase[ci] >= 1.0)
                    pcCgbPhase[ci] -= 1.0;
                idx = ((int)(pcCgbPhase[ci] * 32)) & 31;
                nib = gb[gPcChanRefA[12 + ci]].data[idx >> 1];
                nib = (idx & 1) ? (nib & 0xF) : ((nib >> 4) & 0xF);
                s = ((nib - 8) / 8.0) * amp;
            }
            if (chan->length)
                pcCgbLenLeft[ci] -= 1.0;
            if (allowL)
                mixL[i] += (float)(s * 127);
            if (allowR)
                mixR[i] += (float)(s * 127);
        }
    }
    else
    {
        unsigned int nr43 = chan->frequency & 0xFF;
        unsigned int r = nr43 & 7;
        unsigned int shift = (nr43 >> 4) & 0xF;
        int seven = (gPcChanRefA[12 + ci] & 1) != 0;
        double clockHz = 524288.0 / (r ? r * 16 : 8) / (1 << (shift + 1));
        double amp = env / 15.0;
        for (i = 0; i < n; i++)
        {
            double s = 0.0;
            if (amp > 0.0 && (chan->length == 0 || pcCgbLenLeft[ci] > 0))
            {
                pcNoisePhase += clockHz / rate;
                while (pcNoisePhase >= 1.0)
                {
                    unsigned int bit;
                    pcNoisePhase -= 1.0;
                    if (seven)
                    {
                        bit = ((pcNoiseLfsr & 1) ^ ((pcNoiseLfsr >> 1) & 1)) & 1;
                        pcNoiseLfsr = ((pcNoiseLfsr >> 1) | (bit << 6)) & 0x7F;
                    }
                    else
                    {
                        bit = ((pcNoiseLfsr & 1) ^ ((pcNoiseLfsr >> 1) & 1)) & 1;
                        pcNoiseLfsr = ((pcNoiseLfsr >> 1) | (bit << 14)) & 0x7FFF;
                    }
                }
                s = (pcNoiseLfsr & 1) ? amp : -amp;
            }
            if (chan->length)
                pcCgbLenLeft[ci] -= 1.0;
            if (allowL)
                mixL[i] += (float)(s * 127);
            if (allowR)
                mixR[i] += (float)(s * 127);
        }
    }
}

// ---- device management + per-tick render ----

void Pc_AudioInit(void)
{
#ifdef HAVE_SDL2
    SDL_AudioSpec want;
    SDL_AudioSpec have;
    if (sAudioDev != 0)
        return;
    if (SDL_WasInit(SDL_INIT_AUDIO) == 0)
    {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
            return;
    }
    memset(&want, 0, sizeof(want));
    want.freq = PC_AUDIO_RATE;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = 1024;
    want.callback = NULL;
    sAudioDev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (sAudioDev == 0)
        return;
    if (have.format != AUDIO_S16SYS || have.channels != 2)
    {
        SDL_CloseAudioDevice(sAudioDev);
        sAudioDev = 0;
        return;
    }
    sAudioRate = (int)have.freq;
    SDL_PauseAudioDevice(sAudioDev, 0);
#endif
}

int Pc_AudioRate(void)
{
    return sAudioRate;
}

double Pc_TimeNow(void)
{
#ifdef HAVE_SDL2
    return (double)SDL_GetPerformanceCounter()
         / (double)SDL_GetPerformanceFrequency();
#else
    return (double)clock() / (double)CLOCKS_PER_SEC;
#endif
}

void Pc_AudioFrame(void)
{
    // Game frames drive rendering via m4aSoundMain -> Pc_MixerRenderSamples;
    // nothing to do here (device idles silently when the queue is empty).
}

void Pc_AudioShutdown(void)
{
#ifdef HAVE_SDL2
    if (sAudioDev != 0)
    {
        SDL_CloseAudioDevice(sAudioDev);
        sAudioDev = 0;
    }
#endif
}

// Render n samples of all voices and queue them. Called from m4aSoundMain.
// stepEnvelope != 0 performs one full 60 Hz tick (scheduler already advanced
// via Pc_AudioTick): CgbSound envelopes + per-channel DS envelope, then the
// mixer — mirroring the GBA order. stepEnvelope == 0 renders a partial
// sub-tick with the current channel state so the host queue is fed in
// lockstep with real elapsed time regardless of the game frame rate.
// Headless (no device): no-op.
void Pc_MixerRenderSamples(int n, int stepEnvelope)
{
#ifdef HAVE_SDL2
    unsigned int nchan;
    unsigned int ncgb;
    struct SoundChannel *chans;
    struct CgbChannel *cgbs;
    float mixL[PC_AUDIO_BLOCK_MAX];
    float mixR[PC_AUDIO_BLOCK_MAX];
    short out[PC_AUDIO_BLOCK_MAX * 2];
    double revGain;
    int i;
    unsigned int ci;
    if (sAudioDev == 0)
        return;
    if (n < 1)
        return;
    if (n > PC_AUDIO_BLOCK_MAX)
        n = PC_AUDIO_BLOCK_MAX;
    for (i = 0; i < n; i++)
        mixL[i] = mixR[i] = 0.0f;
    if (!Pc_AudioHalted())
    {
        if (stepEnvelope)
        {
            Pc_CgbFrame();
            chans = Pc_SoundChans(&nchan);
            for (ci = 0; ci < nchan && ci < MAX_DIRECTSOUND_CHANNELS; ci++)
                Pc_DsEnvelope(&chans[ci], (int)ci);
        }
        chans = Pc_SoundChans(&nchan);
        for (ci = 0; ci < nchan && ci < MAX_DIRECTSOUND_CHANNELS; ci++)
            Pc_RenderDs(&chans[ci], (int)ci, mixL, mixR, n, sAudioRate);
        cgbs = Pc_CgbChans(&ncgb);
        for (ci = 0; ci < ncgb && ci < 4; ci++)
            Pc_RenderCgb(&cgbs[ci], (int)ci, mixL, mixR, n, sAudioRate);
    }
    // Reverb: feedback comb approximating the GBA's 87 ms buffer echo.
    revGain = Pc_Reverb() * 4.0 / 512.0;
    if (revGain > 0.8)
        revGain = 0.8;
    for (i = 0; i < n; i++)
    {
        float l = mixL[i];
        float r = mixR[i];
        if (revGain > 0.0)
        {
            l += (float)(revGain * pcRevL[pcRevPos]);
            r += (float)(revGain * pcRevR[pcRevPos]);
            pcRevL[pcRevPos] = l;
            pcRevR[pcRevPos] = r;
            pcRevPos++;
            if (pcRevPos >= PC_REV_DELAY)
                pcRevPos = 0;
        }
        // Bring the GBA 8-bit-scale mix up to a normal 16-bit loudness.
        l *= (float)PC_MASTER_GAIN;
        r *= (float)PC_MASTER_GAIN;
        if (l > 32767.0f)
            l = 32767.0f;
        else if (l < -32768.0f)
            l = -32768.0f;
        if (r > 32767.0f)
            r = 32767.0f;
        else if (r < -32768.0f)
            r = -32768.0f;
        out[i * 2] = (short)l;
        out[i * 2 + 1] = (short)r;
    }
    // Bound queue latency: drop (don't pile up) past ~1 s, e.g. during
    // unpaced boot pumps that run hundreds of frames per second.
    if (SDL_GetQueuedAudioSize(sAudioDev) <= (Uint32)(sAudioRate * 4))
        SDL_QueueAudio(sAudioDev, out, (Uint32)(n * 4));
#endif
}

// ---- DirectSound envelope (one tick; mirrors SoundMainRAM per-call block)
static void Pc_DsEnvelope(struct SoundChannel *chan, int flat)
{
    u8 flags = chan->statusFlags;
    unsigned int env;
    const PcWave *waves;
    unsigned int nw;
    if (!(flags & SOUND_CHANNEL_SF_ON))
        return;
    if (flags & SOUND_CHANNEL_SF_START)
    {
        if (flags & SOUND_CHANNEL_SF_STOP)
        {
            chan->statusFlags = 0;
            return;
        }
        // START init (mirrors the mixer, not the player).
        if (gPcChanRefKind[flat] != PC_VOICE_WAVE)
        {
            chan->statusFlags = 0;
            return;
        }
        waves = Pc_Waves(&nw);
        if (gPcChanRefA[flat] >= nw)
        {
            chan->statusFlags = 0;
            return;
        }
        flags = SOUND_CHANNEL_SF_ENV_ATTACK;
        chan->statusFlags = flags;
        pcDsPos[flat] = 0.0;
        pcDsRemain[flat] = (int)waves[gPcChanRefA[flat]].length;
        env = 0;
        if (waves[gPcChanRefA[flat]].loop)
        {
            flags |= SOUND_CHANNEL_SF_LOOP;
            chan->statusFlags = flags;
        }
        // First attack step applies on the START tick (mixer fallthrough).
        env += chan->attack;
        if (env >= 0xFF)
        {
            env = 0xFF;
            chan->statusFlags = flags - 1;
        }
    }
    else
    {
        env = chan->envelopeVolume;
        if (flags & SOUND_CHANNEL_SF_IEC)
        {
            int left = (int)chan->echoLength - 1;
            chan->echoLength = (u8)left;
            if (left <= 0)
            {
                chan->statusFlags = 0;
                return;
            }
        }
        else if (flags & SOUND_CHANNEL_SF_STOP)
        {
            env = (u8)((env * chan->release) >> 8);
            if (env > chan->echoVolume)
            {
                /* keep rendering at decaying level */
            }
            else if (chan->echoVolume == 0)
            {
                chan->statusFlags = 0;
                return;
            }
            else
            {
                chan->statusFlags = flags | SOUND_CHANNEL_SF_IEC;
            }
        }
        else if ((flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_DECAY)
        {
            env = (u8)((env * chan->decay) >> 8);
            if (env > chan->sustain)
            {
                /* keep decaying */
            }
            else
            {
                env = chan->sustain;
                if (env == 0)
                {
                    if (chan->echoVolume == 0)
                    {
                        chan->statusFlags = 0;
                        return;
                    }
                    chan->statusFlags = flags | SOUND_CHANNEL_SF_IEC;
                }
                else
                {
                    chan->statusFlags = flags - 1;
                }
            }
        }
        else if ((flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_ATTACK)
        {
            env += chan->attack;
            if (env >= 0xFF)
            {
                env = 0xFF;
                chan->statusFlags = flags - 1;
            }
        }
        /* SUSTAIN steady / ENV_RELEASE: level holds. */
    }
    chan->envelopeVolume = env;
    {
        unsigned int scaled = (unsigned int)env * (Pc_MasterVolume() + 1) >> 4;
        chan->envelopeVolumeRight = (u8)((chan->rightVolume * scaled) >> 8);
        chan->envelopeVolumeLeft = (u8)((chan->leftVolume * scaled) >> 8);
    }
}

// ---- CGB helpers (adapted from m4a.c:CgbPan/CgbModVol) ----
static int Pc_CgbPan(struct CgbChannel *chan)
{
    u8 rightVolume = chan->rightVolume;
    u8 leftVolume = chan->leftVolume;
    if (rightVolume >= leftVolume)
    {
        if (rightVolume / 2 >= leftVolume)
        {
            chan->pan = 0x0F;
            return 1;
        }
    }
    else
    {
        if (leftVolume / 2 >= rightVolume)
        {
            chan->pan = 0xF0;
            return 1;
        }
    }
    return 0;
}

static void Pc_CgbModVol(struct CgbChannel *chan)
{
    if (!Pc_CgbPan(chan))
    {
        chan->pan = 0xFF;
        chan->envelopeGoal = (u32)(chan->rightVolume + chan->leftVolume) / 16;
    }
    else
    {
        chan->envelopeGoal = (u32)(chan->rightVolume + chan->leftVolume) / 16;
        if (chan->envelopeGoal > 15)
            chan->envelopeGoal = 15;
    }
    chan->sustainGoal = (chan->envelopeGoal * chan->sustain + 15) >> 4;
    chan->pan &= chan->panMask;
}

static int pcCgbC15 = 14;

// CGB envelope/state step, one tick (mirrors m4a.c:CgbSound minus registers:
// sweep time-variation and length-timer expiry silencing are renderer-side).
static void Pc_CgbFrame(void)
{
    unsigned int nchan;
    struct CgbChannel *chans = Pc_CgbChans(&nchan);
    unsigned int c;
    if (pcCgbC15)
        pcCgbC15--;
    else
        pcCgbC15 = 14;
    for (c = 0; c < nchan && c < 4; c++)
    {
        struct CgbChannel *chan = &chans[c];
        int ch = (int)c + 1;
        int prevC15 = pcCgbC15;
        if (!(chan->statusFlags & SOUND_CHANNEL_SF_ON))
            continue;
        if (chan->statusFlags & SOUND_CHANNEL_SF_START)
        {
            if (chan->statusFlags & SOUND_CHANNEL_SF_STOP)
            {
                chan->statusFlags = 0;
                continue;
            }
            chan->statusFlags = SOUND_CHANNEL_SF_ENV_ATTACK;
            chan->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
            Pc_CgbModVol(chan);
            // Renderer-side voice start: reset phase; arm the length timer.
            pcCgbPhase[c] = 0.0;
            if (chan->length)
                pcCgbLenLeft[c] = (64 - chan->length) * (sAudioRate / 256.0);
            else
                pcCgbLenLeft[c] = 1e18;
            if (chan->length)
                chan->n4 = (ch == 3) ? 0xC0 : 0x40;
            else
                chan->n4 = (ch == 3) ? 0x80 : 0x00;
            chan->envelopeCounter = chan->attack;
            if (chan->attack & 0xFF)
            {
                chan->envelopeVolume = 0;
                goto cgb_step_done;
            }
            goto cgb_decay_start;
        }
        else if (chan->statusFlags & SOUND_CHANNEL_SF_IEC)
        {
            chan->pseudoEchoLength--;
            if ((s8)chan->pseudoEchoLength <= 0)
            {
                chan->statusFlags = 0;
                continue;
            }
            goto cgb_frame_done;
        }
        else if ((chan->statusFlags & SOUND_CHANNEL_SF_STOP)
                 && (chan->statusFlags & SOUND_CHANNEL_SF_ENV))
        {
            chan->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
            chan->envelopeCounter = chan->release;
            if (chan->release & 0xFF)
            {
                chan->modify |= CGB_CHANNEL_MO_VOL;
                goto cgb_step_done;
            }
            goto cgb_echo_start;
        }
    cgb_step_repeat:
        if (chan->envelopeCounter == 0)
        {
            Pc_CgbModVol(chan);
            if ((chan->statusFlags & SOUND_CHANNEL_SF_ENV)
                == SOUND_CHANNEL_SF_ENV_RELEASE)
            {
                chan->envelopeVolume--;
                if ((s8)chan->envelopeVolume <= 0)
                    goto cgb_echo_start;
                chan->envelopeCounter = chan->release;
            }
            else if ((chan->statusFlags & SOUND_CHANNEL_SF_ENV)
                     == SOUND_CHANNEL_SF_ENV_SUSTAIN)
            {
                chan->envelopeVolume = chan->sustainGoal;
                chan->envelopeCounter = 7;
            }
            else if ((chan->statusFlags & SOUND_CHANNEL_SF_ENV)
                     == SOUND_CHANNEL_SF_ENV_DECAY)
            {
                int ev;
                int sg;
                chan->envelopeVolume--;
                ev = (s8)chan->envelopeVolume;
                sg = (s8)chan->sustainGoal;
                if (ev <= sg)
                {
                    if (chan->sustain == 0)
                    {
                        chan->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
                        goto cgb_echo_start;
                    }
                    chan->statusFlags--;
                    chan->modify |= CGB_CHANNEL_MO_VOL;
                    goto cgb_sustain_set;
                }
                chan->envelopeCounter = chan->decay;
            }
            else
            {
                chan->envelopeVolume++;
                if ((u8)chan->envelopeVolume >= chan->envelopeGoal)
                    goto cgb_decay_start;
                chan->envelopeCounter = chan->attack;
            }
        }
        goto cgb_step_done_default;
    cgb_decay_start:
        chan->statusFlags--;
        chan->envelopeCounter = chan->decay;
        if (chan->envelopeCounter & 0xFF)
        {
            chan->modify |= CGB_CHANNEL_MO_VOL;
            chan->envelopeVolume = chan->envelopeGoal;
        }
        else
        {
            if (chan->sustain == 0)
            {
                chan->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
                goto cgb_echo_start;
            }
            chan->statusFlags--;
            chan->modify |= CGB_CHANNEL_MO_VOL;
    cgb_sustain_set:
            chan->envelopeVolume = chan->sustainGoal;
            chan->envelopeCounter = 7;
        }
        goto cgb_step_done_default;
    cgb_echo_start:
        chan->envelopeVolume =
            ((chan->envelopeGoal * chan->pseudoEchoVolume) + 0xFF) >> 8;
        if (chan->envelopeVolume)
        {
            chan->statusFlags |= SOUND_CHANNEL_SF_IEC;
            chan->modify |= CGB_CHANNEL_MO_VOL;
        }
        else
        {
            chan->statusFlags = 0;
        }
        goto cgb_frame_done;
    cgb_step_done_default:;
    cgb_step_done:
        chan->envelopeCounter--;
        if (prevC15 == 0)
        {
            prevC15--;
            goto cgb_step_repeat;
        }
    cgb_frame_done:
        chan->modify = 0;
    }
}
