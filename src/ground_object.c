#include "global.h"
#include "ground_script.h"
#include "memory.h"

typedef struct GroundObject {
    // size: 0x1C4
    u8 unk0[4];
    s16 unk4;
    s16 unk6; // kind
    s16 unk8; // scriptID / group
    s8 unkA; // sector
    u8 fillB[0x14 - 0xB];
    u32 unk14;
    u32 unk18;
    u8 fill1C[0x38 - 0x1C];
    Action unk38;
    u8 unk11C[0x124 - 0x11C];
    u32 unk124[2];
    u8 unk12C[0x144 - 0x12C];
    u8 unk144[0x1C4 - 0x144];
} GroundObject;

IWRAM_INIT GroundObject *gGroundObjects = NULL;

void DeleteGroundObjects(void);
void GroundObject_Delete(s32);

extern u8 gUnknown_811842C[];
extern u8 gUnknown_8118414[];
extern u8 gUnknown_81183F0[];
s16 GroundObject_Add(s32 id, const GroundObjectData*, s32 group, s32 sector);
extern DebugLocation gUnknown_81183E4;
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
bool8 IsOnscreen_80A675C(u8 *, u32 *);

void AllocGroundObjects(void) 
{

    GroundObject *ptr;
    s32 index;

    gGroundObjects = MemoryAlloc(sizeof(GroundObject) * 0x10, 6);
   
    for(index = 0,  ptr = &gGroundObjects[index]; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        ptr->unk6 |= -1;
    }
    DeleteGroundObjects();
}

void DeleteGroundObjects(void)
{
    GroundObject *ptr;
    s32 index;
    
    ptr = &gGroundObjects[0];
    for(index = 0; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 != -1)
            GroundObject_Delete(index);
    }
}

void FreeGroundObjects(void)
{
    DeleteGroundObjects();
    MemoryFree(gGroundObjects);
    gGroundObjects = NULL;
}

void GroundObject_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundObjectData *objectData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_81183E4);
    Log('\0',gUnknown_81183F0, scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    objectData = sectorPtr->objects;

    size = sectorPtr->nObjects;
    for (i = 0; i < size; i++, objectData++)
    {
        GroundObject_Add(-1,objectData,group_s32,sector_s32);
    }
}

void GroundObject_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundObject *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gUnknown_8118414, scriptID_s32);

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk6 != -1) && (ptr->unk8 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unkA == sector_s32)
                GroundObject_Delete(index);
    }
}

void GroundObject_CancelBlank(void)
{
    s32 index;
    GroundObject *ptr;
    u32 stack[2];

    Log('\0',gUnknown_811842C);

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 != -1)
        {
            stack[0] = ptr->unk124[0] + ptr->unk14;
            stack[1] = ptr->unk124[1] + ptr->unk18;
            if(!IsOnscreen_80A675C(ptr->unk144, stack))
                GroundObject_Delete(index);
        }
    }
}

s32 sub_80ABD48(s32 r0)
{
    s32 index;
    GroundObject *ptr;

    s32 r0_s32 = (s16)r0;

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 == r0_s32) return index;
    }

    return -1;
}
