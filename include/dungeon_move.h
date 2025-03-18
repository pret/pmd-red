#ifndef GUARD_DUNGEON_MOVE_H
#define GUARD_DUNGEON_MOVE_H

#include "structs/str_pokemon.h"
#include "structs/str_moves.h"

extern s32 gUnknown_202F208;
extern s32 gUnknown_202F224;

bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move);

#endif // GUARD_DUNGEON_MOVE_H
