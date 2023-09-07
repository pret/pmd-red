#ifndef GUARD_CODE_801AFA4_H
#define GUARD_CODE_801AFA4_H

#include "global.h"
#include "constants/move.h"
#include "menu.h"
#include "pokemon.h"

// size: 0xA4
typedef struct unkStruct_203B22C
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u32 teamItemIndex;
    /* 0x8 */ u8 id; // item index
    /* 0xA */ u16 moveID; // item move??
    /* 0xC */ Move moves[MAX_MON_MOVES * 2];
    /* 0x4C */ s32 monsAbleToLearnMove; // number of party members able to learn move
    /* 0x50 */ s16 unk50[MAX_TEAM_MEMBERS]; // species IDs of each member able to learn move
    /* 0x58 */ s16 chosenPokemon; // species of pokemon that will learn move
    /* 0x5C */ PokemonStruct1 *pokeStruct; // PokemonStruct of said pokemon
    u32 unk60;
    /* 0x64 */ MenuItem menuItems[8];
} unkStruct_203B22C;

bool8 sub_801AFA4(u32);
u32 sub_801B00C(void);
void sub_801B048(void);

#endif // GUARD_CODE_801AFA4_H