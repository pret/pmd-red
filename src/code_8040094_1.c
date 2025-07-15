#include "global.h"
#include "globaldata.h"
#include "constants/move_id.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "effect_data.h"
#include "effect_sub_1.h"
#include "dungeon_vram.h"
#include "code_804267C.h"
#include "dungeon_info.h"
#include "dungeon_message.h"
#include "dungeon_move.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "sprite.h"
#include "weather.h"
#include "dungeon_map_access.h"

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
extern void sub_800EEC8(u16 r0);
extern void sub_8042DD4(s32 a0, Entity *a1, s32 a2);
extern u8 sub_800EA44(s32 species, u16 a2);
extern s32 sub_800E790(s32 species, u16 a2);
extern void sub_806CDD4(Entity *entity, u8, u32 direction);
extern s32 sub_800E52C(struct UnkStruct_8040094 *a0);
extern s32 sub_800EA84(struct UnkStruct_8040094 *a0);
extern bool8 sub_800E838(struct UnkStruct_8040094 *a0, s32 a1);
extern bool8 sub_800E9A8(s32 a0);
extern void sub_803EA10(void);
extern void sub_800EEF8(u16 a0);
extern bool8 sub_803F428(DungeonPos *pos);
extern void sub_800EEE0(u16 a0);
extern s32 sub_800EBC8(struct UnkStruct_8040094 *a0);
extern bool8 sub_800E7D0(struct UnkStruct_8040094 *a0);
extern s32 sub_800ED20(u16 param_1);
extern u8 sub_800EC84(s32 param_1);
extern bool8 MoveMatchesBideClassStatus(Entity *pokemon, Move *move);
extern bool8 IsSleeping(Entity *pokemon);
extern void sub_80421C0(Entity *pokemon, u16);

extern s32 gDungeonBrightness;

extern const u8 *const gPtrMagnitudeMessage;
extern const s32 gUnknown_8106A8C[];

u16 sub_80412E0(u16 moveId, u8 weather, bool32 a2);
static bool32 sub_804143C(Entity *entity, Move *move);
static bool8 sub_80414C0(Entity *entity, Move *move);
static bool8 sub_804141C(u16 moveId, u8 weather, bool32 a2);
static void sub_8040C4C(Entity *entity, Move *move, bool32 a2);
static void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
static void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
static void sub_8041500(struct UnkStruct_8040094 *a0);

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

static void sub_8040C4C(Entity *entity, Move *move, bool32 a2)
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
    DungeonRunFrameActions(0x58);
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
        DungeonRunFrameActions(0x26);
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

            DungeonRunFrameActions(0x59);
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

static void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2)
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

static void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2)
{
    u16 r4 = sub_80412E0(move->id, GetApparentWeather(entity), a2);
    s32 var = sub_800ECB8(r4)->unk2;

    if (a0->unk0 != 0 && var != 0) {
        sub_8041500(a0);
        sub_800EEF8(r4);
        sub_800EF64();
        DungeonRunFrameActions(0x5A);
        sub_8042DD4(sub_800E52C(a0), entity, 1);
    }
}

void sub_8041168(Entity *entity, Entity *entity2, Move *move, DungeonPos *pos)
{
    s32 var2;
    s32 var3;
    struct UnkStruct_8040094 sp;
    bool32 r5 = (sub_804143C(entity, move) != 0);
    u16 r10 = sub_80412E0(move->id, GetApparentWeather(entity), r5);
    s32 var = sub_800ECB8(r10)->unk4;
    EntityInfo *ent2Info = NULL;

    if (EntityIsValid(entity2)) {
        ent2Info = GetEntInfo(entity2);
        if (!sub_8042768(entity2))
            return;
    }
    else {
        if (!sub_803F428(pos))
            return;
    }

    if (sub_80414C0(entity, move))
        return;
    if (var == 0)
        return;

    var2 = sub_800ECA4(var)->unk1c;
    if (var2 != -1) {
        if (EntityIsValid(entity2)) {
            sub_800569C(&sp.unk8, &entity2->axObj.axdata, var2);
        }
        else {
            sp.unk8 = (DungeonPos) {0};
        }
    }
    else {
        sp.unk8 = (DungeonPos) {0};
    }

    sp.unk0 = r10;
    if (ent2Info != NULL) {
        sp.unk2 = ent2Info->apparentID;
        sp.unk4.x = entity2->pixelPos.x / 256;
        sp.unk4.y = entity2->pixelPos.y / 256;
        sp.unkC = 0;
    }
    else {
        s32 x, y;

        sp.unk2 = 1;
        x = X_POS_TO_PIXELPOS(pos->x);
        sp.unk4.x = x / 256;
        y = Y_POS_TO_PIXELPOS(pos->y);
        sp.unk4.y = y / 256;
        sp.unkC = 0;
    }

    sp.unk10 = 0;
    sub_8041500(&sp);
    sub_800EEE0(r10);
    sub_800EF64();
    var3 = sub_800EBC8(&sp);
    DungeonRunFrameActions(0x5B);
    sub_8042DD4(var3, entity2, 6);
    while (1) {
        if (!sub_800E9A8(var3))
            break;
        DungeonRunFrameActions(0x28);
    }
}

