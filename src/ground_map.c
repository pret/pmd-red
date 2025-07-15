#include "global.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_bg.h"
#include "ground_main.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"
#include "memory.h"
#include "ground_map_conversion_table.h"
#include "code_800558C.h"
#include "constants/dungeon.h"

IWRAM_INIT GroundMapAction *gGroundMapAction = {NULL};
IWRAM_INIT GroundBg *gGroundMapDungeon_3001B70 = {NULL};

extern GroundMapAction *gGroundMapAction;

extern const SubStruct_52C gUnknown_8117324;
extern const SubStruct_52C gUnknown_8117354;
extern const SubStruct_52C gUnknown_811733C;
extern const u8 gUnknown_81176A4[];
extern const u8 gUnknown_8117700[];
extern const u8 gUnknown_8117594[];
extern const u8 gUnknown_81175EC[];
extern const DebugLocation gUnknown_81175E0;
extern const DebugLocation gUnknown_8117644;
extern const u8 gUnknown_8117650[];
extern const DebugLocation gUnknown_8117698;

bool8 ChangeScriptFile(s32 a0);
const struct GroundScriptHeader *GetGroundScript(s32 a0, DebugLocation *);

extern DebugLocation gUnknown_8117560;
extern const u8 gUnknown_811756C[];

extern u8 sub_809D678(void *);
extern bool8 GroundScriptNotify(void *, s32);

extern const CallbackData gGroundScriptNullCallbacks;
extern const DebugLocation gUnknown_8117538[];

extern void sub_80A2D68(GroundBg *);
extern void sub_80A2D88(GroundBg *);

void AllocGroundMapAction(void)
{
    gGroundMapAction = MemoryAlloc(sizeof(GroundMapAction), 6);
    gGroundMapAction->groundMapId = -1;
    InitActionWithParams(&gGroundMapAction->action, &gGroundScriptNullCallbacks, 0, -1, -1);
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
    ActionResetScriptData((Action *)gGroundMapAction, gUnknown_8117538);

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
    scriptHeader = GetGroundScript(groundScriptId, &gUnknown_8117560);
    Log(0, gUnknown_811756C, groundScriptId, groupId, sectorId);
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

    Log(0, gUnknown_8117594, index_s32, iVar2); // "GroundMap ExecuteEvent %3d %d
    GetFunctionScript(NULL, &script, index_s32);
    if (iVar2 != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_81175E0);
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

    Log(0, gUnknown_81175EC, map, group, sector, setScriptState); // GroundMap ExecuteStation %3d %3d %3d %d
    GroundMap_GetStationScript(&script, map, group, sector);
    if (setScriptState != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_8117644);
}

void GroundMap_ExecuteEnter(s16 param_1)
{
    ScriptInfoSmall script;
    s32 iVar1;

    iVar1 = param_1;

    Log(0, gUnknown_8117650, iVar1); // GroundMap ExecuteEnter %3d
    GroundMap_GetFirstStationScript(&script, iVar1);
    script.state = 2;
    script.group = 0;
    script.sector = 0;
    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_8117698);
}

UNUSED static u8 sub_80A4D14(void)
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
            if (sub_80023E4(6)) {
                retMapId = MAP_WHISCASH_POND_OPEN;
            }
            break;
    }

    return retMapId;
}

struct MapToDungeonStruct
{
    s16 id;
    DungeonLocation loc;
    u32 unk8;
};

extern const struct MapToDungeonStruct gUnknown_81173C0[];
extern const u8 gUnknown_81176DC[];
extern const u8 gUnknown_8117740[];
extern const DebugLocation gUnknown_81176D0;
extern const DebugLocation gUnknown_8117734;
extern const u32 gUnknown_81176F8[];
extern const u32 gUnknown_8117754[];

void GroundMap_SelectDungeon(s32 mapId, const DungeonLocation *loc, u32 param_2);
void sub_80A56D8(const void *);

void GroundMap_Select(s32 mapId_)
{
    const GroundConversionStruct *ptr;
    s32 mapId = (s16) mapId_;

    Log(0, gUnknown_81176A4,mapId);
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
            const struct MapToDungeonStruct *mapToDungPtr = &gUnknown_81173C0[0];
            while (mapToDungPtr->id != -1 && mapToDungPtr->id != mapId) {
                mapToDungPtr++;
            }
            MemoryFree(gGroundMapDungeon_3001B70);
            gGroundMapDungeon_3001B70 = NULL;
            GroundMap_SelectDungeon(mapId, &mapToDungPtr->loc, mapToDungPtr->unk8);
            return;
        }
        case -1:
            FatalError(&gUnknown_81176D0,gUnknown_81176DC,mapId,ptr->unk0);
            break;
        default:
            GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117324);
            sub_80A5EDC(1);
            break;
    }

    sub_80A2FBC(gGroundMapDungeon_3001B70, ptr->mapFileTableId);
    gGroundMapAction->unkE8 = 0;
    gGroundMapAction->unkEC = 0;
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

    sub_80A56D8(&gUnknown_81176F8);
}

void GroundMap_SelectDungeon(s32 mapId_, const DungeonLocation *loc, u32 param_2)
{
    const GroundConversionStruct *ptr;
    s32 mapId = (s16) mapId_;

    Log('\0', gUnknown_8117700, mapId);
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
        FatalError(&gUnknown_8117734, gUnknown_8117740, mapId);
    }

    GroundBg_Init(gGroundMapDungeon_3001B70, &gUnknown_8117354);
    sub_80A5EDC(1);
    sub_80A3440(gGroundMapDungeon_3001B70, ptr->mapFileTableId, loc, param_2);
    gGroundMapAction->unkE8 = 0;
    gGroundMapAction->unkEC = 0;
    gGroundMapAction->unkF0 = 0;
    gGroundMapAction->unkF4 = 0;
    gGroundMapAction->unkF8.x = 0;
    gGroundMapAction->unkF8.y = 0;
    gGroundMapAction->unk100 = gGroundMapAction->unk104 = gGroundMapAction->unk108 = gGroundMapAction->unk10C = 0;

    sub_80A56D8(&gUnknown_8117754);
}
