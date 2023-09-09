#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, u8 *colorArray, s32, u8 *);
void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);
void SetBGPaletteBufferColorRGB(s32 index, u8 *colorArray, s32, u8 *);

#endif // GUARD_BG_PALETTE_BUFFER_H