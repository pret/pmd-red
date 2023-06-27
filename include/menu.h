#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "input.h"

struct MenuItem
{
    const u8 *text;
    s32 menuAction; // action??
};

struct MenuStruct
{
    // size: 0x50
    const u8 *unk0; // header text?
    /* 0x4 */ const struct MenuItem *menuItems;
    const u32 *menuTextColorArray;
    u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ struct UnkInputStruct input;
    /* 0x48 */ s32 menuAction;
    bool8 unk4C;
    bool8 unk4D;
    bool8 unk4E;
};

#endif // GUARD_MENU_H
