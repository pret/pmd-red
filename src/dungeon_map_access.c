#include "global.h"
#include "dungeon_map_access.h"

#include "dungeon_global_data.h"

extern struct unkStruct_202F190 gUnknown_202F190;
extern struct unkStruct_202F190 *gUnknown_203B430;

struct MapTile* GetMapTile_1(s32 x, s32 y)
{
    if (x >= 0 && y >= 0 && x < DUNGEON_MAX_SIZE_X && y < DUNGEON_MAX_SIZE_Y)
    {
        return gDungeonGlobalData->mapTilePointers[y][x];
    }
    return (struct MapTile*) gUnknown_203B430->unk0;
}

struct MapTile* GetMapTile_2(s32 x, s32 y)
{
    if (x < 0 || y < 0 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y)
    {
        struct MapTile* tile = (struct MapTile*) gUnknown_202F190.unk0;
        gUnknown_202F190 = *gUnknown_203B430;
        return tile;
    }
    return gDungeonGlobalData->mapTilePointers[y][x];
}
