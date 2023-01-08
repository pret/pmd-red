#ifndef GUARD_MOVE_UTIL_H
#define GUARD_MOVE_UTIL_H

#include "dungeon_entity.h"

bool8 CanAIUseMove(struct Entity *pokemon, s32 moveIndex, bool8 hasPPChecker);
bool8 CanMonsterUseMove(struct Entity *pokemon, struct Move *move, bool8 hasPPChecker);

#endif
