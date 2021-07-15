#include "global.h"
#include "file_system.h"
#include "item.h"
#include "team_inventory.h"
#include "random.h"
#include "pokemon.h"

extern struct TeamInventory *gTeamInventory_203B460;
extern struct TeamInventory gUnknown_20389A8;
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_8109764;
extern const char gUnknown_8109794[];
extern const char gUnknown_81097A4[];
extern u16 *gGummiStatBoostLUT;

EWRAM_DATA struct OpenedFile *gItemParametersFile;
EWRAM_DATA struct Item *gItemParametersData;

extern u8 GetItemType(u8);
extern u32 GetItemUnkThrow(u8, u32);
extern bool8 CanSellItem(u8);
extern void sub_8090F58(void*, u8 *, struct ItemSlot *, u8*);
extern void ExpandPlaceholdersBuffer(u8 *, const u8 *, ...);
extern s32 sub_8090FEC(s32 a1, u8* a2, u8 a3);

void LoadItemParameters(void)
{
  gTeamInventory_203B460 = &gUnknown_20389A8;
  gItemParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_8109764,&gSystemFileArchive);
  gItemParametersData = (struct Item *) gItemParametersFile->data;
}

struct TeamInventory *GetMoneyItemsInfo(void)
{
    return &gUnknown_20389A8;
}

void InitializeMoneyItems(void)
{
  s32 i;
  
  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    gTeamInventory_203B460->teamItems[i].unk0 = 0;
  }

  for(i = 0; i < 0xF0; i++)
  {
    gTeamInventory_203B460->teamStorage[i] = 0;
  }

  for(i = 0; i < 8; i++)
  {
    xxx_init_unk230_substruct(i);
  }
  gTeamInventory_203B460->teamMoney = 0;
  gTeamInventory_203B460->teamSavings = 0;
}

s32 GetNumberOfFilledInventorySlots(void)
{
  s32 i;
  s32 count;
  
  count = 0;
  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    if ((gTeamInventory_203B460->teamItems[i].unk0 & 1) != 0) {
      count++;
    }
  }
  return count;
}

bool8 IsThrowableItem(u8 itemIndex)
{
  if ((GetItemType(itemIndex) != ITEM_TYPE_THROWABLE) && (GetItemType(itemIndex) != ITEM_TYPE_ROCK))
    return FALSE;
  else 
    return TRUE;
}

void sub_8090A8C(struct ItemSlot *param_1,u8 itemIndex,u8 param_3)
{
  u32 uVar3;
  u32 uVar4;
  
  if (itemIndex != ITEM_ID_NOTHING) {
    param_1->unk0 = 1;
    param_1->itemIndex = itemIndex;
    if (IsThrowableItem(itemIndex)) {
        uVar3 = GetItemUnkThrow(itemIndex,0);
        uVar4 = GetItemUnkThrow(itemIndex,1);
        param_1->numItems = RandomRange(uVar3,uVar4);
    }
    else if (GetItemType(itemIndex) == ITEM_TYPE_MONEY)
        param_1->numItems  = 1;
    else 
        param_1->numItems  = 0;

    if (param_3 != 0)
        param_1->unk0 |= 8;

  }
  else {
    param_1->unk0 = 0;
    param_1->itemIndex = ITEM_ID_NOTHING;
    param_1->numItems  = 0;
  }
}

void sub_8090B08(struct ItemSlot_ALT *param_1,u8 itemIndex)
{
  u32 uVar2;
  u32 uVar3;
  
  if (itemIndex != ITEM_ID_NOTHING) {
    param_1->itemIndex = itemIndex;
    if (IsThrowableItem(itemIndex)) {
        uVar2 = GetItemUnkThrow(itemIndex,0);
        uVar3 = GetItemUnkThrow(itemIndex,1);
        param_1->numItems = RandomRange(uVar2,uVar3);
    } 
    else if (GetItemType(itemIndex) == ITEM_TYPE_MONEY)
        param_1->numItems = 1;
    else
        param_1->numItems = 0;
  }
  else {
    param_1->itemIndex = 0;
    param_1->numItems = 0;
  }
}

void sub_8090B64(struct ItemSlot *param_1, struct ItemSlot_ALT *param_2)
{
    u8 r6;

    if(param_2->itemIndex != ITEM_ID_NOTHING)
    {
        param_1->unk0 = 1;
        param_1->itemIndex = param_2->itemIndex;
        r6 = IsThrowableItem(param_1->itemIndex);
        if(r6 != 0 || GetItemType(param_1->itemIndex) == ITEM_TYPE_MONEY)
            param_1->numItems = param_2->numItems;
        else if(param_1->itemIndex == ITEM_ID_USED_TM)
            param_1->numItems = param_2->numItems;
        else
            param_1->numItems = 0;
    }
    else
    {
        param_1->itemIndex = ITEM_ID_NOTHING;
        param_1->numItems = 0;
        param_1->unk0 = 0;
    }
}

void sub_8090BB0(struct ItemSlot_ALT *param_1,struct ItemSlot *param_2)
{
  if ((param_2->unk0 & 1) != 0) {
    param_1->itemIndex = param_2->itemIndex;
    param_1->numItems = param_2->numItems;
  }
  else {
    param_1->itemIndex = ITEM_ID_NOTHING;
  }
}

u8 GetItemType(u8 index)
{
    return gItemParametersData[index].type;
}

