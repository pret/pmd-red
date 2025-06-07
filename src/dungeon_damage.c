#include "global.h"
#include "constants/ability.h"
#include "structs/str_dungeon.h"
#include "dungeon_logic.h"
#include "text_util.h"
#include "dungeon_message.h"
#include "string_format.h"
#include "type_effectiveness.h"
#include "constants/move_id.h"
#include "constants/monster.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/iq_skill.h"
#include "math.h"
#include "number_util.h"
#include "status.h"
#include "dungeon_random.h"
#include "dungeon_items.h"
#include "structs/str_damage.h"
#include "dungeon_util.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_misc.h"
#include "weather.h"
#include "game_options.h"
#include "code_8077274_1.h"
#include "code_806CD90.h"
#include "constants/direction.h"
#include "constants/dungeon.h"
#include "dungeon_vram.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_805D8C8.h"
#include "dungeon_map_access.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "position_util.h"
#include "random.h"
#include "sprite.h"
#include "exclusive_pokemon.h"

extern void sub_807F43C(Entity *, Entity *);
extern void sub_8041B18(Entity *pokemon);
extern void sub_8041B90(Entity *pokemon);
extern void sub_8041D00(Entity *pokemon, Entity *target);
extern void SetShopkeeperAggression(Entity *, Entity *);
extern void sub_8042238(Entity *pokemon, Entity *target);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern bool8 sub_806A458(Entity *);
extern bool8 sub_806F660(Entity *, Entity *);
extern bool8 sub_806A58C(s16 a0);
extern void sub_8071D4C(Entity *pokemon, Entity *target, s32 exp);
extern void sub_8042148(Entity *pokemon);
extern void sub_8042A24(Entity *r0);
extern void sub_806A390(Entity *r0);
extern void sub_8078084(Entity * pokemon);
extern void sub_800DBBC(void);
extern void sub_80464C8(Entity *, DungeonPos *, Item *);
extern bool8 DoEnemiesEvolveWhenKOed(u8 dungeon);
extern bool8 sub_806FA5C(Entity *, Entity *, struct unkStruct_8069D4C *);
extern void EntityUpdateStatusSprites(Entity *);
extern bool8 sub_8045888(Entity *r0);
extern void sub_806F500(void);
extern void sub_803F508(Entity *);
extern bool8 sub_806E100(s48_16 *param_1, Entity *pokemon, Entity *target, u8 type, struct DamageStruct *dmgStruct);
extern void sub_8041B74(Entity *pokemon);
extern void sub_8041B5C(Entity *pokemon);
extern void sub_8042940(Entity *r0);
extern void sub_80428B0(Entity *r0);
extern void sub_80428C4(Entity *r0);
extern void sub_80428D8(Entity *);
extern void sub_8042978(Entity *);
extern void sub_804298C(Entity *);
extern void sub_80428EC(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);

extern u8 gUnknown_202F221;

extern const s32 gUnknown_8106A4C;
extern const u8 *const gUnknown_8100548;
extern const u8 *const gUnknown_80FD46C;
extern const u8 *const gUnknown_810056C;
extern const s16 gUnknown_810AC60;
extern const s16 gUnknown_810AC68;
extern const s16 gUnknown_810AC64;
extern const s16 gUnknown_810AC66;
extern const s16 gUnknown_810AC68;
extern const s16 gUnknown_810AC62;

static bool8 HandleDealingDamageInternal(Entity *attacker, Entity *target, struct DamageStruct *r5, bool32 isFalseSwipe, bool32 giveExp, s16 arg4_, s32 arg8);
void DealDamageToEntity(Entity *entity, s32 dmg, s32 r6, s32 r4);
void sub_806F63C(Entity *param_1);

static const u32 gUnknown_8106EFC[] = { 0, 0  };
static const s48_16 gUnknown_8106F04 = { 0x0, 0x10000 };
static const s48_16 gUnknown_8106F0C = { 0x0, 0x20000 };
static const s48_16 gUnknown_8106F14 = { 0x0, 0x18000 };
static const s48_16 gUnknown_8106F1C = { 0x0, 0x8000 };
static const s48_16 gUnknown_8106F24 = { 0x0, 0x3E70000 };
UNUSED static const s48_16 sUnusedModifier1 = { 0, 0xC000 };
UNUSED static const s48_16 sUnusedModifier2 = { 0x0, 0x17FFE };
static const s48_16 gUnknown_8106F3C = {0x0, 0x8000};
static const s48_16 gUnknown_8106F44 = {0x0, 0xE666};
static const s48_16 gUnknown_8106F4C = {0x0, 0x18000};

