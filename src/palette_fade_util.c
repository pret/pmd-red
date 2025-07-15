#include "global.h"
#include "globaldata.h"
#include "palette_fade_util.h"
#include "bg_palette_buffer.h"
#include "gba_color_util.h"

static IWRAM_INIT bool8 sUpdatePaletteFade = FALSE;
static IWRAM_INIT u16 sUnusedPaletteUpdateFlags = 0;

typedef struct PaletteFadeEntry
{
    bool8 active;
    s16 fadeAmount;
    RGB_Array fadeColor;
    RGB_Array *fadeColorArray;
    void (*applyFadeToSingle)(u16, u16);
    void (*applyFadeToRow)(u16);
} PaletteFadeEntry;

#define MAX_FADE_AMOUNT 256

#define PALETTE_COLOR_COUNT 0x200
#define PALETTE_FADE_ENTRY_COUNT 0x21

static IWRAM_DATA RGB_Union sRGBPaletteBuffer[PALETTE_COLOR_COUNT] = {0};
static IWRAM_DATA PaletteFadeEntry sPaletteFadeTable[PALETTE_FADE_ENTRY_COUNT] = {0};

static void ApplySinglePalette(u16 param_1, u16 idx);
static void ApplySinglePaletteBrightness(u16, u16);
static void BlendSinglePalette(u16, u16);
static void FadeToBlackSingle(u16, u16);
static void PerEntryBlendSingle(u16, u16);
static void DesaturateSingle(u16 fadeIndex, u16);
static void ModulatePaletteSingle(u16, u16);
static void ApplyRowPaletteBrightness(u16);
static void BlendRowPalette(u16);
static void FadeToBlackRow(u16);
static void PerEntryBlendRow(u16);
static void DesaturateRow(u16);
static void ModulatePaletteRow(u16);
static void ApplyRowPalette(u16);

NAKED
UNUSED static void sub_80035F8(void)
{
    asm_unified("	.text\n"
"	push {lr}\n"
"	pop {r0}\n"
"	bx r0\n");
}

void InitPaletteFadeTable(void)
{
    PaletteFadeEntry *it1;
    RGB_Union *it2;
    bool8 *r6;
    s32 i;
    s32 zero;

    it1 = &sPaletteFadeTable[0];
    r6 = &sUpdatePaletteFade;
    zero = 0;
    it2 = &sRGBPaletteBuffer[0];

    for (i = 0; i < PALETTE_COLOR_COUNT; it2++, i++)
    {
        it2->asArr.c[0] = zero;
        it2->asArr.c[1] = zero;
        it2->asArr.c[2] = zero;
        it2->asArr.c[3] = zero;
    }

    for (i = 0; i < PALETTE_FADE_ENTRY_COUNT; i++, it1++)
    {
        it1->active = FALSE;
        it1->fadeAmount = 256;
        it1->fadeColor.c[0] = 0;
        it1->fadeColor.c[1] = 0;
        it1->fadeColor.c[2] = 0;
        it1->fadeColor.c[3] = 0;
        it1->fadeColorArray = 0;
        it1->applyFadeToSingle = &ApplySinglePalette;
        it1->applyFadeToRow = &ApplyRowPalette;
    }

    *r6 = TRUE;
}

void SetPaletteFade_Brightness(u16 idx, s32 fadeAmount)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor.c[0] = 0;
    ptr->fadeColor.c[1] = 0;
    ptr->fadeColor.c[2] = 0;
    ptr->fadeColor.c[3] = 0;
    ptr->fadeColorArray = 0;
    ptr->applyFadeToSingle = &ApplySinglePaletteBrightness;
    ptr->applyFadeToRow = &ApplyRowPaletteBrightness;

    sUpdatePaletteFade = TRUE;
}

void SetPaletteFade_Blend(u16 idx, s32 fadeAmount, RGB_Array param_3)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor = param_3;
    ptr->fadeColorArray = 0;
    ptr->applyFadeToSingle = &BlendSinglePalette;
    ptr->applyFadeToRow = &BlendRowPalette;

    sUpdatePaletteFade = TRUE;
}

