#ifndef GUARD_TRADE_ITEMS_MENU_H
#define GUARD_TRADE_ITEMS_MENU_H

#include "structs/str_text.h"
#include "items.h"
#include "structs/menu.h"

// 11 was another saving too?
enum TradeItemsScreens
{
    TRADE_ITEMS_MAIN_MENU,
    TRADE_ITEMS_SEND_ITEM,
    TRADE_ITEMS_SEND_ITEM_SELECTION,
    TRADE_ITEMS_SEND_ITEM_POPUP_MENU,
    TRADE_ITEMS_SEND_ITEM_NUMBER,
    TRADE_ITEMS_ITEM_INFO,
    TRADE_ITEMS_SEND_ITEM_CONFIRM,
    TRADE_ITEMS_RECEIVE_ITEM,
    // 8
    TRADE_ITEMS_IN_COMMUNICATION = 9,
    // 10 - 14
    TRADE_ITEMS_PREPARE_TRADE_SAVING = 15,
    // 16
    TRADE_ITEMS_PRE_EXIT = 17,
    TRADE_ITEMS_EXIT,
};

enum TradeItemsModes
{
    TRADE_ITEMS_SEND_ITEM_MODE,
    TRADE_ITEMS_RECEIVE_ITEM_MODE
};

struct TradeSubStruct
{
    union ItemIdx {
        u8 id; // item id?
        u32 id_u32;
    } itemIdx;
    u32 quantity; // number of items?
};

// size: 0x3A0
struct TradeItemsMenu
{
    u32 currMenu;
    u32 fallbackState;
    u32 itemMode;
    u32 linkStatus;
    u32 unk10;
    unkStructFor8013AA0 unk14;
    MenuStruct unk44[4];
    UnkTextStruct2 unk184[4];
    UnkTextStruct2 unk1E4[4];

    // TODO These might be structs...
    struct TradeSubStruct unk244;

    struct TradeSubStruct unk24C;

    /* 0x254 */ struct TradeSubStruct sentItem;

    /* 0x25C */ Item itemToSend;

    u8 fill25F[0x3A0 - 0x260];
};

s32 UpdateTradeItemsMenu(void);
s32 CreateTradeItemsMenu(void);
void CleanTradeItemsMenu(void);

#endif // GUARD_TRADE_ITEMS_MENU_H