#include "global.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "tile_types.h"

extern u8 sub_806CEBC(struct DungeonEntity *);
extern void sub_806CCB4(struct DungeonEntity *, u8);
extern void sub_803E46C(u32);
extern bool8 sub_808DA44(s32 a1_, u32 a2_);
extern u32 sub_806CF98(struct DungeonEntity *);

extern const u8 gUnknown_8106EEF[];
extern const u8 gDungeonWaterType[];

void sub_806CD90(void)
{
    s32 iVar3;
    struct DungeonEntity *iVar2;
    for(iVar3 = 0; iVar3 < DUNGEON_MAX_POKEMON; iVar3++)
    {
        iVar2 = gDungeonGlobalData->allPokemon[iVar3];
        if(EntityExists(iVar2))
            sub_806CCB4(iVar2, sub_806CEBC(iVar2));
    }
}

void sub_806CDD4(struct DungeonEntity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = r1;
        if(r2 < NUM_DIRECTIONS) r0->facingDir = r2;
    }
}

void sub_806CDFC(struct DungeonEntity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        if(r0->unk6B == r1)
        {
            if(r0->facingDir2 == r2)
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

void sub_806CE34(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->entityData->action.facingDir = newDir & DIRECTION_MASK;
            r0->facingDir = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->facingDir = newDir;
        }
    }
}

void sub_806CE94(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = 6;
        if(newDir < NUM_DIRECTIONS)
        {
            r0->facingDir = newDir;
        }
    }
}

u8 sub_806CEBC(struct DungeonEntity *param_1)
{
  u8 sleepStatus;
  struct DungeonEntityData * iVar2;
  struct DungeonEntityData * iVar3;

  // NOTE: copy needed to match
  iVar2 = param_1->entityData;
  iVar3 = param_1->entityData;
  sleepStatus = iVar2->sleepStatus;

  if ((sleepStatus == SLEEP_STATUS_SLEEP) || (sleepStatus == SLEEP_STATUS_NAPPING) || (sleepStatus == SLEEP_STATUS_NIGHTMARE)) {
    if ((iVar3->transformSpecies != SPECIES_SUDOWOODO) || (iVar3->sleepStatusTurnsLeft != 0x7f)) {
      return 5;
    }
    else
        return 7;
  }
  else if (iVar3->chargingStatus == CHARGING_STATUS_BIDE) {
    return 0xB;
  }
  return 0x7;
}

void sub_806CEFC(struct DungeonEntity *param_1, u32 newDir)
{
  param_1->entityData->action.facingDir = newDir & DIRECTION_MASK;
  sub_806CE68(param_1, (newDir & DIRECTION_MASK));
}

void sub_806CF18(struct DungeonEntity *param_1)
{
  s32 iVar2;
  struct DungeonEntityData *entityData;

  if (EntityExists(param_1)) {
    entityData = param_1->entityData;
    for (iVar2 = 0; iVar2 < 100; iVar2++) {
      sub_803E46C(0x21);
      if (!sub_808DA44(entityData->transformSpecies, param_1->unk6B)) {
        break;
      }
    }
  }
}

u8 sub_806CF54(struct DungeonEntity *param_1)
{
    return param_1->entityData->unk204;
}

void sub_806CF60(void)
{
  struct DungeonEntity *uVar2;
  s32 iVar3;

  for(iVar3 = 0; iVar3 < DUNGEON_MAX_POKEMON; iVar3++)
  {
    uVar2 = gDungeonGlobalData->allPokemon[iVar3];
    if (EntityExists(uVar2)) {
      sub_806CF98(uVar2);
    }
  }
}

u32 sub_806CF98(struct DungeonEntity *param_1)
{
  struct MapTile *mapTile;
  u32 uVar3;
  u16 tileType;
  struct DungeonEntityData *entityData;

  mapTile = GetMapTileForDungeonEntity_2(param_1);
  tileType = mapTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID);
  entityData = param_1->entityData;
  uVar3 = GetShadowSize(entityData->transformSpecies);
  if (tileType == (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) {
    return 6;
  }
  if (tileType == TILE_TYPE_FLOOR) {
    if (IsWaterTileset()) {
      uVar3 = gUnknown_8106EEF[uVar3];
    }
  }
  else if ((tileType == TILE_TYPE_LIQUID) && (gDungeonWaterType[gDungeonGlobalData->tileset] != DUNGEON_WATER_TYPE_LAVA))
    uVar3 = gUnknown_8106EEF[uVar3];
  entityData->unk204 = uVar3;
  return uVar3;
}
