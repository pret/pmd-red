#include "global.h"
#include "weather.h"

#include "constants/item.h"
#include "constants/weather.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_random.h"

extern void TriggerWeatherAbilities(void);
extern void sub_807EAA0(u32, u32);
void sub_807E5E4(u8);

u8 GetWeather(struct DungeonEntity* pokemon)
{
    if (pokemon != NULL && HasItem(pokemon, ITEM_ID_WEATHER_BAND))
    {
        return WEATHER_CLEAR;
    }
    return gDungeonGlobalData->weather;
}

void sub_807E5AC(void)
{
    u8 weather;
    weather = gDungeonGlobalData->unk1C578;
    if(weather == WEATHER_RANDOM)
        weather = DungeonRandomCapped(WEATHER_RANDOM);
    sub_807E5E4(weather);
    TriggerWeatherAbilities();
    sub_807EAA0(0, 1);
}

void sub_807E5E4(u8 weather)
{
  int index;
  u8 *preload;

  gDungeonGlobalData->unkE265 = weather;
  gDungeonGlobalData->weather = gDungeonGlobalData->unkE265;
  gDungeonGlobalData->unkE279 = 0;
  for(index = 0; index < 8; index++) {
    gDungeonGlobalData->unkE267[index] = 0;
    gDungeonGlobalData->startingWeather[index] = 0;
  }
  preload = &gDungeonGlobalData->weatherDamageTimer;
  index = 0;
  *preload = 9;
  gDungeonGlobalData->mudSportTurnsLeft = 0;
  gDungeonGlobalData->waterSportTurnsLeft = 0;
  for(index = 0; index < 0x100; index++)
  {
    gDungeonGlobalData->unk17C[index].unk0 = index;
    gDungeonGlobalData->unk17C[index].unk1 = index;
    gDungeonGlobalData->unk17C[index].unk2 = index;
  }
}
