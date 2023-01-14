#include "global.h"
#include "status.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_ai_movement.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "dungeon_items.h"
#include "code_808417C.h"
#include "code_8077274_1.h"
#include "map.h"
#include "status_checks_1.h"

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

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

extern s32 gUnknown_202DE30[10];

extern void sub_8041D84(struct Entity *);
extern void sub_804178C(u32);
extern void sub_8041D5C(struct Entity *);
extern void RaiseAttackStageTarget(struct Entity *, struct Entity *, u32, u32);
extern void RaiseDefenseStageTarget(struct Entity *, struct Entity *, u32, u32);
extern void sub_8041D48(struct Entity *);
extern u8 sub_806CEBC(struct Entity *);
extern void sub_8041D38(struct Entity * pokemon);
extern void sub_803E46C(u32);
extern void sub_806CCB4(struct Entity *, u8);
extern u8 sub_8043D10(void);
extern void sub_8041CDC(struct Entity *pokemon);
extern void sub_8041CEC(struct Entity *pokemon);
extern void nullsub_73(struct Entity *);
extern void nullsub_74(struct Entity *);
extern void nullsub_75(struct Entity *);
extern void nullsub_76(struct Entity *);
extern void nullsub_77(struct Entity *);
extern void nullsub_78(struct Entity *);
extern void nullsub_79(struct Entity *);
extern void nullsub_80(struct Entity *);
extern void nullsub_81(struct Entity *);
extern void nullsub_82(struct Entity *);
extern void sub_803F580(u32);
extern void sub_8040A84(void);
extern void sub_8041CA8(struct Entity *);
extern void sub_8041C94(struct Entity *);
extern u8 sub_8045888(struct Entity *r0);
extern void sub_803ED30(s32, struct Entity *r0, u8, s32);
extern void sub_8041BF8(struct Entity *);
extern void sub_8041BE8(struct Entity *);
extern void sub_8041CCC(struct Entity *);
extern void sub_8041CB8(struct Entity *r0);
extern void sub_8041C1C(struct Entity *r0);
extern void sub_8042060(struct Entity *, s32);
extern bool8 sub_8071728(struct Entity * param_1, struct Entity * param_2, u8 param_3);
extern void sub_8041FB4(struct Entity *r0, u32 r1);
extern void sub_8041FD8(struct Entity *r0, u32 r1);
extern void sub_80522F4(struct Entity *r1, struct Entity *r2, u8 *);
extern s32 sub_8009DA4(s32, s32);
extern void sub_804201C(struct Entity *r0, u32 r1);
extern void sub_8041FFC(struct Entity *r0, u32 r1);
extern void SetMessageArgument(char[], struct Entity*, u32);
extern void SetMessageArgument_2(char[], struct EntityInfo*, u32);
extern void sub_8041C58(struct Entity *r0);
extern void DungeonEntityUpdateStatusSprites(struct Entity *);
extern void sub_8042040(struct Entity *, s32);
extern void sub_80420A0(struct Entity *);

u8 GetFlashFireStatus(struct Entity *pokemon)
{
    if (!EntityExists(pokemon) || !HasAbility(pokemon, ABILITY_FLASH_FIRE))
    {
        return FLASH_FIRE_STATUS_NONE;
    }
    if (pokemon->info->flashFireBoost > 1)
    {
        return FLASH_FIRE_STATUS_MAXED;
    }
    return FLASH_FIRE_STATUS_NOT_MAXED;
}

static inline s32 UpdateFlashFireBoost_sub(struct EntityInfo * entityData)
{
    s32 flashFireBoost;

    flashFireBoost = entityData->flashFireBoost;
    flashFireBoost++;
    if (FLASH_FIRE_STATUS_MAXED < flashFireBoost) {
      flashFireBoost = FLASH_FIRE_STATUS_NOT_MAXED;
    }
    return flashFireBoost;
}

