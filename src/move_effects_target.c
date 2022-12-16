#include "global.h"


#include "constants/ability.h"
#include "constants/dungeon_action.h"
#include "constants/direction.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "status_checks.h"
#include "targeting.h"
#include "tile_types.h"

extern char gAvailablePokemonNames[];
extern u8 *gUnknown_80FB380[];
extern u8 *gUnknown_80FB384[];
extern u8 *gUnknown_80FB338[];
extern u8 *gUnknown_80FB318[];
extern u8 *gUnknown_80FB35C[];
extern u8 *gUnknown_80FD548[];
extern u8 *gUnknown_80FCD88[];
extern u8 *gUnknown_80FCD58[];
extern u8 *gUnknown_80FCD54[];
extern u8 *gUnknown_80FB3D0[];
extern u8 *gUnknown_80FB3CC[];
extern u8 *gUnknown_80FB3A4[];
extern u8 *gUnknown_80FB360[];
extern u8 *gUnknown_80FB31C[];
extern u8 *gUnknown_80FB388[];
extern u8 *gUnknown_80FB3E0[];
extern u8 *gUnknown_80FB418[];
extern u8 *gUnknown_80FB3F8[];
extern u8 *gUnknown_80FB414[];
extern u8 *gUnknown_80FB43C[];
extern u8 *gUnknown_80FB41C[];
extern u8 *gUnknown_80FB458[];
extern s16 gUnknown_80F4E7C[];
extern s16 gUnknown_80F4F00[];
extern u8 *gUnknown_80FB52C[];
extern u8 *gUnknown_80FCC4C[];
extern u8 *gUnknown_80FB50C[];
extern s16 gUnknown_80F4E30[];
extern u8 *gUnknown_80FF01C[];
extern u8 *gUnknown_80FEBBC[];
extern u8 *gUnknown_80FB564[];
extern u8 *gUnknown_80FB548[];
extern u8 *gUnknown_80FCE84[];
extern u8 *gUnknown_80FCE5C[];
extern const u8 gDungeonWaterType[];
extern u8 *gUnknown_80FD524[];
extern s16 gUnknown_80F4E34[];
extern u8 *gUnknown_80FCEDC[];
extern u8 *gUnknown_80FCEB0[];
extern u8 *gUnknown_80FB5D4[];
extern u8 *gUnknown_80FB598[];
extern u8 *gUnknown_80FB5F8[];
extern u8 *gUnknown_80FB5B4[];
extern s16 gUnknown_80F4E38[];
extern u8 *gUnknown_80FCE34[];
extern s16 gUnknown_80F4E2C[];
extern u8 *gUnknown_80FB610[];
extern u8 *gUnknown_80FCDE0[];
extern u8 *gUnknown_80FCE00[];
extern u8 *gUnknown_80FA844[];
extern u8 *gUnknown_80FB64C[];
extern s16 gUnknown_80F4E58[];
extern u8 *gUnknown_80FB628[];
extern u8 *gUnknown_80FB4F0[];
extern u8 *gUnknown_80FB4B0[];
extern u8 *gUnknown_80FB480[];
extern u8 *gUnknown_80FB4D4[];
extern s16 gUnknown_80F4E54[];
extern u8 *gUnknown_80FB668[];
extern u8 *gUnknown_80FB688[];
extern s16 gUnknown_80F4E60[];
extern u8 *gUnknown_80FB6A4[];
extern u8 *gUnknown_80FB6C0[];
extern s16 gUnknown_80F4E5C[];
extern u8 *gUnknown_80FB6D8[];
extern u8 *gUnknown_80FB6FC[];
extern u8 *gUnknown_80FB718[];
extern s16 gUnknown_80F4EC0[];
extern s16 gUnknown_80F4EBC[];
extern u8 *gUnknown_80FB7DC[];
extern u8 *gUnknown_80FB7BC[];
extern u8 *gUnknown_80FC0B8[];
extern u8 *gUnknown_80FC0C8[];
extern u8 *gUnknown_80FC0E4[];
extern u8 *gUnknown_80FC0D4[];
extern u8 gUnknown_202DEA8[];
extern u8 gUnknown_202DE58[];
extern u8 *gUnknown_80FC274[];
extern u8 *gUnknown_80FC15C[];
extern u8 *gUnknown_80FCA60[];
extern u8 *gUnknown_80FD550[];
extern u8 *gUnknown_80FC0AC[];
extern u8 *gUnknown_80FC158[];
extern u8 *gUnknown_80FC248[];
extern u8 *gUnknown_80FC09C[];
extern u8 *gUnknown_80FC13C[];
extern u8 *gUnknown_80FC270[];
extern u8 *gUnknown_80FC138[];
extern u8 *gUnknown_80FC21C[];

