#ifndef GUARD_POKEMON_TYPES_H
#define GUARD_POKEMON_TYPES_H

const char *GetUnformattedTypeString(u8 type);
const char * GetFormattedTypeString(u8 type);
u8 IsTypePhysical(u8 index);
u8 GetBestResistingType(u8 index);

#endif // GUARD_POKEMON_TYPES_H