void UpdateFlashFireBoost(struct Entity * pokemon, struct Entity *target)
{
  struct EntityInfo * entityData;
  struct EntityInfo * entityData_1;
  s32 flashFireBoost;

  if (EntityExists(target)) {
    entityData = target->info;
    entityData_1 = entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    flashFireBoost = UpdateFlashFireBoost_sub(entityData);
    if (entityData_1->flashFireBoost != flashFireBoost) {
      entityData_1->flashFireBoost = flashFireBoost;
      sub_8041C58(target);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void ChangeAttackMultiplierTarget(struct Entity *pokemon, struct Entity *target, u32 statStage, s32 param_4, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  s32 oldMulti;
  
  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_ATK) {
    strcpy(gUnknown_202DE58,*gUnknown_80FC0C8);
  }
  else {
    strcpy(gUnknown_202DE58,*gUnknown_80FC0B8);
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

  entityData = target->info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  oldMulti = entityData->offensiveMultipliers[statStage];

  if (param_4 < 0x100) {
    sub_8041FD8(target,statStage);
  }
  else {
    sub_8041FB4(target,statStage);
  }

  entityData->offensiveMultipliers[statStage] = sub_8009DA4(entityData->offensiveMultipliers[statStage],param_4);

  if (entityData->offensiveMultipliers[statStage] < 2) {
    entityData->offensiveMultipliers[statStage] = 2;
  }
  if (0x63fd < entityData->offensiveMultipliers[statStage]) {
    entityData->offensiveMultipliers[statStage] = 0x63fd; // 25597
  }
  if (oldMulti > entityData->offensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC11C);
  }
  else if (oldMulti < entityData->offensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC118);
  }
  else
  {
    sub_80522F4(pokemon,target,*gUnknown_80FC184);
  }
  DungeonEntityUpdateStatusSprites(target);
}

void ChangeDefenseMultiplierTarget(struct Entity *pokemon, struct Entity *target, u32 statStage, s32 param_4, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  s32 oldMulti;
  
  if (!EntityExists(target)) {
    return;
  }

  if (statStage != STAT_STAGE_DEF) {
    strcpy(gUnknown_202DE58,*gUnknown_80FC0AC);
  }
  else {
    strcpy(gUnknown_202DE58,*gUnknown_80FC09C);
  }
  if ((param_4 < 0x100) && sub_8071728(pokemon,target,displayMessage)) {
    return;
  }

  entityData = target->info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  oldMulti = entityData->defensiveMultipliers[statStage];

  if (param_4 < 0x100) {
    sub_804201C(target,statStage);
  }
  else {
    sub_8041FFC(target,statStage);
  }

  entityData->defensiveMultipliers[statStage] = sub_8009DA4(entityData->defensiveMultipliers[statStage],param_4);

  if (entityData->defensiveMultipliers[statStage] < 2) {
    entityData->defensiveMultipliers[statStage] = 2;
  }
  if (0x63fd < entityData->defensiveMultipliers[statStage]) {
    entityData->defensiveMultipliers[statStage] = 0x63fd; // 25597
  }
  if (oldMulti > entityData->defensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC114);
  }
  else if (oldMulti < entityData->defensiveMultipliers[statStage]) {
    sub_80522F4(pokemon,target,*gUnknown_80FC0FC);
  }
  else
  {
    sub_80522F4(pokemon,target,*gUnknown_80FC180);
  }
  DungeonEntityUpdateStatusSprites(target);
}

