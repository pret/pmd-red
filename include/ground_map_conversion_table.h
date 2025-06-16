#ifndef GUARD_GROUND_MAP_CONVERSION_TABLE_H
#define GUARD_GROUND_MAP_CONVERSION_TABLE_H

#include "constants/ground_map.h"

// size: 0xC
typedef struct GroundConversionStruct
{
    s16 unk0;
    s16 groundPlaceId;
    s16 mapFileTableId;
    s16 unk6;
    /* 0x8 */ const u8 *text;
} GroundConversionStruct;

extern const GroundConversionStruct gGroundMapConversionTable[MAP_COUNT + 1];

#endif // GUARD_GROUND_MAP_CONVERSION_TABLE_H
