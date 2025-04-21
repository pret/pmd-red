#include "global.h"
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

void AllocGroundObjects(void) 
{

    GroundObject *ptr;
    s32 index;

    gGroundObjects = MemoryAlloc(0x1C40, 6);
   
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
