#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "input.h"

// size: 0x8
typedef struct MenuItem
{
    const u8 *text;
    s32 menuAction; // action??
} MenuItem;

// size: 0x50
typedef struct MenuStruct
{
    const u8 *unk0; // header text?
    /* 0x4 */ const MenuItem *menuItems;
    const u32 *menuTextColorArray;
    u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ MenuInputStruct input;
    /* 0x48 */ s32 menuAction;
    bool8 unk4C;
    bool8 unk4D;
    bool8 unk4E;
} MenuStruct;

#endif // GUARD_MENU_H
