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

struct DebugLocation
{
    char *file;
    u32 line;
    char *func;
};


extern u16 gUnknown_80D4144[];
extern s16 gUnknown_202DE20;
extern s16 gUnknown_202DE22;
extern s16 gUnknown_202DE24;
extern u32 gUnknown_202DE1C;
extern u32 gUnknown_203B14C;
extern const char gNotEntryText[];
extern const char gUnknown_80D418C[];
extern const char gUnknown_80D41C4[];

void sub_8011760(void)
{
    if(sub_80023E4(0xD) != 0)
    {
        sub_800BDFC(0x13);
        return;
    }
    if(sub_80023E4(0xC) != 0)
    {
        sub_800BDFC(0x7); // Pokemon Square Theme
    }
}

void sub_801178C(void)
{
    if(sub_80023E4(0xD) != 0)
    {
        sub_800BDFC(0x13);
        return;
    }
    sub_800BDFC(0x7); // Pokemon Square Theme
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
    gUnknown_202DE20 = 0;
    gUnknown_202DE22 = 0;
    gUnknown_202DE24 = 0;
}

void sub_8011830(void)
{
    sub_800C93C();
    gUnknown_202DE20 = 0;
    gUnknown_202DE22 = 0;
    gUnknown_202DE24 = 0;
}

void sub_8011854(void)
{
    sub_800C9CC();
}

void sub_8011860(void)
{
    if(gUnknown_202DE20 > 0)
    {
        gUnknown_202DE20--;
    }
    if(gUnknown_202DE22 > 0)
    {
        gUnknown_202DE22--;
    }
    if(gUnknown_202DE24 > 0)
    {
        gUnknown_202DE24--;
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

u32 sub_8011940(u16 r0)
{
    u32 temp;
    temp = sub_800C068();

    if(r0 == 999)
    {
        temp ^= 999;
        return (-temp | temp) >> 31;
    }

    return temp == r0;
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
    if(gUnknown_202DE20 > 0)
        return;
    sub_800C074(gUnknown_80D4144[r0], 0x80 << 1);
    gUnknown_202DE20 = 4;
}

void sub_8011A04(void)
{
    if(gUnknown_202DE22 > 0)
        return;
    gUnknown_202DE22 = 3;
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

// Unused
void PrintFuncFileLineOrNotEntry(char * r0, struct DebugLocation *r1)
{
    if(r1 != 0)
    {
        sprintf(r0, gUnknown_80D418C, r1->func, r1->file, r1->line);
    }
    else
    {
        sprintf(r0, gNotEntryText);
    }
}

void PrintFuncFileLine(char *buf, struct DebugLocation *loc, char* prefix)
{
    sprintf(buf, gUnknown_80D41C4, prefix, loc->func, loc->file, loc->line);
}
