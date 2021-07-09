#include "global.h"
#include "item.h"
#include "team_inventory.h"
#include "subStruct_203B240.h"

#include <stddef.h>

extern struct TeamInventory *gTeamInventory_203B460;
extern EWRAM_DATA struct Item *gItemParametersData;

extern s32 sub_80915D4(struct ItemSlot *);
extern void sub_80910B4();
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


bool8 AddItemToInventory(const struct ItemSlot* slot) 
{
  s32 i;

  // try to add item to inventory, return 1 if failed
  for (i = 0; i < 20; i++) {
    UNUSED struct ItemSlot* current = &gTeamInventory_203B460->teamItems[i];
    if (!(i[gTeamInventory_203B460->teamItems].unk0 & 1)) {
      gTeamInventory_203B460->teamItems[i] = *slot;
      return 0;
    }
  }
  return 1;
}


void ConvertMoneyItemToMoney() 
{
  s32 i = 0;

  do {
    UNUSED struct TeamInventory * _gTeamInventory_203B460 = gTeamInventory_203B460;
    UNUSED size_t offs = offsetof(struct TeamInventory, teamItems[i]);

    struct ItemSlot* current_slot = &gTeamInventory_203B460->teamItems[i];
    if ((current_slot->unk0 & 1) && (current_slot->itemIndex == ITEM_ID_POKE)) {
      s32 result;

      result = sub_80915D4(current_slot);
      AddToTeamMoney(result);
      current_slot->itemIndex = 0;
      current_slot->numItems = 0;
      current_slot->unk0 = 0;
    }
  } while (++i < 20);
  sub_80910B4();

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
      for (j = next; j < 20; j++) {
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
  } while (++i < 20);
  sub_80910B4();
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
  return gItemParametersData[index & 0xff].move;
}

u32 sub_80913E0(struct ItemSlot* slot, u32 a2, struct subStruct_203B240 ** a3) 
{
  u8 buffer88[88];  // some struct

  GetItemDescription(slot->itemIndex);
  sub_8090DC4(buffer88, slot->itemIndex, 0);
  if (slot->itemIndex == 124) {
    // empty HM
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

bool8 CanSellItem(u32 id) {
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
          return 1;
    }
    return 0;
}

bool8 IsNotMoneyOrUsedTMItem(u8 id) {
  if (id == ITEM_ID_NOTHING) {
    return 0;
  }
  else if (id == ITEM_ID_POKE) {
    return 0;
  }
  else if (id == ITEM_ID_USED_TM) {
    return 0;
  }
  return 1;
}

bool8 IsNotSpecialItem(u8 id) {
  if (id == ITEM_ID_NOTHING) {
    return 0;
  }
  else if (id == ITEM_ID_POKE) {
    return 0;
  }
  else if (id == ITEM_ID_ROCK_PART) {
    return 0;
  }
  else if (id == ITEM_ID_ICE_PART) {
    return 0;
  }
  else if (id == ITEM_ID_STEEL_PART) {
    return 0;
  }
  else if (id == ITEM_ID_MUSIC_BOX) {
    return 0;
  }
  return 1;
}

bool8 IsEdibleItem(u8 id) {
  if (!((GetItemType(id) == ITEM_TYPE_BERRY_SEED) || (GetItemType(id) == ITEM_TYPE_APPLE_GUMMI))) {
    return 0;
  }
  return 1;
}

bool8 IsTMItem(u8 id) {
  if (id == ITEM_ID_CUT) {
    return 1;
  }
  else if (id == ITEM_ID_FLY) {
    return 1;
  }
  else if (id == ITEM_ID_SURF) {
    return 1;
  }
  else if (id == ITEM_ID_STRENGTH) {
    return 1;
  }
  else if (id == ITEM_ID_FLASH) {
    return 1;
  }
  else if (id == ITEM_ID_ROCK_SMASH) {
    return 1;
  }
  else if (id == ITEM_ID_WATERFALL) {
    return 1;
  }
  else if (id == ITEM_ID_DIVE) {
    return 1;
  }
  return 0;
}