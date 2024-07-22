#include "global.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"
#include "memory.h"

IWRAM_DATA GroundMapAction *gGroundMapAction = {0};
IWRAM_DATA unkStruct_3001B70 *gUnknown_3001B70 = {0};

extern const CallbackData gUnknown_811736C;
extern const DebugLocation gUnknown_8117538[];

extern void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s16 group, s8 sector);
extern void sub_809D648(void *);
extern void sub_80A2D00(unkStruct_3001B70 *);
extern void InitActionScriptData(GroundMapAction *, const DebugLocation *);
extern void sub_80A2D68(unkStruct_3001B70 *);
extern void sub_80A2D88(unkStruct_3001B70 *);

void AllocGroundMapAction(void)
{
    gGroundMapAction = MemoryAlloc(sizeof(GroundMapAction), 6);
    gGroundMapAction->groundMapId = -1;
    InitActionWithParams(&gGroundMapAction->action, &gUnknown_811736C, 0, -1, -1);
    sub_80A5E8C(0);
    GroundMap_Reset();
}

void FreeGroundMapAction(void)
{
    GroundMap_Reset();
    sub_80A5EBC();
    sub_809D648(gGroundMapAction);
    MemoryFree(gGroundMapAction);
    gGroundMapAction = NULL;
}

void GroundMap_Reset(void)
{
    sub_80015C0(0, 0x37);
    sub_80015C0(0, 0x38);
    InitActionScriptData(gGroundMapAction, gUnknown_8117538);

    if (gUnknown_3001B70 != NULL) {
        sub_80A2D00(gUnknown_3001B70);
        MemoryFree(gUnknown_3001B70);
        gUnknown_3001B70 = NULL;
    }

    sub_80A5EDC(0);
}

void sub_80A4B38(void)
{
    nullsub_121();

    if (gUnknown_3001B70 != NULL)
        sub_80A2D68(gUnknown_3001B70);
}

void sub_80A4B54(void)
{
    if (gUnknown_3001B70 != NULL)
        sub_80A2D88(gUnknown_3001B70);

    nullsub_122();
}
