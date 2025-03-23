#ifndef GUARD_DECOMPRESS_SIR_H
#define GUARD_DECOMPRESS_SIR_H

#include "file_system.h"

// size: 0x8
typedef struct SiroArchive
{
    /* 0x0 */ u32 magic;
    /* 0x4 */ const void *data;
} SiroArchive;

const void *GetSiroPtr(OpenedFile *openedFile);
void nullsub_16(void);

#endif // GUARD_DECOMPRESS_SIR_H
