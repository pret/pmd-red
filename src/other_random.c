#include "global.h"
#include "other_random.h"

EWRAM_DATA_2 u16 gOtherRngState = {0};

static s32 OtherRandom16(void)
{
    gOtherRngState = 109 * gOtherRngState + 1021;
    return gOtherRngState;
}

s32 OtherRandInt(s32 cap)
{
    return (OtherRandom16() * cap) >> 16;
}

s32 OtherRandRange(s32 a, s32 b)
{
    return OtherRandInt(b - a) + a;
}
