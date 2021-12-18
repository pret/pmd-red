#include "global.h"
#include "dungeon_map_access.h"

#include "dungeon_global_data.h"

extern struct MapTile *gUnknown_203B430;

struct MapTile* GetMapTileAtPosition(s32 x, s32 y)
{
    if (x >= 0 && y >= 0 && x < DUNGEON_MAX_SIZE_X && y < DUNGEON_MAX_SIZE_Y)
    {
        return gDungeonGlobalData->mapEntityPointers[y][x];
    }
    return gUnknown_203B430;
}
