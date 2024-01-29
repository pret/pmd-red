#include "global.h"
#include "text1.h"
#include "memory.h"

struct unkStruct_3001B64
{
    // size: 0x5A8
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 fill10[0x414 - 0x10];
    u32 unk414;
    u32 unk418;
    u32 unk41C;
    u32 unk420;
    u32 unk424;
    u32 unk428;
    u32 unk42C;
    u32 unk430;
    u32 unk434;
    u8 fill438[0x5A4 - 0x438];
    u16 unk5A4;
};

extern struct unkStruct_3001B64 *gUnknown_3001B64;

extern u16 gUnknown_20399DC;
extern u16 gUnknown_20399DE;

extern u8 sub_809B2B8(u32 *, u32, u32, u32);
extern u32 sub_809B40C(u32 *); 
extern void sub_801416C(s32, s32);
extern void sub_809A83C(s16);
extern u32 sub_809A680(u32, u32);
extern void sub_809A62C(void);
extern void sub_80095CC(u32, u32);
extern void sub_8009408(u32, u32);
extern void sub_809B294(void);
extern void sub_8014144(void);
extern void sub_809A7EC(void);

void sub_809A560(void)
{
    sub_8014144();
    gUnknown_3001B64 = MemoryAlloc(0x5a8,6);
    gUnknown_3001B64->unk0 = 0;
    gUnknown_3001B64->unk4 = -1;
    gUnknown_3001B64->unk8 = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    sub_80095CC(0,0x14);
    sub_800641C(0,1,1);
    sub_8009408(0,0x14);
    sub_809B294();
    gUnknown_3001B64->unk414 = 0;
    gUnknown_3001B64->unk418 = 0;
    gUnknown_3001B64->unk41C = 0;
    gUnknown_3001B64->unk420 = 0;
    gUnknown_3001B64->unk424 = 0;
    gUnknown_3001B64->unk428 = 0;
    gUnknown_3001B64->unk42C = 0;
    gUnknown_3001B64->unk430 = -1;
    gUnknown_3001B64->unk434 = -1;
    sub_809A7EC();
    gUnknown_3001B64->unk5A4 = -1;
}

void sub_809A610(void)
{
    sub_809A62C();
    MemoryFree(gUnknown_3001B64);
    gUnknown_3001B64 = NULL;
}

void sub_809A62C(void)
{
    s32 iVar2;

    gUnknown_3001B64->unk0 = 0;
    gUnknown_3001B64->unk4 = -1;
    gUnknown_3001B64->unk8 = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    for(iVar2 = 0; iVar2 < 10; iVar2++)
    {
        sub_809A83C(iVar2);
    }
    gUnknown_3001B64->unk414 = 0;
    sub_809A680(0, 1);
}

u32 sub_809A680(u32 param_1, u32 param_2)
{
    switch(param_1) {
        case 0:
            sub_809B294();
            sub_800641C(0,1,1);
            break;
        case 1:
            sub_809B294();
            break;
        case 2:
            sub_809B294();
            break;
        case 3:
            sub_809B294();
            break;
        case 4:
            sub_809B294();
            break;
        default:
            sub_809B294();
            sub_800641C(0,1,1);
    }
    gUnknown_3001B64->unk0 = param_1;
    return 1;
}

void sub_809A6E4(u16 r0)
{
    gUnknown_20399DC |= r0;
}

void sub_809A6F8(u16 r0)
{
    gUnknown_20399DC &= ~r0;
}

u16 sub_809A70C(u16 r0)
{
    return gUnknown_20399DC;
}

void nullsub_209(void) {}

void sub_809A71C(s32 param_1)
{
    gUnknown_3001B64->unk4 = param_1;
    gUnknown_3001B64->unk8 = param_1;
    sub_801416C(param_1, param_1);
}

void sub_809A738(s32 param_1, s32 param_2)
{
    gUnknown_3001B64->unk4 = param_1;
    gUnknown_3001B64->unk8 = param_2;
    sub_801416C(param_1, param_2);
}

u8 sub_809A750(void)
{
    return sub_809B40C(&gUnknown_3001B64->unkC);
}

u32 sub_809A768(void)
{
    return 0;
}

u8 sub_809A76C(void)
{
    switch(gUnknown_3001B64->unk0)
    {
        case 3:
            return sub_809B2B8(&gUnknown_3001B64->unkC,4,-1,0);
        case 1:
        case 2:
            return sub_809B2B8(&gUnknown_3001B64->unkC,0x84,-1,0);
        default:
            sub_809A680(0, 1);
            return 0;
    }
}

u8 sub_809A7B4(void)
{
    switch(gUnknown_3001B64->unk0)
    {
        case 3:
        case 1:
        case 2:
            return sub_809B2B8(&gUnknown_3001B64->unkC,4,-1,0);
        default:
            sub_809A680(0, 1);
            return 0;
    }
}

