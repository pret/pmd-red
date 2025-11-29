#include "global.h"
#include "globaldata.h"
#include "other_random.h"

EWRAM_INIT u16 gOtherRngState = {0x348C}; // NDS=020EAC58

// arm9.bin::020127F4
static s32 OtherRandom16(void)
{
    gOtherRngState = 109 * gOtherRngState + 1021;
    return gOtherRngState;
}

// arm9.bin::020127DC
s32 OtherRandInt(s32 exclusiveMax)
{
    return (OtherRandom16() * exclusiveMax) >> 16;
}

// arm9.bin::020127C4
s32 OtherRandRange(s32 a, s32 b)
{
    return OtherRandInt(b - a) + a;
}
