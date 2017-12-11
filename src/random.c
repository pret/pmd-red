#include "global.h"
#include "random.h"

extern s32 gRngState;

void SeedRng(u8 *seed)
{
    gRngState = 54021 + (seed[0] * seed[1]) + (seed[2] * seed[3]) + (seed[4] * seed[5]);
}

static s16 Random16(void)
{
    gRngState = 1566083941 * gRngState + 1;
    return gRngState >> 16;
}

s32 Random(void)
{
    s32 r1 = Random16();
    s32 r2 = Random16();
    return (r1 << 16) | r2;
}

// Returns a random number in the range [0, cap).
s32 RandomCapped(s32 cap)
{
    return (((Random() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}

// Returns a random number between a and b.
s32 RandomRange(s32 a, s32 b)
{
    if (a == b)
        return a;

    if (a < b)
        return RandomCapped(b - a) + a;

    return RandomCapped(a - b) + b;
}

s32 GetRngState(void)
{
    return gRngState;
}

void SetRngState(s32 state)
{
    gRngState = state;
    gRngState = Random();
}
