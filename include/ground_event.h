#ifndef GUARD_GROUND_EVENT_H
#define GUARD_GROUND_EVENT_H

#include "structs/str_position.h"

static inline void SetUnkInGroundEvent(const CompactPos *posPtr, PixelPos *dst)
{
    if (!(posPtr->xFlags & 4)) {
        s32 x = posPtr->xTiles << 11;
        dst->x = x;
        if (posPtr->xFlags & 2) {
            dst->x += 0x400;
        }
    }
    if (!(posPtr->yFlags & 4)) {
        s32 y = posPtr->yTiles << 11;
        dst->y = y;
        if (posPtr->yFlags & 2) {
            dst->y += 0x400;
        }
    }
}

s16 FindGroundEvent(u32 flags, PixelPos *arg1, PixelPos *arg2);

#endif // GUARD_GROUND_EVENT_H
