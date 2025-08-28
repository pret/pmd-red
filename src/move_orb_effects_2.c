#include "global.h"
#include "globaldata.h"
#include "status.h"
#include "dungeon_vram.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_ai_movement.h"
#include "dungeon_logic.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "number_util.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "dungeon_config.h"
#include "moves.h"
#include "dungeon_strings.h"
#include "dungeon_random.h"
#include "dungeon_misc.h"
#include "dungeon_spawns.h"
#include "dungeon_tilemap.h"
#include "pokemon_3.h"

extern u32 gUnknown_8106A4C;

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
extern void UpdateMinimap();
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042A74(Entity *r0);
extern void sub_807EC28(bool8);
extern void DealDamageToEntity(Entity *, s16, u32, u32);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_80420C8(Entity *r0);
extern void nullsub_68(Entity *);
extern void nullsub_67(Entity *);
extern void nullsub_66(Entity *);
extern void nullsub_65(Entity *);
extern void nullsub_64(Entity *);
extern void nullsub_63(Entity *);
extern void nullsub_62(Entity *);
extern void nullsub_61(Entity *);
extern void nullsub_60(Entity *);
extern void nullsub_59(Entity *);
extern void nullsub_58(Entity *);
extern void nullsub_57(Entity *);
extern void sub_8041B34(Entity *);
void sub_8041BD0(Entity *r0, u8 r1);
void sub_8041EB4(Entity *);
void sub_8041EA4(Entity *);
extern void sub_8041E84(Entity *);
extern void sub_8041E94(Entity *);
extern void sub_8041E74(Entity *);
extern void sub_8041E60(Entity *);
extern void sub_8041E4C(Entity *);
extern void sub_8041E3C(Entity *);
extern void sub_8041E1C(Entity *);
extern void nullsub_89(Entity *);
extern void nullsub_88(Entity *);
extern void nullsub_87(Entity *);
extern void nullsub_86(Entity *);
extern void sub_8041E0C(Entity *);
extern void sub_8041DD8(Entity *r0, s32 r1); // NOTE: is s16 in another file
extern bool8 sub_806AA0C(s32, u32);
extern void UpdateMinimap(void);
extern void sub_8041D9C(Entity *);
extern void sub_8041DB0(Entity *pokemon);
extern void sub_8041CA8(Entity *);
extern void sub_8041C94(Entity *);
extern void sub_8041BF8(Entity *);
extern void sub_8041BE8(Entity *);
extern void EntityUpdateStatusSprites(Entity *);

void ConfuseStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }

  if (HasSafeguardStatus(pokemon,target,displayMessage)) {
    return;
  }

  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  if (HasHeldItem(target,ITEM_PERSIM_BAND)) {
    if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD500);
  }
  else
  {
    if (AbilityIsActive(target, ABILITY_OWN_TEMPO)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCDB4);
    }
    else
    {
      sub_8041BE8(target);
      entityInfo = GetEntInfo(target);
      if (entityInfo->cringeClassStatus.status != STATUS_CONFUSED) {
        entityInfo->cringeClassStatus.status = STATUS_CONFUSED;
        entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gConfusionTurnRange,TRUE) + 1;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB25C);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB27C);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void CowerStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->cringeClassStatus.status != STATUS_COWERING) {
      entityInfo->cringeClassStatus.status = STATUS_COWERING;
      entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gCowerTurnRange,TRUE) + 1;
      sub_8041BF8(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB940);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB960);
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

    if (!EntityIsValid(target)) {
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
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB204); // $m0's HP remained unchanged
    }
    else if ((param_4 == 0) && (HP == 0))
    {
        if (displayMessage_u8)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB21C); // $m0 has full HP
    }
    else
    {
        r8 = 0;
        if (maxHPStat != 0) {
            if (ShouldDisplayEntity(target)) {
                r8 = maxHPStat;
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB240); // m0$'s max HP rose by {VALUE_1}
        }
        if (HP != 0) {
            if (ShouldDisplayEntity(target)) {
                r8 = HP;
            }
            if (param_3 != 0) {
                if (entityInfo->maxHPStat == entityInfo->HP) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB1E0); // $m0 was fully healed
                }
                else {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB1C4); // $m0 recovered {VALUE_0} HP
                }
            }
        }
        if (r8)
            sub_803ED30(r8,target,1,-1);
    }
}

