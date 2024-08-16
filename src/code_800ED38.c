#include "global.h"
#include "memory.h"

struct unkStruct_203B0D0_sub
{
    // size: 0x24
    u32 unk0;
    struct unkStruct_203B0D0_sub *unk4;
    struct unkStruct_203B0D0_sub *unk8;
    u32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u32 unk20;
};

struct unkStruct_203B0D0 {
    // size: 0x4C
    u32 unk0;
    struct unkStruct_203B0D0_sub unk4[2];
};

struct unkStruct_203B0D0 *gUnknown_203B0D0;

extern s32 sub_8000728();

void sub_800ED38(s32 r0)
{
    if(gUnknown_203B0D0 == 0) 
    {
        gUnknown_203B0D0 = MemoryAlloc(sizeof(struct unkStruct_203B0D0), 0xB);
        MemoryClear8((u8 *)gUnknown_203B0D0, sizeof(struct unkStruct_203B0D0));
    }
    gUnknown_203B0D0->unk0 = r0;
}

void sub_800ED64(void)
{
    if(gUnknown_203B0D0)
    {
        MemoryFree(gUnknown_203B0D0);
        gUnknown_203B0D0 = NULL;
    }
}

void sub_800ED80(void)
{
    s32 index;
    struct unkStruct_203B0D0_sub *sub;

    gUnknown_203B0D0->unk0 = 0;
    for(index = 0; index < 2; index++)
    {
        sub = &gUnknown_203B0D0->unk4[index];
        sub->unk0 = 0;
        sub->unk4 = 0;
        sub->unk8 = 0;
    }
}

bool8 sub_800EDB0(struct unkStruct_203B0D0_sub *r0)
{
    s32 index;

    for(index = 0; index < 2; index++)
    {
        if(gUnknown_203B0D0->unk4[index].unk0 == 0)
        {
            gUnknown_203B0D0->unk4[index] = *r0;
            return TRUE;
        }
    }
    return FALSE;
}

void sub_800EDF0(u32 r0, struct unkStruct_203B0D0_sub *r1) {
    struct unkStruct_203B0D0_sub stack;
    s32 uVar1;

    switch(r0)
    {
        case 0:
            stack.unk0 = 3;
            stack.unkC = 0xE;
            stack.unk10 = -1;
            stack.unk18 = 0xDC << 2;
            stack.unk1C = 0x1F;
            stack.unk14  = -1;
            stack.unk4 = r1;
            break;
        case 1:
            stack.unk0 = 4;
            stack.unkC = 0xE;
            stack.unk10 = 0xF0 << 4;
            stack.unk18 = -1;
            stack.unk1C = -1;

            // TODO: what math op is this again?
            uVar1 = sub_8000728();
            stack.unk14 = (((int)(-(uVar1 ^ 2) | (uVar1 ^ 2)) >> 0x1f) & 2);
            stack.unk4 = r1;
            break;
    }
    stack.unk8 = r1->unk4;
    stack.unk20 = 0;
    sub_800EDB0(&stack);
}
