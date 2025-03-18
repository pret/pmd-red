#include "global.h"
#include "bg_palette_buffer.h"
#include "cpu.h"

#define BG_PALETTE_BUFFER_SIZE 512
#define BG_PALETTE_ROW_SIZE 16

static EWRAM_DATA bool8 sBGPaletteRowDirty[BG_PALETTE_BUFFER_SIZE / BG_PALETTE_ROW_SIZE] = {0};
static EWRAM_DATA u16 sBGPaletteBuffer[BG_PALETTE_BUFFER_SIZE] = {0};

void InitBGPaletteBuffer(void)
{
    s32 i;

    for (i = 0; i < BG_PALETTE_BUFFER_SIZE; i++) {
        sBGPaletteBuffer[i] = 0;
    }

    for (i = 0; i < BG_PALETTE_BUFFER_SIZE / BG_PALETTE_ROW_SIZE; i++) {
        sBGPaletteRowDirty[i] = TRUE;
    }
}

// arm9.bin::020011A0
void SetBGPaletteBufferColorRGB(s32 index, const RGB *color, s32 brightnessRaw, const RGB *ramp)
{
    s32 brightness = brightnessRaw;

    if (brightness < 0)
        brightness = 0;
    if (brightness > 31)
        brightness = 31;

    sBGPaletteRowDirty[index / BG_PALETTE_ROW_SIZE] = TRUE;

    if (ramp == NULL)
        sBGPaletteBuffer[index] = RGB2(
            color->r * brightness / 256 & 0x1F,
            color->g * brightness / 256 & 0x1F,
            color->b * brightness / 256 & 0x1F);
    else
        sBGPaletteBuffer[index] = RGB2(
            ramp[color->r].r * brightness / 256 & 0x1F,
            ramp[color->g].g * brightness / 256 & 0x1F,
            ramp[color->b].b * brightness / 256 & 0x1F);
}

// arm9.bin::02001130
void SetBGPaletteBufferColorArray(s32 index, const RGB *color32)
{
    sBGPaletteRowDirty[index / BG_PALETTE_ROW_SIZE] = TRUE;
    sBGPaletteBuffer[index] = RGB2(color32->r >> 3, color32->g >> 3, color32->b >> 3);
}

// arm9.bin::020010EC
void SetBGPaletteBufferColor(s32 index, u16 *color)
{
    sBGPaletteRowDirty[index / BG_PALETTE_ROW_SIZE] = TRUE;
    sBGPaletteBuffer[index] = *color;
}

// arm9.bin::02000FC8
void nullsub_4(s32 index, const RGB *colorArray, s32 brightness, const RGB *ramp)
{
}

// arm9.bin::02000F58
void nullsub_5(s32 index, const RGB *colorArray)
{
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void nullsub_143(void)
{
}
#endif

// arm9.bin::02000E9C
void TransferBGPaletteBuffer(void)
{
    u32 i;
    s32 paletteBufferIndex;
    u16 *dest;

    i = 0;
    paletteBufferIndex = 0;
    dest = (u16 *)PLTT;
    do
    {
        if (sBGPaletteRowDirty[i])
        {
            sBGPaletteRowDirty[i] = 0;
            CpuCopy(dest, &sBGPaletteBuffer[paletteBufferIndex], sizeof(u16) * BG_PALETTE_ROW_SIZE);
        }
        ++i;
        dest += BG_PALETTE_ROW_SIZE;
        paletteBufferIndex += BG_PALETTE_ROW_SIZE;
    }
    while (paletteBufferIndex < BG_PALETTE_BUFFER_SIZE);

    // NDS version has a second loop for the 2nd screen (0x5000400 dest instead)
}
