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
#include "dungeon_visibility.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_ai_targeting.h"
#include "position_util.h"
#include "dungeon_ai.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "code_805D8C8.h"
#include "code_8045A00.h"
#include "code_80450F8.h"
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
extern const u8 *const gUnknown_80FE568;
extern const u8 *const gUnknown_80FE520;
extern const u8 *const gUnknown_80FE4D4;
extern const u8 *const gUnknown_80FE4B8;


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
    bool32 prevTileWasShop;
    bool32 isShopTile;

    if (sub_8044B28())
        return;

    leader = GetLeader();
    leaderInfo = GetEntInfo(leader);
    prevTileWasShop = gDungeon->unk644.unk54;
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
        bool8 sameRoom = FALSE;
        bool8 var_2C;
        bool8 var_28;

        for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++) {
            Entity *wildMon = gDungeon->wildPokemon[i];
            if (EntityExists(wildMon)) {
                EntityInfo *wildMonInfo = GetEntInfo(wildMon);
                if (wildMonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER && sub_8070BC0(wildMon) && GetEntityRoom(leader) == GetEntityRoom(wildMon)) {
                    sameRoom = TRUE;
                }
            }
        }

        dialogueInfo.species = MONSTER_KECLEON;
        dialogueInfo.spriteId = 0;
        if (!prevTileWasShop) {
            if (isShopTile == TRUE) {
                if (sameRoom) {
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

        if ((prevTileWasShop != TRUE || isShopTile) && !arg0) {
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
        else if (var_28 && !sameRoom) {
            if (gDungeon->unk644.unk50 > gDungeon->unk644.unk48) {
                sub_807F33C();
            }
        }
        else {
            sub_807EFFC(var_2C);
            if (sub_807F19C(var_2C)) {
                sub_807F33C();
            }
            else if (prevTileWasShop == TRUE && !isShopTile && sameRoom) {
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
    val = sub_807F19C(TRUE);
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

s32 sub_807F19C(bool8 arg0)
{
    s32 diff;
    struct MonDialogueSpriteInfo dialogueInfo;
    s32 i, x, y;

    dialogueInfo.species = MONSTER_KECLEON;
    dialogueInfo.spriteId = 0;
    diff = gDungeon->unk644.unk50 - gDungeon->unk644.unk48;
    if (diff > 0) {
        if (!arg0) {
            return 1;
        }

        gFormatArgs[0] = diff;
        if (DisplayDungeonYesNoMessage(&dialogueInfo, gUnknown_80FE568, TRUE) != 1) { // The merchandise you have chosen costs X
            return 1;
        }
        if (gTeamInventoryRef->teamMoney < diff) {
            DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE520, TRUE); // You don't have enough money.
            return 2;
        }
        PlaySoundEffect(0x14c);
        AddToTeamMoney(-diff);

        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
                const Tile *tile = GetTile(x, y);
                if (!(tile->terrainType & TERRAIN_TYPE_SHOP) && tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                    Item *itemPtr = GetItemData(tile->object);
                    if (CanSellItem(itemPtr->id)) {
                        itemPtr->flags &= ~(ITEM_FLAG_IN_SHOP);
                    }
                }
            }
        }

        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (ItemExists(item) && CanSellItem(item->id)) {
                item->flags &= ~(ITEM_FLAG_IN_SHOP);
            }
        }

        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *mon = gDungeon->activePokemon[i];
            if (EntityExists(mon)) {
                EntityInfo *monInfo = GetEntInfo(mon);
                Item *item = &monInfo->heldItem;
                if (ItemExists(item) && CanSellItem(item->id)) {
                    item->flags &= ~(ITEM_FLAG_IN_SHOP);
                }
            }
        }
        gDungeon->unk644.unk50 = gDungeon->unk644.unk48;
        DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE4D4, TRUE); // Thank you very much.
    }

    return 0;
}

