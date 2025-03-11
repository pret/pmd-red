#include "global.h"
#include "code_8097DD0.h"
#include "constants/colors.h"
#include "constants/type.h"
#include "items.h"
#include "moves.h"
#include "random.h"
#include "pokemon.h"
#include "random.h"
#include "code_800D090.h"
#include "text_util.h"
#include "text.h"
#include "string_format.h"
#include <stddef.h>

extern struct FileArchive gSystemFileArchive;
extern const char gItemParaFileName[];
extern const char gUnknown_8109794[];
extern const char gUnknown_81097A4[];
extern s32 gPowersOfTen[];
extern u8 gHighDigits[];
extern u16 gGummiStatBoostLUT[];
extern u8* gPtrTypeText;  // ptr to "Type\0"
extern u8* gPtrPPD0Text;  // ptr to "PP {VALUE_0} \0"
extern u32 gUnknown_81097E8[4];  // some sort of lookup table (16, 18, 20, 22)
extern u32 gUnknown_81097F8[4];  // some sort of lookup table (17, 19, 21, 23)
extern const char *gUnknown_810AF50[];
extern u8 gUnknown_8108F64[0x3f][32];  // some sort of bit lookup table
extern u8 gInvalidItemIDs[0x10];

EWRAM_DATA OpenedFile *gItemParametersFile = {0};
EWRAM_DATA ItemDataEntry *gItemParametersData = {0};
EWRAM_DATA TeamInventory gTeamInventory = {0};
EWRAM_INIT TeamInventory *gTeamInventoryRef = {NULL};

extern u8 sub_8091E94(s32 a1, s32 a2, s32 a3);
extern void SortKecleonShopInventory();
bool8 AddKecleonWareItem(u8);

#include "data/items.h"

static void sub_8090F58(u8 *, u8 *, Item *, const unkStruct_8090F58 *);

void LoadItemParameters(void)
{
  gTeamInventoryRef = &gTeamInventory;
  gItemParametersFile = OpenFileAndGetFileDataPtr(gItemParaFileName,&gSystemFileArchive);
  gItemParametersData = (ItemDataEntry *) gItemParametersFile->data;
}

TeamInventory *GetMoneyItemsInfo(void)
{
    return &gTeamInventory;
}

void InitializeMoneyItems(void)
{
  s32 i;

  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    gTeamInventoryRef->teamItems[i].flags = 0;
  }

  for(i = 0; i < STORAGE_SIZE; i++)
  {
    gTeamInventoryRef->teamStorage[i] = 0;
  }

  for(i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++)
  {
    InitKecleonShopItem(i);
  }
  gTeamInventoryRef->teamMoney = 0;
  gTeamInventoryRef->teamSavings = 0;
}

s32 GetNumberOfFilledInventorySlots(void)
{
  s32 i;
  s32 count;

  count = 0;
  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    if ((gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS) != 0) {
      count++;
    }
  }
  return count;
}

bool8 IsThrowableItem(u8 id)
{
  if ((GetItemCategory(id) != CATEGORY_THROWN_LINE) && (GetItemCategory(id) != CATEGORY_THROWN_ARC))
    return FALSE;
  else
    return TRUE;
}

void xxx_init_itemslot_8090A8C(Item *slot, u8 id, u8 param_3)
{
  u32 uVar3;
  u32 uVar4;

  if (id != ITEM_NOTHING) {
    slot->flags = ITEM_FLAG_EXISTS;
    slot->id = id;
    if (IsThrowableItem(id)) {
        uVar3 = GetSpawnAmountRange(id, MIN_SPAWN_AMOUNT);
        uVar4 = GetSpawnAmountRange(id, MAX_SPAWN_AMOUNT);
        slot->quantity = RandRange(uVar3, uVar4);
    }
    else if (GetItemCategory(id) == CATEGORY_POKE)
        slot->quantity  = 1;
    else
        slot->quantity  = 0;

    if (param_3 != 0)
        slot->flags |= ITEM_FLAG_STICKY;

  }
  else {
    slot->flags = 0;
    slot->id = ITEM_NOTHING;
    slot->quantity  = 0;
  }
}

