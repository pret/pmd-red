#include "global.h"

extern void sub_808DE50(void* r0, void * r1, u32 r2, u32 r3);

extern void * gUnknown_203B45C;

void sub_808DE30(void* r0, u32 r1)
{
    sub_808DE50(r0, gUnknown_203B45C + (r1 * 0x58), r1, r1 * 0x58);
}
