#ifndef GUARD_DEBUG_MENU3_H
#define GUARD_DEBUG_MENU3_H

#include "menu.h"
#include "structs/str_text.h"

// size: 0xFC
typedef struct unkStruct_203B3F4
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u8 friendArea;
    /* 0x8 */ u32 menuAction;
    /* 0xC */ MenuItem menuItems[8];
    MenuStruct unk4C;
    UnkTextStruct2 unk9C[4];
} unkStruct_203B3F4;

#endif // GUARD_DEBUG_MENU3_H