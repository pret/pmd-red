#include "global.h"
#include "dungeon_message.h"
#include "dungeon_random.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_music.h"
#include "dungeon.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "dungeon_util.h"
#include "code_804267C.h"
#include "weather.h"
#include "constants/move_id.h"

struct UnkStruct_8040094
{
    u16 unk0;
    u16 unk2;
    DungeonPos unk4;
    DungeonPos unk8;
    s32 unkC;
    s32 unk10;
};

extern u8 sub_800EC94(s32 param_1);
extern s32 sub_800E710(s32 a0, u16 a1);
extern void sub_800569C(DungeonPos *, axdata *, u8);
extern void sub_800EEC8(u16 r0);
extern void sub_800EF64(void);
extern void sub_8042DD4(s32 a0, Entity *a1, s32 a2);
extern void sub_803E46C(u32);
extern u8 sub_800EA44(s32 species, u16 a2);
extern s32 sub_800E790(s32 species, u16 a2);
extern void sub_806CDD4(Entity *entity, u8, u32 direction);
void sub_8041500(struct UnkStruct_8040094 *a0);
extern s32 sub_800E52C(struct UnkStruct_8040094 *a0);
extern s32 sub_800EA84(struct UnkStruct_8040094 *a0);
extern bool8 sub_800E838(struct UnkStruct_8040094 *a0, s32 a1);
extern bool8 sub_800E9A8(s32 a0);
extern void sub_803EA10(void);
extern void sub_803E708(s32, u32);
extern void sub_800EEF8(u16 a0);

extern u8 gUnknown_203B40D;
extern s16 gUnknown_2026E4E;
extern s32 gDungeonBrightness;
extern s32 gUnknown_202F224;

extern const u8 *const gPtrMagnitudeMessage;
extern const s32 gUnknown_8106A8C[];

u16 sub_80412E0(u16 moveId, u8 weather, bool32 a2);
bool32 sub_804143C(Entity *entity, Move *move);
bool8 sub_80414C0(Entity *entity, Move *move);
bool8 sub_804141C(u16 moveId, u8 weather, bool32 a2);
void sub_8040C4C(Entity *entity, Move *move, bool32 a2);
void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
void sub_80421C0(Entity *pokemon, u16);

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

void sub_8040C4C(Entity *entity, Move *move, bool32 a2)
{
    u8 savedUnkVar;
    s32 r4;
    struct UnkStruct_8040094 sp;
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

void sub_8040DA0(Entity *entity, Move *move)
{
    s32 i;
    s32 soundEffectId;
    Entity *anotherEntity;
    struct UnkStruct_8040094 sp;
    bool32 r9 = sub_804143C(entity, move);
    bool8 var_28 = FALSE;
    EntityInfo *entInfo = GetEntInfo(entity);
    u8 var_24 = sub_800EA44(entInfo->apparentID, sub_80412E0(move->id, GetApparentWeather(entity), r9));

    sub_8041038(&sp, entity, move, r9);
    if (sub_800E838(&sp, 1)) {
        anotherEntity = gDungeon->unk181e8.cameraTarget;
    }
    else if (move->id == MOVE_SILVER_WIND) {
        anotherEntity = gDungeon->unk181e8.cameraTarget;
    }
    else {
        anotherEntity = entity;
    }

    if (!EntityIsValid(anotherEntity)) {
        anotherEntity = entity;
    }

    sp.unk4.x = anotherEntity->pixelPos.x / 256;
    sp.unk4.y = anotherEntity->pixelPos.y / 256;

    if (!sub_8042768(anotherEntity))
        return;
    if (sub_80414C0(entity, move))
        return;

    if (move->id == MOVE_MAGNITUDE) {
        gUnknown_202F224 = DungeonRandInt(7);
        gDungeon->unk181e8.unk18204 = gDungeon->unk181e8.unk18200 = gUnknown_8106A8C[gUnknown_202F224];
        gFormatArgs[0] = gUnknown_202F224 + 4;
        LogMessageByIdWithPopupCheckUser(anotherEntity, gPtrMagnitudeMessage);
        sub_80421C0(anotherEntity, 0x1A4);
    }
    else if (move->id == MOVE_EARTHQUAKE) {
        gDungeon->unk181e8.unk18204 = gDungeon->unk181e8.unk18200 = 12;
        sub_80421C0(anotherEntity, 0x1A4);
    }

    soundEffectId = sub_800E790(entInfo->apparentID, sub_80412E0(move->id, GetApparentWeather(entity), r9));
    if (soundEffectId != 0x3E5) {
        PlaySoundEffect((u16) soundEffectId);
    }

    if (var_24 == 99) {
        if (sub_8042768(anotherEntity)) {
            s32 direction = entInfo->action.direction;
            sub_8041108(&sp, entity, move, r9);
            for (i = 0; i < NUM_DIRECTIONS; i++) {
                direction--;
                direction &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, direction);
                sub_803E708(2, 0x15);
            }
        }
    }
    else if (var_24 == 98) {
        if (sub_8042768(anotherEntity)) {
            s32 direction = entInfo->action.direction;
            sub_8041108(&sp, entity, move, r9);
            for (i = 0; i < NUM_DIRECTIONS + 1; i++) {
                direction &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, direction);
                sub_803E708(2, 0x15);
                direction++;
            }
        }
    }
    else {
        sub_806CDD4(entity, var_24, entInfo->action.direction);
        entity->unk21 = 0;
        for (i = 0; i < 120; i++) {
            u32 unk;

            sub_803E46C(0x59);
            unk = entity->axObj.axdata.sub1.unk10;
            if (var_24 == 9) {
                unk |= 2;
            }

            if ((unk & 2) && !var_28) {
                sub_8041108(&sp, entity, move, r9);
                var_28 = TRUE;
            }
            if (unk & 1)
                break;
            if (entity->unk21 != 0)
                break;
        }
        entity->unk21 = 0;
    }
}

void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2)
{
    EntityInfo *entInfo = GetEntInfo(entity);
    u16 var_24 = sub_80412E0(move->id, GetApparentWeather(entity), a2);

    if (sub_800ECB8(var_24)->unk2 != 0) {
        s32 r2 = sub_800E710(entInfo->apparentID, sub_80412E0(move->id, GetApparentWeather(entity), a2));

        if (r2 != -1) {
            sub_800569C(&a0->unk8, &entity->axObj.axdata, r2);
        }
        else {
            a0->unk8 = (DungeonPos) {0};
        }

        a0->unk0 = var_24;
        a0->unk2 = entInfo->apparentID;
        a0->unk4.x = entity->pixelPos.x / 256;
        a0->unk4.y = entity->pixelPos.y / 256;
        a0->unkC = entInfo->action.direction;
        a0->unk10 = 0;
    }
    else {
        a0->unk0 = 0;
    }
}

void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2)
{
    u16 r4 = sub_80412E0(move->id, GetApparentWeather(entity), a2);
    s32 var = sub_800ECB8(r4)->unk2;

    if (a0->unk0 != 0 && var != 0) {
        sub_8041500(a0);
        sub_800EEF8(r4);
        sub_800EF64();
        sub_803E46C(0x5A);
        sub_8042DD4(sub_800E52C(a0), entity, 1);
    }
}

//
