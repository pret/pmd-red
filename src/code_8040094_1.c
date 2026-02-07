#include "global.h"
#include "globaldata.h"
#include "constants/move_id.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "code_800558C.h"
#include "code_8040094_1.h"
#include "dungeon_8041AD0.h"
#include "dungeon_info.h"
#include "dungeon_logic.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_move.h"
#include "dungeon_move_util.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_tilemap.h"
#include "dungeon_util.h"
#include "dungeon_vram.h"
#include "effect_data.h"
#include "effect_main.h"
#include "effect_sub_1.h"
#include "graphics_memory.h"
#include "move_orb_actions_3.h"
#include "sprite.h"
#include "weather.h"

static bool32 MoveHasSpecialEffect(Entity *entity, Move *move);
static bool8 sub_80414C0(Entity *entity, Move *move);
static bool8 MoveHasSineWobble(u16 moveId, u8 weather, bool32 hasSpecialEffect);
static void sub_8040C4C(Entity *entity, Move *move, bool32 a2);
static void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
static void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 a2);
static void sub_8041500(struct UnkStruct_8040094 *a0);

bool8 sub_8040BB0(Entity *entity, Move *move, bool8 a2)
{
    bool32 hasSpecialEffect = MoveHasSpecialEffect(entity, move);
    bool8 hasSineWobble = MoveHasSineWobble(move->id, GetApparentWeather(entity), hasSpecialEffect);
    s32 r4 = sub_800ECB8(GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect))->unk0;

    if (!sub_8042768(entity))
        return hasSineWobble;
    if (sub_80414C0(entity, move))
        return hasSineWobble;
    if (!a2)
        return hasSineWobble;

    if (r4 != 0) {
        sub_8040C4C(entity, move, hasSpecialEffect);
    }
    return hasSineWobble;
}

