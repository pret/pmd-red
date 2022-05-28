#include "global.h"
#include "dungeon_range.h"

#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "map.h"

extern bool8 IsTargetTwoTilesAway(struct Position *, struct Position *);

bool8 InSameRoom_2(struct Position *pos1, struct Position *pos2)
{
    u8 pos1RoomIndex;
    u8 visibility = gDungeonGlobalData->visibility;
    struct MapTile *tile1;
    if (visibility == 0)
    {
        visibility = 2;
    }
    tile1 = GetMapTile_1(pos1->x, pos1->y);
    pos1RoomIndex = tile1->roomIndex;
    if (pos1RoomIndex == CORRIDOR_ROOM_INDEX)
    {
        s32 xDiff = pos1->x - pos2->x;
        s32 yDiff;
        xDiff = xDiff < 0 ? -xDiff : xDiff;
        if (xDiff > visibility)
        {
            return FALSE;
        }

        yDiff = pos1->y - pos2->y;
        yDiff = yDiff < 0 ? -yDiff : yDiff;
        if (yDiff > visibility)
        {
            return FALSE;
        }
        returnTrue:
        return TRUE;
    }
    else
    {
        struct MapRoom *pos1Room = &gDungeonGlobalData->roomData[pos1RoomIndex];
        if (pos1Room->startX - 1 > pos2->x || pos1Room->startY - 1 > pos2->y ||
            pos1Room->endX + 1 <= pos2->x || pos1Room->endY + 1 <= pos2->y)
        {
            return FALSE;
        }
        goto returnTrue;
    }
}

bool8 InSameRoom_3(struct Position *pos1, struct Position *pos2)
{
  struct MapTile *iVar2;
  u8 pos1RoomIndex;
  s32 xDiff;
  s32 yDiff;
  s32 x1;
  s32 x2;
  s32 y1;
  s32 y2;

  iVar2 = GetMapTile_1(pos1->x,pos1->y);
  pos1RoomIndex = iVar2->roomIndex;
  if (pos1RoomIndex != CORRIDOR_ROOM_INDEX) {
        struct MapRoom *pos1Room = &gDungeonGlobalData->roomData[pos1RoomIndex];
        if (pos1Room->startX - 1 > pos2->x || pos1Room->startY - 1 > pos2->y ||
            pos1Room->endX + 1 <= pos2->x || pos1Room->endY + 1 <= pos2->y)
        {
            goto _08083394;
        }
  }
  else
  {
_08083394:

    x1 = pos1->x;
    x2 = pos2->x;

    y1 = pos1->y;
    y2 = pos2->y;

    yDiff = y1 - y2;
    xDiff = x1 - x2;

    xDiff = xDiff < 0 ? -xDiff : xDiff;
    yDiff = yDiff < 0 ? -yDiff : yDiff;

    if (yDiff < xDiff) {
      yDiff = xDiff;
    }
    if ((2 < yDiff))
returnFalse:
        return FALSE;
    else if((yDiff == 2) && (!IsTargetTwoTilesAway(pos1,pos2))) {
      goto returnFalse;
    }
  }
  return TRUE;
}
