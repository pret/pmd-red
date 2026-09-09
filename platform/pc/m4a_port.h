// platform/pc/m4a_port.h — host m4a player interface (chunks 2+3).
//
// m4a_port.c implements the m4a API (include/m4a.h) natively and advances the
// eight music players. audio_pc.c (chunk 3) renders the resulting channel
// state to SDL audio; the declarations below are its read interface.
#ifndef PMDRED_PC_M4A_PORT_H
#define PMDRED_PC_M4A_PORT_H

#include "gba/m4a_internal.h"
#include "audio_data.h"

// Advance all players one 60 Hz frame (called by m4aSoundMain).
void Pc_AudioTick(void);

// Render n samples of audio (defined in audio_pc.c; called by m4aSoundMain
// after Pc_AudioTick, mirroring scheduler -> mixer order). stepEnvelope != 0
// steps the envelopes for one 60 Hz tick; 0 renders a partial sub-tick with
// the current channel state (keeps the host queue fed at the device rate
// regardless of the game frame rate).
void Pc_MixerRenderSamples(int n, int stepEnvelope);

// Host audio device rate in samples/sec and a monotonic clock (seconds).
int Pc_AudioRate(void);
double Pc_TimeNow(void);

// Capture the rendered mix to a 16-bit stereo WAV (path NULL disables).
void Pc_AudioWavDump(const char *path, int maxSeconds);

// Nonzero while the sound engine is halted (VSync off: freeze + silence,
// like halted GBA DMA).
int Pc_AudioHalted(void);

// Live channel state for the renderer.
struct SoundChannel *Pc_SoundChans(unsigned *countOut);
struct CgbChannel *Pc_CgbChans(unsigned *countOut);

// Voice selected by a track / behind a sounding channel (NULL if none).
const PcVoice *Pc_TrackVoice(const struct MusicPlayerInfo *info,
                             const struct MusicPlayerTrack *track);
const PcVoice *Pc_ChanVoice(const struct SoundChannel *chan);

// Mixer parameters.
u8 Pc_MasterVolume(void);
u16 Pc_SamplesPerVBlank(void);
u8 Pc_Reverb(void);
u8 Pc_FreqIdx(void);
s32 Pc_PcmFreq(void);
s32 Pc_DivFreq(void);

// Pitch helpers (adapted from m4a.c).
u32 Pc_MidiKeyToFreq(const PcWave *wav, u8 key, u8 fineAdjust);
u32 Pc_MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust);

// Per-channel voice reference set at note-on (flat 0-11 DS, 12-15 CGB).
extern u8 gPcChanRefKind[16];
extern u16 gPcChanRefA[16];

#endif // PMDRED_PC_M4A_PORT_H
