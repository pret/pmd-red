#ifndef GUARD_TEAM_INVENTORY_H
#define GUARD_TEAM_INVENTORY_H

#define MAX_KECLEON_ITEM_SHOP_ITEMS 8
#define MAX_KECLEON_WARE_SHOP_ITEMS 4

struct TeamInventory
{
    struct Item teamItems[INVENTORY_SIZE];
    u16 teamStorage[NUMBER_OF_ITEM_IDS];
    struct BulkItem kecleonShopItems[MAX_KECLEON_ITEM_SHOP_ITEMS];
    struct BulkItem kecleonWareItems[MAX_KECLEON_WARE_SHOP_ITEMS];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

extern struct TeamInventory *gTeamInventory_203B460;

#endif
