#include "global.h"

extern void MemoryFree(void *);

extern u8 *gUnknown_203B194;

void sub_80129FC()
{
    if (gUnknown_203B194) {
        MemoryFree(gUnknown_203B194);
        gUnknown_203B194 = NULL;
    }
}
