#ifndef GUARD_DEBUG_MENU3_H
#define GUARD_DEBUG_MENU3_H

#include "menu.h"
#include "text.h"

// size: 0xFC
struct unkStruct_203B3F4
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u8 friendArea;
    /* 0x8 */ u32 menuAction;
    /* 0xC */ struct MenuItem menuItems[8];
    struct MenuStruct unk4C;
    struct UnkTextStruct2 unk9C[4];
};

#endif // GUARD_DEBUG_MENU3_H