void HandleScannerOrb(Entity* pokemon, Entity* target)
{
  if (EntityIsValid(target)) {
    if (GetEntInfo(target)->scanning) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAEF0); // Item locations are already known
    }
    else
    {
        GetEntInfo(target)->scanning = TRUE;
        nullsub_75(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAEA0); // Item locations became evident
        UpdateCamera(0);
        UpdateMinimap();
        EntityUpdateStatusSprites(target);
    }
  }
}

void HandleStairsOrb(Entity* pokemon, Entity* target)
{
  if (EntityIsValid(target)) {
    if(GetFloorType())
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAF3C);
    }
    else
    {
        if (GetEntInfo(target)->stairSpotter) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAF1C);
        }
        else
        {
            GetEntInfo(target)->stairSpotter = TRUE;
            nullsub_76(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAEC8);
            UpdateCamera(0);
            UpdateMinimap();
            EntityUpdateStatusSprites(target);
        }
    }
  }
}

void HandleRadarOrb(Entity* pokemon, Entity* target)
{
  if (EntityIsValid(target)) {
    if (GetEntInfo(target)->powerEars != 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAFD0);
    }
    else
    {
        GetEntInfo(target)->powerEars = TRUE;
        nullsub_77(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAFAC);
        UpdateCamera(0);
        UpdateMinimap();
        EntityUpdateStatusSprites(target);
    }
  }
}

void HandleLeechSeed(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;
  s32 index;

  if ((EntityIsValid(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) {
    entityInfo = GetEntInfo(target);
    if (pokemon == target) {
      pokemon = target;
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrCantLeechSeedSelfMessage);
    }
    else {
      if (HasSafeguardStatus(pokemon,target,displayMessage)) {
        return;
      }
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (MonsterIsType(target, TYPE_GRASS)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrCantLeechSeedMonMessage);
      }
      else
        {
            switch(entityInfo->leechSeedClassStatus.status)
            {
                case STATUS_DESTINY_BOND:
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAA8C);
                default:
                    entityInfo->leechSeedClassStatus.status = STATUS_LEECH_SEED;
                    entityInfo->leechSeedClassStatus.turns = CalculateStatusTurns(target, gLeechSeedTurnRange, TRUE) + 1;
                    entityInfo->leechSeedClassStatus.damageCountdown = 0;
                    nullsub_78(target);
                    entityInfo->leechSeedClassStatus.unk8 = 0xff;
                    break;
                case STATUS_LEECH_SEED:
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAE7C);
                    return;
            }
            for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
            {
                if (pokemon == gDungeon->activePokemon[index]) {
                    entityInfo->leechSeedClassStatus.unk8 = index;
                    entityInfo2 = GetEntInfo(pokemon);
                    entityInfo->leechSeedClassStatus.unk4 = entityInfo2->dungeonSpriteId;
                }
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAE58);
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
        if (EntityIsValid(target)) {
            entityInfo2 = GetEntInfo(target);
            if(entityInfo2->leechSeedClassStatus.status == STATUS_LEECH_SEED || entityInfo2->leechSeedClassStatus.status == STATUS_DESTINY_BOND)
            {
                if(entityInfo2->leechSeedClassStatus.unk4 == entityInfo->dungeonSpriteId)
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

  if (((EntityIsValid(target)) && (GetEntityType(pokemon) == ENTITY_MONSTER)) &&
     (GetEntityType(target) == ENTITY_MONSTER)) {
        entityInfo = GetEntInfo(pokemon);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
        if (entityInfo->leechSeedClassStatus.status != STATUS_DESTINY_BOND)
        {
            if (entityInfo->leechSeedClassStatus.status == STATUS_LEECH_SEED)
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA79C);

            entityInfo->leechSeedClassStatus.status = STATUS_DESTINY_BOND;
            entityInfo->leechSeedClassStatus.turns = CalculateStatusTurns(target,gDestinyBondTurnRange,TRUE) + 1;
            entityInfo->leechSeedClassStatus.damageCountdown = 0;
            nullsub_74(target);
            entityInfo->leechSeedClassStatus.unk8 = 0xff;
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBB78);
            return;
        }
        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
            if (target == gDungeon->activePokemon[index]) {
                entityInfo->leechSeedClassStatus.unk8 = index;
                entityInfo2 = GetEntInfo(target);
                entityInfo->leechSeedClassStatus.unk4 = entityInfo2->dungeonSpriteId;
            }
        }
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBB4C);
        EntityUpdateStatusSprites(target);
    }
}

void SureShotStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_SURE_SHOT) {
      entityInfo->sureShotClassStatus.status = STATUS_SURE_SHOT;
      entityInfo->sureShotClassStatus.turns = turns + 1;
      sub_8041CDC(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB73C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB764);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WhifferStatusTarget(Entity *pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_WHIFFER) {
      entityInfo->sureShotClassStatus.status = STATUS_WHIFFER;
      entityInfo->sureShotClassStatus.turns = turns + 1;
      sub_8041CEC(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB780);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB7A0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FixedDamageStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_SET_DAMAGE) {
      entityInfo->sureShotClassStatus.status = STATUS_SET_DAMAGE;
      entityInfo->sureShotClassStatus.turns = CalculateStatusTurns(target, gSetDamageTurnRange, FALSE) + 1;
      nullsub_79(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB8BC);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB8E4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void FocusEnergyStatusTarget(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->sureShotClassStatus.status != STATUS_FOCUS_ENERGY) {
      entityInfo->sureShotClassStatus.status = STATUS_FOCUS_ENERGY;
      entityInfo->sureShotClassStatus.turns = CalculateStatusTurns(target, gFocusEnergyTurnRange, FALSE) + 1;
      nullsub_80(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB900);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB924);
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

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    targetEntityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (targetEntityInfo->curseClassStatus.status == STATUS_DECOY) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB994);
    }
    else {
      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity = gDungeon->activePokemon[index];
        if ((((EntityIsValid(entity)) && (target != entity)) &&
           (u8)(GetEntInfo(entity)->curseClassStatus.status - 2U) < 2)) {
          EndCurseClassStatus(pokemon,entity,STATUS_NONE);
          DungeonRunFrameActions(0x2a);
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
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB978);

      for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
      {
        entity2 = gDungeon->activePokemon[index];
        if (EntityIsValid(entity2)) {
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


  if ((EntityIsValid(pokemon) ) && (EntityIsValid(target))) {
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
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB004);
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

  if (EntityIsValid(target)) {
    EndCurseClassStatus(pokemon,target,STATUS_SNATCH);

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->activePokemon[index];
      if ((EntityIsValid(entity)) && (GetEntInfo(entity)->curseClassStatus.status == STATUS_SNATCH)) {
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
    gDungeon->unk17B3C = targetEntityInfo->dungeonSpriteId;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB01C);
    EntityUpdateStatusSprites(target);
  }
}

void TauntStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->cringeClassStatus.status != STATUS_TAUNTED) {
      entityInfo->cringeClassStatus.status = STATUS_TAUNTED;
      entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gTauntTurnRange,TRUE) + 1;
      nullsub_73(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB9F0);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBA14);
    }
    EntityUpdateStatusSprites(target);
  }
}