void SetPaletteFade_FadeToBlack(u16 idx, s32 fadeAmount, RGB_Array param_3)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor = param_3;
    ptr->fadeColorArray = 0;
    ptr->applyFadeToSingle = &FadeToBlackSingle;
    ptr->applyFadeToRow = &FadeToBlackRow;

    sUpdatePaletteFade = TRUE;
}

static UNUSED void SetPaletteFade_PerEntryBlend(u16 idx, s32 fadeAmount, RGB_Array *param_3)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor.c[0] = 0;
    ptr->fadeColor.c[1] = 0;
    ptr->fadeColor.c[2] = 0;
    ptr->fadeColor.c[3] = 0;
    ptr->fadeColorArray = param_3;
    ptr->applyFadeToSingle = &PerEntryBlendSingle;
    ptr->applyFadeToRow = &PerEntryBlendRow;

    sUpdatePaletteFade = TRUE;
}

void SetPaletteFade_Desaturate(u16 idx, s32 fadeAmount, RGB_Array param_3)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor = param_3;
    ptr->fadeColorArray = 0;
    ptr->applyFadeToSingle = &DesaturateSingle;
    ptr->applyFadeToRow = &DesaturateRow;

    sUpdatePaletteFade = TRUE;
}

void SetPaletteFade_Modulate(u16 idx, s32 fadeAmount, RGB_Array param_3)
{
    PaletteFadeEntry *ptr = &sPaletteFadeTable[idx];

    ptr->active = TRUE;
    ptr->fadeAmount = fadeAmount;
    ptr->fadeColor = param_3;
    ptr->fadeColorArray = 0;
    ptr->applyFadeToSingle = &ModulatePaletteSingle;
    ptr->applyFadeToRow = &ModulatePaletteRow;

    sUpdatePaletteFade = TRUE;
}

void sub_8003810(u16 idx, RGB_Array param_2)
{
    PaletteFadeEntry *a = &sPaletteFadeTable[idx / 16];
    a->active = TRUE;

    sRGBPaletteBuffer[idx].asArr = param_2;
    sUpdatePaletteFade = TRUE;
}

static UNUSED void sub_8003844(u16 idx1, u16 idx2)
{
    PaletteFadeEntry *a = &sPaletteFadeTable[idx1 / 16];
    a->active = TRUE;

    sRGBPaletteBuffer[idx1].asArr = GbaColorToRGB(idx2);
    sUpdatePaletteFade = TRUE;
}

void sub_800388C(u16 idx1, const RGB_Union *param_2, s32 param_3)
{
    PaletteFadeEntry *ptr3;
    s32 i;
    u16 idx2 = idx1 / 16;
    u16 sVar2 = (idx1 + param_3 - 1) / 16;
    RGB_Union *ptr1 = &sRGBPaletteBuffer[idx1];

    for (i = 0; i < param_3; param_2++, ptr1++, i++)
    {
        *ptr1 = *param_2;
    }

    ptr3 = &sPaletteFadeTable[idx2];

    for (i = idx2; i <= sVar2; i++, ptr3++)
    {
        ptr3->active = TRUE;
    }

    sUpdatePaletteFade = TRUE;
}

static UNUSED void sub_80038F0(u32 param_1, s16 *param_2, s32 param_3)
{
    u16 idx1;
    u16 idx2;
    u16 uVar;
    RGB_Union *ptr1;
    PaletteFadeEntry *ptr2;
    s32 i;

    idx1 = param_1;
    idx2 = idx1 / 16;
    uVar = (idx1 + param_3 - 1) / 16;
    ptr1 = &sRGBPaletteBuffer[idx1];

    for (i = 0; i < param_3; i++)
    {
        ptr1->asArr = GbaColorToRGB(*param_2++);
        ptr1++;
    }

    ptr2 = &sPaletteFadeTable[idx2];

    for (i = idx2; i <= uVar; i++, ptr2++)
    {
        ptr2->active = TRUE;
    }

    sUpdatePaletteFade = TRUE;
}

