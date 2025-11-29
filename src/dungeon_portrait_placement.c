#include "global.h"
#include "globaldata.h"
#include "dungeon_portrait_placement.h"

// Note: this file is not part of overlay5. It's most likely arm9.bin, but I couldn't locate the address

#include "data/portrait_placements.h"

const PortraitPlacementInfo *GetPortraitPlacementInfo(u8 id)
{
    return &sPortraitPlacements[id];
}
