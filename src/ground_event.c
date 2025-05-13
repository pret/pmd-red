#include "global.h"
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
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
s32 GroundEvent_Add(s32 id, const GroundEventData*, s32 group, s32 sector);
extern DebugLocation gUnknown_81187DC;
extern u8 gGroundEventSelectText[];
extern u8 gGroundEventCancelText[];
extern u8 gGroundEventAddText[];
extern u8 gGroundEventDeleteText[];

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
    s32 unk0;
    s32 unk4;
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

void GroundEvent_Delete(s32 id)
{
    s32 scriptID_s32 = (s16) id;
    GroundEvent *ptr = &gGroundEvents[scriptID_s32];
    Log(0, gGroundEventDeleteText, scriptID_s32);
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

// TODO: Check if file split here

#include "dungeon.h"
#include "decompress_at.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "constants/dungeon.h"

extern bool8 IsWaterDungeon(u32 r0);

struct UnkDungeonFileData
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6[5];
};

struct UnkDataFileStruct
{
    struct UnkDungeonFileData **unk0;
    FloorProperties *unk4;
    u16 **unk8;
    UnkDungeonGlobal_unk1CD98 **unkC;
    u16 **unk10;
};

s32 sub_80ADFB8(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5, u8 *a6, s32 a7);

extern const u8 gUnknown_8108EC0[];
extern const u8 gMapparamText[];
extern const u8 gUnknown_811889C[];
extern const u8 gUnknown_81188B4[];
extern const u8 gUnknown_81188A8[];
extern const u8 gUnknown_81188C0[];
extern const u8 gUnknown_81188CC[];
extern const u8 gUnknown_81188DC[];

void sub_80ADD9C(OpenedFile **a0, OpenedFile **a1, u32 *a2, u32 *a3, u16 *a4, DungeonLocation *a5, s32 a6, s32 a7, s32 a8, u16 *a9)
{
    OpenedFile *file;
    s32 r8;
    s32 i, j;
    u8 name[12];
    DungeonLocation dungLoc;
    u8 dungId;
    s32 dungFloor;
    struct UnkDungeonFileData *strPtr;
    void *r10 = MemoryAlloc(0x930, 7);
    OpenedFile *mapParamFile = OpenFileAndGetFileDataPtr(gMapparamText, &gDungeonFileArchive);

    sub_80901D8(&dungLoc, a5);
    dungId = dungLoc.id;
    dungFloor = dungLoc.floor;
    if (dungId > 62) {
        dungId = 62;
    }

    if (dungFloor <= 0) {
        dungFloor = 1;
    }
    if (dungFloor >= GetDungeonFloorCount(dungId)) {
        dungFloor = GetDungeonFloorCount(dungId) - 1;
    }

    strPtr = &((struct UnkDataFileStruct *)(mapParamFile->data))->unk0[dungId][dungFloor];
    r8 = ((struct UnkDataFileStruct *)(mapParamFile->data))->unk4[strPtr->unk0].unk2;

    CloseFile(mapParamFile);

    sprintf(name, gUnknown_811889C, gUnknown_8108EC0[r8]);
    file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
    DecompressATGlobalFile(a2, 0, file);
    CloseFile(file);

    sprintf(name, gUnknown_81188A8, r8);
    *a0 = OpenFile(name, &gDungeonFileArchive);

    sprintf(name, gUnknown_81188B4, gUnknown_8108EC0[r8]);
    file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
    DecompressATFile(a3, 0x1194, file);
    CloseFile(file);

    if (r8 < 64) {
        sprintf(name, gUnknown_81188C0, gUnknown_8108EC0[r8]);
        file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
        DecompressATFile(r10, 0x930, file);
        CloseFile(file);
    }
    else {
        sprintf(name, gUnknown_81188CC, r8, a6);
        file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
        DecompressATFile(r10, 0x240, file);
        CloseFile(file);
    }

    for (i = 0; i < a8; i++) {
        s32 r7 = !IsWaterDungeon(r8) ? 0 : 3;
        for (j = 0; j < a7; j++) {
            a4[(i * a7) + j] = sub_80ADFB8(j, i, a7, a8, a9, r7, r10, r8);
        }
    }

    sprintf(name, gUnknown_81188DC, r8);
    *a1 = OpenFile(name, &gDungeonFileArchive);
    MemoryFree(r10);
}

