#include "global.h"

#define NUM_FRIEND_AREAS 58

extern u32 gUnformattedTypeStrings[]; // unformatted type names
extern u32 gFormattedTypeStrings[]; // formatted type names

extern u8 gUnknown_810AC7C[];
extern u8 gUnknown_810AC6A[];

extern u8 *gAbilityNames[];
extern u8 *AbilityDescriptions[];

extern u8 gBoughtFriendAreas[NUM_FRIEND_AREAS];
extern u8 *gUnknown_203B468;

extern s16 gUnknown_810AA90[];

u32 GetUnformattedTypeString(u8 type)
{
    return gUnformattedTypeStrings[type];
}

u32 GetFormattedTypeString(u8 type)
{
    return gFormattedTypeStrings[type];
}

u8 sub_8092354(u8 r0)
{
    return gUnknown_810AC7C[r0];
}

u8 sub_8092364(u8 r0)
{
    return gUnknown_810AC6A[r0];
}

void sub_8092374(char *r0, u8 r1)
{
    strncpy(r0, gAbilityNames[r1], 0x50);
}

u8 *sub_8092390(u8 r0)
{
    return AbilityDescriptions[r0];
}

void sub_80923A0(void)
{
    gUnknown_203B468 = gBoughtFriendAreas;
}

u8 *sub_80923B0(void)
{
    return gBoughtFriendAreas;
}

void sub_80923B8(void)
{
    s32 counter;
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        gUnknown_203B468[counter] = 0;
    }
}

u8 sub_80923D4(s32 target)
{
    s32 counter;
    s32 index;
    s32 sum = 0;
    index = 0;
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        sum += gUnknown_810AA90[index];
        if(sum > target)
        {
            return counter;
        }
        index += 4;
    }
    return 0;
}
