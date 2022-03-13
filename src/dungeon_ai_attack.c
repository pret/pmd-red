#include "global.h"
#include "dungeon_ai_attack.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "charge_move.h"
#include "dungeon_action.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_ai_targeting_1.h"
#include "dungeon_ai_targeting_2.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_random_1.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "move_util.h"
#include "moves.h"
#include "position_util.h"
#include "status_checker.h"
#include "status_checks.h"
#include "status_checks_1.h"
#include "targeting.h"
#include "targeting_flags.h"
#include "type_effectiveness.h"

#define REGULAR_ATTACK_INDEX 4

const s16 gRegularAttackWeights[] = {100, 20, 30, 40, 50};

extern bool8 gCanAttackInDirection[NUM_DIRECTIONS];
extern s32 gNumPotentialTargets;
extern s32 gPotentialAttackTargetWeights[NUM_DIRECTIONS];
extern u8 gPotentialAttackTargetDirections[NUM_DIRECTIONS];
extern struct DungeonEntity *gPotentialTargets[NUM_DIRECTIONS];

void DecideAttack(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 i;
    s32 chargeStatus = CHARGING_STATUS_CHARGE;
    struct MoveTargetResults moveTargetResults[MAX_MON_MOVES + 1];
    bool8 willNotUnlinkMove[MAX_MON_MOVES];
    s32 randomWeight;
    bool8 hasPPChecker;
    s32 numUsableMoves;
    s32 total;
    s32 weightCounter;
    bool8 hasWeakTypePicker;
    s32 regularAttackTargetDir;
    bool8 canTargetRegularAttack;
    s32 maxWeight;
    if (CannotAttack(pokemon, FALSE) ||
        ShouldAvoidEnemiesAndShowEffect(pokemon, TRUE) ||
        HasTactic(pokemon, TACTIC_KEEP_YOUR_DISTANCE) ||
        (pokemonData->volatileStatus == VOLATILE_STATUS_CONFUSED && RollPercentChance(gConfusedAttackChance)))
    {
        return;
    }
    if (pokemonData->chargingStatus != CHARGING_STATUS_NONE)
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (pokemonData->moves[i].moveFlags & MOVE_FLAG_EXISTS &&
                MoveMatchesChargingStatus(pokemon, &pokemonData->moves[i]) &&
                pokemonData->chargingStatusMoveIndex == i)
            {
                s32 chosenMoveIndex;
                SetAction(&pokemonData->action, DUNGEON_ACTION_USE_MOVE_AI);
                chosenMoveIndex = i;
                if (i > 0 && pokemonData->moves[i].moveFlags & MOVE_FLAG_LINKED)
                {
                    while (--chosenMoveIndex > 0)
                    {
                        if (!(pokemonData->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_LINKED))
                        {
                            break;
                        }
                    }
                }
                pokemonData->action.actionUseIndex = chosenMoveIndex;
                TargetTileInFront(pokemon);
                return;
            }
        }
    }
    total = 0;
    numUsableMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct PokemonMove *move = &pokemonData->moves[i];
        if (pokemonData->moves[i].moveFlags & MOVE_FLAG_EXISTS)
        {
            if (pokemonData->moves[i].moveFlags & MOVE_FLAG_ENABLED)
            {
                numUsableMoves++;
            }
            total += move->PP;
        }
    }
    if (total == 0)
    {
        struct PokemonMove struggle;
        InitPokemonMove(&struggle, MOVE_STRUGGLE);
        FindMoveTarget(&moveTargetResults[0], pokemon, &struggle);
        if (moveTargetResults[0].moveUsable)
        {
            SetAction(&pokemonData->action, DUNGEON_ACTION_STRUGGLE);
            pokemonData->action.facingDir = moveTargetResults[0].targetDir & DIRECTION_MASK;
            TargetTileInFront(pokemon);
        }
        return;
    }
    hasWeakTypePicker = HasIQSkill(pokemon, IQ_SKILL_WEAK_TYPE_PICKER);
    hasPPChecker = HasIQSkill(pokemon, IQ_SKILL_PP_CHECKER) != FALSE;
    total = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        willNotUnlinkMove[i] = TRUE;
    }
    if (hasPPChecker)
    {
        s32 minPP = 99;
        s32 linkedMoveStartIndex = 0;
        // Linked moves unlink if any move in the chain runs out of PP.
        // With PP Checker, the AI avoids this by not using linked moves if any move in the chain has 1 PP left.
        // This requires a separate check from the 0-PP check used for unlinked moves.
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            struct PokemonMove *move = &pokemonData->moves[i];
            if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            {
                break;
            }
            if (i != 0 && !(move->moveFlags & MOVE_FLAG_LINKED))
            {
                if (linkedMoveStartIndex + 1 < i && minPP <= 1 && linkedMoveStartIndex + 1 <= i)
                {
                    s32 j;
                    for (j = linkedMoveStartIndex; j < i; j++)
                    {
                        willNotUnlinkMove[j] = FALSE;
                    }
                }
                minPP = move->PP;
                linkedMoveStartIndex = i;
            }
            else
            {
                s32 newMinPP = move->PP;
                if (newMinPP > minPP)
                {
                    newMinPP = minPP;
                }
                minPP = newMinPP;
            }
        }
        if (linkedMoveStartIndex + 1 < i && minPP <= 1 && linkedMoveStartIndex + 1 <= i)
        {
            s32 j;
            for (j = linkedMoveStartIndex; j < i; j++)
            {
                willNotUnlinkMove[j] = FALSE;
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct PokemonMove *move;
        moveTargetResults[i].moveUsable = FALSE;
        move = &pokemonData->moves[i];
        if (move->moveFlags & MOVE_FLAG_EXISTS &&
            willNotUnlinkMove[i] &&
            IsMoveIndexUsable(pokemon, i, hasPPChecker) &&
            move->moveFlags & MOVE_FLAG_ENABLED)
        {
            moveTargetResults[i].moveUsable = TRUE;
            if (pokemonData->chargingStatus == chargeStatus)
            {
                if (move->moveID == MOVE_CHARGE)
                {
                    moveTargetResults[i].moveWeight = 0;
                    continue;
                }
                else if (GetMoveTypeForPokemon(pokemon, move) == TYPE_ELECTRIC)
                {
                    moveTargetResults[i].moveWeight = GetMoveWeight(move);
                }
                else
                {
                    moveTargetResults[i].moveWeight = 1;
                }
            }
            else if (hasWeakTypePicker)
            {
                struct MoveTargetResults *results = &moveTargetResults[i];
                results->moveWeight = FindMoveTarget(results, pokemon, move);
            }
            else
            {
                moveTargetResults[i].moveWeight = GetMoveWeight(move);
            }
            total += moveTargetResults[i].moveWeight;
        }
    }
    moveTargetResults[REGULAR_ATTACK_INDEX].moveWeight = 0;
    if (!HasIQSkill(pokemon, IQ_SKILL_EXCLUSIVE_MOVE_USER) && pokemonData->chargingStatus != chargeStatus)
    {
        moveTargetResults[REGULAR_ATTACK_INDEX].moveUsable = TRUE;
        if (pokemonData->chargingStatus == chargeStatus)
        {
            // Never reached? Charge already skips the regular attack in the outer block.
            moveTargetResults[REGULAR_ATTACK_INDEX].moveWeight = 1;
        }
        else if (hasWeakTypePicker)
        {
            moveTargetResults[REGULAR_ATTACK_INDEX].moveWeight = 2;
        }
        else
        {
            moveTargetResults[REGULAR_ATTACK_INDEX].moveWeight = gRegularAttackWeights[numUsableMoves];
        }
        total += moveTargetResults[REGULAR_ATTACK_INDEX].moveWeight;
    }
    if (hasWeakTypePicker)
    {
        s32 i;
        maxWeight = 0;
        total = 0;
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (!moveTargetResults[i].moveUsable)
            {
                moveTargetResults[i].moveWeight = 0;
            }
            else if (maxWeight < moveTargetResults[i].moveWeight)
            {
                maxWeight = moveTargetResults[i].moveWeight;
            }
        }
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (moveTargetResults[i].moveUsable)
            {
                if (maxWeight != moveTargetResults[i].moveWeight)
                {
                    // Only the move(s) with the highest weight can be used, instead of a weighted random.
                    // This has the side effect of making the AI use a STAB ranged move consistently when at a distance.
                    moveTargetResults[i].moveWeight = 0;
                }
                total += moveTargetResults[i].moveWeight;
            }
        }
    }
    if (total == 0)
    {
        return;
    }
    randomWeight = DungeonRandomCapped(total);
    weightCounter = 0;
    if (!HasIQSkill(pokemon, IQ_SKILL_EXCLUSIVE_MOVE_USER))
    {
        canTargetRegularAttack = TargetRegularAttack(pokemon, &regularAttackTargetDir, TRUE);
    }
    else
    {
        canTargetRegularAttack = FALSE;
        regularAttackTargetDir = DIRECTION_SOUTH;
    }
    for (i = 0; i <= REGULAR_ATTACK_INDEX; i++)
    {
        if (moveTargetResults[i].moveUsable && moveTargetResults[i].moveWeight != 0)
        {
            weightCounter += moveTargetResults[i].moveWeight;
            if (weightCounter >= randomWeight)
            {
                if (i == REGULAR_ATTACK_INDEX)
                {
                    if (canTargetRegularAttack)
                    {
                        SetAction(&pokemonData->action, DUNGEON_ACTION_REGULAR_ATTACK);
                        pokemonData->action.facingDir = regularAttackTargetDir & DIRECTION_MASK;
                        TargetTileInFront(pokemon);
                    }
                }
                else
                {
                    FindMoveTarget(&moveTargetResults[i], pokemon, &pokemonData->moves[i]);
                    if (moveTargetResults[i].moveUsable)
                    {
                        s32 chosenMoveIndex;
                        SetAction(&pokemonData->action, DUNGEON_ACTION_USE_MOVE_AI);
                        chosenMoveIndex = i;
                        if (i > 0 && pokemonData->moves[i].moveFlags & MOVE_FLAG_LINKED)
                        {
                            while (--chosenMoveIndex > 0)
                            {
                                if (!(pokemonData->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_LINKED))
                                {
                                    break;
                                }
                            }
                        }
                        pokemonData->action.facingDir = moveTargetResults[i].targetDir & DIRECTION_MASK;
                        pokemonData->action.actionUseIndex = chosenMoveIndex;
                        TargetTileInFront(pokemon);
                    }
                    else
                    {
                        break;
                    }
                }
                return;
            }
        }
    }
    if (canTargetRegularAttack)
    {
        SetAction(&pokemonData->action, DUNGEON_ACTION_REGULAR_ATTACK);
        pokemonData->action.facingDir = regularAttackTargetDir & DIRECTION_MASK;
        TargetTileInFront(pokemon);
    }
}

