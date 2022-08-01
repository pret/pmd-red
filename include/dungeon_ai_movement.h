#ifndef GUARD_DUNGEON_AI_MOVEMENT_H
#define GUARD_DUNGEON_AI_MOVEMENT_H

#include "dungeon_entity.h"

void MoveIfPossible(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);
bool8 CanTakeItem(struct DungeonEntity *pokemon);

#endif
