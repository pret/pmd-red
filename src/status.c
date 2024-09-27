#include "global.h"
#include "status.h"

#include "code_803E46C.h"
#include "code_8045A00.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_ai_movement.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "math.h"
#include "number_util.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"

extern u8 gAvailablePokemonNames[];
extern u8 gFormatItems[];

extern u8 *gUnknown_80FBD78[];
extern u8 *gUnknown_80FBD9C[];
extern u8 *gUnknown_80FBE40[];
extern u8 *gUnknown_80FBE3C[];
extern u8 *gUnknown_80FBE3C[];
extern u8 *gUnknown_80FC084[];
extern u8 *gUnknown_80FC090[];
extern u8 *gUnknown_80FC1C4[];
extern u8 *gUnknown_80FC218[];
extern u8 *gUnknown_80FD550[];
extern u8 *gUnknown_80FCA60[];
extern u8 *gUnknown_80FC184[];
extern u8 *gUnknown_80FC0B8[];
extern u8 *gUnknown_80FC0C8[];
extern u8 *gUnknown_80FC118[];
extern u8 *gUnknown_80FC11C[];
extern u8 *gUnknown_80FC114[];
extern u8 *gUnknown_80FC180[];
extern u8 *gUnknown_80FC0FC[];
extern u8 *gUnknown_80FC0AC[];
extern u8 *gUnknown_80FC09C[];
extern u8 *gUnknown_80FC1F0[];
extern u8 *gUnknown_80FC1A4[];
extern u8 *gUnknown_80FCA64[];
extern s16 gUnknown_80F4E3C[];
extern u8 *gUnknown_80FCC18[];
extern u8 *gUnknown_80FB2E0[];
extern u8 *gUnknown_80FB300[];
extern s16 gUnknown_80F4E50[];
extern u8 *gUnknown_80FB2CC[];
extern u8 *gUnknown_80FB2AC[];
extern u8 *gUnknown_80FF01C[];
extern u8 *gUnknown_80FCBF8[];
extern s16 gUnknown_80F4E40[];
extern u8 *gUnknown_80FA124[];
extern u8 *gUnknown_80FC2B8[];
extern u8 *gUnknown_80FC298[];
extern u8 *gUnknown_80FC2D8[];
extern u8 *gUnknown_80FC298[];
extern s16 gUnknown_80F4E48[];
extern s16 gUnknown_80F4E4C[];
extern u8 *gUnknown_80FB27C[];
extern u8 *gUnknown_80FB25C[];
extern u8 *gUnknown_80FCDB4[];
extern u8 *gUnknown_80FD500[];
extern s16 gUnknown_80F4ECC[];
extern u8 *gUnknown_80FB960[];
extern u8 *gUnknown_80FB940[];
extern u8 *gUnknown_80FB204[];
extern u8 *gUnknown_80FB240[];
extern u8 *gUnknown_80FB1E0[];
extern u8 *gUnknown_80FB1C4[];
extern u8 *gUnknown_80FB21C[];
extern u8 *gUnknown_80FAEA0[];
extern u8 *gUnknown_80FAEF0[];
extern u8 *gUnknown_80FAF3C[];
extern u8 *gUnknown_80FAEC8[];
extern u8 *gUnknown_80FAF1C[];
extern u8 *gUnknown_80FAFAC[];
extern u8 *gUnknown_80FAFD0[];
extern u8 *gPtrCantLeechSeedSelfMessage[];
extern u8 *gPtrCantLeechSeedMonMessage[];
extern u8 *gUnknown_80FAA8C[];
extern u8 *gUnknown_80FAE58[];
extern u8 *gUnknown_80FAE7C[];
extern s16 gUnknown_80F4EB0[];
extern u8 *gUnknown_80FBB4C[];
extern u8 *gUnknown_80FBB78[];
extern u8 *gUnknown_80FA79C[];
extern s16 gUnknown_80F4EF0[];
extern u8 *gUnknown_80FB73C[];
extern u8 *gUnknown_80FB764[];
extern u8 *gUnknown_80FB780[];
extern u8 *gUnknown_80FB7A0[];
extern s16 gUnknown_80F4EC4[];
extern u8 *gUnknown_80FB8BC[];
extern u8 *gUnknown_80FB8E4[];
extern s16 gUnknown_80F4EC8[];
extern u8 *gUnknown_80FB900[];
extern u8 *gUnknown_80FB924[];
extern u8 *gUnknown_80FB994[];
extern s16 gUnknown_80F4ED0[];
extern u8 *gUnknown_80FB978[];
extern s16 gUnknown_80F4EA4[];
extern u8 *gUnknown_80FB004[];
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4EA8[];
extern u8 *gUnknown_80FB01C[];
extern s16 gUnknown_80F4ED8[];
extern u8 *gUnknown_80FBA14[];
extern u8 *gUnknown_80FB9F0[];
extern u8 *gUnknown_80FBA38[];
extern u8 *gUnknown_80FBA60[];
extern u8 *gUnknown_80FBAA0[];
extern u8 *gUnknown_80FBA80[];
extern s16 gUnknown_80F4EE4[];
extern s16 gUnknown_80F4EEC[];
extern u8 *gUnknown_80FBB04[];
extern u8 *gUnknown_80FBB28[];
extern u8 *gUnknown_80FBBD4[];
extern u8 *gUnknown_80FBBB8[];
extern u8 *gUnknown_80FBB94[];
extern s16 gUnknown_80F4EF4[];

