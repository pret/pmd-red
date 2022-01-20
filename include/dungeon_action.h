#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "dungeon_entity.h"

// 0x44C94
void SetAction(struct DungeonActionContainer *actionPointer, u16 action);
// 0x44CA0
void SetWalkAction(struct DungeonActionContainer *actionPointer, s16 species);

#endif
