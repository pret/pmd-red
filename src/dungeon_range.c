#include "global.h"
#include "dungeon_range.h"

#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "map.h"

extern void sub_8082FE0(u32, u32, u32);

void sub_8083288(u32 r0, u32 r1, u32 r2)
{
    sub_8082FE0(r0, r1, r2);
}

bool8 InSameRoom_2(struct Position *pos1, struct Position *pos2)
{
    u8 pos1RoomIndex;
    u8 visibility = gDungeonGlobalData->visibility;
    struct MapTile *tile1;
    if (visibility == 0)
    {
        visibility = 2;
    }
    tile1 = GetMapTileAtPosition(pos1->x, pos1->y);
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
