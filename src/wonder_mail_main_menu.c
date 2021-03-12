#include "global.h"
#include "input.h"

extern u8 *gUnknown_203B3E8;
extern void sub_800641C(void *, u32, u32);
extern void nullsub_54();
extern void sub_8039E18();

void sub_803A1C0(u8 r0)
{
    *gUnknown_203B3E8 = r0;
    nullsub_54();
    sub_8039E18();
}

u32 sub_803A1D8(void)
{
    return 1;
}

u32 sub_803A1DC(void)
{
    return 0;
}

void nullsub_55()
{
}

u32 sub_803A1E4(void)
{
    return 1;
}

u32 sub_803A1E8(void)
{
    return 2;
}

void sub_803A1EC(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
}
