#include "global.h"
#include "globaldata.h"
#include "move_orb_effects_1.h"
#include "dungeon_message.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "status_checks.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "dungeon_misc.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_vram.h"
#include "dungeon_pos_data.h"
#include "dungeon_data.h"
#include "dungeon_8041AD0.h"

u8 sub_8075BF4(Entity * pokemon, s32 sleepClassStatusTurns)
{
  EntityInfo *entityInfo;
  u32 uVar4;

  uVar4 = 0;
  if (!EntityIsValid(pokemon)){
    return uVar4;
  }
  else
  {
    entityInfo = GetEntInfo(pokemon);

    if(entityInfo->sleepClassStatus.status != STATUS_NIGHTMARE && entityInfo->sleepClassStatus.status != STATUS_SLEEP)
    {
        entityInfo->sleepClassStatus.status = STATUS_SLEEP;
        if ((sleepClassStatusTurns != 0x7f) && AbilityIsActive(pokemon, ABILITY_EARLY_BIRD) &&
            (sleepClassStatusTurns = sleepClassStatusTurns / 2, sleepClassStatusTurns < 1)) {
            sleepClassStatusTurns = 1;
        }
        entityInfo->sleepClassStatus.turns = sleepClassStatusTurns;
    }
    else if(entityInfo->sleepClassStatus.status == STATUS_SLEEP)
        uVar4 = 1;
    else if(entityInfo->sleepClassStatus.status == STATUS_NIGHTMARE)
        uVar4 = 2;
    EntityUpdateStatusSprites(pokemon);
  }
  return uVar4;
}

void SleepStatusTarget(Entity * pokemon, Entity * target, s32 turns, u8 displayMessage)
{
  u8 sleep;
  u8 cVar2;


  if (!CannotSleep(pokemon,target,1,displayMessage)) {
    sleep = GetEntInfo(target)->sleepClassStatus.status;
    if (sleep == STATUS_SLEEPLESS) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB380);
    }
    else if (sleep == STATUS_NAPPING) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB384);
    }
    else {
      sub_8041AF4(target);
      cVar2 = sub_8075BF4(target, turns);
      sub_806CE68(target,8);

      if (cVar2 == 1)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB338);
      else if (cVar2 == 2)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB35C);
      else
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB318);
    }
  }
}

bool8 CannotSleep(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage)
{
    if ((!EntityIsValid(target)) ||
        ((SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0), param_3 != 0 &&
        (HasSafeguardStatus(pokemon,target,displayMessage))))) {
        return TRUE;
    }
    else if (IQSkillIsEnabled(target, IQ_NONSLEEPER)) {
        if (displayMessage) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCD54);
        }
        return TRUE;
    }
    else if (AbilityIsActive(target, ABILITY_INSOMNIA)) {
        if (displayMessage) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCD58);
        }
        return TRUE;
    }
    else if (AbilityIsActive(target, ABILITY_VITAL_SPIRIT)) {
        if (displayMessage) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCD88);
        }
        return TRUE;
    }
    else if (HasHeldItem(target, ITEM_INSOMNISCOPE)) {
        if (displayMessage) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD548);
        }
        return TRUE;
    }
    return FALSE;
}

void NightmareStatusTarget(Entity * pokemon, Entity * target, s32 turns)
{
  bool8 hasNightmare;
  EntityInfo *entityInfo;

  hasNightmare = FALSE;
  if (!CannotSleep(pokemon, target, 1, TRUE)) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->sleepClassStatus.status != STATUS_SLEEPLESS) {
      sub_8041EC8(target);
      if (entityInfo->sleepClassStatus.status != STATUS_NIGHTMARE) {
        entityInfo->sleepClassStatus.turns = turns;
        if ((AbilityIsActive(target, ABILITY_EARLY_BIRD)) && (entityInfo->sleepClassStatus.turns >>= 1, entityInfo->sleepClassStatus.turns == 0)) {
          entityInfo->sleepClassStatus.turns = 1;
        }
      }
      else
      {
        hasNightmare = TRUE;
      }
      entityInfo->sleepClassStatus.status = STATUS_NIGHTMARE;
      sub_806CE68(target,8);
      if (hasNightmare) {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3CC);
      }
      else {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3A4);
      }
    }
    else
    {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3D0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void NappingStatusTarget(Entity * pokemon, Entity * target, s32 turns)
{
  bool8 isSleeping;
  EntityInfo *entityInfo;

  isSleeping = FALSE;
  if (!CannotSleep(pokemon, target, 0, TRUE)) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->sleepClassStatus.status != STATUS_SLEEPLESS) {
      sub_8041ED8(target);
      if (entityInfo->sleepClassStatus.status == STATUS_NONE || entityInfo->sleepClassStatus.status == STATUS_YAWNING) {
        entityInfo->sleepClassStatus.turns = turns;
        if ((AbilityIsActive(target, ABILITY_EARLY_BIRD)) && (entityInfo->sleepClassStatus.turns >>= 1, entityInfo->sleepClassStatus.turns == 0)) {
          entityInfo->sleepClassStatus.turns = 1;
        }
      }
      else
      {
        isSleeping = TRUE;
      }
      entityInfo->sleepClassStatus.status = STATUS_NAPPING;
      sub_806CE68(target, 8);
      if (isSleeping) {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB360);
      }
      else {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB31C);
      }
    }
    else
    {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB388);
    }
    EntityUpdateStatusSprites(target);
  }
}

