#ifndef GUARD_MUSIC_H
#define GUARD_MUSIC_H

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
void FadeInNewBGM(u16 SongIndex, u16 speed);
u16 GetCurrentBGSong(void);
void sub_800BF48(u16 SongIndex);
void sub_800BF80(void);
void FadeOutBGM(u16 speed);
void sub_800C074(u16 SongIndex, u16 param_2);
void sub_800C298(u16 songIndex);
void sub_800C3F8(u16 songIndex, u16 speed);

void nullsub_19(void);
void nullsub_20(u16 songIndex);

enum GetMusicPlayerIndex
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

enum BG_Player_State
{
    BG_PLAYER_STATE_INITIALIZE = 0,
    BG_PLAYER_STATE_PLAYING = 1,
    BG_PLAYER_STATE_STOPPED = 4,
};

#endif //GUARD_MUSIC_H
