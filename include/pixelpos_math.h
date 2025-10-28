#ifndef GUARD_PIXELPOS_MATH_H
#define GUARD_PIXELPOS_MATH_H

#include "structs/str_position.h"

void ClampPixelPos(PixelPos *pos, s32 limit);
void InterpolatePixelPos(PixelPos *out, const PixelPos *a, const PixelPos *b, s32 weightA, s32 weightB);

#endif // GUARD_PIXELPOS_MATH_H
