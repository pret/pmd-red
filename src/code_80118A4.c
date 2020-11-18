#include "global.h"

void sub_8011924(void);
void nullsub_26(void);

extern u8 sub_80023E4(u8);
extern void sub_800BDFC(u16 r0);
extern void FadeInNewBGM(u16 r0, u16 r1);
extern void sub_800BF48(u16 r0);
extern void sub_800BF80(void);
extern void sub_800BFD0(u16 r0);
extern void sub_800C3F8(u16 r0, u16 r1);
extern void sub_801199C(u16 r0);
extern u16 sub_800C068();
extern void sub_800C074(u16 r0, u16 r1);
extern void sub_800C298(u16 r0);
extern void sub_800C93C();
extern u8 sub_800C5D0(u16 r0);
extern void sub_800C9CC();

extern void nullsub_27(void);
extern void nullsub_29(void);
extern void nullsub_30(void);
extern void nullsub_31(void);
extern void nullsub_32(void);
extern void nullsub_28(void);

extern int sprintf(char *, const char *, ...);

struct UnkStructType
{
    /* 0x0 */ s16 unk0;

};


struct unkFileStruct
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};


extern u16 gUnknown_80D4144[];
extern struct UnkStructType gUnknown_202DE20;
extern struct UnkStructType gUnknown_202DE22;
extern struct UnkStructType gUnknown_202DE24;
extern u32 gUnknown_202DE1C;
extern u32 gUnknown_203B14C;
extern const char gNotEntryText;
extern const char gUnknown_80D418C;

void sub_8011760(void)
{
    if(sub_80023E4(0xD) != 0)
    {
        sub_800BDFC(0x13);
        return;
    }
    if(sub_80023E4(0xC) != 0)
    {
        sub_800BDFC(0x7);
    }
}

void sub_801178C(void)
{
    if(sub_80023E4(0xD) != 0)
    {
        sub_800BDFC(0x13);
        return;
    }
    sub_800BDFC(0x7);
}

void sub_80117AC(void)
{
    if(sub_80023E4(0xD) == 0)
    {
        sub_800BFD0(0x1E);
    }
}

void sub_80117C4(void)
{
    sub_800BFD0(0x1E);
}

void sub_80117D0(void)
{
    sub_800C074(0x97 << 1, 0x80 << 1);
}

void sub_80117E4(void)
{
    sub_800C074(0x12f, 0x80 << 1);
}

void sub_80117F8(void)
{
    sub_800C074(0x12d, 0x80 << 1);
}

void sub_801180C(void)
{
    gUnknown_202DE1C = 0;
    gUnknown_202DE20.unk0 = 0;
    gUnknown_202DE22.unk0 = 0;
    gUnknown_202DE24.unk0 = 0;
}

void sub_8011830(void)
{
    sub_800C93C();
    gUnknown_202DE20.unk0 = 0;
    gUnknown_202DE22.unk0 = 0;
    gUnknown_202DE24.unk0 = 0;
}

void sub_8011854(void)
{
    sub_800C9CC();
}

void sub_8011860(void)
{
    if(gUnknown_202DE20.unk0 > 0)
    {
        gUnknown_202DE20.unk0--;
    }
    if(gUnknown_202DE22.unk0 > 0)
    {
        gUnknown_202DE22.unk0--;
    }
    if(gUnknown_202DE24.unk0 > 0)
    {
        gUnknown_202DE24.unk0--;
    }
}

void sub_80118A4(void)
{
    sub_8011924();
    sub_801199C(0x3e6);
    sub_801199C(0x3e5);
}

void sub_80118C4(u16 r0)
{
    sub_800BFD0(r0);
    sub_800C3F8(0x3e6, r0);
    sub_800C3F8(0x3e5, r0);
}

void sub_80118F0(u16 r0)
{
    sub_800BDFC(r0);
}

void sub_8011900(u16 songIndex, u16 speed)
{
    FadeInNewBGM(songIndex, speed);
}

void sub_8011914(u16 r0)
{
    sub_800BF48(r0);
}

void sub_8011924()
{
    sub_800BF80();
}

void sub_8011930(u16 r0)
{
    sub_800BFD0(r0);
}

