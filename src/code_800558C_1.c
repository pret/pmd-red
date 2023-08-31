#include "global.h"
#include "bg_palette_buffer.h"
#include "code_800558C_1.h"
#include "cpu.h"
#include "sprite.h"

extern u8 gUnknown_2026E38;
extern u32 *gUnknown_2026E3C;
extern bool8 gUnknown_2026E4C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 *gUnknown_2026E58;
extern u32 gUnknown_203B078;

static void sub_800561C(struct unkStructFor800561C *, s32, s32, u8 *);
s32 *sub_8005674(struct unkStructFor800561C *a0, s32 a1);

void DoAxFrame_800558C(struct axPokemon *a0, s32 spriteX, s32 spriteY, u32 a3, u32 paletteNum, u16 *spriteMasks)
{
    if (!(a0->axdata.flags >> 15))
        return;

    if (a0->axdata.sub1.poseId < 0)
        sub_80054BC(a0);

    if (!(a0->axdata.flags >> 15))
        return;

    a0->axdata.sub1.xPos = a0->axdata.sub1.xOffset + spriteX;
    a0->axdata.sub1.yPos = a0->axdata.sub1.yOffset + spriteY;
    a0->axdata.sub1.paletteNum = paletteNum;
    a0->axdata.sub1.unk16 = a3;
    sub_800533C(a0->axdata.poseData, a0->axdata.spriteData, &a0->axdata.sub1, spriteMasks, !!(a0->axdata.sub1.lastPoseId ^ a0->axdata.sub1.poseId));
    a0->axdata.sub1.lastPoseId = a0->axdata.sub1.poseId;

    if (a0->axdata.flags & 0x800)
        a0->axdata.flags &= 0xF7FF;
}

void sub_8005610(struct OpenedFile *a0, s32 a1, s32 a2, u8 *a3)
{
    sub_800561C((struct unkStructFor800561C *)a0->data, a1, a2, a3);
}

static void sub_800561C(struct unkStructFor800561C *a0, s32 a1, s32 a2, u8 *a3)
{
    s32 i;

    if (a0->unk14 != NULL)
        CpuCopy(OBJ_VRAM0 + a1 * 0x20, a0->unk14, a0->unk1C << 5);

    if (a0->unk18 != NULL) {
        for (i = 0; i < 16; i++)
            SetBGPaletteBufferColorRGB(i + 480, (u8 *)&a0->unk18[i], a2, a3);
    }
}

UNUSED static s32 *sub_8005668(struct OpenedFile *a0, s32 a1)
{
    return sub_8005674((struct unkStructFor800561C *)a0->data, a1);
}

s32 *sub_8005674(struct unkStructFor800561C *a0, s32 a1)
{
    if (a0->unk14 != NULL)
        CpuCopy(OBJ_VRAM0 + a1 * 0x20, a0->unk14, a0->unk1C << 5);

    return a0->unk18;
}

// a0 is an s16[2] and a1 is not confirmed to be (struct axPokemon *) yet
void sub_800569C(s16 *a0, struct axPokemon *a1, u8 a2)
{
    s16 *ptr;
    s16 *ptr2;
    s16 *ptr3;

    a0[0] = 0;
    a0[1] = 0;

    if (!(a1->axdata.flags >> 15) || a2 >= 4)
        return;

    if (a1->axdata.paletteData != NULL) {
        ptr = (s16 *)a1->axdata.paletteData;
        ptr += a1->axdata.sub1.poseId * 8;
        ptr2 = ptr + (a2 * 2);
        if (ptr2[0] == 99 && ptr2[1] == 99) {
            a0[0] = 99;
            a0[1] = 99;
        }
        else {
            ptr3 = ptr + (a2 * 2);
            a0[0] = a1->axdata.sub1.xOffset + ptr3[0];
            a0[1] = a1->axdata.sub1.yOffset + ptr3[1];
        }
    }
    else {
        a0[0] = 99;
        a0[1] = 99;
    }
}

// a0 is an s16[12] and a1 is not confirmed to be (struct axPokemon *) yet
void sub_8005700(s16 *a0, struct axPokemon *a1)
{
    s32 i;
    s16 *ptr;

    if (!(a1->axdata.flags >> 15))
        return;

    if (a1->axdata.paletteData != NULL) {
        ptr = (s16 *)a1->axdata.paletteData;
        ptr += a1->axdata.sub1.poseId * 8;
        for (i = 0; i <= 6; i += 2) {
            if (ptr[i] == 99 && ptr[i + 1] == 99) {
                a0[0] = 99;
                a0[1] = 99;
            }
            else {
                a0[0] = a1->axdata.sub1.xOffset + ptr[i];
                a0[1] = a1->axdata.sub1.yOffset + ptr[i + 1];
            }
            a0 += 2;
        }
    }
    else {
        for (i = 0; i < 4; i++) {
            a0[0] = 99;
            a0[1] = 99;
            a0 += 2;
        }
    }
}

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
    gUnknown_2026E4C = TRUE;
    gUnknown_2026E54 = FALSE;
    gUnknown_2026E50 = 1;
    gUnknown_2026E58 = NULL;
    gUnknown_2026E3C = NULL;
    gUnknown_2026E38 = 0;
    gUnknown_2026E4E = 0x60C;
    gUnknown_203B078 = 0;
}