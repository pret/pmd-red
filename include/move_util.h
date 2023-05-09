#ifndef GUARD_MOVE_UTIL_H
#define GUARD_MOVE_UTIL_H

#include "dungeon_entity.h"

u32 sub_8057144(struct Entity * pokemon);
bool8 sub_80571F0(struct Entity * pokemon, struct Move *move);
bool8 sub_805727C(struct Entity * pokemon, struct Entity * target, s32 chance);
bool8 sub_8057308(struct Entity *pokemon, s32 chance);
bool8 CanAIUseMove(struct Entity *pokemon, s32 moveIndex, bool8 hasPPChecker);
bool8 CanMonsterUseMove(struct Entity *pokemon, struct Move *move, bool8 hasPPChecker);

#endif
