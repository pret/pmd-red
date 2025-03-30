#include "global.h"
#include "dungeon_ai_targeting.h"
#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/targeting.h"
#include "run_dungeon.h"
#include "structs/str_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "structs/map.h"
#include "dungeon_move_util.h"

extern void ShowVisualFlags(Entity *r0);

const u8 gDirectionBitMasks_1[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
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
        || IsExperienceLocked(pokemonInfo->joinedAt.id)
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

bool8 sub_8070F3C(Entity * pokemon, DungeonPos *pos, s32 direction)
{
  u8 terrain;
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pos->x + gAdjacentTileOffsets[direction].x, pos->y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
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
  const Tile *tile;


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
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
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

UNUSED static bool8 sub_8071058(Entity * pokemon, s32 direction)
{
  u8 terrain;
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER)) ||
      (!GetEntInfo(tile->monster)->isNotTeamMember)))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
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
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *tile;
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
            if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
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
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *currentTile;
    const Tile *frontTile;
    *pokemonInFront = FALSE;
    frontTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (frontTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
    {
        return FALSE;
    }
    if (frontTile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE &&
        !gDungeon->unk644.monsterHouseTriggered &&
        IQSkillIsEnabled(pokemon, IQ_HOUSE_AVOIDER))
    {
        return FALSE;
    }
    if (frontTile->object != NULL &&
        IQSkillIsEnabled(pokemon, IQ_TRAP_AVOIDER) &&
        GetEntityType(frontTile->object) == ENTITY_TRAP &&
        (frontTile->object->isVisible || GetEntInfo(pokemon)->blinkerClassStatus.status == STATUS_EYEDROPS))
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
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
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
    u32 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
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
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
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
        const Tile *mapTile;
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
    if (!IsTacticSet(pokemon, TACTIC_AVOID_THE_FIRST_HIT))
        return FALSE;
    if (!forceAvoid)
        return FALSE;
    return TRUE;
}

bool8 ShouldMonsterRunAway(Entity *pokemon)
{
    if (!EntityIsValid(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        if (pokemonInfo->terrifiedTurns != 0)
        {
            return TRUE;
        }
        if (pokemonInfo->isTeamLeader)
        {
            return FALSE;
        }
        if (AbilityIsActive(pokemon, ABILITY_RUN_AWAY))
        {
            bool8 runAwayActive = pokemonInfo->HP < pokemonInfo->maxHPStat / 2;
            if (runAwayActive)
            {
                return TRUE;
            }
        }
        if (IsTacticSet(pokemon, TACTIC_GET_AWAY) ||
            (IsTacticSet(pokemon, TACTIC_AVOID_TROUBLE) && pokemonInfo->HP <= pokemonInfo->maxHPStat / 2))
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
  iVar2 = GetEntInfo(pokemon);

  if (((!iVar2->isTeamLeader) && AbilityIsActive(pokemon,ABILITY_RUN_AWAY) &&
      (cVar1 = SetVisualFlags(iVar2,4,iVar2->HP <= iVar2->maxHPStat / 2), showRunAwayEffect)) &&
     (cVar1)) {
    ShowVisualFlags(pokemon);
  }
}

u8 GetTreatmentBetweenMonsters(Entity *pokemon, Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    EntityInfo *targetData = GetEntInfo(targetPokemon);
    u8 decoyAITracker;
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
        pokemonInfo->monsterBehavior == BEHAVIOR_DIGLETT ||
        targetData->monsterBehavior == BEHAVIOR_DIGLETT ||
        pokemonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET ||
        targetData->monsterBehavior == BEHAVIOR_RESCUE_TARGET ||
        (checkPetrified && !pokemonInfo->isNotTeamMember && targetData->frozenClassStatus.status == STATUS_PETRIFIED) ||
        (!ignoreInvisible && targetData->invisibleClassStatus.status == STATUS_INVISIBLE && !CanSeeInvisibleMonsters(pokemon)))
    {
        return TREATMENT_IGNORE;
    }
    pokemonTargetingDecoy = pokemonInfo->decoyAITracker;
    decoyAITracker = DECOY_AI_NONE;
    if (pokemonTargetingDecoy != DECOY_AI_NONE)
    {
        decoyAITracker = DECOY_AI_WILD;
        if (pokemonTargetingDecoy == DECOY_AI_TEAM)
        {
            decoyAITracker = DECOY_AI_TEAM;
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
    if (targetData->curseClassStatus.status == STATUS_DECOY)
    {
        targetIsDecoy = TRUE;
    }
    return gTreatmentData[decoyAITracker][pokemonIsEnemy][targetIsEnemy][targetIsDecoy];
}

u8 sub_807167C(Entity * pokemon, Entity * target)
{
  bool8 cannotUseItems;
  EntityInfo * targetEntityInfo;
  EntityInfo * pokemonEntityData;

  pokemonEntityData = GetEntInfo(pokemon);
  targetEntityInfo = GetEntInfo(target);
  if (pokemonEntityData->monsterBehavior != BEHAVIOR_RESCUE_TARGET) {
    cannotUseItems = IsExperienceLocked(pokemonEntityData->joinedAt.id);
    if (!cannotUseItems && (pokemonEntityData->shopkeeper == SHOPKEEPER_MODE_NORMAL) && (targetEntityInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET)) {
      cannotUseItems = IsExperienceLocked(targetEntityInfo->joinedAt.id);
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
