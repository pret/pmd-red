#include "global.h"
#include "dungeon_ai_movement.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/tactic.h"
#include "dungeon_action.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_ai_movement_1.h"
#include "dungeon_ai_targeting_1.h"
#include "number_util.h"

extern bool8 CanTakeItem(struct DungeonEntity *pokemon);
extern bool8 ChooseTargetPosition(struct DungeonEntity *pokemon);
extern void DecideMovement(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);

void MoveIfPossible(struct DungeonEntity *pokemon, bool8 showRunAwayEffect)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    pokemonData->notAdjacentToTarget = FALSE;
    pokemonData->hasTarget = FALSE;
    pokemonData->turnAround = FALSE;
    if (HasTactic(pokemon, TACTIC_BE_PATIENT))
    {
        u32 maxHP = pokemonData->maxHP;
        maxHP += maxHP >> 0x1f;
        if (pokemonData->HP <= (s16) (maxHP / 2))
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
            return;
        }
    }
    if (HasTactic(pokemon, TACTIC_WAIT_THERE))
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (!pokemonData->isLeader && RoundUpFixedPoint(pokemonData->belly) == 0)
    {
        pokemonData->action.action = DUNGEON_ACTION_NONE;
    }
    else if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->targetPosition.x = pokemon->posWorld.x;
        pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
    }
    else
    {
        bool8 hasAction;
        if (ShouldAvoidEnemiesAndShowEffect(pokemon, showRunAwayEffect))
        {
            hasAction = AvoidEnemies(pokemon);
        }
        else if (CanTakeItem(pokemon))
        {
            pokemonData->action.action = DUNGEON_ACTION_TAKE_ITEM_AI;
            return;
        }
        else
        {
            hasAction = ChooseTargetPosition(pokemon);
        }
        if (!hasAction)
        {
            pokemonData->action.action = DUNGEON_ACTION_NONE;
        }
        else
        {
            DecideMovement(pokemon, showRunAwayEffect);
        }
    }
}
