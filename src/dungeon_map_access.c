#include "global.h"
#include "dungeon_map_access.h"
#include "code_8004AA0.h"
#include "constants/walkable_tile.h"
#include "decompress.h"
#include "dungeon_map_access.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "random.h"
#include "text1.h"
#include "dungeon_engine.h"
#include "dungeon_movement.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "code_8009804.h"
#include "game_options.h"
#include "dungeon_visibility.h"

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
extern const s16 gUnknown_80F6A4A[];
extern const s16 gUnknown_80F6C06[];

EWRAM_DATA OpenedFile *gDungeonPaletteFile = {0};
EWRAM_DATA unkStruct_202EE8C gUnknown_202EE8C[32] = {0};
EWRAM_DATA OpenedFile *gUnknown_202F18C = {0};
EWRAM_DATA unkStruct_202F190 gUnknown_202F190 = {0};

EWRAM_DATA_2 unkStruct_202F190 *gUnknown_203B430 = {0};

extern u8 sub_8043CE4(u32);
extern void sub_80402AC(s32, s32);
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

void sub_8049ED4(void)
{
    bool32 hallucinating, unk1820F;
    u16 *src;
    Tile *tile;
    s32 r7;
    s32 i;
    s32 r10;
    s32 j;
    s32 x, y;
    s32 r8;
    s32 var_48, var_44;

    Dungeon *dungeon = gDungeon;
    hallucinating = dungeon->unk181e8.hallucinating;
    unk1820F = dungeon->unk181e8.unk1820F;
    x = dungeon->unk181e8.cameraPixelPos.x >> 3;
    r10 = gUnknown_80F6A4A[30 + x];
    var_48 = gUnknown_80F6C06[30 + x];

    for (i = 0; i <= 30; i++) {

        y = (dungeon->unk181e8.cameraPixelPos.y >> 3) - 1;
        x &= 0x1F;
        r8 = gUnknown_80F6A4A[30 + y];
        var_44 = gUnknown_80F6C06[30 + y];
        r7 = r10 + (r8 * 3);
        tile = GetTile(var_48, var_44);
        if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
            src = &dungeon->unk12BEC[r7];
        }
        else if (tile->terrainType & TERRAIN_TYPE_SHOP) {
            src = &dungeon->unk12BDA[r7];
        }
        else if (hallucinating) {
            src = &dungeon->unk11884[tile->unk8][r7];
        }
        else if (tile->unk4 & 4) {
            src = &dungeon->unk12BFE[r7];
        }
        else
        {
            Entity *tileObject = tile->object;
            if (tileObject != NULL) {
                if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                    u8 trapType = tileObject->axObj.info->flags;
                    src = &dungeon->unk12A18[trapType][r7];
                }
                else {
                    src = &dungeon->unk11884[tile->unk8][r7];
                }
            }
            else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                src = &dungeon->unk12A18[dungeon->unk3A12][r7];
            }
            else {
                src = &dungeon->unk11884[tile->unk8][r7];
            }
        }


        for (j = 0; j < 23; j++) {
            y &= 0x1F;
            gUnknown_202B038[3][y][x] = *src;
            src += 3;
            y++;
            r8++;
            if (r8 == 3)
            {
                r8 = 0;
                var_44++;
                r7 = r10;
                tile = GetTile(var_48, var_44);
                if (tile->terrainType & TERRAIN_TYPE_SHOP) {
                    src = &dungeon->unk12BDA[r7];
                }
                else if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
                    src = &dungeon->unk12BEC[r7];
                }
                else if (hallucinating) {
                    src = &dungeon->unk11884[tile->unk8][r7];
                }
                else if (tile->unk4 & 4) {
                    src = &dungeon->unk12BFE[r7];
                }
                else
                {
                    Entity *tileObject = tile->object;
                    if (tileObject != NULL) {
                        if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                            u8 trapType = tileObject->axObj.info->flags;
                            src = &dungeon->unk12A18[trapType][r7];
                        }
                        else {
                            src = &dungeon->unk11884[tile->unk8][r7];
                        }
                    }
                    else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                        src = &dungeon->unk12A18[dungeon->unk3A12][r7];
                    }
                    else {
                        src = &dungeon->unk11884[tile->unk8][r7];
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

void sub_804A1F0(s32 a0, s32 a1)
{
    Tile *tile;
    u16 *src;
    bool32 hallucinating, unk1820F;
    s32 xTemp, yTemp;
    s32 i;
    s32 r8;
    s32 r10;
    s32 r6;
    s32 var_2C;
    s32 var_28;
    s32 x, y;

    Dungeon *dungeon = gDungeon;
    hallucinating = dungeon->unk181e8.hallucinating;
    unk1820F = dungeon->unk181e8.unk1820F;
    xTemp = dungeon->unk181e8.cameraPixelPos.x + a0;
    yTemp = dungeon->unk181e8.cameraPixelPos.y + a1;
    yTemp >>= 3;
    x = xTemp >> 3;
    y = yTemp - 1;
    var_28 = gUnknown_80F6A4A[30 + x];
    var_2C = gUnknown_80F6C06[30 + x];
    r8 = gUnknown_80F6A4A[30 + y];
    r10 = gUnknown_80F6C06[30 + y];
    r6 = var_28 + r8 * 3;
    tile = GetTile(var_2C, r10);
    if (tile->terrainType & TERRAIN_TYPE_SHOP) {
        src = &dungeon->unk12BDA[r6];
    }
    else if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
        src = &dungeon->unk12BEC[r6];
    }
    else if (hallucinating) {
        src = &dungeon->unk11884[tile->unk8][r6];
    }
    else
    {
        Entity *tileObject = tile->object;
        if (tileObject != NULL) {
            if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                u8 trapType = tileObject->axObj.info->flags;
                src = &dungeon->unk12A18[trapType][r6];
            }
            else {
                src = &dungeon->unk11884[tile->unk8][r6];
            }
        }
        else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
            src = &dungeon->unk12A18[dungeon->unk3A12][r6];
        }
        else {
            src = &dungeon->unk11884[tile->unk8][r6];
        }
    }

    for (i = 0; i < 23; i++) {
        x &= 0x1F;
        y &= 0x1F;
        gUnknown_202B038[3][y][x] = *src;
        src += 3;
        y++;
        r8++;
        if (r8 == 3) {
            r8 = 0;
            r10++;
            r6 = var_28;
            tile = GetTile(var_2C, r10);
            if (tile->terrainType & TERRAIN_TYPE_SHOP) {
                src = &dungeon->unk12BDA[r6];
            }
            else if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
                src = &dungeon->unk12BEC[r6];
            }
            else if (hallucinating) {
                src = &dungeon->unk11884[tile->unk8][r6];
            }
            else
            {
                Entity *tileObject = tile->object;
                if (tileObject != NULL) {
                    if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                        u8 trapType = tileObject->axObj.info->flags;
                        src = &dungeon->unk12A18[trapType][r6];
                    }
                    else {
                        src = &dungeon->unk11884[tile->unk8][r6];
                    }
                }
                else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                    src = &dungeon->unk12A18[dungeon->unk3A12][r6];
                }
                else {
                    src = &dungeon->unk11884[tile->unk8][r6];
                }
            }
        }
    }
    sub_80098F8(3);
}

