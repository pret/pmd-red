// platform/pc/audio_data.h — host audio data model (native PC port).
//
// Describes the C arrays emitted by platform/pc/tools/gen_audio.py from the
// game's own m4a sources (sound/songs, sound/voicegroups, sound/wave).
// This is NOT emulation: the data is parsed at build time into native host
// tables; the engine in m4a_port.c/audio_pc.c interprets the track byte
// streams with the same semantics as the GBA player (see MPlayMain in
// src/m4a_1.s) and renders PCM to SDL audio.
//
// Binary contract (fixed by the generator, must match m4a_port.c):
//  - Track streams are raw m4a command bytes. Every `.word` address in a
//    track (PATT/GOTO targets) is emitted as a 4-byte little-endian offset
//    from the start of THAT track's stream (intra-song only; asserted).
//  - Voice/wave/song references are resolved at build time to integer
//    indices below (no pointers, no relocations in the emitted data).
#ifndef PMDRED_PC_AUDIO_DATA_H
#define PMDRED_PC_AUDIO_DATA_H

// ---- Waveforms ----
typedef struct PcWave
{
    unsigned short type;
    unsigned short status;
    unsigned int freq;      // mid-C base pitch, same units as WaveData.freq
    unsigned int loopStart; // inclusive sample index
    unsigned int loopEnd;   // exclusive sample index; validated: start<=end<=length
    unsigned int length;    // total s8 PCM samples
    unsigned int loop;      // nonzero when status & 0xC0 (WAVE_DATA_FLAG_LOOP)
    const signed char *data;
} PcWave;

// 16-byte 4-bit programmable wave (GBA wave RAM format: 32 nibbles).
typedef struct PcGbWave
{
    unsigned char data[16];
} PcGbWave;

// ---- Voices ----
enum PcVoiceRef
{
    PC_VOICE_WAVE = 0,  // DirectSound: refA = PcWave index
    PC_VOICE_GBWAVE,    // AProgWave:   refA = PcGbWave index
    PC_VOICE_DUTY,      // square:      refA = WaveDuty12/25/50/75 (0..3)
    PC_VOICE_KEYMAP,    // KeySplit:    refA = voice-group index, refB = key-map index
    PC_VOICE_DRUMS      // DrumTable:   refA = drums voice-group index
};

typedef struct PcVoice
{
    unsigned char type; // raw m4a voice type (DirectSound/KeySplit/...)
    unsigned char key;  // root key (midi number, Cn3 = 60)
    unsigned char p2;   // ToneData.length / reserved
    unsigned char p3;   // ToneData.pan_sweep / reserved
    unsigned char refKind; // enum PcVoiceRef
    unsigned char _pad;
    unsigned short refA;
    unsigned short refB;
    unsigned char attack;
    unsigned char decay;
    unsigned char sustain;
    unsigned char release;
} PcVoice;

// One voice group (bank_xxx or drums_xxx): contiguous voice array.
typedef struct PcVoiceGroup
{
    const char *name; // e.g. "bank_000" (debug only)
    unsigned int count;
    const PcVoice *voices;
} PcVoiceGroup;

// 128-entry key -> sub-voice index map (KeySplit).
typedef struct PcKeyMap
{
    const char *name;
    unsigned int length;
    const unsigned char *keys;
} PcKeyMap;

// ---- Songs ----
#define PC_SONG_MAX_PARTS 16

typedef struct PcSong
{
    unsigned char trackCount;
    unsigned char blockCount;
    unsigned char priority;
    unsigned char reverb;   // includes SOUND_MODE_REVERB_SET bit, as on GBA
    unsigned char toneBank; // index into pcVoiceGroups[]
    unsigned char nParts;
    unsigned char _pad[2];
    const unsigned char *parts[PC_SONG_MAX_PARTS];
    unsigned short partLen[PC_SONG_MAX_PARTS];
} PcSong;

// NOTE: gSongTable keeps the real `struct Song` type (see gba/m4a_internal.h)
// because game code (src/music.c) reads `.ms` off that symbol. ONLY
// m4a_port.c may interpret `.header`, via Pc_SongHeader().
extern const PcSong *Pc_SongHeader(const void *songHeader);

// ---- Generated tables (defined in build/bin/gen/audio_data.c) ----
extern const PcWave *Pc_Waves(unsigned int *countOut);
extern const PcGbWave *Pc_GbWaves(unsigned int *countOut);
extern const PcVoiceGroup *Pc_VoiceGroups(unsigned int *countOut);
extern const PcKeyMap *Pc_KeyMaps(unsigned int *countOut);
extern const PcSong *Pc_Songs(unsigned int *countOut);

#endif // PMDRED_PC_AUDIO_DATA_H
