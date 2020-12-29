#include "global.h"

extern u32 gUnformattedTypeStrings[]; // unformatted type names
extern u32 gFormattedTypeStrings[]; // formatted type names

extern u8 gUnknown_810AC7C[];
extern u8 gUnknown_810AC6A[];

extern u8 *gAbilityNames[];
extern u8 *AbilityDescriptions[];


u32 GetUnformattedTypeString(u8 type)
{
    return gUnformattedTypeStrings[type];
}

u32 GetFormattedTypeString(u8 type)
{
    return gFormattedTypeStrings[type];
}

u8 sub_8092354(u8 index)
{
    return gUnknown_810AC7C[index];
}

u8 sub_8092364(u8 index)
{
    return gUnknown_810AC6A[index];
}

void sub_8092374(char *r0, u8 index)
{
    strncpy(r0, gAbilityNames[index], 0x50);
}

u8 *GetAbilityDescription(u8 index)
{
    return AbilityDescriptions[index];
}

