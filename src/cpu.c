#include "global.h"

extern u32 gUnknown_202D800;
extern u16 gUnknown_202D7FC; // used to update Blend Count Reg
extern u16 gUnknown_203B0BE[];

void sub_800CDA8(u32 r0)
{
    gUnknown_202D800 = r0;
    gUnknown_202D7FC = gUnknown_203B0BE[r0];
}

u32 sub_800CDC8(void)
{
    return gUnknown_202D800;
}

void SetWindowTitle(char *title)
{
}

void nullsub_23(void)
{
}

void nullsub_182(void)
{
}

u32 sub_800CDE0(void)
{
    return 1;
}

void CpuCopy(void* src, void *dest, s32 size)
{
    CPU_COPY(dest, src, size, 32);
}

void CpuClear(void* dest, s32 size)
{
    CPU_FILL(NULL, dest, size, 32);
}

void CpuFill(void* src, void *dest, s32 size)
{
    CPU_FILL(dest, src, size, 32);
}

#ifdef NONMATCHING
void sub_800CE54(void)
{
    // TODO this is so gross.. looks like a macro or something else but I don't want to deal with this rn
    REG_DMA0CNT_H = (REG_DMA0CNT_H | DMA_ENABLE) & 0xcdff;
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    REG_DMA0CNT_H &= 0x7fff;

    // Everything below matches

    REG_WININ = WININ_WIN0_ALL | WININ_WIN1_ALL;
    REG_WINOUT = WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WIN01_BG3 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG0;
    REG_BLDCNT = gUnknown_202D7FC;
    REG_BLDALPHA = gUnknown_202D7FA;
    if(gUnknown_2026E38 != 0)
    {
        DmaSet(0, &gUnknown_2026E3C[2], REG_ADDR_WIN0H, 0xa2600002);
        REG_WIN0H = gUnknown_2026E3C[0];
        REG_WIN1H = gUnknown_2026E3C[1];
        REG_WIN0V = 160;
        REG_WIN1V = 160;
    }
    else
    {
        REG_WIN0H = 0;
        REG_WIN1H = 0;
        REG_WIN0V = 0;
        REG_WIN1V = 0;
    }
}
#else
NAKED
void sub_800CE54(void)
{
	asm_unified("\tpush {lr}\n"
	"\tldr r2, _0800CEC0\n"
	"\tldrh r0, [r2]\n"
	"\tmovs r3, 0x80\n"
	"\tlsls r3, 8\n"
	"\tadds r1, r3, 0\n"
	"\torrs r0, r1\n"
	"\tldr r1, _0800CEC4\n"
	"\tands r0, r1\n"
	"\tstrh r0, [r2]\n"
	"\tmov r8, r8\n"
	"\tmov r8, r8\n"
	"\tmov r8, r8\n"
	"\tmov r8, r8\n"
	"\tldr r1, _0800CEC8\n"
	"\tands r0, r1\n"
	"\tstrh r0, [r2]\n"
	"\tldr r1, _0800CECC\n"
	"\tldr r2, _0800CED0\n"
	"\tadds r0, r2, 0\n"
	"\tstrh r0, [r1]\n"
	"\tadds r1, 0x2\n"
	"\tmovs r0, 0x3D\n"
	"\tstrh r0, [r1]\n"
	"\tadds r1, 0x6\n"
	"\tldr r0, _0800CED4\n"
	"\tldrh r0, [r0]\n"
	"\tstrh r0, [r1]\n"
	"\tadds r1, 0x2\n"
	"\tldr r0, _0800CED8\n"
	"\tldrh r0, [r0]\n"
	"\tstrh r0, [r1]\n"
	"\tldr r0, _0800CEDC\n"
	"\tldrb r1, [r0]\n"
	"\tcmp r1, 0\n"
	"\tbeq _0800CEF4\n"
	"\tldr r1, _0800CEE0\n"
	"\tldr r0, _0800CEE4\n"
	"\tldr r2, [r0]\n"
	"\tadds r0, r2, 0x4\n"
	"\tstr r0, [r1]\n"
	"\tldr r3, _0800CEE8\n"
	"\tstr r3, [r1, 0x4]\n"
	"\tldr r0, _0800CEEC\n"
	"\tstr r0, [r1, 0x8]\n"
	"\tldr r0, [r1, 0x8]\n"
	"\tldrh r0, [r2]\n"
	"\tstrh r0, [r3]\n"
	"\tsubs r1, 0x6E\n"
	"\tldrh r0, [r2, 0x2]\n"
	"\tstrh r0, [r1]\n"
	"\tldr r0, _0800CEF0\n"
	"\tmovs r1, 0xA0\n"
	"\tb _0800CEFE\n"
	"\t.align 2, 0\n"
"_0800CEC0: .4byte 0x040000ba\n"
"_0800CEC4: .4byte 0x0000cdff\n"
"_0800CEC8: .4byte 0x00007fff\n"
"_0800CECC: .4byte 0x04000048\n"
"_0800CED0: .4byte 0x00003f3f\n"
"_0800CED4: .4byte gUnknown_202D7FC\n"
"_0800CED8: .4byte gUnknown_202D7FA\n"
"_0800CEDC: .4byte gUnknown_2026E38\n"
"_0800CEE0: .4byte 0x040000b0\n"
"_0800CEE4: .4byte gUnknown_2026E3C\n"
"_0800CEE8: .4byte 0x04000040\n"
"_0800CEEC: .4byte 0xa2600002\n"
"_0800CEF0: .4byte 0x04000044\n"
"_0800CEF4:\n"
	"\tldr r0, _0800CF08\n"
	"\tstrh r1, [r0]\n"
	"\tadds r0, 0x2\n"
	"\tstrh r1, [r0]\n"
	"\tadds r0, 0x2\n"
"_0800CEFE:\n"
	"\tstrh r1, [r0]\n"
	"\tadds r0, 0x2\n"
	"\tstrh r1, [r0]\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800CF08: .4byte 0x04000040");
}
#endif
