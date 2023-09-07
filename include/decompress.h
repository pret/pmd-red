#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "file_system.h"

u32 DecompressAT(u8 *, s32, const u8 *);
u32 DecompressATFile(u8 *, s32, OpenedFile *);
u32 DecompressATGlobalFile(u32 *, s32, OpenedFile *);
u8 *GetSiroPtr(OpenedFile *);
void nullsub_16(void);

bool8 sub_800B2D4(char *, char *, s32);

#endif // GUARD_DECOMPRESS_H