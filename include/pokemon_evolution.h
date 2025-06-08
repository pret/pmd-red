#ifndef GUARD_POKEMON_EVOLUTION_H
#define GUARD_POKEMON_EVOLUTION_H

#include "structs/str_pokemon.h"

// size: 0x8
typedef struct EvolveStatus
{
    /* 0x0 */ u8 evoItem1;
    /* 0x1 */ u8 evoItem2;
    // This value is set to a random number in the range [0, 254].
    // Even values produce Silcoon while odd values produce Cascoon.
    /* 0x2 */ u8 wurmpleVal;
    /* 0x4 */ u16 evolutionConditionStatus;
    /* 0x6 */ s16 targetEvolveSpecies;
} EvolveStatus;

void sub_808F468(struct PokemonStruct1 *pokemon, EvolveStatus *evolveStatus,bool8 param_3);
s32 sub_808F700(PokemonStruct1 *pokemon);
PokemonStruct1 *sub_808F734(PokemonStruct1 *pokemon, s16 _species);
PokemonStruct1 *sub_808F798(PokemonStruct1 *pokemon, s16 _species);

#endif // GUARD_POKEMON_EVOLUTION_H
