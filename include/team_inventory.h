#ifndef GUARD_TEAM_INVENTORY_H
#define GUARD_TEAM_INVENTORY_H

struct TeamInventory
{
    struct ItemSlot teamItems[INVENTORY_SIZE];
    u16 teamStorage[NUMBER_OF_ITEM_IDS];
    // same type (initialized by same function):
    struct ItemSlot_ALT unk230[8];
    struct ItemSlot_ALT unk250[4];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

#endif
