#include "global.h"
#include "position_util.h"

#include "constants/direction.h"

const s32 gFacingDirMapping[3][3] = {
  {DIRECTION_NORTHWEST, DIRECTION_NORTH, DIRECTION_NORTHEAST},
  {DIRECTION_WEST, DIRECTION_SOUTH, DIRECTION_EAST},
  {DIRECTION_SOUTHWEST, DIRECTION_SOUTH, DIRECTION_SOUTHEAST}
};

s32 CalculateFacingDir(struct Position *originPos, struct Position *targetPos)
{
  s32 facingDir;
  s32 yDiff;
  s32 xDiff;

  xDiff = targetPos->x - originPos->x;
  yDiff = targetPos->y - originPos->y;
  if (xDiff == 0 && yDiff == 0)
  {
    facingDir = DIRECTION_SOUTH;
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
    facingDir = gFacingDirMapping[yDiff + 1][xDiff + 1];
  }
  return facingDir;
}

s32 GetMaxPositionDifference(short param_1[],short param_2[])
{
  s32 diff_index1;
  s32 diff_index0;

  diff_index0 = param_1[0] - param_2[0];
  if (diff_index0 < 0) {
    diff_index0 = -diff_index0;
  }
  diff_index1 = param_1[1] - param_2[1];
  if (diff_index1 < 0) {
    diff_index1 = -diff_index1;
  }
  if (diff_index1 < diff_index0) {
    diff_index1 = diff_index0;
  }
  return diff_index1;
}

