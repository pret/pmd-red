#ifndef GUARD_DIRECTION_UTIL_H
#define GUARD_DIRECTION_UTIL_H

#include "structs/str_position.h"

s32 sub_8002984(s32 _direction1, u32 caseID);
s32 sub_8002A70(s32 _direction1, s32 _direction2, s32 _caseId);
s32 sub_8002B04(s32 _direction1, s32 _direction2);
PixelPos SetVecFromDirectionSpeed(s32 _dir, u32 speed);
s32 VecDirection8Radial(PixelPos *pixelPos);
s8 SizedDeltaDirection4(const PixelPos *p1, const PixelPos *p2, const PixelPos *p3, const PixelPos *p4);
s8 SizedDeltaDirection8(const PixelPos *p1, const PixelPos *p2, const PixelPos *p3, const PixelPos *p4);

#endif // GUARD_DIRECTION_UTIL_H
