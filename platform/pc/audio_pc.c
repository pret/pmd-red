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
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "gba/gba.h"
#include "gba_shim.h"
#include "audio_data.h"
#include "m4a_port.h"

#define PC_AUDIO_RATE 44100
#define PC_AUDIO_BLOCK_MAX 4096             // largest single render block
#define PC_MASTER_GAIN 256.0f               // 8-bit DS buffer -> 16-bit loudness
#define PC_SATURATE 0.85f                   // soft-knee limiter start (of full scale)
#define PC_REV_BUF_MAX 8192                 // reverb delay line (host samples)
#define PC_CGB_DECLICK 256                  // wave-channel fade on note-off

// GBA CGB 4-bit DAC output levels (NR32 semantics). gCgb3Vol (src/m4a_tables.c)
// maps the m4a envelope index to the register byte; 0x80 is the GBA-only 75%
// mode (bit 7), not mute.
extern const u8 gCgb3Vol[];

#ifdef HAVE_SDL2
#include <SDL2/SDL.h>
static SDL_AudioDeviceID sAudioDev = 0;
static FILE *sWavFile = NULL;
static long sWavDataBytes = 0;
static int sWavMaxSamples = 0;
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
static double pcCgbLenLeft[4];

// ---- CGB hardware state (free-running oscillators, envelope, sweep) ----
static const uint8_t pcCgbDutyPattern[4] = { 0x01, 0x81, 0xE1, 0x7E };
static uint32_t pcCgbPhase[4];          // square/wave: 2^32/period; noise: Q16 fraction
static uint32_t pcCgbPhaseInc[4];       // phase increment per output sample
static uint32_t pcCgbPhaseIncFreq[4];   // frequency the cached increment was built for
static uint8_t  pcCgbNoiseMode[4];      // cached LFSR period mode (noise)
static int32_t  pcCgbWaveSum[4];        // sum of the 32 wave nibbles (DC removal)
static uint32_t pcCgbWaveSumRef[4];     // wave index the cached sum was built for
static uint32_t pcCgbLastWave[4];       // wave index at the last note start
static uint8_t  pcCgbEnvStepDir[4];     // low 3 bits step time, bit 3 = direction
static uint8_t  pcCgbHwEnvVolume[4];
static uint8_t  pcCgbHwEnvNextStep[4];
static uint8_t  pcCgbHwEnvDead[4];
static double   pcCgbHwEnvClockAccum[4];
static int      pcCgbWasOn[4];
static int32_t  pcCgbDeclickSample[4];
static int      pcCgbDeclickRemaining[4];

// Square-1 frequency sweep (NR10).
static uint16_t pcCgbSweepShadowFreq;
static uint8_t  pcCgbSweepStep;
static int      pcCgbSweepEnabled;
static int      pcCgbSweepMuted;
static double   pcCgbSweepClockAccum;

// Noise LFSR.
static unsigned int pcNoiseLfsr = 0x7FFF;

// ---- DirectSound reverb (GBA SoundMainRAM_Reverb: 4-tap feedback comb) ----
static signed char pcRevL[PC_REV_BUF_MAX];
static signed char pcRevR[PC_REV_BUF_MAX];
static int pcRevLen = 0;                // delay line length in host samples
static int pcRevFrame = 0;              // "other" tap offset (one VBlank frame)
static unsigned pcRevPos = 0;

// User low-pass filter state (one-pole IIR, applied on the final mix).
static float pcLpL = 0.0f;
static float pcLpR = 0.0f;

