#include "global.h"
#include "globaldata.h"
#include "dungeon_items.h"
#include "code_8041AD0.h"
#include "code_80869E4.h"
#include "dungeon_range.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "structs/str_dungeon.h"
#include "constants/item.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_map.h"
#include "dungeon_strings.h"
#include "dungeon_logic.h"
#include "dungeon_data.h"
#include "dungeon_pos_data.h"
#include "dungeon_spawns.h"
#include "dungeon_cutscene.h"
#include "dungeon_boss_dialogue.h"
#include "string_format.h"
#include "items.h"
#include "structs/map.h"
#include "trap.h"
#include "math.h"
#include "structs/str_item_text.h"
#include "dungeon_vram.h"
#include "sprite.h"

extern void sub_80416E0(PixelPos *r0, u32, bool8);
extern void sub_804178C(u32);
extern void sub_804219C(PixelPos *pos);

static void MusicBoxCreation(void);
static u8 sub_8046D70(void);

static EWRAM_INIT u8 sUnkItemTileNums[8] = {0x15, 0x00, 0x16, 0x00, 0x15, 0x00, 0x16, 0x00};
static EWRAM_INIT u8 sUnkItemMatrixNums[8] = {0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x02};

static void sub_8046734(Entity *entity, DungeonPos *pos);
static void sub_8046CE4(Item *item,s32 param_2);

static const struct unkStruct_8090F58 gUnknown_80F6990 = {1, 1, 0, 0, 1};
static const struct unkStruct_8090F58 gUnknown_80F699C = {0, 0, 0, 0, 1};
static const struct unkStruct_8090F58 gUnknown_80F69A8 = {0, 0, 0, 0, 0};

void sub_8045BF8(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F699C);
}

void sub_8045C08(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F69A8);
}

void sub_8045C18(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F6990);
}

void CreateItemWithStickyChance(Item *item, u8 itemID, u32 forceSticky)
{
    bool8 stickyFlag;

    ItemIdToItem(item, itemID, FALSE);
    stickyFlag = FALSE;
    if (IsNotSpecialItem(itemID)) {
        if (forceSticky == FORCE_STICKY_RANDOM) {
            if (DungeonRandInt(100) < gDungeon->floorProperties.itemStickyChance)
                stickyFlag = TRUE;
            else
                stickyFlag = FALSE;
        }
        else if (forceSticky == FORCE_STICKY_ALWAYS) {
            stickyFlag = TRUE;
        }
    }

    if (stickyFlag) {
        item->flags |= ITEM_FLAG_STICKY;
    }

    if (GetItemCategory(itemID) == CATEGORY_POKE) {
        sub_8046CE4(item, gDungeon->floorProperties.unk17 * 40);
    }
}

void CreateFloorItems(void)
{
    u8 itemID;
    s32 yCounter, xCounter;
    const Tile *tile;
    s32 spawnType;
    Item item;
    u32 flag;
    s32 x = DungeonRandInt(DUNGEON_MAX_SIZE_X);
    s32 y = DungeonRandInt(DUNGEON_MAX_SIZE_Y);

    gDungeon->numItems = 0;
    for (yCounter = 0; yCounter < DUNGEON_MAX_SIZE_Y; yCounter++) {
        y++;
        if (y == DUNGEON_MAX_SIZE_Y) {
            y = 0;
        }

        for (xCounter = 0; xCounter < DUNGEON_MAX_SIZE_X; xCounter++) {
            x++;
            flag = ITEM_FLAG_IN_SHOP;
            if (x == DUNGEON_MAX_SIZE_X) {
                x = 0;
            }
            tile = GetTile(x,y);

            if (!(tile->terrainFlags & TERRAIN_TYPE_STAIRS) && (tile->spawnOrVisibilityFlags.spawn & SPAWN_FLAG_ITEM)) {
                DungeonPos pos;
                bool8 shopFlag = FALSE;
                pos.x = x;
                pos.y = y;

                if (tile->terrainFlags & TERRAIN_TYPE_SHOP) {
                    shopFlag = TRUE;
                    spawnType = ITEM_SPAWN_IN_SHOP;
                }
                else
                {
                    if (GetTerrainType(tile) == TERRAIN_TYPE_WALL) {
                        spawnType = ITEM_SPAWN_WALL;
                    }
                    else {
                        spawnType = (tile->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE) ? ITEM_SPAWN_IN_MONSTER_HOUSE : ITEM_SPAWN_NORMAL;
                    }
                }
                itemID = GetRandomFloorItem(spawnType);
                if (!IsShoppableItem(itemID)) {
                    shopFlag = FALSE;
                }
                CreateItemWithStickyChance(&item,itemID,FORCE_STICKY_RANDOM);
                if (shopFlag) {
                    item.flags |= flag;
                }
                SpawnItem(&pos,&item,TRUE);
            }
        }
    }
}

