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
#include "dungeon_message.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "number_util.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "dungeon_battle_data.h"

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
extern u8 *gUnknown_80FCC18[];
extern u8 *gUnknown_80FB2E0[];
extern u8 *gUnknown_80FB300[];
extern u8 *gUnknown_80FB2CC[];
extern u8 *gUnknown_80FB2AC[];
extern u8 *gUnknown_80FF01C[];
extern u8 *gUnknown_80FCBF8[];
extern u8 *gUnknown_80FA124[];
extern u8 *gUnknown_80FC2B8[];
extern u8 *gUnknown_80FC298[];
extern u8 *gUnknown_80FC2D8[];
extern u8 *gUnknown_80FC298[];
extern u8 *gUnknown_80FB27C[];
extern u8 *gUnknown_80FB25C[];
extern u8 *gUnknown_80FCDB4[];
extern u8 *gUnknown_80FD500[];
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
extern u8 *gUnknown_80FBB4C[];
extern u8 *gUnknown_80FBB78[];
extern u8 *gUnknown_80FA79C[];
extern u8 *gUnknown_80FB73C[];
extern u8 *gUnknown_80FB764[];
extern u8 *gUnknown_80FB780[];
extern u8 *gUnknown_80FB7A0[];
extern u8 *gUnknown_80FB8BC[];
extern u8 *gUnknown_80FB8E4[];
extern u8 *gUnknown_80FB900[];
extern u8 *gUnknown_80FB924[];
extern u8 *gUnknown_80FB994[];
extern u8 *gUnknown_80FB978[];
extern u8 *gUnknown_80FB004[];
extern u32 gUnknown_8106A4C;
extern u8 *gUnknown_80FB01C[];
extern u8 *gUnknown_80FBA14[];
extern u8 *gUnknown_80FB9F0[];
extern u8 *gUnknown_80FBA38[];
extern u8 *gUnknown_80FBA60[];
extern u8 *gUnknown_80FBAA0[];
extern u8 *gUnknown_80FBA80[];
extern u8 *gUnknown_80FBB04[];
extern u8 *gUnknown_80FBB28[];
extern u8 *gUnknown_80FBBD4[];
extern u8 *gUnknown_80FBBB8[];
extern u8 *gUnknown_80FBB94[];
extern u8 *gUnknown_80FBE84[];
extern u8 *gUnknown_80FBEA0[];
extern u8 *gUnknown_80FBE64[];
extern u8 *gUnknown_80FBDF0[];
extern u8 *gUnknown_80FBDC4[];
extern u8 *gUnknown_80FBE14[];

extern void sub_8041D84(Entity *);
extern void sub_804178C(u32);
extern void sub_8041D5C(Entity *);
extern void sub_8041D48(Entity *);
extern void sub_8041D38(Entity * pokemon);
extern u8 GetFloorType(void);
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
extern void nullsub_85(Entity *);

extern void sub_803F580(u32);
extern void sub_8040A84(void);
extern void sub_8041D9C(Entity *);
extern void sub_8041DB0(Entity *pokemon);
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
extern void sub_8041FB4(Entity *r0, u32 r1);
extern void sub_8041FD8(Entity *r0, u32 r1);
extern void sub_804201C(Entity *r0, u32 r1);
extern void sub_8041FFC(Entity *r0, u32 r1);
extern void sub_8041C58(Entity *r0);
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042040(Entity *, s32);
extern void sub_80420A0(Entity *);

