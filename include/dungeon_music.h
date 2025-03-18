#ifndef GUARD_DUNGEON_MUSIC_H
#define GUARD_DUNGEON_MUSIC_H

u16 DungeonGetCurrentBGSong(void);
void DungeonFadeInNewBGM(u16 songIndex, u32 fadeInSpeed);
void DungeonFadeOutBGM(u16 speed);
void DungeonStartNewBGM(u16 songIndex);
void DungeonStopBGM(void);
bool8 IsFanfareSEPlaying_2(u16 songIndex);
void PlayDungeonCursorSE(bool8 checkMenuEntriesCount);
void PlayDungeonStartButtonSE(void);
void PlaySoundEffect(u32 songIndex);
void StopDungeonBGM(void);
void StopSoundEffect(u32 songIndex);
void sub_8083AB0(s16 param_0, Entity *target, Entity *entity);
bool8 sub_8083C24(void);
bool8 sub_8083C50(void);
bool8 sub_8083C88(u8);
void UpdateDungeonMusic(void);

#endif // GUARD_DUNGEON_MUSIC_H
