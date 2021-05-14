#ifndef GUARD_TRADE_ITEMS_MENU_H
#define GUARD_TRADE_ITEMS_MENU_H

struct unkData
{
    u8 unk0[24];
};

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
    struct unkData *unk2C;
    u32 unk30;
    u32 unk34;
    u8 fill38[0x44 - 0x38];
    u32 unk44;
    u8 fill8[0x134 - 0x48];
    u32 unk134;
    u8 fill138[0x184 - 0x138];
    struct unkData unk184[3]; // guessing the size until I know
    u8 fill188[0x1E4 - 0x1CC];
    u32 unk1E4;
    u8 fill1E8[0x244 - 0x1E8];

    // TODO These might be structs...
    struct TradeSubStruct unk244;

    struct TradeSubStruct unk24C;

    struct TradeSubStruct unk254;

    u8 unk25C;
    u8 chosenNum;
    u8 chosenItem;
    u8 fill25F[0x3A0 - 0x25F];
};

#endif
