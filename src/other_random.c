#include "global.h"
#include "other_random.h"

extern u16 gOtherRngState;

static s32 OtherRandom16(void)
{
    gOtherRngState = 109 * gOtherRngState + 1021;
    return gOtherRngState;
}

s32 OtherRandomCapped(s32 cap)
{
    return (OtherRandom16() * cap) >> 16;
}

s32 OtherRandomRange(s32 a, s32 b)
{
    return OtherRandomCapped(b - a) + a;
}
