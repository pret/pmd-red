#include "global.h"
#include "file_system.h"
#include "item.h"
#include "team_inventory.h"
#include "random.h"
#include "pokemon.h"
#include "subStruct_203B240.h"

#include <stddef.h>

extern struct TeamInventory *gTeamInventory_203B460;
extern struct TeamInventory gUnknown_20389A8;
extern struct FileArchive gSystemFileArchive;
extern struct unkStruct_203B45C *gRecruitedPokemonRef;
extern const char gUnknown_8109764;
extern const char gUnknown_8109794[];
extern const char gUnknown_81097A4[];
extern s32 gUnknown_81097B0[];
extern u8 gUnknown_81097C4[];
extern u16 gGummiStatBoostLUT[];
extern u8 gUnknown_202DE58[0x58];
extern u32 gUnknown_202DE30;
extern u8* gPtrTypeText;  // ptr to "Type\0"
extern u8* gPtrPPD0Text;  // ptr to "PP $d0 \0"
extern u32 gUnknown_810A3F0[100];
extern u32 gUnknown_81097E8[4];  // some sort of lookup table (16, 18, 20, 22)
extern u32 gUnknown_81097F8[4];  // some sort of lookup table (17, 19, 21, 23)
extern u32 gUnknown_810AF50[];
extern u8 gUnknown_8108F64[0x3f][32];  // some sort of bit lookup table
extern s16 gTypeGummiIQBoost[0x12][NUMBER_OF_GUMMIS];

EWRAM_DATA struct OpenedFile *gItemParametersFile;
EWRAM_DATA struct Item *gItemParametersData;

extern u8 GetItemType(u8);
extern u32 GetItemUnkThrow(u8, u32);
extern void ExpandPlaceholdersBuffer(u8 *, const u8 *, ...);
extern s32 sub_8090FEC(s32 a1, u8* a2, u8 a3);
extern void sub_80073B8(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);
extern void sub_8092A88(void*, u16);  // first arg is some struct
extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u32 sub_8092B00(void*);
extern u8* GetUnformattedTypeString(s16);
extern u32 sub_8092BF4(void*);
extern void sub_80073E0(u32);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);
extern s32 sub_8091E94(s32 a1, s32 a2, s32 a3);
extern void xxx_sort_inv_unk230_80918EC();
bool8 xxx_insert_unk250_8091C1C(u8);

void LoadItemParameters(void)
{
  gTeamInventory_203B460 = &gUnknown_20389A8;
  gItemParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_8109764,&gSystemFileArchive);
  gItemParametersData = (struct Item *) gItemParametersFile->data;
}

struct TeamInventory *GetMoneyItemsInfo(void)
{
    return &gUnknown_20389A8;
}

void InitializeMoneyItems(void)
{
  s32 i;

  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    gTeamInventory_203B460->teamItems[i].itemFlags = 0;
  }

  for(i = 0; i < 0xF0; i++)
  {
    gTeamInventory_203B460->teamStorage[i] = 0;
  }

  for(i = 0; i < 8; i++)
  {
    xxx_init_unk230_substruct(i);
  }
  gTeamInventory_203B460->teamMoney = 0;
  gTeamInventory_203B460->teamSavings = 0;
}

s32 GetNumberOfFilledInventorySlots(void)
{
  s32 i;
  s32 count;

  count = 0;
  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    if ((gTeamInventory_203B460->teamItems[i].itemFlags & ITEM_FLAG_EXISTS) != 0) {
      count++;
    }
  }
  return count;
}

bool8 IsThrowableItem(u8 itemIndex)
{
  if ((GetItemType(itemIndex) != ITEM_TYPE_THROWABLE) && (GetItemType(itemIndex) != ITEM_TYPE_ROCK))
    return FALSE;
  else
    return TRUE;
}

void xxx_init_itemslot_8090A8C(struct ItemSlot *slot, u8 itemIndex, u8 param_3)
{
  u32 uVar3;
  u32 uVar4;

  if (itemIndex != ITEM_ID_NOTHING) {
    slot->itemFlags = ITEM_FLAG_EXISTS;
    slot->itemIndex = itemIndex;
    if (IsThrowableItem(itemIndex)) {
        uVar3 = GetItemUnkThrow(itemIndex, 0);
        uVar4 = GetItemUnkThrow(itemIndex, 1);
        slot->numItems = RandomRange(uVar3, uVar4);
    }
    else if (GetItemType(itemIndex) == ITEM_TYPE_MONEY)
        slot->numItems  = 1;
    else
        slot->numItems  = 0;

    if (param_3 != 0)
        slot->itemFlags |= ITEM_FLAG_STICKY;

  }
  else {
    slot->itemFlags = 0;
    slot->itemIndex = ITEM_ID_NOTHING;
    slot->numItems  = 0;
  }
}

void xxx_init_helditem_8090B08(struct HeldItem *held, u8 itemIndex)
{
  u32 uVar2;
  u32 uVar3;

  if (itemIndex != ITEM_ID_NOTHING) {
    held->itemIndex = itemIndex;
    if (IsThrowableItem(itemIndex)) {
        uVar2 = GetItemUnkThrow(itemIndex,0);
        uVar3 = GetItemUnkThrow(itemIndex,1);
        held->numItems = RandomRange(uVar2, uVar3);
    }
    else if (GetItemType(itemIndex) == ITEM_TYPE_MONEY)
        held->numItems = 1;
    else
        held->numItems = 0;
  }
  else {
    held->itemIndex = 0;
    held->numItems = 0;
  }
}

void HeldItemToSlot(struct ItemSlot *slot, struct HeldItem *held)
{
    u8 is_throwable;

    if(held->itemIndex != ITEM_ID_NOTHING)
    {
        slot->itemFlags = ITEM_FLAG_EXISTS;
        slot->itemIndex = held->itemIndex;
        is_throwable = IsThrowableItem(slot->itemIndex);
        if(is_throwable != 0 || GetItemType(slot->itemIndex) == ITEM_TYPE_MONEY)
            slot->numItems = held->numItems;
        else if(slot->itemIndex == ITEM_ID_USED_TM)
            slot->numItems = held->numItems;
        else
            slot->numItems = 0;
    }
    else
    {
        slot->itemIndex = ITEM_ID_NOTHING;
        slot->numItems = 0;
        slot->itemFlags = 0;
    }
}

