#ifndef GUARD_DUNGEON_PORTRAIT_PLACEMENT_H
#define GUARD_DUNGEON_PORTRAIT_PLACEMENT_H

#include "structs/str_position.h"

struct PortraitPlacementInfo
{
    DungeonPos pos;
    bool8 flip;
};

const struct PortraitPlacementInfo *GetPortraitPlacementInfo(u8 id);

#endif
