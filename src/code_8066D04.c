#include "global.h"
#include "globaldata.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_807CD9C.h"
#include "code_8041AD0.h"
#include "code_806CD90.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_music.h"
#include "position_util.h"
#include "dungeon_util.h"
#include "items.h"
#include "input.h"
#include "text.h"
#include "code_803E46C.h"
#include "string_format.h"
#include "friend_area.h"
#include "dungeon_leader.h"
#include "status_checks_1.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_engine.h"
#include "dungeon_move.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "code_8077274_1.h"
#include "code_8084778.h"
#include "pokemon.h"
#include "trap.h"
#include "moves.h"
#include "pokemon_3.h"
#include "menu_input.h"
#include "dungeon_capabilities.h"
#include "constants/item.h"
#include "constants/dungeon.h"
#include "constants/move_id.h"
#include "move_actions.h"

extern u8 *gUnknown_80F8BE0[];
extern u8 *gUnknown_80FF76C[];
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
extern u8 *gItemStickyCannotMove3[];
extern u8 *gNothingCanBePutDownHere[];
extern u8 *gUnknown_80F8E2C[];
extern u8 *gNoExchangesHere[];
extern u8 *gSwappedGroundItem[];
extern const u8 *const gMonThrewItem2;
extern const u8 *const gMonThrewItem1;
extern const u8 *const gCannotFarewell;
extern const u8 *const gSayFarewellQ;
extern const u8 *const gUnknown_80FDFB8;
extern const u8 *const gUnknown_80F913C;
extern const u8 *const gCannotTalk;
extern const u8 *const gUnknown_80FE008;
extern const u8 *const gUnknown_80FDF74;
extern const u8 *const gUnknown_80FF674;
extern const u8 *const gUnknown_80F9114;
extern const u8 *const gMonDisappointedAndLeft;
extern const u8 *const gSendMonBackQ;
extern const u8 *const gSendMonBackWithItemQ;
extern const u8 *const gMonWentBack;
extern const u8 *const gMonCringing;
extern const u8 *const gMonParalyzed;
extern const u8 *const gUnknown_80FC690;

extern s32 gDungeonSubMenuItemsCount;
extern u32 gUnknown_202F208;

extern void sub_8071DA4(Entity *);
extern void sub_806A1B0(Entity *);
extern void sub_806A9B4(Entity *, u32);
extern void sub_8068FE0(Entity *, u32, Entity *r2);
extern bool8 sub_806A58C(s16 a0);
extern bool8 sub_806A564(s16 r0);
extern void sub_8045C08(u8 *buffer, Item *item);
extern bool8 sub_8045888(Entity *);
extern Item *sub_8044D90(Entity *, s32, u32);
void sub_8045BF8(u8 *, Item *);
u8 sub_8048D50();
void SetActionUnusableInDungeonSubMenu(u16 param_1);
void AddActionToDungeonSubMenu(u16 param_1, u8 param_2);
void sub_8044DF0();
void sub_8042208(Entity *pokemon, u8 r1);
void sub_803E708();
void sub_80479B8();
extern void sub_807AB38(Entity *, u32);
extern Entity * sub_8044DA4(Entity *param_1,int param_2);
extern void sub_806A6E8(Entity *);
extern void sub_8044DF0(Entity *, u32, u32);
extern bool32 sub_8055A00(Entity *attacker, s32 firstMoveId, s32 var_34, s32 itemId, s32 arg_0);
extern bool8 sub_8044B28(void);
Entity *sub_806773C(Entity *entity);
void sub_8067558(Entity *entity, Entity *targetEntity, s32 a2);
void sub_8067794(Entity *entity, Entity *targetEntity, s32 a2);
extern void sub_807EF84(void);
extern void sub_80845E0(Entity *entity);
extern void sub_8084448(Entity *entity);
extern void sub_806A3D4(u8 *dst, s32 _a1, s32 id, bool32 _a3);
extern Entity * sub_80696A8(Entity *target);

