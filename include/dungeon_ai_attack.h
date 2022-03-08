#ifndef GUARD_DUNGEON_AI_ATTACK_H
#define GUARD_DUNGEON_AI_ATTACK_H

#include "dungeon_entity.h"

#define RANGED_ATTACK_RANGE 10

struct MoveTargetResults
{
    bool8 moveUsable;
    u8 targetDir;
    s32 moveWeight;
};

void DecideAttack(struct DungeonEntity *pokemon);
s32 FindMoveTarget(struct MoveTargetResults *moveTargetResults, struct DungeonEntity *pokemon, struct PokemonMove *move);
bool8 IsTargetInLineRange(struct DungeonEntity *user, struct DungeonEntity *target, s32 range);
s32 WeightMoveIfUsable(s32 numPotentialTargets, s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, u32 hasStatusChecker);
bool8 CanUseStatusMove(s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool32 hasStatusChecker);
s32 WeightMove(struct DungeonEntity *user, s32 targetingFlags, struct DungeonEntity *target, u32 moveType);

#endif
