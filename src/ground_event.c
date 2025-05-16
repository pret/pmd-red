#include "global.h"
#include "globaldata.h"
#include "ground_script.h"
#include "debug.h"
#include "memory.h"

typedef struct GroundEvent
{
    s16 unk0;
    s16 unk2;
    s16 unk4; // scriptID or group?
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
const struct GroundScriptHeader *GetGroundScript(s16 a0, const DebugLocation *);
s32 GroundEvent_Add(s32 id, const GroundEventData*, s32 group, s32 sector);

void AllocGroundEvents(void)
{
    s32 ind;
    GroundEvent *ptr;
    gGroundEvents = MemoryAlloc(sizeof(GroundEvent) * 0x20, 0x6);

    for(ind = 0, ptr = &gGroundEvents[ind]; ind < 0x20; ind = (s16)(ind + 1), ptr++)
    {
        ptr->unk2 |= -1;
    }
    DeleteGroundEvents();
}

void DeleteGroundEvents(void)
{
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

ALIGNED(4) static const char sFileName[] = "../ground/ground_event.c";
ALIGNED(4) static const char sFuncName[] = "GroundEvent_Select";

static const DebugLocation sGroundEvent_DebugLoc = {
    .file = sFileName,
    .line = 160, // Nice, the line here is 63...
    .func = sFuncName,
};

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
    scriptPtr = GetGroundScript(scriptID_s32, &sGroundEvent_DebugLoc);
    Log('\0',"GroundEvent Select %3d  %3d  %3d", scriptID_s32, group_s32, sector_s32);

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

    Log('\0',"GroundEvent Cancel %3d  %3d", scriptID_s32, sector_s32);

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
    s32 unk0;
    s32 unk4;
};

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

    Log(0, "GroundEvent Add id %3d  kind %3d  group %3d  sector %3d  script %p\0", scriptID_s32, script->id, group_s32, sector_s32, eventData->script->script);

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

    r = (struct TestStruct) {eventData->kind << 11, eventData->unk1 << 11};
    SetUnkInGroundEvent(&eventData->pos, sp);

    ptr->unkC = sp[0];
    ptr->unk14 = sp[0] + r.unk0;
    ptr->unk10 = sp[1];
    ptr->unk18 = sp[1] + r.unk4;
    ptr->unk1C = eventData->script->script;

    GroundLives_CancelBlank_2();
    return scriptID_s32;
}

void GroundEvent_Delete(s32 id)
{
    s32 scriptID_s32 = (s16) id;
    GroundEvent *ptr = &gGroundEvents[scriptID_s32];
    Log(0, "GroundEvent Delete id %3d\0", scriptID_s32);
    ptr->unk2 = -1;
}

bool8 sub_80ADC64(s32 id, ScriptInfoSmall *dst)
{
    s32 scriptID_s32 = (s16) id;
    GroundEvent *ptr = &gGroundEvents[scriptID_s32];

    if (ptr->unk2 != -1) {
        dst->ptr = ptr->unk1C;
        dst->state = 2;
        dst->group = ptr->unk4;
        dst->sector = ptr->unk6;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

s16 FindGroundEvent(u32 flags, s32 *arg1, s32 *arg2)
{
    s32 i;
    GroundEvent *ptr = &gGroundEvents[0];
    for (i = 0; i < 0x20; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1
            && (ptr->unk8 & flags)
            && ptr->unkC < arg2[0]
            && ptr->unk14 > arg1[0]
            && ptr->unk10 < arg2[1]
            && ptr->unk18 > arg1[1])
        {
            return i;
        }
    }

    return -1;
}

UNUSED static s16 UnusedFindGroundEvent(u32 flags, s32 *arg1, s32 *arg2)
{
    s32 i;
    GroundEvent *ptr = &gGroundEvents[0];
    for (i = 0; i < 0x20; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1 && (ptr->unk8 & flags)) {
            struct TestStruct r = {0};
            r.unk0 = (ptr->unkC + ptr->unk14) / 2;
            r.unk4 = (ptr->unk10 + ptr->unk18) / 2;
            if (r.unk0 < arg2[0]
                && r.unk0 > arg1[0]
                && r.unk4 < arg2[1]
                && r.unk4 > arg1[1])
            {
                return i;
            }
        }
    }

    return -1;
}

void nullsub_124(void) {}
