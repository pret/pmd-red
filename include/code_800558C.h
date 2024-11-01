#ifndef GUARD_CODE_800558C_H
#define GUARD_CODE_800558C_H

#include "structs/rgb.h"
#include "structs/axdata.h"
#include "file_system.h"

// size: ? 0x20 for now
struct axMapSprite
{
    axmain axmain;
    const u32 *tiles;
    const Rgb32 *pal;
    s32 tileCount;
};

extern s16 *gUnknown_203B078;

void nullsub_7(s16 *);
void nullsub_8(u32);
void nullsub_9(void);
void nullsub_10(bool8);
void nullsub_12(void);
void nullsub_13(void);
void nullsub_14(void);
void sub_8005610(OpenedFile *, s32, s32, const Rgb32 *);
void sub_8005770(s32, const Rgb32 *color, s32, const Rgb32 *ramp);
void sub_80057E8(void);
void sub_8005838(s32 *, u8 kind);
void sub_80060EC(void);

#endif // GUARD_CODE_800558C_H
