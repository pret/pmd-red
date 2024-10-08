#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, const u8 *colorArray, s32, u8 *);
void nullsub_5(s32 index, const u8 *colorArray);
void SetBGPaletteBufferColorArray(s32 index, const u8 *colorArray);
void SetBGPaletteBufferColorRGB(s32 index, const u8 *colorArray, s32, u8 *);
void TransferBGPaletteBuffer(void);

#endif // GUARD_BG_PALETTE_BUFFER_H
