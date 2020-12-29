#include "global.h"
#include "constants/friend_area.h"

struct unkStruct_80927F4
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

extern bool8 *gFriendAreas;
extern void sub_809485C(struct unkStruct_80927F4 *r0, u32 r1, u32 r2);
extern void sub_8094924(struct unkStruct_80927F4 *r0, u32 *r1, u32);
extern void nullsub_102(struct unkStruct_80927F4 *r0);
extern void sub_809488C(struct unkStruct_80927F4 *r0, u32 *r1, u32 r2);
extern void sub_809486C(struct unkStruct_80927F4 *r0, u32 r1, u32 r2);

#ifndef NONMATCHING
NAKED
#endif
u32 sub_80927A8(u32 r0, u32 r1)
{
#ifdef NONMATCHING
    struct unkStruct_80927F4 temp;
    s32 counter;

    sub_809486C(&temp, r0, r1);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        // TODO moves into R1 for the load/cmp... else it matches
        if(!gFriendAreas[counter])
            temp.unk10 = gFriendAreas[counter];
        else
            temp.unk10 = -1;
        sub_809488C(&temp, &(temp.unk10), 1);
    }
    nullsub_102(&temp);
    return temp.unk8;
#else
	asm_unified("\tpush {r4,r5,lr}\n"
	"\tsub sp, 0x14\n"
	"\tadds r3, r0, 0\n"
	"\tadds r2, r1, 0\n"
	"\tmov r0, sp\n"
	"\tadds r1, r3, 0\n"
	"\tbl sub_809486C\n"
	"\tmovs r4, 0\n"
	"\tadd r5, sp, 0x10\n"
"_080927BC:\n"
	"\tldr r0, _080927F0\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _080927CC\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
"_080927CC:\n"
	"\tstr r0, [sp, 0x10]\n"
	"\tmov r0, sp\n"
	"\tadds r1, r5, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_809488C\n"
	"\tadds r4, 0x1\n"
	"\tcmp r4, 0x39\n"
	"\tble _080927BC\n"
	"\tmov r0, sp\n"
	"\tbl nullsub_102\n"
	"\tldr r0, [sp, 0x8]\n"
	"\tadd sp, 0x14\n"
	"\tpop {r4,r5}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_080927F0: .4byte gFriendAreas");

#endif
}

u32 sub_80927F4(u32 r0, u32 r1)
{
    struct unkStruct_80927F4 temp;
    s32 counter;

    sub_809485C(&temp, r0, r1);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        sub_8094924(&temp, &(temp.unk10), 1);

        // It's setting whether we have the friend area or not
        if((temp.unk10 & 1))
            gFriendAreas[counter] = TRUE;
        else
            gFriendAreas[counter] = FALSE;
    }
    nullsub_102(&temp);
    return temp.unk8;
}

