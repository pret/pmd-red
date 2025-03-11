#include "global.h"
#include "code_8045A00.h"
#include "constants/item.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_map.h"
#include "dungeon_ai_targeting.h"
#include "string_format.h"
#include "items.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "trap.h"
#include "code_80450F8.h"
#include "structs/str_item_text.h"

extern u8 *gUnknown_80FE6F4[];
extern u8 *gPickedUpItemToolbox[];
extern u8 *gMonTerrifiedCouldntPickUpItem[];
extern u8 *gPickedUpItem2[];
extern u8 *gMonCouldntPickUpItem[];
extern u8 *gPickedUpItem[];
extern u8 *gMonSteppedOnItem[];
extern struct unkStruct_8090F58 gUnknown_80F699C;
extern struct unkStruct_8090F58 gUnknown_80F69A8;
extern struct unkStruct_8090F58 gUnknown_80F6990;

bool8 sub_80461C8(DungeonPos *, bool8);
void sub_8045BF8(u8 *, Item *);
extern u32 sub_803D73C(u32);
bool8 sub_80460F8(DungeonPos *, Item *, bool8);

void sub_8045ACC(void)
{
  Entity *entity;
  s32 index;
  s32 pokeCount;

  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    entity = gDungeon->wildPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeon->activePokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(Entity *pokemon)
{
  Entity *entity;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (pokemon == entity)
      return index;
  }
  return -1;
}

void SubstitutePlaceholderStringTags(u8 *buffer, Entity *entity, u32 param_3)
{
  switch(GetEntityType(entity))
  {
    case ENTITY_MONSTER:
        SetMessageArgument_2(buffer, GetEntInfo(entity), param_3);
        break;
    case ENTITY_ITEM:
        sub_8045BF8(buffer, GetItemData_1(entity));
        break;
    case ENTITY_TRAP:
        GetTrapName(buffer, GetTrapData_1(entity)->id);
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}

// FILE SPLIT HERE

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

void sub_8045C28(Item *item, u8 itemID, u32 param_3)
{
    bool8 stickyFlag;

    xxx_init_itemslot_8090A8C(item,itemID,0);
    stickyFlag = FALSE;
    if (IsNotSpecialItem(itemID)) {
        if (param_3 == 0) {
            if (DungeonRandInt(100) < gDungeon->unk1C574.unkA)
                stickyFlag = TRUE;
            else
                stickyFlag = FALSE;
        }
        else if (param_3 == 1) {
            stickyFlag = TRUE;
        }
    }
    if (stickyFlag) {
        item->flags |= ITEM_FLAG_STICKY;
    }

    if (GetItemCategory(itemID) == CATEGORY_POKE) {
        sub_8046CE4(item, gDungeon->unk1C574.unk17 * 40);
    }
}

void sub_8045CB0(void)
{
    u8 itemID;
    s32 yCounter, xCounter;
    const Tile *tile;
    u32 uVar5;
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

            if (!(tile->terrainType & TERRAIN_TYPE_STAIRS) && (tile->spawnOrVisibilityFlags & 2)) {
                DungeonPos pos;
                bool8 shopFlag = FALSE;
                pos.x = x;
                pos.y = y;

                if (tile->terrainType & TERRAIN_TYPE_SHOP) {
                    shopFlag = TRUE;
                    uVar5 = 1;
                }
                else
                {
                    if (GetTerrainType(tile) == TERRAIN_TYPE_WALL) {
                        uVar5 = 3;
                    }
                    else {
                        uVar5 = (tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE) ? 2 : 0;
                    }
                }
                itemID = sub_803D73C(uVar5);
                if (!CanSellItem(itemID)) {
                    shopFlag = 0;
                }
                sub_8045C28(&item,itemID,0);
                if (shopFlag) {
                    item.flags |= flag;
                }
                sub_80460F8(&pos,&item,TRUE);
            }
        }
    }
}

