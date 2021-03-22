#ifndef GUARD_MUSIC_H
#define GUARD_MUSIC_H

void StopBGMusicVSync(void);
void StartBGMusicVSync(void);
u8 sub_800CA38(u32 songIndex);
void StartNewBGM(u16 songIndex);
bool8 IsBGSong(u32 songIndex);
bool8 sub_800CAAC(u32 songIndex);
bool8 sub_800CACC(u32 songIndex);
u16 sub_800CAE0(u16 songIndex);
bool8 sub_800CAF0(u16 songIndex);
void StartNewBGM(u16 songIndex);
void FadeInNewBGM(u16 SongIndex, u16 speed);
u16 GetCurrentBGSong(void);
void sub_800BF48(u16 SongIndex);
void sub_800BF80(void);
void FadeOutBGM(u16 speed);
void sub_800C074(u16 SongIndex, u16 param_2);

void nullsub_19(void);
void nullsub_20(u16 songIndex);

#endif //GUARD_MUSIC_H
