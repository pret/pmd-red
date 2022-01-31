#include "global.h"
#include "status_checks.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "dungeon_action.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_random.h"

extern char *gPtrFrozenMessage;
extern char *gPtrWrappedAroundMessage;
extern char *gPtrWrappedByMessage;
extern char *gPtrBideMessage;
extern char *gPtrPausedMessage;
extern char *gPtrInfatuatedMessage;
extern char gAvailablePokemonNames[];

extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void DecideAttack(struct DungeonEntity*);

bool8 HasStatusAffectingActions(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
    SetAction(&pokemonData->action, DUNGEON_ACTION_WAIT);
    switch (pokemonData->sleepStatus)
    {
        case SLEEP_STATUS_NIGHTMARE:
        case SLEEP_STATUS_SLEEP:
        case SLEEP_STATUS_NAPPING:
            return TRUE;
    }
    switch (pokemonData->immobilizeStatus)
    {
        case IMMOBILIZE_STATUS_FROZEN:
            SendMessage(pokemon, gPtrFrozenMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE:
            SendMessage(pokemon, gPtrWrappedAroundMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_WRAPPED_BY_FOE:
            SendMessage(pokemon, gPtrWrappedByMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_PETRIFIED:
            return TRUE;
    }
    switch (pokemonData->volatileStatus)
    {
        case VOLATILE_STATUS_PAUSED:
            SendMessage(pokemon, gPtrPausedMessage);
            return TRUE;
        case VOLATILE_STATUS_INFATUATED:
            SendMessage(pokemon, gPtrInfatuatedMessage);
            return TRUE;
    }
    if (pokemonData->chargingStatus == CHARGING_STATUS_BIDE)
    {
        SendMessage(pokemon, gPtrBideMessage);
        return TRUE;
    }
    if (pokemonData->waitingStatus == WAITING_STATUS_DECOY)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->targetPosition.x = pokemon->posWorld.x;
        pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
        return TRUE;
    }
    if (pokemonData->shopkeeperMode == SHOPKEEPER_FRIENDLY)
    {
        return TRUE;
    }
    if (pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER)
    {
        if (!CanMoveInDirection(pokemon, pokemonData->action.facingDir))
        {
            if (DungeonRandomCapped(2) != 0)
            {
                pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
                pokemonData->action.facingDir = pokemonData->action.facingDir & DIRECTION_MASK;
                goto walk;
            }
        }
        else
        {
            walk:
            SetWalkAction(&pokemonData->action, pokemonData->entityID);
            return TRUE;
        }
        DecideAttack(pokemon);
        return TRUE;
    }
    if (pokemonData->eyesightStatus == EYESIGHT_STATUS_CROSS_EYED)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        return TRUE;
    }
    return FALSE;
}
