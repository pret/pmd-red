#include "global.h"
#include "constants/walkable_tile.h"
#include "dungeon_map_access.h"

#include "dungeon_global_data.h"
#include "file_system.h"
#include "tile_types.h"

extern struct unkStruct_202F190 gUnknown_202F190;
extern struct unkStruct_202F190 *gUnknown_203B430;
extern struct unkStruct_202F190 gUnknown_80F69D4;
extern struct unkStruct_202F190 gUnknown_80F69EC;

extern u8 gUnknown_8108EC0[];
extern u8 gUnknown_80F6A04[];
extern u8 gUnknown_80F6A10[];
extern u8 gUnknown_80F6A28[];
extern u8 gUnknown_80F6A1C[];
extern u8 gUnknown_80F6A34[];
extern u8 gUnknown_80F6A40[];
extern const struct FileArchive gDungeonFileArchive;

extern struct OpenedFile *gUnknown_202F18C;
extern struct OpenedFile *gDungeonPaletteFile;
extern u8 gUnknown_202EE8C[];
extern u8 gWalkableTileToCrossableTerrain[8];
extern const u8 gDungeonWaterType[];
extern u8 sub_8043CE4(u32);

extern void sub_8004AA4(u8 *, struct OpenedFile *, u32);
extern int sprintf(char *, const char *, ...);

struct Tile* GetTile(s32 x, s32 y)
{
    if (x >= 0 && y >= 0 && x < DUNGEON_MAX_SIZE_X && y < DUNGEON_MAX_SIZE_Y)
    {
        return gDungeon->tilePointers[y][x];
    }
    return (struct Tile*) gUnknown_203B430->unk0;
}

struct Tile* GetTileSafe(s32 x, s32 y)
{
    if (x < 0 || y < 0 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y)
    {
        struct Tile* tile = (struct Tile*) gUnknown_202F190.unk0;
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
  struct OpenedFile *file;
  struct OpenedFile *file_1;
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

extern void sub_80498A8(s32, s32);

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
