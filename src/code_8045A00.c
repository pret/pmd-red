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
#include "dungeon_ai_targeting.h"
#include "string_format.h"
#include "items.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "trap.h"
#include "code_80450F8.h"

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

extern bool8 sub_80461C8(DungeonPos *, u32);
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
