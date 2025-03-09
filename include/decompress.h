#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "file_system.h"

u32 DecompressAT(u8 *dst, s32 dstLen, const u8 *src);
u32 DecompressATFile(void *dst, s32 dstLen, OpenedFile *file);
u32 DecompressATGlobalFile(u32 *result, s32 resultLength, OpenedFile *file);
const u8 *GetSiroPtr(OpenedFile *openedFile);
void nullsub_16(void);

// Returns FALSE if the ascii chars in both strings match, ignoring uppercase/lowercase differences.
// "YeS\0" and "yEs\0" => FALSE
// "Yes\0" and "Tes\0" => TRUE
// "Yes\0" and "y\0" => TRUE
// "T\0" and "Tes\0" => TRUE
bool8 StrsDifferent_IgnoreCase(char *strA, char *strB, s32 maxLen);

#endif // GUARD_DECOMPRESS_H
