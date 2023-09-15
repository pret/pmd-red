#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

void ReverseString(u8 *s, s32 len);
s32 ConvertToDecimal(s32 *decimal, s32 n, s32 len);
s32 ConvertFromDecimal(s32 *decimal, s32 sign, s32 len);
s32 ConvertFromBCD(s32 bcd);
s32 ConvertToBCD(s32 n);

#endif // GUARD_UTIL_H