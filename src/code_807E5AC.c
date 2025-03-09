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
#include "dungeon_random.h"
#include "code_805D8C8.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "move_util.h"
#include "moves.h"
#include "code_80450F8.h"
#include "math.h"
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
            if (EntityIsValid(wildMon)) {
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
                if (EntityIsValid(wildMon)
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
            if (EntityIsValid(mon)) {
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
        if (EntityIsValid(entity)) {
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
extern bool8 sub_8045888(Entity *ent);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
extern void sub_807D068(Entity *, DungeonPos *);
extern void sub_80694C0(Entity *target,s32 x,int y,char param_4);

void sub_807F9BC(Entity *entity);

extern const u8 *const gUnknown_80FCB40;
extern const u8 *const gUnknown_80FCB70;
extern const u8 *const gUnknown_80FE6B4;
extern const u8 *const gUnknown_80FE690;

void sub_807F43C(Entity *target, Entity *attacker)
{
    s32 attackerDirection;
    s32 var_3C;
    DungeonPos attackerPos;
    s32 pixelPosX, pixelPosY;
    PixelPos var_54;
    s32 var_30, r10;
    s32 r6;
    s32 newDir;
    s32 i, directionId;
    Entity *tileEntity;
    s32 var_2C;
    DungeonPos positions[40];
    s32 var_74[4];
    s32 positionsCounter;

    if (AbilityIsActive(attacker, ABILITY_SUCTION_CUPS)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FCB40); // is anchored, cannot be moved
        return;
    }
    if (target == attacker) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FCB70); // couldn't be thrown for some reason
        return;
    }

    attackerPos = attacker->pos;
    for (var_3C = 0; var_3C < 2; var_3C++) {
        positionsCounter = 0;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *mon = gDungeon->activePokemon[i];
            if (EntityIsValid(mon) && target != mon && attacker != mon && CanSeeTarget(target, mon)) {
                if (var_3C == 0) {
                    if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 1)
                        continue;
                }
                else {
                    if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 0)
                        continue;
                }

                if (var_3C == 0) {
                    DungeonPos pos;
                    for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                        pos.x = gAdjacentTileOffsets[directionId].x + mon->pos.x;
                        pos.y = gAdjacentTileOffsets[directionId].y + mon->pos.y;
                        if (!sub_80703A0(attacker, &pos))
                            break;
                    }

                    if (directionId != NUM_DIRECTIONS && positionsCounter < 40) {
                        positions[positionsCounter++] = mon->pos;
                    }
                }
                else {
                    DungeonPos pos;
                    for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                        pos.x = gAdjacentTileOffsets[directionId].x + mon->pos.x;
                        pos.y = gAdjacentTileOffsets[directionId].y + mon->pos.y;
                        if (!sub_80703A0(attacker, &pos) && positionsCounter < 40) {
                            positions[positionsCounter++] = pos;
                        }
                    }
                }
            }
        }

        if (positionsCounter != 0)
            break;
    }

    if (positionsCounter != 0) {
        s32 rnd = DungeonRandInt(positionsCounter);
        attackerPos = positions[rnd];
    }
    else {
        sub_80833E8(&target->pos, var_74);
        for (i = 0; i < 100; i++) {
            DungeonPos pos;
            pos.x = DungeonRandRange(var_74[0], var_74[2]);
            pos.y = DungeonRandRange(var_74[1], var_74[3]);
            if (!sub_80703A0(attacker, &pos)) {
                attackerPos = pos;
                break;
            }
        }
        if (i == 100) {
            TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FE6B4); // But it didn~27t go anywhere.
            return;
        }
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
    TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FE690); // m0 was sent flying!
    if (sub_8045888(attacker)) {
        PlaySoundEffect(0x1A3);
    }

    var_2C = 0;
    attackerDirection = GetEntInfo(attacker)->action.direction;
    r6 = max(attackerPos.x - attacker->pos.x, attackerPos.y - attacker->pos.y) << 4;
    if (r6 > 80)
        r6 = 80;
    if (r6 < 10)
        r6 = 10;

    newDir = GetDirectionTowardsPosition(&attackerPos, &attacker->pos);

    pixelPosX = X_POS_TO_PIXELPOS(attackerPos.x) + ((gAdjacentTileOffsets[newDir].x << 8) / 3);
    pixelPosY = Y_POS_TO_PIXELPOS(attackerPos.y) + ((gAdjacentTileOffsets[newDir].y << 8) / 3);

    var_30 = (pixelPosX - attacker->pixelPos.x) / r6;
    r10 = (pixelPosY - attacker->pixelPos.y) / r6;
    var_54.x = attacker->pixelPos.x;
    var_54.y = attacker->pixelPos.y;
    for (i = 0; i < r6; i++) {
        var_54.x += var_30;
        var_54.y += r10;
        sub_804535C(attacker, &var_54);
        if (sub_8045888(attacker)) {
            attacker->unk1C.raw = sin_4096(var_2C) << 5;
            DungeonRunFrameActions(0x3B);
            if (!(i & 3)) {
                attackerDirection &= DIRECTION_MASK;
                sub_806CDD4(attacker, 6, attackerDirection);
                attackerDirection++;
            }
        }
        var_2C += (0x800 / r6);
    }

    var_54.x = pixelPosX;
    var_54.y = pixelPosY;
    attacker->unk1C.raw = 0;
    sub_804535C(attacker, &var_54);
    DungeonRunFrameActions(0x3B);
    GetEntInfo(attacker)->action.direction = attackerDirection & DIRECTION_MASK;

    tileEntity = GetTile(attackerPos.x, attackerPos.y)->monster;
    if (!EntityIsValid(tileEntity)) {
        sub_80694C0(attacker, attackerPos.x, attackerPos.y, 1);
        sub_807F9BC(attacker);
    }
    else {
        for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
            DungeonPos pos;

            pos.x = gAdjacentTileOffsets[directionId].x + attackerPos.x;
            pos.y = gAdjacentTileOffsets[directionId].y + attackerPos.y;
            if (!sub_80703A0(attacker, &pos)) {
                attackerPos = pos;
                break;
            }
        }
        if (directionId == NUM_DIRECTIONS) {
            WarpTarget(target, attacker, 0, NULL);
        }
        else {
            sub_807D068(attacker, &attackerPos);
            sub_80694C0(attacker, attackerPos.x, attackerPos.y, 1);
        }

        if (GetEntityType(tileEntity) == ENTITY_MONSTER) {
            Move move;

            InitPokemonMove(&move, MOVE_REGULAR_ATTACK);
            if (!sub_80571F0(tileEntity, &move)) {
                sub_806F370(target, tileEntity, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, 0x21A, 0, 0, 0);
            }
            if (EntityIsValid(tileEntity)) {
                sub_806CE68(tileEntity, GetEntInfo(tileEntity)->action.direction);
            }
        }

        sub_806F370(target, attacker, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, 0x219, 0, 0, 0);
        if (EntityIsValid(attacker)) {
            sub_806CE68(attacker, GetEntInfo(attacker)->action.direction);
        }
        sub_803E708(0x1E, 0x3B);
        sub_807F9BC(attacker);
    }
}

