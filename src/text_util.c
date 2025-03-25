#include "global.h"
#include "text_util.h"

#define NUM_POKEMON_TYPES 18

extern const char gNoneText[];
extern const char gNormalText[];
extern const char gFireText[];
extern const char gWaterText[];
extern const char gGrassText[];
extern const char gElectricText[];
extern const char gIceText[];
extern const char gFightingText[];
extern const char gPoisonText[];
extern const char gGroundText[];
extern const char gFlyingText[];
extern const char gPsychicText[];
extern const char gBugText[];
extern const char gRockText[];
extern const char gGhostText[];
extern const char gDragonText[];
extern const char gDarkText[];
extern const char gSteelText[];

extern const char gFormattedNoneText[];
extern const char gFormattedNormalText[];
extern const char gFormattedFireText[];
extern const char gFormattedWaterText[];
extern const char gFormattedGrassText[];
extern const char gFormattedElectricText[];
extern const char gFormattedIceText[];
extern const char gFormattedFightingText[];
extern const char gFormattedPoisonText[];
extern const char gFormattedGroundText[];
extern const char gFormattedFlyingText[];
extern const char gFormattedPsychicText[];
extern const char gFormattedBugText[];
extern const char gFormattedRockText[];
extern const char gFormattedGhostText[];
extern const char gFormattedDragonText[];
extern const char gFormattedDarkText[];
extern const char gFormattedSteelText[];

// NDS=020C81F0
const char * const gUnformattedTypeStrings[NUM_POKEMON_TYPES] =
{
    gNoneText,
    gNormalText,
    gFireText,
    gWaterText,
    gGrassText,
    gElectricText,
    gIceText,
    gFightingText,
    gPoisonText,
    gGroundText,
    gFlyingText,
    gPsychicText,
    gBugText,
    gRockText,
    gGhostText,
    gDragonText,
    gDarkText,
    gSteelText,
};

#include "data/unformatted_type_names.h"

const char * const gFormattedTypeStrings[NUM_POKEMON_TYPES] =
{
    gFormattedNoneText,
    gFormattedNormalText,
    gFormattedFireText,
    gFormattedWaterText,
    gFormattedGrassText,
    gFormattedElectricText,
    gFormattedIceText,
    gFormattedFightingText,
    gFormattedPoisonText,
    gFormattedGroundText,
    gFormattedFlyingText,
    gFormattedPsychicText,
    gFormattedBugText,
    gFormattedRockText,
    gFormattedGhostText,
    gFormattedDragonText,
    gFormattedDarkText,
    gFormattedSteelText,
};

#include "data/formatted_type_names.h"


extern u8 *gAbilityNames[];
extern u8 *AbilityDescriptions[];
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

u8 *GetAbilityDescription(u8 index)
{
    return AbilityDescriptions[index];
}