void SlotToHeldItem(struct HeldItem *held,struct ItemSlot *slot)
{
  if ((slot->itemFlags & ITEM_FLAG_EXISTS) != 0) {
    held->itemIndex = slot->itemIndex;
    held->numItems = slot->numItems;
  }
  else {
    held->itemIndex = ITEM_ID_NOTHING;
  }
}

u8 GetItemType(u8 index)
{
    return gItemParametersData[index].type;
}

s32 GetStackBuyValue(struct ItemSlot *param_1)
{
  if (param_1->itemIndex == ITEM_ID_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 GetStackSellValue(struct ItemSlot *param_1)
{
  if (param_1->itemIndex == ITEM_ID_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].sellPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].sellPrice;
    }
  }
}

s32 GetStackBuyPrice(struct ItemSlot *param_1)
{
  if (!CanSellItem(param_1->itemIndex)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].buyPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].buyPrice;
    }
  }
}

s32 GetStackSellPrice(struct ItemSlot *param_1)
{
  if (!CanSellItem(param_1->itemIndex)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->itemIndex)) {
      return gItemParametersData[param_1->itemIndex].sellPrice * param_1->numItems;
    }
    else {
      return gItemParametersData[param_1->itemIndex].sellPrice;
    }
  }
}

s32 GetItemBuyPrice(u8 itemIndex)
{
    return gItemParametersData[itemIndex].buyPrice;
}

s32 GetItemSellPrice(u8 itemIndex)
{
    return gItemParametersData[itemIndex].sellPrice;
}

s32 GetItemOrder(u8 itemIndex)
{
    return gItemParametersData[itemIndex].order;
}

u8 GetItemPalette(u8 itemIndex)
{
    return gItemParametersData[itemIndex].palette;
}

u8 GetItemCategory(u8 itemIndex)
{
    return gItemParametersData[itemIndex].category;
}

u32 GetItemUnkThrow(u8 itemIndex, u32 r1)
{
    return gItemParametersData[itemIndex].unkThrow1B[r1];
}

u8 *GetItemDescription(u8 itemIndex)
{
    return gItemParametersData[itemIndex].descriptionPointer;
}

u32 GetItemUnkFood(u8 itemIndex, u32 r1)
{
    return gItemParametersData[itemIndex].unkFood1[r1];
}

void sub_8090DC4(void* param_1,u8 itemIndex, struct unkStruct_8090F58* param_3)
{
  char acStack104 [80];
  struct ItemSlot unkItem;

  strncpy(acStack104,gItemParametersData[itemIndex].namePointer,0x50);
  xxx_init_itemslot_8090A8C(&unkItem,itemIndex,0);
  unkItem.numItems = 1;
  sub_8090F58(param_1,acStack104,&unkItem,param_3);
}

extern const u8 gUnknown_8109770[];
extern const u8 gUnknown_8109778[];
extern const u8 gUnknown_810977C[];
extern const u8 gUnknown_8109784[];
extern const u8 gUnknown_810978C[];

void sub_8090E14(u8* ext_buffer, struct ItemSlot* slot, struct unkStruct_8090F58* a3) {
  s32 unk8 = 0;
  u8 buffer[80];

  if (a3) {
    unk8 = a3->unk8 != 0;
  }

  if (GetItemType(slot->itemIndex) == ITEM_TYPE_THROWABLE) {
    // I feel like these labels might actually be there...
    if (unk8) {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109770, gItemParametersData[slot->itemIndex].namePointer, slot->numItems);
    }
    else {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109778, gItemParametersData[slot->itemIndex].namePointer);
    }
  }
  else if (GetItemType(slot->itemIndex) == ITEM_TYPE_ROCK) {
    if (unk8) {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109770, gItemParametersData[slot->itemIndex].namePointer, slot->numItems);
    }
    else {
      ExpandPlaceholdersBuffer(buffer, gUnknown_8109778, gItemParametersData[slot->itemIndex].namePointer);
    }
  }
  else if (slot->itemIndex == 105) {
    ExpandPlaceholdersBuffer(buffer, gUnknown_810977C, GetMoneyValue(slot));
  }
  else {
    strncpy(buffer, gItemParametersData[slot->itemIndex].namePointer, 80);
  }

  if (slot->itemFlags & ITEM_FLAG_STICKY) {
    ExpandPlaceholdersBuffer(ext_buffer, gUnknown_8109784, buffer);
    strncpy(buffer, ext_buffer, 80);
  }

  if (a3) {
    if (a3->unk4 && (slot->itemFlags & ITEM_FLAG_SET)) {
      ExpandPlaceholdersBuffer(ext_buffer, gUnknown_810978C, buffer);
      strncpy(buffer, ext_buffer, 80);
    }
    if ((*(u32*)a3 == 1) || (*(u32*)a3 == 3)) {
        if (slot->itemFlags & ITEM_FLAG_FOR_SALE) {
          sub_8090F58(ext_buffer, buffer, slot, a3);
          return;
        }
      strncpy(ext_buffer, buffer, 80);
      return;
    }
  }
  else {
    strncpy(ext_buffer, buffer, 80);
    return;
  }

  sub_8090F58(ext_buffer, buffer, slot, a3);
  return;
}

