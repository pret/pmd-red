#ifndef GUARD_PORTRAIT_PLACEMENT_H
#define GUARD_PORTRAIT_PLACEMENT_H

// Note: There are two the same, duplicated tables for dungeon and scripts.

#include "structs/str_position.h"

struct PortraitPlacementInfo
{
    DungeonPos pos;
    bool8 flip;
};

// Sets of x, y pos and flips. Instead of passing positions for each portrait, a set id is passed and positions are taken from the table.
enum PortraitPlacements
{
    PLACEMENT_LEFT,
    PLACEMENT_MIDDLE_TOP,
    PLACEMENT_LEFT_, // Same as PLACEMENT_LEFT
    PLACEMENT_RIGHT,
    PLACEMENT_MIDDLE_LEFT,
    PLACEMENT_MIDDLE_RIGHT,
    PLACEMENT_MIDDLE_TOP_FLIP,
    PLACEMENT_LEFT_FLIP,
    PLACEMENT_RIGHT_FLIP,
    PLACEMENT_MIDDLE_LEFT_FLIP,
    PLACEMENT_MIDDLE_RIGHT_FLIP,
    PLACEMENT_TOP,
    PLACEMENT_TOP_LEFT,
    PLACEMENT_TOP_RIGHT,
    PLACEMENT_MIDDLE_TOP_LEFT,
    PLACEMENT_MIDDLE_TOP_RIGHT,
    PLACEMENT_TOP_FLIP,
    PLACEMENT_TOP_LEFT_FLIP,
    PLACEMENT_TOP_RIGHT_FLIP,
    PLACEMENT_MIDDLE_TOP_LEFT_FLIP,
    PLACEMENT_MIDDLE_TOP_RIGHT_FLIP,
    PLACEMENT_COUNT
};

#endif
