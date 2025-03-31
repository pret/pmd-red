#include "global.h"
#include "globaldata.h"
#include "weather.h"
#include "constants/item.h"
#include "constants/move_id.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "code_804267C.h"
#include "code_803E46C.h"
#include "dungeon.h"
#include "dungeon_config.h"
#include "dungeon_leader.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "structs/map.h"
#include "dungeon_message.h"
#include "dungeon_logic.h"
#include "string_format.h"
#include "dungeon_logic.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_logic.h"
#include "position_util.h"
#include "dungeon_ai.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "code_805D8C8.h"
#include "code_803E668.h"
#include "dungeon_items.h"
#include "move_util.h"
#include "moves.h"
#include "math.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "dungeon_misc.h"
#include "code_807E5AC.h"
#include "sprite.h"
#include "dungeon_strings.h"

extern void TriggerWeatherAbilities(void);
extern void sub_804178C(u32);
extern void sub_803E874(bool8 r10, s32 r9);
extern s32 CalculateStatusTurns(Entity *target, const s16 *turnRange, bool8 factorCurerSkills);
extern void sub_80429D8(Entity *r0);
extern void sub_80838EC(u8 *a);

extern OpenedFile *gUnknown_202ECA0;

void sub_807E7FC(bool8 arg0);
void sub_807E8F0(Entity *pokemon);
void GetWeatherName(u8 *buffer, u8 weather);
bool8 sub_807EAA0(bool8 arg0, bool8 arg1);

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
    weather = gDungeon->floorProperties.unk4;
    if(weather == WEATHER_COUNT)
        weather = DungeonRandInt(WEATHER_COUNT);
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
    gDungeon->colorRamp[index].r = index;
    gDungeon->colorRamp[index].g = index;
    gDungeon->colorRamp[index].b = index;
  }
}

// Note: gUnknown_202ECA0 file's 2d array is read as 1d array in functions below, be careful!
void sub_807E698(bool8 arg0)
{
    s32 i, j;
    s32 weatherArrId = GetApparentWeather(NULL) * COLOR_RAMP_COUNT;
    RGB *fileData = (void *) gUnknown_202ECA0->data;
    u8 savedByte;

    sub_8042818(GetApparentWeather(NULL), arg0);
    DungeonRunFrameActions(0x25);
    sub_804178C(1);
    savedByte = gUnknown_203B40D;
    gUnknown_203B40D = 1;

    for (i = 0; i < 64; i++) {
        bool8 r7 = FALSE;

        DungeonRunFrameActions(0x25);
        for (j = 0; j < COLOR_RAMP_COUNT; j++) {
            if (abs(gDungeon->colorRamp[j].r - fileData[weatherArrId + j].r) < 10) {
                gDungeon->colorRamp[j].r = fileData[weatherArrId + j].r;
            }
            else {
                r7 = TRUE;
                if (gDungeon->colorRamp[j].r < fileData[weatherArrId + j].r) {
                    gDungeon->colorRamp[j].r += 10;
                }
                else if (gDungeon->colorRamp[j].r > fileData[weatherArrId + j].r) {
                    gDungeon->colorRamp[j].r -= 10;
                }
            }

            if (abs(gDungeon->colorRamp[j].g - fileData[weatherArrId + j].g) < 10) {
                gDungeon->colorRamp[j].g = fileData[weatherArrId + j].g;
            }
            else {
                r7 = TRUE;
                if (gDungeon->colorRamp[j].g < fileData[weatherArrId + j].g) {
                    gDungeon->colorRamp[j].g += 10;
                }
                else if (gDungeon->colorRamp[j].g > fileData[weatherArrId + j].g) {
                    gDungeon->colorRamp[j].g -= 10;
                }
            }

            if (abs(gDungeon->colorRamp[j].b - fileData[weatherArrId + j].b) < 10) {
                gDungeon->colorRamp[j].b = fileData[weatherArrId + j].b;
            }
            else {
                r7 = TRUE;
                if (gDungeon->colorRamp[j].b < fileData[weatherArrId + j].b) {
                    gDungeon->colorRamp[j].b += 10;
                }
                else if (gDungeon->colorRamp[j].b > fileData[weatherArrId + j].b) {
                    gDungeon->colorRamp[j].b -= 10;
                }
            }
        }

        sub_803E874(FALSE, 0);
        if (!r7)
            break;
    }

    gUnknown_203B40D = savedByte;
    sub_807E7FC(arg0);
}

void sub_807E7FC(bool8 r0)
{
    s32 i;

    Entity *cameraTarget = gDungeon->unk181e8.cameraTarget;
    if (cameraTarget == NULL) {
        cameraTarget = GetLeader();
    }

    if (r0) {
        if (gDungeon->unk1356C == 0) {
            GetWeatherName(gFormatBuffer_Monsters[0], GetApparentWeather(NULL));
            LogMessageByIdWithPopupCheckUser(cameraTarget, gUnknown_80FC5E0); // Weather: {ARG_POKEMON_0}
        }
    }

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *pokemon = gDungeon->activePokemon[i];
        if (EntityIsValid(pokemon)) {
            sub_807E8F0(pokemon);
        }
    }
}

