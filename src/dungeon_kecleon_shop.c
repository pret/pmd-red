#include "global.h"
#include "globaldata.h"
#include "dungeon_kecleon_shop.h"
#include "weather.h"
#include "code_804267C.h"
#include "dungeon_vram.h"
#include "dungeon_info.h"
#include "dungeon_config.h"
#include "dungeon_range.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "structs/map.h"
#include "dungeon_message.h"
#include "dungeon_logic.h"
#include "string_format.h"
#include "dungeon_map_access.h"
#include "position_util.h"
#include "dungeon_ai.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "code_805D8C8.h"
#include "dungeon_items.h"
#include "move_util.h"
#include "moves.h"
#include "math.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "dungeon_misc.h"
#include "sprite.h"
#include "dungeon_strings.h"
#include "dungeon_engine.h"

static void sub_807EFFC(bool8 arg0);
static s32 sub_807F19C(bool8 arg0);
static void sub_807F33C(void);

void sub_807EC28(bool8 arg0)
{
    Entity *leader;
    EntityInfo *leaderInfo;
    bool32 prevTileWasShop;
    bool32 isShopTile;

    if (IsFloorOver())
        return;

    leader = GetLeader();
    leaderInfo = GetEntInfo(leader);
    prevTileWasShop = gDungeon->unk644.unk54;
    isShopTile = (GetTileAtEntitySafe(leader)->terrainFlags & TERRAIN_TYPE_SHOP) != 0;
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
        if (tile->terrainFlags & TERRAIN_TYPE_SHOP) {
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

static void sub_807EFFC(bool8 arg0)
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
                if (tile->terrainFlags & TERRAIN_TYPE_SHOP && tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                    Item *itemPtr = GetItemInfo(tile->object);
                    if (!ItemInShop(itemPtr)) {
                        Item item = *itemPtr;
                        RemoveGroundItem(&pos, 1);
                        if (IsShoppableItem(item.id)) {
                            item.flags |= ITEM_FLAG_IN_SHOP;
                        }
                        SpawnItem(&pos, &item, 1);
                    }
                }
            }
        }

        gDungeon->unk644.unk50 += (gDungeon->unk644.unk48 - local_24);
        DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE4F4, 1); // Your patronage is valued
    }
}

static s32 sub_807F19C(bool8 arg0)
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
                if (!(tile->terrainFlags & TERRAIN_TYPE_SHOP) && tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                    Item *itemPtr = GetItemInfo(tile->object);
                    if (IsShoppableItem(itemPtr->id)) {
                        itemPtr->flags &= ~(ITEM_FLAG_IN_SHOP);
                    }
                }
            }
        }

        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (ItemExists(item) && IsShoppableItem(item->id)) {
                item->flags &= ~(ITEM_FLAG_IN_SHOP);
            }
        }

        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *mon = gDungeon->activePokemon[i];
            if (EntityIsValid(mon)) {
                EntityInfo *monInfo = GetEntInfo(mon);
                Item *item = &monInfo->heldItem;
                if (ItemExists(item) && IsShoppableItem(item->id)) {
                    item->flags &= ~(ITEM_FLAG_IN_SHOP);
                }
            }
        }
        gDungeon->unk644.unk50 = gDungeon->unk644.unk48;
        DisplayDungeonMessage(&dialogueInfo, gUnknown_80FE4D4, TRUE); // Thank you very much.
    }

    return 0;
}

static void sub_807F33C(void)
{
    s32 i, x, y;

    gDungeon->unk644.unk2A = 1;
    gDungeon->unk644.unk2B = 1;
    LogMessageByIdWithPopupCheckUser(GetLeader(), gUnknown_80FE4B8); // Help! Thief! I've been robbed! Help me catch the thief.
    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            const Tile *tile = GetTile(x,y);
            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM) {
                Item *item = GetItemInfo(tile->object);
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