u8 GetFlashFireStatus(Entity *pokemon)
{
    if (!EntityExists(pokemon) || !AbilityIsActive(pokemon, ABILITY_FLASH_FIRE))
    {
        return FLASH_FIRE_STATUS_NONE;
    }
    if (GetEntInfo(pokemon)->flashFireBoost > 1)
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
  s32 flashFireBoost;

  if (EntityExists(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    flashFireBoost = UpdateFlashFireBoost_sub(entityInfo);
    if (entityInfo->flashFireBoost != flashFireBoost) {
      entityInfo->flashFireBoost = flashFireBoost;
      sub_8041C58(target);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ChangeAttackMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s24_8 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s24_8 oldMulti;

  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_ATK) {
    strcpy(gFormatBuffer_Items[0],*gUnknown_80FC0C8);
  }
  else {
    strcpy(gFormatBuffer_Items[0],*gUnknown_80FC0B8);
  }
  if (F248LessThanInt(param_4, 1) && sub_8071728(pokemon,target,displayMessage)) {
    return;
  }

  if ((HasHeldItem(target,ITEM_TWIST_BAND)) && F248LessThanInt(param_4, 1)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD550);
    return;
  }

  if (AbilityIsActive(target, ABILITY_HYPER_CUTTER) && (statStage == STAT_STAGE_ATK) && F248LessThanInt(param_4, 1)) {
    if (displayMessage) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCA60);
    }
    return;
  }

  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  oldMulti = entityInfo->offensiveMultipliers[statStage];

  if (F248LessThanInt(param_4, 1)) {
    sub_8041FD8(target,statStage);
  }
  else {
    sub_8041FB4(target,statStage);
  }

  entityInfo->offensiveMultipliers[statStage] = s24_8_mul(entityInfo->offensiveMultipliers[statStage],param_4);

  if (F248LessThanFloat(entityInfo->offensiveMultipliers[statStage], 0.01)) {
    entityInfo->offensiveMultipliers[statStage] = FloatToF248(0.01);
  }
  if (FloatLessThanF248(99.99, entityInfo->offensiveMultipliers[statStage])) {
    entityInfo->offensiveMultipliers[statStage] = FloatToF248(99.99);
  }
  if (F248GreaterThan(oldMulti, entityInfo->offensiveMultipliers[statStage])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC11C);
  }
  else if (F248LessThan(oldMulti, entityInfo->offensiveMultipliers[statStage])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC118);
  }
  else
  {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC184);
  }
  EntityUpdateStatusSprites(target);
}

void ChangeDefenseMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s24_8 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s24_8 oldMulti;

  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_DEF) {
    strcpy(gFormatBuffer_Items[0],*gUnknown_80FC0AC);
  }
  else {
    strcpy(gFormatBuffer_Items[0],*gUnknown_80FC09C);
  }
  if (F248LessThanInt(param_4, 1) && sub_8071728(pokemon,target,displayMessage)) {
    return;
  }

  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  oldMulti = entityInfo->defensiveMultipliers[statStage];

  if (F248LessThanInt(param_4, 1)) {
    sub_804201C(target,statStage);
  }
  else {
    sub_8041FFC(target,statStage);
  }

  entityInfo->defensiveMultipliers[statStage] = s24_8_mul(entityInfo->defensiveMultipliers[statStage],param_4);

  if (F248LessThanFloat(entityInfo->defensiveMultipliers[statStage], 0.01)) {
    entityInfo->defensiveMultipliers[statStage] = FloatToF248(0.01);
  }
  if (FloatLessThanF248(99.99, entityInfo->defensiveMultipliers[statStage])) {
    entityInfo->defensiveMultipliers[statStage] = FloatToF248(99.99);
  }
  if (F248GreaterThan(oldMulti, entityInfo->defensiveMultipliers[statStage])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC114);
  }
  else if (F248LessThan(oldMulti, entityInfo->defensiveMultipliers[statStage])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC0FC);
  }
  else
  {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC180);
  }
  EntityUpdateStatusSprites(target);
}

void RaiseAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8042040(target,statStage);
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gFormatBuffer_Items[0],*gUnknown_80FC090);
    }
    else {
        strcpy(gFormatBuffer_Items[0],*gUnknown_80FC084);
    }
    if (entityInfo->hitChanceStages[statStage] < MAX_STAT_STAGE) {
      entityInfo->hitChanceStages[statStage]++;
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC1C4);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC218);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LowerAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gFormatBuffer_Items[0],*gUnknown_80FC090);
    }
    else {
        strcpy(gFormatBuffer_Items[0],*gUnknown_80FC084);
    }
    if (!sub_8071728(pokemon,target,displayMessage)) {
      if (AbilityIsActive(target, ABILITY_KEEN_EYE) && (statStage == STAT_STAGE_ACCURACY)){
        if(displayMessage)
        {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCA64);
        }
      }
      else {
        entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        sub_8042060(target,statStage);
        if (entityInfo->hitChanceStages[statStage] != 0) {
          entityInfo->hitChanceStages[statStage]--;
          TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC1A4);
        }
        else {
          TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC1F0);
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
      if (AbilityIsActive(target, ABILITY_INNER_FOCUS)){
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if(displayMessage)
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCC18);
      }
      else {
        entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if(entityInfo->cringeClassStatus.status != STATUS_CRINGE)
        {
            entityInfo->cringeClassStatus.status = STATUS_CRINGE;
            entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target, gCringeTurnRange, TRUE) +  1;
            sub_80420A0(target);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB2E0);
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB300);
        }
        EntityUpdateStatusSprites(target);
      }
    }
  }
}

void ParalyzeStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  const Tile *mapTile;
  EntityInfo *entityInfo;
  Entity *mapPokemonEntity;
  int index;
  bool8 bVar6;
  bool8 bVar7;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    if (AbilityIsActive(target, ABILITY_LIMBER)) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (displayMessage) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCBF8);
      }
    }
    else
    {
      bVar6 = TRUE;
      entityInfo = GetEntInfo(target);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (entityInfo->burnClassStatus.status != STATUS_PARALYSIS) {
        entityInfo->burnClassStatus.status = STATUS_PARALYSIS;
        entityInfo->burnClassStatus.turns = CalculateStatusTurns(target,gParalysisTurnRange,TRUE) + 1;
        entityInfo->burnClassStatus.damageCountdown = 0;
        entityInfo->burnClassStatus.unk4 = 0;
        bVar6 = FALSE;
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB2AC);
        sub_8041C1C(target);
        CalcSpeedStage(target);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB2CC);
      }
      if ((AbilityIsActive(target, ABILITY_SYNCHRONIZE)) && (!bVar6)) {
        bVar7 = FALSE;

        for(index = 0; index < NUM_DIRECTIONS; index++)
        {
          mapTile = GetTile(target->pos.x + gAdjacentTileOffsets[index].x,target->pos.y + gAdjacentTileOffsets[index].y);
          mapPokemonEntity = mapTile->monster;
          if ((EntityExists(mapPokemonEntity)) && (GetEntityType(mapPokemonEntity) == ENTITY_MONSTER)) {
            if (!bVar7) {
              bVar7 = TRUE;
              SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
              TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FF01C);
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
    turns = CalculateStatusTurns(target,gSpeedRaiseTurnRange,FALSE) + 1;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  movSpeed = CalcSpeedStage(target);
  if (movSpeed == MAX_SPEED_STAGE) {
    if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC2B8);
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC298);
    }
    else
    {
        sub_8041CB8(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA124[movSpeed_1]);
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
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  movSpeed = CalcSpeedStage(target);
  if (movSpeed == 0) {
    if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC2D8);
  }
  else {
    for(counter = 0; counter < levels; counter++)
    {
        for(index = 0; index < NUM_SPEED_COUNTERS; index++)
        {
            if (entityInfo->speedDownCounters[index]== 0) {
                entityInfo->speedDownCounters[index] = CalculateStatusTurns(target,gSpeedLowerTurnRange,TRUE) + 1;
                break;
            }
        }
    }
    movSpeed_1 = CalcSpeedStage(target);
    if (movSpeed == movSpeed_1) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC298);
    }
    else
    {
        sub_8041CCC(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA124[movSpeed_1]);
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

  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  if (HasHeldItem(target,ITEM_PERSIM_BAND)) {
    if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD500);
  }
  else
  {
    if (AbilityIsActive(target, ABILITY_OWN_TEMPO)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCDB4);
    }
    else
    {
      sub_8041BE8(target);
      entityInfo = GetEntInfo(target);
      if (entityInfo->cringeClassStatus.status != STATUS_CONFUSED) {
        entityInfo->cringeClassStatus.status = STATUS_CONFUSED;
        entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gConfusionTurnRange,TRUE) + 1;
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB25C);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB27C);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void CowerStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->cringeClassStatus.status != STATUS_COWERING) {
      entityInfo->cringeClassStatus.status = STATUS_COWERING;
      entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gCowerTurnRange,TRUE) + 1;
      sub_8041BF8(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB940);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB960);
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

    entityInfo = GetEntInfo(target);
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
    gFormatArgs[0] = HP;
    gFormatArgs[1] = maxHPStat;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if ((HP == 0) && (maxHPStat == 0)) {
        if (displayMessage_u8)
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB204); // $m0's HP remained unchanged
    }
    else if ((param_4 == 0) && (HP == 0))
    {
        if (displayMessage_u8)
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB21C); // $m0 has full HP
    }
    else
    {
        r8 = 0;
        if (maxHPStat != 0) {
            if (sub_8045888(target)) {
                r8 = maxHPStat;
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB240); // m0$'s max HP rose by {VALUE_1}
        }
        if (HP != 0) {
            if (sub_8045888(target)) {
                r8 = HP;
            }
            if (param_3 != 0) {
                if (entityInfo->maxHPStat == entityInfo->HP) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB1E0); // $m0 was fully healed
                }
                else {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB1C4); // $m0 recovered {VALUE_0} HP
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
    if (GetEntInfo(target)->scanning) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAEF0); // Item locations are already known
    }
    else
    {
        GetEntInfo(target)->scanning = TRUE;
        nullsub_75(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAEA0); // Item locations became evident
        sub_803F580(0);
        sub_8040A84();
        EntityUpdateStatusSprites(target);
    }
  }
}