void xxx_init_helditem_8090B08(BulkItem *held, u8 id)
{
  u32 uVar2;
  u32 uVar3;

  if (id != ITEM_NOTHING) {
    held->id = id;
    if (IsThrowableItem(id)) {
        uVar2 = GetSpawnAmountRange(id,MIN_SPAWN_AMOUNT);
        uVar3 = GetSpawnAmountRange(id,MAX_SPAWN_AMOUNT);
        held->quantity = RandRange(uVar2, uVar3);
    }
    else if (GetItemCategory(id) == CATEGORY_POKE)
        held->quantity = 1;
    else
        held->quantity = 0;
  }
  else {
    held->id = ITEM_NOTHING;
    held->quantity = 0;
  }
}

void HeldItemToSlot(Item *slot, BulkItem *held)
{
    u8 is_throwable;

    if(held->id != ITEM_NOTHING)
    {
        slot->flags = ITEM_FLAG_EXISTS;
        slot->id = held->id;
        is_throwable = IsThrowableItem(slot->id);
        if(is_throwable != 0 || GetItemCategory(slot->id) == CATEGORY_POKE)
            slot->quantity = held->quantity;
        else if(slot->id == ITEM_TM_USED_TM)
            slot->quantity = held->quantity;
        else
            slot->quantity = 0;
    }
    else
    {
        slot->id = ITEM_NOTHING;
        slot->quantity = 0;
        slot->flags = 0;
    }
}

void SlotToHeldItem(BulkItem *held,Item *slot)
{
  if ((slot->flags & ITEM_FLAG_EXISTS) != 0) {
    held->id = slot->id;
    held->quantity = slot->quantity;
  }
  else {
    held->id = ITEM_NOTHING;
  }
}

u8 GetItemCategory(u8 index)
{
    return gItemParametersData[index].category;
}

s32 GetStackBuyValue(Item *param_1)
{
  if (param_1->id == ITEM_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->id)) {
      return gItemParametersData[param_1->id].buyPrice * param_1->quantity;
    }
    else {
      return gItemParametersData[param_1->id].buyPrice;
    }
  }
}

s32 GetStackSellValue(Item *param_1)
{
  if (param_1->id == ITEM_POKE) {
    return GetMoneyValue(param_1);
  }
  else {
    if (IsThrowableItem(param_1->id)) {
      return gItemParametersData[param_1->id].sellPrice * param_1->quantity;
    }
    else {
      return gItemParametersData[param_1->id].sellPrice;
    }
  }
}

s32 GetStackBuyPrice(Item *param_1)
{
  if (!CanSellItem(param_1->id)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->id)) {
      return gItemParametersData[param_1->id].buyPrice * param_1->quantity;
    }
    else {
      return gItemParametersData[param_1->id].buyPrice;
    }
  }
}

s32 GetStackSellPrice(Item *param_1)
{
  if (!CanSellItem(param_1->id)) {
    return 0;
  }
  else {
    if (IsThrowableItem(param_1->id)) {
      return gItemParametersData[param_1->id].sellPrice * param_1->quantity;
    }
    else {
      return gItemParametersData[param_1->id].sellPrice;
    }
  }
}

s32 GetItemBuyPrice(u8 id)
{
    return gItemParametersData[id].buyPrice;
}

s32 GetItemSellPrice(u8 id)
{
    return gItemParametersData[id].sellPrice;
}

s32 GetItemOrder(u8 id)
{
    return gItemParametersData[id].order;
}

s32 GetItemPalette(u8 id)
{
    return gItemParametersData[id].palette;
}

u32 GetItemActionType(u8 id)
{
    return gItemParametersData[id].actionType;
}

u32 GetSpawnAmountRange(u8 id, u32 rangeIndex)
{
    return gItemParametersData[id].spawnAmountRange[rangeIndex];
}

u8 *GetItemDescription(u8 id)
{
    return gItemParametersData[id].description;
}

bool8 TestItemAIFlag(u8 id, u32 aiFlag)
{
    return gItemParametersData[id].aiFlags[aiFlag];
}

// a2 is always NULL
// This func probably appends the quantity of 1, but I haven't checked
// If it appends quantity, we can rename the func
void BufferItemName(u8* dest, u8 id, struct unkStruct_8090F58* a2)
{
  char acStack104 [80];
  Item unkItem;

  strncpy(acStack104, gItemParametersData[id].name, 80);
  xxx_init_itemslot_8090A8C(&unkItem, id, 0);
  unkItem.quantity = 1;
  sub_8090F58(dest, acStack104, &unkItem, a2);
}

extern const u8 gUnknown_8109770[];
extern const u8 gUnknown_8109778[];
extern const u8 gUnknown_810977C[];
extern const u8 gUnknown_8109784[];
extern const u8 gUnknown_810978C[];

