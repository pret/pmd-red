#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "dungeon_entity.h"

void ClearMonsterActionFields(struct DungeonActionContainer *actionPointer);
void SetMonsterActionFields(struct DungeonActionContainer *actionPointer, u16 action);
void SetActionPassTurnOrWalk(struct DungeonActionContainer *actionPointer, s16 species);

#endif
