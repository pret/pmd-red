#ifndef GUARD_STR_ITEMS_H
#define GUARD_STR_ITEMS_H

#include "constants/item.h"

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

// TODO: These should be in constants/
// Not doing it now since we cannot include enums in the constants file due to being used by the data_item and data_monster assemblers

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

#endif // GUARD_STR_ITEMS_H