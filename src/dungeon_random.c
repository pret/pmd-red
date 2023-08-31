#include "global.h"
#include "dungeon_random.h"

EWRAM_DATA_2 u32 gDungeonRngState = {0};
EWRAM_DATA_2 u32 gUnknown_203B458 = {0};

void sub_808408C(u32 param_1)
{
    gUnknown_203B458 = (1 | param_1) & 0xffffff;
}

u32 sub_80840A4(void)
{
    u32 r0;
    u32 r1;

    r1 = gUnknown_203B458 * 0x5d588b65;
    r1++;
    r0 = r1 >> 16;
    r1 *= 0x5d588b65;
    r1++;
    gUnknown_203B458 = r1;
    r1 &= 0xffff0000;
    r0 |= r1;
    r0 &= 0x0ffffff;
    r0 |= 1;
    return r0;
}

void InitDungeonRNG(u32 value)
{
    gDungeonRngState = (value | 1);
}

s32 DungeonRand16Bit(void)
{
    gDungeonRngState = 1566083941 * gDungeonRngState + 1;
    return gDungeonRngState >> 16;
}

s32 DungeonRandInt(s32 cap)
{
    return (((DungeonRand16Bit() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}

s32 DungeonRandRange(s32 low, s32 high)
{
    if(low == high)
        return low;
    else if(low < high)
    {
        return (DungeonRandInt(high - low) + low);
    }
    else
    {
        return (DungeonRandInt(low - high) + high);
    }
}

bool8 DungeonRandOutcome(s32 percentChance)
{
    if (DungeonRandInt(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 DungeonRandOutcome_2(s32 percentChance)
{
    if (DungeonRandInt(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

