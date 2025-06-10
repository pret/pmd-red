#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "code_8092334.h"
#include "structs/str_items.h"
#include "structs/str_pokemon.h"
#include "structs/str_status_text.h"

extern ItemDataEntry *gItemParametersData;
extern TeamInventory *gTeamInventoryRef;

#define ITEM_SETS_RANDOM_CAP 9999
#define ITEM_SETS_SKIP_NUMBER 30000
enum
{
    RANDOM_ITEMS_SET_1 = 1,
    RANDOM_ITEMS_SET_2,
    RANDOM_ITEMS_SET_3,
    RANDOM_ITEMS_SET_4,
    RANDOM_ITEMS_SET_5,
    RANDOM_ITEMS_SET_6,
    RANDOM_ITEMS_SET_7,
    RANDOM_ITEMS_SET_8,
    RANDOM_ITEMS_SET_9,
    RANDOM_ITEMS_SET_10,
    RANDOM_ITEMS_SET_11,
    RANDOM_ITEMS_SET_12,
    RANDOM_ITEMS_SET_13,
    RANDOM_ITEMS_SET_14,
    RANDOM_ITEMS_SET_15,
    RANDOM_ITEMS_SET_KECLEON_SHOP_1,
    RANDOM_ITEMS_SET_KECLEON_WARES_1,
    RANDOM_ITEMS_SET_KECLEON_SHOP_2,
    RANDOM_ITEMS_SET_KECLEON_WARES_2,
    RANDOM_ITEMS_SET_KECLEON_SHOP_3,
    RANDOM_ITEMS_SET_KECLEON_WARES_3,
    RANDOM_ITEMS_SET_KECLEON_SHOP_4,
    RANDOM_ITEMS_SET_KECLEON_WARES_4,
    RANDOM_ITEMS_SET_24,
    RANDOM_ITEMS_SET_25,
    RANDOM_ITEMS_SET_26,
};

void LoadItemParameters(void);
TeamInventory *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
s32 GetNumberOfFilledInventorySlots(void);
bool8 IsThrowableItem(u8 id);
void ItemIdToSlot(Item *param_1,u8 id,u8 param_3);
void xxx_init_helditem_8090B08(BulkItem *param_1,u8 id);
void HeldItemToSlot(Item *param_1, BulkItem *param_2);
void SlotToHeldItem(BulkItem *held, Item *slot);
u8 GetItemCategory(u8 index);
s32 GetStackBuyValue(Item *param_1);
s32 GetStackSellValue(Item *param_1);
s32 GetStackBuyPrice(Item *param_1);
s32 GetStackSellPrice(Item *param_1);
s32 GetItemBuyPrice(u8 id);
s32 GetItemSellPrice(u8 id);
s32 GetItemOrder(u8 id);
s32 GetItemPalette(u8 id);
u32 GetItemActionType(u8 id);
u32 GetSpawnAmountRange(u8 id, u32 r1);
u8 *GetItemDescription(u8 id);
bool8 TestItemAIFlag(u8 id, u32 aiFlag);
void BufferItemName(u8 *, u8 id, unkStruct_8090F58 *);
void sub_8090E14(u8 *ext_buffer, Item *slot, const unkStruct_8090F58 *);
bool8 AddItemToInventory(const Item* slot);
void ConvertMoneyItemToMoney();
void AddToTeamMoney(s32 amount);
u32 GetMoneyValue(Item* slot);
u16 GetItemMoveID(u8 index);
bool8 CanSellItem(u32 id);
bool8 IsGummiItem(u8);
void ShiftItemsDownFrom(s32 start);
void ClearItemSlotAt(u32 index);
void MoveToStorage(Item *slot);
s32 CountKecleonShopItems(void);
void InitKecleonShopItem(u8 index);
BulkItem *GetKecleonShopItem(u8 index);
void FillKecleonShopGaps(void);
void ChooseKecleonShopInventory(u8 index);
bool8 AddKecleonShopItem(u8 itemIndex);
u32 CountKecleonWareItems(void);
void InitKecleonWareItem(u8 index);
BulkItem* GetKecleonWareItem(u8 index);
void FillKecleonWareGaps(void);
void SortKecleonWareInventory(void);
void ChooseKecleonWareInventory(u8 index);
void FillInventoryGaps(void);
bool8 AddHeldItemToInventory(BulkItem* slot);
bool8 IsNotMoneyOrUsedTMItem(u8 id);
bool8 IsNotSpecialItem(u8 id);
s32 FindItemInInventory(u8 id);
bool8 IsHMItem(u8 id);
bool8 IsEdibleItem(u8 id);
u8 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1);
bool8 IsInvalidItemReward(u8 itemID);
bool8 HasGummiItem(void);
void GetGummiItemStatBoost(PokemonStruct1* pokemon, u8 id, bool8 checkBoostFlags, Gummi *gummi);

void ReadHeldItemBits(DataSerializer *, BulkItem *);
void WriteHeldItemBits(DataSerializer *, BulkItem *);
void ReadItemSlotBits(DataSerializer *, Item *);
void WriteItemSlotBits(DataSerializer *, Item *);
s32 RestoreTeamInventory(u8 *, u32 size);
s32 SaveTeamInventory(u8 *, u32 size);






s32 GetItemPossessionCount(u8 id);
s32 WriteHighDecimal(s32, u8 *strbuf, u8);
u32 sub_80913E0(Item* slot, u32 windowId, STATUSTEXTS(statuses));
u8 GetRandomItemForSet(s32 a0, s32 a1, s32 a2);

static inline void ZeroOutItem(Item *item)
{
    item->id = 0;
    item->quantity = 0;
    item->flags = 0;
}

static inline bool8 ItemSticky(Item *item)
{
    return (item->flags & ITEM_FLAG_STICKY);
}

static inline bool8 ItemExists(Item *item)
{
    return (item->flags & ITEM_FLAG_EXISTS);
}

static inline bool8 ItemSet(Item *item)
{
    return (item->flags & ITEM_FLAG_SET);
}

static inline bool8 ItemInShop(Item *item)
{
    return (item->flags & ITEM_FLAG_IN_SHOP);
}

#endif // GUARD_ITEMS_H