s32 sub_80ADF8C(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5)
{
    s32 ret = a5;
    if (a0 >= 0 && a1 >= 0 && a0 < a2 && a1 < a3) {
        ret = a4[a0 + (a1 * a2)];
    }
    return ret;
}

s32 sub_80ADFB8(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5, u8 *a6, s32 a7)
{
    s32 id;
    s32 offsets[8];
    u32 mask = 0;
    s32 baseResult = sub_80ADF8C(a0, a1, a2, a3, a4, a5);

    if (a7 >= 64) {
        if (a0 < 24 && a1 < 24) {
            id = a0 + (a1 * 24);
            return a6[id];
        }
        else {
            return a5;
        }
    }

    offsets[0] = sub_80ADF8C(a0 + 0, a1 + 1, a2, a3, a4, a5);
    offsets[1] = sub_80ADF8C(a0 + 1, a1 + 1, a2, a3, a4, a5);
    offsets[2] = sub_80ADF8C(a0 + 1, a1 + 0, a2, a3, a4, a5);
    offsets[3] = sub_80ADF8C(a0 + 1, a1 - 1, a2, a3, a4, a5);
    offsets[4] = sub_80ADF8C(a0 + 0, a1 - 1, a2, a3, a4, a5);
    offsets[5] = sub_80ADF8C(a0 - 1, a1 - 1, a2, a3, a4, a5);
    offsets[6] = sub_80ADF8C(a0 - 1, a1 + 0, a2, a3, a4, a5);
    offsets[7] = sub_80ADF8C(a0 - 1, a1 + 1, a2, a3, a4, a5);
    if (baseResult == 1) {
        mask = 0xFF;
        if (offsets[0] == 0) mask &= ~0x01;
        if (offsets[1] == 0) mask &= ~0x02;
        if (offsets[2] == 0) mask &= ~0x04;
        if (offsets[3] == 0) mask &= ~0x08;
        if (offsets[4] == 0) mask &= ~0x10;
        if (offsets[5] == 0) mask &= ~0x20;
        if (offsets[6] == 0) mask &= ~0x40;
        if (offsets[7] == 0) mask &= ~0x80;
        mask |= 0x200;
    }
    else if (baseResult == 2) {
        mask = 0xFF;
        if (offsets[0] != 2) mask &= ~0x01;
        if (offsets[1] != 2) mask &= ~0x02;
        if (offsets[2] != 2) mask &= ~0x04;
        if (offsets[3] != 2) mask &= ~0x08;
        if (offsets[4] != 2) mask &= ~0x10;
        if (offsets[5] != 2) mask &= ~0x20;
        if (offsets[6] != 2) mask &= ~0x40;
        if (offsets[7] != 2) mask &= ~0x80;
        mask |= 0x100;
    }
    else if (baseResult == 3) {
        mask = 0xFF;
        if (offsets[0] != 3) mask &= ~0x01;
        if (offsets[1] != 3) mask &= ~0x02;
        if (offsets[2] != 3) mask &= ~0x04;
        if (offsets[3] != 3) mask &= ~0x08;
        if (offsets[4] != 3) mask &= ~0x10;
        if (offsets[5] != 3) mask &= ~0x20;
        if (offsets[6] != 3) mask &= ~0x40;
        if (offsets[7] != 3) mask &= ~0x80;
        mask |= 0x100;
    }
    else {
        mask = 0;
        if (offsets[0] == 0) mask |= 0x01;
        if (offsets[1] == 0) mask |= 0x02;
        if (offsets[2] == 0) mask |= 0x04;
        if (offsets[3] == 0) mask |= 0x08;
        if (offsets[4] == 0) mask |= 0x10;
        if (offsets[5] == 0) mask |= 0x20;
        if (offsets[6] == 0) mask |= 0x40;
        if (offsets[7] == 0) mask |= 0x80;
    }

    id = mask * 3;
    return a6[id];
}