void sub_8045DB4(struct DungeonPos *pos, bool8 printMsg)
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
    tileItem = GetItemData(tileObject);
    if (leaderInfo->action.actionParameters[0].actionUseIndex == 0) {
        if (!printMsg) {
            return;
        }
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        LogMessageByIdWithPopupCheckUser(leader,*gMonSteppedOnItem);
    }
    else if (ShouldMonsterRunAwayAndShowEffect(leader,1)) {
        if (!printMsg) {
            return;
        }
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        LogMessageByIdWithPopupCheckUser(leader,*gMonTerrifiedCouldntPickUpItem);
    }
    else if (GetItemCategory(tileItem->id) == CATEGORY_POKE) {
        PlaySoundEffect(0x14c);
        AddToTeamMoney(GetMoneyValue(tileItem));
        sub_8045BF8(gFormatBuffer_Items[0],tileItem);
        sub_80461C8(pos,1);
        LogMessageByIdWithPopupCheckUser(leader,*gPickedUpItem);
        TryDisplayItemPickupTutorialMessage(tileItem->id);
    }
    else {
        s32 i, maxItems;
        if (gDungeon->unk644.unk17 != 0) {
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
                sub_80461C8(pos,1);
                PlaySoundEffect(0x14a);
                if (inventoryIds[index] < 0) {
                    LogMessageByIdWithPopupCheckUser(leader,*gPickedUpItem2);
                }
                else {
                    LogMessageByIdWithPopupCheckUser(leader,*gPickedUpItemToolbox);
                }
                TryDisplayItemPickupTutorialMessage(tileItem->id);
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
            LogMessageByIdWithPopupCheckUser(leader,*gMonSteppedOnItem);
        }
        else {
            PlaySoundEffect(0x14a);
            if (inventoryIds[i] < 0) {
                leaderInfo->heldItem = *tileItem;
                sub_8045BF8(gFormatBuffer_Items[0],tileItem);
                sub_80461C8(pos,1);
                LogMessageByIdWithPopupCheckUser(leader,*gPickedUpItem2);
            }
            else if (AddItemToInventory(tileItem) != 0) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
                LogMessageByIdWithPopupCheckUser(leader,*gMonCouldntPickUpItem);
            }
            else {
                sub_8045BF8(gFormatBuffer_Items[0],tileItem);
                sub_80461C8(pos,1);
                LogMessageByIdWithPopupCheckUser(leader,*gPickedUpItemToolbox);
            }
            TryDisplayItemPickupTutorialMessage(tileItem->id);
         }
    }
}

