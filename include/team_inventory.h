#ifndef GUARD_TEAM_INVENTORY_H
#define GUARD_TEAM_INVENTORY_H

#define MAX_KECLEON_ITEM_SHOP_ITEMS 8
#define MAX_KECLEON_WARE_SHOP_ITEMS 4

#include "item.h"

// size: 0x268
struct TeamInventory
{
    /* 0x0 */ struct Item teamItems[INVENTORY_SIZE];
    /* 0x50 */ u16 teamStorage[STORAGE_SIZE];
    /* 0x230 */ struct BulkItem kecleonShopItems[MAX_KECLEON_ITEM_SHOP_ITEMS];
    /* 0x250 */ struct BulkItem kecleonWareItems[MAX_KECLEON_WARE_SHOP_ITEMS];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ s32 teamSavings;
};

// Declared in items.c
extern struct TeamInventory *gTeamInventoryRef;

#define MAX_TEAM_MONEY 99999
#define MAX_TEAM_SAVINGS 9999999

#endif
