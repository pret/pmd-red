#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

#include "structs/rgb.h"

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, const Rgb32 *color, s32 brightness, const Rgb32 *ramp);
void nullsub_5(s32 index, const Rgb32 *color);
void SetBGPaletteBufferColorArray(s32 index, const Rgb32 *color);
void SetBGPaletteBufferColorRGB(s32 index, const Rgb32 *color, s32 brightness, const Rgb32 *ramp);
void TransferBGPaletteBuffer(void);

#endif // GUARD_BG_PALETTE_BUFFER_H
