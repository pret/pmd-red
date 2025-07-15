#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "gba_color_util.h"

IWRAM_INIT bool8 gUnknown_3001B58 = FALSE;
IWRAM_INIT u16 gUnknown_3001B5A = 0;

typedef struct unkStruct_3000C00
{
    bool8 unk0;
    u8 unk1;
    s16 fadeFactor;
    RGB_Array unk4;
    s32 unk8;
    void (*unkC)(u16, u16);
    void (*unk10)(u16);
} unkStruct_3000C00;

// TODO: make static once whole file is decompiled
#define UNK_3000400_ARR_COUNT 0x200
#define UNK_3000C00_ARR_COUNT 0x21
IWRAM_DATA RGB_Union gUnknown_3000400[UNK_3000400_ARR_COUNT] = {0};
IWRAM_DATA unkStruct_3000C00 gUnknown_3000C00[UNK_3000C00_ARR_COUNT] = {0};

void sub_8003A34(u16 param_1, u16 idx);
void sub_8003AC0(u16, u16);
void sub_8003C18(u16, u16);
void sub_8003E2C(u16, u16);
void sub_8003F60(u16, u16);
void sub_8004170(u16, u16);
void sub_8004388(u16, u16);
void sub_8003B50(u16);
void sub_8003D00(u16);
void sub_8003EC0(u16);
void sub_8004034(u16);
void sub_8004264(u16);
void sub_8004434(u16);
void sub_8003A74(u16);

NAKED
UNUSED static void sub_80035F8(void)
{
    asm_unified("	.text\n"
"	push {lr}\n"
"	pop {r0}\n"
"	bx r0\n");
}

void sub_8003600(void)
{
    unkStruct_3000C00 *it1;
    RGB_Union *it2;
    bool8 *r6;
    s32 i;
    s32 zero;

    it1 = &gUnknown_3000C00[0];
    r6 = &gUnknown_3001B58;
    zero = 0;
    it2 = &gUnknown_3000400[0];

    for (i = 0; i < UNK_3000400_ARR_COUNT; it2++, i++)
    {
        it2->asArr.c[0] = zero;
        it2->asArr.c[1] = zero;
        it2->asArr.c[2] = zero;
        it2->asArr.c[3] = zero;
    }

    for (i = 0; i < UNK_3000C00_ARR_COUNT; i++, it1++)
    {
        it1->unk0 = FALSE;
        it1->fadeFactor = 256;
        it1->unk4.c[0] = 0;
        it1->unk4.c[1] = 0;
        it1->unk4.c[2] = 0;
        it1->unk4.c[3] = 0;
        it1->unk8 = 0;
        it1->unkC = &sub_8003A34;
        it1->unk10 = &sub_8003A74;
    }

    *r6 = TRUE;
}

void sub_8003664(u16 idx, s32 fadeFactor)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4.c[0] = 0;
    ptr->unk4.c[1] = 0;
    ptr->unk4.c[2] = 0;
    ptr->unk4.c[3] = 0;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003AC0;
    ptr->unk10 = &sub_8003B50;

    gUnknown_3001B58 = TRUE;
}

void sub_80036AC(u16 idx, s32 fadeFactor, RGB_Array param_3)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003C18;
    ptr->unk10 = &sub_8003D00;

    gUnknown_3001B58 = TRUE;
}

void sub_80036F4(u16 idx, s32 fadeFactor, RGB_Array param_3)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003E2C;
    ptr->unk10 = &sub_8003EC0;

    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_800373C(u16 idx, s32 fadeFactor, s32 param_3)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4.c[0] = 0;
    ptr->unk4.c[1] = 0;
    ptr->unk4.c[2] = 0;
    ptr->unk4.c[3] = 0;
    ptr->unk8 = param_3;
    ptr->unkC = &sub_8003F60;
    ptr->unk10 = &sub_8004034;

    gUnknown_3001B58 = TRUE;
}

