#ifndef GUARD_DUNGEON_LIST_MENU_H
#define GUARD_DUNGEON_LIST_MENU_H

#include "structs/str_position.h"

bool8 DungeonListMenu_Init(u32 windowId, DungeonPos *winPos, s32 perPageCount, bool8 showIcons);
bool8 DungeonListMenu_MoveMenuTo(s32 _rescueDungeonId);
u32 DungeonListMenu_GetInput(u8 arrowType);
s16 DungeonListMenu_GetCurrentRescueDungeonId(void);
void DungeonListMenu_Free(void);
bool8 HasZeroAvailableDungeons(void);

#endif
