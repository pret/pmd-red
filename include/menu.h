#ifndef GUARD_MENU_H
#define GUARD_MENU_H

struct MenuItem
{
    const u8 *text;
    s32 menuAction; // action??
};

struct MenuStruct
{
    // size: 0x50
    u8 *unk0;
    /* 0x4 */ struct MenuItem *menuItems;
    const u32 *menuTextColorArray;
    u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ u32 unk14;
    u8 fill18[0x2C - 0x18];
    /* 0x2C */ s16 menuIndex;
    s16 unk2E;
    u8 fill30[0x38 - 0x30];
    u16 unk38;
    u8 fill3A[0x48 - 0x3A];
    /* 0x48 */ s32 menuAction;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
};

#endif // GUARD_MENU_H