void sub_8090F58(void* a1, u8 *a2, struct ItemSlot *slot, struct unkStruct_8090F58* a4) {
  u32 unk0;
  s32 value;
  u8 buffer[40];

  if (!a4) {
    strncpy(a1, a2, 80);
    return;
  }
  else {
    unk0 = a4->unk0;
    switch (unk0) {
      case 1:
      case 2:
        value = GetStackBuyValue(slot);
        break;
      case 3:
      case 4:
        value = GetStackSellValue(slot);
        break;
      default:
        value = 0;
        break;
    }

    if (!value) {
      strncpy(a1, a2, 80);
      return;
    }
  }

  if (a4->unk6) {
    sub_8090FEC(value, buffer, 1);
    ExpandPlaceholdersBuffer(a1, gUnknown_8109794, a2, a4->unk6, buffer);
  }
  else {
    sub_8090FEC(value, buffer, 0);
    ExpandPlaceholdersBuffer(a1, gUnknown_81097A4, a2, buffer);
  }
}

s32 sub_8090FEC(s32 a1, u8* strbuf, u8 a3)
{
  s32 i, count;
  s32 cond = 0;

  count = 0;
  for (i = 0; i < 5; i++) {
    s32 div;

    div = 0;
    while (a1 >= gUnknown_81097B0[i]) {
        a1 -= gUnknown_81097B0[i];
        div++;
    }

    if (div > 9) {
      div = 9;
    }

    if (div) {
        cond = 1;
        *strbuf++ = gUnknown_81097C4[2 * div];
        *strbuf++ = (gUnknown_81097C4 + 1)[2 * div];  // weird staggered arrays...
        count++;
    }
    else if (cond) {
        *strbuf++ = gUnknown_81097C4[0];
        *strbuf++ = (gUnknown_81097C4 + 1)[0];  // weird staggered arrays...
        count++;
    }
    else if (a3) {
        *strbuf++ = 96;  // ` character?
    }
  }

  *strbuf++ = gUnknown_81097C4[2 * a1];
  *strbuf   = (gUnknown_81097C4 + 1)[2 * a1];
  count += 1;
  strbuf[1] = 0;  // null termination
  return count;
}

void FillInventoryGaps()
{
  // fill inventory gaps
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < INVENTORY_SIZE) {
      if (slot_checking[gTeamInventory_203B460->teamItems].itemFlags & ITEM_FLAG_EXISTS) {
        break;
      }
      // find next empty slot
      slot_checking++;
    }

    if (slot_checking == INVENTORY_SIZE) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventory_203B460->teamItems[last_filled] = gTeamInventory_203B460->teamItems[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < INVENTORY_SIZE; last_filled++) {
      struct ItemSlot *slot;
#ifdef NONMATCHING
      slot = &gTeamInventory_203B460->teamItems[last_filled];
#else
      size_t offs = last_filled << 2;
      size_t _slot = offs;
      _slot += (size_t)gTeamInventory_203B460->teamItems;
      slot = (struct ItemSlot*)_slot; // &gTeamInventory_203B460->teamItems[end];
#endif
      slot->itemIndex = 0;
      slot->numItems = 0;
      slot->itemFlags = 0;
  }
}

s32 FindItemInInventory(u8 itemIndex)
{
  s32 i;
  for (i = 0; i < INVENTORY_SIZE; i++) {
    if ((gTeamInventory_203B460->teamItems[i].itemFlags & ITEM_FLAG_EXISTS) && (gTeamInventory_203B460->teamItems[i].itemIndex == itemIndex)) {
      return i;
    }
  }
  return -1;
}

s32 GetItemCountInInventory(u8 _itemIndex)
{
#ifdef NONMATCHING
  s32 count = 0;
  s32 i;
  for (i = 0; i < INVENTORY_SIZE; i++) {
    if ((gTeamInventory_203B460->teamItems[i].unk0 & 1) && (gTeamInventory_203B460->teamItems[i].itemIndex == _itemIndex)) {
      count++;
    }
  }
  return count;
#else
  // have to do hacky stuff to fix initialization order of r6 and r2
  u32 itemIndex = _itemIndex;
  s32 count = 0;
  struct ItemSlot *slot = gTeamInventory_203B460->teamItems;
  s32 one = 1;
  s32 i = 19;

  do {
    register u32 unk0 asm("r1") = slot->itemFlags;
    u32 bottom_bit = one;
    bottom_bit &= unk0;
    if (bottom_bit && (slot->itemIndex == itemIndex)) {
      count++;
    }
    slot++;
  } while(--i >= 0);
  return count;
#endif
}

s32 GetItemPossessionCount(u8 itemIndex)
{
  s32 item_count = GetItemCountInInventory(itemIndex);
  s32 i = 0;

  struct unkStruct_203B45C *_gRecruitedPokemonRef = gRecruitedPokemonRef;
  for (i = 0; i < NUM_SPECIES; i++) {
     struct PokemonStruct* pokemon = &_gRecruitedPokemonRef->pokemon[i];
    if ((1 & pokemon->unk0)
          && ((pokemon->unk0 >> 1) % 2)
          && (pokemon->heldItem.itemIndex != ITEM_ID_NOTHING)
          && (pokemon->heldItem.itemIndex == itemIndex)) {
      item_count++;
    }
  }
  return item_count;
}

void ShiftItemsDownFrom(s32 start)
{
  s32 i, j;
  for (i = start, j = start + 1; i < 19; i++, j++) {
    gTeamInventory_203B460->teamItems[i] = gTeamInventory_203B460->teamItems[j];
  }
  gTeamInventory_203B460->teamItems[19].itemIndex = 0;
  gTeamInventory_203B460->teamItems[19].itemFlags = 0;
}

void ClearItemSlotAt(u32 index)
{
  gTeamInventory_203B460->teamItems[index].itemIndex = ITEM_ID_NOTHING;
  gTeamInventory_203B460->teamItems[index].itemFlags = 0;
}

bool8 sub_809124C(u8 itemIndex, u8 param_3)
{
  struct ItemSlot temp;
  xxx_init_itemslot_8090A8C(&temp, itemIndex, param_3);
  return AddItemToInventory(&temp);
}

bool8 sub_8091274(struct HeldItem* slot)
{
  struct ItemSlot temp;

  HeldItemToSlot(&temp, slot);
  return AddItemToInventory(&temp);
}

