#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "dungeon_entity.h"

void ResetAction(struct DungeonActionContainer *actionPointer);
void SetAction(struct DungeonActionContainer *actionPointer, u16 action);
void SetWalkAction(struct DungeonActionContainer *actionPointer, s16 species);

#endif
