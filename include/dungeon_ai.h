#ifndef GUARD_DUNGEON_AI_H
#define GUARD_DUNGEON_AI_H

#include "dungeon_entity.h"

u32 sub_8075818(struct Entity *entity);
void sub_8075900(struct Entity *pokemon, u8 r1);
void RunMonsterAI(struct Entity *pokemon, u32 unused);

#endif
