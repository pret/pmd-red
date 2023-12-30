#include "global.h"
#include "dungeon_map_access.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"

void sub_804FBE8(void)
{
    Tile *tile;
    int y;
    int x;

    for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
    {
        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
        {
          tile = GetTileSafe(x,y);
          if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL) {
            if ((tile->terrainType & (TERRAIN_TYPE_UNK_8 | TERRAIN_TYPE_IMPASSABLE_WALL)) != 0) {
              tile->unk4 &= 0xfffd;
            }
            tile->unk4 &= 0xfffb;
          }
          if ((tile->unk4 & 1) != 0) {
            tile->terrainType |= TERRAIN_TYPE_STAIRS;
            tile->unk4 &= 0xfffb;
          }
          if ((tile->unk4 & 2) != 0) {
            tile->unk4 &= 0xfffb;
          }
        } 
    }
}

void sub_804FC74(void)
{
    Tile *tile;
    int y;
    int x;

    for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
    {
        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
        {
            if ((GetTile(x, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
                tile = GetTileSafe(x,y);
                tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
                tile->terrainType |= (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            }
        } 
    }
}

void sub_804FCCC(void)
{
    Tile *tile;
    int y;
    int x;

    for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
    {
        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
        {
            if ((GetTile(x, y)->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) != 0) {
                tile = GetTileSafe(x,y);
                tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            }
        } 
    }
}

void sub_804FD10(Tile *tile)
{
    tile->terrainType = 0;
    tile->unk4 = 0;
    tile->room = -1;
    tile->unk8 = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_REGULAR] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_LIQUID] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_CREVICE] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_WALL] = 0;
    tile->unkE = 0;
    tile->monster = NULL;
    tile->object = NULL;
}
