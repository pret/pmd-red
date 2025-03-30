#include "global.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "structs/str_dungeon.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "dungeon_logic.h"
#include "dungeon_config.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_misc.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "position_util.h"
#include "random.h"
#include "sprite.h"
#include "status.h"
#include "text_util.h"

const u8 gUnknown_8106EEF[] = {0x03, 0x04, 0x05, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00 };

void sub_806CC10(void)
{
    EntityInfo *entityInfo;
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);

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
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CCB4(Entity *entity, u8 a1)
{
    s32 sVar1;
    bool8 flag;
    EntityInfo *info;

    info = GetEntInfo(entity);
    flag = gDungeon->unk181e8.hallucinating;

    if (entity == gDungeon->unk181e8.cameraTarget)
        flag = FALSE;

    entity->axObj.unk43_animId2 = a1;
    entity->axObj.unk42_animId1 = a1;
    entity->axObj.unk45_orientation = info->action.direction;
    entity->axObj.unk44_direction1 = info->action.direction;
    entity->axObj.unk47 = 0;
    sVar1 = entity->axObj.unk40_maybeAnimTimer;

    if (info->curseClassStatus.status != STATUS_DECOY && !flag)
        AxResInitFile(&entity->axObj.axdata,
                      entity->axObj.spriteFile, entity->axObj.unk42_animId1,
                      entity->axObj.unk44_direction1, sVar1,
                      Rand32Bit() & 3, FALSE);
    else
        AxResInitFile(&entity->axObj.axdata,
                      GetSpriteData(MONSTER_DECOY),
                      entity->axObj.unk42_animId1,
                      entity->axObj.unk44_direction1, sVar1, Rand32Bit() & 3,
                      FALSE);

    entity->axObj.unk46 = 0;
}

void sub_806CD90(void)
{
    s32 i;
    Entity *entity;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CDD4(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = a1;

        if (direction < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = direction;
    }
}

void sub_806CDFC(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        if (entity->axObj.unk43_animId2 == a1 && entity->axObj.unk45_orientation == direction)
            return;
        sub_806CDD4(entity, a1, direction);
    }
}

void sub_806CE34(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS) {
            GetEntInfo(entity)->action.direction = newDir & DIRECTION_MASK;
            entity->axObj.unk44_direction1 = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = newDir;
    }
}

void sub_806CE94(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = 6;

        if (newDir < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = newDir;
    }
}

u8 sub_806CEBC(Entity *entity)
{
    u8 sleepClassStatus;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(entity);
    sleepClassStatus = entityInfo->sleepClassStatus.status;

    if (sleepClassStatus == STATUS_SLEEP || sleepClassStatus == STATUS_NAPPING || sleepClassStatus == STATUS_NIGHTMARE) {
        if (entityInfo->apparentID != MONSTER_SUDOWOODO || entityInfo->sleepClassStatus.turns != 0x7F)
            return 5;
        else
            return 7;
    }
    if (entityInfo->bideClassStatus.status == STATUS_BIDE)
        return 11;
    return 7;
}

void sub_806CEFC(Entity *entity, u32 newDir)
{
    GetEntInfo(entity)->action.direction = newDir & DIRECTION_MASK;
    sub_806CE68(entity, newDir & DIRECTION_MASK);
}

void sub_806CF18(Entity *entity)
{
    s32 i;
    EntityInfo *entityInfo;

    if (!EntityIsValid(entity))
        return;

    entityInfo = GetEntInfo(entity);
    for (i = 0; i < 100; i++) {
        DungeonRunFrameActions(33);

        if (!sub_808DA44(entityInfo->apparentID, entity->axObj.unk43_animId2))
            break;
    }
}

u8 sub_806CF54(Entity *entity)
{
    return GetEntInfo(entity)->unk204;
}

void sub_806CF60(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CF98(entity);
    }
}

u32 sub_806CF98(Entity *entity)
{
    const Tile *mapTile;
    u32 shadowSize;
    u16 terrainType;
    EntityInfo *entityInfo;

    mapTile = GetTileAtEntitySafe(entity);
    terrainType = mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    entityInfo = GetEntInfo(entity);
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
