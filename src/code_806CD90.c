#include "global.h"
#include "code_806CD90.h"

#include "code_803E46C.h"
#include "code_805D8C8.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "dungeon_util.h"
#include "pokemon_mid.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"

const u8 gUnknown_8106EEF[] = {0x03, 0x04, 0x05, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00 };

void sub_806CC10(void)
{
    EntityInfo *entityInfo;
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity)) {
            entityInfo = entity->info;

            if (entityInfo->unk166 != 0) {
                entityInfo->unk166--;
                if ((entityInfo->unk166 & 1) == 0) // If value is even:
                    sub_806CDD4(entity, 0, (entityInfo->action.direction - 1) & DIRECTION_MASK);
            }
        }
    }
}

void sub_806CC70(void)
{
    s32 i;
    Entity *entity;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CCB4(Entity *entity, u8 a1)
{
    s32 sVar1;
    bool8 flag;
    EntityInfo *info;

    info = entity->info;
    flag = gDungeon->unk181e8.hallucinating;

    if (entity == gDungeon->unk181e8.cameraTarget)
        flag = FALSE;

    entity->unk6B = a1;
    entity->unk6A = a1;
    entity->direction2 = info->action.direction;
    entity->direction = info->action.direction;
    entity->unk6F = 0;
    sVar1 = entity->unk68;

    if (info->waitingStruct.waitingStatus != STATUS_DECOY && !flag)
        sub_80053AC(&entity->spriteInfo, entity->sprite, entity->unk6A, entity->direction, sVar1, Rand32Bit() & 3, FALSE);
    else
        sub_80053AC(&entity->spriteInfo, sub_80687D0(MONSTER_DECOY), entity->unk6A, entity->direction, sVar1, Rand32Bit() & 3, FALSE);

    entity->unk6E = 0;
}

void sub_806CD90(void)
{
    s32 i;
    Entity *entity;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CDD4(Entity *entity, u8 a1, u32 a2)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->unk6A = a1;

        if (a2 < NUM_DIRECTIONS)
            entity->direction = a2;
    }
}

void sub_806CDFC(Entity *entity, u8 a1, u32 a2)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        if (entity->unk6B == a1 && entity->direction2 == a2)
            return;
        sub_806CDD4(entity, a1, a2);
    }
}

void sub_806CE34(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->unk6A = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS) {
            entity->info->action.direction = newDir & DIRECTION_MASK;
            entity->direction = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->unk6A = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS)
            entity->direction = newDir;
    }
}

void sub_806CE94(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->unk6A = 6;

        if (newDir < NUM_DIRECTIONS)
            entity->direction = newDir;
    }
}

u8 sub_806CEBC(Entity *entity)
{
    u8 sleep;
    EntityInfo *entityInfo1;
    EntityInfo *entityInfo2;

    // NOTE: copy needed to match
    entityInfo1 = entity->info;
    entityInfo2 = entity->info;
    sleep = entityInfo1->sleep.sleep;

    if (sleep == STATUS_SLEEP || sleep == STATUS_NAPPING || sleep == STATUS_NIGHTMARE) {
        if (entityInfo2->apparentID != MONSTER_SUDOWOODO || entityInfo2->sleep.sleepTurns != 0x7F)
            return 5;
        else
            return 7;
    }
    if (entityInfo2->charging.chargingStatus == STATUS_BIDE)
        return 11;
    return 7;
}

void sub_806CEFC(Entity *entity, u32 newDir)
{
    entity->info->action.direction = newDir & DIRECTION_MASK;
    sub_806CE68(entity, newDir & DIRECTION_MASK);
}

void sub_806CF18(Entity *entity)
{
    s32 i;
    EntityInfo *entityInfo;

    if (!EntityExists(entity))
        return;

    entityInfo = entity->info;
    for (i = 0; i < 100; i++) {
        sub_803E46C(33);

        if (!sub_808DA44(entityInfo->apparentID, entity->unk6B))
            break;
    }
}

u8 sub_806CF54(Entity *entity)
{
    return entity->info->unk204;
}

void sub_806CF60(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity))
            sub_806CF98(entity);
    }
}

u32 sub_806CF98(Entity *entity)
{
    struct Tile *mapTile;
    u32 shadowSize;
    u16 terrainType;
    EntityInfo *entityInfo;

    mapTile = GetTileAtEntitySafe(entity);
    terrainType = mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    entityInfo = entity->info;
    shadowSize = GetShadowSize(entityInfo->apparentID);

    if (terrainType == (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))
        return 6;

    if (terrainType == TERRAIN_TYPE_NORMAL) {
        if (IsWaterTileset())
            shadowSize = gUnknown_8106EEF[shadowSize];
    }
    else if (terrainType == TERRAIN_TYPE_SECONDARY && gDungeonWaterType[gDungeon->tileset] != DUNGEON_WATER_TYPE_LAVA)
        shadowSize = gUnknown_8106EEF[shadowSize];

    entityInfo->unk204 = shadowSize;
    return shadowSize;
}
