#include "global.h"

extern void GroundMap_GetStationScript(u32, s16, u32, u32);

void sub_80A4BE8(u32 r0, s16 r1)
{
    GroundMap_GetStationScript(r0, r1, 0, 0);
}