// Reset all CGB hardware state and (re)derive the reverb geometry.
static void Pc_CgbHardwareReset(void)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        pcCgbPhase[i] = 0;
        pcCgbPhaseInc[i] = 0;
        pcCgbPhaseIncFreq[i] = 0xFFFFFFFFu;
        pcCgbNoiseMode[i] = 0xFF;
        pcCgbWaveSum[i] = 0;
        pcCgbWaveSumRef[i] = 0xFFFFFFFFu;
        pcCgbLastWave[i] = 0xFFFFFFFFu;
        pcCgbEnvStepDir[i] = 0;
        pcCgbHwEnvVolume[i] = 0;
        pcCgbHwEnvNextStep[i] = 0;
        pcCgbHwEnvDead[i] = 1;
        pcCgbHwEnvClockAccum[i] = 0.0;
        pcCgbWasOn[i] = 0;
        pcCgbDeclickSample[i] = 0;
        pcCgbDeclickRemaining[i] = 0;
    }
    pcCgbSweepShadowFreq = 0;
    pcCgbSweepStep = 0;
    pcCgbSweepEnabled = 0;
    pcCgbSweepMuted = 0;
    pcCgbSweepClockAccum = 0.0;
    pcNoiseLfsr = 0x7FFF;
    pcRevLen = (int)(1584.0 * (double)sAudioRate / (double)Pc_PcmFreq() + 0.5);
    if (pcRevLen < 2)
        pcRevLen = 2;
    if (pcRevLen > PC_REV_BUF_MAX)
        pcRevLen = PC_REV_BUF_MAX;
    pcRevFrame = (int)((double)Pc_SamplesPerVBlank() * (double)sAudioRate
                       / (double)Pc_PcmFreq() + 0.5);
    if (pcRevFrame < 1)
        pcRevFrame = 1;
    if (pcRevFrame >= pcRevLen)
        pcRevFrame = pcRevLen - 1;
    memset(pcRevL, 0, sizeof(pcRevL));
    memset(pcRevR, 0, sizeof(pcRevR));
    pcRevPos = 0;
}

