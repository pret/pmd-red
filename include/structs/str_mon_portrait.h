#ifndef GUARD_STR_MON_PORTRAIT_H
#define GUARD_STR_MON_PORTRAIT_H

#include "structs/rgb.h"
#include "structs/str_file_system.h"
#include "structs/str_position.h"

// size: 0x8
typedef struct PortraitGfxSub
{
    /* 0x0 */ const RGB_Struct *pal;
    /* 0x4 */ const u8 *gfx;
} PortraitGfxSub;

// size: 0x68
typedef struct PortraitGfx
{
    // NOTE: The actual number of sprites is different depending on pokemon. For example, starters have 12 sprites, while most legendaries only 1. Unused sprites are set as NULL, NULL.
    /* 0x0 */ PortraitGfxSub sprites[13];
} PortraitGfx;

// Size: R=0x10 | B=0xF
typedef struct MonPortraitMsg
{
    /* 0x0 */ OpenedFile *faceFile;
    /* 0x4 */ PortraitGfx *faceData;
    /* 0x8 */ DungeonPos pos;
    /* 0xC */ u8 spriteId; // Which mon's sprite to use. For example Kecleon has multiple sprites depending on whether it's green or purple.
    /* 0xD */ bool8 flip; // Whether the mon's sprite is flipped.
    /* 0xE */ u8 unkE;
} MonPortraitMsg;

#endif // GUARD_STR_MON_PORTRAIT_H
