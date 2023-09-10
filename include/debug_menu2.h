#ifndef GUARD_DEBUG_MENU2_H
#define GUARD_DEBUG_MENU2_H

#include "menu.h"
#include "text.h"

// size: 0x138
struct unkStruct_203B3F0
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u8 id;
    /* 0x8 */ u32 menuAction;
    /* 0xC */ MenuItem menuItems[8];
    MenuStruct unk4C;
    u32 unk9C;
    u32 unkA0;
    u32 unkA4;
    u32 unkA8;
    u32 unkAC;
    u32 unkB0;
    UnkTextStruct2 *unkB4;
    u32 unkB8;
    u32 unkBC;
    u8 fill4[0xD8 - 0xC0];
    UnkTextStruct2 unkD8[4];
};

#endif // GUARD_DEBUG_MENU2_H