void sub_807F33C(void)
{
    s32 i, x, y;

    gDungeon->unk644.unk2A = 1;
    gDungeon->unk644.unk2B = 1;
    LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FE4B8); // Help! Thief! I've been robbed! Help me catch the thief.
    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            const Tile *tile = GetTile(x,y);
            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                Item *item = GetItemData(tile->object);
                item->flags &= ~(ITEM_FLAG_IN_SHOP);
            }
        }
    }

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(item)) {
            item->flags &= ~(ITEM_FLAG_IN_SHOP);
        }
    }

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity = gDungeon->activePokemon[i];
        if (EntityExists(entity)) {
            Item *item;
            EntityInfo *info = GetEntInfo(entity);

            info->shopkeeper = FALSE;
            CalcSpeedStage(entity);
            item = &info->heldItem;
            if (ItemExists(item)) {
                item->flags &= ~(ITEM_FLAG_IN_SHOP);
            }
        }
    }

    gDungeon->unk644.unk50 = 0;
    gDungeon->unk644.unk48 = 0;
    gDungeon->unk644.unk4C = 0;
}

extern void sub_80833E8(DungeonPos *param_1, s32 *param_2);
extern void sub_806A5B8(Entity *);

void sub_807F9BC(Entity *entity);

/*
void sub_807F43C(Entity *target, Entity *attacker)
{
    if (AbilityIsActive(attacker, ABILITY_SUCTION_CUPS)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80FCB40); // is anchored, cannot be moved
    }
    else if (attacker == target) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(attacker, attacker, gUnknown_80FCB70); // couldn't be thrown for some reason
    }
    else {
        s32 var_74[4];
        DungeonPos positions[40];
        DungeonPos attackerPos = attacker->pos;
        s32 var_3C = 0;
        s32 monId;

        while (1) {
            s32 positionsCounter = 0;
            for (monId = 0; monId < DUNGEON_MAX_POKEMON; monId++) {
                Entity *mon = gDungeon->activePokemon[monId];
                if (EntityExists(mon) && target != mon && attacker != mon && CanSeeTarget(target, mon)) {
                    if (var_3C == 0) {
                        if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 1)
                            continue;
                    }
                    else {
                        if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 0)
                            continue;
                    }

                    if (var_3C != 0) {
                        s32 directionId;
                        DungeonPos pos;
                        for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                            pos.x = mon->pos.x + gAdjacentTileOffsets[directionId].x;
                            pos.y = mon->pos.y + gAdjacentTileOffsets[directionId].y;
                            if (!sub_80703A0(attacker, &pos))
                                break;
                        }

                        if (directionId == NUM_DIRECTIONS)
                            break;
                        if (positionsCounter > 39)
                            break;
                        positions[positionsCounter++] = mon->pos;
                    }
                    else {
                        s32 directionId;
                        DungeonPos pos;
                        for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                            pos.x = mon->pos.x + gAdjacentTileOffsets[directionId].x;
                            pos.y = mon->pos.y + gAdjacentTileOffsets[directionId].y;
                            if (!sub_80703A0(attacker, &pos) && positionsCounter < 40) {
                                positions[positionsCounter++] = mon->pos;
                            }
                        }
                    }
                }
            }

            if (positionsCounter == 0) {
                if (++var_3C < 2)
                    continue;
                sub_80833E8(&target->pos, var_74);
            }
            else {

            }
            break;
        }

    }
}
*/