void sub_804A49C(s32 a0, s32 a1)
{
    Tile *tile;
    u16 *src;
    bool32 hallucinating, unk1820F;
    s32 xTemp, yTemp;
    s32 i;
    s32 var_2C;
    s32 r10;
    s32 r6;
    s32 var_28;
    s32 r9;
    s32 x, y;

    Dungeon *dungeon = gDungeon;
    hallucinating = dungeon->unk181e8.hallucinating;
    unk1820F = dungeon->unk181e8.unk1820F;
    xTemp = dungeon->unk181e8.cameraPixelPos.x + a0;
    yTemp = dungeon->unk181e8.cameraPixelPos.y + a1;
    x = xTemp >> 3;
    y = yTemp >> 3;
    r9 = gUnknown_80F6A4A[30 + x];
    r10 = gUnknown_80F6C06[30 + x];
    var_28 = gUnknown_80F6A4A[30 + y];
    var_2C = gUnknown_80F6C06[30 + y];
    r6 = r9 + var_28 * 3;
    tile = GetTile(r10, var_2C);
    if (tile->terrainType & TERRAIN_TYPE_SHOP) {
        src = &dungeon->unk12BDA[r6];
    }
    else if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
        src = &dungeon->unk12BEC[r6];
    }
    else if (hallucinating) {
        src = &dungeon->unk11884[tile->unk8][r6];
    }
    else
    {
        Entity *tileObject = tile->object;
        if (tileObject != NULL) {
            if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                u8 trapType = tileObject->axObj.info->flags;
                src = &dungeon->unk12A18[trapType][r6];
            }
            else {
                src = &dungeon->unk11884[tile->unk8][r6];
            }
        }
        else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
            src = &dungeon->unk12A18[dungeon->unk3A12][r6];
        }
        else {
            src = &dungeon->unk11884[tile->unk8][r6];
        }
    }

    for (i = 0; i < 31; i++) {
        x &= 0x1F;
        y &= 0x1F;
        gUnknown_202B038[3][y][x] = *src;
        src++;
        x++;
        r9++;
        if (r9 == 3) {
            r9 = 0;
            r10++;
            r6 = var_28 * 3;
            tile = GetTile(r10, var_2C);
            if (tile->terrainType & TERRAIN_TYPE_SHOP) {
                src = &dungeon->unk12BDA[r6];
            }
            else if (tile->terrainType & TERRAIN_TYPE_UNK_x1000) {
                src = &dungeon->unk12BEC[r6];
            }
            else if (hallucinating) {
                src = &dungeon->unk11884[tile->unk8][r6];
            }
            else
            {
                Entity *tileObject = tile->object;
                if (tileObject != NULL) {
                    if (GetEntityType(tileObject) == ENTITY_TRAP && (tileObject->isVisible || unk1820F)) {
                        u8 trapType = tileObject->axObj.info->flags;
                        src = &dungeon->unk12A18[trapType][r6];
                    }
                    else {
                        src = &dungeon->unk11884[tile->unk8][r6];
                    }
                }
                else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                    src = &dungeon->unk12A18[dungeon->unk3A12][r6];
                }
                else {
                    src = &dungeon->unk11884[tile->unk8][r6];
                }
            }
        }
    }
    sub_80098F8(3);
}