void sub_8090E14(u8* ext_buffer, Item* slot, const struct unkStruct_8090F58* a3) {
  s32 unk8 = 0;
  u8 buffer[80];

  if (a3) {
    unk8 = a3->unk8 != 0;
  }

  if (GetItemCategory(slot->id) == CATEGORY_THROWN_LINE) {
    // I feel like these labels might actually be there...
    if (unk8) {
      sprintfStatic(buffer, gUnknown_8109770, gItemParametersData[slot->id].name, slot->quantity);
    }
    else {
      sprintfStatic(buffer, gUnknown_8109778, gItemParametersData[slot->id].name);
    }
  }
  else if (GetItemCategory(slot->id) == CATEGORY_THROWN_ARC) {
    if (unk8) {
      sprintfStatic(buffer, gUnknown_8109770, gItemParametersData[slot->id].name, slot->quantity);
    }
    else {
      sprintfStatic(buffer, gUnknown_8109778, gItemParametersData[slot->id].name);
    }
  }
  else if (slot->id == ITEM_POKE) {
    sprintfStatic(buffer, gUnknown_810977C, GetMoneyValue(slot));
  }
  else {
    strncpy(buffer, gItemParametersData[slot->id].name, 80);
  }

  if (slot->flags & ITEM_FLAG_STICKY) {
    sprintfStatic(ext_buffer, gUnknown_8109784, buffer);
    strncpy(buffer, ext_buffer, 80);
  }

  if (a3) {
    if (a3->unk4 && (slot->flags & ITEM_FLAG_SET)) {
      sprintfStatic(ext_buffer, gUnknown_810978C, buffer);
      strncpy(buffer, ext_buffer, 80);
    }
    if ((*(u32*)a3 == 1) || (*(u32*)a3 == 3)) {
        if (slot->flags & ITEM_FLAG_IN_SHOP) {
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

static void sub_8090F58(u8* a1, u8 *a2, Item *slot, const struct unkStruct_8090F58* a4) {
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
    WriteHighDecimal(value, buffer, 1);
    sprintfStatic(a1, gUnknown_8109794, a2, a4->unk6, buffer);
  }
  else {
    WriteHighDecimal(value, buffer, 0);
    sprintfStatic(a1, gUnknown_81097A4, a2, buffer);
  }
}

s32 WriteHighDecimal(s32 a1, u8 *strbuf, u8 a3)
{
  s32 i, count;
  s32 cond = 0;

  count = 0;
  for (i = 0; i < 5; i++) {
    s32 div;

    div = 0;
    while (a1 >= gPowersOfTen[i]) {
        a1 -= gPowersOfTen[i];
        div++;
    }

    if (div > 9) {
      div = 9;
    }

    if (div) {
        cond = 1;
        *strbuf++ = gHighDigits[2 * div];
        *strbuf++ = (gHighDigits + 1)[2 * div];  // weird staggered arrays...
        count++;
    }
    else if (cond) {
        *strbuf++ = gHighDigits[0];
        *strbuf++ = (gHighDigits + 1)[0];  // weird staggered arrays...
        count++;
    }
    else if (a3) {
        *strbuf++ = 96;  // ` character?
    }
  }

  *strbuf++ = gHighDigits[2 * a1];
  *strbuf   = (gHighDigits + 1)[2 * a1];
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
      if (slot_checking[gTeamInventoryRef->teamItems].flags & ITEM_FLAG_EXISTS) {
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
      gTeamInventoryRef->teamItems[last_filled] = gTeamInventoryRef->teamItems[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < INVENTORY_SIZE; last_filled++) {
      ZeroOutItem(&gTeamInventoryRef->teamItems[last_filled]);
  }
}

s32 FindItemInInventory(u8 id)
{
  s32 i;
  for (i = 0; i < INVENTORY_SIZE; i++) {
    if ((gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS) && (gTeamInventoryRef->teamItems[i].id == id)) {
      return i;
    }
  }
  return -1;
}

s32 GetItemCountInInventory(u8 id)
{
    s32 i;
    s32 count = 0;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i]) && gTeamInventoryRef->teamItems[i].id == id) {
            count++;
        }
    }

    return count;
}

s32 GetItemPossessionCount(u8 id)
{
    s32 count = GetItemCountInInventory(id);
    s32 i = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonFlag1(mon)
        && PokemonFlag2(mon)
        && (mon->heldItem.id != ITEM_NOTHING)
        && (mon->heldItem.id == id))
        {
            count++;
        }
    }
    return count;
}