void YawnedStatusTarget(Entity * pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (CannotSleep(pokemon,target,1,TRUE)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  if (entityInfo->sleepClassStatus.status == STATUS_NONE) {
    entityInfo->sleepClassStatus.status = STATUS_YAWNING;
    entityInfo->sleepClassStatus.turns = turns;
    nullsub_91(target);
    sub_806CE68(target, 8);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3E0);
  }
  else if (((entityInfo->sleepClassStatus.status == STATUS_SLEEP) || (entityInfo->sleepClassStatus.status == STATUS_NIGHTMARE)) || (entityInfo->sleepClassStatus.status == STATUS_NAPPING)) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB418);
  }
  else if (entityInfo->sleepClassStatus.status == STATUS_SLEEPLESS) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3F8);
  }
  else {
    if (entityInfo->sleepClassStatus.status == STATUS_YAWNING)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB414);
    else
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB3E0);
  }
  EntityUpdateStatusSprites(target);
}

void SleeplessStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;
  bool8 isAsleep;

  isAsleep = FALSE;
  if (!EntityIsValid(target)) {
    return;
  }

  entityInfo = GetEntInfo(target);
  if ((entityInfo->sleepClassStatus.status == STATUS_SLEEP) || (entityInfo->sleepClassStatus.status == STATUS_NAPPING) || (entityInfo->sleepClassStatus.status == STATUS_NIGHTMARE)) {
    isAsleep = TRUE;
  }
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);

  if (entityInfo->sleepClassStatus.status != STATUS_SLEEPLESS)
  {
    entityInfo->sleepClassStatus.status = STATUS_SLEEPLESS;
    entityInfo->sleepClassStatus.turns = CalculateStatusTurns(target, gSleeplessTurnRange, FALSE) + 1;
    entityInfo->unk165 = 0xFF;
    entityInfo->unk164 = 0xFF;
    sub_8041EE8(target);
    sub_806CE68(target,8);
    if(isAsleep)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB41C);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB458);
  }
  else
  {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB43C);
  }
  EntityUpdateStatusSprites(target);
}

void PausedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, s32 turns, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  if ((param_3 != 0) && (HasSafeguardStatus(pokemon,target,displayMessage))) {
    return;
  }
  SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
  if (entityInfo->cringeClassStatus.status != STATUS_PAUSED) {
    entityInfo->cringeClassStatus.status = STATUS_PAUSED;
    entityInfo->cringeClassStatus.turns = turns + 1;
    nullsub_72(target);
    if (turns == 1) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB480);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB4D4);
    }
  }
  else {
    if (turns == 1) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB4B0);
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB4F0);
    }
  }
  EntityUpdateStatusSprites(target);
}

void InfatuateStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;


  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
      if (AbilityIsActive(target,ABILITY_OBLIVIOUS)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (displayMessage) {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCC4C);
        }
      }
      else
      {
        SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
        if (entityInfo->cringeClassStatus.status != STATUS_INFATUATED) {
          entityInfo->cringeClassStatus.status = STATUS_INFATUATED;
          entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target,gInfatuatedTurnRange,TRUE) + 1;
          sub_8041EF8(target);
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB50C);
        }
        else {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB52C);
        }
        EntityUpdateStatusSprites(target);
      }
    }
  }
}

void BurnedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage)
{
  bool8 isNotBurned;
  bool8 hasSynchronized;
  EntityInfo *entityInfo;
  const Tile *tile_1;
  const Tile *tile_2;
  Entity *entity;
  s32 index;

  if (!EntityIsValid(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = GetEntInfo(target);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
    if (AbilityIsActive(target, ABILITY_WATER_VEIL)) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCE5C);
    }
    else
    {
      if (MonsterIsType(target, TYPE_FIRE)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCE84);
      }
      else
      {
        tile_1 = GetTileAtEntitySafe(target);
        if (((tile_1->terrainFlags & (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL)) == TERRAIN_TYPE_SECONDARY) &&
           (gDungeonWaterType[gDungeon->tileset] != DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEBBC);
           }
        else
        {
            isNotBurned = TRUE;
            if (entityInfo->burnClassStatus.status != STATUS_BURN) {
                entityInfo->burnClassStatus.status = STATUS_BURN;
                entityInfo->burnClassStatus.turns = CalculateStatusTurns(target,gBurnTurnRange,TRUE) + 1;
                entityInfo->burnClassStatus.damageCountdown = 0;
                entityInfo->burnClassStatus.badlyPoisonedDamageCount = 0;
                isNotBurned = FALSE;
                if (param_3 != 0) {
                    sub_8041C34(target);
                }
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB548);
            }
            else {
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB564);
            }
            EntityUpdateStatusSprites(target);

            if (!AbilityIsActive(target, ABILITY_SYNCHRONIZE)) {
                return;
            }

            if (isNotBurned) {
                return;
            }

            hasSynchronized = FALSE;

            for(index = 0; index < NUM_DIRECTIONS; index++)
            {
                tile_2 = GetTile(target->pos.x +
                                    gAdjacentTileOffsets[index].x,
                                    target->pos.y + gAdjacentTileOffsets[index].y);
                entity = tile_2->monster;
                if ((EntityIsValid(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                    if (!hasSynchronized) {
                        hasSynchronized = TRUE;
                        SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
                        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FF01C);
                    }
                    if (GetTreatmentBetweenMonstersIgnoreStatus(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
                        // Recurse with the new target
                        BurnedStatusTarget(pokemon,entity,1,displayMessage);
                    }
                }
            }
        }
      }
    }
  }
}

void PoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  bool8 isNotPoisoned;
  bool8 hasSynchronized;
  EntityInfo *entityInfo;
  const Tile *tile;
  Entity *entity;
  s32 index;

  if (!EntityIsValid(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = GetEntInfo(target);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
    if (HasHeldItem(target, ITEM_PECHA_SCARF)) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD524);
    }
    else
    {
      if (AbilityIsActive(target, ABILITY_IMMUNITY)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCEB0);
      }
      else
      {
        if(MonsterIsType(target, TYPE_POISON) || MonsterIsType(target, TYPE_STEEL)){
            if (displayMessage)
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCEDC);
        }
        else
        {
            isNotPoisoned = TRUE;

            if(entityInfo->burnClassStatus.status != STATUS_BADLY_POISONED)
            {
                if(entityInfo->burnClassStatus.status != STATUS_POISONED)
                {
                    entityInfo->burnClassStatus.status = STATUS_POISONED;
                    entityInfo->burnClassStatus.turns = CalculateStatusTurns(target,gPoisonTurnRange,TRUE) + 1;
                    entityInfo->burnClassStatus.damageCountdown = 0;
                    entityInfo->burnClassStatus.badlyPoisonedDamageCount = 0;
                    isNotPoisoned = FALSE;
                    sub_8041C6C(target);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB598);
                    sub_806CE94(target, 8);
                }
                else
                {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB5D4);
                }
            }
            else
            {
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB5F8);
            }

            if ((AbilityIsActive(target, ABILITY_SYNCHRONIZE)) && !isNotPoisoned)
            {
                hasSynchronized = FALSE;

                for(index = 0; index < NUM_DIRECTIONS; index++)
                {
                    tile = GetTile(target->pos.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->pos.y + gAdjacentTileOffsets[index].y);
                    entity = tile->monster;
                    if ((EntityIsValid(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
                            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FF01C);
                        }
                        if (GetTreatmentBetweenMonstersIgnoreStatus(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
                            // Recurse with the new target
                            PoisonedStatusTarget(pokemon,entity,displayMessage);
                        }
                    }
                }
            }
            EntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void BadlyPoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  bool8 isNotBadlyPoisoned;
  bool8 hasSynchronized;
  EntityInfo *entityInfo;
  const Tile *tile;
  Entity *entity;
  s32 index;

  if (!EntityIsValid(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = GetEntInfo(target);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
    if (HasHeldItem(target, ITEM_PECHA_SCARF)) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD524);
    }
    else
    {
      if (AbilityIsActive(target, ABILITY_IMMUNITY)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCEB0);
      }
      else
      {
        if(MonsterIsType(target, TYPE_POISON) || MonsterIsType(target, TYPE_STEEL)){
            if (displayMessage)
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCEDC);
        }
        else
        {
            isNotBadlyPoisoned = TRUE;

            if(entityInfo->burnClassStatus.status != STATUS_BADLY_POISONED)
            {
                    entityInfo->burnClassStatus.status = STATUS_BADLY_POISONED;
                    entityInfo->burnClassStatus.turns = CalculateStatusTurns(target,gBadPoisonTurnRange,TRUE) + 1;
                    entityInfo->burnClassStatus.damageCountdown = 0;
                    entityInfo->burnClassStatus.badlyPoisonedDamageCount = 0;
                    isNotBadlyPoisoned = FALSE;
                    sub_8041C7C(target);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB5B4);
                    sub_806CE94(target, 8);
            }
            else
            {
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB5F8);
            }

            if ((AbilityIsActive(target, ABILITY_SYNCHRONIZE)) && !isNotBadlyPoisoned)
            {
                hasSynchronized = FALSE;

                for(index = 0; index < NUM_DIRECTIONS; index++)
                {
                    tile = GetTile(target->pos.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->pos.y + gAdjacentTileOffsets[index].y);
                    entity = tile->monster;
                    if ((EntityIsValid(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
                            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FF01C);
                        }
                        if (GetTreatmentBetweenMonstersIgnoreStatus(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
                            // Recurse with the new target
                            BadlyPoisonedStatusTarget(pokemon,entity,displayMessage);
                        }
                    }
                }
            }
            EntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void FrozenStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  const Tile *tile;

  if (!EntityIsValid(target)) {
    return;
  }

  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
  entityInfo = GetEntInfo(target);

  if ((entityInfo->frozenClassStatus.status != STATUS_FROZEN) && !HasSafeguardStatus(pokemon,target,displayMessage)) {
    if (AbilityIsActive(target, ABILITY_MAGMA_ARMOR)) {
      if (displayMessage)
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCDE0);
    }
    else
    {
      if (MonsterIsType(target, TYPE_ICE)) {
        if (displayMessage)
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCE00);
      }
      else
      {
        tile = GetTileAtEntitySafe(target);
        if (((tile->terrainFlags & (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL)) == TERRAIN_TYPE_SECONDARY) &&
           (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCE34);
           }
        else
        {
            if (entityInfo->frozenClassStatus.status == STATUS_WRAP || entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
                sub_8076CB4(entityInfo->unk9C);
            }
            sub_8041F08(target);
            entityInfo->frozenClassStatus.status = STATUS_FROZEN;
            entityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gFreezeTurnRange,TRUE) + 1;
            entityInfo->frozenClassStatus.damageCountdown = 0;
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB610);
            EntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void SqueezedStatusTarget(Entity * pokemon, Entity * target, s32 param_3, bool32 displayMessage)
{
  EntityInfo *entityInfo;
  s32 param_3_s32 = (s16) param_3;
  bool8 displayMessage_u8 = displayMessage;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage_u8))) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP || entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
      sub_8076CB4(entityInfo->unk9C);
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_INGRAIN) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA844);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->frozenClassStatus.status != STATUS_CONSTRICTION) {
      entityInfo->frozenClassStatus.status = STATUS_CONSTRICTION;
      entityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gConstrictionTurnRange,TRUE) + 1;
      entityInfo->frozenClassStatus.damageCountdown = 0;
      entityInfo->frozenClassStatus.unk4 = param_3_s32;
      nullsub_71(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB628);
      sub_806CE94(target,8);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB64C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ImmobilizedStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP || entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
      sub_8076CB4(entityInfo->unk9C);
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_INGRAIN) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA844);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->frozenClassStatus.status != STATUS_SHADOW_HOLD) {
      entityInfo->frozenClassStatus.status = STATUS_SHADOW_HOLD;
      entityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gShadowHoldTurnRange,TRUE) + 1;
      entityInfo->frozenClassStatus.damageCountdown = 0;
      nullsub_70(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB668);
      sub_806CE94(target,8);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB688);
    }
    EntityUpdateStatusSprites(target);
  }
}

void IngrainedStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP || entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
      sub_8076CB4(entityInfo->unk9C);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->frozenClassStatus.status != STATUS_INGRAIN) {
      entityInfo->frozenClassStatus.status = STATUS_INGRAIN;
      entityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gIngrainTurnRange,TRUE) + 1;
      entityInfo->frozenClassStatus.damageCountdown = 0;
      nullsub_90(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB6A4);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB6C0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WrapTarget(Entity *pokemon, Entity *target)
{
    EntityInfo *targetEntityInfo;
    EntityInfo *pokemonEntityData;

    if (!EntityIsValid(target))
        return;
    if (HasSafeguardStatus(pokemon, target, TRUE))
        return;

    pokemonEntityData = GetEntInfo(pokemon);
    targetEntityInfo = GetEntInfo(target);
    if (pokemonEntityData->frozenClassStatus.status != STATUS_WRAP
        && pokemonEntityData->frozenClassStatus.status != STATUS_WRAPPED
        && targetEntityInfo->frozenClassStatus.status != STATUS_WRAP
        && targetEntityInfo->frozenClassStatus.status != STATUS_WRAPPED)
    {
        pokemonEntityData->frozenClassStatus.status = STATUS_WRAP;
        pokemonEntityData->frozenClassStatus.turns = 0x7f;
        pokemonEntityData->frozenClassStatus.damageCountdown = 0;
        targetEntityInfo->frozenClassStatus.status = STATUS_WRAPPED;
        targetEntityInfo->frozenClassStatus.turns = CalculateStatusTurns(target, gWrapTurnRange, TRUE) + 1;
        targetEntityInfo->frozenClassStatus.damageCountdown = 0;
        pokemonEntityData->unk9C = gDungeon->unk37F4;
        targetEntityInfo->unk9C = gDungeon->unk37F4;
        gDungeon->unk37F4++;
        nullsub_69(pokemon, target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB6D8);
        sub_806CE94(target,8);
    }
    else {
        if (pokemonEntityData->frozenClassStatus.status == STATUS_WRAP) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB6FC);
        }
        if (targetEntityInfo->frozenClassStatus.status == STATUS_WRAP) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB6FC);
        }
        if (pokemonEntityData->frozenClassStatus.status == STATUS_WRAPPED) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB718);
        }
        if (targetEntityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB718);
        }
    }

    EntityUpdateStatusSprites(target);
}

void sub_8076CB4(s32 param_1)
{
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeon->activePokemon[index];
    if (EntityIsValid(entity)) {
      entityInfo = GetEntInfo(entity);
      if (entityInfo->unk9C == param_1) {
        if ((u8)(entityInfo->frozenClassStatus.status - 3U) < 2) {
          entityInfo->frozenClassStatus.status = STATUS_NONE;
        }
        entityInfo->unk9C = 0;
      }
      EntityUpdateStatusSprites(entity);
    }
  }
}

void PetrifiedStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * targetEntityInfo;
  EntityInfo * entityInfo;
  Entity * entity;
  s32 index;

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    sub_8041C08(target);
    targetEntityInfo = GetEntInfo(target);
    if ((u8)(targetEntityInfo->frozenClassStatus.status - 3U) < 2) {
      sub_8076CB4(targetEntityInfo->unk9C);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (targetEntityInfo->frozenClassStatus.status != STATUS_PETRIFIED) {
      targetEntityInfo->frozenClassStatus.status = STATUS_PETRIFIED;
      if (targetEntityInfo->isTeamLeader) {
        targetEntityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gPetrifiedLeaderTurnRange,TRUE) + 1;
      }
      else {
        targetEntityInfo->frozenClassStatus.turns = CalculateStatusTurns(target,gPetrifiedTurnRange,TRUE) + 1;
      }
      targetEntityInfo->frozenClassStatus.damageCountdown = 0;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB7BC);

    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB7DC);
    }
    if (targetEntityInfo->isNotTeamMember) {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityIsValid(entity)) {
          entityInfo = GetEntInfo(entity);
          if ((entityInfo->aiTarget.aiObjective == AI_CHASE_TARGET) && (entityInfo->aiTarget.aiTarget == target)) {
            entityInfo->aiTarget.aiObjective = AI_STAND_STILL;
            entityInfo->aiTarget.aiTarget = NULL;
            entityInfo->aiTarget.aiTargetSpawnGenID = 0;
            entityInfo->aiTarget.aiTargetingEnemy = FALSE;
          }
        }
      }
    }
    EntityUpdateStatusSprites(target);
  }
}

