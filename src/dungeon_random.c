#include "global.h"
#include "dungeon_random.h"

extern s32 DungeonRandomCapped(s32);

bool8 RollPercentChance(s32 percentChance)
{
    if (DungeonRandomCapped(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}
