#ifndef GUARD_DUNGEON_GENERATION_FIXED_H
#define GUARD_DUNGEON_GENERATION_FIXED_H

#include "structs/dungeon_entity.h"
#include "structs/map.h"

bool8 PlaceFixedRoomTile(Tile *tile, u8 fixedRoomActionId, s32 x, s32 y, bool8 spawnTrapOrItem);
void sub_8051E3C(void);
void sub_8051E7C(Entity *pokemon);

#endif
