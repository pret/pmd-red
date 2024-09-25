#ifndef GUARD_MOVE_CHECKS_H
#define GUARD_MOVE_CHECKS_H

#include "structs/dungeon_entity.h"

bool8 CanUseOnSelfWithStatusChecker(Entity *pokemon, Move *move);
bool8 CanUseOnTargetWithStatusChecker(Entity *user, Entity *target, Move *move);
bool8 HasDisabledMove(Move *moves);
bool8 LastUsedMoveOutOfPP(Move *moves);
bool8 HasLastUsedMove(Move *moves);

#endif
