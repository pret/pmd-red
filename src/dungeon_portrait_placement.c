#include "global.h"
#include "globaldata.h"
#include "dungeon_portrait_placement.h"

// Note: this file is not part of overlay5. It's most likely arm9.bin, but I couldn't locate the address

static const struct PortraitPlacementInfo gUnknown_8107544[] = {
    [0] = {{2,  8}, FALSE},
    [1] = {{12, 5}, FALSE},
    [2] = {{2,  8}, FALSE},
    [3] = {{23, 8}, TRUE},
    [4] = {{7,  8}, FALSE},
    [5] = {{18, 8}, TRUE},
    [6] = {{13, 5}, TRUE},
    [7] = {{2,  8}, TRUE},
    [8] = {{23, 8}, FALSE},
    [9] = {{7,  8}, TRUE},
    [10] = {{18, 8}, FALSE},
    [11] = {{12, 1}, FALSE},
    [12] = {{2,  2}, FALSE},
    [13] = {{23, 2}, TRUE},
    [14] = {{7,  1}, FALSE},
    [15] = {{18, 1}, TRUE},
    [16] = {{13, 1}, TRUE},
    [17] = {{2,  2}, TRUE},
    [18] = {{23, 2}, FALSE},
    [19] = {{7,  1}, TRUE},
    [20] = {{18, 1}, FALSE},
};

const struct PortraitPlacementInfo *GetPortraitPlacementInfo(u8 id)
{
    return &gUnknown_8107544[id];
}
