#include "global.h"
#include "dungeon_capabilities_1.h"

#include "constants/dungeon.h"
#include "constants/status.h"
#include "charge_move.h"
#include "dungeon_ai.h"
#include "dungeon_capabilities.h"

static inline bool8 JoinLocationCannotUseItems(struct DungeonEntityData *pokemonData)
{
    if (pokemonData->joinLocation == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonData->joinLocation == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotUseItems(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->clientType == CLIENT_TYPE_CLIENT
        || JoinLocationCannotUseItems(pokemonData)
        || (!pokemonData->isLeader && ShouldAvoidEnemies(pokemon))
        || CannotMove(pokemon, FALSE)
        || CannotAct(pokemon))
    {
        return TRUE;
    }
    if (IsCharging(pokemon, FALSE))
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotAct(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if ((pokemonData->sleepStatus != SLEEP_STATUS_SLEEPLESS
        && pokemonData->sleepStatus != SLEEP_STATUS_NONE)
        || pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN
        || pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
    {
        return TRUE;
    }
    if (pokemonData->chargingStatus == CHARGING_STATUS_BIDE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotAttack(struct DungeonEntity *pokemon, u8 param_2)
{
  struct DungeonEntityData *iVar3;
  
  iVar3 = pokemon->entityData;
  if ((((((param_2 != '\0') || 
    (iVar3->sleepStatus == SLEEP_STATUS_SLEEPLESS)) ||
    (iVar3->sleepStatus == SLEEP_STATUS_YAWNING)) ||
    (iVar3->sleepStatus == SLEEP_STATUS_NONE)) &&
    ((((iVar3->immobilizeStatus != IMMOBILIZE_STATUS_FROZEN && 
    (iVar3->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE)) &&
    ((iVar3->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_BY_FOE &&
    ((iVar3->immobilizeStatus != IMMOBILIZE_STATUS_PETRIFIED &&
    (iVar3->volatileStatus != VOLATILE_STATUS_CRINGING)))))) &&
    (iVar3->volatileStatus != VOLATILE_STATUS_PAUSED)))) &&
     (((iVar3->volatileStatus != VOLATILE_STATUS_INFATUATED &&
     iVar3->nonVolatileStatus != NON_VOLATILE_STATUS_PARALYZED)) &&
      !ShouldAvoidEnemies(pokemon))) {
      return FALSE;
  }
  return TRUE;
}
