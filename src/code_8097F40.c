#include "global.h"

extern u8 gDungeonWaterType[];

bool8 sub_8097F40(u32 r0)
{
    return gDungeonWaterType[r0] == 2;
}