void HandlePickUpPlayerAction(Entity *entity)
{
  GetEntInfo(entity)->action.actionParameters[0].actionUseIndex = 1;
  PickUpItemFromPos(&entity->pos,0);
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
        sub_8045BF8(gFormatBuffer_Items[0],itemPtr);
        LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotEquip);
        return;
      }
      itemPtr->flags &= ~(ITEM_FLAG_SET);
    }
  }
  sub_8045BF8(gFormatBuffer_Items[0],item);
  PlaySoundEffect(0x133);
  if (param_2 != 0) {
    if ((item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D04);
    }
    else {
      if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8CE4);
      }
      else
      {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8CE8);
      }
    }
  }
  item->flags |= ITEM_FLAG_SET;
  if (((item->flags & ITEM_FLAG_STICKY)) && (param_2 != 0)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
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
        sub_8045BF8(gFormatBuffer_Items[0],item);
        LogMessageByIdWithPopupCheckUser(entity,*gItemStickyCannotEquip);
        return;
      }
      item->flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],item);
      PlaySoundEffect(0x133);
      if (enableMessage) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8D20);
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
  info1 = GetEntInfo(param_1);
  info2 = GetEntInfo(entity);
  item = sub_8044D90(param_1,0,2);

  if((info1->action).actionParameters[0].actionUseIndex == 0x80)
      bVar3 = TRUE;
  else
      bVar3 = FALSE;

  if ((!bVar3) && ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET))) {
    sub_8045BF8(gFormatBuffer_Items[1],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotMove2);
  }
  else
  {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    if (((info2->heldItem).flags & ITEM_FLAG_EXISTS)) {
     if (((info2->heldItem).flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[1],&info2->heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotMove1);
        return;
      }
      item1 = (info2->heldItem);
      item2 = *item;
      item1.flags &= ~(ITEM_FLAG_SET);
      item2.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1,0,100);
      if (bVar3) {
        AddItemToDungeonAt(&param_1->pos,&item1,1);
      }
      else {
        AddItemToInventory(&item1);
      }
      info2->heldItem = item2;
      sub_8045BF8(gFormatBuffer_Items[0],&item2);
      sub_8045BF8(gFormatBuffer_Items[1],&item1);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gMonTookAndReturnedItem);
      if ((item2.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
      }
    }
    else {
      item3 = *item;
      item3.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1, 0, 101);
      info2->heldItem = item3;
      sub_8045BF8(gFormatBuffer_Items[0],&item3);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D44);
      if ((item3.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
      }
    }
    sub_806A6E8(entity);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info2->isTeamLeader) {
      info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}

void HandleTakeItemAction(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *heldItem;
  Item item;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  if (ItemExists(&gTeamInventoryRef->teamItems[ITEM_POWER_BAND])) {
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D60);
  }
  else
  {
    if (ItemSticky(heldItem)) {
        sub_8045BF8(gFormatBuffer_Items[0],heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
    }
    else
    {
      item = *heldItem;
      item.flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],&item);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
      ZeroOutItem(heldItem);
      AddItemToInventory(&item);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D7C);
      sub_806A6E8(entity);
      if (sub_80706A4(entity,&entity->pos) != 0) {
        WarpTarget(param_1,entity,0,0);
      }
      if (!info->isTeamLeader) {
        info->flags |= MOVEMENT_FLAG_UNK_14;
      }
      sub_807AB38(param_1,gDungeon->forceMonsterHouse);
    }
  }
}

void sub_8066BD4(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *item;
  Item *heldItem;
  Item temp;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  item = sub_8044D90(param_1,1,0x1565);
  if (heldItem->flags & ITEM_FLAG_STICKY)
  {
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
  }
  else if ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
  }
  else
  {
    heldItem->flags &= ~(ITEM_FLAG_SET);
    item->flags &= ~(ITEM_FLAG_SET);
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    sub_8045BF8(gFormatBuffer_Items[1],item);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    temp = info->heldItem;
    info->heldItem = *item;
    *item = temp;
    PlaySoundEffect(0x14d);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8DB4);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info->isTeamLeader) {
      info->flags = info->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}

void HandleUseItemAction(Entity *param_1)
{
  Entity *entity;

  entity = sub_8044DA4(param_1,0);
  GetEntInfo(entity)->useHeldItem = TRUE;
}

void HandlePlaceItemAction(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity,0,4);

    sub_8045BF8(gFormatBuffer_Items[0],item);
    if (info->action.actionParameters[0].actionUseIndex == 0x80) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8DE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex < 0x15 && (item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8BE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex == 0x81 && (item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8BE0);
    }
    else {
        const Tile *tile = GetTile(entity->pos.x, entity->pos.y);
        if ((tile->terrainType & TERRAIN_TYPE_STAIRS)) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else if (tile->object != NULL) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else {
            item->flags &= ~(ITEM_FLAG_SET);
            sub_8045BF8(gFormatBuffer_Items[0],item);
            if (AddItemToDungeonAt(&entity->pos,item,1) == 0) {
                LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
            }
            else {
                ZeroOutItem(item);
                FillInventoryGaps();
                PlaySoundEffect(0x14d);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
                LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E28);
                sub_807AB38(entity,gDungeon->forceMonsterHouse);
            }
        }
    }
}