NAKED void sub_807F43C(Entity *target, Entity *attacker)
{
    asm_unified("push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x10C\n"
"	str r0, [sp, 0xEC]\n"
"	mov r8, r1\n"
"	mov r0, r8\n"
"	movs r1, 0xE\n"
"	bl AbilityIsActive\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F470\n"
"	ldr r0, _0807F468\n"
"	mov r1, r8\n"
"	movs r2, 0\n"
"	bl SubstitutePlaceholderStringTags\n"
"	ldr r0, _0807F46C\n"
"	b _0807F694\n"
"	.align 2, 0\n"
"_0807F468: .4byte gFormatBuffer_Monsters\n"
"_0807F46C: .4byte gUnknown_80FCB40\n"
"_0807F470:\n"
"	ldr r0, [sp, 0xEC]\n"
"	cmp r0, r8\n"
"	bne _0807F490\n"
"	ldr r0, _0807F488\n"
"	mov r1, r8\n"
"	movs r2, 0\n"
"	bl SubstitutePlaceholderStringTags\n"
"	ldr r0, _0807F48C\n"
"	ldr r2, [r0]\n"
"	mov r0, r8\n"
"	b _0807F698\n"
"	.align 2, 0\n"
"_0807F488: .4byte gFormatBuffer_Monsters\n"
"_0807F48C: .4byte gUnknown_80FCB70\n"
"_0807F490:\n"
"	mov r1, r8\n"
"	ldr r0, [r1, 0x4]\n"
"	add r1, sp, 0xD4\n"
"	str r0, [r1]\n"
"	movs r2, 0\n"
"	str r2, [sp, 0xF0]\n"
"_0807F49C:\n"
"	movs r3, 0\n"
"	mov r9, r3\n"
"	movs r7, 0\n"
"	mov r4, sp\n"
"	adds r4, 0x18\n"
"	str r4, [sp, 0x108]\n"
"_0807F4A8:\n"
"	ldr r0, _0807F504\n"
"	ldr r0, [r0]\n"
"	lsls r1, r7, 2\n"
"	ldr r2, _0807F508\n"
"	adds r0, r2\n"
"	adds r0, r1\n"
"	ldr r4, [r0]\n"
"	adds r0, r4, 0\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	adds r3, r7, 0x1\n"
"	str r3, [sp, 0x104]\n"
"	cmp r0, 0\n"
"	bne _0807F4C8\n"
"	b _0807F602\n"
"_0807F4C8:\n"
"	ldr r0, [sp, 0xEC]\n"
"	cmp r0, r4\n"
"	bne _0807F4D0\n"
"	b _0807F602\n"
"_0807F4D0:\n"
"	cmp r8, r4\n"
"	bne _0807F4D6\n"
"	b _0807F602\n"
"_0807F4D6:\n"
"	adds r1, r4, 0\n"
"	bl CanSeeTarget\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _0807F4E4\n"
"	b _0807F602\n"
"_0807F4E4:\n"
"	ldr r1, [sp, 0xF0]\n"
"	cmp r1, 0\n"
"	bne _0807F50C\n"
"	ldr r0, [sp, 0xEC]\n"
"	adds r1, r4, 0\n"
"	movs r2, 0\n"
"	movs r3, 0x1\n"
"	bl GetTreatmentBetweenMonsters\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	cmp r0, 0x1\n"
"	beq _0807F500\n"
"	b _0807F602\n"
"_0807F500:\n"
"	b _0807F51E\n"
"	.align 2, 0\n"
"_0807F504: .4byte gDungeon\n"
"_0807F508: .4byte 0x000135cc\n"
"_0807F50C:\n"
"	ldr r0, [sp, 0xEC]\n"
"	adds r1, r4, 0\n"
"	movs r2, 0\n"
"	movs r3, 0x1\n"
"	bl GetTreatmentBetweenMonsters\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _0807F602\n"
"_0807F51E:\n"
"	ldr r2, [sp, 0xF0]\n"
"	cmp r2, 0\n"
"	bne _0807F594\n"
"	movs r5, 0\n"
"	add r6, sp, 0xC8\n"
"	adds r3, r7, 0x1\n"
"	str r3, [sp, 0x104]\n"
"	adds r7, r6, 0\n"
"	ldr r0, _0807F588\n"
"	mov r10, r0\n"
"_0807F532:\n"
"	ldr r0, _0807F58C\n"
"	lsls r3, r5, 2\n"
"	adds r3, r0\n"
"	ldrh r0, [r4, 0x4]\n"
"	ldrh r1, [r3]\n"
"	adds r0, r1\n"
"	lsls r0, 16\n"
"	lsrs r0, 16\n"
"	ldr r1, [r6]\n"
"	mov r2, r10\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [r7]\n"
"	ldrh r2, [r4, 0x6]\n"
"	ldrh r3, [r3, 0x2]\n"
"	adds r2, r3\n"
"	lsls r2, 16\n"
"	ldr r0, _0807F590\n"
"	ands r1, r0\n"
"	orrs r1, r2\n"
"	str r1, [r7]\n"
"	mov r0, r8\n"
"	add r1, sp, 0xC8\n"
"	bl sub_80703A0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F570\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x7\n"
"	ble _0807F532\n"
"_0807F570:\n"
"	cmp r5, 0x8\n"
"	beq _0807F602\n"
"	mov r3, r9\n"
"	cmp r3, 0x27\n"
"	bgt _0807F602\n"
"	ldr r0, [r4, 0x4]\n"
"	ldr r4, [sp, 0x108]\n"
"	stm r4!, {r0}\n"
"	str r4, [sp, 0x108]\n"
"	movs r0, 0x1\n"
"	add r9, r0\n"
"	b _0807F602\n"
"	.align 2, 0\n"
"_0807F588: .4byte 0xffff0000\n"
"_0807F58C: .4byte gAdjacentTileOffsets\n"
"_0807F590: .4byte 0x0000ffff\n"
"_0807F594:\n"
"	movs r5, 0\n"
"	add r6, sp, 0xCC\n"
"	adds r1, r7, 0x1\n"
"	str r1, [sp, 0x104]\n"
"	adds r7, r6, 0\n"
"	mov r2, r9\n"
"	lsls r0, r2, 2\n"
"	add r0, sp\n"
"	adds r0, 0x18\n"
"	mov r10, r0\n"
"_0807F5A8:\n"
"	ldr r0, _0807F630\n"
"	lsls r3, r5, 2\n"
"	adds r3, r0\n"
"	ldrh r0, [r4, 0x4]\n"
"	ldrh r1, [r3]\n"
"	adds r0, r1\n"
"	lsls r0, 16\n"
"	lsrs r0, 16\n"
"	ldr r2, _0807F634\n"
"	ldr r1, [r6]\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [r7]\n"
"	ldrh r2, [r4, 0x6]\n"
"	ldrh r3, [r3, 0x2]\n"
"	adds r2, r3\n"
"	lsls r2, 16\n"
"	ldr r0, _0807F638\n"
"	ands r1, r0\n"
"	orrs r1, r2\n"
"	str r1, [r7]\n"
"	mov r0, r8\n"
"	add r1, sp, 0xCC\n"
"	bl sub_80703A0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _0807F5FC\n"
"	mov r2, r9\n"
"	cmp r2, 0x27\n"
"	bgt _0807F5FC\n"
"	ldr r0, [r6]\n"
"	mov r3, r10\n"
"	adds r3, 0x4\n"
"	mov r10, r3\n"
"	subs r3, 0x4\n"
"	stm r3!, {r0}\n"
"	ldr r0, [sp, 0x108]\n"
"	adds r0, 0x4\n"
"	str r0, [sp, 0x108]\n"
"	movs r1, 0x1\n"
"	add r9, r1\n"
"_0807F5FC:\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x7\n"
"	ble _0807F5A8\n"
"_0807F602:\n"
"	ldr r7, [sp, 0x104]\n"
"	cmp r7, 0x13\n"
"	bgt _0807F60A\n"
"	b _0807F4A8\n"
"_0807F60A:\n"
"	mov r2, r9\n"
"	cmp r2, 0\n"
"	bne _0807F63C\n"
"	ldr r3, [sp, 0xF0]\n"
"	adds r3, 0x1\n"
"	str r3, [sp, 0xF0]\n"
"	cmp r3, 0x1\n"
"	bgt _0807F61C\n"
"	b _0807F49C\n"
"_0807F61C:\n"
"	ldr r0, [sp, 0xEC]\n"
"	adds r0, 0x4\n"
"	add r4, sp, 0xB8\n"
"	adds r1, r4, 0\n"
"	bl sub_80833E8\n"
"	movs r7, 0\n"
"	add r5, sp, 0xD0\n"
"	adds r6, r5, 0\n"
"	b _0807F654\n"
"	.align 2, 0\n"
"_0807F630: .4byte gAdjacentTileOffsets\n"
"_0807F634: .4byte 0xffff0000\n"
"_0807F638: .4byte 0x0000ffff\n"
"_0807F63C:\n"
"	mov r0, r9\n"
"	bl DungeonRandInt\n"
"	lsls r0, 2\n"
"	add r0, sp\n"
"	adds r0, 0x18\n"
"	ldr r0, [r0]\n"
"	str r0, [sp, 0xD4]\n"
"	b _0807F6A8\n"
"_0807F64E:\n"
"	ldr r0, [r5]\n"
"	str r0, [sp, 0xD4]\n"
"	b _0807F68E\n"
"_0807F654:\n"
"	ldr r0, [r4]\n"
"	ldr r1, [r4, 0x8]\n"
"	bl DungeonRandRange\n"
"	lsls r0, 16\n"
"	lsrs r0, 16\n"
"	ldr r2, _0807F6A0\n"
"	ldr r1, [r5]\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [r6]\n"
"	ldr r0, [r4, 0x4]\n"
"	ldr r1, [r4, 0xC]\n"
"	bl DungeonRandRange\n"
"	lsls r0, 16\n"
"	ldrh r1, [r6]\n"
"	orrs r1, r0\n"
"	str r1, [r6]\n"
"	mov r0, r8\n"
"	add r1, sp, 0xD0\n"
"	bl sub_80703A0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F64E\n"
"	adds r7, 0x1\n"
"	cmp r7, 0x63\n"
"	ble _0807F654\n"
"_0807F68E:\n"
"	cmp r7, 0x64\n"
"	bne _0807F6A8\n"
"	ldr r0, _0807F6A4\n"
"_0807F694:\n"
"	ldr r2, [r0]\n"
"	ldr r0, [sp, 0xEC]\n"
"_0807F698:\n"
"	mov r1, r8\n"
"	bl TryDisplayDungeonLoggableMessage3\n"
"	b _0807F99C\n"
"	.align 2, 0\n"
"_0807F6A0: .4byte 0xffff0000\n"
"_0807F6A4: .4byte gUnknown_80FE6B4\n"
"_0807F6A8:\n"
"	ldr r0, _0807F860\n"
"	mov r1, r8\n"
"	movs r2, 0\n"
"	bl SubstitutePlaceholderStringTags\n"
"	ldr r0, _0807F864\n"
"	ldr r2, [r0]\n"
"	ldr r0, [sp, 0xEC]\n"
"	mov r1, r8\n"
"	bl TryDisplayDungeonLoggableMessage3\n"
"	mov r0, r8\n"
"	bl sub_8045888\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F6D0\n"
"	ldr r0, _0807F868\n"
"	bl PlaySoundEffect\n"
"_0807F6D0:\n"
"	movs r4, 0\n"
"	str r4, [sp, 0x100]\n"
"	mov r1, r8\n"
"	ldr r0, [r1, 0x70]\n"
"	adds r0, 0x46\n"
"	ldrb r0, [r0]\n"
"	mov r9, r0\n"
"	add r2, sp, 0xD4\n"
"	movs r3, 0\n"
"	ldrsh r1, [r2, r3]\n"
"	mov r4, r8\n"
"	movs r3, 0x4\n"
"	ldrsh r0, [r4, r3]\n"
"	subs r3, r1, r0\n"
"	movs r4, 0x2\n"
"	ldrsh r1, [r2, r4]\n"
"	mov r2, r8\n"
"	movs r4, 0x6\n"
"	ldrsh r0, [r2, r4]\n"
"	subs r1, r0\n"
"	cmp r1, r3\n"
"	bge _0807F6FE\n"
"	adds r1, r3, 0\n"
"_0807F6FE:\n"
"	lsls r6, r1, 4\n"
"	cmp r6, 0x50\n"
"	ble _0807F706\n"
"	movs r6, 0x50\n"
"_0807F706:\n"
"	cmp r6, 0x9\n"
"	bgt _0807F70C\n"
"	movs r6, 0xA\n"
"_0807F70C:\n"
"	mov r1, r8\n"
"	adds r1, 0x4\n"
"	add r0, sp, 0xD4\n"
"	bl GetDirectionTowardsPosition\n"
"	adds r5, r0, 0\n"
"	add r2, sp, 0xD4\n"
"	movs r1, 0\n"
"	ldrsh r0, [r2, r1]\n"
"	lsls r4, r0, 1\n"
"	adds r4, r0\n"
"	lsls r4, 11\n"
"	movs r3, 0xC0\n"
"	lsls r3, 4\n"
"	adds r4, r3\n"
"	ldr r0, _0807F86C\n"
"	lsls r5, 2\n"
"	adds r5, r0\n"
"	movs r1, 0\n"
"	ldrsh r0, [r5, r1]\n"
"	lsls r0, 8\n"
"	movs r1, 0x3\n"
"	bl __divsi3\n"
"	adds r4, r0\n"
"	str r4, [sp, 0xF4]\n"
"	movs r3, 0xD6\n"
"	add r3, sp\n"
"	movs r2, 0\n"
"	ldrsh r0, [r3, r2]\n"
"	lsls r4, r0, 1\n"
"	adds r4, r0\n"
"	lsls r4, 11\n"
"	movs r0, 0x80\n"
"	lsls r0, 5\n"
"	adds r4, r0\n"
"	movs r1, 0x2\n"
"	ldrsh r0, [r5, r1]\n"
"	lsls r0, 8\n"
"	movs r1, 0x3\n"
"	bl __divsi3\n"
"	adds r4, r0\n"
"	str r4, [sp, 0xF8]\n"
"	mov r2, r8\n"
"	ldr r5, [r2, 0xC]\n"
"	ldr r3, [sp, 0xF4]\n"
"	subs r0, r3, r5\n"
"	adds r1, r6, 0\n"
"	bl __divsi3\n"
"	str r0, [sp, 0xFC]\n"
"	mov r0, r8\n"
"	ldr r4, [r0, 0x10]\n"
"	ldr r1, [sp, 0xF8]\n"
"	subs r0, r1, r4\n"
"	adds r1, r6, 0\n"
"	bl __divsi3\n"
"	mov r10, r0\n"
"	add r0, sp, 0xD8\n"
"	str r5, [r0]\n"
"	str r4, [r0, 0x4]\n"
"	movs r7, 0\n"
"	adds r5, r0, 0\n"
"	cmp r7, r6\n"
"	bge _0807F7FC\n"
"	adds r4, r5, 0\n"
"_0807F794:\n"
"	ldr r0, [r5]\n"
"	ldr r2, [sp, 0xFC]\n"
"	adds r0, r2, r0\n"
"	str r0, [r4]\n"
"	ldr r0, [r4, 0x4]\n"
"	add r0, r10\n"
"	str r0, [r4, 0x4]\n"
"	mov r0, r8\n"
"	adds r1, r4, 0\n"
"	bl sub_804535C\n"
"	mov r0, r8\n"
"	bl sub_8045888\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F7E6\n"
"	ldr r0, [sp, 0x100]\n"
"	bl sin_4096\n"
"	lsls r0, 5\n"
"	mov r3, r8\n"
"	str r0, [r3, 0x1C]\n"
"	movs r0, 0x3B\n"
"	bl sub_803E46C\n"
"	movs r0, 0x3\n"
"	ands r0, r7\n"
"	cmp r0, 0\n"
"	bne _0807F7E6\n"
"	movs r0, 0x7\n"
"	mov r1, r9\n"
"	ands r1, r0\n"
"	mov r9, r1\n"
"	mov r0, r8\n"
"	movs r1, 0x6\n"
"	mov r2, r9\n"
"	bl sub_806CDD4\n"
"	movs r2, 0x1\n"
"	add r9, r2\n"
"_0807F7E6:\n"
"	movs r0, 0x80\n"
"	lsls r0, 4\n"
"	adds r1, r6, 0\n"
"	bl __divsi3\n"
"	ldr r3, [sp, 0x100]\n"
"	adds r3, r0\n"
"	str r3, [sp, 0x100]\n"
"	adds r7, 0x1\n"
"	cmp r7, r6\n"
"	blt _0807F794\n"
"_0807F7FC:\n"
"	ldr r4, [sp, 0xF4]\n"
"	str r4, [r5]\n"
"	add r1, sp, 0xD8\n"
"	ldr r0, [sp, 0xF8]\n"
"	str r0, [r1, 0x4]\n"
"	movs r0, 0\n"
"	mov r2, r8\n"
"	str r0, [r2, 0x1C]\n"
"	mov r0, r8\n"
"	bl sub_804535C\n"
"	movs r0, 0x3B\n"
"	bl sub_803E46C\n"
"	mov r3, r8\n"
"	ldr r0, [r3, 0x70]\n"
"	movs r1, 0x7\n"
"	mov r4, r9\n"
"	ands r4, r1\n"
"	adds r0, 0x46\n"
"	strb r4, [r0]\n"
"	add r2, sp, 0xD4\n"
"	movs r1, 0\n"
"	ldrsh r0, [r2, r1]\n"
"	adds r4, r2, 0\n"
"	movs r3, 0x2\n"
"	ldrsh r1, [r4, r3]\n"
"	bl GetTile\n"
"	ldr r6, [r0, 0x10]\n"
"	adds r0, r6, 0\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _0807F876\n"
"	add r2, sp, 0xD4\n"
"	movs r0, 0\n"
"	ldrsh r1, [r2, r0]\n"
"	movs r3, 0x2\n"
"	ldrsh r2, [r4, r3]\n"
"	mov r0, r8\n"
"	movs r3, 0x1\n"
"	bl sub_80694C0\n"
"	mov r0, r8\n"
"	bl sub_807F9BC\n"
"	b _0807F99C\n"
"	.align 2, 0\n"
"_0807F860: .4byte gFormatBuffer_Monsters\n"
"_0807F864: .4byte gUnknown_80FE690\n"
"_0807F868: .4byte 0x000001a3\n"
"_0807F86C: .4byte gAdjacentTileOffsets\n"
"_0807F870:\n"
"	ldr r0, [r7]\n"
"	str r0, [sp, 0xD4]\n"
"	b _0807F8BE\n"
"_0807F876:\n"
"	movs r5, 0\n"
"	add r4, sp, 0xE0\n"
"	adds r7, r4, 0\n"
"_0807F87C:\n"
"	ldr r0, _0807F8D0\n"
"	lsls r3, r5, 2\n"
"	adds r3, r0\n"
"	add r1, sp, 0xD4\n"
"	ldrh r0, [r1]\n"
"	ldrh r2, [r3]\n"
"	adds r0, r2\n"
"	lsls r0, 16\n"
"	lsrs r0, 16\n"
"	ldr r2, _0807F8D4\n"
"	ldr r1, [r7]\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [r4]\n"
"	add r0, sp, 0xD4\n"
"	ldrh r2, [r0, 0x2]\n"
"	ldrh r3, [r3, 0x2]\n"
"	adds r2, r3\n"
"	lsls r2, 16\n"
"	ldr r0, _0807F8D8\n"
"	ands r1, r0\n"
"	orrs r1, r2\n"
"	str r1, [r4]\n"
"	mov r0, r8\n"
"	add r1, sp, 0xE0\n"
"	bl sub_80703A0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F870\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x7\n"
"	ble _0807F87C\n"
"_0807F8BE:\n"
"	cmp r5, 0x8\n"
"	bne _0807F8DC\n"
"	ldr r0, [sp, 0xEC]\n"
"	mov r1, r8\n"
"	movs r2, 0\n"
"	movs r3, 0\n"
"	bl WarpTarget\n"
"	b _0807F8FA\n"
"	.align 2, 0\n"
"_0807F8D0: .4byte gAdjacentTileOffsets\n"
"_0807F8D4: .4byte 0xffff0000\n"
"_0807F8D8: .4byte 0x0000ffff\n"
"_0807F8DC:\n"
"	mov r0, r8\n"
"	add r1, sp, 0xD4\n"
"	bl sub_807D068\n"
"	add r0, sp, 0xD4\n"
"	movs r3, 0\n"
"	ldrsh r1, [r0, r3]\n"
"	movs r0, 0xD6\n"
"	add r0, sp\n"
"	movs r4, 0\n"
"	ldrsh r2, [r0, r4]\n"
"	mov r0, r8\n"
"	movs r3, 0x1\n"
"	bl sub_80694C0\n"
"_0807F8FA:\n"
"	adds r0, r6, 0\n"
"	bl GetEntityType\n"
"	cmp r0, 0x1\n"
"	bne _0807F954\n"
"	add r4, sp, 0xE4\n"
"	ldr r1, _0807F9AC\n"
"	adds r0, r4, 0\n"
"	bl InitPokemonMove\n"
"	adds r0, r6, 0\n"
"	adds r1, r4, 0\n"
"	bl sub_80571F0\n"
"	lsls r0, 24\n"
"	lsrs r1, r0, 24\n"
"	cmp r1, 0\n"
"	bne _0807F93C\n"
"	ldr r0, _0807F9B0\n"
"	movs r3, 0\n"
"	ldrsh r2, [r0, r3]\n"
"	str r1, [sp]\n"
"	str r1, [sp, 0x4]\n"
"	ldr r0, _0807F9B4\n"
"	str r0, [sp, 0x8]\n"
"	str r1, [sp, 0xC]\n"
"	str r1, [sp, 0x10]\n"
"	str r1, [sp, 0x14]\n"
"	ldr r0, [sp, 0xEC]\n"
"	adds r1, r6, 0\n"
"	movs r3, 0\n"
"	bl sub_806F370\n"
"_0807F93C:\n"
"	adds r0, r6, 0\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F954\n"
"	ldr r0, [r6, 0x70]\n"
"	adds r0, 0x46\n"
"	ldrb r1, [r0]\n"
"	adds r0, r6, 0\n"
"	bl sub_806CE68\n"
"_0807F954:\n"
"	ldr r0, _0807F9B0\n"
"	movs r4, 0\n"
"	ldrsh r2, [r0, r4]\n"
"	movs r1, 0\n"
"	str r1, [sp]\n"
"	str r1, [sp, 0x4]\n"
"	ldr r0, _0807F9B8\n"
"	str r0, [sp, 0x8]\n"
"	str r1, [sp, 0xC]\n"
"	str r1, [sp, 0x10]\n"
"	str r1, [sp, 0x14]\n"
"	ldr r0, [sp, 0xEC]\n"
"	mov r1, r8\n"
"	movs r3, 0\n"
"	bl sub_806F370\n"
"	mov r0, r8\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0807F98E\n"
"	mov r1, r8\n"
"	ldr r0, [r1, 0x70]\n"
"	adds r0, 0x46\n"
"	ldrb r1, [r0]\n"
"	mov r0, r8\n"
"	bl sub_806CE68\n"
"_0807F98E:\n"
"	movs r0, 0x1E\n"
"	movs r1, 0x3B\n"
"	bl sub_803E708\n"
"	mov r0, r8\n"
"	bl sub_807F9BC\n"
"_0807F99C:\n"
"	add sp, 0x10C\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0807F9AC: .4byte 0x00000163\n"
"_0807F9B0: .4byte gHurlOrbDmgValue\n"
"_0807F9B4: .4byte 0x0000021a\n"
"_0807F9B8: .4byte 0x00000219");
}

void sub_807F9BC(Entity *entity)
{
    if (EntityExists(entity)) {
        EntityInfo *entInfo = GetEntInfo(entity);
        if (entInfo->isTeamLeader) {
            gDungeon->unk1 = 0;
            gDungeon->unk5C0 = -1;
            sub_804AC20(&entity->pos);
            sub_807EC28(FALSE);
        }
        sub_806A5B8(entity);
        sub_8075900(entity, gDungeon->forceMonsterHouse);
    }
}

extern u8 sub_803D6FC(void);

void sub_807FA18(void)
{
    s32 x, y;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            Tile *tile = GetTileMut(x, y);

            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_TRAP) {
                s32 trapId;
                DungeonPos pos = {x, y};

                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_UNK6) {
                    trapId = TRAP_WARP_TRAP;
                }
                else {
                    trapId = sub_803D6FC();
                }

                if (trapId == TRAP_WONDER_TILE) {
                    Entity *trap = SpawnTrap(trapId, &pos, 2);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = TRUE;
                    }
                }
                else {
                    Entity *trap = SpawnTrap(trapId, &pos, 0);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = FALSE;
                    }
                }
            }
        }
    }
}

//
