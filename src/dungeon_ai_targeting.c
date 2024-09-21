#include "global.h"
#include "dungeon_ai_targeting.h"

#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/targeting.h"

#include "dungeon_engine.h"
#include "structs/str_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "structs/map.h"
#include "tile_types.h"

extern void ShowVisualFlags(Entity *r0);

const u8 gDirectionBitMasks_2[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_3[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_4[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_5[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_6[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_7[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

const u8 gTreatmentData[3][2][2][2] = {
    {
        {
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE}
        },
        {
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE}
        }
    },
    {
        {
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE}
        },
        {
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY},
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY}
        }
    },
    {
        {
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY},
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY}
        },
        {
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE}
        }
    }
};

bool8 sub_8070F3C(Entity * pokemon, Position *pos, s32 direction)
{
  u8 terrain;
  struct Tile *tile;

  terrain = GetCrossableTerrain(pokemon->axObj.info->id);

  tile = GetTile(pos->x + gAdjacentTileOffsets[direction].x, pos->y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }

    tile = GetTile(pos->x, pos->y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_2[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_8070F14(Entity * pokemon, s32 direction)
{
  struct Tile *tile;


  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL)))) {

    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[0] & gDirectionBitMasks_3[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_8070F80(Entity * pokemon, s32 direction)
{
  u8 terrain;
  struct Tile *tile;

  terrain = GetCrossableTerrain(pokemon->axObj.info->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }

    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_4[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_8071058(Entity * pokemon, s32 direction)
{
  u8 terrain;
  struct Tile *tile;

  terrain = GetCrossableTerrain(pokemon->axObj.info->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER)) ||
      (!tile->monster->axObj.info->isNotTeamMember)))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }
    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_5[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 CanAttackInDirection(Entity *pokemon, s32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->axObj.info->id);
    struct Tile *tile;
    if (crossableTerrain < CROSSABLE_TERRAIN_CREVICE)
    {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
    }
    tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) &&
        (tile->monster == NULL || GetEntityType(tile->monster) == ENTITY_MONSTER))
    {
        if (!IsCurrentFixedRoomBossFight())
        {
            if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE ||
                HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
            else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
            {
                // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
                // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
            {
                if ((direction & 1) != 0)
                {
                    crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
                }
                else
                {
                    crossableTerrain = CROSSABLE_TERRAIN_WALL;
                }
            }
        }
        tile = GetTile(pokemon->pos.x, pokemon->pos.y);
        if (tile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_6[direction & DIRECTION_MASK])
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 CanAIMonsterMoveInDirection(Entity *pokemon, s32 direction, bool8 *pokemonInFront)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->axObj.info->id);
    struct Tile *frontTile, *currentTile;
    *pokemonInFront = FALSE;
    frontTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (frontTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
    {
        return FALSE;
    }
    if (frontTile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE &&
        !gDungeon->monsterHouseTriggered &&
        IQSkillIsEnabled(pokemon, IQ_HOUSE_AVOIDER))
    {
        return FALSE;
    }
    if (frontTile->object != NULL &&
        IQSkillIsEnabled(pokemon, IQ_TRAP_AVOIDER) &&
        GetEntityType(frontTile->object) == ENTITY_TRAP &&
        (frontTile->object->isVisible || pokemon->axObj.info->eyesightStatus.eyesightStatus == STATUS_EYEDROPS))
    {
        return FALSE;
    }
    if ((frontTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY &&
        gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA &&
        IQSkillIsEnabled(pokemon, IQ_LAVA_EVADER))
    {
        return FALSE;
    }
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally move through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't move through walls.
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }
    currentTile = GetTile(pokemon->pos.x, pokemon->pos.y);
    if (currentTile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_7[direction & DIRECTION_MASK])
    {
        if (frontTile->monster == NULL)
        {
            return TRUE;
        }
        else
        {
            *pokemonInFront = TRUE;
        }
    }
    return FALSE;
}

bool8 IsAtJunction(Entity *pokemon)
{
    u32 crossableTerrain = GetCrossableTerrain(pokemon->axObj.info->id);
    if (!IsCurrentFixedRoomBossFight())
    {
        if (pokemon->axObj.info->transformStatus.transformStatus == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
    }
    if (crossableTerrain == CROSSABLE_TERRAIN_WALL)
    {
        EntityInfo *pokemonInfo = pokemon->axObj.info;
        pokemonInfo->mobileTurnTimer += DungeonRandInt(100);
        if (pokemonInfo->mobileTurnTimer < 200)
        {
            return FALSE;
        }
        else
        {
            pokemonInfo->mobileTurnTimer = 0;
        }
    }
    else
    {
        struct Tile *mapTile;
        char walkableNeighborFlags;
        if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA
           && crossableTerrain == CROSSABLE_TERRAIN_LIQUID
           && IQSkillIsEnabled(pokemon, IQ_LAVA_EVADER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_REGULAR;
        }
        mapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
        walkableNeighborFlags = mapTile->walkableNeighborFlags[crossableTerrain];
        /*
        Check for configurations of open tiles that are considered junctions; i.e., shaped like a 'T' or '+'.
        X=Wall, O=Open

        0x54  0x51  0x45  0x15  0x55
        XOX   XOX   XXX   XOX   XOX
        OOO   OOX   OOO   XOO   OOO
        XXX   XOX   XOX   XOX   XOX
        */
        if (walkableNeighborFlags != 0x54 && walkableNeighborFlags != 0x51 && walkableNeighborFlags != 0x45 && walkableNeighborFlags != 0x15 && walkableNeighborFlags != 0x55)
        {
            return FALSE;
        }
    }
    return TRUE;
}

bool8 ShouldAvoidFirstHit(Entity *pokemon, bool8 forceAvoid)
{
    if (!HasTactic(pokemon, TACTIC_AVOID_THE_FIRST_HIT))
        return FALSE;
    if (!forceAvoid)
        return FALSE;
    return TRUE;
}

bool8 ShouldMonsterRunAway(Entity *pokemon)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = pokemon->axObj.info;
        if (pokemonInfo->terrifiedTurns != 0)
        {
            return TRUE;
        }
        if (pokemonInfo->isTeamLeader)
        {
            return FALSE;
        }
        if (HasAbility(pokemon, ABILITY_RUN_AWAY))
        {
            bool8 runAwayActive = pokemonInfo->HP < pokemonInfo->maxHPStat / 2;
            if (runAwayActive)
            {
                return TRUE;
            }
        }
        if (HasTactic(pokemon, TACTIC_GET_AWAY) ||
            (HasTactic(pokemon, TACTIC_AVOID_TROUBLE) && pokemonInfo->HP <= pokemonInfo->maxHPStat / 2))
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 ShouldMonsterRunAwayAndShowEffect(Entity *pokemon, bool8 showRunAwayEffect)
{
    if (ShouldMonsterRunAway(pokemon))
    {
        CheckRunAwayVisualFlag(pokemon, showRunAwayEffect);
        return TRUE;
    }
    return FALSE;
}

void CheckRunAwayVisualFlag(Entity *pokemon, bool8 showRunAwayEffect)
{
  bool8 cVar1;
  EntityInfo *iVar2;
  EntityInfo *iVar3;
  iVar2 = pokemon->axObj.info;
  iVar3 = iVar2;

  if (((!iVar2->isTeamLeader) && HasAbility(pokemon,ABILITY_RUN_AWAY) &&
      (cVar1 = SetVisualFlags(iVar3,4,iVar2->HP <= iVar2->maxHPStat / 2), showRunAwayEffect)) &&
     (cVar1)) {
    ShowVisualFlags(pokemon);
  }
}

u8 GetTreatmentBetweenMonsters(Entity *pokemon, Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    EntityInfo *targetData = targetPokemon->axObj.info;
    u8 targetingDecoy;
    u8 pokemonTargetingDecoy;
    bool8 pokemonIsEnemy;
    bool8 targetIsEnemy;
    bool8 targetIsDecoy;
    if (pokemon == targetPokemon)
    {
        return TREATMENT_TREAT_AS_ALLY;
    }
    if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
        targetData->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
        pokemonInfo->clientType == CLIENT_TYPE_DONT_MOVE ||
        targetData->clientType == CLIENT_TYPE_DONT_MOVE ||
        pokemonInfo->clientType == CLIENT_TYPE_CLIENT ||
        targetData->clientType == CLIENT_TYPE_CLIENT ||
        (checkPetrified && !pokemonInfo->isNotTeamMember && targetData->immobilize.immobilizeStatus == STATUS_PETRIFIED) ||
        (!ignoreInvisible && targetData->transformStatus.transformStatus == STATUS_INVISIBLE && !CanSeeInvisibleMonsters(pokemon)))
    {
        return TREATMENT_IGNORE;
    }
    pokemonTargetingDecoy = pokemonInfo->targetingDecoy;
    targetingDecoy = TARGETING_DECOY_NONE;
    if (pokemonTargetingDecoy != TARGETING_DECOY_NONE)
    {
        targetingDecoy = TARGETING_DECOY_WILD;
        if (pokemonTargetingDecoy == TARGETING_DECOY_TEAM)
        {
            targetingDecoy = TARGETING_DECOY_TEAM;
        }
    }
    if (pokemonInfo->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        pokemonIsEnemy = FALSE;
        if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_ATTACK_TEAM)
        {
            pokemonIsEnemy = TRUE;
        }
    }
    else
    {
        pokemonIsEnemy = pokemonInfo->isNotTeamMember ? TRUE : FALSE;
    }
    if (targetData->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        targetIsEnemy = FALSE;
        if (targetData->shopkeeper == SHOPKEEPER_MODE_ATTACK_TEAM)
        {
            targetIsEnemy = TRUE;
        }
    }
    else
    {
        targetIsEnemy = targetData->isNotTeamMember ? TRUE : FALSE;
    }
    targetIsDecoy = FALSE;
    if (targetData->waitingStruct.waitingStatus == STATUS_DECOY)
    {
        targetIsDecoy = TRUE;
    }
    return gTreatmentData[targetingDecoy][pokemonIsEnemy][targetIsEnemy][targetIsDecoy];
}

