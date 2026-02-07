#ifndef GUARD_EFFECT_SUB_2_H
#define GUARD_EFFECT_SUB_2_H

#include "structs/effect_data.h"
#include "structs/str_file_system.h"

void sub_800F034(void);
void sub_800F078(void);
void sub_800F094(void);
s32 sub_800F0F4(s32 animType, s32 effectID);
void sub_800F13C(s32 index, OpenedFile *file, const unkStruct_80B9CC4 *r2);
void sub_800F15C(s32 effectID);
unkStruct_800F18C *sub_800F18C(s32 index);
bool8 sub_800F19C(s32 index);

#endif // GUARD_EFFECT_SUB_2_H
