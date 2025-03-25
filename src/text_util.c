#include "global.h"
#include "text_util.h"
#include "strings.h"

extern u8 gIsTypePhysicalTable[];
extern u8 gUnknown_810AC6A[];

extern u32 gUnknown_810983C[26]; // TODO: verify size later

u32 ReturnIntFromChar(u8 r0)
{
    return r0;
}

// arm9.bin::020614D0
u32 ReturnIntFromChar2(u8 r0)
{
    return r0;
}

UNUSED static void sub_8092290(u8 *buffer, u8 *string)
{
  while( *string != '\0' ) {
    *buffer++ = ReturnIntFromChar2(*string++);
  }
  *buffer = 0; // append a 0
}

void sub_80922B4(u8 *buffer, const u8 *string, s32 size)
{
    while(1)
    {
        if(size-- < 1 || *string == '\0')
        {
            break;
        }
        *buffer++ = ReturnIntFromChar2(*string++);
    }
    *buffer = 0; // append a 0
}

u32 sub_80922E4(u32 r0)
{
    return gUnknown_810983C[r0];
}

void CopyStringtoBuffer(u8 *buffer, u8 *string)
{
  while( *string != '\0' ) {
    *buffer++ = *string++;
  }
  *buffer = 0; // append a 0
}

void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size)
{
  while( 1 ) {
    if (size-- < 1) {
        break;
    }
    if (*string == '\0') {
        *buffer = 0; // append a 0 and break
        break;
    }
    // NOTE: *buffer++ = *string++ cases register flip
    *buffer = *string;
    buffer++;
    string++;
  }
}

// arm9.bin::02061508
const char *GetUnformattedTypeString(u8 type)
{
    return gUnformattedTypeStrings[type];
}

const char * GetFormattedTypeString(u8 type)
{
    return gFormattedTypeStrings[type];
}

u8 IsTypePhysical(u8 index)
{
    return gIsTypePhysicalTable[index];
}

u8 sub_8092364(u8 index)
{
    return gUnknown_810AC6A[index];
}

void CopyAbilityNametoBuffer(char *buffer, u8 index)
{
    strncpy(buffer, gAbilityNames[index], 0x50);
}

const u8 *GetAbilityDescription(u8 index)
{
    return AbilityDescriptions[index];
}
