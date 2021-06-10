#include "global.h"
#include "file_system.h"
#include "gUnknown_203B460.h"
#include "random.h"
#include "item.h"

extern struct unkStruct_203B460 *gUnknown_203B460;
extern struct unkStruct_203B460 gUnknown_20389A8;
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_8109764;

EWRAM_DATA struct OpenedFile *gItemParametersFile;
EWRAM_DATA struct Item *gItemParametersData;

extern void sub_8091840(u8);
extern u8 GetItemType(u8);
extern u32 GetItemUnkThrow(u8, u32);
extern s32 sub_80915D4(struct ItemStruct_203B460 *);
extern u8 sub_80914E4(u8);
extern void sub_8090F58(u32, u8 *, struct ItemStruct_203B460 *, u32);

void LoadItemParameters(void)
{
  gUnknown_203B460 = &gUnknown_20389A8;
  gItemParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_8109764,&gSystemFileArchive);
  gItemParametersData = (struct Item *) gItemParametersFile->data;
}

struct unkStruct_203B460 *GetMoneyItemsInfo(void)
{
    return &gUnknown_20389A8;
}

void InitializeMoneyItems(void)
{
  s32 iVar1;
  
  for(iVar1 = 0; iVar1 < 0x14; iVar1++)
  {
    gUnknown_203B460->fill0[iVar1].unk0 = 0;
  }

  for(iVar1 = 0; iVar1 < 0xF0; iVar1++)
  {
    gUnknown_203B460->unk50[iVar1] = 0;
  }

  for(iVar1 = 0; iVar1 < 8; iVar1++)
  {
    sub_8091840(iVar1);
  }
  gUnknown_203B460->teamMoney = 0;
  gUnknown_203B460->teamSavings = 0;
}

s32 sub_8090A34(void)
{
  s32 iVar2;
  s32 iVar3;
  
  iVar3 = 0;
  for(iVar2 = 0; iVar2 < 0x14; iVar2++)
  {
    if ((gUnknown_203B460->fill0[iVar2].unk0 & 1) != 0) {
      iVar3++;
    }
  }
  return iVar3;
}

bool8 sub_8090A60(u8 itemIndex)
{
  if ((GetItemType(itemIndex) != ITEM_TYPE_THROWABLE) && (GetItemType(itemIndex) != ITEM_TYPE_ROCK)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

void sub_8090A8C(struct ItemStruct_203B460 *param_1,u8 itemIndex,u8 param_3)
{
  u32 uVar3;
  u32 uVar4;
  
  if (itemIndex != 0) {
    param_1->unk0 = 1;
    param_1->itemIndex = itemIndex;
    if (sub_8090A60(itemIndex)) {
        uVar3 = GetItemUnkThrow(itemIndex,0);
        uVar4 = GetItemUnkThrow(itemIndex,1);
        param_1->numItems = RandomRange(uVar3,uVar4);
    }
    else {
        if (GetItemType(itemIndex) == ITEM_TYPE_MONEY) {
            param_1->numItems  = 1;
        }
        else {
            param_1->numItems  = 0;
        }
    }
    if (param_3 != 0) {
        param_1->unk0 |= 8;
    }
  }
  else {
    param_1->unk0 = 0;
    param_1->itemIndex = 0;
    param_1->numItems  = 0;
  }
}

// TODO is this a struct one too?
void sub_8090B08(struct ItemStruct_203B460 *param_1,u8 itemIndex)
{
  u32 uVar2;
  u32 uVar3;
  
  if (itemIndex != 0) {
    param_1->unk0 = itemIndex;
    if (sub_8090A60(itemIndex)) {
        uVar2 = GetItemUnkThrow(itemIndex,0);
        uVar3 = GetItemUnkThrow(itemIndex,1);
        param_1->numItems = RandomRange(uVar2,uVar3);
    } else {
      if (GetItemType(itemIndex) == ITEM_TYPE_MONEY) {
        param_1->numItems = 1;
      }
      else {
        param_1->numItems = 0;
      }
    }
  }
  else {
    param_1->unk0 = 0;
    param_1->numItems = 0;
  }
}

NAKED
void sub_8090B64(u32 r0, u32 r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r5, r1, 0\n"
	"\tldrb r1, [r5]\n"
	"\tadds r0, r1, 0\n"
	"\tcmp r0, 0\n"
	"\tbeq _08090BA4\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r4]\n"
	"\tstrb r1, [r4, 0x2]\n"
	"\tldrb r0, [r4, 0x2]\n"
	"\tbl sub_8090A60\n"
	"\tlsls r0, 24\n"
	"\tlsrs r6, r0, 24\n"
	"\tcmp r6, 0\n"
	"\tbne _08090B9A\n"
	"\tldrb r0, [r4, 0x2]\n"
	"\tbl GetItemType\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, 0x6\n"
	"\tbeq _08090B9A\n"
	"\tldrb r0, [r4, 0x2]\n"
	"\tcmp r0, 0x7C\n"
	"\tbne _08090BA0\n"
"_08090B9A:\n"
	"\tldrb r0, [r5, 0x1]\n"
	"\tstrb r0, [r4, 0x1]\n"
	"\tb _08090BAA\n"
"_08090BA0:\n"
	"\tstrb r6, [r4, 0x1]\n"
	"\tb _08090BAA\n"
"_08090BA4:\n"
	"\tstrb r0, [r4, 0x2]\n"
	"\tstrb r0, [r4, 0x1]\n"
	"\tstrb r0, [r4]\n"
"_08090BAA:\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

void sub_8090BB0(struct ItemStruct_203B460 *param_1,struct ItemStruct_203B460 *param_2)
{
  if ((param_2->unk0 & 1) != 0) {
    param_1->unk0 = param_2->itemIndex;
    param_1->numItems = param_2->numItems;
  }
  else {
    param_1->unk0 = 0;
  }
}

u8 GetItemType(u8 index)
{
    return gItemParametersData[index].type;
}

s32 sub_8090BE4(struct ItemStruct_203B460 *param_1)
{
  if (param_1->itemIndex == 0x69) {
    return sub_80915D4(param_1);
  }
  else {
    if (sub_8090A60(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 sub_8090C30(struct ItemStruct_203B460 *param_1)
{
  if (param_1->itemIndex == 0x69) {
    return sub_80915D4(param_1);
  }
  else {
    if (sub_8090A60(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].sellPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].sellPrice;
    }
  }
}

s32 sub_8090C7C(struct ItemStruct_203B460 *param_1)
{
  if (sub_80914E4(param_1->itemIndex) == 0) {
    return 0;
  }
  else {
    if (sub_8090A60(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 sub_8090CCC(struct ItemStruct_203B460 *param_1)
{
  if (sub_80914E4(param_1->itemIndex) == 0) {
    return 0;
  }
  else {
    if (sub_8090A60(param_1->itemIndex)) {
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

u8 GetItemOrder(u8 itemIndex)
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

void sub_8090DC4(u32 param_1,u8 itemIndex,u32 param_3)
{
  char acStack104 [80];
  struct ItemStruct_203B460 unkItem;
  
  strncpy(acStack104,gItemParametersData[itemIndex].namePointer,0x50);
  sub_8090A8C(&unkItem,itemIndex,0);
  unkItem.numItems = 1;
  sub_8090F58(param_1,acStack104,&unkItem,param_3);
}

