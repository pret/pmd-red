#include "global.h"
#include "globaldata.h"
#include "random.h"

static EWRAM_INIT s32 sPRNGState = {1};

void SeedRng(u8 seed[6])
{
    sPRNGState = 54021 + (seed[0] * seed[1]) + (seed[2] * seed[3]) + (seed[4] * seed[5]);
}

static s16 Rand16Bit(void)
{
    sPRNGState = (1566083941 * sPRNGState) + 1;
    return sPRNGState >> 16;
}

s32 Rand32Bit(void)
{
    s32 a = Rand16Bit();
    s32 b = Rand16Bit();
    return (a << 16) | b;
}

s32 RandInt(s32 maxExclusive)
{
    return (((Rand32Bit() & 0xFFFF) * maxExclusive) >> 16) & 0xFFFF;
}

s32 RandRange(s32 minInclusive, s32 maxExclusive)
{
    if (minInclusive == maxExclusive)
        return minInclusive;
    else if (minInclusive < maxExclusive)
        return RandInt(maxExclusive - minInclusive) + minInclusive;
    else // minclusive > maxExclusive
        return RandInt(minInclusive - maxExclusive) + maxExclusive;
}

s32 GetRNGState(void)
{
    return sPRNGState;
}

void SetRNGSeed(s32 state)
{
    sPRNGState = state;
    sPRNGState = Rand32Bit();
}