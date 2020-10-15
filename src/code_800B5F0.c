#include "global.h"

#include "global.h"

extern u8 gUnknown_203B098;
extern u32 gIntrTable[];
extern u32 IntrMain;
extern u8 gUnknown_202D4B8;

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

void sub_800B6B0(const u32 *r0)
{
    CpuCopy32(r0, &gIntrTable, 0x18); // 0x18 = 0x6 * 4 (0x4f00 is 32 bits)
    CpuCopy32(&IntrMain, &gUnknown_202D4B8, 0x120); // 0x120 = 0x48 * 4 (0x4f00 is 32 bits)
    INTR_VECTOR = &gUnknown_202D4B8;
}

u32 *sub_800B6E8(u32 r0)
{
    return &gIntrTable[r0];
}
