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