// GBA advance per output sample, scaled from 18157 Hz to the host rate:
// advance = divFreq * chanFrequency / 2^23 wave samples per GBA sample.
static double Pc_DsStep(const struct SoundChannel *chan, int rate)
{
    return (double)Pc_DivFreq() * (double)chan->frequency
         * ((double)Pc_PcmFreq() / (double)rate) / 8388608.0;
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
        step = (double)Pc_PcmFreq() / (double)rate; // Fix: 1:1 at GBA rate
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

// ---- CGB hardware helpers ----

// Square-1 NR10 sweep timing: 0 is treated as 8.
static int Pc_CgbSweepTime(const struct CgbChannel *chan)
{
    int t = (chan->sweep >> 4) & 7;
    return t ? t : 8;
}

// One sweep calculation (initial = trigger-time overflow check, never writes).
static int Pc_CgbSweepCalc(struct CgbChannel *chan, int initial)
{
    int shift = chan->sweep & 7;
    if (initial || Pc_CgbSweepTime(chan) != 8)
    {
        int32_t freq = pcCgbSweepShadowFreq;
        if (chan->sweep & 0x08)
        {
            freq -= freq >> shift;
            if (!initial && freq >= 0)
            {
                pcCgbSweepShadowFreq = (uint16_t)freq;
                chan->frequency = (uint32_t)freq;
            }
        }
        else
        {
            freq += freq >> shift;
            if (freq >= 2048)
                return 0;
            if (!initial && shift)
            {
                pcCgbSweepShadowFreq = (uint16_t)freq;
                chan->frequency = (uint32_t)freq;
                if (!Pc_CgbSweepCalc(chan, 1))
                    return 0;
            }
        }
    }
    pcCgbSweepStep = (uint8_t)Pc_CgbSweepTime(chan);
    return 1;
}

// NRx4 trigger as seen by the sweep unit (CgbSound writes it on every MO_VOL).
static void Pc_CgbSweepRetrigger(struct CgbChannel *chan)
{
    int time = Pc_CgbSweepTime(chan);
    int shift = chan->sweep & 7;
    pcCgbSweepMuted = 0;
    pcCgbSweepShadowFreq = (uint16_t)(chan->frequency & 0x7FF);
    pcCgbSweepStep = (uint8_t)time;
    pcCgbSweepEnabled = (time != 8) || shift != 0;
    if (shift && !Pc_CgbSweepCalc(chan, 1))
        pcCgbSweepMuted = 1;
}

// One 128 Hz sweep clock.
static void Pc_CgbSweepClock(struct CgbChannel *chan, int rate)
{
    if (!pcCgbSweepEnabled || pcCgbSweepMuted)
        return;
    pcCgbSweepClockAccum += 128.0 / (double)rate;
    while (pcCgbSweepClockAccum >= 1.0)
    {
        pcCgbSweepClockAccum -= 1.0;
        if (--pcCgbSweepStep != 0)
            continue;
        if (!Pc_CgbSweepCalc(chan, 0))
            pcCgbSweepMuted = 1;
    }
}

// CgbSound's MO_VOL register write: reload the hardware envelope unit and
// reset the noise LFSR (NRx4 trigger). The 64 Hz clock accumulator is left
// free-running, matching the hardware frame sequencer.
static void Pc_CgbHwEnvWrite(int ci, struct CgbChannel *chan)
{
    uint8_t stepDir = pcCgbEnvStepDir[ci];
    uint8_t stepTime = stepDir & 0x07;
    int dirInc = (stepDir & 0x08) != 0;
    pcCgbHwEnvVolume[ci] = chan->envelopeVolume & 0x0F;
    pcCgbHwEnvNextStep[ci] = stepTime;
    if (stepTime == 0)
        pcCgbHwEnvDead[ci] = 1;
    else if (!dirInc && pcCgbHwEnvVolume[ci] == 0)
        pcCgbHwEnvDead[ci] = 1;
    else if (dirInc && pcCgbHwEnvVolume[ci] == 15)
        pcCgbHwEnvDead[ci] = 1;
    else
        pcCgbHwEnvDead[ci] = 0;
    if ((chan->type & 7) == 4)
        pcNoiseLfsr = (gPcChanRefA[12 + ci] & 1) ? 0x7F : 0x7FFF;
}

// Free-running 64 Hz hardware envelope clock.
static void Pc_CgbHwEnvClock(int ci, int rate)
{
    pcCgbHwEnvClockAccum[ci] += 64.0 / (double)rate;
    while (pcCgbHwEnvClockAccum[ci] >= 1.0)
    {
        pcCgbHwEnvClockAccum[ci] -= 1.0;
        if (pcCgbHwEnvDead[ci] || (pcCgbEnvStepDir[ci] & 0x07) == 0)
            continue;
        if (--pcCgbHwEnvNextStep[ci] != 0)
            continue;
        if (pcCgbEnvStepDir[ci] & 0x08)
        {
            if (++pcCgbHwEnvVolume[ci] >= 15)
            {
                pcCgbHwEnvVolume[ci] = 15;
                pcCgbHwEnvDead[ci] = 1;
            }
            else
                pcCgbHwEnvNextStep[ci] = pcCgbEnvStepDir[ci] & 0x07;
        }
        else
        {
            if (--pcCgbHwEnvVolume[ci] == 0)
                pcCgbHwEnvDead[ci] = 1;
            else
                pcCgbHwEnvNextStep[ci] = pcCgbEnvStepDir[ci] & 0x07;
        }
    }
}

// Apply the register writes CgbSound performs at the end of a frame.
static void Pc_CgbApplyModify(int ci, struct CgbChannel *chan)
{
    int type = chan->type & 7;
    if (chan->modify & CGB_CHANNEL_MO_VOL)
    {
        if (type == 1)
            Pc_CgbSweepRetrigger(chan);
        if (type != 3)
            Pc_CgbHwEnvWrite(ci, chan);
    }
}

// One square sample (advances the free-running phase first, like hardware).
static int32_t Pc_CgbSquareSample(int ci, const struct CgbChannel *chan, int rate)
{
    uint8_t pattern;
    int bit;
    if (pcCgbPhaseIncFreq[ci] != chan->frequency)
    {
        uint32_t f = chan->frequency & 0x7FF;
        double hz = 131072.0 / (2048.0 - (double)f);
        pcCgbPhaseInc[ci] = (uint32_t)(hz / (double)rate * 4294967296.0);
        pcCgbPhaseIncFreq[ci] = chan->frequency;
    }
    pcCgbPhase[ci] += pcCgbPhaseInc[ci];
    pattern = pcCgbDutyPattern[gPcChanRefA[12 + ci] & 3];
    bit = (int)((pcCgbPhase[ci] >> 29) & 7);
    return (pattern & (1u << bit)) ? 64 : -64;
}

// One programmable-wave sample. The waveform mean is subtracted to remove the
// DC offset (hardware has no per-waveform bias).
static int32_t Pc_CgbWaveSample(int ci, const struct CgbChannel *chan, int rate)
{
    const PcGbWave *gb;
    unsigned int ngb;
    uint32_t ref = gPcChanRefA[12 + ci];
    int nr32;
    int32_t nib;
    int32_t shifted;
    int32_t meanShifted;
    int pos;
    gb = Pc_GbWaves(&ngb);
    if (ref >= ngb)
        return 0;
    if (pcCgbPhaseIncFreq[ci] != chan->frequency)
    {
        uint32_t f = chan->frequency & 0x7FF;
        double hz = 65536.0 / (2048.0 - (double)f);
        pcCgbPhaseInc[ci] = (uint32_t)(hz / (double)rate * 4294967296.0);
        pcCgbPhaseIncFreq[ci] = chan->frequency;
    }
    if (pcCgbWaveSumRef[ci] != ref)
    {
        int32_t sum = 0;
        int k;
        for (k = 0; k < 16; k++)
        {
            sum += (gb[ref].data[k] >> 4) & 0x0F;
            sum += gb[ref].data[k] & 0x0F;
        }
        pcCgbWaveSum[ci] = sum;
        pcCgbWaveSumRef[ci] = ref;
    }
    pos = (int)((pcCgbPhase[ci] >> 27) & 0x1F);
    nib = (pos & 1) ? (gb[ref].data[pos >> 1] & 0x0F)
                    : ((gb[ref].data[pos >> 1] >> 4) & 0x0F);
    nr32 = gCgb3Vol[chan->envelopeVolume & 0x0F];
    if (nr32 == 0)
    {
        shifted = 0;
        meanShifted = 0;
    }
    else if (nr32 & 0x80)
    {
        // GBA-only 75% mode.
        shifted = (nib + (nib << 1)) >> 2;
        meanShifted = (pcCgbWaveSum[ci] * 3) >> 7;
    }
    else
    {
        int sh = ((nr32 >> 5) & 3) - 1;
        shifted = nib >> sh;
        meanShifted = pcCgbWaveSum[ci] >> (5 + sh);
    }
    pcCgbPhase[ci] += pcCgbPhaseInc[ci];
    return (shifted - meanShifted) * 8;
}

// One noise sample; the LFSR is box-averaged over every clock inside the
// output sample so the fast hardware clock does not alias to a rigid square.
static int32_t Pc_CgbNoiseSample(int ci, const struct CgbChannel *chan, int rate)
{
    unsigned int nr43 = (chan->frequency & 0xF7)
                      | ((gPcChanRefA[12 + ci] & 1) << 3);
    uint8_t divRatio = nr43 & 0x07;
    uint8_t shiftFreq = (nr43 >> 4) & 0x0F;
    int shortMode = (nr43 & 0x08) != 0;
    uint32_t remaining;
    uint32_t untilClock;
    int32_t sample;
    if (pcCgbPhaseIncFreq[ci] != chan->frequency
        || pcCgbNoiseMode[ci] != (uint8_t)shortMode)
    {
        double base = 524288.0;
        double divisor = (divRatio == 0) ? 0.5 : (double)divRatio;
        double noiseFreq = base / divisor / (double)(1 << (shiftFreq + 1));
        pcCgbPhaseInc[ci] = (uint32_t)(noiseFreq / (double)rate * 65536.0);
        if (pcCgbPhaseInc[ci] == 0)
            pcCgbPhaseInc[ci] = 1;
        pcCgbPhaseIncFreq[ci] = chan->frequency;
        pcCgbNoiseMode[ci] = (uint8_t)shortMode;
    }
    remaining = pcCgbPhaseInc[ci];
    untilClock = 0x10000u - pcCgbPhase[ci];
    if (remaining < untilClock)
    {
        sample = (pcNoiseLfsr & 1) ? 64 : -64;
        pcCgbPhase[ci] += remaining;
    }
    else
    {
        int32_t acc = (int32_t)untilClock * ((pcNoiseLfsr & 1) ? 64 : -64);
        remaining -= untilClock;
        for (;;)
        {
            unsigned int bit = ((pcNoiseLfsr >> 1) ^ pcNoiseLfsr) & 1;
            if (shortMode)
                pcNoiseLfsr = (pcNoiseLfsr >> 1) | (bit << 6);
            else
                pcNoiseLfsr = (pcNoiseLfsr >> 1) | (bit << 14);
            if (remaining < 0x10000u)
                break;
            acc += (int32_t)(0x10000u * ((pcNoiseLfsr & 1) ? 64 : -64));
            remaining -= 0x10000u;
        }
        acc += (int32_t)remaining * ((pcNoiseLfsr & 1) ? 64 : -64);
        pcCgbPhase[ci] = remaining;
        sample = acc / (int32_t)pcCgbPhaseInc[ci];
    }
    return sample;
}

// Render one CGB voice into the float mix (n samples). Samples are produced
// in the GBA mixing domain (square/noise base +/-64, wave +/-120) so the
// DirectSound:PSG balance matches hardware.
static void Pc_RenderCgb(struct CgbChannel *chan, int ci,
                         float *mixL, float *mixR, int n, int rate)
{
    int type;
    int allowL;
    int allowR;
    int i;

    if (!(chan->statusFlags & SOUND_CHANNEL_SF_ON))
    {
        // Squares free-run on hardware even while silent.
        type = chan->type & 7;
        if (type == 1 || type == 2)
        {
            uint32_t f = chan->frequency & 0x7FF;
            if (pcCgbPhaseIncFreq[ci] != chan->frequency)
            {
                double hz = 131072.0 / (2048.0 - (double)f);
                pcCgbPhaseInc[ci] = (uint32_t)(hz / (double)rate * 4294967296.0);
                pcCgbPhaseIncFreq[ci] = chan->frequency;
            }
            pcCgbPhase[ci] += pcCgbPhaseInc[ci] * (uint32_t)n;
        }
        if (type == 3 && pcCgbWasOn[ci] && pcCgbDeclickRemaining[ci] <= 0)
            pcCgbDeclickRemaining[ci] = PC_CGB_DECLICK;
        pcCgbWasOn[ci] = 0;
        if (type == 3 && pcCgbDeclickRemaining[ci] > 0)
        {
            allowR = (chan->pan & chan->panMask) & 0x0F;
            allowL = (chan->pan & chan->panMask) & 0xF0;
            for (i = 0; i < n && pcCgbDeclickRemaining[ci] > 0; i++)
            {
                int32_t faded = (pcCgbDeclickSample[ci]
                                 * pcCgbDeclickRemaining[ci]) / PC_CGB_DECLICK;
                pcCgbDeclickRemaining[ci]--;
                if (allowL)
                    mixL[i] += (float)faded;
                if (allowR)
                    mixR[i] += (float)faded;
            }
        }
        return;
    }
    pcCgbWasOn[ci] = 1;
    pcCgbDeclickRemaining[ci] = 0;

    if (chan->statusFlags & SOUND_CHANNEL_SF_START)
        return;
    type = chan->type & 7;
    if (type < 1 || type > 4)
        return;

    allowR = (chan->pan & chan->panMask) & 0x0F;
    allowL = (chan->pan & chan->panMask) & 0xF0;

    for (i = 0; i < n; i++)
    {
        int32_t sample;
        if (chan->length != 0)
        {
            pcCgbLenLeft[ci] -= 1.0;
            if (pcCgbLenLeft[ci] <= 0.0)
                continue;
        }
        if (type == 1 || type == 2)
        {
            Pc_CgbHwEnvClock(ci, rate);
            if (type == 1)
            {
                Pc_CgbSweepClock(chan, rate);
                if (pcCgbSweepMuted)
                    continue;
            }
            sample = Pc_CgbSquareSample(ci, chan, rate);
            sample = (sample * pcCgbHwEnvVolume[ci]) >> 4;
        }
        else if (type == 3)
        {
            sample = Pc_CgbWaveSample(ci, chan, rate);
        }
        else
        {
            Pc_CgbHwEnvClock(ci, rate);
            sample = Pc_CgbNoiseSample(ci, chan, rate);
            sample = (sample * pcCgbHwEnvVolume[ci]) >> 4;
        }
        sample >>= 1;
        if (type == 3)
            pcCgbDeclickSample[ci] = sample;
        if (allowL)
            mixL[i] += (float)sample;
        if (allowR)
            mixR[i] += (float)sample;
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
    Pc_CgbHardwareReset();
    SDL_PauseAudioDevice(sAudioDev, 0);
#endif
}

int Pc_AudioRate(void)
{
    return sAudioRate;
}

// The reverb amount the current song's m4a sound mode selected (0-127),
// before any user reverb override. For the settings UI's info line.
int Pc_AudioSongReverb(void)
{
    return Pc_Reverb();
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
    float dsL[PC_AUDIO_BLOCK_MAX];
    float dsR[PC_AUDIO_BLOCK_MAX];
    float cgbL[PC_AUDIO_BLOCK_MAX];
    float cgbR[PC_AUDIO_BLOCK_MAX];
    short out[PC_AUDIO_BLOCK_MAX * 2];
    int reverb;
    int i;
    unsigned int ci;
    if (sAudioDev == 0)
        return;
    if (n < 1)
        return;
    if (n > PC_AUDIO_BLOCK_MAX)
        n = PC_AUDIO_BLOCK_MAX;
    if (pcRevLen == 0)
        Pc_CgbHardwareReset();
    for (i = 0; i < n; i++)
        dsL[i] = dsR[i] = cgbL[i] = cgbR[i] = 0.0f;
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
            Pc_RenderDs(&chans[ci], (int)ci, dsL, dsR, n, sAudioRate);
        cgbs = Pc_CgbChans(&ncgb);
        for (ci = 0; ci < ncgb && ci < 4; ci++)
            Pc_RenderCgb(&cgbs[ci], (int)ci, cgbL, cgbR, n, sAudioRate);
    }
    // Reverb: GBA SoundMainRAM_Reverb. DS-only feedback comb, four taps
    // (L/R at the current and one-VBlank-ahead positions), mono wet summed
    // into both channels. The DS mix lives in the GBA's 8-bit buffer domain:
    // it is clamped to +/-127 (the hardware buffer saturates there), which is
    // also what keeps the output consistently loud regardless of polyphony.
    // The user can override the song's reverb or disable it entirely.
    {
        PcAudioPrefs *ap = Pc_ConfigAudioPrefs();
        reverb = 0;
        if (ap->reverbMode == 2)
            reverb = ap->reverbOverride & 0x7F;
        else if (ap->reverbMode != 0)
            reverb = Pc_Reverb();
    }
    {
        PcAudioPrefs *ap = Pc_ConfigAudioPrefs();
        float vol = ap->muted ? 0.0f : ((float)ap->masterVolume / 100.0f);
        float lpA = 0.0f;
        if (ap->lowPass)
        {
            float fc = (float)ap->lowPassCutoff;
            if (fc < 50.0f)
                fc = 50.0f;
            if (fc > (float)sAudioRate * 0.45f)
                fc = (float)sAudioRate * 0.45f;
            lpA = 1.0f - expf(-2.0f * 3.14159265358979323846f * fc
                              / (float)sAudioRate);
        }
        if (lpA == 0.0f)
        {
            pcLpL = 0.0f;
            pcLpR = 0.0f;
        }
    for (i = 0; i < n; i++)
    {
        int il = (int)dsL[i];
        int ir = (int)dsR[i];
        if (il > 127) il = 127; else if (il < -128) il = -128;
        if (ir > 127) ir = 127; else if (ir < -128) ir = -128;
        if (reverb > 0)
        {
            int other = (int)pcRevPos + pcRevFrame;
            int sum;
            int wet;
            if (other >= pcRevLen)
                other -= pcRevLen;
            sum = pcRevL[pcRevPos] + pcRevR[pcRevPos]
                + pcRevL[other] + pcRevR[other];
            wet = (sum * reverb) >> 9;
            il += wet;
            ir += wet;
            if (il > 127) il = 127; else if (il < -128) il = -128;
            if (ir > 127) ir = 127; else if (ir < -128) ir = -128;
            pcRevL[pcRevPos] = (signed char)il;
            pcRevR[pcRevPos] = (signed char)ir;
            pcRevPos++;
            if (pcRevPos >= (unsigned)pcRevLen)
                pcRevPos = 0;
        }
        // PSG channels are hardware voices added after the PCM buffer, so
        // they are mixed dry on top of the reverb tail.
        {
            float l = (float)il + cgbL[i];
            float r = (float)ir + cgbR[i];
            // Bring the GBA 8-bit-scale mix up to a normal 16-bit loudness,
            // then apply the user master volume.
            l *= (float)PC_MASTER_GAIN * vol;
            r *= (float)PC_MASTER_GAIN * vol;
            // Soft knee: keep the top of the range musical instead of hard
            // clipping when DS saturation + PSG + reverb push past 16 bits.
            if (l > 32767.0f * PC_SATURATE)
                l = 32767.0f * PC_SATURATE + (32767.0f - 32767.0f * PC_SATURATE)
                    * tanhf((l - 32767.0f * PC_SATURATE) / (32767.0f * (1.0f - PC_SATURATE)));
            else if (l < -32768.0f * PC_SATURATE)
                l = -32768.0f * PC_SATURATE - (32768.0f - 32768.0f * PC_SATURATE)
                    * tanhf((-l - 32768.0f * PC_SATURATE) / (32768.0f * (1.0f - PC_SATURATE)));
            if (r > 32767.0f * PC_SATURATE)
                r = 32767.0f * PC_SATURATE + (32767.0f - 32767.0f * PC_SATURATE)
                    * tanhf((r - 32767.0f * PC_SATURATE) / (32767.0f * (1.0f - PC_SATURATE)));
            else if (r < -32768.0f * PC_SATURATE)
                r = -32768.0f * PC_SATURATE - (32768.0f - 32768.0f * PC_SATURATE)
                    * tanhf((-r - 32768.0f * PC_SATURATE) / (32768.0f * (1.0f - PC_SATURATE)));
            if (lpA > 0.0f)
            {
                l = pcLpL + lpA * (l - pcLpL);
                pcLpL = l;
                r = pcLpR + lpA * (r - pcLpR);
                pcLpR = r;
            }
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
    }
    }
    // Bound queue latency: drop (don't pile up) past ~1 s, e.g. during
    // unpaced boot pumps that run hundreds of frames per second.
    if (SDL_GetQueuedAudioSize(sAudioDev) <= (Uint32)(sAudioRate * 4))
        SDL_QueueAudio(sAudioDev, out, (Uint32)(n * 4));
    if (sWavFile != NULL)
    {
        int nw = n;
        if (nw > sWavMaxSamples)
            nw = sWavMaxSamples;
        if (nw > 0)
        {
            fwrite(out, 2, (size_t)nw * 2, sWavFile);
            sWavDataBytes += (long)nw * 4;
            sWavMaxSamples -= nw;
        }
        if (sWavMaxSamples <= 0)
        {
            long total = sWavDataBytes + 36;
            fseek(sWavFile, 4, SEEK_SET);
            fputc((int)(total & 0xFF), sWavFile);
            fputc((int)((total >> 8) & 0xFF), sWavFile);
            fputc((int)((total >> 16) & 0xFF), sWavFile);
            fputc((int)((total >> 24) & 0xFF), sWavFile);
            fseek(sWavFile, 40, SEEK_SET);
            fputc((int)(sWavDataBytes & 0xFF), sWavFile);
            fputc((int)((sWavDataBytes >> 8) & 0xFF), sWavFile);
            fputc((int)((sWavDataBytes >> 16) & 0xFF), sWavFile);
            fputc((int)((sWavDataBytes >> 24) & 0xFF), sWavFile);
            fclose(sWavFile);
            sWavFile = NULL;
        }
    }
#endif
}

void Pc_AudioWavDump(const char *path, int maxSeconds)
{
#ifdef HAVE_SDL2
    unsigned char hdr[44];
    unsigned int br;
    if (sWavFile != NULL)
    {
        fclose(sWavFile);
        sWavFile = NULL;
    }
    if (path == NULL || maxSeconds <= 0)
        return;
    sWavFile = fopen(path, "wb");
    if (sWavFile == NULL)
        return;
    sWavMaxSamples = sAudioRate * maxSeconds;
    sWavDataBytes = 0;
    memset(hdr, 0, sizeof(hdr));
    memcpy(hdr, "RIFF", 4);
    memcpy(hdr + 8, "WAVEfmt ", 8);
    hdr[16] = 16;
    hdr[20] = 1;
    hdr[22] = 2;
    br = (unsigned int)sAudioRate;
    hdr[24] = (unsigned char)(br & 0xFF);
    hdr[25] = (unsigned char)((br >> 8) & 0xFF);
    hdr[26] = (unsigned char)((br >> 16) & 0xFF);
    hdr[27] = (unsigned char)((br >> 24) & 0xFF);
    br *= 4;
    hdr[28] = (unsigned char)(br & 0xFF);
    hdr[29] = (unsigned char)((br >> 8) & 0xFF);
    hdr[30] = (unsigned char)((br >> 16) & 0xFF);
    hdr[31] = (unsigned char)((br >> 24) & 0xFF);
    hdr[32] = 4;
    hdr[34] = 16;
    memcpy(hdr + 36, "data", 4);
    fwrite(hdr, 1, 44, sWavFile);
#else
    (void)path;
    (void)maxSeconds;
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
        {
            chan->modify = 0;
            continue;
        }
        if (chan->statusFlags & SOUND_CHANNEL_SF_START)
        {
            if (chan->statusFlags & SOUND_CHANNEL_SF_STOP)
            {
                chan->statusFlags = 0;
                chan->modify = 0;
                continue;
            }
            chan->statusFlags = SOUND_CHANNEL_SF_ENV_ATTACK;
            chan->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
            Pc_CgbModVol(chan);
            pcCgbEnvStepDir[c] = (u8)((chan->attack & 7) | 0x08);
            // Renderer-side voice start: squares free-run; the wave restarts
            // only when its table changes (hardware wave-RAM reload); arm the
            // length timer. Length loads: square/noise (64 - 6-bit), wave
            // (256 - 8-bit).
            if (ch == 3)
            {
                if (pcCgbLastWave[c] != gPcChanRefA[12 + c])
                    pcCgbPhase[c] = 0;
                else
                    pcCgbPhase[c] &= 0xF8000000u;
                pcCgbLastWave[c] = gPcChanRefA[12 + c];
            }
            if (chan->length)
                pcCgbLenLeft[c] = ((ch == 3) ? (double)(256 - (chan->length & 0xFF))
                                             : (double)(64 - (chan->length & 0x3F)))
                                * (sAudioRate / 256.0);
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
                chan->modify = 0;
                continue;
            }
            goto cgb_frame_done;
        }
        else if ((chan->statusFlags & SOUND_CHANNEL_SF_STOP)
                 && (chan->statusFlags & SOUND_CHANNEL_SF_ENV))
        {
            chan->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
            chan->envelopeCounter = chan->release;
            pcCgbEnvStepDir[c] = (u8)(chan->release & 7);
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
                pcCgbEnvStepDir[c] = 0x08;
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
        pcCgbEnvStepDir[c] = (u8)(chan->decay & 7);
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
            pcCgbEnvStepDir[c] = 0x08;
            chan->envelopeVolume = chan->sustainGoal;
            chan->envelopeCounter = 7;
        }
        goto cgb_step_done_default;
    cgb_echo_start:
        pcCgbEnvStepDir[c] = 0x08;
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
        if (chan->statusFlags & SOUND_CHANNEL_SF_ON)
            Pc_CgbApplyModify(c, chan);
        chan->modify = 0;
    }
}
