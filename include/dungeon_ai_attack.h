#ifndef GUARD_DUNGEON_AI_ATTACK_H
#define GUARD_DUNGEON_AI_ATTACK_H

#include "dungeon_entity.h"

struct MoveTargetResults
{
    bool8 moveUsable;
    u8 targetDir;
    s32 moveWeight;
};

// 0x7BB94
void DecideAttack(struct DungeonEntity *pokemon);
// 0x7C04C
s32 FindMoveTarget(struct MoveTargetResults *moveTargetResults, struct DungeonEntity *pokemon, struct PokemonMove *move);

#endif
