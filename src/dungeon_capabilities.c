#include "global.h"
#include "dungeon_capabilities.h"

#include "constants/status.h"

bool8 CannotMove(struct DungeonEntity *pokemon, bool8 checkBlinker)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if ((checkBlinker && pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER)
        || pokemonData->sleepStatus == SLEEP_STATUS_SLEEP
        || pokemonData->sleepStatus == SLEEP_STATUS_NAPPING
        || pokemonData->sleepStatus == SLEEP_STATUS_NIGHTMARE
        || pokemonData->volatileStatus == VOLATILE_STATUS_PAUSED
        || pokemonData->volatileStatus == VOLATILE_STATUS_INFATUATED
        || pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
    {
        return TRUE;
    }
    if (pokemonData->terrifiedTurnsLeft != 0)
    {
        return TRUE;
    }
    return FALSE;
}

