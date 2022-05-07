#include "global.h"
#include "dungeon_ai_targeting_1.h"

#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/targeting.h"

#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "tile_types.h"


extern u8 gDungeonWaterType[];

extern bool8 SetVisualFlags(struct DungeonEntityData *, u32, bool8);
extern void ShowVisualFlags(struct DungeonEntity *r0);

const u8 gTargetingData[3][2][2][2] = {
    {
        {
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        }
    },
    {
        {
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET},
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET}
        }
    },
    {
        {
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET},
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        }
    }
};


bool8 IsAtJunction(struct DungeonEntity *pokemon)
{
  char cVar2;
  u32 crossableTerrain;
  struct MapTile *mapTile;
  struct DungeonEntityData *iVar7;

  crossableTerrain = GetCrossableTerrain(pokemon->entityData->entityID);
  if (!IsFixedDungeon()) {
    if ((pokemon->entityData->transformStatus == TRANSFORM_STATUS_MOBILE) || (HasItem(pokemon, ITEM_ID_MOBILE_SCARF))) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
    }
    else if (HasIQSkill(pokemon, IQ_SKILL_ALL_TERRAIN_HIKER)) {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
    }
    else if (HasIQSkill(pokemon, IQ_SKILL_SUPER_MOBILE)) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
    }
  }
  if (crossableTerrain == CROSSABLE_TERRAIN_WALL) {
    iVar7 = pokemon->entityData;
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
       && (HasIQSkill(pokemon, IQ_SKILL_LAVA_EVADER))) {
      crossableTerrain = CROSSABLE_TERRAIN_REGULAR;
    }
    mapTile = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y);
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

void CheckRunAwayVisualFlag(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
  bool8 cVar1;
  struct DungeonEntityData *iVar2;
  struct DungeonEntityData *iVar3;
  
  iVar2 = pokemon->entityData;
  iVar3 = iVar2;

  if (((!iVar2->isLeader) && HasAbility(pokemon,ABILITY_RUN_AWAY) &&
      (cVar1 = SetVisualFlags(iVar3,4,iVar2->HP <= iVar2->maxHP / 2), showRunAwayEffect)) &&
     (cVar1)) {
    ShowVisualFlags(pokemon);
  }
}

u8 CanTarget(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct DungeonEntityData *targetData = targetPokemon->entityData;
    u8 targetingDecoy;
    u8 pokemonTargetingDecoy;
    bool8 pokemonIsEnemy;
    bool8 targetIsEnemy;
    bool8 targetIsDecoy;
    if (pokemon == targetPokemon)
    {
        return TARGET_CAPABILITY_CANNOT_ATTACK;
    }
    if (pokemonData->shopkeeperMode == SHOPKEEPER_FRIENDLY ||
        targetData->shopkeeperMode == SHOPKEEPER_FRIENDLY ||
        pokemonData->clientType == CLIENT_TYPE_DONT_MOVE ||
        targetData->clientType == CLIENT_TYPE_DONT_MOVE ||
        pokemonData->clientType == CLIENT_TYPE_CLIENT ||
        targetData->clientType == CLIENT_TYPE_CLIENT ||
        (checkPetrified && !pokemonData->isEnemy && targetData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED) ||
        (!ignoreInvisible && targetData->transformStatus == TRANSFORM_STATUS_INVISIBLE && !CanSeeInvisible(pokemon)))
    {
        return TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET;
    }
    pokemonTargetingDecoy = pokemonData->targetingDecoy;
    targetingDecoy = TARGETING_DECOY_NONE;
    if (pokemonTargetingDecoy != TARGETING_DECOY_NONE)
    {
        targetingDecoy = TARGETING_DECOY_WILD;
        if (pokemonTargetingDecoy == TARGETING_DECOY_TEAM)
        {
            targetingDecoy = TARGETING_DECOY_TEAM;
        }
    }
    if (pokemonData->shopkeeperMode != SHOPKEEPER_NONE)
    {
        pokemonIsEnemy = FALSE;
        if (pokemonData->shopkeeperMode == SHOPKEEPER_AGGRESSIVE_TO_PLAYER)
        {
            pokemonIsEnemy = TRUE;
        }
    }
    else
    {
        pokemonIsEnemy = pokemonData->isEnemy ? TRUE : FALSE;
    }
    if (targetData->shopkeeperMode != SHOPKEEPER_NONE)
    {
        targetIsEnemy = FALSE;
        if (targetData->shopkeeperMode == SHOPKEEPER_AGGRESSIVE_TO_PLAYER)
        {
            targetIsEnemy = TRUE;
        }
    }
    else
    {
        targetIsEnemy = targetData->isEnemy ? TRUE : FALSE;
    }
    targetIsDecoy = FALSE;
    if (targetData->waitingStatus == WAITING_STATUS_DECOY)
    {
        targetIsDecoy = TRUE;
    }
    return gTargetingData[targetingDecoy][pokemonIsEnemy][targetIsEnemy][targetIsDecoy];
}

static inline bool8 JoinLocationCannotUseItems_1(struct DungeonEntityData *pokemonData)
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

u8 sub_807167C(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  bool8 bVar1;
  struct DungeonEntityData * iVar3;
  struct DungeonEntityData * iVar4;

  iVar4 = pokemon->entityData;
  iVar3 = target->entityData;
  if (iVar4->clientType != CLIENT_TYPE_CLIENT) {
    bVar1 = JoinLocationCannotUseItems_1(iVar4);
    if (!bVar1 && (iVar4->shopkeeperMode == SHOPKEEPER_NONE) && (iVar3->clientType != CLIENT_TYPE_CLIENT)) {
      bVar1 = JoinLocationCannotUseItems_1(iVar3);
      if (bVar1 || (iVar3->shopkeeperMode != SHOPKEEPER_NONE)) {
error:
          return TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET;
      }
      else
      {
        if ((iVar4->isEnemy) != (iVar3->isEnemy)) {
          return TARGET_CAPABILITY_CAN_TARGET;
        }
        else {
          return TARGET_CAPABILITY_CANNOT_ATTACK;
        }
      }
    }
  }
  goto error;
}
