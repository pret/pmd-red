#include "global.h"
#include "constants/ability.h"
#include "structs/str_dungeon.h"
#include "dungeon_pokemon_attributes.h"
#include "status_checks_1.h"
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
#include "type_chart.h"
#include "dungeon_random.h"
#include "code_8045A00.h"
#include "dungeon_items.h"
#include "structs/str_damage.h"

void sub_8042940(Entity *r0);
void sub_80428B0(Entity *r0);
void sub_80428C4(Entity *r0);

extern void sub_806F500(void);
extern void sub_800A020(struct unkStruct_80943A8 *param_1, u32 param_2);
extern void sub_800A3F0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *);
extern void sub_800A6D0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *);
extern void sub_800A34C(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, const struct unkStruct_80943A8 *param3);
extern void sub_800A6F0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *param3);
extern void sub_800A088(struct unkStruct_80943A8 *param_1, u32 param_2);
extern u32 sub_800A048(struct unkStruct_80943A8 *param_1);
extern bool8 sub_800A2F0(const struct unkStruct_80943A8*, const struct unkStruct_80943A8*);
extern bool8 sub_806E100(struct unkStruct_80943A8 *param_1, Entity *pokemon, Entity *target, u8 type, struct DamageStruct *dmgStruct);
extern void sub_8041B74(Entity *pokemon);
extern void sub_8041B5C(Entity *pokemon);
extern void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
extern void sub_80457DC(Entity *);

extern const s32 gUnknown_80F54B4[NUM_EFFECTIVENESS][NUM_EFFECTIVENESS];
extern const s32 gUnknown_80F504C[];
extern const s32 gUnknown_80F50A0[];
extern const s16 gUnknown_810AC60;
extern const s16 gUnknown_810AC68;
extern const s16 gUnknown_810AC64;
extern const s16 gUnknown_810AC66;
extern const s16 gUnknown_810AC68;
extern const s16 gUnknown_810AC62;
extern const s16 gUnknown_80F4DAE;
extern const s16 gUnknown_80F4DB0;
extern const struct unkStruct_80943A8 gUnknown_8106F24;
extern const struct unkStruct_80943A8 gUnknown_8106F04;
extern const struct unkStruct_80943A8 gUnknown_8106F1C;
extern const struct unkStruct_80943A8 gUnknown_8106F14;
extern const u8 *const gUnknown_80FAE00;
extern const u8 *const gUnknown_80FADD8;
extern const u8 *const gUnknown_80FEE04;
extern const u8 *const gUnknown_80FEE2C;
extern const u8 *const gUnknown_80FEE54;

