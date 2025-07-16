#ifndef GUARD_DUNGEON_MAP_H
#define GUARD_DUNGEON_MAP_H

#include "structs/str_position.h"

extern bool8 gShowMonsterDotsInDungeonMap;
extern bool8 gShowDungeonMap;
extern DungeonPos gPlayerDotMapPosition;

void SetDungeonMapToNotShown(void);
void OpenDungeonMapFile(void);
void InitDungeonMap(bool8 a0);
void CloseDungeonMapFile(void);
void LoadDungeonMapPalette(void);
void DrawMinimapTile(s32 x, s32 y);
void CopyDungeonMapToVram(void);
void FlashLeaderIcon(void);
void ResetMapPlayerDotFrames(void);
void UpdateMinimap(void);
void UpdateBgTilemapForDungeonMap(bool8 a0);
void TryResetDungeonMapTilesScheduledForCopy(void);

#endif
