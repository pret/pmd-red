#include "global.h"
#include "dungeon_pokemon_attributes_1.h"

#include "constants/tactic.h"

bool8 HasTactic(struct DungeonEntity *pokemon, u8 tactic)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->isLeader)
    {
        bool8 isGoTheOtherWay = tactic == TACTIC_GO_THE_OTHER_WAY;
        return isGoTheOtherWay;
    }
    return pokemonData->tactic == tactic;
}