bool8 sub_80460F8(DungeonPos *pos, Item *item, bool8 a2)
{
    s32 i, count;
    Tile *tile;
    Entity *entity = sub_8045708(pos);

    if (entity == NULL)
        return FALSE;
    *entity->axObj.info.item = *item;
    entity->axObj.info.item->flags &= ~(ITEM_FLAG_SET);
    entity->isVisible = TRUE;
    tile = GetTileMut(pos->x, pos->y);
    tile->object = entity;
    if ((tile->terrainType & TERRAIN_TYPE_SHOP) && CanSellItem(item->id)) {
        if (item->flags & ITEM_FLAG_IN_SHOP) {
            if (a2) {
                gDungeon->unk644.unk48 += GetStackBuyPrice(item);
            }
        }
        else {
            gDungeon->unk644.unk4C += GetStackSellPrice(item);
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

bool8 sub_80461C8(DungeonPos *pos, bool8 a2)
{
    s32 i, count;
    Item *item;
    Tile *tile = GetTileMut(pos->x, pos->y);
    Entity *tileObject = tile->object;
    if (tileObject == NULL || GetEntityType(tileObject) != ENTITY_ITEM)
        return FALSE;

    item = GetItemData(tileObject);
    if ((tile->terrainType & TERRAIN_TYPE_SHOP) && CanSellItem(item->id)) {
        if (item->flags & ITEM_FLAG_IN_SHOP) {
            if (a2) {
                gDungeon->unk644.unk48 -= GetStackBuyPrice(item);
            }
        }
        else {
            gDungeon->unk644.unk4C -= GetStackSellPrice(item);
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

s32 sub_8046298(Item *item)
{
    return gItemParametersData[item->id].icon;
}

extern bool8 sub_8045888(Entity *);

extern SpriteOAM gUnknown_202EDC0;
extern u8 gUnknown_203B420[];
extern u8 gUnknown_203B428[];

bool8 sub_80462AC(Entity * entity, u8 a1, u8 a2, u8 a3, u8 a4)
{
    s32 x, y, y2;
    s32 objMode = 0;

    if (!EntityIsValid(entity))
        return FALSE;

    if (a2) {
        s32 terrainType = GetTerrainType(GetTile(entity->pos.x, entity->pos.y));

        if (terrainType == TERRAIN_TYPE_WALL)
            return FALSE;
        if (terrainType == TERRAIN_TYPE_SECONDARY) {
            objMode = 1;
        }

        if (!sub_8045888(entity))
            return FALSE;
    }

    x = (entity->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
    y = ((entity->pixelPos.y - entity->unk1C.raw) / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 = ((entity->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y) + 8;
    y2 /= 2;

    if (x >= -32 && y >= -32 && x <= 272 && y <= 192) {
        s32 tileNum;

        SpriteSetMatrixNum(&gUnknown_202EDC0, 0);
        if (a1) {
            tileNum = 0x17;
            SpriteSetPalNum(&gUnknown_202EDC0, 10);
        }
        else {
            tileNum = sub_8046298(entity->axObj.info.item);
            if (a3 != 0xFF && tileNum == 0) {
                tileNum = gUnknown_203B420[a3];
                SpriteSetMatrixNum(&gUnknown_202EDC0, gUnknown_203B428[a3] * 8);
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

void sub_804652C(Entity *entity1, Entity *entity2, Item *item, bool8 a3, DungeonPos *pos);

void sub_80464C8(Entity *entity, DungeonPos *pos, Item *item)
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
    sub_804652C(entity, &itemEntity, item, TRUE, NULL);
}

void sub_8046734(Entity *entity, DungeonPos *pos);

extern void sub_804219C(PixelPos *pos);

extern const u8 *const gUnknown_80FED30;
extern const DungeonPos gUnknown_80F4468[];
extern const u8 *const gItemFellOnGround;
extern const u8 *const gItemLost;
extern const u8 *const gItemFellOutOfSight;
extern const u8 *const gItemFellInWater;
extern const u8 *const gItemBuried;

void sub_804652C(Entity *entity1, Entity *entity2, Item *item, bool8 a3, DungeonPos *pos)
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
        if (GetTerrainType(tile) != TERRAIN_TYPE_WALL && !(tile->terrainType & TERRAIN_TYPE_STAIRS) && tile->object == NULL) {
            sub_8046734(entity2, &localPos);
            localPos2 = localPos;
            if (GetTerrainType(tile) == (TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL) || (sub_80460F8(&localPos, item, TRUE))) {
                var_24 = TRUE;
            }
            break;
        }
        i++;
    }

    sub_8045BF8(gFormatBuffer_Items[0], item);
    if (var_24) {
        ShowDungeonMapAtPos(localPos.x, localPos.y);
        switch (GetTerrainType(GetTile(localPos.x, localPos.y))) {
            case TERRAIN_TYPE_NORMAL:
                TryDisplayDungeonLoggableMessage5(entity1, &localPos, gItemFellOnGround);
                break;
            case TERRAIN_TYPE_SECONDARY:
                TryDisplayDungeonLoggableMessage5(entity1, &localPos, gItemFellInWater);
                break;
            case TERRAIN_TYPE_WALL:
                TryDisplayDungeonLoggableMessage5(entity1, &localPos, gItemBuried);
                break;
            case TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL:
                TryDisplayDungeonLoggableMessage5(entity1, &localPos, gItemFellOutOfSight);
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
        TryDisplayDungeonLoggableMessage5(entity1, &localPos, gItemLost);
    }
}

//
