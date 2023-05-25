#include "global.h"

extern void sub_8082FE0(u32, void *, u32);
extern void sub_8082FA8(void *, void *, u32);


void nullsub_98()
{}

void sub_808300C(u32 *param_1, u32 *param_2)
{
    sub_8082FA8(param_1, param_2, 8);
}

void sub_8083018(u32 param_1)
{
    u8 auStack_10 [12];

    sub_8082FE0(param_1,auStack_10,8);
    auStack_10[8] = 0;
}

void sub_8083030(u32 *param_1, u32 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,2);
}

void sub_8083048(u32 *param_1, u32 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,2);
}

void sub_8083060(u32 *param_1, u32 param_2)
{
    u8 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,1);
}

void sub_8083078(u32 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_808308C(u32 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_80830A0(u32 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_80830B4(u32 *param_1, u8 param_2)
{
    u8 local_8;

    local_8 = (param_2 != 0) ? -1 : 0;
    sub_8082FA8(param_1,&local_8,1);
}

void sub_80830D8(u32 *param_1, u16 *param_2)
{
    sub_8082FA8(param_1, &param_2[0], 1);
    sub_8082FA8(param_1, &param_2[1], 1);
}

void sub_80830F8(u32 *param_1, u32 *param_2)
{
    sub_8082FA8(param_1, &param_2[0], 1);
    sub_8082FA8(param_1, &param_2[1], 1);
    sub_8082FA8(param_1, &param_2[2], 1);
    sub_8082FA8(param_1, &param_2[3], 1);
}

void sub_808312C(u32 *param_1, u16 *param_2)
{
    sub_8082FA8(param_1, &param_2[0], 1);
    sub_8082FA8(param_1, &param_2[1], 1);
}

void sub_808314C(u32 *param_1, u32 *param_2, u32 param_3)
{
    sub_8082FA8(param_1, param_2, param_3);
}

u16 sub_8083158(u32 param_1)
{
    u16 local_8;

    sub_8082FE0(param_1,&local_8,2);
    return local_8;
}

s16 sub_8083170(u32 param_1)
{
    s16 local_8;

    sub_8082FE0(param_1,&local_8,2);
    return local_8;
}

u8 sub_8083188(u32 param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8;
}

u32 sub_80831A0(u32 param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,&local_8,4);
    return local_8;
}

u32 sub_80831B4(u32 param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,&local_8,4);
    return local_8;
}

u32 sub_80831C8(u32 param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,&local_8,4);
    return local_8;
}

bool8 sub_80831DC(u32 param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8 != 0;
}

void sub_80831F8(u32 param_1,u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    sub_8082FE0(param_1,&param_2[0],1);
    sub_8082FE0(param_1,&param_2[1],1);
}


void sub_8083220(u32 param_1,u32 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    sub_8082FE0(param_1,&param_2[0],1);
    sub_8082FE0(param_1,&param_2[1],1);
    sub_8082FE0(param_1,&param_2[2],1);
    sub_8082FE0(param_1,&param_2[3],1);
}

void sub_8083260(u32 param_1,u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    sub_8082FE0(param_1,&param_2[0],1);
    sub_8082FE0(param_1,&param_2[1],1);
}

void sub_8083288(u32 r0, u16 *r1, u32 r2)
{
    sub_8082FE0(r0, r1, r2);
}

