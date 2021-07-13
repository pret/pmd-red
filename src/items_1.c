#include "global.h"
#include "item.h"
#include "team_inventory.h"
#include "random.h"
#include "pokemon.h"
#include "subStruct_203B240.h"

#include <stddef.h>

extern struct TeamInventory *gTeamInventory_203B460;
extern EWRAM_DATA struct Item *gItemParametersData;

extern void sub_80073B8(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);
extern void sub_8092A88(void*, u16);  // first arg is some struct
extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u32 sub_8092B00(void*);
extern u8* GetUnformattedTypeString(s16);
extern u32 sub_8092BF4(void*);
extern void sub_80073E0(u32);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);

extern u8 gUnknown_202DE58[0x58];
extern u32 gUnknown_202DE30;
extern u8* gPtrTypeText;  // ptr to "Type\0"
extern u8* gPtrPPD0Text;  // ptr to "PP $d0 \0"
extern u32 gUnknown_810A3F0[100];
extern struct unkStruct_203B45C *gRecruitedPokemonRef;
extern s16 gTypeGummiIQBoost[0x12][NUMBER_OF_GUMMIS];
extern u16 gGummiStatBoostLUT;


// s32 sub_8090FEC(s32 a1, u8* a2, u8 a3) 
// {
//   s32 i, j;
//   s32 cond = 0;

//   j = 0;
//   for (i = 0; i < 4; i++) {
//     s32 div = 0;
//     s32 next = i + 1;
//     register s32* unk_temp asm("r0");

//     register UNUSED size_t unk_offs asm("r3") = i << 2;
//     unk_temp = (s32*)0x81097B0;
//     next = i + 1;
//     if (a1 >= unk_temp[i]) {
//       register s32 *temp_81097B0 asm("r2") = (s32*)0x81097B0;
//       u32 _i = i;
//       s32 diff;
//       do {
//         // correct other than register usage
//         diff = temp_81097B0[_i];
//         a1 -= diff;
//         div++;
//       } while (a1 >= diff);
//     }

//     if (div > 9) {
//       div = 9;
//     }
//     // /correct

//     if (!div && !cond) {
//         if (a3) {
//           *a2++ = 96;
//         }
//     }
//     else {
//       u8 temp;
//       if (div) {
//         u32 offs;

//         cond = 1;
//         offs = 2 * div;
//         *a2++ = ((u8*)0x81097C4)[offs];
//         temp  = ((u8*)0x81097C5)[offs];
//       }
//       else {
//         *a2++ = ((u8*)0x81097C4)[0];
//         temp  = ((u8*)0x81097C5)[0];
//       }

//       *a2++ = temp;
//       j++;
//     }
//   }

//   *a2++ = ((u8*)0x81097C4)[2 * a1];
//   *a2++ = ((u8*)0x81097C5)[2 * a1];
//   *a2 = 0;
//   return j + 1;
// }

void FillInventoryGaps() 
{
  // fill inventory gaps
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    // effectively just a while loop 
    if ((slot_checking < INVENTORY_SIZE) && !(slot_checking[gTeamInventory_203B460->teamItems].unk0 & 1)) {
      // find next empty slot
      do {
        slot_checking++;
      } while ((slot_checking < INVENTORY_SIZE) && !(slot_checking[gTeamInventory_203B460->teamItems].unk0 & 1));
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
      slot->unk0 = 0;
  }
}

