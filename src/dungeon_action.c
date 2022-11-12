#include "global.h"
#include "dungeon_action.h"

#include "constants/ability.h"
#include "constants/dungeon_action.h"
#include "dungeon_ai.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "dungeon_pokemon_attributes.h"
#include "pokemon.h"
#include "item.h"
#include "status_checks_1.h"

extern u8 *gUnknown_80F91EC[];
extern u8 *gUnknown_80F7C50[];
extern u8 gUnknown_80F697C[];
extern s16 gSpeedTurns[2][0x19];

struct ItemText
{
    u8 *desc;
    u8 *useText;
};
extern const struct ItemText gActions[];

extern void sub_8071B48(void);
extern void sub_8043ED0(u32);
extern u8 sub_8043D10(void);
extern bool8 sub_8044B28(void);
extern void sub_8086AC0(void);
extern void sub_8043ED0(u32);
extern void sub_807EAA0(u32, u32);
extern void UseAttack(u32);

extern void sub_8071B48(void);
extern void TriggerWeatherAbilities(void);
extern void sub_8074094(struct DungeonEntity *);
extern void sub_8071DA4(struct DungeonEntity *);
extern u8 sub_8072CF4(struct DungeonEntity *);
extern void TickStatusHeal(struct DungeonEntity *);

void sub_8044820(void)
{
  s32 movSpeed;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData2;
  struct DungeonEntity * entity;
  struct DungeonEntity * entity2;
  s32 index;
  
  for (index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++) {
    entity = gDungeonGlobalData->wildPokemon[index];
    if (EntityExists(entity)) {
      if (sub_8044B28()) break;
      entityData = entity->entityData;
      gDungeonGlobalData->unkB8 = entity;
      TriggerWeatherAbilities();
      if ((entityData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED) == 0) {
        if ((u16)(entityData->flags & MOVEMENT_FLAG_UNK_14) != 0) {
            entityData->flags &= ~(MOVEMENT_FLAG_UNK_14);
        }
        else
        {
          entityData->movingIntoTarget = FALSE;
          movSpeed = GetMovementSpeed(entity);
          if (gSpeedTurns[movSpeed][gDungeonGlobalData->speedTurnCounter] != 0) {
            if (!entityData->attacking) {
              entityData->flags &= ~(MOVEMENT_FLAG_UNK_14 | MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED);
              entityData->recalculateFollow = FALSE;
              TickStatusHeal(entity);
              if (EntityExists(entity)) {
                sub_8071DA4(entity);
                DecideAction(entity, 0);
                if (sub_8044B28()) break;
                sub_8072CF4(entity);
                sub_8086AC0();
                sub_8043ED0(0);
                if (sub_8044B28()) break;
              }
            }
          }
        }
      }
    }
  }
  if (sub_8044B28() == 0) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      entity2 = gDungeonGlobalData->wildPokemon[index];
      if ((EntityExists(entity2)) && (entityData2 = entity2->entityData, entityData2->movingIntoTarget))
      {
        sub_8074094(entity2);
        if (EntityExists(entity2)) {
          sub_8071DA4(entity2);
          entityData2->movingIntoTarget = FALSE;
        }
      }
    }
  }
}

