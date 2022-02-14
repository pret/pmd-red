#ifndef GUARD_TARGETING_FLAGS_H
#define GUARD_TARGETING_FLAGS_H

#include "constants/move.h"
#include "dungeon_entity.h"

// 0x7CD64
s16 GetMoveTargetingFlagsForPokemon(struct DungeonEntity *pokemon, struct PokemonMove *move, u32 isAI);

#endif
