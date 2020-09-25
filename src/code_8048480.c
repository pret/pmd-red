#include "global.h"

extern void sub_807D148(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_8075FCC(void);
extern void sub_8077AE4(u32 r0, u32 r1, u32 r2);
extern void sub_8072008(u32 r0, u32 r1, u32 r2, u32 r3);

void sub_8048480(u32 r0, u32 r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(void)
{
    sub_8075FCC();
}

void sub_804849C(u32 r0, u32 r1)
{
    sub_8077AE4(r0, r1, 1);
}
