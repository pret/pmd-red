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
#include "dungeon_capabilities.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_range.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "structs/map.h"
#include "number_util.h"
#include "position_util.h"

#define INFINITY 999
#define INFINITY_2 999999
#define CHECK_VISIBILITY_DISTANCE 5
#define CORRIDOR_VISIBILITY 2

#define TURN_LEFT_45 1
#define TURN_RIGHT_45 2
#define TURN_LEFT_90 3
#define TURN_RIGHT_90 4
#define TURN_LEFT_135 5

struct CanMoveInDirectionInfo
{
    bool8 tryTurn;
    bool8 canMoveInDirection;
    bool8 pokemonInFront;
    s32 direction;
};

const s32 gFaceDirectionIncrements[] = {0, 1, -1, 2, -2, 3, -3, 4, 0, -1, 1, -2, 2, -3, 3, 4};

void MoveIfPossible(Entity *pokemon, bool8 showRunAwayEffect)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    pokemonInfo->aiTarget.aiNotNextToTarget = FALSE;
    pokemonInfo->aiTarget.aiTargetingEnemy = FALSE;
    pokemonInfo->aiTarget.aiTurningAround = FALSE;
    if (HasTactic(pokemon, TACTIC_BE_PATIENT))
    {
        u32 maxHPStat = pokemonInfo->maxHPStat;
        maxHPStat += maxHPStat >> 0x1f;
        if (pokemonInfo->HP <= (s16) (maxHPStat / 2))
        {
            pokemonInfo->action.action = ACTION_NOTHING;
            return;
        }
    }
    if (HasTactic(pokemon, TACTIC_WAIT_THERE))
    {
        pokemonInfo->action.action = ACTION_NOTHING;
    }
    else if (!pokemonInfo->isTeamLeader && FixedPointToInt(pokemonInfo->belly) == 0)
    {
        pokemonInfo->action.action = ACTION_NOTHING;
    }
    else if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT)
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        pokemonInfo->targetPos.x = pokemon->pos.x;
        pokemonInfo->targetPos.y = pokemon->pos.y - 1;
    }
    else
    {
        bool8 hasAction;
        if (ShouldMonsterRunAwayAndShowEffect(pokemon, showRunAwayEffect))
        {
            hasAction = AvoidEnemies(pokemon);
        }
        else if (CanTakeItem(pokemon))
        {
            pokemonInfo->action.action = ACTION_PICK_UP_AI;
            return;
        }
        else
        {
            hasAction = ChooseTargetPosition(pokemon);
        }
        if (!hasAction)
        {
            pokemonInfo->action.action = ACTION_NOTHING;
        }
        else
        {
            DecideMovement(pokemon, showRunAwayEffect);
        }
    }
}