void ShiftItemsDownFrom(s32 start)
{
  s32 i, j;
  for (i = start, j = start + 1; i < INVENTORY_SIZE - 1; i++, j++) {
    gTeamInventoryRef->teamItems[i] = gTeamInventoryRef->teamItems[j];
  }
  gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].id = ITEM_NOTHING;
  gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags = 0;
}

void ClearItemSlotAt(u32 index)
{
  gTeamInventoryRef->teamItems[index].id = ITEM_NOTHING;
  gTeamInventoryRef->teamItems[index].flags = 0;
}

bool8 sub_809124C(u8 id, u8 param_3)
{
  Item temp;
  xxx_init_itemslot_8090A8C(&temp, id, param_3);
  return AddItemToInventory(&temp);
}

bool8 AddHeldItemToInventory(BulkItem* slot)
{
  Item temp;

  HeldItemToSlot(&temp, slot);
  return AddItemToInventory(&temp);
}

bool8 AddItemToInventory(const Item* slot)
{
    s32 i;

    // try to add item to inventory, return 1 if failed
    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (!ItemExists(&gTeamInventoryRef->teamItems[i])) {
            gTeamInventoryRef->teamItems[i] = *slot;
            return FALSE;
        }
    }
    return TRUE;
}

void ConvertMoneyItemToMoney(void)
{
    s32 i, j;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(item) && item->id == ITEM_POKE) {
            AddToTeamMoney(GetMoneyValue(item));
            ZeroOutItem(item);
        }
    }
    FillInventoryGaps();

    for (i = 0; i < INVENTORY_SIZE; i++) {
        s32 lowestIndex = -1;

        if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
            s32 lowestOrder = GetItemOrder(gTeamInventoryRef->teamItems[i].id);

            for (j = i + 1; j < INVENTORY_SIZE; j++) {
                if (ItemExists(&gTeamInventoryRef->teamItems[j]) && lowestOrder > GetItemOrder(gTeamInventoryRef->teamItems[j].id)) {
                    lowestIndex = j;
                    lowestOrder = GetItemOrder(gTeamInventoryRef->teamItems[j].id);
                }
            }

            if (lowestIndex >= 0) {
                // swap the slots
                Item temp = gTeamInventoryRef->teamItems[i];
                gTeamInventoryRef->teamItems[i] = gTeamInventoryRef->teamItems[lowestIndex];
                gTeamInventoryRef->teamItems[lowestIndex] = temp;
            }
        }
    }
    FillInventoryGaps();
}

void AddToTeamMoney(s32 amount)
{
  s32 clamped_money;
  gTeamInventoryRef->teamMoney += amount;

  // clamp money
  clamped_money = MAX_TEAM_MONEY;
  if (gTeamInventoryRef->teamMoney <= MAX_TEAM_MONEY) {
    if (gTeamInventoryRef->teamMoney >= 0) {
      return;
    }
    clamped_money = 0;
  }
  gTeamInventoryRef->teamMoney = clamped_money;
}

u16 GetItemMoveID(u8 index)
{
  return gItemParametersData[index].moveID;
}

u32 sub_80913E0(Item* slot, u32 a2, struct subStruct_203B240 ** a3)
{
  u8 buffer88[88];  // some struct

  GetItemDescription(slot->id);
  BufferItemName(buffer88, slot->id, NULL);
  if (slot->id == ITEM_TM_USED_TM) {
    // empty TM
    BufferItemName(gFormatBuffer_Items[0], (u8)(slot->quantity + 125), NULL);
  }
  sub_80073B8(a2);
  PrintFormattedStringOnWindow(16, 0, buffer88, a2, 0);

  PrintFormattedStringOnWindow(8, 24, GetItemDescription(slot->id), a2, 0);
  if (GetItemCategory(slot->id) == CATEGORY_TMS_HMS) {
    Move *buffer8 = (Move*) (buffer88 + 80);  // field in struct
    u16 move = GetItemMoveID(slot->id);
    u8 moves_data;
    const u8* typestring;
    u32 result;

    InitPokemonMove(buffer8, move);
    AddDoubleUnderScoreHighlight(a2, 4, 82, 200, COLOR_WHITE_2);
    PrintFormattedStringOnWindow(4, 84, gPtrTypeText, a2, 0);
    moves_data = GetMoveType(buffer8);
    typestring = GetUnformattedTypeString(moves_data);
    PrintFormattedStringOnWindow(64, 84, typestring, a2, 0);
    result = GetMoveBasePP(buffer8);
    gFormatArgs[0] = result;
    PrintFormattedStringOnWindow(128, 84, gPtrPPD0Text, a2, 0);
  }

  sub_80073E0(a2);
  return sub_8097DF0(GetItemDescription(slot->id), a3);
}

