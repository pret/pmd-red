#include "global.h"
#include "dungeon_capabilities.h"

#include "constants/status.h"

bool8 CannotMove(struct Entity *pokemon, bool8 checkBlinker)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    if ((checkBlinker && pokemonInfo->eyesightStatus == STATUS_BLINKER)
        || pokemonInfo->sleep == STATUS_SLEEP
        || pokemonInfo->sleep == STATUS_NAPPING
        || pokemonInfo->sleep == STATUS_NIGHTMARE
        || pokemonInfo->volatileStatus == STATUS_PAUSED
        || pokemonInfo->volatileStatus == STATUS_INFATUATED
        || pokemonInfo->immobilizeStatus == STATUS_PETRIFIED)
    {
        return TRUE;
    }
    if (pokemonInfo->terrifiedTurns != 0)
    {
        return TRUE;
    }
    return FALSE;
}