void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC)
{
    bool32 r9;
    // Some compiler weirdness, because it won't match without creating arg4 again
    s32 r10 = arg4;
    s32 returnDmg = 0;

    if (HandleDealingDamageInternal(attacker, target, dmgStruct, isFalseSwipe, giveExp, r10, argC))
        return;
    if (dmgStruct->tookNoDamage)
        return;
    if (!EntityIsValid(attacker) || !EntityIsValid(target))
        return;
    if (GetEntityType(attacker) != ENTITY_MONSTER || GetEntityType(target) != ENTITY_MONSTER)
        return;

    r9 = arg8;
    if (CheckVariousStatuses(target) || GetEntInfo(target)->bideClassStatus.status != 0)
        r9 = FALSE;
    if (r9
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1
        && attacker != target
        && IsTypePhysical(dmgStruct->type)
        && GetEntInfo(target)->reflectClassStatus.status == STATUS_VITAL_THROW)
    {
        sub_8042730(target, attacker);
        sub_807F43C(target, attacker);
    }

    if (GetEntInfo(target)->bideClassStatus.status == STATUS_ENRAGED) {
        RaiseAttackStageTarget(attacker, target, gUnknown_8106A4C, 1);
    }

    if (!EntityIsValid(attacker) || !EntityIsValid(target))
        return;

    if (r9
        && attacker != target
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1)
    {
        bool32 isPhysical = IsTypePhysical(dmgStruct->type);
        if (GetEntInfo(target)->reflectClassStatus.status == STATUS_COUNTER && isPhysical) {
            sub_8041B18(target);
            returnDmg += 4;
        }
        if (GetEntInfo(target)->reflectClassStatus.status == STATUS_MINI_COUNTER && isPhysical) {
            sub_8041B18(target);
            returnDmg += 1;
        }
        if (GetEntInfo(target)->reflectClassStatus.status == STATUS_MIRROR_COAT && !isPhysical) {
            sub_8041B90(target);
            returnDmg += 4;
        }

        if (AbilityIsActive(target, ABILITY_ROUGH_SKIN))
            returnDmg += 2;

        if (returnDmg) {
            struct DamageStruct sp;

            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FCFA4);
            sp.dmg = (dmgStruct->dmg * returnDmg) / 4;
            sp.type = dmgStruct->type;
            sp.residualDmgType = 6;
            sp.typeEffectiveness = 2;
            sp.isCrit = FALSE;
            sp.unkE = 0;
            sp.tookNoDamage = FALSE;
            HandleDealingDamageInternal(target, attacker, &sp, FALSE, giveExp, r10, argC);
        }
    }
    if (!EntityIsValid(attacker) || !EntityIsValid(target))
        return;

    // Check trapping / contact abilities
    if (r9
        && attacker != target
        && abs(attacker->pos.x - target->pos.x) <= 1 && abs(attacker->pos.y - target->pos.y) <= 1)
    {
        bool32 isPhysical = IsTypePhysical(dmgStruct->type);
        EntityInfo *attackerInfo = GetEntInfo(attacker);

        if (AbilityIsActive(target, ABILITY_ARENA_TRAP)
            && !MonsterIsType(attacker, TYPE_FLYING)
            && !AbilityIsActive(attacker, ABILITY_LEVITATE)
            && DungeonRandInt(100) < gArenaTrapActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_ARENA_TRAP;
        }
        if (AbilityIsActive(target, ABILITY_SHADOW_TAG)
            && DungeonRandInt(100) < gShadowTagActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_SHADOW_TAG;
        }
        if (AbilityIsActive(target, ABILITY_MAGNET_PULL)
            && MonsterIsType(attacker, TYPE_STEEL)
            && DungeonRandInt(100) < gMagnetPullActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_MAGNET_PULL;
        }

        if (AbilityIsActive(target, ABILITY_STATIC)
            && isPhysical
            && DungeonRandInt(100) < gStaticActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_STATIC;
        }
        if (AbilityIsActive(target, ABILITY_POISON_POINT)
            && DungeonRandInt(100) < gPoisonPointActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_POISON_POINT;
        }
        if (AbilityIsActive(target, ABILITY_EFFECT_SPORE)
            && isPhysical
            && DungeonRandInt(100) < gEffectSproreActivateChance)
        {
            s32 rnd = DungeonRandInt(3);
            if (rnd < 1)
                attackerInfo->abilityEffectFlags |= ABILITY_FLAG_EFFECT_SPORE_PSN;
            else if (rnd < 2)
                attackerInfo->abilityEffectFlags |= ABILITY_FLAG_EFFECT_SPORE_PRLZ;
            else
                attackerInfo->abilityEffectFlags |= ABILITY_FLAG_EFFECT_SPORE_SLP;
        }
        if (AbilityIsActive(target, ABILITY_FLAME_BODY)
            && DungeonRandInt(100) < gFlameBodyActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_FLAME_BODY;
        }
        if (AbilityIsActive(target, ABILITY_CUTE_CHARM)
            && isPhysical
            && DungeonRandInt(100) < gCuteCharmActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_CUTE_CHARM;
        }
        if (AbilityIsActive(target, ABILITY_STENCH)
            && DungeonRandInt(100) < gStenchActivateChance)
        {
            attackerInfo->abilityEffectFlags |= ABILITY_FLAG_STENCH;
        }
    }
    if (!EntityIsValid(attacker) || !EntityIsValid(target))
        return;

    // Destiny Bond
    if (r9) {
        EntityInfo *targetInfo = GetEntInfo(target);
        if (targetInfo->leechSeedClassStatus.status == STATUS_DESTINY_BOND) {
            Entity *destBondTarget = gDungeon->activePokemon[targetInfo->leechSeedClassStatus.unk8];
            if (destBondTarget == NULL) {
                targetInfo->leechSeedClassStatus.status = 0;
            }
            else if (GetEntInfo(destBondTarget)->dungeonSpriteId != targetInfo->leechSeedClassStatus.unk4) {
                targetInfo->leechSeedClassStatus.status = 0;
            }
            else {
                sub_8041D00(destBondTarget, target);
                DealDamageToEntity(destBondTarget, dmgStruct->dmg, 0xC, 0x1F9);
            }
        }
    }
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

    dmgStruct->tookNoDamage = FALSE;
    if (GetEntityType(target) != ENTITY_MONSTER) {
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }

    targetData = GetEntInfo(target);
    TrySendImmobilizeSleepEndMsg(attacker, target);
    SetShopkeeperAggression(attacker, target);
    if (GetEntityType(attacker) == ENTITY_MONSTER
        && GetEntInfo(attacker)->sureShotClassStatus.status == STATUS_SET_DAMAGE
        && dmgStruct->unkE == 0)
    {
        dmgStruct->dmg = gSetDamageDmgValue;
    }

    if (arg4 != 0x20E && AbilityIsActive(target, ABILITY_STURDY) && dmgStruct->dmg == 9999) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
        TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FCA90);
        sub_8042238(attacker, target);
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }
    if (targetData->frozenClassStatus.status == STATUS_FROZEN) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
        TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9600);
        sub_8042238(attacker, target);
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }

    if ((targetData->sleepClassStatus.status == STATUS_SLEEP || targetData->sleepClassStatus.status == STATUS_NAPPING || targetData->sleepClassStatus.status == STATUS_NIGHTMARE)
        && targetData->sleepClassStatus.turns == 0x7F)
    {
        WakeUpPokemon(target);
    }

    if ((AbilityIsActive(target, ABILITY_VOLT_ABSORB) && dmgStruct->type == TYPE_ELECTRIC)) {
        HealTargetHP(attacker, target, dmgStruct->dmg, 0, 0);
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }
    else if (AbilityIsActive(target, ABILITY_WATER_ABSORB) && dmgStruct->type == TYPE_WATER) {
        HealTargetHP(attacker, target, dmgStruct->dmg, 0, 0);
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }

    if (targetData->unk152 == 0) {
        if (dmgStruct->isCrit) {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9614);
        }
        switch (dmgStruct->typeEffectiveness) {
            case EFFECTIVENESS_IMMUNE:
                TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9630);
                break;
            case EFFECTIVENESS_RESIST:
                TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9654);
                break;
            case EFFECTIVENESS_SUPER:
                TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9670);
                break;
        }
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
    if (dmgStruct->dmg == 0) {
        if (sub_8045888(attacker) && sub_8045888(target)) {
            if (targetData->unk152 == 0) {
                TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9688);
            }
            sub_8042238(attacker, target);
        }
        else {
            if (targetData->unk152 == 0) {
                TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9688);
            }
            sub_803E708(0x1E, 0x18);
        }
        dmgStruct->tookNoDamage = TRUE;
        return FALSE;
    }
    else if (dmgStruct->dmg == 9999) {
        if (arg8 != 0 && sub_8045888(target)) {
            unkTile = GetTileAtEntitySafe(target);
            sub_803E708(0x14, 0x18);
            unkTile->spawnOrVisibilityFlags |= 4;
            sub_8049ED4();
        }
        if (targetData->unk152 == 0) {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F96A8);
        }
        targetData->unkA0 = 999;
    }
    else {
        const u8 *str;

        gFormatArgs[0] = dmgStruct->dmg;
        str = gUnknown_80F9764[dmgStruct->residualDmgType];

        ASM_MATCH_TRICK(dmgStruct);

        targetData->unkA0 += dmgStruct->dmg;
        if (targetData->unkA0 > 999)
            targetData->unkA0 = 999;

        if (sub_8045888(target)) {
            if (dmgStruct->residualDmgType != 14) {
                sub_803ED30(-dmgStruct->dmg, target, 1, -1);
            }
            if (targetData->unk152 == 0 && str != NULL) {
                TryDisplayDungeonLoggableMessage3(attacker, target, str);
            }
        }
        else {
            if (targetData->unk152 == 0 && str != NULL) {
                TryDisplayDungeonLoggableMessage3(attacker, target, str);
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
            if (targetData->blinkerClassStatus.status == STATUS_BLINKER || targetData->blinkerClassStatus.status == STATUS_CROSS_EYED)
                unkBool = FALSE;
            if (unkBool) {
                EntityInfo *info = GetEntInfo(target);
                info->action.direction = (GetDirectionTowardsPosition(&target->pos, &attacker->pos) & DIRECTION_MASK);
            }
            TargetTileInFront(target);
        }
        sub_806CDD4(target, 6, GetEntInfo(target)->action.direction);
        sub_80420E8(target, dmgStruct);
        var_24 = TRUE;
    }

    // HP goes down
    hpBefore = targetData->HP;
    if (targetData->HP > dmgStruct->dmg)
        targetData->HP -= dmgStruct->dmg;
    else
        targetData->HP = 0;

    if (targetData->reflectClassStatus.status == STATUS_ENDURING) {
        if (targetData->HP == 0) {
            targetData->HP = 1;
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_8100548);
        }
    }
    else if (isFalseSwipe == TRUE && targetData->HP == 0) {
        targetData->HP = 1;
        TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_810056C);
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
            unkTile->spawnOrVisibilityFlags &= ~(0x4);
            sub_8049ED4();
        }
        return FALSE;
    }

    // 0 HP
    if (targetData->invisibleClassStatus.status == STATUS_TRANSFORMED) {
        SendTransformEndMessage(attacker, target);
    }

    if (unkTile != NULL) {
        sub_803E708(0x14, 0x18);
        target->unk22 = 2;
        sub_803E708(0xA, 0x18);
        unkTile->spawnOrVisibilityFlags &= ~(0x4);
        sub_8049ED4();
    }
    else if (var_24) {
        target->unk22 = 1;
        sub_803E708(0x1E, 0x18);
    }

    r8 = 1;
    if (EntityIsValid(attacker) && GetEntityType(attacker) == ENTITY_MONSTER && attacker != target)
        r8 = 0;

    targetData->unk14C = 0;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
    if (dmgStruct->residualDmgType == 19 || dmgStruct->residualDmgType == 20) {
        if (targetData->isNotTeamMember) {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9E44);
        }
        else {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9E44);
        }
    }
    else if (targetData->isNotTeamMember)
    {
        if (targetData->monsterBehavior == BEHAVIOR_RESCUE_TARGET) {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9DF0[r8]);
        }
        else {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9CC0[r8]);
        }
    }
    else {
        PokemonStruct2 *recruitedMon = &gRecruitedPokemonRef->pokemon2[targetData->teamIndex];
        if (targetData->isTeamLeader || (targetData->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER && gDungeon->unk644.unk18 == 0)) {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9CEC[r8]);
        }
        else if (IsExperienceLocked(targetData->joinedAt.id)) {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9DAC[r8]);
        }
        else if (targetData->monsterBehavior == BEHAVIOR_RESCUE_TARGET) {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9DF0[r8]);
        }
        else if (sub_806A58C(recruitedMon->unkA)) {
            if (gDungeon->unk644.unk19 != 0) {
                DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9D8C[r8]);
            }
            else {
                DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9D84[r8]);
            }
        }
        else {
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80F9D28[r8]);
        }
    }

    if (targetData->frozenClassStatus.status == STATUS_WRAP || targetData->frozenClassStatus.status == STATUS_WRAPPED) {
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
                    gDungeon->unk644.unk35 = 0;
                    gDungeon->unk644.itemHoldersIdentified = 0;
                }
                ZeroOutItem(&targetData->heldItem);
                if (targetData->curseClassStatus.status == STATUS_SNATCH) {
                    EndCurseClassStatus(attacker, target, STATUS_SNATCH);
                }
                else if (targetData->curseClassStatus.status == STATUS_DECOY) {
                    EndCurseClassStatus(attacker, target, STATUS_DECOY);
                }
                sub_8078084(target);
                ResetMonEntityData(targetData, 0);
                sub_800DBBC();
                sub_806A390(target);
                sub_806CCB4(target, sub_806CEBC(target));
                EntityUpdateStatusSprites(target);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
                DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80FD46C);
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
                if (EntityIsValid(teamMember)
                    && teamMember != target
                    && CanSeeTarget(target, teamMember)
                    && abs(teamMember->pos.x - target->pos.x) <= 1 && abs(teamMember->pos.y - target->pos.y) <= 1)
                {
                    break;
                }
            }
            if (i != MAX_TEAM_MEMBERS) {
                DungeonPos monPos; // r4

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
                    gDungeon->unk644.unk35 = 0;
                    gDungeon->unk644.itemHoldersIdentified = 0;
                }
                ZeroOutItem(heldItem);
                if (targetData->curseClassStatus.status == STATUS_SNATCH) {
                    EndCurseClassStatus(attacker, target, STATUS_SNATCH);
                }
                else if (targetData->curseClassStatus.status == STATUS_DECOY) {
                    EndCurseClassStatus(attacker, target, STATUS_DECOY);
                }
                sub_8078084(target);
                ResetMonEntityData(targetData, 0);
                sub_800DBBC();
                sub_806A390(target);
                sub_806CCB4(target, sub_806CEBC(target));
                EntityUpdateStatusSprites(target);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], teamMember, 0);
                DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80FD484);
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
            CreateItemWithStickyChance(reviverSeed, ITEM_PLAIN_SEED, FORCE_STICKY_NEVER);
            target->unk22 = 0;
            targetData->HP = targetData->maxHPStat;
            targetData->unk158 = 0;
            targetData->unk14C = 1;
            targetData->belly = targetData->maxBelly;
            if (targetData->isTeamLeader) {
                gDungeon->unk644.unk35 = 0;
                gDungeon->unk644.itemHoldersIdentified = 0;
            }
            if (targetData->curseClassStatus.status == STATUS_SNATCH) {
                EndCurseClassStatus(attacker, target, STATUS_SNATCH);
            }
            else if (targetData->curseClassStatus.status == STATUS_DECOY) {
                EndCurseClassStatus(attacker, target, STATUS_DECOY);
            }
            sub_8078084(target);
            ResetMonEntityData(targetData, 0);
            sub_800DBBC();
            sub_806A390(target);
            sub_806CCB4(target, sub_806CEBC(target));
            EntityUpdateStatusSprites(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
            DisplayDungeonLoggableMessageTrue(attacker, gUnknown_80FD46C);
            sub_806F63C(target);
            return FALSE;
        }
    }

    if (!targetData->isTeamLeader && ItemExists(&targetData->heldItem)) {
        sub_80464C8(target, &target->pos, &targetData->heldItem);
        ZeroOutItem(&targetData->heldItem);
    }
    if (targetData->bossFlag) {
        gDungeon->unk644.bossSongIndex = 999;
    }

    // Give exp
    r10 = FALSE;
    if (GetEntityType(attacker) == ENTITY_MONSTER) {
        EntityInfo *attackerData = GetEntInfo(attacker);
        s32 exp  = CalculateEXPGain(targetData->id, targetData->level);
        switch (targetData->expMultiplier) {
            case EXP_BOOSTED:
                exp *= 3;
                exp /= 2;
                break;
            case EXP_HALVED:
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
                        if (EntityIsValid(teamMember) && teamMember != attacker) {
                            sub_8071D4C(attacker, teamMember, exp);
                        }
                    }
                    r10 = TRUE;
                }
            }
            else {
                if (DoEnemiesEvolveWhenKOed(gDungeon->unk644.dungeonLocation.id)) {
                    attackerData->unk149 = 1;
                    gDungeon->unkD = 1;
                }
            }
        }
    }

    if (EntityIsValid(attacker) && GetEntityType(attacker) == ENTITY_MONSTER && !GetEntInfo(attacker)->isTeamLeader)
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

