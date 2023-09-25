#include "global.h"
#include "code_803D0D8.h"

static EWRAM_DATA_2 u8 sUnknown_203B408 = {0};

#include "data/code_803D0D8.h"

u8 sub_803D0D8()
{
    return sUnknown_203B408;
}

UNUSED static void sub_803D0E4(u8 a0)
{
    sUnknown_203B408 = a0;
}

u8 sub_803D0F0(u8 r0)
{
    return sUnknown_80F42F0[r0];
}

u8 sub_803D100(u8 r0)
{
    return sUnknown_80F42D0[r0];
}

// Probably continues in code_803D110.s