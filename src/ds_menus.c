#include "global.h"
#include "input.h"
#include "text_1.h"

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
    ShowWindows(NULL, TRUE, TRUE);
}
