#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

#include "structs/rgb.h"

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, const RGB *color, s32 brightness, const RGB *ramp);
void nullsub_5(s32 index, const RGB *color);
void SetBGPaletteBufferColorArray(s32 index, const RGB *color);
void SetBGPaletteBufferColorRGB(s32 index, const RGB *color, s32 brightness, const RGB *ramp);
void SetBGPaletteBufferColor(s32 index, u16 *color);
void TransferBGPaletteBuffer(void);

#endif // GUARD_BG_PALETTE_BUFFER_H