bool8 CanTakeItem(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    struct Tile *mapTile;
    Entity *object;
    if (!EntityExists(pokemon) || CheckVariousConditions(pokemon))
    {
        return FALSE;
    }
    mapTile = GetTileAtEntitySafe(pokemon);
    object = mapTile->object;
    if (object == NULL)
    {
        return FALSE;
    }
    switch (GetEntityType(object))
    {
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_TRAP:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
        case ENTITY_ITEM:
            if (!pokemonInfo->isTeamLeader &&
                !(pokemonInfo->heldItem.flags & ITEM_FLAG_EXISTS) &&
                ((mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) || !pokemonInfo->isNotTeamMember) &&
                !(GetItemData(object)->flags & ITEM_FLAG_IN_SHOP))
            {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

bool8 ChooseTargetPosition(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    if (!TargetLeader(pokemon))
    {
        Entity **possibleTargets;
        s32 maxPossibleTargets;
        s32 targetIndex;
        bool8 canCrossWalls;
        s32 targetDistance;
        s32 i;
        if (gDungeon->decoyActive)
        {
            possibleTargets = gDungeon->allPokemon;
            maxPossibleTargets = DUNGEON_MAX_POKEMON;
        }
        else if (pokemonInfo->isNotTeamMember)
        {
            possibleTargets = gDungeon->teamPokemon;
            maxPossibleTargets = MAX_TEAM_MEMBERS;
        }
        else
        {
            possibleTargets = gDungeon->wildPokemon;
            maxPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
        }
        canCrossWalls = CanCrossWalls(pokemon);
        targetIndex = -1;
        targetDistance = INFINITY;
        for (i = 0; i < maxPossibleTargets; i++)
        {
            Entity *target = possibleTargets[i];
            if (EntityExists(target) && target->axObj.info->clientType == CLIENT_TYPE_NONE)
            {
                if (gDungeon->decoyActive)
                {
                    if (GetTreatmentBetweenMonsters(pokemon, target, FALSE, TRUE) != TREATMENT_TREAT_AS_ENEMY)
                    {
                        continue;
                    }
                }
                else if (!pokemonInfo->isNotTeamMember && target->axObj.info->immobilize.immobilizeStatus == STATUS_PETRIFIED)
                {
                    continue;
                }
                if (target->axObj.info->shopkeeper != SHOPKEEPER_MODE_SHOPKEEPER)
                {
                    s32 currentDistance;
                    if (canCrossWalls)
                    {
                        s32 distance = pokemon->pos.x - target->pos.x;
                        if (distance < 0)
                        {
                            distance = -distance;
                        }
                        if (distance > CHECK_VISIBILITY_DISTANCE)
                        {
                            goto checkCanSeeTarget;
                        }
                        distance = pokemon->pos.y - target->pos.y;
                        if (distance < 0)
                        {
                            distance = -distance;
                        }
                        if (distance > CHECK_VISIBILITY_DISTANCE)
                        {
                            goto checkCanSeeTarget;
                        }
                    }
                    else
                    {
                        checkCanSeeTarget:
                        if (!CanTargetEntity(pokemon, target))
                        {
                            continue;
                        }
                    }
                    currentDistance = GetDistance(&pokemon->pos, &target->pos);
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
            pokemonInfo->aiTarget.aiObjective = AI_CHASE_TARGET;
            pokemonInfo->aiTarget.aiTargetPos = possibleTargets[targetIndex]->pos;
            pokemonInfo->aiTarget.aiTarget = possibleTargets[targetIndex];
            pokemonInfo->aiTarget.aiTargetSpawnGenID = pokemonInfo->aiTarget.aiTarget->spawnGenID;
            pokemonInfo->aiTarget.aiTargetingEnemy = TRUE;
            pokemonInfo->moveRandomly = FALSE;
            if (HasTactic(pokemon, TACTIC_KEEP_YOUR_DISTANCE) && !CanSeeTeammate(pokemon))
            {
                s32 distanceX = pokemon->pos.x - possibleTargets[targetIndex]->pos.x;
                if (distanceX < 0)
                {
                    distanceX = -distanceX;
                }
                if (distanceX < 2)
                {
                    s32 distanceY = pokemon->pos.y - possibleTargets[targetIndex]->pos.y;
                    if (distanceY < 0)
                    {
                        distanceY = -distanceY;
                    }
                    if (distanceY < 2)
                    {
                        pokemonInfo->aiTarget.aiTurningAround = TRUE;
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
            if (!pokemonInfo->isNotTeamMember)
            {
                Entity *leader = GetLeaderIfVisible(pokemon);
                if (EntityExists(leader))
                {
                    pokemonInfo->aiTarget.aiObjective = AI_CHASE_TARGET;
                    pokemonInfo->aiTarget.aiTargetPos = leader->pos;
                    pokemonInfo->aiTarget.aiTarget = leader;
                    pokemonInfo->aiTarget.aiTargetSpawnGenID = leader->spawnGenID;
                    pokemonInfo->moveRandomly = FALSE;
                    return TRUE;
                }
            }
        } while (0);
    }
    else if (pokemonInfo->isTeamLeader)
    {
        // This item targeting code is never reached because the leader is never AI-controlled.
        u8 room;
        s32 minX, minY, maxX, maxY, x, y, maxY2;
        if (gDungeon->unk181e8.visibilityRange) {
            // Dead code.
            u8 a = -a;
        }
        room = GetTile(pokemon->pos.x, pokemon->pos.y)->room;
        if (room == CORRIDOR_ROOM)
        {
            do
            {
                minX = pokemon->pos.x - CORRIDOR_VISIBILITY;
                minY = pokemon->pos.y - CORRIDOR_VISIBILITY;
                maxX = pokemon->pos.x + CORRIDOR_VISIBILITY;
                maxY = pokemon->pos.y + CORRIDOR_VISIBILITY;
            } while (0);
        }
        else
        {
            struct RoomData *mapRoom = &gDungeon->roomData[room];
            minX = mapRoom->bottomRightCornerX - 1;
            minY = mapRoom->bottomRightCornerY - 1;
            maxX = mapRoom->topLeftCornerX + 1;
            maxY = mapRoom->topLeftCornerY + 1;
        }
        maxY2 = maxY;
        for (y = minY; y <= maxY2; y++)
        {
            for (x = minX; x <= maxX; x++)
            {
                Entity *object = GetTileSafe(x, y)->object;
                if (object && GetEntityType(object) == ENTITY_ITEM)
                {
                    pokemonInfo->aiTarget.aiObjective = AI_TAKE_ITEM;
                    pokemonInfo->aiTarget.aiTargetPos.x = x;
                    pokemonInfo->aiTarget.aiTargetPos.y = y;
                    pokemonInfo->aiTarget.aiTarget = NULL;
                    pokemonInfo->aiTarget.aiTargetSpawnGenID = 0;
                    pokemonInfo->moveRandomly = FALSE;
                    return TRUE;
                }
            }
        }
    }
    if ((u8) (pokemonInfo->aiTarget.aiObjective - 1) <= 1)
    {
        if (pokemonInfo->aiTarget.aiTarget)
        {
            if (pokemonInfo->aiTarget.aiTarget->spawnGenID == pokemonInfo->aiTarget.aiTargetSpawnGenID)
            {
                EntityInfo *targetData = pokemonInfo->aiTarget.aiTarget->axObj.info;
                s32 i;
                for (i = 0; i < NUM_PREV_POS; i++)
                {
                    if (CanTargetPosition(pokemon, &targetData->prevPos[i]))
                    {
                        pokemonInfo->aiTarget.aiObjective = AI_CHASE_REMEMBERED_TARGET;
                        pokemonInfo->aiTarget.aiTargetPos = targetData->prevPos[i];
                        pokemonInfo->moveRandomly = FALSE;
                        return TRUE;
                    }
                }
            }
            else
            {
                pokemonInfo->aiTarget.aiObjective = AI_STAND_STILL;
                pokemonInfo->aiTarget.aiTarget = NULL;
                pokemonInfo->aiTarget.aiTargetSpawnGenID = 0;
            }
        }
    }
    Wander(pokemon);
    return TRUE;
}

void DecideMovement(Entity *pokemon, bool8 showRunAwayEffect)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    s32 direction;
    s32 turnLimit;
    s32 i;
    struct CanMoveInDirectionInfo canMoveInDirectionInfo[6];
    bool8 pokemonInFront;
    pokemonInfo->targetPos = pokemonInfo->aiTarget.aiTargetPos;
    if (pokemon->pos.x == pokemonInfo->aiTarget.aiTargetPos.x &&
        pokemon->pos.y == pokemonInfo->aiTarget.aiTargetPos.y)
    {
        SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
        return;
    }
    direction = GetDirectionTowardsPosition(&pokemon->pos, &pokemonInfo->aiTarget.aiTargetPos);
    if (ShouldAvoidFirstHit(pokemon, pokemonInfo->aiTarget.aiTargetingEnemy))
    {
        if (pokemonInfo->aiTarget.aiObjective == AI_CHASE_TARGET &&
            IsTargetTwoTilesAway(&pokemon->pos, &pokemonInfo->aiTarget.aiTargetPos))
        {
            s32 distance = GetDistance(&pokemon->pos, &pokemonInfo->aiTarget.aiTargetPos);
            if (distance == 2)
            {
                SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
                return;
            }
            else if (distance < 2)
            {
                direction += 4;
                direction &= DIRECTION_MASK;
            }
        }
    }
    else if (pokemonInfo->aiTarget.aiTurningAround)
    {
        direction += 4;
        direction &= DIRECTION_MASK;
    }
    if (CanAIMonsterMoveInDirection(pokemon, direction, &pokemonInFront))
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = direction & DIRECTION_MASK;
        return;
    }
    else if (pokemonInFront)
    {
        if (!pokemonInfo->isNotTeamMember && !pokemonInfo->recalculateFollow)
        {
            pokemonInfo->aiTarget.aiNotNextToTarget = TRUE;
            pokemonInfo->aiNextToTarget = TRUE;
            SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
            pokemonInfo->waiting = TRUE;
            return;
        }
        if (pokemon->pos.x + gAdjacentTileOffsets[direction].x == pokemonInfo->aiTarget.aiTargetPos.x &&
            pokemon->pos.y + gAdjacentTileOffsets[direction].y == pokemonInfo->aiTarget.aiTargetPos.y)
        {
            SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
            pokemonInfo->waiting = TRUE;
            return;
        }
        pokemonInfo->aiTarget.aiNotNextToTarget = TRUE;
    }
    canMoveInDirectionInfo[TURN_LEFT_45].tryTurn = canMoveInDirectionInfo[TURN_RIGHT_45].tryTurn = canMoveInDirectionInfo[TURN_LEFT_90].tryTurn = canMoveInDirectionInfo[TURN_RIGHT_90].tryTurn = canMoveInDirectionInfo[TURN_LEFT_135].tryTurn = TRUE;
    if (!pokemonInfo->isNotTeamMember && (direction & 1) != 0)
    {
        s32 targetDistanceX = pokemon->pos.x - pokemonInfo->aiTarget.aiTargetPos.x;
        s32 targetDistanceY;
        if (targetDistanceX < 0)
        {
            targetDistanceX = -targetDistanceX;
        }
        targetDistanceY = pokemon->pos.y - pokemonInfo->aiTarget.aiTargetPos.y;
        if (targetDistanceY < 0)
        {
            targetDistanceY = -targetDistanceY;
        }
        if (targetDistanceX <= 2 && targetDistanceY <= 2 && targetDistanceX != targetDistanceY)
        {
            if ((direction & 2) != 0)
            {
                if (targetDistanceX < targetDistanceY)
                {
                    canMoveInDirectionInfo[TURN_RIGHT_45].tryTurn = FALSE;
                }
                else
                {
                    canMoveInDirectionInfo[TURN_LEFT_45].tryTurn = FALSE;
                }
            }
            else
            {
                if (targetDistanceX < targetDistanceY)
                {
                    canMoveInDirectionInfo[TURN_LEFT_45].tryTurn = FALSE;
                }
                else
                {
                    canMoveInDirectionInfo[TURN_RIGHT_45].tryTurn = FALSE;
                }
            }
        }
    }
    turnLimit = TURN_LEFT_90;
    if (ShouldMonsterRunAwayAndShowEffect(pokemon, showRunAwayEffect) || pokemonInfo->aiTarget.aiTurningAround)
    {
        turnLimit = TURN_LEFT_135;
    }
    for (i = TURN_LEFT_45; i < turnLimit; i++)
    {
        canMoveInDirectionInfo[i].direction = (gFaceDirectionIncrements[i] + direction) & DIRECTION_MASK;
        canMoveInDirectionInfo[i].canMoveInDirection = CanAIMonsterMoveInDirection(pokemon, canMoveInDirectionInfo[i].direction, &canMoveInDirectionInfo[i].pokemonInFront);
        if (!canMoveInDirectionInfo[i].canMoveInDirection && !canMoveInDirectionInfo[i].pokemonInFront)
        {
            canMoveInDirectionInfo[TURN_RIGHT_45].tryTurn = TRUE;
            canMoveInDirectionInfo[TURN_LEFT_45].tryTurn = TRUE;
        }
    }
    for (i = TURN_LEFT_45; i < turnLimit; i++)
    {
        if (canMoveInDirectionInfo[i].canMoveInDirection && canMoveInDirectionInfo[i].tryTurn)
        {
            SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
            pokemonInfo->action.direction = canMoveInDirectionInfo[i].direction & DIRECTION_MASK;
            return;
        }
        if (canMoveInDirectionInfo[i].pokemonInFront)
        {
            pokemonInfo->aiTarget.aiNotNextToTarget = TRUE;
        }
    }
    SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
    pokemonInfo->waiting = TRUE;
    if (pokemonInfo->isTeamLeader)
    {
        pokemonInfo->aiTarget.aiNotNextToTarget = FALSE;
        pokemonInfo->aiNextToTarget = FALSE;
    }
    else if (pokemonInfo->aiTarget.aiNotNextToTarget)
    {
        pokemonInfo->aiNextToTarget = TRUE;
    }
}

bool8 AvoidEnemies(Entity *pokemon)
{
    bool8 pokemonInFront;
    u8 closestTargetRoom;
    s32 closestTargetDistance = INFINITY_2;
    Entity *closestTarget;
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    u8 room = GetEntityRoom(pokemon);
    Entity **possibleTargets;
    s32 numPossibleTargets;
    s32 i;
    if (gDungeon->decoyActive)
    {
        possibleTargets = gDungeon->allPokemon;
        numPossibleTargets = DUNGEON_MAX_POKEMON;
    }
    else if (pokemonInfo->isNotTeamMember)
    {
        possibleTargets = gDungeon->teamPokemon;
        numPossibleTargets = MAX_TEAM_MEMBERS;
    }
    else
    {
        possibleTargets = gDungeon->wildPokemon;
        numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
    }
    closestTarget = NULL;
    closestTargetRoom = CORRIDOR_ROOM;
    for (i = 0; i < numPossibleTargets; i++)
    {
        Entity *target = possibleTargets[i];
        if (EntityExists(target) && CanSeeTarget(pokemon, target))
        {
            s32 distance;
            if (gDungeon->decoyActive && GetTreatmentBetweenMonsters(pokemon, target, FALSE, TRUE) != TREATMENT_TREAT_AS_ENEMY)
            {
                continue;
            }
            distance = GetDistance(&pokemon->pos, &target->pos);
            if (closestTargetDistance > distance)
            {
                closestTargetDistance = distance;
                closestTarget = target;
                closestTargetRoom = GetEntityRoom(target);
                pokemonInfo->aiTarget.aiTargetPos = closestTarget->pos;
                pokemonInfo->targetPos = closestTarget->pos;
            }
        }
    }
    if (closestTargetDistance != INFINITY_2)
    {
        if (room == closestTargetRoom && room != CORRIDOR_ROOM)
        {
            struct Tile *tile = GetTile(pokemon->pos.x, pokemon->pos.y);
            if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
            {
                Position aiTargetPos;
                s32 targetDir;
                aiTargetPos.x = pokemon->pos.x;
                aiTargetPos.y = pokemon->pos.y;
                // Scan for a direction leading outside the room.
                for (targetDir = 0; targetDir < NUM_DIRECTIONS; targetDir++)
                {
                    struct Tile *adjacentTile;
                    aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetDir].x;
                    aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetDir].y;
                    adjacentTile = GetTile(aiTargetPos.x, aiTargetPos.y);
                    if (adjacentTile->room != room && CanAIMonsterMoveInDirection(pokemon, targetDir, &pokemonInFront))
                    {
                        break;
                    }
                }
                if (targetDir == NUM_DIRECTIONS)
                {
                    targetDir = DungeonRandInt(NUM_DIRECTIONS);
                    pokemonInfo->aiTarget.aiObjective = AI_STAND_STILL;
                    pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetDir].x;
                    pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetDir].y;
                    return TRUE;
                }
                else
                {
                    pokemonInfo->aiTarget.aiObjective = AI_RUN_AWAY;
                    pokemonInfo->aiTarget.aiTargetPos = aiTargetPos;
                    return TRUE;
                }
            }
            else
            {
                // At this point, the Pokémon is running directly away from the target.
                // If there are any room exits that the Pokémon can head towards without moving
                // closer to the target, head towards the furthest eligible exit.
                s32 naturalJunctionListCounts;
                Position *naturalJunctionList = gDungeon->naturalJunctionList[room];
                s32 furthestTargetExitIndex;
                s32 furthestTargetToExitDistance;
                s32 distanceX;
                s32 pokemonToTargetDistance;
                s32 i;
                naturalJunctionListCounts = gDungeon->naturalJunctionListCounts[room];
                furthestTargetToExitDistance = -INFINITY_2;
                furthestTargetExitIndex = 0;
                distanceX = closestTarget->pos.x - pokemon->pos.x;
                if (distanceX < 0)
                {
                    distanceX = -distanceX;
                }
                pokemonToTargetDistance = closestTarget->pos.y - pokemon->pos.y;
                if (pokemonToTargetDistance < 0)
                {
                    pokemonToTargetDistance = -pokemonToTargetDistance;
                }
                if (pokemonToTargetDistance < distanceX)
                {
                    pokemonToTargetDistance = distanceX;
                }
                for (i = 0; i < naturalJunctionListCounts; i++)
                {
                    s32 targetToExitDistance;
                    s32 pokemonToExitSignX, pokemonToExitSignY;
                    s32 adjacentToTargetDistanceX, adjacentToTargetDistance;
                    s32 distanceX = closestTarget->pos.x - naturalJunctionList[i].x;
                    if (distanceX < 0)
                    {
                        distanceX = -distanceX;
                    }
                    targetToExitDistance = closestTarget->pos.y - naturalJunctionList[i].y;
                    if (targetToExitDistance < 0)
                    {
                        targetToExitDistance = -targetToExitDistance;
                    }
                    if (targetToExitDistance < distanceX)
                    {
                        targetToExitDistance = distanceX;
                    }
                    pokemonToExitSignX = naturalJunctionList[i].x - pokemon->pos.x;
                    pokemonToExitSignY = naturalJunctionList[i].y - pokemon->pos.y;
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
                    adjacentToTargetDistanceX = closestTarget->pos.x - (pokemon->pos.x + pokemonToExitSignX);
                    if (adjacentToTargetDistanceX < 0)
                    {
                        adjacentToTargetDistanceX = -adjacentToTargetDistanceX;
                    }
                    adjacentToTargetDistance = closestTarget->pos.y - (pokemon->pos.y + pokemonToExitSignY);
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
                    pokemonInfo->aiTarget.aiObjective = AI_RUN_AWAY;
                    pokemonInfo->aiTarget.aiTargetPos.x = naturalJunctionList[furthestTargetExitIndex].x;
                    pokemonInfo->aiTarget.aiTargetPos.y = naturalJunctionList[furthestTargetExitIndex].y;
                    return TRUE;
                }
            }
        }
        pokemonInfo->aiTarget.aiObjective = AI_RUN_AWAY;
        pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x - (closestTarget->pos.x - pokemon->pos.x);
        pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y - (closestTarget->pos.y - pokemon->pos.y);
        return TRUE;
    }
    else
    {
        return Wander(pokemon);
    }
}

bool8 Wander(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    s32 room = GetEntityRoom(pokemon);
    s32 targetFacingDir = 0;
    if (room == CORRIDOR_ROOM)
    {
        bool8 isAtJunction = FALSE;
        s32 oppositeFacingDir = (pokemonInfo->action.direction + NUM_DIRECTIONS / 2) & DIRECTION_MASK;
        s32 targetFacingDir2;
        s32 i;
        if (IsAtJunction(pokemon))
        {
            pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
            isAtJunction = TRUE;
        }
        for (i = 0; i < NUM_DIRECTIONS; i++)
        {
            bool8 pokemonInFront;
            targetFacingDir = (pokemonInfo->action.direction + gFaceDirectionIncrements[i]) & DIRECTION_MASK;
            if ((!isAtJunction || targetFacingDir != oppositeFacingDir) &&
                CanAIMonsterMoveInDirection(pokemon, targetFacingDir, &pokemonInFront))
            {
                // It's possible that the goto is an ugly fakematching, but we'll never know for sure.
                goto DEFAULT;
            }
        }
        targetFacingDir2 = DungeonRandInt(NUM_DIRECTIONS);
        pokemonInfo->aiTarget.aiObjective = AI_STAND_STILL;
        pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetFacingDir2].x;
        pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetFacingDir2].y;
        return TRUE;
    }
    else
    {
        s32 naturalJunctionListCounts = gDungeon->naturalJunctionListCounts[room];
        Position *naturalJunctionList = gDungeon->naturalJunctionList[room];
        if (pokemonInfo->moveRandomly)
        {
            s32 targetFacingDir = DungeonRandInt(NUM_DIRECTIONS);
            pokemonInfo->aiTarget.aiObjective = AI_STAND_STILL;
            pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetFacingDir].x;
            pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetFacingDir].y;
            return TRUE;
        }
        else
        {
            if (pokemonInfo->aiTarget.aiObjective != AI_LEAVE_ROOM)
            {
                s32 i;
                if (naturalJunctionListCounts == 0)
                {
                    targetFacingDir = DungeonRandInt(NUM_DIRECTIONS);
                    pokemonInfo->aiTarget.aiObjective = AI_STAND_STILL;
                    pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetFacingDir].x;
                    pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetFacingDir].y;
                    return TRUE;
                }
                for (i = 0; i < 10; i++)
                {
                    targetFacingDir = DungeonRandInt(naturalJunctionListCounts);
                    if (pokemon->pos.x != naturalJunctionList[targetFacingDir].x ||
                        pokemon->pos.y != naturalJunctionList[targetFacingDir].y)
                    {
                        pokemonInfo->aiTarget.aiObjective = AI_LEAVE_ROOM;
                        pokemonInfo->aiTarget.aiTargetPos.x = naturalJunctionList[targetFacingDir].x;
                        pokemonInfo->aiTarget.aiTargetPos.y = naturalJunctionList[targetFacingDir].y;
                        return TRUE;
                    }
                }
                // If the AI randomly picks the exit it's standing on 10 times,
                // it gives up and exits the way it came.
                // This occurs normally for one-exit rooms, but can happen rarely for multi-exit rooms.
            }
            if (GetTile(pokemon->pos.x, pokemon->pos.y)->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
            {
                s32 i;
                targetFacingDir = DungeonRandInt(NUM_DIRECTIONS);
                for (i = 0; i < NUM_DIRECTIONS; i++, targetFacingDir++)
                {
                    bool8 pokemonInFront;
                    s32 forwardX, forwardY;
                    targetFacingDir &= DIRECTION_MASK;
                    forwardX = pokemon->pos.x + gAdjacentTileOffsets[targetFacingDir].x;
                    forwardY = pokemon->pos.y + gAdjacentTileOffsets[targetFacingDir].y;
                    if (GetTile(forwardX, forwardY)->room == CORRIDOR_ROOM &&
                        CanAIMonsterMoveInDirection(pokemon, targetFacingDir, &pokemonInFront))
                    {
                        pokemonInfo->aiTarget.aiObjective = AI_ROAM;
                        pokemonInfo->aiTarget.aiTargetPos.x = forwardX;
                        pokemonInfo->aiTarget.aiTargetPos.y = forwardY;
                        return TRUE;
                    }
                }
            }
            return TRUE;
        }
    }
DEFAULT:
    pokemonInfo->aiTarget.aiObjective = AI_ROAM;
    pokemonInfo->aiTarget.aiTargetPos.x = pokemon->pos.x + gAdjacentTileOffsets[targetFacingDir].x;
    pokemonInfo->aiTarget.aiTargetPos.y = pokemon->pos.y + gAdjacentTileOffsets[targetFacingDir].y;
    return TRUE;
}

void sub_807BB78(Entity *pokemon)
{
    EntityInfo *entityInfo;

    entityInfo = pokemon->axObj.info;
    entityInfo->aiTarget.aiObjective = 0;
    entityInfo->aiTarget.aiTargetPos = pokemon->pos;
    entityInfo->aiTarget.aiTarget = 0;
    entityInfo->aiTarget.aiTargetSpawnGenID = 0;
}
