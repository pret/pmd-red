#include "global.h"

struct unkStruct_80A2608
{
    s16 unk0;
    /*0x2*/ u16 padding;
    /*0x4*/ u32 padding2;
    /*0x8*/ u16 padding3;
    /*0xA*/ u16 padding4;
    u8 unkC;
    /* 0xD */ u8 padding5;
    s16 unkE;
    u8 unk11;
};

extern u8 sub_80023E4(u32);
extern u8 sub_80973F4(s16);
extern struct unkStruct_80A2608 *sub_80A2608(s32);
extern struct unkStruct_80A2608 *sub_80A2620(u32);
extern u8 sub_8097384(u32);
extern s16 gUnknown_8116F9A[];

s16 sub_80A26B8(s16 r0)
{
    // Useless cast that forces correct ordering
    s32 temp;
    temp = r0;

    return gUnknown_8116F9A[r0];
}

s16 sub_80A26CC(s16 r0)
{
    return (0xDC >> 2) + r0;
}


#ifndef NONMATCHING
NAKED
#endif
s32 sub_80A26D8(u8 r0)
{
#ifdef NONMATCHING
    s32 counter;
    s32 counter2;
    struct unkStruct_80A2608 *temp;
    for(counter = 0; counter <= 0x52; counter++)
    {
        // Forcing a shift here.. but does it to R4 instead of R0
        counter2 = counter <<  0x10;
        counter2 >>= 0x10;
        temp = sub_80A2608(counter2);
        if(temp->unk11 != 0)
        {
            if(temp->unkC == r0)
            {
                return counter2;
            }
        }
    }
    return -1;
#else
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tlsls r0, 24\n"
	"\tlsrs r6, r0, 24\n"
	"\tmovs r5, 0\n"
"_080A26E0:\n"
	"\tlsls r0, r5, 16\n"
	"\tasrs r4, r0, 16\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_80A2608\n"
	"\tadds r1, r0, 0\n"
	"\tldrb r0, [r1, 0x11]\n"
	"\tcmp r0, 0\n"
	"\tbeq _080A26FC\n"
	"\tldrb r0, [r1, 0xC]\n"
	"\tcmp r0, r6\n"
	"\tbne _080A26FC\n"
	"\tadds r0, r4, 0\n"
	"\tb _080A2706\n"
"_080A26FC:\n"
	"\tadds r5, 0x1\n"
	"\tcmp r5, 0x52\n"
	"\tble _080A26E0\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
"_080A2706:\n"
	"\tpop {r4-r6}\n"
	"\tpop {r1}\n"
	"\tbx r1\n");
#endif
}

u8 sub_80A270C(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s32 temp_number;

    temp_number = r0; // forcing a shift before addressing
    temp = sub_80A2608(gUnknown_8116F9A[temp_number]);
    return temp->unkC;
}

u8 sub_80A2728(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s16 temp_number = (0xDC >> 2) + r0;
    temp = sub_80A2608(temp_number);
    return temp->unkC;
}

u8 sub_80A2740(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    temp = sub_80A2608(r0);
    return temp->unkC;
}

u32 sub_80A2750(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = r0;
    temp_2 = temp_32;

    if(r0 == 0x50)
        return 3;
    if(r0 == 0x51)
        return 2;
    if(r0 == 0x52)
        return 4;
    if((u16)(r0 - 0x28) <= 0xE)
        return 2;
    if((u16)(r0 - 0x37) <= 0x18)
        return 4;

    temp = sub_80A2608(temp_2);
    if(temp->unkE == -1)
        return 1;
    if(sub_80023E4(5) != 0)
        return 1;
    if(sub_80973F4(temp->unkE) == 0)
        return 1;
    if(sub_80023E4(1) == 0)
        return 1;
    return 2;
}

u32 sub_80A27CC(s16 r0)
{
    s32 temp;
    s32 temp2;
    struct unkStruct_80A2608 *return_var;

    // Same dumbness as above to get a match
    temp2 = r0;
    temp = temp2;

    return_var = sub_80A2620(r0);
    if(return_var->unk0 == -1)
        return 0;
    if(sub_80023E4(5) != 0)
        return 0;
    if(sub_8097384(r0) != 0)
        return 1;
    if(sub_80023E4(1) == 0)
        return 0;
    if(sub_80973F4(temp) == 0)
        return 0;
    return 1;
}
