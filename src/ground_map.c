#include "global.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_bg.h"
#include "ground_main.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"
#include "memory.h"

IWRAM_INIT GroundMapAction *gGroundMapAction = {NULL};
IWRAM_INIT GroundBg *gGroundMapDungeon_3001B70 = {NULL};

extern GroundMapAction *gGroundMapAction;

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
    InitAction2((Action *)gGroundMapAction);
    MemoryFree(gGroundMapAction);
    gGroundMapAction = NULL;
}

void GroundMap_Reset(void)
{
    ClearScriptVarArray(NULL, MAP_LOCAL);
    ClearScriptVarArray(NULL, MAP_LOCAL_DOOR);
    ActionResetScriptData((Action *)gGroundMapAction, gUnknown_8117538);

    if (gGroundMapDungeon_3001B70 != NULL) {
        GroundBg_FreeAll(gGroundMapDungeon_3001B70);
        MemoryFree(gGroundMapDungeon_3001B70);
        gGroundMapDungeon_3001B70 = NULL;
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
    if (gGroundConversion_811BAF4[index].unk0 == 5) return FALSE;
    if (gGroundConversion_811BAF4[index].unk0 != 8) return TRUE;
    return FALSE;
}

s32 GetAdjustedGroundMap(s16 param_1)
{
    s32 iVar5;

    iVar5 = param_1;

    switch(iVar5)
    {
        case 9:
        case 0xC:
            iVar5 = (s16)(iVar5 + ((GetScriptVarValue(NULL, BASE_KIND) * 6) + GetScriptVarValue(NULL, BASE_LEVEL)));
            break;
        case 2:
            if (sub_80023E4(6)) {
                iVar5 = 3;
            }
            break;
        default:
            break;
    }

    return iVar5;
}
