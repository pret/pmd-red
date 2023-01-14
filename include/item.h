#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "constants/item.h"
#include "code_8092334.h"

struct Item
{
    /* 0x0 */ u8 *namePointer;
    /* 0x4 */ u32 buyPrice;
    /* 0x8 */ u32 sellPrice;
    /* 0xC */ u8 type;
    /* 0xD */ u8 icon;
    /* 0x10 */ u8 *descriptionPointer;
    // Determines how the AI can use the item.
    // Index 0: Item can be used on self.
    // Index 1: Item can be thrown at allies.
    // Index 2: Item can be thrown at enemies.
    /* 0x14 */ bool8 aiFlags[3];
    /* 0x18 */ s16 move;
    /* 0x1A */ u8 order; // Numbered order they are in storage
    /* 0x1B */ u8 unkThrow1B[2];
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 category;
};

struct ItemSlot
{
    u8 itemFlags;
    u8 numItems;
    u8 itemIndex;
};

struct HeldItem {
  u8 itemIndex;
  u8 numItems;
};

struct unkStruct_80915F4
{
    s16 unk0;
    u16 unk2;
};

struct unkStruct_8090F58
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    u8 unk8;
};

enum ItemFlag
{
    ITEM_FLAG_EXISTS = 1 << 0,
    ITEM_FLAG_FOR_SALE = 1 << 1,
    ITEM_FLAG_STICKY = 1 << 3,
    ITEM_FLAG_SET = 1 << 4 // This item can be thrown by pressing L+R instead of having to go to the bag menu.
};

enum ItemAIFlag
{
    ITEM_AI_FLAG_TARGET_SELF,
    ITEM_AI_FLAG_TARGET_ALLY,
    ITEM_AI_FLAG_TARGET_ENEMY
};

#define NUMBER_OF_GUMMIS 18
#define INVENTORY_SIZE 20
#define STORAGE_SIZE NUMBER_OF_ITEM_IDS

void LoadItemParameters(void);
struct TeamInventory *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
s32 GetNumberOfFilledInventorySlots(void);
bool8 IsThrowableItem(u8 itemIndex);
void xxx_init_itemslot_8090A8C(struct ItemSlot *param_1,u8 itemIndex,u8 param_3);
void xxx_init_helditem_8090B08(struct HeldItem *param_1,u8 itemIndex);
void HeldItemToSlot(struct ItemSlot *param_1, struct HeldItem *param_2);
void SlotToHeldItem(struct HeldItem *held,struct ItemSlot *slot);
u8 GetItemType(u8 index);
s32 GetStackBuyValue(struct ItemSlot *param_1);
s32 GetStackSellValue(struct ItemSlot *param_1);
s32 GetStackBuyPrice(struct ItemSlot *param_1);
s32 GetStackSellPrice(struct ItemSlot *param_1);
s32 GetItemBuyPrice(u8 itemIndex);
s32 GetItemSellPrice(u8 itemIndex);
s32 GetItemOrder(u8 itemIndex);
u8 GetItemPalette(u8 itemIndex);
u32 GetItemCategory(u8 itemIndex);
u32 GetItemUnkThrow(u8 itemIndex, u32 r1);
u8 *GetItemDescription(u8 itemIndex);
bool8 GetItemAIFlag(u8 itemIndex, u32 r1);
void sub_8090DC4(void* param_1,u8 itemIndex, struct unkStruct_8090F58* param_3);
void sub_8090E14(u8* ext_buffer, struct ItemSlot* slot, struct unkStruct_8090F58* a3);
bool8 AddItemToInventory(const struct ItemSlot* slot);
void ConvertMoneyItemToMoney();
void AddToTeamMoney(s32 amount);
u32 GetMoneyValue(struct ItemSlot* slot);
u16 GetItemMove(u8 index);
bool8 CanSellItem(u32 id);
bool8 IsGummiItem(u8);
void sub_8090F58(void*, u8 *, struct ItemSlot *, struct unkStruct_8090F58*);
void ShiftItemsDownFrom(s32 start);
void ClearItemSlotAt(u32 index);
void MoveToStorage(struct ItemSlot* slot);
s32 CountKecleonShopItems(void);
void InitKecleonShopItem(u8 index);
struct HeldItem *GetKecleonShopItem(u8 index);
void FillKecleonShopGaps(void);
void SortKecleonShopInventory(void);
void ChooseKecleonShopInventory(u8 index);
bool8 AddKecleonShopItem(u8 itemIndex);
u32 CountKecleonWareItems(void);
void InitKecleonWareItem(u8 index);
struct HeldItem* GetKecleonWareItem(u8 index);
void FillKecleonWareGaps(void);
void SortKecleonWareInventory(void);
void ChooseKecleonWareInventory(u8 index);
bool8 AddKecleonWareItem(u8 itemIndex);
void FillInventoryGaps();
bool8 AddHeldItemToInventory(struct HeldItem* slot);
bool8 IsNotMoneyOrUsedTMItem(u8 id);
s32 FindItemInInventory(u8 itemIndex);
bool8 IsHMItem(u8 id);
bool8 IsEdibleItem(u8 id);


void RestoreHeldItem(struct unkStruct_8094924*, struct HeldItem*);
void SaveHeldItem(struct unkStruct_8094924*, struct HeldItem*);
void RestoreItemSlot(struct unkStruct_8094924 *a1, struct ItemSlot *a2);
void SaveItemSlot(struct unkStruct_8094924 *a1, struct ItemSlot *a2);
s32 RestoreTeamInventory(u8 *unk0, u32 size);
s32 SaveTeamInventory(u8 *unk0, u32 size);

#endif
