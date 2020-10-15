#include "global.h"

extern u8 gUnknown_203B150;

void nullsub_199(void)
{
}

void nullsub_27(void)
{
}

void sub_8011B08(void)
{
    gUnknown_203B150 = 1;
}

void sub_8011B14(void)
{
    gUnknown_203B150 = 0;
}

#ifndef NONMATCHING
NAKED
#endif
u8 sub_8011B20(void)
{
#ifdef NONMATCHING
    // TODO figure out why I mix up my mv/ldr for these kinds of comparisons
    u8 temp;
    if(gUnknown_203B150 == 0)
    {
        temp = 1;
    }
    else
    {
        temp = 0;
    }
    gUnknown_203B150 = temp;
    return gUnknown_203B150;
#else
	asm_unified("\tpush {lr}\n"
	"\tldr r1, _08011B38\n"
	"\tmovs r2, 0\n"
	"\tldrb r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbne _08011B2E\n"
	"\tmovs r2, 0x1\n"
"_08011B2E:\n"
	"\tstrb r2, [r1]\n"
	"\tldrb r0, [r1]\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08011B38: .4byte gUnknown_203B150");
#endif
}

// unused
u8 sub_8011B3C(void)
{
    return gUnknown_203B150;
}

// unused
void nullsub_137(void)
{

}
