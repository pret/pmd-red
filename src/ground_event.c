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
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    const ScriptCommand *unk1C;
} GroundEvent;

IWRAM_INIT GroundEvent *gGroundEvents = NULL;

extern void GroundLives_CancelBlank_2(void);

void DeleteGroundEvents(void);
void GroundEvent_Delete(s32);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
s32 GroundEvent_Add(s32 id, const GroundEventData*, s32 group, s32 sector);
extern DebugLocation gUnknown_81187DC;
extern u8 gGroundEventSelectText[];
extern u8 gGroundEventCancelText[];
extern u8 gGroundEventAddText[];

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

static inline void SetUnkInGroundEvent(const CompactPos *posPtr, s32 *dst)
{
    if (!(posPtr->xFlags & 4)) {
        s32 unk = posPtr->xTiles << 11;
        dst[0] = unk;
        if (posPtr->xFlags & 2) {
            dst[0] = unk + 0x400;
        }
    }
    if (!(posPtr->yFlags & 4)) {
        s32 unk = posPtr->yTiles << 11;
        dst[1] = unk;
        if (posPtr->yFlags & 2) {
            dst[1] = unk + 0x400;
        }
    }
}

struct TestStruct
{
    u32 unk0;
    u32 unk4;
};

extern struct TestStruct sUnknown; // Todo: figure out or guess what this variable could be.

s32 GroundEvent_Add(s32 id, const GroundEventData *eventData, s32 group, s32 sector)
{
    s32 i;
    s32 scriptID_s32 = (s16) id;
    s32 group_s32 = (s16) group;
    s32 sector_s32 = (s8) sector;
    const ScriptRef *script;
    GroundEvent *ptr;
    struct TestStruct r;
    s32 sp[2];

    ASM_MATCH_TRICK(sector_s32);

    script = eventData->script;

    if (scriptID_s32 < 0) {
        ptr = &gGroundEvents[0];
        for (i = 0; i < 0x20; i = (s16)(i + 1), ptr++) {
            if (ptr->unk2 == -1) {
                scriptID_s32 = i;
                break;
            }
        }
        if (scriptID_s32 < 0) {
            return -1;
        }
    }
    else {
        ptr = &gGroundEvents[scriptID_s32];
    }

    Log(0, gGroundEventAddText, scriptID_s32, script->id, group_s32, sector_s32, eventData->script->script);

    ptr->unk0 = scriptID_s32;
    ptr->unk2 = script->id;
    ptr->unk4 = group_s32;
    ptr->unk6 = sector_s32;
    switch (script->type) {
        case 1:
        case 2:
            ptr->unk8 = 0x60;
            break;
        case 7:
        default:
            ptr->unk8 = 0x20;
            break;
    }

    // The line below effectively does nothing(it's not even generated in the asm, agbcc ignores it, but changes regalloc...), because 'r' is overwritten in the next two instructions, however it is REQUIRED to match. Only discovered, because it's present in Blue's asm.
    r = sUnknown;

    r.unk0 = eventData->kind << 11;
    r.unk4 = eventData->unk1 << 11;
    SetUnkInGroundEvent(&eventData->pos, sp);

    ptr->unkC = sp[0];
    ptr->unk14 = sp[0] + r.unk0;
    ptr->unk10 = sp[1];
    ptr->unk18 = sp[1] + r.unk4;
    ptr->unk1C = eventData->script->script;

    GroundLives_CancelBlank_2();
    return scriptID_s32;
}

