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

extern u8 *gUnknown_80FEE04[];
extern u8 *gUnknown_80FEE2C[];
extern u8 *gUnknown_80FEE54[];

void sub_8042940(Entity *r0);
void sub_80428B0(Entity *r0);
void sub_80428C4(Entity *r0);

void sub_806E8B0(Entity * pokemon, Entity * target, u8 param_3, s32 *param_4, s32 *param_5, s32 param_6)
{
  bool8 hasNegStatus_pokemon;
  bool8 visFlags_pokemon_1;
  bool8 visFlags_pokemon_2;
  bool8 hasNegStatus_target;
  bool8 visFlags_target;
  s32 iVar3;
  bool32 isNotEnemy;
  EntityInfo * entityInfo;
  EntityInfo * entityInfo_1;
  s32 r7;
  s32 r8;
  s32 r10;
  s32 sp_0x4;
  s32 sp_0x8;

  r7 = 1;
  r8 = 1;
  sp_0x4 = 1;
  sp_0x8 = 1;
  r10 = IsTypePhysical(param_3) == 0;


  if (HasAbility(pokemon, ABILITY_GUTS)) {
    entityInfo = GetEntInfo(pokemon);
    hasNegStatus_pokemon = HasNegativeStatus(pokemon);
    visFlags_pokemon_1 = SetVisualFlags(entityInfo,1,hasNegStatus_pokemon);
    if (hasNegStatus_pokemon) {
      r7 = 2;
    }
    if (visFlags_pokemon_1) {
      sub_80428B0(pokemon);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEE04); // Guts boosted its power
    }
  }

  if ((HasAbility(pokemon, ABILITY_HUGE_POWER)) || (HasAbility(pokemon, ABILITY_PURE_POWER))) {
    entityInfo_1 = GetEntInfo(pokemon);
    iVar3 = 0;
    if ((param_6 < 0x21) && (!r10)) {
      iVar3 = 1;
    }
    visFlags_pokemon_2 = SetVisualFlags(entityInfo_1,0x100,iVar3);
    if (iVar3 != 0) {
      r7 *= 3;
      r8 <<= 1;
    }
    if (visFlags_pokemon_2) {
      sub_80428C4(pokemon);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEE2C); // It's special ability boosted Attack
    }
  }

  if ((HasAbility(pokemon, ABILITY_HUSTLE)) && (!r10)) {
    r7 *= 3;
    r8 <<= 1;
  }

  if(GetEntInfo(pokemon)->isNotTeamMember)
  {
      isNotEnemy = FALSE;
  }
  else
  {
      isNotEnemy = TRUE;
  }

  if ((HasAbility(pokemon, ABILITY_PLUS)) && (r10 == 1) && gDungeon->minusIsActive[isNotEnemy]) {
    r7 *= 15;
    r8 *= 10;
  }

  // ABILITY_MINUS
  if ((HasAbility(pokemon, ABILITY_MINUS)) && (r10 == 1) && gDungeon->plusIsActive[isNotEnemy]) {
    r7 *= 15;
    r8 *= 10;
  }

  if (HasAbility(target, ABILITY_INTIMIDATE) && (!r10)) {
    r7 <<= 2;
    r8 *= 5;
  }

  if ((HasAbility(target, ABILITY_MARVEL_SCALE)) && (!r10)) {
    entityInfo = GetEntInfo(target);
    hasNegStatus_target = HasNegativeStatus(target);
    visFlags_target = SetVisualFlags(entityInfo, 8, hasNegStatus_target);
    if (hasNegStatus_target) {
      sp_0x4 *= 3;
      sp_0x8 <<= 1;
    }
    if (visFlags_target) {
      sub_8042940(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEE54); // Its special ability quickened attacks!
    }
  }

  *param_4 *= r7;
  *param_5 *= sp_0x4;
  if (r8 != 1) {
    *param_4 = *param_4 / r8;
  }
  if (sp_0x8 != 1) {
    *param_5 = *param_5 / sp_0x8;
  }
}

