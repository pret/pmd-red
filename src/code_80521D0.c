#include "global.h"

extern void sub_80526D0(u8 r0);
extern u8 sub_8045888(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_80523A8(u32 r0, u32 r1, u8 r2);

void sub_805229C(void)
{
    return sub_80526D0(0x50);
}

void sub_80522A8(u32 r0, u32 r1, u32 r2, u32 r3)
{
    if ((sub_8045888(r0, r1, r2, r3) << 24) != 0){
        sub_80523A8(r0, r1, 1);
    }
}

void sub_80522C8(u32 r0, u32 r1, u32 r2, u32 r3)
{
    if ((sub_8045888(r0, r1, r2, r3) << 24) != 0){
        sub_80523A8(r0, r1, 0);
    }
}

void sub_80522E8(u32 r0, u32 r1)
{
    sub_80523A8(r0, r1, 0);
}
