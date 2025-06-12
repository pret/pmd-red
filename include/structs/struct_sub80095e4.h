#ifndef GUARD_struct_sub80095e4_H
#define GUARD_struct_sub80095e4_H

#include "structs/menu.h"
#include "structs/str_text.h"

#include "text_1.h"
#include "text_3.h"

// Struct related with sub_80095E4
// size: R=0x9C | B=?
typedef struct struct_Sub80095E4
{
    /* 0x0 */ MenuInputStruct input;
    /* 0x34 */ u32 winId;
    /* 0x38 */ WindowTemplate *unk38;
    /* 0x3C */ WindowTemplates windows;
} struct_Sub80095E4;

// Has 1 additional array
// size: R=0xA0 | B=0x9C?
typedef struct struct_Sub80095E4_2
{
    /* 0x0 */ struct_Sub80095E4 s0; // s as in 'struct' ; decided to go against unk as to not have `->unk0->unk3C`
    /* 0x9C */ WindowHeader header;
} struct_Sub80095E4_2;

// Note: In order to get matching ASM, this macro had to be created.
// It's probable the code below is not exactly how it was originally written, but it generates the same asm.
#define SUB_8009_MATCH(ptr, _a0)                                                        \
{                                                                                       \
    UNUSED s32 new10;                                                                   \
    s16 newE;                                                                           \
    s16 a0 = (_a0);                                                                     \
    UNUSED s32 a0_ = a0;                                                                \
    UNUSED s16 oldE = (ptr).windows.id[(ptr).winId].height;                             \
    a0_ = 0;                                                                            \
    new10 = a0 + 2;                                                                     \
    newE = a0;                                                                          \
                                                                                        \
    (ptr).windows.id[(ptr).winId].height = newE;                                        \
    (ptr).windows.id[(ptr).winId].unk10 = a0 + 2;                                       \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    ShowWindows(&(ptr).windows, TRUE, TRUE);                                            \
}

#define SUB_80095E4_CALL(ptr)                                                           \
{                                                                                       \
    SUB_8009_MATCH(ptr, sub_80095E4((ptr).input.currPageEntries, 12) + 2)               \
}

// For sub_801C440 and sub_8023420 where unkE and unk10 are the same.
#define SUB_80095E4_CALL_2(ptr)                                                         \
{                                                                                       \
    s32 a0 = sub_80095E4((ptr).input.currPageEntries, 12) + 2;                          \
    UNUSED s16 oldE = (ptr).windows.id[(ptr).winId].height;                             \
    s16 newE = a0;                                                                      \
                                                                                        \
    (ptr).windows.id[(ptr).winId].height = newE;                                        \
    (ptr).windows.id[(ptr).winId].unk10 = newE;                                         \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    ShowWindows(&(ptr).windows, TRUE, TRUE);                                            \
}

// sub_802BF30 and sub_802C328 use a different function call, and 24 instead of 12
#define SUB_8009614_CALL(ptr)                                                           \
{                                                                                       \
    SUB_8009_MATCH(ptr, sub_8009614((ptr).input.currPageEntries, 24) + 2)               \
}

#endif // GUARD_struct_sub80095e4_H
