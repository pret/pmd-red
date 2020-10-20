#include "global.h"
#include "code_800558C.h"

extern u32 gUnknown_203B47C;

extern u8 gUnknown_2026E38;
extern u32 gUnknown_2026E3C;
extern u16 gUnknown_2026E4E;
extern u32 gUnknown_2026E50;
extern u32 gUnknown_2026E54;
extern u32 gUnknown_2026E58;

extern void sub_800CC44(u32 r0, u32 r1);

// Unused
#ifndef NONMATCHING
NAKED
#endif
void sub_80060A8(void)
{
#ifdef NONMATCHING
    // TODO ordering of statements is wrong but regs are good so f*** it.
    // My mv/ldr stuff for temp is out of order
    u32 temp;
    gUnknown_2026E3C = gUnknown_2026E58;

    temp = 0;
    if (gUnknown_2026E54  == 0)
    {
        temp = 1;
    }
    gUnknown_2026E54 = temp;

    temp = 0;

    if (gUnknown_2026E50  == 0)
    {
        temp = 1;
    }
    gUnknown_2026E50 = temp;
    
    gUnknown_2026E38 = 0;
#else
	asm_unified("\tpush {lr}\n"
	"\tldr r1, _080060D8\n"
	"\tldr r0, _080060DC\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r1]\n"
	"\tldr r2, _080060E0\n"
	"\tmovs r1, 0\n"
	"\tldr r0, [r2]\n"
	"\tcmp r0, 0\n"
	"\tbne _080060BE\n"
	"\tmovs r1, 0x1\n"
"_080060BE:\n"
	"\tstr r1, [r2]\n"
	"\tldr r2, _080060E4\n"
	"\tmovs r1, 0\n"
	"\tldr r0, [r2]\n"
	"\tcmp r0, 0\n"
	"\tbne _080060CC\n"
	"\tmovs r1, 0x1\n"
"_080060CC:\n"
	"\tstr r1, [r2]\n"
	"\tldr r1, _080060E8\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r1]\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080060D8: .4byte gUnknown_2026E3C\n"
"_080060DC: .4byte gUnknown_2026E58\n"
"_080060E0: .4byte gUnknown_2026E54\n"
"_080060E4: .4byte gUnknown_2026E50\n"
"_080060E8: .4byte gUnknown_2026E38");

#endif
}

#ifndef NONMATCHING
NAKED
#endif
void sub_80060EC(void)
{
#ifdef NONMATCHING
    // TODO ordering of statements is wrong but regs are good so f*** it.
    u32 temp;
    gUnknown_2026E3C = gUnknown_2026E58;
    temp = 0;

    if (gUnknown_2026E54  == 0)
    {
        temp = 1;
    }
    gUnknown_2026E54 = temp;

    temp = 0;

    if (gUnknown_2026E50  == 0)
    {
        temp = 1;
    }
    gUnknown_2026E50 = temp;
    
    sub_800CC44((gUnknown_2026E4E & (0xF8 << 5)) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = 1;
#else
            asm_unified("\tpush {lr}\n"
            "\tldr r1, _08006130\n"
            "\tldr r0, _08006134\n"
            "\tldr r0, [r0]\n"
            "\tstr r0, [r1]\n"
            "\tldr r2, _08006138\n"
            "\tmovs r1, 0\n"
            "\tldr r0, [r2]\n"
            "\tcmp r0, 0\n"
            "\tbne _08006102\n"
            "\tmovs r1, 0x1\n"
    "_08006102:\n"
            "\tstr r1, [r2]\n"
            "\tldr r2, _0800613C\n"
            "\tmovs r1, 0\n"
            "\tldr r0, [r2]\n"
            "\tcmp r0, 0\n"
            "\tbne _08006110\n"
            "\tmovs r1, 0x1\n"
    "_08006110:\n"
            "\tstr r1, [r2]\n"
            "\tldr r0, _08006140\n"
            "\tldrh r2, [r0]\n"
            "\tmovs r0, 0xF8\n"
            "\tlsls r0, 5\n"
            "\tands r0, r2\n"
            "\tlsrs r0, 8\n"
            "\tmovs r1, 0x1F\n"
            "\tands r1, r2\n"
            "\tbl sub_800CC44\n"
            "\tldr r1, _08006144\n"
            "\tmovs r0, 0x1\n"
            "\tstrb r0, [r1]\n"
            "\tpop {r0}\n"
            "\tbx r0\n"
            "\t.align 2, 0\n"
    "_08006130: .4byte gUnknown_2026E3C\n"
    "_08006134: .4byte gUnknown_2026E58\n"
    "_08006138: .4byte gUnknown_2026E54\n"
    "_0800613C: .4byte gUnknown_2026E50\n"
    "_08006140: .4byte gUnknown_2026E4E\n"
    "_08006144: .4byte gUnknown_2026E38");
#endif
}
