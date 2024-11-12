#ifndef GUARD_STR_POSITION_H
#define GUARD_STR_POSITION_H

// size: 0x4
typedef struct Position
{
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Position;

/**
 * Precise position expressed in pixel units, as s24_8 fixpoint.
 * This type has subpixel precision to 1/256th of a pixel.
 */
// size: 0x8
typedef struct Position32
{
    /* 0x0 */ s32 x; // TODO: convert to s24_8 across the codebase
    /* 0x4 */ s32 y;
} Position32;

/**
 * Currently only used in script data, for entities and GroundLink data.
 * Position expressed in terms of *graphics* tiles, 8 pixels per unit.
 * Flags allow expressing half-tile offsets and allow using a current/default coordinate.
 */
// size: 0x4
typedef struct CompactPos {
    u8 xTiles;
    u8 yTiles;
    u8 xFlags;
    u8 yFlags;
} CompactPos;

#endif // GUARD_STR_POSITION_H
