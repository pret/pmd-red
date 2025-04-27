#include "global.h"
#include "memory.h"

struct GroundEvent_sub
{
    s16 unk0;
    s16 unk2;
    u8 unk4[0x20 - 0x4];
};

struct GroundEvents
{
    // size: 0x400
    struct GroundEvent_sub arr[0x20];
};

IWRAM_INIT struct GroundEvents *gGroundEvents = NULL;

void DeleteGroundEvents(void);
void GroundEvent_Delete(s32);

void AllocGroundEvents(void) {
    s32 ind;
    struct GroundEvent_sub *ptr;
    gGroundEvents = MemoryAlloc(sizeof(struct GroundEvents), 0x6);

    for(ind = 0, ptr = &gGroundEvents->arr[ind]; ind < 0x20; ind = (s16)(ind + 1), ptr++)
    {
        ptr->unk2 |= -1;
    }
    DeleteGroundEvents();
}

void DeleteGroundEvents(void) {
    s32 v1;
    struct GroundEvent_sub* current;
    
    current = &gGroundEvents->arr[0];
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

