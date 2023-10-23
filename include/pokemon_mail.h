#ifndef POKEMON_MAIL_H
#define POKEMON_MAIL_H

#include "structs/str_802C39C.h"

// size: 0x8
typedef struct PokemonMail
{
    const u8 *headline;
    const u8 *text;
} PokemonMail;

// size: 0x8
typedef struct unkStruct_80E9920
{
    /* 0x0 */ s16 parentSpecies;
    /* 0x2 */ s16 childSpecies;
    /* 0x4 */ const u8 *text;
} unkStruct_80E9920;

// size: 0xC
typedef struct unkStruct_80E9F8C
{
    /* 0x0 */ s16 speciesA;
    /* 0x2 */ s16 speciesB;
    /* 0x4 */ const u8 *headline;
    /* 0x8 */ const u8 *text;
} unkStruct_80E9F8C;

#define NUM_POKEMON_MAIL 56

void CreateRescueDescription(unkStruct_802C39C *);
void CreateRescueTitle(unkStruct_802C39C *);
const u8 *GetPokemonMailHeadline(u8 index);
const u8 *GetPokemonMailText(u8 index);

void sub_803B6B0(s32 x, s32 y, u8 index, u32);
bool8 sub_803C0DC(s16 species);
bool8 sub_803C110(s16 index);

#endif // POKEMON_MAIL_H