void TryLeaderItemPickUp(struct DungeonPos *pos, bool8 printMsg)
{
    Item *tileItem;
    int inventoryIds[INVENTORY_SIZE + 1];
    Item *inventoryItems[INVENTORY_SIZE + 1];
    Entity *leader = GetLeader();
    EntityInfo *leaderInfo = GetEntInfo(leader);
    const Tile *tile = GetTile(pos->x,pos->y);
    Entity *tileObject = tile->object;
    if (tileObject == NULL) {
        return;
    }
    if (GetEntityType(tileObject) != ENTITY_ITEM) {
        return;
    }
    tileItem = GetItemInfo(tileObject);
    if (leaderInfo->action.actionParameters[0].actionUseIndex == 0) {
        if (!printMsg) {
            return;
        }
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        LogMessageByIdWithPopupCheckUser(leader,gMonSteppedOnItem);
    }
    else if (ShouldMonsterRunAwayAndShowEffect(leader,1)) {
        if (!printMsg) {
            return;
        }
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        LogMessageByIdWithPopupCheckUser(leader,gMonTerrifiedCouldntPickUpItem);
    }
    else if (GetItemCategory(tileItem->id) == CATEGORY_POKE) {
        PlaySoundEffect(0x14c);
        AddToTeamMoney(GetMoneyValue(tileItem));
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        RemoveGroundItem(pos,TRUE);
        LogMessageByIdWithPopupCheckUser(leader,gPickedUpItem);
        DisplayItemTip(tileItem->id);
    }
    else {
        s32 i, maxItems;
        if (gDungeon->unk644.hasInventory) {
            for (i = 0; i < INVENTORY_SIZE; i++) {
                inventoryItems[i] = &gTeamInventoryRef->teamItems[i];
                inventoryIds[i] = i;
            }
            maxItems = INVENTORY_SIZE;
        }
        else {
            inventoryItems[0] = &leaderInfo->heldItem;
            inventoryIds[0] = -1;
            maxItems = 1;
        }

        if (tileItem->id <= ITEM_GEO_PEBBLE && !(tileItem->flags & ITEM_FLAG_IN_SHOP)) {
            s32 index = -1;
            s32 numberItems = -1;
            s32 i;

            for (i = 0; i < maxItems; i++) {
                if (ItemExists(inventoryItems[i])
                    && !(inventoryItems[i]->flags & ITEM_FLAG_IN_SHOP)
                    && (tileItem->id == inventoryItems[i]->id)
                    && (tileItem->flags & ITEM_FLAG_STICKY) == (inventoryItems[i]->flags & ITEM_FLAG_STICKY)
                    && inventoryItems[i]->quantity != 99
                    && numberItems < inventoryItems[i]->quantity)
                {
                    numberItems = inventoryItems[i]->quantity;
                    index = i;
                }
            }

            if (index == -1) {
                s32 i;

                numberItems = -1;
                for (i = 0; i < maxItems; i++) {
                    if (ItemExists(inventoryItems[i])
                        && !(inventoryItems[i]->flags & ITEM_FLAG_IN_SHOP)
                        && tileItem->id == inventoryItems[i]->id
                        && inventoryItems[i]->quantity != 99
                        && numberItems < inventoryItems[i]->quantity)
                    {
                        numberItems = inventoryItems[i]->quantity;
                        index = i;
                    }
                }
            }

            if (index != -1) {
                struct Item *addedItem = inventoryItems[index];
                s32 newQuantity = addedItem->quantity + tileItem->quantity;

                if (newQuantity >= 99) {
                    newQuantity = 99;
                }
                addedItem->quantity = newQuantity;

                if (tileItem->flags & ITEM_FLAG_STICKY) {
                    inventoryItems[index]->flags |= ITEM_FLAG_STICKY;
                }
                sub_8045BF8(gFormatBuffer_Items[0],tileItem);
                RemoveGroundItem(pos,TRUE);
                PlaySoundEffect(0x14a);
                if (inventoryIds[index] < 0) {
                    LogMessageByIdWithPopupCheckUser(leader,gPickedUpItem2);
                }
                else {
                    LogMessageByIdWithPopupCheckUser(leader,gPickedUpItemToolbox);
                }
                DisplayItemTip(tileItem->id);
                return;
            }
        }

        for (i = 0; i < maxItems; i++) {
            if (!ItemExists(inventoryItems[i]))
                break;
        }

        if (i == maxItems) {
            if (!printMsg) {
                return;
            }
            sub_8045BF8(gFormatBuffer_Items[0],tileItem);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
            LogMessageByIdWithPopupCheckUser(leader,gMonSteppedOnItem);
        }
        else {
            PlaySoundEffect(0x14a);
            if (inventoryIds[i] < 0) {
                leaderInfo->heldItem = *tileItem;
                sub_8045BF8(gFormatBuffer_Items[0],tileItem);
                RemoveGroundItem(pos,TRUE);
                LogMessageByIdWithPopupCheckUser(leader,gPickedUpItem2);
            }
            else if (AddItemToInventory(tileItem) != 0) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
                LogMessageByIdWithPopupCheckUser(leader,gMonCouldntPickUpItem);
            }
            else {
                sub_8045BF8(gFormatBuffer_Items[0],tileItem);
                RemoveGroundItem(pos,TRUE);
                LogMessageByIdWithPopupCheckUser(leader,gPickedUpItemToolbox);
            }
            DisplayItemTip(tileItem->id);
         }
    }
}

