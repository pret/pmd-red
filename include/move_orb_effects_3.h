#ifndef GUARD_MOVE_ORB_EFFECTS_3_H
#define GUARD_MOVE_ORB_EFFECTS_3_H

#include "structs/dungeon_entity.h"
#include "structs/str_moves.h"

void SetChargeStatusTarget(Entity *pokemon, Entity *target, u8 newStatus, Move *move, const u8 *message);
void sub_8079764(Entity * pokemon);

#endif