void RaiseAccuracyStageTarget(struct Entity * pokemon, struct Entity * target, s32 statStage)
{
  struct EntityInfo *entityData;

  if (EntityExists(target)) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8042040(target,statStage);
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gUnknown_202DE58,*gUnknown_80FC090);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_80FC084);
    }
    if (entityData->hitChancesStages[statStage] < MAX_STAT_STAGE) {
      entityData->hitChancesStages[statStage]++;
      sub_80522F4(pokemon,target,*gUnknown_80FC1C4);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC218);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void LowerAccuracyStageTarget(struct Entity * pokemon, struct Entity * target, s32 statStage, bool8 displayMessage)
{
  struct EntityInfo *entityData;

  if (EntityExists(target)) {
    if (statStage != STAT_STAGE_ACCURACY) {
        strcpy(gUnknown_202DE58,*gUnknown_80FC090);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_80FC084);
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
        entityData = target->info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_8042060(target,statStage);
        if (entityData->hitChancesStages[statStage] != 0) {
          entityData->hitChancesStages[statStage]--;
          sub_80522F4(pokemon,target,*gUnknown_80FC1A4);
        }
        else {
          sub_80522F4(pokemon,target,*gUnknown_80FC1F0);
        }
        DungeonEntityUpdateStatusSprites(target);
      }
    }
  }
}

void CringeStatusTarget(struct Entity * pokemon,struct Entity * target, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  
  if (EntityExists(target)) {
    if (!HasSafeguardStatus(pokemon, target, displayMessage)) {
      if (HasAbility(target, ABILITY_INNER_FOCUS)){
            SetMessageArgument(gAvailablePokemonNames,target,0);
            if(displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCC18);
      }
      else {
        entityData = target->info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if(entityData->volatileStatus != STATUS_CRINGE)
        {
            entityData->volatileStatus = STATUS_CRINGE;
            entityData->volatileStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E3C, TRUE) +  1;
            sub_80420A0(target);
            sub_80522F4(pokemon,target,*gUnknown_80FB2E0);
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FB300);
        }
        DungeonEntityUpdateStatusSprites(target);
      }
    }
  }
}

void ParalyzeStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage)
{
  struct Tile *mapTile;
  register struct EntityInfo *entityData;
  struct Entity *mapPokemonEntity;
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
      entityData = target->info;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (entityData->nonVolatileStatus != STATUS_PARALYSIS) {
        entityData->nonVolatileStatus = STATUS_PARALYSIS;
        entityData->nonVolatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E50,TRUE) + 1;
        entityData->nonVolatileStatusDamageCountdown = 0;
        entityData->fillAF = 0;
        bVar6 = FALSE;
        sub_80522F4(pokemon,target,*gUnknown_80FB2AC);
        sub_8041C1C(target);
        GetSpeedStatus(target);
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
              SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
              sub_80522F4(pokemon,target,*gUnknown_80FF01C);
            }
            if (sub_807167C(target,mapPokemonEntity) == 1) {
              ParalyzeStatusTarget(pokemon, mapPokemonEntity, displayMessage);
            }
          }
        }
      }
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void RaiseMovementSpeedTarget(struct Entity * pokemon, struct Entity * target, s32 turns, bool8 displayMessage)
{
  s32 movSpeed;
  s32 index;
  s32 movSpeed_1;
  struct EntityInfo *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  if (turns == 0) {
    turns = CalculateStatusTurns(target,gUnknown_80F4E40,FALSE) + 1;
  }
  entityData = target->info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  movSpeed = GetSpeedStatus(target);
  if (movSpeed == MAX_SPEED_STAGE) {
    if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FC2B8);
  }
  else {
    for(index = 0; index < NUM_SPEED_COUNTERS; index++)
    {
        if(entityData->speedUpCounters[index]  == 0)
        {
            entityData->speedUpCounters[index]  = turns;
            break;
        }
    } 
    movSpeed_1 = GetSpeedStatus(target);
    if (movSpeed == movSpeed_1) {
        sub_80522F4(pokemon,target,*gUnknown_80FC298);
    }
    else
    {
        sub_8041CB8(target);
        sub_80522F4(pokemon,target,gUnknown_80FA124[movSpeed_1]);
        entityData->speedStageChanged = TRUE;
        entityData->attacking = FALSE;
    }
  }
  DungeonEntityUpdateStatusSprites(target);
}

