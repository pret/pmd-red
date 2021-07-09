#include "global.h"
#include "item.h"
#include "gUnknown_203B460.h"

#include <stddef.h>

extern struct unkStruct_203B460 *gUnknown_203B460;

extern s32 sub_80915D4(struct ItemStruct_203B460 *);
extern void sub_80910B4();
extern void sub_80913A0(s32);

bool8 sub_8091290(const struct ItemStruct_203B460* x) {
  s32 i;

  // try to add item to inventory, return 1 if failed
  for (i = 0; i < 20; i++) {
    UNUSED struct ItemStruct_203B460* current = &gUnknown_203B460->fill0[i];
    if (!(i[gUnknown_203B460->fill0].unk0 & 1)) {
      gUnknown_203B460->fill0[i] = *x;
      return 0;
    }
  }
  return 1;
}


void sub_80912C8() {
  s32 i = 0;

  do {
    UNUSED struct unkStruct_203B460 * _gUnknown_203B460 = gUnknown_203B460;
    UNUSED size_t offs = offsetof(struct unkStruct_203B460, fill0[i]);

    struct ItemStruct_203B460* current_slot = &gUnknown_203B460->fill0[i];
    if ((current_slot->unk0 & 1) && (current_slot->itemIndex == 105)) {
      s32 result;

      result = sub_80915D4(current_slot);
      sub_80913A0(result);
      current_slot->itemIndex = 0;
      current_slot->numItems = 0;
      current_slot->unk0 = 0;
    }
  } while (++i < 20);
  sub_80910B4();

  i = 0;
  do {
    s32 lowest_index = -1;
    UNUSED size_t offs = offsetof(struct unkStruct_203B460, fill0[i]);

    bool8 item_occupied = i[gUnknown_203B460->fill0].unk0 & 1;
    s32 next = i + 1;
    
    if (item_occupied) {
      s32 lowest_order = GetItemOrder(gUnknown_203B460->fill0[i].itemIndex);
      s32 j;

      // find next lowest
      for (j = next; j < 20; j++) {
        UNUSED size_t offs = offsetof(struct unkStruct_203B460, fill0[j]);
        if ((j[gUnknown_203B460->fill0].unk0 & 1) && (lowest_order > GetItemOrder(gUnknown_203B460->fill0[j].itemIndex))) {
          lowest_index = j;
          lowest_order = GetItemOrder(gUnknown_203B460->fill0[j].itemIndex);
        }
      }

      if (lowest_index >= 0) {
        // swap the slots
        struct ItemStruct_203B460 current = gUnknown_203B460->fill0[i];
        gUnknown_203B460->fill0[i] = gUnknown_203B460->fill0[lowest_index]; 
        gUnknown_203B460->fill0[lowest_index] = current;
      }
    }
  } while (++i < 20);
  sub_80910B4();
}