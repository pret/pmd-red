#ifndef GUARD_TARGETING_FLAGS_H
#define GUARD_TARGETING_FLAGS_H

#include "constants/move.h"
#include "dungeon_entity.h"

s16 GetMoveTargetAndRangeForPokemon(Entity *pokemon, Move *move, bool32 isAI);

#endif