bool8 SpawnItem(DungeonPos *pos, Item *item, bool8 a2)
{
    s32 i, count;
    Tile *tile;
    Entity *itemEntity = SpawnItemEntity(pos);

    if (itemEntity == NULL)
        return FALSE;
    *itemEntity->axObj.info.item = *item;
    itemEntity->axObj.info.item->flags &= ~(ITEM_FLAG_SET);
    itemEntity->isVisible = TRUE;
    tile = GetTileMut(pos->x, pos->y);
    tile->object = itemEntity;
    if ((tile->terrainFlags & TERRAIN_TYPE_SHOP) && IsShoppableItem(item->id)) {
        if (item->flags & ITEM_FLAG_IN_SHOP) {
            if (a2) {
                gDungeon->unk644.unk48 += GetActualBuyPrice(item);
            }
        }
        else {
            gDungeon->unk644.unk4C += GetActualSellPrice(item);
        }
    }

    count = 0;
    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        if (EntityIsValid(gDungeon->items[i])) {
            count = i + 1;
        }
    }
    gDungeon->numItems = count;
    return TRUE;
}

bool8 RemoveGroundItem(DungeonPos *pos, bool8 a2)
{
    s32 i, count;
    Item *item;
    Tile *tile = GetTileMut(pos->x, pos->y);
    Entity *tileObject = tile->object;
    if (tileObject == NULL || GetEntityType(tileObject) != ENTITY_ITEM)
        return FALSE;

    item = GetItemInfo(tileObject);
    if ((tile->terrainFlags & TERRAIN_TYPE_SHOP) && IsShoppableItem(item->id)) {
        if (item->flags & ITEM_FLAG_IN_SHOP) {
            if (a2) {
                gDungeon->unk644.unk48 -= GetActualBuyPrice(item);
            }
        }
        else {
            gDungeon->unk644.unk4C -= GetActualSellPrice(item);
        }
    }

    tile->object = NULL;
    tileObject->type = ENTITY_NOTHING;

    count = 0;
    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        if (EntityIsValid(gDungeon->items[i])) {
            count = i + 1;
        }
    }
    gDungeon->numItems = count;
    return TRUE;
}

static s32 GetItemIconId(Item *item)
{
    return gItemParametersData[item->id].icon;
}

