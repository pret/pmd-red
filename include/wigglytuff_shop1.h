#ifndef GUARD_WIGGLYTUFF_SHOP1_H
#define GUARD_WIGGLYTUFF_SHOP1_H

#include "constants/friend_area.h"
#include "menu.h"
#include "text.h"

typedef struct WigglytuffShop1Work
{
    /* 0x0 */ u8 friendAreas[NUM_FRIEND_AREAS];
    /* 0x3C */ u32 mode;
    MenuInputStruct unk40;
    s32 unk74;
    UnkTextStruct2 *unk78;
    UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
} WigglytuffShop1Work;

bool8 sub_80211AC(u32 mode, u32);
u32 sub_8021274(bool8);
u8 sub_802132C(void);
void sub_8021354(bool8 cursorSprite);
void sub_80213A0(void);
void sub_8021494(void);
bool8 sub_8021700(u32 kind);

#endif // GUARD_WIGGLYTUFF_SHOP1_H