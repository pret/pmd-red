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

// TODO CheckVariousStatuses, CheckVariousStatuses2, CheckVariousConditions all check for different conditions that interfere with a Pokémon's ability to act,
// but I'm not sure what the reason is for each function checking the conditions that they do.
// These functions could use better names if someone figures out a clear pattern/reasoning.
bool8 CheckVariousStatuses2(Entity *pokemon, bool8 checkBlinker)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;

    if ((checkBlinker && pokemonInfo->eyesightStatus.eyesightStatus == STATUS_BLINKER)
        || pokemonInfo->sleep.sleep == STATUS_SLEEP
        || pokemonInfo->sleep.sleep == STATUS_NAPPING
        || pokemonInfo->sleep.sleep == STATUS_NIGHTMARE
        || pokemonInfo->volatileStatus.volatileStatus == STATUS_PAUSED
        || pokemonInfo->volatileStatus.volatileStatus == STATUS_INFATUATED
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
        return TRUE;

    if (pokemonInfo->terrifiedTurns != 0)
        return TRUE;

    return FALSE;
}

bool8 sub_8070BC0(Entity* entity)
{
    EntityInfo *entityInfo = entity->axObj.info;

    if (IsChargingAnyTwoTurnMove(entity, FALSE)
        || entityInfo->sleep.sleep == STATUS_YAWNING
        || entityInfo->sleep.sleep == STATUS_NIGHTMARE
        || ShouldMonsterRunAway(entity)
        || entityInfo->muzzled.muzzled == TRUE
        || entityInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED
        || entityInfo->immobilize.immobilizeStatus == STATUS_FROZEN)
        return FALSE;

    if (entityInfo->volatileStatus.volatileStatus == STATUS_CONFUSED)
        return FALSE;
    if (entityInfo->sleep.sleep == STATUS_SLEEP)
        return FALSE;
    if (entityInfo->transformStatus.transformStatus == STATUS_INVISIBLE
        || entityInfo->sleep.sleep == STATUS_NAPPING)
        return FALSE;
    if (entityInfo->volatileStatus.volatileStatus == STATUS_CRINGE)
        return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAP)
        return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAPPED
        || entityInfo->eyesightStatus.eyesightStatus == STATUS_CROSS_EYED)
        return FALSE;
    if (entityInfo->waitingStruct.waitingStatus == STATUS_DECOY)
        return FALSE;
    if (entityInfo->eyesightStatus.eyesightStatus == STATUS_BLINKER)
        return FALSE;
    if (entityInfo->volatileStatus.volatileStatus != STATUS_INFATUATED
        && entityInfo->volatileStatus.volatileStatus != STATUS_PAUSED)
        return TRUE;

    return FALSE;
}

bool8 CheckVariousConditions(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;

    if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT
        || IsClientOrTeamBase(pokemonInfo->joinedAt.joinedAt)
        || (!pokemonInfo->isTeamLeader && ShouldMonsterRunAway(pokemon))
        || CheckVariousStatuses2(pokemon, FALSE)
        || CheckVariousStatuses(pokemon))
        return TRUE;

    if (IsChargingAnyTwoTurnMove(pokemon, FALSE))
        return TRUE;

    return FALSE;
}

bool8 CheckVariousStatuses(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;

    if ((pokemonInfo->sleep.sleep != STATUS_SLEEPLESS
        && pokemonInfo->sleep.sleep != STATUS_NONE)
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_FROZEN
        || pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
        return TRUE;

    if (pokemonInfo->charging.chargingStatus == STATUS_BIDE)
        return TRUE;

    return FALSE;
}

bool8 CannotAttack(Entity *pokemon, bool8 skipSleep)
{
  EntityInfo *pokemonInfo = pokemon->axObj.info;

  if ((skipSleep ||
      pokemonInfo->sleep.sleep == STATUS_SLEEPLESS ||
      pokemonInfo->sleep.sleep == STATUS_YAWNING ||
      pokemonInfo->sleep.sleep == STATUS_NONE) &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_FROZEN &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_WRAP &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_WRAPPED &&
      pokemonInfo->immobilize.immobilizeStatus != STATUS_PETRIFIED &&
      pokemonInfo->volatileStatus.volatileStatus != STATUS_CRINGE &&
      pokemonInfo->volatileStatus.volatileStatus != STATUS_PAUSED &&
      pokemonInfo->volatileStatus.volatileStatus != STATUS_INFATUATED &&
      pokemonInfo->nonVolatile.nonVolatileStatus != STATUS_PARALYSIS &&
      !ShouldMonsterRunAway(pokemon))
      return FALSE;

  return TRUE;
}

bool8 CanMoveInDirection(Entity *pokemon, u32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->axObj.info->id);
    struct Tile *currentMapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);

    if (currentMapTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL || currentMapTile->monster != NULL)
        return FALSE;

    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
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