bool8 CanSellItem(u32 id)
{
  u8 id_;
  id = (u8)id;
  id_ = id;

  if (id != ITEM_NOTHING
      && id != ITEM_POKE
      && id != ITEM_ROCK_PART
      && id != ITEM_ICE_PART
      && id != ITEM_STEEL_PART
      && id != ITEM_MUSIC_BOX
      && GetItemSellPrice(id_)
      && GetItemBuyPrice(id_))
          return TRUE;

    return FALSE;
}

bool8 IsNotMoneyOrUsedTMItem(u8 id)
{
  if (id == ITEM_NOTHING) {
    return FALSE;
  }
  else if (id == ITEM_POKE) {
    return FALSE;
  }
  else if (id == ITEM_TM_USED_TM) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsNotSpecialItem(u8 id)
{
  if (id == ITEM_NOTHING) {
    return FALSE;
  }
  else if (id == ITEM_POKE) {
    return FALSE;
  }
  else if (id == ITEM_ROCK_PART) {
    return FALSE;
  }
  else if (id == ITEM_ICE_PART) {
    return FALSE;
  }
  else if (id == ITEM_STEEL_PART) {
    return FALSE;
  }
  else if (id == ITEM_MUSIC_BOX) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsEdibleItem(u8 id)
{
  if (!((GetItemCategory(id) == CATEGORY_BERRIES_SEEDS_VITAMINS) || (GetItemCategory(id) == CATEGORY_FOOD_GUMMIES))) {
    return FALSE;
  }
  return TRUE;
}

bool8 IsHMItem(u8 id)
{
  if (id == ITEM_HM_CUT) {
    return TRUE;
  }
  else if (id == ITEM_HM_FLY) {
    return TRUE;
  }
  else if (id == ITEM_HM_SURF) {
    return TRUE;
  }
  else if (id == ITEM_HM_STRENGTH) {
    return TRUE;
  }
  else if (id == ITEM_HM_FLASH) {
    return TRUE;
  }
  else if (id == ITEM_HM_ROCK_SMASH) {
    return TRUE;
  }
  else if (id == ITEM_HM_WATERFALL) {
    return TRUE;
  }
  else if (id == ITEM_HM_DIVE) {
    return TRUE;
  }
  return FALSE;
}

u32 GetMoneyValue(Item* slot)
{
  return gUnknown_810A3F0[slot->quantity];
}

u32 GetMoneyValueHeld(BulkItem* slot)
{
  // potentially different slot type (used for held item)
  return gUnknown_810A3F0[slot->quantity];
}

void GetGummiItemStatBoost(PokemonStruct1* pokemon, u8 id, bool8 checkBoostFlags, Gummi *gummi)
{
  // item stat buff?
  s8 result;

  gummi->boostAmount = (u16)-1;
  gummi->flags = 0;
  result = IsGummiItem(id);
  if (result) {
    u8 pokemon_type_0 = GetPokemonType(pokemon->speciesNum, 0);
    u8 pokemon_type_1 = GetPokemonType(pokemon->speciesNum, 1);
    u32 gummi_index = id - ITEM_WHITE_GUMMI + 1;
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
    gummi->boostAmount = boost_amount;
    if (!checkBoostFlags) {
      u16 boost_flags;
      if (!boost_amount && RandInt(16) == 10) {
        // supa gummi (all stats boost)
        boost_flags = 0xf;
      }
      else {
        s32 random_index = RandInt(4);
        u16* table = gGummiStatBoostLUT;
        boost_flags = table[random_index];
      }

      gummi->flags = boost_flags;
      boost_flags = gummi->flags;
      if (gummi->flags & 1) {
        if (pokemon->offense.att[OFFENSE_NRM] < 255) {
          pokemon->offense.att[OFFENSE_NRM]++;
        }
        else {
          // fix operand order
          u16 unk2 = gummi->flags;
          unk2 &= ~1;
          gummi->flags &= unk2;
        }
      }
      if (gummi->flags & 2) {
        if (pokemon->offense.att[OFFENSE_SP] < 255) {
          pokemon->offense.att[OFFENSE_SP]++;
        }
        else {
          gummi->flags &= ~2;
        }
      }
      if (gummi->flags & 4) {
        if (pokemon->offense.def[OFFENSE_NRM] < 255) {
          pokemon->offense.def[OFFENSE_NRM]++;
        }
        else {
          gummi->flags &= ~4;
        }
      }
      if (gummi->flags & 8) {
        if (pokemon->offense.def[OFFENSE_SP] < 255) {
          pokemon->offense.def[OFFENSE_SP] ++;
        }
        else {
          gummi->flags &= ~8;
        }
      }
    }
  }
}

bool8 IsGummiItem(u8 id)
{
  if (id < ITEM_WHITE_GUMMI) {
    return FALSE;
  }
  if (id > ITEM_SILVER_GUMMI) {
    return FALSE;
  }
  return TRUE;
}

bool8 HasGummiItem(void)
{
    s32 i;
    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i]) && IsGummiItem(gTeamInventoryRef->teamItems[i].id)) {
            return TRUE;
        }
    }
    return FALSE;
}

