#include "global.h"
#include "move_effects_target.h"

#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
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
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "pokemon.h"
#include "status_checks.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
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
extern u8 gFormatItems[];
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

extern bool8 sub_8071728(Entity * pokemon, Entity * target, bool8 displayMessage);
extern void sub_8041F28(Entity *, s32);
extern void sub_8041F4C(Entity *, s32);
extern void sub_8041F70(Entity *, s32);
extern void sub_8041F94(Entity *, s32);
extern void sub_8041C08(Entity *);
extern void sub_8076CB4(s32);
extern void sub_8041F08(Entity *);
extern void sub_8041C7C(Entity *);
extern void sub_8041C6C(Entity *);
extern void sub_8041C34(Entity *);
extern void sub_8041EF8(Entity *);
extern void sub_8041EE8(Entity *);
extern void sub_8041EC8(Entity *);
extern void sub_8041ED8(Entity *);
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8041AF4(Entity *);
extern void sub_80522F4(Entity *r1, Entity *r2, u8 *);
extern void nullsub_91(Entity *);
extern void nullsub_90(Entity *);
extern void nullsub_72(Entity *);
extern void nullsub_71(Entity *);
extern void nullsub_70(Entity *);
extern void nullsub_69(Entity *, Entity *);


void sub_8075BA4(Entity *param_1, u8 param_2)
{
  EntityInfo * entityInfo = param_1->axObj.info;

  if ((param_2 != 0) && (entityInfo->volatileStatus.volatileStatus == STATUS_COWERING)) {
      entityInfo->action.direction = (entityInfo->action.direction + 4) & DIRECTION_MASK;
      TargetTileInFront(param_1);
  }
  else if (entityInfo->volatileStatus.volatileStatus == STATUS_CONFUSED) {
      entityInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
      TargetTileInFront(param_1);
  }
}

u8 sub_8075BF4(Entity * pokemon, s32 sleepTurns)
{
  EntityInfo *entityInfo;
  u32 uVar4;

  uVar4 = 0;
  if (!EntityExists(pokemon)){
    return uVar4;
  }
  else
  {
    entityInfo = pokemon->axObj.info;

    if(entityInfo->sleep.sleep != STATUS_NIGHTMARE && entityInfo->sleep.sleep != STATUS_SLEEP)
    {
        entityInfo->sleep.sleep = STATUS_SLEEP;
        if ((sleepTurns != 0x7f) && HasAbility(pokemon, ABILITY_EARLY_BIRD) &&
            (sleepTurns = sleepTurns / 2, sleepTurns < 1)) {
            sleepTurns = 1;
        }
        entityInfo->sleep.sleepTurns = sleepTurns;
    }
    else if(entityInfo->sleep.sleep == STATUS_SLEEP)
        uVar4 = 1;
    else if(entityInfo->sleep.sleep == STATUS_NIGHTMARE)
        uVar4 = 2;
    EntityUpdateStatusSprites(pokemon);
  }
  return uVar4;
}

