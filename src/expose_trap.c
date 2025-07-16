#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"

bool8 ExposeTrap(s32 x,s32 y);

void sub_807D3CC(Entity *param_1)
{
    u32 room;
    u8 flag;
    int x;
    int y;
    s32 range;
    RoomData *roomData;

    flag = FALSE;
    range = gDungeon->unk181e8.visibilityRange;
    if (range == 0) {
        range = 2;
    }
    room = GetEntityRoom(param_1);

    if (room == CORRIDOR_ROOM) {
        for (y = (param_1->pos).y - range; y <= ((param_1->pos).y + range); y++)
        {
            for (x = (param_1->pos).x - range; x <= ((param_1->pos).x + range); x++) {
                flag |= ExposeTrap(x,y);
            }
        }
    }
    else {
        roomData = &gDungeon->roomData[room];
        for (y = roomData->bottomRightCornerY + -1; y <= roomData->topLeftCornerY + 1; y++) {
            for (x = roomData->bottomRightCornerX + -1; x <= roomData->topLeftCornerX + 1; x++) {
                flag |= ExposeTrap(x,y);
            }
        }
    }
    if (flag) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80FD2F8); // All traps were exposed
        UpdateMinimap();
        UpdateTrapsVisibility();
    }
    else {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80FD320); // There appears to be no hidden traps.
    }
}

bool8 ExposeTrap(s32 x,s32 y)
{
    const Tile *tile;
    Entity *trap;

    tile = GetTile(x,y);
    trap = tile->object;
    if (((trap != NULL) && (GetEntityType(trap) == ENTITY_TRAP)) && (!trap->isVisible)) {
        trap->isVisible = TRUE;
        return TRUE;
    }
    else {
        return FALSE;
    }
}