// TODO fix this nonmatching
#ifndef NONMATCHING
NAKED
#endif
u32 sub_8011940(u16 r0)
{
#ifdef NONMATCHING
    u32 temp;
    temp = sub_800C068();

    if(r0 == 0x3e7)
    {
        temp ^= r0;
        // TODO this OR/NEG apparently is close
        temp |= -temp;
        return temp >> 31;
    }

    if(temp != r0)
        return 0;
    else
        return 1;
#else
	asm_unified("\tpush {r4,lr}\n"
	"\tlsls r0, 16\n"
	"\tlsrs r4, r0, 16\n"
	"\tbl sub_800C068\n"
	"\tlsls r0, 16\n"
	"\tlsrs r1, r0, 16\n"
	"\tldr r0, _08011960\n"
	"\tcmp r4, r0\n"
	"\tbne _08011964\n"
	"\teors r1, r4\n"
	"\tnegs r0, r1\n"
	"\torrs r0, r1\n"
	"\tlsrs r0, 31\n"
	"\tb _0801196C\n"
        "\t.align 2,0\n"
        "_08011960: .4byte 0x000003e7\n"
        "_08011964:\n"
        "\tmovs r0, 0\n"
        "\tcmp r1, r4\n"
        "\tbne _0801196C\n"
        "\tmovs r0, 0x1\n"
        "_0801196C:\n"
        "\tpop {r4}\n"
        "\tpop {r1}\n"
        "\tbx r1");
#endif
}

void sub_8011974(u16 r0, u16 r1)
{
    sub_800C074(r0, r1);
}

void sub_8011988(u16 r0)
{
    sub_800C074(r0, 0x80 << 1);
}

void sub_801199C(u16 r0)
{
    sub_800C298(r0);
}

void sub_80119AC(u16 r0, u16 r1)
{
    sub_800C3F8(r0, r1);
}

u8 sub_80119C0(u16 r0)
{
    return sub_800C5D0(r0);
}

void sub_80119D4(u32 r0)
{
    if(gUnknown_202DE20.unk0 > 0)
        return;
    sub_800C074(gUnknown_80D4144[r0], 0x80 << 1);
    gUnknown_202DE20.unk0 = 4;
}

void sub_8011A04(void)
{
    if(gUnknown_202DE22.unk0 > 0)
        return;
    gUnknown_202DE22.unk0 = 3;
    sub_800C074(0x131, 0x80 << 1);
}

void sub_8011A2C(u32 r0)
{
    gUnknown_202DE1C = r0;
}

void NDS_DebugInit(void)
{
    nullsub_26();
    nullsub_27();
    nullsub_29();
    nullsub_30();
    nullsub_31();
    nullsub_32();
    nullsub_28();
    gUnknown_203B14C = 1; // Maybe a flag saying Debug is on?
}

void nullsub_25(void)
{
}

void nullsub_26(void)
{
}

#ifndef NONMATCHING
NAKED
#endif
// Unused
void PrintFuncFileLineOrNotEntry(char * r0, struct unkFileStruct *r1)
{
#ifdef NONMATCHING
    u32 temp;
    if(r1 != 0)
    {
        // TODO fix regswap here.. otherwise looks good
        temp = r1->unk4;
        sprintf(r0, &gUnknown_80D418C, r1->unk8, r1->unk0, temp);
    }
    else
    {
        sprintf(r0, &gNotEntryText);
    }
#else
	asm_unified("\tpush {r4,lr}\n"
	"\tsub sp, 0x4\n"
	"\tadds r4, r0, 0\n"
	"\tadds r0, r1, 0\n"
	"\tcmp r0, 0\n"
	"\tbeq _08011A90\n"
	"\tldr r1, _08011A8C\n"
	"\tldr r2, [r0, 0x8]\n"
	"\tldr r3, [r0]\n"
	"\tldr r0, [r0, 0x4]\n"
	"\tstr r0, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tbl sprintf\n"
	"\tb _08011A98\n"
	"\t.align 2, 0\n"
"_08011A8C: .4byte gUnknown_80D418C\n"
"_08011A90:\n"
	"\tldr r1, _08011AA0\n"
	"\tadds r0, r4, 0\n"
	"\tbl sprintf\n"
"_08011A98:\n"
	"\tadd sp, 0x4\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08011AA0: .4byte gNotEntryText");
#endif
}
