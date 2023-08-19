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
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "move_util.h"
#include "moves.h"
#include "move_checks.h"
#include "position_util.h"
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
extern struct Entity *gPotentialTargets[NUM_DIRECTIONS];

extern void sub_8055A00(struct Entity *, u8, u32, u32, u32);
extern void sub_806A9B4(struct Entity *, u8);
extern bool8 sub_8044B28(void);
extern void sub_8057588(struct Entity *, u32);
extern void sub_806A1B0(struct Entity *);
extern struct Item *sub_8044D90(struct Entity *, s32, u32);
extern bool8 sub_8044D40(struct ActionContainer *, u32);

void DecideAttack(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 i;
    s32 chargeStatus = STATUS_CHARGING;
    struct AIPossibleMove aiPossibleMove[MAX_MON_MOVES + 1];
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
        ShouldMonsterRunAwayAndShowEffect(pokemon, TRUE) ||
        HasTactic(pokemon, TACTIC_KEEP_YOUR_DISTANCE) ||
        (pokemonInfo->volatileStatus == STATUS_CONFUSED && DungeonRandOutcome(gConfusedAttackChance)))
    {
        return;
    }
    if (pokemonInfo->chargingStatus != STATUS_NONE)
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_EXISTS &&
                MoveMatchesChargingStatus(pokemon, &pokemonInfo->moves[i]) &&
                pokemonInfo->chargingStatusMoveIndex == i)
            {
                s32 chosenMoveIndex;
                SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_AI);
                chosenMoveIndex = i;
                if (i > 0 && pokemonInfo->moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
                {
                    while (--chosenMoveIndex > 0)
                    {
                        if (!(pokemonInfo->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                        {
                            break;
                        }
                    }
                }
                pokemonInfo->action.actionUseIndex = chosenMoveIndex;
                TargetTileInFront(pokemon);
                return;
            }
        }
    }
    total = 0;
    numUsableMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct Move *move = &pokemonInfo->moves[i];
        if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_EXISTS)
        {
            if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
            {
                numUsableMoves++;
            }
            total += move->PP;
        }
    }
    if (total == 0)
    {
        struct Move struggle;
        InitPokemonMove(&struggle, MOVE_STRUGGLE);
        AIConsiderMove(&aiPossibleMove[0], pokemon, &struggle);
        if (aiPossibleMove[0].canBeUsed)
        {
            SetMonsterActionFields(&pokemonInfo->action, ACTION_STRUGGLE);
            pokemonInfo->action.direction = aiPossibleMove[0].direction & DIRECTION_MASK;
            TargetTileInFront(pokemon);
        }
        return;
    }
    hasWeakTypePicker = IQSkillIsEnabled(pokemon, IQ_WEAK_TYPE_PICKER);
    hasPPChecker = IQSkillIsEnabled(pokemon, IQ_PP_CHECKER) != FALSE;
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
            struct Move *move = &pokemonInfo->moves[i];
            if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            {
                break;
            }
            if (i != 0 && !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
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
        struct Move *move;
        aiPossibleMove[i].canBeUsed = FALSE;
        move = &pokemonInfo->moves[i];
        if (move->moveFlags & MOVE_FLAG_EXISTS &&
            willNotUnlinkMove[i] &&
            CanAIUseMove(pokemon, i, hasPPChecker) &&
            move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
        {
            aiPossibleMove[i].canBeUsed = TRUE;
            if (pokemonInfo->chargingStatus == chargeStatus)
            {
                if (move->id == MOVE_CHARGE)
                {
                    aiPossibleMove[i].weight = 0;
                    continue;
                }
                else if (GetMoveTypeForMonster(pokemon, move) == TYPE_ELECTRIC)
                {
                    aiPossibleMove[i].weight = GetMoveAIWeight(move);
                }
                else
                {
                    aiPossibleMove[i].weight = 1;
                }
            }
            else if (hasWeakTypePicker)
            {
                struct AIPossibleMove *results = &aiPossibleMove[i];
                results->weight = AIConsiderMove(results, pokemon, move);
            }
            else
            {
                aiPossibleMove[i].weight = GetMoveAIWeight(move);
            }
            total += aiPossibleMove[i].weight;
        }
    }
    aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 0;
    if (!IQSkillIsEnabled(pokemon, IQ_EXCLUSIVE_MOVE_USER) && pokemonInfo->chargingStatus != chargeStatus)
    {
        aiPossibleMove[REGULAR_ATTACK_INDEX].canBeUsed = TRUE;
        if (pokemonInfo->chargingStatus == chargeStatus)
        {
            // Never reached? Charge already skips the regular attack in the outer block.
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 1;
        }
        else if (hasWeakTypePicker)
        {
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 2;
        }
        else
        {
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = gRegularAttackWeights[numUsableMoves];
        }
        total += aiPossibleMove[REGULAR_ATTACK_INDEX].weight;
    }
    if (hasWeakTypePicker)
    {
        s32 i;
        maxWeight = 0;
        total = 0;
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (!aiPossibleMove[i].canBeUsed)
            {
                aiPossibleMove[i].weight = 0;
            }
            else if (maxWeight < aiPossibleMove[i].weight)
            {
                maxWeight = aiPossibleMove[i].weight;
            }
        }
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (aiPossibleMove[i].canBeUsed)
            {
                if (maxWeight != aiPossibleMove[i].weight)
                {
                    // Only the move(s) with the highest weight can be used, instead of a weighted random.
                    // This has the side effect of making the AI use a STAB ranged move consistently when at a distance.
                    aiPossibleMove[i].weight = 0;
                }
                total += aiPossibleMove[i].weight;
            }
        }
    }
    if (total == 0)
    {
        return;
    }
    randomWeight = DungeonRandInt(total);
    weightCounter = 0;
    if (!IQSkillIsEnabled(pokemon, IQ_EXCLUSIVE_MOVE_USER))
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
        if (aiPossibleMove[i].canBeUsed && aiPossibleMove[i].weight != 0)
        {
            weightCounter += aiPossibleMove[i].weight;
            if (weightCounter >= randomWeight)
            {
                if (i == REGULAR_ATTACK_INDEX)
                {
                    if (canTargetRegularAttack)
                    {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_REGULAR_ATTACK);
                        pokemonInfo->action.direction = regularAttackTargetDir & DIRECTION_MASK;
                        TargetTileInFront(pokemon);
                    }
                }
                else
                {
                    AIConsiderMove(&aiPossibleMove[i], pokemon, &pokemonInfo->moves[i]);
                    if (aiPossibleMove[i].canBeUsed)
                    {
                        s32 chosenMoveIndex;
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_AI);
                        chosenMoveIndex = i;
                        if (i > 0 && pokemonInfo->moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
                        {
                            while (--chosenMoveIndex > 0)
                            {
                                if (!(pokemonInfo->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                                {
                                    break;
                                }
                            }
                        }
                        pokemonInfo->action.direction = aiPossibleMove[i].direction & DIRECTION_MASK;
                        pokemonInfo->action.actionUseIndex = chosenMoveIndex;
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
        SetMonsterActionFields(&pokemonInfo->action, ACTION_REGULAR_ATTACK);
        pokemonInfo->action.direction = regularAttackTargetDir & DIRECTION_MASK;
        TargetTileInFront(pokemon);
    }
}

s32 AIConsiderMove(struct AIPossibleMove *aiPossibleMove, struct Entity *pokemon, struct Move *move)
{
    s32 targetingFlags;
    s32 moveWeight = 1;
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 numPotentialTargets = 0;
    s32 i;
    bool8 hasStatusChecker;
    s32 rangeTargetingFlags;
    s32 rangeTargetingFlags2;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gCanAttackInDirection[i] = FALSE;
    }
    targetingFlags = GetMoveTargetAndRangeForPokemon(pokemon, move, TRUE);
    hasStatusChecker = IQSkillIsEnabled(pokemon, IQ_STATUS_CHECKER);
    aiPossibleMove->canBeUsed = FALSE;
    if ((pokemonInfo->volatileStatus == STATUS_TAUNTED && !MovesIgnoresTaunted(move)) ||
        (hasStatusChecker && !CanUseOnSelfWithStatusChecker(pokemon, move)))
    {
        return 1;
    }
    rangeTargetingFlags = targetingFlags & 0xF0;
    if (rangeTargetingFlags == TARGETING_FLAG_TARGET_OTHER ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_FRONTAL_CONE ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_AROUND)
    {
        if (pokemonInfo->eyesightStatus == STATUS_BLINKER)
        {
            u8 direction = pokemonInfo->action.direction;
            i = direction; // Fixes a regswap.
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
                struct Tile *adjacentTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x,
                    pokemon->pos.y + gAdjacentTileOffsets[i].y);
                struct Entity *adjacentPokemon = adjacentTile->monster;
                if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) == ENTITY_MONSTER)
                {
                    if (rangeTargetingFlags != TARGETING_FLAG_TARGET_FRONTAL_CONE &&
                        rangeTargetingFlags != TARGETING_FLAG_TARGET_AROUND)
                    {
                        if (!CanAttackInDirection(pokemon, i))
                        {
                            continue;
                        }
                    }
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, adjacentPokemon, move, hasStatusChecker);
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_ROOM)
    {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target) && CanSeeTarget(pokemon, target))
            {
                numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_2_TILES_AHEAD)
    {
        for (i = 0; i < NUM_DIRECTIONS; i++)
        {
            struct Tile *targetTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x,
                pokemon->pos.y + gAdjacentTileOffsets[i].y);
            if (CanAttackInDirection(pokemon, i))
            {
                struct Entity *targetPokemon = targetTile->monster;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_MONSTER)
                {
                    s32 prevNumPotentialTargets = numPotentialTargets;
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
                    if (prevNumPotentialTargets != numPotentialTargets)
                    {
                        continue;
                    }
                }
                targetTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x * 2,
                    pokemon->pos.y + gAdjacentTileOffsets[i].y * 2);
                targetPokemon = targetTile->monster;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_MONSTER)
                {
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
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
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target) && pokemon != target)
            {
                s32 direction = GetDirectionTowardsPosition(&pokemon->pos, &target->pos);
                if (!gCanAttackInDirection[direction] &&
                    CanSeeTarget(pokemon, target) &&
                    IsTargetInLineRange(pokemon, target, maxRange) &&
                    IsAITargetEligible(targetingFlags, pokemon, target, move, hasStatusChecker) &&
                    IsTargetInRange(pokemon, target, direction, maxRange))
                {
                    gCanAttackInDirection[direction] = TRUE;
                    gPotentialAttackTargetDirections[numPotentialTargets] = direction;
                    gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, targetingFlags, target, GetMoveTypeForMonster(pokemon, move));
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
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target))
            {
                numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_SELF)
    {
        numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, pokemon, move, hasStatusChecker);
    }
    if (numPotentialTargets == 0)
    {
        aiPossibleMove->canBeUsed = FALSE;
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
        weightCounter = DungeonRandInt(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= gPotentialAttackTargetWeights[i];
            if (weightCounter < 0)
            {
                break;
            }
        }
        aiPossibleMove->canBeUsed = TRUE;
        aiPossibleMove->direction = gPotentialAttackTargetDirections[i];
        aiPossibleMove->weight = 8;
    }
    return moveWeight;
}

