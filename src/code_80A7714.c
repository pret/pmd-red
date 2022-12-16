#include "global.h"

extern void sub_80A68A0(void);
extern void sub_80A7094(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_80A7310(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_80A7784();
extern s16 gUnknown_2039DE0;

extern u32 gUnknown_8117EFC;
extern u32 *gMapScriptTable[];

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

u8 sub_80A77A0(s16 r0)
{
    s32 temp;
    s32 temp2;
    temp = r0;
    temp2 = temp;
    if(gUnknown_2039DE0 != temp)
    {
        if(temp < 0)
        {
            sub_80A7784();

        }
        else
        {
            sub_80A7764(temp2);
        }
        return 1;
    }
    return 0;
}

// TODO review this later
u32 *sub_80A77D0(s16 r0)
{
    if(r0 != -1)
    {
        return gMapScriptTable[r0];
    }
    else
    {
        return &gUnknown_8117EFC;
    }
}