void CheckElectricAbilities(void)
{
  struct DungeonEntityData * entityData;
  struct DungeonEntityData * entityData2;
  struct DungeonEntity *entity;
  u32 isNotEnemy;
  s32 index;
  
  if (gSpeedTurns[1][gDungeonGlobalData->speedTurnCounter] != 0) {
    sub_8071B48();
    gDungeonGlobalData->hasPlus[0] = FALSE;
    gDungeonGlobalData->hasPlus[1] = FALSE;
    gDungeonGlobalData->hasMinus[0] = FALSE;
    gDungeonGlobalData->hasMinus[1] = FALSE;
    gDungeonGlobalData->lightningRodPokemon = NULL;
    gDungeonGlobalData->unk17B38 = 2;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeonGlobalData->allPokemon[index];
        if (EntityExists(entity)) {
            entityData = entity->entityData;
            entityData2 = entityData;
            entityData->attacking = FALSE;

            if(entityData->isEnemy)
            {
                isNotEnemy = FALSE;
            }
            else {
                isNotEnemy = TRUE;
            }

            if (HasAbility(entity, ABILITY_LIGHTNINGROD)) {
                gDungeonGlobalData->lightningRodPokemon = entity;
                gDungeonGlobalData->unk17B38 = entityData2->unk98;
            }
            if (HasAbility(entity, ABILITY_MINUS)) {
                gDungeonGlobalData->hasMinus[isNotEnemy] = TRUE;
            }  
            if (HasAbility(entity, ABILITY_PLUS)) {
                gDungeonGlobalData->hasPlus[isNotEnemy] = TRUE;
            }
        }
    }
    sub_8043ED0(0);
  }
}

void sub_8044AB4(void)
{
  s32 index;
  
  if (gSpeedTurns[1][gDungeonGlobalData->speedTurnCounter + 1] != 0) {
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
      if (EntityExists(gDungeonGlobalData->allPokemon[index])) {
        UseAttack(0);
        break;
      }
    }
    sub_807EAA0(1,0);
    sub_8086AC0();
    sub_8043ED0(0);
  }
}

bool8 sub_8044B28(void)
{
    if (gDungeonGlobalData->unk4 == 0) {
        if (GetLeaderEntity() == NULL) {
            gDungeonGlobalData->unk654 = 1;
        }
        else if (gDungeonGlobalData->unk2 == 1) {
            gDungeonGlobalData->unk654 = 2;
        }
        else if (gDungeonGlobalData->unk2 != 2) {
            return FALSE;
        }
        else {
            gDungeonGlobalData->unk654 = 2;
        }
    }
    return TRUE;
}
 
bool8 sub_8044B84(void)
{
    if(gDungeonGlobalData->unk10 != 0)
    {
        return TRUE;
    }
    else {
        return sub_8044B28();
    }
}

u8 *sub_8044BA8(u16 param_1, u8 itemIndex)
{
  u32 uVar3;
  u32 uVar4;
  
  if ((param_1 == 0x26) && (sub_8043D10() == 2)) {
    return *gUnknown_80F91EC;
  }
  else {
    uVar3 = uVar4 = strcmp(gUnknown_80F7C50[param_1 << 1], gUnknown_80F697C);
    if (uVar3 != 0) {
      uVar4 = 1;
    }
    if ((u8)(uVar4) == 0) {
        return gActions[GetItemCategory(itemIndex)].useText;
    }
    else
    {
        return gUnknown_80F7C50[param_1 << 1];
    }
  }
}

void sub_8044C10(u8 param_1)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = DUNGEON_ACTION_NONE;

    if(param_1)
    {
        entityData->action.actionUseIndex = 0;
        entityData->action.unkC = 0;
        entityData->action.itemTargetPosition.x = -1;
        entityData->action.itemTargetPosition.y = -1;
    }
}

void sub_8044C50(u16 action)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = action;
    entityData->action.actionUseIndex = 0;
    entityData->action.unkC = 0;
    entityData->action.itemTargetPosition.x = -1;
    entityData->action.itemTargetPosition.y = -1;
}

void ResetAction(struct DungeonActionContainer *actionPointer)
{
    actionPointer->action = DUNGEON_ACTION_NONE;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetAction(struct DungeonActionContainer *actionPointer, u16 action)
{
    actionPointer->action = action;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetWalkAction(struct DungeonActionContainer *actionPointer, s16 species)
{
    if (GetIsMoving(species))
    {
        actionPointer->action = DUNGEON_ACTION_WALK;
    }
    else
    {
        actionPointer->action = DUNGEON_ACTION_WAIT;
    }
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}
