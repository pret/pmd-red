#ifndef GUARD_DUNGEON_MUSIC_H
#define GUARD_DUNGEON_MUSIC_H

void PlaySoundEffect(u32 songIndex);
void StopSoundEffect(u32 songIndex);
bool8 IsFanfareSEPlaying_2(u16 songIndex);
void DungeonStartNewBGM(u16 songIndex);
void DungeonFadeInNewBGM(u16 songIndex, u32 fadeInSpeed);
void DungeonFadeOutBGM(u16 speed);
void DungeonStopBGM(void);
u16 DungeonGetCurrentBGSong(void);
void StopDungeonBGM(void);
void UpdateDungeonMusic(void);

#endif