s32 FindItemInInventory(u8 itemIndex) 
{
  s32 i;
  for (i = 0; i < INVENTORY_SIZE; i++) {
    if ((gTeamInventory_203B460->teamItems[i].unk0 & 1) && (gTeamInventory_203B460->teamItems[i].itemIndex == itemIndex)) {
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
    register u32 unk0 asm("r1") = slot->unk0;
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
          && (pokemon->itemIndexHeld != ITEM_ID_NOTHING)
          && (pokemon->itemIndexHeld == itemIndex)) {
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
  gTeamInventory_203B460->teamItems[19].unk0 = 0;
}

void ClearItemSlotAt(u32 index)
{
  gTeamInventory_203B460->teamItems[index].itemIndex = ITEM_ID_NOTHING;
  gTeamInventory_203B460->teamItems[index].unk0 = 0;
}

bool8 sub_809124C(u8 itemIndex, u8 param_3)
{
  struct ItemSlot temp;
  sub_8090A8C(&temp, itemIndex, param_3);
  return AddItemToInventory(&temp);
}

bool8 sub_8091274(struct ItemSlot_ALT* slot) 
{
  struct ItemSlot temp;

  sub_8090B64(&temp, slot);
  return AddItemToInventory(&temp);
}

bool8 AddItemToInventory(const struct ItemSlot* slot) 
{
  s32 i;

  // try to add item to inventory, return 1 if failed
  for (i = 0; i < INVENTORY_SIZE; i++) {
    UNUSED struct ItemSlot* current = &gTeamInventory_203B460->teamItems[i];
    if (!(i[gTeamInventory_203B460->teamItems].unk0 & 1)) {
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
    if ((current_slot->unk0 & 1) && (current_slot->itemIndex == ITEM_ID_POKE)) {
      u32 result;

      result = GetMoneyValue(current_slot);
      AddToTeamMoney(result);
      current_slot->itemIndex = 0;
      current_slot->numItems = 0;
      current_slot->unk0 = 0;
    }
  } while (++i < INVENTORY_SIZE);
  FillInventoryGaps();

  i = 0;
  do {
    s32 lowest_index = -1;
    UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[i]);

    bool8 item_occupied = i[gTeamInventory_203B460->teamItems].unk0 & 1;
    s32 next = i + 1;
    
    if (item_occupied) {
      s32 lowest_order = GetItemOrder(gTeamInventory_203B460->teamItems[i].itemIndex);
      s32 j;

      // find next lowest
      for (j = next; j < INVENTORY_SIZE; j++) {
        UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[j]);
        if ((j[gTeamInventory_203B460->teamItems].unk0 & 1) && (lowest_order > GetItemOrder(gTeamInventory_203B460->teamItems[j].itemIndex))) {
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

u32 GetMoneyValue2(struct ItemSlot* slot) 
{
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
        u16* table = &gGummiStatBoostLUT;
        boost_flags = table[random_index];
      }

      a4->unk2 = boost_flags;
      boost_flags = a4->unk2;
      if (a4->unk2 & 1) {
        if (pokemon->pokeAtt < 255) {
          pokemon->pokeAtt++;
        }
        else {
          // fix operand order
          u16 unk2 = a4->unk2;
          unk2 &= ~1;
          a4->unk2 &= unk2;
        }
      }
      if (a4->unk2 & 2) {
        if (pokemon->pokeSPAtt < 255) {
          pokemon->pokeSPAtt++;
        }
        else {
          a4->unk2 &= ~2;
        }
      }
      if (a4->unk2 & 4) {
        if (pokemon->pokeDef < 255) {
          pokemon->pokeDef++;
        }
        else {
          a4->unk2 &= ~4;
        }
      }
      if (a4->unk2 & 8) {
        if (pokemon->pokeSPDef < 255) {
          pokemon->pokeSPDef++;
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
    if ((i[gTeamInventory_203B460->teamItems].unk0 & 1) && IsGummiItem(i[gTeamInventory_203B460->teamItems].itemIndex)) {
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
  struct subStruct_203B460* unk230;

  unk230 = &gTeamInventory_203B460->unk230[i];
  unk230->itemIndex = 0;
  unk230->unk1 = 0;
}

struct subStruct_203B460* sub_809185C(u8 i) 
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
    // effectively just a while loop
    if ((slot_checking < 8) && !gTeamInventory_203B460->unk230[slot_checking].itemIndex) {
      do {
        // find next empty slot
        slot_checking++;
      } while ((slot_checking < 8) && !gTeamInventory_203B460->unk230[slot_checking].itemIndex);
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

void sub_80918EC() {
  // sort unk230
  s32 i;

  for (i = 0; i < 7; i++) {
      s32 j;
      for (j = i + 1; j < 8; j++) {
          s32 order_i = GetItemOrder(gTeamInventory_203B460->unk230[i].itemIndex);
          s32 order_j = GetItemOrder(gTeamInventory_203B460->unk230[j].itemIndex);
          if (order_i > order_j || (order_i == order_j && gTeamInventory_203B460->unk230[i].unk1 < gTeamInventory_203B460->unk230[j].unk1)) {
              struct subStruct_203B460 str_i = gTeamInventory_203B460->unk230[i];
              gTeamInventory_203B460->unk230[i] = gTeamInventory_203B460->unk230[j];
              gTeamInventory_203B460->unk230[j] = str_i;
          }
      }
  }
}