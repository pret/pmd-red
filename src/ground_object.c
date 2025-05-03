#include "global.h"
#include "ground_script.h"
#include "memory.h"

typedef struct GroundObject {
    // size: 0x1C4
    u8 unk0[6];
    s16 unk6;
    u8 fill8[0x1C4 - 8];
} GroundObject;

IWRAM_INIT GroundObject *gGroundObjects = NULL;

void DeleteGroundObjects(void);
void GroundObject_Delete(s32);

extern u8 gUnknown_81183F0[];
s16 GroundObject_Add(s32 id, const GroundObjectData*, s32 group, s32 sector);
extern DebugLocation gUnknown_81183E4;
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);

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
    const GroundObjectData *effectData;
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
    effectData = sectorPtr->objects;

    size = sectorPtr->nObjects;
    for (i = 0; i < size; i++, effectData++)
    {
        GroundObject_Add(-1,effectData,group_s32,sector_s32);
    }
}

