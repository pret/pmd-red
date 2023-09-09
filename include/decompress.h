#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "file_system.h"

u32 DecompressAT(u8 *result, s32 resultLength, const u8 *compressedData);
u32 DecompressATFile(u8 *result, s32 resultLength, OpenedFile *file);
u32 DecompressATGlobalFile(u32 *result, s32 resultLength, OpenedFile *file);
u8 *GetSiroPtr(OpenedFile *openedFile);
void nullsub_16(void);

bool8 sub_800B2D4(char *, char *, s32 length);

#endif // GUARD_DECOMPRESS_H