void HandleStairsOrb(Entity* pokemon, Entity* target)
{
  if (EntityExists(target)) {
    if(GetFloorType())
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAF3C);
    }
    else
    {
        if (GetEntInfo(target)->stairSpotter) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAF1C);
        }
        else
        {
            GetEntInfo(target)->stairSpotter = TRUE;
            nullsub_76(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAEC8);
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
    if (GetEntInfo(target)->powerEars != 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAFD0);
    }
    else
    {
        GetEntInfo(target)->powerEars = TRUE;
        nullsub_77(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAFAC);
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
    entityInfo = GetEntInfo(target);
    if (pokemon == target) {
      pokemon = target;
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gPtrCantLeechSeedSelfMessage);
    }
    else {
      if (HasSafeguardStatus(pokemon,target,displayMessage)) {
        return;
      }
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (MonsterIsType(target, TYPE_GRASS)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gPtrCantLeechSeedMonMessage);
      }
      else
        {
            switch(entityInfo->leechSeedClassStatus.status)
            {
                case STATUS_DESTINY_BOND:
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAA8C);
                default:
                    entityInfo->leechSeedClassStatus.status = STATUS_LEECH_SEED;
                    entityInfo->leechSeedClassStatus.turns = CalculateStatusTurns(target, gLeechSeedTurnRange, TRUE) + 1;
                    entityInfo->leechSeedClassStatus.damageCountdown = 0;
                    nullsub_78(target);
                    entityInfo->leechSeedClassStatus.unk8 = 0xff;
                    break;
                case STATUS_LEECH_SEED:
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAE7C);
                    return;
            }
            for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
            {
                if (pokemon == gDungeon->activePokemon[index]) {
                    entityInfo->leechSeedClassStatus.unk8 = index;
                    entityInfo2 = GetEntInfo(pokemon);
                    entityInfo->leechSeedClassStatus.unk4 = entityInfo2->unk98;
                }
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAE58);
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

    entityInfo = GetEntInfo(pokemon);
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        target = gDungeon->activePokemon[index];
        if (EntityExists(target)) {
            entityInfo2 = GetEntInfo(target);
            if((u8)(entityInfo2->leechSeedClassStatus.status - 1) <= 1)
            {
                if(entityInfo2->leechSeedClassStatus.unk4 == entityInfo->unk98)
                {
                    entityInfo2->leechSeedClassStatus.status = STATUS_NONE;
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

  if (((EntityExists(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) &&
     (GetEntityType(target) == ENTITY_MONSTER)) {
        entityInfo = GetEntInfo(pokemon);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
        if (entityInfo->leechSeedClassStatus.status != STATUS_DESTINY_BOND)
        {
            if (entityInfo->leechSeedClassStatus.status == STATUS_LEECH_SEED)
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FA79C);

            entityInfo->leechSeedClassStatus.status = STATUS_DESTINY_BOND;
            entityInfo->leechSeedClassStatus.turns = CalculateStatusTurns(target,gDestinyBondTurnRange,TRUE) + 1;
            entityInfo->leechSeedClassStatus.damageCountdown = 0;
            nullsub_74(target);
            entityInfo->leechSeedClassStatus.unk8 = 0xff;
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBB78);
            return;
        }
        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
            if (target == gDungeon->activePokemon[index]) {
                entityInfo->leechSeedClassStatus.unk8 = index;
                entityInfo2 = GetEntInfo(target);
                entityInfo->leechSeedClassStatus.unk4 = entityInfo2->unk98;
            }
        }
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBB4C);
        EntityUpdateStatusSprites(target);
    }
}

void SureShotStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_SURE_SHOT) {
      entityInfo->sureShotClassStatus.status = STATUS_SURE_SHOT;
      entityInfo->sureShotClassStatus.turns = turns + 1;
      sub_8041CDC(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB73C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB764);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WhifferStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_WHIFFER) {
      entityInfo->sureShotClassStatus.status = STATUS_WHIFFER;
      entityInfo->sureShotClassStatus.turns = turns + 1;
      sub_8041CEC(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB780);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB7A0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FixedDamageStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_SET_DAMAGE) {
      entityInfo->sureShotClassStatus.status = STATUS_SET_DAMAGE;
      entityInfo->sureShotClassStatus.turns = CalculateStatusTurns(target, gSetDamageTurnRange, FALSE) + 1;
      nullsub_79(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB8BC);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB8E4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FocusEnergyStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_FOCUS_ENERGY) {
      entityInfo->sureShotClassStatus.status = STATUS_FOCUS_ENERGY;
      entityInfo->sureShotClassStatus.turns = CalculateStatusTurns(target, gFocusEnergyTurnRange, FALSE) + 1;
      nullsub_80(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB900);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB924);
    }
    EntityUpdateStatusSprites(target);
  }
}

void sub_80783C4(Entity * pokemon, Entity * target, bool8 param_3)
{
  EntityInfo *targetEntityInfo;
  EntityInfo *entityInfo;
  Entity * entity;
  Entity * entity2;
  ActionContainer action;
  s32 index;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    targetEntityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (targetEntityInfo->curseClassStatus.status == STATUS_DECOY) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB994);
    }
    else {
      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity = gDungeon->activePokemon[index];
        if ((((EntityExists(entity)) && (target != entity)) &&
           (u8)(GetEntInfo(entity)->curseClassStatus.status - 2U) < 2)) {
          EndCurseClassStatus(pokemon,entity,STATUS_NONE);
          sub_803E46C(0x2a);
        }
      }
      sub_8041D38(target);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (targetEntityInfo->curseClassStatus.status != STATUS_NONE) {
        EndCurseClassStatus(pokemon,target, STATUS_DECOY);
      }
      targetEntityInfo->curseClassStatus.status = STATUS_DECOY;
      targetEntityInfo->curseClassStatus.applierNonTeamMemberFlag = GetEntInfo(pokemon)->isNotTeamMember;
      targetEntityInfo->curseClassStatus.unk2 = param_3;
      targetEntityInfo->curseClassStatus.turns = CalculateStatusTurns(target,gDecoyTurnRange,TRUE) + 1;
      targetEntityInfo->curseClassStatus.damageCountdown = 0;
      sub_806CCB4(target,sub_806CEBC(target));
      gDungeon->decoyIsActive = TRUE;
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB978);

      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity2 = gDungeon->activePokemon[index];
        if (EntityExists(entity2)) {
          entityInfo = GetEntInfo(entity2);
          entityInfo->aiTarget.aiObjective = AI_STAND_STILL;
          entityInfo->aiTarget.aiTarget = NULL;
          entityInfo->aiTarget.aiTargetSpawnGenID = 0;
          if (!entityInfo->isTeamLeader) {
            action = entityInfo->action;
            AIMovement(entity2, TRUE);
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
    pokemonEntityData = GetEntInfo(pokemon);
    targetEntityInfo = GetEntInfo(target);
    if (MonsterIsType(pokemon, TYPE_GHOST)) {
        if (HasSafeguardStatus(pokemon,target, TRUE)) {
            return;
      }
      EndCurseClassStatus(pokemon,target,STATUS_CURSED);
      sub_8041D48(target);
      HP = pokemonEntityData->HP / 2;
      pokemonEntityData->HP = HP;
      if (HP == 0) {
        pokemonEntityData->HP = 1;
      }
      if (targetEntityInfo->curseClassStatus.status != STATUS_CURSED) {
        targetEntityInfo->curseClassStatus.status = STATUS_CURSED;
        targetEntityInfo->curseClassStatus.turns = CalculateStatusTurns(target,gCurseTurnRange,TRUE) + 1;
        targetEntityInfo->curseClassStatus.damageCountdown = 0;
      }
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB004);
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
  EntityInfo *targetEntityInfo;

  if (EntityExists(target)) {
    EndCurseClassStatus(pokemon,target,STATUS_SNATCH);

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->activePokemon[index];
      if ((EntityExists(entity)) && (GetEntInfo(entity)->curseClassStatus.status == STATUS_SNATCH)) {
        EndCurseClassStatus(pokemon, entity, STATUS_NONE);
      }
    }
    nullsub_81(target);

    targetEntityInfo = GetEntInfo(target);
    if (targetEntityInfo->curseClassStatus.status != STATUS_SNATCH) {
      targetEntityInfo->curseClassStatus.status = STATUS_SNATCH;
      targetEntityInfo->curseClassStatus.turns= CalculateStatusTurns(target,gSnatchTurnRange,FALSE) + 1;
      targetEntityInfo->curseClassStatus.damageCountdown = 0;
    }

    gDungeon->snatchPokemon = target;
    gDungeon->unk17B3C = targetEntityInfo->unk98;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB01C);
    EntityUpdateStatusSprites(target);
  }
}

void TauntStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->cringeClassStatus.status != STATUS_TAUNTED) {
      entityInfo->cringeClassStatus.status = STATUS_TAUNTED;
      entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gTauntTurnRange,TRUE) + 1;
      nullsub_73(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FB9F0);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBA14);
    }
    EntityUpdateStatusSprites(target);
  }
}

void HandleStockpile(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->stockpileStage < MAX_STOCKPILE_STAGE) {
      entityInfo->stockpileStage++;
      sub_804178C(1);
      sub_8041D5C(target);
      gFormatArgs[0] = entityInfo->stockpileStage;
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBA38);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBA60);
    }
    EntityUpdateStatusSprites(target);
  }
}

void InvisibleStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * targetEntityInfo;

  if (EntityExists(target)) {
    targetEntityInfo = GetEntInfo(target);
    if (targetEntityInfo->invisibleClassStatus.status == STATUS_TRANSFORMED) {
      SendTransformEndMessage(pokemon,target);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (targetEntityInfo->invisibleClassStatus.status != STATUS_INVISIBLE) {
      targetEntityInfo->invisibleClassStatus.status = STATUS_INVISIBLE;
      targetEntityInfo->invisibleClassStatus.turns = CalculateStatusTurns(target,gInvisibleTurnRange,FALSE) + 1;
      sub_8041D84(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBA80);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBAA0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void PerishSongTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * entityInfo;

  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    nullsub_82(target);
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->perishSongTurns == 0) {
      entityInfo->perishSongTurns = CalculateStatusTurns(target,gPerishSongTurnRange,FALSE) + 1;
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBB04);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBB28);
    }
    EntityUpdateStatusSprites(target);
  }
}

void EncoreStatusTarget(Entity *pokemon,Entity *target)
{
  Move *movePtr;
  int index;
  EntityInfo *EntityInfo;

  EntityInfo = GetEntInfo(target);
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &EntityInfo->moves.moves[index];
      if ((EntityInfo->moves.moves[index].moveFlags & MOVE_FLAG_EXISTS) && (movePtr->moveFlags & MOVE_FLAG_LAST_USED)) break;
    }
    if ((index == MAX_MON_MOVES) && ((EntityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0)) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBBD4);
    }
    else {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (EntityInfo->cringeClassStatus.status != STATUS_ENCORE) {
        EntityInfo->cringeClassStatus.status = STATUS_ENCORE;
        EntityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gEncoreTurnRange,TRUE) + 1;
        nullsub_83(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBB94);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBBB8);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void sub_8078A58(Entity *pokemon, Entity *target, s32 param_3, s32 param_4)
{
    EntityInfo *targetInfo;
    FixedPoint bellyBefore;

    if (!EntityExists(target))
        return;

    targetInfo = GetEntInfo(target);

    if (param_4 != 0) {
        FixedPoint sp0 = IntToFixedPoint(param_4);
        bellyBefore = targetInfo->maxBelly;
        targetInfo->maxBelly = FixedPoint_Subtract(bellyBefore, sp0);
        targetInfo->belly = FixedPoint_Min(targetInfo->belly, targetInfo->maxBelly);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);

        if (FixedPointToInt(bellyBefore) != FixedPointToInt(targetInfo->maxBelly)) {
            sub_8041D9C(target);
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FBD9C);
        }
        else
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FBE3C);
    }
    else {
        FixedPoint sp8 = IntToFixedPoint(param_3);
        bellyBefore = targetInfo->belly;
        targetInfo->belly = FixedPoint_Subtract(bellyBefore, sp8);

        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);

        if (FixedPointToInt(bellyBefore) != FixedPointToInt(targetInfo->belly)) {
            nullsub_84(target);
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FBD78);
        }
        else
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FBE40);
    }

    EntityUpdateStatusSprites(target);
}

