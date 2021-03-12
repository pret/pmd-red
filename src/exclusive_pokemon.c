#include "global.h"
#include "constants/species.h"
#define NUM_EXCLUSIVE_POKEMON 12

#define RED_EXCLUSIVE(species)  \
{                               \
    .poke_id = species,         \
    .in_rrt = TRUE,             \
    .in_brt = FALSE,            \
}

#define BLUE_EXCLUSIVE(species) \
{                               \
    .poke_id = species,         \
    .in_rrt = FALSE,            \
    .in_brt = TRUE,             \
}


struct ExclusivePokemon
{
    u16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};

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


struct unkStruct_203B498
{
    u8 fill0[0x58];
    bool8 Exclusives[NUM_EXCLUSIVE_POKEMON];
};
extern struct unkStruct_203B498 *gUnknown_203B498;
extern struct unkStruct_203B498 gUnknown_2039840;


void LoadExclusivePokemon(void)
{
    gUnknown_203B498 = &gUnknown_2039840;
}

struct unkStruct_203B498 *GetExclusivePokemon(void)
{
    return &gUnknown_2039840;
}

void InitializeExclusivePokemon(void)
{
    s32 counter;
    memset(gUnknown_203B498, 0, sizeof(struct unkStruct_203B498));
    for(counter = 0; counter < NUM_EXCLUSIVE_POKEMON; counter++)
    {
        gUnknown_203B498->Exclusives[counter] = gExclusivePokemon[counter].in_rrt;
    }
}
