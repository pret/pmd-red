#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "dungeon_entity.h"

void ClearMonsterActionFields(struct ActionContainer *actionPointer);
void SetMonsterActionFields(struct ActionContainer *actionPointer, u16 action);
void SetActionPassTurnOrWalk(struct ActionContainer *actionPointer, s16 species);

#endif