void sub_807F9BC(Entity *entity)
{
    if (EntityIsValid(entity)) {
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

extern SpriteOAM gUnknown_202EDC0;

void sub_807FA9C(void)
{
    s32 x, y;
    bool8 unkBool = gDungeon->unk181e8.showInvisibleTrapsMonsters;

    for (y = gDungeon->unk181e8.cameraPos.y - 5; y < gDungeon->unk181e8.cameraPos.y + 5; y++) {
        for (x = gDungeon->unk181e8.cameraPos.x - 6; x < gDungeon->unk181e8.cameraPos.x + 6; x++) {
            bool8 r6 = FALSE;
            const Tile *tile = GetTile(x, y);

            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP && (tile->object->isVisible || unkBool)) {
                r6 = TRUE;
            }
            if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                r6 = TRUE;
            }

            if (r6) {
                s32 spriteX = (x * 24) - gDungeon->unk181e8.cameraPixelPos.x;
                s32 spriteY = (y * 24) - gDungeon->unk181e8.cameraPixelPos.y;
                if (spriteX >= -32 && spriteY >= -32 && spriteX <= 272 && spriteY <= 192)  {
                    SpriteSetObjMode(&gUnknown_202EDC0, 0);
                    SpriteSetY(&gUnknown_202EDC0, spriteY);
                    SpriteSetX(&gUnknown_202EDC0, spriteX);
                    SpriteSetPriority(&gUnknown_202EDC0, 3);
                    SpriteSetPalNum(&gUnknown_202EDC0, 10);
                    SpriteSetTileNum(&gUnknown_202EDC0, 0x1FC);

                    AddSprite(&gUnknown_202EDC0, 0, NULL, NULL);
                }
            }
        }
    }
}

//
