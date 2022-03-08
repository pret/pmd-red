#ifndef GUARD_DUNGEON_AI_ATTACK_1_H
#define GUARD_DUNGEON_AI_ATTACK_1_H

#include "dungeon_entity.h"

bool8 IsTargetStraightAhead(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, s32 facingDir, s32 maxRange);

#endif