void HandleStockpile(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->stockpileStage < MAX_STOCKPILE_STAGE) {
      entityInfo->stockpileStage++;
      sub_804178C(1);
      sub_8041D5C(target);
      gFormatArgs[0] = entityInfo->stockpileStage;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBA38);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBA60);
    }
    EntityUpdateStatusSprites(target);
  }
}

void InvisibleStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * targetEntityInfo;

  if (EntityIsValid(target)) {
    targetEntityInfo = GetEntInfo(target);
    if (targetEntityInfo->invisibleClassStatus.status == STATUS_TRANSFORMED) {
      SendTransformEndMessage(pokemon,target);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (targetEntityInfo->invisibleClassStatus.status != STATUS_INVISIBLE) {
      targetEntityInfo->invisibleClassStatus.status = STATUS_INVISIBLE;
      targetEntityInfo->invisibleClassStatus.turns = CalculateStatusTurns(target,gInvisibleTurnRange,FALSE) + 1;
      sub_8041D84(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBA80);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBAA0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void PerishSongTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * entityInfo;

  if (EntityIsValid(target) && !HasSafeguardStatus(pokemon, target, TRUE)) {
    nullsub_82(target);
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->perishSongTurns == 0) {
      entityInfo->perishSongTurns = CalculateStatusTurns(target,gPerishSongTurnRange,FALSE) + 1;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBB04);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBB28);
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
  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &EntityInfo->moves.moves[index];
      if ((EntityInfo->moves.moves[index].moveFlags & MOVE_FLAG_EXISTS) && (movePtr->moveFlags & MOVE_FLAG_LAST_USED)) break;
    }
    if ((index == MAX_MON_MOVES) && ((EntityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0)) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBBD4);
    }
    else {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (EntityInfo->cringeClassStatus.status != STATUS_ENCORE) {
        EntityInfo->cringeClassStatus.status = STATUS_ENCORE;
        EntityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gEncoreTurnRange,TRUE) + 1;
        nullsub_83(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBB94);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBBB8);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void sub_8078A58(Entity *pokemon, Entity *target, s32 param_3, s32 param_4)
{
    EntityInfo *targetInfo;
    FixedPoint bellyBefore;

    if (!EntityIsValid(target))
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
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBD9C);
        }
        else
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBE3C);
    }
    else {
        FixedPoint sp8 = IntToFixedPoint(param_3);
        bellyBefore = targetInfo->belly;
        targetInfo->belly = FixedPoint_Subtract(bellyBefore, sp8);

        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);

        if (FixedPointToInt(bellyBefore) != FixedPointToInt(targetInfo->belly)) {
            nullsub_84(target);
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBD78);
        }
        else
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBE40);
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

    if (!EntityIsValid(target)) {
        return;
    }
    targetInfo = GetEntInfo(target);
    if ((!targetInfo->isTeamLeader) && (HasHeldItem(target,0x1b))) {
        if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBEA0);
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
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBE64); // $m0's belly filled up full!
        }
        if (FixedPointToInt(sp_0x20) == FixedPointToInt(targetInfo->maxBelly)) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBDF0); // $m0's belly won't get any bigger!
        }
        else {
            sub_8041DB0(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBDC4); // m0's max belly size increased!
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
            if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBE14); // $m0's belly didn't change!
        }
        else {
            if (FixedPointToInt(*bellyPtr) >= FixedPointToInt(*puVar8)) {
                if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBE64); // $m0's belly filled up full!
            }
            else
            {
                if (displayMessage) TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBE84); // $m0's belly was filled!
            }
        }
    }
    EntityUpdateStatusSprites(target);
}

void MuzzleTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->muzzled.muzzled != TRUE) {
        entityInfo->muzzled.muzzled = TRUE;
        entityInfo->muzzled.turns = CalculateStatusTurns(target,gMuzzledTurnRange, TRUE) + 1;
        nullsub_86(target);
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBF68);
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBF84);
    }
    EntityUpdateStatusSprites(target);
  }
}

