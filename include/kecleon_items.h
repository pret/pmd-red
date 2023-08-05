#ifndef GUARD_KECLEON_ITEMS_H
#define GUARD_KECLEON_ITEMS_H

#include "file_system.h"
#include "item.h"
#include "menu.h"
#include "text.h"

// size: 0x148
struct unkStruct_203B210
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: KecleonShopMode
    /* 0x4 */ bool8 isKecleonItemShop; // FALSE indicates it is Kecleon TM Shop
    /* 0x8 */ u32 currState;
    /* 0xC */ u32 fallbackState;
    /* 0x10 */ s32 itemSellPrice;
    /* 0x14 */ u32 numInventoryItemToSell;
    /* 0x18 */ s32 inventoryItemSellPrice;
    /* 0x1C */ struct Item soldItem;
    /* 0x20 */ u8 itemShopItemIndex;
    /* 0x21 */ u8 wareShopItemIndex;
    /* 0x24 */ u32 soldItemInventoryIndex;
    /* 0x28 */ u32 menuAction1;
    /* 0x2C */ u32 menuAction2;
    /* 0x30 */ u32 menuAction3;
    /* 0x34 */ struct MenuItem menuItems[8];
    u16 unk74[8];
    /* 0x84 */ struct MenuStruct menu;
    /* 0xD4 */ struct OpenedFile *faceFile;
    /* 0xD8 */ u8 *faceData;
    u16 unkDC;
    u16 unkDE;
    u8 unkE0;
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
    struct OpenedFile **unkE4;
    struct UnkTextStruct2 unkE8[4];
};

// size: 0xA0
struct unkStruct_203B214
{
    /* 0x0 */ struct MenuInputStruct input;
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

// size: 0xF4
struct unkStruct_203B224
{
    u32 unk0;
    u32 unk4[INVENTORY_SIZE];
    /* 0x54 */ struct MenuInputStruct input;
    u32 unk88;
    struct UnkTextStruct2 *unk8C;
    struct UnkTextStruct2 unk90[4];
    u8 unkF0[4];
};

enum KecleonShopMode
{
    KECLEON_SHOP_MODE_ITEMS_AWAKE = 0,
    KECLEON_SHOP_MODE_ITEMS_ASLEEP = 1,
    KECLEON_SHOP_MODE_WARES_AWAKE = 2,
    KECLEON_SHOP_MODE_WARES_ASLEEP = 3,
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
    KECLEON_STORE_CANT_SELL_ITEM = 13,
};

// mode corresponds to the enum: KecleonShopMode
u32 DisplayKeckleonDialogueSprite(u32 mode);

#endif // GUARD_KECLEON_ITEMS_H
