#ifndef GUARD_KECLEON_BROS4_H
#define GUARD_KECLEON_BROS4_H

#include "constants/item.h"
#include "structs/menu.h"
#include "structs/struct_sub80095e4.h"

// size: 0xF4
typedef struct unkStruct_203B224
{
    u32 unk0;
    u32 unk4[INVENTORY_SIZE];
    /* 0x54 */ struct_Sub80095E4_2 unk54;
} unkStruct_203B224;

bool8 sub_801A5D8(u32, s32, UnkTextStruct2_sub *, u32);
u32 sub_801A6E8(bool8);
s32 sub_801A8AC(void);
void sub_801A8D0(bool8);
void sub_801A928(void);
void sub_801A9E0(void);
void sub_801AD34(u32);
bool8 sub_801ADA0(s32);
void sub_801AE84(void);
s32 sub_801AEA8(void);
s32 sub_801AED0(s32 index);
void sub_801AEE4(s32 index, s32 value);

#endif // GUARD_KECLEON_BROS4_H