bool8 AddItemToInventory(const struct ItemSlot* slot)
{
  s32 i;

  // try to add item to inventory, return 1 if failed
  for (i = 0; i < INVENTORY_SIZE; i++) {
    UNUSED struct ItemSlot* current = &gTeamInventory_203B460->teamItems[i];
    if (!(i[gTeamInventory_203B460->teamItems].itemFlags & ITEM_FLAG_EXISTS)) {
      gTeamInventory_203B460->teamItems[i] = *slot;
      return FALSE;
    }
  }
  return TRUE;
}

void ConvertMoneyItemToMoney()
{
  s32 i = 0;

  do {
    UNUSED struct TeamInventory * _gTeamInventory_203B460 = gTeamInventory_203B460;
    UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[i]);

    struct ItemSlot* current_slot = &gTeamInventory_203B460->teamItems[i];
    if ((current_slot->itemFlags & ITEM_FLAG_EXISTS) && (current_slot->itemIndex == ITEM_ID_POKE)) {
      u32 result;

      result = GetMoneyValue(current_slot);
      AddToTeamMoney(result);
      current_slot->itemIndex = 0;
      current_slot->numItems = 0;
      current_slot->itemFlags = 0;
    }
  } while (++i < INVENTORY_SIZE);
  FillInventoryGaps();

  i = 0;
  do {
    s32 lowest_index = -1;
    UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[i]);

    bool8 item_occupied = i[gTeamInventory_203B460->teamItems].itemFlags & ITEM_FLAG_EXISTS;
    s32 next = i + 1;

    if (item_occupied) {
      s32 lowest_order = GetItemOrder(gTeamInventory_203B460->teamItems[i].itemIndex);
      s32 j;

      // find next lowest
      for (j = next; j < INVENTORY_SIZE; j++) {
        UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[j]);
        if ((j[gTeamInventory_203B460->teamItems].itemFlags & ITEM_FLAG_EXISTS) && (lowest_order > GetItemOrder(gTeamInventory_203B460->teamItems[j].itemIndex))) {
          lowest_index = j;
          lowest_order = GetItemOrder(gTeamInventory_203B460->teamItems[j].itemIndex);
        }
      }

      if (lowest_index >= 0) {
        // swap the slots
        struct ItemSlot current = gTeamInventory_203B460->teamItems[i];
        gTeamInventory_203B460->teamItems[i] = gTeamInventory_203B460->teamItems[lowest_index];
        gTeamInventory_203B460->teamItems[lowest_index] = current;
      }
    }
  } while (++i < INVENTORY_SIZE);
  FillInventoryGaps();
}

void AddToTeamMoney(s32 amount)
{
  s32 clamped_money;
  gTeamInventory_203B460->teamMoney += amount;

  // clamp money
  clamped_money = 99999;
  if (gTeamInventory_203B460->teamMoney <= 99999) {
    if (gTeamInventory_203B460->teamMoney >= 0) {
      return;
    }
    clamped_money = 0;
  }
  gTeamInventory_203B460->teamMoney = clamped_money;
}

u16 GetItemMove(u8 index)
{
  return gItemParametersData[index].move;
}

u32 sub_80913E0(struct ItemSlot* slot, u32 a2, struct subStruct_203B240 ** a3)
{
  u8 buffer88[88];  // some struct

  GetItemDescription(slot->itemIndex);
  sub_8090DC4(buffer88, slot->itemIndex, 0);
  if (slot->itemIndex == ITEM_ID_USED_TM) {
    // empty TM
    sub_8090DC4(&gUnknown_202DE58, (u8)(slot->numItems + 125), 0);
  }
  sub_80073B8(a2);
  xxx_format_and_draw(16, 0, buffer88, a2, 0);

  xxx_format_and_draw(8, 24, GetItemDescription(slot->itemIndex), a2, 0);
  if (GetItemType(slot->itemIndex) == ITEM_TYPE_TM) {
    u8* buffer8 = buffer88 + 0x50;  // field in struct
    u16 move = GetItemMove(slot->itemIndex);
    u8 moves_data;
    u8* typestring;
    u32 result;

    sub_8092A88(buffer8, move);
    sub_80078A4(a2, 4, 82, 200, 7);
    xxx_format_and_draw(4, 84, gPtrTypeText, a2, 0);
    moves_data = sub_8092B00(buffer8);
    typestring = GetUnformattedTypeString(moves_data);
    xxx_format_and_draw(64, 84, typestring, a2, 0);
    result = sub_8092BF4(buffer8);
    gUnknown_202DE30 = result;
    xxx_format_and_draw(128, 84, gPtrPPD0Text, a2, 0);
  }

  sub_80073E0(a2);
  return sub_8097DF0(GetItemDescription(slot->itemIndex), a3);
}

bool8 CanSellItem(u32 id)
{
  u8 id_;
  id = (u8)id;
  id_ = id;

  if((id != ITEM_ID_NOTHING)
      && (id != ITEM_ID_POKE)
      && (id != ITEM_ID_ROCK_PART)
      && (id != ITEM_ID_ICE_PART)
      && (id != ITEM_ID_STEEL_PART)
      && (id != ITEM_ID_MUSIC_BOX)
      && (GetItemSellPrice(id_))
      && (GetItemBuyPrice(id_))) {
          return TRUE;
    }
    return FALSE;
}

