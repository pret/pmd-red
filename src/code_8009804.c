#include "global.h"

extern u8 gUnknown_202D238[4];

extern s32 gUnknown_202D23C;

struct unkStruct_202D240
{
    u32 *unk0;
    u32 *unk4;
    u32 *unk8;
};
extern struct unkStruct_202D240 gUnknown_202D240[8];

void vram_related_8009804(void)
{
    u32 counter;
    u32 *r1;

    r1 = (u32 *) VRAM;
    for(counter = 0; counter < 0x13C0; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) 0x06007000;
    for(counter = 0; counter < 0x400; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) 0x06008000;
    for(counter = 0; counter < 0x2000; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OBJ_VRAM0;
    for(counter = 0; counter < 0x1f80; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) PLTT;
    for(counter = 0; counter < 0x78; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OBJ_PLTT;
    for(counter = 0; counter < 0x78; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OAM;
    for(counter = 0; counter < 0x100; counter++)
    {
        *r1++ = 0xa000a0;
    }
}

void sub_80098A0(void)
{
    gUnknown_202D23C = 0;
    gUnknown_202D238[0] = 0;
    gUnknown_202D238[1] = 0;
    gUnknown_202D238[2] = 0;
    gUnknown_202D238[3] = 0;
}

void sub_80098BC(u32 *r0, u32 *r1, u32 *r2)
{
    if(gUnknown_202D23C < 8){
        gUnknown_202D240[gUnknown_202D23C].unk0 = r0;
        gUnknown_202D240[gUnknown_202D23C].unk4 = r1;
        gUnknown_202D240[gUnknown_202D23C].unk8 = r2;
        gUnknown_202D23C++;
    }
}

void sub_80098F8(u32 r0)
{
    gUnknown_202D238[r0] = 1;
}
