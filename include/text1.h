#ifndef GUARD_TEXT1_H
#define GUARD_TEXT1_H

#include "text.h"

extern UnkTextStruct1 gUnknown_2027370[4];
extern UnkTextStruct2 gUnknown_202AFC0[4];
extern u32 gUnknown_202B030;
extern u16 gUnknown_202B038[4][32][32]; // dimensions unknown... but usage points to these dimensions

void LoadCharmaps(void);
void SelectCharmap(u32);
u32 xxx_update_some_bg_tiles(u32 a0);

u32 sub_80063B0(void);
void sub_800641C(UnkTextStruct2 *a0, bool8 a1, bool8 a2);

#endif // GUARD_TEXT1_H