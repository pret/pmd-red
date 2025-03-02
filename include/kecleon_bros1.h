#ifndef GUARD_KECLEON_BROS1_H
#define GUARD_KECLEON_BROS1_H

#include "file_system.h"
#include "items.h"
#include "structs/menu.h"
#include "structs/str_text.h"

enum KecleonStoreStates
{
    KECLEON_STORE_INIT = 0,
    KECLEON_STORE_MAIN_MENU,
    KECLEON_STORE_INFO,
    KECLEON_STORE_UNK3,
    KECLEON_STORE_EXIT,
    KECLEON_STORE_NO_STORE_ITEMS,
    KECLEON_STORE_NO_MONEY,
    KECLEON_STORE_TOO_MUCH_MONEY,
    KECLEON_STORE_NO_ITEMS_TO_SELL,
    KECLEON_STORE_NO_ITEMS,
    KECLEON_STORE_TOO_MANY_ITEMS,
    KECLEON_STORE_UNK11,
    KECLEON_STORE_NOT_ENOUGH_MONEY,
    KECLEON_STORE_CANT_SELL_ITEM,
    KECLEON_STORE_SELL_ITEM_TOO_MUCH_MONEY,
    KECLEON_STORE_UNK15,
    KECLEON_STORE_BUY_ITEM_MENU,
    KECLEON_STORE_BUY_ITEM_RECEIPT,
    KECLEON_STORE_UNK18,
    KECLEON_STORE_UNK19,
    KECLEON_STORE_UNK20,
    KECLEON_STORE_BUY_ITEM_INFO,
    KECLEON_STORE_BUY_ITEM,
    KECLEON_STORE_UNK23,
    KECLEON_STORE_SELL_ITEM_MENU,
    KECLEON_STORE_SELL_ITEM_RECEIPT,
    KECLEON_STORE_UNK26,
    KECLEON_STORE_UNK27,
    KECLEON_STORE_UNK28,
    KECLEON_STORE_SELL_ITEM_INFO,
    KECLEON_STORE_SELL_ITEM,
    KECLEON_STORE_SELL_ALL_ITEMS,
    KECLEON_STORE_SELL_ALL_ITEMS_RECEIPT,
};

// size: 0x148
typedef struct KecleonBrosWork1
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: KecleonBrosMode
    /* 0x4 */ bool8 isKecleonItemShop; // FALSE indicates it is Kecleon TM Shop
    /* 0x8 */ u32 currState;
    /* 0xC */ u32 fallbackState;
    /* 0x10 */ s32 itemSellPrice;
    /* 0x14 */ u32 numInventoryItemToSell;
    /* 0x18 */ s32 inventoryItemSellPrice;
    /* 0x1C */ Item soldItem;
    /* 0x20 */ u8 itemShopItemIndex;
    /* 0x21 */ u8 wareShopItemIndex;
    /* 0x24 */ u32 soldItemInventoryIndex;
    /* 0x28 */ u32 menuAction1;
    /* 0x2C */ u32 menuAction2;
    /* 0x30 */ u32 menuAction3;
    /* 0x34 */ MenuItem menuItems[8];
    u16 unk74[8];
    /* 0x84 */ MenuStruct menu;
    /* 0xD4 */ struct MonPortraitMsg monPortrait;
    struct MonPortraitMsg *monPortraitPtr;
    WindowTemplates unkE8;
} KecleonBrosWork1;

// mode corresponds to the enum: KecleonBrosMode
bool8 CreateKecleonBros(u32 mode);
void DeleteKecleonBros(void);
u32 KecleonBrosCallback(void);

#endif // GUARD_KECLEON_BROS1_H
