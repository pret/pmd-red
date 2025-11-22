#include "global.h"
#include "globaldata.h"
#include "ground_map.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_bg.h"
#include "ground_main.h"
#include "ground_script.h"
#include "ground_script_file.h"
#include "ground_weather.h"
#include "memory.h"
#include "ground_map_conversion_table.h"
#include "code_800558C.h"
#include "constants/dungeon.h"
#include "constants/ground_map.h"
#include "code_809D148.h"

IWRAM_INIT GroundMapAction *gGroundMapAction = {NULL};
IWRAM_INIT GroundBg *gGroundMapDungeon_3001B70 = {NULL};

static void sub_80A5204(void *, const void *, BmaHeader *, s32);
static void sub_80A56D8(const PixelPos *pos);

static const SubStruct_52C gUnknown_8117324 = {
    .unk0 = 0,
    .unk2 = 13,
    .unk4 = 0,
    .unk6 = 0x380,
    .unk8 = 0x4B0,
    .unkA = 1,
    .numLayers = 1,
    .unkE = 0xbc,
    .unk10 = 0x5e,
    .unk12 = 0,
    .unk14 = sub_80A5204,
};

static const SubStruct_52C gUnknown_811733C = {
    .unk0 = 0,
    .unk2 = 14,
    .unk4 = 0,
    .unk6 = 0x400,
    .unk8 = 0x4B0,
    .unkA = 0,
    .numLayers = 2,
    .unkE = 0xbc,
    .unk10 = 0x5e,
    .unk12 = 0,
    .unk14 = sub_80A5204,
};

static const SubStruct_52C gUnknown_8117354 = {
    .unk0 = 0,
    .unk2 = 12,
    .unk4 = 0,
    .unk6 = 0x200,
    .unk8 = 0x4B0,
    .unkA = 1,
    .numLayers = 1,
    .unkE = 0xbc,
    .unk10 = 0x5e,
    .unk12 = 0,
    .unk14 = sub_80A5204,
};

static const CallbackData sGroundScriptNullCallbacks = {0};

struct MapToDungeonStruct
{
    s16 id;
    DungeonLocation loc;
    u32 unk8;
};

