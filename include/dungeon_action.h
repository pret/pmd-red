#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "structs/dungeon_entity.h"

void sub_8044C50(u16 action);
void ClearMonsterActionFields(ActionContainer *actionPointer);
void SetMonsterActionFields(ActionContainer *actionPointer, u16 action);
void SetActionPassTurnOrWalk(ActionContainer *actionPointer, s16 species);

#endif
