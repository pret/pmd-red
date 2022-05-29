#include "global.h"
#include "dungeon_ai_movement_1.h"

#include "constants/targeting.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_ai_targeting_2.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "position_util.h"

#define INFINITY 999999

const s32 gFaceDirectionIncrements[] = {0, 1, -1, 2, -2, 3, -3, 4, 0, -1, 1, -2, 2, -3, 3, 4};

extern bool8 IsAtJunction(struct DungeonEntity *pokemon);

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
        return Wander(pokemon);
    }
}

#ifdef NONMATCHING
bool8 Wander(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 roomIndex = GetEntityRoomIndex(pokemon);
    s32 targetFacingDir;
    if (roomIndex == CORRIDOR_ROOM_INDEX)
    {
        bool8 isAtJunction = FALSE;
        s32 oppositeFacingDir = (pokemonData->action.facingDir + NUM_DIRECTIONS / 2) & DIRECTION_MASK;
        s32 targetFacingDir2;
        s32 i;
        if (IsAtJunction(pokemon))
        {
            pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
            isAtJunction = TRUE;
        }
        for (i = 0; i < NUM_DIRECTIONS; i++)
        {
            bool8 pokemonInFront;
            targetFacingDir = (pokemonData->action.facingDir + gFaceDirectionIncrements[i]) & DIRECTION_MASK;
            if ((!isAtJunction || targetFacingDir != oppositeFacingDir) &&
                CanMoveForward(pokemon, targetFacingDir, &pokemonInFront))
            {
                pokemonData->movementAction = MOVEMENT_ACTION_WANDER_CORRIDOR;
                pokemonData->targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetFacingDir].x;
                pokemonData->targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetFacingDir].y;
                return TRUE;
            }
        }
        targetFacingDir2 = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
        pokemonData->targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetFacingDir2].x;
        pokemonData->targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetFacingDir2].y;
    }
    else
    {
        s32 numRoomExits = gDungeonGlobalData->numRoomExits[roomIndex];
        struct Position *roomExits = gDungeonGlobalData->roomExits[roomIndex];
        if (pokemonData->moveRandomly)
        {
            s32 targetFacingDir = DungeonRandomCapped(NUM_DIRECTIONS);
            pokemonData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
            pokemonData->targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetFacingDir].x;
            pokemonData->targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetFacingDir].y;
        }
        else
        {
            if (pokemonData->movementAction != MOVEMENT_ACTION_EXIT_ROOM)
            {
                s32 i;
                if (numRoomExits == 0)
                {
                    targetFacingDir = DungeonRandomCapped(NUM_DIRECTIONS);
                    pokemonData->movementAction = MOVEMENT_ACTION_FACE_RANDOM_DIRECTION;
                    pokemonData->targetMovePosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[targetFacingDir].x;
                    pokemonData->targetMovePosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[targetFacingDir].y;
                    return TRUE;
                }
                do {
                    for (i = 0; i < 10; i++)
                    {
                        targetFacingDir = DungeonRandomCapped(numRoomExits);
                        if (pokemon->posWorld.x != roomExits[targetFacingDir].x ||
                            pokemon->posWorld.y != roomExits[targetFacingDir].y)
                        {
                            pokemonData->movementAction = MOVEMENT_ACTION_EXIT_ROOM;
                            pokemonData->targetMovePosition.x = roomExits[targetFacingDir].x;
                            pokemonData->targetMovePosition.y = roomExits[targetFacingDir].y;
                            goto a;
                            return TRUE;
                        }
                    }
                } while (0);
                // If the AI randomly picks the exit it's standing on 10 times,
                // it gives up and exits the way it came.
                // This occurs normally for one-exit rooms, but can happen rarely for multi-exit rooms.
            }
            if (GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y)->tileType & TILE_TYPE_ROOM_EXIT)
            {
                s32 i;
                targetFacingDir = DungeonRandomCapped(NUM_DIRECTIONS);
                for (i = 0; i < NUM_DIRECTIONS; i++, targetFacingDir++)
                {
                    bool8 pokemonInFront;
                    s32 forwardX, forwardY;
                    targetFacingDir &= DIRECTION_MASK;
                    forwardX = pokemon->posWorld.x + gAdjacentTileOffsets[targetFacingDir].x;
                    forwardY = pokemon->posWorld.y + gAdjacentTileOffsets[targetFacingDir].y;
                    if (GetMapTile_1(forwardX, forwardY)->roomIndex == CORRIDOR_ROOM_INDEX &&
                        CanMoveForward(pokemon, targetFacingDir, &pokemonInFront))
                    {
                        pokemonData->movementAction = MOVEMENT_ACTION_WANDER_CORRIDOR;
                        pokemonData->targetMovePosition.x = forwardX;
                        pokemonData->targetMovePosition.y = forwardY;
                        a:
                        return TRUE;
                    }
                }
            }
            return TRUE;
        }
    }
    return TRUE;
}
#else
NAKED
bool8 Wander(struct DungeonEntity *pokemon)
{
    asm_unified("push {r4-r7,lr}\n"
"mov r7, r10\n"
"mov r6, r9\n"
"mov r5, r8\n"
"push {r5-r7}\n"
"sub sp, 0x10\n"
"adds r6, r0, 0\n"
"ldr r7, [r6, 0x70]\n"
"bl GetEntityRoomIndex\n"
"lsls r0, 24\n"
"lsrs r3, r0, 24\n"
"cmp r3, 0xFF\n"
"bne _0807B9DC\n"
"movs r0, 0\n"
"str r0, [sp, 0x4]\n"
"adds r4, r7, 0\n"
"adds r4, 0x46\n"
"ldrb r0, [r4]\n"
"adds r0, 0x4\n"
"mov r8, r0\n"
"movs r0, 0x7\n"
"mov r1, r8\n"
"ands r1, r0\n"
"mov r8, r1\n"
"adds r0, r6, 0\n"
"bl IsAtJunction\n"
"lsls r0, 24\n"
"mov r9, r4\n"
"cmp r0, 0\n"
"beq _0807B96C\n"
"movs r0, 0x8\n"
"bl DungeonRandomCapped\n"
"strb r0, [r4]\n"
"movs r2, 0x1\n"
"str r2, [sp, 0x4]\n"
"_0807B96C:\n"
"movs r3, 0\n"
"movs r4, 0x78\n"
"adds r4, r7\n"
"mov r10, r4\n"
"adds r0, r7, 0\n"
"adds r0, 0x88\n"
"str r0, [sp, 0x8]\n"
"adds r7, 0x8A\n"
"ldr r5, _0807B9D4\n"
"_0807B97E:\n"
"mov r1, r9\n"
"ldrb r0, [r1]\n"
"ldr r1, [r5]\n"
"adds r4, r0, r1\n"
"movs r0, 0x7\n"
"ands r4, r0\n"
"ldr r2, [sp, 0x4]\n"
"cmp r2, 0\n"
"beq _0807B994\n"
"cmp r4, r8\n"
"beq _0807B9AA\n"
"_0807B994:\n"
"adds r0, r6, 0\n"
"adds r1, r4, 0\n"
"mov r2, sp\n"
"str r3, [sp, 0xC]\n"
"bl CanMoveForward\n"
"lsls r0, 24\n"
"ldr r3, [sp, 0xC]\n"
"cmp r0, 0\n"
"beq _0807B9AA\n"
"b _0807BB42\n"
"_0807B9AA:\n"
"adds r5, 0x4\n"
"adds r3, 0x1\n"
"cmp r3, 0x7\n"
"ble _0807B97E\n"
"movs r0, 0x8\n"
"bl DungeonRandomCapped\n"
"movs r1, 0x6\n"
"mov r3, r10\n"
"strb r1, [r3]\n"
"ldr r1, _0807B9D8\n"
"lsls r0, 2\n"
"adds r0, r1\n"
"ldrh r1, [r0]\n"
"ldrh r4, [r6, 0x4]\n"
"adds r1, r4\n"
"ldr r2, [sp, 0x8]\n"
"strh r1, [r2]\n"
"ldrh r0, [r0, 0x2]\n"
"b _0807BB5A\n"
".align 2, 0\n"
"_0807B9D4: .4byte gFaceDirectionIncrements\n"
"_0807B9D8: .4byte gAdjacentTileOffsets\n"
"_0807B9DC:\n"
"ldr r0, _0807BA30\n"
"ldr r2, [r0]\n"
"lsls r1, r3, 1\n"
"ldr r4, _0807BA34\n"
"adds r0, r2, r4\n"
"adds r0, r1\n"
"movs r4, 0\n"
"ldrsh r1, [r0, r4]\n"
"mov r8, r1\n"
"lsls r0, r3, 7\n"
"ldr r1, _0807BA38\n"
"adds r0, r1\n"
"adds r2, r0\n"
"mov r9, r2\n"
"movs r2, 0x8A\n"
"lsls r2, 1\n"
"adds r0, r7, r2\n"
"ldr r0, [r0]\n"
"cmp r0, 0\n"
"beq _0807BA40\n"
"movs r0, 0x8\n"
"bl DungeonRandomCapped\n"
"adds r2, r7, 0\n"
"adds r2, 0x78\n"
"movs r1, 0x6\n"
"strb r1, [r2]\n"
"ldr r1, _0807BA3C\n"
"lsls r0, 2\n"
"adds r0, r1\n"
"ldrh r1, [r0]\n"
"ldrh r3, [r6, 0x4]\n"
"adds r1, r3\n"
"adds r2, 0x10\n"
"strh r1, [r2]\n"
"ldrh r0, [r0, 0x2]\n"
"ldrh r6, [r6, 0x6]\n"
"adds r0, r6\n"
"adds r1, r7, 0\n"
"adds r1, 0x8A\n"
"strh r0, [r1]\n"
"b _0807BB60\n"
".align 2, 0\n"
"_0807BA30: .4byte gDungeonGlobalData\n"
"_0807BA34: .4byte 0x00010844\n"
"_0807BA38: .4byte 0x00010884\n"
"_0807BA3C: .4byte gAdjacentTileOffsets\n"
"_0807BA40:\n"
"adds r0, r7, 0\n"
"adds r0, 0x78\n"
"ldrb r1, [r0]\n"
"mov r10, r0\n"
"cmp r1, 0x4\n"
"beq _0807BAA2\n"
"mov r4, r8\n"
"cmp r4, 0\n"
"bne _0807BA84\n"
"movs r0, 0x8\n"
"bl DungeonRandomCapped\n"
"adds r4, r0, 0\n"
"movs r0, 0x6\n"
"mov r1, r10\n"
"strb r0, [r1]\n"
"ldr r0, _0807BA80\n"
"lsls r2, r4, 2\n"
"adds r2, r0\n"
"ldrh r0, [r2]\n"
"ldrh r3, [r6, 0x4]\n"
"adds r0, r3\n"
"adds r1, r7, 0\n"
"adds r1, 0x88\n"
"strh r0, [r1]\n"
"ldrh r0, [r2, 0x2]\n"
"ldrh r6, [r6, 0x6]\n"
"adds r0, r6\n"
"adds r1, 0x2\n"
"strh r0, [r1]\n"
"b _0807BB60\n"
".align 2, 0\n"
"_0807BA80: .4byte gAdjacentTileOffsets\n"
"_0807BA84:\n"
"movs r5, 0\n"
"_0807BA86:\n"
"mov r0, r8\n"
"bl DungeonRandomCapped\n"
"adds r4, r0, 0\n"
"ldr r0, [r6, 0x4]\n"
"lsls r1, r4, 2\n"
"mov r4, r9\n"
"adds r2, r1, r4\n"
"ldr r1, [r2]\n"
"cmp r0, r1\n"
"bne _0807BB18\n"
"adds r5, 0x1\n"
"cmp r5, 0x9\n"
"ble _0807BA86\n"
"_0807BAA2:\n"
"movs r1, 0x4\n"
"ldrsh r0, [r6, r1]\n"
"movs r2, 0x6\n"
"ldrsh r1, [r6, r2]\n"
"bl GetMapTile_1\n"
"ldrh r1, [r0]\n"
"movs r0, 0x8\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0807BB60\n"
"movs r0, 0x8\n"
"bl DungeonRandomCapped\n"
"adds r4, r0, 0\n"
"movs r3, 0\n"
"mov r9, r3\n"
"_0807BAC4:\n"
"movs r0, 0x7\n"
"ands r4, r0\n"
"movs r0, 0x4\n"
"ldrsh r2, [r6, r0]\n"
"ldr r0, _0807BB14\n"
"lsls r1, r4, 2\n"
"adds r1, r0\n"
"movs r3, 0\n"
"ldrsh r0, [r1, r3]\n"
"adds r2, r0\n"
"mov r8, r2\n"
"movs r0, 0x6\n"
"ldrsh r2, [r6, r0]\n"
"movs r3, 0x2\n"
"ldrsh r0, [r1, r3]\n"
"adds r5, r2, r0\n"
"mov r0, r8\n"
"adds r1, r5, 0\n"
"bl GetMapTile_1\n"
"ldrb r0, [r0, 0x9]\n"
"cmp r0, 0xFF\n"
"bne _0807BB04\n"
"adds r0, r6, 0\n"
"adds r1, r4, 0\n"
"mov r2, sp\n"
"adds r2, 0x1\n"
"bl CanMoveForward\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0807BB2E\n"
"_0807BB04:\n"
"movs r0, 0x1\n"
"add r9, r0\n"
"adds r4, 0x1\n"
"mov r1, r9\n"
"cmp r1, 0x7\n"
"ble _0807BAC4\n"
"b _0807BB60\n"
".align 2, 0\n"
"_0807BB14: .4byte gAdjacentTileOffsets\n"
"_0807BB18:\n"
"movs r0, 0x4\n"
"mov r3, r10\n"
"strb r0, [r3]\n"
"ldrh r1, [r2]\n"
"adds r0, r7, 0\n"
"adds r0, 0x88\n"
"strh r1, [r0]\n"
"ldrh r1, [r2, 0x2]\n"
"adds r0, 0x2\n"
"strh r1, [r0]\n"
"b _0807BB60\n"
"_0807BB2E:\n"
"movs r0, 0x3\n"
"mov r4, r10\n"
"strb r0, [r4]\n"
"adds r0, r7, 0\n"
"adds r0, 0x88\n"
"mov r1, r8\n"
"strh r1, [r0]\n"
"adds r0, 0x2\n"
"strh r5, [r0]\n"
"b _0807BB60\n"
"_0807BB42:\n"
"movs r0, 0x3\n"
"mov r2, r10\n"
"strb r0, [r2]\n"
"ldr r0, _0807BB74\n"
"lsls r1, r4, 2\n"
"adds r1, r0\n"
"ldrh r0, [r1]\n"
"ldrh r3, [r6, 0x4]\n"
"adds r0, r3\n"
"ldr r4, [sp, 0x8]\n"
"strh r0, [r4]\n"
"ldrh r0, [r1, 0x2]\n"
"_0807BB5A:\n"
"ldrh r6, [r6, 0x6]\n"
"adds r0, r6\n"
"strh r0, [r7]\n"
"_0807BB60:\n"
"movs r0, 0x1\n"
"add sp, 0x10\n"
"pop {r3-r5}\n"
"mov r8, r3\n"
"mov r9, r4\n"
"mov r10, r5\n"
"pop {r4-r7}\n"
"pop {r1}\n"
"bx r1\n"
".align 2, 0\n"
"_0807BB74: .4byte gAdjacentTileOffsets");
}
#endif
