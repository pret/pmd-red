#ifndef GUARD_TEXT_UTIL_H
#define GUARD_TEXT_UTIL_H

void sub_80922B4(u8 *buffer, const u8 *string, s32 size);
u32 sub_80922E4(u32 r0);
void CopyStringtoBuffer(u8 *buffer, u8 *string);
void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size);
const char *GetUnformattedTypeString(u8 type);
const char * GetFormattedTypeString(u8 type);
u8 IsTypePhysical(u8 index);
u8 sub_8092364(u8 index);
void CopyAbilityNametoBuffer(char *buffer, u8 index);
const u8 *GetAbilityDescription(u8 index);
u32 ReturnIntFromChar2(u8);

#endif
