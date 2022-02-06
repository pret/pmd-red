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
#include "dungeon_capabilities_1.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_random.h"
#include "dungeon_random_1.h"
#include "moves.h"
#include "status_checks.h"

#define REGULAR_ATTACK_INDEX 4

const s16 gRegularAttackWeights[] = {100, 20, 30, 40, 50};

struct MoveTargetResults
{
    bool8 moveUsable;
    u8 targetDir;
    s32 moveWeight;
};

extern void TargetTileInFront(struct DungeonEntity*);
extern s32 FindMoveTarget(struct MoveTargetResults*, struct DungeonEntity*, struct PokemonMove*);
extern bool8 IsMoveUsable(struct DungeonEntity*, s32, bool8);
extern bool8 TargetRegularAttack(struct DungeonEntity*, u32*, bool8);

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