extern bool8 sub_8071728(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
extern void sub_8041F28(struct DungeonEntity *, s32);
extern void sub_8041F4C(struct DungeonEntity *, s32);
extern void sub_8041F70(struct DungeonEntity *, s32);
extern void sub_8041F94(struct DungeonEntity *, s32);
extern void sub_8041C08(struct DungeonEntity *);
extern void sub_8076CB4(s32);
extern void sub_8041F08(struct DungeonEntity *);
extern void sub_8041C7C(struct DungeonEntity *);
extern void sub_8041C6C(struct DungeonEntity *);
extern void sub_806CE94(struct DungeonEntity *, u32);
extern void sub_8041C34(struct DungeonEntity *);
extern void sub_8041EF8(struct DungeonEntity *);
extern void sub_8041EE8(struct DungeonEntity *);
extern void sub_8041EC8(struct DungeonEntity *);
extern void sub_8041ED8(struct DungeonEntity *);
extern void DungeonEntityUpdateStatusSprites(struct DungeonEntity *);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void SetMessageArgument_2(char[], struct DungeonEntityData*, u32);
extern void sub_8041AF4(struct DungeonEntity *);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, u8 *);
extern void sub_806CE68(struct DungeonEntity *, s32);
extern void nullsub_91(struct DungeonEntity *);
extern void nullsub_90(struct DungeonEntity *);
extern void nullsub_72(struct DungeonEntity *);
extern void nullsub_71(struct DungeonEntity *);
extern void nullsub_70(struct DungeonEntity *);
extern void nullsub_69(struct DungeonEntity *, struct DungeonEntity *);


void sub_8075BA4(struct DungeonEntity *param_1, u8 param_2)
{
  struct DungeonEntityData * entityData = param_1->entityData;

  if ((param_2 != 0) && (entityData->volatileStatus == VOLATILE_STATUS_COWERING)) {
      entityData->action.facingDir = (entityData->action.facingDir + 4) & DIRECTION_MASK;
      TargetTileInFront(param_1);
  }
  else if (entityData->volatileStatus == VOLATILE_STATUS_CONFUSED) {
      entityData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
      TargetTileInFront(param_1);
  }
}

u8 sub_8075BF4(struct DungeonEntity * pokemon, s32 sleepTurns)
{
  struct DungeonEntityData *entityData;
  u32 uVar4;

  uVar4 = 0;
  if (!EntityExists(pokemon)){
    return uVar4;
  }
  else
  {
    entityData = pokemon->entityData;

    if(entityData->sleepStatus != SLEEP_STATUS_NIGHTMARE && entityData->sleepStatus != SLEEP_STATUS_SLEEP)
    {
        entityData->sleepStatus = SLEEP_STATUS_SLEEP;
        if ((sleepTurns != 0x7f) && HasAbility(pokemon, ABILITY_EARLY_BIRD) &&
            (sleepTurns = sleepTurns / 2, sleepTurns < 1)) {
            sleepTurns = 1;
        }
        entityData->sleepStatusTurnsLeft = sleepTurns;
    }
    else if(entityData->sleepStatus == SLEEP_STATUS_SLEEP)
        uVar4 = 1;
    else if(entityData->sleepStatus == SLEEP_STATUS_NIGHTMARE)
        uVar4 = 2;
    DungeonEntityUpdateStatusSprites(pokemon);
  }
  return uVar4;
}

void sub_8075C58(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns, u8 displayMessage)
{
  u8 sleepStatus;
  u8 cVar2;


  if (!CannotSleep(pokemon,target,1,displayMessage)) {
    sleepStatus = target->entityData->sleepStatus;
    if (sleepStatus == SLEEP_STATUS_SLEEPLESS) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FB380);
    }
    else if (sleepStatus == SLEEP_STATUS_NAPPING) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FB384);
    }
    else {
      sub_8041AF4(target);
      cVar2 = sub_8075BF4(target, turns);
      sub_806CE68(target,8);

      if (cVar2 == 1)
        sub_80522F4(pokemon,target,*gUnknown_80FB338);
      else if (cVar2 == 2)
        sub_80522F4(pokemon,target,*gUnknown_80FB35C);
      else
        sub_80522F4(pokemon,target,*gUnknown_80FB318);
    }
  }
}

