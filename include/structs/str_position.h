#ifndef GUARD_STR_POSITION_H
#define GUARD_STR_POSITION_H

// size: 0x4
typedef struct Position
{
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Position;

// size: 0x8
typedef struct Position32
{
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Position32;

#endif // GUARD_STR_POSITION_H