void LowerOffensiveStat(Entity * pokemon, Entity * target, struct StatIndex stat, s32 nStages, u8 checkProtected, bool8 logMsgProtected)
{
    EntityInfo *entityInfo;
    s32 newStage;

    if (!EntityIsValid(target))
        return;

    if (stat.id != STAT_INDEX_PHYSICAL) {
        strcpy(gFormatBuffer_Items[0], gUnknown_80FC0C8);
    }
    else {
        strcpy(gFormatBuffer_Items[0], gUnknown_80FC0B8);
    }

    if (checkProtected) {
        if (IsProtectedFromStatDrops(pokemon,target,logMsgProtected))
            return;

        if (HasHeldItem(target, ITEM_TWIST_BAND)) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD550);
            return;
        }

        if (AbilityIsActive(target, ABILITY_HYPER_CUTTER) && stat.id == STAT_INDEX_PHYSICAL) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCA60);
            return;
        }
    }

    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8041F28(target,stat);
    if (nStages == 1) {
        strcpy(gFormatBuffer_Items[1], gUnknown_80FC0E4);
    }
    else {
        strcpy(gFormatBuffer_Items[1], gUnknown_80FC0D4);
    }

    newStage = entityInfo->offensiveStages[stat.id];
    newStage -= nStages;
    if (newStage < 0) {
        newStage = 0;
    }

    if (entityInfo->offensiveStages[stat.id] != newStage) {
        entityInfo->offensiveStages[stat.id] = newStage;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC15C);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC274);
    }

    EntityUpdateStatusSprites(target);
}

void LowerDefensiveStat(Entity * pokemon, Entity * target, struct StatIndex stat, s32 nStages, bool8 checkProtected, bool8 logMsgProtected)
{
    EntityInfo *entityInfo;
    s32 newStage;

    if (!EntityIsValid(target))
        return;

    if (stat.id != STAT_INDEX_PHYSICAL) {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC0AC);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC09C);
    }

    if (checkProtected) {
        if (IsProtectedFromStatDrops(pokemon,target,logMsgProtected))
            return;
    }

    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8041F4C(target,stat);
    if (nStages == 1) {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0E4);
    }
    else {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0D4);
    }

    newStage = entityInfo->defensiveStages[stat.id];
    newStage -= nStages;
    if (newStage < 0) {
        newStage = 0;
    }

    if (entityInfo->defensiveStages[stat.id] != newStage) {
        entityInfo->defensiveStages[stat.id] = newStage;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC158);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC248);
    }

    EntityUpdateStatusSprites(target);
}

void RaiseAttackStageTarget(Entity * pokemon, Entity * target, struct StatIndex stat, s32 increment)
{
    EntityInfo *entityInfo;
    s32 attackStage = increment;

    if (!EntityIsValid(target)) {
        return;
    }
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8041F70(target,stat);
    if (stat.id != STAT_INDEX_PHYSICAL) {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC0C8);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC0B8);
    }

    if (increment == 1) {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0E4);
    }
    else {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0D4);
    }

    attackStage = entityInfo->offensiveStages[stat.id];
    attackStage = attackStage + increment;
    if (attackStage >= MAX_STAT_STAGE) {
        attackStage = MAX_STAT_STAGE;
    }
    if (entityInfo->offensiveStages[stat.id] != attackStage) {
        entityInfo->offensiveStages[stat.id] = attackStage;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC13C);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC270);
    }
    EntityUpdateStatusSprites(target);
}

void RaiseDefenseStageTarget(Entity * pokemon, Entity * target, struct StatIndex stat, s32 increment)
{
    EntityInfo *entityInfo;
    s32 defenseStage = increment;

    if (!EntityIsValid(target)) {
        return;
    }
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8041F94(target,stat);
    if (stat.id != STAT_INDEX_PHYSICAL) {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC0AC);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC09C);
    }

    if (increment == 1) {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0E4);
    }
    else {
        strcpy(gFormatBuffer_Items[1],gUnknown_80FC0D4);
    }

    defenseStage = entityInfo->defensiveStages[stat.id];
    defenseStage = defenseStage + increment;
    if (defenseStage >= MAX_STAT_STAGE) {
        defenseStage = MAX_STAT_STAGE;
    }
    if (entityInfo->defensiveStages[stat.id] != defenseStage) {
        entityInfo->defensiveStages[stat.id] = defenseStage;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC138);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC21C);
    }
    EntityUpdateStatusSprites(target);
}

