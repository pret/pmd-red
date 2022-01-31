#include "global.h"
#include "dungeon_engine.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"

bool8 IsFixedDungeon()
{
    if (gDungeonGlobalData->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}
