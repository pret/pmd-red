#include "global.h"
#include "item.h"
#include "gUnknown_203B460.h"

extern struct unkStruct_203B460 *gUnknown_203B460;

bool8 sub_8091290(const struct ItemStruct_203B460* x) {
  s32 i;

  for (i = 0; i < 20; i++) {
    __attribute__((unused)) struct ItemStruct_203B460* current = &gUnknown_203B460->fill0[i];
    if (!(i[gUnknown_203B460->fill0].unk0 & 1)) {
      gUnknown_203B460->fill0[i] = *x;
      return 0;
    }
  }
  return 1;
}