static UNUSED RGB_Array sub_8003978(u16 idx)
{
    return sRGBPaletteBuffer[idx].asArr;
}

static UNUSED u16 sub_8003988(u16 idx)
{
    return RGBToGbaColor(sRGBPaletteBuffer[idx].asArr);
}

static UNUSED void sub_80039A4(u16 idx)
{
    sUnusedPaletteUpdateFlags |= idx;
}

void RunPaletteFadeFunctions(void)
{
    s32 i;

    if (sUpdatePaletteFade) {
        PaletteFadeEntry* ptr1 = sPaletteFadeTable;
        if (sPaletteFadeTable[0xf].active) {
            sPaletteFadeTable[PALETTE_FADE_ENTRY_COUNT - 1].active = TRUE;
        }

        for (i = 0; i < PALETTE_FADE_ENTRY_COUNT - 1; i++, ptr1++) {
            if (ptr1->active) {
                ptr1->applyFadeToRow(i);
                ptr1->active = FALSE;
            }
        }

        if (sPaletteFadeTable[PALETTE_FADE_ENTRY_COUNT - 1].active) {
            PaletteFadeEntry *ptr2 = &sPaletteFadeTable[PALETTE_FADE_ENTRY_COUNT - 1];
            // here ptr2 == ptr1
            ptr1->applyFadeToSingle(0x20, 0xf0);
            ptr2->active = FALSE;
        }

        sUnusedPaletteUpdateFlags = 1 | 2;
        sUpdatePaletteFade = FALSE;
    }
}

static void ApplySinglePalette(u16 param_1, u16 idx)
{
    RGB_Array *rgb = &sRGBPaletteBuffer[idx].asArr;
    u16 color = RGB_TO_GBA2(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);

    SetBGPaletteBufferColor(idx, &color);
}

