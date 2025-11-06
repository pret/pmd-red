#ifndef GUARD_DUNGEON_AI_ATTACK_H
#define GUARD_DUNGEON_AI_ATTACK_H

#include "structs/dungeon_entity.h"

#define RANGED_ATTACK_RANGE 10

// size: 0x8
struct AIPossibleMove
{
    bool8 canBeUsed;
    u8 direction;
    s32 weight;
};

void ChooseAIMove(Entity *pokemon);
s32 AIConsiderMove(struct AIPossibleMove *aiPossibleMove, Entity *pokemon, Move *move);
bool8 IsTargetInRange(Entity *pokemon, Entity *targetPokemon, s32 direction, s32 maxRange);
void HandleUseMoveAIAction(Entity *target);
void HandleUseOrbAction(Entity *pokemon);
s16 GetMoveTargetAndRangeForPokemon(Entity *pokemon, Move *move, bool32 isAI);

#endif
