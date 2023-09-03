#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "constants/item.h"
#include "code_8092334.h"

// size: 0x20
typedef struct ItemDataEntry
{
    /* 0x0 */ u8 *name;
    /* 0x4 */ u32 buyPrice;
    /* 0x8 */ u32 sellPrice;
    /* 0xC */ u8 category;
    /* 0xD */ u8 icon;
    /* 0x10 */ u8 *description;
    // Determines how the AI can use the item.
    // Index 0: Item can be used on self.
    // Index 1: Item can be thrown at allies.
    // Index 2: Item can be thrown at enemies.
    /* 0x14 */ bool8 aiFlags[3];
    /* 0x18 */ s16 moveID;
    /* 0x1A */ u8 order; // Numbered order they are in storage
    /* 0x1B */ u8 spawnAmountRange[2];
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 actionType;
} ItemDataEntry;

// size: 0x4
typedef struct Item
{
    /* 0x0 */ u8 flags;
    /* 0x1 */ u8 quantity;
    /* 0x2 */ u8 id;
} Item;

// size: 0x4
typedef struct BulkItem
{
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 quantity;
} BulkItem;

// size: 0x4
typedef struct Gummi
{
    /* 0x0 */ s16 boostAmount;
    /* 0x2 */ u16 flags;
} Gummi;

// size: 0xC
typedef struct unkStruct_8090F58
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    u8 unk8;
} unkStruct_8090F58;

// size: 0x268
typedef struct TeamInventory
{
    /* 0x0 */ Item teamItems[INVENTORY_SIZE];
    /* 0x50 */ u16 teamStorage[STORAGE_SIZE];
    /* 0x230 */ BulkItem kecleonShopItems[MAX_KECLEON_ITEM_SHOP_ITEMS];
    /* 0x250 */ BulkItem kecleonWareItems[MAX_KECLEON_WARE_SHOP_ITEMS];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ s32 teamSavings;
} TeamInventory;

enum ItemFlag
{
    ITEM_FLAG_EXISTS = 1 << 0,
    ITEM_FLAG_IN_SHOP = 1 << 1, // in a Kecleon shop
    ITEM_FLAG_UNPAID = 1 << 2, // Picked up in Kecleon shop but not paid for yet
    ITEM_FLAG_STICKY = 1 << 3,
    ITEM_FLAG_SET = 1 << 4 // This item can be thrown by pressing L+R instead of having to go to the bag menu.
};

enum ItemAIFlag
{
    ITEM_AI_FLAG_TARGET_SELF,
    ITEM_AI_FLAG_TARGET_ALLY,
    ITEM_AI_FLAG_TARGET_ENEMY
};

extern TeamInventory *gTeamInventoryRef;

void LoadItemParameters(void);
TeamInventory *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
s32 GetNumberOfFilledInventorySlots(void);
bool8 IsThrowableItem(u8 id);
void xxx_init_itemslot_8090A8C(Item *param_1,u8 id,u8 param_3);
void xxx_init_helditem_8090B08(BulkItem *param_1,u8 id);
void HeldItemToSlot(Item *param_1, BulkItem *param_2);
void SlotToHeldItem(BulkItem *held, Item *slot);
u8 GetItemCategory(u8 index);
s32 GetStackBuyValue(Item *param_1);
s32 GetStackSellValue(Item *param_1);
s32 GetStackBuyPrice(Item *param_1);
s32 GetStackSellPrice(Item *param_1);
s32 GetItemBuyPrice(u8 id);
s32 GetItemSellPrice(u8 id);
s32 GetItemOrder(u8 id);
u8 GetItemPalette(u8 id);
u32 GetItemActionType(u8 id);
u32 GetSpawnAmountRange(u8 id, u32 r1);
u8 *GetItemDescription(u8 id);
bool8 GetItemAIFlag(u8 id, u32 r1);
void BufferItemName(u8 *, u8, unkStruct_8090F58 *);
void sub_8090E14(u8 *ext_buffer, Item *slot, unkStruct_8090F58 *);
bool8 AddItemToInventory(const Item* slot);
void ConvertMoneyItemToMoney();
void AddToTeamMoney(s32 amount);
u32 GetMoneyValue(Item* slot);
u16 GetItemMoveID(u8 index);
bool8 CanSellItem(u32 id);
bool8 IsGummiItem(u8);
void ShiftItemsDownFrom(s32 start);
void ClearItemSlotAt(u32 index);
void MoveToStorage(Item *slot);
s32 CountKecleonShopItems(void);
void InitKecleonShopItem(u8 index);
BulkItem *GetKecleonShopItem(u8 index);
void FillKecleonShopGaps(void);
void SortKecleonShopInventory(void);
void ChooseKecleonShopInventory(u8 index);
bool8 AddKecleonShopItem(u8 itemIndex);
u32 CountKecleonWareItems(void);
void InitKecleonWareItem(u8 index);
BulkItem* GetKecleonWareItem(u8 index);
void FillKecleonWareGaps(void);
void SortKecleonWareInventory(void);
void ChooseKecleonWareInventory(u8 index);
bool8 AddKecleonWareItem(u8 itemIndex);
void FillInventoryGaps();
bool8 AddHeldItemToInventory(BulkItem* slot);
bool8 IsNotMoneyOrUsedTMItem(u8 id);
s32 FindItemInInventory(u8 id);
bool8 IsHMItem(u8 id);
bool8 IsEdibleItem(u8 id);
u8 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1);
bool8 IsInvalidItemReward(u8 itemID);

void RestoreHeldItem(unkStruct_8094924 *, BulkItem *);
void SaveHeldItem(unkStruct_8094924 *, BulkItem *);
void RestoreItemSlot(unkStruct_8094924 *, Item *);
void SaveItemSlot(unkStruct_8094924 *, Item *);
s32 RestoreTeamInventory(u8 *, u32);
s32 SaveTeamInventory(u8 *, u32);

#endif
