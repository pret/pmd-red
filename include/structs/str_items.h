#ifndef GUARD_STR_ITEMS_H
#define GUARD_STR_ITEMS_H

#include "constants/item.h"

// size: R=0x20 | B=?
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
typedef struct Gummi
{
    /* 0x0 */ s16 boostAmount;
    /* 0x2 */ u16 flags;
} Gummi;

// size: R=0xC | B=0x9?
typedef struct unkStruct_8090F58
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ u8 unk8;
} unkStruct_8090F58;

// size: R=0x4 | B=0x3
typedef struct Item
{
    /* 0x0 */ u8 flags;
    /* 0x1 */ u8 quantity;
    /* 0x2 */ u8 id;
} Item;

// size: R=0x4 | B=0x2
typedef struct BulkItem
{
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 quantity;
} BulkItem;

// size: R=0x268 | B=0x23C
typedef struct TeamInventory
{
    /* R=0x0   | B=0x0   */ Item teamItems[INVENTORY_SIZE];
    /* R=0x50  | B=0x3C  */ u16 teamStorage[STORAGE_SIZE];
    /* R=0x230 | B=0x21C */ BulkItem kecleonShopItems[MAX_KECLEON_ITEM_SHOP_ITEMS];
    /* R=0x250 | B=0x22C */ BulkItem kecleonWareItems[MAX_KECLEON_WARE_SHOP_ITEMS];
    /* R=0x260 | B=0x234 */ s32 teamMoney;
    /* R=0x264 | B=0x238 */ s32 teamSavings;
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