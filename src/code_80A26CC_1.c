#include "global.h"

extern u32 sub_8001658(u32, u32);
extern const char *sub_80A2B18(s16);

const char *sub_80A2B28(u16 r0)
{
    return sub_80A2B18(sub_8001658(0, 17));
}
