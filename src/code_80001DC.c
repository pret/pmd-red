#include "global.h"

extern u32 gUnknown_3004000;

// unused, returns stack pointer
u32 sub_80001DC() {
    return (u32)__builtin_frame_address(0);
}

u32 *sub_80001E0(void)
{
    return &gUnknown_3004000;
}
