#ifndef GUARD_DEBUG_MENU4_H
#define GUARD_DEBUG_MENU4_H

#include "pokemon.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x140
typedef struct unkStruct_203B3F8
{
    /* 0x0 */ u32 state;
    s16 unk4;
    u16 unk6;
    /* 0x8 */ PokemonStruct1 *pokemon;
    /* 0xC */ u32 menuAction;
    MenuStruct unk10;
    unkStructFor8013AA0 unk60;
    MenuItem unk90[8];
    u16 unkD0[8];
    UnkTextStruct3 unkE0;
} unkStruct_203B3F8;

#endif // GUARD_DEBUG_MENU4_H
