#ifndef GUARD_MUSIC_H
#define GUARD_MUSIC_H

#define NUM_FANFARES 19
#define FANFARE_START_INDEX 200

#define NUM_SOUND_EFFECTS 639
#define SOUND_EFFECTS_START_INDEX 300

#define STOP_SOUND_EFFECT 997
#define STOP_FANFARE 998
#define STOP_BGM 999

#define MAX_VOLUME 256

enum MusicPlayerIndex
{
    INDEX_BGM,
    INDEX_FANFARE,
    INDEX_SE1,
    INDEX_SE2,
    INDEX_SE3,
    INDEX_SE4,
    INDEX_SE5,
    INDEX_SE6,
    MUSIC_PLAYERS_COUNT
};

// TODO: continue to doc the rest of BG/Fanfare Player States
enum BG_Player_State
{
    BG_PLAYER_STATE_INITIALIZE,
    BG_PLAYER_STATE_PLAYING,
    // 2 - 3
    BG_PLAYER_STATE_STOPPED = 4,
};

enum Fanfare_Player_State
{
    FANFARE_PLAYER_STATE_INITIALIZE,
    // 1 - 2
    FANFARE_PLAYER_STATE_PLAYING = 3,
};

// size: 0x8. PMD keeps its own copy of music players for some reason
typedef struct PMDMusicPlayer
{
    u16 unk0;
    u16 songIndex;
    u16 volume;
    bool8 isNotMaxVolume;
} PMDMusicPlayer;

void FadeInNewBGM(u16 songIndex, u16 speed);
void FadeOutBGM(u16 speed);
void FadeOutFanfareSE(u16 songIndex, u16 speed);
u16 GetCurrentBGSong(void);
void InitMusic(void);
bool8 IsFanfareSEPlaying(u16 songIndex);
void nullsub_18(void);
void PlayFanfareSE(u16 songIndex, u16 volume);
void QueueBGM(u16 songIndex);
void SoundVSync(void);
void StartBGMusicVSync(void);
void StartNewBGM(u16 songIndex);
void StopBGM(void); // Stops all BGM, fanfares and SE's
void StopBGMusicVSync(void);
void StopFanfareSE(u16 songIndex);
void UpdateSound(void);

// libagbsyscall
extern void SoundBiasReset(void);
extern void SoundBiasSet(void);

#endif //GUARD_MUSIC_H
