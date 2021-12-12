#include "global.h"
#include "dungeon_random.h"

extern s32 DungeonRandom(void);

s32 DungeonRandomCapped(s32 cap)
{
    return (((DungeonRandom() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}