void sub_8075C58(Entity * pokemon, Entity * target, s32 turns, u8 displayMessage)
{
  u8 sleep;
  u8 cVar2;


  if (!CannotSleep(pokemon,target,1,displayMessage)) {
    sleep = target->axObj.info->sleep.sleep;
    if (sleep == STATUS_SLEEPLESS) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FB380);
    }
    else if (sleep == STATUS_NAPPING) {
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

bool8 CannotSleep(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage)
{
    if ((!EntityExists(target)) ||
        ((SetMessageArgument(gAvailablePokemonNames,target,0), param_3 != 0 &&
        (HasSafeguardStatus(pokemon,target,displayMessage))))) {
        return TRUE;
    }
    else if (IQSkillIsEnabled(target, IQ_NONSLEEPER)) {
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
    else if (HasHeldItem(target, ITEM_INSOMNISCOPE)) {
        if (displayMessage) {
            sub_80522F4(pokemon,target,*gUnknown_80FD548);
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
    entityInfo = target->axObj.info;
    if (entityInfo->sleep.sleep != STATUS_SLEEPLESS) {
      sub_8041EC8(target);
      if (entityInfo->sleep.sleep != STATUS_NIGHTMARE) {
        entityInfo->sleep.sleepTurns = turns;
        if ((HasAbility(target, ABILITY_EARLY_BIRD)) && (entityInfo->sleep.sleepTurns >>= 1, entityInfo->sleep.sleepTurns == 0)) {
          entityInfo->sleep.sleepTurns = 1;
        }
      }
      else
      {
        hasNightmare = TRUE;
      }
      entityInfo->sleep.sleep = STATUS_NIGHTMARE;
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
    EntityUpdateStatusSprites(target);
  }
}

void NappingStatusTarget(Entity * pokemon, Entity * target, s32 turns)
{
  bool8 isSleeping;
  EntityInfo *entityInfo;

  isSleeping = FALSE;
  if (!CannotSleep(pokemon, target, 0, TRUE)) {
    entityInfo = target->axObj.info;
    if (entityInfo->sleep.sleep != STATUS_SLEEPLESS) {
      sub_8041ED8(target);
      if (entityInfo->sleep.sleep == STATUS_NONE || entityInfo->sleep.sleep == STATUS_YAWNING) {
        entityInfo->sleep.sleepTurns = turns;
        if ((HasAbility(target, ABILITY_EARLY_BIRD)) && (entityInfo->sleep.sleepTurns >>= 1, entityInfo->sleep.sleepTurns == 0)) {
          entityInfo->sleep.sleepTurns = 1;
        }
      }
      else
      {
        isSleeping = TRUE;
      }
      entityInfo->sleep.sleep = STATUS_NAPPING;
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
    EntityUpdateStatusSprites(target);
  }
}

void YawnedStatusTarget(Entity * pokemon, Entity * target, s32 turns)
{
  EntityInfo *entityInfo;

  if (CannotSleep(pokemon,target,1,TRUE)) {
    return;
  }
  entityInfo = target->axObj.info;
  if (entityInfo->sleep.sleep == STATUS_NONE) {
    entityInfo->sleep.sleep = STATUS_YAWNING;
    entityInfo->sleep.sleepTurns = turns;
    nullsub_91(target);
    sub_806CE68(target, 8);
    sub_80522F4(pokemon,target,*gUnknown_80FB3E0);
  }
  else if (((entityInfo->sleep.sleep == STATUS_SLEEP) || (entityInfo->sleep.sleep == STATUS_NIGHTMARE)) || (entityInfo->sleep.sleep == STATUS_NAPPING)) {
    sub_80522F4(pokemon,target,*gUnknown_80FB418);
  }
  else if (entityInfo->sleep.sleep == STATUS_SLEEPLESS) {
    sub_80522F4(pokemon,target,*gUnknown_80FB3F8);
  }
  else {
    if (entityInfo->sleep.sleep == STATUS_YAWNING)
        sub_80522F4(pokemon,target,*gUnknown_80FB414);
    else
        sub_80522F4(pokemon,target,*gUnknown_80FB3E0);
  }
  EntityUpdateStatusSprites(target);
}

void SleeplessStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;
  bool8 isAsleep;

  isAsleep = FALSE;
  if (!EntityExists(target)) {
    return;
  }

  entityInfo = target->axObj.info;
  if ((entityInfo->sleep.sleep == STATUS_SLEEP) || (entityInfo->sleep.sleep == STATUS_NAPPING) || (entityInfo->sleep.sleep == STATUS_NIGHTMARE)) {
    isAsleep = TRUE;
  }
  SetMessageArgument(gAvailablePokemonNames, target, 0);

  if (entityInfo->sleep.sleep != STATUS_SLEEPLESS)
  {
    entityInfo->sleep.sleep = STATUS_SLEEPLESS;
    entityInfo->sleep.sleepTurns = CalculateStatusTurns(target, gUnknown_80F4E7C, FALSE) + 1;
    entityInfo->unk165 = 0xFF;
    entityInfo->unk164 = 0xFF;
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
  EntityUpdateStatusSprites(target);
}

void PausedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, s32 turns, bool8 displayMessage)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  if ((param_3 != 0) && (HasSafeguardStatus(pokemon,target,displayMessage))) {
    return;
  }
  SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
  if (entityInfo->volatileStatus.volatileStatus != STATUS_PAUSED) {
    entityInfo->volatileStatus.volatileStatus = STATUS_PAUSED;
    entityInfo->volatileStatus.volatileStatusTurns = turns + 1;
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
  EntityUpdateStatusSprites(target);
}

void InfatuateStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  EntityInfo *entityInfo;


  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
      if (HasAbility(target,ABILITY_OBLIVIOUS)) {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (displayMessage) {
          sub_80522F4(pokemon,target,*gUnknown_80FCC4C);
        }
      }
      else
      {
        SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
        if (entityInfo->volatileStatus.volatileStatus != STATUS_INFATUATED) {
          entityInfo->volatileStatus.volatileStatus = STATUS_INFATUATED;
          entityInfo->volatileStatus.volatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4F00,TRUE) + 1;
          sub_8041EF8(target);
          sub_80522F4(pokemon,target,*gUnknown_80FB50C);
        }
        else {
          sub_80522F4(pokemon,target,*gUnknown_80FB52C);
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
  struct Tile *tile_1;
  struct Tile *tile_2;
  Entity *entity;
  s32 index;

  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = target->axObj.info;
    SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
    if (HasAbility(target, ABILITY_WATER_VEIL)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FCE5C);
    }
    else
    {
      if (MonsterIsType(target, TYPE_FIRE)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCE84);
      }
      else
      {
        tile_1 = GetTileAtEntitySafe(target);
        if (((tile_1->terrainType & (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL)) == TERRAIN_TYPE_SECONDARY) &&
           (gDungeonWaterType[gDungeon->tileset] != DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    sub_80522F4(pokemon,target,*gUnknown_80FEBBC);
           }
        else
        {
            isNotBurned = TRUE;
            if (entityInfo->nonVolatile.nonVolatileStatus != STATUS_BURN) {
                entityInfo->nonVolatile.nonVolatileStatus = STATUS_BURN;
                entityInfo->nonVolatile.nonVolatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E30,TRUE) + 1;
                entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = 0;
                entityInfo->nonVolatile.unk4 = 0;
                isNotBurned = FALSE;
                if (param_3 != 0) {
                    sub_8041C34(target);
                }
                sub_80522F4(pokemon,target,*gUnknown_80FB548);
            }
            else {
                sub_80522F4(pokemon,target,*gUnknown_80FB564);
            }
            EntityUpdateStatusSprites(target);

            if (!HasAbility(target, ABILITY_SYNCHRONIZE)) {
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
                if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                    if (!hasSynchronized) {
                        hasSynchronized = TRUE;
                        SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
                        sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                    }
                    if (sub_807167C(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
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
  struct Tile *tile;
  Entity *entity;
  s32 index;

  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = target->axObj.info;
    SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
    if (HasHeldItem(target, ITEM_PECHA_SCARF)) {
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
        if(MonsterIsType(target, TYPE_POISON) || MonsterIsType(target, TYPE_STEEL)){
            if (displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCEDC);
        }
        else
        {
            isNotPoisoned = TRUE;

            if(entityInfo->nonVolatile.nonVolatileStatus != STATUS_BADLY_POISONED)
            {
                if(entityInfo->nonVolatile.nonVolatileStatus != STATUS_POISONED)
                {
                    entityInfo->nonVolatile.nonVolatileStatus = STATUS_POISONED;
                    entityInfo->nonVolatile.nonVolatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E34,TRUE) + 1;
                    entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = 0;
                    entityInfo->nonVolatile.unk4 = 0;
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
                    tile = GetTile(target->pos.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->pos.y + gAdjacentTileOffsets[index].y);
                    entity = tile->monster;
                    if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
                            sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                        }
                        if (sub_807167C(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
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
  struct Tile *tile;
  Entity *entity;
  s32 index;

  if (!EntityExists(target)) {
    return;
  }

  if (!HasSafeguardStatus(pokemon,target,displayMessage)) {
    entityInfo = target->axObj.info;
    SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
    if (HasHeldItem(target, ITEM_PECHA_SCARF)) {
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
        if(MonsterIsType(target, TYPE_POISON) || MonsterIsType(target, TYPE_STEEL)){
            if (displayMessage)
                sub_80522F4(pokemon,target,*gUnknown_80FCEDC);
        }
        else
        {
            isNotBadlyPoisoned = TRUE;

            if(entityInfo->nonVolatile.nonVolatileStatus != STATUS_BADLY_POISONED)
            {
                    entityInfo->nonVolatile.nonVolatileStatus = STATUS_BADLY_POISONED;
                    entityInfo->nonVolatile.nonVolatileStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E38,TRUE) + 1;
                    entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = 0;
                    entityInfo->nonVolatile.unk4 = 0;
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
                    tile = GetTile(target->pos.x +
                                        gAdjacentTileOffsets[index].x,
                                        target->pos.y + gAdjacentTileOffsets[index].y);
                    entity = tile->monster;
                    if ((EntityExists(entity)) && (GetEntityType(entity) == ENTITY_MONSTER)) {
                        if (!hasSynchronized) {
                            hasSynchronized = TRUE;
                            SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
                            sub_80522F4(pokemon,target,*gUnknown_80FF01C);
                        }
                        if (sub_807167C(target,entity) == TREATMENT_TREAT_AS_ENEMY) {
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
  struct Tile *tile;

  if (!EntityExists(target)) {
    return;
  }

  SetMessageArgument(gAvailablePokemonNames, target, 0);
  entityInfo = target->axObj.info;

  if ((entityInfo->immobilize.immobilizeStatus != STATUS_FROZEN) && !HasSafeguardStatus(pokemon,target,displayMessage)) {
    if (HasAbility(target, ABILITY_MAGMA_ARMOR)) {
      if (displayMessage)
        sub_80522F4(pokemon,target,*gUnknown_80FCDE0);
    }
    else
    {
      if (MonsterIsType(target, TYPE_ICE)) {
        if (displayMessage)
            sub_80522F4(pokemon,target,*gUnknown_80FCE00);
      }
      else
      {
        tile = GetTileAtEntitySafe(target);
        if (((tile->terrainType & (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL)) == TERRAIN_TYPE_SECONDARY) &&
           (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA)) {
                if (displayMessage)
                    sub_80522F4(pokemon,target,*gUnknown_80FCE34);
           }
        else
        {
            if ((u8)(entityInfo->immobilize.immobilizeStatus - 3) <=  1) {
                sub_8076CB4(entityInfo->unk9C);
            }
            sub_8041F08(target);
            entityInfo->immobilize.immobilizeStatus = STATUS_FROZEN;
            entityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E2C,TRUE) + 1;
            entityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
            sub_80522F4(pokemon,target,*gUnknown_80FB610);
            EntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void SqueezedStatusTarget(Entity * pokemon, Entity * target, s16 param_3, bool32 displayMessage)
{
  EntityInfo *entityInfo;
  s32 param_3_s32 = param_3;
  bool8 displayMessage_u8 = displayMessage;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,displayMessage_u8))) {
    entityInfo = target->axObj.info;
    if ((u8)(entityInfo->immobilize.immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityInfo->unk9C);
    }
    else if (entityInfo->immobilize.immobilizeStatus == STATUS_INGRAIN) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA844);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->immobilize.immobilizeStatus != STATUS_CONSTRICTION) {
      entityInfo->immobilize.immobilizeStatus = STATUS_CONSTRICTION;
      entityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E58,TRUE) + 1;
      entityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
      entityInfo->immobilize.unk4 = param_3_s32;
      nullsub_71(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB628);
      sub_806CE94(target,8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB64C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ImmobilizedStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = target->axObj.info;
    if ((u8)(entityInfo->immobilize.immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityInfo->unk9C);
    }
    else if (entityInfo->immobilize.immobilizeStatus == STATUS_INGRAIN) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA844);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->immobilize.immobilizeStatus != STATUS_SHADOW_HOLD) {
      entityInfo->immobilize.immobilizeStatus = STATUS_SHADOW_HOLD;
      entityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E54,TRUE) + 1;
      entityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
      nullsub_70(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB668);
      sub_806CE94(target,8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB688);
    }
    EntityUpdateStatusSprites(target);
  }
}

void IngrainedStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    entityInfo2 = entityInfo;
    if ((u8)(entityInfo->immobilize.immobilizeStatus - 3U) < 2) {
      sub_8076CB4(entityInfo->unk9C);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo2->immobilize.immobilizeStatus != STATUS_INGRAIN) {
      entityInfo2->immobilize.immobilizeStatus = STATUS_INGRAIN;
      entityInfo2->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E60,TRUE) + 1;
      entityInfo2->immobilize.immobilizeStatusDamageCountdown = 0;
      nullsub_90(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB6A4);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB6C0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WrapTarget(Entity * pokemon, Entity * target)
{
  EntityInfo * targetEntityInfo;
  s32 *piVar3;
  s32 *iVar5;
  EntityInfo * pokemonEntityData;

  if (!EntityExists(target)) {
    return;
  }

  if (HasSafeguardStatus(pokemon, target, TRUE)) {
    return;
  }
  pokemonEntityData = pokemon->axObj.info;
  targetEntityInfo = target->axObj.info;
  if ((u8)(pokemonEntityData->immobilize.immobilizeStatus - 3U) > 1) {
    if ((targetEntityInfo->immobilize.immobilizeStatus != STATUS_WRAP))
    {
        if(targetEntityInfo->immobilize.immobilizeStatus != STATUS_WRAPPED) {
            pokemonEntityData->immobilize.immobilizeStatus = STATUS_WRAP;
            pokemonEntityData->immobilize.immobilizeStatusTurns = 0x7f;
            pokemonEntityData->immobilize.immobilizeStatusDamageCountdown = 0;
            targetEntityInfo->immobilize.immobilizeStatus = STATUS_WRAPPED;
            targetEntityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E5C, TRUE) + 1;
            targetEntityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
            iVar5 = &pokemonEntityData->unk9C;
            piVar3 = &gDungeon->unk37F4;
            *iVar5 = *piVar3;
            targetEntityInfo->unk9C  = *piVar3;
            *piVar3 +=1;
            nullsub_69(pokemon, target);
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FB6D8);
            sub_806CE94(target,8);
            goto _08076C98;
        }
    }
  }
  if (pokemonEntityData->immobilize.immobilizeStatus == STATUS_WRAP) {
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB6FC);
  }
  if (targetEntityInfo->immobilize.immobilizeStatus == STATUS_WRAP) {
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB6FC);
  }
  if (pokemonEntityData->immobilize.immobilizeStatus == STATUS_WRAPPED) {
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB718);
  }
  if (targetEntityInfo->immobilize.immobilizeStatus == STATUS_WRAPPED) {
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_80522F4(pokemon,target,*gUnknown_80FB718);
  }
_08076C98:
  EntityUpdateStatusSprites(target);
}

void sub_8076CB4(s32 param_1)
{
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeon->allPokemon[index];
    if (EntityExists(entity)) {
      entityInfo = entity->axObj.info;
      if (entityInfo->unk9C == param_1) {
        if ((u8)(entityInfo->immobilize.immobilizeStatus - 3U) < 2) {
          entityInfo->immobilize.immobilizeStatus = STATUS_NONE;
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

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    sub_8041C08(target);
    targetEntityInfo = target->axObj.info;
    if ((u8)(targetEntityInfo->immobilize.immobilizeStatus - 3U) < 2) {
      sub_8076CB4(targetEntityInfo->unk9C);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (targetEntityInfo->immobilize.immobilizeStatus != STATUS_PETRIFIED) {
      targetEntityInfo->immobilize.immobilizeStatus = STATUS_PETRIFIED;
      if (targetEntityInfo->isTeamLeader) {
        targetEntityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EBC,TRUE) + 1;
      }
      else {
        targetEntityInfo->immobilize.immobilizeStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EC0,TRUE) + 1;
      }
      targetEntityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
      sub_80522F4(pokemon,target,*gUnknown_80FB7BC);

    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB7DC);
    }
    if (targetEntityInfo->isNotTeamMember) {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
          entityInfo = entity->axObj.info;
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

void LowerAttackStageTarget(Entity * pokemon, Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage)
{
  EntityInfo *entityInfo;
  s32 attackStage = decrement;

  if (!EntityExists(target)) {
    return;
  }
  if (index != STAT_STAGE_ATK) {
    strcpy(gFormatItems,*gUnknown_80FC0C8);
  }
  else {
    strcpy(gFormatItems,*gUnknown_80FC0B8);
  }
  if (param_5) {
    if (sub_8071728(pokemon,target,displayMessage)) {
      return;
    }
    if (HasHeldItem(target, ITEM_TWIST_BAND)) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FD550);
    }
    else {
      if ((!HasAbility(target, ABILITY_HYPER_CUTTER)) || (index != STAT_STAGE_ATK)) goto _08076EE4;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FCA60);
    }
  }
  else {
_08076EE4:
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F28(target,index);
    if (decrement == 1) {
      strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
      strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }
    attackStage = entityInfo->offensiveStages[index];
    attackStage -= decrement;
    if (attackStage < 0) {
      attackStage = 0;
    }
    if (entityInfo->offensiveStages[index] != attackStage) {
      entityInfo->offensiveStages[index] = attackStage;
      sub_80522F4(pokemon,target,*gUnknown_80FC15C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC274);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LowerDefenseStageTarget(Entity * pokemon, Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage)
{
    EntityInfo *entityInfo;
    s32 defenseStage = decrement;

    if (!EntityExists(target)) {
        return;
    }
    if (index != STAT_STAGE_DEF) {
        strcpy(gFormatItems,*gUnknown_80FC0AC);
    }
    else {
        strcpy(gFormatItems,*gUnknown_80FC09C);
    }
    if (!param_5 || !sub_8071728(pokemon,target,displayMessage)) {
        entityInfo = target->axObj.info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_8041F4C(target,index);
        if (decrement == 1) {
            strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
        }
        else {
            strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
        }
        defenseStage = entityInfo->defensiveStages[index];
        defenseStage = defenseStage - decrement;
        if (defenseStage < 0) {
            defenseStage = 0;
        }
        if (entityInfo->defensiveStages[index] != defenseStage) {
            entityInfo->defensiveStages[index] = defenseStage;
            sub_80522F4(pokemon,target,*gUnknown_80FC158);
        }
        else {
            sub_80522F4(pokemon,target,*gUnknown_80FC248);
        }
        EntityUpdateStatusSprites(target);
  }
}

void RaiseAttackStageTarget(Entity * pokemon, Entity * target, s32 index, s32 increment)
{
    EntityInfo *entityInfo;
    s32 attackStage = increment;

    if (!EntityExists(target)) {
        return;
    }
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F70(target,index);
    if (index != STAT_STAGE_ATK) {
        strcpy(gFormatItems,*gUnknown_80FC0C8);
    }
    else {
        strcpy(gFormatItems,*gUnknown_80FC0B8);
    }

    if (increment == 1) {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }

    attackStage = entityInfo->offensiveStages[index];
    attackStage = attackStage + increment;
    if (attackStage >= MAX_STAT_STAGE) {
        attackStage = MAX_STAT_STAGE;
    }
    if (entityInfo->offensiveStages[index] != attackStage) {
        entityInfo->offensiveStages[index] = attackStage;
        sub_80522F4(pokemon,target,*gUnknown_80FC13C);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FC270);
    }
    EntityUpdateStatusSprites(target);
}

void RaiseDefenseStageTarget(Entity * pokemon, Entity * target, s32 index, s32 increment)
{
    EntityInfo *entityInfo;
    s32 defenseStage = increment;

    if (!EntityExists(target)) {
        return;
    }
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    sub_8041F94(target,index);
    if (index != STAT_STAGE_DEF) {
        strcpy(gFormatItems,*gUnknown_80FC0AC);
    }
    else {
        strcpy(gFormatItems,*gUnknown_80FC09C);
    }

    if (increment == 1) {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0E4);
    }
    else {
        strcpy(gUnknown_202DEA8,*gUnknown_80FC0D4);
    }

    defenseStage = entityInfo->defensiveStages[index];
    defenseStage = defenseStage + increment;
    if (defenseStage >= MAX_STAT_STAGE) {
        defenseStage = MAX_STAT_STAGE;
    }
    if (entityInfo->defensiveStages[index] != defenseStage) {
        entityInfo->defensiveStages[index] = defenseStage;
        sub_80522F4(pokemon,target,*gUnknown_80FC138);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FC21C);
    }
    EntityUpdateStatusSprites(target);
}
