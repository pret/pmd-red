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
    gUnknown_203B078 = NULL;
}

#ifdef NONMATCHING // 98.13% https://decomp.me/scratch/sflGg
void sub_8005838(s32 *a0, u8 kind)
{
    s16 *r1;
    s16 *r2;
    s16 *r3;
    s32 i;

    if (!gUnknown_2026E4C)
        kind = 0;

    r3 = !gUnknown_2026E54 ? &gUnknown_2026E60 : &gUnknown_20270E8;

    r2 = gUnknown_203B078;
    if (r2 == NULL)
        r2 = &gUnknown_80B83EA;

    gUnknown_2026E58 = r3;

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
                    else {
                        if (a0[3] <= i) {
                            *r3++ = *r2++;
                            *r3++ = 256;
                        }
                        else {
                            if (i - a0[1] < 16) {
                                iVar5 = gUnknown_80B8008[i - a0[1]];
                                r4 = a0[0] + gUnknown_80B8008[i - a0[1]];
                                iVar5 -= a0[2];
                            }
                            else {
                                if (a0[3] - i < 16) {
                                    iVar5 = gUnknown_80B8008[r4];
                                    r4 = a0[0] + gUnknown_80B8008[r4];
                                    iVar5 -= a0[2];
                                }
                                else {
                                    r4 = a0[0];
                                    iVar5 = a0[2];
                                }
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
                s32 iVar3;
                s32 sp14;
                s32 iVar5;
                s32 uVar7; // r2
                s32 sp10;
                s32 iVar10;
                s32 iVar11; // r4

                s32 tmp1;
                s32 tmp2;
                s32 val1;
                s32 val2;
                s32 val3;
                s32 spC;

                s32 j;
                s32 k;

                val1 = gUnknown_2026E40;
                val2 = gUnknown_2026E44;
                val3 = gUnknown_2026E48;

                spC = 0x400 / (val3 / 256 + 1);
                iVar11 = val2 / 256;

                j = iVar11;
                k = iVar11;
                for (sp10 = 0; sp10 < 0x400; sp10 += spC) {
                    tmp1 = val3 * sin_abs_4096(sp10) / 256;

                    sp14 = (val2 + tmp1) / 256;
                    r8 = (val2 - tmp1) / 256;

                    if (j < sp14 || k > r8) {
                        tmp2 = val3 * cos_4096(sp10) / 256;

                        iVar5 = (val1 - tmp2) / 256;
                        iVar3 = (val1 + tmp2) / 256;

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

                        while (j < sp14) {
                            if (j >= 0) { // Cannot merge ifs for matching
                                if (j < 160) {
                                    if (gUnknown_2026E54 == 0)
                                        gUnknown_2026E60[iVar11 * 2 + j * 2] = uVar7;
                                    else
                                        gUnknown_20270E8[iVar11 * 2 + j * 2] = uVar7;
                                }
                            }
                            j++;
                        }

                        while (k > r8) {
                            if (k >= 0) { // Cannot merge ifs for matching
                                if (k < 160) {
                                    if (gUnknown_2026E54 == 0)
                                        gUnknown_2026E60[iVar11 * 2 + k * 2] = uVar7;
                                    else
                                        gUnknown_20270E8[iVar11 * 2 + k * 2] = uVar7;
                                }
                            }
                            k--;
                        }
                    }
                }
            }
            break;
    }
}
#else
NAKED void sub_8005838(s32 *a0, u8 kind)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x18\n"
    "\tadds r5, r0, 0\n"
    "\tlsls r1, 24\n"
    "\tlsrs r1, 24\n"
    "\tldr r0, _08005880\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0\n"
    "\tbne _08005854\n"
    "\tmovs r1, 0\n"
"_08005854:\n"
    "\tldr r0, _08005884\n"
    "\tldr r0, [r0]\n"
    "\tldr r3, _08005888\n"
    "\tcmp r0, 0\n"
    "\tbne _08005860\n"
    "\tldr r3, _0800588C\n"
"_08005860:\n"
    "\tldr r0, _08005890\n"
    "\tldr r2, [r0]\n"
    "\tcmp r2, 0\n"
    "\tbne _0800586A\n"
    "\tldr r2, _08005894\n"
"_0800586A:\n"
    "\tldr r0, _08005898\n"
    "\tstr r3, [r0]\n"
    "\tcmp r1, 0x5\n"
    "\tbls _08005876\n"
    "\tbl _08006094\n"
"_08005876:\n"
    "\tlsls r0, r1, 2\n"
    "\tldr r1, _0800589C\n"
    "\tadds r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
"_08005880: .4byte gUnknown_2026E4C\n"
"_08005884: .4byte gUnknown_2026E54\n"
"_08005888: .4byte gUnknown_20270E8\n"
"_0800588C: .4byte gUnknown_2026E60\n"
"_08005890: .4byte gUnknown_203B078\n"
"_08005894: .4byte gUnknown_80B83EA\n"
"_08005898: .4byte gUnknown_2026E58\n"
"_0800589C: .4byte _080058A0\n"
    "\t.align 2, 0\n"
"_080058A0:\n"
    "\t.4byte _080058B8\n"
    "\t.4byte _08005984\n"
    "\t.4byte _08005A98\n"
    "\t.4byte _08005BAC\n"
    "\t.4byte _08005D46\n"
    "\t.4byte _08005E58\n"
"_080058B8:\n"
    "\tmovs r1, 0\n"
    "\tmovs r7, 0x9\n"
"_080058BC:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tbge _080058BC\n"
    "\tb _08006094\n"
"_08005984:\n"
    "\tldr r1, _08005A94\n"
    "\tmovs r7, 0x9\n"
"_08005988:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tblt _08005A90\n"
    "\tb _08005988\n"
"_08005A90:\n"
    "\tb _08006094\n"
    "\t.align 2, 0\n"
"_08005A94: .4byte gUnknown_80B816A\n"
"_08005A98:\n"
    "\tldr r1, _08005BA8\n"
    "\tmovs r7, 0x9\n"
"_08005A9C:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tblt _08005BA4\n"
    "\tb _08005A9C\n"
"_08005BA4:\n"
    "\tb _08006094\n"
    "\t.align 2, 0\n"
"_08005BA8: .4byte gUnknown_80B802A\n"
"_08005BAC:\n"
    "\tldr r0, [r5]\n"
    "\tmov r10, r0\n"
    "\tcmp r0, 0\n"
    "\tbge _08005BBA\n"
    "\tldr r0, [r5, 0x8]\n"
    "\tcmp r0, 0\n"
    "\tblt _08005BDC\n"
"_08005BBA:\n"
    "\tldr r1, [r5, 0x4]\n"
    "\tcmp r1, 0\n"
    "\tbge _08005BC6\n"
    "\tldr r0, [r5, 0xC]\n"
    "\tcmp r0, 0\n"
    "\tblt _08005BDC\n"
"_08005BC6:\n"
    "\tmov r4, r10\n"
    "\tcmp r4, 0xEF\n"
    "\tble _08005BD2\n"
    "\tldr r0, [r5, 0x8]\n"
    "\tcmp r0, 0xEF\n"
    "\tbgt _08005BDC\n"
"_08005BD2:\n"
    "\tcmp r1, 0x9F\n"
    "\tble _08005CA8\n"
    "\tldr r0, [r5, 0xC]\n"
    "\tcmp r0, 0x9F\n"
    "\tble _08005CA8\n"
"_08005BDC:\n"
    "\tmovs r1, 0xF0\n"
    "\tmovs r7, 0x9\n"
"_08005BE0:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tbge _08005BE0\n"
    "\tb _08006094\n"
"_08005CA8:\n"
    "\tmovs r7, 0\n"
    "\tmov r8, r1\n"
    "\tmovs r6, 0x80\n"
    "\tlsls r6, 1\n"
    "\tmov r12, r6\n"
    "\tlsls r0, r1, 1\n"
    "\tldr r1, _08005CCC\n"
    "\tsubs r6, r1, r0\n"
    "\tmov r9, r10\n"
"_08005CBA:\n"
    "\tcmp r8, r7\n"
    "\tble _08005CD0\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tmov r4, r12\n"
    "\tstrh r4, [r3]\n"
    "\tb _08005D3A\n"
    "\t.align 2, 0\n"
"_08005CCC: .4byte gUnknown_80B8008\n"
"_08005CD0:\n"
    "\tldr r1, [r5, 0xC]\n"
    "\tcmp r1, r7\n"
    "\tbgt _08005CE2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tmov r0, r12\n"
    "\tb _08005D38\n"
"_08005CE2:\n"
    "\tmov r4, r8\n"
    "\tsubs r0, r7, r4\n"
    "\tcmp r0, 0xF\n"
    "\tbgt _08005CF0\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r6, r0]\n"
    "\tb _08005D00\n"
"_08005CF0:\n"
    "\tsubs r0, r1, r7\n"
    "\tcmp r0, 0xF\n"
    "\tbgt _08005D10\n"
    "\tlsls r0, 1\n"
    "\tldr r1, _08005D0C\n"
    "\tadds r0, r1\n"
    "\tmovs r4, 0\n"
    "\tldrsh r1, [r0, r4]\n"
"_08005D00:\n"
    "\tmov r0, r9\n"
    "\tadds r4, r0, r1\n"
    "\tldr r0, [r5, 0x8]\n"
    "\tsubs r1, r0, r1\n"
    "\tb _08005D14\n"
    "\t.align 2, 0\n"
"_08005D0C: .4byte gUnknown_80B8008\n"
"_08005D10:\n"
    "\tmov r4, r10\n"
    "\tldr r1, [r5, 0x8]\n"
"_08005D14:\n"
    "\tcmp r4, 0\n"
    "\tbge _08005D1A\n"
    "\tmovs r4, 0\n"
"_08005D1A:\n"
    "\tcmp r4, 0xEF\n"
    "\tble _08005D20\n"
    "\tmovs r4, 0xEF\n"
"_08005D20:\n"
    "\tcmp r1, 0\n"
    "\tbgt _08005D26\n"
    "\tmovs r1, 0x1\n"
"_08005D26:\n"
    "\tcmp r1, 0xF0\n"
    "\tble _08005D2C\n"
    "\tmovs r1, 0xF0\n"
"_08005D2C:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tlsls r0, r1, 8\n"
    "\torrs r0, r4\n"
"_08005D38:\n"
    "\tstrh r0, [r3]\n"
"_08005D3A:\n"
    "\tadds r3, 0x2\n"
    "\tadds r6, 0x2\n"
    "\tadds r7, 0x1\n"
    "\tcmp r7, 0x9F\n"
    "\tble _08005CBA\n"
    "\tb _08006094\n"
"_08005D46:\n"
    "\tldr r1, _08005E54\n"
    "\tmovs r7, 0xE\n"
"_08005D4A:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r1, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tblt _08005E52\n"
    "\tb _08005D4A\n"
"_08005E52:\n"
    "\tb _08006094\n"
    "\t.align 2, 0\n"
"_08005E54: .4byte gUnknown_80B82AA\n"
"_08005E58:\n"
    "\tldr r4, _08005FF4\n"
    "\tldr r5, _08005FF8\n"
    "\tldr r6, _08005FFC\n"
    "\tmovs r0, 0x80\n"
    "\tlsls r0, 1\n"
    "\tadds r1, r0, 0\n"
    "\tmovs r7, 0xE\n"
"_08005E66:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tstrh r1, [r3]\n"
    "\tadds r3, 0x2\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tbge _08005E66\n"
    "\tldr r4, [r4]\n"
    "\tstr r4, [sp]\n"
    "\tldr r5, [r5]\n"
    "\tstr r5, [sp, 0x4]\n"
    "\tldr r6, [r6]\n"
    "\tstr r6, [sp, 0x8]\n"
    "\tadds r1, r6, 0\n"
    "\tcmp r6, 0\n"
    "\tbge _08005F40\n"
    "\tadds r1, 0xFF\n"
"_08005F40:\n"
    "\tasrs r1, 8\n"
    "\tadds r1, 0x1\n"
    "\tmovs r0, 0x80\n"
    "\tlsls r0, 3\n"
    "\tbl __divsi3\n"
    "\tstr r0, [sp, 0xC]\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tcmp r0, 0\n"
    "\tbge _08005F56\n"
    "\tadds r0, 0xFF\n"
"_08005F56:\n"
    "\tasrs r4, r0, 8\n"
    "\tadds r5, r4, 0\n"
    "\tmovs r3, 0\n"
    "\tlsls r0, r4, 2\n"
    "\tadds r7, r0, 0x2\n"
    "\tmov r9, r7\n"
"_08005F62:\n"
    "\tadds r0, r3, 0\n"
    "\tstr r3, [sp, 0x10]\n"
    "\tbl sin_abs_4096\n"
    "\tldr r1, [sp, 0x8]\n"
    "\tmuls r0, r1\n"
    "\tldr r3, [sp, 0x10]\n"
    "\tcmp r0, 0\n"
    "\tbge _08005F76\n"
    "\tadds r0, 0xFF\n"
"_08005F76:\n"
    "\tasrs r0, 8\n"
    "\tldr r2, [sp, 0x4]\n"
    "\tadds r1, r2, r0\n"
    "\tcmp r1, 0\n"
    "\tbge _08005F82\n"
    "\tadds r1, 0xFF\n"
"_08005F82:\n"
    "\tasrs r1, 8\n"
    "\tstr r1, [sp, 0x14]\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tsubs r0, r6, r0\n"
    "\tcmp r0, 0\n"
    "\tbge _08005F90\n"
    "\tadds r0, 0xFF\n"
"_08005F90:\n"
    "\tasrs r0, 8\n"
    "\tmov r8, r0\n"
    "\tldr r0, [sp, 0x14]\n"
    "\tcmp r5, r0\n"
    "\tblt _08005FA4\n"
    "\tldr r1, [sp, 0xC]\n"
    "\tadds r1, r3\n"
    "\tmov r10, r1\n"
    "\tcmp r4, r8\n"
    "\tble _0800608A\n"
"_08005FA4:\n"
    "\tadds r0, r3, 0\n"
    "\tstr r3, [sp, 0x10]\n"
    "\tbl cos_4096\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tmuls r0, r2\n"
    "\tldr r3, [sp, 0x10]\n"
    "\tcmp r0, 0\n"
    "\tbge _08005FB8\n"
    "\tadds r0, 0xFF\n"
"_08005FB8:\n"
    "\tasrs r0, 8\n"
    "\tldr r6, [sp]\n"
    "\tsubs r1, r6, r0\n"
    "\tcmp r1, 0\n"
    "\tbge _08005FC4\n"
    "\tadds r1, 0xFF\n"
"_08005FC4:\n"
    "\tasrs r1, 8\n"
    "\tldr r2, [sp]\n"
    "\tadds r0, r2, r0\n"
    "\tcmp r0, 0\n"
    "\tbge _08005FD0\n"
    "\tadds r0, 0xFF\n"
"_08005FD0:\n"
    "\tasrs r0, 8\n"
    "\tcmp r1, 0\n"
    "\tbge _08005FD8\n"
    "\tmovs r1, 0\n"
"_08005FD8:\n"
    "\tcmp r0, 0\n"
    "\tbge _08005FDE\n"
    "\tmovs r0, 0\n"
"_08005FDE:\n"
    "\tcmp r1, 0xEF\n"
    "\tble _08005FE4\n"
    "\tmovs r1, 0x9F\n"
"_08005FE4:\n"
    "\tcmp r0, 0xEF\n"
    "\tble _08005FEA\n"
    "\tmovs r0, 0x9F\n"
"_08005FEA:\n"
    "\tcmp r1, r0\n"
    "\tble _08006000\n"
    "\tlsls r2, r1, 8\n"
    "\torrs r2, r0\n"
    "\tb _08006004\n"
    "\t.align 2, 0\n"
"_08005FF4: .4byte gUnknown_2026E40\n"
"_08005FF8: .4byte gUnknown_2026E44\n"
"_08005FFC: .4byte gUnknown_2026E48\n"
"_08006000:\n"
    "\tlsls r2, r0, 8\n"
    "\torrs r2, r1\n"
"_08006004:\n"
    "\tldr r6, [sp, 0xC]\n"
    "\tadds r3, r6\n"
    "\tmov r10, r3\n"
    "\tldr r0, [sp, 0x14]\n"
    "\tcmp r5, r0\n"
    "\tbge _0800604E\n"
    "\tldr r1, _08006030\n"
    "\tmov r12, r1\n"
    "\tldr r3, _08006034\n"
    "\tadd r3, r9\n"
    "\tldr r1, _08006038\n"
    "\tadd r1, r9\n"
"_0800601C:\n"
    "\tcmp r5, 0\n"
    "\tblt _0800603E\n"
    "\tcmp r5, 0x9F\n"
    "\tbgt _0800603E\n"
    "\tmov r6, r12\n"
    "\tldr r0, [r6]\n"
    "\tcmp r0, 0\n"
    "\tbne _0800603C\n"
    "\tstrh r2, [r1]\n"
    "\tb _0800603E\n"
    "\t.align 2, 0\n"
"_08006030: .4byte gUnknown_2026E54\n"
"_08006034: .4byte gUnknown_20270E8\n"
"_08006038: .4byte gUnknown_2026E60\n"
"_0800603C:\n"
    "\tstrh r2, [r3]\n"
"_0800603E:\n"
    "\tadds r3, 0x4\n"
    "\tadds r1, 0x4\n"
    "\tmovs r0, 0x4\n"
    "\tadd r9, r0\n"
    "\tadds r5, 0x1\n"
    "\tldr r6, [sp, 0x14]\n"
    "\tcmp r5, r6\n"
    "\tblt _0800601C\n"
"_0800604E:\n"
    "\tcmp r4, r8\n"
    "\tble _0800608A\n"
    "\tldr r6, _08006070\n"
    "\tldr r0, _08006074\n"
    "\tadds r3, r7, r0\n"
    "\tldr r0, _08006078\n"
    "\tadds r1, r7, r0\n"
"_0800605C:\n"
    "\tcmp r4, 0\n"
    "\tblt _0800607E\n"
    "\tcmp r4, 0x9F\n"
    "\tbgt _0800607E\n"
    "\tldr r0, [r6]\n"
    "\tcmp r0, 0\n"
    "\tbne _0800607C\n"
    "\tstrh r2, [r1]\n"
    "\tb _0800607E\n"
    "\t.align 2, 0\n"
"_08006070: .4byte gUnknown_2026E54\n"
"_08006074: .4byte gUnknown_20270E8\n"
"_08006078: .4byte gUnknown_2026E60\n"
"_0800607C:\n"
    "\tstrh r2, [r3]\n"
"_0800607E:\n"
    "\tsubs r3, 0x4\n"
    "\tsubs r1, 0x4\n"
    "\tsubs r7, 0x4\n"
    "\tsubs r4, 0x1\n"
    "\tcmp r4, r8\n"
    "\tbgt _0800605C\n"
"_0800608A:\n"
    "\tmov r3, r10\n"
    "\tldr r0, _080060A4\n"
    "\tcmp r3, r0\n"
    "\tbgt _08006094\n"
    "\tb _08005F62\n"
"_08006094:\n"
    "\tadd sp, 0x18\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_080060A4: .4byte 0x000003ff");
}
#endif // NONMATCHING

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
