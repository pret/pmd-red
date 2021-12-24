#include "global.h"
#include "dungeon_random_1.h"

#include "dungeon_random.h"

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
