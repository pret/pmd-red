#include "global.h"
#include "globaldata.h"
#include "ground_event.h"
#include "ground_script.h"
#include "ground_lives.h"
#include "debug.h"
#include "memory.h"
#include "ground_script_file.h"

#define NUM_GROUND_EVENTS 32

typedef struct GroundEvent
{
    s16 unk0;
    s16 unk2;
    s16 unk4; // scriptID or group?
    s8 unk6; // sector
    s32 unk8;
    PixelPos unkC;
    PixelPos unk14;
    const ScriptCommand *unk1C;
} GroundEvent;

IWRAM_INIT GroundEvent *gGroundEvents = NULL;

static s32 GroundEvent_Add(s32 id, const GroundEventData *eventData, s32 group, s32 sector);
static void GroundEvent_Delete(s32 id);

void AllocGroundEvents(void)
{
    s32 i;
    GroundEvent *ptr;
    gGroundEvents = MemoryAlloc(sizeof(GroundEvent) * NUM_GROUND_EVENTS, MEMALLOC_GROUP_6);

    for (i = 0, ptr = &gGroundEvents[i]; i < NUM_GROUND_EVENTS; i = (s16)(i + 1), ptr++) {
        ptr->unk2 |= -1;
    }

    DeleteGroundEvents();
}

void DeleteGroundEvents(void)
{
    s32 v1;
    GroundEvent* current;

    current = &gGroundEvents[0];
    for (v1 = 0; v1 < NUM_GROUND_EVENTS; v1 = (s16) (v1 + 0x1), current++) {
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
    scriptPtr = GetGroundScript(scriptID_s32, DEBUG_LOC_PTR("../ground/ground_event.c", 160, "GroundEvent_Select"));

    Log(0, "GroundEvent Select %3d  %3d  %3d",
        scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    eventData = sectorPtr->events;

    size = sectorPtr->nEvents;
    for (i = 0; i < size; i++, eventData++) {
        GroundEvent_Add(-1, eventData, group_s32, sector_s32);
    }
}

void GroundEvent_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundEvent *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8)sector;

    Log(0, "GroundEvent Cancel %3d  %3d",
        scriptID_s32, sector_s32);

    index = 0;
    ptr = &gGroundEvents[0];
    for(; index < NUM_GROUND_EVENTS; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk2 != -1) && (ptr->unk4 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unk6 == sector_s32)
                GroundEvent_Delete(index);
    }
}

static s32 GroundEvent_Add(s32 id, const GroundEventData *eventData, s32 group, s32 sector)
{
    s32 i;
    s32 scriptID_s32 = (s16) id;
    s32 group_s32 = (s16) group;
    s32 sector_s32 = (s8) sector;
    const ScriptRef *script;
    GroundEvent *ptr;
    PixelPos pos;
    PixelPos resultPos;

    ASM_MATCH_TRICK(sector_s32);

    script = eventData->script;

    if (scriptID_s32 < 0) {
        ptr = &gGroundEvents[0];
        for (i = 0; i < NUM_GROUND_EVENTS; i = (s16)(i + 1), ptr++) {
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

    Log(0, "GroundEvent Add id %3d  kind %3d  group %3d  sector %3d  script %p\0",
        scriptID_s32, script->id, group_s32, sector_s32, eventData->script->script);

    ptr->unk0 = scriptID_s32;
    ptr->unk2 = script->id;
    ptr->unk4 = group_s32;
    ptr->unk6 = sector_s32;
    switch (script->type) {
        case SCRIPT_TYPE_01:
        case SCRIPT_TYPE_02: {
            ptr->unk8 = 0x60;
            break;
        }
        case SCRIPT_TYPE_07:
        default: {
            ptr->unk8 = 0x20;
            break;
        }
    }

    pos = (PixelPos) {eventData->kind << 11, eventData->unk1 << 11};
    SetUnkInGroundEvent(&eventData->pos, &resultPos);

    ptr->unkC.x = resultPos.x;
    ptr->unk14.x = resultPos.x + pos.x;
    ptr->unkC.y = resultPos.y;
    ptr->unk14.y = resultPos.y + pos.y;
    ptr->unk1C = eventData->script->script;

    GroundLives_CancelBlank_2();
    return scriptID_s32;
}

static void GroundEvent_Delete(s32 id)
{
    s32 scriptID_s32 = (s16)id;
    GroundEvent *ptr = &gGroundEvents[scriptID_s32];
    Log(0, "GroundEvent Delete id %3d\0",
        scriptID_s32);
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

s16 FindGroundEvent(u32 flags, PixelPos *arg1, PixelPos *arg2)
{
    s32 i;
    GroundEvent *ptr = &gGroundEvents[0];
    for (i = 0; i < NUM_GROUND_EVENTS; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1
            && (ptr->unk8 & flags)
            && ptr->unkC.x < arg2->x
            && ptr->unk14.x > arg1->x
            && ptr->unkC.y < arg2->y
            && ptr->unk14.y > arg1->y)
        {
            return i;
        }
    }

    return -1;
}

UNUSED static s16 UnusedFindGroundEvent(u32 flags, PixelPos *arg1, PixelPos *arg2)
{
    s32 i;
    GroundEvent *ptr = &gGroundEvents[0];
    for (i = 0; i < NUM_GROUND_EVENTS; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1 && (ptr->unk8 & flags)) {
            PixelPos resultPos = {0};
            resultPos.x = (ptr->unkC.x + ptr->unk14.x) / 2;
            resultPos.y = (ptr->unkC.y + ptr->unk14.y) / 2;
            if (resultPos.x < arg2->x
                && resultPos.x > arg1->x
                && resultPos.y < arg2->y
                && resultPos.y > arg1->y)
            {
                return i;
            }
        }
    }

    return -1;
}

void nullsub_124(void)
{
}
