#include "global.h"
#include "dungeon_ai.h"

#include "constants/ability.h"
#include "constants/tactic.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_util.h"

bool8 ShouldAvoidEnemies(struct DungeonEntity *pokemon)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        if (pokemonData->terrifiedTurnsLeft != 0)
        {
            return TRUE;
        }
        if (pokemonData->isLeader)
        {
            return FALSE;
        }
        if (HasAbility(pokemon, ABILITY_RUN_AWAY))
        {
            bool8 runAwayActive = pokemonData->HP < pokemonData->maxHP / 2;
            if (runAwayActive)
            {
                return TRUE;
            }
        }
        if (HasTactic(pokemon, TACTIC_GET_AWAY)
            || (HasTactic(pokemon, TACTIC_AVOID_TROUBLE) && pokemonData->HP <= pokemonData->maxHP / 2))
        {
            return TRUE;
        }
        return FALSE;
    }
}
