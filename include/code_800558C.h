#ifndef GUARD_CODE_800558C_H
#define GUARD_CODE_800558C_H

#include "file_system.h"

// size: ? 0x20 for now
struct unkStructFor800561C
{
    u8 fill0[0x14 - 0x0];
    void *unk14;
    s32 *unk18;
    s32 unk1C;
};

extern s16 *gUnknown_203B078;

void nullsub_7(s16 *);
void nullsub_9(void);
void nullsub_10(bool8);
void nullsub_12(void);
void nullsub_13(void);
void nullsub_14(void);
void sub_8005610(OpenedFile *, s32, s32, u8 *);
void sub_8005770(s32, u8 *, s32, u8 *);
void sub_80057E8(void);
void sub_8005838(s32 *, u8);
void sub_80060EC(void);

#endif // GUARD_CODE_800558C_H