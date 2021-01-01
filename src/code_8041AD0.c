#include "global.h"

struct unkDungeon_8041D5C
{
    u8 padding[0x70];
    u8 *unk70[100];
};

struct unk_struct_8041F08
{
    u32 unk0;
    u32 unk4;
};

struct unkStruct_80420E8
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern u8 *gUnknown_203B418;


extern void sub_803ED30(u8, struct unkDungeon_8041D5C *r0, u8, u8); 
extern void sub_804151C(struct unkDungeon_8041D5C *r0, u32 r1, u8 r2);
extern void sub_80416E0(struct unkDungeon_8041D5C *r0, u32, u32);
extern u8 sub_8042768(struct unkDungeon_8041D5C *r0);
extern void sub_806CDD4(struct unkDungeon_8041D5C *r0, u8, u32);
extern u8 sub_8071858(struct unkDungeon_8041D5C *r0, u8);
extern u32 sub_806F62C(u32);
extern void sub_8083E38(u32);
extern u8 sub_803F428(struct unkDungeon_8041D5C *r0);
extern void sub_8041550(struct unkDungeon_8041D5C *r0, u32, u32, u32);


void sub_80421C0(struct unkDungeon_8041D5C *r0, u16 r1);


void sub_8041AD0(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xA2 << 1, 1);
}

void sub_8041AE0(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x143, 1);
}

void sub_8041AF4(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x25, 1);
    sub_80421C0(r0, 0x197);
}

void nullsub_57(void)
{
}

void sub_8041B18(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x141, 1);
}

void nullsub_58(void)
{
}

void nullsub_59(void)
{
}

void sub_8041B34(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 7, 1);
}

void nullsub_60(void)
{
}

void sub_8041B48(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 4, 0);
}

void nullsub_61(void)
{
}

void sub_8041B5C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x171, 1);
}

void nullsub_62(struct unkDungeon_8041D5C *r0)
{
}

void sub_8041B74(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x171, 0);
}

void nullsub_63(void)
{
}

void nullsub_64(void)
{
}

void sub_8041B90(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xD6 << 1, 0);
}

void nullsub_65(void)
{
}

void nullsub_66(void)
{
}

void sub_8041BA8(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 4, 1);
}

void nullsub_67(void)
{
}

void sub_8041BBC(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xD4 << 1, 1);
}

void nullsub_68(void)
{
}

void sub_8041BD0(struct unkDungeon_8041D5C *r0, u8 r1)
{
    if(r1 == 0)
    {
        return;
    }
    sub_80421C0(r0, 0x1a5);
}

void sub_8041BE8(struct unkDungeon_8041D5C *r0)
{
    sub_80421C0(r0, 0xCB << 1);
}

void sub_8041BF8(struct unkDungeon_8041D5C *r0)
{
    sub_806CDD4(r0, 0xA, 8);
}

void sub_8041C08(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void sub_8041C1C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x1a7, 1);
}

void nullsub_69(void)
{
}

void sub_8041C34(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x4C, 1);
}

void nullsub_70(void)
{
}

void nullsub_71(void)
{
}

void sub_8041C4C(struct unkDungeon_8041D5C *r0, u32 r1)
{
    sub_804151C(r0, r1, 1);
}

void sub_8041C58(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x1a9, 1);
}

void sub_8041C6C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void sub_8041C7C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x9D << 1, 1);
}

void nullsub_72(void)
{
}

void nullsub_73(void)
{
}

void sub_8041C94(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x171, 1);
}

void sub_8041CA8(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 7, 1);
}

void sub_8041CB8(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x18b, 1);
}

void sub_8041CCC(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xC5 << 1, 1);
}

void sub_8041CDC(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 5, 1);
}

void sub_8041CEC(struct unkDungeon_8041D5C *r0)
{
    sub_80421C0(r0, 0x19d);
}

void nullsub_74(void)
{
}

void sub_8041D00(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1)
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

void sub_8041D38(struct unkDungeon_8041D5C * r0)
{
    sub_804151C(r0, 0x21, 1);
}

void sub_8041D48(struct unkDungeon_8041D5C * r0)
{
    sub_80421C0(r0, 0x191);
}

void nullsub_81(void)
{
}

void sub_8041D5C(struct unkDungeon_8041D5C *r0)
{
    u8 *temp;
    if(sub_8042768(r0) == 0)
    {
        return;
    }
    temp = *r0->unk70;
    sub_803ED30(temp[0x89 << 1] , r0, 1, 0xB);
}

void sub_8041D84(struct unkDungeon_8041D5C * r0)
{
    sub_80421C0(r0, 0x19f);
}

void nullsub_82(void)
{
}

void nullsub_83(void)
{
}

void sub_8041D9C(struct unkDungeon_8041D5C * r0)
{
    sub_804151C(r0, 0x131, 1);
}

void sub_8041DB0(struct unkDungeon_8041D5C * r0)
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