void sub_8066E14(Entity *entity)
{
    Item *item[2];
    EntityInfo *info = GetEntInfo(entity);
    item[0] = sub_8044D90(entity,0,5);
    item[1] = sub_8044D90(entity,1,6);

    if (info->action.actionParameters[0].actionUseIndex != 0x80) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E2C);
    }
    else if (info->action.actionParameters[1].actionUseIndex < 0x15 && (item[1]->flags & ITEM_FLAG_SET) && (item[1]->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],item[1]);
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8BE0);
    }
    else if (info->action.actionParameters[1].actionUseIndex == 0x81 && ItemSticky(item[1])) {
        sub_8045BF8(gFormatBuffer_Items[1],item[1]);
        LogMessageByIdWithPopupCheckUser(entity,*gItemStickyCannotMove3);
    }
    else {
        const Tile *tile = GetTile((entity->pos).x,(entity->pos).y);
        if (tile->object != NULL && GetEntityType(tile->object) != ENTITY_ITEM) {
            LogMessageByIdWithPopupCheckUser(entity,*gNoExchangesHere);
        }
        else {
            Item newItems[2];

            newItems[0] = *item[0];
            newItems[1] = *item[1];
            newItems[0].flags &= ~(ITEM_FLAG_SET);
            newItems[1].flags &= ~(ITEM_FLAG_SET);

            RemoveItemFromDungeonAt(&info->action.actionParameters[0].itemPos,1);
            ZeroOutItem(item[1]);
            if (!AddItemToDungeonAt(&info->action.actionParameters[0].itemPos,&newItems[1],1)) {
                LogMessageByIdWithPopupCheckUser(entity,*gNothingCanBePutDownHere);
            }
            else {
                if (info->action.actionParameters[1].actionUseIndex == 0x81) {
                    info->heldItem = newItems[0];
                }
                else {
                    AddItemToInventory(&newItems[0]);
                }

                FillInventoryGaps();
                sub_8045BF8(gFormatBuffer_Items[0],&newItems[1]);
                sub_8045BF8(gFormatBuffer_Items[1],&newItems[0]);
                PlaySoundEffect(0x14d);
                LogMessageByIdWithPopupCheckUser(entity,*gSwappedGroundItem);
                sub_807AB38(entity,gDungeon->forceMonsterHouse);
            }
        }
    }
}

void sub_8066FA4(Entity *entity)
{
    Item *item[2];
    EntityInfo *info = GetEntInfo(entity);
    const Tile *tile = GetTile((entity->pos).x,(entity->pos).y);

    item[0] = sub_8044D90(entity,0,7);
    sub_8045BF8(gFormatBuffer_Items[0],item[0]);
    if (info->action.actionParameters[0].actionUseIndex < 0x15 && (item[0]->flags & ITEM_FLAG_SET) && (item[0]->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[1],item[0]);
        LogMessageByIdWithPopupCheckUser(entity,*gItemStickyCannotMove3);
    }
    else if (info->action.actionParameters[0].actionUseIndex == 0x81 && ItemSticky(item[0])) {
        LogMessageByIdWithPopupCheckUser(entity,*gItemStickyCannotMove2);
    }
    else if (tile->object != NULL && GetEntityType(tile->object) != ENTITY_ITEM) {
        LogMessageByIdWithPopupCheckUser(entity,*gNoExchangesHere);
    }
    else {
        Item newItems[2];

        item[1] = GetItemData(tile->object);
        sub_8045BF8(gFormatBuffer_Items[1],item[1]);
        newItems[0] = *item[0];
        newItems[1] = *item[1];
        newItems[0].flags &= ~(ITEM_FLAG_SET);
        newItems[1].flags &= ~(ITEM_FLAG_SET);

        RemoveItemFromDungeonAt(&entity->pos,1);
        ZeroOutItem(item[0]);
        if (!AddItemToDungeonAt(&entity->pos, &newItems[0],1)) {
            LogMessageByIdWithPopupCheckUser(entity,*gNothingCanBePutDownHere);
        }
        else {
            if (info->action.actionParameters[0].actionUseIndex  == 0x81) {
                info->heldItem = newItems[1];
            }
            else {
                AddItemToInventory(&newItems[1]);
            }
            FillInventoryGaps();
            PlaySoundEffect(0x14d);
            LogMessageByIdWithPopupCheckUser(entity,*gSwappedGroundItem);
            sub_807AB38(entity,gDungeon->forceMonsterHouse);
        }
    }
}

void sub_8067110(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity,0,8);

    sub_8045BF8(gFormatBuffer_Items[0],item);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],info,0);
    if (sub_8048D50(entity,item)) {
        Item item2;

        LogMessageByIdWithPopupCheckUser(entity,sub_80464AC(item));
        item2 = *item;
        sub_8044DF0(entity,0,0x66);
        sub_803E708(0x1e,0x11);
        sub_80479B8(0,0,0,entity,entity,&item2);
        sub_807AB38(entity,gDungeon->forceMonsterHouse);
    }
}

struct UnkStruct_8067110
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
};

extern void sub_8083904(DungeonPos *pos, Entity *entity);
extern void sub_80475C4(Entity *entity, Item *item, DungeonPos *pos1, DungeonPos *pos2, struct UnkStruct_8067110 *);
extern void sub_8047190(Entity *entity, Item *item, DungeonPos *pos1, s32 dir, struct UnkStruct_8067110 *);

