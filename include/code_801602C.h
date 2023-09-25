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
    /* 0x10 */ MenuItem menus[3];
    u8 fill[0x50 - 0x28];
};

u32 sub_801602C(u32 mode, u8 *name);
u32 sub_8016080(void);
void sub_80160D8(void);

#endif // GUARD_CODE_801602C_H