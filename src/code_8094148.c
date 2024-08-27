#include "global.h"

typedef struct unkStruct_8094148
{
    s16 unk0;
    s16 unk2;
} unkStruct_8094148;

unkStruct_8094148 *sub_8094268(unkStruct_8094148* param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    param_2.unk2 += param_3.unk2;
    param_2.unk0 += param_3.unk0;

    if (param_2.unk2 > 999)
    {
        param_2.unk0++;
        param_2.unk2 -= 1000;
    }

    *param_1 = param_2;
    return param_1;
}

unkStruct_8094148 *sub_80942C0(unkStruct_8094148* param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    param_2.unk2 -= param_3.unk2;
    param_2.unk0 -= param_3.unk0;

    if (param_2.unk2 < 0)
    {
        param_2.unk0--;
        param_2.unk2 += 1000;
    }

    if (param_2.unk0 < 0)
    {
        param_2.unk0 = 0;
        param_2.unk2 = 0;
    }

    *param_1 = param_2;
    return param_1;
}

unkStruct_8094148 *sub_8094318(unkStruct_8094148* param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    if (param_2.unk0 > param_3.unk0
    || (param_2.unk0 >= param_3.unk0 && param_2.unk2 > param_3.unk2))
    {
        *param_1 = param_3;
    }
    else
    {
        *param_1 = param_2;
    }

    return param_1;
}

unkStruct_8094148 *sub_8094344(unkStruct_8094148* param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    if (param_2.unk0 > param_3.unk0
    || (param_2.unk0 >= param_3.unk0 && param_2.unk2 > param_3.unk2))
    {
        *param_1 = param_2;
    }
    else
    {
        *param_1 = param_3;
    }

    return param_1;
}

unkStruct_8094148 *sub_8094370(unkStruct_8094148* param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    unkStruct_8094148 p;

    p.unk0 = param_2.unk0;
    p.unk2 = param_3.unk0;

    if (p.unk2 > 999)
    {
        p.unk2 = 999;
    }

    *param_1 = p;
    return param_1;
}

void sub_80943A0(unkStruct_8094148* param_1, unkStruct_8094148 param_2)
{
    unkStruct_8094148 p;
    p.unk0 = param_2.unk0;
    p.unk2 = 0;
    *param_1 = p;
}

struct unkStruct_80943A8
{
    s32 s0;
    s32 s4;
} unkStruct_80943A8;

unkStruct_8094148 *sub_80943A8(unkStruct_8094148 *param_1, struct unkStruct_80943A8* param_2)
{
    unkStruct_8094148 s;
    s32 x;

    s.unk0 = param_2->s4 >> 0x10;

    x = param_2->s4 & 0xffff;
    s.unk2 = (1000 * x) >> 0x10;

    *param_1 = s;
    return param_1;
}

unkStruct_8094148 *sub_80943DC(unkStruct_8094148 *param_1, unkStruct_8094148 param_2, unkStruct_8094148 param_3)
{
    s32 div;

    div = (1000 * param_2.unk0 + param_2.unk2);
    div *= (1000 * param_3.unk0 + param_3.unk2);
    div /= 1000;

    param_2.unk0 = div / 1000;
    param_2.unk2 = div % 1000;

    *param_1 = param_2;
    return param_1;
}