void sub_807E88C(void)
{
    s32 i;
    s32 weatherArrId = GetApparentWeather(0) * COLOR_RAMP_COUNT;
    RGB *fileData = (void *) gUnknown_202ECA0->data;

    for (i = 0; i < COLOR_RAMP_COUNT; i++) {
        gDungeon->colorRamp[i].r = fileData[weatherArrId + i].r;
        gDungeon->colorRamp[i].g = fileData[weatherArrId + i].g;
        gDungeon->colorRamp[i].b = fileData[weatherArrId + i].b;
    }

    sub_803E874(0, 0);
}

void sub_807E8F0(Entity *pokemon)
{
    u8 oldTypes[2];
    bool8 flag = FALSE;

    if (EntityIsValid(pokemon)) {
        EntityInfo *info = GetEntInfo(pokemon);
        s32 previousApparentId = info->apparentID;
        oldTypes[0] = info->types[0];
        oldTypes[1] = info->types[1];
        CalcSpeedStage(pokemon);
        if (AbilityIsActive(pokemon, ABILITY_FORECAST)) {
            info->types[0] = gCastformByWeather[GetApparentWeather(pokemon)].type;
            info->types[1] = TYPE_NONE;
        }
        else if ((info->reflectClassStatus.status != STATUS_CONVERSION2) && (info->isColorChanged == FALSE)){
            info->types[0] = GetPokemonType(info->id, 0);
            info->types[1] = GetPokemonType(info->id, 1);
        }

        if ((oldTypes[0] != info->types[0]) || (oldTypes[1] != info->types[1])) {
            flag = TRUE;
        }

        if (IS_CASTFORM_FORM_MONSTER(info->id) || info->id == MONSTER_CASTFORM) {
            if (AbilityIsActive(pokemon, ABILITY_FORECAST)) {
                info->apparentID = GetMonsterApparentID(pokemon, info->id);
            }
            else {
                info->apparentID = MONSTER_CASTFORM;
            }
            if (info->apparentID != previousApparentId) {
                pokemon->axObj.spriteFile = GetSpriteData(info->apparentID);
                sub_806CCB4(pokemon,sub_806CEBC(pokemon));
                flag = TRUE;
            }
        }
        if (flag) {
            sub_80429D8(pokemon);
        }
    }
}

void GetWeatherName(u8 *buffer, u8 weather)
{
    strcpy(buffer, gWeatherNames[weather]);
}

void MudWaterSportEffect(u8 which)
{
    if (which == 0) {
        gDungeon->weather.mudSportTurns = CalculateStatusTurns(0, gMudWaterSportTurnRange, FALSE);
        LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FAD8C);
    }
    else {
        gDungeon->weather.waterSportTurns =CalculateStatusTurns(0, gMudWaterSportTurnRange, FALSE);
        LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FADB0);
    }
}

bool8 sub_807EAA0(bool8 arg0, bool8 arg1)
{
    s32 i;
    s32 var = 0;
    s32 index = -1;
    bool8 ret = FALSE;
    s32 weatherBefore = GetApparentWeather(NULL);

    for (i = 0; i < 8; i++) {
        if (gDungeon->weather.unkE267[i] < gDungeon->weather.naturalWeather[i]) {
            gDungeon->weather.unkE267[i] = gDungeon->weather.naturalWeather[i];
        }
        else if (gDungeon->weather.unkE267[i] > gDungeon->weather.naturalWeather[i]) {
            sub_80838EC(&gDungeon->weather.unkE267[i]);
        }

        if (var < gDungeon->weather.unkE267[i]) {
            var = gDungeon->weather.unkE267[i];
            index = i;
        }
    }

    if (index < 0) {
        gDungeon->weather.weather = gDungeon->weather.unkE265;
    }
    else {
        gDungeon->weather.weather = index;
    }

    if (gDungeon->weather.nullifyWeather) {
        gDungeon->weather.weather = 0;
    }

    if (weatherBefore != GetApparentWeather(NULL) || arg1) {
        ret = TRUE;
        sub_807E698(arg0);
    }

    if (gDungeon->weather.weatherDamageCounter != 0) {
        gDungeon->weather.weatherDamageCounter--;
    }
    else {
        gDungeon->weather.weatherDamageCounter = 9;
    }

    if (gDungeon->weather.mudSportTurns != 0) {
        sub_80838EC(&gDungeon->weather.mudSportTurns);
        if (gDungeon->weather.mudSportTurns == 0) {
            LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FA778);
        }
    }
    if (gDungeon->weather.waterSportTurns != 0) {
        sub_80838EC(&gDungeon->weather.waterSportTurns);
        if (gDungeon->weather.waterSportTurns == 0) {
            LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FA758);
        }
    }

    return ret;
}

