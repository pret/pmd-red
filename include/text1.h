#ifndef GUARD_TEXT1_H
#define GUARD_TEXT1_H

#include "structs/str_text.h"

extern UnkTextStruct1 gUnknown_2027370[4];
extern UnkTextStruct2 gUnknown_202AFC0[4];
extern u32 gTextShadowMask;
extern u16 gUnknown_202B038[4][32][32]; // dimensions unknown... but usage points to these dimensions

void LoadCharmaps(void);
void SelectCharmap(u32);
u32 UpdateFadeInTile(u32 a0);

u32 sub_80063B0(void);
void xxx_call_save_unk_text_struct_800641C(const UnkTextStruct2 *a0, bool8 a1, bool8 a2);

#endif // GUARD_TEXT1_H
