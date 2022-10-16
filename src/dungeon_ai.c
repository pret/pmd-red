#include "global.h"
#include "dungeon_ai.h"

#include "constants/ability.h"
#include "constants/dungeon_action.h"
#include "constants/direction.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "pokemon.h"
#include "status_checks.h"
#include "targeting.h"

extern char gAvailablePokemonNames[];
extern char *gPtrCouldntBeUsedMessage;
extern char *gPtrItsaMonsterHouseMessage;
extern u8 *gUnknown_80FB380[];
extern u8 *gUnknown_80FB384[];
extern u8 *gUnknown_80FB338[];
extern u8 *gUnknown_80FB318[];
extern u8 *gUnknown_80FB35C[];

extern void DungeonEntityUpdateStatusSprites(struct DungeonEntity *);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern u8 sub_8044B28(void);
extern void sub_807AB38(struct DungeonEntity *, u32);
extern void sub_8041888(u32);
extern u8 sub_803F428(s16 *);
extern void sub_803E708(u32, u32);
extern struct DungeonEntity *GetLeaderEntity();
extern u8 sub_8075CFC(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern void sub_8041AF4(struct DungeonEntity *);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, u8 *);
extern void sub_806CE68(struct DungeonEntity *, s32);

u32 sub_8075818(struct DungeonEntity *entity)
{
    struct MapTile *tile;
    struct DungeonEntityData *entityData;
    struct DungeonEntity *subEntity;
    struct ItemSlot *item;
    u8 *trapData; // TODO: turn into struct when more research is done..
    u8 r1;

    entityData = entity->entityData;
    if(EntityExists(entity))
    {
        tile = GetMapTileForDungeonEntity_2(entity);
        if(HasIQSkill(entity, IQ_SKILL_SUPER_MOBILE))
            if(!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
                return 1;
        subEntity = tile->mapObject;
        if(subEntity != NULL)
        {
            switch(GetEntityType(subEntity))
            {
                case ENTITY_NONE:
                case ENTITY_POKEMON:
                case ENTITY_UNK_4:
                case ENTITY_UNK_5:
                    break;
                case ENTITY_TRAP:
                    trapData = (u8*) GetTrapData(subEntity);
                    r1 = 0;
                    if(trapData[1] == 0)
                    {
                        if(!subEntity->visible || entityData->isEnemy)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData[1] == 1)
                    {
                        if(!entityData->isEnemy)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData[1] == 2)
                    {
                        if(!entityData->isEnemy)
                            r1 = 1;
                    }
flag_check:
                    if(r1 == 0)
                        break;
                    else
                        goto error;
                case ENTITY_ITEM:
                    if(!entityData->isLeader)
                    {
                        if(!(entityData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
                        {
                            if(!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
                            {
                                if(entityData->isEnemy)
                                    break;
                                else
                                {
                                    item = GetItemData(subEntity);
                                    if(!(item->itemFlags & ITEM_FLAG_FOR_SALE))
                                    {
                                        return 1;
                                    }
                                }
                            }
                            else
                            {
                                item = GetItemData(subEntity);
                                if(!(item->itemFlags & ITEM_FLAG_FOR_SALE))
                                {
error:
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}

void sub_8075900(struct DungeonEntity *pokemon, u8 r1)
{
    if(EntityExists(pokemon))
    {
        if(!pokemon->entityData->isEnemy)
        {
            if(!sub_8044B28())
            {
                if(!gDungeonGlobalData->monsterHouseActive)
                {
                    if((GetMapTileForDungeonEntity_2(pokemon)->tileType & TILE_TYPE_MONSTER_HOUSE))
                    {
                        // It's a monster house!
                        SendMessage(GetLeaderEntity(), gPtrItsaMonsterHouseMessage);
                        gDungeonGlobalData->unk672 = 1;
                        sub_807AB38(pokemon, r1);
                        sub_8041888(0);
                        if(sub_803F428(&pokemon->posWorld.x) != 0)
                            sub_803E708(0x78, 0x39);
                    }
                }
            }
        }
    }
}

void DecideAction(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED)
    {
        if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
        {
            SendImmobilizeEndMessage(pokemon, pokemon);
        }
    }
    else
    {
        pokemonData->targetingDecoy = TARGETING_DECOY_NONE;
        if (pokemonData->clientType == CLIENT_TYPE_NONE || IsMovingClient(pokemon))
        {
            if (pokemonData->clientType != CLIENT_TYPE_CLIENT && pokemonData->useHeldItem)
            {
                if (CannotUseItems(pokemon))
                {
                    pokemonData->useHeldItem = FALSE;
                    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
                    SendMessage(pokemon, gPtrCouldntBeUsedMessage);
                    return;
                }
                DecideUseItem(pokemon);
                if (pokemonData->action.action != DUNGEON_ACTION_NONE)
                {
                    return;
                }
            }
            if (!HasStatusAffectingActions(pokemon))
            {
                if (gDungeonGlobalData->decoyActive)
                {
                    s32 i;
                    struct DungeonEntity *target;
                    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
                    {
                        target = gDungeonGlobalData->allPokemon[i];
                        if (EntityExists(target) &&
                            target->entityData->waitingStatus == WAITING_STATUS_DECOY &&
                            CanSee(pokemon, target))
                        {
                            bool8 enemyDecoy = target->entityData->enemyDecoy;
                            u8 targetingDecoy = TARGETING_DECOY_TEAM;
                            if (enemyDecoy)
                            {
                                targetingDecoy = TARGETING_DECOY_WILD;
                            }
                            pokemonData->targetingDecoy = targetingDecoy;
                            break;
                        }
                    }
                }
                ResetAction(&pokemonData->action);
                if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
                {
                    SetWalkAction(&pokemonData->action, pokemonData->entityID);
                    pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
                    pokemonData->targetPosition.x = pokemon->posWorld.x;
                    pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
                }
                else
                {
                    DecideUseItem(pokemon);
                    if (pokemonData->action.action == DUNGEON_ACTION_NONE)
                    {
                        if (!HasIQSkill(pokemon, IQ_SKILL_DEDICATED_TRAVELER))
                        {
                            DecideAttack(pokemon);
                            if (pokemonData->action.action != DUNGEON_ACTION_NONE)
                            {
                                return;
                            }
                            if (pokemonData->volatileStatus == VOLATILE_STATUS_CONFUSED)
                            {
                                SetWalkAction(&pokemonData->action, pokemonData->entityID);
                            }
                            else
                            {
                                if (!GetIsMoving(pokemonData->entityID))
                                {
                                    return;
                                }
                                MoveIfPossible(pokemon, TRUE);
                            }
                        }
                        else
                        {
                            if (pokemonData->volatileStatus == VOLATILE_STATUS_CONFUSED)
                            {
                                SetWalkAction(&pokemonData->action, pokemonData->entityID);
                            }
                            else
                            {
                                if (GetIsMoving(pokemonData->entityID))
                                {
                                    MoveIfPossible(pokemon, TRUE);
                                }
                                if (pokemonData->action.action > DUNGEON_ACTION_WAIT)
                                {
                                    return;
                                }
                                DecideAttack(pokemon);
                                if (pokemonData->action.action <= DUNGEON_ACTION_WAIT)
                                {
                                    return;
                                }
                                pokemonData->notAdjacentToTarget = FALSE;
                                pokemonData->movingIntoTarget = FALSE;
                                pokemonData->waiting = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}

void sub_8075BA4(struct DungeonEntity *param_1,char param_2)
{
  struct DungeonEntityData * iVar2 = param_1->entityData;

  if ((param_2 != '\0') && (iVar2->volatileStatus == VOLATILE_STATUS_COWERING)) {
      iVar2->action.facingDir = (iVar2->action.facingDir + 4) & DIRECTION_MASK;
      TargetTileInFront(param_1);
  }
  else if (iVar2->volatileStatus == VOLATILE_STATUS_CONFUSED) {
      iVar2->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
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

void sub_8075C58(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 param_3, u8 param_4)
{
  u8 sleepStatus;
  u8 cVar2;
  

  if (sub_8075CFC(pokemon,target,1,param_4) == '\0') {
    sleepStatus = target->entityData->sleepStatus;
    if (sleepStatus == SLEEP_STATUS_SLEEPLESS) {
      if (param_4)
        sub_80522F4(pokemon,target,*gUnknown_80FB380);
    }
    else if (sleepStatus == SLEEP_STATUS_NAPPING) {
      if (param_4)
        sub_80522F4(pokemon,target,*gUnknown_80FB384);
    }
    else {
      sub_8041AF4(target);
      cVar2 = sub_8075BF4(target,param_3);
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
