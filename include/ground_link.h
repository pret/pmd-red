#ifndef GUARD_GROUND_LINK_H
#define GUARD_GROUND_LINK_H

#include "structs/str_position.h"

void GroundLink_Select(s16 r0);
s32 GroundLink_GetPos(s32 _arg0, PixelPos *pos);
s32 GroundLink_GetArea(s32 _arg0, PixelPos *arg1, PixelPos *arg2, PixelPos *arg3);

#endif // GUARD_GROUND_LINK_H
