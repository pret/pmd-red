#include "global.h"
#include "bg_palette_buffer.h"
#include "code_800558C_1.h"
#include "file_system.h"

extern u8 gUnknown_2026E38;
extern u32 gUnknown_2026E3C;
extern u8 gUnknown_2026E4C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 gUnknown_2026E58;
extern u32 gUnknown_203B078;

UNUSED static void sub_8005764(s32 a0, struct OpenedFile *file, s32 a2, u8 *a3)
{
    sub_8005770(a0, file->data, a2, a3);
}

void sub_8005770(s32 param_1, u8 *RGBArray, s32 a1, u8 *a2)
{
    s32 i;

    for (i = 0; i < 16; i++)
        SetBGPaletteBufferColorRGB((param_1 + 0x10) * 0x10 + i, &RGBArray[i * 4], a1, a2);
}

// Maybe struct Position
void nullsub_7(s16 *a0)
{}

void nullsub_8(void)
{}

void nullsub_9(void)
{}

void nullsub_10(bool8 a0)
{}

UNUSED static void nullsub_144(void)
{}

void nullsub_11(void)
{}

void nullsub_12(void)
{}

void nullsub_13(void)
{}

UNUSED static void nullsub_145(void)
{}

void nullsub_14(void)
{}

UNUSED static void nullsub_146(void)
{}

UNUSED static void nullsub_147(void)
{}

UNUSED static void nullsub_148(void)
{}

UNUSED static void nullsub_149(void)
{}

UNUSED static bool8 sub_80057D8(void)
{
    return FALSE;
}

UNUSED static bool8 sub_80057DC(void)
{
    return FALSE;
}

UNUSED static void nullsub_150(void)
{}

UNUSED static void nullsub_151(void)
{}

void sub_80057E8(void)
{
    gUnknown_2026E4C = 1;
    gUnknown_2026E54 = 0;
    gUnknown_2026E50 = 1;
    gUnknown_2026E58 = 0;
    gUnknown_2026E3C = 0;
    gUnknown_2026E38 = 0;
    gUnknown_2026E4E = 0x60C;
    gUnknown_203B078 = 0;
}