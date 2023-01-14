#ifndef GUARD_DUNGEON_AI_ATTACK_H
#define GUARD_DUNGEON_AI_ATTACK_H

#include "dungeon_entity.h"

#define RANGED_ATTACK_RANGE 10

struct AIPossibleMove
{
    bool8 canBeUsed;
    u8 direction;
    s32 weight;
};

void DecideAttack(struct Entity *pokemon);
s32 AIConsiderMove(struct AIPossibleMove *aiPossibleMove, struct Entity *pokemon, struct Move *move);
bool8 IsTargetInLineRange(struct Entity *user, struct Entity *target, s32 range);
s32 TryAddTargetToAITargetList(s32 numPotentialTargets, s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, u32 hasStatusChecker);
bool8 IsAITargetEligible(s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, bool32 hasStatusChecker);
s32 WeightMove(struct Entity *user, s32 targetingFlags, struct Entity *target, u32 moveType);
bool8 TargetRegularAttack(struct Entity *pokemon, u32 *targetDir, bool8 checkPetrified);
bool8 IsTargetInRange(struct Entity *pokemon, struct Entity *targetPokemon, s32 direction, s32 maxRange);

#endif
