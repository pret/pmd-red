#include "global.h"
#include "code_8004AA0.h"
#include "constants/walkable_tile.h"
#include "decompress.h"
#include "dungeon_map_access.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "random.h"
#include "dungeon_engine.h"

extern unkStruct_202F190 gUnknown_202F190;
extern unkStruct_202F190 *gUnknown_203B430;
extern unkStruct_202F190 gUnknown_80F69D4;
extern unkStruct_202F190 gUnknown_80F69EC;

extern u8 gUnknown_8108EC0[];
extern u8 gUnknown_80F6A04[];
extern u8 gUnknown_80F6A10[];
extern u8 gUnknown_80F6A28[];
extern u8 gUnknown_80F6A1C[];
extern u8 gUnknown_80F6A34[];
extern u8 gUnknown_80F6A40[];
extern const struct FileArchive gDungeonFileArchive;

extern OpenedFile *gUnknown_202F18C;
extern OpenedFile *gDungeonPaletteFile;
extern unkStruct_202EE8C gUnknown_202EE8C[32];
extern u8 gWalkableTileToCrossableTerrain[8];
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
  DecompressATFile(gDungeon->unk11884,0x1194,file_1);
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