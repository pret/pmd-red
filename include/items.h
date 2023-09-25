#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "code_8092334.h"
#include "structs/str_items.h"
#include "structs/str_pokemon.h"
#include "structs/subStruct_203B240.h"

extern TeamInventory *gTeamInventoryRef;

void LoadItemParameters(void);
TeamInventory *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
s32 GetNumberOfFilledInventorySlots(void);
bool8 IsThrowableItem(u8 id);
void xxx_init_itemslot_8090A8C(Item *param_1,u8 id,u8 param_3);
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
u8 GetItemPalette(u8 id);
u32 GetItemActionType(u8 id);
u32 GetSpawnAmountRange(u8 id, u32 r1);
u8 *GetItemDescription(u8 id);
bool8 GetItemAIFlag(u8 id, u32 r1);
void BufferItemName(u8 *, u8 id, unkStruct_8090F58 *);
void sub_8090E14(u8 *ext_buffer, Item *slot, unkStruct_8090F58 *);
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
void SortKecleonShopInventory(void);
void ChooseKecleonShopInventory(u8 index);
bool8 AddKecleonShopItem(u8 itemIndex);
u32 CountKecleonWareItems(void);
void InitKecleonWareItem(u8 index);
BulkItem* GetKecleonWareItem(u8 index);
void FillKecleonWareGaps(void);
void SortKecleonWareInventory(void);
void ChooseKecleonWareInventory(u8 index);
bool8 AddKecleonWareItem(u8 itemIndex);
void FillInventoryGaps();
bool8 AddHeldItemToInventory(BulkItem* slot);
bool8 IsNotMoneyOrUsedTMItem(u8 id);
s32 FindItemInInventory(u8 id);
bool8 IsHMItem(u8 id);
bool8 IsEdibleItem(u8 id);
u8 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1);
bool8 IsInvalidItemReward(u8 itemID);
bool8 HasGummiItem(void);
void GetGummiItemStatBoost(PokemonStruct1* pokemon, u8 id, bool8 checkBoostFlags, Gummi *gummi);

void RestoreHeldItem(unkStruct_8094924 *, BulkItem *);
void SaveHeldItem(unkStruct_8094924 *, BulkItem *);
void RestoreItemSlot(unkStruct_8094924 *, Item *);
void SaveItemSlot(unkStruct_8094924 *, Item *);
s32 RestoreTeamInventory(u8 *, u32 size);
s32 SaveTeamInventory(u8 *, u32 size);






s32 sub_8090FEC(s32, u8 *strbuf, u8);
u32 sub_80913E0(Item *slot, u32, struct subStruct_203B240 **);

#endif // GUARD_ITEMS_H