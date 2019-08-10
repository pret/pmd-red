#include "global.h"

#define BG_PALETTE_BUFFER_SIZE 512
#define BG_PALETTE_BUFFER_CHUNK_SIZE 16

extern u16 gBGPaletteBuffer[BG_PALETTE_BUFFER_SIZE];
extern bool8 gBGPaletteUsed[BG_PALETTE_BUFFER_SIZE / BG_PALETTE_BUFFER_CHUNK_SIZE];

extern void CpuCopy(void* src, void* dest, u32 size);

#ifndef NONMATCHING
NAKED
#endif
void InitBGPaletteBuffer(void)
{
#ifdef NONMATCHING
    u16 color = 0;
    u16* ptr;
    u32 i;
    bool8 paletteUsed;

    u8* p;

    ptr = gBGPaletteBuffer;

    i = 0x80;
    i <<= 2;

    do {
        *ptr++ = color;
        i--;
    } while (i);

    paletteUsed = TRUE;

    p = gBGPaletteUsed;
    p += 31;

    do
        *p-- = paletteUsed;
    while ((s32) p >= (s32) &gBGPaletteUsed);
#else
    asm_unified("\tpush {lr}\n"
        "\tmovs r2, 0\n"
        "\tldr r1, =gBGPaletteBuffer\n"
        "\tmovs r0, 0x80\n"
        "\tlsls r0, 2\n"
        "_0800463E:\n"
        "\tstrh r2, [r1]\n"
        "\tadds r1, 0x2\n"
        "\tsubs r0, 0x1\n"
        "\tcmp r0, 0\n"
        "\tbne _0800463E\n"
        "\tldr r1, =gBGPaletteUsed\n"
        "\tmovs r2, 0x1\n"
        "\tadds r0, r1, 0\n"
        "\tadds r0, 0x1F\n"
        "_08004650:\n"
        "\tstrb r2, [r0]\n"
        "\tsubs r0, 0x1\n"
        "\tcmp r0, r1\n"
        "\tbge _08004650\n"
        "\tpop {r0}\n"
        "\tbx r0\n"
        "\t.align 2, 0\n"
        "\t.pool");
#endif
}

