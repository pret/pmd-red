#include "global.h"
#include "dungeon.h"

extern u32 *gStoryMissionText[];
extern const u8 gDummyScenarioText;
extern u32 gUnknown_8109CC0;
extern u8 sub_80A270C();
extern void sub_80015C0(u8, u8);

const u8 *sub_809747C(s16 r0)
{
    if(r0 == 0xD)
    {
        return &gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C());
    }
}

const u8 *sub_80974A0(s16 r0)
{
    if(r0 == 0xD)
    {
        return &gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C());
    }
}

#ifndef NONMATCHING
NAKED
#endif
u32 *sub_80974C4(s16 r0)
{
#ifdef NONMATCHING
    // TODO fix regswap memes of r0/r1
    if(r0 <= 0x1E)
    {
        return gStoryMissionText[(r0 << 1)];
    }
    else
    {
        return &gUnknown_8109CC0;
    }
#else
	asm_unified("\tpush {lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tcmp r0, 0x1E\n"
	"\tble _080974D8\n"
	"\tldr r0, _080974D4\n"
	"\tb _080974E0\n"
	"\t.align 2, 0\n"
"_080974D4: .4byte gUnknown_8109CC0\n"
"_080974D8:\n"
	"\tlsls r0, 3\n"
	"\tldr r1, _080974E4\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
"_080974E0:\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_080974E4: .4byte gStoryMissionText");

#endif
} 

void sub_80974E8(void)
{
    sub_80015C0(0, 0x2E);
    sub_80015C0(0, 0x2F);
}

void nullsub_208(void)
{
}
