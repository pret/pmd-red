#include "global.h"
#include "weather.h"

#include "constants/item.h"
#include "constants/weather.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"

u8 GetWeather(struct DungeonEntity* pokemon)
{
    if (pokemon != NULL && HasItem(pokemon, ITEM_ID_WEATHER_BAND))
    {
        return WEATHER_CLEAR;
    }
    return gDungeonGlobalData->weather;
}