#ifndef NONMATCHING
NAKED
#endif
void SetBGPaletteBufferColorRGB(s32 index, u8 *RGBArray, s32 a1, u8 *a2)
{
#ifdef NONMATCHING
    if (a1 < 0) {
        a1 = 0;
    }
    if (a1 > 31) {
        a1 = 31;
    }
    gBGPaletteUsed[index / 16] = 1;
    if (!a2) {
        gBGPaletteBuffer[index] = ((RGBArray[2] * a1 / 256 & 0x1F) << 10) | ((RGBArray[1] * a1 / 256 & 0x1F) << 5) | (RGBArray[0] * a1 / 256 & 0x1F);
    }
    else
    {
        gBGPaletteBuffer[index] = ((a2[4 * RGBArray[2] + 2] * a1 / 256 & 0x1F) << 10) | ((a2[4 * RGBArray[1] + 1] * a1 / 256 & 0x1F) << 5) | (a2[4 * RGBArray[0]] * a1 / 256 & 0x1F);
    }
#else
    asm_unified("\tpush {r4-r7,lr}\n"
        "\tadds r4, r0, 0\n"
        "\tadds r5, r1, 0\n"
        "\tcmp r2, 0\n"
        "\tbge _08004670\n"
        "\tmovs r2, 0\n"
        "_08004670:\n"
        "\tcmp r2, 0x1F\n"
        "\tble _08004676\n"
        "\tmovs r2, 0x1F\n"
        "_08004676:\n"
        "\tldr r1, =gBGPaletteUsed\n"
        "\tadds r0, r4, 0\n"
        "\tcmp r4, 0\n"
        "\tbge _08004680\n"
        "\tadds r0, 0xF\n"
        "_08004680:\n"
        "\tasrs r0, 4\n"
        "\tadds r0, r1\n"
        "\tmovs r1, 0x1\n"
        "\tstrb r1, [r0]\n"
        "\tcmp r3, 0\n"
        "\tbne _080046D4\n"
        "\tldr r0, =gBGPaletteBuffer\n"
        "\tlsls r1, r4, 1\n"
        "\tadds r6, r1, r0\n"
        "\tldrb r0, [r5, 0x2]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _0800469C\n"
        "\tadds r0, 0xFF\n"
        "_0800469C:\n"
        "\tasrs r0, 8\n"
        "\tmovs r3, 0x1F\n"
        "\tands r0, r3\n"
        "\tlsls r4, r0, 10\n"
        "\tldrb r0, [r5, 0x1]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _080046AE\n"
        "\tadds r0, 0xFF\n"
        "_080046AE:\n"
        "\tasrs r0, 8\n"
        "\tands r0, r3\n"
        "\tlsls r1, r0, 5\n"
        "\torrs r1, r4\n"
        "\tldrb r0, [r5]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _080046C0\n"
        "\tadds r0, 0xFF\n"
        "_080046C0:\n"
        "\tasrs r0, 8\n"
        "\tands r0, r3\n"
        "\torrs r1, r0\n"
        "\tstrh r1, [r6]\n"
        "\tb _08004722\n"
        "\t.align 2, 0\n"
        "\t.pool\n"
        "_080046D4:\n"
        "\tldr r1, =gBGPaletteBuffer\n"
        "\tlsls r0, r4, 1\n"
        "\tadds r7, r0, r1\n"
        "\tldrb r0, [r5, 0x2]\n"
        "\tlsls r0, 2\n"
        "\tadds r0, r3\n"
        "\tldrb r0, [r0, 0x2]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _080046EA\n"
        "\tadds r0, 0xFF\n"
        "_080046EA:\n"
        "\tasrs r0, 8\n"
        "\tmovs r4, 0x1F\n"
        "\tands r0, r4\n"
        "\tlsls r6, r0, 10\n"
        "\tldrb r0, [r5, 0x1]\n"
        "\tlsls r0, 2\n"
        "\tadds r0, r3\n"
        "\tldrb r0, [r0, 0x1]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _08004702\n"
        "\tadds r0, 0xFF\n"
        "_08004702:\n"
        "\tasrs r0, 8\n"
        "\tands r0, r4\n"
        "\tlsls r1, r0, 5\n"
        "\torrs r1, r6\n"
        "\tldrb r0, [r5]\n"
        "\tlsls r0, 2\n"
        "\tadds r0, r3\n"
        "\tldrb r0, [r0]\n"
        "\tmuls r0, r2\n"
        "\tcmp r0, 0\n"
        "\tbge _0800471A\n"
        "\tadds r0, 0xFF\n"
        "_0800471A:\n"
        "\tasrs r0, 8\n"
        "\tands r0, r4\n"
        "\torrs r1, r0\n"
        "\tstrh r1, [r7]\n"
        "_08004722:\n"
        "\tpop {r4-r7}\n"
        "\tpop {r0}\n"
        "\tbx r0\n"
        "\t.align 2, 0\n"
        "\t.pool");
#endif
}

void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray)
{
    gBGPaletteUsed[index / BG_PALETTE_BUFFER_CHUNK_SIZE] = TRUE;
    gBGPaletteBuffer[index] = (colorArray[2] >> 3) << 10 | (colorArray[1] >> 3) << 5 | colorArray[0] >> 3;
}

void SetBGPaletteBufferColor(s32 index, u16 *color)
{
    gBGPaletteUsed[index / BG_PALETTE_BUFFER_CHUNK_SIZE] = TRUE;
    gBGPaletteBuffer[index] = *color;
}

void nullsub_4(void)
{

}
void nullsub_5(void)
{

}
void nullsub_143(void)
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
        if (gBGPaletteUsed[i])
        {
            gBGPaletteUsed[i] = 0;
            CpuCopy(dest, &gBGPaletteBuffer[paletteBufferIndex], sizeof(u16) * 16);
        }
        ++i;
        dest += 16;
        paletteBufferIndex += 16;
    }
    while ( paletteBufferIndex < BG_PALETTE_BUFFER_SIZE );
}
