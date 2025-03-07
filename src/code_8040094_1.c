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
extern void sub_8042DD4(s32 a0, Entity *a1, s32 a2);
extern void sub_803E46C(u32);

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

struct UnkStruct_202EDE8
{
    u16 unk0;
    u16 unk2;
    DungeonPos unk4;
    DungeonPos unk8;
    s32 unkC;
    s32 unk10;
};

void sub_8041500(struct UnkStruct_202EDE8 *a0);
extern s32 sub_800EA84(struct UnkStruct_202EDE8 *a0);
extern bool8 sub_800E9A8(s32 a0);
extern void sub_803EA10(void);

extern u8 gUnknown_203B40D;
extern s16 gUnknown_2026E4E;
extern s32 gDungeonBrightness;

void sub_8040C4C(Entity *entity, Move *move, bool32 a2)
{
    u8 savedUnkVar;
    s32 r4;
    struct UnkStruct_202EDE8 sp;
    u16 r9 = sub_80412E0(move->id, GetApparentWeather(entity), a2);
    EntityInfo *entInfo = GetEntInfo(entity);
    bool8 r8 = sub_800EC94(move->id);
    s32 apparentId = entInfo->apparentID;
    s32 r2 = sub_800E710(apparentId, sub_80412E0(move->id, GetApparentWeather(entity), TRUE));

    if (r2 != -1) {
        sub_800569C(&sp.unk8, &entity->axObj.axdata, r2);
    }
    else {
        sp.unk8 = (DungeonPos) {0};
    }

    sp.unk0 = r9;
    sp.unk2 = entInfo->apparentID;
    sp.unk4.x = entity->pixelPos.x / 256;
    sp.unk4.y = entity->pixelPos.y / 256;
    sp.unkC = entInfo->action.direction;
    sp.unk10 = 0;
    sub_8041500(&sp);
    sub_800EEC8(r9);
    sub_800EF64();
    sub_803E46C(0x58);
    r4 = sub_800EA84(&sp);
    sub_8042DD4(r4, entity, 5);
    savedUnkVar = gUnknown_203B40D;
    while (1) {
        if (!sub_800E9A8(r4))
            break;
        if (!r8)
            break;

        gUnknown_203B40D = 1;
        if (gUnknown_2026E4E != 0x1010) {
            gUnknown_2026E4E += 0x101;
        }

        if (gDungeonBrightness >= 5) {
            gDungeonBrightness -= 4;
        }
        else {
            gDungeonBrightness = 0;
            r8 = FALSE;
        }
        sub_803EA10();
        sub_803E46C(0x26);
    }
    gUnknown_203B40D = savedUnkVar;
}

//
