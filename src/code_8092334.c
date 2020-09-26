#include "global.h"

extern u32 gUnformattedTypeStrings[]; // unformatted type names
extern u32 gFormattedTypeStrings[]; // formatted type names
extern u8 gUnknown_810AC7C[];
extern u8 gUnknown_810AC6A[];
extern u8 *gUnknown_810B4C8[];
extern u8 *gUnknown_810B988[];
extern u32 gUnknown_2038C28;
extern u32 *gUnknown_203B468;

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
    strncpy(r0, gUnknown_810B4C8[r1], 0x50);
}

u8 *sub_8092390(u8 r0)
{
    return gUnknown_810B988[r0];
}

void sub_80923A0(void)
{
    gUnknown_203B468 = &gUnknown_2038C28;
}

u32 *sub_80923B0(void)
{
    return &gUnknown_2038C28;
}
