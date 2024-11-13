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
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if ((checkBlinker && pokemonInfo->blinkerClassStatus.status == STATUS_BLINKER))
        return TRUE;
    if (pokemonInfo->sleepClassStatus.status == STATUS_SLEEP || pokemonInfo->sleepClassStatus.status == STATUS_NAPPING || pokemonInfo->sleepClassStatus.status == STATUS_NIGHTMARE)
        return TRUE;
    if (pokemonInfo->cringeClassStatus.status == STATUS_PAUSED || pokemonInfo->cringeClassStatus.status == STATUS_INFATUATED)
        return TRUE;
    if (pokemonInfo->frozenClassStatus.status == STATUS_PETRIFIED)
        return TRUE;
    if (pokemonInfo->terrifiedTurns != 0)
        return TRUE;

    return FALSE;
}

bool8 sub_8070BC0(Entity* entity)
{
    EntityInfo *entityInfo = GetEntInfo(entity);

    if (IsChargingAnyTwoTurnMove(entity, FALSE)
        || entityInfo->sleepClassStatus.status == STATUS_YAWNING
        || entityInfo->sleepClassStatus.status == STATUS_NIGHTMARE
        || ShouldMonsterRunAway(entity)
        || entityInfo->muzzled.muzzled == TRUE
        || entityInfo->frozenClassStatus.status == STATUS_PETRIFIED
        || entityInfo->frozenClassStatus.status == STATUS_FROZEN)
        return FALSE;

    if (entityInfo->cringeClassStatus.status == STATUS_CONFUSED)
        return FALSE;
    if (entityInfo->sleepClassStatus.status == STATUS_SLEEP)
        return FALSE;
    if (entityInfo->invisibleClassStatus.status == STATUS_INVISIBLE
        || entityInfo->sleepClassStatus.status == STATUS_NAPPING)
        return FALSE;
    if (entityInfo->cringeClassStatus.status == STATUS_CRINGE)
        return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP)
        return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAPPED
        || entityInfo->blinkerClassStatus.status == STATUS_CROSS_EYED)
        return FALSE;
    if (entityInfo->curseClassStatus.status == STATUS_DECOY)
        return FALSE;
    if (entityInfo->blinkerClassStatus.status == STATUS_BLINKER)
        return FALSE;
    if (entityInfo->cringeClassStatus.status != STATUS_INFATUATED
        && entityInfo->cringeClassStatus.status != STATUS_PAUSED)
        return TRUE;

    return FALSE;
}

bool8 CheckVariousConditions(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if (pokemonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET
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
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if ((pokemonInfo->sleepClassStatus.status != STATUS_SLEEPLESS && pokemonInfo->sleepClassStatus.status != STATUS_NONE))
        return TRUE;
    if (pokemonInfo->frozenClassStatus.status == STATUS_FROZEN || pokemonInfo->frozenClassStatus.status == STATUS_PETRIFIED)
        return TRUE;
    if (pokemonInfo->bideClassStatus.status == STATUS_BIDE)
        return TRUE;

    return FALSE;
}

bool8 CannotAttack(Entity *pokemon, bool8 skipSleep)
{
  EntityInfo *pokemonInfo = GetEntInfo(pokemon);

  if ((skipSleep ||
      pokemonInfo->sleepClassStatus.status == STATUS_SLEEPLESS ||
      pokemonInfo->sleepClassStatus.status == STATUS_YAWNING ||
      pokemonInfo->sleepClassStatus.status == STATUS_NONE) &&
      pokemonInfo->frozenClassStatus.status != STATUS_FROZEN &&
      pokemonInfo->frozenClassStatus.status != STATUS_WRAP &&
      pokemonInfo->frozenClassStatus.status != STATUS_WRAPPED &&
      pokemonInfo->frozenClassStatus.status != STATUS_PETRIFIED &&
      pokemonInfo->cringeClassStatus.status != STATUS_CRINGE &&
      pokemonInfo->cringeClassStatus.status != STATUS_PAUSED &&
      pokemonInfo->cringeClassStatus.status != STATUS_INFATUATED &&
      pokemonInfo->burnClassStatus.status != STATUS_PARALYSIS &&
      !ShouldMonsterRunAway(pokemon))
      return FALSE;

  return TRUE;
}

bool8 CanMoveInDirection(Entity *pokemon, u32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *currentMapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);

    if (currentMapTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL || currentMapTile->monster != NULL)
        return FALSE;

    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
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
