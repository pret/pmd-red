#include "global.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "debug.h"
#include "memory.h"

void DeleteGroundEffects(void);

// size must be 0x1c4
typedef struct GroundEffect {
    u8 fill0[6];
    s16 unk6;
    s16 unk8;
    s8 unkA;
    u8 fillB[0x14 - 0xB];
    s32 unk14; // some x?
    s32 unk18; // some y?
    u8 fill1C[0x124 - 0x1C];
    PixelPos unkPixelPos; // 0x124
    u8 fill12C[0x144 - 0x12C];
    struct UnkGroundSpriteStruct unk144;
} GroundEffect;

IWRAM_INIT GroundEffect* gGroundEffects = NULL;  // size 16 array
void GroundEffect_Delete(s32);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
extern DebugLocation gUnknown_8118610;
extern u8 gUnknown_811861C[];
extern u8 gUnknown_8118640[];
s16 GroundEffect_Add(s32 id, const GroundEffectData*, s32 group, s32 sector);

void AllocGroundEffects()
{
    s32 index;
    GroundEffect* current;
    
    gGroundEffects = MemoryAlloc(16 * sizeof(GroundEffect), 6);
    current = gGroundEffects;
    for (index = 0; index < 16; index = (s16) (index + 0x1), current++) {    
        current->unk6 = -1;
    }
    DeleteGroundEffects();
}


void DeleteGroundEffects(void)
{
    s32 index;
    GroundEffect* current;
    
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

void GroundEffect_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundEffectData *effectData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_8118610);
    Log('\0',gUnknown_811861C, scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    effectData = sectorPtr->effects;

    size = sectorPtr->nEffects;
    for (i = 0; i < size; i++, effectData++)
    {
        GroundEffect_Add(-1,effectData,group_s32,sector_s32);
    }
}

void GroundEffect_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundEffect *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gUnknown_8118640, scriptID_s32);

    index = 0;
    ptr = &gGroundEffects[0];
    for(; index < 16; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk6 != -1) && (ptr->unk8 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unkA == sector_s32)
                GroundEffect_Delete(index);
    }
}

extern const char gUnknown_8118658[];

void GroundEffect_CancelBlank()
{
    s32 index;
    GroundEffect *ptr;
    PixelPos pos;

    Log(0, gUnknown_8118658); // "GroundEffect CancelBlank"

    index = 0;
    ptr = &gGroundEffects[0];
    for (; index < 16; index = (s16)(index + 1), ptr++)
    {
        if (ptr->unk6 != -1)
        {
            pos.x = ptr->unkPixelPos.x + ptr->unk14;
            pos.y = ptr->unkPixelPos.y + ptr->unk18;
            if (!IsOnscreen_80A675C(&ptr->unk144, &pos))
            {
                GroundEffect_Delete(index);
            }
        }
    }
}
