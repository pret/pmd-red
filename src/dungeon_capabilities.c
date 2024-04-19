#include "global.h"
#include "dungeon_capabilities.h"

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
#include "structs/map.h"

const u8 gDirectionBitMasks_1[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

bool8 CannotMove(Entity *pokemon, bool8 checkBlinker)
{
    EntityInfo *pokemonInfo = pokemon->info;

    if ((checkBlinker && pokemonInfo->eyesightStatus == STATUS_BLINKER)
        || pokemonInfo->sleep.sleep == STATUS_SLEEP
        || pokemonInfo->sleep.sleep == STATUS_NAPPING
        || pokemonInfo->sleep.sleep == STATUS_NIGHTMARE
        || pokemonInfo->volatileStatus == STATUS_PAUSED
        || pokemonInfo->volatileStatus == STATUS_INFATUATED
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
        return TRUE;

    if (pokemonInfo->terrifiedTurns != 0)
        return TRUE;

    return FALSE;
}

bool8 sub_8070BC0(Entity* entity)
{
    EntityInfo *entityInfo = entity->info;

    if (IsCharging(entity, FALSE)
        || entityInfo->sleep.sleep == STATUS_YAWNING
        || entityInfo->sleep.sleep == STATUS_NIGHTMARE
        || ShouldMonsterRunAway(entity)
        || entityInfo->muzzled == TRUE
        || entityInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED
        || entityInfo->immobilize.immobilizeStatus == STATUS_FROZEN)
        return FALSE;

    if (entityInfo->volatileStatus == STATUS_CONFUSED)
        return FALSE;
    if (entityInfo->sleep.sleep == STATUS_SLEEP)
        return FALSE;
    if (entityInfo->transformStatus == STATUS_INVISIBLE
        || entityInfo->sleep.sleep == STATUS_NAPPING)
        return FALSE;
    if (entityInfo->volatileStatus == STATUS_CRINGE)
        return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAP)
        return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAPPED
        || entityInfo->eyesightStatus == STATUS_CROSS_EYED)
        return FALSE;
    if (entityInfo->waitingStatus == STATUS_DECOY)
        return FALSE;
    if (entityInfo->eyesightStatus == STATUS_BLINKER)
        return FALSE;
    if (entityInfo->volatileStatus != STATUS_INFATUATED
        && entityInfo->volatileStatus != STATUS_PAUSED)
        return TRUE;
        
    return FALSE;
}

static inline bool8 JoinLocationCannotUseItems(EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt.joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        return TRUE;
    if (pokemonInfo->joinedAt.joinedAt == DUNGEON_RESCUE_TEAM_BASE)
        return TRUE;
    return FALSE;
}

bool8 CannotUseItems(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->info;

    if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT
        || JoinLocationCannotUseItems(pokemonInfo)
        || (!pokemonInfo->isTeamLeader && ShouldMonsterRunAway(pokemon))
        || CannotMove(pokemon, FALSE)
        || HasStatusThatPreventsActing(pokemon))
        return TRUE;

    if (IsCharging(pokemon, FALSE))
        return TRUE;

    return FALSE;
}

bool8 HasStatusThatPreventsActing(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->info;

    if ((pokemonInfo->sleep.sleep != STATUS_SLEEPLESS
        && pokemonInfo->sleep.sleep != STATUS_NONE)
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_FROZEN
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
        return TRUE;

    if (pokemonInfo->chargingStatus == STATUS_BIDE)
        return TRUE;

    return FALSE;
}

bool8 CannotAttack(Entity *pokemon, bool8 skipSleep)
{
  EntityInfo *pokemonInfo = pokemon->info;

  if ((skipSleep ||
      pokemonInfo->sleep.sleep == STATUS_SLEEPLESS ||
      pokemonInfo->sleep.sleep == STATUS_YAWNING ||
      pokemonInfo->sleep.sleep == STATUS_NONE) &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_FROZEN &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_WRAP &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_WRAPPED &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_PETRIFIED &&
      pokemonInfo->volatileStatus != STATUS_CRINGE &&
      pokemonInfo->volatileStatus != STATUS_PAUSED &&
      pokemonInfo->volatileStatus != STATUS_INFATUATED &&
      pokemonInfo->nonVolatile.nonVolatileStatus != STATUS_PARALYSIS &&
      !ShouldMonsterRunAway(pokemon))
      return FALSE;

  return TRUE;
}

bool8 CanMoveInDirection(Entity *pokemon, u32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->info->id);
    struct Tile *currentMapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);

    if (currentMapTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL || currentMapTile->monster != NULL)
        return FALSE;

    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->info->transformStatus == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE)) {
            if (direction & 1)
                // Super Mobile can't break walls diagonally.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            else
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
    }

    currentMapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
    if (!(currentMapTile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_1[direction & DIRECTION_MASK]))
        return FALSE;

    return TRUE;
}
