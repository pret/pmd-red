#ifndef GUARD_STATUS_CHECKER_H
#define GUARD_STATUS_CHECKER_H

#include "constants/move.h"
#include "dungeon_entity.h"

// 0x5C498
bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move);

#endif
