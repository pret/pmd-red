#include "global.h"
#include "dungeon_random.h"

extern u32 gDungeonRngState;

void SetDungeonRNG(u32 value)
{
    gDungeonRngState = (value | 1);
}

s32 DungeonRandom(void)
{
    gDungeonRngState = 1566083941 * gDungeonRngState + 1;
    return gDungeonRngState >> 16;
}

s32 DungeonRandomCapped(s32 cap)
{
    return (((DungeonRandom() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}

s32 DungeonRandomRange(s32 low, s32 high)
{
    if(low == high)
        return low;
    else if(low < high)
    {
        return (DungeonRandomCapped(high - low) + low);
    }
    else
    {
        return (DungeonRandomCapped(low - high) + high);
    }
}

bool8 RollPercentChance(s32 percentChance)
{
    if (DungeonRandomCapped(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 RollPercentChance_2(s32 percentChance)
{
    if (DungeonRandomCapped(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

