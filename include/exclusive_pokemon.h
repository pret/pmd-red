#ifndef GUARD_EXCLUSIVE_POKEMON_H
#define GUARD_EXCLUSIVE_POKEMON_H

#include "code_8092334.h"


#define NUM_EXCLUSIVE_POKEMON 12

struct ExclusivePokemon
{
    s16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};

struct ExclusivePokemonData
{
    u8 fill0[0x48];
    u32 unk48[4];
    /* 0x58 */ bool8 Exclusives[NUM_EXCLUSIVE_POKEMON];
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

extern struct ExclusivePokemonData *gUnknown_203B498;

void LoadExclusivePokemon(void);
struct ExclusivePokemonData *GetExclusivePokemon(void);
void InitializeExclusivePokemon(void);
bool8 IsExclusivePokemonUnlocked(s16 pokeID);
void UnlockExclusivePokemon(s16 pokeID);
void WriteExclusivePokemon(struct unkStruct_8094924 *r0);
void ReadExclusivePokemon(struct unkStruct_8094924 *r0);

#endif // GUARD_EXCLUSIVE_POKEMON_H