static void ApplyRowPalette(u16 param_1)
{
    s32 i;
    u16 color;
    u16 idx = param_1 * 16;
    RGB_Array *rgb = &sRGBPaletteBuffer[idx].asArr;

    for (i = 0; i < 16; rgb++, i++) {
        color = RGB_TO_GBA(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
        SetBGPaletteBufferColor(idx + i, &color);
    }
}

static void ApplySinglePaletteBrightness(u16 idx1, u16 idx2)
{
    u16 color;
    PaletteFadeEntry *ptr2 = &sPaletteFadeTable[idx1];
    u16 fadeAmount = ptr2->fadeAmount;
    RGB_Array *rgb = &sRGBPaletteBuffer[idx2].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        color = RGB_TO_GBA2(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
    }
    else if (fadeAmount == 0) {
        color = RGB_BLACK;
    }
    else {
        color = RGB_TO_GBA((rgb->c[RGB_R] * fadeAmount) / 256,
                          (rgb->c[RGB_G] * fadeAmount) / 256,
                          (rgb->c[RGB_B] * fadeAmount) / 256);
    }

    SetBGPaletteBufferColor(idx2, &color);
}

static void ApplyRowPaletteBrightness(u16 param1)
{
    u16 color;
    s32 i;
    PaletteFadeEntry *ptr1 = &sPaletteFadeTable[param1];
    u16 fadeAmount = ptr1->fadeAmount;
    u16 id = param1 * 16;
    RGB_Array *rgb = &sRGBPaletteBuffer[id].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        for (i = 0; i < 16; rgb++, i++) {
            color = RGB_TO_GBA(rgb->c[RGB_R], rgb->c[RGB_G], rgb->c[RGB_B]);
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
    else if (fadeAmount == 0) {
        color = RGB_BLACK;
        for (i = 0; i < 16; rgb++, i++) {
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
    else {
        for (i = 0; i < 16; rgb++, i++) {
            color = RGB_TO_GBA((rgb->c[RGB_R] * fadeAmount) / 256,
                          (rgb->c[RGB_G] * fadeAmount) / 256,
                          (rgb->c[RGB_B] * fadeAmount) / 256);
            SetBGPaletteBufferColor(id + i, &color);
        }
    }
}

static void BlendSinglePalette(u16 fadeIdx, u16 paletteIdx)
{
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeRGB = fade->fadeColor;
    RGB_Array *paletteRGB = &sRGBPaletteBuffer[paletteIdx].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        // Just use the palette color directly
        color = RGB_TO_GBA2(paletteRGB->c[RGB_R], paletteRGB->c[RGB_G], paletteRGB->c[RGB_B]);
    }
    else if (fadeAmount == 0) {
        // Fully faded to target color
        color = RGB_TO_GBA2(fadeRGB.c[RGB_R], fadeRGB.c[RGB_G], fadeRGB.c[RGB_B]);
    }
    else {
        // Blend
        u16 invFade = 256 - fadeAmount;
        s32 invFadeR = fadeRGB.c[RGB_R] * invFade;
        s32 invFadeG = fadeRGB.c[RGB_G] * invFade;
        s32 invFadeB = fadeRGB.c[RGB_B] * invFade;
        color = RGB_TO_GBA2((paletteRGB->c[RGB_R] * fadeAmount + invFadeR) / 256,
                            (paletteRGB->c[RGB_G] * fadeAmount + invFadeG) / 256,
                            (paletteRGB->c[RGB_B] * fadeAmount + invFadeB) / 256);
    }

    SetBGPaletteBufferColor(paletteIdx, &color);
}

static void BlendRowPalette(u16 fadeIdx)
{
    s32 i;
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeRGB = fade->fadeColor;
    u16 basePaletteIdx = fadeIdx * 16;
    RGB_Array *paletteRGB = &sRGBPaletteBuffer[basePaletteIdx].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        // Just use the palette color directly
        for (i = 0; i < 16; paletteRGB++, i++) {
            color = RGB_TO_GBA(paletteRGB->c[RGB_R], paletteRGB->c[RGB_G], paletteRGB->c[RGB_B]);
            SetBGPaletteBufferColor(basePaletteIdx + i, &color);
        }
    }
    else if (fadeAmount == 0) {
        // Fully faded to target color
        color = RGB_TO_GBA2(fadeRGB.c[RGB_R], fadeRGB.c[RGB_G], fadeRGB.c[RGB_B]);
        for (i = 0; i < 16; paletteRGB++, i++) {
            SetBGPaletteBufferColor(basePaletteIdx + i, &color);
        }
    }
    else {
        // Blend
        u16 invFade = 256 - fadeAmount;
        s32 invFadeR = fadeRGB.c[RGB_R] * invFade;
        s32 invFadeG = fadeRGB.c[RGB_G] * invFade;
        s32 invFadeB = fadeRGB.c[RGB_B] * invFade;
        for (i = 0; i < 16; paletteRGB++, i++) {
            color = RGB_TO_GBA((paletteRGB->c[RGB_R] * fadeAmount + invFadeR) / 256,
                                (paletteRGB->c[RGB_G] * fadeAmount + invFadeG) / 256,
                                (paletteRGB->c[RGB_B] * fadeAmount + invFadeB) / 256);
            SetBGPaletteBufferColor(basePaletteIdx + i, &color);
        }
    }
}

static void FadeToBlackSingle(u16 fadeIdx, u16 targetIdx)
{
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeRGB = fade->fadeColor;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        color = RGB_TO_GBA2(fadeRGB.c[RGB_R], fadeRGB.c[RGB_G], fadeRGB.c[RGB_B]);
    }
    else if (fadeAmount == 0) {
        color = RGB_BLACK;
    }
    else {
        color = RGB_TO_GBA((fadeRGB.c[RGB_R] * fadeAmount) / 256,
                            (fadeRGB.c[RGB_G] * fadeAmount) / 256,
                            (fadeRGB.c[RGB_B] * fadeAmount) / 256);
    }

    SetBGPaletteBufferColor(targetIdx, &color);
}

static void FadeToBlackRow(u16 fadeIdx)
{
    u16 color;
    s32 i;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeColor = fade->fadeColor;
    u16 targetStartIdx = fadeIdx * 16;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        color = RGB_TO_GBA2(fadeColor.c[RGB_R], fadeColor.c[RGB_G], fadeColor.c[RGB_B]);
    }
    else if (fadeAmount == 0) {
        color = RGB_BLACK;
    }
    else {
        color = RGB_TO_GBA((fadeColor.c[RGB_R] * fadeAmount) / 256,
                            (fadeColor.c[RGB_G] * fadeAmount) / 256,
                            (fadeColor.c[RGB_B] * fadeAmount) / 256);
    }

    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColor(targetStartIdx + i, &color);
    }
}

