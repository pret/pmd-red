#include "global.h"
#include "dungeon_capabilities.h"

#include "constants/status.h"
#include "charge_move.h"
#include "dungeon_ai_targeting.h"

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
        return TRUE;

    if (pokemonInfo->terrifiedTurns != 0)
        return TRUE;

    return FALSE;
}

bool8 sub_8070BC0(struct Entity* entity)
{
    struct EntityInfo *entityInfo = entity->info;

    if (IsCharging(entity, FALSE)
        || entityInfo->sleep == STATUS_YAWNING
        || entityInfo->sleep == STATUS_NIGHTMARE
        || ShouldMonsterRunAway(entity)
        || entityInfo->muzzled == TRUE
        || entityInfo->immobilizeStatus == STATUS_PETRIFIED
        || entityInfo->immobilizeStatus == STATUS_FROZEN)
        return FALSE;

    if (entityInfo->volatileStatus == STATUS_CONFUSED)
        return FALSE;
    if (entityInfo->sleep == STATUS_SLEEP)
        return FALSE;
    if (entityInfo->transformStatus == STATUS_INVISIBLE
        || entityInfo->sleep == STATUS_NAPPING)
        return FALSE;
    if (entityInfo->volatileStatus == STATUS_CRINGE)
        return FALSE;
    if (entityInfo->immobilizeStatus == STATUS_WRAP)
        return FALSE;
    if (entityInfo->immobilizeStatus == STATUS_WRAPPED
        || entityInfo->eyesightStatus == STATUS_CROSS_EYED)
        return FALSE;
    if (entityInfo->waitingStatus == STATUS_DECOY)
        return FALSE;
    if (entityInfo->eyesightStatus == STATUS_BLINKER)
        return FALSE;
    if (entityInfo->volatileStatus != STATUS_INFATUATED
        && entityInfo->volatileStatus != STATUS_PAUSED)
        return TRUE;
        
    return FALSE;
}