#include "global.h"

extern u32 gUnformattedTypeStrings[]; // unformatted type names
extern u32 gFormattedTypeStrings[]; // formatted type names
extern u8 gUnknown_810AC7C[];
extern u8 gUnknown_810AC6A[];

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