void sub_80671A0(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity, 0, 9);

    if (info->action.actionParameters[0].actionUseIndex == 0x81 && ItemSticky(item)) {
        sub_8045BF8(gFormatBuffer_Items[0], item);
        LogMessageByIdWithPopupCheckUser(entity, *gUnknown_80F8BE0);
        sub_803E708(0x14, 0x4C);
    }
    else if ((GetItemCategory(item->id) == CATEGORY_THROWN_LINE || GetItemCategory(item->id) == CATEGORY_THROWN_ARC) && ItemSticky(item)) {
        sub_8045BF8(gFormatBuffer_Items[0], item);
        LogMessageByIdWithPopupCheckUser(entity, *gUnknown_80F8BE0);
        sub_803E708(0x14, 0x4C);
    }
    else if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        LogMessageByIdWithPopupCheckUser(entity, *gUnknown_80FF76C);
        sub_803E708(0x14, 0x4C);
    }
    else {
        bool8 r7;
        Item newItem;
        DungeonPos pos;
        struct UnkStruct_8067110 unkStruct;

        newItem = *item;
        newItem.flags &= ~(ITEM_FLAG_SET);

        if (info->action.actionParameters[0].actionUseIndex == 0x80) {
            item = NULL;
            RemoveItemFromDungeonAt(&info->action.actionParameters[0].itemPos, 1);
        }

        r7 = TRUE;
        if ((GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE || GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC) && (newItem.quantity > 1)) {
            r7 = FALSE;
        }

        if (r7) {
            if (info->action.actionParameters[0].actionUseIndex != 0x80) {
                ZeroOutItem(item);
                FillInventoryGaps();
            }
        }
        else {
            if (info->action.actionParameters[0].actionUseIndex == 0x80) {
                newItem.quantity--;
                AddItemToDungeonAt(&info->action.actionParameters[0].itemPos, &newItem, 1);
            }
            else {
                item->quantity--;
            }
        }

        if (HasHeldItem(entity, ITEM_NO_AIM_SCOPE)) {
            info->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        }

        if (sub_8045888(entity)) {
            s32 i;
            s32 dir = info->action.direction;
            sub_80421C0(entity, 0x164);

            for (i = 0; i < NUM_DIRECTIONS; i++) {
                dir--;
                dir &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, dir);
                sub_803E708(2, 21);
            }
            info->unk166 = 4;
        }

        if ((GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE || GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC)) {
            newItem.quantity = 1;
        }

        sub_8045C08(gFormatBuffer_Items[0], &newItem);
        SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
        if (GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE) {
            LogMessageByIdWithPopupCheckUser(entity, gMonThrewItem2);
        }
        else {
            LogMessageByIdWithPopupCheckUser(entity, gMonThrewItem1);
        }

        sub_8042208(entity, GetItemCategory(newItem.id));
        if (HasHeldItem(entity, ITEM_CURVE_BAND)) {
            unkStruct.unk1 = 1;
        }
        else {
            unkStruct.unk1 = 0;
        }

        switch (info->longTossClassStatus.status) {
            case 0:
                unkStruct.unk0 = 0;
                unkStruct.unk2 = 10;
                break;
            case STATUS_LONG_TOSS:
                unkStruct.unk0 = 0;
                unkStruct.unk2 = 99;
                break;
            case STATUS_PIERCE:
                unkStruct.unk0 = 1;
                unkStruct.unk2 = 99;
                break;
        }

        if (HasHeldItem(entity, ITEM_PIERCE_BAND)) {
            unkStruct.unk0 = 1;
            unkStruct.unk2 = 99;
        }

        if (GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC) {
            sub_8083904(&pos, entity);
            sub_80475C4(entity, &newItem, &entity->pos, &pos, &unkStruct);
        }
        else {
            sub_8047190(entity, &newItem, &entity->pos, info->action.direction, &unkStruct);
        }

        if (EntityIsValid(entity)) {
            sub_806CE68(entity, info->action.direction);
            sub_807AB38(entity,gDungeon->forceMonsterHouse);
        }
    }
}

void HandleTalkFieldAction(Entity *entity)
{
    sub_8067558(entity, sub_806773C(entity), -1);
}

void sub_806752C(ActionContainer *a0)
{
    Entity *targetEntity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    sub_8067558(GetLeader(), targetEntity, 0);
}

