#include "global.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "items.h"

extern u16 gUnknown_80F6964[];

bool8 sub_80461C8(Position *, u32);
void sub_80460F8(Position *, Item *, u32);

Item * sub_8044CC8(Entity *param_1, unkStruct_8044CC8 *param_2)
{
  Tile *tile;
  Item *item;
  EntityInfo *info;
  
  if ((u8)(param_2->actionUseIndex - 1) < INVENTORY_SIZE) {
    item = &gTeamInventoryRef->teamItems[param_2->actionUseIndex - 1];
  }
  else if (param_2->actionUseIndex == 0x80) {
    tile = GetTile((param_2->lastItemThrowPosition).x,(param_2->lastItemThrowPosition).y);
    item = GetItemData(tile->object);
  }
  else {
    if (param_2->actionUseIndex == 0x81) {
      info = param_1->info;
    }
    else {
      if (3 < (u8)(param_2->actionUseIndex + 0x70)) {
        return NULL;
      }
      info = gDungeon->teamPokemon[param_2->actionUseIndex - 0x90]->info;
    }
    item = &info->heldItem;
  }
  return item;
}

bool8 sub_8044D40(ActionContainer *param_1,s32 index)
{
  Item *item;
  unkStruct_8044CC8 *puVar1;
  
  puVar1 = &param_1->unk4[index];
  if ((u8)(puVar1->actionUseIndex - 1) < INVENTORY_SIZE) {
    item = &gTeamInventoryRef->teamItems[puVar1->actionUseIndex - 1];
    item->id = ITEM_NOTHING;
    item->quantity = 0;
    item->flags = 0;
    FillInventoryGaps();
  }
  else {
    if (puVar1->actionUseIndex != 0x80) {
      return FALSE;
    }
    sub_80461C8(&puVar1->lastItemThrowPosition,1);
  }
  return TRUE;
}

Item *sub_8044D90(Entity *entity, s32 index, s32 unused) {
    EntityInfo *info = entity->info;
    register unkStruct_8044CC8 *puVar1 asm("r3") = &info->action.unk4[index];
    return sub_8044CC8(entity, puVar1);
}

Entity *sub_8044DA4(Entity *entity, s32 index)
{
    EntityInfo *info = entity->info;
    return gDungeon->teamPokemon[info->action.unk4[index].actionUseIndex];
}

u16 sub_8044DC8(u8 *param_1)
{
  if (param_1[2] == ITEM_SWITCH_BOX) {
    return 0x35;
  }
  else {
    return gUnknown_80F6964[GetItemCategory(param_1[2])];
  }
}

void sub_8044DF0(Entity *entity, s32 index, u32 unused)
{
  Item *item;
  EntityInfo *info;
  
  info = entity->info;
  item = sub_8044D90(entity,index,unused);
  if ((info->action).unk4[0].actionUseIndex == 0x80) {
    sub_80461C8(&(info->action).unk4[0].lastItemThrowPosition,1);
  }
  else {
    item->id = ITEM_NOTHING;
    item->quantity = 0;
    item->flags = 0;
    FillInventoryGaps();
  }
}


void sub_8044E24(Entity *entity,int index,u32 unused)
{
  Item *itemPtr;
  EntityInfo *info;
  Position *pos;
  Item item;
  
  itemPtr = sub_8044D90(entity,index,unused);
  info = entity->info;
  if (!IsHMItem(itemPtr->id)) {
    if (GetItemCategory(itemPtr->id) == CATEGORY_TMS_HMS) {
      if (info->action.unk4[index].actionUseIndex == 0x80) {
        item = *itemPtr;
        pos = &info->action.unk4[index].lastItemThrowPosition;
        sub_80461C8(pos,1);
        item.quantity = itemPtr->id - 125;
        item.id = ITEM_TM_USED_TM;
        sub_80460F8(pos,&item,1);
      }
      else {
        itemPtr->quantity = itemPtr->id - 125;
        itemPtr->id = ITEM_TM_USED_TM;
      }
    }
    else {
      sub_8044DF0(entity,index,unused);
    }
  }
}
