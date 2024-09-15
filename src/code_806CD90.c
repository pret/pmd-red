#include "global.h"
#include "code_806CD90.h"
#include "code_803E46C.h"
#include "code_805D8C8.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "dungeon_util.h"
#include "pokemon_mid.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "dungeon_capabilities.h"
#include "dungeon_random.h"
#include "text_util.h"
#include "code_804267C.h"
#include "move_effects_target.h"
#include "dungeon_pokemon_attributes.h"

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

void sub_806CDD4(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->unk6A = a1;

        if (direction < NUM_DIRECTIONS)
            entity->direction = direction;
    }
}

void sub_806CDFC(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        if (entity->unk6B == a1 && entity->direction2 == direction)
            return;
        sub_806CDD4(entity, a1, direction);
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

struct UnkStruct_sub_806D010
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
};

bool8 sub_806D528(Entity *, Entity *, struct UnkStruct_sub_806D010 *r8, bool32, s32, s32, s32);

extern void sub_807F43C(Entity *, Entity *);
extern void sub_8041B18(Entity *pokemon);
extern void sub_8041B90(Entity *pokemon);
extern void sub_80522F4(Entity *, Entity *, const u8 *);
extern void sub_8041D00(Entity *pokemon, Entity *target);
extern void DealDamageToEntity(Entity *, s32, u32, u32);

extern const s32 gUnknown_8106A4C;
extern const s16 gUnknown_80F4E10;
extern const s16 gUnknown_80F4E12;
extern const s16 gUnknown_80F4E14;
extern const s16 gUnknown_80F4E16;
extern const s16 gUnknown_80F4E18;
extern const s16 gUnknown_80F4E1A;
extern const s16 gUnknown_80F4E1C;
extern const s16 gUnknown_80F4E1E;
extern const s16 gUnknown_80F4E20;
extern const u8 *const gUnknown_80FCFA4;

