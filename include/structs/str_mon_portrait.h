#ifndef GUARD_STR_MON_PORTRAIT_H
#define GUARD_STR_MON_PORTRAIT_H

#include "structs/rgb.h"
#include "structs/str_file_system.h"
#include "structs/str_position.h"

// size: 0x8
typedef struct PortraitGfxSub
{
    const RGB *pal;
    const u8 *gfx;
} PortraitGfxSub;

// size: variable
typedef struct PortraitGfx
{
    // NOTE: The actual number of sprites is different depending on pokemon. For example, starters have 12 sprites, while most legendaries only 1. Unused sprites are set as NULL, NULL.
    PortraitGfxSub sprites[12];
} PortraitGfx;

// size: 0xC
typedef struct MonPortraitMsg
{
    OpenedFile *faceFile;
    PortraitGfx *faceData;
    DungeonPos pos;
    u8 spriteId; // Which mon's sprite to use. For example Kecleon has multiple sprites depending on whether it's green or purple.
    bool8 flip; // Whether the mon's sprite is flipped.
    u8 unkE;
} MonPortraitMsg;

#endif // GUARD_STR_MON_PORTRAIT_H