void sub_8041DD8(struct unkDungeon_8041D5C *r0, s16 r1)
{
    u32 temp;
    temp = r1;

    if(sub_8071858(r0, 0xE) != 0)
        sub_804151C(r0, temp, 1);
    else
        sub_804151C(r0, 0xE, 1);
}

void nullsub_89(void)
{
}

void sub_8041E0C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x41, 1);
}

void sub_8041E1C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x8F << 1, 1);
    sub_80421C0(r0, 0xCE << 1);
}

void sub_8041E3C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xD7 << 1, 1);
}

void sub_8041E4C(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x1b1, 1);
}

void sub_8041E60(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x1a9, 1);
}

void sub_8041E74(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xC9 << 1, 1);
}

void sub_8041E84(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xC7 << 1, 1);
}

void sub_8041E94(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xC8 << 1, 1);
}

void sub_8041EA4(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8041EB4(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x171, 1);
}

void sub_8041EC8(struct unkDungeon_8041D5C *r0)
{
    sub_80421C0(r0, 0x197);
}

void sub_8041ED8(struct unkDungeon_8041D5C *r0)
{
    sub_80421C0(r0, 0x197);
}

void sub_8041EE8(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8041EF8(struct unkDungeon_8041D5C *r0)
{
    sub_804151C(r0, 0xF, 1);
}

void sub_8041F08(struct unkDungeon_8041D5C *r0)
{
    volatile struct unk_struct_8041F08 temp;
    temp.unk0 = 2;
    temp.unk4 = 0;
    sub_8041550(r0, 0x15, 1, 3);
}

void nullsub_90(void)
{
}

void sub_8041F28(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041F4C(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041F70(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041F94(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041FB4(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041FD8(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8041FFC(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_804201C(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8042040(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8042060(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_8042080(struct unkDungeon_8041D5C *r0, u32 r1)
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

void sub_80420A0(struct unkDungeon_8041D5C *r0, u32 r1)
{
    sub_804151C(r0, 0x143, 1);
}

void nullsub_91(void)
{
}

void sub_80420B8(struct unkDungeon_8041D5C *r0, u32 r1)
{
    sub_804151C(r0, 0x19, 1);
}

void sub_80420C8(struct unkDungeon_8041D5C *r0)
{
    volatile struct unk_struct_8041F08 temp;
    temp.unk0 = 2;
    temp.unk4 = 0;
    sub_8041550(r0, 0x15, 1, 3);
}

void nullsub_92(void)
{
}

void sub_80420E8(struct unkDungeon_8041D5C *r0, struct unkStruct_80420E8 *r1)
{
    u32 temp;
    u32 arg;
    volatile struct unk_struct_8041F08 temp_1;
    temp = r1->unk8;
    if(gUnknown_203B418[0x16d] != 0)
        temp = sub_806F62C(r1->unk8);
    switch(temp)
    {
        default:
        case 0:
            arg = 8;
            break;
        case 1:
            arg = 9;
            break;
        case 2:
            arg = 10;
            break;
        case 3:
            arg = 11;
            break;
    }
    temp_1.unk0 = 0;
    temp_1.unk4 = 1;
    sub_8041550(r0, arg, 1, 3);
}

void sub_8042148(struct unkDungeon_8041D5C *r0)
{
    sub_80421C0(r0, 0x1a7);
    sub_804151C(r0, 0x9F << 1, 1);
}

void nullsub_93()
{
}

void sub_804216C(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2)
{
    if(r2 == 1)
        sub_804151C(r1, 0xF8, 1);
    else
        sub_804151C(r1, 0xF9, 1);
}

void sub_804218C(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_804151C(r1, 0x2A, 1);
}

void sub_804219C(struct unkDungeon_8041D5C *r0)
{
    sub_80416E0(r0, 0x90, 1);
}

void sub_80421AC(u32 r0, struct unkDungeon_8041D5C * r1)
{
    sub_804151C(r1, 0x167, 1);
}

void sub_80421C0(struct unkDungeon_8041D5C *r0, u16 r1)
{
    if(r0 == NULL)
        sub_8083E38(r1);
    else
        if(sub_8042768(r0) != 0)
            sub_8083E38(r1);
}

void sub_80421EC(struct unkDungeon_8041D5C *r0, u16 r1)
{
    if(sub_803F428(r0) != 0)
        sub_8083E38(r1);
}

void sub_8042208(struct unkDungeon_8041D5C *r0, u8 r1)
{
    if(r1 == 0)
        sub_8083E38(0xA9 << 1);
    else if(r1 == 1)
        sub_8083E38(0x151);
    else
        sub_8083E38(0xA8 << 1);
}

void sub_8042238(u32 r0, struct unkDungeon_8041D5C *r1)
{
    u8 *temp;
    temp = *r1->unk70;
    if(temp[6] != 0)
        sub_8083E38(0x157);
    else
        sub_8083E38(0xAB << 1);
}
