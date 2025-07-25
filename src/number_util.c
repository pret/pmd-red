#include "global.h"
#include "globaldata.h"
#include "number_util.h"

FixedPoint FixedPoint_Add(FixedPoint a, FixedPoint b)
{
    a.unk2 += b.unk2;
    a.unk0 += b.unk0;

    if (a.unk2 > 999)
    {
        a.unk0++;
        a.unk2 -= 1000;
    }

    return a;
}

FixedPoint FixedPoint_Subtract(FixedPoint a, FixedPoint b)
{
    a.unk2 -= b.unk2;
    a.unk0 -= b.unk0;

    if (a.unk2 < 0)
    {
        a.unk0--;
        a.unk2 += 1000;
    }

    if (a.unk0 < 0)
    {
        a.unk0 = 0;
        a.unk2 = 0;
    }

    return a;
}

FixedPoint FixedPoint_Min(FixedPoint a, FixedPoint b)
{
    if (a.unk0 > b.unk0
    || (a.unk0 >= b.unk0 && a.unk2 > b.unk2))
    {
        return b;
    }
    else
    {
        return a;
    }
}

FixedPoint FixedPoint_Max(FixedPoint a, FixedPoint b)
{
    if (a.unk0 > b.unk0
    || (a.unk0 >= b.unk0 && a.unk2 > b.unk2))
    {
        return a;
    }
    else
    {
        return b;
    }
}

FixedPoint sub_8094370(FixedPoint param_1, FixedPoint param_2)
{
    FixedPoint p;

    p.unk0 = param_1.unk0;
    p.unk2 = param_2.unk0;

    if (p.unk2 > 999)
    {
        p.unk2 = 999;
    }

    return p;
}

FixedPoint IntToFixedPoint(s32 a)
{
    FixedPoint p = IntToFixedPointMacro(a);
    return p;
}

FixedPoint FixedPoint_SetFromUnk(s48_16* param_1)
{
    FixedPoint s;

    s.unk0 = param_1->lo >> 0x10;
    s.unk2 = (1000 * (param_1->lo & 0xffff)) >> 0x10;

    return s;
}

FixedPoint FixedPoint_Div(FixedPoint a, FixedPoint b)
{
    s32 div;

    div = (1000 * a.unk0 + a.unk2);
    div *= (1000 * b.unk0 + b.unk2);
    div /= 1000;

    a.unk0 = div / 1000;
    a.unk2 = div % 1000;

    return a;
}

s32 FixedPointToInt(FixedPoint a) // Always rounded up
{
    if (a.unk0 == 0)
    {
        if (a.unk2 == 0)
        {
            return 0;
        }
        return 1;
    }
    else if (a.unk2 != 0)
    {
        return a.unk0 + 1;
    }
    else
    {
        return a.unk0;
    }
}

// arm9.bin::02064154
void ReadBellyBits(DataSerializer *r0, FixedPoint *dst)
{
    ReadBits(r0, &dst->unk0, 16);
    ReadBits(r0, &dst->unk2, 16);
}

// arm9.bin::02064124
void WriteBellyBits(DataSerializer *r0, FixedPoint *src)
{
    WriteBits(r0, &src->unk0, 16);
    WriteBits(r0, &src->unk2, 16);
}
