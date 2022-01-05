#include "global.h"
#include "dungeon_ai_1.h"

#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_pokemon_attributes_1.h"

const u8 gTargetingData[3][2][2][2] = {
    {
        {
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        }
    },
    {
        {
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET},
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET}
        }
    },
    {
        {
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET},
            {TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET, TARGET_CAPABILITY_CAN_TARGET}
        },
        {
            {TARGET_CAPABILITY_CAN_TARGET, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET},
            {TARGET_CAPABILITY_CANNOT_ATTACK, TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET}
        }
    }
};

u8 CanTarget(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct DungeonEntityData *targetData = targetPokemon->entityData;
    u8 targetingDecoy;
    u8 pokemonTargetingDecoy;
    bool8 pokemonIsEnemy;
    bool8 targetIsEnemy;
    bool8 targetIsDecoy;
    if (pokemon == targetPokemon)
    {
        return TARGET_CAPABILITY_CANNOT_ATTACK;
    }
    if (pokemonData->shopkeeperMode == SHOPKEEPER_FRIENDLY ||
        targetData->shopkeeperMode == SHOPKEEPER_FRIENDLY ||
        pokemonData->clientType == CLIENT_TYPE_DONT_MOVE ||
        targetData->clientType == CLIENT_TYPE_DONT_MOVE ||
        pokemonData->clientType == CLIENT_TYPE_CLIENT ||
        targetData->clientType == CLIENT_TYPE_CLIENT ||
        (checkPetrified && !pokemonData->isEnemy && targetData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED) ||
        (!ignoreInvisible && targetData->transformStatus == TRANSFORM_STATUS_INVISIBLE && !CanSeeInvisible(pokemon)))
    {
        return TARGET_CAPABILITY_CAN_ATTACK_NOT_TARGET;
    }
    pokemonTargetingDecoy = pokemonData->targetingDecoy;
    targetingDecoy = TARGETING_DECOY_NONE;
    if (pokemonTargetingDecoy != TARGETING_DECOY_NONE)
    {
        targetingDecoy = TARGETING_DECOY_WILD;
        if (pokemonTargetingDecoy == TARGETING_DECOY_TEAM)
        {
            targetingDecoy = TARGETING_DECOY_TEAM;
        }
    }
    if (pokemonData->shopkeeperMode != SHOPKEEPER_NONE)
    {
        pokemonIsEnemy = FALSE;
        if (pokemonData->shopkeeperMode == SHOPKEEPER_AGGRESSIVE_TO_PLAYER)
        {
            pokemonIsEnemy = TRUE;
        }
    }
    else
    {
        pokemonIsEnemy = pokemonData->isEnemy ? TRUE : FALSE;
    }
    if (targetData->shopkeeperMode != SHOPKEEPER_NONE)
    {
        targetIsEnemy = FALSE;
        if (targetData->shopkeeperMode == SHOPKEEPER_AGGRESSIVE_TO_PLAYER)
        {
            targetIsEnemy = TRUE;
        }
    }
    else
    {
        targetIsEnemy = targetData->isEnemy ? TRUE : FALSE;
    }
    targetIsDecoy = FALSE;
    if (targetData->waitingStatus == WAITING_STATUS_DECOY)
    {
        targetIsDecoy = TRUE;
    }
    return gTargetingData[targetingDecoy][pokemonIsEnemy][targetIsEnemy][targetIsDecoy];
}