void sub_8078B5C(Entity *pokemon, Entity *target, u32 bellyIncrement, s32 maxBellyIncrement, bool8 displayMessage)
{
    bool8 bellySizeIncreased;
    FixedPoint oldBelly;
    FixedPoint *bellyPtr;
    EntityInfo *targetInfo;
    FixedPoint *puVar8;
    FixedPoint sp_0x0;
    FixedPoint sp_0x4;
    FixedPoint sp_0x8;
    FixedPoint sp_0x10;
    FixedPoint sp_0x14;
    FixedPoint sp_0x18;
    FixedPoint sp_0x20;
    bool32 bellySame;

    if (!EntityExists(target)) {
        return;
    }
    targetInfo = GetEntInfo(target);
    if ((!targetInfo->isTeamLeader) && (HasHeldItem(target,0x1b))) {
        if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBEA0);
        return;
    }
    bellySizeIncreased = FALSE;
    if (maxBellyIncrement != 0) {
        if(FixedPointToInt(targetInfo->belly) >= FixedPointToInt(targetInfo->maxBelly))
        {
            bellySizeIncreased = TRUE;
        }
        if (bellyIncrement == 999)
        {
            bellySizeIncreased = TRUE;
        }
    }
    if (bellySizeIncreased) {
        bellyPtr = &targetInfo->maxBelly;
        sp_0x20 = *bellyPtr;
        bellySame = (FixedPointToInt(targetInfo->belly) ==  FixedPointToInt(*bellyPtr));
        sp_0x0 = IntToFixedPoint(maxBellyIncrement);
        sp_0x4 = FixedPoint_Add(*bellyPtr,sp_0x0);
        *bellyPtr = sp_0x4;
        sp_0x8 = IntToFixedPoint(200);
        *bellyPtr = FixedPoint_Min(sp_0x4,sp_0x8);
        targetInfo->belly = *bellyPtr;
        if ((!bellySame) && (displayMessage)) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBE64); // $m0's belly filled up full!
        }
        if (FixedPointToInt(sp_0x20) == FixedPointToInt(targetInfo->maxBelly)) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBDF0); // $m0's belly won't get any bigger!
        }
        else {
            sub_8041DB0(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBDC4); // m0's max belly size increased!
        }
    }
    else {
        bellyPtr = &targetInfo->belly;
        oldBelly = *bellyPtr;
        sp_0x10 = IntToFixedPoint(bellyIncrement);
        sp_0x14 = FixedPoint_Add(*bellyPtr,sp_0x10);
        *bellyPtr = sp_0x14;
        puVar8 = &targetInfo->maxBelly;
        sp_0x18 = FixedPoint_Min(sp_0x14,*puVar8);
        *bellyPtr = sp_0x18;
        if (bellyIncrement == 999) {
            *bellyPtr = *puVar8;
        }
        nullsub_85(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (FixedPointToInt(oldBelly) ==  FixedPointToInt(*bellyPtr)) {
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBE14); // $m0's belly didn't change!
        }
        else {
            if (FixedPointToInt(*bellyPtr) >= FixedPointToInt(*puVar8)) {
                if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBE64); // $m0's belly filled up full!
            }
            else
            {
                if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBE84); // $m0's belly was filled!
            }
        }
    }
    EntityUpdateStatusSprites(target);
}