bool8 sub_80462AC(Entity * entity, u8 hallucinating, u8 a2, u8 a3, u8 a4)
{
    s32 x, y, y2;
    s32 objMode = 0;

    if (!EntityIsValid(entity))
        return FALSE;

    if (a2) {
        s32 terrainFlags = GetTerrainType(GetTile(entity->pos.x, entity->pos.y));

        if (terrainFlags == TERRAIN_TYPE_WALL)
            return FALSE;
        if (terrainFlags == TERRAIN_TYPE_SECONDARY) {
            objMode = 1;
        }

        if (!ShouldDisplayEntity(entity))
            return FALSE;
    }

    x = (entity->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
    y = ((entity->pixelPos.y - entity->unk1C.raw) / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 = ((entity->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y) + 8;
    y2 /= 2;

    if (x >= -32 && y >= -32 && x <= 272 && y <= 192) {
        s32 tileNum;

        SpriteSetMatrixNum(&gUnknown_202EDC0, 0);
        if (hallucinating) {
            tileNum = 0x17;
            SpriteSetPalNum(&gUnknown_202EDC0, 10);
        }
        else {
            tileNum = GetItemIconId(entity->axObj.info.item);
            if (a3 != 0xFF && tileNum == 0) {
                tileNum = sUnkItemTileNums[a3];
                SpriteSetMatrixNum(&gUnknown_202EDC0, sUnkItemMatrixNums[a3] * 8);
            }
            SpriteSetPalNum(&gUnknown_202EDC0, GetItemPalette(entity->axObj.info.item->id));
        }

        SpriteSetY(&gUnknown_202EDC0, y);
        SpriteSetX(&gUnknown_202EDC0, x);
        SpriteSetObjMode(&gUnknown_202EDC0, objMode);
        SpriteSetPriority(&gUnknown_202EDC0, 3);
        SpriteSetTileNum(&gUnknown_202EDC0, 0x1A0 + tileNum * 4);
        if (!a4) {
            y2 = 1;
        }
        AddSprite(&gUnknown_202EDC0, y2, NULL, NULL);
        return TRUE;
    }

    return FALSE;
}

const u8 *sub_80464AC(Item *item)
{
    return gActions[GetItemActionType(item->id)].desc;
}

void SpawnDroppedItemWrapper(Entity *entity, DungeonPos *pos, Item *item)
{
    s32 x, y;
    Entity itemEntity;

    itemEntity.type = ENTITY_ITEM;
    itemEntity.unk24 = 0;
    itemEntity.isVisible = TRUE;
    itemEntity.unk22 = 0;
    itemEntity.axObj.info.item = item;
    itemEntity.pos = *pos;

    x = ((pos->x * 24) + 4) << 8;
    y = ((pos->y * 24) + 4) << 8;
    SetEntityPixelPos(&itemEntity, x, y);
    itemEntity.spawnGenID = 0;
    SpawnDroppedItem(entity, &itemEntity, item, TRUE, NULL);
}

void SpawnDroppedItem(Entity *entity1, Entity *entity2, Item *item, bool8 a3, DungeonPos *pos)
{
    DungeonPos localPos;
    DungeonPos localPos2;
    s32 i;
    const Tile *tile = GetTile(entity2->pos.x, entity2->pos.y);
    Entity *tileObject = tile->object;
    bool8 var_24 = FALSE;

    if (tileObject != NULL && GetEntityType(tileObject) == ENTITY_TRAP) {
        sub_8046734(entity2, &entity2->pos);
        sub_807FE44(&entity2->pos, 1);
        LogMessageByIdWithPopupCheckUser(entity1, gUnknown_80FED30);
        if (!ItemExists(item))
            return;
    }

    localPos.x = entity2->pos.x;
    localPos.y = entity2->pos.y;
    localPos2 = localPos;
    if (a3) {
        i = 0;
    }
    else {
        i = 1;
    }

    while (1) {
        if (gUnknown_80F4468[i].x == 99) {
            var_24 = FALSE;
            break;
        }
        localPos.x = entity2->pos.x + gUnknown_80F4468[i].x;
        localPos.y = entity2->pos.y + gUnknown_80F4468[i].y;
        tile = GetTile(localPos.x, localPos.y);
        if (GetTerrainType(tile) != TERRAIN_TYPE_WALL && !(tile->terrainFlags & TERRAIN_TYPE_STAIRS) && tile->object == NULL) {
            sub_8046734(entity2, &localPos);
            localPos2 = localPos;
            if (GetTerrainType(tile) == (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL) || (SpawnItem(&localPos, item, TRUE))) {
                var_24 = TRUE;
            }
            break;
        }
        i++;
    }

    sub_8045BF8(gFormatBuffer_Items[0], item);
    if (var_24) {
        DrawMinimapTile(localPos.x, localPos.y);
        switch (GetTerrainType(GetTile(localPos.x, localPos.y))) {
            case TERRAIN_TYPE_NORMAL:
                LogMessageByIdWithPopupCheckUserUnknown(entity1, &localPos, gItemFellOnGround);
                break;
            case TERRAIN_TYPE_SECONDARY:
                LogMessageByIdWithPopupCheckUserUnknown(entity1, &localPos, gItemFellInWater);
                break;
            case TERRAIN_TYPE_WALL:
                LogMessageByIdWithPopupCheckUserUnknown(entity1, &localPos, gItemBuried);
                break;
            case TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL:
                LogMessageByIdWithPopupCheckUserUnknown(entity1, &localPos, gItemFellOutOfSight);
                break;
        }
    }
    else {
        PixelPos pixelPos;

        pixelPos.x = X_POS_TO_PIXELPOS(localPos2.x);
        pixelPos.y = X_POS_TO_PIXELPOS(localPos2.y); // Intentional or a typo(X vs Y)?
        if (pos != NULL) {
            pixelPos.x += pos->x << 8;
            pixelPos.y += pos->y << 8;
        }

        sub_804219C(&pixelPos);
        LogMessageByIdWithPopupCheckUserUnknown(entity1, &localPos, gItemLost);
    }
}

static void sub_8046734(Entity *entity, DungeonPos *pos)
{
    PixelPos posPixel;
    PixelPos calcPixelPos;
    bool8 hallucinating = gDungeon->unk181e8.hallucinating;

    posPixel.x = ((pos->x * 24) + 4) << 8;
    posPixel.y = ((pos->y * 24) + 4) << 8;
    if (abs(entity->pixelPos.x - posPixel.x) > 11 || abs(entity->pixelPos.y - posPixel.y) > 11) {
        s32 i;
        PixelPos add;
        s32 unk = 0; // Direction?
        s32 sinVal = 0;

        calcPixelPos.x = entity->pixelPos.x;
        calcPixelPos.y = entity->pixelPos.y;

        add.x = (posPixel.x - calcPixelPos.x) / 24;
        add.y = (posPixel.y - calcPixelPos.y) / 24;
        for (i = 0; i < 24; i++) {
            calcPixelPos.x += add.x;
            calcPixelPos.y += add.y;
            entity->unk1C.raw = sin_4096(sinVal) * 12;
            UpdateEntityPixelPos(entity, &calcPixelPos);
            sub_80462AC(entity, hallucinating, 0, unk, 0);
            DungeonRunFrameActions(0x13);
            sinVal += 85;
            if ((i & 3) == 0) {
                unk++;
            }
            unk &= 7;
        }
    }

    SetEntityPixelPos(entity, posPixel.x, posPixel.y);
    entity->unk1C.raw = 0;
    sub_80462AC(entity, hallucinating, 1, 0xFF, 0);
    DungeonRunFrameActions(0x13);
}

void sub_8046860(Entity *entity, DungeonPos *pos, Item *item, s32 a4)
{
    sub_804687C(entity, pos, pos, item, a4);
}

void sub_804687C(Entity *entity, DungeonPos *pos1, DungeonPos *pos2, Item *item, s32 count)
{
    Entity itemEntities[10];
    DungeonPos targetTilePos[10];
    PixelPos itemVelocity[10];
    u8 targetTileUsed[30];
    s32 sinVal;
    s32 i;
    bool8 r1, r9;

    for (i = 0; i < 30; i++) {
        targetTileUsed[i] = 0;
    }

    for (i = 0; i < count; i++) {
        s32 j;
        bool8 foundTile = FALSE;
        DungeonPos pos;

        pos.x = pos2->x;
        pos.y = pos2->y;

        for (j = 0; j < 30; j++) {
            if (gUnknown_80F4468[j].x == 99)
                break;
            if (!targetTileUsed[j]) {
                const Tile *tile;

                pos.x = pos2->x + gUnknown_80F4468[j].x;
                pos.y = pos2->y + gUnknown_80F4468[j].y;

                tile = GetTile(pos.x, pos.y);
                if (GetTerrainType(tile) != TERRAIN_TYPE_WALL && !(tile->terrainFlags & TERRAIN_TYPE_STAIRS) && tile->object == NULL) {
                    targetTilePos[i] = pos;
                    targetTileUsed[j] = TRUE;
                    foundTile = TRUE;
                    break;
                }
            }
        }

        if (!foundTile) {
            targetTilePos[i].x = -1;
            targetTilePos[i].y = -1;
        }
    }

    r1 = FALSE;
    r9 = FALSE;
    for (i = 0; i < count; i++) {
        if (targetTilePos[i].x < 0) {
            itemEntities[i].type = ENTITY_NOTHING;
            r9 = TRUE;
        }
        else {
            s32 x, y;

            itemEntities[i].type = ENTITY_ITEM;
            itemEntities[i].unk24 = 0;
            itemEntities[i].isVisible = TRUE;
            itemEntities[i].unk22 = 0;
            itemEntities[i].axObj.info.item = &item[i];
            itemEntities[i].pos = targetTilePos[i];
            x = ((pos1->x * 24) + 4) << 8;
            y = ((pos1->y * 24) + 4) << 8;
            SetEntityPixelPos(&itemEntities[i], x, y);
            itemEntities[i].spawnGenID = 0;
            itemVelocity[i].x = ((((targetTilePos[i].x * 24) + 4) << 8) - (itemEntities[i].pixelPos.x)) / 24;
            itemVelocity[i].y = ((((targetTilePos[i].y * 24) + 4) << 8) - (itemEntities[i].pixelPos.y)) / 24;
            r1 = TRUE;
        }
    }

    if (!r1) {
        if (count > 1) {
            LogMessageByIdWithPopupCheckUser(entity, gAllItemsLost);
        }
        else {
            LogMessageByIdWithPopupCheckUser(entity, gItemLost);
        }
    }
    else {
        s32 counter;
        s32 dirMaybe;
        bool8 hallucinating;

        if (r9) {
            LogMessageByIdWithPopupCheckUser(entity, gSeveralItemsLost);
        }

        dirMaybe = 0;
        hallucinating = gDungeon->unk181e8.hallucinating;
        sinVal = 0;
        for (counter = 0; counter < 24; counter++) {
            for (i = 0; i < count; i++) {
                if (EntityIsValid(&itemEntities[i])) {
                    IncreaseEntityPixelPos(&itemEntities[i], itemVelocity[i].x, itemVelocity[i].y);
                    itemEntities[i].unk1C.raw = sin_4096(sinVal) * 12;
                    sub_80462AC(&itemEntities[i], hallucinating, 1, dirMaybe, 0);
                }
            }
            DungeonRunFrameActions(0x13);
            sinVal += 85;
            if ((counter & 3) == 0) {
                dirMaybe++;
            }
            dirMaybe &= 7;
        }

        for (i = 0; i < count; i++) {
            if (targetTilePos[i].x >= 0) {
                SpawnItem(&targetTilePos[i], &item[i], TRUE);
            }
        }
    }
}

bool8 HasHeldItem(Entity *pokemon, u8 id)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (!ItemExists(&pokemonInfo->heldItem)) {
        return FALSE;
    }
    if (pokemonInfo->heldItem.flags & ITEM_FLAG_STICKY) {
        return FALSE;
    }
    if (pokemonInfo->heldItem.id != id) {
        return FALSE;
    }
    return TRUE;
}

static void sub_8046CE4(Item *item,s32 param_2)
{
    s32 i;
    s32 rand = DungeonRandInt(100);

    for (i = 0; i < 200; i++) {
        if (gUnknown_810A3F0[rand] <= param_2) {
            item->quantity = rand;
            return;
        }
        rand /= 2;
    }
    item->quantity = 1;
}

void sub_8046D20(void)
{
    u8 cVar1;

    cVar1 = gDungeon->unk8;
    gDungeon->unk8 = sub_8046D70();
    if (((gDungeon->unk8 == 1) && (cVar1 == 0)) &&
         (DisplayDungeonYesNoMessage(0, gUnknown_80FA408, 1) == 1)) {
        gDungeon->unk4 = 1;
        gDungeon->unk11 = 2;
    }
    else {
        MusicBoxCreation();
    }
}

static u8 sub_8046D70(void)
{
    if (gDungeon->unk644.unk46)
        return 0;
    else
        return 0;
}

static void MusicBoxCreation(void)
{
    bool8 musicBoxOnce;
    bool8 createMusicBox;
    s32 i;
    s32 indexes[3];

    createMusicBox = FALSE;
    do {
        musicBoxOnce = FALSE;
        indexes[0] = -1;
        indexes[1] = -1;
        indexes[2] = -1;

        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (ItemExists(item)) {
                if (item->id == ITEM_ROCK_PART) {
                    indexes[0] = i;
                }
                if (item->id == ITEM_ICE_PART) {
                    indexes[1] = i;
                }
                if (item->id == ITEM_STEEL_PART) {
                    indexes[2] = i;
                }
            }
        }

        if ((indexes[0] >= 0) && (indexes[1] >= 0) && (indexes[2] >= 0)) {

            musicBoxOnce = TRUE;
            createMusicBox = TRUE;

            // clear out each of the parts
            ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[0]]);
            ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[1]]);
            ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[2]]);

            // init the music box
            ItemIdToItem(&gTeamInventoryRef->teamItems[indexes[0]], ITEM_MUSIC_BOX, 0);
        }
    } while (musicBoxOnce);

    FillInventoryGaps();

    if (createMusicBox) {
        Entity *leader = GetLeader();
        sub_80855E4(sub_80861A8);
        gDungeon->unk1356C = 1;
        DisplayDungeonMessage(0,gUnknown_810531C,1);
        sub_803E708(0x3c,0x41);
        DisplayDungeonMessage(0,gUnknown_8105360,1);
        sub_80869E4(leader,4,10,0);
        sub_80416E0(&leader->pixelPos,0x10c,FALSE);
        sub_80421C0(leader,0xd7);
        sub_803E708(0x3c,0x41);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        DisplayDungeonMessage(0,gUnknown_81053A8,1);
        sub_803E708(10,0x41);
        PlaySoundEffect(0xd4);
        DisplayDungeonMessage(0,gUnknown_8105434,1);
        sub_803E708(10,0x41);
        sub_804178C(1);
        gDungeon->unk1356C = 0;
        UpdateMinimap();
    }
}

