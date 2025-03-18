#ifndef GUARD_CODE_800558C_H
#define GUARD_CODE_800558C_H

#include "structs/axdata.h"
#include "structs/rgb.h"

typedef struct Palette256
{
    RGB pal[256];
} Palette256;

// size: 0x20
struct EfoFileData
{
    /* 0x0 */ ax_pose **poses; // TODO: Verify if these fields' names are actually valid
    /* 0x4 */ ax_anim ***animations;
    /* 0x8 */ s32 animCount;
    /* 0xC */ void *spriteData; // ?
    /* 0x10 */ Palette256 *unk10; // ?
    /* 0x14 */ const u32 *tiles;
    /* 0x18 */ const RGB *pal;
    /* 0x1C */ s32 tileCount;
};

extern bool8 gUnknown_2026E38;
extern u32 *gUnknown_2026E3C;
extern s16 gUnknown_2026E4E;

extern s16 *gUnknown_203B078;

void nullsub_7(s16 *);
void nullsub_8(u32);
void nullsub_9(void);
void nullsub_10(bool8);
void nullsub_12(void);
void nullsub_13(void);
void nullsub_14(void);
void sub_8005610(OpenedFile *, s32, s32, const RGB *);
const RGB *sub_8005674(const struct EfoFileData *a0, s32 vramIdx);
void sub_8005770(s32, const RGB *color, s32, const RGB *ramp);
void sub_80057E8(void);
void sub_8005838(s32 *, u8 kind);
void sub_80060EC(void);

#endif // GUARD_CODE_800558C_H
