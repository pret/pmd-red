#include "global.h"
#include "debug.h"
#include "ground_main.h"
#include "ground_map_1.h"
#include "ground_script.h"

extern GroundMapAction *gGroundMapAction;

extern const u8 gUnknown_8117594[];
extern const u8 gUnknown_81175EC[];
extern const DebugLocation gUnknown_81175E0;
extern const DebugLocation gUnknown_8117644;
extern const u8 gUnknown_8117650[];
extern const DebugLocation gUnknown_8117698;

extern void GroundMap_GetStationScript(ScriptInfoSmall *, s16, u32, u32);

extern u8 sub_809D678(void *);
extern void sub_809D710(u8 *, ScriptInfoSmall *, s32);
extern bool8 sub_809D968(void *, s32);

static void sub_80A4BE8(ScriptInfoSmall *script, s16 r1)
{
    GroundMap_GetStationScript(script, r1, 0, 0);
}

void GroundMap_ExecuteEvent(s16 scriptIndex, u32 param_2)
{
    ScriptInfoSmall script;
    s32 index_s32;
    u8 iVar2;

    index_s32 = scriptIndex;
    iVar2 = param_2;

    Log(0,gUnknown_8117594, index_s32, iVar2); // "GroundMap ExecuteEvent %3d %d
    sub_809D710(NULL, &script, index_s32);
    if (iVar2 != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_81175E0);
}

void GroundMap_ExecuteStation(s16 param_1, s16 param_2, s8 param_3, u32 param_4)
{
    ScriptInfoSmall script;
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    u8 iVar4;

    iVar1 = param_1;
    iVar2 = param_2;
    iVar3 = param_3;
    iVar4 = param_4;

    Log(0, gUnknown_81175EC, iVar1, iVar2, iVar3, iVar4); // GroundMap ExecuteStation %3d %3d %3d %d
    GroundMap_GetStationScript(&script, iVar1, iVar2, iVar3);
    if (iVar4 != 0)
        script.state = 5;

    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_8117644);
}

void GroundMap_ExecuteEnter(s16 param_1)
{
    ScriptInfoSmall script;
    s32 iVar1;

    iVar1 = param_1;

    Log(0, gUnknown_8117650, iVar1); // GroundMap ExecuteEnter %3d
    sub_80A4BE8(&script, iVar1);
    script.state = 2;
    script.group = 0;
    script.sector = 0;
    GroundScript_ExecutePP(&gGroundMapAction->action, 0, &script, &gUnknown_8117698);
}

UNUSED static u8 sub_80A4D14(void)
{
    return sub_809D678(&gGroundMapAction->action);
}

bool8 sub_80A4D2C(s16 param_1)
{
    s32 iVar1 = param_1;
    return sub_809D968(&gGroundMapAction->action, iVar1);
}

bool8 sub_80A4D48(s16 index)
{
    if (index == -1) return TRUE;
    if (gGroundConversion_811BAF4[index].unk0 == 5) return FALSE;
    if (gGroundConversion_811BAF4[index].unk0 != 8) return TRUE;
    return FALSE;
}
