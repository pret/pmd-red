#include "global.h"

extern u32 gIQSkillNames[];
extern u32 gIQSkillDescriptions[];
extern u32 gTacticsDescriptions[];
extern u8 *gTactics[];
extern u8 gUnknown_810A36B[];

extern s16 gUnknown_810A378[];
extern s32 gUnknown_810A390[];

u32 sub_808EAB0(u8 r0)
{
    return gIQSkillNames[r0];
}

void sub_808EAC0(char *r0, u8 r1)
{
    strncpy(r0, gTactics[r1], 0x14);
}

u32 sub_808EADC(u8 r0)
{
    return gIQSkillDescriptions[r0];
}

u32 sub_808EAEC(u8 r0)
{
    return gTacticsDescriptions[r0];
}

u8 sub_808EAFC(u8 r0)
{
    return gUnknown_810A36B[r0];
}

void sub_808EB0C(u8 *r0, s32 r1)
{
    s32 counter;
    s32 storage;
    u32 index;
    storage = 0;
    index = 0;
    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[index] <= r1)
        {
            r0[storage] = counter;
            storage++;
        }
        index++;
    }
    if(storage > 0xB)
    {
        return;
    }
    while(storage <= 0xB)
    {
        r0[storage] = 0xB;
        storage++;
    }
}

void sub_808EB48(u8 *r0, s32 r1)
{
    s32 counter;

    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[counter] <= r1)
        {
            r0[counter] = TRUE;
        }
        else
        {
            r0[counter] = FALSE;
        }
    }
}

bool8 sub_808EB7C(s32 r0, u8 r1)
{
    if(r1 == 0)
    {
        return FALSE;
    }

    return gUnknown_810A390[r1] <= r0;
}
