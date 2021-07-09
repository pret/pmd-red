#include "global.h"
#include "item.h"
#include "gUnknown_203B460.h"
#include "subStruct_203B240.h"

#include <stddef.h>

extern struct unkStruct_203B460 *gUnknown_203B460;
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
    UNUSED struct ItemSlot* current = &gUnknown_203B460->teamItems[i];
    if (!(i[gUnknown_203B460->teamItems].unk0 & 1)) {
      gUnknown_203B460->teamItems[i] = *slot;
      return 0;
    }
  }
  return 1;
}


void ConvertMoneyItemToMoney() 
{
  s32 i = 0;

  do {
    UNUSED struct unkStruct_203B460 * _gUnknown_203B460 = gUnknown_203B460;
    UNUSED size_t offs = offsetof(struct unkStruct_203B460, teamItems[i]);

    struct ItemSlot* current_slot = &gUnknown_203B460->teamItems[i];
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
    UNUSED size_t offs = offsetof(struct unkStruct_203B460, teamItems[i]);

    bool8 item_occupied = i[gUnknown_203B460->teamItems].unk0 & 1;
    s32 next = i + 1;
    
    if (item_occupied) {
      s32 lowest_order = GetItemOrder(gUnknown_203B460->teamItems[i].itemIndex);
      s32 j;

      // find next lowest
      for (j = next; j < 20; j++) {
        UNUSED size_t offs = offsetof(struct unkStruct_203B460, teamItems[j]);
        if ((j[gUnknown_203B460->teamItems].unk0 & 1) && (lowest_order > GetItemOrder(gUnknown_203B460->teamItems[j].itemIndex))) {
          lowest_index = j;
          lowest_order = GetItemOrder(gUnknown_203B460->teamItems[j].itemIndex);
        }
      }

      if (lowest_index >= 0) {
        // swap the slots
        struct ItemSlot current = gUnknown_203B460->teamItems[i];
        gUnknown_203B460->teamItems[i] = gUnknown_203B460->teamItems[lowest_index]; 
        gUnknown_203B460->teamItems[lowest_index] = current;
      }
    }
  } while (++i < 20);
  sub_80910B4();
}

void AddToTeamMoney(s32 amount)
{
  s32 clamped_money;
  gUnknown_203B460->teamMoney += amount;

  // clamp money
  clamped_money = 99999;
  if (gUnknown_203B460->teamMoney <= 99999) {
    if (gUnknown_203B460->teamMoney >= 0) {
      return;
    }
    clamped_money = 0;
  }
  gUnknown_203B460->teamMoney = clamped_money;
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