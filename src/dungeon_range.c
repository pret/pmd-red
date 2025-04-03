#include "global.h"
#include "dungeon_range.h"
#include "sprite.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "structs/map.h"
#include "structs/str_202ED28.h"


bool8 IsPositionActuallyInSight(DungeonPos *pos1, DungeonPos *pos2)
{
    u8 pos1Room;
    u8 visibility = gDungeon->unk181e8.visibilityRange;
    const Tile *tile1;
    if (visibility == 0)
    {
        visibility = 2;
    }
    tile1 = GetTile(pos1->x, pos1->y);
    pos1Room = tile1->room;
    if (pos1Room == CORRIDOR_ROOM)
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
        struct RoomData *pos1RoomData = &gDungeon->roomData[pos1Room];
        if (pos1RoomData->bottomRightCornerX - 1 > pos2->x || pos1RoomData->bottomRightCornerY - 1 > pos2->y ||
            pos1RoomData->topLeftCornerX + 1 <= pos2->x || pos1RoomData->topLeftCornerY + 1 <= pos2->y)
        {
            return FALSE;
        }
        goto returnTrue;
    }
}

bool8 IsPositionInSight(DungeonPos *pos1, DungeonPos *pos2)
{
  const Tile *tile;
  u8 pos1Room;
  s32 xDiff;
  s32 yDiff;
  s32 x1;
  s32 x2;
  s32 y1;
  s32 y2;

  tile = GetTile(pos1->x,pos1->y);
  pos1Room = tile->room;
  if (pos1Room != CORRIDOR_ROOM) {
        struct RoomData *pos1RoomData = &gDungeon->roomData[pos1Room];
        if (pos1RoomData->bottomRightCornerX - 1 > pos2->x || pos1RoomData->bottomRightCornerY - 1 > pos2->y ||
            pos1RoomData->topLeftCornerX + 1 <= pos2->x || pos1RoomData->topLeftCornerY + 1 <= pos2->y)
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

void sub_80833E8(DungeonPos *param_1, s32 *param_2)
{
  const Tile *tile;
  struct RoomData *mapRoom;
  u32 visibility;
  u32 room;

  tile = GetTile(param_1->x, param_1->y);
  visibility = gDungeon->unk181e8.visibilityRange;
  if (visibility == 0) {
    visibility = 2;
  }
  room = tile->room;
  if (room == CORRIDOR_ROOM) {
    param_2[0] = param_1->x - visibility;
    param_2[2] = param_1->x + visibility + 1;
    param_2[1] = param_1->y - visibility;
    param_2[3] = param_1->y + visibility + 1;
  }
  else {
    mapRoom = &gDungeon->roomData[room];
    param_2[0] = mapRoom->bottomRightCornerX - 1;
    param_2[2] = mapRoom->topLeftCornerX + 2;
    param_2[1] = mapRoom->bottomRightCornerY - 1;
    param_2[3] = mapRoom->topLeftCornerY + 2;
  }
}

bool8 IsTargetTwoTilesAway(DungeonPos *pos1, DungeonPos *pos2)
{
    s32 i;
    const Tile *tile;
    s32 diff;
    s32 x1;
    s32 y1;
    s32 xDiff;
    s32 yDiff;
    s32 x2;
    s32 y2;

    diff = abs(pos1->x - pos2->x);
    if (diff < 2)
    {
        diff = abs(pos1->y - pos2->y);
        if (diff < 2)
        {
            return TRUE;
        }
    }
    xDiff = abs(pos1->x - pos2->x);
    yDiff = abs(pos1->y - pos2->y);
    if (yDiff < xDiff)
    {
        yDiff = xDiff;
    }
    if (yDiff == 2)
    {
        x1 = pos1->x;
        y1 = pos1->y;

        for (i = 0; i < 2; i++)
        {
            if (x1 < pos2->x)
            {
                x1++;
            }
            if (x1 > pos2->x)
            {
                x1--;
            }
            if (y1 < pos2->y)
            {
                y1++;
            }
            if (y1 > pos2->y)
            {
                y1--;
            }
            tile = GetTile(x1, y1);
            if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0)
            {
                return FALSE;
            }
        }

        x2 = pos2->x;
        y2 = pos2->y;

        for (i = 0; i < 2; i++)
        {
            if (x2 < pos1->x)
            {
                x2 = x2 + 1;
            }
            if (x2 > pos1->x)
            {
                x2 = x2 - 1;
            }
            if (y2 < pos1->y)
            {
                y2 = y2 + 1;
            }
            if (y2 > pos1->y)
            {
                y2 = y2 - 1;
            }
            tile = GetTile(x2, y2);
            if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0)
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8083568(s32 inX, s32 inY, u8 index)
{
    s32 x = inX - gDungeon->unk181e8.cameraPixelPos.x;
    s32 y = inY - gDungeon->unk181e8.cameraPixelPos.y;

    if (x >= -16 && y >= -16 && x <= 255 && y <= 175)
    {
        SpriteSetX(&gUnknown_202ED28[0][index].sprite, x + gUnknown_202ED28[0][index].pos.x);
        SpriteSetY(&gUnknown_202ED28[0][index].sprite, y + gUnknown_202ED28[0][index].pos.y);

        AddSprite(&gUnknown_202ED28[0][index].sprite, 0, NULL, NULL);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
