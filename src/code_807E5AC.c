#include "global.h"
#include "weather.h"
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
#include "dungeon_pokemon_attributes.h"
#include "string_format.h"
#include "dungeon_movement.h"
#include "dungeon_capabilities.h"
#include "dungeon_map_access.h"
#include "position_util.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "code_805D8C8.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"

extern u8 gUnknown_203B40D;
extern OpenedFile *gUnknown_202ECA0;

extern void sub_804178C(u32);
extern bool8 sub_80461C8(DungeonPos *, u32);
extern void sub_80429D8(Entity *r0);
extern s32 GetMonsterApparentID(Entity *pokemon, s32 id);
extern void sub_803E874(bool8 r10, s32 r9);
extern void GetWeatherName(u8 *dst, u8 weatherId);
extern s32 CalculateStatusTurns(Entity *target, const s16 *turnRange, bool8 factorCurerSkills);
extern void sub_80838EC(u8 *a);
extern bool8 sub_8044B28(void);
extern void sub_80460F8(DungeonPos *, Item *, u32);

void sub_807E7FC(bool8 arg0);
void sub_807EFFC(bool8 arg0);
s32 sub_807F19C(bool8 arg0);
void sub_807E8F0(Entity *pokemon);
bool8 sub_807EF48(void);
void sub_807F33C(void);

extern const u8 *gWeatherNames[];

extern const u8 *const gUnknown_80FC5E0;
extern const u8 *const gUnknown_80FA778;
extern const u8 *const gUnknown_80FA758;
extern const u8 *const gUnknown_80FE674;
extern const u8 *const gUnknown_80FE65C;
extern const u8 *const gUnknown_80FE63C;
extern const u8 *const gUnknown_80FE5F0;
extern const u8 *const gUnknown_80FAD8C;
extern const u8 *const gUnknown_80FADB0;
extern const u8 *const gUnknown_80FE5C0;
extern const u8 *const gUnknown_80FE4F4;


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

void sub_807EC28(bool8 arg0)
{
    Entity *leader;
    EntityInfo *leaderInfo;
    u32 var_34;
    bool32 isShopTile;

    if (sub_8044B28())
        return;

    leader = GetLeader();
    leaderInfo = GetEntInfo(leader);
    var_34 = gDungeon->unk644.unk54;
    isShopTile = (GetTileAtEntitySafe(leader)->terrainType & TERRAIN_TYPE_SHOP) != 0;
    gDungeon->unk644.unk54 = isShopTile;
    gDungeon->unk644.unk55 = isShopTile;
    if (gDungeon->unk644.unk2A || gDungeon->unk644.unk50 == 0)
        return;

    if (leaderInfo->invisibleClassStatus.status == STATUS_INVISIBLE) {
        gDungeon->unk644.unk54 = 0;
        gDungeon->unk644.unk55 = 0;
    }
    else {
        s32 i;
        struct MonDialogueSpriteInfo dialogueInfo;
        bool8 var_30 = FALSE;
        bool8 var_2C;
        bool8 var_28;

        for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++) {
            Entity *wildMon = gDungeon->wildPokemon[i];
            if (EntityExists(wildMon)) {
                EntityInfo *wildMonInfo = GetEntInfo(wildMon);
                if (wildMonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER && sub_8070BC0(wildMon) && GetEntityRoom(leader) == GetEntityRoom(wildMon)) {
                    var_30 = TRUE;
                }
            }
        }

        dialogueInfo.species = MONSTER_KECLEON;
        dialogueInfo.spriteId = 0;
        if (var_34 == 0) {
            if (isShopTile == TRUE) {
                if (var_30) {
                    DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE674, TRUE); // Ah welcome!
                }
                return;
            }
        }
        else {
            if (isShopTile == TRUE) {
                return;
            }
        }

        if ((var_34 != 1 || isShopTile) && !arg0) {
            return;
        }

        var_2C = FALSE;
        var_28 = FALSE;
        if (sub_807EF48()) {
            var_28 = TRUE;
            for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++) {
                Entity *wildMon = gDungeon->wildPokemon[i];
                if (EntityExists(wildMon)
                    && GetEntInfo(wildMon)->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER
                    && sub_8070BC0(wildMon)
                    && GetEntityRoom(leader) == GetEntityRoom(wildMon))
                {
                    var_2C = TRUE;
                    if (abs(leader->pos.x - wildMon->pos.x) >= 2 || abs(leader->pos.y - wildMon->pos.y) >= 2) {
                        s32 x, y;
                        DungeonPos pos;

                        for (x = -1; x < 2; x++) {
                            for (y = -1; y < 2; y++) {
                                pos.x = leader->pos.x + x;
                                pos.y = leader->pos.y + y;
                                if (GetTile(pos.x, pos.y)->room != CORRIDOR_ROOM) {
                                    if (!sub_80703A0(wildMon, &pos)) {
                                        WarpTarget(leader, wildMon, 3, &pos);
                                        goto LOOP_BREAK; // Used to break out of the nested loops
                                    }
                                }
                            }
                        }
                    LOOP_BREAK:
                    }

                    if (sub_8070BC0(leader)) {
                        sub_806CE34(leader, GetDirectionTowardsPosition(&leader->pos, &wildMon->pos));
                    }
                    else {
                        var_2C = FALSE;
                    }

                    sub_806CE68(wildMon, GetDirectionTowardsPosition(&wildMon->pos, &leader->pos));
                    break;
                }
            }
        }

        if (var_28 && !var_2C) {
            if (gDungeon->unk644.unk50 > gDungeon->unk644.unk48) {
                sub_807F33C();
            }
        }
        else if (var_28 && !var_30) {
            if (gDungeon->unk644.unk50 > gDungeon->unk644.unk48) {
                sub_807F33C();
            }
        }
        else {
            sub_807EFFC(var_2C);
            if (sub_807F19C(var_2C)) {
                sub_807F33C();
            }
            else if (var_34 == 1 && !isShopTile && var_30) {
                DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE65C, TRUE); // I await your next visit
            }
        }
    }
}

