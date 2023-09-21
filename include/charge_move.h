#ifndef GUARD_CHARGE_MOVE_H
#define GUARD_CHARGE_MOVE_H

#include "structs/dungeon_entity.h"

bool8 MoveMatchesChargingStatus(Entity *pokemon, Move *move);
// checkCharge = Check for the move named Charge.
bool8 IsCharging(Entity *pokemon, bool8 checkCharge);

#endif