void LowerMovementSpeedTarget(struct Entity * pokemon, struct Entity * target, s32 levels, bool8 displayMessage)
{
  s32 movSpeed;
  s32 counter;
  s32 index;
  s32 movSpeed_1;
  struct EntityInfo *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  if (HasSafeguardStatus(pokemon,target,displayMessage)) {
    return;
  }
  entityData = target->info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  movSpeed = GetSpeedStatus(target);
  if (movSpeed == 0) {
    if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FC2D8);
  }
  else {
    for(counter = 0; counter < levels; counter++)
    {
        for(index = 0; index < NUM_SPEED_COUNTERS; index++)
        {
            if (entityData->speedDownCounters[index]== 0) {
                entityData->speedDownCounters[index] = CalculateStatusTurns(target,gUnknown_80F4E48,TRUE) + 1;
                break;
            }
        }
    }
    movSpeed_1 = GetSpeedStatus(target);
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
  DungeonEntityUpdateStatusSprites(target);
}

void ConfuseStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  
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
      entityData = target->info;
      if (entityData->volatileStatus != STATUS_CONFUSED) {
        entityData->volatileStatus = STATUS_CONFUSED;
        entityData->volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E4C,TRUE) + 1;
        sub_80522F4(pokemon,target,*gUnknown_80FB25C);
      }
      else {
        sub_80522F4(pokemon,target,*gUnknown_80FB27C);
      }
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void CowerStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->volatileStatus != STATUS_COWERING) {
      entityData->volatileStatus = STATUS_COWERING;
      entityData->volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ECC,TRUE) + 1;
      sub_8041BF8(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB940);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB960);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void HealTargetHP(struct Entity *pokemon, struct Entity *target, s32 param_3, s32 param_4, bool32 displayMessage)
{
    struct EntityInfo *entityData;
    s32 HP;
    s32 maxHPStat;
    s32 r8;
    u8 displayMessage_u8;

    displayMessage_u8 = displayMessage;

    if (!EntityExists(target)) {
        return;
    }

    entityData = target->info;
    maxHPStat = entityData->maxHPStat;
    HP = entityData->HP;
    if (((entityData->HP == entityData->maxHPStat) && (0 < param_4)) || (param_3 == 0)) {
        entityData->maxHPStat += param_4;
        entityData->HP += param_4;
        if (entityData->maxHPStat > 999) {
            entityData->maxHPStat = 999;
        }
        if (entityData->HP > entityData->maxHPStat) {
            entityData->HP = entityData->maxHPStat;
        }
        if (entityData->HP == entityData->maxHPStat) {
            HP = entityData->HP;
        }
        sub_8041C94(target);
    }
    else {
        entityData->HP += param_3;
        if (entityData->HP > entityData->maxHPStat) {
            entityData->HP = entityData->maxHPStat;
        }
        sub_8041CA8(target);
    }
    maxHPStat = entityData->maxHPStat - maxHPStat;
    HP = entityData->HP - HP;
    DungeonEntityUpdateStatusSprites(target);
    gUnknown_202DE30[0] = HP;
    gUnknown_202DE30[1] = maxHPStat;
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
            if (sub_8045888(target) != 0) {
                r8 = maxHPStat;
            }
            sub_80522F4(pokemon,target,*gUnknown_80FB240); // m0$'s max HP rose by $d1
        }
        if (HP != 0) {
            if (sub_8045888(target) != 0) {
                r8 = HP;
            }
            if (param_3 != 0) {
                if (entityData->maxHPStat == entityData->HP) {
                    sub_80522F4(pokemon,target,*gUnknown_80FB1E0); // $m0 was fully healed
                }
                else {
                    sub_80522F4(pokemon,target,*gUnknown_80FB1C4); // $m0 recovered $d0 HP
                }
            }
        }
        if (r8)
            sub_803ED30(r8,target,1,-1);
    }
}