void MoveToStorage(Item* slot)
{
  if (IsThrowableItem(slot->id)) {
    gTeamInventoryRef->teamStorage[slot->id] += slot->quantity;
  }
  else {
    gTeamInventoryRef->teamStorage[slot->id]++;
  }

  if (gTeamInventoryRef->teamStorage[slot->id] > 999) {
    gTeamInventoryRef->teamStorage[slot->id] = 999;
  }
}

s32 CountKecleonShopItems(void)
{
  s32 i;
  s32 counter = 0;
  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
    if (gTeamInventoryRef->kecleonShopItems[i].id) {
      counter++;
    }
  }
  return counter;
}

void InitKecleonShopItem(u8 index)
{
  BulkItem* shopItem;

  shopItem = &gTeamInventoryRef->kecleonShopItems[index];
  shopItem->id = ITEM_NOTHING;
  shopItem->quantity = 0;
}

BulkItem* GetKecleonShopItem(u8 i)
{
  return &gTeamInventoryRef->kecleonShopItems[i];
}

void FillKecleonShopGaps(void)
{
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < MAX_KECLEON_ITEM_SHOP_ITEMS) {
      if (gTeamInventoryRef->kecleonShopItems[slot_checking].id) {
        break;
      }
      // find next empty slot
      slot_checking++;
    }

    if (slot_checking == MAX_KECLEON_ITEM_SHOP_ITEMS) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventoryRef->kecleonShopItems[last_filled] = gTeamInventoryRef->kecleonShopItems[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < MAX_KECLEON_ITEM_SHOP_ITEMS; last_filled++) {
    InitKecleonShopItem(last_filled);
  }
}

void SortKecleonShopInventory(void) {
  s32 i;

  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS - 1; i++) {
    s32 j;
    for (j = i + 1; j < MAX_KECLEON_ITEM_SHOP_ITEMS; j++) {
      s32 order_i = GetItemOrder(gTeamInventoryRef->kecleonShopItems[i].id);
      s32 order_j = GetItemOrder(gTeamInventoryRef->kecleonShopItems[j].id);
      if (order_i > order_j || (order_i == order_j && gTeamInventoryRef->kecleonShopItems[i].quantity < gTeamInventoryRef->kecleonShopItems[j].quantity)) {
        BulkItem str_i = gTeamInventoryRef->kecleonShopItems[i];
        gTeamInventoryRef->kecleonShopItems[i] = gTeamInventoryRef->kecleonShopItems[j];
        gTeamInventoryRef->kecleonShopItems[j] = str_i;
      }
    }
  }
}

void ChooseKecleonShopInventory(u8 index) {
  u32 data[4];
  s32 i;

  memcpy(data, gUnknown_81097E8, 4 * sizeof(u32));
  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
    InitKecleonShopItem(i);
  }
  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
    s32 rand_1 = RandInt(9999);
    s32 rand_2 = RandInt(9999);
    AddKecleonShopItem(sub_8091E94(data[index], rand_1, rand_2));
  }
  SortKecleonShopInventory();
  ChooseKecleonWareInventory(index);
}

bool8 AddKecleonShopItem(u8 itemIndex) {
  BulkItem held;
  s32 i;

  xxx_init_helditem_8090B08(&held, itemIndex);  // initialize
  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
    if (!gTeamInventoryRef->kecleonShopItems[i].id) {
      gTeamInventoryRef->kecleonShopItems[i] = held;
      return FALSE;
    }
  }
  return TRUE;
}

