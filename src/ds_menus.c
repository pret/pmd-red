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

u32 CreateDualSlotMenu(void)
{
    return 1;
}

u32 UpdateDualSlotMenu(void)
{
    return 0;
}

void CleanDualSlotMenu()
{
}

u32 CreateWirelessCommsMenu(void)
{
    return 1;
}

u32 UpdateWirelessCommsMenu(void)
{
    return 2;
}

void CleanWirelessCommsMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
}
