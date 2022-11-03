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

void sub_80833E8(struct Position *param_1, s32 *param_2)
{
  struct MapTile *tile;
  struct MapRoom *room;
  u32 visibility;
  u32 roomIndex;
  
  tile = GetMapTile_1(param_1->x, param_1->y);
  visibility = gDungeonGlobalData->visibility;
  if (visibility == 0) {
    visibility = 2;
  }
  roomIndex = tile->roomIndex;
  if (roomIndex == CORRIDOR_ROOM_INDEX) {
    param_2[0] = param_1->x - visibility;
    param_2[2] = param_1->x + visibility + 1;
    param_2[1] = param_1->y - visibility;
    param_2[3] = param_1->y + visibility + 1;
  }
  else {
    room = &gDungeonGlobalData->roomData[roomIndex];
    param_2[0] = room->startX - 1;
    param_2[2] = room->endX + 2;
    param_2[1] = room->startY - 1;
    param_2[3] = room->endY + 2;
  }
}

bool8 IsTargetTwoTilesAway(struct Position *pos1, struct Position *pos2)
{
    s32 counter;
    struct MapTile *tile;
    s32 diff;
    s32 yCoord;
    s32 xCoord;
    s32 xDiff;
    s32 yDiff;
    s32 yCoord_1;
    s32 xCoord_1;
  
    diff = pos1->x - pos2->x;
    if (diff < 0) {
        diff = -diff;
    }
    if (diff < 2) {
        diff = pos1->y - pos2->y;
        if (diff < 0) {
            diff = -diff;
        }
        if (1 >= diff) return TRUE;
    }
    xDiff = pos1->x - pos2->x;
    if (xDiff < 0) {
      xDiff = -xDiff;
    }
    yDiff = pos1->y - pos2->y;
    if (yDiff < 0) {
      yDiff = -yDiff;
    }
    if (yDiff < xDiff) {
      yDiff = xDiff;
    }
    if (yDiff == 2) {

        xCoord = pos1->x;
        yCoord = pos1->y;

        for(counter = 0; counter < 2; counter++){
            if (xCoord < pos2->x) {
                xCoord = xCoord + 1;
            }
            if (xCoord > pos2->x) {
                xCoord = xCoord - 1;
            }
            if (yCoord < pos2->y) {
                yCoord = yCoord + 1;
            }
            if (yCoord > pos2->y) {
                yCoord = yCoord -1;
            }
            tile = GetMapTile_1(xCoord,yCoord);
            if ((tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) == 0) return FALSE;
        }

        xCoord_1 = pos2->x;
        yCoord_1 = pos2->y;

        for(counter = 0; counter < 2; counter++)
        {
            if (xCoord_1 < pos1->x) {
                xCoord_1 = xCoord_1 + 1;
            }
            if (xCoord_1 > pos1->x) {
                xCoord_1 = xCoord_1 - 1;
            }
            if (yCoord_1 < pos1->y) {
                yCoord_1 = yCoord_1 + 1;
            }
            if (yCoord_1 > pos1->y) {
                yCoord_1 = yCoord_1 - 1;
            }
            tile = GetMapTile_1(xCoord_1, yCoord_1);
            if ((tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) == 0) return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}
