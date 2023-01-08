#ifndef GUARD_TEAM_INVENTORY_H
#define GUARD_TEAM_INVENTORY_H

struct TeamInventory
{
    struct Item teamItems[INVENTORY_SIZE];
    u16 teamStorage[NUMBER_OF_ITEM_IDS];
    // same type (initialized by same function):
    struct BulkItem unk230[8];
    struct BulkItem unk250[4];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

extern struct TeamInventory *gTeamInventory_203B460;

#endif
