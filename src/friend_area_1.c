#include "global.h"
#include "constants/friend_area.h"

extern bool8 *gFriendAreas;
extern void sub_809485C(u32 *r0, u8 *r1, u32 r2);
extern void sub_8094924(u32 *r0, u32 *r1, u32);
extern void nullsub_102(u32 *r0);
extern void sub_809488C(u32 *r0, u32 *r1, u32 r2);
extern void sub_809486C(u32 *r0, u8 *r1, u32 r2);

u32 sub_80927A8(u8 *r0, u32 r1)
{
    u32 temp[5];
    s32 counter;

    sub_809486C(temp, r0, r1);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        if(gFriendAreas[counter] != 0)
            temp[4] = -1;
        else
            temp[4] = 0;
        sub_809488C(temp, &(temp[4]), 1);
    }
    nullsub_102(temp);
    return temp[2];
}

u32 sub_80927F4(u8 *r0, u32 r1)
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

