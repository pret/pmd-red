#ifndef GUARD_DUNGEON_MUSIC_H
#define GUARD_DUNGEON_MUSIC_H

void PlayDungeonCursorSE(bool8 checkMenuEntriesCount);
void PlayDungeonConfirmationSE(void);
void sub_8083D1C(void);
void PlayDungeonCancelSE(void);
void PlayDungeonStartButtonSE(void);
void sub_8083D58(void);
void sub_8083D68(void);
void sub_8083D78(void);
void sub_8083D88(void);
void PlayDungeonFailBGM(void);
void PlayDungeonCompleteBGM(void);
void sub_8083E28(void);
void PlaySoundEffect(u32 songIndex);
void StopSoundEffect(u32 songIndex);
bool8 IsFanfareSEPlaying_2(u16 songIndex);
void DungeonStartNewBGM(u16 songIndex);
void DungeonFadeInNewBGM(u16 songIndex, u32 fadeInSpeed);
void DungeonFadeOutBGM(u16 speed);
void DungeonStopBGM(void);
void StopDungeonBGM(void);
void UpdateDungeonMusic(void);

#endif // GUARD_DUNGEON_MUSIC_H