extern void sub_806F500(void);
extern void sub_800A020(struct unkStruct_80943A8 *param_1, u32 param_2);
extern void sub_800A3F0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *);
extern void sub_800A6D0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *);
extern void sub_800A34C(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, const struct unkStruct_80943A8 *param3);
extern void sub_800A6F0(struct unkStruct_80943A8 *param_1, struct unkStruct_80943A8 *param_2, struct unkStruct_80943A8 *param3);
extern void sub_800A088(struct unkStruct_80943A8 *param_1, u32 param_2);
extern u32 sub_800A048(struct unkStruct_80943A8 *param_1);
extern bool8 sub_800A2F0(const struct unkStruct_80943A8*, struct unkStruct_80943A8*);
extern bool8 sub_806E100(struct unkStruct_80943A8 *param_1, Entity *pokemon, Entity *target, u8 type, struct DamageStruct *dmgStruct);
extern void sub_8041B74(Entity *pokemon);
extern void sub_8041B5C(Entity *pokemon);

extern const s32 gUnknown_80F504C[];
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

void sub_806EAF4(Entity *attacker, Entity *target, u8 moveType, u32 movePower, u32 critChance, struct DamageStruct *dmgStruct, u32 arg_8, u16 moveId, bool8 arg_10)
{
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    bool32 physicalMove = (IsTypePhysical(moveType) != FALSE);

    sub_806F500();
    if (!attackerInfo->isTeamLeader && FixedPointToInt(attackerInfo->belly) == 0) {
        dmgStruct->dmg = 1;
        dmgStruct->residualDmgType = 0;
        dmgStruct->typeEffectiveness = EFFECTIVENESS_NEUTRAL;
        dmgStruct->type = moveType;
        dmgStruct->isCrit = FALSE;
        dmgStruct->unkE = 0;
        dmgStruct->unkF = 0;
    }
    else if (moveId == MOVE_REGULAR_ATTACK && HasAbility(target, ABILITY_WONDER_GUARD)) {
        dmgStruct->dmg = 1;
        dmgStruct->residualDmgType = 0;
        dmgStruct->typeEffectiveness = EFFECTIVENESS_NEUTRAL;
        dmgStruct->type = moveType;
        dmgStruct->isCrit = FALSE;
        dmgStruct->unkE = 0;
        dmgStruct->unkF = 0;
    }
    else {
        s32 atkStatStage, defStatStage;
        s32 atkStatCalc, defStatCalc;
        s32 atkStat, defStat;
        s32 rand;
        struct unkStruct_80943A8 unkSp1;
        struct unkStruct_80943A8 unkSp2;
        struct unkStruct_80943A8 unkSp3;
        s32 r6;
        s32 unkAtkStat2, unkDefStat2;
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
        gDungeon->unk134.unk138 = physicalMove;

        atkStatStage = attackerInfo->offensiveStages[physicalMove];
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
        gDungeon->unk134.unk140[0] = attackerInfo->atk[physicalMove] + movePower;
        atkStatCalc = s24_8_mul((attackerInfo->atk[physicalMove] + movePower) * 256, gUnknown_80F504C[atkStatStage]);
        atkStatCalc = s24_8_mul(atkStatCalc, attackerInfo->offensiveMultipliers[physicalMove]);
        atkStat = atkStatCalc / 8;

        defStatStage = targetInfo->defensiveStages[physicalMove];
        if (targetInfo->charging.chargingStatus == STATUS_SKULL_BASH) {
            gDungeon->unk134.unk17A = 1;
            defStatStage++;
        }
        if (targetInfo->apparentID == MONSTER_DEOXYS_ATTACK) {
            defStatStage -= 2;
        }
        if (targetInfo->apparentID == MONSTER_DEOXYS_DEFENSE) {
            defStatStage += 2;
        }
        if (attackerInfo->apparentID == MONSTER_DEOXYS_SPEED) {
            defStatStage -= 2;
        }

        if (defStatStage < 0) defStatStage = 0;
        if (defStatStage > 20) defStatStage = 20;

        gDungeon->unk134.unk13E[1] = defStatStage;
        gDungeon->unk134.unk140[1] = targetInfo->def[physicalMove];
        defStatCalc = s24_8_mul((targetInfo->def[physicalMove]) * 256, gUnknown_80F504C[defStatStage]);
        defStatCalc = s24_8_mul(defStatCalc, targetInfo->defensiveMultipliers[physicalMove]);
        defStat = defStatCalc / 8;

        rand = DungeonRandInt(100);
        if (physicalMove) {
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
        sub_806E8B0(attacker, target, moveType, &atkStat, &defStat, rand);
        sub_800A020(&unkSp1, atkStat - defStat);
        sub_800A020(&unkSp2, 8);
        sub_800A3F0(&unkSp1, &unkSp1, &unkSp2);
        if (attackerInfo->isNotTeamMember) {
            sub_800A020(&unkSp2, attackerInfo->teamIndex);
            unkSp3.s0 = 0;
            unkSp3.s4 = 0xAAAA;
            sub_800A34C(&unkSp2, &unkSp2, &unkSp3);
            r6 = (attackerInfo->teamIndex * 2) / 3;
        }
        else {
            unkAtkStat2 = attackerInfo->atk[physicalMove];
            unkDefStat2 = 1;
            sub_806E8B0(attacker, target, moveType, &unkAtkStat2, &unkDefStat2, rand);
            sub_800A020(&unkSp2, unkAtkStat2);
            sub_800A020(&unkSp3, 3);
            sub_800A3F0(&unkSp2, &unkSp2, &unkSp3);
            r6 = unkAtkStat2 / 3;
        }
        sub_800A6D0(&unkSp4, &unkSp1, &unkSp2);
        gDungeon->unk134.unk140[5] = r6;
        gDungeon->unk134.unk140[6] = sub_800A048(&unkSp1);
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
        sub_800A6D0(&unkSp8, &unkSp5, &unkSp6);
        if (sub_800A2F0(&gUnknown_8106F24, &unkSp8)) {
            unkSp8 = gUnknown_8106F24;
        }
        if (sub_800A2F0(&gUnknown_8106F04, &unkSp8)) {
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
        if (arg_10 && !physicalMove && targetInfo->protection.protectionStatus == STATUS_REFLECT) {
            sub_8041B74(target);
            sub_800A34C(&unkSp9, &unkSp9, &gUnknown_8106F1C);
            gDungeon->unk134.unk166 = 1;
        }
        if (arg_10 && physicalMove == TRUE && targetInfo->protection.protectionStatus == STATUS_LIGHT_SCREEN) {
            sub_8041B5C(target);
            sub_800A34C(&unkSp9, &unkSp9, &gUnknown_8106F1C);
            gDungeon->unk134.unk167 = 1;
        }
        // Check crit
        if (!HasAbility(target, ABILITY_BATTLE_ARMOR) && !HasAbility(target, ABILITY_SHELL_ARMOR)) {
            s32 critOdds = (attackerInfo->isNotTeamMember) ? critChance : 0;
            if (attackerInfo->moveStatus.moveStatus == STATUS_FOCUS_ENERGY) {
                critOdds = 999;
                gDungeon->unk134.unk168 = 1;
            }
            else {
                if (HasHeldItem(attacker, ITEM_SCOPE_LENS)) {
                    critOdds += gUnknown_80F4DAE;
                    gDungeon->unk134.unk164 = 1;
                }
                if (HasHeldItem(attacker, ITEM_PATSY_BAND)) {
                    critOdds += gUnknown_80F4DAE;
                    gDungeon->unk134.unk165 = 1;
                }
                if (r5 && IQSkillIsEnabled(attacker, IQ_TYPE_ADVANTAGE_MASTER)) {
                    critOdds += gUnknown_80F4DB0;
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
        gDungeon->unk134.unk15C = arg_8;
        sub_800A088(&unkSp10, arg_8);
        sub_800A34C(&unkSp8, &unkSp8, &unkSp10);
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
