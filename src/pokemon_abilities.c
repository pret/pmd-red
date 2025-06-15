#include "global.h"
#include "globaldata.h"
#include "pokemon_abilities.h"
#include "strings.h"

// Unused
void CopyAbilityNametoBuffer(char *buffer, u8 index)
{
    strncpy(buffer, gAbilityNames[index], 0x50);
}

const u8 *GetAbilityDescription(u8 index)
{
    return gAbilityDescriptions[index];
}
