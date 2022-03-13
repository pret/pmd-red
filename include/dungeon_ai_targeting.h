#ifndef GUARD_DUNGEON_AI_TARGETING_H
#define GUARD_DUNGEON_AI_TARGETING_H

#include "dungeon_entity.h"

bool8 CanAttackInFront(struct DungeonEntity *pokemon, s32 direction);
bool8 CanMoveForward(struct DungeonEntity *pokemon, s32 facingDir, bool8 *pokemonInFront);

#endif