s32 GetStackBuyValue(struct ItemSlot *param_1)
{
  if (param_1->itemIndex == ITEM_ID_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 GetStackSellValue(struct ItemSlot *param_1)
{
  if (param_1->itemIndex == ITEM_ID_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].sellPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].sellPrice;
    }
  }
}

s32 GetStackBuyPrice(struct ItemSlot *param_1)
{
  if (!CanSellItem(param_1->itemIndex)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 GetStackSellPrice(struct ItemSlot *param_1)
{
  if (!CanSellItem(param_1->itemIndex)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].sellPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].sellPrice;
    }
  }
}

s32 GetItemBuyPrice(u8 itemIndex)
{
    return gItemParametersData[itemIndex].buyPrice;
}

s32 GetItemSellPrice(u8 itemIndex)
{
    return gItemParametersData[itemIndex].sellPrice;
}

s32 GetItemOrder(u8 itemIndex)
{
    return gItemParametersData[itemIndex].order;
}

u8 GetItemPalette(u8 itemIndex)
{
    return gItemParametersData[itemIndex].palette;
}

u8 GetItemCategory(u8 itemIndex)
{
    return gItemParametersData[itemIndex].category;
}

u32 GetItemUnkThrow(u8 itemIndex, u32 r1)
{
    return gItemParametersData[itemIndex].unkThrow1B[r1];
}

u8 *GetItemDescription(u8 itemIndex)
{
    return gItemParametersData[itemIndex].descriptionPointer;
}

u32 GetItemUnkFood(u8 itemIndex, u32 r1)
{
    return gItemParametersData[itemIndex].unkFood1[r1];
}

void sub_8090DC4(void* param_1,u8 itemIndex, u8* param_3)
{
  char acStack104 [80];
  struct ItemSlot unkItem;
  
  strncpy(acStack104,gItemParametersData[itemIndex].namePointer,0x50);
  sub_8090A8C(&unkItem,itemIndex,0);
  unkItem.numItems = 1;
  sub_8090F58(param_1,acStack104,&unkItem,param_3);
}

extern const u8 gUnknown_8109770[];
extern const u8 gUnknown_8109778[];
extern const u8 gUnknown_810977C[];
extern const u8 gUnknown_8109784[];
extern const u8 gUnknown_810978C[];

void sub_8090E14(u8* ext_buffer, struct ItemSlot* slot, u8* a3) {
  s32 unk8 = 0;
  u8 buffer[80];

  if (a3) {
    unk8 = a3[8] != 0;
  }

  if (GetItemType(slot->itemIndex) == ITEM_TYPE_THROWABLE) {
    // I feel like these labels might actually be there...
    if (unk8) {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109770, gItemParametersData[slot->itemIndex].namePointer, slot->numItems);
    }
    else {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109778, gItemParametersData[slot->itemIndex].namePointer);
    }
  }
  else if (GetItemType(slot->itemIndex) == ITEM_TYPE_ROCK) {
    if (unk8) {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109770, gItemParametersData[slot->itemIndex].namePointer, slot->numItems);
    }
    else {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109778, gItemParametersData[slot->itemIndex].namePointer);
    }
  }
  else if (slot->itemIndex == 105) {
    ExpandPlaceholdersBuffer(buffer, gUnknown_810977C, GetMoneyValue(slot));
  }
  else {
    strncpy(buffer, gItemParametersData[slot->itemIndex].namePointer, 80);
  }

  if (slot->unk0 & 8) {
    ExpandPlaceholdersBuffer(ext_buffer, gUnknown_8109784, buffer);
    strncpy(buffer, ext_buffer, 80);
  }

  if (a3) {
    if (a3[4] && (slot->unk0 & 0x10)) {
      ExpandPlaceholdersBuffer(ext_buffer, gUnknown_810978C, buffer);
      strncpy(buffer, ext_buffer, 80);
    }
    if ((*(u32*)a3 == 1) || (*(u32*)a3 == 3)) {
        if (slot->unk0 & 2) {
          sub_8090F58(ext_buffer, buffer, slot, a3);
          return;
        }
      strncpy(ext_buffer, buffer, 80);
      return;
    }
  }
  else {
    strncpy(ext_buffer, buffer, 80);
    return;
  }

  sub_8090F58(ext_buffer, buffer, slot, a3);
  return;
}

void sub_8090F58(void* a1, u8 *a2, struct ItemSlot *slot, u8* a4) {
  u32 unk0;
  s32 value;
  u8 buffer[40];
  
  if (!a4) {
    strncpy(a1, a2, 80);
    return;
  }
  else {
    unk0 = *(u32*)a4;
    switch (unk0) {
      case 1:
      case 2:
        value = GetStackBuyValue(slot);
        break;
      case 3:
      case 4:
        value = GetStackSellValue(slot);
        break;
      default:
        value = 0;
        break;
    }

    if (!value) {
      strncpy(a1, a2, 80);
      return;
    }
  }

  if (*(s16*)&a4[6]) {    
    sub_8090FEC(value, buffer, 1);
    ExpandPlaceholdersBuffer(a1, gUnknown_8109794, a2, *(s16*)&a4[6], buffer);
  }
  else {
    sub_8090FEC(value, buffer, 0);
    ExpandPlaceholdersBuffer(a1, gUnknown_81097A4, a2, buffer);
  }
}
