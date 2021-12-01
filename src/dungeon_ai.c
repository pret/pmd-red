#include "global.h"
#include "dungeon_ai.h"

#include "constants/ability.h"
#include "constants/tactic.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_util.h"

extern void CheckRunAwayVisualFlag(struct DungeonEntity *, u8 r1);

bool8 ShouldAvoidFirstHit(struct DungeonEntity *pokemon, bool8 forceAvoid)
{
    if(!HasTactic(pokemon, TACTIC_AVOID_THE_FIRST_HIT))
        return FALSE;
    if(!forceAvoid)
        return FALSE;
    return TRUE;
}

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

bool8 ShouldAvoidEnemies_2(struct DungeonEntity *pokemon, u8 r1)
{
    if(ShouldAvoidEnemies(pokemon))
    {
        CheckRunAwayVisualFlag(pokemon, r1);
        return TRUE;
    }
    return FALSE;
}
