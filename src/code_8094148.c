#include "global.h"

s32 *sub_8094268(s32 *param_1, s32 param_2, s32 param_3)
{
    s32 x;
    s32 y;
    u16 z;

    y = param_2;

    x = ((y >> 0x10) + (param_3 >> 0x10)) << 0x10;
    y = (y & 0x0000ffff) | x;
    z = y + param_3;
    y = (y & 0xffff0000) | z;

    if ((y >> 0x10) > 999) {
        u16 b;
        s32 c;

        b = y + 1;
        y = (y & 0xffff0000) | b;
        c = ((y >> 0x10) - 1000) << 0x10;
        y = (y & 0x0000ffff) | c;
    }

    *param_1 = y;
    return param_1;
}

#ifdef NONMATCHING
// https://decomp.me/scratch/RUfc2 (99.52% matching)
s32* sub_80942C0(s32* param_1, s32 param_2, s32 param_3)
{
    s32 x;
    s32 y;
    u16 z;
    s32* dest;

    dest = param_1;
    y = param_2;

    x = ((y >> 0x10) - (param_3 >> 0x10)) << 0x10;
    y = (y & 0x0000ffff) | x;
    z = y - param_3;
    y = (y & 0xffff0000) | z;

    if (y < 0) {
        u16 b;
        s32 c;
        b = (y - 1);
        y = (y & 0xffff0000) | b;

        c = ((y >> 0x10) + 1000) << 0x10;

        y = (y & 0x0000ffff) | c;
    }

    if ((y << 0x10) < 0) {
        y = 0;
    }

    *dest = y;
    return dest;
}
#else
NAKED
void sub_80942C0(s32* param_1, s32 param_2, s32 param_3)
{
    asm_unified(
    "\tpush {r4,r5,lr}\n"
    "\tadds r5, r0, 0\n"
    "\tadds r3, r1, 0\n"
    "\tasrs r0, r3, 16\n"
    "\tasrs r1, r2, 16\n"
    "\tsubs r0, r1\n"
    "\tlsls r0, 16\n"
    "\tldr r4, _08094310\n"
    "\tands r3, r4\n"
    "\torrs r3, r0\n"
    "\tsubs r2, r3, r2\n"
    "\tlsls r2, 16\n"
    "\tlsrs r2, 16\n"
    "\tldr r1, _08094314\n"
    "\tands r3, r1\n"
    "\torrs r3, r2\n"
    "\tcmp r3, 0\n"
    "\tbge _080942FC\n"
    "\tsubs r0, r3, 0x1\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tands r3, r1\n"
    "\torrs r3, r0\n"
    "\tasrs r0, r3, 16\n"
    "\tmovs r2, 0xFA\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r2\n"
    "\tlsls r0, 16\n"
    "\tands r3, r4\n"
    "\torrs r3, r0\n"
    "_080942FC:\n"
    "\tlsls r0, r3, 16\n"
    "\tcmp r0, 0\n"
    "\tbge _08094304\n"
    "\tmovs r3, 0\n"
    "_08094304:\n"
    "\tstr r3, [r5]\n"
    "\tadds r0, r5, 0\n"
    "\tpop {r4,r5}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "_08094310: .4byte 0x0000ffff\n"
    "_08094314: .4byte 0xffff0000\n"
    );
}
#endif

s32* sub_8094318(s32* param_1, s32 param_2, s32 param_3)
{
    s16 a;
    s16 b;

    a = param_3;
    b = param_2;

    if ((b > a) || (b >= a && (param_2 >> 0x10 > param_3 >> 0x10))) {
        *param_1 = param_3;
    }
    else {
        *param_1 = param_2;
    }

    return param_1;
}

s32* sub_8094344(s32* param_1, s32 param_2, s32 param_3)
{
    s16 a;
    s16 b;

    a = param_3;
    b = param_2;

    if ((b > a) || (b >= a && (param_2 >> 0x10 > param_3 >> 0x10)))
    {
        *param_1 = param_2;
    }
    else
    {
        *param_1 = param_3;
    }

    return param_1;
}