void TransformStatusTarget(Entity * pokemon, Entity * target)
{
    s16 species;
    s32 iVar5;
    s32 apparentID;
    s16 apparentID_s16;
    s32 index;
    EntityInfo *entityInfo;
    OpenedFile *sprite;
    SpawnPokemonData auStack544[64];

    if (!EntityIsValid(target))
        return;

    entityInfo = GetEntInfo(target);

    if (entityInfo->invisibleClassStatus.status == STATUS_TRANSFORMED)
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBF04);
    else {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        iVar5 = GetAvailableMonsToTransform(auStack544, 0);

        if (iVar5 == 0)
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBEE4);
        else {
            sprite = NULL;

            for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
                species = ExtractSpeciesIndex(&auStack544[DungeonRandInt(iVar5)]);
                apparentID_s16 = GetMonsterApparentID(target, species);
                apparentID = apparentID_s16;

                if (apparentID != entityInfo->apparentID && sub_806AA0C(apparentID, 1)) {
                    sprite = GetSpriteData(apparentID);
                    if (sprite != NULL)
                        break;
                }
            }

            if (index == DUNGEON_MAX_POKEMON || sprite == NULL)
                TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBEE4);
            else {
                entityInfo->apparentID = apparentID;
                target->axObj.spriteFile = sprite;
                entityInfo->invisibleClassStatus.status = STATUS_TRANSFORMED;
                entityInfo->invisibleClassStatus.turns = CalculateStatusTurns(target, gTransformedTurnRange, TRUE) + 1;
                DetermineMonsterShadow(target);
                nullsub_87(target);
                sub_806CCB4(target, sub_806CEBC(target));
                CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[1], entityInfo->apparentID);
                TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FBEC0);
                EntityUpdateStatusSprites(target);
            }
        }
    }
}

void MobileStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;


  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);

    if (entityInfo->invisibleClassStatus.status == STATUS_TRANSFORMED) {
        SendTransformEndMessage(pokemon,target);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->invisibleClassStatus.status != STATUS_MOBILE) {
        entityInfo->invisibleClassStatus.status = STATUS_MOBILE;
        entityInfo->invisibleClassStatus.turns = CalculateStatusTurns(target,gMobileTurnRange, FALSE) + 1;
        nullsub_88(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBF28);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBF50);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ExposeStatusTarget(Entity * pokemon, Entity * target, s16 param_3)
{
  EntityInfo *entityInfo;
  s32 param_3_s16;
  s32 param_3_s16_2;
  bool32 flag;
  bool32 flag2;

  param_3_s16 = param_3;
  param_3_s16_2 = param_3_s16;
  flag = FALSE;
  flag2 = FALSE;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->hitChanceStages[1] > 10) {
      entityInfo->hitChanceStages[1] = 10;
      flag = TRUE;
    }
    if(flag)
    {
        sub_8041DD8(target,param_3_s16);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC000);
        flag2 = TRUE;
    }
    if (entityInfo->exposed) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBFB8);
    }
    else
    {
      if (!flag2) {
        sub_8041DD8(target,param_3_s16_2);
      }
      if (!MonsterIsType(target, TYPE_GHOST)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBFD8);
      }
      else {
        entityInfo->exposed = TRUE;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBF9C);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void IdentityItemHolders(Entity *pokemon, Entity *target)
{
  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    UNUSED EntityInfo *entityInfo = GetEntInfo(target);
    if (!gDungeon->unk644.itemHoldersIdentified) {
        nullsub_89(target);
        gDungeon->unk644.itemHoldersIdentified = TRUE;
        EntityUpdateStatusSprites(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC028);
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC054);
    }
  }
}

void BlindTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->blinkerClassStatus.status != STATUS_BLINKER) {
        entityInfo->blinkerClassStatus.status = STATUS_BLINKER;
        entityInfo->blinkerClassStatus.turns = CalculateStatusTurns(target,gBlinkerTurnRange, TRUE) + 1;
        sub_8041E0C(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB7F4);
        DungeonRunFrameActions(0x31);
        UpdateTrapsVisibility();
        UpdateMinimap();
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB810);
    }
    EntityUpdateStatusSprites(target);
  }
}

void CrossEyeVisionTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;


  if (EntityIsValid(target)) {
    if(!HasSafeguardStatus(pokemon, target, TRUE))
    {
        entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (entityInfo->blinkerClassStatus.status != STATUS_CROSS_EYED) {
            sub_8041E1C(target);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB834);
            entityInfo->blinkerClassStatus.status = STATUS_CROSS_EYED;
            entityInfo->blinkerClassStatus.turns = CalculateStatusTurns(target,gCrossEyedTurnRange, TRUE) + 1;
            UpdateCamera(0x1);
            UpdateTrapsVisibility();
            UpdateMinimap();
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB85C);
        }
        EntityUpdateStatusSprites(target);
    }
  }
}

void RestoreVisionTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;


  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->blinkerClassStatus.status != STATUS_EYEDROPS) {
        entityInfo->blinkerClassStatus.status = STATUS_EYEDROPS;
        entityInfo->blinkerClassStatus.turns = CalculateStatusTurns(target,gEyedropsTurnRange, FALSE) + 1;
        sub_8041E3C(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB880);
        DungeonRunFrameActions(0x31);
        UpdateTrapsVisibility();
        UpdateMinimap();
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB89C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RestorePPTarget(Entity * pokemon,Entity * target, s32 param_3)
{
  volatile s32 PP;
  volatile s32 basePP;
  Move *movePtr;
  Move *movePtr1;
  s32 index;
  bool8 PPChanged;
  EntityInfo *entityInfo;

  PPChanged = FALSE;
  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &entityInfo->moves.moves[index];
      movePtr1 = movePtr;
      if ((movePtr->moveFlags & MOVE_FLAG_EXISTS)) {
        PP = movePtr->PP;
        basePP = GetMoveBasePP(movePtr1);
        if (PP < basePP) {
          PP += param_3;
          if (PP > basePP) {
            PP = basePP;
          }
          movePtr->PP = PP;
          PPChanged = TRUE;
        }
      }
    }
    if (PPChanged) {
      sub_8041E4C(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDBD0);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDBF0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseAtkStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);

    entityInfo = GetEntInfo(target);
    oldStat = entityInfo->atk[0];
    oldStat1 = oldStat;

    newStat = entityInfo->atk[0] + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo->atk[0] = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E60(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC33C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC360);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseSpAtkStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);

    entityInfo = GetEntInfo(target);
    oldStat = entityInfo->atk[1];
    oldStat1 = oldStat;

    newStat = entityInfo->atk[1] + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo->atk[1] = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E74(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC388);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC3B4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseDefStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);

    entityInfo = GetEntInfo(target);
    oldStat = entityInfo->def[0];
    oldStat1 = oldStat;

    newStat = entityInfo->def[0] + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo->def[0] = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E84(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC3D8);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC3FC);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseSpDefStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);

    entityInfo = GetEntInfo(target);
    oldStat = entityInfo->def[1];
    oldStat1 = oldStat;

    newStat = entityInfo->def[1] + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo->def[1] = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E94(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC428);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC454);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LongTossStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
    if (entityInfo->longTossClassStatus.status != STATUS_LONG_TOSS) {
      entityInfo->longTossClassStatus.status = STATUS_LONG_TOSS;
      sub_8041EA4(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD20C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD22C);
    }
    EntityUpdateStatusSprites(target);
}

void PierceStatusTarget(Entity * pokemon, Entity * target)
{
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
    if (entityInfo->longTossClassStatus.status != STATUS_PIERCE) {
      entityInfo->longTossClassStatus.status = STATUS_PIERCE;
      sub_8041EB4(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD254);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD27C);
    }
    EntityUpdateStatusSprites(target);
}