static void PerEntryBlendSingle(u16 fadeIdx, u16 targetIdx)
{
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array *fadeSubColor = &fade->fadeColorArray[targetIdx % 16];
    RGB_Array *baseColor = &sRGBPaletteBuffer[targetIdx].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        color = RGB_TO_GBA2(baseColor->c[RGB_R], baseColor->c[RGB_G], baseColor->c[RGB_B]);
    }
    else if (fadeAmount == 0) {
        color = RGB_TO_GBA2(fadeSubColor->c[RGB_R], fadeSubColor->c[RGB_G], fadeSubColor->c[RGB_B]);
    }
    else {
        u16 invFade = 256 - fadeAmount;
        s32 r = fadeSubColor->c[RGB_R] * invFade + baseColor->c[RGB_R] * fadeAmount;
        s32 g = fadeSubColor->c[RGB_G] * invFade + baseColor->c[RGB_G] * fadeAmount;
        s32 b = fadeSubColor->c[RGB_B] * invFade + baseColor->c[RGB_B] * fadeAmount;
        color = RGB_TO_GBA2(r / 256, g / 256, b / 256);
    }

    SetBGPaletteBufferColor(targetIdx, &color);
}

static void PerEntryBlendRow(u16 fadeIdx)
{
    u16 color;
    s32 i;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIdx];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array *fadeColors = fade->fadeColorArray;
    u16 targetStartIdx = fadeIdx * 16;
    RGB_Array *baseColors = &sRGBPaletteBuffer[targetStartIdx].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        // Fully use base palette
        for (i = 0; i < 16; baseColors++, i++) {
            color = RGB_TO_GBA(baseColors->c[RGB_R], baseColors->c[RGB_G], baseColors->c[RGB_B]);
            ASM_MATCH_TRICK(i);
            SetBGPaletteBufferColor(targetStartIdx + i, &color);
        }
    }
    else if (fadeAmount == 0) {
        // Fully use fade palette
        for (i = 0; i < 16; fadeColors++, i++) {
            color = RGB_TO_GBA(fadeColors->c[RGB_R], fadeColors->c[RGB_G], fadeColors->c[RGB_B]);
            SetBGPaletteBufferColor(targetStartIdx + i, &color);
        }
    }
    else {
        // Blend fade and base
        u16 invFade = 256 - fadeAmount;

        for (i = 0; i < 16; baseColors++, fadeColors++, i++) {
            s32 r = fadeColors->c[RGB_R] * invFade + baseColors->c[RGB_R] * fadeAmount;
            s32 g = fadeColors->c[RGB_G] * invFade + baseColors->c[RGB_G] * fadeAmount;
            s32 b = fadeColors->c[RGB_B] * invFade + baseColors->c[RGB_B] * fadeAmount;
            color = RGB_TO_GBA(r / 256, g / 256, b / 256);
            SetBGPaletteBufferColor(targetStartIdx + i, &color);
        }
    }
}

