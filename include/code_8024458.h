#ifndef GUARD_CODE_8024458_H
#define GUARD_CODE_8024458_H

#include "input.h"
#include "structs/str_text.h"

struct unkStruct_203B2AC
{
    MenuInputStruct input;
    u32 unk34[3];
    u8 unk40[0x48 - 0x40];
    s16 speciesNum;
    u32 unk4C;
    u8 unk50[0xB0 - 0x50];
    u32 unkB0;
    u8 fillB4[0xE0 - 0xB4];
    u32 unkE0;
    UnkTextStruct2 *unkE4;
    UnkTextStruct2 unkE8[4];
    u8 unk148[4];
};

bool8 sub_8024458(s16 speciesNum, s32);
u32 sub_80244E4(void);
void sub_802452C(void);
void sub_802453C(void);

#endif // GUARD_CODE_8024458_H