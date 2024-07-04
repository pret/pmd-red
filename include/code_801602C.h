#ifndef GUARD_CODE_801602C_H
#define GUARD_CODE_801602C_H

#include "structs/menu.h"

// size: 0x50
struct unkStruct_203B200
{
    u32 unk0;
    u32 unk4;
    /* 0x8 */ u8 *pokeName;
    /* 0xC */ s32 state;
    /* 0x10 */ MenuItem menus[8];
};

u32 CreateConfirmNameMenu(u32 mode, u8 *name);
u32 sub_8016080(void);
void CleanConfirmNameMenu(void);

enum ConfirmNameMenuStates
{
    CONFIRM_NAME_MENU_INIT,
    CONFIRM_NAME_MENU_PROMPT,
    CONFIRM_NAME_MENU_TOO_LONG,
    CONFIRM_NAME_MENU_EMPTY,
    CONFIRM_NAME_MENU_EXIT = 4
};

#endif // GUARD_CODE_801602C_H