extern s32 gFormatData_202DE30[10];

extern void sub_8041D84(Entity *);
extern void sub_804178C(u32);
extern void sub_8041D5C(Entity *);
extern void RaiseAttackStageTarget(Entity *, Entity *, u32, u32);
extern void RaiseDefenseStageTarget(Entity *, Entity *, u32, u32);
extern void sub_8041D48(Entity *);
extern void sub_8041D38(Entity * pokemon);
extern u8 sub_8043D10(void);
extern void sub_8041CDC(Entity *pokemon);
extern void sub_8041CEC(Entity *pokemon);
extern void nullsub_73(Entity *);
extern void nullsub_74(Entity *);
extern void nullsub_75(Entity *);
extern void nullsub_76(Entity *);
extern void nullsub_77(Entity *);
extern void nullsub_78(Entity *);
extern void nullsub_79(Entity *);
extern void nullsub_80(Entity *);
extern void nullsub_81(Entity *);
extern void nullsub_82(Entity *);
extern void nullsub_83(Entity *);
extern void nullsub_84(Entity *);

extern void sub_8041D9C(Entity *);

extern void sub_803F580(u32);
extern void sub_8040A84(void);
extern void sub_8041CA8(Entity *);
extern void sub_8041C94(Entity *);
extern bool8 sub_8045888(Entity *r0);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern void sub_8041BF8(Entity *);
extern void sub_8041BE8(Entity *);
extern void sub_8041CCC(Entity *);
extern void sub_8041CB8(Entity *r0);
extern void sub_8041C1C(Entity *r0);
extern void sub_8042060(Entity *, s32);
extern bool8 sub_8071728(Entity * param_1, Entity * param_2, u8 param_3);
extern void sub_8041FB4(Entity *r0, u32 r1);
extern void sub_8041FD8(Entity *r0, u32 r1);
extern void sub_80522F4(Entity *r1, Entity *r2, u8 *);
extern void sub_804201C(Entity *r0, u32 r1);
extern void sub_8041FFC(Entity *r0, u32 r1);
extern void sub_8041C58(Entity *r0);
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042040(Entity *, s32);
extern void sub_80420A0(Entity *);

u8 GetFlashFireStatus(Entity *pokemon)
{
    if (!EntityExists(pokemon) || !HasAbility(pokemon, ABILITY_FLASH_FIRE))
    {
        return FLASH_FIRE_STATUS_NONE;
    }
    if (pokemon->axObj.info->flashFireBoost > 1)
    {
        return FLASH_FIRE_STATUS_MAXED;
    }
    return FLASH_FIRE_STATUS_NOT_MAXED;
}

static inline s32 UpdateFlashFireBoost_sub(EntityInfo * entityInfo)
{
    s32 flashFireBoost;

    flashFireBoost = entityInfo->flashFireBoost;
    flashFireBoost++;
    if (FLASH_FIRE_STATUS_MAXED < flashFireBoost) {
      flashFireBoost = FLASH_FIRE_STATUS_NOT_MAXED;
    }
    return flashFireBoost;
}

void UpdateFlashFireBoost(Entity * pokemon, Entity *target)
{
  EntityInfo * entityInfo;
  EntityInfo * entityInfo_1;
  s32 flashFireBoost;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    entityInfo_1 = entityInfo;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    flashFireBoost = UpdateFlashFireBoost_sub(entityInfo);
    if (entityInfo_1->flashFireBoost != flashFireBoost) {
      entityInfo_1->flashFireBoost = flashFireBoost;
      sub_8041C58(target);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ChangeAttackMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s32 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s32 oldMulti;

  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_ATK) {
    strcpy(gFormatItems,*gUnknown_80FC0C8);
  }
  else {
    strcpy(gFormatItems,*gUnknown_80FC0B8);
  }
  if ((param_4 < 0x100) && sub_8071728(pokemon,target,displayMessage)) {
    return;
  }

  if ((HasHeldItem(target,ITEM_TWIST_BAND)) && (param_4 < 0x100)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FD550);
    return;
  }

  if (HasAbility(target, ABILITY_HYPER_CUTTER) && (statStage == STAT_STAGE_ATK) && (param_4 < 0x100)) {
    if (displayMessage) {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_80522F4(pokemon,target,*gUnknown_80FCA60);
    }
    return;
  }

  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  oldMulti = entityInfo->offensiveMultipliers[statStage];

  if (param_4 < 0x100) {
    sub_8041FD8(target,statStage);
  }
  else {
    sub_8041FB4(target,statStage);
  }

  entityInfo->offensiveMultipliers[statStage] = s24_8_mul(entityInfo->offensiveMultipliers[statStage],param_4);

  if (entityInfo->offensiveMultipliers[statStage] < 2) {
    entityInfo->offensiveMultipliers[statStage] = 2;
  }
  if (0x63fd < entityInfo->offensiveMultipliers[statStage]) {
    entityInfo->offensiveMultipliers[statStage] = 0x63fd; // 25597
  }
  if (oldMulti > entityInfo->offensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC11C);
  }
  else if (oldMulti < entityInfo->offensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC118);
  }
  else
  {
    sub_80522F4(pokemon,target,*gUnknown_80FC184);
  }
  EntityUpdateStatusSprites(target);
}

void ChangeDefenseMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s32 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s32 oldMulti;

  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_DEF) {
    strcpy(gFormatItems,*gUnknown_80FC0AC);
  }
  else {
    strcpy(gFormatItems,*gUnknown_80FC09C);
  }
  if ((param_4 < 0x100) && sub_8071728(pokemon,target,displayMessage)) {
    return;
  }

  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  oldMulti = entityInfo->defensiveMultipliers[statStage];

  if (param_4 < 0x100) {
    sub_804201C(target,statStage);
  }
  else {
    sub_8041FFC(target,statStage);
  }

  entityInfo->defensiveMultipliers[statStage] = s24_8_mul(entityInfo->defensiveMultipliers[statStage],param_4);

  if (entityInfo->defensiveMultipliers[statStage] < 2) {
    entityInfo->defensiveMultipliers[statStage] = 2;
  }
  if (0x63fd < entityInfo->defensiveMultipliers[statStage]) {
    entityInfo->defensiveMultipliers[statStage] = 0x63fd; // 25597
  }
  if (oldMulti > entityInfo->defensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC114);
  }
  else if (oldMulti < entityInfo->defensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC0FC);
  }
  else
  {
    sub_80522F4(pokemon,target,*gUnknown_80FC180);
  }
  EntityUpdateStatusSprites(target);
}

void RaiseAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8042040(target,statStage);
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gFormatItems,*gUnknown_80FC090);
    }
    else {
        strcpy(gFormatItems,*gUnknown_80FC084);
    }
    if (entityInfo->hitChanceStages[statStage] < MAX_STAT_STAGE) {
      entityInfo->hitChanceStages[statStage]++;
      sub_80522F4(pokemon,target,*gUnknown_80FC1C4);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC218);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LowerAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gFormatItems,*gUnknown_80FC090);
    }
    else {
        strcpy(gFormatItems,*gUnknown_80FC084);
    }
    if (!sub_8071728(pokemon,target,displayMessage)) {
      if (HasAbility(target, ABILITY_KEEN_EYE) && (statStage == STAT_STAGE_ACCURACY)){
        if(displayMessage)
        {
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FCA64);
        }
      }
      else {
        entityInfo = target->axObj.info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_8042060(target,statStage);
        if (entityInfo->hitChanceStages[statStage] != 0) {
          entityInfo->hitChanceStages[statStage]--;
          sub_80522F4(pokemon,target,*gUnknown_80FC1A4);
        }
        else {
          sub_80522F4(pokemon,target,*gUnknown_80FC1F0);
        }
        EntityUpdateStatusSprites(target);
      }
    }
  }
}

void CringeStatusTarget(Entity * pokemon,Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    if (!HasSafeguardStatus(pokemon, target, displayMessage)) {
      if (HasAbility(target, ABILITY_INNER_FOCUS)){
            SetMessageArgument(gAvailablePokemonNames,target,0);
            if(displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCC18);
      }
      else {
        entityInfo = target->axObj.info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if(entityInfo->volatileStatus.volatileStatus != STATUS_CRINGE)
        {
            entityInfo->volatileStatus.volatileStatus = STATUS_CRINGE;
            entityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E3C, TRUE) +  1;
            sub_80420A0(target);
            sub_80522F4(pokemon,target,*gUnknown_80FB2E0);
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FB300);
        }
        EntityUpdateStatusSprites(target);
      }
    }
  }
}

void ParalyzeStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  struct Tile *mapTile;
  EntityInfo *entityInfo;
  Entity *mapPokemonEntity;
  int index;
  bool8 bVar6;
  bool8 bVar7;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    if (HasAbility(target, ABILITY_LIMBER)) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (displayMessage) {
        sub_80522F4(pokemon,target,*gUnknown_80FCBF8);
      }
    }
    else
    {
      bVar6 = TRUE;
      entityInfo = target->axObj.info;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (entityInfo->nonVolatile.nonVolatileStatus != STATUS_PARALYSIS) {
        entityInfo->nonVolatile.nonVolatileStatus = STATUS_PARALYSIS;
        entityInfo->nonVolatile.nonVolatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E50,TRUE) + 1;
        entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = 0;
        entityInfo->nonVolatile.unk4 = 0;
        bVar6 = FALSE;
        sub_80522F4(pokemon,target,*gUnknown_80FB2AC);
        sub_8041C1C(target);
        CalcSpeedStage(target);
      }
      else {
        sub_80522F4(pokemon,target,*gUnknown_80FB2CC);
      }
      if ((HasAbility(target, ABILITY_SYNCHRONIZE)) && (!bVar6)) {
        bVar7 = FALSE;

        for(index = 0; index < NUM_DIRECTIONS; index++)
        {
          mapTile = GetTile(target->pos.x + gAdjacentTileOffsets[index].x,target->pos.y + gAdjacentTileOffsets[index].y);
          mapPokemonEntity = mapTile->monster;
          if ((EntityExists(mapPokemonEntity)) && (GetEntityType(mapPokemonEntity) == ENTITY_MONSTER)) {
            if (!bVar7) {
              bVar7 = TRUE;
              SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
              sub_80522F4(pokemon,target,*gUnknown_80FF01C);
            }
            if (sub_807167C(target,mapPokemonEntity) == 1) {
              ParalyzeStatusTarget(pokemon, mapPokemonEntity, displayMessage);
            }
          }
        }
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void RaiseMovementSpeedTarget(Entity * pokemon, Entity * target, s32 turns, bool8 displayMessage)
{
  s32 movSpeed;
  s32 index;
  s32 movSpeed_1;
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  if (turns == 0) {
    turns = CalculateStatusTurns(target,gUnknown_80F4E40,FALSE) + 1;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  movSpeed = CalcSpeedStage(target);
  if (movSpeed == MAX_SPEED_STAGE) {
    if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FC2B8);
  }
  else {
    for(index = 0; index < NUM_SPEED_COUNTERS; index++)
    {
        if(entityInfo->speedUpCounters[index]  == 0)
        {
            entityInfo->speedUpCounters[index]  = turns;
            break;
        }
    }
    movSpeed_1 = CalcSpeedStage(target);
    if (movSpeed == movSpeed_1) {
        sub_80522F4(pokemon,target,*gUnknown_80FC298);
    }
    else
    {
        sub_8041CB8(target);
        sub_80522F4(pokemon,target,gUnknown_80FA124[movSpeed_1]);
        entityInfo->speedStageChanged = TRUE;
        entityInfo->attacking = FALSE;
    }
  }
  EntityUpdateStatusSprites(target);
}

void LowerMovementSpeedTarget(Entity * pokemon, Entity * target, s32 levels, bool8 displayMessage)
{
  s32 movSpeed;
  s32 counter;
  s32 index;
  s32 movSpeed_1;
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  if (HasSafeguardStatus(pokemon,target,displayMessage)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  movSpeed = CalcSpeedStage(target);
  if (movSpeed == 0) {
    if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FC2D8);
  }
  else {
    for(counter = 0; counter < levels; counter++)
    {
        for(index = 0; index < NUM_SPEED_COUNTERS; index++)
        {
            if (entityInfo->speedDownCounters[index]== 0) {
                entityInfo->speedDownCounters[index] = CalculateStatusTurns(target,gUnknown_80F4E48,TRUE) + 1;
                break;
            }
        }
    }
    movSpeed_1 = CalcSpeedStage(target);
    if (movSpeed == movSpeed_1) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FC298);
    }
    else
    {
        sub_8041CCC(target);
        sub_80522F4(pokemon,target,gUnknown_80FA124[movSpeed_1]);
    }
  }
  EntityUpdateStatusSprites(target);
}

void ConfuseStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }

  if (HasSafeguardStatus(pokemon,target,displayMessage)) {
    return;
  }

  SetMessageArgument(gAvailablePokemonNames,target,0);
  if (HasHeldItem(target,ITEM_PERSIM_BAND)) {
    if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FD500);
  }
  else
  {
    if (HasAbility(target, ABILITY_OWN_TEMPO)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCDB4);
    }
    else
    {
      sub_8041BE8(target);
      entityInfo = target->axObj.info;
      if (entityInfo->volatileStatus.volatileStatus != STATUS_CONFUSED) {
        entityInfo->volatileStatus.volatileStatus = STATUS_CONFUSED;
        entityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E4C,TRUE) + 1;
        sub_80522F4(pokemon,target,*gUnknown_80FB25C);
      }
      else {
        sub_80522F4(pokemon,target,*gUnknown_80FB27C);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void CowerStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->volatileStatus.volatileStatus != STATUS_COWERING) {
      entityInfo->volatileStatus.volatileStatus = STATUS_COWERING;
      entityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ECC,TRUE) + 1;
      sub_8041BF8(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB940);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB960);
    }
    EntityUpdateStatusSprites(target);
  }
}

