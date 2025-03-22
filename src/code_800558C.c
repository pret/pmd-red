#include "global.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "math.h"

EWRAM_DATA bool8 gUnknown_2026E38 = FALSE;
EWRAM_DATA u32 *gUnknown_2026E3C = NULL;
EWRAM_DATA static s32 sUnknown_2026E40 = 0; // Read from but never written to
EWRAM_DATA static s32 sUnknown_2026E44 = 0; // Read from but never written to
EWRAM_DATA static s32 sUnknown_2026E48 = 0; // Read from but never written to
EWRAM_DATA static bool8 sUnknown_2026E4C = FALSE;
EWRAM_DATA s16 gUnknown_2026E4E = 0;
EWRAM_DATA static bool32 sUnknown_2026E50 = FALSE;
EWRAM_DATA static bool32 sUnknown_2026E54 = FALSE;
EWRAM_DATA static u32 *sUnknown_2026E58 = NULL;
UNUSED EWRAM_DATA static u32 sUnused0 = 0;
EWRAM_DATA static s16 sUnknown_2026E60[324] = {0}; // These might be [2][162]
EWRAM_DATA static s16 sUnknown_20270E8[324] = {0};

EWRAM_INIT s16 *gUnknown_203B078 = NULL;

// data.s
extern const s16 gUnknown_80B8008[17];
extern const s16 gUnknown_80B802A[16 * 10];
extern const s16 gUnknown_80B816A[16 * 10];
extern const s16 gUnknown_80B82AA[16 * 10];
extern const s16 gUnknown_80B83EA[16 * 10];

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
    const s16 *r1, *r2;
    s16 *r3;
    s32 i;

    if (!sUnknown_2026E4C)
        kind = 0;

    r3 = !sUnknown_2026E54 ? sUnknown_2026E60 : sUnknown_20270E8;

    r2 = gUnknown_203B078;
    if (r2 == NULL)
        r2 = (void *) &gUnknown_80B83EA;

    sUnknown_2026E58 = (void *) r3;

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
            }
            break;
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
