#include "global.h"
#include "dungeon_pokemon_attributes.h"

#include "dungeon_util.h"

bool8 HasAbility(struct DungeonEntity *pokemon, u8 ability)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        if (pokemonData->ability1 == ability || pokemonData->ability2 == ability)
        {
            return TRUE;
        }
        return FALSE;
    }
}