bool8 IsTargetInLineRange(struct Entity *user, struct Entity *target, s32 range)
{
    s32 distanceX = user->pos.x - target->pos.x;
    s32 distanceY, distance;
    s32 direction;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    distanceY = user->pos.y - target->pos.y;
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
        if (user->pos.x < target->pos.x &&
            (user->pos.y < target->pos.y || user->pos.y > target->pos.y))
        {
            returnTrue:
            return TRUE;
        }
        if (user->pos.x > target->pos.x); // Fixes register loading order.
        direction = DIRECTION_SOUTHWEST;
        if (user->pos.x <= target->pos.x || user->pos.y <= target->pos.y)
        {
            goto checkDirectionSet;
        }
        goto returnTrue;
    }
    else if (user->pos.x == target->pos.x && user->pos.y < target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x < target->pos.x && user->pos.y == target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x == target->pos.x && user->pos.y > target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x > target->pos.x && user->pos.y == target->pos.y)
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

s32 TryAddTargetToAITargetList(s32 numPotentialTargets, s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, bool32 hasStatusChecker)
{
    s32 direction;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    struct EntityInfo *userData = user->info;
    if ((user->pos.x == target->pos.x && user->pos.y == target->pos.y) ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_ROOM ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_FLOOR ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_SELF)
    {
        direction = userData->action.direction;
    }
    else
    {
        direction = GetDirectionTowardsPosition(&user->pos, &target->pos);
    }
    if (!gCanAttackInDirection[direction] &&
        IsAITargetEligible(targetingFlags2, user, target, move, hasStatusChecker2))
    {
        gCanAttackInDirection[direction] = TRUE;
        do { gPotentialAttackTargetDirections[numPotentialTargets] = direction; } while (0);
        gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(user, targetingFlags2, target, GetMoveTypeForMonster(user, move));
        gPotentialTargets[numPotentialTargets] = target;
        numPotentialTargets++;
    }
    return numPotentialTargets;
}

