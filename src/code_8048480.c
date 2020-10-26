#include "global.h"

extern void sub_807D148(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_8075FCC(void);
extern void sub_8077AE4(u32 r0, u32 r1, u32 r2);
extern void sub_8072008(u32 r0, u32 r1, u32 r2, u8 r3);
extern void sub_8076D10(void);
extern void sub_80522F4(u32 r0, u32 r1, u32 r2);
extern void sub_807232C(u32 r0, u32 r1, u32 r2);
extern u32 gUnknown_80F89F4;

void sub_8048480(u32 r0, u32 r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(void)
{
    sub_8075FCC();
}

void sub_804849C(u32 r0, u32 r1)
{
    sub_8077AE4(r0, r1, 1);
}

#ifndef NONMATCHING
NAKED
#endif
void sub_80484A8(u32 r0, u32 r1)
{   
#ifdef NONMATCHING
    // TODO missing something on the stack
    u32 *temp;
    *temp = 1;
    sub_8072008(r0, r1, 1, 1);
#else
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0x4\n"
	"\tmovs r2, 0x1\n"
	"\tstr r2, [sp]\n"
	"\tmovs r3, 0x1\n"
	"\tbl sub_8072008\n"
	"\tadd sp, 0x4\n"
	"\tpop {r0}\n"
	"\tbx r0");
#endif
}

void sub_80484BC(void)
{
    sub_8076D10();
}

void sub_80484C8(u32 r0, u32 r1)
{
    sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_80484DC(u32 r0, u32 r1)
{
    sub_807232C(r0, r1, 1);
}
