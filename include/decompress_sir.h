#ifndef GUARD_DECOMPRESS_SIR_H
#define GUARD_DECOMPRESS_SIR_H

#include "file_system.h"

// size: 0x10
typedef struct SiroArchive
{
    /* 0x0 */ u8 magic[4];
    /* 0x4 */ const void *data;
    /* 0x8 */ u32 unused1; // Always 0
    /* 0xC */ u32 unused2; // Always 0
} SiroArchive;

const void *GetSiroPtr(OpenedFile *openedFile);
void nullsub_16(void);

#endif // GUARD_DECOMPRESS_SIR_H
