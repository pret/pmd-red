#include "global.h"
#include "dungeon_ai_movement.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/tactic.h"
#include "dungeon_action.h"
#include "dungeon_ai_leader.h"
#include "dungeon_ai_movement_1.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "number_util.h"
#include "position_util.h"

#define INFINITY 999
#define CHECK_VISIBILITY_DISTANCE 5
#define CORRIDOR_VISIBILITY 2

extern void DecideMovement(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);
extern bool8 CanCrossWalls(struct DungeonEntity *pokemon);
extern struct DungeonEntity *GetLeaderEntityIfVisible(struct DungeonEntity *pokemon);

void MoveIfPossible(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    pokemonData->notAdjacentToTarget = FALSE;
    pokemonData->hasTarget = FALSE;
    pokemonData->turnAround = FALSE;
    if (HasTactic(pokemon, TACTIC_BE_PATIENT))
    {
        u32 maxHP = pokemonData->maxHP;
        maxHP += maxHP >> 0x1f;
        if (pokemonData->HP <= (s16) (maxHP / 2))
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
            return;
        }
    }
    if (HasTactic(pokemon, TACTIC_WAIT_THERE))
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (!pokemonData->isLeader && RoundUpFixedPoint(pokemonData->belly) == 0)
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->targetPosition.x = pokemon->posWorld.x;
        pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
    }
    else
    {
        bool8 hasAction;
        if (ShouldAvoidEnemiesAndShowEffect(pokemon, showRunAwayEffect))
        {
            hasAction = AvoidEnemies(pokemon);
        }
        else if (CanTakeItem(pokemon))
        {
            pokemonData->action.action = DUNGEON_ACTION_TAKE_ITEM_AI;
            return;
        }
        else
        {
            hasAction = ChooseTargetPosition(pokemon);
        }
        if (!hasAction)
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
        }
        else
        {
            DecideMovement(pokemon, showRunAwayEffect);
        }
    }
}