void sub_8067558(Entity *entity, Entity *targetEntity, s32 a2)
{
    EntityInfo *info1 = GetEntInfo(entity);

    if (targetEntity == NULL) {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
    else if (!sub_8070BC0(entity)) {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
    else if (GetTreatmentBetweenMonsters(entity, targetEntity, TRUE, FALSE) != 1
             && GetTreatmentBetweenMonsters(targetEntity, entity, TRUE, FALSE) != 1)
    {
        EntityInfo *info2 = GetEntInfo(targetEntity);

        SetMessageArgument_2(gFormatBuffer_Monsters[0], info2, 0);
        SetMessageArgument_2(gFormatBuffer_Monsters[1], info1, 7);
        sub_8084778();
        TrySendImmobilizeSleepEndMsg(entity, targetEntity);
        if (!sub_8070BC0(targetEntity) || CheckVariousStatuses2(targetEntity, TRUE)) {
            DisplayDungeonMessage(NULL, gUnknown_80FE008, TRUE);
            return;
        }

        sub_806CEFC(entity, GetDirectionTowardsPosition(&entity->pos, &targetEntity->pos));
        if (a2 >= 0) {
            sub_806CEFC(targetEntity, a2);
        }
        else {
            sub_806CEFC(targetEntity, info1->action.direction + 4);
        }

        if (info2->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER) {
            sub_807EF84();
            return;
        }

        if (info2->monsterBehavior == 1) {
            if (gDungeon->unk644.unk2A != 0) {
                DisplayDungeonMessage(NULL, gUnknown_80FF674, TRUE);
            }
            else if (gDungeon->unk644.unk33) {
                sub_80845E0(targetEntity);
            }
            else {
                sub_8084448(targetEntity);
            }
        }
        else {
            u8 txt[300];
            s32 r2;
            s32 speciesId = info2->apparentID;
            bool8 r6 = FALSE;

            if (info2->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
                speciesId = MONSTER_MUNCHLAX;
            }
            else if (info2->joinedAt.id == DUNGEON_RESCUE_TEAM_BASE) {
                speciesId = MONSTER_DECOY;
            }
            else if (info2->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER && !gDungeon->unk644.unk18) {
                r6 = TRUE;
            }

            if (info2->HP <= info2->maxHPStat / 4) {
                r2 = 2;
            }
            else if (info2->HP <= (info2->maxHPStat * 6) / 10) {
                r2 = 1;
            }
            else {
                r2 = 0;
            }

            sub_806A3D4(txt, speciesId,  r2, r6);
            DisplayDungeonMessage(NULL, txt, TRUE);
        }
    }
    else {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
}

Entity *sub_806773C(Entity *entity)
{
    Entity *ret = sub_80696A8(entity);
    if (ret == NULL) return NULL;
    if (GetEntityType(ret) != ENTITY_MONSTER) return NULL;
    if (GetEntInfo(entity)->isNotTeamMember) return NULL;

    return ret;
}

void sub_8067768(ActionContainer *a0)
{
    Entity *targetEntity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    sub_8067794(GetLeader(), targetEntity, 0);
}

void sub_8067794(Entity *entity, Entity *targetEntity, s32 a2)
{
    const u8 *stringPtr1;
    const u8 *stringPtr2;
    s32 teamIndex;
    EntityInfo *info2 = GetEntInfo(targetEntity);

    if (targetEntity == NULL) {
        DisplayDungeonMessage(NULL, gCannotFarewell, TRUE);
        return;
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], targetEntity, 0);
    stringPtr1 = gSayFarewellQ;
    stringPtr2 = gUnknown_80F913C;
    teamIndex = info2->teamIndex;
    if (teamIndex >= 0) {
        PokemonStruct2 *pokeStruct = &gRecruitedPokemonRef->pokemon2[teamIndex];
        if (sub_806A564(pokeStruct->unkA)) {
            stringPtr1 = gUnknown_80F9114;
            stringPtr2 = gMonDisappointedAndLeft;
        }
        else if (sub_806A58C(pokeStruct->unkA)) {
            if (IsMakuhitaTrainingMaze()) {
                stringPtr1 = gSendMonBackQ;
            }
            else {
                stringPtr1 = gSendMonBackWithItemQ;
            }
            stringPtr2 = gMonWentBack;
        }
    }

    if (DisplayDungeonYesNoMessage(NULL, stringPtr1, FALSE) == 1) {
        u8 tempText[64];

        strncpy(tempText, gFormatBuffer_Monsters[0], sizeof(tempText));
        sub_8068FE0(targetEntity, 0x21D, 0);
        strncpy(gFormatBuffer_Monsters[0], tempText, sizeof(tempText));
        DisplayDungeonMessage(NULL, stringPtr2, TRUE);
    }
}

void HandleUseMovePlayerAction(Entity *entity)
{
    s32 i = 0;

    while (i < sub_8070828(entity, TRUE)) {
        EntityInfo *info = GetEntInfo(entity);

        sub_8055A00(entity, info->action.actionParameters[1].actionUseIndex, 1, 0, 0);
        if (sub_8044B28()) {
            break;
        }
        if (info->unk159 != 0) {
            break;
        }
        i++;
    }

    sub_8057588(entity, 1);
    if (!sub_8044B28()) {
        if (EntityIsValid(entity)) {
            sub_806A9B4(entity, GetEntInfo(entity)->action.actionParameters[1].actionUseIndex);
        }
        sub_806A1B0(entity);
    }
}

void sub_8067904(Entity *entity, u16 moveId)
{
    Move move;
    EntityInfo *info = GetEntInfo(entity);

    gUnknown_202F208 = 0;
    InitPokemonMove(&move, moveId);
    if (info->cringeClassStatus.status == STATUS_CRINGE) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        LogMessageByIdWithPopupCheckUser(entity, gMonCringing);
    }
    else if (info->burnClassStatus.status == STATUS_PARALYSIS) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        LogMessageByIdWithPopupCheckUser(entity, gMonParalyzed);
    }
    else {
        s32 i;
        bool32 isStruggle;

        if (moveId == MOVE_STRUGGLE) {
            isStruggle = TRUE;
        }
        else {
            isStruggle = FALSE;
        }

        i = 0;
        while (i < sub_8070828(entity, TRUE)) {
            info->abilityEffectFlags = 0;
            move.moveFlags |= 8;
            move.moveFlags |= 4;
            move.PP = 10;
            TryUseChosenMove(entity, isStruggle, 0, 0, FALSE, &move);

            if (!EntityIsValid(entity) || info->unk159 != 0) {
                break;
            }
            i++;
        }

        if (EntityIsValid(entity)) {
            if (moveId == MOVE_STRUGGLE && gUnknown_202F208 == 0) {
                LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FC690);
            }
            if (info->isTeamLeader && moveId != MOVE_STRUGGLE) {
                DungeonPos pos;

                pos.x = entity->pos.x + gAdjacentTileOffsets[info->action.direction].x;
                pos.y = entity->pos.y + gAdjacentTileOffsets[info->action.direction].y;
                sub_807FE44(&pos, 1);
            }
            sub_8071DA4(entity);
        }
    }
}