bool8 IsAITargetEligible(s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, bool32 hasStatusChecker)
{
    struct EntityInfo *targetData;
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
        targetData = target->info;
        goto checkThirdParty;
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_ATTACK_ALL)
    {
        targetData = target->info;
        if (user == target)
        {
            goto returnFalse;
        }
        checkThirdParty:
        hasTarget = TRUE;
        if (targetData->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
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
                if (!HasLowHealth(target))
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
                targetData = target->info;
                if ((targetData->types[0] != TYPE_GHOST && targetData->types[1] != TYPE_GHOST) || targetData->exposed)
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_ALL)
            {
                if (!HasNegativeStatus(target) && !HasLowHealth(target))
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
            useChance = GetMoveAccuracyOrAIChance(move, ACCURACY_AI_CONDITION_RANDOM_CHANCE);
            if (DungeonRandInt(100) >= useChance)
            {
                goto returnFalse;
            }
        }
    }
    return hasTarget;
}

s32 WeightMove(struct Entity *user, s32 targetingFlags, struct Entity *target, u32 moveType)
{
#ifndef NONMATCHING
    register struct EntityInfo *targetData asm("r4");
#else
    struct EntityInfo *targetData;
#endif
    s32 targetingFlags2 = (s16) targetingFlags;
    u8 moveType2 = moveType;
    u8 weight = 1;
    struct EntityInfo *targetData2;
    targetData2 = targetData = target->info;
    if (!targetData->isNotTeamMember || (targetingFlags2 & 0xF) != TARGETING_FLAG_TARGET_OTHER)
    {
        return 1;
    }
    else if (IQSkillIsEnabled(user, IQ_EXP_GO_GETTER))
    {
        // BUG: expYieldRankings has lower values as the Pokémon's experience yield increases.
        // This causes Exp. Go-Getter to prioritize Pokémon worth less experience
        // instead of Pokémon worth more experience.
        weight = gDungeon->expYieldRankings[targetData->id];
    }
    else if (IQSkillIsEnabled(user, IQ_EFFICIENCY_EXPERT))
    {
        weight = -12 - targetData2->HP;
        if (weight == 0)
        {
            weight = 1;
        }
    }
    else if (IQSkillIsEnabled(user, IQ_WEAK_TYPE_PICKER))
    {
       weight = WeightWeakTypePicker(user, target, moveType2) + 1;
    }
    return weight;
}