u8 GetFlashFireStatus(Entity *pokemon)
{
    if (!EntityIsValid(pokemon) || !AbilityIsActive(pokemon, ABILITY_FLASH_FIRE))
    {
        return FLASH_FIRE_STATUS_NONE;
    }
    if (GetEntInfo(pokemon)->flashFireBoost > 1)
    {
        return FLASH_FIRE_STATUS_MAXED;
    }
    return FLASH_FIRE_STATUS_NOT_MAXED;
}

void UpdateFlashFireBoost(Entity * pokemon, Entity *target)
{
    s32 flashFireBoost;

    if (EntityIsValid(target)) {
        EntityInfo * entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        flashFireBoost = entityInfo->flashFireBoost;
        if (++flashFireBoost >= 2) {
            flashFireBoost = 2;
        }
        if (entityInfo->flashFireBoost != flashFireBoost) {
            entityInfo->flashFireBoost = flashFireBoost;
            sub_8041C58(target);
        }
        EntityUpdateStatusSprites(target);
    }
}

void ChangeAttackMultiplierTarget(Entity *pokemon, Entity *target, struct StatIndex stat, s24_8 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s24_8 oldMulti;

  if (!EntityIsValid(target)) {
    return;
  }

  if (stat.id != STAT_INDEX_PHYSICAL) {
    strcpy(gFormatBuffer_Items[0],gUnknown_80FC0C8);
  }
  else {
    strcpy(gFormatBuffer_Items[0],gUnknown_80FC0B8);
  }
  if (F248LessThanInt(param_4, 1) && IsProtectedFromStatDrops(pokemon,target,displayMessage)) {
    return;
  }

  if ((HasHeldItem(target,ITEM_TWIST_BAND)) && F248LessThanInt(param_4, 1)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD550);
    return;
  }

  if (AbilityIsActive(target, ABILITY_HYPER_CUTTER) && (stat.id == STAT_INDEX_PHYSICAL) && F248LessThanInt(param_4, 1)) {
    if (displayMessage) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCA60);
    }
    return;
  }

  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  oldMulti = entityInfo->offensiveMultipliers[stat.id];

  if (F248LessThanInt(param_4, 1)) {
    sub_8041FD8(target,stat);
  }
  else {
    sub_8041FB4(target,stat);
  }

  entityInfo->offensiveMultipliers[stat.id] = s24_8_mul(entityInfo->offensiveMultipliers[stat.id],param_4);

  if (F248LessThanFloat(entityInfo->offensiveMultipliers[stat.id], 0.01)) {
    entityInfo->offensiveMultipliers[stat.id] = FloatToF248(0.01);
  }
  if (FloatLessThanF248(99.99, entityInfo->offensiveMultipliers[stat.id])) {
    entityInfo->offensiveMultipliers[stat.id] = FloatToF248(99.99);
  }
  if (F248GreaterThan(oldMulti, entityInfo->offensiveMultipliers[stat.id])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC11C);
  }
  else if (F248LessThan(oldMulti, entityInfo->offensiveMultipliers[stat.id])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC118);
  }
  else
  {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC184);
  }
  EntityUpdateStatusSprites(target);
}

