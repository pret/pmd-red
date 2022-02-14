#include "global.h"
#include "dungeon_ai_attack.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/type.h"
#include "charge_move.h"
#include "dungeon_action.h"
#include "dungeon_ai.h"
#include "dungeon_ai_attack_1.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_random_1.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "moves.h"
#include "position_util.h"
#include "status_checks.h"
#include "targeting.h"
#include "targeting_flags.h"

#define REGULAR_ATTACK_INDEX 4

const s16 gRegularAttackWeights[] = {100, 20, 30, 40, 50};

extern bool8 gCanAttackInDirection[NUM_DIRECTIONS];
extern s32 gNumPotentialTargets;
extern s32 gPotentialTargetWeights_2[NUM_DIRECTIONS];
extern u8 gPotentialAttackTargetDirections[NUM_DIRECTIONS];
extern struct DungeonEntity *gPotentialTargets[NUM_DIRECTIONS];

extern bool8 IsMoveUsable(struct DungeonEntity*, s32, bool8);
extern bool8 TargetRegularAttack(struct DungeonEntity*, u32*, bool8);
extern bool8 CanUseWithStatusChecker(struct DungeonEntity*, struct PokemonMove*);
extern bool8 CanAttackInFront(struct DungeonEntity*, s32);
extern s32 WeightMoveIfUsable(s32, s32, struct DungeonEntity*, struct DungeonEntity*, struct PokemonMove*, bool8);
extern bool8 IsTargetInLineRange(struct DungeonEntity*, struct DungeonEntity*, s32);
extern bool8 CanUseStatusMove(s32, struct DungeonEntity*, struct DungeonEntity*, struct PokemonMove*, bool8);
extern s32 WeightMove(struct DungeonEntity*, s32, struct DungeonEntity*, u8);

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
            IsMoveUsable(pokemon, i, hasPPChecker) &&
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
        (hasStatusChecker && !CanUseWithStatusChecker(pokemon, move)))
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
                gPotentialTargetWeights_2[numPotentialTargets] = 99;
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
                struct MapTile *adjacentTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[i].x,
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
            struct MapTile *targetTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[i].x,
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
                targetTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[i].x * 2,
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
                    gPotentialTargetWeights_2[numPotentialTargets] = WeightMove(pokemon, targetingFlags, target, GetMoveTypeForPokemon(pokemon, move));
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
            if (maxWeight < gPotentialTargetWeights_2[i])
            {
                maxWeight = gPotentialTargetWeights_2[i];
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight != gPotentialTargetWeights_2[i])
            {
                gPotentialTargetWeights_2[i] = 0;
            }
        }
        moveWeight = maxWeight;
        for (i = 0; i < numPotentialTargets; i++)
        {
            totalWeight += gPotentialTargetWeights_2[i];
        }
        weightCounter = DungeonRandomCapped(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= gPotentialTargetWeights_2[i];
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