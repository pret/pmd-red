#include "global.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "tile_types.h"

extern u8 sub_806CEBC(struct Entity *);
extern void sub_806CCB4(struct Entity *, u8);
extern void sub_803E46C(u32);
extern bool8 sub_808DA44(s32 a1_, u32 a2_);
extern u32 sub_806CF98(struct Entity *);

extern const u8 gUnknown_8106EEF[];
extern const u8 gDungeonWaterType[];

void sub_806CD90(void)
{
    s32 iVar3;
    struct Entity *iVar2;
    for(iVar3 = 0; iVar3 < DUNGEON_MAX_POKEMON; iVar3++)
    {
        iVar2 = gDungeon->allPokemon[iVar3];
        if(EntityExists(iVar2))
            sub_806CCB4(iVar2, sub_806CEBC(iVar2));
    }
}

void sub_806CDD4(struct Entity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_MONSTER)
    {
        r0->unk6A = r1;
        if(r2 < NUM_DIRECTIONS) r0->direction = r2;
    }
}

void sub_806CDFC(struct Entity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_MONSTER)
    {
        if(r0->unk6B == r1)
        {
            if(r0->direction2 == r2)
                return;
            else
                goto change_dir;
        }
        else
        {
change_dir:
            sub_806CDD4(r0, r1, r2);
        }
    }
}

void sub_806CE34(struct Entity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_MONSTER)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->info->action.direction = newDir & DIRECTION_MASK;
            r0->direction = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(struct Entity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_MONSTER)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->direction = newDir;
        }
    }
}

void sub_806CE94(struct Entity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_MONSTER)
    {
        r0->unk6A = 6;
        if(newDir < NUM_DIRECTIONS)
        {
            r0->direction = newDir;
        }
    }
}

u8 sub_806CEBC(struct Entity *param_1)
{
  u8 sleep;
  struct EntityInfo * iVar2;
  struct EntityInfo * iVar3;

  // NOTE: copy needed to match
  iVar2 = param_1->info;
  iVar3 = param_1->info;
  sleep = iVar2->sleep;

  if ((sleep == STATUS_SLEEP) || (sleep == STATUS_NAPPING) || (sleep == STATUS_NIGHTMARE)) {
    if ((iVar3->apparentID != MONSTER_SUDOWOODO) || (iVar3->sleepTurns != 0x7f)) {
      return 5;
    }
    else
        return 7;
  }
  else if (iVar3->chargingStatus == STATUS_BIDE) {
    return 0xB;
  }
  return 0x7;
}

void sub_806CEFC(struct Entity *param_1, u32 newDir)
{
  param_1->info->action.direction = newDir & DIRECTION_MASK;
  sub_806CE68(param_1, (newDir & DIRECTION_MASK));
}

void sub_806CF18(struct Entity *param_1)
{
  s32 iVar2;
  struct EntityInfo *entityData;

  if (EntityExists(param_1)) {
    entityData = param_1->info;
    for (iVar2 = 0; iVar2 < 100; iVar2++) {
      sub_803E46C(0x21);
      if (!sub_808DA44(entityData->apparentID, param_1->unk6B)) {
        break;
      }
    }
  }
}

u8 sub_806CF54(struct Entity *param_1)
{
    return param_1->info->unk204;
}

void sub_806CF60(void)
{
  struct Entity *uVar2;
  s32 iVar3;

  for(iVar3 = 0; iVar3 < DUNGEON_MAX_POKEMON; iVar3++)
  {
    uVar2 = gDungeon->allPokemon[iVar3];
    if (EntityExists(uVar2)) {
      sub_806CF98(uVar2);
    }
  }
}

u32 sub_806CF98(struct Entity *param_1)
{
  struct Tile *mapTile;
  u32 uVar3;
  u16 terrainType;
  struct EntityInfo *entityData;

  mapTile = GetTileAtEntitySafe(param_1);
  terrainType = mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  entityData = param_1->info;
  uVar3 = GetShadowSize(entityData->apparentID);
  if (terrainType == (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) {
    return 6;
  }
  if (terrainType == TERRAIN_TYPE_NORMAL) {
    if (IsWaterTileset()) {
      uVar3 = gUnknown_8106EEF[uVar3];
    }
  }
  else if ((terrainType == TERRAIN_TYPE_SECONDARY) && (gDungeonWaterType[gDungeon->tileset] != DUNGEON_WATER_TYPE_LAVA))
    uVar3 = gUnknown_8106EEF[uVar3];
  entityData->unk204 = uVar3;
  return uVar3;
}
