#ifndef GUARD_CONSTANTS_ADJACENT_TILE_OFFSETS_H
#define GUARD_CONSTANTS_ADJACENT_TILE_OFFSETS_H

#include "position.h"

const struct Position gAdjacentTileOffsets[8] = {
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1}
};

#endif