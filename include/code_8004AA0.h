#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "structs/str_202EE8C.h"
#include "structs/str_file_system.h"

extern AnimatedColor gDungeonAnimatedColors[32];

// size: Variable
typedef struct AnimatedColorData
{
    s16 colorCount; // how many colors to cycle through (pointed by colors)
    s16 duration;   // duration of each color
    RGB_Struct colors[0];  // color data
} AnimatedColorData;

void nullsub_6(void);
void ReadAnimatedColorData(AnimatedColor *, OpenedFile *, s32);
bool8 UpdateAnimatedColors(bool8, AnimatedColor *, s32, s32, s32, const RGB_Struct *);
bool8 sub_8004C00(AnimatedColor *a0, s32 a1, s32 a2, s32 brightness, const RGB_Struct *ramp, RGB_Struct16 *a5);
bool8 sub_8004D14(AnimatedColor *, s32);
bool8 sub_8004D40(AnimatedColor *, s32);

#endif // GUARD_CODE_8004AA0_H
