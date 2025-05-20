#ifndef GUARD_GROUND_LIVES_H
#define GUARD_GROUND_LIVES_H

#include "structs/str_position.h"

struct Struct3001B84_sub120
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
};

// ground_lives.s
s32 sub_80A7AE8(s16);
s32 sub_80A8FD8(s32 id_, PixelPos *pixelPos);

#endif // GUARD_GROUND_LIVES_H