extern void sub_80684C4(void);
void sub_8045064(void);
extern void PlayDungeonCursorSE(u8 param_1);
extern void sub_8068344(void);
bool8 CanSubMenuItemBeChosen(s32 param_1);
void sub_8068310(s32 n, PokemonStruct1 **monPtrs);
void sub_8067F00(u8 a0, PokemonStruct1 **a1, s32 a2, s32 a3, s32 a4);
extern void DungeonShowWindows(WindowTemplates *a0, u8 a1);
u32 sub_8014140(s32 a0, const void *a1);
void sub_8083D1C(void);
void PlayDungeonConfirmationSE(void);
void PlayDungeonCancelSE(void);
void sub_806806C(PokemonStruct1 *a0);
void CreateDungeonMenuSubWindow(WindowTemplates *a0, s32 a1);
extern void sub_803EAF0(u32, u8 *);

extern const s32 gUnknown_8106E80[];
extern MenuInputStruct gDungeonMenu;
extern u32 gDungeonFramesCounter;

static EWRAM_DATA WindowHeader gUnknown_202F308 = {0};
static EWRAM_DATA s32 gUnknown_202F30C = 0;
static EWRAM_DATA s32 gUnknown_202F310 = 0;

// It's likely a struct only used in Blue version. Touchpad maybe?
static const u8 gUnknown_8106DA4[] = {
    0x01, 0, 0x38, 0, 0, 0, 0x18, 0, 0x18, 0, 0, 0, 0x02, 0, 0x38, 0, 0x68, 0, 0x18, 0, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const WindowTemplates gUnknown_8106DC8 = {
    .id = {
        [0] =
        {
            .unk0 = 0,
            .type = WINDOW_TYPE_WITH_HEADER,
            .pos = {0x02, 0x02},
            .width = 0x11,
            .height = 0x0E,
            .unk10 = 0x12,
            .unk12 = 0x02,
            .header = &gUnknown_202F308
        },
        [1] =
        {
            .unk0 = 0,
            .type = WINDOW_TYPE_NORMAL,
            .pos = {0x15, 0x04},
            .width = 0x07,
            .height = 0x04,
            .unk10 = 0x04,
            .unk12 = 0,
            .header = NULL
        },
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

void sub_8067A80(u8 a0, s32 a1, s32 a2, PokemonStruct1 **a3)
{
    s32 i;
    s32 r10;
    WindowTemplates spTxtStruct = gUnknown_8106DC8;

    gUnknown_202F30C = 0;
    r10 = 0;
    for (i = 0; i < a2; i++) {
        a3[i]->unk0 &= ~(0x8000);
    }

    while (1) {
        sub_8068310(a2, a3);
        if (gUnknown_202F310 >= a1)
            break;
        while (1) {
            s32 r7 = 0, r5 = 0;

            gUnknown_202F308.count = 1;
            gUnknown_202F308.currId = 0;
            gUnknown_202F308.width = 0xE;
            gUnknown_202F308.f3 = 0;

            ASM_MATCH_TRICK(r7);

            DungeonShowWindows(&spTxtStruct, 1);
            sub_8067F00(a0, a3, gUnknown_202F30C, a2, a1);
            gDungeonMenu.unk1A = min(a2, 8);
            gDungeonMenu.menuIndex = r10;
            gDungeonMenu.unk1C = 8;
            gDungeonMenu.unk1E = 0;
            gDungeonMenu.unk20 = 0;
            gDungeonMenu.unk4 = 0;
            gDungeonMenu.firstEntryY = 18;
            gDungeonMenu.unkC = 0;
            gDungeonMenu.unkE = 0;
            gDungeonMenu.unk14.x = 0;
            gDungeonMenu.unk0 = 0;
            sub_801317C(&gDungeonMenu.unk28);
            sub_80137B0(&gDungeonMenu, 0);
            while (1) {
                s32 r4;

                AddMenuCursorSprite(&gDungeonMenu);
                r5 = 0;
                r7 = 0;
                if (a2 - gUnknown_202F30C > 8) {
                    r5 = 1;
                    sub_80684C4();
                }
                if (gUnknown_202F30C != 0) {
                    r7 = 1;
                    sub_8068344();
                }

                r4 = sub_8014140(0, gUnknown_8106DA4);
                DungeonRunFrameActions(0x37);
                if (r4 == 2 && r5) {
                    if (a2 - gUnknown_202F30C > 8) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollDownWindowFunc(0);
                            DungeonRunFrameActions(0x37);
                        }
                        gUnknown_202F30C++;
                    }
                    r7 = 0;
                    r10 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 7) {
                        if (a2 - gUnknown_202F30C > 8) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                ScrollDownWindowFunc(0);
                                DungeonRunFrameActions(0x37);
                            }
                            gUnknown_202F30C++;
                        }
                        r7 = 0;
                        r10 = 7;
                        break;
                    }
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, 0);
                }

                if (r4 == 1 && r7 != 0) {
                    if (gUnknown_202F30C != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollUpWindowFunc(0);
                            DungeonRunFrameActions(0x37);
                        }
                        gUnknown_202F30C--;
                    }
                    r7 = 0;
                    r10 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 0) {
                        if (gUnknown_202F30C != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                ScrollUpWindowFunc(0);
                                DungeonRunFrameActions(0x37);
                            }
                            gUnknown_202F30C--;
                        }
                        r7 = 0;
                        r10 = 0;
                        break;
                    }
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, 0);
                }

                if (sub_80048C8()) {
                    continue;
                }

                if (gRealInputs.pressed & START_BUTTON) {
                    sub_8083D1C();
                    r7 = 3;
                    break;
                }
                if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                    PlayDungeonConfirmationSE();
                    r7 = 1;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    r7 = 2;
                    break;
                }
            }

            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x37);
            if (r7 == 0) {
                continue;
            }
            else if (r7 == 2) {
                r10 = gDungeonMenu.menuIndex;
                if (gUnknown_202F310 < a1) {
                    continue;
                }

                if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDFB8, TRUE) == 1) {
                    break;
                }
                else {
                    continue;
                }
            }
            else if (r7 == 3) {
                r10 = gDungeonMenu.menuIndex;
                sub_806806C(a3[gUnknown_202F30C + r10]);
                continue;
            }
            else {
                s32 arrId;
                u8 locIdIsPartner;

                r10 = gDungeonMenu.menuIndex;
                arrId = gUnknown_202F30C + r10;
                gDungeonSubMenuItemsCount = 0;
                AddActionToDungeonSubMenu(0x29, 0);
                AddActionToDungeonSubMenu(0x2A, 0);
                AddActionToDungeonSubMenu(0x40, 0);
                if (a3[arrId]->unk0 & 0x8000) {
                    SetActionUnusableInDungeonSubMenu(0x29);
                }
                else {
                    SetActionUnusableInDungeonSubMenu(0x2A);
                }

                // This unnecessary variable is required to match.
                locIdIsPartner = DUNGEON_JOIN_LOCATION_PARTNER;
                if (a3[arrId]->isTeamLeader || (a3[arrId]->dungeonLocation.id == DUNGEON_JOIN_LOCATION_LEADER || a3[arrId]->dungeonLocation.id == locIdIsPartner)) {
                    SetActionUnusableInDungeonSubMenu(0x29);
                }

                sub_8045064();
                CreateDungeonMenuSubWindow(&spTxtStruct, 0x15);

                while (1) {
                    AddMenuCursorSprite(&gDungeonMenu);
                    DungeonRunFrameActions(0x37);

                    if (gRealInputs.repeated & DPAD_DOWN) {
                        PlayDungeonCursorSE(1);
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, 1);
                    }
                    if (gRealInputs.repeated & DPAD_UP) {
                        PlayDungeonCursorSE(1);
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, 1);
                    }

                    if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                        if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                            PlayDungeonConfirmationSE();
                            r7 = 1;
                            break;
                        }
                        PlayDungeonCancelSE();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                        PlayDungeonCancelSE();
                        r7 = 0;
                        break;
                    }
                }

                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x37);
                if (r7 != 0) {
                    if (gDungeonMenu.menuIndex == 0) {
                        a3[arrId]->unk0 |= 0x8000;
                        sub_8068310(a2, a3);
                    }
                    else if (gDungeonMenu.menuIndex == 1) {
                        a3[arrId]->unk0 &= ~(0x8000);
                        sub_8068310(a2, a3);
                    }
                    else {
                        sub_806806C(a3[arrId]);
                    }
                }
                continue;
            }
        }
    }
}

