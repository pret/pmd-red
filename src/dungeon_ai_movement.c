#include "global.h"
#include "dungeon_ai_movement.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/tactic.h"
#include "dungeon_action.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_ai_movement_1.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_util.h"
#include "item.h"
#include "number_util.h"
#include "map.h"

extern bool8 CanTakeItem(struct DungeonEntity *pokemon);
extern bool8 ChooseTargetPosition(struct DungeonEntity *pokemon);
extern void DecideMovement(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);

void MoveIfPossible(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    pokemonData->notAdjacentToTarget = FALSE;
    pokemonData->hasTarget = FALSE;
    pokemonData->turnAround = FALSE;
    if (HasTactic(pokemon, TACTIC_BE_PATIENT))
    {
        u32 maxHP = pokemonData->maxHP;
        maxHP += maxHP >> 0x1f;
        if (pokemonData->HP <= (s16) (maxHP / 2))
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
            return;
        }
    }
    if (HasTactic(pokemon, TACTIC_WAIT_THERE))
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (!pokemonData->isLeader && RoundUpFixedPoint(pokemonData->belly) == 0)
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->targetPosition.x = pokemon->posWorld.x;
        pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
    }
    else
    {
        bool8 hasAction;
        if (ShouldAvoidEnemiesAndShowEffect(pokemon, showRunAwayEffect))
        {
            hasAction = AvoidEnemies(pokemon);
        }
        else if (CanTakeItem(pokemon))
        {
            pokemonData->action.action = DUNGEON_ACTION_TAKE_ITEM_AI;
            return;
        }
        else
        {
            hasAction = ChooseTargetPosition(pokemon);
        }
        if (!hasAction)
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
        }
        else
        {
            DecideMovement(pokemon, showRunAwayEffect);
        }
    }
}

bool8 CanTakeItem(struct DungeonEntity *pokemon)
{
  struct MapTile *mapTile;
  struct ItemSlot *item;
  struct DungeonEntity *mapEntity;
  struct DungeonEntityData *entityData;

  entityData = pokemon->entityData;
  if (EntityExists(pokemon) && !CannotUseItems(pokemon)) {
    mapTile = GetMapTileForDungeonEntity_2(pokemon);
    mapEntity = mapTile->mapObject;
    if (mapEntity != NULL) {
      switch(GetEntityType(mapEntity)) {
        case ENTITY_NONE:
        case ENTITY_POKEMON:
        case ENTITY_TRAP:
        case 4:
        case 5:
            break;
        case ENTITY_ITEM:
            if ((((!entityData->isLeader) && !(entityData->heldItem.itemFlags & ITEM_FLAG_EXISTS)) &&
                (((mapTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) || (!entityData->isEnemy)))) &&
            (item = GetItemData(mapEntity), (item->itemFlags & ITEM_FLAG_FOR_SALE) == 0)) {
                return TRUE;
            }
      }
    }
  }
  return FALSE;
}
