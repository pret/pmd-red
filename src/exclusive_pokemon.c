#include "global.h"
#include "constants/species.h"
#include "exclusive_pokemon.h"

const struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON] = {

    RED_EXCLUSIVE(SPECIES_PORYGON),
    BLUE_EXCLUSIVE(SPECIES_PORYGON2),
    BLUE_EXCLUSIVE(SPECIES_MAGIKARP),
    BLUE_EXCLUSIVE(SPECIES_GYARADOS),
    RED_EXCLUSIVE(SPECIES_FEEBAS),
    RED_EXCLUSIVE(SPECIES_MILOTIC),
    RED_EXCLUSIVE(SPECIES_PLUSLE),
    BLUE_EXCLUSIVE(SPECIES_MINUN),
    BLUE_EXCLUSIVE(SPECIES_LAPRAS),
    RED_EXCLUSIVE(SPECIES_MANTINE),
    RED_EXCLUSIVE(SPECIES_ROSELIA),
    BLUE_EXCLUSIVE(SPECIES_AIPOM),
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
extern struct ExclusivePokemonData gExclusivePokemonInfo;


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
