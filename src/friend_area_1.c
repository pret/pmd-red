#include "global.h"
#include "constants/friend_area.h"

extern bool8 *gFriendAreas;
extern void sub_809485C(u32 *r0, u32 r1, u32 r2);
extern void sub_8094924(u32 *r0, u32 *r1, u32);
extern void nullsub_102(u32 *r0);
extern void sub_809488C(u32 *r0, u32 *r1, u32 r2);
extern void sub_809486C(u32 *r0, u32 r1, u32 r2);

#ifdef NONMATCHING
u32 sub_80927A8(u32 r0, u32 r1)
{
    u32 temp[5];
    s32 counter;

    sub_809486C(temp, r0, r1);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        // TODO moves into R1 for the load else it matches
        if(!gFriendAreas[counter])
            temp[4] = gFriendAreas[counter];
        else
            temp[4] = -1;
        sub_809488C(temp, &(temp[4]), 1);
    }
    nullsub_102(temp);
    return temp[2];
}
#else
NAKED u32 sub_80927A8(u32 r0, u32 r1)
{
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
}
#endif

u32 sub_80927F4(u32 r0, u32 r1)
{
    u32 temp[5];
    s32 counter;

    sub_809485C(temp, r0, r1);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        sub_8094924(temp, &(temp[4]), 1);
        // It's setting whether we have the friend area or not
        if((temp[4] & 1))
            gFriendAreas[counter] = TRUE;
        else
            gFriendAreas[counter] = FALSE;
    }
    nullsub_102(temp);
    return temp[2];
}

