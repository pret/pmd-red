#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, u8 *RGBArray, s32 a1, u8 *a2);
void SetBGPaletteBufferColorRGB(s32 index, u8 *RGBArray, s32 a1, u8 *a2);

#endif // GUARD_BG_PALETTE_BUFFER_H