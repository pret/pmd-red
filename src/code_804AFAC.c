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

bool8 static inline boundsCheck(s32 x, s32 y)
{
    if ((((x < 0 || (y < 0)) || (DUNGEON_MAX_SIZE_X <= x)) || (DUNGEON_MAX_SIZE_Y <= y)))
    {
        return TRUE;
    }
    else
        return FALSE;
}

// https://decomp.me/scratch/w591w (98.17% matching - Seth)
// r6 and r7 are swapped
#ifdef NONMATCHING
void sub_804FD30(void)
{
  int x;
  int y;
  
  for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
  {
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        sub_804FD10(GetTileSafe(x,y));

        if ((boundsCheck(x,     y - 1)) ||
            (boundsCheck(x + 1, y - 1)) ||
            (boundsCheck(x + 1, y - 1)) ||
            (boundsCheck(x + 1, y + 1)) ||
            (boundsCheck(x,     y + 1)) ||
            (boundsCheck(x - 1, y + 1)) || 
            (boundsCheck(x - 1, y)) ||
            (boundsCheck(x - 1, y - 1)))
        {
            GetTileSafe(x,y)->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
        }
      }
    }

    gDungeon->unkE21C = -1;
    gDungeon->unkE21E = -1;

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
        gDungeon->unk1371C[x]->type = 0;
    }
}
#else
NAKED
void sub_804FD30(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x4\n"
	"\tmovs r6, 0\n"
"_0804FD3A:\n"
	"\tmovs r7, 0\n"
	"\tadds r4, r6, 0x1\n"
"_0804FD3E:\n"
	"\tadds r0, r6, 0\n"
	"\tadds r1, r7, 0\n"
	"\tbl GetTileSafe\n"
	"\tbl sub_804FD10\n"
	"\tsubs r3, r7, 0x1\n"
	"\tcmp r6, 0\n"
	"\tblt _0804FD5C\n"
	"\tcmp r3, 0\n"
	"\tblt _0804FD5C\n"
	"\tcmp r6, 0x37\n"
	"\tbgt _0804FD5C\n"
	"\tcmp r3, 0x1F\n"
	"\tble _0804FD60\n"
"_0804FD5C:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FD62\n"
"_0804FD60:\n"
	"\tmovs r0, 0\n"
"_0804FD62:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tcmp r4, 0\n"
	"\tblt _0804FD76\n"
	"\tcmp r3, 0\n"
	"\tblt _0804FD76\n"
	"\tcmp r4, 0x37\n"
	"\tbgt _0804FD76\n"
	"\tcmp r3, 0x1F\n"
	"\tble _0804FD7A\n"
"_0804FD76:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FD7C\n"
"_0804FD7A:\n"
	"\tmovs r0, 0\n"
"_0804FD7C:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tcmp r4, 0\n"
	"\tblt _0804FD90\n"
	"\tcmp r3, 0\n"
	"\tblt _0804FD90\n"
	"\tcmp r4, 0x37\n"
	"\tbgt _0804FD90\n"
	"\tcmp r3, 0x1F\n"
	"\tble _0804FD94\n"
"_0804FD90:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FD96\n"
"_0804FD94:\n"
	"\tmovs r0, 0\n"
"_0804FD96:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tadds r2, r7, 0x1\n"
	"\tcmp r4, 0\n"
	"\tblt _0804FDAC\n"
	"\tcmp r2, 0\n"
	"\tblt _0804FDAC\n"
	"\tcmp r4, 0x37\n"
	"\tbgt _0804FDAC\n"
	"\tcmp r2, 0x1F\n"
	"\tble _0804FDB0\n"
"_0804FDAC:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FDB2\n"
"_0804FDB0:\n"
	"\tmovs r0, 0\n"
"_0804FDB2:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tcmp r6, 0\n"
	"\tblt _0804FDC6\n"
	"\tcmp r2, 0\n"
	"\tblt _0804FDC6\n"
	"\tcmp r6, 0x37\n"
	"\tbgt _0804FDC6\n"
	"\tcmp r2, 0x1F\n"
	"\tble _0804FDCA\n"
"_0804FDC6:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FDCC\n"
"_0804FDCA:\n"
	"\tmovs r0, 0\n"
"_0804FDCC:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tadds r0, r2, 0\n"
	"\tsubs r1, r6, 0x1\n"
	"\tcmp r1, 0\n"
	"\tblt _0804FDE4\n"
	"\tcmp r0, 0\n"
	"\tblt _0804FDE4\n"
	"\tcmp r1, 0x37\n"
	"\tbgt _0804FDE4\n"
	"\tcmp r2, 0x1F\n"
	"\tble _0804FDE8\n"
"_0804FDE4:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FDEA\n"
"_0804FDE8:\n"
	"\tmovs r0, 0\n"
"_0804FDEA:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tcmp r1, 0\n"
	"\tblt _0804FDFE\n"
	"\tcmp r7, 0\n"
	"\tblt _0804FDFE\n"
	"\tcmp r1, 0x37\n"
	"\tbgt _0804FDFE\n"
	"\tcmp r7, 0x1F\n"
	"\tble _0804FE02\n"
"_0804FDFE:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FE04\n"
"_0804FE02:\n"
	"\tmovs r0, 0\n"
"_0804FE04:\n"
	"\tcmp r0, 0\n"
	"\tbne _0804FE24\n"
	"\tadds r0, r3, 0\n"
	"\tcmp r1, 0\n"
	"\tblt _0804FE1A\n"
	"\tcmp r0, 0\n"
	"\tblt _0804FE1A\n"
	"\tcmp r1, 0x37\n"
	"\tbgt _0804FE1A\n"
	"\tcmp r3, 0x1F\n"
	"\tble _0804FE1E\n"
"_0804FE1A:\n"
	"\tmovs r0, 0x1\n"
	"\tb _0804FE20\n"
"_0804FE1E:\n"
	"\tmovs r0, 0\n"
"_0804FE20:\n"
	"\tcmp r0, 0\n"
	"\tbeq _0804FE34\n"
"_0804FE24:\n"
	"\tadds r0, r6, 0\n"
	"\tadds r1, r7, 0\n"
	"\tbl GetTileSafe\n"
	"\tldrh r2, [r0]\n"
	"\tmovs r1, 0x10\n"
	"\torrs r1, r2\n"
	"\tstrh r1, [r0]\n"
"_0804FE34:\n"
	"\tadds r7, 0x1\n"
	"\tcmp r7, 0x1F\n"
	"\tble _0804FD3E\n"
	"\tadds r6, 0x1\n"
	"\tcmp r6, 0x37\n"
	"\tbgt _0804FE42\n"
	"\tb _0804FD3A\n"
"_0804FE42:\n"
	"\tldr r3, _0804FEB4\n"
	"\tldr r1, [r3]\n"
	"\tldr r0, _0804FEB8\n"
	"\tadds r2, r1, r0\n"
	"\tldr r0, _0804FEBC\n"
	"\tstrh r0, [r2]\n"
	"\tldr r2, _0804FEC0\n"
	"\tadds r1, r2\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tstrh r0, [r1]\n"
	"\tmovs r6, 0\n"
	"\tmov r8, r3\n"
	"\tldr r1, _0804FEC4\n"
"_0804FE5E:\n"
	"\tadds r5, r1, 0\n"
	"\tmovs r4, 0\n"
	"\tmovs r7, 0x7\n"
"_0804FE64:\n"
	"\tmov r2, r8\n"
	"\tldr r0, [r2]\n"
	"\tadds r0, r5\n"
	"\tadds r0, r4\n"
	"\tstr r1, [sp]\n"
	"\tbl sub_804FD10\n"
	"\tadds r4, 0x18\n"
	"\tsubs r7, 0x1\n"
	"\tldr r1, [sp]\n"
	"\tcmp r7, 0\n"
	"\tbge _0804FE64\n"
	"\tadds r1, 0xC0\n"
	"\tadds r6, 0x1\n"
	"\tcmp r6, 0x7\n"
	"\tble _0804FE5E\n"
	"\tldr r0, _0804FEB4\n"
	"\tldr r1, [r0]\n"
	"\tldr r2, _0804FEC8\n"
	"\tadds r1, r2\n"
	"\tmovs r2, 0\n"
	"\tstrh r2, [r1]\n"
	"\tmovs r6, 0\n"
	"\tadds r4, r0, 0\n"
	"\tldr r3, _0804FECC\n"
"_0804FE96:\n"
	"\tldr r0, [r4]\n"
	"\tlsls r1, r6, 2\n"
	"\tadds r0, r3\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tstr r2, [r0]\n"
	"\tadds r6, 0x1\n"
	"\tcmp r6, 0x3F\n"
	"\tble _0804FE96\n"
	"\tadd sp, 0x4\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0804FEB4: .4byte gDungeon\n"
"_0804FEB8: .4byte 0x0000e21c\n"
"_0804FEBC: .4byte 0x0000ffff\n"
"_0804FEC0: .4byte 0x0000e21e\n"
"_0804FEC4: .4byte 0x0000e27c\n"
"_0804FEC8: .4byte 0x00003904\n"
"_0804FECC: .4byte 0x0001371c\n");
}
#endif

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