void HealTargetHP(Entity *pokemon, Entity *target, s32 param_3, s32 param_4, bool32 displayMessage)
{
    EntityInfo *entityInfo;
    s32 HP;
    s32 maxHPStat;
    s32 r8;
    u8 displayMessage_u8;

    displayMessage_u8 = displayMessage;

    if (!EntityExists(target)) {
        return;
    }

    entityInfo = target->axObj.info;
    maxHPStat = entityInfo->maxHPStat;
    HP = entityInfo->HP;
    if (((entityInfo->HP == entityInfo->maxHPStat) && (0 < param_4)) || (param_3 == 0)) {
        entityInfo->maxHPStat += param_4;
        entityInfo->HP += param_4;
        if (entityInfo->maxHPStat > 999) {
            entityInfo->maxHPStat = 999;
        }
        if (entityInfo->HP > entityInfo->maxHPStat) {
            entityInfo->HP = entityInfo->maxHPStat;
        }
        if (entityInfo->HP == entityInfo->maxHPStat) {
            HP = entityInfo->HP;
        }
        sub_8041C94(target);
    }
    else {
        entityInfo->HP += param_3;
        if (entityInfo->HP > entityInfo->maxHPStat) {
            entityInfo->HP = entityInfo->maxHPStat;
        }
        sub_8041CA8(target);
    }
    maxHPStat = entityInfo->maxHPStat - maxHPStat;
    HP = entityInfo->HP - HP;
    EntityUpdateStatusSprites(target);
    gFormatData_202DE30[0] = HP;
    gFormatData_202DE30[1] = maxHPStat;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if ((HP == 0) && (maxHPStat == 0)) {
        if (displayMessage_u8)
            sub_80522F4(pokemon,target,*gUnknown_80FB204); // $m0's HP remained unchanged
    }
    else if ((param_4 == 0) && (HP == 0))
    {
        if (displayMessage_u8)
            sub_80522F4(pokemon,target,*gUnknown_80FB21C); // $m0 has full HP
    }
    else
    {
        r8 = 0;
        if (maxHPStat != 0) {
            if (sub_8045888(target)) {
                r8 = maxHPStat;
            }
            sub_80522F4(pokemon,target,*gUnknown_80FB240); // m0$'s max HP rose by {ARG_VALUE_1}
        }
        if (HP != 0) {
            if (sub_8045888(target)) {
                r8 = HP;
            }
            if (param_3 != 0) {
                if (entityInfo->maxHPStat == entityInfo->HP) {
                    sub_80522F4(pokemon,target,*gUnknown_80FB1E0); // $m0 was fully healed
                }
                else {
                    sub_80522F4(pokemon,target,*gUnknown_80FB1C4); // $m0 recovered {ARG_VALUE_0} HP
                }
            }
        }
        if (r8)
            sub_803ED30(r8,target,1,-1);
    }
}

void HandleScannerOrb(Entity* pokemon, Entity* target)
{
  if (EntityExists(target)) {
    if (target->axObj.info->scanning) {
        sub_80522F4(pokemon,target,*gUnknown_80FAEF0); // Item locations are already known
    }
    else
    {
        target->axObj.info->scanning = TRUE;
        nullsub_75(target);
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        sub_80522F4(pokemon,target,*gUnknown_80FAEA0); // Item locations became evident
        sub_803F580(0);
        sub_8040A84();
        EntityUpdateStatusSprites(target);
    }
  }
}

void HandleStairsOrb(Entity* pokemon, Entity* target)
{
  if (EntityExists(target)) {
    if(sub_8043D10())
    {
        sub_80522F4(pokemon,target,*gUnknown_80FAF3C);
    }
    else
    {
        if (target->axObj.info->stairSpotter) {
            sub_80522F4(pokemon,target,*gUnknown_80FAF1C);
        }
        else
        {
            target->axObj.info->stairSpotter = TRUE;
            nullsub_76(target);
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FAEC8);
            sub_803F580(0);
            sub_8040A84();
            EntityUpdateStatusSprites(target);
        }
    }
  }
}

void HandleRadarOrb(Entity* pokemon, Entity* target)
{
  if (EntityExists(target)) {
    if (target->axObj.info->powerEars != 0) {
        sub_80522F4(pokemon,target,*gUnknown_80FAFD0);
    }
    else
    {
        target->axObj.info->powerEars = TRUE;
        nullsub_77(target);
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_80522F4(pokemon,target,*gUnknown_80FAFAC);
        sub_803F580(0);
        sub_8040A84();
        EntityUpdateStatusSprites(target);
    }
  }
}

