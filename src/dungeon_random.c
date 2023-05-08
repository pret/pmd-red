#include "global.h"
#include "dungeon_random.h"

EWRAM_DATA_2 u32 gDungeonRngState = {0};

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

