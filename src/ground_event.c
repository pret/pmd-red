#include "global.h"
#include "ground_script.h"
#include "debug.h"
#include "memory.h"

typedef struct GroundEvent
{
    s16 unk0;
    s16 unk2;
    s16 unk4; // scriptID
    s8 unk6; // sector
    u8 unk7[0x20 - 0x7];
} GroundEvent;

IWRAM_INIT GroundEvent *gGroundEvents = NULL;

void DeleteGroundEvents(void);
void GroundEvent_Delete(s32);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
s16 GroundEvent_Add(s32 id, const GroundEventData*, s32 group, s32 sector);
extern DebugLocation gUnknown_81187DC;
extern u8 gGroundEventSelectText[];
extern u8 gGroundEventCancelText[];

void AllocGroundEvents(void) {
    s32 ind;
    GroundEvent *ptr;
    gGroundEvents = MemoryAlloc(sizeof(GroundEvent) * 0x20, 0x6);

    for(ind = 0, ptr = &gGroundEvents[ind]; ind < 0x20; ind = (s16)(ind + 1), ptr++)
    {
        ptr->unk2 |= -1;
    }
    DeleteGroundEvents();
}

void DeleteGroundEvents(void) {
    s32 v1;
    GroundEvent* current;
    
    current = &gGroundEvents[0];
    for (v1 = 0; v1 < 0x20; v1 = (s16) (v1 + 0x1), current++) {    
        if(current->unk2 != -1)
            GroundEvent_Delete(v1);
    }
}

void FreeGroundEvents(void)
{
    DeleteGroundEvents();
    MemoryFree(gGroundEvents);
    gGroundEvents = NULL;
}

void GroundEvent_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundEventData *eventData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_81187DC);
    Log('\0',gGroundEventSelectText, scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    eventData = sectorPtr->events;

    size = sectorPtr->nEvents;
    for (i = 0; i < size; i++, eventData++)
    {
        GroundEvent_Add(-1,eventData,group_s32,sector_s32);
    }
}

void GroundEvent_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundEvent *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gGroundEventCancelText, scriptID_s32, sector_s32);

    index = 0;
    ptr = &gGroundEvents[0];
    for(; index < 0x20; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk2 != -1) && (ptr->unk4 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unk6 == sector_s32)
                GroundEvent_Delete(index);
    }
}

