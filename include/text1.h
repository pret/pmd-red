#ifndef GUARD_TEXT1_H
#define GUARD_TEXT1_H

#include "text.h"

extern EWRAM_DATA struct UnkTextStruct2 gUnknown_202AFC0[4];
extern EWRAM_DATA u16 gUnknown_202B038[4][32][32];

void LoadCharmaps(void);
void SelectCharmap(u32);
u32 xxx_update_some_bg_tiles(u32 a0);

void sub_800641C(struct UnkTextStruct2 *a0, u8 a1, u8 a2);

#endif // GUARD_TEXT1_H