static void DesaturateSingle(u16 fadeIndex, u16 targetIndex)
{
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIndex];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeColor = fade->fadeColor;
    RGB_Array *baseColor = &sRGBPaletteBuffer[targetIndex].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        // No fade, just use base color
        color = RGB_TO_GBA2(baseColor->c[RGB_R], baseColor->c[RGB_G], baseColor->c[RGB_B] );
    }
    else {
        u16 r, g, b;
        // Fading to black per channel

        r = fadeColor.c[RGB_R] + ((255 - fadeColor.c[RGB_R]) * fadeAmount) / 256;
        g = fadeColor.c[RGB_G] + ((255 - fadeColor.c[RGB_G]) * fadeAmount) / 256;
        b = fadeColor.c[RGB_B] + ((255 - fadeColor.c[RGB_B]) * fadeAmount) / 256;

        color = RGB_TO_GBA2((r * baseColor->c[RGB_R]) / 255, (g * baseColor->c[RGB_G]) / 255, (b * baseColor->c[RGB_B]) / 255);
    }

    SetBGPaletteBufferColor(targetIndex, &color);
}

static void DesaturateRow(u16 fadeIndex)
{
    s32 i;
    u16 color;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIndex];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeColor = fade->fadeColor;
    u16 targetIndex = fadeIndex * 16;
    RGB_Array *baseColor = &sRGBPaletteBuffer[targetIndex].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT) {
        for (i = 0; i < 16; baseColor++, i++) {
            // No fade, just use base color
            color = RGB_TO_GBA(baseColor->c[RGB_R], baseColor->c[RGB_G], baseColor->c[RGB_B]);
            SetBGPaletteBufferColor(targetIndex + i, &color);
        }
    }
    else {
        u16 r, g, b;
        // Fading to black per channel

        r = fadeColor.c[RGB_R] + ((255 - fadeColor.c[RGB_R]) * fadeAmount) / 256;
        g = fadeColor.c[RGB_G] + ((255 - fadeColor.c[RGB_G]) * fadeAmount) / 256;
        b = fadeColor.c[RGB_B] + ((255 - fadeColor.c[RGB_B]) * fadeAmount) / 256;
        for (i = 0; i < 16; baseColor++, i++) {
            color = RGB_TO_GBA((r * baseColor->c[RGB_R]) / 255, (g * baseColor->c[RGB_G]) / 255, (b * baseColor->c[RGB_B]) / 255);
            SetBGPaletteBufferColor(targetIndex + i, &color);
        }
    }
}

static void ModulatePaletteSingle(u16 fadeIndex, u16 paletteIndex)
{
    u16 color;
    u16 r, g, b;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIndex];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeColor = fade->fadeColor;
    RGB_Array *baseColor = &sRGBPaletteBuffer[paletteIndex].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT)
        fadeAmount = MAX_FADE_AMOUNT;

    r = fadeColor.c[RGB_R] * fadeAmount / 256;
    g = fadeColor.c[RGB_G] * fadeAmount / 256;
    b = fadeColor.c[RGB_B] * fadeAmount / 256;
    color = RGB_TO_GBA2((r * baseColor->c[RGB_R]) / 255, (g * baseColor->c[RGB_G]) / 255, (b * baseColor->c[RGB_B]) / 255);
    SetBGPaletteBufferColor(paletteIndex, &color);
}

static void ModulatePaletteRow(u16 fadeIndex)
{
    s32 i;
    u16 color;
    u16 r, g, b;
    PaletteFadeEntry *fade = &sPaletteFadeTable[fadeIndex];
    u16 fadeAmount = fade->fadeAmount;
    RGB_Array fadeColor = fade->fadeColor;
    u16 paletteIndex = fadeIndex * 16;
    RGB_Array *baseColors = &sRGBPaletteBuffer[paletteIndex].asArr;

    if (fadeAmount >= MAX_FADE_AMOUNT)
        fadeAmount = MAX_FADE_AMOUNT;

    r = fadeColor.c[RGB_R] * fadeAmount / 256;
    g = fadeColor.c[RGB_G] * fadeAmount / 256;
    b = fadeColor.c[RGB_B] * fadeAmount / 256;
    for (i = 0; i < 16; baseColors++, i++) {
        color = RGB_TO_GBA2((r * baseColors->c[RGB_R]) / 255, (g * baseColors->c[RGB_G]) / 255, (b * baseColors->c[RGB_B]) / 255);
        SetBGPaletteBufferColor(paletteIndex + i, &color);
    }
}