bool8 CannotSleep(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, bool8 displayMessage)
{  
    if ((!EntityExists(target)) ||
        ((SetMessageArgument(gAvailablePokemonNames,target,0), param_3 != 0 &&
        (HasSafeguardStatus(pokemon,target,displayMessage))))) {
        return TRUE;
    }
    else if (HasIQSkill(target, IQ_SKILL_NONSLEEPER)) {
        if (displayMessage) {
            sub_80522F4(pokemon,target,*gUnknown_80FCD54);
        }
        return TRUE;
    }
    else if (HasAbility(target, ABILITY_INSOMNIA)) {
        if (displayMessage) {
            sub_80522F4(pokemon,target,*gUnknown_80FCD58);
        }
        return TRUE;
    }
    else if (HasAbility(target, ABILITY_VITAL_SPIRIT)) {
        if (displayMessage) {
            sub_80522F4(pokemon,target,*gUnknown_80FCD88);
        }
        return TRUE;
    }
    else if (HasItem(target, ITEM_ID_INSOMNISCOPE)) {
        if (displayMessage) {
            sub_80522F4(pokemon,target,*gUnknown_80FD548);
        }
        return TRUE;
    }
    return FALSE;
}

void NightmareStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns)
{
  bool8 hasNightmare;
  struct DungeonEntityData *entityData;
  
  hasNightmare = FALSE;
  if (!CannotSleep(pokemon, target, 1, TRUE)) {
    entityData = target->entityData;
    if (entityData->sleepStatus != SLEEP_STATUS_SLEEPLESS) {
      sub_8041EC8(target);
      if (entityData->sleepStatus != SLEEP_STATUS_NIGHTMARE) {
        entityData->sleepStatusTurnsLeft = turns;
        if ((HasAbility(target, ABILITY_EARLY_BIRD)) && (entityData->sleepStatusTurnsLeft >>= 1, entityData->sleepStatusTurnsLeft == 0)) {
          entityData->sleepStatusTurnsLeft = 1;
        }
      }
      else
      {
        hasNightmare = TRUE;
      }
      entityData->sleepStatus = SLEEP_STATUS_NIGHTMARE;
      sub_806CE68(target,8);
      if (hasNightmare) {
          sub_80522F4(pokemon,target,*gUnknown_80FB3CC);
      }
      else {
          sub_80522F4(pokemon,target,*gUnknown_80FB3A4);
      }
    }
    else
    {
      sub_80522F4(pokemon,target,*gUnknown_80FB3D0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void NappingStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns)
{
  bool8 isSleeping;
  struct DungeonEntityData *entityData;
  
  isSleeping = FALSE;
  if (!CannotSleep(pokemon, target, 0, TRUE)) {
    entityData = target->entityData;
    if (entityData->sleepStatus != SLEEP_STATUS_SLEEPLESS) {
      sub_8041ED8(target);
      if (entityData->sleepStatus == SLEEP_STATUS_NONE || entityData->sleepStatus == SLEEP_STATUS_YAWNING) {
        entityData->sleepStatusTurnsLeft = turns;
        if ((HasAbility(target, ABILITY_EARLY_BIRD)) && (entityData->sleepStatusTurnsLeft >>= 1, entityData->sleepStatusTurnsLeft == 0)) {
          entityData->sleepStatusTurnsLeft = 1;
        }
      }
      else
      {
        isSleeping = TRUE;
      }
      entityData->sleepStatus = SLEEP_STATUS_NAPPING;
      sub_806CE68(target, 8);
      if (isSleeping) {
          sub_80522F4(pokemon,target,*gUnknown_80FB360);
      }
      else {
          sub_80522F4(pokemon,target,*gUnknown_80FB31C);
      }
    }
    else
    {
      sub_80522F4(pokemon,target,*gUnknown_80FB388);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void YawnedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns)
{
  struct DungeonEntityData *entityData;
  
  if (CannotSleep(pokemon,target,1,TRUE)) {
    return;
  }
  entityData = target->entityData;
  if (entityData->sleepStatus == SLEEP_STATUS_NONE) {
    entityData->sleepStatus = SLEEP_STATUS_YAWNING;
    entityData->sleepStatusTurnsLeft = turns;
    nullsub_91(target);
    sub_806CE68(target, 8);
    sub_80522F4(pokemon,target,*gUnknown_80FB3E0);
  }
  else if (((entityData->sleepStatus == SLEEP_STATUS_SLEEP) || (entityData->sleepStatus == SLEEP_STATUS_NIGHTMARE)) || (entityData->sleepStatus == SLEEP_STATUS_NAPPING)) {
    sub_80522F4(pokemon,target,*gUnknown_80FB418);
  }
  else if (entityData->sleepStatus == SLEEP_STATUS_SLEEPLESS) {
    sub_80522F4(pokemon,target,*gUnknown_80FB3F8);
  }
  else {
    if (entityData->sleepStatus == SLEEP_STATUS_YAWNING)
        sub_80522F4(pokemon,target,*gUnknown_80FB414);
    else
        sub_80522F4(pokemon,target,*gUnknown_80FB3E0);
  }
  DungeonEntityUpdateStatusSprites(target);
}

void SleeplessStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  bool8 isAsleep;
  
  isAsleep = FALSE;
  if (!EntityExists(target)) {
    return;
  }

  entityData = target->entityData;
  if ((entityData->sleepStatus == SLEEP_STATUS_SLEEP) || (entityData->sleepStatus == SLEEP_STATUS_NAPPING) || (entityData->sleepStatus == SLEEP_STATUS_NIGHTMARE)) {
    isAsleep = TRUE;
  }
  SetMessageArgument(gAvailablePokemonNames, target, 0);

  if (entityData->sleepStatus != SLEEP_STATUS_SLEEPLESS)
  {
    entityData->sleepStatus = SLEEP_STATUS_SLEEPLESS;
    entityData->sleepStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E7C, FALSE) + 1;
    entityData->unk165 = 0xFF;
    entityData->unk164 = 0xFF;
    sub_8041EE8(target);
    sub_806CE68(target,8);
    if(isAsleep)
        sub_80522F4(pokemon,target,*gUnknown_80FB41C);
    sub_80522F4(pokemon,target,*gUnknown_80FB458);
  }
  else
  {
      sub_80522F4(pokemon,target,*gUnknown_80FB43C);
  }
  DungeonEntityUpdateStatusSprites(target);
}

void PausedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, s32 turns, bool8 displayMessage)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  if ((param_3 != 0) && (HasSafeguardStatus(pokemon,target,displayMessage))) {
    return;
  }
  SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
  if (entityData->volatileStatus != VOLATILE_STATUS_PAUSED) {
    entityData->volatileStatus = VOLATILE_STATUS_PAUSED;
    entityData->volatileStatusTurnsLeft = turns + 1;
    nullsub_72(target);
    if (turns == 1) {
        sub_80522F4(pokemon,target,*gUnknown_80FB480);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FB4D4);
    }
  }
  else {
    if (turns == 1) {
        sub_80522F4(pokemon,target,*gUnknown_80FB4B0);
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FB4F0);
    }
  }
  DungeonEntityUpdateStatusSprites(target);
}

void InfatuateStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage)
{
  struct DungeonEntityData *entityData;
  

  if (EntityExists(target)) {
    entityData = target->entityData;
    if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
      if (HasAbility(target,ABILITY_OBLIVIOUS)) {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (displayMessage) {
          sub_80522F4(pokemon,target,*gUnknown_80FCC4C);
        }
      }
      else
      {
        SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
        if (entityData->volatileStatus != VOLATILE_STATUS_INFATUATED) {
          entityData->volatileStatus = VOLATILE_STATUS_INFATUATED;
          entityData->volatileStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F00,TRUE) + 1;
          sub_8041EF8(target);
          sub_80522F4(pokemon,target,*gUnknown_80FB50C);
        }
        else {
          sub_80522F4(pokemon,target,*gUnknown_80FB52C);
        }
        DungeonEntityUpdateStatusSprites(target);
      }
    }
  }
}

void BurnedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, bool8 displayMessage)
{
  bool8 isNotBurned;
  bool8 hasSynchronized;
  struct DungeonEntityData *entityData;
  struct MapTile *tile_1;
  struct MapTile *tile_2;
  struct DungeonEntity *entity;
  s32 index;
  
  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityData = target->entityData;
    SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
    if (HasAbility(target, ABILITY_WATER_VEIL)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FCE5C);
    }
    else
    {
      if (HasType(target, TYPE_FIRE)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCE84);
      }
      else
      {
        tile_1 = GetMapTileForDungeonEntity_2(target);
        if (((tile_1->tileType & (TILE_TYPE_LIQUID | TILE_TYPE_FLOOR)) == TILE_TYPE_LIQUID) &&
           (gDungeonWaterType[gDungeonGlobalData->tileset] != DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    sub_80522F4(pokemon,target,*gUnknown_80FEBBC);
           }
        else
        {
            isNotBurned = TRUE;
            if (entityData->nonVolatileStatus != NON_VOLATILE_STATUS_BURNED) {
                entityData->nonVolatileStatus = NON_VOLATILE_STATUS_BURNED;
                entityData->nonVolatileStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E30,TRUE) + 1;
                entityData->nonVolatileStatusDamageTimer = 0;
                entityData->fillAF = 0;
                isNotBurned = FALSE;
                if (param_3 != 0) {
                    sub_8041C34(target);
                }
                sub_80522F4(pokemon,target,*gUnknown_80FB548);
            }
            else {
                sub_80522F4(pokemon,target,*gUnknown_80FB564);
            }
            DungeonEntityUpdateStatusSprites(target);

            if (!HasAbility(target, ABILITY_SYNCHRONIZE)) {
                return;
            }

            if (isNotBurned) {
                return;
            }

            hasSynchronized = FALSE;

            for(index = 0; index < NUM_DIRECTIONS; index++)
            {
                tile_2 = GetMapTile_1(target->posWorld.x +
                                    gAdjacentTileOffsets[index].x,
                                    target->posWorld.y + gAdjacentTileOffsets[index].y);
                entity = tile_2->pokemon;
                if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_POKEMON)) {
                    if (!hasSynchronized) {
                        hasSynchronized = TRUE;
                        SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
                        sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                    }
                    if (sub_807167C(target,entity) == TARGET_CAPABILITY_CAN_TARGET) {
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

void PoisonedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage)
{
  bool8 isNotPoisoned;
  bool8 hasSynchronized;
  struct DungeonEntityData *entityData;
  struct MapTile *tile;
  struct DungeonEntity *entity;
  s32 index;
  
  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityData = target->entityData;
    SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
    if (HasItem(target, ITEM_ID_PECHA_SCARF)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FD524);
    }
    else
    {
      if (HasAbility(target, ABILITY_IMMUNITY)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCEB0);
      }
      else
      {
        if(HasType(target, TYPE_POISON) || HasType(target, TYPE_STEEL)){
            if (displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCEDC);
        }
        else
        {
            isNotPoisoned = TRUE;

            if(entityData->nonVolatileStatus != NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                if(entityData->nonVolatileStatus != NON_VOLATILE_STATUS_POISONED)
                {
                    entityData->nonVolatileStatus = NON_VOLATILE_STATUS_POISONED;
                    entityData->nonVolatileStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E34,TRUE) + 1;
                    entityData->nonVolatileStatusDamageTimer = 0;
                    entityData->fillAF = 0;
                    isNotPoisoned = FALSE;
                    sub_8041C6C(target);
                    sub_80522F4(pokemon,target,*gUnknown_80FB598);
                    sub_806CE94(target, 8);
                }
                else
                {   
                    sub_80522F4(pokemon,target,*gUnknown_80FB5D4);
                }
            }
            else
            {
                sub_80522F4(pokemon,target,*gUnknown_80FB5F8);
            }

            if ((HasAbility(target, ABILITY_SYNCHRONIZE)) && !isNotPoisoned)
            {
                hasSynchronized = FALSE;

                for(index = 0; index < NUM_DIRECTIONS; index++)
                {
                    tile = GetMapTile_1(target->posWorld.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->posWorld.y + gAdjacentTileOffsets[index].y);
                    entity = tile->pokemon;
                    if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_POKEMON)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
                            sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                        }
                        if (sub_807167C(target,entity) == TARGET_CAPABILITY_CAN_TARGET) {
                            // Recurse with the new target
                            PoisonedStatusTarget(pokemon,entity,displayMessage);
                        }
                    }
                }
            }
            DungeonEntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void BadlyPoisonedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage)
{
  bool8 isNotBadlyPoisoned;
  bool8 hasSynchronized;
  struct DungeonEntityData *entityData;
  struct MapTile *tile;
  struct DungeonEntity *entity;
  s32 index;
  
  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityData = target->entityData;
    SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
    if (HasItem(target, ITEM_ID_PECHA_SCARF)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FD524);
    }
    else
    {
      if (HasAbility(target, ABILITY_IMMUNITY)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCEB0);
      }
      else
      {
        if(HasType(target, TYPE_POISON) || HasType(target, TYPE_STEEL)){
            if (displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCEDC);
        }
        else
        {
            isNotBadlyPoisoned = TRUE;

            if(entityData->nonVolatileStatus != NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                    entityData->nonVolatileStatus = NON_VOLATILE_STATUS_BADLY_POISONED;
                    entityData->nonVolatileStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E38,TRUE) + 1;
                    entityData->nonVolatileStatusDamageTimer = 0;
                    entityData->fillAF = 0;
                    isNotBadlyPoisoned = FALSE;
                    sub_8041C7C(target);
                    sub_80522F4(pokemon,target,*gUnknown_80FB5B4);
                    sub_806CE94(target, 8);
            }
            else
            {
                sub_80522F4(pokemon,target,*gUnknown_80FB5F8);
            }

            if ((HasAbility(target, ABILITY_SYNCHRONIZE)) && !isNotBadlyPoisoned)
            {
                hasSynchronized = FALSE;

                for(index = 0; index < NUM_DIRECTIONS; index++)
                {
                    tile = GetMapTile_1(target->posWorld.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->posWorld.y + gAdjacentTileOffsets[index].y);
                    entity = tile->pokemon;
                    if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_POKEMON)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gAvailablePokemonNames,entityData,0);
                            sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                        }
                        if (sub_807167C(target,entity) == TARGET_CAPABILITY_CAN_TARGET) {
                            // Recurse with the new target
                            BadlyPoisonedStatusTarget(pokemon,entity,displayMessage);
                        }
                    }
                }
            }
            DungeonEntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void FrozenStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage)
{
  struct DungeonEntityData *entityData;
  struct MapTile *tile;
  
  if (!EntityExists(target)) {
    return;
  }

  SetMessageArgument(gAvailablePokemonNames, target, 0);
  entityData = target->entityData;

  if ((entityData->immobilizeStatus != IMMOBILIZE_STATUS_FROZEN) && !HasSafeguardStatus(pokemon,target,displayMessage)) {
    if (HasAbility(target, ABILITY_MAGMA_ARMOR)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FCDE0);
    }
    else
    {
      if (HasType(target, TYPE_ICE)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCE00);
      }
      else
      {
        tile = GetMapTileForDungeonEntity_2(target);
        if (((tile->tileType & (TILE_TYPE_LIQUID | TILE_TYPE_FLOOR)) == TILE_TYPE_LIQUID) &&
           (gDungeonWaterType[gDungeonGlobalData->tileset] == DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    sub_80522F4(pokemon,target,*gUnknown_80FCE34);
           }
        else
        {
            if ((u8)(entityData->immobilizeStatus - 3) <=  1) {
                sub_8076CB4(entityData->unk9C);
            }
            sub_8041F08(target);
            entityData->immobilizeStatus = IMMOBILIZE_STATUS_FROZEN;
            entityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E2C,TRUE) + 1;
            entityData->immobilizeStatusDamageTimer = 0;
            sub_80522F4(pokemon,target,*gUnknown_80FB610);
            DungeonEntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void SqueezedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s16 param_3, bool32 displayMessage)
{
  struct DungeonEntityData *entityData;
  s32 param_3_s32 = param_3;
  bool8 displayMessage_u8 = displayMessage;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage_u8))) {
    entityData = target->entityData;
    if ((u8)(entityData->immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityData->unk9C);
    }
    else if (entityData->immobilizeStatus == IMMOBILIZE_STATUS_INGRAIN) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA844);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->immobilizeStatus != IMMOBILIZE_STATUS_SQUEEZED) {
      entityData->immobilizeStatus = IMMOBILIZE_STATUS_SQUEEZED;
      entityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E58,TRUE) + 1;
      entityData->immobilizeStatusDamageTimer = 0;
      entityData->unkB4 = param_3_s32;
      nullsub_71(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB628);
      sub_806CE94(target,8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB64C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void ImmobilizedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityData = target->entityData;
    if ((u8)(entityData->immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityData->unk9C);
    }
    else if (entityData->immobilizeStatus == IMMOBILIZE_STATUS_INGRAIN) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA844);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->immobilizeStatus != IMMOBILIZE_STATUS_IMMOBILIZED) {
      entityData->immobilizeStatus = IMMOBILIZE_STATUS_IMMOBILIZED;
      entityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E54,TRUE) + 1;
      entityData->immobilizeStatusDamageTimer = 0;
      nullsub_70(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB668);
      sub_806CE94(target,8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB688);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void IngrainedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData2;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    entityData2 = entityData;
    if ((u8)(entityData->immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityData->unk9C);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData2->immobilizeStatus != IMMOBILIZE_STATUS_INGRAIN) {
      entityData2->immobilizeStatus = IMMOBILIZE_STATUS_INGRAIN;
      entityData2->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E60,TRUE) + 1;
      entityData2->immobilizeStatusDamageTimer = 0;
      nullsub_90(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB6A4);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB6C0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void WrapTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData * targetEntityData;
  s32 *piVar3;
  s32 *iVar5;
  struct DungeonEntityData * pokemonEntityData;
  
  if (!EntityExists(target)) {
    return;
  }

  if (HasSafeguardStatus(pokemon, target, TRUE)) {
    return;
  }
  pokemonEntityData = pokemon->entityData;
  targetEntityData = target->entityData;
  if ((u8)(pokemonEntityData->immobilizeStatus - 3U) > 1) {
    if ((targetEntityData->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE))
    {
        if(targetEntityData->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_BY_FOE) {
            pokemonEntityData->immobilizeStatus = IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE;
            pokemonEntityData->immobilizeStatusTurnsLeft = 0x7f;
            pokemonEntityData->immobilizeStatusDamageTimer = 0;
            targetEntityData->immobilizeStatus = IMMOBILIZE_STATUS_WRAPPED_BY_FOE;
            targetEntityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E5C, TRUE) + 1;
            targetEntityData->immobilizeStatusDamageTimer = 0;
            iVar5 = &pokemonEntityData->unk9C;
            piVar3 = &gDungeonGlobalData->unk37F4;
            *iVar5 = *piVar3;
            targetEntityData->unk9C  = *piVar3;
            *piVar3 +=1;
            nullsub_69(pokemon, target);
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FB6D8);
            sub_806CE94(target,8);
            goto _08076C98;
        }
    }
  }
  if (pokemonEntityData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE) {
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB6FC);
  }
  if (targetEntityData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE) {
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB6FC);
  }
  if (pokemonEntityData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_BY_FOE) {
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB718);
  }
  if (targetEntityData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_BY_FOE) {
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB718);
  }
