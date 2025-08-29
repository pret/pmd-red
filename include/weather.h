#ifndef GUARD_WEATHER_H
#define GUARD_WEATHER_H

#include "structs/dungeon_entity.h"

u8 GetApparentWeather(Entity *pokemon);
void sub_807E5E4(u8 weather);
void sub_807E7FC(bool8 r0);
void sub_807E88C(void);
void sub_807E8F0(Entity *pokemon);
void GetWeatherName(u8 *buffer, u8 weather);
void MudWaterSportEffect(u8 which);
bool8 sub_807EAA0(bool8 arg0, bool8 arg1);

#endif