static const struct MapToDungeonStruct sMapToDungeonTable[] = {
    {
        .id = MAP_TINY_WOODS_END,
        .loc = { .id = DUNGEON_TINY_WOODS, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_THUNDERWAVE_CAVE_END,
        .loc = { .id = DUNGEON_THUNDERWAVE_CAVE, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_STEEL_END,
        .loc = { .id = DUNGEON_MT_STEEL, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_SINISTER_WOODS_END,
        .loc = { .id = DUNGEON_SINISTER_WOODS, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_SILENT_CHASM_END,
        .loc = { .id = DUNGEON_SILENT_CHASM, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_THUNDER_MID,
        .loc = { .id = DUNGEON_MT_THUNDER, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_THUNDER_END,
        .loc = { .id = DUNGEON_MT_THUNDER_PEAK, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_BLAZE_MID,
        .loc = { .id = DUNGEON_MT_BLAZE, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_BLAZE_END,
        .loc = { .id = DUNGEON_MT_BLAZE_PEAK, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_FROSTY_FOREST_MID,
        .loc = { .id = DUNGEON_FROSTY_FOREST, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_FROSTY_FOREST_END,
        .loc = { .id = DUNGEON_FROSTY_GROTTO, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_FREEZE_MID,
        .loc = { .id = DUNGEON_MT_FREEZE, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MT_FREEZE_END,
        .loc = { .id = DUNGEON_MT_FREEZE_PEAK, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MAGMA_CAVERN_MID,
        .loc = { .id = DUNGEON_MAGMA_CAVERN, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_MAGMA_CAVERN_END,
        .loc = { .id = DUNGEON_MAGMA_CAVERN_PIT, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_SKY_TOWER_MID,
        .loc = { .id = DUNGEON_SKY_TOWER, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_SKY_TOWER_END,
        .loc = { .id = DUNGEON_SKY_TOWER_SUMMIT, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D14,
        .loc = { .id = DUNGEON_STORMY_SEA, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D15,
        .loc = { .id = DUNGEON_SILVER_TRENCH, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D16,
        .loc = { .id = DUNGEON_FIERY_FIELD, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D17,
        .loc = { .id = DUNGEON_LIGHTNING_FIELD, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D18,
        .loc = { .id = DUNGEON_NORTHWIND_FIELD, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D19,
        .loc = { .id = DUNGEON_MT_FARAWAY, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D20,
        .loc = { .id = DUNGEON_WESTERN_CAVE, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D21,
        .loc = { .id = DUNGEON_NORTHERN_RANGE, .floor = 100 },
        .unk8 = 0,
    },
    {
        .id = MAP_D23,
        .loc = { .id = DUNGEON_WISH_CAVE, .floor = 20 },
        .unk8 = 0,
    },
    {
        .id = MAP_D25,
        .loc = { .id = DUNGEON_HOWLING_FOREST, .floor = 100 },
        .unk8 = 0,
    },
    // -1 = table's end
    {
        .id = -1,
        .loc = { .id = DUNGEON_TINY_WOODS, .floor = 100 },
        .unk8 = 0,
    },
};

void AllocGroundMapAction(void)
{
    gGroundMapAction = MemoryAlloc(sizeof(GroundMapAction), 6);
    gGroundMapAction->groundMapId = -1;
    InitActionWithParams(&gGroundMapAction->action, &sGroundScriptNullCallbacks, 0, -1, -1);
    sub_80A5E8C(0);
    GroundMap_Reset();
}

void FreeGroundMapAction(void)
{
    GroundMap_Reset();
    sub_80A5EBC();
    InitAction2(&gGroundMapAction->action);
    FREE_AND_SET_NULL(gGroundMapAction);
}

void GroundMap_Reset(void)
{
    ClearScriptVarArray(NULL, MAP_LOCAL);
    ClearScriptVarArray(NULL, MAP_LOCAL_DOOR);
    ActionResetScriptData(&gGroundMapAction->action, DEBUG_LOC_PTR("../ground/ground_map.c", 0xF8, "GroundMap_Reset"));

    if (gGroundMapDungeon_3001B70 != NULL) {
        GroundBg_FreeAll(gGroundMapDungeon_3001B70);
        FREE_AND_SET_NULL(gGroundMapDungeon_3001B70);
    }

    sub_80A5EDC(0);
}

void sub_80A4B38(void)
{
    nullsub_121();

    if (gGroundMapDungeon_3001B70 != NULL)
        sub_80A2D68(gGroundMapDungeon_3001B70);
}

void sub_80A4B54(void)
{
    if (gGroundMapDungeon_3001B70 != NULL)
        sub_80A2D88(gGroundMapDungeon_3001B70);

    nullsub_122();
}

void GroundMap_GetStationScript(ScriptInfoSmall *r0, s32 _groundScriptId, s32 _groupId, s32 _sectorId)
{
    const struct GroundScriptHeader *scriptHeader;
    s32 groundScriptId = (s16) _groundScriptId;
    s32 groupId = (s16) _groupId;
    s32 sectorId = (s8) _sectorId;

    ChangeScriptFile(groundScriptId);
    scriptHeader = GetGroundScript(groundScriptId, DEBUG_LOC_PTR("../ground/ground_map.c", 0x138, "GroundMap_GetStationScript"));
    Log(0, "GroundMap ExecuteStation %3d %3d %3d", groundScriptId, groupId, sectorId);
    {
        const struct GroundScriptGroup *groups = &scriptHeader->groups[groupId];
        const struct GroundScriptSector *sectors = &groups->sectors[sectorId];
        r0->ptr = sectors->station[0]->script;
    }

    r0->state = 2;
    r0->group = groupId;
    r0->sector = sectorId;
}

static void GroundMap_GetFirstStationScript(ScriptInfoSmall *script, s16 r1)
{
    GroundMap_GetStationScript(script, r1, 0, 0);
}

// overlay_0000.bin::02155DD0
void GroundMap_ExecuteEvent(s16 scriptIndex, u32 param_2)
{
    ScriptInfoSmall script;
    s32 index_s32;
    u8 iVar2;

    index_s32 = scriptIndex;
    iVar2 = param_2;

    Log(0, "GroundMap ExecuteEvent %3d %d ==================", index_s32, iVar2);
    GetFunctionScript(NULL, &script, index_s32);
    if (iVar2 != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, DEBUG_LOC_PTR("../ground/ground_map.c", 0x17D, "GroundMap_ExecuteEvent"));
}

void GroundMap_ExecuteStation(s32 _map, s32 _group, s32 _sector, bool32 _setScriptState)
{
    ScriptInfoSmall script;
    s32 map;
    s32 group;
    s32 sector;
    bool8 setScriptState;

    map = (s16)_map;
    group = (s16)_group;
    sector = (s8)_sector;
    setScriptState = (bool8)_setScriptState;

    Log(0, "GroundMap ExecuteStation %3d %3d %3d %d ==================", map, group, sector, setScriptState);
    GroundMap_GetStationScript(&script, map, group, sector);
    if (setScriptState != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, DEBUG_LOC_PTR("../ground/ground_map.c", 0x199, "GroundMap_ExecuteStation"));
}

void GroundMap_ExecuteEnter(s16 param_1)
{
    ScriptInfoSmall script;
    s32 iVar1;

    iVar1 = param_1;

    Log(0, "GroundMap ExecuteEnter %3d ==================", iVar1);
    GroundMap_GetFirstStationScript(&script, iVar1);
    script.state = 2;
    script.group = 0;
    script.sector = 0;
    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, DEBUG_LOC_PTR("../ground/ground_map.c", 0x1B3, "GroundMap_ExecuteEnter"));
}

UNUSED static bool8 sub_80A4D14(void)
{
    return sub_809D678(&gGroundMapAction->action);
}

bool8 GroundMapNotifyAll(s16 param_1)
{
    s32 iVar1 = param_1;
    return GroundScriptNotify(&gGroundMapAction->action, iVar1);
}

bool8 sub_80A4D48(s16 index)
{
    if (index == -1) return TRUE;
    if (gGroundMapConversionTable[index].unk0 == 5) return FALSE;
    if (gGroundMapConversionTable[index].unk0 != 8) return TRUE;
    return FALSE;
}

s16 GetAdjustedGroundMap(s32 mapId)
{
    s32 retMapId = (s16) mapId;

    switch (retMapId) {
        case MAP_TEAM_BASE:
        case MAP_TEAM_BASE_INSIDE:
            retMapId = (s16)(retMapId + ((GetScriptVarValue(NULL, BASE_KIND) * TEAM_BASE_MAPS_PER_SPECIES) + GetScriptVarValue(NULL, BASE_LEVEL)));
            break;
        case MAP_WHISCASH_POND:
            if (CheckQuest(QUEST_REACHED_POSTGAME)) {
                retMapId = MAP_WHISCASH_POND_OPEN;
            }
            break;
    }

    return retMapId;
}

void GroundMap_Select(s32 mapId_)
{
    const GroundConversionStruct *ptr;
    s32 mapId = (s16) mapId_;

    Log(0, "GroundMap Select %3d", mapId);
    ClearScriptVarArray(NULL, MAP_LOCAL);
    ClearScriptVarArray(NULL, MAP_LOCAL_DOOR);
    sub_80A5EDC(0);
    if (gGroundMapDungeon_3001B70 != NULL) {
        GroundBg_FreeAll(gGroundMapDungeon_3001B70);
        FREE_AND_SET_NULL(gGroundMapDungeon_3001B70);
    }
    gGroundMapDungeon_3001B70 = MemoryAlloc(sizeof(*gGroundMapDungeon_3001B70),6);
    gGroundMapAction->groundMapId = mapId;
    if (mapId == -1) {
        GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117324);
        sub_80A2FBC(gGroundMapDungeon_3001B70, mapId);
        return;
    }

    ptr = &gGroundMapConversionTable[mapId];
    switch (ptr->unk0) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_811733C);
            gUnknown_2026E4E = 0x1000;
        break;
        case 0xA:
        case 0xB: {
            const struct MapToDungeonStruct *mapToDungPtr = sMapToDungeonTable;
            while (mapToDungPtr->id != -1 && mapToDungPtr->id != mapId) {
                mapToDungPtr++;
            }
            FREE_AND_SET_NULL(gGroundMapDungeon_3001B70);
            GroundMap_SelectDungeon(mapId, &mapToDungPtr->loc, mapToDungPtr->unk8);
            return;
        }
        case -1:
            FatalError(DEBUG_LOC_PTR("../ground/ground_map.c", 0x249, "GroundMap_Select"),"select map type error %d %d",mapId,ptr->unk0);
            break;
        default:
            GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117324);
            sub_80A5EDC(1);
            break;
    }

    sub_80A2FBC(gGroundMapDungeon_3001B70, ptr->mapFileTableId);
    gGroundMapAction->unkE8.x = 0;
    gGroundMapAction->unkE8.y = 0;
    gGroundMapAction->unkF0 = 0;
    gGroundMapAction->unkF4 = 0;
    gGroundMapAction->unkF8.x = 0;
    gGroundMapAction->unkF8.y = 0;
    gGroundMapAction->unk100 = gGroundMapAction->unk104 = gGroundMapAction->unk108 = gGroundMapAction->unk10C = 0;

    switch (gGroundMapAction->groundMapId) {
        case MAP_PERSONALITY_TEST_CYAN:
        case MAP_PERSONALITY_TEST_PURPLE:
        case MAP_PERSONALITY_TEST_MULTICOLOR:
            sub_80A3BB0(gGroundMapDungeon_3001B70,4);
            gUnknown_2026E4E = 0x808;
            break;
        case MAP_FUGITIVES_BLIZZARD_ROAD:
        case MAP_FUGITIVES_SNOW_ROAD:
            sub_80A3BB0(gGroundMapDungeon_3001B70,1);
            break;
        case MAP_SUMMIT_SUNSET:
            sub_80A3BB0(gGroundMapDungeon_3001B70,1);
        case MAP_HILL_OF_THE_ANCIENTS:
            sub_80A3B80(gGroundMapDungeon_3001B70,0,0);
            break;
        case MAP_COMET:
            gUnknown_2026E4E = 0x1010;
            break;
        case MAP_NIGHTMARE:
            sub_80A3BB0(gGroundMapDungeon_3001B70,4);
            gUnknown_2026E4E = 0x80C;
            break;
        case MAP_NIGHT_SKY_2:
            sub_80A3BB0(gGroundMapDungeon_3001B70,1);
            break;
        case MAP_SILENT_CHASM_ENTRY:
            gUnknown_2026E4E = 0x1010;
            sub_80A3BB0(gGroundMapDungeon_3001B70,4);
            break;
        case MAP_NIGHT_SKY_1:
            sub_80A3BB0(gGroundMapDungeon_3001B70,4);
            break;
        case MAP_PELIPPER_POST_OFFICE:
            sub_80A3BB0(gGroundMapDungeon_3001B70,3);
            break;
        case MAP_FRIEND_AREA_FINAL_ISLAND:
            sub_80A3BB0(gGroundMapDungeon_3001B70,3);
            break;
        case MAP_TITLE_SCREEN:
            sub_80A3BB0(gGroundMapDungeon_3001B70,3);
        case MAP_INTRO:
            sub_80A3B80(gGroundMapDungeon_3001B70,0,0);
            break;
    }

    if (ptr->unk6 != -1) {
        GroundWeather_Select(ptr->unk6);
    }

    sub_80A56D8(&(const PixelPos) {0});
}

void GroundMap_SelectDungeon(s32 mapId_, const DungeonLocation *loc, u32 param_2)
{
    const GroundConversionStruct *ptr;
    s32 mapId = (s16) mapId_;

    Log('\0', "GroundMap SelectDungeon %3d", mapId);
    ClearScriptVarArray(NULL, MAP_LOCAL);
    ClearScriptVarArray(NULL, MAP_LOCAL_DOOR);
    sub_80A5EDC('\0');
    if (gGroundMapDungeon_3001B70 != NULL) {
        GroundBg_FreeAll(gGroundMapDungeon_3001B70);
        FREE_AND_SET_NULL(gGroundMapDungeon_3001B70);
    }

    gGroundMapDungeon_3001B70 = MemoryAlloc(sizeof(*gGroundMapDungeon_3001B70),6);
    gGroundMapAction->groundMapId = mapId;
    if (mapId == -1 || loc->id == DUNGEON_INVALID) {
        GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117324);
        sub_80A2FBC(gGroundMapDungeon_3001B70,-1);
        return;
    }

    ptr = &gGroundMapConversionTable[mapId];
    if (ptr->unk0 != 0xA && ptr->unk0 != 0xB) {
        FatalError(DEBUG_LOC_PTR("../ground/ground_map.c", 0x2C6, "GroundMap_SelectDungeon"), "map type error %d", mapId);
    }

    GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117354);
    sub_80A5EDC(1);
    sub_80A3440(gGroundMapDungeon_3001B70, ptr->mapFileTableId, loc, param_2);
    gGroundMapAction->unkE8.x = 0;
    gGroundMapAction->unkE8.y = 0;
    gGroundMapAction->unkF0 = 0;
    gGroundMapAction->unkF4 = 0;
    gGroundMapAction->unkF8.x = 0;
    gGroundMapAction->unkF8.y = 0;
    gGroundMapAction->unk100 = gGroundMapAction->unk104 = gGroundMapAction->unk108 = gGroundMapAction->unk10C = 0;

    sub_80A56D8(&(const PixelPos) {0, 0});
}

NAKED
static void sub_80A5204(void *a, const void *b, BmaHeader *c, s32 d)
{
    asm_unified(
"	push {r4-r7,lr}     \n"
"	mov r7, r10         \n"
"	mov r6, r9          \n"
"	mov r5, r8          \n"
"	push {r5-r7}        \n"
"	sub sp, 0x18        \n"
"	str r0, [sp]        \n"
"	mov r8, r1          \n"
"	str r2, [sp, 0x4]   \n"
"	str r3, [sp, 0x8]   \n"
"	movs r1, 0x8        \n"
"	ldrsh r0, [r2, r1]  \n"
"	cmp r0, 0           \n"
"	bgt _080A5222       \n"
"	b _080A53EA         \n"
"_080A5222:             \n"
"	mov r5, r8          \n"
"	ldr r2, [sp]        \n"
"	mov r12, r2         \n"
"	movs r0, 0          \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r3, [r3, 0x1]  \n"
"	str r3, [sp, 0x10]  \n"
"	ldr r1, [sp, 0x4]   \n"
"	ldrh r2, [r1, 0xA]  \n"
"	mov r1, sp          \n"
"	strh r2, [r1, 0xC]  \n"
"	movs r1, 0xFF       \n"
"_080A523A:             \n"
"	adds r0, 0x1        \n"
"	mov r10, r0         \n"
"	movs r3, 0xFF       \n"
"	mov r9, r3          \n"
"_080A5242:             \n"
"	mov r0, r12         \n"
"	strb r1, [r0]       \n"
"	movs r2, 0x1        \n"
"	add r12, r2         \n"
"	movs r3, 0x1        \n"
"	negs r3, r3         \n"
"	add r9, r3          \n"
"	mov r0, r9          \n"
"	cmp r0, 0           \n"
"	bge _080A5242       \n"
"	mov r0, r10         \n"
"	cmp r0, 0x3         \n"
"	ble _080A523A       \n"
"	movs r1, 0          \n"
"	ldr r2, [sp, 0x10]  \n"
"	cmp r1, r2          \n"
"	blt _080A5266       \n"
"	b _080A53BA         \n"
"_080A5266:             \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"_080A526A:             \n"
"	adds r0, 0x1        \n"
"	mov r10, r0         \n"
"	adds r0, r1, 0x1    \n"
"	str r0, [sp, 0x14]  \n"
"	movs r0, 0xFF       \n"
"	movs r2, 0x4        \n"
"	mov r9, r2          \n"
"_080A5278:             \n"
"	mov r3, r12         \n"
"	strb r0, [r3]       \n"
"	movs r2, 0x1        \n"
"	add r12, r2         \n"
"	movs r3, 0x1        \n"
"	negs r3, r3         \n"
"	add r9, r3          \n"
"	mov r2, r9          \n"
"	cmp r2, 0           \n"
"	bge _080A5278       \n"
"	movs r3, 0x5        \n"
"	mov r9, r3          \n"
"	movs r0, 0          \n"
"	cmp r1, 0           \n"
"	bne _080A5308       \n"
"	cmp r1, r7          \n"
"	bge _080A5394       \n"
"_080A529A:             \n"
"	ldrb r1, [r5]       \n"
"	adds r5, 0x1        \n"
"	cmp r1, 0xBF        \n"
"	ble _080A52C2       \n"
"	adds r6, r0, 0      \n"
"	subs r6, 0xBF       \n"
"	cmp r1, 0xBF        \n"
"	ble _080A5300       \n"
"	adds r2, r1, 0      \n"
"	subs r2, 0xBF       \n"
"_080A52AE:             \n"
"	ldrb r0, [r5]       \n"
"	mov r3, r12         \n"
"	strb r0, [r3]       \n"
"	adds r5, 0x1        \n"
"	movs r0, 0x1        \n"
"	add r12, r0         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A52AE       \n"
"	b _080A5300         \n"
"_080A52C2:             \n"
"	cmp r1, 0x7F        \n"
"	ble _080A52E6       \n"
"	ldrb r4, [r5]       \n"
"	adds r5, 0x1        \n"
"	adds r6, r0, 0      \n"
"	subs r6, 0x7F       \n"
"	cmp r1, 0x7F        \n"
"	ble _080A5300       \n"
"	adds r2, r1, 0      \n"
"	subs r2, 0x7F       \n"
"_080A52D6:             \n"
"	mov r3, r12         \n"
"	strb r4, [r3]       \n"
"	movs r0, 0x1        \n"
"	add r12, r0         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A52D6       \n"
"	b _080A5300         \n"
"_080A52E6:             \n"
"	movs r2, 0          \n"
"	adds r6, r0, 0x1    \n"
"	cmp r2, r1          \n"
"	bgt _080A5300       \n"
"	movs r0, 0          \n"
"	adds r2, r1, 0x1    \n"
"_080A52F2:             \n"
"	mov r3, r12         \n"
"	strb r0, [r3]       \n"
"	movs r3, 0x1        \n"
"	add r12, r3         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A52F2       \n"
"_080A5300:             \n"
"	adds r0, r6, r1     \n"
"	cmp r0, r7          \n"
"	blt _080A529A       \n"
"	b _080A5394         \n"
"_080A5308:             \n"
"	ldr r4, _080A5340   \n"
"	add r4, r12         \n"
"	cmp r0, r7          \n"
"	bge _080A5394       \n"
"_080A5310:             \n"
"	ldrb r3, [r5]       \n"
"	adds r5, 0x1        \n"
"	cmp r3, 0xBF        \n"
"	ble _080A5344       \n"
"	adds r6, r0, 0      \n"
"	subs r6, 0xBF       \n"
"	cmp r3, 0xBF        \n"
"	ble _080A538E       \n"
"	adds r2, r3, 0      \n"
"	subs r2, 0xBF       \n"
"_080A5324:             \n"
"	ldrb r1, [r5]       \n"
"	ldrb r0, [r4]       \n"
"	eors r1, r0         \n"
"	mov r0, r12         \n"
"	strb r1, [r0]       \n"
"	adds r4, 0x1        \n"
"	adds r5, 0x1        \n"
"	movs r1, 0x1        \n"
"	add r12, r1         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A5324       \n"
"	b _080A538E         \n"
"	.align 2, 0         \n"
"_080A5340: .4byte 0xffffff00\n"
"_080A5344:             \n"
"	cmp r3, 0x7F        \n"
"	ble _080A5372       \n"
"	ldrb r2, [r5]       \n"
"	mov r8, r2          \n"
"	adds r5, 0x1        \n"
"	adds r6, r0, 0      \n"
"	subs r6, 0x7F       \n"
"	cmp r3, 0x7F        \n"
"	ble _080A538E       \n"
"	adds r2, r3, 0      \n"
"	subs r2, 0x7F       \n"
"_080A535A:             \n"
"	ldrb r1, [r4]       \n"
"	mov r0, r8          \n"
"	eors r0, r1         \n"
"	mov r1, r12         \n"
"	strb r0, [r1]       \n"
"	adds r4, 0x1        \n"
"	movs r0, 0x1        \n"
"	add r12, r0         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A535A       \n"
"	b _080A538E         \n"
"_080A5372:             \n"
"	movs r2, 0          \n"
"	adds r6, r0, 0x1    \n"
"	cmp r2, r3          \n"
"	bgt _080A538E       \n"
"	adds r2, r3, 0x1    \n"
"_080A537C:             \n"
"	ldrb r0, [r4]       \n"
"	mov r1, r12         \n"
"	strb r0, [r1]       \n"
"	adds r4, 0x1        \n"
"	movs r0, 0x1        \n"
"	add r12, r0         \n"
"	subs r2, 0x1        \n"
"	cmp r2, 0           \n"
"	bne _080A537C       \n"
"_080A538E:             \n"
"	adds r0, r6, r3     \n"
"	cmp r0, r7          \n"
"	blt _080A5310       \n"
"_080A5394:             \n"
"	add r9, r7          \n"
"	mov r1, r9          \n"
"	cmp r1, 0xFF        \n"
"	bgt _080A53AE       \n"
"	movs r0, 0xFF       \n"
"_080A539E:             \n"
"	mov r2, r12         \n"
"	strb r0, [r2]       \n"
"	movs r3, 0x1        \n"
"	add r12, r3         \n"
"	add r9, r3          \n"
"	mov r1, r9          \n"
"	cmp r1, 0xFF        \n"
"	ble _080A539E       \n"
"_080A53AE:             \n"
"	ldr r1, [sp, 0x14]  \n"
"	mov r0, r10         \n"
"	ldr r2, [sp, 0x10]  \n"
"	cmp r1, r2          \n"
"	bge _080A53BA       \n"
"	b _080A526A         \n"
"_080A53BA:             \n"
"	ldr r3, [sp, 0x8]   \n"
"	cmp r0, r3          \n"
"	bge _080A53E6       \n"
"	movs r1, 0xFF       \n"
"_080A53C2:             \n"
"	adds r0, 0x1        \n"
"	mov r10, r0         \n"
"	movs r0, 0xFF       \n"
"	mov r9, r0          \n"
"_080A53CA:             \n"
"	mov r2, r12         \n"
"	strb r1, [r2]       \n"
"	movs r3, 0x1        \n"
"	add r12, r3         \n"
"	movs r0, 0x1        \n"
"	negs r0, r0         \n"
"	add r9, r0          \n"
"	mov r2, r9          \n"
"	cmp r2, 0           \n"
"	bge _080A53CA       \n"
"	mov r0, r10         \n"
"	ldr r3, [sp, 0x8]   \n"
"	cmp r0, r3          \n"
"	blt _080A53C2       \n"
"_080A53E6:             \n"
"	mov r8, r5          \n"
"	b _080A547E         \n"
"_080A53EA:             \n"
"	ldr r1, [sp]        \n"
"	movs r0, 0          \n"
"	ldr r2, [sp, 0x4]   \n"
"	ldrb r2, [r2, 0x1]  \n"
"	str r2, [sp, 0x10]  \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrh r2, [r3, 0xA]  \n"
"	mov r3, sp          \n"
"	strh r2, [r3, 0xC]  \n"
"	movs r6, 0xFF       \n"
"_080A53FE:             \n"
"	adds r5, r0, 0x1    \n"
"	movs r4, 0xFF       \n"
"_080A5402:             \n"
"	strb r6, [r1]       \n"
"	adds r1, 0x1        \n"
"	subs r4, 0x1        \n"
"	cmp r4, 0           \n"
"	bge _080A5402       \n"
"	adds r0, r5, 0      \n"
"	cmp r0, 0x3         \n"
"	ble _080A53FE       \n"
"	movs r4, 0          \n"
"	ldr r3, [sp, 0x10]  \n"
"	cmp r4, r3          \n"
"	bge _080A5460       \n"
"	ldr r2, [sp, 0x4]   \n"
"	ldrb r7, [r2]       \n"
"	movs r3, 0xFF       \n"
"_080A5420:             \n"
"	adds r5, r0, 0x1    \n"
"	adds r2, r4, 0x1    \n"
"	movs r4, 0x4        \n"
"_080A5426:             \n"
"	strb r3, [r1]       \n"
"	adds r1, 0x1        \n"
"	subs r4, 0x1        \n"
"	cmp r4, 0           \n"
"	bge _080A5426       \n"
"	movs r4, 0x5        \n"
"	cmp r7, 0           \n"
"	beq _080A5444       \n"
"	movs r6, 0          \n"
"	adds r0, r7, 0      \n"
"_080A543A:             \n"
"	strb r6, [r1]       \n"
"	adds r1, 0x1        \n"
"	subs r0, 0x1        \n"
"	cmp r0, 0           \n"
"	bne _080A543A       \n"
"_080A5444:             \n"
"	adds r4, r7         \n"
"	cmp r4, 0xFF        \n"
"	bgt _080A5456       \n"
"	movs r0, 0xFF       \n"
"_080A544C:             \n"
"	strb r0, [r1]       \n"
"	adds r1, 0x1        \n"
"	adds r4, 0x1        \n"
"	cmp r4, 0xFF        \n"
"	ble _080A544C       \n"
"_080A5456:             \n"
"	adds r4, r2, 0      \n"
"	adds r0, r5, 0      \n"
"	ldr r2, [sp, 0x10]  \n"
"	cmp r4, r2          \n"
"	blt _080A5420       \n"
"_080A5460:             \n"
"	ldr r3, [sp, 0x8]   \n"
"	cmp r0, r3          \n"
"	bge _080A547E       \n"
"	movs r6, 0xFF       \n"
"_080A5468:             \n"
"	adds r5, r0, 0x1    \n"
"	movs r4, 0xFF       \n"
"_080A546C:             \n"
"	strb r6, [r1]       \n"
"	adds r1, 0x1        \n"
"	subs r4, 0x1        \n"
"	cmp r4, 0           \n"
"	bge _080A546C       \n"
"	adds r0, r5, 0      \n"
"	ldr r2, [sp, 0x8]   \n"
"	cmp r0, r2          \n"
"	blt _080A5468       \n"
"_080A547E:             \n"
"	mov r3, sp          \n"
"	ldrh r3, [r3, 0xC]  \n"
"	lsls r0, r3, 16     \n"
"	cmp r0, 0           \n"
"	bgt _080A548A       \n"
"	b _080A5590         \n"
"_080A548A:             \n"
"	mov r6, r8          \n"
"	ldr r0, [sp]        \n"
"	movs r1, 0x80       \n"
"	lsls r1, 3          \n"
"	adds r2, r0, r1     \n"
"	movs r0, 0          \n"
"	ldr r3, [sp, 0x10]  \n"
"	cmp r0, r3          \n"
"	bge _080A5586       \n"
"	movs r1, 0xFB       \n"
"	mov r10, r1         \n"
"_080A54A0:             \n"
"	adds r2, 0x5        \n"
"	movs r4, 0          \n"
"	cmp r0, 0           \n"
"	bne _080A54EC       \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"	movs r1, 0x1        \n"
"	mov r9, r1          \n"
"	cmp r0, r7          \n"
"	bge _080A5574       \n"
"_080A54B4:             \n"
"	ldrb r1, [r6]       \n"
"	adds r6, 0x1        \n"
"	cmp r1, 0x7F        \n"
"	ble _080A54DE       \n"
"	subs r4, 0x7F       \n"
"	cmp r1, 0x7F        \n"
"	ble _080A54D6       \n"
"	movs r5, 0x80       \n"
"	adds r3, r1, 0      \n"
"	subs r3, 0x7F       \n"
"_080A54C8:             \n"
"	ldrb r0, [r2]       \n"
"	orrs r0, r5         \n"
"	strb r0, [r2]       \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A54C8       \n"
"_080A54D6:             \n"
"	adds r4, r1         \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"	b _080A54E6         \n"
"_080A54DE:             \n"
"	adds r0, r1, 0x1    \n"
"	adds r2, r0         \n"
"	adds r0, r4, 0x1    \n"
"	adds r4, r0, r1     \n"
"_080A54E6:             \n"
"	cmp r4, r7          \n"
"	blt _080A54B4       \n"
"	b _080A5574         \n"
"_080A54EC:             \n"
"	ldr r1, _080A5538   \n"
"	adds r1, r2         \n"
"	mov r12, r1         \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"	adds r0, 0x1        \n"
"	mov r9, r0          \n"
"	cmp r4, r7          \n"
"	bge _080A5574       \n"
"_080A54FE:             \n"
"	ldrb r5, [r6]       \n"
"	adds r6, 0x1        \n"
"	cmp r5, 0x7F        \n"
"	ble _080A553C       \n"
"	subs r4, 0x7F       \n"
"	cmp r5, 0x7F        \n"
"	ble _080A556A       \n"
"	movs r7, 0x80       \n"
"	movs r0, 0x80       \n"
"	mov r8, r0          \n"
"	adds r3, r5, 0      \n"
"	subs r3, 0x7F       \n"
"_080A5516:             \n"
"	mov r0, r12         \n"
"	ldrb r1, [r0]       \n"
"	mov r0, r8          \n"
"	ands r0, r1         \n"
"	movs r1, 0x1        \n"
"	add r12, r1         \n"
"	cmp r0, 0           \n"
"	bne _080A552C       \n"
"	ldrb r0, [r2]       \n"
"	orrs r0, r7         \n"
"	strb r0, [r2]       \n"
"_080A552C:             \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A5516       \n"
"	b _080A556A         \n"
"	.align 2, 0         \n"
"_080A5538: .4byte 0xffffff00\n"
"_080A553C:             \n"
"	movs r3, 0          \n"
"	adds r4, 0x1        \n"
"	cmp r3, r5          \n"
"	bgt _080A556A       \n"
"	movs r7, 0x80       \n"
"	movs r3, 0x80       \n"
"	mov r8, r3          \n"
"	adds r3, r5, 0x1    \n"
"_080A554C:             \n"
"	mov r0, r12         \n"
"	ldrb r1, [r0]       \n"
"	mov r0, r8          \n"
"	ands r0, r1         \n"
"	movs r1, 0x1        \n"
"	add r12, r1         \n"
"	cmp r0, 0           \n"
"	beq _080A5562       \n"
"	ldrb r0, [r2]       \n"
"	orrs r0, r7         \n"
"	strb r0, [r2]       \n"
"_080A5562:             \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A554C       \n"
"_080A556A:             \n"
"	adds r4, r5         \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"	cmp r4, r7          \n"
"	blt _080A54FE       \n"
"_080A5574:             \n"
"	mov r1, r10         \n"
"	subs r0, r1, r7     \n"
"	adds r2, r0         \n"
"	mov r0, r9          \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r3, [r3, 0x1]  \n"
"	str r3, [sp, 0x10]  \n"
"	cmp r0, r3          \n"
"	blt _080A54A0       \n"
"_080A5586:             \n"
"	mov r8, r6          \n"
"	ldr r0, [sp, 0x4]   \n"
"	ldrh r1, [r0, 0xA]  \n"
"	mov r0, sp          \n"
"	strh r1, [r0, 0xC]  \n"
"_080A5590:             \n"
"	mov r2, sp          \n"
"	ldrh r2, [r2, 0xC]  \n"
"	lsls r0, r2, 16     \n"
"	asrs r0, 16         \n"
"	cmp r0, 0x1         \n"
"	ble _080A568C       \n"
"	mov r6, r8          \n"
"	ldr r3, [sp]        \n"
"	movs r0, 0x80       \n"
"	lsls r0, 3          \n"
"	adds r2, r3, r0     \n"
"	movs r0, 0          \n"
"	b _080A5684         \n"
"_080A55AA:             \n"
"	adds r2, 0x5        \n"
"	movs r4, 0          \n"
"	cmp r0, 0           \n"
"	bne _080A55F2       \n"
"	ldr r3, [sp, 0x4]   \n"
"	ldrb r7, [r3]       \n"
"	movs r1, 0x1        \n"
"	mov r10, r1         \n"
"	cmp r0, r7          \n"
"	bge _080A567C       \n"
"_080A55BE:             \n"
"	ldrb r1, [r6]       \n"
"	adds r6, 0x1        \n"
"	cmp r1, 0x7F        \n"
"	ble _080A55E4       \n"
"	subs r4, 0x7F       \n"
"	cmp r1, 0x7F        \n"
"	ble _080A55E0       \n"
"	movs r5, 0x40       \n"
"	adds r3, r1, 0      \n"
"	subs r3, 0x7F       \n"
"_080A55D2:             \n"
"	ldrb r0, [r2]       \n"
"	orrs r0, r5         \n"
"	strb r0, [r2]       \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A55D2       \n"
"_080A55E0:             \n"
"	adds r4, r1         \n"
"	b _080A55EC         \n"
"_080A55E4:             \n"
"	adds r0, r1, 0x1    \n"
"	adds r2, r0         \n"
"	adds r0, r4, 0x1    \n"
"	adds r4, r0, r1     \n"
"_080A55EC:             \n"
"	cmp r4, r7          \n"
"	blt _080A55BE       \n"
"	b _080A567C         \n"
"_080A55F2:             \n"
"	ldr r3, _080A5640   \n"
"	adds r3, r2         \n"
"	mov r12, r3         \n"
"	ldr r1, [sp, 0x4]   \n"
"	ldrb r7, [r1]       \n"
"	adds r0, 0x1        \n"
"	mov r10, r0         \n"
"	cmp r4, r7          \n"
"	bge _080A567C       \n"
"_080A5604:             \n"
"	ldrb r5, [r6]       \n"
"	adds r6, 0x1        \n"
"	cmp r5, 0x7F        \n"
"	ble _080A5644       \n"
"	subs r4, 0x7F       \n"
"	cmp r5, 0x7F        \n"
"	ble _080A5676       \n"
"	movs r3, 0x40       \n"
"	mov r8, r3          \n"
"	movs r0, 0x40       \n"
"	mov r9, r0          \n"
"	adds r3, r5, 0      \n"
"	subs r3, 0x7F       \n"
"_080A561E:             \n"
"	mov r0, r12         \n"
"	ldrb r1, [r0]       \n"
"	mov r0, r9          \n"
"	ands r0, r1         \n"
"	movs r1, 0x1        \n"
"	add r12, r1         \n"
"	cmp r0, 0           \n"
"	bne _080A5636       \n"
"	ldrb r0, [r2]       \n"
"	mov r1, r8          \n"
"	orrs r0, r1         \n"
"	strb r0, [r2]       \n"
"_080A5636:             \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A561E       \n"
"	b _080A5676         \n"
"	.align 2, 0         \n"
"_080A5640: .4byte 0xffffff00\n"
"_080A5644:             \n"
"	movs r3, 0          \n"
"	adds r4, 0x1        \n"
"	cmp r3, r5          \n"
"	bgt _080A5676       \n"
"	movs r3, 0x40       \n"
"	mov r8, r3          \n"
"	movs r0, 0x40       \n"
"	mov r9, r0          \n"
"	adds r3, r5, 0x1    \n"
"_080A5656:             \n"
"	mov r0, r12         \n"
"	ldrb r1, [r0]       \n"
"	mov r0, r9          \n"
"	ands r0, r1         \n"
"	movs r1, 0x1        \n"
"	add r12, r1         \n"
"	cmp r0, 0           \n"
"	beq _080A566E       \n"
"	ldrb r0, [r2]       \n"
"	mov r1, r8          \n"
"	orrs r0, r1         \n"
"	strb r0, [r2]       \n"
"_080A566E:             \n"
"	adds r2, 0x1        \n"
"	subs r3, 0x1        \n"
"	cmp r3, 0           \n"
"	bne _080A5656       \n"
"_080A5676:             \n"
"	adds r4, r5         \n"
"	cmp r4, r7          \n"
"	blt _080A5604       \n"
"_080A567C:             \n"
"	movs r3, 0xFB       \n"
"	subs r0, r3, r7     \n"
"	adds r2, r0         \n"
"	mov r0, r10         \n"
"_080A5684:             \n"
"	ldr r1, [sp, 0x10]  \n"
"	cmp r0, r1          \n"
"	blt _080A55AA       \n"
"	mov r8, r6          \n"
"_080A568C:             \n"
"	mov r0, r8          \n"
"	add sp, 0x18        \n"
"	pop {r3-r5}         \n"
"	mov r8, r3          \n"
"	mov r9, r4          \n"
"	mov r10, r5         \n"
"	pop {r4-r7}         \n"
"	pop {r1}            \n"
"	bx r1               ");
}

void sub_80A56A0(u8 param_1, u8 param_2)
{
    sub_80A3B80(gGroundMapDungeon_3001B70, param_1, param_2);
}

void sub_80A56C0(PixelPos *pos)
{
    GetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, pos);
}

static void sub_80A56D8(const PixelPos *pos)
{
    SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, pos);
}

void sub_80A56F0(PixelPos *pos)
{
    gGroundMapAction->unkE8 = *pos;
}

void sub_80A5704(PixelPos *pos)
{
    gGroundMapAction->unkF8 = *pos;
    gGroundMapAction->unkF0 = 0;
    gGroundMapAction->unkF4 = 0;
}

s16 GetGroundMapID(void)
{
    return gGroundMapAction->groundMapId;
}

UNUSED static const GroundConversionStruct *GetGroundConversionStruct(void)
{
    return &gGroundMapConversionTable[gGroundMapAction->groundMapId];
}

UNUSED static bool8 sub_80A5758(PixelPos *pos)
{
    if(gGroundMapDungeon_3001B70 != NULL)
    {
        sub_80A4608(gGroundMapDungeon_3001B70, pos);
        return TRUE;

    }
    else {
        return FALSE;
    }
}

bool8 GetCurrentDungeonBounds(PixelPos *pos1, PixelPos *pos2)
{
    if(gGroundMapDungeon_3001B70 != NULL)
    {
        GetDungeonBounds(gGroundMapDungeon_3001B70, pos1, pos2);
        return TRUE;

    }
    else {
        return FALSE;
    }
}

bool8 sub_80A579C(PixelPos *pos1, PixelPos *pos2)
{
    const GroundConversionStruct *convTable;

    if(gGroundMapDungeon_3001B70 != NULL)
    {
        if(gGroundMapAction->groundMapId != -1)
        {
            convTable = &gGroundMapConversionTable[gGroundMapAction->groundMapId];
            GetDungeonBounds(gGroundMapDungeon_3001B70, pos1, pos2);

            pos1->x += 0x7800;
            pos1->y += 0x5000;
            pos2->x -= 0x7800;
            pos2->y -= 0x5000;

            if(convTable->unk0 == 0xA)
            {
                pos1->x += 0x1800;
                pos1->y += 0x1800;
                pos2->x -= 0x1800;
                pos2->y -= 0x1800;
            }

            if (pos1->x > pos2->x) {
                pos2->x = pos1->x;
            }
            if (pos1->y > pos2->y) {
                pos2->y = pos1->y;
            }
            return TRUE;
        }
    }
    return FALSE;
}

bool8 CheckMapCollision_80A585C(PixelPos *pixPos1, PixelPos *boundary)
{
    u8 *currPtr;
    int i, j;
    u8 *ptr;

    ptr = (void *)gGroundMapDungeon_3001B70->unk544 + ((pixPos1->y * 256) + pixPos1->x + 0x405);

    i = boundary->y;

    if (gGroundMapDungeon_3001B70->unk544 == NULL) {
        return TRUE;
    }

    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            if ((*(currPtr++) & 0x80) != 0)
                return TRUE;
        }
        ptr += 256;
    }
    return FALSE;
}

bool8 sub_80A58C8(PixelPos *pixPos1, PixelPos *boundary)
{
    u8 *currPtr;
    int i, j;
    u8 *ptr;

    ptr = (void *)gGroundMapDungeon_3001B70->unk544 + ((pixPos1->y * 256) + pixPos1->x + 0x405);

    i = boundary->y;

    if (gGroundMapDungeon_3001B70->unk544 == NULL) {
        return TRUE;
    }

    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            if ((*(currPtr++) & 0x40) != 0)
                return TRUE;
        }
        ptr += 256;
    }
    return FALSE;
}

u8 sub_80A5934(u8 param_1, PixelPos *param_2, PixelPos *param_3)
{
    return sub_80A4660(gGroundMapDungeon_3001B70, param_1, param_2, param_3);
}

u8 sub_80A595C(u8 param_1, PixelPos *param_2, PixelPos *param_3)
{
    return sub_80A46C0(gGroundMapDungeon_3001B70, param_1, param_2, param_3);
}

u16 sub_80A5984(s32 param_1, PixelPos *param_2)
{
    return sub_80A4720(gGroundMapDungeon_3001B70, param_1, param_2);
}

void sub_80A59A0(s32 param_1, PixelPos *param_2, u16 param_3)
{
    sub_80A4740(gGroundMapDungeon_3001B70, param_1, param_2, param_3);
}

void GroundMap_Action(void)
{
    nullsub_123();
    HandleAction(&gGroundMapAction->action, DEBUG_LOC_PTR("../ground/ground_map.c", 0x57F, "GroundMap_Action"));
}

void sub_80A59DC(void)
{
    if (gGroundMapDungeon_3001B70 != NULL) {
        PixelPos pixPos;

        if (sub_809D248(&pixPos) == 0) {
            pixPos.x = 0;
            pixPos.y = 0;
        }

        switch (gGroundMapAction->groundMapId) {
            case MAP_PERSONALITY_TEST_CYAN:
            case MAP_PERSONALITY_TEST_PURPLE:
            case MAP_PERSONALITY_TEST_MULTICOLOR: {
                PixelPos pixPos2;

                gGroundMapAction->unkF4 += 2;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 4;
                gGroundMapAction->unkF4 &= 3;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x, pixPos.y + gGroundMapAction->unkF8.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                pixPos2.x = pixPos.x;
                pixPos2.y = pixPos.y - gGroundMapAction->unkF8.y;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case MAP_FUGITIVES_SNOW_ROAD:
            case MAP_FUGITIVES_BLIZZARD_ROAD: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8.x;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case MAP_NIGHTMARE: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8.x;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case MAP_SUMMIT_SUNSET: {
                PixelPos pixPos2 = pixPos;

                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case MAP_NIGHT_SKY_1: {
                PixelPos pixPos2;

                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0 += gGroundMapAction->unkE8.x;
                gGroundMapAction->unkF4 += gGroundMapAction->unkE8.y;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 8;
                gGroundMapAction->unkF0 %= 8;
                gGroundMapAction->unkF4 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y + gGroundMapAction->unkF8.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case MAP_NIGHT_SKY_2: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8.x;
                gGroundMapAction->unkF4 += gGroundMapAction->unkE8.y;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 8;
                gGroundMapAction->unkF0 %= 8;
                gGroundMapAction->unkF4 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y + gGroundMapAction->unkF8.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case MAP_SILENT_CHASM_ENTRY: {
                PixelPos pixPos2;

                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 4;
                gGroundMapAction->unkF0 &= 3;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case MAP_PELIPPER_POST_OFFICE: {
                PixelPos pixPos2;

                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 &= 7;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case MAP_TITLE_SCREEN: {
                PixelPos pixPos2;

                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 &= 7;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { gGroundMapAction->unkF8.x, pixPos.y};
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case MAP_FRIEND_AREA_FINAL_ISLAND: {
                PixelPos pixPos2;

                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos);
                pixPos2 = (PixelPos) {0, 0};
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            default:
                SetCameraPositionForLayer(gGroundMapDungeon_3001B70, 0, &pixPos);
                break;
        }

        sub_80A4764(gGroundMapDungeon_3001B70);
    }

    sub_80A60D8();
}

void sub_80A5E70(void)
{
    if (gGroundMapDungeon_3001B70 != NULL)
        sub_80A49E8(gGroundMapDungeon_3001B70);

    sub_80A62D0();
}
