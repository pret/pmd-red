#include "global.h"
#include "constants/friend_area.h"
#include "friend_area.h"

extern struct FriendAreaSettings gFriendAreaSettings[58];
extern bool8 *gFriendAreas;

extern u32 gFriendAreaDescriptions[];
extern const char *gFriendAreaNames[];
extern u32 gUnknown_81098A4;

extern void sub_800D158(u8 *r0, u32 *r1, const char *r2, ...);

const char *GetFriendAreaName(u8 index)
{
    return gFriendAreaNames[index];
}

u8 GetFriendAreaUnlockCondition(u8 index)
{
    return gFriendAreaSettings[index].unlock_condition;
}

u32 GetFriendAreaPrice(u8 index)
{
    return gFriendAreaSettings[index].price;
}

void sub_8092558(u8 *r0, u8 index)
{
    sub_800D158(r0, &gUnknown_81098A4, gFriendAreaNames[index]);
}

#ifdef NONMATCHING
void sub_8092578(u8 *r0, u8 r1, u8 r2)
{
    struct unkFriendAreaStruct temp;
    if(r2)
    {
        sub_8090FEC(gFriendAreaSettings[r1].price,&(temp.unk4),1);
        // TODO: There's some stack storage here in the middle calling this func
        //         add     r0, sp, 0x4
        //          str     r0, [sp] 
        //temp.unk0 = temp.unk4;
        sub_800D158(r0,&gUnknown_81098AC,gFriendAreaNames[r1],0x60);
    }
    else
    {
        strcpy(r0, gFriendAreaNames[r1]);
    }
}
#else
NAKED void sub_8092578(u8 *r0, u8 r1, u8 r2)
{
        asm_unified("\tpush {r4,r5,lr}\n"
	"\tsub sp, 0x18\n"
	"\tadds r5, r0, 0\n"
	"\tlsls r1, 24\n"
	"\tlsrs r4, r1, 24\n"
	"\tlsls r2, 24\n"
	"\tcmp r2, 0\n"
	"\tbeq _080925C0\n"
	"\tldr r0, _080925B4\n"
	"\tlsls r1, r4, 3\n"
	"\tadds r0, 0x4\n"
	"\tadds r1, r0\n"
	"\tldr r0, [r1]\n"
	"\tadd r1, sp, 0x4\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_8090FEC\n"
	"\tldr r1, _080925B8\n"
	"\tldr r2, _080925BC\n"
	"\tlsls r0, r4, 2\n"
	"\tadds r0, r2\n"
	"\tldr r2, [r0]\n"
	"\tadd r0, sp, 0x4\n"
	"\tstr r0, [sp]\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r3, 0x60\n"
	"\tbl sub_800D158\n"
	"\tb _080925CE\n"
	"\t.align 2, 0\n"
"\t_080925B4: .4byte gFriendAreaSettings\n"
"\t_080925B8: .4byte gUnknown_81098AC\n"
"\t_080925BC: .4byte gFriendAreaNames\n"
"\t_080925C0:\n"
	"\tldr r0, _080925D8\n"
	"\tlsls r1, r4, 2\n"
	"\tadds r1, r0\n"
	"\tldr r1, [r1]\n"
	"\tadds r0, r5, 0\n"
	"\tbl strcpy\n"
"\t_080925CE:\n"
	"\tadd sp, 0x18\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"\t_080925D8: .4byte gFriendAreaNames");
}
#endif

u32 GetFriendAreaDescription(u8 index)
{
    return gFriendAreaDescriptions[index];
}

void UnlockFriendArea(u8 index)
{
    gFriendAreas[index] = TRUE;
}

bool8 GetFriendAreaStatus(u8 index)
{
    return gFriendAreas[index];
}

bool8 HasAllFriendAreas(void)
{
    s32 counter;
    for(counter = 1; counter < NUM_FRIEND_AREAS; counter++)
    {
        if(!gFriendAreas[counter])
        {
            return FALSE;
        }
    }
    return TRUE;
}
