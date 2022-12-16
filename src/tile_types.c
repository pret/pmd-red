#include "global.h"
#include "tile_types.h"

#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"

const u8 gDungeonWaterType[] = {
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_WATER,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_WATER,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
};

extern void sub_80498A8(s32, s32);
extern void sub_80402AC(s32, s32);
extern void sub_8049BB0(s32, s32);
extern u32 sub_806CF98(struct DungeonEntity *);
void sub_8042A14(struct Position *);
extern void sub_8049ED4(void);

bool8 sub_804ACE4(struct Position *pos)
{
  struct MapTile *tile;
  struct DungeonEntity *entity;
  
  tile = GetMapTile_1(pos->x,pos->y);
  entity = tile->mapObject;
  if ((entity != NULL) && (GetEntityType(entity) == ENTITY_ITEM)) {
    return TRUE;
  }
  return FALSE;
}

struct DungeonEntity *sub_804AD0C(struct Position *pos)
{
  struct MapTile *tile;
  struct DungeonEntity *entity;
  
  tile = GetMapTile_1(pos->x,pos->y);
  entity = tile->pokemon;
  if ((entity != NULL) && (entity->entityType == ENTITY_POKEMON)) {
    return entity;
  }
  return NULL;
}

bool8 sub_804AD34(struct Position *pos)
{
  struct MapTile *tile;
  s32 x;
  struct DungeonEntity * entity;
  s32 y;
  bool8 iVar8;
  s32 index;
  
  iVar8 = 0;
  tile = GetMapTile_2(pos->x,pos->y);
  if (!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
    if(!(tile->tileType & (TILE_TYPE_UNK_8 | TILE_TYPE_MAP_EDGE))){
    iVar8 = 1;
    tile->tileType = (tile->tileType & ~(TILE_TYPE_LIQUID | TILE_TYPE_FLOOR)) | TILE_TYPE_FLOOR;

    for(y = -1; y < 2; y++)
    {
      for(x = -1; x < 2; x++)
      {
        sub_80498A8(x + pos->x, y + pos->y);
        sub_8049BB0(x + pos->x, y + pos->y);
        sub_80402AC(x + pos->x, y + pos->y);
      }
    }
  }
  if (iVar8 != 0) {
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeonGlobalData->allPokemon[index];
      if (EntityExists(entity)) {
        sub_806CF98(entity);
      }
    }
    sub_8049ED4();
    sub_8042A14(pos);
  }
  return iVar8;
}

bool8 sub_804AE08(struct Position *pos)
{
  struct MapTile *tile;
  s32 x;
  s32 y;
  bool8 uVar6;
  
  uVar6 = FALSE;
  tile = GetMapTile_2(pos->x,pos->y);

  if (!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
    if(!(tile->tileType & (TILE_TYPE_UNK_8 | TILE_TYPE_MAP_EDGE))) {
        uVar6 = TRUE;
        tile->tileType = (tile->tileType & ~(TILE_TYPE_LIQUID | TILE_TYPE_FLOOR)) | TILE_TYPE_FLOOR;
        tile->unk4 = tile->unk4 | 0x10;

        for(y = -1; y < 2; y++)
        {
            for(x = -1; x < 2; x++)
            {
                sub_8049BB0(x + pos->x, y + pos->y);
            }
        }
    }
  return uVar6;
}

void sub_804AE84(struct Position *pos)
{
  struct MapTile *tile;
  s32 x;
  struct DungeonEntity * entity;
  s32 index;
  s32 y;
  
  tile = GetMapTile_2(pos->x,pos->y);
  if ((tile->unk4 & 0x10) != 0) {
    tile->unk4 = tile->unk4 & 0xffef;

    for(y = -1; y < 2; y++)
    {
      for(x = -1; x < 2; x++)
      {
        sub_80498A8(x + pos->x, y + pos->y);
        sub_80402AC(x + pos->x, y + pos->y);
      }
    }

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeonGlobalData->allPokemon[index];
      if (EntityExists(entity)) {
        sub_806CF98(entity);
      }
    }
    sub_8049ED4();
    sub_8042A14(pos);
  }
}

bool8 IsTileGround(struct MapTile* tile)
{
    bool8 isGround = FALSE;
    if (IsWaterTileset())
    {
        if (!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
        {
            isGround = TRUE;
        }
    }
    else if ((tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) != TILE_TYPE_LIQUID ||
        gDungeonWaterType[gDungeonGlobalData->tileset] == DUNGEON_WATER_TYPE_LAVA)
    {
        isGround = TRUE;
    }
    return isGround;
}

bool8 IsWaterTileset()
{
    if (gDungeonGlobalData->tileset == 0 ||
        gDungeonGlobalData->tileset == 0x31 ||
        gDungeonGlobalData->tileset == 0x20 ||
        gDungeonGlobalData->tileset == 0x21 ||
        gDungeonGlobalData->tileset == 0x36)
    {
        return TRUE;
    }
    return FALSE;
}