void HandleLeechSeed(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;
  s32 index;

  if ((EntityExists(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) {
    entityInfo = target->axObj.info;
    if (pokemon == target) {
      pokemon = target;
      if (displayMessage)
        sub_80522F4(pokemon,target,*gPtrCantLeechSeedSelfMessage);
    }
    else {
      if (HasSafeguardStatus(pokemon,target,displayMessage)) {
        return;
      }
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (MonsterIsType(target, TYPE_GRASS)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gPtrCantLeechSeedMonMessage);
      }
      else
        {
            switch(entityInfo->linked.linkedStatus)
            {
                case STATUS_DESTINY_BOND:
                    sub_80522F4(pokemon,target,*gUnknown_80FAA8C);
                default:
                    entityInfo->linked.linkedStatus = STATUS_LEECH_SEED;
                    entityInfo->linked.linkedStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EB0, TRUE) + 1;
                    entityInfo->linked.linkedStatusDamageCountdown = 0;
                    nullsub_78(target);
                    entityInfo->linked.unkD8 = 0xff;
                    break;
                case STATUS_LEECH_SEED:
                    sub_80522F4(pokemon,target,*gUnknown_80FAE7C);
                    return;
            }
            for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
            {
                if (pokemon == gDungeon->allPokemon[index]) {
                    entityInfo->linked.unkD8 = index;
                    entityInfo2 = pokemon->axObj.info;
                    entityInfo->linked.unkD4 = entityInfo2->unk98;
                }
            }
            sub_80522F4(pokemon,target,*gUnknown_80FAE58);
            EntityUpdateStatusSprites(target);
        }
      }
    }
  }

void sub_8078084(Entity * pokemon)
{
    EntityInfo *entityInfo;
    EntityInfo *entityInfo2;
    Entity *target;
    s32 index;

    entityInfo = pokemon->axObj.info;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        target = gDungeon->allPokemon[index];
        if (EntityExists(target)) {
            entityInfo2 = target->axObj.info;
            if((u8)(entityInfo2->linked.linkedStatus - 1) <= 1)
            {
                if(entityInfo2->linked.unkD4 == entityInfo->unk98)
                {
                    entityInfo2->linked.linkedStatus = STATUS_NONE;
                    EntityUpdateStatusSprites(target);
                }
            }
        }
    }
  }

void DestinyBondStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;
  s32 index;
  u8 *linkedStatus;
  s32 zero;

  if (((EntityExists(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) &&
     (GetEntityType(target) == ENTITY_MONSTER)) {
        entityInfo = pokemon->axObj.info;
        SetMessageArgument(gAvailablePokemonNames,pokemon,0);
        linkedStatus = &entityInfo->linked.linkedStatus;
        if (entityInfo->linked.linkedStatus != STATUS_DESTINY_BOND)
        {
            if (entityInfo->linked.linkedStatus == STATUS_LEECH_SEED)
                sub_80522F4(pokemon,target,*gUnknown_80FA79C);
            zero = 0;
            *linkedStatus = STATUS_DESTINY_BOND;
            entityInfo->linked.linkedStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EF0,TRUE) + 1;
            entityInfo->linked.linkedStatusDamageCountdown = zero;
            nullsub_74(target);
            entityInfo->linked.unkD8 = 0xff;
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FBB78);
            return;
        }
        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
            if (target == gDungeon->allPokemon[index]) {
                entityInfo->linked.unkD8 = index;
                entityInfo2 = target->axObj.info;
                entityInfo->linked.unkD4 = entityInfo2->unk98;
            }
        }
        sub_80522F4(pokemon,target,*gUnknown_80FBB4C);
        EntityUpdateStatusSprites(target);
    }
}

void SureShotStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->moveStatus.moveStatus != STATUS_SURE_SHOT) {
      entityInfo->moveStatus.moveStatus = STATUS_SURE_SHOT;
      entityInfo->moveStatus.moveStatusTurns = turns + 1;
      sub_8041CDC(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB73C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB764);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WhifferStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->moveStatus.moveStatus != STATUS_WHIFFER) {
      entityInfo->moveStatus.moveStatus = STATUS_WHIFFER;
      entityInfo->moveStatus.moveStatusTurns = turns + 1;
      sub_8041CEC(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB780);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB7A0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FixedDamageStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->moveStatus.moveStatus != STATUS_SET_DAMAGE) {
      entityInfo->moveStatus.moveStatus = STATUS_SET_DAMAGE;
      entityInfo->moveStatus.moveStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EC4, FALSE) + 1;
      nullsub_79(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB8BC);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB8E4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FocusEnergyStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->moveStatus.moveStatus != STATUS_FOCUS_ENERGY) {
      entityInfo->moveStatus.moveStatus = STATUS_FOCUS_ENERGY;
      entityInfo->moveStatus.moveStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EC8, FALSE) + 1;
      nullsub_80(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB900);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB924);
    }
    EntityUpdateStatusSprites(target);
  }
}

