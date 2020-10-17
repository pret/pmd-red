#include "global.h"

extern bool8 gInterruptsEnabled;
extern u32 gIntrTable[];
extern u32 IntrMain;
extern u8 gUnknown_202D4B8;
extern u32 gUnknown_202D5F0[];

bool8 EnableInterrupts(void)
{
    if(gInterruptsEnabled == FALSE)
    {
        return FALSE;
    }

    if((REG_IME & 1) != 0)
    {
        return FALSE;
    }
    else
    {
        REG_IME = 1;
        return TRUE;
    }
}

bool8 DisableInterrupts(void)
{
    if(gInterruptsEnabled == 0)
    {
        return FALSE;
    }

    if((REG_IME & 1) == 0)
    {
        return FALSE;
    }
    else
    {
        REG_IME = 0;
        return TRUE;
    }

}

bool8 sub_800B650(void)
{
    if(gInterruptsEnabled == FALSE)
    {
        return FALSE;
    }

    if((REG_IME & 1) != 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void SetInterruptFlag(u16 flag)
{
    if(gInterruptsEnabled == FALSE)
    {
        return;
    }

    REG_IME = 0;
    INTR_CHECK |= flag;
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

u32 sub_800B6F4(u32 r0, u32 r1)
{
    u32 temp;
    u32 interrupt_var;

    interrupt_var = DisableInterrupts();
    temp = gUnknown_202D5F0[r0];
    gUnknown_202D5F0[r0] = r1;
    if(interrupt_var != FALSE){
        EnableInterrupts();
    }
    return temp;
}
