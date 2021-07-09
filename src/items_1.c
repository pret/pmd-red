#include "global.h"
#include "item.h"
#include "gUnknown_203B460.h"

#include <stddef.h>

extern struct unkStruct_203B460 *gUnknown_203B460;
extern EWRAM_DATA struct Item *gItemParametersData;

extern s32 sub_80915D4(struct ItemSlot *);
extern void sub_80910B4();

bool8 AddItemToInventory(const struct ItemSlot* slot) {
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


void RemoveMoneyFromInventory() {
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

void AddToTeamMoney(s32 amount) {
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

u16 GetItemMove(u8 index) {
  return gItemParametersData[index & 0xff].move;
}