bool8 CanTakeItem(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct MapTile *mapTile;
    struct DungeonEntity *mapObject;
    if (!EntityExists(pokemon) || CannotUseItems(pokemon))
    {
        return FALSE;
    }
    mapTile = GetMapTileForDungeonEntity_2(pokemon);
    mapObject = mapTile->mapObject;
    if (mapObject == NULL)
    {
        return FALSE;
    }
    switch (GetEntityType(mapObject))
    {
        case ENTITY_NONE:
        case ENTITY_POKEMON:
        case ENTITY_TRAP:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
        case ENTITY_ITEM:
            if (!pokemonData->isLeader &&
                !(pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS) &&
                ((mapTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) || !pokemonData->isEnemy) &&
                !(GetItemData(mapObject)->itemFlags & ITEM_FLAG_FOR_SALE))
            {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

bool8 ChooseTargetPosition(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (!TargetLeader(pokemon))
    {
        struct DungeonEntity **possibleTargets;
        s32 maxPossibleTargets;
        s32 targetIndex;
        bool8 canCrossWalls;
        s32 targetDistance;
        s32 i;
        if (gDungeonGlobalData->decoyActive)
        {
            possibleTargets = gDungeonGlobalData->allPokemon;
            maxPossibleTargets = DUNGEON_MAX_POKEMON;
        }
        else if (pokemonData->isEnemy)
        {
            possibleTargets = gDungeonGlobalData->teamPokemon;
            maxPossibleTargets = MAX_TEAM_MEMBERS;
        }
        else
        {
            possibleTargets = gDungeonGlobalData->wildPokemon;
            maxPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
        }
        canCrossWalls = CanCrossWalls(pokemon);
        targetIndex = -1;
        targetDistance = INFINITY;
        for (i = 0; i < maxPossibleTargets; i++)
        {
            struct DungeonEntity *target = possibleTargets[i];
            if (EntityExists(target) && target->entityData->clientType == CLIENT_TYPE_NONE)
            {
                if (gDungeonGlobalData->decoyActive)
                {
                    if (CanTarget(pokemon, target, FALSE, TRUE) != TARGET_CAPABILITY_CAN_TARGET)
                    {
                        continue;
                    }
                }
                else if (!pokemonData->isEnemy && target->entityData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
                {
                    continue;
                }
                if (target->entityData->shopkeeperMode != SHOPKEEPER_FRIENDLY)
                {
                    s32 currentDistance;
                    if (canCrossWalls)
                    {
                        s32 distance = pokemon->posWorld.x - target->posWorld.x;
                        if (distance < 0)
                        {
                            distance = -distance;
                        }
                        if (distance > CHECK_VISIBILITY_DISTANCE)
                        {
                            goto checkCanSee;
                        }
                        distance = pokemon->posWorld.y - target->posWorld.y;
                        if (distance < 0)
                        {
                            distance = -distance;
                        }
                        if (distance > CHECK_VISIBILITY_DISTANCE)
                        {
                            goto checkCanSee;
                        }
                    }
                    else
                    {
                        checkCanSee:
                        if (!CanSee_2(pokemon, target))
                        {
                            continue;
                        }
                    }
                    currentDistance = GetDistance(&pokemon->posWorld, &target->posWorld);
                    if (targetDistance > currentDistance)
                    {
                        targetDistance = currentDistance;
                        targetIndex = i;
                        if (targetDistance < 2)
                        {
                            break;
                        }
                    }
                }
            }
        }
        if (targetIndex > -1)
        {
            pokemonData->movementAction = MOVEMENT_ACTION_FOLLOW;
            pokemonData->targetMovePosition = possibleTargets[targetIndex]->posWorld;
            pokemonData->targetPokemon = possibleTargets[targetIndex];
            pokemonData->targetPokemonSpawnIndex = pokemonData->targetPokemon->spawnIndex;
            pokemonData->hasTarget = TRUE;
            pokemonData->moveRandomly = FALSE;
            if (HasTactic(pokemon, TACTIC_KEEP_YOUR_DISTANCE) && !CanSeeTeammate(pokemon))
            {
                s32 distanceX = pokemon->posWorld.x - possibleTargets[targetIndex]->posWorld.x;
                if (distanceX < 0)
                {
                    distanceX = -distanceX;
                }
                if (distanceX < 2)
                {
                    s32 distanceY = pokemon->posWorld.y - possibleTargets[targetIndex]->posWorld.y;
                    if (distanceY < 0)
                    {
                        distanceY = -distanceY;
                    }
                    if (distanceY < 2)
                    {
                        pokemonData->turnAround = TRUE;
                    }
                }
            }
            return TRUE;
        }
    }
    if (!HasTactic(pokemon, TACTIC_GO_THE_OTHER_WAY))
    {
        do
        {
            if (!pokemonData->isEnemy)
            {
                struct DungeonEntity *leader = GetLeaderEntityIfVisible(pokemon);
                if (EntityExists(leader))
                {
                    pokemonData->movementAction = MOVEMENT_ACTION_FOLLOW;
                    pokemonData->targetMovePosition = leader->posWorld;
                    pokemonData->targetPokemon = leader;
                    pokemonData->targetPokemonSpawnIndex = leader->spawnIndex;
                    pokemonData->moveRandomly = FALSE;
                    return TRUE;
                }
            }
        } while (0);
    }
    else if (pokemonData->isLeader)
    {
        // This item targeting code is never reached because the leader is never AI-controlled.
        u8 roomIndex;
        s32 minX, minY, maxX, maxY, x, y, maxY2;
        if (gDungeonGlobalData->visibility) {
            // Dead code.
            u8 a = -a;
        }
        roomIndex = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y)->roomIndex;
        if (roomIndex == CORRIDOR_ROOM_INDEX)
        {
            do
            {
                minX = pokemon->posWorld.x - CORRIDOR_VISIBILITY;
                minY = pokemon->posWorld.y - CORRIDOR_VISIBILITY;
                maxX = pokemon->posWorld.x + CORRIDOR_VISIBILITY;
                maxY = pokemon->posWorld.y + CORRIDOR_VISIBILITY;
            } while (0);
        }
        else
        {
            struct MapRoom *room = &gDungeonGlobalData->roomData[roomIndex];
            minX = room->startX - 1;
            minY = room->startY - 1;
            maxX = room->endX + 1;
            maxY = room->endY + 1;
        }
        maxY2 = maxY;
        for (y = minY; y <= maxY2; y++)
        {
            for (x = minX; x <= maxX; x++)
            {
                struct DungeonEntity *mapObject = GetMapTile_2(x, y)->mapObject;
                if (mapObject && GetEntityType(mapObject) == ENTITY_ITEM)
                {
                    pokemonData->movementAction = MOVEMENT_ACTION_TAKE_ITEM;
                    pokemonData->targetMovePosition.x = x;
                    pokemonData->targetMovePosition.y = y;
                    pokemonData->targetPokemon = NULL;
                    pokemonData->targetPokemonSpawnIndex = 0;
                    pokemonData->moveRandomly = FALSE;
                    return TRUE;
                }
            }
        }
    }
    if ((u8) (pokemonData->movementAction - 1) <= 1)
    {
        if (pokemonData->targetPokemon)
        {
            if (pokemonData->targetPokemon->spawnIndex == pokemonData->targetPokemonSpawnIndex)
            {
                struct DungeonEntityData *targetData = pokemonData->targetPokemon->entityData;
                s32 i;
                for (i = 0; i < NUM_PREVIOUS_POSITIONS; i++)
                {
                    if (InSameRoom(pokemon, &targetData->previousPositions[i]))
                    {
                        pokemonData->movementAction = MOVEMENT_ACTION_WANDER;
                        pokemonData->targetMovePosition = targetData->previousPositions[i];
                        pokemonData->moveRandomly = FALSE;
                        return TRUE;
                    }
                }
            }
            else
            {
                pokemonData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
                pokemonData->targetPokemon = NULL;
                pokemonData->targetPokemonSpawnIndex = 0;
            }
        }
    }
    Wander(pokemon);
    return TRUE;
}
