#include "global.h"
#include "exclusive_pokemon.h"

const struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON] = {

    RED_EXCLUSIVE(MONSTER_PORYGON),
    BLUE_EXCLUSIVE(MONSTER_PORYGON2),
    BLUE_EXCLUSIVE(MONSTER_MAGIKARP),
    BLUE_EXCLUSIVE(MONSTER_GYARADOS),
    RED_EXCLUSIVE(MONSTER_FEEBAS),
    RED_EXCLUSIVE(MONSTER_MILOTIC),
    RED_EXCLUSIVE(MONSTER_PLUSLE),
    BLUE_EXCLUSIVE(MONSTER_MINUN),
    BLUE_EXCLUSIVE(MONSTER_LAPRAS),
    RED_EXCLUSIVE(MONSTER_MANTINE),
    RED_EXCLUSIVE(MONSTER_ROSELIA),
    BLUE_EXCLUSIVE(MONSTER_AIPOM),
};

const u8 filler_ex0[8] = 
{
    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};
const u8 filler_ex1[8] = 
{
    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};

extern struct ExclusivePokemonData *gUnknown_203B498;
EWRAM_DATA struct ExclusivePokemonData gExclusivePokemonInfo;


void LoadExclusivePokemon(void)
{
    gUnknown_203B498 = &gExclusivePokemonInfo;
}

struct ExclusivePokemonData *GetExclusivePokemon(void)
{
    return &gExclusivePokemonInfo;
}

void InitializeExclusivePokemon(void)
{
    s32 counter;
    memset(gUnknown_203B498, 0, sizeof(struct ExclusivePokemonData));
    for(counter = 0; counter < NUM_EXCLUSIVE_POKEMON; counter++)
    {
        gUnknown_203B498->Exclusives[counter] = gExclusivePokemon[counter].in_rrt;
    }
}
