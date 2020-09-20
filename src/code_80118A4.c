#include "global.h"

extern void sub_8011924(void);
extern void sub_801199C(u16 r0);
extern void sub_800BFD0(u8 r0);
extern void sub_800C3F8(u16 r0, u8 r1);

void sub_80118A4(void)
{
    sub_8011924();
    sub_801199C(0x3e6);
    sub_801199C(0x3e5);
}