static void ApplyAtkDefStatBoosts(Entity *attacker, Entity *target, u8 moveType, s32 *atkStat, s32 *defStat, s32 rand)
{
    bool32 isNotEnemy;
    s32 atkMultiplier = 1;
    s32 atkDivisor = 1;
    s32 defMultiplier = 1;
    s32 defDivisor = 1;
    s32 splitIndex = (!IsTypePhysical(moveType)) ? 1 : 0;

    if (HasAbility(attacker, ABILITY_GUTS)) {
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

    if ((HasAbility(attacker, ABILITY_HUGE_POWER)) || (HasAbility(attacker, ABILITY_PURE_POWER))) {
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

    if ((HasAbility(attacker, ABILITY_HUSTLE)) && (splitIndex == 0)) {
        atkMultiplier *= 3;
        atkDivisor *= 2;
    }

    if (GetEntInfo(attacker)->isNotTeamMember) {
        isNotEnemy = FALSE;
    }
    else {
        isNotEnemy = TRUE;
    }

    if ((HasAbility(attacker, ABILITY_PLUS)) && (splitIndex == 1) && gDungeon->minusIsActive[isNotEnemy]) {
        atkMultiplier *= 15;
        atkDivisor *= 10;
    }
    if ((HasAbility(attacker, ABILITY_MINUS)) && (splitIndex == 1) && gDungeon->plusIsActive[isNotEnemy]) {
        atkMultiplier *= 15;
        atkDivisor *= 10;
    }

    if (HasAbility(target, ABILITY_INTIMIDATE) && (splitIndex == 0)) {
        atkMultiplier *= 4;
        atkDivisor *= 5;
    }

    if ((HasAbility(target, ABILITY_MARVEL_SCALE)) && (splitIndex == 0)) {
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
    dmgStruct->unkF = 0;
}

void CalcDamage(Entity *attacker, Entity *target, u8 moveType, s32 movePower, s32 critChance, struct DamageStruct *dmgStruct, s32 arg8, u16 moveId, bool8 arg_10)
{
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 splitIndex = (!IsTypePhysical(moveType)) ? 1 : 0;

    sub_806F500();
    if (!attackerInfo->isTeamLeader && FixedPointToInt(attackerInfo->belly) == 0) {
        SetDamageOne(dmgStruct, moveType);
    }
    else if (moveId == MOVE_REGULAR_ATTACK && HasAbility(target, ABILITY_WONDER_GUARD)) {
        SetDamageOne(dmgStruct, moveType);
    }
    else {
        s32 atkStatStage, defStatStage;
        s32 statCalc;
        s32 atkStat, defStat;
        s32 rand;
        s32 r6;
        struct unkStruct_80943A8 unkSp1;
        struct unkStruct_80943A8 unkSp2;
        struct unkStruct_80943A8 unkSp3;
        struct unkStruct_80943A8 unkSp4;
        struct unkStruct_80943A8 unkSp5;
        struct unkStruct_80943A8 unkSp6;
        struct unkStruct_80943A8 unkSp7;
        struct unkStruct_80943A8 unkSp8;
        struct unkStruct_80943A8 unkSp9;
        struct unkStruct_80943A8 unkSp10;
        struct unkStruct_80943A8 unkSp11;
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
        statCalc = s24_8_mul((attackerInfo->atk[splitIndex] + movePower) * 256, gUnknown_80F504C[atkStatStage]);
        statCalc = s24_8_mul(statCalc, attackerInfo->offensiveMultipliers[splitIndex]);
        atkStat = statCalc / 256;

        defStatStage = targetInfo->defensiveStages[splitIndex];
        if (splitIndex == 0 && targetInfo->charging.chargingStatus == STATUS_SKULL_BASH) {
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
        statCalc = s24_8_mul((targetInfo->def[splitIndex]) * 256, gUnknown_80F50A0[defStatStage]);
        statCalc = s24_8_mul(statCalc, targetInfo->defensiveMultipliers[splitIndex]);
        defStat = statCalc / 256;

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
        sub_800A020(&unkSp1, atkStat - defStat);
        sub_800A020(&unkSp2, 8);
        sub_800A3F0(&unkSp1, &unkSp1, &unkSp2);
        if (!attackerInfo->isNotTeamMember) {
            sub_800A020(&unkSp2, attackerInfo->level);
            unkSp3.s0 = 0;
            unkSp3.s4 = 0xAAAA;
            sub_800A34C(&unkSp2, &unkSp2, &unkSp3);
            r6 = (attackerInfo->level * 2) / 3;
        }
        else {
            s32 unkAtkStat2 = attackerInfo->atk[splitIndex];
            s32 unkDefStat2 = 1;
            ApplyAtkDefStatBoosts(attacker, target, moveType, &unkAtkStat2, &unkDefStat2, rand);
            sub_800A020(&unkSp2, unkAtkStat2);
            sub_800A020(&unkSp3, 3);
            sub_800A3F0(&unkSp2, &unkSp2, &unkSp3);
            r6 = unkAtkStat2 / 3;
        }
        sub_800A6D0(&unkSp4, &unkSp1, &unkSp2);
        gDungeon->unk134.unk140[5] = r6;
        gDungeon->unk134.unk140[6] = sub_800A048(&unkSp4);
        unkSp5 = unkSp4;
        unkSp7 = unkSp4;
        sub_800A34C(&unkSp5, &unkSp5, &unkSp5);
        unkSp6.s0 = 0;
        unkSp6.s4 = 0xCCC;
        sub_800A34C(&unkSp5, &unkSp5, &unkSp6);
        sub_800A020(&unkSp6, 2);
        sub_800A34C(&unkSp7, &unkSp7, &unkSp6);
        sub_800A020(&unkSp6, defStat);
        sub_800A6F0(&unkSp7, &unkSp7, &unkSp6);
        sub_800A020(&unkSp6, 10);
        sub_800A6D0(&unkSp7, &unkSp7, &unkSp6);
        sub_800A6D0(&unkSp8, &unkSp5, &unkSp7);
        if (sub_800A2F0(&gUnknown_8106F24, &unkSp8)) {
            unkSp8 = gUnknown_8106F24;
        }
        if (sub_800A2F0(&unkSp8, &gUnknown_8106F04)) {
            unkSp8 = gUnknown_8106F04;
        }
        r5 = sub_806E100(&unkSp9, attacker, target, moveType, dmgStruct);

        if (moveType == TYPE_FIRE) {
            s32 flashFireStatus = GetFlashFireStatus(target);
            if (flashFireStatus != FLASH_FIRE_STATUS_NONE && targetInfo->unk152 == 0 && arg_10) {
                targetInfo->unk152 = 1;
                SetMessageArgument(gFormatBuffer_Monsters[1], target, 0);
                if (flashFireStatus == FLASH_FIRE_STATUS_MAXED) {
                    TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FAE00); // Fire moves won't become stronger!
                }
                else {
                    TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FADD8); // m1 used Flash Fire to absorb fire!
                }
            }
        }
        if (arg_10) {
            if (splitIndex == 0 && targetInfo->protection.protectionStatus == STATUS_REFLECT) {
                sub_8041B74(target);
                sub_800A34C(&unkSp9, &unkSp9, &gUnknown_8106F1C);
                gDungeon->unk134.unk166 = 1;
            }
            if (splitIndex == 1 && targetInfo->protection.protectionStatus == STATUS_LIGHT_SCREEN) {
                sub_8041B5C(target);
                sub_800A34C(&unkSp9, &unkSp9, &gUnknown_8106F1C);
                gDungeon->unk134.unk167 = 1;
            }
        }

        // Check crit
        if (!HasAbility(target, ABILITY_BATTLE_ARMOR) && !HasAbility(target, ABILITY_SHELL_ARMOR)) {
            s32 critOdds;

            if (attackerInfo->isNotTeamMember) {
                critOdds = 0;
            }
            else {
                critOdds = critChance;
            }

            if (attackerInfo->moveStatus.moveStatus == STATUS_FOCUS_ENERGY) {
                critOdds = 999;
                gDungeon->unk134.unk168 = 1;
            }
            else {
                if (HasHeldItem(attacker, ITEM_SCOPE_LENS)) {
                    critOdds += gUnknown_80F4DAE;
                    gDungeon->unk134.unk164 = 1;
                }
                if (HasHeldItem(target, ITEM_PATSY_BAND)) {
                    critOdds += gUnknown_80F4DAE;
                    gDungeon->unk134.unk165 = 1;
                }
                if (r5 && IQSkillIsEnabled(attacker, IQ_TYPE_ADVANTAGE_MASTER)) {
                    critOdds = gUnknown_80F4DB0;
                    gDungeon->unk134.unk169 = 1;
                }
            }
            if (DungeonRandInt(100) < critOdds) {
                sub_800A34C(&unkSp9, &unkSp9, &gUnknown_8106F14);
                dmgStruct->isCrit = TRUE;
            }
        }

        gDungeon->unk134.unk154 = sub_800A048(&unkSp8);
        sub_800A34C(&unkSp8, &unkSp8, &unkSp9);
        {
            // Ugly hack needed to match
            #ifdef NONMATCHING
            s32 arg8_Match;
            #else
            register s32 arg8_Match asm("r2");
            #endif // NONMATCHING

            gDungeon->unk134.unk15C = arg8_Match = arg8;
            ASM_MATCH_TRICK(arg8);
            sub_800A088(&unkSp10, arg8_Match);
            sub_800A34C(&unkSp8, &unkSp8, &unkSp10);
        }

        // ALSO needed to match. unk694 chosen randomly and it worked with matching.
        ASM_MATCH_TRICK(gDungeon->unk694);
        gDungeon->unk134.unk150 = sub_800A048(&unkSp8);
        {
            s32 rnd = DungeonRandInt(0x4000);
            unkSp9.s0 = 0;
            unkSp9.s4 = 0xE000 + rnd;
        }
        sub_800A34C(&unkSp8, &unkSp8, &unkSp9);
        sub_800A020(&unkSp11, 100);

        sub_800A34C(&unkSp9, &unkSp11, &unkSp9);
        gDungeon->unk134.unk158 = sub_800A048(&unkSp9);

        dmgStruct->dmg = sub_800A048(&unkSp8);
        dmgStruct->residualDmgType = 0;
        if (dmgStruct->dmg == 0) {
            dmgStruct->isCrit = FALSE;
        }
    }
}

void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct)
{
    struct unkStruct_80943A8 unkSp1;
    struct unkStruct_80943A8 unkSp2;
    s32 a2New = a2;

    if (a2New <= 0) a2New = 1;
    if (a2New > 999) a2New = 999;

    dmgStruct->type = moveType;
    sub_806E100(&unkSp1, attacker, target, moveType, dmgStruct);
    sub_800A020(&unkSp2, a2New);
    sub_800A34C(&unkSp2, &unkSp2, &unkSp1);
    dmgStruct->dmg = sub_800A048(&unkSp2);
    dmgStruct->residualDmgType = 0;
}

void DealDamageToEntity(Entity *entity, s32 dmg, s32 r6, s16 r4)
{
    Entity spEntity;
    struct DamageStruct dmgStruct;
    s32 r4_ = r4;

    sub_80457DC(&spEntity);
    dmgStruct.dmg = dmg;
    dmgStruct.typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    dmgStruct.type = TYPE_NONE;
    dmgStruct.residualDmgType = r6;
    dmgStruct.isCrit = FALSE;
    dmgStruct.unkE = 0;
    dmgStruct.unkF = 0;
    HandleDealingDamage(&spEntity, entity, &dmgStruct, FALSE, FALSE, r4_, FALSE, 0);
}

void sub_806F370(Entity *pokemon, Entity *target, s32 dmg, s32 r9, u8 *arg_0, u8 moveType, s16 arg_8, s32 arg_C, s32 arg_10, s32 arg_14)
{
    s32 i;
    struct DamageStruct dmgStruct;
    s32 arg_8_ = arg_8;
    s32 dmgNew = dmg;

    dmgStruct.typeEffectiveness = EFFECTIVENESS_NEUTRAL;
    dmgStruct.residualDmgType = arg_C;
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
        if (HasAbility(target, ABILITY_WONDER_GUARD)) {
            if (gUnknown_80F54B4[typeEffectiveness[0]][typeEffectiveness[1]] != EFFECTIVENESS_SUPER) {
                dmgNew = 0;
            }
        }
    }

    dmgStruct.dmg = dmgNew;
    if (dmgNew == 0) {
        dmgStruct.unkF = 1;
    }
    else {
        dmgStruct.unkF = 0;
    }

    HandleDealingDamage(pokemon, target, &dmgStruct, FALSE, r9, arg_8_, arg_10, arg_14);
    if (arg_0 != NULL) {
        *arg_0 = dmgStruct.unkF;
    }
}