bool8 IsNotMoneyOrUsedTMItem(u8 id)
{
  if (id == ITEM_ID_NOTHING) {
    return FALSE;
  }
  else if (id == ITEM_ID_POKE) {
    return FALSE;
  }
  else if (id == ITEM_ID_USED_TM) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsNotSpecialItem(u8 id)
{
  if (id == ITEM_ID_NOTHING) {
    return FALSE;
  }
  else if (id == ITEM_ID_POKE) {
    return FALSE;
  }
  else if (id == ITEM_ID_ROCK_PART) {
    return FALSE;
  }
  else if (id == ITEM_ID_ICE_PART) {
    return FALSE;
  }
  else if (id == ITEM_ID_STEEL_PART) {
    return FALSE;
  }
  else if (id == ITEM_ID_MUSIC_BOX) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsEdibleItem(u8 id)
{
  if (!((GetItemType(id) == ITEM_TYPE_BERRY_SEED) || (GetItemType(id) == ITEM_TYPE_APPLE_GUMMI))) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsHMItem(u8 id)
{
  if (id == ITEM_ID_CUT) {
    return TRUE;
  }
  else if (id == ITEM_ID_FLY) {
    return TRUE;
  }
  else if (id == ITEM_ID_SURF) {
    return TRUE;
  }
  else if (id == ITEM_ID_STRENGTH) {
    return TRUE;
  }
  else if (id == ITEM_ID_FLASH) {
    return TRUE;
  }
  else if (id == ITEM_ID_ROCK_SMASH) {
    return TRUE;
  }
  else if (id == ITEM_ID_WATERFALL) {
    return TRUE;
  }
  else if (id == ITEM_ID_DIVE) {
    return TRUE;
  }
  return FALSE;
}

u32 GetMoneyValue(struct ItemSlot* slot)
{
  return gUnknown_810A3F0[slot->numItems];
}

u32 GetMoneyValueHeld(struct HeldItem* slot)
{
  // potentially different slot type (used for held item)
  return gUnknown_810A3F0[slot->numItems];
}

void GetGummiItemStatBoost(struct PokemonStruct* pokemon, u8 itemIndex, u8 a3, struct unkStruct_80915F4* a4)
{
  // item stat buff?
  s8 result;

  a4->unk0 = (u16)-1;
  a4->unk2 = 0;
  result = IsGummiItem(itemIndex);
  if (result) {
    u8 pokemon_type_0 = GetPokemonType(pokemon->speciesNum, 0);
    u8 pokemon_type_1 = GetPokemonType(pokemon->speciesNum, 1);
    u32 gummi_index = itemIndex - ITEM_ID_WHITE_GUMMI + 1;
    s32 value0;
    s32 value1;
    s32 diff;
    u16 boost_amount;

    value0 = gTypeGummiIQBoost[pokemon_type_0][gummi_index];
    value1 = gTypeGummiIQBoost[pokemon_type_1][gummi_index];
    diff  = pokemon->IQ;

    pokemon->IQ += value0 + value1;
    diff = pokemon->IQ - diff;
    if (pokemon->IQ <= 0) {
      pokemon->IQ = 1;
    }
    if (pokemon->IQ > 999) {
      pokemon->IQ = 999;
    }

    boost_amount = 0;
    if (diff <= 8) {
      boost_amount = 1;
      if (diff <= 4) {
        boost_amount = 3;
        if (diff > 2) {
          boost_amount = 2;
        }
      }
    }
    a4->unk0 = boost_amount;
    if (!a3) {
      u16 boost_flags;
      if (!boost_amount && RandomCapped(16) == 10) {
        // supa gummi (all stats boost)
        boost_flags = 0xf;
      }
      else {
        s32 random_index = RandomCapped(4);
        u16* table = gGummiStatBoostLUT;
        boost_flags = table[random_index];
      }

      a4->unk2 = boost_flags;
      boost_flags = a4->unk2;
      if (a4->unk2 & 1) {
        if (pokemon->offense.att[OFFENSE_NRM] < 255) {
          pokemon->offense.att[OFFENSE_NRM]++;
        }
        else {
          // fix operand order
          u16 unk2 = a4->unk2;
          unk2 &= ~1;
          a4->unk2 &= unk2;
        }
      }
      if (a4->unk2 & 2) {
        if (pokemon->offense.att[OFFENSE_SP] < 255) {
          pokemon->offense.att[OFFENSE_SP]++;
        }
        else {
          a4->unk2 &= ~2;
        }
      }
      if (a4->unk2 & 4) {
        if (pokemon->offense.def[OFFENSE_NRM] < 255) {
          pokemon->offense.def[OFFENSE_NRM]++;
        }
        else {
          a4->unk2 &= ~4;
        }
      }
      if (a4->unk2 & 8) {
        if (pokemon->offense.def[OFFENSE_SP] < 255) {
          pokemon->offense.def[OFFENSE_SP] ++;
        }
        else {
          a4->unk2 &= ~8;
        }
      }
    }
  }
}

bool8 IsGummiItem(u8 itemIndex)
{
  if (itemIndex < ITEM_ID_WHITE_GUMMI) {
    return FALSE;
  }
  if (itemIndex > ITEM_ID_SILVER_GUMMI) {
    return FALSE;
  }
  return TRUE;
}

bool8 HasGummiItem()
{
  s32 i;
  for (i = 0; i < INVENTORY_SIZE; i++) {
    UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[i]);
    if ((i[gTeamInventory_203B460->teamItems].itemFlags & ITEM_FLAG_EXISTS) && IsGummiItem(i[gTeamInventory_203B460->teamItems].itemIndex)) {
      return TRUE;
    }
  }
  return FALSE;
}

void MoveToStorage(struct ItemSlot* slot)
{
  if (IsThrowableItem(slot->itemIndex)) {
    gTeamInventory_203B460->teamStorage[slot->itemIndex] += slot->numItems;
  }
  else {
    gTeamInventory_203B460->teamStorage[slot->itemIndex]++;
  }

  if (gTeamInventory_203B460->teamStorage[slot->itemIndex] > 999) {
    gTeamInventory_203B460->teamStorage[slot->itemIndex] = 999;
  }
}

s32 xxx_count_inv_unk230()
{
  s32 i;
  s32 counter = 0;
  for (i = 0; i < 8; i++) {
    if (gTeamInventory_203B460->unk230[i].itemIndex) {
      counter++;
    }
  }
  return counter;
}

void xxx_init_unk230_substruct(u8 i)
{
  struct HeldItem* unk230;

  unk230 = &gTeamInventory_203B460->unk230[i];
  unk230->itemIndex = 0;
  unk230->numItems = 0;
}

struct HeldItem* xxx_get_inv_unk230_at_809185C(u8 i)
{
  return &gTeamInventory_203B460->unk230[i];
}

void xxx_fill_unk230_gaps()
{
  // fill unk230 gaps
  // basically the same as FillInventoryGaps
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < 8) {
      if (gTeamInventory_203B460->unk230[slot_checking].itemIndex) {
        break;
      }
      // find next empty slot
      slot_checking++;
    }

    if (slot_checking == 8) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventory_203B460->unk230[last_filled] = gTeamInventory_203B460->unk230[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < 8; last_filled++) {
    xxx_init_unk230_substruct(last_filled);
  }
}

void xxx_sort_inv_unk230_80918EC() {
  s32 i;

  for (i = 0; i < 7; i++) {
    s32 j;
    for (j = i + 1; j < 8; j++) {
      s32 order_i = GetItemOrder(gTeamInventory_203B460->unk230[i].itemIndex);
      s32 order_j = GetItemOrder(gTeamInventory_203B460->unk230[j].itemIndex);
      if (order_i > order_j || (order_i == order_j && gTeamInventory_203B460->unk230[i].numItems < gTeamInventory_203B460->unk230[j].numItems)) {
        struct HeldItem str_i = gTeamInventory_203B460->unk230[i];
        gTeamInventory_203B460->unk230[i] = gTeamInventory_203B460->unk230[j];
        gTeamInventory_203B460->unk230[j] = str_i;
      }
    }
  }
}

void xxx_inv_unk250_random_8091980(u8 a1) {
  u32 data[4];
  s32 i;

  memcpy(data, gUnknown_81097E8, 4 * sizeof(u32));
  for (i = 0; i < 8; i++) {
    xxx_init_unk230_substruct(i);
  }
  for (i = 0; i < 8; i++) {
    s32 rand_1 = RandomCapped(9999);
    s32 rand_2 = RandomCapped(9999);
    xxx_insert_unk230_80919FC(sub_8091E94(data[a1], rand_1, rand_2));
  }
  xxx_sort_inv_unk230_80918EC();
  sub_8091BB4(a1);
}

bool8 xxx_insert_unk230_80919FC(u8 itemIndex) {
  struct HeldItem held;
  s32 i;

  xxx_init_helditem_8090B08(&held, itemIndex);  // initialize
  for (i = 0; i < 8; i++) {
    if (!gTeamInventory_203B460->unk230[i].itemIndex) {
      gTeamInventory_203B460->unk230[i] = held;
      return FALSE;
    }
  }
  return TRUE;
}

u32 xxx_count_non_empty_inv_unk250_8091A48() {
  s32 i;
  u32 count = 0;
  for (i = 0; i < 4; i++) {
    if (gTeamInventory_203B460->unk250[i].itemIndex) {
      count++;
    }
  }
  return count;
}

void xxx_init_inv_unk250_at_8091A74(u8 index) {
  struct HeldItem* unk250 = &gTeamInventory_203B460->unk250[index];
  unk250->itemIndex = 0;
  unk250->numItems = 0;
}

struct HeldItem* xxx_get_unk250_at_8091A90(u8 index) {
    return &gTeamInventory_203B460->unk250[index];
}

void xxx_fill_inv_unk250_gaps_8091AA8(u8 index) {
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < 4) {
      if (gTeamInventory_203B460->unk250[slot_checking].itemIndex != ITEM_ID_NOTHING) {
        break;
      }
      slot_checking++;
    }

    if (slot_checking == 4) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventory_203B460->unk250[last_filled] = gTeamInventory_203B460->unk250[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < 4; last_filled++) {
    xxx_init_inv_unk250_at_8091A74(last_filled);
  }
}

