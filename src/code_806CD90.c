#include "global.h"
#include "code_806CD90.h"
#include "code_803E46C.h"
#include "code_805D8C8.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "dungeon_util.h"
#include "code_803E668.h"
#include "exclusive_pokemon.h"
#include "code_8077274_1.h"
#include "code_8069D4C.h"
#include "code_8045A00.h"
#include "position_util.h"
#include "game_options.h"
#include "dungeon_items.h"
#include "status.h"
#include "pokemon_mid.h"
#include "pokemon.h"
#include "random.h"
#include "targeting.h"
#include "sprite.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "dungeon_capabilities.h"
#include "dungeon_random.h"
#include "text_util.h"
#include "dungeon_visibility.h"
#include "code_804267C.h"
#include "move_effects_target.h"
#include "dungeon_pokemon_attributes.h"
#include "code_8041AD0.h"
#include "type_chart.h"

extern u8 gUnknown_202F221;
extern u8 gUnknown_202DFE8[];

extern void sub_806BFC0(EntityInfo *, u32);
extern void sub_805239C(Entity *, const u8 *);

const u8 gUnknown_8106EEF[] = {0x03, 0x04, 0x05, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00 };

void sub_806CC10(void)
{
    EntityInfo *entityInfo;
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity)) {
            entityInfo = entity->axObj.info;

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

    info = entity->axObj.info;
    flag = gDungeon->unk181e8.hallucinating;

    if (entity == gDungeon->unk181e8.cameraTarget)
        flag = FALSE;

    entity->axObj.unk43_animId2 = a1;
    entity->axObj.unk42_animId1 = a1;
    entity->axObj.unk45_orientation = info->action.direction;
    entity->axObj.unk44_direction1 = info->action.direction;
    entity->axObj.unk47 = 0;
    sVar1 = entity->axObj.unk40_maybeAnimTimer;

    if (info->waitingStruct.waitingStatus != STATUS_DECOY && !flag)
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
        entity = gDungeon->allPokemon[i];

        if (EntityExists(entity))
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
            entity->axObj.info->action.direction = newDir & DIRECTION_MASK;
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
    u8 sleep;
    EntityInfo *entityInfo1;
    EntityInfo *entityInfo2;

    // NOTE: copy needed to match
    entityInfo1 = entity->axObj.info;
    entityInfo2 = entity->axObj.info;
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
    entity->axObj.info->action.direction = newDir & DIRECTION_MASK;
    sub_806CE68(entity, newDir & DIRECTION_MASK);
}

void sub_806CF18(Entity *entity)
{
    s32 i;
    EntityInfo *entityInfo;

    if (!EntityExists(entity))
        return;

    entityInfo = entity->axObj.info;
    for (i = 0; i < 100; i++) {
        sub_803E46C(33);

        if (!sub_808DA44(entityInfo->apparentID, entity->axObj.unk43_animId2))
            break;
    }
}

