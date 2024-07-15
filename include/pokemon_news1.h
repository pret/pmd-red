#ifndef GUARD_POKEMON_NEWS1_H
#define GUARD_POKEMON_NEWS1_H

#include "constants/wonder_mail.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/struct_sub80095e4.h"

// size: 0xD4;
struct unkStruct_203B2CC
{
    /* 0x0 */ u8 receivedNewsletters[NUM_POKEMON_NEWS];
    /* 0x38 */ struct_Sub80095E4 s38;
};

u8 GetPokemonNewsIndex(void);
bool8 HasNoPKMNNews(void);

bool8 sub_802B640(u32, UnkTextStruct2_sub *, u32);
u32 sub_802B720(bool8);
void sub_802B7D0(bool8 cursorSprite);
void sub_802B81C(void);

#endif // GUARD_POKEMON_NEWS1_H