void sub_804A728(Position *pos, s32 a1, u8 a2, u8 a3)
{
    Position spArray[6];
    u16 *src;
    s32 k;
    Entity *leader;
    s32 i, j;
    s32 adjacentX, adjacentY;
    s32 r5;
    s32 r10;
    s32 r9;
    Position var_48;
    s32 var_38, var_34;
    s32 x, x2, y;
    Dungeon *dungeon = gDungeon;

    leader = GetLeader();
    x = dungeon->unk181e8.cameraPixelPos.x >> 3;
    x2 = x;
    gDungeon->unk181e8.unk1821A = a3;
    i = pos->x;
    j = pos->y;
    adjacentX = gAdjacentTileOffsets[a1].x;
    adjacentY = gAdjacentTileOffsets[a1].y;
    for (k = 0; k < 6; k++) {
        spArray[k].x = i;
        spArray[k].y = j;
        i += adjacentX;
        j += adjacentY;
    }
    var_38 = gUnknown_80F6A4A[30 + x2];
    r10 = gUnknown_80F6C06[30 + x2];

    for (i = 0; i < 31; i++) {
        y = dungeon->unk181e8.cameraPixelPos.y >> 3;
        var_34 = gUnknown_80F6A4A[30 + y];
        r9 = gUnknown_80F6C06[30 + y];
        r5 = var_38 + var_34 * 3;
        var_48.x = r10;
        var_48.y = r9;
        if (a2 != 0) {
            if (r10 == pos->x && r9 == pos->y) {
                src = &dungeon->unk12B92[r5];
            }
            else {
                src = &dungeon->unk13554[r5];
            }
        }
        else if (!sub_807049C(leader, &var_48) && sub_8045AAC(leader, &var_48)) {
            for (k = 0; k < 6; k++) {
                if (spArray[k].x == r10 && spArray[k].y == r9)
                    break;
            }
            if (k == 6) {
                if (gGameOptionsRef->gridEnable) {
                    src = &dungeon->unk12B80[r5];
                }
                else {
                    src = &dungeon->unk13554[r5];
                }
            }
            else {
                src = &dungeon->unk12B92[r5];
            }
        }
        else {
            src = &dungeon->unk13554[r5];
        }

        for (j = 0; j < 21; j++) {
            x &= 0x1F;
            y &= 0x1F;
            gUnknown_202B038[2][y][x] = *src;
            src += 3;
            y++;
            var_34++;
            if (var_34 == 3) {
                var_34 = 0;
                r9++;
                r5 = var_38;
                var_48.x = r10;
                var_48.y = r9;
                if (a2 != 0) {
                    if (r10 == pos->x && r9 == pos->y) {
                        src = &dungeon->unk12B92[r5];
                    }
                    else {
                        src = &dungeon->unk13554[r5];
                    }
                }
                else if (!sub_807049C(leader, &var_48) && sub_8045AAC(leader, &var_48)) {
                    for (k = 0; k < 6; k++) {
                        if (spArray[k].x == r10 && spArray[k].y == r9)
                            break;
                    }
                    if (k == 6) {
                        if (gGameOptionsRef->gridEnable) {
                            src = &dungeon->unk12B80[r5];
                        }
                        else {
                            src = &dungeon->unk13554[r5];
                        }
                    }
                    else {
                        src = &dungeon->unk12B92[r5];
                    }
                }
                else {
                    src = &dungeon->unk13554[r5];
                }
            }
        }

        x++;
        var_38++;
        if (var_38 == 3) {
            var_38 = 0;
            r10++;
        }
    }

    sub_80098F8(2);
}

