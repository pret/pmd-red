#ifndef GUARD_MOVE_UTIL_H
#define GUARD_MOVE_UTIL_H

#include "dungeon_entity.h"

u32 sub_8057144(Entity * pokemon);
bool8 sub_80571F0(Entity * pokemon, Move *move);
bool8 sub_805727C(Entity * pokemon, Entity * target, s32 chance);
bool8 sub_8057308(Entity *pokemon, s32 chance);
bool8 CanAIUseMove(Entity *pokemon, s32 moveIndex, bool8 hasPPChecker);
bool8 CanMonsterUseMove(Entity *pokemon, Move *move, bool8 hasPPChecker);

#endif
