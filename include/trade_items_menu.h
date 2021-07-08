#ifndef GUARD_TRADE_ITEMS_MENU_H
#define GUARD_TRADE_ITEMS_MENU_H

#include "text.h"
#include "item.h"

struct TradeSubStruct
{
    u8 itemIndex; // item id?
    u8 fill3[0x3];
    u32 numItems; // number of items?
};


struct TradeItemsMenu
{
    // size: 0x3A0
    u32 currMenu;
    u32 unk4;
    u32 itemMode;
    u32 linkStatus;
    u32 unk10;
    u32 numItemsToSend; // item #
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    struct UnkTextStruct2 *unk2C;
    u32 unk30;
    u32 unk34;
    u8 fill38[0x44 - 0x38];
    u32 unk44;
    u8 fill8[0x134 - 0x48];
    u32 unk134;
    u8 fill138[0x184 - 0x138];
    struct UnkTextStruct2 unk184[4];
    struct UnkTextStruct2 unk1E4[4];

    // TODO These might be structs...
    struct TradeSubStruct unk244;

    struct TradeSubStruct unk24C;

    /* 0x254 */ struct TradeSubStruct sentItem;

    /* 0x25C */ struct ItemStruct_203B460 itemToSend;

    u8 fill25F[0x3A0 - 0x260];
};


s32 UpdateTradeItemsMenu(void);
s32 CreateTradeItemsMenu(void);
void CleanTradeItemsMenu(void);

#endif