void sub_80783C4(Entity * pokemon, Entity * target, u8 param_3)
{
  EntityInfo *targetEntityInfo;
  EntityInfo *entityInfo;
  Entity * entity;
  Entity * entity2;
  ActionContainer action;
  s32 index;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    targetEntityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityInfo->waitingStruct.waitingStatus == STATUS_DECOY) {
      sub_80522F4(pokemon,target,*gUnknown_80FB994);
    }
    else {
      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity = gDungeon->allPokemon[index];
        if ((((EntityExists(entity)) && (target != entity)) &&
           (u8)(entity->axObj.info->waitingStruct.waitingStatus - 2U) < 2)) {
          SendWaitingEndMessage(pokemon,entity,STATUS_NONE);
          sub_803E46C(0x2a);
        }
      }
      sub_8041D38(target);
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (targetEntityInfo->waitingStruct.waitingStatus != STATUS_NONE) {
        SendWaitingEndMessage(pokemon,target, STATUS_DECOY);
      }
      targetEntityInfo->waitingStruct.waitingStatus = STATUS_DECOY;
      targetEntityInfo->waitingStruct.enemyDecoy = pokemon->axObj.info->isNotTeamMember;
      targetEntityInfo->waitingStruct.unkCA = param_3;
      targetEntityInfo->waitingStruct.waitingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ED0,TRUE) + 1;
      targetEntityInfo->waitingStruct.curseDamageCountdown = 0;
      sub_806CCB4(target,sub_806CEBC(target));
      gDungeon->decoyActive = TRUE;
      sub_80522F4(pokemon,target,*gUnknown_80FB978);

      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity2 = gDungeon->allPokemon[index];
        if (EntityExists(entity2)) {
          entityInfo = entity2->axObj.info;
          entityInfo->aiTarget.aiObjective = AI_STAND_STILL;
          entityInfo->aiTarget.aiTarget = NULL;
          entityInfo->aiTarget.aiTargetSpawnGenID = 0;
          if (!entityInfo->isTeamLeader) {
            action = entityInfo->action;
            MoveIfPossible(entity2, TRUE);
            entityInfo->action = action;
          }
        }
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void CurseStatusTarget(Entity *pokemon, Entity * target)
{
  u32 statStage;
  s32 HP;
  EntityInfo * pokemonEntityData;
  EntityInfo * targetEntityInfo;


  if ((EntityExists(pokemon) ) && (EntityExists(target))) {
    pokemonEntityData = pokemon->axObj.info;
    targetEntityInfo = target->axObj.info;
    if (MonsterIsType(pokemon, TYPE_GHOST)) {
        if (HasSafeguardStatus(pokemon,target, TRUE)) {
            return;
      }
      SendWaitingEndMessage(pokemon,target,STATUS_CURSED);
      sub_8041D48(target);
      HP = pokemonEntityData->HP / 2;
      pokemonEntityData->HP = HP;
      if (HP == 0) {
        pokemonEntityData->HP = 1;
      }
      if (targetEntityInfo->waitingStruct.waitingStatus != STATUS_CURSED) {
        targetEntityInfo->waitingStruct.waitingStatus = STATUS_CURSED;
        targetEntityInfo->waitingStruct.waitingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EA4,TRUE) + 1;
        targetEntityInfo->waitingStruct.curseDamageCountdown = 0;
      }
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FB004);
    }
    else {
      statStage = gUnknown_8106A4C;
      RaiseAttackStageTarget(pokemon,pokemon,statStage,1);
      RaiseDefenseStageTarget(pokemon,pokemon,statStage,1);
      LowerMovementSpeedTarget(pokemon,pokemon,1,TRUE);
    }
    EntityUpdateStatusSprites(target);
  }
}

void SnatchStatusTarget(Entity * pokemon, Entity * target)
{
  Entity * entity;
  s32 index;
  EntityInfo * targetEntityInfo;
  EntityInfo * targetEntityInfo2;

  if (EntityExists(target)) {
    SendWaitingEndMessage(pokemon,target,STATUS_SNATCH);

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->allPokemon[index];
      if ((EntityExists(entity)) && (entity->axObj.info->waitingStruct.waitingStatus == STATUS_SNATCH)) {
        SendWaitingEndMessage(pokemon, entity, STATUS_NONE);
      }
    }
    nullsub_81(target);

    targetEntityInfo = target->axObj.info;
    targetEntityInfo2 = targetEntityInfo;
    if (targetEntityInfo->waitingStruct.waitingStatus != STATUS_SNATCH) {
      targetEntityInfo->waitingStruct.waitingStatus = STATUS_SNATCH;
      targetEntityInfo->waitingStruct.waitingStatusTurns= CalculateStatusTurns(target,gUnknown_80F4EA8,FALSE) + 1;
      targetEntityInfo->waitingStruct.curseDamageCountdown = 0;
    }

    gDungeon->snatchPokemon = target;
    gDungeon->unk17B3C = targetEntityInfo2->unk98;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB01C);
    EntityUpdateStatusSprites(target);
  }
}

void TauntStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->volatileStatus.volatileStatus != STATUS_TAUNTED) {
      entityInfo->volatileStatus.volatileStatus = STATUS_TAUNTED;
      entityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ED8,TRUE) + 1;
      nullsub_73(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB9F0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBA14);
    }
    EntityUpdateStatusSprites(target);
  }
}

void HandleStockpile(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->stockpileStage < MAX_STOCKPILE_STAGE) {
      entityInfo->stockpileStage++;
      sub_804178C(1);
      sub_8041D5C(target);
      gFormatData_202DE30[0] = entityInfo->stockpileStage;
      sub_80522F4(pokemon,target,*gUnknown_80FBA38);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBA60);
    }
    EntityUpdateStatusSprites(target);
  }
}

void InvisibleStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * targetEntityInfo;
  EntityInfo * targetEntityInfo_1;

  if (EntityExists(target)) {
    targetEntityInfo = target->axObj.info;
    targetEntityInfo_1 = targetEntityInfo;
    if (targetEntityInfo_1->transformStatus.transformStatus == STATUS_TRANSFORMED) {
      SendTransformEndMessage(pokemon,target);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityInfo_1->transformStatus.transformStatus != STATUS_INVISIBLE) {
      targetEntityInfo_1->transformStatus.transformStatus = STATUS_INVISIBLE;
      targetEntityInfo_1->transformStatus.transformStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EE4,FALSE) + 1;
      sub_8041D84(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBA80);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBAA0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void PerishSongTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * entityInfo;

  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    nullsub_82(target);
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->perishSongTurns == 0) {
      entityInfo->perishSongTurns = CalculateStatusTurns(target,gUnknown_80F4EEC,FALSE) + 1;
      sub_80522F4(pokemon,target,*gUnknown_80FBB04);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBB28);
    }
    EntityUpdateStatusSprites(target);
  }
}

void EncoreStatusTarget(Entity *pokemon,Entity *target)
{
  Move *movePtr;
  int index;
  EntityInfo *EntityInfo;

  EntityInfo = target->axObj.info;
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &EntityInfo->moves[index];
      if ((EntityInfo->moves[index].moveFlags & MOVE_FLAG_EXISTS) && (movePtr->moveFlags & MOVE_FLAG_LAST_USED)) break;
    }
    if ((index == MAX_MON_MOVES) && ((EntityInfo->struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0)) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FBBD4);
    }
    else {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (EntityInfo->volatileStatus.volatileStatus != STATUS_ENCORE) {
        EntityInfo->volatileStatus.volatileStatus = STATUS_ENCORE;
        EntityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EF4,TRUE) + 1;
        nullsub_83(target);
        sub_80522F4(pokemon,target,*gUnknown_80FBB94);
      }
      else {
        sub_80522F4(pokemon,target,*gUnknown_80FBBB8);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void sub_8078A58(struct Entity *pokemon, struct Entity *target, s32 param_3, s32 param_4)
{
    struct EntityInfo *targetInfo;
    FixedPoint bellyBefore;

    if (!EntityExists(target))
        return;

    targetInfo = target->axObj.info;

    if (param_4 != 0) {
        FixedPoint sp0 = IntToFixedPoint(param_4);
        bellyBefore = targetInfo->maxBelly;
        targetInfo->maxBelly = FixedPoint_Subtract(bellyBefore, sp0);
        targetInfo->belly = FixedPoint_Min(targetInfo->belly, targetInfo->maxBelly);
        SetMessageArgument(gAvailablePokemonNames, target, 0);

        if (FixedPointToInt(bellyBefore) != FixedPointToInt(targetInfo->maxBelly)) {
            sub_8041D9C(target);
            sub_80522F4(pokemon, target, *gUnknown_80FBD9C);
        }
        else
            sub_80522F4(pokemon, target, *gUnknown_80FBE3C);
    }
    else {
        FixedPoint sp8 = IntToFixedPoint(param_3);
        bellyBefore = targetInfo->belly;
        targetInfo->belly = FixedPoint_Subtract(bellyBefore, sp8);

        SetMessageArgument(gAvailablePokemonNames, target, 0);

        if (FixedPointToInt(bellyBefore) != FixedPointToInt(targetInfo->belly)) {
            nullsub_84(target);
            sub_80522F4(pokemon, target, *gUnknown_80FBD78);
        }
        else
            sub_80522F4(pokemon, target, *gUnknown_80FBE40);
    }

    EntityUpdateStatusSprites(target);
}
