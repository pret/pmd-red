#include "global.h"
#include "globaldata.h"
#include "position_util.h"

#include "constants/direction.h"

static const s32 sFacingDirMapping[3][3] = {
    {DIRECTION_NORTHWEST, DIRECTION_NORTH, DIRECTION_NORTHEAST},
    {DIRECTION_WEST, DIRECTION_SOUTH, DIRECTION_EAST},
    {DIRECTION_SOUTHWEST, DIRECTION_SOUTH, DIRECTION_SOUTHEAST}
};

s32 GetDirectionTowardsPosition(DungeonPos *originPos, DungeonPos *targetPos)
{
    s32 xDiff = targetPos->x - originPos->x;
    s32 yDiff = targetPos->y - originPos->y;

    if (xDiff == 0 && yDiff == 0)
        return DIRECTION_SOUTH;

    if (xDiff >= 1)
        xDiff = 1;
    if (yDiff >= 1)
        yDiff = 1;
    if (xDiff <= -1)
        xDiff = -1;
    if (yDiff <= -1)
        yDiff = -1;

    return sFacingDirMapping[yDiff + 1][xDiff + 1];
}

s32 GetDistance(DungeonPos *pos1, DungeonPos *pos2)
{
    return max(abs(pos1->x - pos2->x), abs(pos1->y - pos2->y));
}
