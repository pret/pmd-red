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

bool8 CannotAttack(struct DungeonEntity *pokemon, bool8 skipSleep)
{
  struct DungeonEntityData *pokemonData = pokemon->entityData;
  if ((skipSleep ||
      pokemonData->sleepStatus == SLEEP_STATUS_SLEEPLESS ||
      pokemonData->sleepStatus == SLEEP_STATUS_YAWNING ||
      pokemonData->sleepStatus == SLEEP_STATUS_NONE) &&
      pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_FROZEN &&
      pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE &&
      pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_WRAPPED_BY_FOE &&
      pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_PETRIFIED &&
      pokemonData->volatileStatus != VOLATILE_STATUS_CRINGING &&
      pokemonData->volatileStatus != VOLATILE_STATUS_PAUSED &&
      pokemonData->volatileStatus != VOLATILE_STATUS_INFATUATED &&
      pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_PARALYZED &&
      !ShouldAvoidEnemies(pokemon)) {
      return FALSE;
  }
  return TRUE;
}
