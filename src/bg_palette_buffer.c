#include "global.h"
#include "bg_palette_buffer.h"
#include "cpu.h"

#define BG_PALETTE_BUFFER_SIZE 512
#define BG_PALETTE_BUFFER_CHUNK_SIZE 16

static EWRAM_DATA bool8 sBGPaletteUsed[BG_PALETTE_BUFFER_SIZE / BG_PALETTE_BUFFER_CHUNK_SIZE] = {0};
static EWRAM_DATA u16 sBGPaletteBuffer[BG_PALETTE_BUFFER_SIZE] = {0};

void InitBGPaletteBuffer(void)
{
    s32 i;

    for (i = 0; i < BG_PALETTE_BUFFER_SIZE; i++) {
        sBGPaletteBuffer[i] = 0;
    }

    for (i = 0; i < BG_PALETTE_BUFFER_SIZE / BG_PALETTE_BUFFER_CHUNK_SIZE; i++) {
        sBGPaletteUsed[i] = TRUE;
    }
}

// 99.48% (r3/r4 regswap) https://decomp.me/scratch/7Yc8i
void SetBGPaletteBufferColorRGB(s32 index, const u8 *colorArray, s32 a1, u8 *a2)
{
    #ifdef NONMATCHING
    s32 var;
    #else
    register s32 var asm("r1");
    #endif // NONMATCHING

    if (a1 < 0)
        a1 = 0;
    if (a1 > 31)
        a1 = 31;

    sBGPaletteUsed[index / 16] = 1;

    if (a2 == NULL)
        sBGPaletteBuffer[index] = var = ((colorArray[2] * a1 / 256 & 0x1F) << 10) | ((colorArray[1] * a1 / 256 & 0x1F) << 5) | (colorArray[0] * a1 / 256 & 0x1F);
    else
        sBGPaletteBuffer[index] = var = ((a2[4 * colorArray[2] + 2] * a1 / 256 & 0x1F) << 10) | ((a2[4 * colorArray[1] + 1] * a1 / 256 & 0x1F) << 5) | (a2[4 * colorArray[0]] * a1 / 256 & 0x1F);
}

void SetBGPaletteBufferColorArray(s32 index, const u8 *colorArray)
{
    sBGPaletteUsed[index / BG_PALETTE_BUFFER_CHUNK_SIZE] = TRUE;
    sBGPaletteBuffer[index] = (colorArray[2] >> 3) << 10 | (colorArray[1] >> 3) << 5 | colorArray[0] >> 3;
}

void SetBGPaletteBufferColor(s32 index, u16 *color)
{
    sBGPaletteUsed[index / BG_PALETTE_BUFFER_CHUNK_SIZE] = TRUE;
    sBGPaletteBuffer[index] = *color;
}

void nullsub_4(s32 index, const u8 *colorArray, s32 a1, u8 *a2)
{
}

void nullsub_5(void)
{
}

UNUSED static void nullsub_143(void)
{
}

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
        if (sBGPaletteUsed[i])
        {
            sBGPaletteUsed[i] = 0;
            CpuCopy(dest, &sBGPaletteBuffer[paletteBufferIndex], sizeof(u16) * 16);
        }
        ++i;
        dest += 16;
        paletteBufferIndex += 16;
    }
    while (paletteBufferIndex < BG_PALETTE_BUFFER_SIZE);
}
