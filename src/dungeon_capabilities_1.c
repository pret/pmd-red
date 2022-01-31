#include "global.h"
#include "dungeon_capabilities_1.h"

#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "charge_move.h"
#include "dungeon_ai.h"
#include "dungeon_capabilities.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_util.h"
#include "map.h"

const u8 gDirectionBitMasks[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

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

bool8 CanMoveInDirection(struct DungeonEntity *pokemon, u32 facingDir)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->entityData->entityID);
    struct MapTile *currentMapTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[facingDir].x,
        pokemon->posWorld.y + gAdjacentTileOffsets[facingDir].y);
    if (currentMapTile->tileType & TILE_TYPE_MAP_EDGE || currentMapTile->pokemon != NULL)
    {
        return FALSE;
    }
    if (!IsFixedDungeon())
    {
        if (pokemon->entityData->transformStatus == TRANSFORM_STATUS_MOBILE || HasItem(pokemon, ITEM_ID_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (HasIQSkill(pokemon, IQ_SKILL_ALL_TERRAIN_HIKER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (HasIQSkill(pokemon, IQ_SKILL_SUPER_MOBILE))
        {
            if (facingDir & 1)
            {
                // Super Mobile can't break walls diagonally.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }
    currentMapTile = GetMapTileAtPosition(pokemon->posWorld.x, pokemon->posWorld.y);
    if (!(currentMapTile->canMoveAdjacent[crossableTerrain] & gDirectionBitMasks[facingDir & DIRECTION_MASK]))
    {
        return FALSE;
    }
    return TRUE;
}
