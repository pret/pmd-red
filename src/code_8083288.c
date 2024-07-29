#include "global.h"
#include "code_8092334.h"
#include "structs/str_position.h"

extern void sub_8082FA8(unkStruct_8094924 *, void *, u32);

void sub_8082FD4(unkStruct_8094924 *param_1, u8 *r1, u32 r2)
{
    param_1->unk0 = r1;
    param_1->unk8 = 0;
    param_1->unk4 = r1 + r2;
}

void sub_8082FE0(unkStruct_8094924 *param_1, u8 *param_2, s32 size) {
    while (size != 0) {
        *param_2 = *(param_1->unk0);
        param_1->unk0++;
        param_2++;
        size--;
        param_1->unk8++;
    } 
}

void nullsub_98(unkStruct_8094924 *param_1)
{}

void sub_808300C(unkStruct_8094924 *param_1, u8 *param_2)
{
    sub_8082FA8(param_1, param_2, 8);
}

void sub_8083018(unkStruct_8094924 *param_1)
{
    u8 auStack_10 [12];

    sub_8082FE0(param_1,auStack_10,8);
    auStack_10[8] = 0;
}

void sub_8083030(unkStruct_8094924 *param_1, u16 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,2);
}

void sub_8083048(unkStruct_8094924 *param_1, u32 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,2);
}

void sub_8083060(unkStruct_8094924 *param_1, u32 param_2)
{
    u8 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,1);
}

void sub_8083078(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_808308C(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_80830A0(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,4);
}

void sub_80830B4(unkStruct_8094924 *param_1, u8 param_2)
{
    u8 local_8;

    local_8 = (param_2 != 0) ? -1 : 0;
    sub_8082FA8(param_1,&local_8,1);
}

void SavePosition(unkStruct_8094924 *param_1, Position *param_2)
{
    sub_8082FA8(param_1, &param_2->x, 1);
    sub_8082FA8(param_1, &param_2->y, 1);
}

void sub_80830F8(unkStruct_8094924 *param_1, u32 *param_2)
{
    sub_8082FA8(param_1, &param_2[0], 1);
    sub_8082FA8(param_1, &param_2[1], 1);
    sub_8082FA8(param_1, &param_2[2], 1);
    sub_8082FA8(param_1, &param_2[3], 1);
}

void sub_808312C(unkStruct_8094924 *param_1, u16 *param_2)
{
    sub_8082FA8(param_1, &param_2[0], 1);
    sub_8082FA8(param_1, &param_2[1], 1);
}

void SaveSpeedCounters(unkStruct_8094924 *param_1, u32 *speedCounters, u32 numCounters)
{
    sub_8082FA8(param_1, speedCounters, numCounters);
}

u16 sub_8083158(unkStruct_8094924 *param_1)
{
    u16 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,2);
    return local_8;
}

s16 sub_8083170(unkStruct_8094924 *param_1)
{
    s16 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,2);
    return local_8;
}

u8 sub_8083188(unkStruct_8094924 *param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8;
}

u32 sub_80831A0(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

u32 sub_80831B4(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

u32 sub_80831C8(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

bool8 sub_80831DC(unkStruct_8094924 *param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8 != 0;
}

void sub_80831F8(unkStruct_8094924 *param_1,u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    sub_8082FE0(param_1,(u8 *)&param_2[0],1);
    sub_8082FE0(param_1,(u8 *)&param_2[1],1);
}


void sub_8083220(unkStruct_8094924 *param_1,u32 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    sub_8082FE0(param_1,(u8 *)&param_2[0],1);
    sub_8082FE0(param_1,(u8 *)&param_2[1],1);
    sub_8082FE0(param_1,(u8 *)&param_2[2],1);
    sub_8082FE0(param_1,(u8 *)&param_2[3],1);
}

void sub_8083260(unkStruct_8094924 *param_1,u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    sub_8082FE0(param_1,(u8 *)&param_2[0],1);
    sub_8082FE0(param_1,(u8 *)&param_2[1],1);
}

void sub_8083288(unkStruct_8094924 *r0, u16 *r1, u32 size)
{
    sub_8082FE0(r0, (u8 *)r1, size);
}

