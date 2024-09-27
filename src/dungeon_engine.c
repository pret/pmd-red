#include "global.h"
#include "dungeon_engine.h"

#include "code_803E46C.h"
#include "constants/dungeon.h"
#include "dungeon_ai_leader.h"
#include "dungeon_ai.h"
#include "dungeon_leader.h"
#include "dungeon_movement.h"
#include "dungeon_util.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"

extern s16 gSpeedTurns[2][25];

extern bool8 sub_8044B28(void);
extern void TrySpawnMonsterAndActivatePlusMinus(void);
extern void sub_807E378(void);
extern void sub_8044574(void);
extern void sub_8044820(void);
extern void sub_8044AB4(void);
extern u8 UseAttack(u32);
extern void TickStatusHeal(Entity *);
extern void sub_8086AC0(void);
extern void sub_8043ED0(u32);
extern void sub_8071DA4(Entity *);
extern void TriggerWeatherAbilities(void);
extern void sub_805D8C8(void);
extern void sub_805F02C(void);

static void sub_8044454(void);
static bool8 xxx_dungeon_80442D0(bool8);


bool8 IsBossFight()
{
    if (gDungeon->bossBattleIndex != 0 && gDungeon->bossBattleIndex <= 0x31)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsCurrentFixedRoomBossFight()
{
    if (gDungeon->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsMakuhitaTrainingMaze(void)
{
    if( (u8)(gDungeon->dungeonLocation.id - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE)
        return TRUE;
    else
        return FALSE;
}

void RunFractionalTurn(bool8 param_1)
{
  bool8 cVar2;

  if (!sub_8044B28()) {
    TrySpawnMonsterAndActivatePlusMinus();
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
              gDungeon->fractionalTurn++;
              if (gDungeon->fractionalTurn == 24) {
                 gDungeon->fractionalTurn = 0;
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
  EntityInfo *entityInfo;
  Entity *entity;
  s32 movSpeed;

  entity = GetLeader();
  if (entity == NULL) {
      return FALSE;
  }
  else
  {
    TriggerWeatherAbilities();
    movSpeed = CalcSpeedStage(entity);
    if (gSpeedTurns[movSpeed][gDungeon->fractionalTurn] == 0) {
        return FALSE;
    }
    else
    {
      if (entity->axObj.info->attacking) {
          return FALSE;
      }
      else
      {
        while (1) {
          if(entity = GetLeader(), entity == NULL)
          {
              return FALSE;
          }
          else
          {
            if ((UseAttack(0) == 0) &&
                ((gDungeon->unk66C != 0 ||
                (gDungeon->unk673 != 0)))) {
                sub_803E46C(0xc);
            }
            entity->axObj.info->speedStageChanged = FALSE;
            if (sub_8044B28()) return FALSE;
            gDungeon->unkB8 = entity;
            gDungeon->unkBC = 0;
            if (param_1) {
                param_1 = FALSE;
            }
            else {
                TickStatusHeal(entity);
            }
            if (sub_8044B28()) return FALSE;
            sub_8071DA4(entity);
            gDungeon->noActionInProgress = TRUE;
            sub_805D8C8();
            gDungeon->noActionInProgress = FALSE;
            if (sub_8044B28()) break;
            sub_8072CF4(entity);
            sub_8086AC0();
            sub_8043ED0(0);
            if (sub_8044B28()) break;
            entityInfo = entity->axObj.info;
            if ((entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) {
                entity->axObj.info->flags = (entityInfo->flags & ~(MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) | MOVEMENT_FLAG_UNK_14;
            }
            if (sub_8044B28() ) break;
            sub_8044454();
            if (sub_8044B28()) break;
            if (gDungeon->unkBC != 0) {
                sub_805F02C();
                gDungeon->unkBC = 0;
                param_1 = TRUE;
            }
            else {
                if (!entity->axObj.info->speedStageChanged) break;
                gDungeon->fractionalTurn = 0;
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
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  if (gDungeon->unkE) {
    gDungeon->unkE = 0;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->allPokemon[index];
      if ((EntityExists(entity)) && (entityInfo = entity->axObj.info, (entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY))) {
        if (sub_8044B28()) break;
        TickStatusHeal(entity);
        if (EntityExists(entity)) {
          sub_8071DA4(entity);
          RunMonsterAI(entity, 0);
          sub_8072CF4(entity);
          sub_8086AC0();
          sub_8043ED0(0);
          entityInfo->flags = (entityInfo->flags & ~(MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) | MOVEMENT_FLAG_UNK_14;
        }
      }
    }
  }
}

void sub_80444F4(Entity *pokemon)
{
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  if (pokemon == GetLeader() && gDungeon->unkE) {
    gDungeon->unkE = 0;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->allPokemon[index];
      if ((EntityExists(entity)) && (pokemon != entity) && (entityInfo = entity->axObj.info, (entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY))) {
        if (sub_8044B28()) break;
        RunMonsterAI(entity, 0);
        sub_8072CF4(entity);
        sub_8086AC0();
        sub_8043ED0(0);
      }
    }
  }
}
