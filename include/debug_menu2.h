#ifndef GUARD_DEBUG_MENU2_H
#define GUARD_DEBUG_MENU2_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x138
typedef struct unkStruct_203B3F0
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u8 id;
    /* 0x8 */ u32 menuAction;
    /* 0xC */ MenuItem menuItems[8];
    MenuStruct unk4C;
    unkStructFor8013AA0 unk9C;
    u8 fillCC[0xD8 - 0xCC];
    WindowTemplates unkD8;
} unkStruct_203B3F0;

#endif // GUARD_DEBUG_MENU2_H
