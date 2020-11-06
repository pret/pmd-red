#include "global.h"

extern void sub_80A68A0(void);
extern void sub_80A7094(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_80A7310(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_80A7784();
extern s16 gUnknown_2039DE0;

void sub_80A7714(void)
{
    sub_80A68A0();
}

void sub_80A7720(u32 r0, u32 r1, u32 r2)
{
    sub_80A7094(r0, 0, r1, r2);
    sub_80A7310(r0, r1, 0, r2);
}

void sub_80A7744(void)
{
    gUnknown_2039DE0 = -1;
}

void sub_80A7754(void)
{
    gUnknown_2039DE0 = -1;
}

void sub_80A7764(s16 r0)
{
    s32 temp = r0;
    sub_80A7784();
    if(temp != -1)
    {
        gUnknown_2039DE0 = temp;
    }
}

void sub_80A7784(void)
{
    if(gUnknown_2039DE0 != -1)
    {
        gUnknown_2039DE0 = -1;
    }
}
