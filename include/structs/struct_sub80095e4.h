#ifndef GUARD_struct_sub80095e4_H
#define GUARD_struct_sub80095e4_H

#include "structs/menu.h"
#include "structs/str_text.h"

s32 sub_80095E4(s32 a0, s32 a1);

// Struct related with sub_80095E4
typedef struct struct_Sub80095E4
{
    /* 0x0 */ MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    // size: 0x9C
} struct_Sub80095E4;

// Has 1 additional array.
// size: 0xA0
typedef struct struct_Sub80095E4_2
{
    /* 0x0 */ struct_Sub80095E4 s0; // s as in 'struct' ; decided to go against unk as to not have `->unk0->unk3C`
    UnkTextStruct2_sub2 unk9C;
} struct_Sub80095E4_2;

// Note: In order to get matching ASM, this macro had to be created.
// It's probable the code below is not exactly how it was originally written, but it generates the same asm.
#define SUB_80095E4_CALL(ptr)                                                           \
{                                                                                       \
    s16 a0 = sub_80095E4((ptr).input.unk1A, 12) + 2;                                    \
    UNUSED s32 a0_ = a0;                                                                \
    UNUSED s16 oldE = (ptr).unk3C[(ptr).unk34].unkE;                                    \
    UNUSED s32 new10 = a0 + 2;                                                          \
    s16 newE = a0;                                                                      \
                                                                                        \
    (ptr).unk3C[(ptr).unk34].unkE = newE;                                               \
    (ptr).unk3C[(ptr).unk34].unk10 = a0 + 2;                                            \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    sub_800641C((ptr).unk3C, TRUE, TRUE);                                               \
}

// For sub_801C440 and sub_8023420 where unkE and unk10 are the same.
#define SUB_80095E4_CALL_2(ptr)                                                         \
{                                                                                       \
    s32 a0 = sub_80095E4((ptr).input.unk1A, 12) + 2;                                    \
    UNUSED s16 oldE = (ptr).unk3C[(ptr).unk34].unkE;                                    \
    s16 newE = a0;                                                                      \
                                                                                        \
    (ptr).unk3C[(ptr).unk34].unkE = newE;                                               \
    (ptr).unk3C[(ptr).unk34].unk10 = newE;                                              \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    sub_800641C((ptr).unk3C, TRUE, TRUE);                                               \
}

#endif // GUARD_struct_sub80095e4_H
