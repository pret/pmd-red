#include "global.h"
#include "decompress_sir.h"

#define MAGIC_SIR0 0x30524953
#define MAGIC_SIRO 0x4F524953

static void NDS_DecompressRLE(const SiroArchive *);

// arm9.bin::020093F4
const void *GetSiroPtr(OpenedFile *openedFile)
{
    const SiroArchive *siro = (const SiroArchive *)openedFile->data;

    if (siro->magic == MAGIC_SIR0)
        NDS_DecompressRLE(openedFile->data);
    else if (siro->magic != MAGIC_SIRO)
        return openedFile->data;

    openedFile->data = siro->data;

    return openedFile->data;
}

// arm9.bin::020093A0
UNUSED static const void *UnusedGetSir0Ptr(const SiroArchive *siro)
{
    if (siro->magic != MAGIC_SIR0)
        return siro;

    NDS_DecompressRLE(siro);
    return siro->data;
}

// arm9.bin::02009324
static void NDS_DecompressRLE(const SiroArchive *siro)
{
}

// TODO: IDK if these two funcs are in blue. Figure it out

void nullsub_16(void)
{
}

UNUSED static void nullsub_175(void)
{
}
