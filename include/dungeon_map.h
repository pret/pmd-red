#ifndef GUARD_DUNGEON_MAP_H
#define GUARD_DUNGEON_MAP_H

extern bool8 gUnknown_202EE00;
extern bool8 gShowDungeonMap;

void SetDungeonMapToNotShown(void);
void OpenDungeonMapFile(void);
void InitDungeonMap(bool8 a0);
void CloseDungeonMapFile(void);
void LoadDungeonMapPalette(void);
void sub_80402AC(s32 x, s32 y);
void sub_8040788(void);
void ShowPlayerDotOnMap(void);
void ResetMapPlayerDotFrames(void);
void sub_8040A84(void);
void sub_8040ABC(bool8 a0);
void sub_8040B60(void);

#endif
