#include "global.h"
#include "dungeon_ai_movement.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/tactic.h"
#include "dungeon_action.h"
#include "dungeon_ai_leader.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_movement_1.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "number_util.h"
#include "position_util.h"

#define INFINITY 999
#define INFINITY_2 999999
#define CHECK_VISIBILITY_DISTANCE 5
#define CORRIDOR_VISIBILITY 2

extern bool8 IsTargetTwoTilesAway(struct Position *, struct Position *);

const s32 gFaceDirectionIncrements[] = {0, 1, -1, 2, -2, 3, -3, 4, 0, -1, 1, -2, 2, -3, 3, 4};

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

NAKED
void DecideMovement(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
    asm_unified("push {r4-r7,lr}\n"
"mov r7, r10\n"
"mov r6, r9\n"
"mov r5, r8\n"
"push {r5-r7}\n"
"sub sp, 0x3C\n"
"mov r9, r0\n"
"lsls r1, 24\n"
"lsrs r7, r1, 24\n"
"ldr r5, [r0, 0x70]\n"
"movs r0, 0xB6\n"
"lsls r0, 1\n"
"adds r1, r5, r0\n"
"adds r4, r5, 0\n"
"adds r4, 0x88\n"
"ldr r0, [r4]\n"
"str r0, [r1]\n"
"mov r2, r9\n"
"ldr r1, [r2, 0x4]\n"
"ldr r0, [r4]\n"
"cmp r1, r0\n"
"beq _0807B348\n"
"mov r6, r9\n"
"adds r6, 0x4\n"
"adds r0, r6, 0\n"
"adds r1, r4, 0\n"
"bl CalculateFacingDir\n"
"mov r8, r0\n"
"adds r0, r5, 0\n"
"adds r0, 0x7A\n"
"ldrb r1, [r0]\n"
"mov r0, r9\n"
"bl ShouldAvoidFirstHit\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807B366\n"
"adds r0, r5, 0\n"
"adds r0, 0x78\n"
"ldrb r0, [r0]\n"
"cmp r0, 0x1\n"
"bne _0807B37C\n"
"adds r0, r6, 0\n"
"adds r1, r4, 0\n"
"bl IsTargetTwoTilesAway\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807B37C\n"
"adds r0, r6, 0\n"
"adds r1, r4, 0\n"
"bl GetDistance\n"
"cmp r0, 0x2\n"
"bne _0807B354\n"
"_0807B348:\n"
"adds r0, r5, 0\n"
"adds r0, 0x44\n"
"movs r1, 0x1\n"
"bl SetAction\n"
"b _0807B5CE\n"
"_0807B354:\n"
"cmp r0, 0x1\n"
"bgt _0807B37C\n"
"movs r3, 0x4\n"
"add r8, r3\n"
"movs r0, 0x7\n"
"mov r1, r8\n"
"ands r1, r0\n"
"mov r8, r1\n"
"b _0807B37C\n"
"_0807B366:\n"
"adds r0, r5, 0\n"
"adds r0, 0x7B\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0807B37C\n"
"movs r2, 0x4\n"
"add r8, r2\n"
"movs r0, 0x7\n"
"mov r3, r8\n"
"ands r3, r0\n"
"mov r8, r3\n"
"_0807B37C:\n"
"add r4, sp, 0x30\n"
"mov r0, r9\n"
"mov r1, r8\n"
"adds r2, r4, 0\n"
"bl CanMoveForward\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807B3A8\n"
"adds r0, r5, 0\n"
"adds r0, 0x44\n"
"movs r2, 0x2\n"
"ldrsh r1, [r5, r2]\n"
"bl SetWalkAction\n"
"movs r0, 0x7\n"
"mov r3, r8\n"
"ands r3, r0\n"
"adds r0, r5, 0\n"
"adds r0, 0x46\n"
"strb r3, [r0]\n"
"b _0807B5CE\n"
"_0807B3A8:\n"
"ldrb r0, [r4]\n"
"cmp r0, 0\n"
"beq _0807B444\n"
"ldrb r0, [r5, 0x6]\n"
"cmp r0, 0\n"
"bne _0807B3E8\n"
"ldr r1, _0807B3E0\n"
"adds r0, r5, r1\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"bne _0807B3E8\n"
"adds r0, r5, 0\n"
"adds r0, 0x79\n"
"movs r4, 0x1\n"
"strb r4, [r0]\n"
"movs r2, 0xA2\n"
"lsls r2, 1\n"
"adds r0, r5, r2\n"
"strb r4, [r0]\n"
"adds r0, r5, 0\n"
"adds r0, 0x44\n"
"movs r1, 0x1\n"
"bl SetAction\n"
"ldr r3, _0807B3E4\n"
"adds r0, r5, r3\n"
"strb r4, [r0]\n"
"b _0807B5CE\n"
".align 2, 0\n"
"_0807B3E0: .4byte 0x00000145\n"
"_0807B3E4: .4byte 0x00000147\n"
"_0807B3E8:\n"
"mov r0, r9\n"
"movs r2, 0x4\n"
"ldrsh r1, [r0, r2]\n"
"ldr r2, _0807B434\n"
"mov r3, r8\n"
"lsls r0, r3, 2\n"
"adds r2, r0, r2\n"
"movs r3, 0\n"
"ldrsh r0, [r2, r3]\n"
"adds r1, r0\n"
"adds r0, r5, 0\n"
"adds r0, 0x88\n"
"movs r3, 0\n"
"ldrsh r0, [r0, r3]\n"
"cmp r1, r0\n"
"bne _0807B43C\n"
"mov r1, r9\n"
"movs r3, 0x6\n"
"ldrsh r0, [r1, r3]\n"
"movs r3, 0x2\n"
"ldrsh r1, [r2, r3]\n"
"adds r0, r1\n"
"adds r1, r5, 0\n"
"adds r1, 0x8A\n"
"movs r2, 0\n"
"ldrsh r1, [r1, r2]\n"
"cmp r0, r1\n"
"bne _0807B43C\n"
"adds r0, r5, 0\n"
"adds r0, 0x44\n"
"movs r1, 0x1\n"
"bl SetAction\n"
"ldr r3, _0807B438\n"
"adds r1, r5, r3\n"
"movs r0, 0x1\n"
"strb r0, [r1]\n"
"b _0807B5CE\n"
".align 2, 0\n"
"_0807B434: .4byte gAdjacentTileOffsets\n"
"_0807B438: .4byte 0x00000147\n"
"_0807B43C:\n"
"adds r1, r5, 0\n"
"adds r1, 0x79\n"
"movs r0, 0x1\n"
"strb r0, [r1]\n"
"_0807B444:\n"
"mov r3, sp\n"
"mov r2, sp\n"
"mov r1, sp\n"
"add r0, sp, 0x28\n"
"movs r4, 0x1\n"
"strb r4, [r0]\n"
"add r0, sp, 0x20\n"
"strb r4, [r0]\n"
"strb r4, [r1, 0x18]\n"
"strb r4, [r2, 0x10]\n"
"strb r4, [r3, 0x8]\n"
"ldrb r6, [r5, 0x6]\n"
"cmp r6, 0\n"
"bne _0807B4C8\n"
"mov r0, r8\n"
"ands r0, r4\n"
"cmp r0, 0\n"
"beq _0807B4C8\n"
"mov r1, r9\n"
"movs r2, 0x4\n"
"ldrsh r0, [r1, r2]\n"
"adds r1, r5, 0\n"
"adds r1, 0x88\n"
"movs r3, 0\n"
"ldrsh r1, [r1, r3]\n"
"subs r2, r0, r1\n"
"cmp r2, 0\n"
"bge _0807B47E\n"
"negs r2, r2\n"
"_0807B47E:\n"
"mov r0, r9\n"
"movs r3, 0x6\n"
"ldrsh r1, [r0, r3]\n"
"adds r0, r5, 0\n"
"adds r0, 0x8A\n"
"movs r3, 0\n"
"ldrsh r0, [r0, r3]\n"
"subs r1, r0\n"
"cmp r1, 0\n"
"bge _0807B494\n"
"negs r1, r1\n"
"_0807B494:\n"
"cmp r2, 0x2\n"
"bgt _0807B4C8\n"
"cmp r1, 0x2\n"
"bgt _0807B4C8\n"
"cmp r2, r1\n"
"beq _0807B4C8\n"
"movs r3, 0x2\n"
"mov r0, r8\n"
"ands r3, r0\n"
"cmp r3, 0\n"
"beq _0807B4BA\n"
"cmp r2, r1\n"
"bge _0807B4B4\n"
"mov r0, sp\n"
"strb r6, [r0, 0x10]\n"
"b _0807B4C8\n"
"_0807B4B4:\n"
"mov r0, sp\n"
"strb r6, [r0, 0x8]\n"
"b _0807B4C8\n"
"_0807B4BA:\n"
"cmp r2, r1\n"
"bge _0807B4C4\n"
"mov r0, sp\n"
"strb r3, [r0, 0x8]\n"
"b _0807B4C8\n"
"_0807B4C4:\n"
"mov r0, sp\n"
"strb r3, [r0, 0x10]\n"
"_0807B4C8:\n"
"movs r1, 0x3\n"
"mov r10, r1\n"
"mov r0, r9\n"
"adds r1, r7, 0\n"
"bl ShouldAvoidEnemiesAndShowEffect\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0807B4E4\n"
"adds r0, r5, 0\n"
"adds r0, 0x7B\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0807B4E8\n"
"_0807B4E4:\n"
"movs r2, 0x5\n"
"mov r10, r2\n"
"_0807B4E8:\n"
"movs r6, 0x1\n"
"adds r3, r5, 0\n"
"adds r3, 0x44\n"
"str r3, [sp, 0x34]\n"
"cmp r6, r10\n"
"bge _0807B53C\n"
"mov r3, sp\n"
"mov r4, sp\n"
"adds r4, 0xA\n"
"add r7, sp, 0x8\n"
"_0807B4FC:\n"
"lsls r0, r6, 3\n"
"add r2, sp, 0x4\n"
"adds r2, r0\n"
"ldr r1, _0807B598\n"
"lsls r0, r6, 2\n"
"adds r0, r1\n"
"ldr r1, [r0]\n"
"add r1, r8\n"
"movs r0, 0x7\n"
"ands r1, r0\n"
"str r1, [r2]\n"
"mov r0, r9\n"
"adds r2, r4, 0\n"
"str r3, [sp, 0x38]\n"
"bl CanMoveForward\n"
"strb r0, [r7, 0x1]\n"
"lsls r0, 24\n"
"ldr r3, [sp, 0x38]\n"
"cmp r0, 0\n"
"bne _0807B532\n"
"ldrb r0, [r4]\n"
"cmp r0, 0\n"
"bne _0807B532\n"
"movs r0, 0x1\n"
"strb r0, [r3, 0x10]\n"
"strb r0, [r3, 0x8]\n"
"_0807B532:\n"
"adds r4, 0x8\n"
"adds r7, 0x8\n"
"adds r6, 0x1\n"
"cmp r6, r10\n"
"blt _0807B4FC\n"
"_0807B53C:\n"
"movs r6, 0x1\n"
"cmp r6, r10\n"
"bge _0807B56E\n"
"adds r3, r5, 0\n"
"adds r3, 0x79\n"
"add r1, sp, 0x8\n"
"movs r4, 0x8\n"
"movs r7, 0x1\n"
"_0807B54C:\n"
"adds r2, r4, 0\n"
"ldrb r0, [r1, 0x1]\n"
"cmp r0, 0\n"
"beq _0807B55A\n"
"ldrb r0, [r1]\n"
"cmp r0, 0\n"
"bne _0807B5A0\n"
"_0807B55A:\n"
"ldrb r0, [r1, 0x2]\n"
"cmp r0, 0\n"
"beq _0807B562\n"
"strb r7, [r3]\n"
"_0807B562:\n"
"adds r1, 0x8\n"
"adds r4, r2, 0\n"
"adds r4, 0x8\n"
"adds r6, 0x1\n"
"cmp r6, r10\n"
"blt _0807B54C\n"
"_0807B56E:\n"
"ldr r0, [sp, 0x34]\n"
"movs r1, 0x1\n"
"bl SetAction\n"
"ldr r1, _0807B59C\n"
"adds r0, r5, r1\n"
"movs r1, 0\n"
"movs r2, 0x1\n"
"strb r2, [r0]\n"
"ldrb r0, [r5, 0x7]\n"
"cmp r0, 0\n"
"beq _0807B5BC\n"
"adds r0, r5, 0\n"
"adds r0, 0x79\n"
"strb r1, [r0]\n"
"movs r2, 0xA2\n"
"lsls r2, 1\n"
"adds r0, r5, r2\n"
"strb r1, [r0]\n"
"b _0807B5CE\n"
".align 2, 0\n"
"_0807B598: .4byte gFaceDirectionIncrements\n"
"_0807B59C: .4byte 0x00000147\n"
"_0807B5A0:\n"
"movs r3, 0x2\n"
"ldrsh r1, [r5, r3]\n"
"ldr r0, [sp, 0x34]\n"
"bl SetWalkAction\n"
"add r0, sp, 0x4\n"
"adds r0, r4\n"
"ldr r0, [r0]\n"
"movs r1, 0x7\n"
"ands r0, r1\n"
"adds r1, r5, 0\n"
"adds r1, 0x46\n"
"strb r0, [r1]\n"
"b _0807B5CE\n"
"_0807B5BC:\n"
"adds r0, r5, 0\n"
"adds r0, 0x79\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0807B5CE\n"
"movs r1, 0xA2\n"
"lsls r1, 1\n"
"adds r0, r5, r1\n"
"strb r2, [r0]\n"
"_0807B5CE:\n"
"add sp, 0x3C\n"
"pop {r3-r5}\n"
"mov r8, r3\n"
"mov r9, r4\n"
"mov r10, r5\n"
"pop {r4-r7}\n"
"pop {r0}\n"
"bx r0");
}

bool8 AvoidEnemies(struct DungeonEntity *pokemon)
{
    bool8 pokemonInFront;
    u8 closestTargetRoomIndex;
    s32 closestTargetDistance = INFINITY_2;
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
    if (closestTargetDistance != INFINITY_2)
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
                furthestTargetToExitDistance = -INFINITY_2;
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
                for (i = 0; i < 10; i++)
                {
                    targetFacingDir = DungeonRandomCapped(numRoomExits);
                    if (pokemon->posWorld.x != roomExits[targetFacingDir].x ||
                        pokemon->posWorld.y != roomExits[targetFacingDir].y)
                    {
                        pokemonData->movementAction = MOVEMENT_ACTION_EXIT_ROOM;
                        pokemonData->targetMovePosition.x = roomExits[targetFacingDir].x;
                        pokemonData->targetMovePosition.y = roomExits[targetFacingDir].y;
                        return TRUE;
                    }
                }
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

void sub_807BB78(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *entityData;

    entityData = pokemon->entityData;
    entityData->movementAction = 0;
    entityData->targetMovePosition = pokemon->posWorld;
    entityData->targetPokemon = 0;
    entityData->targetPokemonSpawnIndex = 0;
}