void sub_8067F00(u8 a0, PokemonStruct1 **a1, s32 a2_, s32 a3, s32 a4)
{
    s32 i, y;
    s32 a2;

    a2 = a2_ - 1;
    y = 0x16;

    sub_80073B8(0);
    WriteFriendAreaName(gFormatBuffer_Monsters[0], a0, FALSE);
    PrintFormattedStringOnWindow(12, 0, _("{POKEMON_0}"), 0, '\0');
    i = 0;
    while (i < 10) {
        if (a2 >= 0) {
            if (a2 >= a3) {
                break;
            }

            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0], a1[a2], 0);
            sub_808D930(gFormatBuffer_Monsters[1], a1[a2]->speciesNum);
            gFormatArgs[0] = a2 + 1;
            if (a1[a2]->unk0 & 0x8000) {
                InlineStrcpy(gFormatBuffer_Items[0], _("{STAR_BULLET}"));
            }
            else {
                InlineStrcpy(gFormatBuffer_Items[0], _("{ICON_BLANK}"));
            }

            if (a1[a2]->unk0 & 0x4000) {
                PrintFormattedStringOnWindow(7, y, _("{MOVE_ITEM_0}{color CYAN}$v02:{POKEMON_0}{reset}"), 0, '\0');
            }
            else {
                PrintFormattedStringOnWindow(7, y, _("{MOVE_ITEM_0}{color YELLOW}$v02:{POKEMON_0}{reset}"), 0, '\0');
            }
        }

        i++;
        y += 12;
        a2++;
    }

    sub_80073E0(0);
    sub_80073B8(1);
    if (gUnknown_202F310 >= a4) {
        PrintFormattedStringOnWindow(8, 2, _("Press {B_BUTTON}\nif OK."), 1, '\0');
    }
    else {
        gFormatArgs[0] = a4 - gUnknown_202F310;
        PrintFormattedStringOnWindow(8, 2, _("Say bye to\n{VALUE_0} more"), 1, '\0');
    }

    sub_80073E0(1);
}

