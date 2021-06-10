#ifndef ITEMS_H
#define ITEMS_H

struct Item
{
    /* 0x0 */ u8 *namePointer;
    /* 0x4 */ u32 buyPrice;
    /* 0x8 */ u32 sellPrice;
    /* 0xC */ u8 type;
    /* 0xD */ u8 icon;
    /* 0xE */ u16 fill;
    /* 0x10 */ u8 *descriptionPointer;
    /* 0x14 */ bool8 unkFood1[2];
    /* 0x16 */ u8 throwDmg;
    /* 0x17 */ u8 fill2;
    /* 0x18 */ s16 move;
    /* 0x1A */ u8 order; // Numbered order they are in storage
    /* 0x1B */ u8 unkThrow1B[2];
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 category;
    /* 0x1F */ u8 fill3;
};

enum ItemType
{
    ITEM_TYPE_THROWABLE,
    ITEM_TYPE_ROCK,
    ITEM_TYPE_BERRY_SEED,
    ITEM_TYPE_APPLE_GUMMI,
    ITEM_TYPE_HOLD_ITEM,
    ITEM_TYPE_TM,
    ITEM_TYPE_MONEY,
    ITEM_TYPE_UNUSED,
    ITEM_TYPE_MISC,
    ITEM_TYPE_ORB,
    ITEM_TYPE_LINK_BOX,
    ITEM_TYPE_USED_TM
};

enum ItemCategory
{
    ITEM_CATEGORY_NOTHING,
    ITEM_CATEGORY_THROWABLE,
    ITEM_CATEGORY_ROCKS,
    ITEM_CATEGORY_RIBBONS,
    ITEM_CATEGORY_FOOD,
    ITEM_CATEGORY_HEALING,
    ITEM_CATEGORY_CHESTNUT,
    ITEM_CATEGORY_MONEY_WISH_STONE,
    ITEM_CATEGORY_MISC,
    ITEM_CATEGORY_TM,
    ITEM_CATEGORY_LINK_BOX,
    ITEM_CATEGORY_SPECS,
    ITEM_CATEGORY_SCARFS,
    ITEM_CATEGORY_ORBS
};

void LoadItemParameters(void);
struct unkStruct_203B460 *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
u8 GetItemType(u8 index);
s32 GetItemBuyPrice(u8 itemIndex);
s32 GetItemSellPrice(u8 itemIndex);
u8 GetItemOrder(u8 itemIndex);
u8 GetItemPalette(u8 itemIndex);
u8 GetItemCategory(u8 itemIndex);
u32 GetItemUnkThrow(u8 itemIndex, u32 r1);
u8 *GetItemDescription(u8 itemIndex);
u32 GetItemUnkFood(u8 itemIndex, u32 r1);
s32 sub_8090A34(void);
bool8 sub_8090A60(u8 itemIndex);

#endif
