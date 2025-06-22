#include "global.h"
#include "globaldata.h"
#include "pokemon_types.h"
#include "strings.h"
#include "dungeon_data.h"

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

u8 GetBestResistingType(u8 index)
{
    return gBestResistTypeTable[index];
}
