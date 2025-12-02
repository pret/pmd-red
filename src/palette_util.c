#include "global.h"
#include "globaldata.h"
#include "palette_util.h"
#include "bg_palette_buffer.h"
#include "palette_fade_util.h"

enum PU_SomeStateID
{
    PU_SOMESTATE_0,
    PU_SOMESTATE_1,
    PU_SOMESTATE_2,
    PU_SOMESTATE_3,
    PU_SOMESTATE_4,
    PU_SOMESTATE_5,
};

#define ARR_COUNT_2039998 33

// Size: R=0x10 | B=0xE
typedef struct UnkStruct_2039958
{
    /* 0x0 */ s32 unk0; // See enum "PU_SomeStateID"
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
    /* 0xC */ u16 unkC;
} UnkStruct_2039958;

// Size: R=0x18 | B=16
typedef struct UnkStruct_2039978
{
    /* 0x0 */ u32 unk0; // See enum "PaletteUtilUnk0Kind"
    /* 0x4 */ RGB_Array unk4;
    /* 0x8 */ UnkStruct_2039958 unk8;
} UnkStruct_2039978;

static EWRAM_DATA UnkStruct_2039958 gUnknown_2039958 = { 0 };
static EWRAM_DATA UnkStruct_2039958 gUnknown_2039968 = { 0 };
static EWRAM_DATA UnkStruct_2039978 gUnknown_2039978 = { 0 };
static EWRAM_DATA bool8 gUnknown_2039990 = FALSE;
static EWRAM_DATA s16 gUnknown_2039992 = 0;
UNUSED static EWRAM_DATA s32 sUnused = 0;
static EWRAM_DATA u16 gUnknown_2039998[ARR_COUNT_2039998] = { 0 };

static void sub_8099838(UnkStruct_2039958 *a0);
static void sub_8099848(UnkStruct_2039958 *a0);
static void sub_8099DD0(u16 a0);
static void sub_8099E58(u16 a0);
static void sub_8099E80(u16 a0, RGB_Array a1);

void sub_8099744(void)
{
    RunPaletteFadeFunctions();
}

void sub_8099750(void)
{
    TransferBGPaletteBuffer();
}

void sub_809975C(void)
{
    sub_809977C();
}

void sub_8099768(void)
{
    sub_809977C();
    sub_8099744();
    sub_8099750();
}

void sub_809977C(void)
{
    s32 i;

    gUnknown_2039990 = FALSE;
    gUnknown_2039992 = 0;
    sub_8099838(&gUnknown_2039958);
    sub_8099838(&gUnknown_2039968);
    sub_8099838(&gUnknown_2039978.unk8);
    gUnknown_2039978.unk0 = PALUTIL_KIND_00;
    gUnknown_2039978.unk8.unkC = 0x100;
    gUnknown_2039958.unkC = 0;
    sub_8099DD0(0);
    gUnknown_2039968.unkC = 0x100;
    sub_8099E58(0x100);

    for (i = 0; i < ARR_COUNT_2039998; i++) {
        gUnknown_2039998[i] = 0;
    }
}

void sub_80997F4(u16 a0, u16 a1)
{
    gUnknown_2039998[a0] = a1;
    sub_8099848(&gUnknown_2039958);
    sub_8099848(&gUnknown_2039968);
    sub_8099848(&gUnknown_2039978.unk8);
}

UNUSED static u32 sub_8099828(u16 a0)
{
    return gUnknown_2039998[a0];
}

static void sub_8099838(UnkStruct_2039958 *a0)
{
    a0->unk0 = PU_SOMESTATE_1;
    a0->unkC = 0;
    a0->unk4 = 0;
    a0->unk6 = 0;
}

static void sub_8099848(UnkStruct_2039958 *a0)
{
    if (a0->unk0 == PU_SOMESTATE_0)
        a0->unk0 = PU_SOMESTATE_1;
}