_08076C98:
  DungeonEntityUpdateStatusSprites(target);
}

void sub_8076CB4(s32 param_1)
{
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;

  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeonGlobalData->allPokemon[index];
    if (EntityExists(entity)) {
      entityData = entity->entityData;
      if (entityData->unk9C == param_1) {
        if ((u8)(entityData->immobilizeStatus - 3U) < 2) {
          entityData->immobilizeStatus = IMMOBILIZE_STATUS_NONE;
        }
        entityData->unk9C = 0;
      }
      DungeonEntityUpdateStatusSprites(entity);
    }
  }
}

void PetrifiedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData * targetEntityData;
  struct DungeonEntityData * entityData;
  struct DungeonEntity * entity;
  s32 index;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    sub_8041C08(target);
    targetEntityData = target->entityData;
    if ((u8)(targetEntityData->immobilizeStatus - 3U) < 2) {
      sub_8076CB4(targetEntityData->unk9C);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityData->immobilizeStatus != IMMOBILIZE_STATUS_PETRIFIED) {
      targetEntityData->immobilizeStatus = IMMOBILIZE_STATUS_PETRIFIED;
      if (targetEntityData->isLeader) {
        targetEntityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4EBC,TRUE) + 1;
      }
      else {
        targetEntityData->immobilizeStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4EC0,TRUE) + 1;
      }
      targetEntityData->immobilizeStatusDamageTimer = 0;
      sub_80522F4(pokemon,target,*gUnknown_80FB7BC);

    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB7DC);
    }
    if (targetEntityData->isEnemy) {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeonGlobalData->teamPokemon[index];
        if (EntityExists(entity)) {
          entityData = entity->entityData;
          if ((entityData->movementAction == MOVEMENT_ACTION_FOLLOW) && (entityData->targetPokemon == target)) {
            entityData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
            entityData->targetPokemon = NULL;
            entityData->targetPokemonSpawnIndex = 0;
            entityData->hasTarget = FALSE;
          }
        }
      }
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void LowerAttackStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage)
{
  struct DungeonEntityData *entityData;
  s32 attackStage = decrement;
  
  if (!EntityExists(target)) {
    return;
  }
  if (index != STAT_STAGE_ATTACK) {
    strcpy(gUnknown_202DE58,*gUnknown_80FC0C8);
  }
  else {
    strcpy(gUnknown_202DE58,*gUnknown_80FC0B8);
  }
  if (param_5) {
    if (sub_8071728(pokemon,target,displayMessage)) {
      return;
    }
    if (HasItem(target, ITEM_ID_TWIST_BAND)) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FD550);
    }
    else {
      if ((!HasAbility(target, ABILITY_HYPER_CUTTER)) || (index != STAT_STAGE_ATTACK)) goto _08076EE4;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FCA60);
    }
  }
  else {
_08076EE4:
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F28(target,index);
    if (decrement == 1) {
      strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
      strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }
    attackStage = entityData->attackStages[index];
    attackStage -= decrement;
    if (attackStage < 0) {
      attackStage = 0;
    }
    if (entityData->attackStages[index] != attackStage) {
      entityData->attackStages[index] = attackStage;
      sub_80522F4(pokemon,target,*gUnknown_80FC15C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC274);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void LowerDefenseStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage)
{
    struct DungeonEntityData *entityData;
    s32 defenseStage = decrement;
    
    if (!EntityExists(target)) {
        return;
    }
    if (index != STAT_STAGE_DEFENSE) {
        strcpy(gUnknown_202DE58,*gUnknown_80FC0AC);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_80FC09C);
    }
    if (!param_5 || !sub_8071728(pokemon,target,displayMessage)) {
        entityData = target->entityData;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_8041F4C(target,index);
        if (decrement == 1) {
            strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
        }
        else {
            strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
        }
        defenseStage = entityData->defenseStages[index];
        defenseStage = defenseStage - decrement;
        if (defenseStage < 0) {
            defenseStage = 0;
        }
        if (entityData->defenseStages[index] != defenseStage) {
            entityData->defenseStages[index] = defenseStage;
            sub_80522F4(pokemon,target,*gUnknown_80FC158);
        }
        else {
            sub_80522F4(pokemon,target,*gUnknown_80FC248);
        }
        DungeonEntityUpdateStatusSprites(target);
  }
}

void RaiseAttackStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 increment)
{
    struct DungeonEntityData *entityData;
    s32 attackStage = increment;
    
    if (!EntityExists(target)) {
        return;
    }
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F70(target,index);
    if (index != STAT_STAGE_ATTACK) {
        strcpy(gUnknown_202DE58,*gUnknown_80FC0C8);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_80FC0B8);
    }

    if (increment == 1) {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }

    attackStage = entityData->attackStages[index];
    attackStage = attackStage + increment;
    if (attackStage >= MAX_STAT_STAGE) {
        attackStage = MAX_STAT_STAGE;
    }
    if (entityData->attackStages[index] != attackStage) {
        entityData->attackStages[index] = attackStage;
        sub_80522F4(pokemon,target,*gUnknown_80FC13C);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FC270);
    }
    DungeonEntityUpdateStatusSprites(target);
}

void RaiseDefenseStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 increment)
{
    struct DungeonEntityData *entityData;
    s32 defenseStage = increment;
    
    if (!EntityExists(target)) {
        return;
    }
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F94(target,index);
    if (index != STAT_STAGE_DEFENSE) {
        strcpy(gUnknown_202DE58,*gUnknown_80FC0AC);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_80FC09C);
    }

    if (increment == 1) {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }

    defenseStage = entityData->defenseStages[index];
    defenseStage = defenseStage + increment;
    if (defenseStage >= MAX_STAT_STAGE) {
        defenseStage = MAX_STAT_STAGE;
    }
    if (entityData->defenseStages[index] != defenseStage) {
        entityData->defenseStages[index] = defenseStage;
        sub_80522F4(pokemon,target,*gUnknown_80FC138);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FC21C);
    }
    DungeonEntityUpdateStatusSprites(target);
}
