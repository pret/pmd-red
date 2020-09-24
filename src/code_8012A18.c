#include "global.h"

extern u8 gUnknown_80F42D0[];
extern u8 gUnknown_80F42F0[];
extern u8 gUnknown_203B408;

u8 sub_803D0D8()
{
    return gUnknown_203B408;
}

void sub_803D0E4(u8 r0)
{
    gUnknown_203B408 = r0;
}

u8 sub_803D0F0(u8 r0)
{
    return gUnknown_80F42F0[r0];
}

u8 sub_803D100(u8 r0)
{
    return gUnknown_80F42D0[r0];
}