void xxx_sort_inv_unk250_8091B20() {
  s32 i;

  for (i = 0; i < 3; i++) {
    s32 j;
    for (j = i + 1; j < 4; j++) {
      s32 order_i = GetItemOrder(gTeamInventory_203B460->unk250[i].itemIndex);
      s32 order_j = GetItemOrder(gTeamInventory_203B460->unk250[j].itemIndex);
      if (order_i > order_j || (order_i == order_j && gTeamInventory_203B460->unk250[i].numItems < gTeamInventory_203B460->unk250[j].numItems)) {
        struct HeldItem str_i = gTeamInventory_203B460->unk250[i];
        gTeamInventory_203B460->unk250[i] = gTeamInventory_203B460->unk250[j];
        gTeamInventory_203B460->unk250[j] = str_i;
      }
    }
  }
}

void sub_8091BB4(u8 index) {
  u32 data[4];
  s32 i;

  memcpy(data, gUnknown_81097F8, 4 * sizeof(u32));
  for (i = 0; i < 4; i++) {
    xxx_init_inv_unk250_at_8091A74(i);
  }
  for (i = 0; i < 4; i++) {
    s32 rand_1 = RandomCapped(9999);
    s32 rand_2 = RandomCapped(9999);
    xxx_insert_unk250_8091C1C(sub_8091E94(data[index], rand_1, rand_2));
  }
  xxx_sort_inv_unk250_8091B20();
}

bool8 xxx_insert_unk250_8091C1C(u8 itemIndex) {
  struct HeldItem held;
  s32 i;

  xxx_init_helditem_8090B08(&held, itemIndex);  // initialize
  for (i = 0; i < 4; i++) {
    if (!gTeamInventory_203B460->unk250[i].itemIndex) {
      gTeamInventory_203B460->unk250[i] = held;
      return FALSE;
    }
  }
  return TRUE;
}

s32 SaveTeamInventory(u8* unk0, u32 size)
{
  struct unkStruct_8094924 unk;
  s32 i;

  xxx_init_struct_8094924_save_809486C(&unk, unk0, size);
  for (i = 0; i < INVENTORY_SIZE; i++) {
    SaveItemSlot(&unk, &gTeamInventory_203B460->teamItems[i]);
  }
  for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
    SaveIntegerBits(&unk, &gTeamInventory_203B460->teamStorage[i], 10);
  }
  for (i = 0; i < 8; i++) {
    SaveHeldItem(&unk, &gTeamInventory_203B460->unk230[i]);
  }
  for (i = 0; i < 4; i++) {
    SaveHeldItem(&unk, &gTeamInventory_203B460->unk250[i]);
  }
  SaveIntegerBits(&unk, &gTeamInventory_203B460->teamMoney, 24);
  SaveIntegerBits(&unk, &gTeamInventory_203B460->teamSavings, 24);
  nullsub_102(&unk);
  return unk.unk8;
}

