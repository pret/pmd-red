#ifndef GUARD_DUNGEON_AI_ATTACK_1_H
#define GUARD_DUNGEON_AI_ATTACK_1_H

#include "dungeon_entity.h"

// 0x7C580
s32 WeightMoveIfUsable(s32 numPotentialTargets, s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, u32 hasStatusChecker);
// 0x7C648
bool8 CanUseStatusMove(s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool32 hasStatusChecker);
// 0x7C7AC
s32 WeightMove(struct DungeonEntity *user, s32 targetingFlags, struct DungeonEntity *target, u32 moveType);

#endif
