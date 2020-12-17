#include "global.h"

struct unkStruct_8041D5C
{
    u8 padding[0x70];
    u8 *unk70[100];
};

struct unk_struct_8041F08
{
    u32 unk0;
    u32 unk4;
};


extern void sub_803ED30(u8, struct unkStruct_8041D5C *r0, u8, u8); 
extern void sub_804151C(u32 r0, u32 r1, u8 r2);
extern void sub_80421C0(u32 r0, u32 r1);
extern u8 sub_8042768(void);
extern void sub_806CDD4(u32 r0, u8, u32);
extern u8 sub_8071858(u32, u8);

extern void sub_8041550(u32 r0, u32, u32, u32);


void sub_8041AD0(u32 r0)
{
    sub_804151C(r0, 0xA2 << 1, 1);
}

void sub_8041AE0(u32 r0)
{
    sub_804151C(r0, 0x143, 1);
}

void sub_8041AF4(u32 r0)
{
    sub_804151C(r0, 0x25, 1);
    sub_80421C0(r0, 0x197);
}

void nullsub_57(void)
{
}

void sub_8041B18(u32 r0)
{
    sub_804151C(r0, 0x141, 1);
}

void nullsub_58(void)
{
}

void nullsub_59(void)
{
}

void sub_8041B34(u32 r0)
{
    sub_804151C(r0, 7, 1);
}

void nullsub_60(void)
{
}

void sub_8041B48(u32 r0)
{
    sub_804151C(r0, 4, 0);
}

void nullsub_61(void)
{
}

void sub_8041B5C(u32 r0)
{
    sub_804151C(r0, 0x171, 1);
}

void nullsub_62(void)
{
}

void sub_8041B74(u32 r0)
{
    sub_804151C(r0, 0x171, 0);
}

void nullsub_63(void)
{
}

void nullsub_64(void)
{
}

void sub_8041B90(u32 r0)
{
    sub_804151C(r0, 0xD6 << 1, 0);
}

void nullsub_65(void)
{
}

void nullsub_66(void)
{
}

void sub_8041BA8(u32 r0)
{
    sub_804151C(r0, 4, 1);
}

void nullsub_67(void)
{
}

void sub_8041BBC(u32 r0)
{
    sub_804151C(r0, 0xD4 << 1, 1);
}

void nullsub_68(void)
{
}

void sub_8041BD0(u32 r0, u8 r1)
{
    if(r1 == 0)
    {
        return;
    }
    sub_80421C0(r0, 0x1a5);
}

void sub_8041BE8(u32 r0)
{
    sub_80421C0(r0, 0xCB << 1);
}

void sub_8041BF8(u32 r0)
{
    sub_806CDD4(r0, 0xA, 8);
}

