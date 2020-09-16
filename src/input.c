#include "global.h"
#include "input.h"

extern struct Input gUnknown_2025600;
extern struct test gUnknown_20255F0;
extern struct test gUnknown_2025638;
extern struct test gUnknown_2025648;
extern struct test3 gUnknown_2025668;
extern u32 gUnknown_202562C;

#ifndef NONMATCHING
NAKED
#endif
void InitInput(void)
{
#ifdef NONMATCHING
    gUnknown_20255F0.unk0 = 0;
    gUnknown_20255F0.unk1 = 0;
    gUnknown_20255F0.unk2 = 0;
    gUnknown_20255F0.unk3 = 0;

    gUnknown_2025638.unk0 = 0;
    gUnknown_2025638.unk1 = 0;
    gUnknown_2025638.unk2 = 0;
    gUnknown_2025638.unk3 = 0;

    gUnknown_202562C = 4854977; // ????? (0x4a14c1)

    gUnknown_2025600.unk16 = 0; // TODO: should be str but generates strh
    gUnknown_2025600.unk0 = 0xffff; // probably a mask
    gUnknown_2025600.unk1 = -1;
    gUnknown_2025600.unk2 = -1;
    gUnknown_2025600.unk3 = -1;
    gUnknown_2025600.unk14 = -1;
    gUnknown_2025600.unk15 = -1;
    gUnknown_2025600.unk4 = -1;
    gUnknown_2025600.unk5 = -1;
    gUnknown_2025600.unk6 = -1;
    gUnknown_2025600.unk7 = -1;
    gUnknown_2025600.unk8 = -1;
    gUnknown_2025600.unk9 = -1;
    gUnknown_2025600.unk10 = -1;
    gUnknown_2025600.unk11 = -1;
    gUnknown_2025600.unk18 = 0;
    gUnknown_2025600.unk19 = 0;

    gUnknown_2025668.unk0 = 0;
    gUnknown_2025668.unk1 = 0;
#else
    asm_unified("\tldr r0, =gUnknown_20255F0\n"
       "\tmovs r3, 0\n"
       "\tmovs r2, 0\n"
       "\tstrh r2, [r0] \n"
       "\tstrh r2, [r0, 0x2]\n"
       "\tstrh r2, [r0, 0x4]\n"
       "\tstrh r2, [r0, 0x6]\n"
       "\tldr r0, =gUnknown_2025638\n"
       "\tstrh r2, [r0]\n"
       "\tstrh r2, [r0, 0x2]\n"
       "\tstrh r2, [r0, 0x4]\n"
       "\tstrh r2, [r0, 0x6]\n"
       "\tldr r1, =gUnknown_202562C\n"
       "\tldr r0, =0x4a14c1\n"
       "\tstr r0, [r1]\n"
       "\tldr r0, =gUnknown_2025600\n"
       "\tstr r2, [r0, 0x20]\n"
       "\tldr r1, =0xffff\n"
       "\tstrh r1, [r0] \n"
       "\tmovs r1, 0x1\n"
       "\tnegs r1, r1\n"
       "\tstrh r1, [r0, 0x2]\n"
       "\tstrh r1, [r0, 0x4]\n"
       "\tstrh r1, [r0, 0x6]\n"
       "\tstrh r1, [r0, 0x1C]\n"
       "\tstrh r1, [r0, 0x1E]\n"
       "\tstrh r1, [r0, 0x8]\n"
       "\tstrh r1, [r0, 0xA]\n"
       "\tstrh r1, [r0, 0xC]\n"
       "\tstrh r1, [r0, 0xE]\n"
       "\tstrh r1, [r0, 0x10]\n"
       "\tstrh r1, [r0, 0x12]\n"
       "\tstrh r1, [r0, 0x14]\n"
       "\tstrh r1, [r0, 0x16]\n"
       "\tadds r1, r0, 0\n"
       "\tadds r1, 0x28\n"
       "\tstrb r3, [r1]\n"
       "\tadds r0, 0x29\n"
       "\tstrb r3, [r0]\n"
       "\tldr r0, =gUnknown_2025668\n"
       "\tstrh r2, [r0]\n"
       "\tstrh r2, [r0, 0x2]\n"
       "\tbx lr\n"
       "\t.align 2, 0\n"
       "\t.pool");
#endif
}

#ifndef NONMATCHING
NAKED
#endif
void sub_800485C(void)
{
#ifdef NONMATCHING
    gUnknown_20255F0 = gUnknown_2025638;

    // TODO missing:
    // ldr r0, [r0]
    // str r0, [r1]

    gUnknown_2025638.unk0 = 0;
    gUnknown_2025638.unk1 = 0;
    gUnknown_2025638.unk2 = 0;
    gUnknown_2025638.unk3 = 0;

    gUnknown_2025600.unk0 = 0xffff;
    gUnknown_2025600.unk1 = -1;
    gUnknown_2025600.unk2 = -1;
    gUnknown_2025600.unk3 = -1;
    gUnknown_2025600.unk4 = -1;
    gUnknown_2025600.unk5 = -1;
    gUnknown_2025600.unk6 = -1;
    gUnknown_2025600.unk7 = -1;
    gUnknown_2025600.unk8 = -1;
    gUnknown_2025600.unk9 = -1;
    gUnknown_2025600.unk10 = -1;
    gUnknown_2025600.unk11 = -1;

    gUnknown_2025600.unk18 = 0;
    gUnknown_2025600.unk19 = 0;
#else
    asm_unified("\tpush {r4,r5,lr}\n"
	"\tldr r2, =gUnknown_2025638\n"
	"\tldr r1, =gUnknown_20255F0\n"
	"\tadds r0, r2, 0\n"
	"\tldm r0!, {r3-r5}\n"
	"\tstm r1!, {r3-r5}\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r1]\n"
	"\tmovs r3, 0\n"
	"\tmovs r0, 0\n"
	"\tstrh r0, [r2]\n"
	"\tstrh r0, [r2, 0x2]\n"
	"\tstrh r0, [r2, 0x4]\n"
	"\tstrh r0, [r2, 0x6]\n"
	"\tldr r0, =gUnknown_2025600\n"
	"\tldr r1, =0xffff\n"
	"\tstrh r1, [r0]\n"
	"\tmovs r1, 0x1\n"
	"\tnegs r1, r1\n"
	"\tstrh r1, [r0, 0x2]\n"
	"\tstrh r1, [r0, 0x4]\n"
	"\tstrh r1, [r0, 0x6]\n"
	"\tstrh r1, [r0, 0x8]\n"
	"\tstrh r1, [r0, 0xA]\n"
	"\tstrh r1, [r0, 0xC]\n"
	"\tstrh r1, [r0, 0xE]\n"
	"\tstrh r1, [r0, 0x10]\n"
	"\tstrh r1, [r0, 0x12]\n"
	"\tstrh r1, [r0, 0x14]\n"
	"\tstrh r1, [r0, 0x16]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x28\n"
	"\tstrb r3, [r1]\n"
	"\tadds r0, 0x29\n"
	"\tstrb r3, [r0]\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
	"\t.pool");
#endif
}

// Unused
u8 sub_80048B8(void)
{
    return 0;
}

u8 sub_80048BC(void)
{
    return 0;
}

// Unused
u8 sub_80048C0(void)
{
    return 0;
}

// Unused
u8 sub_80048C4(void)
{
    return 0;
}

u8 sub_80048C8(void)
{
    return 0;
}

// Unused
u8 sub_80048CC(void)
{
    return 0;
}
