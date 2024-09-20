#include "global.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "cpu.h"
#include "sprite.h"

extern u8 gUnknown_2026E38;
extern u32 *gUnknown_2026E3C;
extern s32 gUnknown_2026E40;
extern s32 gUnknown_2026E44;
extern s32 gUnknown_2026E48;
extern bool8 gUnknown_2026E4C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 *gUnknown_2026E58;
extern s16 gUnknown_2026E60[];
extern s16 gUnknown_20270E8[];

extern s16 *gUnknown_203B078;

// data.s
extern const s16 gUnknown_80B8008[17];
extern const s16 gUnknown_80B802A[16 * 10];
extern const s16 gUnknown_80B816A[16 * 10];
extern const s16 gUnknown_80B82AA[16 * 10];
extern const s16 gUnknown_80B83EA[16 * 10];

// code_8009804.s
extern s32 sin_abs_4096(s32);
extern s32 cos_4096(s32);

static void sub_800561C(struct unkStructFor800561C *, s32, s32, u8 *);
s32 *sub_8005674(struct unkStructFor800561C *, s32);

void DoAxFrame_800558C(struct axPokemon *a0, s32 spriteX, s32 spriteY, u32 a3, u32 paletteNum, u16 *spriteMasks)
{
    if (!(a0->obj.axdata.flags >> 15))
        return;

    if (a0->obj.axdata.sub1.poseId < 0)
        RunAxAnimationFrame(a0);

    if (!(a0->obj.axdata.flags >> 15))
        return;

    a0->obj.axdata.sub1.xPos = a0->obj.axdata.sub1.xOffset + spriteX;
    a0->obj.axdata.sub1.yPos = a0->obj.axdata.sub1.yOffset + spriteY;
    a0->obj.axdata.sub1.paletteNum = paletteNum;
    a0->obj.axdata.sub1.unk16 = a3;
    sub_800533C(a0->obj.axdata.poseData, a0->obj.axdata.spriteData, &a0->obj.axdata.sub1, spriteMasks, !!(a0->obj.axdata.sub1.lastPoseId ^ a0->obj.axdata.sub1.poseId));
    a0->obj.axdata.sub1.lastPoseId = a0->obj.axdata.sub1.poseId;

    if (a0->obj.axdata.flags & 0x800)
        a0->obj.axdata.flags &= 0xF7FF;
}

void sub_8005610(OpenedFile *a0, s32 a1, s32 a2, u8 *a3)
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