void sub_804AA60(void)
{
    s32 i;
    s32 j;
    for(i = 0; i < 0x20; i++)
    {
        for(j = 0; j < 0x20; j++)
        {
            gUnknown_202B038[2][i][j] = 0;
        }
    }
    sub_80098F8(2);
    gDungeon->unk181e8.unk1821A = 0;
}

void sub_804AAAC(void)
{
    s32 x;
    s32 y;
    struct Tile *tile;
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            tile = GetTileSafe(x,y);
            tile->unk4 = 0;
        }
    }
}

void sub_804AAD4(void)
{
    struct Tile *tile;
    struct RoomData *room1;
    struct RoomData *room2;
    s32 roomIndex;
    int x;
    int y;
    s32 maxRooms;
    s32 index;

    for(index = 0; index < MAX_ROOM_COUNT; index++)
    {
        gDungeon->roomData[index].unk0 = 0;
        gDungeon->roomData[index].unk1 = 0;
        gDungeon->roomData[index].bottomRightCornerX = 9999;
        gDungeon->roomData[index].bottomRightCornerY = 9999;
        gDungeon->roomData[index].topLeftCornerX = 0xd8f1;
        gDungeon->roomData[index].topLeftCornerY = 0xd8f1;
    }

    maxRooms = 0;
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            tile = GetTile(x,y);
            roomIndex = tile->room;
            if (roomIndex != CORRIDOR_ROOM) {
                room1 = &gDungeon->roomData[roomIndex];
                room1->unk0 = 1;
                if (room1->bottomRightCornerX > x) {
                    room1->bottomRightCornerX = x;
                }
                if (room1->bottomRightCornerY > y) {
                    room1->bottomRightCornerY = y;
                }
                if (room1->topLeftCornerX < x + 1) {
                    room1->topLeftCornerX = x + 1;
                }
                if (room1->topLeftCornerY < y + 1) {
                    room1->topLeftCornerY = y + 1;
                }
                if (maxRooms < roomIndex) {
                    maxRooms = roomIndex;
                }
            }
        }
    }


    for(index = 0; index < MAX_ROOM_COUNT; index++)
    {
        room2 = &gDungeon->roomData[index];
        if(room2 ->unk0 != 0)
        {
            room2->unkC = (room2->bottomRightCornerX - 1) * 24;
            room2->unk10 = (room2->bottomRightCornerY - 1) * 24;
            room2->unk14 = (room2->topLeftCornerX + 1) * 24;
            room2->unk18 = (room2->topLeftCornerY + 1)  * 24;
        }
    }

    gDungeon->unk104C0 = maxRooms + 1;
}

void sub_804AC20(Position *pos)
{
    s32 y;
    struct Tile *tile2;
    struct Tile *tile;
    s32 yMax;
    u32 visibilityRange;
    s32 xMin;
    s32 x;
    s32 xMax;
    s32 yMin;
    s32 roomIndex;
    struct RoomData *room;

    tile2 = GetTile(pos->x,pos->y);
    roomIndex = tile2->room;
    visibilityRange = gDungeon->unk181e8.visibilityRange;
    if (!gDungeon->unk181e8.blinded) {
        if (visibilityRange == 0) {
            visibilityRange = 2;
        }
        if (roomIndex == CORRIDOR_ROOM) {
            xMin = pos->x - visibilityRange;
            yMin = pos->y - visibilityRange;
            xMax = pos->x + visibilityRange;
            yMax = pos->y + visibilityRange;
        }
        else {
            room = &gDungeon->roomData[roomIndex];
            if (room->unk1 != 0) {
                return;
            }
            room->unk1 = 1;
            xMin = room->bottomRightCornerX - 1;
            yMin = room->bottomRightCornerY - 1;
            xMax = room->topLeftCornerX;
            yMax = room->topLeftCornerY;
        }
        for (y = yMin; y <= yMax; y++) {
            for (x = xMin; x <= xMax; x++) {
                tile = GetTileSafe(x,y);
                tile->unk4 = tile->unk4 | 3;
                sub_80402AC(x,y);
            }
        }
    }
}
