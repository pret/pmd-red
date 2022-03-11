#ifndef GUARD_DUNGEON_CAPABILITIES_1_H
#define GUARD_DUNGEON_CAPABILITIES_1_H

#include "dungeon_entity.h"

bool8 CannotUseItems(struct DungeonEntity *pokemon);
bool8 CannotAct(struct DungeonEntity *pokemon);
bool8 CannotAttack(struct DungeonEntity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(struct DungeonEntity *pokemon, u32 facingDir);

#endif