bool8 sub_806E100(s48_16 *param_1, Entity *pokemon, Entity *target, u8 type, DamageStruct *dmgStruct)
{
  bool8 torrentFlag;
  bool8 overgrowFlag;
  bool8 swarmFlag;
  bool8 blazeFlag;
  bool8 torrentVisualFlag;
  bool8 overgrowVisualFlag;
  bool8 swarmVisualFlag;
  bool8 blazeVisualFlag;
  bool8 bVar4;
  EntityInfo *targetInfo;
  s32 effectiveness;
  s32 index;
  s32 local_38 [2];
  s32 hasWonderGuard;
  s32 normalOrFightingType;
  EntityInfo *pokemonInfo;
  u8 weather;
  s32 temp;

  bVar4 = FALSE;
  normalOrFightingType = FALSE;
  pokemonInfo = GetEntInfo(pokemon);
  targetInfo = GetEntInfo(target);
  FP48_16_FromS32(param_1, 1);
  dmgStruct->isCrit = 0;
  dmgStruct->unkE = 0;
  hasWonderGuard = FALSE;
  if (!EntityIsValid(target)) {
    return TRUE;
  }
  else {
    if ((type == TYPE_NORMAL) || (type == TYPE_FIGHTING)) {
      normalOrFightingType = TRUE;
    }
    if ((AbilityIsActive(target, ABILITY_WONDER_GUARD)) && (type != TYPE_NONE)) {
      hasWonderGuard = TRUE;
    }
    dmgStruct->typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    for (index = 0; index < 2; index++) {
      const s48_16 *local_48[] = {&gUnknown_8106F3C, &gUnknown_8106F44, &gUnknown_8106F04, &gUnknown_8106F4C};
      if (F48_16_IsZero(param_1)) break;
      if (((normalOrFightingType) && (targetInfo->types[index] == TYPE_GHOST)) && (targetInfo->exposed == FALSE)) {
            effectiveness = EFFECTIVENESS_IMMUNE;
            gDungeon->unk134.pokemonExposed = TRUE;
      }
      else {
            effectiveness = gTypeEffectivenessChart[type][targetInfo->types[index]];
      }
      if (effectiveness != EFFECTIVENESS_NEUTRAL) {
        F48_16_SMul(param_1,param_1,local_48[effectiveness]);
      }
      local_38[index] = effectiveness;
      gDungeon->unk134.unk13C[index] = effectiveness;
    }

    dmgStruct->typeEffectiveness = gEffectivenessChart[local_38[0]][local_38[1]];
    bVar4 = TRUE;
    if ((dmgStruct->typeEffectiveness != EFFECTIVENESS_SUPER) && (bVar4 = FALSE, hasWonderGuard)) {
      temp = gUnknown_8106EFC[1];
      param_1->hi = gUnknown_8106EFC[0];
      param_1->lo = temp;
    }

    if (((type == TYPE_FIRE) || (type == TYPE_ICE)) && (AbilityIsActive(target,ABILITY_THICK_FAT))) {
      gDungeon->unk134.unk16D = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((type == TYPE_FIRE) && (GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)) {
      gDungeon->unk134.fill16E[0] = TRUE;
      FP48_16_FromS32(param_1,0);
      dmgStruct->typeEffectiveness = EFFECTIVENESS_IMMUNE;
      dmgStruct->isCrit = 0;
      dmgStruct->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_GROUND) && (AbilityIsActive(target, ABILITY_LEVITATE))) {
      gDungeon->unk134.fill16E[1] = TRUE;
      FP48_16_FromS32(param_1,0);
      dmgStruct->typeEffectiveness = EFFECTIVENESS_IMMUNE;
      dmgStruct->isCrit = 0;
      dmgStruct->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_WATER) && (AbilityIsActive(pokemon, ABILITY_TORRENT))) {
      torrentFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      torrentVisualFlag = SetVisualFlags(pokemonInfo,0x80,torrentFlag);
      if (torrentFlag) {
        gDungeon->unk134.fill16E[2] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (torrentVisualFlag) {
        sub_80428EC(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEDA8);
      }
    }
    if ((type == TYPE_GRASS) && (AbilityIsActive(pokemon, ABILITY_OVERGROW))) {
      overgrowFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      overgrowVisualFlag = SetVisualFlags(pokemonInfo,2,overgrowFlag);
      if (overgrowFlag) {
        gDungeon->unk134.fill16E[3] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (overgrowVisualFlag) {
        sub_80428D8(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FED88);
      }
    }
    if ((type == TYPE_BUG) && (AbilityIsActive(pokemon, ABILITY_SWARM))) {
      swarmFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      swarmVisualFlag = SetVisualFlags(pokemonInfo,0x10,swarmFlag);
      if (swarmFlag) {
        gDungeon->unk134.fill16E[4] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (swarmVisualFlag) {
        sub_8042978(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEDC8);
      }
    }
    if ((type == TYPE_FIRE) && (AbilityIsActive(pokemon, ABILITY_BLAZE))) {
      blazeFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      blazeVisualFlag = SetVisualFlags(pokemonInfo,0x20,blazeFlag);
      if (blazeFlag) {
        gDungeon->unk134.fill16E[5] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (blazeVisualFlag) {
        sub_804298C(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEDE8);
      }
    }
    if (!(F48_16_IsZero(param_1)) && (MonsterIsType(pokemon, type))) {
      gDungeon->unk134.fill16E[6] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
    }
    weather = GetApparentWeather(pokemon);
    if (weather == WEATHER_SUNNY) {
      if (type == TYPE_FIRE) {
        gDungeon->unk134.unk16C = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk134.unk16C = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
      }
    }
    if (weather == WEATHER_RAIN) {
      if (type == TYPE_FIRE) {
        gDungeon->unk134.unk16B = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk134.unk16B = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
      }
    }
    if ((weather == WEATHER_CLOUDY) && (type != TYPE_NORMAL)) {
      static const s48_16 gUnknown_8106F64 = {0x0, 0xC000};
      F48_16_SMul(param_1,param_1, &gUnknown_8106F64);
      gDungeon->unk134.unk16A = TRUE;
    }
    if (((gDungeon->weather.mudSportTurns != 0) || (weather == WEATHER_FOG)) && (type == TYPE_ELECTRIC)) {
      gDungeon->unk134.fill16E[7] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((gDungeon->weather.waterSportTurns != 0) && (type == TYPE_FIRE)) {
      gDungeon->unk134.fill16E[8] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((type == TYPE_ELECTRIC) && (pokemonInfo->bideClassStatus.status == STATUS_CHARGING)) {
      gDungeon->unk134.fill16E[9] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
    }
  }
  return bVar4;
}

s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType)
{
    s32 weight = 1;
    bool8 checkExposed = FALSE;
    EntityInfo *userData;
    EntityInfo *targetData;
    u8 *targetTypes;
    u8 *targetType;
    u32 moveTypeOffset;
    if (!EntityIsValid(target))
    {
        return 1;
    }
    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING)
    {
        checkExposed = TRUE;
    }
    userData = GetEntInfo(user);
    targetData = GetEntInfo(target);
    if (moveType == TYPE_FIRE && GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)
    {
        return 0;
    }
    if (moveType == TYPE_ELECTRIC && AbilityIsActive(target, ABILITY_VOLT_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_WATER && AbilityIsActive(target, ABILITY_WATER_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_GROUND && AbilityIsActive(target, ABILITY_LEVITATE))
    {
        return 1;
    }
    targetTypes = targetData->types;
    moveTypeOffset = moveType * NUM_TYPES * sizeof(s16);
    targetType = targetData->types;
    do
    {
        s32 effectiveness;
        u32 typeEffectivenessMultipliers[NUM_EFFECTIVENESS] = {0, 1, 2, 4};
        if (checkExposed && *targetType == TYPE_GHOST && !targetData->exposed)
        {
            effectiveness = 0;
            gDungeon->unk134.pokemonExposed = TRUE;
        }
        else
        {
            effectiveness = gTypeEffectivenessChart[moveType][*targetType];
            // Used to swap variable initialization order at the loop start.
            effectiveness = *(s16*)(((s8*) gTypeEffectivenessChart) + moveTypeOffset + *targetType * 2);
        }
        if (weight == 0)
        {
            goto breakLoop;
        }
        weight *= typeEffectivenessMultipliers[effectiveness];
        weight /= 2;
        if (weight == 0)
        {
            // BUG: If the Pokémon's first type resists the move, the second type is ignored.
            // This calculates type effectiveness incorrectly if the first type resists the move and the second type is weak to the move.
            // For example, a Fire-type move is considered not very effective against a Rock/Bug-type like Anorith.
            return 2;
        }
    } while ((s32)(++targetType) <= (s32)(targetTypes + 1));
    breakLoop:
    if ((moveType == TYPE_FIRE || moveType == TYPE_ICE) && AbilityIsActive(target, ABILITY_THICK_FAT))
    {
        return 2;
    }
    if (moveType == TYPE_WATER && AbilityIsActive(user, ABILITY_TORRENT))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_GRASS && AbilityIsActive(user, ABILITY_OVERGROW))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_BUG && AbilityIsActive(user, ABILITY_SWARM))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_FIRE && AbilityIsActive(user, ABILITY_BLAZE))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (weight == 0)
    {
        return 2;
    }
    if (MonsterIsType(user, moveType))
    {
        weight *= 2;
    }
    targetTypes = targetData->types;
    if (GetApparentWeather(user) == WEATHER_SUNNY)
    {
        if (moveType == TYPE_FIRE)
        {
            weight *= 2;
        }
        else if (moveType == TYPE_WATER)
        {
            return 2;
        }
    }
    if (gDungeon->weather.mudSportTurns != 0 && moveType == TYPE_ELECTRIC)
    {
        return 2;
    }
    if (gDungeon->weather.waterSportTurns != 0 && moveType == TYPE_FIRE)
    {
        return 2;
    }
    if (moveType == TYPE_ELECTRIC && userData->bideClassStatus.status == STATUS_CHARGING)
    {
        weight *= 2;
    }
    if (weight > 2)
    {
        weight = 3;
    }
    return weight + 2;
}

static void ApplyAtkDefStatBoosts(Entity *attacker, Entity *target, u8 moveType, s32 *atkStat, s32 *defStat, s32 rand)
{
    bool32 isNotEnemy;
    s32 atkMultiplier = 1;
    s32 atkDivisor = 1;
    s32 defMultiplier = 1;
    s32 defDivisor = 1;
    s32 splitIndex = (!IsTypePhysical(moveType)) ? 1 : 0;

    if (AbilityIsActive(attacker, ABILITY_GUTS)) {
        EntityInfo *entInfo = GetEntInfo(attacker);
        bool8 gutsBoost = HasNegativeStatus(attacker);
        bool8 visFlags_attacker_1 = SetVisualFlags(entInfo,1,gutsBoost);

        if (gutsBoost) {
            atkMultiplier = 2;
        }
        if (visFlags_attacker_1) {
            sub_80428B0(attacker);
            TryDisplayDungeonLoggableMessage3(attacker,target, gUnknown_80FEE04); // Guts boosted its power
        }
    }

    if ((AbilityIsActive(attacker, ABILITY_HUGE_POWER)) || (AbilityIsActive(attacker, ABILITY_PURE_POWER))) {
        EntityInfo *entInfo = GetEntInfo(attacker);
        bool32 hugePowerBoost = (rand < 33 && splitIndex == 0);
        bool8 visFlags_attacker_2 = SetVisualFlags(entInfo,0x100,hugePowerBoost);

        if (hugePowerBoost) {
            atkMultiplier *= 3;
            atkDivisor *= 2;
        }
        if (visFlags_attacker_2) {
            sub_80428C4(attacker);
            TryDisplayDungeonLoggableMessage3(attacker,target, gUnknown_80FEE2C); // It's special ability boosted Attack
        }
    }

    if ((AbilityIsActive(attacker, ABILITY_HUSTLE)) && (splitIndex == 0)) {
        atkMultiplier *= 3;
        atkDivisor *= 2;
    }

    if (GetEntInfo(attacker)->isNotTeamMember) {
        isNotEnemy = FALSE;
    }
    else {
        isNotEnemy = TRUE;
    }

    if ((AbilityIsActive(attacker, ABILITY_PLUS)) && (splitIndex == 1) && gDungeon->minusIsActive[isNotEnemy]) {
        atkMultiplier *= 15;
        atkDivisor *= 10;
    }
    if ((AbilityIsActive(attacker, ABILITY_MINUS)) && (splitIndex == 1) && gDungeon->plusIsActive[isNotEnemy]) {
        atkMultiplier *= 15;
        atkDivisor *= 10;
    }

    if (AbilityIsActive(target, ABILITY_INTIMIDATE) && (splitIndex == 0)) {
        atkMultiplier *= 4;
        atkDivisor *= 5;
    }

    if ((AbilityIsActive(target, ABILITY_MARVEL_SCALE)) && (splitIndex == 0)) {
        EntityInfo *targetInfo = GetEntInfo(target);
        bool8 hasNegStatus_target = HasNegativeStatus(target);
        bool8 visFlags_target = SetVisualFlags(targetInfo, 8, hasNegStatus_target);

        if (hasNegStatus_target) {
            defMultiplier *= 3;
            defDivisor *= 2;
        }
        if (visFlags_target) {
            sub_8042940(target);
            TryDisplayDungeonLoggableMessage3(attacker,target, gUnknown_80FEE54); // Its special ability quickened attacks!
        }
    }

    *atkStat *= atkMultiplier;
    *defStat *= defMultiplier;
    if (atkDivisor != 1) {
        *atkStat = *atkStat / atkDivisor;
    }
    if (defDivisor != 1) {
        *defStat = *defStat / defDivisor;
    }
}

static inline void SetDamageOne(struct DamageStruct *dmgStruct, u8 moveType)
{
    dmgStruct->dmg = 1;
    dmgStruct->residualDmgType = 0;
    dmgStruct->typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    dmgStruct->type = moveType;
    dmgStruct->isCrit = FALSE;
    dmgStruct->unkE = 0;
    dmgStruct->tookNoDamage = FALSE;
}

void CalcDamage(Entity *attacker, Entity *target, u8 moveType, s32 movePower, s32 critChance, struct DamageStruct *dmgStruct, s24_8 arg8, u16 moveId, bool8 arg_10)
{
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 splitIndex = (!IsTypePhysical(moveType)) ? 1 : 0;

    sub_806F500();
    if (!attackerInfo->isTeamLeader && FixedPointToInt(attackerInfo->belly) == 0) {
        SetDamageOne(dmgStruct, moveType);
    }
    else if (moveId == MOVE_REGULAR_ATTACK && AbilityIsActive(target, ABILITY_WONDER_GUARD)) {
        SetDamageOne(dmgStruct, moveType);
    }
    else {
        s32 atkStatStage, defStatStage;
        s24_8 statCalc;
        s32 atkStat, defStat;
        s32 rand;
        s32 r6;
        s48_16 unkSp1;
        s48_16 unkSp2;
        s48_16 unkSp3;
        s48_16 unkSp4;
        s48_16 unkSp5;
        s48_16 unkSp6;
        s48_16 unkSp7;
        s48_16 unkSp8;
        s48_16 unkSp9;
        s48_16 unkSp10;
        s48_16 unkSp11;
        bool8 r5;

        dmgStruct->type = moveType;
        gDungeon->unk134.unk134 = moveType;
        gDungeon->unk134.unk138 = splitIndex;

        atkStatStage = attackerInfo->offensiveStages[splitIndex];
        if (arg_10 && moveType == TYPE_FIRE) {
            atkStatStage += attackerInfo->flashFireBoost;
            gDungeon->unk134.unk140[2] = attackerInfo->flashFireBoost;
        }
        if (attackerInfo->apparentID == MONSTER_DEOXYS_ATTACK) {
            atkStatStage += 2;
        }
        if (attackerInfo->apparentID == MONSTER_DEOXYS_DEFENSE) {
            atkStatStage -= 2;
        }
        if (attackerInfo->apparentID == MONSTER_DEOXYS_SPEED) {
            atkStatStage -= 2;
        }

        if (atkStatStage < 0) atkStatStage = 0;
        if (atkStatStage > 20) atkStatStage = 20;

        gDungeon->unk134.unk13E[0] = atkStatStage;
        gDungeon->unk134.unk140[0] = attackerInfo->atk[splitIndex] + movePower;
        statCalc = s24_8_mul(IntToF248(attackerInfo->atk[splitIndex] + movePower), gAtkStatStageMultipliers[atkStatStage]);
        statCalc = s24_8_mul(statCalc, attackerInfo->offensiveMultipliers[splitIndex]);
        atkStat = F248ToInt(statCalc);

        defStatStage = targetInfo->defensiveStages[splitIndex];
        if (splitIndex == 0 && targetInfo->bideClassStatus.status == STATUS_SKULL_BASH) {
            gDungeon->unk134.unk17A = 1;
            defStatStage++;
        }
        if (targetInfo->apparentID == MONSTER_DEOXYS_ATTACK) {
            defStatStage -= 2;
        }
        if (targetInfo->apparentID == MONSTER_DEOXYS_DEFENSE) {
            defStatStage += 2;
        }
        if (targetInfo->apparentID == MONSTER_DEOXYS_SPEED) {
            defStatStage -= 2;
        }

        if (defStatStage < 0) defStatStage = 0;
        if (defStatStage > 20) defStatStage = 20;

        gDungeon->unk134.unk13E[1] = defStatStage;
        gDungeon->unk134.unk140[1] = targetInfo->def[splitIndex];
        statCalc = s24_8_mul(IntToF248(targetInfo->def[splitIndex]), gDefStatStageMultipliers[defStatStage]);
        statCalc = s24_8_mul(statCalc, targetInfo->defensiveMultipliers[splitIndex]);
        defStat = F248ToInt(statCalc);

        rand = DungeonRandInt(100);
        if (splitIndex == 0) {
            if (HasHeldItem(attacker, ITEM_POWER_BAND)) {
                atkStat += gUnknown_810AC60;
                gDungeon->unk134.unk160 += gUnknown_810AC60;
            }
            if (HasHeldItem(attacker, ITEM_MUNCH_BELT)) {
                atkStat += gUnknown_810AC68;
                gDungeon->unk134.unk160 += gUnknown_810AC68;
            }
            if (arg_10 && HasHeldItem(target, ITEM_DEF_SCARF)) {
                defStat += gUnknown_810AC64;
                gDungeon->unk134.unk162 += gUnknown_810AC64;
            }
        }
        else {
            if (arg_10 && HasHeldItem(target, ITEM_ZINC_BAND)) {
                defStat += gUnknown_810AC66;
                gDungeon->unk134.unk163 += gUnknown_810AC66;
            }
            if (HasHeldItem(attacker, ITEM_SPECIAL_BAND)) {
                atkStat += gUnknown_810AC62;
                gDungeon->unk134.unk161 += gUnknown_810AC62;
            }
            if (HasHeldItem(attacker, ITEM_MUNCH_BELT)) {
                atkStat += gUnknown_810AC68;
                gDungeon->unk134.unk161 += gUnknown_810AC68;
            }
        }

        gDungeon->unk134.unk140[3] = atkStat;
        gDungeon->unk134.unk140[4] = defStat;
        if (atkStat < 0) atkStat = 0;
        if (atkStat >= 999) atkStat = 999;

        attackerInfo->previousVisualFlags &= ~(0x100);
        attackerInfo->visualFlags &= ~(0x100);
        ApplyAtkDefStatBoosts(attacker, target, moveType, &atkStat, &defStat, rand);
        FP48_16_FromS32(&unkSp1, atkStat - defStat);
        FP48_16_FromS32(&unkSp2, 8);
        F48_16_SDiv(&unkSp1, &unkSp1, &unkSp2);
        if (!attackerInfo->isNotTeamMember) {
            FP48_16_FromS32(&unkSp2, attackerInfo->level);
            unkSp3.hi = 0;
            unkSp3.lo = 0xAAAA;
            F48_16_SMul(&unkSp2, &unkSp2, &unkSp3);
            r6 = (attackerInfo->level * 2) / 3;
        }
        else {
            s32 unkAtkStat2 = attackerInfo->atk[splitIndex];
            s32 unkDefStat2 = 1;
            ApplyAtkDefStatBoosts(attacker, target, moveType, &unkAtkStat2, &unkDefStat2, rand);
            FP48_16_FromS32(&unkSp2, unkAtkStat2);
            FP48_16_FromS32(&unkSp3, 3);
            F48_16_SDiv(&unkSp2, &unkSp2, &unkSp3);
            r6 = unkAtkStat2 / 3;
        }
        FP48_16_Add(&unkSp4, &unkSp1, &unkSp2);
        gDungeon->unk134.unk140[5] = r6;
        gDungeon->unk134.unk140[6] = FP48_16_ToS32(&unkSp4);
        unkSp5 = unkSp4;
        unkSp7 = unkSp4;
        F48_16_SMul(&unkSp5, &unkSp5, &unkSp5);
        unkSp6.hi = 0;
        unkSp6.lo = 0xCCC;
        F48_16_SMul(&unkSp5, &unkSp5, &unkSp6);
        FP48_16_FromS32(&unkSp6, 2);
        F48_16_SMul(&unkSp7, &unkSp7, &unkSp6);
        FP48_16_FromS32(&unkSp6, defStat);
        FP48_16_Subtract(&unkSp7, &unkSp7, &unkSp6);
        FP48_16_FromS32(&unkSp6, 10);
        FP48_16_Add(&unkSp7, &unkSp7, &unkSp6);
        FP48_16_Add(&unkSp8, &unkSp5, &unkSp7);
        if (FP48_16_SLessThan(&gUnknown_8106F24, &unkSp8)) {
            unkSp8 = gUnknown_8106F24;
        }
        if (FP48_16_SLessThan(&unkSp8, &gUnknown_8106F04)) {
            unkSp8 = gUnknown_8106F04;
        }
        r5 = sub_806E100(&unkSp9, attacker, target, moveType, dmgStruct);

        if (moveType == TYPE_FIRE) {
            s32 flashFireStatus = GetFlashFireStatus(target);
            if (flashFireStatus != FLASH_FIRE_STATUS_NONE && targetInfo->unk152 == 0 && arg_10) {
                targetInfo->unk152 = 1;
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
                if (flashFireStatus == FLASH_FIRE_STATUS_MAXED) {
                    TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FAE00); // Fire moves won't become stronger!
                }
                else {
                    TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FADD8); // m1 used Flash Fire to absorb fire!
                }
            }
        }
        if (arg_10) {
            if (splitIndex == 0 && targetInfo->reflectClassStatus.status == STATUS_REFLECT) {
                sub_8041B74(target);
                F48_16_SMul(&unkSp9, &unkSp9, &gUnknown_8106F1C);
                gDungeon->unk134.unk166 = 1;
            }
            if (splitIndex == 1 && targetInfo->reflectClassStatus.status == STATUS_LIGHT_SCREEN) {
                sub_8041B5C(target);
                F48_16_SMul(&unkSp9, &unkSp9, &gUnknown_8106F1C);
                gDungeon->unk134.unk167 = 1;
            }
        }

        // Check crit
        if (!AbilityIsActive(target, ABILITY_BATTLE_ARMOR) && !AbilityIsActive(target, ABILITY_SHELL_ARMOR)) {
            s32 critOdds;

            if (attackerInfo->isNotTeamMember) {
                critOdds = 0;
            }
            else {
                critOdds = critChance;
            }

            if (attackerInfo->sureShotClassStatus.status == STATUS_FOCUS_ENERGY) {
                critOdds = 999;
                gDungeon->unk134.unk168 = 1;
            }
            else {
                if (HasHeldItem(attacker, ITEM_SCOPE_LENS)) {
                    critOdds += gCritOddsScopeLensPatsyBand;
                    gDungeon->unk134.unk164 = 1;
                }
                if (HasHeldItem(target, ITEM_PATSY_BAND)) {
                    critOdds += gCritOddsScopeLensPatsyBand;
                    gDungeon->unk134.unk165 = 1;
                }
                if (r5 && IQSkillIsEnabled(attacker, IQ_TYPE_ADVANTAGE_MASTER)) {
                    critOdds = gCritOddsIqAdvantageMaster;
                    gDungeon->unk134.unk169 = 1;
                }
            }
            if (DungeonRandInt(100) < critOdds) {
                F48_16_SMul(&unkSp9, &unkSp9, &gUnknown_8106F14);
                dmgStruct->isCrit = TRUE;
            }
        }

        gDungeon->unk134.unk154 = FP48_16_ToS32(&unkSp8);
        F48_16_SMul(&unkSp8, &unkSp8, &unkSp9);
        {
            // Ugly hack needed to match
            #ifdef NONMATCHING
            s24_8 arg8_Match;
            #else
            register s24_8 arg8_Match asm("r2");
            #endif // NONMATCHING

            gDungeon->unk134.unk15C = arg8_Match = arg8;
            FP48_16_FromF248(&unkSp10, arg8_Match);
            F48_16_SMul(&unkSp8, &unkSp8, &unkSp10);
        }

        // ALSO needed to match. unk694 chosen randomly and it worked with matching.
        ASM_MATCH_TRICK(gDungeon->unk644.unk50);
        gDungeon->unk134.unk150 = FP48_16_ToS32(&unkSp8);
        {
            s32 rnd = DungeonRandInt(0x4000);
            unkSp9.hi = 0;
            unkSp9.lo = 0xE000 + rnd;
        }
        F48_16_SMul(&unkSp8, &unkSp8, &unkSp9);
        FP48_16_FromS32(&unkSp11, 100);

        F48_16_SMul(&unkSp9, &unkSp11, &unkSp9);
        gDungeon->unk134.unk158 = FP48_16_ToS32(&unkSp9);

        dmgStruct->dmg = FP48_16_ToS32(&unkSp8);
        dmgStruct->residualDmgType = 0;
        if (dmgStruct->dmg == 0) {
            dmgStruct->isCrit = FALSE;
        }
    }
}

