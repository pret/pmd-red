#ifndef GUARD_DUNGEON_MOVE_H
#define GUARD_DUNGEON_MOVE_H

#include "structs/str_pokemon.h"
#include "structs/str_moves.h"

bool8 HandleRegularDamagingMove(Entity *attacker, Entity *target, Move *move, s32 itemId);
bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move);

#endif