s32 FindMoveTarget(struct MoveTargetResults *moveTargetResults, struct DungeonEntity *pokemon, struct PokemonMove *move)
{
    s32 targetingFlags;
    s32 moveWeight = 1;
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 numPotentialTargets = 0;
    s32 i;
    bool8 hasStatusChecker;
    s32 rangeTargetingFlags;
    s32 rangeTargetingFlags2;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gCanAttackInDirection[i] = FALSE;
    }
    targetingFlags = GetMoveTargetingFlagsForPokemon(pokemon, move, TRUE);
    hasStatusChecker = HasIQSkill(pokemon, IQ_SKILL_STATUS_CHECKER);
    moveTargetResults->moveUsable = FALSE;
    if ((pokemonData->volatileStatus == VOLATILE_STATUS_TAUNTED && !MoveDealsDirectDamage(move)) ||
        (hasStatusChecker && !CanUseOnSelfWithStatusChecker(pokemon, move)))
    {
        return 1;
    }
    rangeTargetingFlags = targetingFlags & 0xF0;
    if (rangeTargetingFlags == TARGETING_FLAG_TARGET_OTHER ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_FRONTAL_CONE ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_AROUND)
    {
        if (pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER)
        {
            u8 facingDir = pokemonData->action.facingDir;
            i = facingDir; // Fixes a regswap.
            if (!gCanAttackInDirection[i])
            {
                gCanAttackInDirection[i] = TRUE;
                gPotentialAttackTargetDirections[numPotentialTargets] = i;
                gPotentialAttackTargetWeights[numPotentialTargets] = 99;
                gPotentialTargets[numPotentialTargets] = NULL;
                numPotentialTargets++;
            }
        }
        else
        {
            for (i = 0; i < NUM_DIRECTIONS; i++)
            {
                // Double assignment to fix a regswap.
                s16 rangeTargetingFlags = rangeTargetingFlags2 = targetingFlags & 0xF0;
                struct MapTile *adjacentTile = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[i].x,
                    pokemon->posWorld.y + gAdjacentTileOffsets[i].y);
                struct DungeonEntity *adjacentPokemon = adjacentTile->pokemon;
                if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) == ENTITY_POKEMON)
                {
                    if (rangeTargetingFlags != TARGETING_FLAG_TARGET_FRONTAL_CONE &&
                        rangeTargetingFlags != TARGETING_FLAG_TARGET_AROUND)
                    {
                        if (!CanAttackInFront(pokemon, i))
                        {
                            continue;
                        }
                    }
                    numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, adjacentPokemon, move, hasStatusChecker);
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_ROOM)
    {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct DungeonEntity *target = gDungeonGlobalData->allPokemon[i];
            if (EntityExists(target) && CanSee(pokemon, target))
            {
                numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_2_TILES_AHEAD)
    {
        for (i = 0; i < NUM_DIRECTIONS; i++)
        {
            struct MapTile *targetTile = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[i].x,
                pokemon->posWorld.y + gAdjacentTileOffsets[i].y);
            if (CanAttackInFront(pokemon, i))
            {
                struct DungeonEntity *targetPokemon = targetTile->pokemon;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_POKEMON)
                {
                    s32 prevNumPotentialTargets = numPotentialTargets;
                    numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
                    if (prevNumPotentialTargets != numPotentialTargets)
                    {
                        continue;
                    }
                }
                targetTile = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[i].x * 2,
                    pokemon->posWorld.y + gAdjacentTileOffsets[i].y * 2);
                targetPokemon = targetTile->pokemon;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_POKEMON)
                {
                    numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_LINE || rangeTargetingFlags == TARGETING_FLAG_CUT_CORNERS)
    {
        s32 maxRange = 1;
        s32 i;
        if (rangeTargetingFlags == TARGETING_FLAG_TARGET_LINE)
        {
            maxRange = 10;
        }
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct DungeonEntity *target = gDungeonGlobalData->allPokemon[i];
            if (EntityExists(target) && pokemon != target)
            {
                s32 facingDir = CalculateFacingDir(&pokemon->posWorld, &target->posWorld);
                if (!gCanAttackInDirection[facingDir] &&
                    CanSee(pokemon, target) &&
                    IsTargetInLineRange(pokemon, target, maxRange) &&
                    CanUseStatusMove(targetingFlags, pokemon, target, move, hasStatusChecker) &&
                    IsTargetStraightAhead(pokemon, target, facingDir, maxRange))
                {
                    gCanAttackInDirection[facingDir] = TRUE;
                    gPotentialAttackTargetDirections[numPotentialTargets] = facingDir;
                    gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, targetingFlags, target, GetMoveTypeForPokemon(pokemon, move));
                    gPotentialTargets[numPotentialTargets] = target;
                    numPotentialTargets++;
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_FLOOR)
    {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct DungeonEntity *target = gDungeonGlobalData->allPokemon[i];
            if (EntityExists(target))
            {
                numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_SELF)
    {
        numPotentialTargets = WeightMoveIfUsable(numPotentialTargets, targetingFlags, pokemon, pokemon, move, hasStatusChecker);
    }
    if (numPotentialTargets == 0)
    {
        moveTargetResults->moveUsable = FALSE;
    }
    else
    {
        s32 totalWeight = 0;
        s32 maxWeight = 0;
        s32 weightCounter;
        s32 i;
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight < gPotentialAttackTargetWeights[i])
            {
                maxWeight = gPotentialAttackTargetWeights[i];
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight != gPotentialAttackTargetWeights[i])
            {
                gPotentialAttackTargetWeights[i] = 0;
            }
        }
        moveWeight = maxWeight;
        for (i = 0; i < numPotentialTargets; i++)
        {
            totalWeight += gPotentialAttackTargetWeights[i];
        }
        weightCounter = DungeonRandomCapped(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= gPotentialAttackTargetWeights[i];
            if (weightCounter < 0)
            {
                break;
            }
        }
        moveTargetResults->moveUsable = TRUE;
        moveTargetResults->targetDir = gPotentialAttackTargetDirections[i];
        moveTargetResults->moveWeight = 8;
    }
    return moveWeight;
}

