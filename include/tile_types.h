#ifndef GUARD_TILE_TYPES_H
#define GUARD_TILE_TYPES_H

#include "structs/map.h"

#define DUNGEON_WATER_TYPE_NONE 0
#define DUNGEON_WATER_TYPE_LAVA 1
#define DUNGEON_WATER_TYPE_WATER 2

extern const u8 gDungeonWaterType[76];

void sub_804AE84(Position *pos);
bool8 IsTileGround(Tile *tile);
bool8 IsWaterTileset();

#endif // GUARD_TILE_TYPES_H