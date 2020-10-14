#include "global.h"

#include "global.h"

extern u8 gUnknown_203B098;

u8 sub_800B5F0(void)
{
    if(gUnknown_203B098 == 0)
    {
        return 0;
    }

    if((REG_IME & 1) != 0)
    {
        return 0;
    }
    else
    {
        REG_IME = 1;
        return 1;
    }
}

u8 sub_800B620(void)
{
    if(gUnknown_203B098 == 0)
    {
        return 0;
    }

    if((REG_IME & 1) == 0)
    {
        return 0;
    }
    else
    {
        REG_IME = 0;
        return 1;
    }

}

u8 sub_800B650(void)
{
    if(gUnknown_203B098 == 0)
    {
        return 0;
    }

    if((REG_IME & 1) != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void sub_800B67C(u16 r0)
{
    if(gUnknown_203B098 == 0)
    {
        return;
    }

    REG_IME = 0;
    INTR_CHECK |= r0;
    REG_IME = 1;
}