u8 sub_806CF54(Entity *entity)
{
    return entity->axObj.info->unk204;
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
    entityInfo = entity->axObj.info;
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

static bool8 HandleDealingDamageInternal(Entity *attacker, Entity *target, struct DamageStruct *r5, bool32 isFalseSwipe, bool32 giveExp, s16 arg4_, s32 arg8);

extern void sub_807F43C(Entity *, Entity *);
extern void sub_8041B18(Entity *pokemon);
extern void sub_8041B90(Entity *pokemon);
extern void sub_80522F4(Entity *, Entity *, const u8 *);
extern void sub_8041D00(Entity *pokemon, Entity *target);
extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern void SetShopkeeperAggression(Entity *, Entity *);
extern void sub_8042238(Entity *pokemon, Entity *target);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern bool8 sub_806A458(Entity *);
extern bool8 sub_806F660(Entity *, Entity *);
extern bool8 sub_806A58C(s16 a0);
extern void sub_8071D4C(Entity *pokemon, Entity *target, s32 exp);
extern void sub_8042148(Entity *pokemon);
extern void sub_8068FE0(Entity *, u32, Entity *r2);
extern void sub_80694C0(Entity *, s32, s32, u32);
extern void sub_8042A24(Entity *r0);
extern void sub_806A390(Entity *r0);
extern void sub_806F63C(Entity *r0);
extern void sub_8078084(Entity * pokemon);
extern void sub_800DBBC(void);
extern void sub_8045C28(Item *Item, u8 itemID, u32 param_3);
extern void sub_80464C8(Entity *, Position *, Item *);
extern bool8 DoEnemiesEvolveWhenKOed(u8 dungeon);
extern bool8 sub_806FA5C(Entity *, Entity *, struct unkStruct_8069D4C *);
extern void EntityUpdateStatusSprites(Entity *);
extern bool8 sub_8045888(Entity *r0);
extern void sub_8049ED4(void);

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
extern const s16 gUnknown_80F4F8C;
extern const u8 *const gUnknown_80FCFA4;
extern const u8 *const gUnknown_80FCA90;
extern const u8 *const gUnknown_80F9600;
extern const u8 *const gUnknown_80F9614;
extern const u8 *const gUnknown_80F9630;
extern const u8 *const gUnknown_80F9654;
extern const u8 *const gUnknown_80F9670;
extern const u8 *const gUnknown_80F9614;
extern const u8 *const gUnknown_80F9688;
extern const u8 *const gUnknown_80FD484;
extern const u8 *const gUnknown_80F96A8;
extern const u8 *const gUnknown_8100548;
extern const u8 *const gUnknown_80FD46C;
extern const u8 *const gUnknown_810056C;
extern const u8 *const gUnknown_80F9E44;
extern const u8 *const gUnknown_80F9764[];
extern const u8 *const gUnknown_80F9CC0[];
extern const u8 *const gUnknown_80F9CEC[];
extern const u8 *const gUnknown_80F9DAC[];
extern const u8 *const gUnknown_80F9DF0[];
extern const u8 *const gUnknown_80F9D8C[];
extern const u8 *const gUnknown_80F9D84[];
extern const u8 *const gUnknown_80F9D28[];

extern u8 gAvailablePokemonNames[];
extern u32 gFormatData_202DE30;

void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, s32 giveExp, s16 arg4, bool32 arg8, s32 argC)
{
    bool32 r9;
    // Some compiler weirdness, because it won't match without creating arg4 again
    s32 r10 = arg4;
    s32 returnDmg = 0;

    if (HandleDealingDamageInternal(attacker, target, dmgStruct, isFalseSwipe, giveExp, r10, argC))
        return;
    if (dmgStruct->unkF)
        return;
    if (!EntityExists(attacker) || !EntityExists(target))
        return;
    if (GetEntityType(attacker) != ENTITY_MONSTER || GetEntityType(target) != ENTITY_MONSTER)
        return;

    r9 = arg8;
    if (CheckVariousStatuses(target) || target->axObj.info->charging.chargingStatus != 0)
        r9 = FALSE;
    if (r9
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1
        && attacker != target
        && IsTypePhysical(dmgStruct->type)
        && target->axObj.info->protection.protectionStatus == STATUS_VITAL_THROW)
    {
        sub_8042730(target, attacker);
        sub_807F43C(target, attacker);
    }

    if (target->axObj.info->charging.chargingStatus == STATUS_ENRAGED) {
        RaiseAttackStageTarget(attacker, target, gUnknown_8106A4C, 1);
    }

    if (!EntityExists(attacker) || !EntityExists(target))
        return;

    if (r9
        && attacker != target
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1)
    {
        bool32 isPhysical = IsTypePhysical(dmgStruct->type);
        if (target->axObj.info->protection.protectionStatus == STATUS_COUNTER && isPhysical) {
            sub_8041B18(target);
            returnDmg += 4;
        }
        if (target->axObj.info->protection.protectionStatus == STATUS_MINI_COUNTER && isPhysical) {
            sub_8041B18(target);
            returnDmg += 1;
        }
        if (target->axObj.info->protection.protectionStatus == STATUS_MIRROR_COAT && !isPhysical) {
            sub_8041B90(target);
            returnDmg += 4;
        }

        if (HasAbility(target, ABILITY_ROUGH_SKIN))
            returnDmg += 2;

        if (returnDmg) {
            struct DamageStruct sp;

            sub_80522F4(attacker, target, gUnknown_80FCFA4);
            sp.dmg = (dmgStruct->dmg * returnDmg) / 4;
            sp.type = dmgStruct->type;
            sp.residualDmgType = 6;
            sp.typeEffectiveness = 2;
            sp.isCrit = FALSE;
            sp.unkE = 0;
            sp.unkF = 0;
            HandleDealingDamageInternal(target, attacker, &sp, FALSE, giveExp, r10, argC);
        }
    }
    if (!EntityExists(attacker) || !EntityExists(target))
        return;

    // Check trapping / contact abilities
    if (r9
        && attacker != target
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1)
    {
        bool32 isPhysical = IsTypePhysical(dmgStruct->type);
        EntityInfo *attackerInfo = attacker->axObj.info;

        if (HasAbility(target, ABILITY_ARENA_TRAP)
            && !MonsterIsType(attacker, TYPE_FLYING)
            && !HasAbility(attacker, ABILITY_LEVITATE)
            && DungeonRandInt(100) < gUnknown_80F4E10)
        {
            attackerInfo->unk178 |= 1;
        }
        if (HasAbility(target, ABILITY_SHADOW_TAG)
            && DungeonRandInt(100) < gUnknown_80F4E12)
        {
            attackerInfo->unk178 |= 2;
        }
        if (HasAbility(target, ABILITY_MAGNET_PULL)
            && MonsterIsType(attacker, TYPE_STEEL)
            && DungeonRandInt(100) < gUnknown_80F4E14)
        {
            attackerInfo->unk178 |= 4;
        }

        if (HasAbility(target, ABILITY_STATIC)
            && isPhysical
            && DungeonRandInt(100) < gUnknown_80F4E16)
        {
            attackerInfo->unk178 |= 8;
        }
        if (HasAbility(target, ABILITY_POISON_POINT)
            && DungeonRandInt(100) < gUnknown_80F4E18)
        {
            attackerInfo->unk178 |= 0x20;
        }
        if (HasAbility(target, ABILITY_EFFECT_SPORE)
            && isPhysical
            && DungeonRandInt(100) < gUnknown_80F4E1A)
        {
            s32 rnd = DungeonRandInt(3);
            if (rnd < 1)
                attackerInfo->unk178 |= 0x40;
            else if (rnd < 2)
                attackerInfo->unk178 |= 0x10;
            else
                attackerInfo->unk178 |= 0x80;
        }
        if (HasAbility(target, ABILITY_FLAME_BODY)
            && DungeonRandInt(100) < gUnknown_80F4E1C)
        {
            attackerInfo->unk178 |= 0x100;
        }
        if (HasAbility(target, ABILITY_CUTE_CHARM)
            && isPhysical
            && DungeonRandInt(100) < gUnknown_80F4E1E)
        {
            attackerInfo->unk178 |= 0x200;
        }
        if (HasAbility(target, ABILITY_STENCH)
            && DungeonRandInt(100) < gUnknown_80F4E20)
        {
            attackerInfo->unk178 |= 0x400;
        }
    }
    if (!EntityExists(attacker) || !EntityExists(target))
        return;

    // Destiny Bond
    if (r9) {
        EntityInfo *targetInfo = GetEntInfo(target);
        if (targetInfo->linked.linkedStatus == STATUS_DESTINY_BOND) {
            Entity *destBondTarget = gDungeon->allPokemon[targetInfo->linked.unkD8];
            if (destBondTarget == NULL) {
                targetInfo->linked.linkedStatus = 0;
            }
            else if (destBondTarget->axObj.info->unk98 != targetInfo->linked.unkD4) {
                targetInfo->linked.linkedStatus = 0;
            }
            else {
                sub_8041D00(destBondTarget, target);
                DealDamageToEntity(destBondTarget, dmgStruct->dmg, 0xC, 0x1F9);
            }
        }
    }
}

