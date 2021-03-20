#ifndef EXCLUSIVE_POKEMON_H
#define EXCLUSIVE_POKEMON_H

#define NUM_EXCLUSIVE_POKEMON 12

struct ExclusivePokemon
{
    u16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};

struct unkStruct_203B498
{
    u8 fill0[0x58];
    bool8 Exclusives[NUM_EXCLUSIVE_POKEMON];
};

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


void LoadExclusivePokemon(void);
struct unkStruct_203B498 *GetExclusivePokemon(void);
void InitializeExclusivePokemon(void);

#endif // EXCLUSIVE_POKEMON_H
