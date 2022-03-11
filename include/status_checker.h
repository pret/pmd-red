#ifndef GUARD_STATUS_CHECKER_H
#define GUARD_STATUS_CHECKER_H

#include "constants/move.h"
#include "dungeon_entity.h"

bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move);
bool8 CanUseOnTargetWithStatusChecker(struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move);
bool8 HasDisabledMove(struct PokemonMove *moves);
bool8 LastUsedMoveOutOfPP(struct PokemonMove *moves);
bool8 HasLastUsedMove(struct PokemonMove *moves);

#endif
