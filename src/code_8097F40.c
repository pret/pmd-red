#include "global.h"
#include "dungeon_map_access.h"

bool8 IsWaterDungeon(u32 r0)
{
    return gDungeonWaterType[r0] == DUNGEON_WATER_TYPE_WATER;
}
