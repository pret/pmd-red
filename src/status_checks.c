#include "global.h"
#include "status_checks.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_random.h"

const s16 gConfusedAttackChance = 70;

extern char *gPtrFrozenMessage;
extern char *gPtrWrappedAroundMessage;
extern char *gPtrWrappedByMessage;
extern char *gPtrBideMessage;
extern char *gPtrPausedMessage;
extern char *gPtrInfatuatedMessage;
extern char gAvailablePokemonNames[];

extern void SetMessageArgument(char[], struct Entity*, u32);

bool8 HasStatusAffectingActions(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
    SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
    switch (pokemonInfo->sleep)
    {
        case STATUS_NIGHTMARE:
        case STATUS_SLEEP:
        case STATUS_NAPPING:
            return TRUE;
    }
    switch (pokemonInfo->immobilizeStatus)
    {
        case STATUS_FROZEN:
            SendMessage(pokemon, gPtrFrozenMessage);
            return TRUE;
        case STATUS_WRAP:
            SendMessage(pokemon, gPtrWrappedAroundMessage);
            return TRUE;
        case STATUS_WRAPPED:
            SendMessage(pokemon, gPtrWrappedByMessage);
            return TRUE;
        case STATUS_PETRIFIED:
            return TRUE;
    }
    switch (pokemonInfo->volatileStatus)
    {
        case STATUS_PAUSED:
            SendMessage(pokemon, gPtrPausedMessage);
            return TRUE;
        case STATUS_INFATUATED:
            SendMessage(pokemon, gPtrInfatuatedMessage);
            return TRUE;
    }
    if (pokemonInfo->chargingStatus == STATUS_BIDE)
    {
        SendMessage(pokemon, gPtrBideMessage);
        return TRUE;
    }
    if (pokemonInfo->waitingStatus == STATUS_DECOY)
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        pokemonInfo->targetPos.x = pokemon->pos.x;
        pokemonInfo->targetPos.y = pokemon->pos.y - 1;
        return TRUE;
    }
    if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER)
    {
        return TRUE;
    }
    if (pokemonInfo->eyesightStatus == STATUS_BLINKER)
    {
        if (!CanMoveInDirection(pokemon, pokemonInfo->action.direction))
        {
            if (DungeonRandInt(2) != 0)
            {
                pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
                pokemonInfo->action.direction = pokemonInfo->action.direction & DIRECTION_MASK;
                goto walk;
            }
        }
        else
        {
            walk:
            SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
            return TRUE;
        }
        DecideAttack(pokemon);
        return TRUE;
    }
    if (pokemonInfo->eyesightStatus == STATUS_CROSS_EYED)
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        return TRUE;
    }
    return FALSE;
}
