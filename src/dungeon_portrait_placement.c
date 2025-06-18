#include "global.h"
#include "globaldata.h"
#include "dungeon_portrait_placement.h"

// Note: this file is not part of overlay5. It's most likely arm9.bin, but I couldn't locate the address

static const struct PortraitPlacementInfo sPortraitPlacements[PLACEMENT_COUNT] = {
    [PLACEMENT_LEFT]                    = {{2,  8}, FALSE},
    [PLACEMENT_MIDDLE_TOP]              = {{12, 5}, FALSE},
    [PLACEMENT_LEFT_]                   = {{2,  8}, FALSE},
    [PLACEMENT_RIGHT]                   = {{23, 8}, TRUE},
    [PLACEMENT_MIDDLE_LEFT]             = {{7,  8}, FALSE},
    [PLACEMENT_MIDDLE_RIGHT]            = {{18, 8}, TRUE},
    [PLACEMENT_MIDDLE_TOP_FLIP]         = {{13, 5}, TRUE},
    [PLACEMENT_LEFT_FLIP]               = {{2,  8}, TRUE},
    [PLACEMENT_RIGHT_FLIP]              = {{23, 8}, FALSE},
    [PLACEMENT_MIDDLE_LEFT_FLIP]        = {{7,  8}, TRUE},
    [PLACEMENT_MIDDLE_RIGHT_FLIP]       = {{18, 8}, FALSE},
    [PLACEMENT_TOP]                     = {{12, 1}, FALSE},
    [PLACEMENT_TOP_LEFT]                = {{2,  2}, FALSE},
    [PLACEMENT_TOP_RIGHT]               = {{23, 2}, TRUE},
    [PLACEMENT_MIDDLE_TOP_LEFT]         = {{7,  1}, FALSE},
    [PLACEMENT_MIDDLE_TOP_RIGHT]        = {{18, 1}, TRUE},
    [PLACEMENT_TOP_FLIP]                = {{13, 1}, TRUE},
    [PLACEMENT_TOP_LEFT_FLIP]           = {{2,  2}, TRUE},
    [PLACEMENT_TOP_RIGHT_FLIP]          = {{23, 2}, FALSE},
    [PLACEMENT_MIDDLE_TOP_LEFT_FLIP]    = {{7,  1}, TRUE},
    [PLACEMENT_MIDDLE_TOP_RIGHT_FLIP]   = {{18, 1}, FALSE},
};

const struct PortraitPlacementInfo *GetPortraitPlacementInfo(u8 id)
{
    return &sPortraitPlacements[id];
}
