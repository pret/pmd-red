#ifndef GUARD_PALETTE_FADE_UTIL_H
#define GUARD_PALETTE_FADE_UTIL_H

#include "structs/rgb.h"

void InitPaletteFadeTable(void);
void SetPaletteFade_Brightness(u16 idx, s32 fadeAmount);
void SetPaletteFade_Blend(u16 idx, s32 fadeAmount, RGB_Array param_3);
void SetPaletteFade_FadeToBlack(u16 idx, s32 fadeAmount, RGB_Array param_3);
void SetPaletteFade_Desaturate(u16 idx, s32 fadeAmount, RGB_Array param_3);
void SetPaletteFade_Modulate(u16 idx, s32 fadeAmount, RGB_Array param_3);
void sub_8003810(u16 idx, RGB_Array param_2);
void sub_800388C(u16 idx1, const RGB_Union *param_2, s32 param_3);
void RunPaletteFadeFunctions(void);

#endif // GUARD_PALETTE_FADE_UTIL_H
