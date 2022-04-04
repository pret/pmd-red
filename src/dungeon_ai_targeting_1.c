#include "global.h"
#include "dungeon_ai_targeting_1.h"

#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/tactic.h"

#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "tile_types.h"

extern void CheckRunAwayVisualFlag(struct DungeonEntity *, bool8 showRunAwayEffect);
extern u8 gDungeonWaterType[];

bool8 IsAtJunction(struct DungeonEntity *param_1)
{
  char cVar2;
  u32 crossableTerrain;
  struct MapTile *mapTile;
  struct DungeonEntityData *iVar7;

  crossableTerrain = GetCrossableTerrain(param_1->entityData->entityID);
  if (!IsFixedDungeon()) {
    if ((param_1->entityData->transformStatus == TRANSFORM_STATUS_MOBILE) || (HasItem(param_1, ITEM_ID_MOBILE_SCARF))) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
    }
    else if (HasIQSkill(param_1, IQ_SKILL_ALL_TERRAIN_HIKER)) {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
    }
    else if (HasIQSkill(param_1, IQ_SKILL_SUPER_MOBILE)) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
    }
  }
  if (crossableTerrain == CROSSABLE_TERRAIN_WALL) {
    iVar7 = param_1->entityData;
    iVar7->mobileTurnTimer += DungeonRandomCapped(100);
    if (iVar7->mobileTurnTimer < 200) {
        return FALSE;
    }
    else
        iVar7->mobileTurnTimer = 0;
  }
  else {
    if ((gDungeonWaterType[gDungeonGlobalData->tileset] == DUNGEON_WATER_TYPE_LAVA) 
       && (crossableTerrain == CROSSABLE_TERRAIN_LIQUID)
       && (HasIQSkill(param_1, IQ_SKILL_LAVA_EVADER))) {
      crossableTerrain = CROSSABLE_TERRAIN_REGULAR;
    }
    mapTile = GetMapTile_1(param_1->posWorld.x, param_1->posWorld.y);
    cVar2 = mapTile->canMoveAdjacent[crossableTerrain];
    if ((cVar2 != 0x54) && (cVar2 != 0x51) && (cVar2 != 0x45) && (cVar2 != 0x15) && (cVar2 != 0x55)) return FALSE;
  }
    return TRUE;
}

bool8 ShouldAvoidFirstHit(struct DungeonEntity *pokemon, bool8 forceAvoid)
{
    if (!HasTactic(pokemon, TACTIC_AVOID_THE_FIRST_HIT))
        return FALSE;
    if (!forceAvoid)
        return FALSE;
    return TRUE;
}

bool8 ShouldAvoidEnemies(struct DungeonEntity *pokemon)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        if (pokemonData->terrifiedTurnsLeft != 0)
        {
            return TRUE;
        }
        if (pokemonData->isLeader)
        {
            return FALSE;
        }
        if (HasAbility(pokemon, ABILITY_RUN_AWAY))
        {
            bool8 runAwayActive = pokemonData->HP < pokemonData->maxHP / 2;
            if (runAwayActive)
            {
                return TRUE;
            }
        }
        if (HasTactic(pokemon, TACTIC_GET_AWAY) ||
            (HasTactic(pokemon, TACTIC_AVOID_TROUBLE) && pokemonData->HP <= pokemonData->maxHP / 2))
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 ShouldAvoidEnemiesAndShowEffect(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
    if (ShouldAvoidEnemies(pokemon))
    {
        CheckRunAwayVisualFlag(pokemon, showRunAwayEffect);
        return TRUE;
    }
    return FALSE;
}
