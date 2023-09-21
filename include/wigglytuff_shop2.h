#ifndef GUARD_WIGGLYTUFF_SHOP2_H
#define GUARD_WIGGLYTUFF_SHOP2_H

#include "input.h"
#include "structs/str_text.h"

typedef struct WigglytuffShop2Work
{
    MenuInputStructSub unk0;
    /* 0xC */ u8 friendArea;
    bool8 unkD;
    s16 unkE[0x10];
    u32 unk30[0x10];
    /* 0x70 */ s32 numPokemoninFriendArea;
    s32 unk74;
    UnkTextStruct2 *unk78;
    UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
} WigglytuffShop2Work;

bool8 sub_8021774(u8 friendArea, bool8, s32);
u32 sub_80217EC(void);
void sub_8021830(void);

#endif // GUARD_WIGGLYTUFF_SHOP2_H