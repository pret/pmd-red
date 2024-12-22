#ifndef GUARD_CODE_8002774_H
#define GUARD_CODE_8002774_H

#include "structs/str_position.h"

s32 sub_8002A70(s32 a0, s32 a1, s32 a2);
s32 sub_8002B04(s32, s32);
s32 VecDirection8Sign(PixelPos *param_1);
s32 VecDirection4SignYX(PixelPos *param_1);
s8 VecDirection8Radial(PixelPos *param_1);
s8 VecDirection4Radial(PixelPos *param_1);
s8 SizedDeltaDirection4(PixelPos *r0, PixelPos *r1, PixelPos *r2, PixelPos *r3);
s8 SizedDeltaDirection8(PixelPos *r0, PixelPos *r1, PixelPos *r2, PixelPos *r3);

#endif
