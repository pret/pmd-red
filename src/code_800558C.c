#include "global.h"
#include "globaldata.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "math.h"

EWRAM_DATA bool8 gUnknown_2026E38 = FALSE;
EWRAM_DATA s16 *gUnknown_2026E3C = NULL;
EWRAM_DATA static s32 sUnknown_2026E40 = 0; // Read from but never written to
EWRAM_DATA static s32 sUnknown_2026E44 = 0; // Read from but never written to
EWRAM_DATA static s32 sUnknown_2026E48 = 0; // Read from but never written to
EWRAM_DATA static bool8 sUnknown_2026E4C = FALSE;
EWRAM_DATA s16 gUnknown_2026E4E = 0;
EWRAM_DATA static bool32 sUnknown_2026E50 = FALSE;
EWRAM_DATA static bool32 sUnknown_2026E54 = FALSE;
EWRAM_DATA static s16 *sUnknown_2026E58 = NULL;
UNUSED EWRAM_DATA static u32 sUnused0 = 0;
EWRAM_DATA static s16 sUnknown_2026E60[324] = {0}; // These might be [2][162]
EWRAM_DATA static s16 sUnknown_20270E8[324] = {0};

EWRAM_INIT s16 *gUnknown_203B078 = NULL;

static const s16 gUnknown_80B8008[17] = {16, 12, 9, 7, 6, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0};

#define UNK_TABLES_ARR_COUNT 160

static const s16 gUnknown_80B802A[UNK_TABLES_ARR_COUNT] = {
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x846C, 0x8967, 0x8C64, 0x8E62, 0x9060, 0x915F, 0x935D,
    0x945C, 0x955B, 0x965A, 0x965A, 0x9759, 0x9858, 0x9858,
    0x9957, 0x9957, 0x9A56, 0x9A56, 0x9A56, 0x9B55, 0x9B55,
    0x9B55, 0x9B55, 0x9B55, 0x9C55, 0x9C54, 0x9C54, 0x9C54,
    0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54,
    0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54,
    0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9C54, 0x9B55,
    0x9B55, 0x9B55, 0x9B55, 0x9B55, 0x9A56, 0x9A56, 0x9A56,
    0x9957, 0x9957, 0x9858, 0x9858, 0x9759, 0x965A, 0x965A,
    0x955B, 0x945C, 0x935D, 0x915F, 0x9060, 0x8E62, 0x8C64,
    0x8967, 0x846C, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100
};

static const s16 gUnknown_80B816A[UNK_TABLES_ARR_COUNT] = {
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x8071, 0x866B, 0x8A67, 0x8D64, 0x8F62, 0x9160, 0x935E,
    0x955C, 0x975A, 0x9958, 0x9A57, 0x9B56, 0x9D54, 0x9E53,
    0xA051, 0xA051, 0xA150, 0xA24F, 0xA44D, 0xA54C, 0xA54C,
    0xA64B, 0xA74A, 0xA849, 0xA948, 0xA948, 0xAA47, 0xAA47,
    0xAB46, 0xAC45, 0xAC45, 0xAD44, 0xAD44, 0xAE43, 0xAE43,
    0xAF42, 0xAF42, 0xB041, 0xB041, 0xB140, 0xB140, 0xB140,
    0xB23F, 0xB23F, 0xB23F, 0xB23F, 0xB33E, 0xB33E, 0xB33E,
    0xB33E, 0xB33E, 0xB33E, 0xB43D, 0xB43D, 0xB43D, 0xB43D,
    0xB43D, 0xB43D, 0xB43D, 0xB43D, 0xB43D, 0xB43D, 0xB43D,
    0xB43D, 0xB43D, 0xB43D, 0xB43D, 0xB43D, 0xB33E, 0xB33E,
    0xB33E, 0xB33E, 0xB33E, 0xB33E, 0xB23F, 0xB23F, 0xB23F,
    0xB23F, 0xB140, 0xB140, 0xB140, 0xB041, 0xB041, 0xAF42,
    0xAF42, 0xAE43, 0xAE43, 0xAD44, 0xAD44, 0xAC45, 0xAC45,
    0xAB46, 0xAA47, 0xAA47, 0xA948, 0xA948, 0xA849, 0xA74A,
    0xA64B, 0xA54C, 0xA54C, 0xA44D, 0xA24F, 0xA150, 0xA051,
    0xA051, 0x9E53, 0x9D54, 0x9B56, 0x9A57, 0x9958, 0x975A,
    0x955C, 0x935E, 0x9160, 0x8F62, 0x8D64, 0x8A67, 0x866B,
    0x8071, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x100
};

