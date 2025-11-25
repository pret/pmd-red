#ifndef GUARD_BG_PALETTE_BUFFER_H
#define GUARD_BG_PALETTE_BUFFER_H

#include "structs/rgb.h"

void InitBGPaletteBuffer(void);
void nullsub_4(s32 index, const RGB_Struct *color, s32 brightness, const RGB_Struct *ramp);
void nullsub_5(s32 index, const RGB_Struct *color);
void SetBGPaletteBufferColorArray(s32 index, const RGB_Struct *color);
void SetBGPaletteBufferColorRGB(s32 index, const RGB_Struct *color, s32 brightness, const RGB_Struct *ramp);
void SetBGPaletteBufferColor(s32 index, u16 *color);
void TransferBGPaletteBuffer(void);

#endif // GUARD_BG_PALETTE_BUFFER_H
