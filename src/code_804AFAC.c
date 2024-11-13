#include "global.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
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
          tile = GetTileMut(x,y);
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
                tile = GetTileMut(x,y);
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
                tile = GetTileMut(x,y);
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

bool8 static inline boundsCheck(int x, int y)
{
    if (x < 0 || (y < 0)) return TRUE;
    if (DUNGEON_MAX_SIZE_X <= x) return TRUE;
    if (DUNGEON_MAX_SIZE_Y <= y) return TRUE;
    return FALSE;
}

void sub_804FD30(void)
{
  int x;
  int y;

  for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
  {
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        sub_804FD10(GetTileMut(x,y));

        if ((boundsCheck(x,     y - 1)) ||
            (boundsCheck(x + 1, y - 1)) ||
            (boundsCheck(x + 1, y - 1)) ||
            (boundsCheck(x + 1, y + 1)) ||
            (boundsCheck(x,     y + 1)) ||
            (boundsCheck(x - 1, y + 1)) ||
            (boundsCheck(x - 1, y)) ||
            (boundsCheck(x - 1, y - 1)))
        {
            GetTileMut(x,y)->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
        }
      }
    }

    gDungeon->unkE21C.x = -1;
    gDungeon->unkE21C.y = -1;

    for(x = 0; x < 8; x++)
    {
        for(y = 0; y < 8; y++)
        {
            sub_804FD10(&gDungeon->unkE27C[x][y]);
        }
    }

    gDungeon->unk3904 = 0;
    for(x = 0; x < 0x40; x++)
    {
        gDungeon->traps[x]->type = 0;
    }
}


void sub_804FED0(s32 *param_1, s32 param_2)
{
    int idx1;
    int idx2;
    s32 temp;
    int counter;

    for (counter = 0; counter < param_2 << 1; counter++) {
        idx1 = DungeonRandInt(param_2);
        idx2 = DungeonRandInt(param_2);
        temp = param_1[idx1];
        param_1[idx1] = param_1[idx2];
        param_1[idx2] = temp;
    }
}