// Almost all 0x100
static const s16 gUnknown_80B82AA[UNK_TABLES_ARR_COUNT] = {
    [0 ... 2] = 0x100,
    [3] = 0x9392,
    [4 ... UNK_TABLES_ARR_COUNT - 1] = 0x100
};
// All zeroes
static const s16 gUnknown_80B83EA[UNK_TABLES_ARR_COUNT] = {
    [0 ... UNK_TABLES_ARR_COUNT - 1] = 0
};

// arm9.bin::02006154
void sub_80057E8(void)
{
    sUnknown_2026E4C = TRUE;
    sUnknown_2026E54 = FALSE;
    sUnknown_2026E50 = TRUE;
    sUnknown_2026E58 = NULL;
    gUnknown_2026E3C = NULL;
    gUnknown_2026E38 = FALSE;
    gUnknown_2026E4E = 0x60C;
    gUnknown_203B078 = NULL;
}

// arm9.bin::02005758
void sub_8005838(s32 *a0, u8 kind)
{
    const s16 *src1, *src2;
    s16 *dst;
    s32 i;

    if (!sUnknown_2026E4C)
        kind = 0;

    dst = !sUnknown_2026E54 ? sUnknown_2026E60 : sUnknown_20270E8;

    src1 = gUnknown_203B078;
    if (src1 == NULL)
        src1 = gUnknown_80B83EA;

    sUnknown_2026E58 = dst;

    switch (kind) {
        case 0:
            for (i = 0; i < 10; i++) {
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
                *dst++ = *src1++;
                *dst++ = 0;
            }
            break;
        case 1:
            src2 = gUnknown_80B816A;
            for (i = 0; i < 10; i++) {
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
            }
            break;
        case 2:
            src2 = gUnknown_80B802A;
            for (i = 0; i < 10; i++) {
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
            }
            break;
        case 3:
            if ((a0[0] < 0 && a0[2] < 0)
                || (a0[1] < 0 && a0[3] < 0)
                || (a0[0] >= 240 && a0[2] >= 240)
                || (a0[1] >= 160 && a0[3] >= 160)) {
                for (i = 0; i < 10; i++) {
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                    *dst++ = *src1++;
                    *dst++ = 240;
                }
            }
            else {
                s32 iVar5;
                s32 r4;
                for (i = 0; i < 160; i++) {
                    if (a0[1] > i) {
                        *dst++ = *src1++;
                        *dst++ = 256;
                    }
                    else if (a0[3] <= i) {
                        *dst++ = *src1++;
                        *dst++ = 256;
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

                        *dst++ = *src1++;
                        *dst++ = (iVar5 << 8) | r4;
                    }
                }
            }
            break;
        case 4:
            src2 = gUnknown_80B82AA;
            for (i = 0; i < 15; i++) {
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
                *dst++ = *src1++;
                *dst++ = *src2++;
            }
            break;
        case 5: {
            s32 r8;
            s32 sp14;
            s32 uVar7;
            s32 sp10;
            s32 iVar11;

            s32 val1;
            s32 val2;
            s32 val3;
            s32 spC;

            s32 j, k;

            for (i = 0; i < 15; i++) {
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
                *dst++ = *src1++;
                *dst++ = 256;
            }

            val1 = sUnknown_2026E40;
            val2 = sUnknown_2026E44;
            val3 = sUnknown_2026E48;

            spC = 0x400 / (val3 / 256 + 1);
            iVar11 = val2 / 256;

            k = iVar11;
            j = iVar11;
            for (sp10 = 0; sp10 < 0x400; sp10 += spC) {
                s32 tmp1 = sin_4096(sp10) * val3 / 256;

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

                        if (!sUnknown_2026E54)
                            sUnknown_2026E60[j * 2 + 1] = uVar7;
                        else
                            sUnknown_20270E8[j * 2 + 1] = uVar7;
                    }

                    for (; k > r8; k--) {
                        if (k < 0)
                            continue;
                        if (k >= 160)
                            continue;

                        if (!sUnknown_2026E54)
                            sUnknown_2026E60[k * 2 + 1] = uVar7;
                        else
                            sUnknown_20270E8[k * 2 + 1] = uVar7;
                    }
                }
            }
            break;
        }
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void sub_80060A8(void)
{
    gUnknown_2026E3C = sUnknown_2026E58;
    sUnknown_2026E54 = !sUnknown_2026E54;
    sUnknown_2026E50 = !sUnknown_2026E50;
    gUnknown_2026E38 = FALSE;
}
#endif

// arm9.bin::020056C0
void sub_80060EC(void)
{
    gUnknown_2026E3C = sUnknown_2026E58;
    sUnknown_2026E54 = !sUnknown_2026E54;
    sUnknown_2026E50 = !sUnknown_2026E50;
    SetBldAlphaReg((gUnknown_2026E4E & 0x1F00) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = TRUE;
}
