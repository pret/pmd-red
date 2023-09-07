#ifndef GUARD_KECLEON_BROS2_H
#define GUARD_KECLEON_BROS2_H

#include "input.h"
#include "text.h"

// size: 0xA0
struct unkStruct_203B214
{
    /* 0x0 */ MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

bool8 sub_8019E40(u32);
u32 sub_8019EDC(u8);
u8 sub_8019FB0(void);
void sub_8019FCC(bool8);
void sub_801A010(void);
void sub_801A0D8(void);

#endif // GUARD_KECLEON_BROS2_H