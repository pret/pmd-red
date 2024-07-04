#ifndef GUARD_WIGGLYTUFF_SHOP2_H
#define GUARD_WIGGLYTUFF_SHOP2_H

#include "structs/menu.h"
#include "structs/str_text.h"

typedef struct WigglytuffShop2Work
{
    MenuInputStructSub unk0;
    /* 0xC */ u8 friendArea;
    bool8 unkD;
    s16 friendAreaSpecies[0x10];
    u32 pokemonStatus[0x10];
    /* 0x70 */ s32 numPokemoninFriendArea;
    s32 unk74;
    UnkTextStruct2 *unk78;
    UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
} WigglytuffShop2Work;

bool8 CreateWigglytuffShopFriendAreaMenu(u8 friendArea, bool8, s32);
u32 HandleWigglytuffShopFriendAreaMenuInput(void);
void CleanWigglytuffShopFriendAreaInfoMenu(void);

enum WigglytuffShop2FriendAreaPokemonStatus
{
    POKEMON_UNKNOWN,
    POKEMON_SEEN,
    POKEMON_RECRUITED,
};

#endif // GUARD_WIGGLYTUFF_SHOP2_H