bool8 IsTargetInLineRange(struct DungeonEntity *user, struct DungeonEntity *target, s32 range)
{
    s32 distanceX = user->posWorld.x - target->posWorld.x;
    s32 distanceY, distance;
    s32 direction;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    distanceY = user->posWorld.y - target->posWorld.y;
    if (distanceY < 0)
    {
        distanceY = -distanceY;
    }
    distance = distanceY;
    if (distanceY < distanceX)
    {
        distance = distanceX;
    }
    if (distance > RANGED_ATTACK_RANGE || distance > range)
    {
        return FALSE;
    }
    direction = -1;
    if (distanceX == distanceY)
    {
        if (user->posWorld.x < target->posWorld.x &&
            (user->posWorld.y < target->posWorld.y || user->posWorld.y > target->posWorld.y))
        {
            returnTrue:
            return TRUE;
        }
        if (user->posWorld.x > target->posWorld.x); // Fixes register loading order.
        direction = DIRECTION_SOUTHWEST;
        if (user->posWorld.x <= target->posWorld.x || user->posWorld.y <= target->posWorld.y)
        {
            goto checkDirectionSet;
        }
        goto returnTrue;
    }
    else if (user->posWorld.x == target->posWorld.x && user->posWorld.y < target->posWorld.y)
    {
        return TRUE;
    }
    else if (user->posWorld.x < target->posWorld.x && user->posWorld.y == target->posWorld.y)
    {
        return TRUE;
    }
    else if (user->posWorld.x == target->posWorld.x && user->posWorld.y > target->posWorld.y)
    {
        return TRUE;
    }
    else if (user->posWorld.x > target->posWorld.x && user->posWorld.y == target->posWorld.y)
    {
        direction = DIRECTION_WEST;
    }
    checkDirectionSet:
    if (direction < 0)
    {
        return FALSE;
    }
    return TRUE;
}

