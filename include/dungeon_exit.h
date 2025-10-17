#ifndef GUARD_DUNGEON_EXIT_H
#define GUARD_DUNGEON_EXIT_H

#include "structs/dungeon_entity.h"

void SetUpDungeonExitData(s16 dungeonExitReason, Entity *target, Entity *entity);
bool8 IsUnsuccessfulDungeonExit(void);
bool8 sub_8083C50(void);
bool8 sub_8083C88(u8 param_1);

#endif // GUARD_DUNGEON_EXIT_H
