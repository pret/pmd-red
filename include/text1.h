#ifndef GUARD_TEXT1_H
#define GUARD_TEXT1_H

#include "text.h"

extern struct UnkTextStruct1 gUnknown_2027370[4];
extern struct UnkTextStruct2 gUnknown_202AFC0[4];
extern u32 gUnknown_202B030;
extern u16 gUnknown_202B038[4][32][32];

void LoadCharmaps(void);
void SelectCharmap(u32);
u32 xxx_update_some_bg_tiles(u32 a0);

void sub_800641C(struct UnkTextStruct2 *a0, u8 a1, u8 a2);

#endif // GUARD_TEXT1_H