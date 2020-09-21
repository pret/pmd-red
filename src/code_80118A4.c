#include "global.h"

void sub_8011924(void);

extern void sub_800BDFC(u16 r0);
extern void sub_800BE8C(u16 r0, u16 r1);
extern void sub_800BF48(u16 r0);
extern void sub_800BF80(void);
extern void sub_800BFD0(u16 r0);
extern void sub_800C3F8(u16 r0, u16 r1);
extern void sub_801199C(u16 r0);
extern void sub_800C068(u16 r0);

void sub_80118A4(void)
{
    sub_8011924();
    sub_801199C(0x3e6);
    sub_801199C(0x3e5);
}

void sub_80118C4(u16 r0)
{
    sub_800BFD0(r0);
    sub_800C3F8(0x3e6, r0);
    sub_800C3F8(0x3e5, r0);
}

void sub_80118F0(u16 r0)
{
    sub_800BDFC(r0);
}

void sub_8011900(u16 r0, u16 r1)
{
    sub_800BE8C(r0, r1);
}

void sub_8011914(u16 r0)
{
    sub_800BF48(r0);
}

void sub_8011924()
{
    sub_800BF80();
}

void sub_8011930(u16 r0)
{
    sub_800BFD0(r0);
}
