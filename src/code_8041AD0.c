#include "global.h"

extern void sub_804151C(u32 r0, u32 r1, u32 r2);
extern void sub_80421C0(u32 r0, u32 r1);
extern void sub_806CDD4(u32 r0, u8, u8);

void sub_8041AD0(u32 r0)
{
    sub_804151C(r0, 0xA2 << 1, 1);
}

void sub_8041AE0(u32 r0)
{
    sub_804151C(r0, 0x143, 1);
}

void sub_8041AF4(u32 r0)
{
    sub_804151C(r0, 0x25, 1);
    sub_80421C0(r0, 0x197);
}

void nullsub_57(void)
{
}

void sub_8041B18(u32 r0)
{
    sub_804151C(r0, 0x141, 1);
}

void nullsub_58(void)
{
}

void nullsub_59(void)
{
}

void sub_8041B34(u32 r0)
{
    sub_804151C(r0, 7, 1);
}

void nullsub_60(void)
{
}

void sub_8041B48(u32 r0)
{
    sub_804151C(r0, 4, 0);
}

void nullsub_61(void)
{
}

void sub_8041B5C(u32 r0)
{
    sub_804151C(r0, 0x171, 1);
}

void nullsub_62(void)
{
}

void sub_8041B74(u32 r0)
{
    sub_804151C(r0, 0x171, 0);
}

void nullsub_63(void)
{
}

void nullsub_64(void)
{
}

void sub_8041B90(u32 r0)
{
    sub_804151C(r0, 0xD6 << 1, 0);
}

void nullsub_65(void)
{
}

void nullsub_66(void)
{
}

void sub_8041BA8(u32 r0)
{
    sub_804151C(r0, 4, 1);
}

void nullsub_67(void)
{
}

void sub_8041BBC(u32 r0)
{
    sub_804151C(r0, 0xD4 << 1, 1);
}

void nullsub_68(void)
{
}

void sub_8041BD0(u32 r0, u8 r1)
{
    if(r1 == 0)
    {
        return;
    }
    sub_80421C0(r0, 0x1a5);
}

void sub_8041BE8(u32 r0)
{
    sub_80421C0(r0, 0xCB << 1);
}

void sub_8041BF8(u32 r0)
{
    sub_806CDD4(r0, 0xA, 8);
}

void sub_8041C08(u32 r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void sub_8041C1C(u32 r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void nullsub_69(void)
{
}

void sub_8041C34(u32 r0)
{
    sub_804151C(r0, 0x4C, 1);
}

void nullsub_70(void)
{
}

void nullsub_71(void)
{
}

void sub_8041C4C(u32 r0, u32 r1)
{
    sub_804151C(r0, r1, 1);
}

void sub_8041C58(u32 r0)
{
    sub_804151C(r0, 0x1a9, 1);
}

void sub_8041C6C(u32 r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void sub_8041C7C(u32 r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void nullsub_72(void)
{
}

void nullsub_73(void)
{
}
