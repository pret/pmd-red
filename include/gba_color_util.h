#ifndef GUARD_GBA_COLOR_UTIL_H
#define GUARD_GBA_COLOR_UTIL_H

#include "structs/rgb.h"

u16 RGBToGbaColor(RGB_Array s);
RGB_Array GbaColorToRGB(u16 color);

#endif // GUARD_GBA_COLOR_UTIL_H