void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct)
{
    s48_16 unkSp1;
    s48_16 unkSp2;
    s32 a2New = a2;

    if (a2New <= 0) a2New = 1;
    if (a2New > 999) a2New = 999;

    dmgStruct->type = moveType;
    sub_806E100(&unkSp1, attacker, target, moveType, dmgStruct);
    FP48_16_FromS32(&unkSp2, a2New);
    F48_16_SMul(&unkSp2, &unkSp2, &unkSp1);
    dmgStruct->dmg = FP48_16_ToS32(&unkSp2);
    dmgStruct->residualDmgType = 0;
}

void DealDamageToEntity(Entity *entity, s32 dmg, s32 r6, s32 r4)
{
    Entity spEntity;
    struct DamageStruct dmgStruct;
    s32 r4_ = (s16) r4;

    sub_80457DC(&spEntity);
    dmgStruct.dmg = dmg;
    dmgStruct.typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    dmgStruct.type = TYPE_NONE;
    dmgStruct.residualDmgType = r6;
    dmgStruct.isCrit = FALSE;
    dmgStruct.unkE = 0;
    dmgStruct.tookNoDamage = FALSE;
    HandleDealingDamage(&spEntity, entity, &dmgStruct, FALSE, FALSE, r4_, FALSE, 0);
}

