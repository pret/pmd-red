#ifndef GUARD_STR_202EE8C_H
#define GUARD_STR_202EE8C_H

#include "structs/rgb.h"

// size: 0x18
typedef struct AnimatedColor
{
    u32 flags;
    u16 duration;
    s16 timer;
    RGB_Struct *colorsStart;
    RGB_Struct *currentColor;
    RGB_Struct *colorsEnd;
    RGB_Struct color;
} AnimatedColor;

#endif // GUARD_STR_202EE8C_H
