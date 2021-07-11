#ifndef GUARD_TEAM_INVENTORY_H
#define GUARD_TEAM_INVENTORY_H

#include "item.h"

struct subStruct_203B460
{
    u8 unk0;
    u8 unk1;
};

struct TeamInventory
{
    struct ItemSlot teamItems[INVENTORY_SIZE];
    u16 teamStorage[NUMBER_OF_ITEM_IDS];
    struct subStruct_203B460 unk230[8];  // this is probably actually the same struct as ItemSlot_ALT (see sub_80919FC)
    struct subStruct_203B460 unk250[4]; // TODO: idk if this is identical struct or not.. Ghidra says sizes are same
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

#endif
