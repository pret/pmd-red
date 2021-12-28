#ifndef GUARD_DUNGEON_AI_ATTACK_H
#define GUARD_DUNGEON_AI_ATTACK_H

#include "dungeon_entity.h"

// 0x7C9F8
bool8 IsTargetStraightAhead(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, s32 facingDir, s32 maxRange);

#endif
