#include "global.h"
#include "code_8004AA0.h"
#include "constants/walkable_tile.h"
#include "decompress.h"
#include "dungeon_map_access.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "random.h"
#include "dungeon_engine.h"
#include "dungeon_movement.h"
#include "dungeon_util.h"
#include "code_8009804.h"

extern unkStruct_202F190 gUnknown_80F69D4;
extern unkStruct_202F190 gUnknown_80F69EC;
extern u8 gUnknown_80F6A04[];
extern u8 gUnknown_80F6A10[];
extern u8 gUnknown_80F6A28[];
extern u8 gUnknown_80F6A1C[];
extern u8 gUnknown_80F6A34[];
extern u8 gUnknown_80F6A40[];
extern u8 gUnknown_8108EC0[];
extern const struct FileArchive gDungeonFileArchive;

EWRAM_DATA OpenedFile *gDungeonPaletteFile = {0};
EWRAM_DATA unkStruct_202EE8C gUnknown_202EE8C[32] = {0};
EWRAM_DATA OpenedFile *gUnknown_202F18C = {0};
EWRAM_DATA unkStruct_202F190 gUnknown_202F190 = {0};

EWRAM_DATA_2 unkStruct_202F190 *gUnknown_203B430 = {0};

extern u8 sub_8043CE4(u32);

extern int sprintf(char *, const char *, ...);
void sub_8049BB0(s32, s32);
void sub_80498A8(s32, s32);

Tile *GetTile(s32 x, s32 y)
{
    if (x >= 0 && y >= 0 && x < DUNGEON_MAX_SIZE_X && y < DUNGEON_MAX_SIZE_Y)
    {
        return gDungeon->tilePointers[y][x];
    }
    return (Tile *) gUnknown_203B430->unk0;
}

Tile *GetTileSafe(s32 x, s32 y)
{
    if (x < 0 || y < 0 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y)
    {
        Tile *tile = (Tile *) gUnknown_202F190.unk0;
        gUnknown_202F190 = *gUnknown_203B430;
        return tile;
    }
    return gDungeon->tilePointers[y][x];
}

void sub_80495E4(void)
{
  s32 YCoord;
  s32 XCoord;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      gDungeon->tilePointers[YCoord][XCoord] = &gDungeon->tiles[YCoord][XCoord];
    }
  }
  gDungeon->tileset = 0;
  gDungeon->unk3A10 = 0;
  gDungeon->unk13570 = 0;
}

void LoadDungeonTilesetAssets(void)
{
  OpenedFile *file;
  OpenedFile *file_1;
  u8 fileName [12];

  sprintf(fileName,gUnknown_80F6A04,gUnknown_8108EC0[gDungeon->tileset]); // b%02dfon
  file = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);
  DecompressATGlobalFile((u32 *)0x06008000,0,file);
  CloseFile(file);

  sprintf(fileName,gUnknown_80F6A10,gDungeon->tileset); // b%02dpal
  gDungeonPaletteFile = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);

  sprintf(fileName,gUnknown_80F6A1C,gUnknown_8108EC0[gDungeon->tileset]); // b%02dcel
  file_1 = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);
  DecompressATFile((void*)gDungeon->unk11884,0x1194,file_1);
  CloseFile(file_1);

  if (gDungeon->tileset < 0x40) {
    sprintf(fileName,gUnknown_80F6A28,gUnknown_8108EC0[gDungeon->tileset]); // b%02dcex
    file = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);
    DecompressATFile(gDungeon->unk12C24,0x930,file);
    CloseFile(file);
  }
  else {
    sprintf(fileName,gUnknown_80F6A34,gDungeon->tileset); // b%02demap0
    file = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);
    DecompressATFile(gDungeon->unk12C24,0x240,file);
    CloseFile(file);
  }
  sprintf(fileName,gUnknown_80F6A40,gDungeon->tileset); // b%02dcanm
  gUnknown_202F18C = OpenFileAndGetFileDataPtr(fileName,&gDungeonFileArchive);
  sub_8004AA4(gUnknown_202EE8C,gUnknown_202F18C,0x20);
  gWalkableTileToCrossableTerrain[0] = CROSSABLE_TERRAIN_REGULAR;
  gWalkableTileToCrossableTerrain[1] = CROSSABLE_TERRAIN_LIQUID;
  gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_CHASM] = CROSSABLE_TERRAIN_CREVICE;
  gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_WALL] = CROSSABLE_TERRAIN_WALL;

  if(gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA)
  {
    gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_LAVA] = CROSSABLE_TERRAIN_LIQUID;
    gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_WATER] = CROSSABLE_TERRAIN_REGULAR;
  }
  else
  {
    gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_LAVA]  = CROSSABLE_TERRAIN_REGULAR;
    gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_WATER]  = CROSSABLE_TERRAIN_LIQUID;
  }
}

