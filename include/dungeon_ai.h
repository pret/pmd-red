#ifndef GUARD_DUNGEON_AI_H
#define GUARD_DUNGEON_AI_H

#include "dungeon_entity.h"

u32 sub_8075818(struct DungeonEntity *entity);
void sub_8075900(struct DungeonEntity *pokemon, u8 r1);
void DecideAction(struct DungeonEntity *pokemon, u32 unused);

#endif
