#ifndef GUARD_KECLEON_BROS1_H
#define GUARD_KECLEON_BROS1_H

#include "file_system.h"
#include "items.h"
#include "structs/menu.h"
#include "structs/str_text.h"

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
    /* 0xD4 */ OpenedFile *faceFile;
    /* 0xD8 */ u8 *faceData;
    u16 unkDC;
    u16 unkDE;
    u8 unkE0;
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
    OpenedFile **unkE4;
    UnkTextStruct2 unkE8[4];
} KecleonBrosWork1;

// mode corresponds to the enum: KecleonBrosMode
bool8 CreateKecleonBros(u32 mode);
void DeleteKecleonBros(void);
u32 KecleonBrosCallback(void);

#endif // GUARD_KECLEON_BROS1_H