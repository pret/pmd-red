#include "global.h"
#include "dungeon_ai_attack_1.h"

#include "constants/direction.h"
#include "constants/iq_skill.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "dungeon_ai_targeting_2.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "moves.h"
#include "position_util.h"
#include "status_checker.h"
#include "status_checks_1.h"
#include "type_effectiveness.h"

extern bool8 gCanAttackInDirection[NUM_DIRECTIONS];
extern s32 gPotentialAttackTargetWeights[NUM_DIRECTIONS];
extern u8 gPotentialAttackTargetDirections[NUM_DIRECTIONS];
extern struct DungeonEntity *gPotentialTargets[NUM_DIRECTIONS];

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
        // This causes Exp. Go-Getter to prioritizes Pokémon worth less experience
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