void sub_806F370(Entity *pokemon, Entity *target, s32 dmg, s32 giveExp, bool8 *tookNoDamage, u8 moveType, s16 arg_8, s32 residualDmgType, s32 arg_10, s32 arg_14)
{
    s32 i;
    struct DamageStruct dmgStruct;
    s32 arg_8_ = arg_8;
    s32 dmgNew = dmg;

    dmgStruct.typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    dmgStruct.residualDmgType = residualDmgType;
    dmgStruct.type = moveType;
    dmgStruct.isCrit = FALSE;
    dmgStruct.unkE = 0;

    if (moveType != TYPE_NONE) {
        s32 typeEffectiveness[2];
        EntityInfo *targetInfo = GetEntInfo(target);
        for (i = 0; i < 2; i++) {
            s32 effectiv = gTypeEffectivenessChart[moveType][targetInfo->types[i]];
            typeEffectiveness[i] = effectiv;
        }
        if (AbilityIsActive(target, ABILITY_WONDER_GUARD)) {
            if (gEffectivenessChart[typeEffectiveness[0]][typeEffectiveness[1]] != EFFECTIVENESS_SUPER) {
                dmgNew = 0;
            }
        }
    }

    dmgStruct.dmg = dmgNew;
    if (dmgNew == 0) {
        dmgStruct.tookNoDamage = TRUE;
    }
    else {
        dmgStruct.tookNoDamage = FALSE;
    }

    HandleDealingDamage(pokemon, target, &dmgStruct, FALSE, giveExp, arg_8_, arg_10, arg_14);
    if (tookNoDamage != NULL) {
        *tookNoDamage = dmgStruct.tookNoDamage;
    }
}

