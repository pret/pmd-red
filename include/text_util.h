#ifndef GUARD_TEXT_UTIL_H
#define GUARD_TEXT_UTIL_H

void StrncpyCustom(u8 *buffer, const u8 *string, s32 n); // Regular strncpy, but it calls GetCharId for each char
void CopyStringtoBuffer(u8 *buffer, const u8 *string);
void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size);
s32 ReturnIntFromChar(u8 c);
u32 GetCharId(u8);

#endif