u32 CountKecleonWareItems(void) {
  s32 i;
  u32 count = 0;
  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
    if (gTeamInventoryRef->kecleonWareItems[i].id) {
      count++;
    }
  }
  return count;
}

void InitKecleonWareItem(u8 index) {
  BulkItem* wareItem = &gTeamInventoryRef->kecleonWareItems[index];
  wareItem->id = ITEM_NOTHING;
  wareItem->quantity = 0;
}

BulkItem* GetKecleonWareItem(u8 index) {
    return &gTeamInventoryRef->kecleonWareItems[index];
}

void FillKecleonWareGaps(void) {
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < MAX_KECLEON_WARE_SHOP_ITEMS) {
      if (gTeamInventoryRef->kecleonWareItems[slot_checking].id != ITEM_NOTHING) {
        break;
      }
      slot_checking++;
    }

    if (slot_checking == MAX_KECLEON_WARE_SHOP_ITEMS) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventoryRef->kecleonWareItems[last_filled] = gTeamInventoryRef->kecleonWareItems[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < MAX_KECLEON_WARE_SHOP_ITEMS; last_filled++) {
    InitKecleonWareItem(last_filled);
  }
}

void SortKecleonWareInventory(void) {
  s32 i;

  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS - 1; i++) {
    s32 j;
    for (j = i + 1; j < MAX_KECLEON_WARE_SHOP_ITEMS; j++) {
      s32 order_i = GetItemOrder(gTeamInventoryRef->kecleonWareItems[i].id);
      s32 order_j = GetItemOrder(gTeamInventoryRef->kecleonWareItems[j].id);
      if (order_i > order_j || (order_i == order_j && gTeamInventoryRef->kecleonWareItems[i].quantity < gTeamInventoryRef->kecleonWareItems[j].quantity)) {
        BulkItem str_i = gTeamInventoryRef->kecleonWareItems[i];
        gTeamInventoryRef->kecleonWareItems[i] = gTeamInventoryRef->kecleonWareItems[j];
        gTeamInventoryRef->kecleonWareItems[j] = str_i;
      }
    }
  }
}

void ChooseKecleonWareInventory(u8 index) {
  u32 data[MAX_KECLEON_WARE_SHOP_ITEMS];
  s32 i;

  memcpy(data, gUnknown_81097F8, 4 * sizeof(u32));
  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
    InitKecleonWareItem(i);
  }
  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
    s32 rand_1 = RandInt(9999);
    s32 rand_2 = RandInt(9999);
    AddKecleonWareItem(sub_8091E94(data[index], rand_1, rand_2));
  }
  SortKecleonWareInventory();
}

bool8 AddKecleonWareItem(u8 itemIndex) {
  BulkItem held;
  s32 i;

  xxx_init_helditem_8090B08(&held, itemIndex);  // initialize
  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
    if (!gTeamInventoryRef->kecleonWareItems[i].id) {
      gTeamInventoryRef->kecleonWareItems[i] = held;
      return FALSE;
    }
  }
  return TRUE;
}

s32 SaveTeamInventory(u8* unk0, u32 size)
{
  DataSerializer unk;
  s32 i;

  InitBitWriter(&unk, unk0, size);
  for (i = 0; i < INVENTORY_SIZE; i++) {
    WriteItemSlotBits(&unk, &gTeamInventoryRef->teamItems[i]);
  }
  for (i = 0; i < STORAGE_SIZE; i++) {
    WriteBits(&unk, &gTeamInventoryRef->teamStorage[i], 10);
  }
  for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
    WriteHeldItemBits(&unk, &gTeamInventoryRef->kecleonShopItems[i]);
  }
  for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
    WriteHeldItemBits(&unk, &gTeamInventoryRef->kecleonWareItems[i]);
  }
  WriteBits(&unk, &gTeamInventoryRef->teamMoney, 24);
  WriteBits(&unk, &gTeamInventoryRef->teamSavings, 24);

  FinishBitSerializer(&unk);
  return unk.count;
}

