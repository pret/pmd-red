#include "global.h"
#include "weather.h"

#include "constants/item.h"
#include "constants/move_id.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_util.h"

extern void TriggerWeatherAbilities(void);
extern void sub_807EAA0(u32, u32);
void sub_807E5E4(u8);

u8 GetApparentWeather(Entity *pokemon)
{
    if (pokemon != NULL && HasHeldItem(pokemon, ITEM_WEATHER_BAND))
    {
        return WEATHER_CLEAR;
    }
    return gDungeon->weather.weather;
}

void sub_807E5AC(void)
{
    u8 weather;
    weather = gDungeon->unk1C574.unk4;
    if(weather == WEATHER_RANDOM)
        weather = DungeonRandInt(WEATHER_RANDOM);
    sub_807E5E4(weather);
    TriggerWeatherAbilities();
    sub_807EAA0(0, 1);
}

void sub_807E5E4(u8 weather)
{
  int index;
  u8 *preload;

  gDungeon->weather.unkE265 = weather;
  gDungeon->weather.weather = gDungeon->weather.unkE265;
  gDungeon->weather.nullifyWeather = FALSE;
  for(index = 0; index < 8; index++) {
    gDungeon->weather.unkE267[index] = 0;
    gDungeon->weather.naturalWeather[index] = 0;
  }
  preload = &gDungeon->weather.weatherDamageCounter;
  index = 0;
  *preload = 9;
  gDungeon->weather.mudSportTurns = 0;
  gDungeon->weather.waterSportTurns = 0;
  for(index = 0; index < 0x100; index++)
  {
    gDungeon->unk17C[index].unk0 = index;
    gDungeon->unk17C[index].unk1 = index;
    gDungeon->unk17C[index].unk2 = index;
  }
}
