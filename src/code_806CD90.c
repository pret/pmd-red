#include "global.h"
#include "code_805D8C8.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "tile_types.h"

extern u8 sub_806CEBC(struct Entity *);
extern void sub_806CCB4(struct Entity *, u8);
extern void sub_803E46C(u32);
extern bool8 sub_808DA44(s32 a1_, u32 a2_);
extern u32 sub_806CF98(struct Entity *);
extern struct OpenedFile *sub_80687D0(s16);
void sub_806CDD4(struct Entity *, u8, u32);

extern const u8 gUnknown_8106EEF[];
extern const u8 gDungeonWaterType[];

void sub_806CC10(void)
{
  struct EntityInfo *entityInfo;
  struct Entity *entity;
  s32 index;
  
  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeon->allPokemon[index];
    if (EntityExists(entity)) {
      entityInfo = entity->info;

      if ((entityInfo->unk166 != 0) && (entityInfo->unk166--, (entityInfo->unk166 & 1) == 0)) {
        sub_806CDD4(entity,0, (entityInfo->action.direction - 1) & 7);
      }
    }
  }
}

void sub_806CC70(void)
{
    s32 index;
    struct Entity *entity;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if(EntityExists(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CCB4(struct Entity *entity, u8 param_2)
{
    s32 sVar1;
    bool8 flag;
    struct EntityInfo *info;

    info = entity->info;
    flag = gDungeon->hallucinating;

    if (entity == gDungeon->cameraTarget)
        flag = FALSE;

    entity->unk6B = param_2;
    entity->unk6A = param_2;
    entity->direction2 = info->action.direction;
    entity->direction = info->action.direction;
    entity->unk6F = 0;
    sVar1 = entity->unk68;

    if (info->waitingStatus != STATUS_DECOY && !flag)
        sub_80053AC(&entity->spriteInfo, entity->sprite, entity->unk6A, entity->direction, sVar1, Rand32Bit() & 3, FALSE);
    else
        sub_80053AC(&entity->spriteInfo, sub_80687D0(MONSTER_DECOY), entity->unk6A, entity->direction, sVar1, Rand32Bit() & 3, FALSE);

    entity->unk6E = 0;
}

void sub_806CD90(void)
{
    s32 index;
    struct Entity *entity;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if(EntityExists(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CDD4(struct Entity *entity, u8 r1, u32 r2)
{
    if(GetEntityType(entity) == ENTITY_MONSTER)
    {
        entity->unk6A = r1;
        if(r2 < NUM_DIRECTIONS) entity->direction = r2;
    }
}

void sub_806CDFC(struct Entity *entity, u8 r1, u32 r2)
{
    if(GetEntityType(entity) == ENTITY_MONSTER)
    {
        if(entity->unk6B == r1)
        {
            if(entity->direction2 == r2)
                return;
            else
                goto change_dir;
        }
        else
        {
change_dir:
            sub_806CDD4(entity, r1, r2);
        }
    }
}

void sub_806CE34(struct Entity *entity, u32 newDir)
{
    if(GetEntityType(entity) == ENTITY_MONSTER)
    {
        entity->unk6A = sub_806CEBC(entity);
        if(newDir < NUM_DIRECTIONS)
        {
            entity->info->action.direction = newDir & DIRECTION_MASK;
            entity->direction = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(struct Entity *entity, u32 newDir)
{
    if(GetEntityType(entity) == ENTITY_MONSTER)
    {
        entity->unk6A = sub_806CEBC(entity);
        if(newDir < NUM_DIRECTIONS)
        {
            entity->direction = newDir;
        }
    }
}

void sub_806CE94(struct Entity *entity, u32 newDir)
{
    if(GetEntityType(entity) == ENTITY_MONSTER)
    {
        entity->unk6A = 6;
        if(newDir < NUM_DIRECTIONS)
        {
            entity->direction = newDir;
        }
    }
}

u8 sub_806CEBC(struct Entity *entity)
{
  u8 sleep;
  struct EntityInfo * entityInfo1;
  struct EntityInfo * entityInfo2;

  // NOTE: copy needed to match
  entityInfo1 = entity->info;
  entityInfo2 = entity->info;
  sleep = entityInfo1->sleep;

  if ((sleep == STATUS_SLEEP) || (sleep == STATUS_NAPPING) || (sleep == STATUS_NIGHTMARE)) {
    if ((entityInfo2->apparentID != MONSTER_SUDOWOODO) || (entityInfo2->sleepTurns != 0x7f)) {
      return 5;
    }
    else
        return 7;
  }
  else if (entityInfo2->chargingStatus == STATUS_BIDE) {
    return 0xB;
  }
  return 0x7;
}

void sub_806CEFC(struct Entity *entity, u32 newDir)
{
  entity->info->action.direction = newDir & DIRECTION_MASK;
  sub_806CE68(entity, (newDir & DIRECTION_MASK));
}

void sub_806CF18(struct Entity *entity)
{
  s32 index;
  struct EntityInfo *entityInfo;

  if (EntityExists(entity)) {
    entityInfo = entity->info;
    for (index = 0; index < 100; index++) {
      sub_803E46C(0x21);
      if (!sub_808DA44(entityInfo->apparentID, entity->unk6B)) {
        break;
      }
    }
  }
}

u8 sub_806CF54(struct Entity *entity)
{
    return entity->info->unk204;
}

void sub_806CF60(void)
{
  struct Entity *entity;
  s32 index;

  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeon->allPokemon[index];
    if (EntityExists(entity)) {
      sub_806CF98(entity);
    }
  }
}

u32 sub_806CF98(struct Entity *entity)
{
  struct Tile *mapTile;
  u32 uVar3;
  u16 terrainType;
  struct EntityInfo *entityInfo;

  mapTile = GetTileAtEntitySafe(entity);
  terrainType = mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  entityInfo = entity->info;
  uVar3 = GetShadowSize(entityInfo->apparentID);
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
  entityInfo->unk204 = uVar3;
  return uVar3;
}