static inline void ZeroOutItem(Item *item)
{
    item->id = 0;
    item->quantity = 0;
    item->flags = 0;
}

static inline bool8 ItemSticky(Item *item)
{
    return (item->flags & ITEM_FLAG_STICKY);
}

static inline bool8 ItemExists(Item *item)
{
    return (item->flags & ITEM_FLAG_EXISTS);
}

static inline bool8 ItemInShop(Item *item)
{
    return (item->flags & ITEM_FLAG_IN_SHOP);
}

static inline u8 ItemId(Item *item)
{
    return item->id;
}

static bool8 HandleDealingDamageInternal(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4_, s32 arg8)
{
    s32 hpBefore, hpChange;
    EntityInfo *targetData;
    s32 arg4 = arg4_;
    bool32 var_24 = FALSE;
    bool32 r10 = FALSE;
    s32 r8  = 0;
    Tile *unkTile = NULL;

    dmgStruct->unkF = 0;
    if (GetEntityType(target) != ENTITY_MONSTER) {
        dmgStruct->unkF = 1;
        return FALSE;
    }

    targetData = GetEntInfo(target);
    TrySendImmobilizeSleepEndMsg(attacker, target);
    SetShopkeeperAggression(attacker, target);
    if (GetEntityType(attacker) == ENTITY_MONSTER
        && attacker->axObj.info->moveStatus.moveStatus == STATUS_SET_DAMAGE
        && dmgStruct->unkE == 0)
    {
        dmgStruct->dmg = gUnknown_80F4F8C;
    }

    if (arg4 != 0x20E && HasAbility(target, ABILITY_STURDY) && dmgStruct->dmg == 9999) {
        SetMessageArgument(gUnknown_202DFE8, target, 0);
        sub_80522F4(attacker, target, gUnknown_80FCA90);
        sub_8042238(attacker, target);
        dmgStruct->unkF = 1;
        return FALSE;
    }
    if (targetData->immobilize.immobilizeStatus == STATUS_FROZEN) {
        SetMessageArgument(gUnknown_202DFE8, target, 0);
        sub_80522F4(attacker, target, gUnknown_80F9600);
        sub_8042238(attacker, target);
        dmgStruct->unkF = 1;
        return FALSE;
    }

    if ((targetData->sleep.sleep == STATUS_SLEEP || targetData->sleep.sleep == STATUS_NAPPING || targetData->sleep.sleep == STATUS_NIGHTMARE)
        && targetData->sleep.sleepTurns == 0x7F)
    {
        WakeUpPokemon(target);
    }

    if ((HasAbility(target, ABILITY_VOLT_ABSORB) && dmgStruct->type == TYPE_ELECTRIC)) {
        HealTargetHP(attacker, target, dmgStruct->dmg, 0, 0);
        dmgStruct->unkF = 1;
        return FALSE;
    }
    else if (HasAbility(target, ABILITY_WATER_ABSORB) && dmgStruct->type == TYPE_WATER) {
        HealTargetHP(attacker, target, dmgStruct->dmg, 0, 0);
        dmgStruct->unkF = 1;
        return FALSE;
    }

    if (targetData->unk152 == 0) {
        if (dmgStruct->isCrit) {
            sub_80522F4(attacker, target, gUnknown_80F9614);
        }
        switch (dmgStruct->typeEffectiveness) {
            case EFFECTIVENESS_IMMUNE:
                sub_80522F4(attacker, target, gUnknown_80F9630);
                break;
            case EFFECTIVENESS_RESIST:
                sub_80522F4(attacker, target, gUnknown_80F9654);
                break;
            case EFFECTIVENESS_SUPER:
                sub_80522F4(attacker, target, gUnknown_80F9670);
                break;
        }
    }

    SetMessageArgument(gAvailablePokemonNames, attacker, 0);
    SetMessageArgument(gAvailablePokemonNames + 0x50, target, 0);
    if (dmgStruct->dmg == 0) {
        if (sub_8045888(attacker) && sub_8045888(target)) {
            if (targetData->unk152 == 0) {
                sub_80522F4(attacker, target, gUnknown_80F9688);
            }
            sub_8042238(attacker, target);
        }
        else {
            if (targetData->unk152 == 0) {
                sub_80522F4(attacker, target, gUnknown_80F9688);
            }
            sub_803E708(0x1E, 0x18);
        }
        dmgStruct->unkF = 1;
        return FALSE;
    }
    else if (dmgStruct->dmg == 9999) {
        if (arg8 != 0 && sub_8045888(target)) {
            unkTile = GetTileAtEntitySafe(target);
            sub_803E708(0x14, 0x18);
            unkTile->unk4 |= 4;
            sub_8049ED4();
        }
        if (targetData->unk152 == 0) {
            sub_80522F4(attacker, target, gUnknown_80F96A8);
        }
        targetData->unkA0 = 999;
    }
    else {
        const u8 *str;

        gFormatData_202DE30 = dmgStruct->dmg;
        str = gUnknown_80F9764[dmgStruct->residualDmgType];

        // Needed to match - the line can be safely removed
        dmgStruct++;dmgStruct--;

        targetData->unkA0 += dmgStruct->dmg;
        if (targetData->unkA0 > 999)
            targetData->unkA0 = 999;

        if (sub_8045888(target)) {
            if (dmgStruct->residualDmgType != 14) {
                sub_803ED30(-dmgStruct->dmg, target, 1, -1);
            }
            if (targetData->unk152 == 0 && str != NULL) {
                sub_80522F4(attacker, target, str);
            }
        }
        else {
            if (targetData->unk152 == 0 && str != NULL) {
                sub_80522F4(attacker, target, str);
            }
        }
    }

    if ((dmgStruct->residualDmgType != 14 || targetData->HP <= 1) && unkTile == NULL && sub_8045888(target)) {
        if ((attacker->pos.x != target->pos.x || attacker->pos.y != target->pos.y) && GetEntityType(attacker) == ENTITY_MONSTER) {
            bool32 unkBool = FALSE;
            if (targetData->isTeamLeader) {
                if (gGameOptionsRef->damageTurn != 0 && !sub_806A458(target)) {
                    if (CanSeeTarget(target, attacker))
                        unkBool = TRUE;
                    else
                        unkBool = FALSE;
                }
            }
            else {
                unkBool = FALSE;
            }
            if (targetData->eyesightStatus.eyesightStatus == STATUS_BLINKER || targetData->eyesightStatus.eyesightStatus == STATUS_CROSS_EYED)
                unkBool = FALSE;
            if (unkBool) {
                EntityInfo *info = GetEntInfo(target);
                info->action.direction = (GetDirectionTowardsPosition(&target->pos, &attacker->pos) & DIRECTION_MASK);
            }
            TargetTileInFront(target);
        }
        sub_806CDD4(target, 6, target->axObj.info->action.direction);
        sub_80420E8(target, dmgStruct);
        var_24 = TRUE;
    }

    // HP goes down
    hpBefore = targetData->HP;
    if (targetData->HP > dmgStruct->dmg)
        targetData->HP -= dmgStruct->dmg;
    else
        targetData->HP = 0;

    if (targetData->protection.protectionStatus == STATUS_ENDURING) {
        if (targetData->HP == 0) {
            targetData->HP = 1;
            sub_80522F4(attacker, target, gUnknown_8100548);
        }
    }
    else if (isFalseSwipe == TRUE && targetData->HP == 0) {
        targetData->HP = 1;
        sub_80522F4(attacker, target, gUnknown_810056C);
    }

    hpChange = hpBefore - targetData->HP;
    if (hpChange < 0)
        hpChange = 0;

    if (var_24 || unkTile != NULL)
        sub_803E708(0xA, 0x18);

    if (targetData->HP != 0) {
        if (var_24) {
            sub_806CE68(target, 8);
        }
        if (HasHeldItem(target, ITEM_JOY_RIBBON) && hpChange > 0 && dmgStruct->dmg != 9999) {
            sub_8071D4C(attacker, target, hpChange);
        }

        if (unkTile != NULL)
        {
            unkTile->unk4 &= ~(0x4);
            sub_8049ED4();
        }
        return FALSE;
    }

    // 0 HP
    if (targetData->transformStatus.transformStatus == STATUS_TRANSFORMED) {
        SendTransformEndMessage(attacker, target);
    }

    if (unkTile != NULL) {
        sub_803E708(0x14, 0x18);
        target->unk22 = 2;
        sub_803E708(0xA, 0x18);
        unkTile->unk4 &= ~(0x4);
        sub_8049ED4();
    }
    else if (var_24) {
        target->unk22 = 1;
        sub_803E708(0x1E, 0x18);
    }

    r8 = 1;
    if (EntityExists(attacker) && GetEntityType(attacker) == ENTITY_MONSTER && attacker != target)
        r8 = 0;

    targetData->unk14C = 0;
    SetMessageArgument(gAvailablePokemonNames, attacker, 0);
    SetMessageArgument(gAvailablePokemonNames + 0x50, target, 0);
    if (dmgStruct->residualDmgType == 19 || dmgStruct->residualDmgType == 20) {
        if (targetData->isNotTeamMember) {
            sub_80522F4(attacker, target, gUnknown_80F9E44);
        }
        else {
            sub_805239C(attacker, gUnknown_80F9E44);
        }
    }
    else if (targetData->isNotTeamMember)
    {
        if (targetData->clientType == CLIENT_TYPE_CLIENT) {
            sub_805239C(attacker, gUnknown_80F9DF0[r8]);
        }
        else {
            sub_80522F4(attacker, target, gUnknown_80F9CC0[r8]);
        }
    }
    else {
        PokemonStruct2 *recruitedMon = &gRecruitedPokemonRef->pokemon2[targetData->teamIndex];
        if (targetData->isTeamLeader || (targetData->joinedAt.joinedAt == DUNGEON_JOIN_LOCATION_PARTNER && gDungeon->unk65C == 0)) {
            sub_805239C(attacker, gUnknown_80F9CEC[r8]);
        }
        else if (IsClientOrTeamBase(targetData->joinedAt.joinedAt)) {
            sub_805239C(attacker, gUnknown_80F9DAC[r8]);
        }
        else if (targetData->clientType == CLIENT_TYPE_CLIENT) {
            sub_805239C(attacker, gUnknown_80F9DF0[r8]);
        }
        else if (sub_806A58C(recruitedMon->unkA)) {
            if (gDungeon->unk65D != 0) {
                sub_805239C(attacker, gUnknown_80F9D8C[r8]);
            }
            else {
                sub_805239C(attacker, gUnknown_80F9D84[r8]);
            }
        }
        else {
            sub_805239C(attacker, gUnknown_80F9D28[r8]);
        }
    }

    if (targetData->immobilize.immobilizeStatus == STATUS_WRAP || targetData->immobilize.immobilizeStatus == STATUS_WRAPPED) {
        sub_8076CB4(targetData->unk9C);
    }

    // Try revive items
    if (targetData->heldItem.flags & ITEM_FLAG_EXISTS) {
        // This do/while 0 loop has no effect other than matching asm, and can be removed.
        do
        {
            if (!(ItemSticky(&targetData->heldItem)) && !(ItemInShop(&targetData->heldItem)) && ItemId(&targetData->heldItem) == ITEM_REVIVER_ORB) {
                sub_8042148(target);
                target->unk22 = 0;
                targetData->HP = targetData->maxHPStat;
                targetData->unk158 = 0;
                targetData->unk14C = 1;
                targetData->belly = targetData->maxBelly;
                if (targetData->isTeamLeader) {
                    gDungeon->unk679 = 0;
                    gDungeon->itemHoldersIdentified = 0;
                }
                ZeroOutItem(&targetData->heldItem);
                if (targetData->waitingStruct.waitingStatus == STATUS_SNATCH) {
                    SendWaitingEndMessage(attacker, target, STATUS_SNATCH);
                }
                else if (targetData->waitingStruct.waitingStatus == STATUS_DECOY) {
                    SendWaitingEndMessage(attacker, target, STATUS_DECOY);
                }
                sub_8078084(target);
                sub_806BFC0(targetData, 0);
                sub_800DBBC();
                sub_806A390(target);
                sub_806CCB4(target, sub_806CEBC(target));
                EntityUpdateStatusSprites(target);
                SetMessageArgument(gUnknown_202DFE8, target, 0);
                sub_805239C(attacker, gUnknown_80FD46C);
                sub_806F63C(target);
                return FALSE;
            }
        } while(0);
    }

    if (targetData->isTeamLeader)
    {
        Item *heldItem = &targetData->heldItem;
        if (ItemExists(heldItem) && !(ItemSticky(heldItem)) && ItemId(heldItem) == ITEM_POSSESS_ORB ) {
            s32 i;
            Entity *teamMember;

            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                teamMember = gDungeon->teamPokemon[i];
                if (EntityExists(teamMember)
                    && teamMember != target
                    && CanSeeTarget(target, teamMember)
                    && abs(teamMember->pos.x - target->pos.x) <= 1 && abs(teamMember->pos.y - target->pos.y) <= 1)
                {
                    break;
                }
            }
            if (i != MAX_TEAM_MEMBERS) {
                Position monPos; // r4

                sub_8042148(target);

                monPos = teamMember->pos;
                sub_8068FE0(teamMember, 0x221, target);
                sub_80694C0(target, monPos.x, monPos.y, 1);
                sub_804535C(target, NULL);
                target->unk22 = 0;
                targetData->HP = targetData->maxHPStat;
                sub_8042A24(target);
                targetData->unk158 = 0;
                targetData->unk14C = 1;
                targetData->belly = targetData->maxBelly;
                if (targetData->isTeamLeader) {
                    gDungeon->unk679 = 0;
                    gDungeon->itemHoldersIdentified = 0;
                }
                ZeroOutItem(heldItem);
                if (targetData->waitingStruct.waitingStatus == STATUS_SNATCH) {
                    SendWaitingEndMessage(attacker, target, STATUS_SNATCH);
                }
                else if (targetData->waitingStruct.waitingStatus == STATUS_DECOY) {
                    SendWaitingEndMessage(attacker, target, STATUS_DECOY);
                }
                sub_8078084(target);
                sub_806BFC0(targetData, 0);
                sub_800DBBC();
                sub_806A390(target);
                sub_806CCB4(target, sub_806CEBC(target));
                EntityUpdateStatusSprites(target);
                SetMessageArgument(gAvailablePokemonNames, target, 0);
                SetMessageArgument(gAvailablePokemonNames + 0x50, teamMember, 0);
                sub_805239C(attacker, gUnknown_80FD484);
                sub_806F63C(target);
                return FALSE;
            }

        }

    }

    if (IQSkillIsEnabled(target, IQ_ITEM_MASTER)) {
        s32 i; // r3
        Item *reviverSeed = NULL; // r4
        if (ItemExists(&targetData->heldItem) && !ItemSticky(&targetData->heldItem) && ItemId(&targetData->heldItem) == ITEM_REVIVER_SEED)
            reviverSeed = &targetData->heldItem;
        if (reviverSeed == NULL && !targetData->isNotTeamMember) {
            for (i = 0; i < INVENTORY_SIZE; i++) {
                Item *bagItem = &gTeamInventoryRef->teamItems[i];
                if (!(bagItem->flags & ITEM_FLAG_EXISTS))
                    continue;
                if (bagItem->flags & ITEM_FLAG_STICKY)
                    continue;
                if (bagItem->id == ITEM_REVIVER_SEED) {
                    reviverSeed = bagItem;
                    break;
                }
            }
        }

        if (reviverSeed != NULL) {
            sub_8042148(target);
            sub_8045C28(reviverSeed, ITEM_PLAIN_SEED, 2);
            target->unk22 = 0;
            targetData->HP = targetData->maxHPStat;
            targetData->unk158 = 0;
            targetData->unk14C = 1;
            targetData->belly = targetData->maxBelly;
            if (targetData->isTeamLeader) {
                gDungeon->unk679 = 0;
                gDungeon->itemHoldersIdentified = 0;
            }
            if (targetData->waitingStruct.waitingStatus == STATUS_SNATCH) {
                SendWaitingEndMessage(attacker, target, STATUS_SNATCH);
            }
            else if (targetData->waitingStruct.waitingStatus == STATUS_DECOY) {
                SendWaitingEndMessage(attacker, target, STATUS_DECOY);
            }
            sub_8078084(target);
            sub_806BFC0(targetData, 0);
            sub_800DBBC();
            sub_806A390(target);
            sub_806CCB4(target, sub_806CEBC(target));
            EntityUpdateStatusSprites(target);
            SetMessageArgument(gUnknown_202DFE8, target, 0);
            sub_805239C(attacker, gUnknown_80FD46C);
            sub_806F63C(target);
            return FALSE;
        }
    }

    if (!targetData->isTeamLeader && ItemExists(&targetData->heldItem)) {
        sub_80464C8(target, &target->pos, &targetData->heldItem);
        ZeroOutItem(&targetData->heldItem);
    }
    if (targetData->bossFlag) {
        gDungeon->bossSongIndex = 999;
    }

    // Give exp
    r10 = FALSE;
    if (GetEntityType(attacker) == ENTITY_MONSTER) {
        EntityInfo *attackerData = GetEntInfo(attacker);
        s32 exp  = CalculateEXPGain(targetData->id, targetData->level);
        switch (targetData->unkFB) {
            case 2:
                exp *= 3;
                exp /= 2;
                break;
            case 0:
                exp /= 2;
                break;
        }
        if (exp == 0)
            exp = 1;
        if (attackerData->isTeamLeader) {
            sub_80980B4(targetData->id);
        }
        if (targetData->grudge) {
            attackerData->unk14B = 1;
        }

        if (giveExp == TRUE) {
            if (!attackerData->isNotTeamMember) {
                if (targetData->isNotTeamMember) {
                    s32 i;

                    sub_8071D4C(attacker, attacker, exp);
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        Entity *teamMember = gDungeon->teamPokemon[i];
                        if (EntityExists(teamMember) && teamMember != attacker) {
                            sub_8071D4C(attacker, teamMember, exp);
                        }
                    }
                    r10 = TRUE;
                }
            }
            else {
                if (DoEnemiesEvolveWhenKOed(gDungeon->dungeonLocation.id)) {
                    attackerData->unk149 = 1;
                    gDungeon->unkD = 1;
                }
            }
        }
    }

    if (EntityExists(attacker) && GetEntityType(attacker) == ENTITY_MONSTER && !attacker->axObj.info->isTeamLeader)
        r10 = FALSE;

    if (r10) {
        struct unkStruct_8069D4C sp;

        sub_8069D4C(&sp, target);
        if (sub_806F660(attacker, target)) {
            if (!sub_806FA5C(attacker, target, &sp)) {
                sub_8068FE0(target, 0x1F5, attacker);
            }
            else {
                gUnknown_202F221 = 1;
            }
        }
        else {
            sub_8068FE0(target, arg4, attacker);
        }
    }
    else {
        sub_8068FE0(target, arg4, attacker);
    }

    return TRUE;
}