static void sub_809985C(UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = 0x100;
            a0->unk0 = PU_SOMESTATE_1;
        }
        else {
            a0->unk0 = PU_SOMESTATE_2;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = PU_SOMESTATE_2;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

static void sub_8099880(UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = a1;
            a0->unk0 = PU_SOMESTATE_1;
        }
        else {
            a0->unk0 = PU_SOMESTATE_3;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = PU_SOMESTATE_3;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

static void sub_80998A0(UnkStruct_2039958 *a0, s32 a1, u16 a2, u16 a3)
{
    if (a1 < 0)
        a1 = 30;

    if (a2 > a3) {
        a0->unk0 = PU_SOMESTATE_5;
        a0->unkA = a2 - a3;
    }
    else if (a2 < a3) {
        a0->unk0 = PU_SOMESTATE_4;
        a0->unkA = a3 - a2;
    }
    else {
        a0->unk0 = PU_SOMESTATE_1;
        a0->unkA = 0;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
    a0->unkC = a2;
    a0->unk8 = a3;
}

static bool8 sub_80998E0(UnkStruct_2039958 *a0)
{
    switch (a0->unk0) {
        case PU_SOMESTATE_0:
            break;
        case PU_SOMESTATE_1:
            a0->unk0 = PU_SOMESTATE_0;
            return TRUE;
        case PU_SOMESTATE_2:
            if (--a0->unk4 > 0) {
                u16 var = 0x100 - ((a0->unk4 << 8) / a0->unk6);
                if (a0->unkC < var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0x100;
                a0->unk0 = PU_SOMESTATE_0;
            }
            return TRUE;
        case PU_SOMESTATE_3:
            if (--a0->unk4 > 0) {
                u16 var = (a0->unk4 << 8) / a0->unk6;
                if (a0->unkC > var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0;
                a0->unk0 = PU_SOMESTATE_0;
            }
            return TRUE;
        case PU_SOMESTATE_4:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 - ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = PU_SOMESTATE_0;
            }
            return TRUE;
        case PU_SOMESTATE_5:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 + ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = PU_SOMESTATE_0;
            }
            return TRUE;
    }

    return FALSE;
}

void sub_80999D4(s32 a0)
{
    gUnknown_2039990 = TRUE;
    gUnknown_2039992 = a0;
}

void sub_80999E8(s32 a0)
{
    sub_809985C(&gUnknown_2039958, a0);
}

void sub_80999FC(s32 a0)
{
    sub_8099880(&gUnknown_2039958, a0);
}

void sub_8099A10(s32 a1, u16 a2, u16 a3)
{
    sub_80998A0(&gUnknown_2039958, a1, a2, a3);
}

void sub_8099A34(s32 a0)
{
    sub_809985C(&gUnknown_2039968, a0);
}

void sub_8099A48(s32 a0)
{
    sub_8099880(&gUnknown_2039968, a0);
}

void sub_8099A5C(s32 kind, s32 a1, RGB_Array a2)
{
    gUnknown_2039978.unk0 = kind;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0;
    sub_809985C(&gUnknown_2039978.unk8, a1);

    switch (kind) {
        case PALUTIL_KIND_01:
        case PALUTIL_KIND_03:
            gUnknown_2039968.unkC = 0x100;
            gUnknown_2039958.unkC = 0x100;
            break;
        case PALUTIL_KIND_09:
        case PALUTIL_KIND_11:
            gUnknown_2039968.unkC = 0x100;
            break;
        case PALUTIL_KIND_05:
        case PALUTIL_KIND_07:
        case PALUTIL_KIND_13:
        case PALUTIL_KIND_14:
            gUnknown_2039958.unkC = 0x100;
            break;
    }
}

void sub_8099AFC(s32 kind, s32 a1, RGB_Array a2)
{
    gUnknown_2039978.unk0 = kind;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0x100;
    sub_8099880(&gUnknown_2039978.unk8, a1);

    switch (kind) {
        case PALUTIL_KIND_02:
        case PALUTIL_KIND_04:
            gUnknown_2039968.unkC = 0;
            gUnknown_2039958.unkC = 0;
            break;
        case PALUTIL_KIND_10:
        case PALUTIL_KIND_12:
            gUnknown_2039968.unkC = 0;
            break;
        case PALUTIL_KIND_06:
        case PALUTIL_KIND_08:
        case PALUTIL_KIND_13:
        case PALUTIL_KIND_14:
            gUnknown_2039958.unkC = 0;
            break;
    }
}

bool8 sub_8099B94(void)
{
    if (gUnknown_2039990)
        return TRUE;

    if (gUnknown_2039978.unk0 != PALUTIL_KIND_00)
        return (gUnknown_2039978.unk8.unk0 != PU_SOMESTATE_0);

    return (gUnknown_2039958.unk0 != PU_SOMESTATE_0 || gUnknown_2039968.unk0 != PU_SOMESTATE_0);
}

void sub_8099BE4(void)
{
    if (gUnknown_2039978.unk0 != PALUTIL_KIND_00 || gUnknown_2039978.unk8.unk0 != PU_SOMESTATE_0) {
        if (sub_80998E0(&gUnknown_2039978.unk8)) {
            sub_8099E80(gUnknown_2039978.unk8.unkC, gUnknown_2039978.unk4);
        }
        else if (gUnknown_2039978.unk8.unk0 == PU_SOMESTATE_0) {
            switch (gUnknown_2039978.unk0) {
                case PALUTIL_KIND_00:
                    break;
                case PALUTIL_KIND_01:
                case PALUTIL_KIND_03:
                case PALUTIL_KIND_05:
                case PALUTIL_KIND_07:
                case PALUTIL_KIND_09:
                case PALUTIL_KIND_11:
                    if (gUnknown_2039978.unk8.unkC >= 0x100) {
                        gUnknown_2039978.unk0 = PALUTIL_KIND_00;
                    }
                    else if (gUnknown_2039990) {
                        s32 kind = PALUTIL_KIND_00;

                        switch (gUnknown_2039978.unk0) {
                            case PALUTIL_KIND_01: {
                                kind = PALUTIL_KIND_02;
                                break;
                            }
                            case PALUTIL_KIND_03: {
                                kind = PALUTIL_KIND_04;
                                break;
                            }
                            case PALUTIL_KIND_05: {
                                kind = PALUTIL_KIND_06;
                                break;
                            }
                            case PALUTIL_KIND_07: {
                                kind = PALUTIL_KIND_08;
                                break;
                            }
                        }

                        if (kind != PALUTIL_KIND_00)
                            sub_8099AFC(kind, gUnknown_2039992, gUnknown_2039978.unk4);
                        else
                            gUnknown_2039978.unk0 = PALUTIL_KIND_00;

                    }
                    break;
                case PALUTIL_KIND_02:
                case PALUTIL_KIND_04:
                case PALUTIL_KIND_06:
                case PALUTIL_KIND_08:
                case PALUTIL_KIND_10:
                case PALUTIL_KIND_12:
                case PALUTIL_KIND_13:
                case PALUTIL_KIND_14:
                    if (gUnknown_2039978.unk8.unkC == 0) {
                        gUnknown_2039978.unk0 = PALUTIL_KIND_00;
                    }
                    else if (gUnknown_2039990) {
                        sub_8099AFC(gUnknown_2039978.unk0, gUnknown_2039992, gUnknown_2039978.unk4);
                    }
                    break;
            }
        }
    }
    else if (gUnknown_2039990) {
        bool8 r5 = TRUE;
        if (gUnknown_2039958.unkC != 0 || gUnknown_2039958.unk0 != PU_SOMESTATE_0) {
            r5 = FALSE;
            if (gUnknown_2039958.unk0 != PU_SOMESTATE_3) {
                sub_8099880(&gUnknown_2039958, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039958)) {
                sub_8099DD0(gUnknown_2039958.unkC);
            }
        }
        if (gUnknown_2039968.unkC != 0 || gUnknown_2039968.unk0 != PU_SOMESTATE_0) {
            r5 = FALSE;
            if (gUnknown_2039968.unk0 != PU_SOMESTATE_3) {
                sub_8099880(&gUnknown_2039968, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039968)) {
                sub_8099E58(gUnknown_2039968.unkC);
            }
        }

        if (r5) {
            gUnknown_2039990 = FALSE;
        }
    }
    else {
        if (sub_80998E0(&gUnknown_2039958)) {
            sub_8099DD0(gUnknown_2039958.unkC);
        }
        if (sub_80998E0(&gUnknown_2039968)) {
            sub_8099E58(gUnknown_2039968.unkC);
        }
    }
}

static void sub_8099DD0(u16 a0)
{
    s32 i;

    for (i = 0; i < 14; i++) {
        if (gUnknown_2039998[i] & 1) {
            SetPaletteFade_Brightness(i, 0x100);
        }
        else {
            SetPaletteFade_Brightness(i, a0);
        }
    }

    for (i = 16; i < 31; i++) {
        if (gUnknown_2039998[i] & 1) {
            SetPaletteFade_Brightness(i, 0x100);
        }
        else {
            SetPaletteFade_Brightness(i, a0);
        }
    }

    SetPaletteFade_Brightness(32, a0);
}

static void sub_8099E58(u16 a0)
{
    SetPaletteFade_Brightness(15, a0);
    SetPaletteFade_Brightness(14, a0);
    SetPaletteFade_Brightness(31, a0);
}

static void sub_8099E80(u16 param_1,RGB_Array param_2)
{
    s32 i;

    switch (gUnknown_2039978.unk0) {
        case PALUTIL_KIND_00:
            break;
        case PALUTIL_KIND_01:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_09:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }
            break;
         case PALUTIL_KIND_05:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Blend(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_02:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_10:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_06:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_FadeToBlack(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_03:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_11:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_07:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else {
                    SetPaletteFade_Desaturate(i, param_1, param_2);
                }
            }
            break;
         case PALUTIL_KIND_04:
            for (i = 0; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i,param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }

            for (i = 16; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i,param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_12:
            for (i = 14; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i,param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }

            for (i = 31; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i,param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }
            break;
        case PALUTIL_KIND_13:
        case PALUTIL_KIND_14: {
            switch (gUnknown_2039978.unk0) {
                case PALUTIL_KIND_13:
                    param_2.c[RGB_R] = 0x90;
                    param_2.c[RGB_G] = 0x90;
                    param_2.c[RGB_B] = 0xFF;
                    param_2.c[RGB_UNK] = 0xFF;
                    break;
                case PALUTIL_KIND_14:
                    param_2.c[RGB_R] = 0xFF;
                    param_2.c[RGB_G] = 0xC0;
                    param_2.c[RGB_B] = 0x80;
                    param_2.c[RGB_UNK] = 0xFF;
                    break;
            }
            // Fallthrough
        }
        case PALUTIL_KIND_08: {
            for (i = 0; i < 14; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }

            for (i = 16; i < 31; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    SetPaletteFade_Brightness(i, 0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    SetPaletteFade_Brightness(i, param_1);
                }
                else {
                    SetPaletteFade_Modulate(i, param_1, param_2);
                }
            }
            break;
        }
    }
}
