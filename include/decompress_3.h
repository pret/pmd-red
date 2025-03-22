#ifndef GUARD_DECOMPRESS_3_H
#define GUARD_DECOMPRESS_3_H

// Returns FALSE if the ascii chars in both strings match, ignoring uppercase/lowercase differences.
// "YeS\0" and "yEs\0" => FALSE
// "Yes\0" and "Tes\0" => TRUE
// "Yes\0" and "y\0" => TRUE
// "T\0" and "Tes\0" => TRUE
bool8 StrsDifferent_IgnoreCase(const char *strA, const char *strB, s32 maxLen);

#endif // GUARD_DECOMPRESS_3_H