void sub_8049820(void)
{
    CloseFile(gUnknown_202F18C);
    CloseFile(gDungeonPaletteFile);
}

void sub_8049840(void)
{
  if (sub_8043CE4(gDungeon->tileset) != 0) {
    gUnknown_203B430 = &gUnknown_80F69EC;
  }
  else {
    gUnknown_203B430 = &gUnknown_80F69D4;
  }
}


void sub_8049884(void)
{
  s32 XCoord;
  s32 YCoord;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++) {
      sub_80498A8(XCoord,YCoord);
    }
  }
}

void sub_80498A8(int x,int y)
{
  volatile u32 sp_0x0;
  volatile u32 sp_0x4;
  volatile u32 sp_0x8;
  volatile u32 sp_0xC;
  volatile u32 sp_0x10;
  volatile u32 sp_0x14;
  volatile u32 sp_0x18;
  volatile u32 sp_0x1C;
  u32 r1;
  u16 sp_0x20; // sp 0x20
  int r4;
  s32 r7; // r7

  if (x < 0) {
    return;
  }
  if (y < 0) {
    return;
  }
  if (DUNGEON_MAX_SIZE_X <= x) {
    return;
  }
  if (DUNGEON_MAX_SIZE_Y <= y) {
    return;
  }
  r7 = 0;
  sp_0x20 = GetTile(x, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  if (gDungeon->tileset >= 0x40) {
    if ((0x17 >= x) && (0x17 >= y)) {
        GetTileSafe(x,y)->unk8 = gDungeon->unk12C24[y * 0x18 + x];
    }
    else {
      GetTileSafe(x,y)->unk8 = 0;
    }
  }
  else
  {
    sp_0x0 = GetTile(x,y + 1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x4 = GetTile(x + 1,y + 1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x8 = GetTile(x + 1,y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0xC = GetTile(x + 1,y -1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x10 = GetTile(x, y -1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x14 = GetTile(x - 1,y -1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x18 = GetTile(x - 1, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    r1 =  GetTile(x - 1,y + 1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    sp_0x1C = r1;
    if (sp_0x20 == 1) {
      r7 = 0xFF;
      if (sp_0x0 == 0) {
        r7 = 0xfe;
      }
      if (sp_0x4 == 0) {
        r7 &= -3;
      }
      if (sp_0x8 == 0) {
        r7 &= -5;
      }
      if (sp_0xC == 0) {
        r7 &= -9;
      }
      if (sp_0x10 == 0) {
        r7 &= -17;
      }
      if (sp_0x14 == 0) {
        r7 &= 0xffffffdf;
      }
      if (sp_0x18 == 0) {
        r7 &= 0xffffffbf;
      }
      if (r1 == 0) {
        r7 &= 0xffffff7f;
      }
      r7 |= 0x200;
    }
    else if (sp_0x20 == 2) {
        r7 = 0xff;
        if (sp_0x0 != 2) {
          r7 = 0xfe;
        }
        if (sp_0x4 != 2) {
          r7 &= 0xfffffffd;
        }
        if (sp_0x8 != 2) {
          r7 &= 0xfffffffb;
        }
        if (sp_0xC != 2) {
          r7 &= 0xfffffff7;
        }
        if (sp_0x10 != 2) {
          r7 &= 0xffffffef;
        }
        if (sp_0x14 != 2) {
          r7 &= 0xffffffdf;
        }
        if (sp_0x18 != 2) {
          r7 &= 0xffffffbf;
        }
        if (r1 != 2) {
          r7 &= 0xffffff7f;
        }
        r7 |= 0x100;
      }
    else if (sp_0x20 == 3) {
        r7 = 0xff;
        if (sp_0x0 != 3) {
          r7 = 0xfe;
        }
        if (sp_0x4 != 3) {
          r7 &= 0xfffffffd;
        }
        if (sp_0x8 != 3) {
          r7 &= 0xfffffffb;
        }
        if (sp_0xC != 3) {
          r7 &= 0xfffffff7;
        }
        if (sp_0x10 != 3) {
          r7 &= 0xffffffef;
        }
        if (sp_0x14 != 3) {
          r7 &= 0xffffffdf;
        }
        if (sp_0x18 != 3) {
          r7 &= 0xffffffbf;
        }
        if (sp_0x1C != 3) {
          r7 &= 0xffffff7f;
        }
        r7 |= 0x100;
    }
    else
    {
      if (sp_0x0 == 0) {
        r7 = 1;
      }
      if (sp_0x4 == 0) {
        r7 |= 2;
      }
      if (sp_0x8 == 0) {
        r7 |= 4;
      }
      if (sp_0xC == 0) {
        r7 |= 8;
      }
      if (sp_0x10 == 0) {
        r7 |= 0x10;
      }
      if (sp_0x14 == 0) {
        r7 |= 0x20;
      }
      if (sp_0x18 == 0) {
        r7 |= 0x40;
      }
      if (sp_0x1C == 0) {
        r7 |= 0x80;
      }
    }
    r4 = RandInt(4);
    if (r4 == 3) {
      r4 = 0;
    }
    if (IsBossFight()) {
      r4 = 0;
    }
    GetTileSafe(x,y)->unk8 = gDungeon->unk12C24[r4 + r7 * 3];
  }
}

void sub_8049B8C(void)
{
  s32 XCoord;
  s32 YCoord;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++) {
      sub_8049BB0(XCoord,YCoord);
    }
  }
}

void sub_8049BB0(s32 x, s32 y)
{
    s32 i;
    u32 terrainFlags;
    u32 flags[6];
    u32 var_4C[8];
    bool8 var_2C[8];

    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;

    terrainFlags = GetTile(x,   y+1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[0] = terrainFlags;
    var_4C[1] = GetTile(x+1, y+1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[2] = GetTile(x+1, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[3] = GetTile(x+1, y-1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[4] = GetTile(x,   y-1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[5] = GetTile(x-1, y-1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[6] = GetTile(x-1, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    var_4C[7] = GetTile(x-1, y+1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);

    if (var_4C[0] == TERRAIN_TYPE_NORMAL)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 1;
    if (var_4C[2] == TERRAIN_TYPE_NORMAL)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 4;
    if (var_4C[4] == TERRAIN_TYPE_NORMAL)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 0x10;
    if (var_4C[6] == TERRAIN_TYPE_NORMAL)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 0x40;

    if (var_4C[0] != 0 && var_4C[1] == TERRAIN_TYPE_NORMAL && var_4C[2] != 0)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 2;
    if (var_4C[2] != 0 && var_4C[3] == TERRAIN_TYPE_NORMAL && var_4C[4] != 0)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 8;
    if (var_4C[4] != 0 && var_4C[5] == TERRAIN_TYPE_NORMAL && var_4C[6] != 0)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 0x20;
    if (var_4C[6] != 0 && var_4C[7] == TERRAIN_TYPE_NORMAL && var_4C[0] != 0)
        flags[CROSSABLE_TERRAIN_REGULAR] |= 0x80;

    for (i = 0; i < 8; i++) {
        if (var_4C[i] == TERRAIN_TYPE_NORMAL || var_4C[i] == TERRAIN_TYPE_SECONDARY)
            var_2C[i] = TRUE;
        else
            var_2C[i] = FALSE;
    }

    if (var_2C[0])
        flags[CROSSABLE_TERRAIN_LIQUID] |= 1;
    if (var_2C[2])
        flags[CROSSABLE_TERRAIN_LIQUID] |= 4;
    if (var_2C[4])
        flags[CROSSABLE_TERRAIN_LIQUID] |= 0x10;
    if (var_2C[6])
        flags[CROSSABLE_TERRAIN_LIQUID] |= 0x40;

    if (var_4C[0] != 0 && var_2C[1] && var_4C[2] != 0)
        flags[CROSSABLE_TERRAIN_LIQUID] |= 2;
    if (var_4C[2] != 0 && var_2C[3] && var_4C[4] != 0)
        flags[CROSSABLE_TERRAIN_LIQUID] |= 8;
    if (var_4C[4] != 0 && var_2C[5] && var_4C[6] != 0)
        flags[CROSSABLE_TERRAIN_LIQUID] |= 0x20;
    if (var_4C[6] != 0 && var_2C[7] && var_4C[0] != 0)
        flags[CROSSABLE_TERRAIN_LIQUID] |= 0x80;

    if (var_4C[0] != 0)
        flags[2] |= 1;
    if (var_4C[2] != 0)
        flags[2] |= 4;
    if (var_4C[4] != 0)
        flags[2] |= 0x10;
    if (var_4C[6] != 0)
        flags[2] |= 0x40;

    if (var_4C[0] != 0 && var_4C[1] != 0 && var_4C[2] != 0)
        flags[CROSSABLE_TERRAIN_CREVICE] |= 2;
    if (var_4C[2] != 0 && var_4C[3] != 0 && var_4C[4] != 0)
        flags[CROSSABLE_TERRAIN_CREVICE] |= 8;
    if (var_4C[4] != 0 && var_4C[5] != 0 && var_4C[6] != 0)
        flags[CROSSABLE_TERRAIN_CREVICE] |= 0x20;
    if (var_4C[6] != 0 && var_4C[7] != 0 && var_4C[0] != 0)
        flags[CROSSABLE_TERRAIN_CREVICE] |= 0x80;

    flags[3] = 0xFF;
    if (x <= 1)
        flags[CROSSABLE_TERRAIN_WALL] = 0x1F;
    if (y <= 1)
        flags[CROSSABLE_TERRAIN_WALL] &= ~(0x8 | 0x10 | 0x20);
    if (x > 53)
        flags[CROSSABLE_TERRAIN_WALL] &= ~(0x2 | 0x4 | 0x8);
    if (y > 29)
        flags[CROSSABLE_TERRAIN_WALL] &= ~(0x80 | 0x1 | 0x2);

    GetTileSafe(x, y)->walkableNeighborFlags[CROSSABLE_TERRAIN_REGULAR] = flags[CROSSABLE_TERRAIN_REGULAR];
    GetTileSafe(x, y)->walkableNeighborFlags[CROSSABLE_TERRAIN_LIQUID] = flags[CROSSABLE_TERRAIN_LIQUID];
    GetTileSafe(x, y)->walkableNeighborFlags[CROSSABLE_TERRAIN_CREVICE] = flags[CROSSABLE_TERRAIN_CREVICE];
    GetTileSafe(x, y)->walkableNeighborFlags[CROSSABLE_TERRAIN_WALL] = flags[CROSSABLE_TERRAIN_WALL];
}

extern const s16 gUnknown_80F6A4A[];
extern const s16 gUnknown_80F6C06[];

extern u16 gUnknown_202B038[4][32][32];

void sub_8049ED4(void)
{
    s32 var_58;
    s32 var_54;
    s16 *r2;
    Tile *r5;
    s32 r7;
    s32 i;
    s32 r10;
    s32 j;
    s32 x, y;
    s32 r8;
    s32 var_48, var_44;

    Dungeon *dungeon = gDungeon;
    var_58 = dungeon->unk181e8.hallucinating;
    var_54 = dungeon->unk181e8.unk1820F;
    x = dungeon->unk181e8.cameraPixelPos.x >> 3;
    r10 = gUnknown_80F6A4A[30 + x];
    var_48 = gUnknown_80F6C06[30 + x];

    for (i = 0; i <= 30; i++) {

        y = (dungeon->unk181e8.cameraPixelPos.y >> 3) - 1;
        x &= 0x1F;
        r8 = gUnknown_80F6A4A[30 + y];
        var_44 = gUnknown_80F6C06[30 + y];
        r7 = r10 + (r8 * 3);
        r5 = GetTile(var_48, var_44);
        if (r5->terrainType & TERRAIN_TYPE_UNK_x1000) {
            r2 = &dungeon->unk12BEC[r7];
        }
        else if (r5->terrainType & TERRAIN_TYPE_SHOP) {
            r2 = &dungeon->unk12BDA[r7];
        }
        else if (var_58 != 0) {
            r2 = &dungeon->unk11884[r5->unk8][r7];
        }
        else if (r5->unk4 & 4) {
            r2 = &dungeon->unk12BFE[r7];
        }
        else
        {
            Entity *tileObject = r5->object;
            if (tileObject != NULL) {
                if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || var_54 != 0)) {
                    u8 trapType = tileObject->info->flags;
                    r2 = &dungeon->unk12A18[trapType][r7];
                }
                else {
                    r2 = &dungeon->unk11884[r5->unk8][r7];
                }
            }
            else {
                if (r5->terrainType & TERRAIN_TYPE_STAIRS) {
                    r2 = &dungeon->unk12A18[dungeon->unk3A12][r7];
                }
                else {
                    r2 = &dungeon->unk11884[r5->unk8][r7];
                }
            }
        }


        for (j = 0; j < 23; j++) {
            y &= 0x1F;

            gUnknown_202B038[3][y][x] = *r2;

            r2 += 3;
            y++;
            r8++;
            if (r8 == 3)
            {
                r8 = 0;
                var_44++;
                r7 = r10;
                r5 = GetTile(var_48, var_44);
                if (r5->terrainType & TERRAIN_TYPE_SHOP) {
                    r2 = &dungeon->unk12BDA[r7];
                }
                else if (r5->terrainType & TERRAIN_TYPE_UNK_x1000) {
                    r2 = &dungeon->unk12BEC[r7];
                }
                else if (var_58 != 0) {
                    r2 = &dungeon->unk11884[r5->unk8][r7];
                }
                else if (r5->unk4 & 4) {
                    r2 = &dungeon->unk12BFE[r7];
                }
                else
                {
                    Entity *tileObject = r5->object;
                    if (tileObject != NULL) {
                        if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || var_54 != 0)) {
                            u8 trapType = tileObject->info->flags;
                            r2 = &dungeon->unk12A18[trapType][r7];
                        }
                        else {
                            r2 = &dungeon->unk11884[r5->unk8][r7];
                        }
                    }
                    else {
                        if (r5->terrainType & TERRAIN_TYPE_STAIRS) {
                            r2 = &dungeon->unk12A18[dungeon->unk3A12][r7];
                        }
                        else {
                            r2 = &dungeon->unk11884[r5->unk8][r7];
                        }
                    }
                }

            }
        }

        x++;
        r10++;
        if (r10 == 3) {
            r10 = 0;
            var_48++;
        }
    }

    sub_80098F8(3);
}

//
