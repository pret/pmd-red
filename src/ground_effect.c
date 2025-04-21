#include "global.h"
#include "memory.h"

void DeleteGroundEffects(void);

// size must be 0x1c4
struct unkStruct_3001B8C {
    u8 fill0[6];
    s16 unk6;
    u8 fill8[0x1c4 - 8];
};

IWRAM_INIT struct unkStruct_3001B8C* gGroundEffects = NULL;  // size 16 array
void GroundEffect_Delete(s32);

void AllocGroundEffects()
{
    s32 index;
    struct unkStruct_3001B8C* current;
    
    gGroundEffects = MemoryAlloc(16 * sizeof(struct unkStruct_3001B8C), 6);
    current = gGroundEffects;
    for (index = 0; index < 16; index = (s16) (index + 0x1), current++) {    
        current->unk6 = -1;
    }
    DeleteGroundEffects();
}


void DeleteGroundEffects(void)
{
    s32 index;
    struct unkStruct_3001B8C* current;
    
    current = gGroundEffects;
    for (index = 0; index < 16; index = (s16) (index + 0x1), current++) {    
        if(current->unk6 != -1)
            GroundEffect_Delete(index);
    }
}

void FreeGroundEffects(void)
{
    DeleteGroundEffects();
    MemoryFree(gGroundEffects);
    gGroundEffects = NULL;
}
