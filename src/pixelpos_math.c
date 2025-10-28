#include "global.h"
#include "globaldata.h"
#include "pixelpos_math.h"

UNUSED static const u8 sUnusedZeroArray[28] = {0};

// arm9.bin::02010314
void ClampPixelPos(PixelPos *pos, s32 limit)
{
    if (pos->x > limit)
        pos->x = limit;
    else if (pos->x < -limit)
        pos->x = -limit;

    if (pos->y > limit)
        pos->y = limit;
    else if (pos->y < -limit)
        pos->y = -limit;
}

// arm9.bin::020102B8
void InterpolatePixelPos(PixelPos *out, const PixelPos *a, const PixelPos *b, s32 weightA, s32 weightB)
{
    s32 weight = (weightA + weightB);
    out->x = (weightA * a->x + weightB * b->x) / weight;
    out->y = (weightA * a->y + weightB * b->y) / weight;
}
