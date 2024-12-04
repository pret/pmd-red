#include "global.h"
#include "weather.h"
#include "code_804267C.h"
#include "code_803E46C.h"
#include "dungeon.h"
#include "dungeon_config.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "dungeon_message.h"
#include "dungeon_pokemon_attributes.h"
#include "string_format.h"
#include "dungeon_movement.h"
#include "code_806CD90.h"
#include "code_805D8C8.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"

extern u8 gUnknown_203B40D;
extern OpenedFile *gUnknown_202ECA0;
extern void sub_804178C(u32);

extern void sub_80429D8(Entity *r0);
extern s32 GetMonsterApparentID(Entity *pokemon, s32 id);
void sub_803E874(bool8 r10, s32 r9);
void GetWeatherName(u8 *dst, u8 weatherId);
extern s32 CalculateStatusTurns(Entity *target, const s16 *turnRange, bool8 factorCurerSkills);

void sub_807E7FC(bool8 arg0);
void sub_807E8F0(Entity *pokemon);

extern const u8 *const gUnknown_80FC5E0;

// Note: gUnknown_202ECA0 file's 2d array is read as 1d array in functions below, be careful!
void sub_807E698(bool8 arg0)
{
    s32 i, j;
    s32 weatherArrId = GetApparentWeather(NULL) * COLOR_RAMP_COUNT;
    RGB *fileData = (void *) gUnknown_202ECA0->data;
    u8 savedByte;

    sub_8042818(GetApparentWeather(NULL), arg0);
    sub_803E46C(0x25);
    sub_804178C(1);
    savedByte = gUnknown_203B40D;
    gUnknown_203B40D = 1;

    for (i = 0; i < 64; i++) {
        bool8 r7 = FALSE;

        sub_803E46C(0x25);
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
        if (EntityExists(pokemon)) {
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

    if (EntityExists(pokemon)) {
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

extern const u8 *gWeatherNames[];
extern const u8 *const gUnknown_80FAD8C;
extern const u8 *const gUnknown_80FADB0;

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