s32 WeightMoveIfUsable(s32 numPotentialTargets, s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool32 hasStatusChecker)
{
    s32 facingDir;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    struct DungeonEntityData *userData = user->entityData;
    if ((user->posWorld.x == target->posWorld.x && user->posWorld.y == target->posWorld.y) ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_ROOM ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_FLOOR ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_SELF)
    {
        facingDir = userData->action.facingDir;
    }
    else
    {
        facingDir = CalculateFacingDir(&user->posWorld, &target->posWorld);
    }
    if (!gCanAttackInDirection[facingDir] &&
        CanUseStatusMove(targetingFlags2, user, target, move, hasStatusChecker2))
    {
        gCanAttackInDirection[facingDir] = TRUE;
        do { gPotentialAttackTargetDirections[numPotentialTargets] = facingDir; } while (0);
        gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(user, targetingFlags2, target, GetMoveTypeForPokemon(user, move));
        gPotentialTargets[numPotentialTargets] = target;
        numPotentialTargets++;
    }
    return numPotentialTargets;
}

bool8 CanUseStatusMove(s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool32 hasStatusChecker)
{
    struct DungeonEntityData *targetData;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    bool8 hasTarget = FALSE;
    u32 categoryTargetingFlags = targetingFlags2 & 0xF;
    u32 *categoryTargetingFlags2 = &categoryTargetingFlags; // Fixes a regswap.
    if (*categoryTargetingFlags2 == TARGETING_FLAG_TARGET_OTHER)
    {
        if (CanTarget(user, target, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
        {
            hasTarget = TRUE;
        }
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_HEAL_TEAM)
    {
        goto checkCanTarget;
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_LONG_RANGE)
    {
        targetData = target->entityData;
        goto checkThirdParty;
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_ATTACK_ALL)
    {
        targetData = target->entityData;
        if (user == target)
        {
            goto returnFalse;
        }
        checkThirdParty:
        hasTarget = TRUE;
        if (targetData->shopkeeperMode == SHOPKEEPER_FRIENDLY ||
            targetData->clientType == CLIENT_TYPE_DONT_MOVE ||
            targetData->clientType == CLIENT_TYPE_CLIENT)
        {
            returnFalse:
            return FALSE;
        }
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_BOOST_TEAM)
    {
        if (user == target)
        {
            goto returnFalse;
        }
        checkCanTarget:
        if (CanTarget(user, target, FALSE, TRUE) == TARGET_CAPABILITY_CANNOT_ATTACK)
        {
            hasTarget = TRUE;
        }
    }
    else if ((u16) (categoryTargetingFlags - 3) <= 1) // categoryTargetingFlags == TARGETING_FLAG_ITEM
    {
        hasTarget = TRUE;
    }

    if (hasTarget)
    {
        if (hasStatusChecker2)
        {
            if (!CanUseOnTargetWithStatusChecker(user, target, move))
            {
                goto returnFalse;
            }
            if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_SET_TRAP)
            {
                goto rollMoveUseChance;
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_HP)
            {
                if (!HasQuarterHPOrLess(target))
                {
                    if (*categoryTargetingFlags2);
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_STATUS)
            {
                if (!HasNegativeStatus(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_DREAM_EATER)
            {
                if (!IsSleeping(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_EXPOSE)
            {
                targetData = target->entityData;
                if ((targetData->types[0] != TYPE_GHOST && targetData->types[1] != TYPE_GHOST) || targetData->exposedStatus)
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_ALL)
            {
                if (!HasNegativeStatus(target) && !HasQuarterHPOrLess(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
        }
        else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_SET_TRAP)
        {
            s32 useChance;
            rollMoveUseChance:
            useChance = GetMoveAccuracy(move, ACCURACY_TYPE_USE_CHANCE);
            if (DungeonRandomCapped(100) >= useChance)
            {
                goto returnFalse;
            }
        }
    }
    return hasTarget;
}

s32 WeightMove(struct DungeonEntity *user, s32 targetingFlags, struct DungeonEntity *target, u32 moveType)
{
#ifndef NONMATCHING
    register struct DungeonEntityData *targetData asm("r4");
#else
    struct DungeonEntityData *targetData;
#endif
    s32 targetingFlags2 = (s16) targetingFlags;
    u8 moveType2 = moveType;
    u8 weight = 1;
    struct DungeonEntityData *targetData2;
    targetData2 = targetData = target->entityData;
    if (!targetData->isEnemy || (targetingFlags2 & 0xF) != TARGETING_FLAG_TARGET_OTHER)
    {
        return 1;
    }
    else if (HasIQSkill(user, IQ_SKILL_EXP_GO_GETTER))
    {
        // BUG: expYieldRankings has lower values as the Pokémon's experience yield increases.
        // This causes Exp. Go-Getter to prioritize Pokémon worth less experience
        // instead of Pokémon worth more experience.
        weight = gDungeonGlobalData->expYieldRankings[targetData->entityID];
    }
    else if (HasIQSkill(user, IQ_SKILL_EFFICIENCY_EXPERT))
    {
        weight = -12 - targetData2->HP;
        if (weight == 0)
        {
            weight = 1;
        }
    }
    else if (HasIQSkill(user, IQ_SKILL_WEAK_TYPE_PICKER))
    {
       weight = WeightWeakTypePicker(user, target, moveType2) + 1;
    }
    return weight;
}

bool8 TargetRegularAttack(struct DungeonEntity *pokemon, u32 *targetDir, bool8 checkPetrified)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 numPotentialTargets = 0;
    s32 facingDir = pokemonData->action.facingDir;
    s32 faceTurnLimit = pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER ? 1 : 8;
    s32 i;
    s32 potentialAttackTargetDirections[NUM_DIRECTIONS];
    s32 potentialAttackTargetWeights[NUM_DIRECTIONS];
    bool8 hasTargetingIQ = HasIQSkill(pokemon, IQ_SKILL_EXP_GO_GETTER) || HasIQSkill(pokemon, IQ_SKILL_EFFICIENCY_EXPERT);
    bool8 hasStatusChecker = HasIQSkill(pokemon, IQ_SKILL_STATUS_CHECKER);
    for (i = 0; i < faceTurnLimit; i++, facingDir++)
    {
        struct DungeonEntity *target;
        facingDir &= DIRECTION_MASK;
        target = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[facingDir].x,
            pokemon->posWorld.y + gAdjacentTileOffsets[facingDir].y)->pokemon;
        if (target != NULL &&
            GetEntityType(target) == ENTITY_POKEMON &&
            CanAttackInFront(pokemon, facingDir) &&
            CanTarget(pokemon, target, FALSE, checkPetrified) == TARGET_CAPABILITY_CAN_TARGET &&
            (!hasStatusChecker || target->entityData->immobilizeStatus != IMMOBILIZE_STATUS_FROZEN))
        {
            potentialAttackTargetDirections[numPotentialTargets] = facingDir;
            potentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, TARGETING_FLAG_TARGET_OTHER, target, TYPE_NONE);
            if (!hasTargetingIQ)
            {
                *targetDir = facingDir;
                return TRUE;
            }
            numPotentialTargets++;
        }
    }
    if (numPotentialTargets == 0)
    {
        return FALSE;
    }
    else
    {
        s32 totalWeight = 0;
        s32 maxWeight = 0;
        s32 weightCounter;
        s32 i;
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight < potentialAttackTargetWeights[i])
            {
                maxWeight = potentialAttackTargetWeights[i];
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight != potentialAttackTargetWeights[i])
            {
                potentialAttackTargetWeights[i] = 0;
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            totalWeight += potentialAttackTargetWeights[i];
        }
        weightCounter = DungeonRandomCapped(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= potentialAttackTargetWeights[i];
            if (weightCounter < 0)
            {
                break;
            }
        }
        *targetDir = potentialAttackTargetDirections[i];
        return TRUE;
    }

}

bool8 IsTargetStraightAhead(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, s32 facingDir, s32 maxRange)
{
    s32 distanceX = pokemon->posWorld.x - targetPokemon->posWorld.x;
    s32 effectiveMaxRange;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    effectiveMaxRange = pokemon->posWorld.y - targetPokemon->posWorld.y;
    if (effectiveMaxRange < 0)
    {
        effectiveMaxRange = -effectiveMaxRange;
    }
    if (effectiveMaxRange < distanceX)
    {
        effectiveMaxRange = distanceX;
    }
    if (effectiveMaxRange > maxRange)
    {
        effectiveMaxRange = maxRange;
    }
    if (!HasIQSkill(pokemon, IQ_SKILL_COURSE_CHECKER))
    {
        // BUG: effectiveMaxRange is already capped at maxRange, so this condition always evaluates to TRUE.
        // The AI also has range checks elsewhere, so this doesn't become an issue in most cases.
        // If the AI has the Long Toss or Pierce statuses and Course Checker is disabled,
        // this incorrect check causes the AI to throw items at targets further than 10 tiles away.
        if (effectiveMaxRange <= maxRange)
        {
            return TRUE;
        }
    }
    else
    {
        s32 currentPosX = pokemon->posWorld.x;
        s32 currentPosY = pokemon->posWorld.y;
        s32 adjacentTileOffsetX = gAdjacentTileOffsets[facingDir].x;
        s32 adjacentTileOffsetY = gAdjacentTileOffsets[facingDir].y;
        s32 i;
        for (i = 0; i <= effectiveMaxRange; i++)
        {
            struct MapTile *mapTile;
            currentPosX += adjacentTileOffsetX;
            currentPosY += adjacentTileOffsetY;
            if (currentPosX <= 0 || currentPosY <= 0 ||
                currentPosX >= DUNGEON_MAX_SIZE_X - 1 || currentPosY >= DUNGEON_MAX_SIZE_Y - 1)
            {
                break;
            }
            while (0); // Extra label needed to swap branch locations in ASM.
            mapTile = GetMapTile_1(currentPosX, currentPosY);
            if (!(mapTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
            {
                break;
            }
            if (mapTile->pokemon == targetPokemon)
            {
                return TRUE;
            }
            if (mapTile->pokemon != NULL)
            {
                break;
            }
        }
    }
    return FALSE;
}