void HandleScannerOrb(struct Entity* pokemon, struct Entity* target)
{
  if (EntityExists(target)) {
    if (target->info->scanning) {
        sub_80522F4(pokemon,target,*gUnknown_80FAEF0); // Item locations are already known
    }
    else
    {
        target->info->scanning = TRUE;
        nullsub_75(target);
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        sub_80522F4(pokemon,target,*gUnknown_80FAEA0); // Item locations became evident
        sub_803F580(0);
        sub_8040A84();
        DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void HandleStairsOrb(struct Entity* pokemon, struct Entity* target)
{
  if (EntityExists(target)) {
    if(sub_8043D10())
    {
        sub_80522F4(pokemon,target,*gUnknown_80FAF3C);
    }
    else
    {
        if (target->info->stairSpotter) {
            sub_80522F4(pokemon,target,*gUnknown_80FAF1C);
        }
        else
        {
            target->info->stairSpotter = TRUE;
            nullsub_76(target);
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FAEC8);
            sub_803F580(0);
            sub_8040A84();
            DungeonEntityUpdateStatusSprites(target);
        }
    }
  }
}

void HandleRadarOrb(struct Entity* pokemon, struct Entity* target)
{
  if (EntityExists(target)) {
    if (target->info->powerEars != 0) {
        sub_80522F4(pokemon,target,*gUnknown_80FAFD0);
    }
    else
    {
        target->info->powerEars = TRUE;
        nullsub_77(target);
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_80522F4(pokemon,target,*gUnknown_80FAFAC);
        sub_803F580(0);
        sub_8040A84();
        DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void HandleLeechSeed(struct Entity * pokemon, struct Entity * target, bool8 displayMessage)
{
  struct EntityInfo *entityData;
  struct EntityInfo *entityData2;
  s32 index;

  if ((EntityExists(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) {
    entityData = target->info;
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
            switch(entityData->linkedStatus)
            {
                case STATUS_DESTINY_BOND:
                    sub_80522F4(pokemon,target,*gUnknown_80FAA8C);
                default:
                    entityData->linkedStatus = STATUS_LEECH_SEED;
                    entityData->linkedStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EB0, TRUE) + 1;
                    entityData->linkedStatusDamageCountdown = 0;
                    nullsub_78(target);
                    entityData->unkD8 = 0xff;
                    break;
                case STATUS_LEECH_SEED:
                    sub_80522F4(pokemon,target,*gUnknown_80FAE7C);
                    return;
            }
            for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
            {
                if (pokemon == gDungeon->allPokemon[index]) {
                    entityData->unkD8 = index;
                    entityData2 = pokemon->info;
                    entityData->unkD4 = entityData2->unk98;
                }
            }
            sub_80522F4(pokemon,target,*gUnknown_80FAE58);
            DungeonEntityUpdateStatusSprites(target);
        }
      }
    }
  }

void sub_8078084(struct Entity * pokemon)
{
    struct EntityInfo *entityData;
    struct EntityInfo *entityData2;
    struct Entity *target;
    s32 index;

    entityData = pokemon->info;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        target = gDungeon->allPokemon[index];
        if (EntityExists(target)) {
            entityData2 = target->info;
            if((u8)(entityData2->linkedStatus - 1) <= 1)
            {
                if(entityData2->unkD4 == entityData->unk98)
                {
                    entityData2->linkedStatus = STATUS_NONE;
                    DungeonEntityUpdateStatusSprites(target);
                }
            }
        }
    }
  }

void DestinyBondStatusTarget(struct Entity * pokemon, struct Entity * target)
{
  struct EntityInfo *entityData;
  struct EntityInfo *entityData2;
  s32 index;
  u8 *linkedStatus;
  s32 zero;
  
  if (((EntityExists(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) &&
     (GetEntityType(target) == ENTITY_MONSTER)) {
        entityData = pokemon->info;
        SetMessageArgument(gAvailablePokemonNames,pokemon,0);
        linkedStatus = &entityData->linkedStatus;
        if (entityData->linkedStatus != STATUS_DESTINY_BOND)
        {
            if (entityData->linkedStatus == STATUS_LEECH_SEED)
                sub_80522F4(pokemon,target,*gUnknown_80FA79C);
            zero = 0;
            *linkedStatus = STATUS_DESTINY_BOND;
            entityData->linkedStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EF0,TRUE) + 1;
            entityData->linkedStatusDamageCountdown = zero;
            nullsub_74(target);
            entityData->unkD8 = 0xff;
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FBB78);
            return;
        }
        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
            if (target == gDungeon->allPokemon[index]) {
                entityData->unkD8 = index;
                entityData2 = target->info;
                entityData->unkD4 = entityData2->unk98;
            }
        }
        sub_80522F4(pokemon,target,*gUnknown_80FBB4C);
        DungeonEntityUpdateStatusSprites(target);
    }
}

void SureShotStatusTarget(struct Entity *pokemon, struct Entity * target, s32 turns)
{
  struct EntityInfo *entityData;
  
  if (EntityExists(target)) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->moveStatus != STATUS_SURE_SHOT) {
      entityData->moveStatus = STATUS_SURE_SHOT;
      entityData->moveStatusTurns = turns + 1;
      sub_8041CDC(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB73C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB764);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void WhifferStatusTarget(struct Entity *pokemon, struct Entity * target, s32 turns)
{
  struct EntityInfo *entityData;
  
  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->moveStatus != STATUS_WHIFFER) {
      entityData->moveStatus = STATUS_WHIFFER;
      entityData->moveStatusTurns = turns + 1;
      sub_8041CEC(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB780);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB7A0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void FixedDamageStatusTarget(struct Entity *pokemon, struct Entity * target)
{
  struct EntityInfo *entityData;
  
  if (EntityExists(target)) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->moveStatus != STATUS_SET_DAMAGE) {
      entityData->moveStatus = STATUS_SET_DAMAGE;
      entityData->moveStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EC4, FALSE) + 1;
      nullsub_79(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB8BC);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB8E4);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void FocusEnergyStatusTarget(struct Entity *pokemon, struct Entity * target)
{
  struct EntityInfo *entityData;
  
  if (EntityExists(target)) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->moveStatus != STATUS_FOCUS_ENERGY) {
      entityData->moveStatus = STATUS_FOCUS_ENERGY;
      entityData->moveStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EC8, FALSE) + 1;
      nullsub_80(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB900);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB924);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_80783C4(struct Entity * pokemon, struct Entity * target, u8 param_3)
{
  struct EntityInfo *targetEntityData;
  struct EntityInfo *entityData;
  struct Entity * entity;
  struct Entity * entity2;
  struct ActionContainer action;
  s32 index;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    targetEntityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityData->waitingStatus == STATUS_DECOY) {
      sub_80522F4(pokemon,target,*gUnknown_80FB994);
    }
    else {
      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity = gDungeon->allPokemon[index];
        if ((((EntityExists(entity)) && (target != entity)) &&
           (u8)(entity->info->waitingStatus - 2U) < 2)) {
          SendWaitingEndMessage(pokemon,entity,STATUS_NONE);
          sub_803E46C(0x2a);
        }
      }
      sub_8041D38(target);
      SetMessageArgument(gAvailablePokemonNames,target,0);
      if (targetEntityData->waitingStatus != STATUS_NONE) {
        SendWaitingEndMessage(pokemon,target, STATUS_DECOY);
      }
      targetEntityData->waitingStatus = STATUS_DECOY;
      targetEntityData->enemyDecoy = pokemon->info->isNotTeamMember;
      targetEntityData->fillCA = param_3;
      targetEntityData->waitingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ED0,TRUE) + 1;
      targetEntityData->curseDamageCountdown = 0;
      sub_806CCB4(target,sub_806CEBC(target));
      gDungeon->decoyActive = TRUE;
      sub_80522F4(pokemon,target,*gUnknown_80FB978);

      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity2 = gDungeon->allPokemon[index];
        if (EntityExists(entity2)) {
          entityData = entity2->info;
          entityData->aiObjective = AI_STAND_STILL;
          entityData->aiTarget = NULL;
          entityData->aiTargetSpawnGenID = 0;
          if (!entityData->isTeamLeader) {
            action = entityData->action;
            MoveIfPossible(entity2, TRUE);
            entityData->action = action;
          }
        }
      }
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void CurseStatusTarget(struct Entity *pokemon, struct Entity * target)
{
  u32 statStage;
  s32 HP;
  struct EntityInfo * pokemonEntityData;
  struct EntityInfo * targetEntityData;
  

  if ((EntityExists(pokemon) ) && (EntityExists(target))) {
    pokemonEntityData = pokemon->info;
    targetEntityData = target->info;
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
      if (targetEntityData->waitingStatus != STATUS_CURSED) {
        targetEntityData->waitingStatus = STATUS_CURSED;
        targetEntityData->waitingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EA4,TRUE) + 1;
        targetEntityData->curseDamageCountdown = 0;
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
    DungeonEntityUpdateStatusSprites(target);
  }
}

