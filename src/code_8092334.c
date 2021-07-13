#include "code_8092334.h"
#include "global.h"
#include "memory.h"
#include "item.h"


s16 sub_8094828(u16 r0, u8 itemIndex)
{
    if(itemIndex != 0)
    {
        if(GetItemType(itemIndex) == ITEM_TYPE_ORB)
            return 0x223;
        else
            return 0x224;
    }
    else
    {
        return r0;
    }
}

void sub_809485C(struct unkStruct_8094924 *r0, u8 *r1, s32 size)
{
    r0->unk0 = r1;
    r0->unk8 = 0;
    r0->unkC = 0;
    r0->unk4 = &r1[size];
}

void sub_809486C(struct unkStruct_8094924 *r0, u8 *r1, s32 size)
{
    r0->unk0 = r1;
    r0->unk8 = 0;
    r0->unkC = 0;
    r0->unk4 = &r1[size];
    MemoryClear8(r1, size);
}

void nullsub_102(struct unkStruct_8094924 *r0)
{

}

void sub_809488C(struct unkStruct_8094924 *r0, u8 *r1, s32 size)
{
    s32 r5;
    u8 *r6;

    r5 = 0;
    r6 = r1;


    if(size != 0)
    {
        while(size != 0)
        {
            if(( *(r6) >> r5) & 1)
            {
                *r0->unk0 |= (1 << r0->unk8);
            }
            r5++;
            if(r5 == 8)
            {
                r6++;
                r5 = 0;
            }
            r0->unk8++;
            if(r0->unk8 == 8)
            {
                r0->unk0++;
                r0->unk8 = 0;
            }
            r0->unkC++;
            size--;
        }
    }
}

// Unused
NAKED
void sub_80948E4(struct unkStruct_8094924 *r0, u8 *r1, s32 size)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r5, r2, 0\n"
	"\tadds r6, r1, 0\n"
	"\tcmp r5, 0\n"
	"\tbeq _0809491C\n"
"_080948F0:\n"
	"\tldrb r1, [r6]\n"
	"\tldr r0, [r4, 0x8]\n"
	"\tlsls r1, r0\n"
	"\tldr r3, [r4]\n"
	"\tldrb r2, [r3]\n"
	"\tadds r0, r1, 0\n"
	"\torrs r0, r2\n"
	"\tstrb r0, [r3]\n"
	"\tldr r2, [r4]\n"
	"\tadds r0, r2, 0x1\n"
	"\tstr r0, [r4]\n"
	"\tasrs r1, 8\n"
	"\tldrb r0, [r2, 0x1]\n"
	"\torrs r1, r0\n"
	"\tstrb r1, [r2, 0x1]\n"
	"\tadds r6, 0x1\n"
	"\tldr r0, [r4, 0xC]\n"
	"\tadds r0, 0x8\n"
	"\tstr r0, [r4, 0xC]\n"
	"\tsubs r5, 0x1\n"
	"\tcmp r5, 0\n"
	"\tbne _080948F0\n"
"_0809491C:\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

void sub_8094924(struct unkStruct_8094924 *r0, u8 *r1, s32 size)
{
    s32 r6;
    u8 *r2;

    r6 = 0;
    r2 = r1;


    if(size != 0)
    {
        while(size != 0)
        {
            if(r6 == 0)
                *r2 = 0;
            if(( *(r0->unk0) >> r0->unk8) & 1)
            {
                *r2 |= (1 << r6);
            }
            r6++;
            if(r6 == 8)
            {
                r2++;
                r6 = 0;
            }
            r0->unk8++;
            if(r0->unk8 == 8)
            {
                r0->unk0++;
                r0->unk8 = 0;
            }
            r0->unkC++;
            size--;
        }
    }
}