static void sub_8040C4C(Entity *entity, Move *move, bool32 hasSpecialEffect)
{
    bool8 savedUnkVar;
    s32 r4;
    struct UnkStruct_8040094 sp;
    u16 r9 = GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect);
    EntityInfo *entInfo = GetEntInfo(entity);
    bool8 r8 = sub_800EC94(move->id);
    s32 apparentId = entInfo->apparentID;
    s32 r2 = sub_800E710(apparentId, GetEffectiveMoveId(move->id, GetApparentWeather(entity), TRUE));

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
    while (TRUE) {
        if (!sub_800E9A8(r4))
            break;
        if (!r8)
            break;

        gUnknown_203B40D = TRUE;
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
    bool32 hasSpecialEffect = MoveHasSpecialEffect(entity, move);
    bool8 var_28 = FALSE;
    EntityInfo *entInfo = GetEntInfo(entity);
    u8 animId = sub_800EA44(entInfo->apparentID, GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect));

    sub_8041038(&sp, entity, move, hasSpecialEffect);
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
        LogMessageByIdWithPopupCheckUser_Async(anotherEntity, gPtrMagnitudeMessage);
        sub_80421C0(anotherEntity, 0x1A4);
    }
    else if (move->id == MOVE_EARTHQUAKE) {
        gDungeon->unk181e8.unk18204 = gDungeon->unk181e8.unk18200 = 12;
        sub_80421C0(anotherEntity, 0x1A4);
    }

    soundEffectId = sub_800E790(entInfo->apparentID, GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect));
    if (soundEffectId != 0x3E5) {
        PlaySoundEffect((u16) soundEffectId);
    }

    if (animId == 99) {
        if (sub_8042768(anotherEntity)) {
            s32 direction = entInfo->action.direction;
            sub_8041108(&sp, entity, move, hasSpecialEffect);
            for (i = 0; i < NUM_DIRECTIONS; i++) {
                direction--;
                direction &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, direction);
                DungeonWaitFrames_Async(2, 0x15);
            }
        }
    }
    else if (animId == 98) {
        if (sub_8042768(anotherEntity)) {
            s32 direction = entInfo->action.direction;
            sub_8041108(&sp, entity, move, hasSpecialEffect);
            for (i = 0; i < NUM_DIRECTIONS + 1; i++) {
                direction &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, direction);
                DungeonWaitFrames_Async(2, 0x15);
                direction++;
            }
        }
    }
    else {
        sub_806CDD4(entity, animId, entInfo->action.direction);
        entity->unk21 = 0;
        for (i = 0; i < 120; i++) {
            u32 unk;

            DungeonRunFrameActions(0x59);
            unk = entity->axObj.axdata.sub1.unk10;
            if (animId == 9) {
                unk |= 2;
            }

            if ((unk & 2) && !var_28) {
                sub_8041108(&sp, entity, move, hasSpecialEffect);
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

static void sub_8041038(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 hasSpecialEffect)
{
    EntityInfo *entInfo = GetEntInfo(entity);
    u16 effectiveMoveId = GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect);

    if (sub_800ECB8(effectiveMoveId)->unk2 != 0) {
        s32 r2 = sub_800E710(entInfo->apparentID, GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect));

        if (r2 != -1) {
            sub_800569C(&a0->unk8, &entity->axObj.axdata, r2);
        }
        else {
            a0->unk8 = (DungeonPos) {0};
        }

        a0->unk0 = effectiveMoveId;
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

static void sub_8041108(struct UnkStruct_8040094 *a0, Entity *entity, Move *move, bool32 hasSpecialEffect)
{
    u16 effectiveMoveId = GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect);
    s32 var = sub_800ECB8(effectiveMoveId)->unk2;

    if (a0->unk0 != 0 && var != 0) {
        sub_8041500(a0);
        sub_800EEF8(effectiveMoveId);
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
    bool32 hasSpecialEffect = (MoveHasSpecialEffect(entity, move) != FALSE);
    u16 effectiveMoveId = GetEffectiveMoveId(move->id, GetApparentWeather(entity), hasSpecialEffect);
    s32 var = sub_800ECB8(effectiveMoveId)->unk4;
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

    sp.unk0 = effectiveMoveId;
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
    sub_800EEE0(effectiveMoveId);
    sub_800EF64();
    var3 = sub_800EBC8(&sp);
    DungeonRunFrameActions(0x5B);
    sub_8042DD4(var3, entity2, 6);
    while (TRUE) {
        if (!sub_800E9A8(var3))
            break;
        DungeonRunFrameActions(0x28);
    }
}

u16 GetEffectiveMoveId(u16 moveId, u8 weather, bool32 hasSpecialEffect)
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
                ret = MOVE_WEATHER_BALL_SUNNY;
                break;
            case WEATHER_SANDSTORM:
                ret = MOVE_WEATHER_BALL_SANDSTORM;
                break;
            case WEATHER_RAIN:
                ret = MOVE_WEATHER_BALL_RAIN;
                break;
            case WEATHER_HAIL:
            case WEATHER_SNOW:
                ret = MOVE_WEATHER_BALL_HAIL;
                break;
        }
    }
    else if (hasSpecialEffect) {
        switch (moveId) {
            case MOVE_DIG:
                ret = MOVE_DIG_2ND_TURN;
                break;
            case MOVE_RAZOR_WIND:
                ret = MOVE_RAZOR_WIND_2ND_TURN;
                break;
            case MOVE_FOCUS_PUNCH:
                ret = MOVE_FOCUS_PUNCH_2ND_TURN;
                break;
            case MOVE_SKY_ATTACK:
                ret = MOVE_SKY_ATTACK_2ND_TURN;
                break;
            case MOVE_SOLARBEAM:
                ret = MOVE_SOLARBEAM_2ND_TURN;
                break;
            case MOVE_FLY:
                ret = MOVE_FLY_2ND_TURN;
                break;
            case MOVE_DIVE:
                ret = MOVE_DIVE_2ND_TURN;
                break;
            case MOVE_BOUNCE:
                ret = MOVE_BOUNCE_2ND_TURN;
                break;
            case MOVE_SKULL_BASH:
                ret = MOVE_SKULL_BASH_2ND_TURN;
                break;
            case MOVE_CURSE:
                ret = MOVE_CURSE_GHOST;
                break;
            case MOVE_SNORE:
                ret = MOVE_SNORE_ATTACK;
                break;
            case MOVE_SLEEP_TALK:
                ret = MOVE_SLEEP_TALK_ATTACK;
                break;
            default:
                ret = moveId;
                break;
        }
    }

    return ret;
}

UNUSED static s32 sub_8041400(u16 moveId, u8 weather, bool32 hasSpecialEffect)
{
    return sub_800ED20(GetEffectiveMoveId(moveId, weather, hasSpecialEffect));
}

static bool8 MoveHasSineWobble(u16 moveId, u8 weather, bool32 hasSpecialEffect)
{
    return EffectiveMoveHasSineWobble(GetEffectiveMoveId(moveId, weather, hasSpecialEffect));
}

static bool32 MoveHasSpecialEffect(Entity *entity, Move *move)
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
        if (!IsMonsterSleeping(entity))
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
