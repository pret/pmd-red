#include "global.h"
#include "dungeon_ai_movement_1.h"

#include "constants/targeting.h"
#include "dungeon_ai_targeting_2.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "position_util.h"

#define INFINITY 999999

extern bool8 CanMoveForward(struct DungeonEntity *pokemon, s32 facingDir, bool8 *pokemonInFront);
extern bool8 Explore(struct DungeonEntity *pokemon);

bool8 AvoidEnemies(struct DungeonEntity *pokemon)
{
    bool8 pokemonInFront;
    u8 closestTargetRoomIndex;
    s32 closestTargetDistance = INFINITY;
    struct DungeonEntity *closestTarget;
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    u8 roomIndex = GetEntityRoomIndex(pokemon);
    struct DungeonEntity **possibleTargets;
    s32 numPossibleTargets;
    s32 i;
    if (gDungeonGlobalData->decoyActive)
    {
        possibleTargets = gDungeonGlobalData->allPokemon;
        numPossibleTargets = DUNGEON_MAX_POKEMON;
    }
    else if (pokemonData->isEnemy)
    {
        possibleTargets = gDungeonGlobalData->teamPokemon;
        numPossibleTargets = MAX_TEAM_MEMBERS;
    }
    else
    {
        possibleTargets = gDungeonGlobalData->wildPokemon;
        numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
    }
    closestTarget = NULL;
    closestTargetRoomIndex = CORRIDOR_ROOM_INDEX;
    for (i = 0; i < numPossibleTargets; i++)
    {
        struct DungeonEntity *target = possibleTargets[i];
        if (EntityExists(target) && CanSee(pokemon, target))
        {
            s32 distance;
            if (gDungeonGlobalData->decoyActive && CanTarget(pokemon, target, FALSE, TRUE) != TARGET_CAPABILITY_CAN_TARGET)
            {
                continue;
            }
            distance = GetDistance(&pokemon->posWorld, &target->posWorld);
            if (closestTargetDistance > distance)
            {
                closestTargetDistance = distance;
                closestTarget = target;
                closestTargetRoomIndex = GetEntityRoomIndex(target);
                pokemonData->targetMovePosition = closestTarget->posWorld;
                pokemonData->targetPosition = closestTarget->posWorld;
            }
        }
    }
    if (closestTargetDistance != INFINITY)
    {
        if (roomIndex == closestTargetRoomIndex && roomIndex != CORRIDOR_ROOM_INDEX)
        {
            struct MapTile *tile = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y);
            if (tile->tileType & TILE_TYPE_ROOM_EXIT)
            {
                struct Position targetMovePosition;
                s32 targetDir;
                targetMovePosition.x = pokemon->posWorld.x;
                targetMovePosition.y = pokemon->posWorld.y;
                // Scan for a direction leading outside the room.
                for (targetDir = 0; targetDir < NUM_DIRECTIONS; targetDir++)
                {
                    struct MapTile *adjacentTile;
                    targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetDir].x;
                    targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetDir].y;
                    adjacentTile = GetMapTile_1(targetMovePosition.x, targetMovePosition.y);
                    if (adjacentTile->roomIndex != roomIndex && CanMoveForward(pokemon, targetDir, &pokemonInFront))
                    {
                        break;
                    }
                }
                if (targetDir == NUM_DIRECTIONS)
                {
                    targetDir = DungeonRandomCapped(NUM_DIRECTIONS);
                    pokemonData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
                    pokemonData->targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetDir].x;
                    pokemonData->targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetDir].y;
                    return TRUE;
                }
                else
                {
                    pokemonData->movementAction = MOVEMENT_ACTION_RUN_AWAY_FROM_ENEMY;
                    pokemonData->targetMovePosition = targetMovePosition;
                    return TRUE;
                }
            }
            else
            {
                // At this point, the Pokémon is running directly away from the target.
                // If there are any room exits that the Pokémon can head towards without moving
                // closer to the target, head towards the furthest eligible exit.
                s32 numRoomExits;
                struct Position *roomExits = gDungeonGlobalData->roomExits[roomIndex];
                s32 furthestTargetExitIndex;
                s32 furthestTargetToExitDistance;
                s32 distanceX;
                s32 pokemonToTargetDistance;
                s32 i;
                numRoomExits = gDungeonGlobalData->numRoomExits[roomIndex];
                furthestTargetToExitDistance = -INFINITY;
                furthestTargetExitIndex = 0;
                distanceX = closestTarget->posWorld.x - pokemon->posWorld.x;
                if (distanceX < 0)
                {
                    distanceX = -distanceX;
                }
                pokemonToTargetDistance = closestTarget->posWorld.y - pokemon->posWorld.y;
                if (pokemonToTargetDistance < 0)
                {
                    pokemonToTargetDistance = -pokemonToTargetDistance;
                }
                if (pokemonToTargetDistance < distanceX)
                {
                    pokemonToTargetDistance = distanceX;
                }
                for (i = 0; i < numRoomExits; i++)
                {
                    s32 targetToExitDistance;
                    s32 pokemonToExitSignX, pokemonToExitSignY;
                    s32 adjacentToTargetDistanceX, adjacentToTargetDistance;
                    s32 distanceX = closestTarget->posWorld.x - roomExits[i].x;
                    if (distanceX < 0)
                    {
                        distanceX = -distanceX;
                    }
                    targetToExitDistance = closestTarget->posWorld.y - roomExits[i].y;
                    if (targetToExitDistance < 0)
                    {
                        targetToExitDistance = -targetToExitDistance;
                    }
                    if (targetToExitDistance < distanceX)
                    {
                        targetToExitDistance = distanceX;
                    }
                    pokemonToExitSignX = roomExits[i].x - pokemon->posWorld.x;
                    pokemonToExitSignY = roomExits[i].y - pokemon->posWorld.y;
                    if (pokemonToExitSignX < -1)
                    {
                        pokemonToExitSignX = -1;
                    }
                    if (pokemonToExitSignY < -1)
                    {
                        pokemonToExitSignY = -1;
                    }
                    if (pokemonToExitSignX > 1)
                    {
                        pokemonToExitSignX = 1;
                    }
                    if (pokemonToExitSignY > 1)
                    {
                        pokemonToExitSignY = 1;
                    }
                    adjacentToTargetDistanceX = closestTarget->posWorld.x - (pokemon->posWorld.x + pokemonToExitSignX);
                    if (adjacentToTargetDistanceX < 0)
                    {
                        adjacentToTargetDistanceX = -adjacentToTargetDistanceX;
                    }
                    adjacentToTargetDistance = closestTarget->posWorld.y - (pokemon->posWorld.y + pokemonToExitSignY);
                    if (adjacentToTargetDistance < 0)
                    {
                        adjacentToTargetDistance = -adjacentToTargetDistance;
                    }
                    if (adjacentToTargetDistance < adjacentToTargetDistanceX)
                    {
                        adjacentToTargetDistance = adjacentToTargetDistanceX;
                    }
                    // BUG: The Pokémon is allowed to move towards the exit and remain the same
                    // distance away from the target.
                    // This leads to odd behavior like turning around when near an exit.
                    // Using a > instead of a >= would avoid this issue.
                    // For an example of this behavior, see https://youtu.be/plke4eU_PU8?t=435.
                    if (adjacentToTargetDistance >= pokemonToTargetDistance &&
                        furthestTargetToExitDistance < targetToExitDistance)
                    {
                        furthestTargetExitIndex = i;
                        furthestTargetToExitDistance = targetToExitDistance;
                    }
                }
                if (furthestTargetToExitDistance >= 0)
                {
                    pokemonData->movementAction = MOVEMENT_ACTION_RUN_AWAY_FROM_ENEMY;
                    pokemonData->targetMovePosition.x = roomExits[furthestTargetExitIndex].x;
                    pokemonData->targetMovePosition.y = roomExits[furthestTargetExitIndex].y;
                    return TRUE;
                }
            }
        }
        pokemonData->movementAction = MOVEMENT_ACTION_RUN_AWAY_FROM_ENEMY;
        pokemonData->targetMovePosition.x = pokemon->posWorld.x - (closestTarget->posWorld.x - pokemon->posWorld.x);
        pokemonData->targetMovePosition.y = pokemon->posWorld.y - (closestTarget->posWorld.y - pokemon->posWorld.y);
        return TRUE;
    }
    else
    {
        return Explore(pokemon);
    }
}
