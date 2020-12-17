#include "global.h"

struct unkStruct_20399E8
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u8 unk44;
};

struct unkStruct_809D158
{
    u32 unk0;
    u32 unk4;
};

extern struct unkStruct_20399E8 gUnknown_20399E8;

void sub_809D0BC(void);


void sub_809D0AC(void)
{
    sub_809D0BC();
}

void nullsub_119(void)
{
}

#ifndef NONMATCHING
NAKED
#endif
void sub_809D0BC(void)
{
#ifdef NONMATCHING
    struct unkStruct_20399E8 *pre_load_203;
    
    u32 temp;
    u32 temp1;

    pre_load_203 = &gUnknown_20399E8;

    // TODO regswap.. should be r2/r3, not r0, r1
    temp = gUnknown_8116478.unk0;
    temp1 = gUnknown_8116478.unk4;

    pre_load_203->unk3C = temp;
    pre_load_203->unk40 = temp1;
    pre_load_203->unk44 = 0;
    sub_809D158(0);
    pre_load_203->unk8 = 0;
    pre_load_203->unkC = 0;
    pre_load_203->unk10 = 0;
    pre_load_203->unk4 = -1;
    pre_load_203->unk24 = 0;
    pre_load_203->unk28 = 0;
    pre_load_203->unk2C = 0;
    pre_load_203->unk30 = 0;
    pre_load_203->unk34 = 0;
    pre_load_203->unk38 = 0;
#else
	asm_unified("\tpush {r4,r5,lr}\n"
	"\tldr r5, _0809D0F8\n"
	"\tldr r1, _0809D0FC\n"
	"\tldr r2, [r1]\n"
	"\tldr r3, [r1, 0x4]\n"
	"\tstr r2, [r5, 0x3C]\n"
	"\tstr r3, [r5, 0x40]\n"
	"\tadds r0, r5, 0\n"
	"\tadds r0, 0x44\n"
	"\tmovs r4, 0\n"
	"\tstrb r4, [r0]\n"
	"\tmovs r0, 0\n"
	"\tbl sub_809D158\n"
	"\tstr r4, [r5, 0x8]\n"
	"\tstr r4, [r5, 0xC]\n"
	"\tstr r4, [r5, 0x10]\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tstr r0, [r5, 0x4]\n"
	"\tstr r4, [r5, 0x24]\n"
	"\tstr r4, [r5, 0x28]\n"
	"\tstr r4, [r5, 0x2C]\n"
	"\tstr r4, [r5, 0x30]\n"
	"\tstr r4, [r5, 0x34]\n"
	"\tstr r4, [r5, 0x38]\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0809D0F8: .4byte gUnknown_20399E8\n"
"_0809D0FC: .4byte gUnknown_8116478\n");
#endif
}

void sub_809D100(u32 r0)
{
    if(gUnknown_20399E8.unk24 != r0)
    {
        gUnknown_20399E8.unk24 = r0;
        gUnknown_20399E8.unk28 = 0;
        gUnknown_20399E8.unk2C = 0;
        gUnknown_20399E8.unk30 = 0;
        gUnknown_20399E8.unk34 = 0;
        gUnknown_20399E8.unk38 = 0;
    }
}

void sub_809D124(u32 r0, u32 r1, u32 r2)
{
    if(gUnknown_20399E8.unk24 != r0)
    {
        gUnknown_20399E8.unk24 = r0;
        gUnknown_20399E8.unk30 = 0;
        gUnknown_20399E8.unk34 = 0;
        gUnknown_20399E8.unk38 = 0;
    }
    gUnknown_20399E8.unk28 = r1;
    gUnknown_20399E8.unk2C = r2;
}

void sub_809D148(u32 r0)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;

}

void sub_809D158(u32 r0, struct unkStruct_809D158 *r1)
{
    u32 temp;
    u32 temp1;
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;

    // Load both first and then store
    temp = r1->unk0;
    temp1 = r1->unk4;
    gUnknown_20399E8.unk1C = temp;
    gUnknown_20399E8.unk20 = temp1;
}

void sub_809D170(u32 r0, u32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D180(u32 r0, u32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r1;
}

void sub_809D190(u32 r0, struct unkStruct_809D158 *r1, u32 r2)
{
    u32 temp;
    u32 temp1;
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r2;

    // Load both first and then store
    temp = r1->unk0;
    temp1 = r1->unk4;
    gUnknown_20399E8.unk14 = temp;
    gUnknown_20399E8.unk18 = temp1;
}

void sub_809D1A8(u32 r0, u32 r1, u32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D1BC(u32 r0, u32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r1;
}

void sub_809D1CC(u32 r0, struct unkStruct_809D158 *r1, u32 r2)
{
    u32 temp;
    u32 temp1;

    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r2;

    // Load both first and then store
    temp = r1->unk0;
    temp1 = r1->unk4;
    gUnknown_20399E8.unk14 = temp;
    gUnknown_20399E8.unk18 = temp1;
}

void sub_809D1E4(u32 r0, u32 r1, u32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r2;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D1F8(u32 r0, u32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r1;
}

void sub_809D208(u32 r0, struct unkStruct_809D158 *r1, u32 r2)
{
    u32 temp;
    u32 temp1;

    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r2;

    // Load both first and then store
    temp = r1->unk0;
    temp1 = r1->unk4;
    gUnknown_20399E8.unk14 = temp;
    gUnknown_20399E8.unk18 = temp1;
}

void sub_809D220(u32 r0, u32 r1, u32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk4 = r1;
}

u32 sub_809D234(void)
{
    u32 temp;
    temp = gUnknown_20399E8.unk8;
    if(temp != 0)
    {
        temp = 1;
    }
    return temp;
}

// TODO regswap but matches otherwise
// Loads struct into R1... should be R3
#ifndef NONMATCHING
NAKED
#endif
u8 sub_809D248(struct unkStruct_809D158 *r0)
{
#ifdef NONMATCHING
    u32 temp;
    u32 temp1;

    temp = gUnknown_20399E8.unk3C;
    temp1 = gUnknown_20399E8.unk40;
    r0->unk0 = temp;
    r0->unk4 = temp1;
    return gUnknown_20399E8.unk44;
#else
	asm_unified("\tldr r3, _0809D258\n"
	"\tldr r1, [r3, 0x3C]\n"
	"\tldr r2, [r3, 0x40]\n"
	"\tstr r1, [r0]\n"
	"\tstr r2, [r0, 0x4]\n"
	"\tadds r3, 0x44\n"
	"\tldrb r0, [r3]\n"
	"\tbx lr\n"
	"\t.align 2, 0\n"
"_0809D258: .4byte gUnknown_20399E8");
#endif
}
