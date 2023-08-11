#include "global.h"
#include "dungeon_map_access.h"
#include "dungeon_global_data.h"
#include "file_system.h"
#include "tile_types.h"
#include "random.h"
#include "dungeon_engine.h"
#include "text1.h"

extern void sub_80402AC(s32, s32);
extern void sub_80098F8(u32);

void sub_804AA60(void) {
    s32 i;
    s32 j;
    for(i = 0; i < 0x20; i++)
    {
        for(j = 0; j < 0x20; j++)
        {
            gUnknown_202B038[2][i][j] = 0;
        }
    }
    sub_80098F8(2);
    gDungeon->unk1821A = 0;
}

void sub_804AAAC(void)
{
    s32 x;
    s32 y;
    struct Tile *tile;
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            tile = GetTileSafe(x,y);
            tile->unk4 = 0;
        }
    }
}

void sub_804AAD4(void)
{
    struct Tile *tile;
    struct RoomData *room1;
    struct RoomData *room2;
    s32 roomIndex;
    int x;
    int y;
    s32 maxRooms;
    s32 index;

    for(index = 0; index < 0x20; index++)
    {
        gDungeon->roomData[index].unk0 = 0;
        gDungeon->roomData[index].unk1 = 0;
        gDungeon->roomData[index].bottomRightCornerX = 9999;
        gDungeon->roomData[index].bottomRightCornerY = 9999;
        gDungeon->roomData[index].topLeftCornerX = 0xd8f1;
        gDungeon->roomData[index].topLeftCornerY = 0xd8f1;
    }

    maxRooms = 0;
    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            tile = GetTile(x,y);
            roomIndex = tile->room;
            if (roomIndex != CORRIDOR_ROOM) {
                room1 = &gDungeon->roomData[roomIndex];
                room1->unk0 = 1;
                if (room1->bottomRightCornerX > x) {
                    room1->bottomRightCornerX = x;
                }
                if (room1->bottomRightCornerY > y) {
                    room1->bottomRightCornerY = y;
                }
                if (room1->topLeftCornerX < x + 1) {
                    room1->topLeftCornerX = x + 1;
                }
                if (room1->topLeftCornerY < y + 1) {
                    room1->topLeftCornerY = y + 1;
                }
                if (maxRooms < roomIndex) {
                    maxRooms = roomIndex;
                }
            }
        }
    }


    for(index = 0; index < 0x20; index++)
    {
        room2 = &gDungeon->roomData[index];
        if(room2 ->unk0 != 0)
        {
            room2->unkC = (room2->bottomRightCornerX - 1) * 24;
            room2->unk10 = (room2->bottomRightCornerY - 1) * 24;
            room2->unk14 = (room2->topLeftCornerX + 1) * 24;
            room2->unk18 = (room2->topLeftCornerY + 1)  * 24;
        }
    }

    gDungeon->unk104C0 = maxRooms + 1;
}

void sub_804AC20(struct Position *pos)
{
    s32 y;
    struct Tile *tile2;
    struct Tile *tile;
    s32 yMax;
    u32 visibilityRange;
    s32 xMin;
    s32 x;
    s32 xMax;
    s32 yMin;
    s32 roomIndex;
    struct RoomData *room;

    tile2 = GetTile(pos->x,pos->y);
    roomIndex = tile2->room;
    visibilityRange = gDungeon->visibilityRange;
    if (!gDungeon->blinded) {
        if (visibilityRange == 0) {
            visibilityRange = 2;
        }
        if (roomIndex == CORRIDOR_ROOM) {
            xMin = pos->x - visibilityRange;
            yMin = pos->y - visibilityRange;
            xMax = pos->x + visibilityRange;
            yMax = pos->y + visibilityRange;
        }
        else {
            room = &gDungeon->roomData[roomIndex];
            if (room->unk1 != 0) {
                return;
            }
            room->unk1 = 1;
            xMin = room->bottomRightCornerX - 1;
            yMin = room->bottomRightCornerY - 1;
            xMax = room->topLeftCornerX;
            yMax = room->topLeftCornerY;
        }
        for (y = yMin; y <= yMax; y++) {
            for (x = xMin; x <= xMax; x++) {
                tile = GetTileSafe(x,y);
                tile->unk4 = tile->unk4 | 3;
                sub_80402AC(x,y);
            }
        }
    }
}
