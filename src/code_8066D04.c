#include "global.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "items.h"

extern u8 gFormatItems[];
extern u8 gUnknown_202DEA8[];
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];

extern u8 *gUnknown_80F8BE0[];
extern u8 *gItemStickyCannotMove1[];
extern u8 *gItemStickyCannotMove2[];
extern u8 *gItemStickyCannotEquip[];
extern u8 *gMonTookAndReturnedItem[];
extern u8 *gUnknown_80F8CE4[];
extern u8 *gUnknown_80F8CE8[];
extern u8 *gUnknown_80F8D04[];
extern u8 *gUnknown_80F8D20[];
extern u8 *gUnknown_80F8D44[];
extern u8 *gUnknown_80F8D60[];
extern u8 *gUnknown_80F8D7C[];
extern u8 *gUnknown_80F8DB4[];
extern u8 *gUnknown_80F8DE0[];
extern u8 *gUnknown_80F8E04[];
extern u8 *gUnknown_80F8E28[];

extern Item *sub_8044D90(Entity *, s32, u32);
void sub_8045BF8(u8 *, Item *);
u8 sub_80460F8(Position *, Item *, u32);
extern void sub_807AB38(Entity *, u32);
extern Entity * sub_8044DA4(Entity *param_1,int param_2);
extern void sub_807D148(Entity *pokemon, Entity *r1, u32 r2, Position *r3);
extern void sub_806A6E8(Entity *);
extern void sub_8044DF0(Entity *, u32, u32);
extern void sub_8045DB4(Position *, u32);

void HandlePickUpPlayerAction(Entity *entity)
{
  entity->axObj.info->action.unk4[0].actionUseIndex = 1;
  sub_8045DB4(&entity->pos,0);
}

void HandleSetItemAction(Entity *param_1, bool8 param_2)
{
  Item *item;
  Item *itemPtr;
  s32 index;

  item = sub_8044D90(param_1,0,0xfe);
  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    itemPtr = &gTeamInventoryRef->teamItems[index];
    if (((itemPtr->flags & ITEM_FLAG_EXISTS)) && ((itemPtr->flags & ITEM_FLAG_SET))) {
      if ((itemPtr->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatItems,itemPtr);
        SendMessage(param_1,*gItemStickyCannotEquip);
        return;
      }
      itemPtr->flags &= ~(ITEM_FLAG_SET);
    }
  }
  sub_8045BF8(gFormatItems,item);
  PlaySoundEffect(0x133);
  if (param_2 != 0) {
    if ((item->flags & ITEM_FLAG_STICKY)) {
        SendMessage(param_1,*gUnknown_80F8D04);
    }
    else {
      if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
        SendMessage(param_1,*gUnknown_80F8CE4);
      }
      else
      {
        SendMessage(param_1,*gUnknown_80F8CE8);
      }
    }
  }
  item->flags |= ITEM_FLAG_SET;
  if (((item->flags & ITEM_FLAG_STICKY)) && (param_2 != 0)) {
    sub_8045BF8(gFormatItems,item);
    SendMessage(param_1,*gUnknown_80F8BE0);
  }
}


void HandleUnsetItemAction(Entity *entity,bool8 enableMessage)
{
  Item *item;
  int index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if (((item->flags & ITEM_FLAG_EXISTS)) && ((item->flags & ITEM_FLAG_SET))) {
      if ((item->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatItems,item);
        SendMessage(entity,*gItemStickyCannotEquip);
        return;
      }
      item->flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatItems,item);
      PlaySoundEffect(0x133);
      if (enableMessage) {
        SendMessage(entity,*gUnknown_80F8D20);
      }
    }
  }
}


void HandleGiveItemAction(Entity *param_1)
{
  Entity *entity;
  Item *item;
  EntityInfo *info1;
  EntityInfo *info2;
  bool8 bVar3;
  Item item1;
  Item item2;
  Item item3;

  entity = sub_8044DA4(param_1,1);
  info1 = param_1->axObj.info;
  info2 = entity->axObj.info;
  item = sub_8044D90(param_1,0,2);

  if((info1->action).unk4[0].actionUseIndex == 0x80)
      bVar3 = TRUE;
  else
      bVar3 = FALSE;

  if ((!bVar3) && ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET))) {
    sub_8045BF8(gUnknown_202DEA8,item);
    SendMessage(param_1,*gItemStickyCannotMove2);
  }
  else
  {
    SetMessageArgument(gUnknown_202DFE8,entity,0);
    if (((info2->heldItem).flags & ITEM_FLAG_EXISTS)) {
     if (((info2->heldItem).flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gUnknown_202DEA8,&info2->heldItem);
        SendMessage(param_1,*gItemStickyCannotMove1);
        return;
      }
      item1 = (info2->heldItem);
      item2 = *item;
      item1.flags &= ~(ITEM_FLAG_SET);
      item2.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1,0,100);
      if (bVar3) {
        sub_80460F8(&param_1->pos,&item1,1);
      }
      else {
        AddItemToInventory(&item1);
      }
      info2->heldItem = item2;
      sub_8045BF8(gFormatItems,&item2);
      sub_8045BF8(gFormatItems + 0x50,&item1);
      PlaySoundEffect(0x14d);
      SendMessage(param_1,*gMonTookAndReturnedItem);
      if ((item2.flags & ITEM_FLAG_STICKY)) {
        SendMessage(param_1,*gUnknown_80F8BE0);
      }
    }
    else {
      item3 = *item;
      item3.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1, 0, 101);
      info2->heldItem = item3;
      sub_8045BF8(gFormatItems,&item3);
      PlaySoundEffect(0x14d);
      SendMessage(param_1,*gUnknown_80F8D44);
      if ((item3.flags & ITEM_FLAG_STICKY)) {
        SendMessage(param_1,*gUnknown_80F8BE0);
      }
    }
    sub_806A6E8(entity);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      sub_807D148(param_1,entity,0,0);
    }
    if (!info2->isTeamLeader) {
      info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->unk3A08);
  }
}