void sub_8041C08(u32 r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void sub_8041C1C(u32 r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void nullsub_69(void)
{
}

void sub_8041C34(u32 r0)
{
    sub_804151C(r0, 0x4C, 1);
}

void nullsub_70(void)
{
}

void nullsub_71(void)
{
}

void sub_8041C4C(u32 r0, u32 r1)
{
    sub_804151C(r0, r1, 1);
}

void sub_8041C58(u32 r0)
{
    sub_804151C(r0, 0x1a9, 1);
}

void sub_8041C6C(u32 r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void sub_8041C7C(u32 r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void nullsub_72(void)
{
}

void nullsub_73(void)
{
}

void sub_8041C94(u32 r0)
{
    sub_804151C(r0, 0x171, 1);
}

void sub_8041CA8(u32 r0)
{
    sub_804151C(r0, 7, 1);
}

void sub_8041CB8(u32 r0)
{
    sub_804151C(r0, 0x18b, 1);
}

void sub_8041CCC(u32 r0)
{
    sub_804151C(r0, 0xC5 << 1, 1);
}

void sub_8041CDC(u32 r0)
{
    sub_804151C(r0, 5, 1);
}

void sub_8041CEC(u32 r0)
{
    sub_80421C0(r0, 0x19d);
}

void nullsub_74(void)
{
}

void sub_8041D00(u32 r0, u32 r1)
{
    sub_804151C(r1, 0x2F, 1);
    sub_804151C(r0, 0x30, 1);
}

void nullsub_75(void)
{
}

void nullsub_76(void)
{
}

void nullsub_77(void)
{
}

void nullsub_78(void)
{
}

void nullsub_79(void)
{
}

void nullsub_80(void)
{
}

void sub_8041D38(u32 r0)
{
    sub_804151C(r0, 0x21, 1);
}

void sub_8041D48(u32 r0)
{
    sub_80421C0(r0, 0x191);
}

void nullsub_81(void)
{
}

void sub_8041D5C(struct unkStruct_8041D5C *r0)
{
    u8 *temp;
    if(sub_8042768() == 0)
    {
        return;
    }
    temp = *r0->unk70;
    sub_803ED30(temp[0x89 << 1] , r0, 1, 0xB);
}

void sub_8041D84(u32 r0)
{
    sub_80421C0(r0, 0x19f);
}

void nullsub_82(void)
{
}

void nullsub_83(void)
{
}

void sub_8041D9C(u32 r0)
{
    sub_804151C(r0, 0x131, 1);
}

void sub_8041DB0(u32 r0)
{
    sub_804151C(r0, 0x30, 1);
}

void nullsub_84(void)
{
}

void nullsub_85(void)
{
}

void nullsub_204(void)
{
}

void nullsub_86(void)
{
}

void nullsub_87(void)
{
}

void nullsub_88(void)
{
}

#ifndef NONMATCHING
NAKED
#endif
// TODO r1 is doing an lsr instead of an asr... maybe a signed arg?
void sub_8041DD8(u32 r0, u16 r1)
{
#ifdef NONMATCHING
    if(sub_8071858(r0, 0xE) != 0)
    {
        sub_804151C(r0, r1, 1);
        return;
    }
    sub_804151C(r0, 0xE, 1);
#else
	asm_unified("\tpush {r4,r5,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tlsls r1, 16\n"
	"\tasrs r5, r1, 16\n"
	"\tmovs r1, 0xE\n"
	"\tbl sub_8071858\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08041DF8\n"
	"\tadds r0, r4, 0\n"
	"\tadds r1, r5, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_804151C\n"
	"\tb _08041E02\n"
"_08041DF8:\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0xE\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_804151C\n"
"_08041E02:\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0");
#endif
}

void nullsub_89(void)
{
}

void sub_8041E0C(u32 r0)
{
    sub_804151C(r0, 0x41, 1);
}

void sub_8041E1C(u32 r0)
{
    sub_804151C(r0, 0x8F << 1, 1);
    sub_80421C0(r0, 0xCE << 1);
}

void sub_8041E3C(u32 r0)
{
    sub_804151C(r0, 0xD7 << 1, 1);
}

void sub_8041E4C(u32 r0)
{
    sub_804151C(r0, 0x1b1, 1);
}

void sub_8041E60(u32 r0)
{
    sub_804151C(r0, 0x1a9, 1);
}

void sub_8041E74(u32 r0)
{
    sub_804151C(r0, 0xC9 << 1, 1);
}

void sub_8041E84(u32 r0)
{
    sub_804151C(r0, 0xC7 << 1, 1);
}

void sub_8041E94(u32 r0)
{
    sub_804151C(r0, 0xC8 << 1, 1);
}

void sub_8041EA4(u32 r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8041EB4(u32 r0)
{
    sub_804151C(r0, 0x171, 1);
}

void sub_8041EC8(u32 r0)
{
    sub_80421C0(r0, 0x197);
}

void sub_8041ED8(u32 r0)
{
    sub_80421C0(r0, 0x197);
}

void sub_8041EE8(u32 r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8041EF8(u32 r0)
{
    sub_804151C(r0, 0xF, 1);
}

void sub_8041F08(u32 r0)
{
    volatile struct unk_struct_8041F08 temp;
    temp.unk0 = 2;
    temp.unk4 = 0;
    sub_8041550(r0, 0x15, 1, 3);
}

void nullsub_90(void)
{
}

void sub_8041F28(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xCA << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0x193, 1);
    }
}

void sub_8041F4C(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0x18f, 1);
    }
    else
    {
        sub_804151C(r0, 0x191, 1);
    }
}

void sub_8041F70(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0x1a9, 1);
    }
    else
    {
        sub_804151C(r0, 0xC9 << 1, 1);
    }
}

void sub_8041F94(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xC7 << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0xC8 << 1, 1);
    }
}

void sub_8041FB4(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0x1a9, 1);
    }
    else
    {
        sub_804151C(r0, 0xC9 << 1, 1);
    }
}

void sub_8041FD8(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xCA << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0x193, 1);
    }
}

void sub_8041FFC(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xC7 << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0xC8 << 1, 1);
    }
}

void sub_804201C(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0x18f, 1);
    }
    else
    {
        sub_804151C(r0, 0x191, 1);
    }
}

void sub_8042040(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xC6 << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0xD, 1);
    }
}

void sub_8042060(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0x18d, 1);
    }
    else
    {
        sub_804151C(r0, 0xE, 1);
    }
}

void sub_8042080(u32 r0, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(r0, 0xC6 << 1, 1);
    }
    else
    {
        sub_804151C(r0, 0xD, 1);
    }
}

void sub_80420A0(u32 r0, u32 r1)
{
    sub_804151C(r0, 0x143, 1);
}

void nullsub_91(void)
{
}

void sub_80420B8(u32 r0, u32 r1)
{
    sub_804151C(r0, 0x19, 1);
}

void sub_80420C8(u32 r0)
{
    volatile struct unk_struct_8041F08 temp;
    temp.unk0 = 2;
    temp.unk4 = 0;
    sub_8041550(r0, 0x15, 1, 3);
}

void nullsub_92(void)
{
}