void ChangeDefenseMultiplierTarget(Entity *pokemon, Entity *target, struct StatIndex stat, s24_8 param_4, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s24_8 oldMulti;

  if (!EntityIsValid(target)) {
    return;
  }

  if (stat.id != STAT_INDEX_PHYSICAL) {
    strcpy(gFormatBuffer_Items[0],gUnknown_80FC0AC);
  }
  else {
    strcpy(gFormatBuffer_Items[0],gUnknown_80FC09C);
  }
  if (F248LessThanInt(param_4, 1) && IsProtectedFromStatDrops(pokemon,target,displayMessage)) {
    return;
  }

  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  oldMulti = entityInfo->defensiveMultipliers[stat.id];

  if (F248LessThanInt(param_4, 1)) {
    sub_804201C(target,stat);
  }
  else {
    sub_8041FFC(target,stat);
  }

  entityInfo->defensiveMultipliers[stat.id] = s24_8_mul(entityInfo->defensiveMultipliers[stat.id],param_4);

  if (F248LessThanFloat(entityInfo->defensiveMultipliers[stat.id], 0.01)) {
    entityInfo->defensiveMultipliers[stat.id] = FloatToF248(0.01);
  }
  if (FloatLessThanF248(99.99, entityInfo->defensiveMultipliers[stat.id])) {
    entityInfo->defensiveMultipliers[stat.id] = FloatToF248(99.99);
  }
  if (F248GreaterThan(oldMulti, entityInfo->defensiveMultipliers[stat.id])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC114);
  }
  else if (F248LessThan(oldMulti, entityInfo->defensiveMultipliers[stat.id])) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC0FC);
  }
  else
  {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC180);
  }
  EntityUpdateStatusSprites(target);
}

void RaiseAccuracyStageTarget(Entity * pokemon, Entity * target, struct StatIndex stat)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    sub_8042040(target,stat);
    if (stat.id != STAT_INDEX_ACCURACY) {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC090);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC084);
    }
    if (entityInfo->hitChanceStages[stat.id] < MAX_STAT_STAGE) {
      entityInfo->hitChanceStages[stat.id]++;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC1C4);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC218);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LowerAccuracyStageTarget(Entity * pokemon, Entity * target, struct StatIndex stat, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    if (stat.id != STAT_INDEX_ACCURACY) {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC090);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_80FC084);
    }
    if (!IsProtectedFromStatDrops(pokemon,target,displayMessage)) {
      if (AbilityIsActive(target, ABILITY_KEEN_EYE) && (stat.id == STAT_INDEX_ACCURACY)){
        if(displayMessage)
        {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCA64);
        }
      }
      else {
        entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        sub_8042060(target,stat.id);
        if (entityInfo->hitChanceStages[stat.id] != 0) {
          entityInfo->hitChanceStages[stat.id]--;
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC1A4);
        }
        else {
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC1F0);
        }
        EntityUpdateStatusSprites(target);
      }
    }
  }
}

void CringeStatusTarget(Entity * pokemon,Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    if (!HasSafeguardStatus(pokemon, target, displayMessage)) {
      if (AbilityIsActive(target, ABILITY_INNER_FOCUS)){
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            if(displayMessage)
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCC18);
      }
      else {
        entityInfo = GetEntInfo(target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if(entityInfo->cringeClassStatus.status != STATUS_CRINGE)
        {
            entityInfo->cringeClassStatus.status = STATUS_CRINGE;
            entityInfo->cringeClassStatus.turns = CalculateStatusTurns(target, gCringeTurnRange, TRUE) +  1;
            sub_80420A0(target);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB2E0);
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB300);
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

  if ((EntityIsValid(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage))) {
    if (AbilityIsActive(target, ABILITY_LIMBER)) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      if (displayMessage) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCBF8);
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
        entityInfo->burnClassStatus.badlyPoisonedDamageCount = 0;
        bVar6 = FALSE;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB2AC);
        sub_8041C1C(target);
        CalcSpeedStage(target);
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB2CC);
      }
      if ((AbilityIsActive(target, ABILITY_SYNCHRONIZE)) && (!bVar6)) {
        bVar7 = FALSE;

        for(index = 0; index < NUM_DIRECTIONS; index++)
        {
          mapTile = GetTile(target->pos.x + gAdjacentTileOffsets[index].x,target->pos.y + gAdjacentTileOffsets[index].y);
          mapPokemonEntity = mapTile->monster;
          if ((EntityIsValid(mapPokemonEntity)) && (GetEntityType(mapPokemonEntity) == ENTITY_MONSTER)) {
            if (!bVar7) {
              bVar7 = TRUE;
              SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
              TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FF01C);
            }
            if (GetTreatmentBetweenMonstersIgnoreStatus(target,mapPokemonEntity) == TREATMENT_TREAT_AS_ENEMY) {
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

  if (!EntityIsValid(target)) {
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC2B8);
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC298);
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

  if (!EntityIsValid(target)) {
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC2D8);
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
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC298);
    }
    else
    {
        sub_8041CCC(target);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA124[movSpeed_1]);
    }
  }
  EntityUpdateStatusSprites(target);
}