u8 sub_807167C(Entity * pokemon, Entity * target)
{
  bool8 cannotUseItems;
  EntityInfo * targetEntityInfo;
  EntityInfo * pokemonEntityData;

  pokemonEntityData = pokemon->axObj.info;
  targetEntityInfo = target->axObj.info;
  if (pokemonEntityData->clientType != CLIENT_TYPE_CLIENT) {
    cannotUseItems = IsClientOrTeamBase(pokemonEntityData->joinedAt.joinedAt);
    if (!cannotUseItems && (pokemonEntityData->shopkeeper == SHOPKEEPER_MODE_NORMAL) && (targetEntityInfo->clientType != CLIENT_TYPE_CLIENT)) {
      cannotUseItems = IsClientOrTeamBase(targetEntityInfo->joinedAt.joinedAt);
      if (cannotUseItems || (targetEntityInfo->shopkeeper != SHOPKEEPER_MODE_NORMAL)) {
error:
          return TREATMENT_IGNORE;
      }
      else
      {
        if ((pokemonEntityData->isNotTeamMember) != (targetEntityInfo->isNotTeamMember)) {
          return TREATMENT_TREAT_AS_ENEMY;
        }
        else {
          return TREATMENT_TREAT_AS_ALLY;
        }
      }
    }
  }
  goto error;
}
