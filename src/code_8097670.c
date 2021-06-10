#include "global.h"

struct unkStruct_203B494
{
    // size: 0xC8?
    u32 unk0;
    s32 numAdventures;
    s32 unk8;
    s32 unkC;
    u8 unk10; // location?
    u8 unk11;
    u8 fill12[2];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u32 unk1C[0xE];
    u8 fill54[0x8C - 0x54];
    u32 unk8C[0xD];
    union UNKC0{
        s32 unkC0;
        s16 unkC0_16;
    } UNKC0;
};

extern struct unkStruct_203B494 *gUnknown_203B494;
extern struct unkStruct_203B494 gUnknown_2039778;
extern const u8 *gAdventureLogText[];

void sub_8097670(void)
{
    gUnknown_203B494 = &gUnknown_2039778;
}

struct unkStruct_203B494 *sub_8097680(void)
{
    return &gUnknown_2039778;
}

void sub_8097688(u8 *r0)
{
    gUnknown_203B494->unk10 = r0[0];
    gUnknown_203B494->unk11 = r0[1];
}

u8 *sub_809769C(void)
{
    return &gUnknown_203B494->unk10;
}

void sub_80976A8(void)
{
    s32 iVar2;

    gUnknown_203B494->unk0 = 0;
    gUnknown_203B494->unk14 = 0;
    gUnknown_203B494->unk16 = 0;
    gUnknown_203B494->unk18 = 0;
    gUnknown_203B494->UNKC0.unkC0 = 0;
    gUnknown_203B494->unk8 = 0;
    gUnknown_203B494->unkC = 0;

    for(iVar2 = 0; iVar2 < 0xE; iVar2++)
    {
        gUnknown_203B494->unk1C[iVar2] = 0;
    }
    
    for(iVar2 = 0; iVar2 < 0xD; iVar2++)
    {
        gUnknown_203B494->unk8C[iVar2] = 0;
    }
}

void sub_80976F8(u8 r0)
{
    gUnknown_203B494->unk0 |= (1 << r0);
}

u8 sub_8097710(u8 r0)
{
    if((gUnknown_203B494->unk0 & (1 << r0)) != 0)
        return 1;
    else
        return 0;
}

const u8 *GetAdventureLogLine(u8 index)
{
    return gAdventureLogText[index];
}

void ResetNumAdventures(void)
{
    gUnknown_203B494->numAdventures = 0;
}

void IncrementNumAdventures(void)
{
    gUnknown_203B494->numAdventures++;
    if(gUnknown_203B494->numAdventures > 99999)
        gUnknown_203B494->numAdventures = 99999;
}

s32 GetNumAdventures(void)
{
    return gUnknown_203B494->numAdventures;
}

void SetNumAdventures(s32 numAdventures)
{
    gUnknown_203B494->numAdventures = numAdventures;
}

void sub_8097790(void)
{
    gUnknown_203B494->unk8++;
    if(gUnknown_203B494->unk8 > 99999)
        gUnknown_203B494->unk8 = 99999;
    sub_80976F8(8);
}

s32 sub_80977B8(void)
{
    return gUnknown_203B494->unk8;
}

void sub_80977C4(s32 r0)
{
    gUnknown_203B494->unk8 = r0;
}

void sub_80977D0(void)
{
    gUnknown_203B494->unkC++;
    if(gUnknown_203B494->unkC > 99999)
        gUnknown_203B494->unkC = 99999;
    sub_80976F8(9);
}

s32 sub_80977F8(void)
{
    return gUnknown_203B494->unkC;
}

void sub_8097804(s32 r0)
{
    gUnknown_203B494->unkC = r0;
}

void sub_8097810(void)
{
    if(gUnknown_203B494->unk14 < 9999)
        gUnknown_203B494->unk14++;
    sub_80976F8(0xB);
}

s16 sub_8097838(void)
{
    return gUnknown_203B494->unk14;
}

void sub_8097848(void)
{
    if(gUnknown_203B494->unk16 < 9999)
        gUnknown_203B494->unk16++;
    sub_80976F8(0xA);
}

s16 sub_8097870(void)
{
    return gUnknown_203B494->unk16;
}

s16 sub_8097880(void)
{
    return gUnknown_203B494->unk18;
}

void sub_8097890(void)
{
    if(gUnknown_203B494->UNKC0.unkC0 < 99999)
        gUnknown_203B494->UNKC0.unkC0++;
    sub_80976F8(0xC);
}

s16 sub_80978B8(void)
{
    return gUnknown_203B494->UNKC0.unkC0_16;
}