UNUSED static s32 *sub_8005668(OpenedFile *a0, s32 a1)
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

    if (!(a1->obj.axdata.flags >> 15) || a2 >= 4)
        return;

    if (a1->obj.axdata.paletteData != NULL) {
        ptr = (s16 *)a1->obj.axdata.paletteData;
        ptr += a1->obj.axdata.sub1.poseId * 8;
        ptr2 = ptr + (a2 * 2);
        if (ptr2[0] == 99 && ptr2[1] == 99) {
            a0[0] = 99;
            a0[1] = 99;
        }
        else {
            ptr3 = ptr + (a2 * 2);
            a0[0] = a1->obj.axdata.sub1.xOffset + ptr3[0];
            a0[1] = a1->obj.axdata.sub1.yOffset + ptr3[1];
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

    if (!(a1->obj.axdata.flags >> 15))
        return;

    if (a1->obj.axdata.paletteData != NULL) {
        ptr = (s16 *)a1->obj.axdata.paletteData;
        ptr += a1->obj.axdata.sub1.poseId * 8;
        for (i = 0; i <= 6; i += 2) {
            if (ptr[i] == 99 && ptr[i + 1] == 99) {
                a0[0] = 99;
                a0[1] = 99;
            }
            else {
                a0[0] = a1->obj.axdata.sub1.xOffset + ptr[i];
                a0[1] = a1->obj.axdata.sub1.yOffset + ptr[i + 1];
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

UNUSED static void sub_8005764(s32 a0, OpenedFile *file, s32 a2, u8 *a3)
{
    sub_8005770(a0, file->data, a2, a3);
}

void sub_8005770(s32 param_1, u8 *colorArray, s32 a1, u8 *a2)
{
    s32 i;

    for (i = 0; i < 16; i++)
        SetBGPaletteBufferColorRGB((param_1 + 0x10) * 0x10 + i, &colorArray[i * 4], a1, a2);
}

// Maybe Position
void nullsub_7(s16 *a0)
{}

void nullsub_8(u32 a0)
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
    gUnknown_203B078 = NULL;
}

void sub_8005838(s32 *a0, u8 kind)
{
    const s16 *r1, *r2;
    s16 *r3;
    s32 i;

    if (!gUnknown_2026E4C)
        kind = 0;

    r3 = !gUnknown_2026E54 ? (s16 *) &gUnknown_2026E60 : (s16*) &gUnknown_20270E8;

    r2 = gUnknown_203B078;
    if (r2 == NULL)
        r2 = (void *) &gUnknown_80B83EA;

    gUnknown_2026E58 = (void *) r3;

    switch (kind) {
        case 0:
            for (i = 0; i < 10; i++) {
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
                *r3++ = *r2++;
                *r3++ = 0;
            }
            break;
        case 1:
            r1 = gUnknown_80B816A;
            for (i = 0; i < 10; i++) {
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
            }
            break;
        case 2:
            r1 = gUnknown_80B802A;
            for (i = 0; i < 10; i++) {
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
            }
            break;
        case 3:
            if ((a0[0] < 0 && a0[2] < 0)
                || (a0[1] < 0 && a0[3] < 0)
                || (a0[0] >= 240 && a0[2] >= 240)
                || (a0[1] >= 160 && a0[3] >= 160)) {
                for (i = 0; i < 10; i++) {
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                    *r3++ = *r2++;
                    *r3++ = 240;
                }
            }
            else {
                s32 iVar5;
                s32 r4;
                for (i = 0; i < 160; i++) {
                    if (a0[1] > i) {
                        *r3++ = *r2++;
                        *r3++ = 256;
                    }
                    else if (a0[3] <= i) {
                        *r3++ = *r2++;
                        *r3++ = 256;
                    }
                    else {
                        if (i - a0[1] < 16) {
                            r4 = a0[0] + gUnknown_80B8008[i - a0[1]];
                            iVar5 = a0[2] - gUnknown_80B8008[i - a0[1]];
                        }
                        else if (a0[3] - i < 16) {
                            r4 = a0[0] + gUnknown_80B8008[a0[3] - i];
                            iVar5 = a0[2] - gUnknown_80B8008[a0[3] - i];
                        }
                        else {
                            r4 = a0[0];
                            iVar5 = a0[2];
                        }

                        if (r4 < 0)
                            r4 = 0;
                        if (r4 > 240 - 1)
                            r4 = 240 - 1;

                        if (iVar5 < 1)
                            iVar5 = 1;
                        if (iVar5 > 240)
                            iVar5 = 240;

                        *r3++ = *r2++;
                        *r3++ = (iVar5 << 8) | r4;
                    }
                }
            }
            break;
        case 4:
            r1 = gUnknown_80B82AA;
            for (i = 0; i < 15; i++) {
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
                *r3++ = *r2++;
                *r3++ = *r1++;
            }
            break;
        case 5:
            for (i = 0; i < 15; i++) {
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
                *r3++ = *r2++;
                *r3++ = 256;
            }
            {
                s32 r8;
                s32 sp14;
                s32 uVar7; // r2
                s32 sp10;
                s32 iVar11; // r4

                s32 val1;
                s32 val2;
                s32 val3;
                s32 spC;

                s32 j, k;

                val1 = gUnknown_2026E40;
                val2 = gUnknown_2026E44;
                val3 = gUnknown_2026E48;

                spC = 0x400 / (val3 / 256 + 1);
                iVar11 = val2 / 256;

                k = iVar11;
                j = iVar11;
                for (sp10 = 0; sp10 < 0x400; sp10 += spC) {
                    s32 tmp1 = sin_abs_4096(sp10) * val3 / 256;

                    sp14 = (val2 + tmp1) / 256;
                    r8 = (val2 - tmp1) / 256;

                    if (j < sp14 || k > r8) {
                        s32 tmp2 = cos_4096(sp10) * val3 / 256;

                        s32 iVar5 = (val1 - tmp2) / 256;
                        s32 iVar3 = (val1 + tmp2) / 256;

                        if (iVar5 < 0)
                            iVar5 = 0;
                        if (iVar3 < 0)
                            iVar3 = 0;
                        if (iVar5 > 240 - 1)
                            iVar5 = 160 - 1;
                        if (iVar3 > 240 - 1)
                            iVar3 = 160 - 1;

                        if (iVar5 > iVar3)
                            uVar7 = (iVar5 << 8) | iVar3;
                        else
                            uVar7 = (iVar3 << 8) | iVar5;

                        for (; j < sp14; j++) {
                            if (j < 0)
                                continue;
                            if (j >= 160)
                                continue;

                            if (gUnknown_2026E54 == 0)
                                gUnknown_2026E60[j * 2 + 1] = uVar7;
                            else
                                gUnknown_20270E8[j * 2 + 1] = uVar7;
                        }

                        for (; k > r8; k--) {
                            if (k < 0)
                                continue;
                            if (k >= 160)
                                continue;

                            if (gUnknown_2026E54 == 0)
                                gUnknown_2026E60[k * 2 + 1] = uVar7;
                            else
                                gUnknown_20270E8[k * 2 + 1] = uVar7;
                        }
                    }
                }
            }
            break;
    }
}

UNUSED static void sub_80060A8(void)
{
    gUnknown_2026E3C = gUnknown_2026E58;
    gUnknown_2026E54 = !gUnknown_2026E54;
    gUnknown_2026E50 = !gUnknown_2026E50;
    gUnknown_2026E38 = FALSE;
}

void sub_80060EC(void)
{
    gUnknown_2026E3C = gUnknown_2026E58;
    gUnknown_2026E54 = !gUnknown_2026E54;
    gUnknown_2026E50 = !gUnknown_2026E50;
    SetBldAlphaReg((gUnknown_2026E4E & 0x1F00) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = TRUE;
}
