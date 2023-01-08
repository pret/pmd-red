#include "global.h"
#include "position_util.h"

#include "constants/direction.h"

const s32 gFacingDirMapping[3][3] = {
    {DIRECTION_NORTHWEST, DIRECTION_NORTH, DIRECTION_NORTHEAST},
    {DIRECTION_WEST, DIRECTION_SOUTH, DIRECTION_EAST},
    {DIRECTION_SOUTHWEST, DIRECTION_SOUTH, DIRECTION_SOUTHEAST}
};

s32 GetDirectionTowardsPosition(struct Position *originPos, struct Position *targetPos)
{
    s32 direction;
    s32 yDiff;
    s32 xDiff;

    xDiff = targetPos->x - originPos->x;
    yDiff = targetPos->y - originPos->y;
    if (xDiff == 0 && yDiff == 0)
    {
        direction = DIRECTION_SOUTH;
    }
    else
    {
        if (xDiff > 0)
        {
            xDiff = 1;
        }
        if (yDiff > 0)
        {
            yDiff = 1;
        }
        if (xDiff <= -1)
        {
            xDiff = -1;
        }
        if (yDiff <= -1)
        {
            yDiff = -1;
        }
        direction = gFacingDirMapping[yDiff + 1][xDiff + 1];
    }
    return direction;
}

s32 GetDistance(struct Position *pos1, struct Position *pos2)
{
    s32 distanceX = pos1->x - pos2->x;
    s32 distance;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    distance = pos1->y - pos2->y;
    if (distance < 0)
    {
        distance = -distance;
    }
    if (distance < distanceX)
    {
        distance = distanceX;
    }
    return distance;
}

