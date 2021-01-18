#include "global.h"

extern s32 sub_80908D8(u32);

s32 sub_803C1B4(s32 r0, u8 r1)
{
    s32 temp;
    temp = sub_80908D8(r0);
    if(r1 == 2)
    {
        temp += 2;
    }
    if(temp > 0xF)
        temp = 0xF;
    return temp;
}