void SnatchStatusTarget(struct Entity * pokemon, struct Entity * target)
{
  struct Entity * entity;
  s32 index;
  struct EntityInfo * targetEntityData;
  struct EntityInfo * targetEntityData2;
  
  if (EntityExists(target)) {
    SendWaitingEndMessage(pokemon,target,STATUS_SNATCH);

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->allPokemon[index];
      if ((EntityExists(entity)) && (entity->info->waitingStatus == STATUS_SNATCH)) {
        SendWaitingEndMessage(pokemon, entity, STATUS_NONE);
      }
    }
    nullsub_81(target);

    targetEntityData = target->info;
    targetEntityData2 = targetEntityData;
    if (targetEntityData->waitingStatus != STATUS_SNATCH) {
      targetEntityData->waitingStatus = STATUS_SNATCH;
      targetEntityData->waitingStatusTurns= CalculateStatusTurns(target,gUnknown_80F4EA8,FALSE) + 1;
      targetEntityData->curseDamageCountdown = 0;
    }

    gDungeon->snatchPokemon = target;
    gDungeon->unk17B3C = targetEntityData2->unk98;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB01C);
    DungeonEntityUpdateStatusSprites(target);
  }
}

void TauntStatusTarget(struct Entity * pokemon, struct Entity * target)
{
  struct EntityInfo *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->volatileStatus != STATUS_TAUNTED) {
      entityData->volatileStatus = STATUS_TAUNTED;
      entityData->volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4ED8,TRUE) + 1;
      nullsub_73(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB9F0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBA14);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void HandleStockpile(struct Entity * pokemon, struct Entity * target)
{
  struct EntityInfo *entityData;
  
  if ((EntityExists(target))) {
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->stockpileStage < MAX_STOCKPILE_STAGE) {
      entityData->stockpileStage++;
      sub_804178C(1);
      sub_8041D5C(target);
      gUnknown_202DE30[0] = entityData->stockpileStage;
      sub_80522F4(pokemon,target,*gUnknown_80FBA38);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBA60);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void InvisibleStatusTarget(struct Entity * pokemon, struct Entity * target)
{
  struct EntityInfo * targetEntityData;
  struct EntityInfo * targetEntityData_1;
  
  if (EntityExists(target)) {
    targetEntityData = target->info;
    targetEntityData_1 = targetEntityData;
    if (targetEntityData_1->transformStatus == STATUS_TRANSFORMED) {
      SendTransformEndMessage(pokemon,target);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityData_1->transformStatus != STATUS_INVISIBLE) {
      targetEntityData_1->transformStatus = STATUS_INVISIBLE;
      targetEntityData_1->transformStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EE4,FALSE) + 1;
      sub_8041D84(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBA80);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBAA0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void PerishSongTarget(struct Entity * pokemon, struct Entity * target)
{
  struct EntityInfo * entityData;
  
  if (EntityExists(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    nullsub_82(target);
    entityData = target->info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->perishSongTurns == 0) {
      entityData->perishSongTurns = CalculateStatusTurns(target,gUnknown_80F4EEC,FALSE) + 1;
      sub_80522F4(pokemon,target,*gUnknown_80FBB04);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBB28);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}