void HandleTakeItemAction(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  EntityInfo *info2;
  Item *heldItem;
  Item item;

  entity = sub_8044DA4(param_1,0);
  info = entity->axObj.info;
  info2 = entity->axObj.info;
  heldItem = &info->heldItem;
  if ((gTeamInventoryRef->teamItems[ITEM_POWER_BAND].flags & ITEM_FLAG_EXISTS)) {
    SendMessage(param_1,*gUnknown_80F8D60);
  }
  else
  {
    if ((heldItem->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatItems,heldItem);
        SendMessage(param_1,*gUnknown_80F8BE0);
    }
    else
    {
      item = *heldItem;
      item.flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatItems,&item);
      SetMessageArgument(gAvailablePokemonNames,entity,0);
      heldItem->id = ITEM_NOTHING;
      heldItem->quantity = 0;
      heldItem->flags = 0;
      AddItemToInventory(&item);
      PlaySoundEffect(0x14d);
      SendMessage(param_1,*gUnknown_80F8D7C);
      sub_806A6E8(entity);
      if (sub_80706A4(entity,&entity->pos) != 0) {
        sub_807D148(param_1,entity,0,0);
      }
      if (!info2->isTeamLeader) {
        info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
      }
      sub_807AB38(param_1,gDungeon->unk3A08);
    }
  }
}

void sub_8066BD4(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  EntityInfo *info2; // NOTE: needed two of these to match
  Item *item;
  Item *heldItem;
  Item temp;

  entity = sub_8044DA4(param_1,0);
  info = entity->axObj.info;
  info2 = entity->axObj.info;
  heldItem = &info->heldItem;
  item = sub_8044D90(param_1,1,0x1565);
  if (heldItem->flags & ITEM_FLAG_STICKY)
  {
    sub_8045BF8(gFormatItems,heldItem);
    SendMessage(param_1,*gUnknown_80F8BE0);
  }
  else if ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
    sub_8045BF8(gFormatItems,item);
    SendMessage(param_1,*gUnknown_80F8BE0);
  }
  else
  {
    heldItem->flags &= ~(ITEM_FLAG_SET);
    item->flags &= ~(ITEM_FLAG_SET);
    sub_8045BF8(gFormatItems,heldItem);
    sub_8045BF8(gFormatItems + 0x50,item);
    SetMessageArgument(gUnknown_202DFE8,entity,0);
    temp = info->heldItem;
    info->heldItem = *item;
    *item = temp;
    PlaySoundEffect(0x14d);
    SendMessage(param_1,*gUnknown_80F8DB4);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      sub_807D148(param_1,entity,0,0);
    }
    if (!info2->isTeamLeader) {
      info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->unk3A08);
  }
}

void HandleUseItemAction(Entity *param_1)
{
  Entity *entity;

  entity = sub_8044DA4(param_1,0);
  entity->axObj.info->useHeldItem = TRUE;
}

void HandlePlaceItemAction(Entity *param_1)
{
    Item *item;
    Tile *tile;
    EntityInfo *info;
#ifndef NONMATCHING
    register Entity *entity asm("r4");
#else
    Entity *entity;
#endif

    entity = param_1;

    info = entity->axObj.info;
    item = sub_8044D90(entity,0,4);
    sub_8045BF8(gFormatItems,item);
    if (info->action.unk4[0].actionUseIndex == 0x80) {
        SendMessage(entity,*gUnknown_80F8DE0);
    }
    else if ((info->action.unk4[0].actionUseIndex < 0x15) && ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET))) {
        SendMessage(entity,*gUnknown_80F8BE0);
    }
    else if ((info->action.unk4[0].actionUseIndex == 0x81) && ((item->flags & ITEM_FLAG_STICKY))) {
        SendMessage(entity,*gUnknown_80F8BE0);
    }
    else {
        tile = GetTile(entity->pos.x, entity->pos.y);
        if (!(tile->terrainType & TERRAIN_TYPE_STAIRS))
        {
            if(((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL) &&
                (tile->object == NULL)) {
                item->flags &= ~(ITEM_FLAG_SET);
                sub_8045BF8(gFormatItems,item);
                if (sub_80460F8(&entity->pos,item,1) == 0) {
                _message:
                    SendMessage(entity,*gUnknown_80F8E04);
                }
                else
                {
                    item->id = ITEM_NOTHING;
                    item->quantity = 0;
                    item->flags = 0;
                    FillInventoryGaps();
                    PlaySoundEffect(0x14d);
                    SetMessageArgument(gAvailablePokemonNames,entity,0);
                    SendMessage(entity,*gUnknown_80F8E28);
                    sub_807AB38(entity,gDungeon->unk3A08);
                }
            }
            else
            {
                goto _message;
            }
        }
        else
        {
            goto _message;
        }
    }
}
