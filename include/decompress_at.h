#ifndef GUARD_DECOMPRESS_AT_H
#define GUARD_DECOMPRESS_AT_H

#include "file_system.h"

u32 DecompressAT(u8 *dst, s32 dstLen, const u8 *src);
u32 DecompressATFile(void *dst, s32 dstLen, OpenedFile *file);
u32 DecompressATGlobalFile(u32 *result, s32 resultLength, OpenedFile *file);

#endif // GUARD_DECOMPRESS_AT_H