void SetShopkeeperAggression(Entity *pokemon, Entity *target)
{
    EntityInfo *info;

    info = GetEntInfo(target);

    if(info->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        if(GetEntityType(pokemon) == ENTITY_MONSTER)
        {
            if(GetEntInfo(pokemon)->isNotTeamMember)
            {
                info->shopkeeper = SHOPKEEPER_MODE_ATTACK_ENEMIES;
            }
            else
            {
                info->shopkeeper = SHOPKEEPER_MODE_ATTACK_TEAM;
            }
        }
    }
}

void sub_806F480(Entity *pokemon, u8 r1)
{
    EntityInfo *info;

    info = GetEntInfo(pokemon);

    if(info->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        if(r1)
        {
            info->shopkeeper = SHOPKEEPER_MODE_ATTACK_ENEMIES;
        }
        else
        {
            info->shopkeeper = SHOPKEEPER_MODE_ATTACK_TEAM;
        }
    }
}

u8 sub_806F4A4(Entity *pokemon, u8 type)
{
    EntityInfo *info = GetEntInfo(pokemon);
    s32 index;

    if(MonsterIsType(pokemon, TYPE_GHOST))
    {
        if(type == TYPE_NORMAL || type == TYPE_FIGHTING)
            if(!info->exposed)
                return FALSE;
    }
    for(index = 0; index < 2; index++)
    {
        if(gTypeEffectivenessChart[type][info->types[index]] == EFFECTIVENESS_IMMUNE)
            return FALSE;
    }
    return TRUE;
}