bool8 sub_8046F00(Item *item)
{
    s32 i;

    if (GetItemCategory(item->id) == CATEGORY_TMS_HMS) {
        u16 moveID = GetItemMoveID(item->id);
        if (!IsHMItem(item->id)) {
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                Entity *entity = gDungeon->teamPokemon[i];
                if (EntityIsValid(entity)) {
                    bool8 canLearnMove = CanMonLearnMove(moveID, GetEntInfo(entity)->id);
                    bool8 cannotMove = CheckVariousStatuses2(entity, FALSE);
                    if (cannotMove) {
                        canLearnMove = FALSE;
                    }
                    if (canLearnMove)
                        return TRUE;
                }
            }
        }
        return FALSE;
    }

    return TRUE;
}

void ClearAllItemsWithFlag(s32 itemFlag)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if ((item->flags & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
            ZeroOutItem(item);
        }
    }
    FillInventoryGaps();

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *entityInfo = GetEntInfo(entity);
            Item *item = &entityInfo->heldItem;
            if ((item->flags & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
                ZeroOutItem(item);
            }
        }
    }
}

void AllItemsToPlainSeed(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++)
    {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if ((item->flags & ITEM_FLAG_EXISTS)) {
            ItemIdToItem(item, ITEM_PLAIN_SEED, FALSE);
        }
    }
    FillInventoryGaps();

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *entityInfo = GetEntInfo(entity);
            Item *item = &entityInfo->heldItem;
            if ((item->flags & ITEM_FLAG_EXISTS)) {
                ItemIdToItem(item, ITEM_PLAIN_SEED, FALSE);
            }
        }
    }
}

bool8 PlayerHasItemWithFlag(s32 itemFlag)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++)
    {
        if ((ItemExists(&gTeamInventoryRef->teamItems[i])) && (gTeamInventoryRef->teamItems[i].flags & itemFlag)) {
            return TRUE;
        }
    }
    FillInventoryGaps();

    for (i = 0; i < MAX_TEAM_MEMBERS; i++)
    {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *entityInfo = GetEntInfo(entity);
            Item *item = &entityInfo->heldItem;
            if ((ItemExists(item) & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void CleanUpInventoryItems(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if (item->flags & ITEM_FLAG_EXISTS) {
            if (item->id == ITEM_POKE) {
                AddToTeamMoney(GetMoneyValue(item));
                ZeroOutItem(item);
            }
            if (item->flags & ITEM_FLAG_IN_SHOP) {
                ZeroOutItem(item);
            }
        }
    }
    FillInventoryGaps();
}

void ClearUnpaidFlagFromAllItems(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(item) && item->flags & ITEM_FLAG_UNPAID) {
            item->flags &= ~(ITEM_FLAG_UNPAID);
        }
    }
}
