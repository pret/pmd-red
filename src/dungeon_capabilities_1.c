#include "global.h"
#include "dungeon_capabilities_1.h"

#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "charge_move.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "map.h"

const u8 gDirectionBitMasks_1[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

static inline bool8 JoinLocationCannotUseItems(struct EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotUseItems(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT
        || JoinLocationCannotUseItems(pokemonInfo)
        || (!pokemonInfo->isTeamLeader && ShouldMonsterRunAway(pokemon))
        || CannotMove(pokemon, FALSE)
        || HasStatusThatPreventsActing(pokemon))
    {
        return TRUE;
    }
    if (IsCharging(pokemon, FALSE))
    {
        return TRUE;
    }
    return FALSE;
}

bool8 HasStatusThatPreventsActing(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    if ((pokemonInfo->sleep != STATUS_SLEEPLESS
        && pokemonInfo->sleep != STATUS_NONE)
        || pokemonInfo->immobilizeStatus == STATUS_FROZEN
        || pokemonInfo->immobilizeStatus == STATUS_PETRIFIED)
    {
        return TRUE;
    }
    if (pokemonInfo->chargingStatus == STATUS_BIDE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotAttack(struct Entity *pokemon, bool8 skipSleep)
{
  struct EntityInfo *pokemonInfo = pokemon->info;
  if ((skipSleep ||
      pokemonInfo->sleep == STATUS_SLEEPLESS ||
      pokemonInfo->sleep == STATUS_YAWNING ||
      pokemonInfo->sleep == STATUS_NONE) &&
      pokemonInfo->immobilizeStatus != STATUS_FROZEN &&
      pokemonInfo->immobilizeStatus != STATUS_WRAP &&
      pokemonInfo->immobilizeStatus != STATUS_WRAPPED &&
      pokemonInfo->immobilizeStatus != STATUS_PETRIFIED &&
      pokemonInfo->volatileStatus != STATUS_CRINGE &&
      pokemonInfo->volatileStatus != STATUS_PAUSED &&
      pokemonInfo->volatileStatus != STATUS_INFATUATED &&
      pokemonInfo->nonVolatileStatus != STATUS_PARALYSIS &&
      !ShouldMonsterRunAway(pokemon)) {
      return FALSE;
  }
  return TRUE;
}

bool8 CanMoveInDirection(struct Entity *pokemon, u32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->info->id);
    struct Tile *currentMapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (currentMapTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL || currentMapTile->monster != NULL)
    {
        return FALSE;
    }
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->info->transformStatus == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if (direction & 1)
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
    currentMapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
    if (!(currentMapTile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_1[direction & DIRECTION_MASK]))
    {
        return FALSE;
    }
    return TRUE;
}
