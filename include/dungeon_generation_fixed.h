#ifndef GUARD_DUNGEON_GENERATION_FIXED_H
#define GUARD_DUNGEON_GENERATION_FIXED_H

#include "structs/dungeon_entity.h"
#include "structs/map.h"

bool8 PlaceFixedRoomTile(Tile *tile, u8 a1, s32 x, s32 y, u8 a5);
void sub_8051E3C(void);
void sub_8051E7C(Entity *pokemon);

#endif
