#include "global.h"
#include "dungeon_engine.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"

bool8 IsBossBattle()
{
    if (gDungeonGlobalData->bossBattleIndex != 0 && gDungeonGlobalData->bossBattleIndex <= 0x31)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFixedDungeon()
{
    if (gDungeonGlobalData->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}