void sub_806F500(void)
{
    struct unkStruct_Dungeon134_sub *temp;

    temp = &gDungeon->unk134;

    temp->unk134 = 0;
    temp->unk138 = 0;
    temp->unk13C[0] = 0;
    temp->unk13C[1] = 0;
    temp->unk13E[0] = 0xA;
    temp->unk13E[1] = 0xA;
    temp->unk140[0] = 1;
    temp->unk140[1] = 1;
    temp->unk140[2] = 0;
    temp->unk140[4] = 0;
    temp->unk140[3] = 0;
    temp->unk140[5] = 0;
    temp->unk140[6] = 0;
    temp->unk150 = 0;
    temp->unk158 = 0;
    temp->unk15C = F248_ZERO;
    temp->unk160 = 0;
    temp->unk161 = 0;
    temp->unk162 = 0;
    temp->unk163 = 0;
    temp->unk164 = 0;
    temp->unk165 = 0;
    temp->unk166 = 0;
    temp->unk167 = 0;
    temp->unk168 = 0;
    temp->unk169 = 0;
    temp->unk16A = 0;
    temp->unk16C = 0;
    temp->unk16B = 0;
    temp->unk16D = 0;
    temp->fill16E[0] = 0;
    temp->fill16E[1] = 0;
    temp->fill16E[2] = 0;
    temp->fill16E[3] = 0;
    temp->fill16E[4] = 0;
    temp->fill16E[5] = 0;
    temp->fill16E[6] = 0;
    temp->fill16E[7] = 0;
    temp->fill16E[8] = 0;
    temp->fill16E[9] = 0;
    temp->fill16E[10] = 0;
    temp->pokemonExposed = FALSE;
    temp->unk17A = 0;
}

static const s32 gUnknown_8106F7C[] = {0, 0, 0, 1};

s32 sub_806F62C(int param_1)
{
    return gUnknown_8106F7C[param_1];
}

void sub_806F63C(Entity *param_1)
{
    UnkDungeonGlobal_unk181E8_sub *temp;

    temp = &gDungeon->unk181e8;

    if (temp->cameraTarget == param_1) {
        sub_803F508(temp->cameraTarget);
    }
}
