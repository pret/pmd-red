#ifndef GUARD_DEBUG_MENU4_H
#define GUARD_DEBUG_MENU4_H

#include "pokemon.h"
#include "menu.h"
#include "text.h"

// size: 0x140
typedef struct unkStruct_203B3F8
{
    /* 0x0 */ u32 state;
    s16 unk4;
    u16 unk6;
    /* 0x8 */ PokemonStruct1 *pokemon;
    /* 0xC */ u32 menuAction;
    MenuStruct unk10;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    UnkTextStruct2 *unk78;
    u32 unk7C;
    u32 unk80;
    u8 fill84[0x90 - 0x84];
    MenuItem unk90[8];
    u16 unkD0[8];
    UnkTextStruct2 unkE0[4];
} unkStruct_203B3F8;

#endif // GUARD_DEBUG_MENU4_H