u16 sub_80412E0(u16 moveId, u8 weather, bool32 a2)
{
    u16 ret = moveId;

    if (moveId == MOVE_WEATHER_BALL) {
        switch (weather) {
            case WEATHER_CLEAR:
            case WEATHER_FOG:
            case WEATHER_CLOUDY:
                ret = moveId;
                break;
            case WEATHER_SUNNY:
                ret = 0x19E;
                break;
            case WEATHER_SANDSTORM:
                ret = 0x1A1;
                break;
            case WEATHER_RAIN:
                ret = 0x1A0;
                break;
            case WEATHER_HAIL:
            case WEATHER_SNOW:
                ret = 0x19F;
                break;
        }
    }
    else if (a2) {
        switch (moveId) {
            case MOVE_DIG:
                ret = 0x1A2;
                break;
            case MOVE_RAZOR_WIND:
                ret = 0x1A3;
                break;
            case MOVE_FOCUS_PUNCH:
                ret = 0x1A4;
                break;
            case MOVE_SKY_ATTACK:
                ret = 0x1A5;
                break;
            case MOVE_SOLARBEAM:
                ret = 0x1A6;
                break;
            case MOVE_FLY:
                ret = 0x1A7;
                break;
            case MOVE_DIVE:
                ret = 0x1A8;
                break;
            case MOVE_BOUNCE:
                ret = 0x1A9;
                break;
            case MOVE_SKULL_BASH:
                ret = 0x1AA;
                break;
            case MOVE_CURSE:
                ret = 0x1AB;
                break;
            case MOVE_SNORE:
                ret = 0x1AC;
                break;
            case MOVE_SLEEP_TALK:
                ret = 0x1AD;
                break;
            default:
                ret = moveId;
                break;
        }
    }

    return ret;
}

UNUSED static s32 sub_8041400(u16 moveId, u8 weather, bool32 a2)
{
    return sub_800ED20(sub_80412E0(moveId, weather, a2));
}

static bool8 sub_804141C(u16 moveId, u8 weather, bool32 a2)
{
    return sub_800EC84(sub_80412E0(moveId, weather, a2));
}

static bool32 sub_804143C(Entity *entity, Move *move)
{
    if (move->id == MOVE_CURSE) {
        if (EntityIsValid(entity) && GetEntityType(entity) == ENTITY_MONSTER) {
            if (GetEntInfo(entity)->types[0] == TYPE_GHOST || GetEntInfo(entity)->types[1] == TYPE_GHOST)
                return TRUE;
            else
                return FALSE;
        }
    }
    else if (move->id == MOVE_SNORE || move->id == MOVE_SLEEP_TALK) {
        if (!IsSleeping(entity))
            return TRUE;
        else
            return FALSE;
    }
    else if (move->id == MOVE_SOLARBEAM) {
        if (GetApparentWeather(entity) == WEATHER_SUNNY)
            return TRUE;
    }

    return MoveMatchesBideClassStatus(entity, move) != FALSE;
}

static bool8 sub_80414C0(Entity *entity, Move *move)
{
    if (move->id == MOVE_DIVE) {
        if (IsTileGround(GetTileAtEntitySafe(entity)))
            return TRUE;
    }
    if (move->id == MOVE_DIG) {
        if (GetTerrainType(GetTileAtEntitySafe(entity)) != TERRAIN_TYPE_NORMAL)
            return TRUE;
    }

    return FALSE;
}

static void sub_8041500(struct UnkStruct_8040094 *a0)
{
    if (sub_800E7D0(a0)) {
        DungeonRunFrameActions(0x5C);
        sub_8052740(0x5D);
    }
}
