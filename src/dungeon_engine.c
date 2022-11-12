#include "global.h"
#include "dungeon_entity.h"
#include "dungeon_engine.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"
#include "dungeon_ai.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "status_checks_1.h"

extern s16 gSpeedTurns[2][25];

extern bool8 sub_8044B28(void);
extern void CheckElectricAbilities(void);
extern void sub_807E378(void);
extern void sub_8044574(void);
extern void sub_8044820(void);
extern void sub_8044AB4(void);
extern u8 UseAttack(u32);
extern u8 sub_8072CF4(struct DungeonEntity *);
extern void TickStatusHeal(struct DungeonEntity *);
extern void sub_8086AC0(void);
extern void sub_8043ED0(u32);
extern void sub_8071DA4(struct DungeonEntity *);
extern void TriggerWeatherAbilities(void);
extern void sub_805D8C8(void);
extern void sub_805F02C(void);
extern void sub_803E46C(u32);

static void sub_8044454(void);
static bool8 xxx_dungeon_80442D0(bool8);


bool8 IsBossBattle()
{
    if (gDungeonGlobalData->bossBattleIndex != 0 && gDungeonGlobalData->bossBattleIndex <= 0x31)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFixedDungeon()
{
    if (gDungeonGlobalData->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8044210(void)
{
    if( (u8)(gDungeonGlobalData->unk644 - 0x4B) < 0x17)
        return TRUE;
    else
        return FALSE;
}

void RunDungeon(bool8 param_1)
{
  bool8 cVar2;
  
  if (!sub_8044B28()) {
    CheckElectricAbilities();
    if (!sub_8044B28()) {
      cVar2 = xxx_dungeon_80442D0(param_1);
      if (!sub_8044B28()) {
        if (cVar2 != 0) {
          sub_807E378();
          if (sub_8044B28()) {
            return;
          }
        }
        if (!sub_8044B28()) {
          sub_8044574();
          if (!sub_8044B28()) {
            sub_8044820();
            if (!sub_8044B28()) {
              sub_8044AB4();
              gDungeonGlobalData->speedTurnCounter++;
              if (gDungeonGlobalData->speedTurnCounter == 24) {
                 gDungeonGlobalData->speedTurnCounter = 0;
              }
            }
          }
        }
      }
    }
  }
}

static bool8 xxx_dungeon_80442D0(bool8 param_1)
{
  struct DungeonEntityData *entityData;
  struct DungeonEntity *entity;
  s32 movSpeed;
  
  entity = GetLeaderEntity();
  if (entity == NULL) {
      return FALSE;
  }
  else
  {
    TriggerWeatherAbilities();
    movSpeed = GetMovementSpeed(entity);
    if (gSpeedTurns[movSpeed][gDungeonGlobalData->speedTurnCounter] == 0) {
        return FALSE;
    }
    else
    {
      if (entity->entityData->attacking) {
          return FALSE;
      }
      else
      {
        while (1) {
          if(entity = GetLeaderEntity(), entity == NULL)
          {
              return FALSE;
          }
          else
          {
            if ((UseAttack(0) == 0) &&
                ((gDungeonGlobalData->unk66C != 0 ||
                (gDungeonGlobalData->unk673 != 0)))) {
                sub_803E46C(0xc);
            }
            entity->entityData->movementSpeedChanged = FALSE;
            if (sub_8044B28()) return FALSE;
            gDungeonGlobalData->unkB8 = entity;
            gDungeonGlobalData->unkBC = 0;
            if (param_1) {
                param_1 = FALSE;
            }
            else {
                TickStatusHeal(entity);
            }
            if (sub_8044B28()) return FALSE;
            sub_8071DA4(entity);
            gDungeonGlobalData->inputAllowed = TRUE;
            sub_805D8C8();
            gDungeonGlobalData->inputAllowed = FALSE;
            if (sub_8044B28()) break;
            sub_8072CF4(entity);
            sub_8086AC0();
            sub_8043ED0(0);
            if (sub_8044B28()) break;
            entityData = entity->entityData;
            if ((entityData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED)) {
                entity->entityData->flags = (entityData->flags & ~(MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED)) | MOVEMENT_FLAG_UNK_14;
            }
            if (sub_8044B28() ) break;
            sub_8044454();
            if (sub_8044B28()) break;
            if (gDungeonGlobalData->unkBC != 0) {
                sub_805F02C();
                gDungeonGlobalData->unkBC = 0;
                param_1 = TRUE;
            }
            else {
                if (!entity->entityData->movementSpeedChanged) break;
                gDungeonGlobalData->speedTurnCounter = 0;
            }
          }
        }
      }
    }
  }
  return TRUE;
}

static void sub_8044454(void)
{
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;
  
  if (gDungeonGlobalData->unkE) {
    gDungeonGlobalData->unkE = 0;
    
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeonGlobalData->allPokemon[index];
      if ((EntityExists(entity)) && (entityData = entity->entityData, (entityData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED))) {
        if (sub_8044B28()) break;
        TickStatusHeal(entity);
        if (EntityExists(entity)) {
          sub_8071DA4(entity);
          DecideAction(entity, 0);
          sub_8072CF4(entity);
          sub_8086AC0();
          sub_8043ED0(0);
          entityData->flags = (entityData->flags & ~(MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED)) | MOVEMENT_FLAG_UNK_14;
        }
      }
    }
  }
}

void sub_80444F4(struct DungeonEntity *pokemon)
{
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;
  
  if (pokemon == GetLeaderEntity() && gDungeonGlobalData->unkE) {
    gDungeonGlobalData->unkE = 0;
    
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeonGlobalData->allPokemon[index];
      if ((EntityExists(entity)) && (pokemon != entity) && (entityData = entity->entityData, (entityData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED))) {
        if (sub_8044B28()) break;
        DecideAction(entity, 0);
        sub_8072CF4(entity);
        sub_8086AC0();
        sub_8043ED0(0);
      }
    }
  }
}