s32 RestoreTeamInventory(u8 *unk0, u32 size)
{
  struct unkStruct_8094924 unk;
  s32 i;

  xxx_init_struct_8094924_restore_809485C(&unk, unk0, size);
  for (i = 0; i < 20; i++) {
    RestoreItemSlot(&unk, &gTeamInventory_203B460->teamItems[i]);
  }
  for (i = 0; i < 240; i++) {
    RestoreIntegerBits(&unk, &gTeamInventory_203B460->teamStorage[i], 10);
  }
  for (i = 0; i < 8; i++) {
    RestoreHeldItem(&unk, &gTeamInventory_203B460->unk230[i]);
  }
  for (i = 0; i < 4; i++) {
    RestoreHeldItem(&unk, &gTeamInventory_203B460->unk250[i]);
  }
  RestoreIntegerBits(&unk, &gTeamInventory_203B460->teamMoney, 24);
  RestoreIntegerBits(&unk, &gTeamInventory_203B460->teamSavings, 24);
  nullsub_102(&unk);
  return unk.unk8;
}

void RestoreHeldItem(struct unkStruct_8094924 *a1, struct HeldItem *item)
{
  RestoreIntegerBits(a1, &item->itemIndex, 8);
  RestoreIntegerBits(a1, &item->numItems, 7);
}

void SaveHeldItem(struct unkStruct_8094924 *a1, struct HeldItem *item)
{
  SaveIntegerBits(a1, &item->itemIndex, 8);
  SaveIntegerBits(a1, &item->numItems, 7);
}

void RestoreItemSlot(struct unkStruct_8094924 *a1, struct ItemSlot *slot)
{
  RestoreIntegerBits(a1, &slot->itemFlags, 8);
  RestoreIntegerBits(a1, &slot->numItems, 7);
  RestoreIntegerBits(a1, &slot->itemIndex, 8);
}

void SaveItemSlot(struct unkStruct_8094924 *a1, struct ItemSlot *slot)
{
  SaveIntegerBits(a1, &slot->itemFlags, 8);
  SaveIntegerBits(a1, &slot->numItems, 7);
  SaveIntegerBits(a1, &slot->itemIndex, 8);
}

u32 sub_8091E50(u8 index)
{
  return gUnknown_810AF50[index];
}

u32 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1)
{
  if (i0 > 0x3e)
    return 0;
  else
    return (gUnknown_8108F64[i0][i1 >> 3] >> (i1 & 7)) & 1;
}


extern u16* gUnknown_8108E58[];

struct UnkStruct_8091E94 {
  s16 unk0[12];
  s16 unk18[0xf0];
};

