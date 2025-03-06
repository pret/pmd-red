#include "global.h"
#include "code_800558C.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "dungeon_message.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "file_system.h"
#include "play_time.h"
#include "cpu.h"
#include "dungeon.h"
#include "game_options.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "dungeon_generation.h"
#include "dungeon_util.h"
#include "trap.h"
#include "text.h"
#include "code_804267C.h"
#include "weather.h"
#include "constants/dungeon.h"

extern u8 sub_800EC94(s32 param_1);
extern s32 sub_800E710(s32 a0, u16 a1);
extern void sub_800569C(DungeonPos *, axdata *, u8);
extern void sub_800EEC8(u16 r0);
extern void sub_800EF64(void);
extern s32 sub_800EA84(s32 *param_1);
extern void sub_8042DD4(s32 a0, Entity *a1, s32 a2);

u16 sub_80412E0(u16 moveId, u8 weather, bool32 a2);
bool32 sub_804143C(Entity *entity, Move *move);
bool8 sub_80414C0(Entity *entity, Move *move);
bool8 sub_804141C(u16 moveIdy, u8 weather, bool32 a2);
void sub_8040C4C(Entity *entity, Move *move, bool32 a2);

bool8 sub_8040BB0(Entity *entity, Move *move, bool8 a2)
{
    bool32 r8 = sub_804143C(entity, move);
    bool8 r9 = sub_804141C(move->id, GetApparentWeather(entity), r8);
    s32 r4 = sub_800ECB8(sub_80412E0(move->id, GetApparentWeather(entity), r8))->unk0;

    if (!sub_8042768(entity))
        return r9;
    if (sub_80414C0(entity, move))
        return r9;
    if (!a2)
        return r9;

    if (r4 != 0) {
        sub_8040C4C(entity, move, r8);
    }
    return r9;
}

/*
void sub_8040C4C(Entity *entity, Move *move, bool32 a2)
{
    DungeonPos pos;
    s32 r9 = sub_80412E0(move->id, GetApparentWeather(entity), a2);
    EntityInfo *entInfo = GetEntInfo(entity);
    bool8 r8 = sub_800EC94(move->id);
    s32 apparentId = entInfo->apparentID;
    s32 r2 = sub_800E710(apparentId, sub_80412E0(move->id, GetApparentWeather(entity), TRUE));

    if (r2 != -1) {
        sub_800569C(&pos, &entity->axObj.axdata, r2);
    }
    else {
        pos = (DungeonPos) {0};
    }
}
*/
//
