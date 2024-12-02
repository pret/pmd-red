#include "global.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"
#include "memory.h"

IWRAM_DATA GroundMapAction *gGroundMapAction = {0};
IWRAM_DATA unkStruct_3001B70 *gGroundMapDungeon_3001B70 = {0};

extern const CallbackData gGroundScriptNullCallbacks;
extern const DebugLocation gUnknown_8117538[];

extern void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s16 group, s8 sector);
extern void sub_80A2D00(unkStruct_3001B70 *);
extern void sub_80A2D68(unkStruct_3001B70 *);
extern void sub_80A2D88(unkStruct_3001B70 *);

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
        sub_80A2D00(gGroundMapDungeon_3001B70);
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

bool8 ChangeScriptFile(s32 a0);
const struct GroundScriptHeader *GetGroundScript(s32 a0, DebugLocation *);

extern DebugLocation gUnknown_8117560;
extern const u8 gUnknown_811756C[];

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