s32 RestoreTeamInventory(u8 *unk0, u32 size)
{
    DataSerializer unk;
    s32 i;

    InitBitReader(&unk, unk0, size);
    for (i = 0; i < INVENTORY_SIZE; i++) {
        ReadItemSlotBits(&unk, &gTeamInventoryRef->teamItems[i]);
    }
    for (i = 0; i < STORAGE_SIZE; i++) {
        ReadBits(&unk, &gTeamInventoryRef->teamStorage[i], 10);
    }
    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
        ReadHeldItemBits(&unk, &gTeamInventoryRef->kecleonShopItems[i]);
    }
    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
        ReadHeldItemBits(&unk, &gTeamInventoryRef->kecleonWareItems[i]);
    }
    ReadBits(&unk, &gTeamInventoryRef->teamMoney, 24);
    ReadBits(&unk, &gTeamInventoryRef->teamSavings, 24);

    FinishBitSerializer(&unk);
    return unk.count;
}

void ReadHeldItemBits(DataSerializer *a1, BulkItem *item)
{
  ReadBits(a1, &item->id, 8);
  ReadBits(a1, &item->quantity, 7);
}

void WriteHeldItemBits(DataSerializer *a1, BulkItem *item)
{
  WriteBits(a1, &item->id, 8);
  WriteBits(a1, &item->quantity, 7);
}

void ReadItemSlotBits(DataSerializer *a1, Item *slot)
{
  ReadBits(a1, &slot->flags, 8);
  ReadBits(a1, &slot->quantity, 7);
  ReadBits(a1, &slot->id, 8);
}

void WriteItemSlotBits(DataSerializer *a1, Item *slot)
{
  WriteBits(a1, &slot->flags, 8);
  WriteBits(a1, &slot->quantity, 7);
  WriteBits(a1, &slot->id, 8);
}

const char *sub_8091E50(u8 index)
{
  return gUnknown_810AF50[index];
}

u8 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1)
{
  if (i0 > 0x3e)
    return 0;
  else
    return (gUnknown_8108F64[i0][i1 >> 3] >> (i1 & 7)) & 1;
}

extern const u16* gUnknown_8108E58[];

u8 sub_8091E94(s32 a0, s32 a1, s32 a2)
{
    s32 id, i, arrId;
    u8 foundCategory, ret;
    struct UnkDungeonGlobal_unk1C590 data;
    s16 rawArray[NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS];
    const u16 *ptr = gUnknown_8108E58[a0 - 1];

    id = 0;
    arrId = 0;
    while (id < NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS) {
        if (ptr[arrId] >= 30000) {
            s32 a = ptr[arrId] - 30000;

            while (a != 0) {
                rawArray[id++] = 0;
                a--;
            }
        }
        else {
            rawArray[id++] = ptr[arrId];
        }
        arrId++;
    }

    arrId = 0;
    for (id = 0; id < NUM_ITEM_CATEGORIES; id++) {
        data.categoryValues[arrId] = rawArray[arrId];
        arrId++;
    }

    for (id = 0; id < NUMBER_OF_ITEM_IDS; id++) {
        data.itemValues[id] = rawArray[arrId];
        arrId++;
    }

    foundCategory = NUM_ITEM_CATEGORIES;
    for (i = 0; i < NUM_ITEM_CATEGORIES; i++) {
        if (data.categoryValues[i] != 0 && data.categoryValues[i] >= a1) {
            foundCategory = i;
            break;
        }
    }

    ret = ITEM_PLAIN_SEED;
    if (foundCategory != NUM_ITEM_CATEGORIES) {
        for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
            if (data.itemValues[i] != 0 && GetItemCategory(i) == foundCategory && data.itemValues[i] >= a2) {
                ret = i;
                break;
            }
        }
    }

    return ret;
}

void ClearAllItems_8091FB4(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item* slot = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(slot)) {
            slot->flags &= ~(ITEM_FLAG_STICKY);
            if (slot->id == ITEM_POKE) {
                AddToTeamMoney(GetMoneyValue(slot));
                ZeroOutItem(slot);
            }
        }
    }
    FillInventoryGaps();
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
            PokemonStruct1 *pokemon = &gRecruitedPokemonRef->pokemon[i];
            if (pokemon->heldItem.id) {
                if (pokemon->heldItem.id == ITEM_POKE) {
                    AddToTeamMoney(GetMoneyValueHeld(&pokemon->heldItem));
                    pokemon->heldItem.id = ITEM_NOTHING;
                }
            }
        }
    }
}

bool8 IsInvalidItemReward(u8 itemID)
{
  s32 index;

  if (itemID >= NUMBER_OF_ITEM_IDS)
      return TRUE;
  else {
    index = 0;
    while (gInvalidItemIDs[index] != NUMBER_OF_ITEM_IDS){
      if (gInvalidItemIDs[index] == itemID)
        return TRUE;
      index++;
    };
    return FALSE;
  }
}
