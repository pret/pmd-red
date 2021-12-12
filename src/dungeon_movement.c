#include "global.h"
#include "dungeon_movement.h"

#include "constants/dungeon_action.h"
#include "constants/direction.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "dungeon_ai_items.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "map.h"
#include "pokemon.h"

extern char gAvailablePokemonNames[];
extern char *gPtrCouldntBeUsedMessage;
extern char *gPtrItsaMonsterHouseMessage;
extern struct DungeonGlobalData *gDungeonGlobalData;

extern void SendImmobilizeEndMessage(struct DungeonEntity*, struct DungeonEntity*);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void SendMessage(struct DungeonEntity*, char*);
extern bool8 HasStatusAffectingActions(struct DungeonEntity*);
extern bool8 CanSee(struct DungeonEntity*, struct DungeonEntity*);
extern void ResetAction(u16*);
extern void SetWalkAction(u16*, s16);
extern void DecideAttack(struct DungeonEntity*);
extern void MoveIfPossible(struct DungeonEntity*, bool8);
extern u8 sub_8044B28(void);
extern void sub_807AB38(struct DungeonEntity *, u32);
extern void sub_8041888(u32);
extern u8 sub_803F428(s16 *);
extern void sub_803E708(u32, u32);
extern struct DungeonEntity *GetLeaderEntity();
extern void TargetTileInFront(struct DungeonEntity *);

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
        tile = sub_8045128(entity);
        if(HasIQSkill(entity, IQ_SKILL_SUPER_MOBILE))
            if(!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_UNK_1)))
                return 1;
        subEntity = tile->mapObject;
        if(subEntity != NULL)
        {
            switch(GetEntityType(subEntity))
            {
                case ENTITY_NONE:
                case ENTITY_POKEMON:
                case 4:
                case 5:
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
                            if(!(tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_UNK_1)))
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
                    if((sub_8045128(pokemon)->tileType & TILE_TYPE_MONSTER_HOUSE))
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
    if ((pokemonData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED) != 0)
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
                ResetAction(&pokemonData->action.action);
                if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
                {
                    SetWalkAction(&pokemonData->action.action, pokemonData->entityID);
                    pokemonData->action.facingDir = DungeonRandomCapped(8);
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
                                SetWalkAction(&pokemonData->action.action, pokemonData->entityID);
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
                                SetWalkAction(&pokemonData->action.action, pokemonData->entityID);
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
