#include "global.h"

#include "tile_types.h"

bool8 IsWaterDungeon(u32 r0)
{
    return gDungeonWaterType[r0] == DUNGEON_WATER_TYPE_WATER;
}
