#ifndef GUARD_CHARGE_MOVE_H
#define GUARD_CHARGE_MOVE_H

#include "dungeon_entity.h"

bool8 MoveMatchesChargingStatus(struct Entity *pokemon, struct Move *move);
// checkCharge = Check for the move named Charge.
bool8 IsCharging(struct Entity *pokemon, bool8 checkCharge);

#endif
