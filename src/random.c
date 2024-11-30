#include "global.h"
#include "globaldata.h"
#include "random.h"

EWRAM_DATA_2 s32 gPRNGSequenceNum = {0};

void SeedRng(u8 *seed)
{
    gPRNGSequenceNum = 54021 + (seed[0] * seed[1]) + (seed[2] * seed[3]) + (seed[4] * seed[5]);
}

static s16 Rand16Bit(void)
{
    gPRNGSequenceNum = 1566083941 * gPRNGSequenceNum + 1;
    return gPRNGSequenceNum >> 16;
}

s32 Rand32Bit(void)
{
    s32 r1 = Rand16Bit();
    s32 r2 = Rand16Bit();
    return (r1 << 16) | r2;
}

// Returns a random number in the range [0, cap).
s32 RandInt(s32 cap)
{
    return (((Rand32Bit() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}

// Returns a random number between a and b.
s32 RandRange(s32 a, s32 b)
{
    if (a == b)
        return a;

    if (a < b)
        return RandInt(b - a) + a;

    return RandInt(a - b) + b;
}

s32 GetRNGSeed(void)
{
    return gPRNGSequenceNum;
}

void SetRNGSeed(s32 state)
{
    gPRNGSequenceNum = state;
    gPRNGSequenceNum = Rand32Bit();
}
