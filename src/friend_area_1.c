#include "global.h"
#include "constants/friend_area.h"
#include "code_8092334.h"
#include "friend_area.h"

u32 SaveFriendAreas(u8 *r0, u32 size)
{
    struct unkStruct_8094924 unk;
    u32 temp;
    s32 counter;

    xxx_init_struct_8094924_save_809486C(&unk, r0, size);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        if(gFriendAreas[counter] != 0)
            temp = -1;
        else
            temp = 0;
        SaveIntegerBits(&unk, (u8*)&temp, 1);
    }
    nullsub_102(&unk);
    return unk.unk8;
}

u32 ReadSavedFriendAreas(u8 *r0, s32 size)
{
    struct unkStruct_8094924 unk;
    u32 temp;
    s32 counter;

    xxx_init_struct_8094924_restore_809485C(&unk, r0, size);
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        RestoreIntegerBits(&unk, &temp, 1);
        // It's setting whether we have the friend area or not
        if(temp & 1)
            gFriendAreas[counter] = 1;
        else
            gFriendAreas[counter] = 0;
    }
    nullsub_102(&unk);
    return unk.unk8;
}