void sub_806806C(PokemonStruct1 *a0)
{
    struct unkStruct_808FF20 unkStruct;
    struct UnkInfoTabStruct var_C8;
    WindowTemplates spTxtStruct = {0};
    s32 r7;

    spTxtStruct.id[0].type = WINDOW_TYPE_WITH_HEADER;
    spTxtStruct.id[0].pos.x = 2;
    spTxtStruct.id[0].pos.y = 2;
    spTxtStruct.id[0].width = 0x12;
    spTxtStruct.id[0].height = 0xE;
    spTxtStruct.id[0].unk10 = 0x12;
    spTxtStruct.id[0].unk12 = 2;
    spTxtStruct.id[0].header = &gUnknown_202F308;
    spTxtStruct.id[1].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.id[2].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.id[3].type = WINDOW_TYPE_NORMAL;

    r7 = 0;
    unkStruct.unk40 = 0;
    unkStruct.unk56 = 0;
    gDungeonMenu.menuIndex = 0;

    while (1) {
        bool32 loopBreak = FALSE;
        s32 spF8[4] = {2, 3, 4, 5};

        gUnknown_202F308.count = 4;
        gUnknown_202F308.currId = r7;
        gUnknown_202F308.width = 10;
        gUnknown_202F308.f3 = 0;

        gDungeonMenu.unk1E = r7;
        gDungeonMenu.unk20 = 4;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1C = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk0 = 0;

        sub_801317C(&gDungeonMenu.unk28);
        DungeonShowWindows(&spTxtStruct, 1);
        sub_808FF20(&unkStruct, a0, gDungeon->unk644.unk16);
        CreatePokemonInfoTabScreen(spF8[r7], r7, &unkStruct, &var_C8, 0);

        gDungeonMenu.unkC = (gWindows[0].x + 15) * 8;
        gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;

        while (1) {
            s32 r5;

            AddMenuCursorSprite(&gDungeonMenu);
            if (spF8[r7] == 4) {
                if (var_C8.unk0[8] != 0) {
                    sub_80684C4();
                }
                if (unkStruct.unk40 != 0) {
                    sub_8068344();
                }
            }

            r5 = sub_8014140(0, gUnknown_8106DA4);
            DungeonRunFrameActions(0x1C);
            if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                PlayDungeonCursorSE(0);
                if (++r7 == 4) {
                    r7 = 0;
                }
                break;
            }
            if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                PlayDungeonCursorSE(0);
                if (--r7 == -1) {
                    r7 = 3;
                }
                break;
            }

            if (spF8[r7] == 4) {
                if (((gRealInputs.repeated & DPAD_DOWN) || r5 == 2) && var_C8.unk0[8] != 0) {
                    s32 i;

                    PlayDungeonCursorSE(0);
                    for (i = 0; i < 6; i++) {
                        ScrollDownWindowFunc(0);
                        DungeonRunFrameActions(0x1C);
                    }
                    unkStruct.unk40++;
                    break;
                }
                if (((gRealInputs.repeated & DPAD_UP) || r5 == 1) && unkStruct.unk40 != 0) {
                    s32 i;

                    PlayDungeonCursorSE(0);
                    for (i = 0; i < 6; i++) {
                        ScrollUpWindowFunc(0);
                        DungeonRunFrameActions(0x1C);
                    }
                    unkStruct.unk40--;
                    break;
                }
            }

            if (sub_80048C8()) {
                continue;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                loopBreak = TRUE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                loopBreak = TRUE;
                break;
            }
        }

        DungeonRunFrameActions(0x37);
        if (loopBreak) {
            break;
        }
    }

    sub_803EAF0(0, NULL);
}

void sub_8068310(s32 n, PokemonStruct1 **monPtrs)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < n; i++) {
        if ((monPtrs[i]->unk0 & 0x8000) != 0) {
            counter++;
        }
    }
    gUnknown_202F310 = counter;
}

void sub_8068344(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 16);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x8);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

// The same as sub_80623B0
void sub_80684C4(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 0);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x70);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}
