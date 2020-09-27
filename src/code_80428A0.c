#include "global.h"

extern void sub_804151C(u32 r0, u32 r1, u32 r2);
extern void sub_803E708(u32 r0, u32 r1);
extern void sub_80416A4(u32 r0, u32 r1, u32 r2);
extern void sub_80421C0(u32 r0, u32 r1);

void sub_80428A0(u32 r0)
{
    sub_804151C(r0, 0x29, 1);
}

void sub_80428B0(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428C4(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428D8(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80428EC(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_8042900(u32 r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void sub_8042910(u32 r0)
{
    sub_804151C(r0, 0x29, 0);
}

void sub_8042920(u32 r0)
{
    sub_804151C(r0, 0x48, 0);
}

void sub_8042930(u32 r0)
{
    sub_804151C(r0, 0xD3 << 1, 1);
}

void sub_8042940(u32 r0)
{
    sub_804151C(r0, 0xC7 << 1, 0);
}

void sub_8042950(u32 r0)
{
    sub_804151C(r0, 0xD8 << 1, 1);
    sub_803E708(0xA, 0x42);
}

void sub_8042968(u32 r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void sub_8042978(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_804298C(u32 r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80429A0(u32 r0)
{
    sub_804151C(r0, 0x199, 0);
}

void sub_80429B4(u32 r0)
{
    sub_804151C(r0, 0x1ab, 0);
}

void sub_80429C8(u32 r0)
{
    sub_804151C(r0, 0x4, 1);
}

void sub_80429D8(u32 r0)
{
    sub_804151C(r0, 0x8F << 1, 1);
}

void sub_80429E8(u32 r0)
{
    sub_804151C(r0, 0x11d, 1);
}

void sub_80429FC(u32 r0)
{
    sub_80416A4(r0, 0xCF << 1, 1);
    sub_80421C0(0, 0xD4);
}

void sub_8042A14(u32 r0)
{
    sub_80416A4(r0, 0x36, 1);
}

void sub_8042A24(u32 r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8042A34(u32 r0)
{
    sub_80416A4(r0, 0x9F << 1, 0);
}

void sub_8042A44(u32 r0)
{
    sub_804151C(r0, 0xDA << 1, 1);
}

void sub_8042A54(u32 r0)
{
    sub_80416A4(r0, 0x37, 1);
}

void sub_8042A64(u32 r0)
{
    sub_80416A4(r0, 0x29, 1);
}

void sub_8042A74(u32 r0)
{
    sub_804151C(r0, 0x18, 1);
}