void sub_806D010(Entity *r6, Entity *r5, struct UnkStruct_sub_806D010 *r8, bool32 r3, s32 arg0, s16 arg4, bool32 arg8, s32 argC)
{
    bool32 r9;
    // Some compiler weirdness, because it won't match without creating arg4 again
    s32 r10 = arg4;
    s32 r7 = 0;

    if (sub_806D528(r6, r5, r8, r3, arg0, r10, argC))
        return;
    if (r8->unkF)
        return;
    if (!EntityExists(r6) || !EntityExists(r5))
        return;
    if (GetEntityType(r6) != ENTITY_MONSTER || GetEntityType(r5) != ENTITY_MONSTER)
        return;

    r9 = arg8;
    if (CheckVariousStatuses(r5) || r5->info->charging.chargingStatus != 0)
        r9 = FALSE;
    if (r9
        && abs(r6->pos.x - r5->pos.x) <= 1 && abs(r6->pos.y - r5->pos.y) <= 1
        && r6 != r5
        && sub_8092354(r8->unkC)
        && r5->info->protection.protectionStatus == STATUS_VITAL_THROW)
    {
        sub_8042730(r5, r6);
        sub_807F43C(r5, r6);
    }

    if (r5->info->charging.chargingStatus == STATUS_ENRAGED) {
        RaiseAttackStageTarget(r6, r5, gUnknown_8106A4C, 1);
    }

    if (!EntityExists(r6) || !EntityExists(r5))
        return;

    if (r9
        && r6 != r5
        && abs(r6->pos.x - r5->pos.x) <= 1 && abs(r6->pos.y - r5->pos.y) <= 1)
    {
        u8 r4 = sub_8092354(r8->unkC); // Possibly move category/split
        if (r5->info->protection.protectionStatus == STATUS_COUNTER && r4 != 0) {
            sub_8041B18(r5);
            r7 += 4;
        }
        if (r5->info->protection.protectionStatus == STATUS_MINI_COUNTER && r4 != 0) {
            sub_8041B18(r5);
            r7 += 1;
        }
        if (r5->info->protection.protectionStatus == STATUS_MIRROR_COAT && r4 == 0) {
            sub_8041B90(r5);
            r7 += 4;
        }

        if (HasAbility(r5, ABILITY_ROUGH_SKIN))
            r7 += 2;

        if (r7) {
            struct UnkStruct_sub_806D010 sp;

            sub_80522F4(r6, r5, gUnknown_80FCFA4);
            sp.unk0 = (r8->unk0 * r7) / 4;
            sp.unkC = r8->unkC;
            sp.unk4 = 6;
            sp.unk8 = 2;
            sp.unkD = 0;
            sp.unkE = 0;
            sp.unkF = 0;
            sub_806D528(r5, r6, &sp, FALSE, arg0, r10, argC);
        }
    }
    if (!EntityExists(r6) || !EntityExists(r5))
        return;

    // Check trapping / contact abilities
    if (r9
        && r6 != r5
        && abs(r6->pos.x - r5->pos.x) <= 1 && abs(r6->pos.y - r5->pos.y) <= 1)
    {
        bool8 unkBool = sub_8092354(r8->unkC);
        EntityInfo *monInfo = r6->info;

        if (HasAbility(r5, ABILITY_ARENA_TRAP)
            && !MonsterIsType(r6, TYPE_FLYING)
            && !HasAbility(r6, ABILITY_LEVITATE)
            && DungeonRandInt(100) < gUnknown_80F4E10)
        {
            monInfo->unk178 |= 1;
        }
        if (HasAbility(r5, ABILITY_SHADOW_TAG)
            && DungeonRandInt(100) < gUnknown_80F4E12)
        {
            monInfo->unk178 |= 2;
        }
        if (HasAbility(r5, ABILITY_MAGNET_PULL)
            && MonsterIsType(r6, TYPE_STEEL)
            && DungeonRandInt(100) < gUnknown_80F4E14)
        {
            monInfo->unk178 |= 4;
        }

        if (HasAbility(r5, ABILITY_STATIC)
            && unkBool
            && DungeonRandInt(100) < gUnknown_80F4E16)
        {
            monInfo->unk178 |= 8;
        }
        if (HasAbility(r5, ABILITY_POISON_POINT)
            && DungeonRandInt(100) < gUnknown_80F4E18)
        {
            monInfo->unk178 |= 0x20;
        }
        if (HasAbility(r5, ABILITY_EFFECT_SPORE)
            && unkBool
            && DungeonRandInt(100) < gUnknown_80F4E1A)
        {
            s32 rnd = DungeonRandInt(3);
            if (rnd < 1)
                monInfo->unk178 |= 0x40;
            else if (rnd < 2)
                monInfo->unk178 |= 0x10;
            else
                monInfo->unk178 |= 0x80;
        }
        if (HasAbility(r5, ABILITY_FLAME_BODY)
            && DungeonRandInt(100) < gUnknown_80F4E1C)
        {
            monInfo->unk178 |= 0x100;
        }
        if (HasAbility(r5, ABILITY_CUTE_CHARM)
            && unkBool
            && DungeonRandInt(100) < gUnknown_80F4E1E)
        {
            monInfo->unk178 |= 0x200;
        }
        if (HasAbility(r5, ABILITY_STENCH)
            && DungeonRandInt(100) < gUnknown_80F4E20)
        {
            monInfo->unk178 |= 0x400;
        }
    }
    if (!EntityExists(r6) || !EntityExists(r5))
        return;

    // Destiny Bond
    if (r9) {
        EntityInfo *monInfo = GetEntInfo(r5);
        if (monInfo->linked.linkedStatus == STATUS_DESTINY_BOND) {
            Entity *destBondTarget = gDungeon->allPokemon[monInfo->linked.unkD8];
            if (destBondTarget == NULL) {
                monInfo->linked.linkedStatus = 0;
            }
            else if (destBondTarget->info->unk98 != monInfo->linked.unkD4) {
                monInfo->linked.linkedStatus = 0;
            }
            else {
                sub_8041D00(destBondTarget, r5);
                DealDamageToEntity(destBondTarget, r8->unk0, 0xC, 0x1F9);
            }
        }
    }
}
