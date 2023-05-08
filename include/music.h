#ifndef GUARD_MUSIC_H
#define GUARD_MUSIC_H

// PMD keeps it's own copy of music players for some reason
struct PMDMusicPlayer
{
    u16 unk0;
    u16 songIndex;
    u16 volume;
    bool8 isNotMaxVolume;
};

void StopBGMusicVSync(void);
void StartBGMusicVSync(void);
bool8 IsValidSong(u32 songIndex);
void StartNewBGM(u16 songIndex);
bool8 IsBGSong(u32 songIndex);
bool8 IsSoundEffect(u32 songIndex);
bool8 IsFanfare(u32 songIndex);
u16 GetMusicPlayerIndex(u16 songIndex);
bool8 IsMusicPlayerPlaying(u16 songIndex);
void StartNewBGM(u16 songIndex);
void FadeInNewBGM(u16 songIndex, u16 speed);
u16 GetCurrentBGSong(void);
void QueueBGM(u16 songIndex);
void StopBGM(void); // stops all BGM, fanfares and SE's
void FadeOutBGM(u16 speed);
void PlayFanfareSE(u16 songIndex, u16 volume);
void StopFanfareSE(u16 songIndex);
void FadeOutFanfareSE(u16 songIndex, u16 speed);
bool8 IsFanfareSEPlaying(u16 songIndex);
void SoundBiasReset(void);
void SoundBiasSet(void);
void UpdateSound(void);
void SoundVSync(void);
void nullsub_18(void);

void nullsub_19(void);
void nullsub_20(u16 songIndex);

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
};

// TODO: continue to doc the rest of BG/Fanfare Player States
enum BG_Player_State
{
    BG_PLAYER_STATE_INITIALIZE = 0,
    BG_PLAYER_STATE_PLAYING = 1,
    BG_PLAYER_STATE_STOPPED = 4,
};

enum Fanfare_Player_State
{
    FANFARE_PLAYER_STATE_INITIALIZE = 0,
    FANFARE_PLAYER_STATE_PLAYING = 3,
};

#endif //GUARD_MUSIC_H