NAKED
s32 sub_8091E94(s32 a1, s32 a2, s32 a3)
{
#if 0
  // this is about as good as I got it so far
  s32 i;
  u8 item_type;
  s32 result;

  // struct of 12 + 0xf0 (NUMBER_OF_ITEM_IDS) hwords?
  struct UnkStruct_8091E94 s1;
  u16 s2[12 + 0xf0];
  s32 data_index;
  // 30000: level up exp required?

  data_index = 0;
  // compressed data?
  for (i = 0; i < 252; i++) {
    if (gUnknown_8108E58[a1 - 1][i] > 29999) {
      s32 j;
      for (j = gUnknown_8108E58[a1 - 1][i] - 30000; j != 0; j--) {
        s2[data_index++] = 0;
      }
    }
    else {
      s2[data_index++] = gUnknown_8108E58[a1 - 1][i];
    }
  }

  for (i = 0; i < 12; i++) {
    s1.unk0[i] = s2[i];
  }

  for (i = 0; i < 240; i++) {
    s1.unk18[i] = s2[12 + i];
  }

  item_type = 0;
  for (i = 0; i < 12; i++) {
    if (s1.unk0[i] && s1.unk0[i] >= a2){
      item_type = i;
      break;
    }
  }

  result = 70;
  if (item_type != 12) {
    s32 j;
    for (j = 0; j < 240; j++) {
      if (s1.unk18[j] && (GetItemType(j) == item_type) && (s1.unk18[j] >= a3)) {
        return result;
      }
    }
    result = j;
  }
  return result;
#else
  asm_unified("\tpush {r4-r7,lr}\n"
"\tmov r7, r10\n"
"\tmov r6, r9\n"
"\tmov r5, r8\n"
"\tpush {r5-r7}\n"
"\tldr r4, _08091EE4\n"
"\tadd sp, r4\n"
"\tmov r8, r1\n"
"\tmov r10, r2\n"
"\tldr r1, _08091EE8\n"
"\tsubs r0, 0x1\n"
"\tlsls r0, 2\n"
"\tadds r0, r1\n"
"\tmovs r3, 0\n"
"\tadd r1, sp, 0x18\n"
"\tmov r9, r1\n"
"\tldr r2, _08091EEC\n"
"\tmov r12, r2\n"
"\tadd r6, sp, 0x1F8\n"
"\tldr r2, [r0]\n"
"\tadds r7, r6, 0\n"
"\tmovs r4, 0\n"
"_08091EC0:\n"
"\tldrh r1, [r2]\n"
"\tcmp r1, r12\n"
"\tbls _08091EF4\n"
"\tldrh r0, [r2]\n"
"\tldr r1, _08091EF0\n"
"\tadds r0, r1\n"
"\tcmp r0, 0\n"
"\tbeq _08091EFC\n"
"\tmovs r5, 0\n"
"\tadds r1, r7, r4\n"
"_08091ED4:\n"
"\tstrh r5, [r1]\n"
"\tadds r1, 0x2\n"
"\tadds r4, 0x2\n"
"\tadds r3, 0x1\n"
"\tsubs r0, 0x1\n"
"\tcmp r0, 0\n"
"\tbne _08091ED4\n"
"\tb _08091EFC\n"
"\t.align 2, 0\n"
"_08091EE4: .4byte 0xfffffc10\n"
"_08091EE8: .4byte gUnknown_8108E58\n"
"_08091EEC: .4byte 0x0000752f\n"
"_08091EF0: .4byte 0xffff8ad0\n"
"_08091EF4:\n"
"\tadds r0, r6, r4\n"
"\tstrh r1, [r0]\n"
"\tadds r4, 0x2\n"
"\tadds r3, 0x1\n"
"_08091EFC:\n"
"\tadds r2, 0x2\n"
"\tcmp r3, 0xFB\n"
"\tble _08091EC0\n"
"\tmovs r3, 0xB\n"
"\tadd r2, sp, 0x1F8\n"
"\tmov r1, sp\n"
"_08091F08:\n"
"\tldrh r0, [r2]\n"
"\tstrh r0, [r1]\n"
"\tadds r2, 0x2\n"
"\tadds r1, 0x2\n"
"\tsubs r3, 0x1\n"
"\tcmp r3, 0\n"
"\tbge _08091F08\n"
"\tmov r2, r9\n"
"\tadd r1, sp, 0x210\n"
"\tmovs r3, 0xEF\n"
"_08091F1C:\n"
"\tldrh r0, [r1]\n"
"\tstrh r0, [r2]\n"
"\tadds r1, 0x2\n"
"\tadds r2, 0x2\n"
"\tsubs r3, 0x1\n"
"\tcmp r3, 0\n"
"\tbge _08091F1C\n"
"\tmovs r7, 0xC\n"
"\tmovs r6, 0\n"
"\tmov r0, sp\n"
"\tmovs r2, 0\n"
"\tldrsh r0, [r0, r2]\n"
"\tcmp r0, 0\n"
"\tbeq _08091F4A\n"
"\tmov r0, sp\n"
"\tmovs r1, 0\n"
"\tldrsh r0, [r0, r1]\n"
"\tcmp r0, r8\n"
"\tblt _08091F4A\n"
"\tmovs r7, 0\n"
"\tb _08091F66\n"
"_08091F46:\n"
"\tmov r8, r5\n"
"\tb _08091F9C\n"
"_08091F4A:\n"
"\tadds r6, 0x1\n"
"\tcmp r6, 0xB\n"
"\tbgt _08091F66\n"
"\tlsls r0, r6, 1\n"
"\tmov r2, sp\n"
"\tadds r1, r2, r0\n"
"\tmovs r2, 0\n"
"\tldrsh r0, [r1, r2]\n"
"\tcmp r0, 0\n"
"\tbeq _08091F4A\n"
"\tcmp r0, r8\n"
"\tblt _08091F4A\n"
"\tlsls r0, r6, 24\n"
"\tlsrs r7, r0, 24\n"
"_08091F66:\n"
"\tmovs r0, 0x46\n"
"\tmov r8, r0\n"
"\tcmp r7, 0xC\n"
"\tbeq _08091F9C\n"
"\tmovs r6, 0\n"
"\tmov r4, r9\n"
"_08091F72:\n"
"\tmovs r1, 0\n"
"\tldrsh r0, [r4, r1]\n"
"\tcmp r0, 0\n"
"\tbeq _08091F94\n"
"\tlsls r0, r6, 24\n"
"\tlsrs r5, r0, 24\n"
"\tadds r0, r5, 0\n"
"\tbl GetItemType\n"
"\tlsls r0, 24\n"
"\tlsrs r0, 24\n"
"\tcmp r0, r7\n"
"\tbne _08091F94\n"
"\tmovs r2, 0\n"
"\tldrsh r0, [r4, r2]\n"
"\tcmp r0, r10\n"
"\tbge _08091F46\n"
"_08091F94:\n"
"\tadds r4, 0x2\n"
"\tadds r6, 0x1\n"
"\tcmp r6, 0xEF\n"
"\tble _08091F72\n"
"_08091F9C:\n"
"\tmov r0, r8\n"
"\tmovs r3, 0xFC\n"
"\tlsls r3, 2\n"
"\tadd sp, r3\n"
"\tpop {r3-r5}\n"
"\tmov r8, r3\n"
"\tmov r9, r4\n"
"\tmov r10, r5\n"
"\tpop {r4-r7}\n"
"\tpop {r1}\n"
"\tbx r1\n");
#endif
}

void ClearAllItems_8091FB4() {
  s32 i;

  for (i = 0; i < INVENTORY_SIZE; i++) {
    struct ItemSlot* slot = &gTeamInventory_203B460->teamItems[i];
    if (slot->itemFlags & ITEM_FLAG_EXISTS) {
      slot->itemFlags &= 0xf7;
      if (slot->itemIndex == ITEM_ID_POKE) {
        AddToTeamMoney(GetMoneyValue(slot));
        slot->itemIndex = 0;
        slot->numItems = 0;
        slot->itemFlags = 0;
      }
    }
  }
  FillInventoryGaps();
  for (i = 0; i < NUM_SPECIES; i++) {
    struct PokemonStruct* pokemon;
#ifdef NONMATCHING
    pokemon = &i[gRecruitedPokemonRef->pokemon];
#else
    register size_t offset asm("r1") = offsetof(struct unkStruct_203B45C, pokemon[i]);
    struct PokemonStruct* p = gRecruitedPokemonRef->pokemon;
    size_t addr = offset + (size_t)p;
    pokemon = (struct PokemonStruct*)addr;
#endif

    if ((u8)pokemon->unk0 & 1) {
      if (pokemon->heldItem.itemIndex) {
        if (pokemon->heldItem.itemIndex == ITEM_ID_POKE) {
          AddToTeamMoney(GetMoneyValueHeld(&pokemon->heldItem));
          pokemon->heldItem.itemIndex = 0;
        }
      }
    }
  }
}