bool8 TargetRegularAttack(struct Entity *pokemon, u32 *targetDir, bool8 checkPetrified)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 numPotentialTargets = 0;
    s32 direction = pokemonInfo->action.direction;
    s32 faceTurnLimit = pokemonInfo->eyesightStatus == STATUS_BLINKER ? 1 : 8;
    s32 i;
    s32 potentialAttackTargetDirections[NUM_DIRECTIONS];
    s32 potentialAttackTargetWeights[NUM_DIRECTIONS];
    bool8 hasTargetingIQ = IQSkillIsEnabled(pokemon, IQ_EXP_GO_GETTER) || IQSkillIsEnabled(pokemon, IQ_EFFICIENCY_EXPERT);
    bool8 hasStatusChecker = IQSkillIsEnabled(pokemon, IQ_STATUS_CHECKER);
    for (i = 0; i < faceTurnLimit; i++, direction++)
    {
        struct Entity *target;
        direction &= DIRECTION_MASK;
        target = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
            pokemon->pos.y + gAdjacentTileOffsets[direction].y)->monster;
        if (target != NULL &&
            GetEntityType(target) == ENTITY_MONSTER &&
            CanAttackInDirection(pokemon, direction) &&
            CanTarget(pokemon, target, FALSE, checkPetrified) == TARGET_CAPABILITY_CAN_TARGET &&
            (!hasStatusChecker || target->info->immobilizeStatus != STATUS_FROZEN))
        {
            potentialAttackTargetDirections[numPotentialTargets] = direction;
            potentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, TARGETING_FLAG_TARGET_OTHER, target, TYPE_NONE);
            if (!hasTargetingIQ)
            {
                *targetDir = direction;
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
        weightCounter = DungeonRandInt(totalWeight);
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

bool8 IsTargetInRange(struct Entity *pokemon, struct Entity *targetPokemon, s32 direction, s32 maxRange)
{
    s32 distanceX = pokemon->pos.x - targetPokemon->pos.x;
    s32 effectiveMaxRange;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    effectiveMaxRange = pokemon->pos.y - targetPokemon->pos.y;
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
    if (!IQSkillIsEnabled(pokemon, IQ_COURSE_CHECKER))
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
        s32 currentPosX = pokemon->pos.x;
        s32 currentPosY = pokemon->pos.y;
        s32 adjacentTileOffsetX = gAdjacentTileOffsets[direction].x;
        s32 adjacentTileOffsetY = gAdjacentTileOffsets[direction].y;
        s32 i;
        for (i = 0; i <= effectiveMaxRange; i++)
        {
            struct Tile *mapTile;
            currentPosX += adjacentTileOffsetX;
            currentPosY += adjacentTileOffsetY;
            if (currentPosX <= 0 || currentPosY <= 0 ||
                currentPosX >= DUNGEON_MAX_SIZE_X - 1 || currentPosY >= DUNGEON_MAX_SIZE_Y - 1)
            {
                break;
            }
            while (0); // Extra label needed to swap branch locations in ASM.
            mapTile = GetTile(currentPosX, currentPosY);
            if (!(mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            {
                break;
            }
            if (mapTile->monster == targetPokemon)
            {
                return TRUE;
            }
            if (mapTile->monster != NULL)
            {
                break;
            }
        }
    }
    return FALSE;
}

void sub_807CABC(struct Entity *target)
{
    struct EntityInfo *entityInfo;
    s32 counter;

    counter = 0;
    while (TRUE) {
        if (counter >= sub_8070828(target, TRUE))
            break;
        entityInfo = target->info;
        sub_8055A00(target, entityInfo->action.actionUseIndex, 1, 0, 0);
        if (!EntityExists(target))
            break;
        if (sub_8044B28())
            break;
        if (entityInfo->unk159)
            break;
        counter++;
    }

    sub_8057588(target, 1);
    if (EntityExists(target))
        sub_806A9B4(target, target->info->action.actionUseIndex);

    sub_806A1B0(target);
}

#if NONMATCHING // 99.09% https://decomp.me/scratch/rpwXh
void sub_807CB3C(struct Entity *pokemon)
{
    bool8 r4;
    struct Item *item;
    struct Item IVar5;
    struct EntityInfo *entityInfo; // r7
    struct ActionContainer act;
    struct Move move;
    struct AIPossibleMove sp28;
    bool8 r8;

    entityInfo = pokemon->info;
    item = sub_8044D90(pokemon, 0, 21);
    IVar5 = *item;

    if (item->flags & ITEM_FLAG_STICKY) {
        sub_8045BF8(gUnknown_202DE58, item);
        SendMessage(pokemon, *gUnknown_80FE3E8);
        return;
    }

    act = entityInfo->action;

    if (IsBossFight()) {
        SendMessage(pokemon, *gPtrMysteriousPowerPreventedUseMessage);
        r4 = TRUE;
    }
    else {
        r8 = TRUE;
        InitPokemonMove(&move, GetItemMoveID(IVar5.id));

        if (!entityInfo->isTeamLeader) {
            sp28.canBeUsed = r8;
            sp28.weight = 10;
            AIConsiderMove(&sp28, pokemon, entityInfo->moves);

            if (sp28.canBeUsed) {
                entityInfo->action.direction = sp28.direction & 7;
                TargetTileInFront(pokemon);
            }
        }
    
        if (entityInfo->volatileStatus == 1) {
            SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
            SendMessage(pokemon, *gUnknown_80FC714);
            r4 = FALSE;
        }
        else if (entityInfo->volatileStatus == 7) {
            SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
            SendMessage(pokemon, *gUnknown_80FC718);
            r4 = FALSE;
        }
        else {
            if (entityInfo->nonVolatileStatus == 4) {
                SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
                SendMessage(pokemon, *gUnknown_80FC6A8);
                r4 = FALSE;
                r8 = FALSE;
            }
            if (r8) {
                if ((IVar5.id == ITEM_SWITCHER_ORB) || (IVar5.id == ITEM_POUNCE_ORB)) {
                    sub_8044DF0(pokemon, 0, 122);
                    move.moveFlags |= MOVE_FLAG_SET;
                    move.moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                    move.PP = 10;
                    sub_8055FA0(pokemon, 0, IVar5.id, 0, 0, &move);
                    r4 = FALSE;
                }
                else
                    r4 = sub_8055FA0(pokemon, 0, IVar5.id, 0, 0, &move);
            }
            else
                r4 = FALSE;
        }
    }

    if (EntityExists(pokemon)) {
        if (r4)
            sub_8044DF0(pokemon, 0, 122);

        sub_8071DA4(pokemon);
        sub_806CE68(pokemon, 8);

        if (entityInfo->isTeamLeader) {
            sub_804AC20(&pokemon->pos);
            sub_807EC28(FALSE);
        }

        sub_806A5B8(pokemon);
        sub_8075900(pokemon, gDungeon->unk3A08);
    }
    else if (r4)
        sub_8044D40(&act, 0);

    if (!sub_8044B28())
        sub_806A1B0(pokemon);
}
#else
NAKED
void sub_807CB3C(struct Entity *pokemon)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x30\n"
    "\tadds r6, r0, 0\n"
    "\tldr r7, [r6, 0x70]\n"
    "\tmovs r1, 0\n"
    "\tmovs r2, 0x15\n"
    "\tbl sub_8044D90\n"
    "\tadds r2, r0, 0\n"
    "\tldr r5, [r2]\n"
    "\tldrb r1, [r2]\n"
    "\tmovs r0, 0x8\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CB80\n"
    "\tldr r0, _0807CB78\n"
    "\tadds r1, r2, 0\n"
    "\tbl sub_8045BF8\n"
    "\tldr r0, _0807CB7C\n"
    "\tldr r1, [r0]\n"
    "\tadds r0, r6, 0\n"
    "\tbl SendMessage\n"
    "\tb _0807CD54\n"
    "\t.align 2, 0\n"
"_0807CB78: .4byte gUnknown_202DE58\n"
"_0807CB7C: .4byte gUnknown_80FE3E8\n"
"_0807CB80:\n"
    "\tadd r0, sp, 0x8\n"
    "\tadds r1, r7, 0\n"
    "\tadds r1, 0x44\n"
    "\tldm r1!, {r2-r4}\n"
    "\tstm r0!, {r2-r4}\n"
    "\tldm r1!, {r2-r4}\n"
    "\tstm r0!, {r2-r4}\n"
    "\tbl IsBossFight\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CBAC\n"
    "\tldr r0, _0807CBA8\n"
    "\tldr r1, [r0]\n"
    "\tadds r0, r6, 0\n"
    "\tbl SendMessage\n"
    "\tmovs r4, 0x1\n"
    "\tb _0807CCDE\n"
    "\t.align 2, 0\n"
"_0807CBA8: .4byte gPtrMysteriousPowerPreventedUseMessage\n"
"_0807CBAC:\n"
    "\tmovs r0, 0x1\n"
    "\tmov r8, r0\n"
    "\tadd r4, sp, 0x20\n"
    "\tlsls r5, 8\n"
    "\tlsrs r0, r5, 24\n"
    "\tbl GetItemMoveID\n"
    "\tadds r1, r0, 0\n"
    "\tlsls r1, 16\n"
    "\tlsrs r1, 16\n"
    "\tadds r0, r4, 0\n"
    "\tbl InitPokemonMove\n"
    "\tldrb r0, [r7, 0x7]\n"
    "\tmov r10, r4\n"
    "\tmov r9, r5\n"
    "\tcmp r0, 0\n"
    "\tbne _0807CC08\n"
    "\tldr r1, _0807CC20\n"
    "\tldr r0, [sp, 0x28]\n"
    "\tands r0, r1\n"
    "\tmov r1, r8\n"
    "\torrs r0, r1\n"
    "\tstr r0, [sp, 0x28]\n"
    "\tmovs r0, 0xA\n"
    "\tadd r4, sp, 0x28\n"
    "\tstr r0, [r4, 0x4]\n"
    "\tmovs r3, 0x8C\n"
    "\tlsls r3, 1\n"
    "\tadds r2, r7, r3\n"
    "\tadds r0, r4, 0\n"
    "\tadds r1, r6, 0\n"
    "\tbl AIConsiderMove\n"
    "\tldrb r0, [r4]\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CC08\n"
    "\tldrb r1, [r4, 0x1]\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r1\n"
    "\tadds r1, r7, 0\n"
    "\tadds r1, 0x46\n"
    "\tstrb r0, [r1]\n"
    "\tadds r0, r6, 0\n"
    "\tbl TargetTileInFront\n"
"_0807CC08:\n"
    "\tadds r0, r7, 0\n"
    "\tadds r0, 0xBC\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0x1\n"
    "\tbne _0807CC2C\n"
    "\tldr r0, _0807CC24\n"
    "\tadds r1, r6, 0\n"
    "\tmovs r2, 0\n"
    "\tbl SetMessageArgument\n"
    "\tldr r0, _0807CC28\n"
    "\tb _0807CC3C\n"
    "\t.align 2, 0\n"
"_0807CC20: .4byte 0xffffff00\n"
"_0807CC24: .4byte gAvailablePokemonNames\n"
"_0807CC28: .4byte gUnknown_80FC714\n"
"_0807CC2C:\n"
    "\tcmp r0, 0x7\n"
    "\tbne _0807CC50\n"
    "\tldr r0, _0807CC48\n"
    "\tadds r1, r6, 0\n"
    "\tmovs r2, 0\n"
    "\tbl SetMessageArgument\n"
    "\tldr r0, _0807CC4C\n"
"_0807CC3C:\n"
    "\tldr r1, [r0]\n"
    "\tadds r0, r6, 0\n"
    "\tbl SendMessage\n"
    "\tb _0807CCDC\n"
    "\t.align 2, 0\n"
"_0807CC48: .4byte gAvailablePokemonNames\n"
"_0807CC4C: .4byte gUnknown_80FC718\n"
"_0807CC50:\n"
    "\tadds r0, r7, 0\n"
    "\tadds r0, 0xAC\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0x4\n"
    "\tbne _0807CC72\n"
    "\tldr r0, _0807CCB8\n"
    "\tadds r1, r6, 0\n"
    "\tmovs r2, 0\n"
    "\tbl SetMessageArgument\n"
    "\tldr r0, _0807CCBC\n"
    "\tldr r1, [r0]\n"
    "\tadds r0, r6, 0\n"
    "\tbl SendMessage\n"
    "\tmovs r4, 0\n"
    "\tmov r8, r4\n"
"_0807CC72:\n"
    "\tmov r0, r8\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CCDC\n"
    "\tmov r5, r9\n"
    "\tlsrs r0, r5, 24\n"
    "\tcmp r0, 0xB6\n"
    "\tbeq _0807CC84\n"
    "\tcmp r0, 0xBF\n"
    "\tbne _0807CCC0\n"
"_0807CC84:\n"
    "\tadds r0, r6, 0\n"
    "\tmovs r1, 0\n"
    "\tmovs r2, 0x7A\n"
    "\tbl sub_8044DF0\n"
    "\tmov r2, r10\n"
    "\tldrb r1, [r2]\n"
    "\tmovs r0, 0x8\n"
    "\tmovs r4, 0\n"
    "\torrs r0, r1\n"
    "\tadd r3, sp, 0x20\n"
    "\tmovs r1, 0x4\n"
    "\torrs r0, r1\n"
    "\tstrb r0, [r3]\n"
    "\tmovs r0, 0xA\n"
    "\tstrb r0, [r3, 0x4]\n"
    "\tlsrs r2, r5, 24\n"
    "\tstr r4, [sp]\n"
    "\tstr r3, [sp, 0x4]\n"
    "\tadds r0, r6, 0\n"
    "\tmovs r1, 0\n"
    "\tmovs r3, 0\n"
    "\tbl sub_8055FA0\n"
    "\tb _0807CCDE\n"
    "\t.align 2, 0\n"
"_0807CCB8: .4byte gAvailablePokemonNames\n"
"_0807CCBC: .4byte gUnknown_80FC6A8\n"
"_0807CCC0:\n"
    "\tmov r3, r9\n"
    "\tlsrs r2, r3, 24\n"
    "\tmovs r0, 0\n"
    "\tstr r0, [sp]\n"
    "\tmov r4, r10\n"
    "\tstr r4, [sp, 0x4]\n"
    "\tadds r0, r6, 0\n"
    "\tmovs r1, 0\n"
    "\tmovs r3, 0\n"
    "\tbl sub_8055FA0\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tb _0807CCDE\n"
"_0807CCDC:\n"
    "\tmovs r4, 0\n"
"_0807CCDE:\n"
    "\tadds r0, r6, 0\n"
    "\tbl EntityExists\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CD38\n"
    "\tcmp r4, 0\n"
    "\tbeq _0807CCF8\n"
    "\tadds r0, r6, 0\n"
    "\tmovs r1, 0\n"
    "\tmovs r2, 0x7A\n"
    "\tbl sub_8044DF0\n"
"_0807CCF8:\n"
    "\tadds r0, r6, 0\n"
    "\tbl sub_8071DA4\n"
    "\tadds r0, r6, 0\n"
    "\tmovs r1, 0x8\n"
    "\tbl sub_806CE68\n"
    "\tldrb r0, [r7, 0x7]\n"
    "\tcmp r0, 0\n"
    "\tbeq _0807CD18\n"
    "\tadds r0, r6, 0x4\n"
    "\tbl sub_804AC20\n"
    "\tmovs r0, 0\n"
    "\tbl sub_807EC28\n"
"_0807CD18:\n"
    "\tadds r0, r6, 0\n"
    "\tbl sub_806A5B8\n"
    "\tldr r0, _0807CD30\n"
    "\tldr r0, [r0]\n"
    "\tldr r1, _0807CD34\n"
    "\tadds r0, r1\n"
    "\tldrb r1, [r0]\n"
    "\tadds r0, r6, 0\n"
    "\tbl sub_8075900\n"
    "\tb _0807CD44\n"
    "\t.align 2, 0\n"
"_0807CD30: .4byte gDungeon\n"
"_0807CD34: .4byte 0x00003a08\n"
"_0807CD38:\n"
    "\tcmp r4, 0\n"
    "\tbeq _0807CD44\n"
    "\tadd r0, sp, 0x8\n"
    "\tmovs r1, 0\n"
    "\tbl sub_8044D40\n"
"_0807CD44:\n"
    "\tbl sub_8044B28\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _0807CD54\n"
    "\tadds r0, r6, 0\n"
    "\tbl sub_806A1B0\n"
"_0807CD54:\n"
    "\tadd sp, 0x30\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}
#endif // NONMATCHING