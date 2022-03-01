#ifndef GUARD_STATUS_CHECKER_H
#define GUARD_STATUS_CHECKER_H

#include "constants/move.h"
#include "dungeon_entity.h"

// 0x5C498
bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move);
// 0x5CEB8
bool8 CanUseOnTargetWithStatusChecker(struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move);
// 0x5D810
bool8 HasDisabledMove(struct PokemonMove *moves);

#endif
