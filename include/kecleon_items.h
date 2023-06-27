#ifndef GUARD_KECLEON_ITEMS_H
#define GUARD_KECLEON_ITEMS_H

#include "team_inventory.h"
#include "text.h"
#include "menu.h"

struct unkStruct_203B210
{
    // size: 0x148
    u32 unk0;
    bool8 isKecleonItemShop; // FALSE indicates it is Kecleon TM Shop
    u32 currState;
    u32 fallbackState;
    s32 itemSellPrice;
    u32 numInventoryItemToSell;
    s32 inventoryItemSellPrice;
    struct Item soldItem;
    u8 itemShopItemIndex;
    u8 wareShopItemIndex;
    u32 soldItemInventoryIndex;
    u32 menuAction1;
    u32 menuAction2;
    u32 menuAction3;
    struct MenuItem menuItems[8];
    u16 unk74[8];
    struct MenuStruct menu;
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unkDC;
    u16 unkDE;
    u8 unkE0;
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
    struct OpenedFile **unkE4;
    struct UnkTextStruct2 unkE8[4];
};

struct unkStruct_203B224
{
    // size: 0xF4
    u32 unk0;
    u32 unk4[INVENTORY_SIZE];
    /* 0x54 */ struct MenuInputStruct input;
    u32 unk88;
    struct UnkTextStruct2 *unk8C;
    struct UnkTextStruct2 unk90[4];
    u8 unkF0[4];
};

enum KecleonStoreStates
{
    KECLEON_STORE_INIT = 0,
    KECLEON_STORE_MAIN_MENU = 1,
    KECLEON_STORE_EXIT = 4,
    KECLEON_STORE_NO_STORE_ITEMS = 5,
    KECLEON_STORE_NO_MONEY = 6,
    KECLEON_STORE_NO_ITEMS_TO_SELL = 9,
    KECLEON_STORE_TOO_MANY_ITEMS = 10,
    KECLEON_STORE_NOT_ENOUGH_MONEY = 12,
    KECLEON_STORE_CANT_SELL_ITEM = 13
};

#endif // GUARD_KECLEON_ITEMS_H
