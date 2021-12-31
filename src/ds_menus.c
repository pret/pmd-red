#include "global.h"
#include "input.h"
#include "text.h"

u32 CreateDualSlotMenu(void)
{
    return 1;
}

u32 UpdateDualSlotMenu(void)
{
    return 0;
}

void CleanDualSlotMenu(void)
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