bool8 sub_807EF48(void)
{
    if ((gDungeon->unk644.unk50 - gDungeon->unk644.unk48) > 0) {
        return TRUE;
    }
    if (gDungeon->unk644.unk4C != 0) {
        return TRUE;
    }

    return FALSE;
}


void sub_807EF84(void)
{
    s32 val;
    struct MonDialogueSpriteInfo dialogueInfo;

    dialogueInfo.species = MONSTER_KECLEON;
    dialogueInfo.spriteId = 0;

    sub_807EFFC(1);
    val = sub_807F19C(1);
    if (val != 0) {
        Tile *tile = GetTileAtEntitySafe(GetLeader());
        if (tile->terrainType & TERRAIN_TYPE_SHOP) {
            if (val != 2) {
                DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE63C, 1); // This is very disappointing, please return any items before you leave.
            }
        }
        else {
            sub_807F33C();
        }
    }
    else {
        DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE5F0, 1); // Looking forward to seeing you again!
    }
}

void sub_807EFFC(bool8 arg0)
{
    struct MonDialogueSpriteInfo dialogueInfo;

    if (gDungeon->unk644.unk4C == 0)
        return;

    dialogueInfo.species = MONSTER_KECLEON;
    dialogueInfo.spriteId = 0;
    if (!arg0)
        return;

    gFormatArgs[0] = gDungeon->unk644.unk4C;
    if (DisplayDungeonYesNoMessage(&dialogueInfo, gUnknown_80FE5C0, TRUE) == 1) { // For the merch you have left, I shall pay X. Is that acceptable?
        s32 x, y;
        DungeonPos pos;
        s32 local_24;

        PlaySoundEffect(0x14c);
        AddToTeamMoney(gDungeon->unk644.unk4C);
        local_24 = gDungeon->unk644.unk48;
        for (x = gDungeon->kecleonShopPos.minX; x <= gDungeon->kecleonShopPos.maxX; x++) {
            for (y = gDungeon->kecleonShopPos.minY; y <= gDungeon->kecleonShopPos.maxY; y++) {
                const Tile *tile;

                pos.y = y;
                pos.x = x;
                tile = GetTile(x,y);
                if (tile->terrainType & TERRAIN_TYPE_SHOP && tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                    Item *itemPtr = GetItemData(tile->object);
                    if (!ItemInShop(itemPtr)) {
                        Item item = *itemPtr;
                        sub_80461C8(&pos, 1);
                        if (CanSellItem(item.id)) {
                            item.flags |= ITEM_FLAG_IN_SHOP;
                        }
                        sub_80460F8(&pos, &item, 1);
                    }
                }
            }
        }

        gDungeon->unk644.unk50 += (gDungeon->unk644.unk48 - local_24);
        DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE4F4, 1); // Your patronage is valued
    }
}

//
