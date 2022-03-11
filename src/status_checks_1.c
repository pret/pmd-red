#include "global.h"
#include "status_checks_1.h"

#include "constants/status.h"

bool8 HasNegativeStatus(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 i;
    if (pokemonData->sleepStatus == SLEEP_STATUS_SLEEP ||
        pokemonData->sleepStatus == SLEEP_STATUS_NIGHTMARE ||
        pokemonData->sleepStatus == SLEEP_STATUS_YAWNING ||
        pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_NONE ||
        (pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_INGRAIN && pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_NONE) ||
        pokemonData->volatileStatus != VOLATILE_STATUS_NONE ||
        pokemonData->waitingStatus == WAITING_STATUS_CURSED ||
        pokemonData->waitingStatus == WAITING_STATUS_DECOY ||
        pokemonData->linkedStatus == LINKED_STATUS_LEECH_SEED ||
        pokemonData->moveStatus == MOVE_STATUS_WHIFFER ||
        pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER ||
        pokemonData->eyesightStatus == EYESIGHT_STATUS_CROSS_EYED ||
        pokemonData->muzzledStatus == MUZZLED_STATUS_MUZZLED ||
        pokemonData->exposedStatus ||
        pokemonData->perishSongTimer != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct PokemonMove *moves = pokemonData->moves;
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags2 & MOVE_FLAG_SEALED)
        {
            return TRUE;
        }
    }
    for (i = 0; i < NUM_SPEED_TURN_COUNTERS; i++)
    {
        if (pokemonData->slowTurnsLeft[i] != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsSleeping(struct DungeonEntity *pokemon)
{
    if (pokemon->entityData->sleepStatus != SLEEP_STATUS_SLEEP &&
        pokemon->entityData->sleepStatus != SLEEP_STATUS_NAPPING &&
        pokemon->entityData->sleepStatus != SLEEP_STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasQuarterHPOrLess(struct DungeonEntity* pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct DungeonEntityData *pokemonData2 = pokemon->entityData;
    s32 maxHP = pokemonData->maxHP;
    if (maxHP < 0)
    {
        maxHP += 3;
    }
    if (pokemonData2->HP <= maxHP >> 2)
    {
        return TRUE;
    }
    return FALSE;
}