void sub_8003780(u16 idx, s32 fadeFactor, RGB_Array param_3)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8004170;
    ptr->unk10 = &sub_8004264;

    gUnknown_3001B58 = TRUE;
}

void sub_80037C8(u16 idx, s32 fadeFactor, RGB_Array param_3)
{
    unkStruct_3000C00 *ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->fadeFactor = fadeFactor;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8004388;
    ptr->unk10 = &sub_8004434;

    gUnknown_3001B58 = TRUE;
}

void sub_8003810(u16 idx, RGB_Union param_2)
{
    unkStruct_3000C00 *a = &gUnknown_3000C00[idx / 16];
    a->unk0 = TRUE;

    gUnknown_3000400[idx] = param_2;
    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_8003844(u16 idx1, u16 idx2)
{
    unkStruct_3000C00 *a = &gUnknown_3000C00[idx1 / 16];
    a->unk0 = TRUE;

    gUnknown_3000400[idx1].asArr = GbaColorToRGB(idx2);
    gUnknown_3001B58 = TRUE;
}

void sub_800388C(u16 idx1, RGB_Union *param_2, s32 param_3)
{
    unkStruct_3000C00 *ptr3;
    s32 i;
    u16 idx2 = idx1 / 16;
    u16 sVar2 = (idx1 + param_3 - 1) / 16;
    RGB_Union *ptr1 = &gUnknown_3000400[idx1];

    for (i = 0; i < param_3; param_2++, ptr1++, i++)
    {
        *ptr1 = *param_2;
    }

    ptr3 = &gUnknown_3000C00[idx2];

    for (i = idx2; i <= sVar2; i++, ptr3++)
    {
        ptr3->unk0 = TRUE;
    }

    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_80038F0(u32 param_1, s16 *param_2, s32 param_3)
{
    u16 idx1;
    u16 idx2;
    u16 uVar;
    RGB_Union *ptr1;
    unkStruct_3000C00 *ptr2;
    s32 i;

    idx1 = param_1;
    idx2 = idx1 / 16;
    uVar = (idx1 + param_3 - 1) / 16;
    ptr1 = &gUnknown_3000400[idx1];

    for (i = 0; i < param_3; i++)
    {
        ptr1->asArr = GbaColorToRGB(*param_2++);
        ptr1++;
    }

    ptr2 = &gUnknown_3000C00[idx2];

    for (i = idx2; i <= uVar; i++, ptr2++)
    {
        ptr2->unk0 = TRUE;
    }

    gUnknown_3001B58 = TRUE;
}

static UNUSED RGB_Array sub_8003978(u16 idx)
{
    return gUnknown_3000400[idx].asArr;
}

static UNUSED u16 sub_8003988(u16 idx)
{
    return RGBToGbaColor(gUnknown_3000400[idx].asArr);
}

static UNUSED void sub_80039A4(u16 idx)
{
    gUnknown_3001B5A |= idx;
}

void sub_80039B8(void)
{
    s32 i;

    if (gUnknown_3001B58) {
        unkStruct_3000C00* ptr1 = gUnknown_3000C00;
        if (gUnknown_3000C00[0xf].unk0) {
            gUnknown_3000C00[UNK_3000C00_ARR_COUNT - 1].unk0 = TRUE;
        }

        for (i = 0; i < UNK_3000C00_ARR_COUNT - 1; i++, ptr1++) {
            if (ptr1->unk0) {
                ptr1->unk10(i);
                ptr1->unk0 = FALSE;
            }
        }

        if (gUnknown_3000C00[UNK_3000C00_ARR_COUNT - 1].unk0) {
            unkStruct_3000C00 *ptr2 = &gUnknown_3000C00[UNK_3000C00_ARR_COUNT - 1];
            // here ptr2 == ptr1
            ptr1->unkC(0x20, 0xf0);
            ptr2->unk0 = FALSE;
        }

        gUnknown_3001B5A = 3;
        gUnknown_3001B58 = FALSE;
    }
}

void sub_8003A34(u16 param_1, u16 idx)
{
    RGB_Array *rgb = &gUnknown_3000400[idx].asArr;
    u16 color = RGB_TO_GBA2(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);

    SetBGPaletteBufferColor(idx, &color);
}

void sub_8003A74(u16 param_1)
{
    s32 i;
    u16 color;
    u16 idx = param_1 * 16;
    RGB_Array *rgb = &gUnknown_3000400[idx].asArr;

    for (i = 0; i < 16; rgb++, i++) {
        color = RGB_TO_GBA(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
        SetBGPaletteBufferColor(idx + i, &color);
    }
}

void sub_8003AC0(u16 idx1, u16 idx2)
{
    u16 color;
    unkStruct_3000C00 *ptr2 = &gUnknown_3000C00[idx1];
    u16 fadeFactor = ptr2->fadeFactor;
    RGB_Array *rgb = &gUnknown_3000400[idx2].asArr;

    if (fadeFactor > 255) {
        color = RGB_TO_GBA2(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
    }
    else if (fadeFactor == 0) {
        color = RGB_BLACK;
    }
    else {
        color = RGB_TO_GBA((rgb->c[RGB_R] * fadeFactor) / 256,
                          (rgb->c[RGB_G] * fadeFactor) / 256,
                          (rgb->c[RGB_B] * fadeFactor) / 256);
    }

    SetBGPaletteBufferColor(idx2, &color);
}

void sub_8003B50(u16 param1)
{
    u16 color;
    s32 i;
    unkStruct_3000C00 *ptr1 = &gUnknown_3000C00[param1];
    u16 fadeFactor = ptr1->fadeFactor;
    u16 id = param1 * 16;
    RGB_Array *rgb = &gUnknown_3000400[id].asArr;

    if (fadeFactor > 255) {
        for (i = 0; i < 16; rgb++, i++) {
            color = RGB_TO_GBA(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
    else if (fadeFactor == 0) {
        color = RGB_BLACK;
        for (i = 0; i < 16; rgb++, i++) {
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
    else {
        for (i = 0; i < 16; rgb++, i++) {
            color = RGB_TO_GBA((rgb->c[RGB_R] * fadeFactor) / 256,
                          (rgb->c[RGB_G] * fadeFactor) / 256,
                          (rgb->c[RGB_B] * fadeFactor) / 256);
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
}

void sub_8003C18(u16 fadeIdx, u16 paletteIdx)
{
    u16 color;
    unkStruct_3000C00 *fade = &gUnknown_3000C00[fadeIdx];
    u16 fadeFactor = fade->fadeFactor;
    RGB_Array fadeRGB = fade->unk4;
    RGB_Array *paletteRGB = &gUnknown_3000400[paletteIdx].asArr;

    if (fadeFactor > 0xFF) {
        // Just use the palette color directly
        color = RGB_TO_GBA2(paletteRGB->c[RGB_R], paletteRGB->c[RGB_G], paletteRGB->c[RGB_B]);
    }
    else if (fadeFactor == 0) {
        // Fully faded to target color
        color = RGB_TO_GBA2(fadeRGB.c[RGB_R], fadeRGB.c[RGB_G], fadeRGB.c[RGB_B]);
    }
    else {
        // Blend
        u16 invFade = 256 - fadeFactor;
        s32 invFadeR = fadeRGB.c[RGB_R] * invFade;
        s32 invFadeG = fadeRGB.c[RGB_G] * invFade;
        s32 invFadeB = fadeRGB.c[RGB_B] * invFade;
        color = RGB_TO_GBA2((paletteRGB->c[RGB_R] * fadeFactor + invFadeR) / 256,
                            (paletteRGB->c[RGB_G] * fadeFactor + invFadeG) / 256,
                            (paletteRGB->c[RGB_B] * fadeFactor + invFadeB) / 256);
    }

    SetBGPaletteBufferColor(paletteIdx, &color);
}
