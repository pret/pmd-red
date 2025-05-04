#include "global.h"
#include "ground_script.h"
#include "memory.h"

struct GroundLivesMeta_Sub1
{
    // size: 0xC
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct unkStruct_3001B80
{
    // size: 0x338
   struct GroundLivesMeta_Sub1 unk0[3];
    u32 unk24;
    u8 unk28;
    struct GroundLivesMeta_Sub1 unk2C[0x40];
    ScriptInfoSmall unk32C;
};
IWRAM_INIT struct unkStruct_3001B80 *gGroundLivesMeta = NULL;

struct unkStruct_3001B84_sub
{
    // size: 0x1F0
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s8 unk6;
    u8 unk8[0x1F0 - 0x8];
};

struct unkStruct_3001B84
{
    struct unkStruct_3001B84_sub array[0x18];
};

IWRAM_INIT struct unkStruct_3001B84 *gGroundLives = NULL;

extern void DeleteGroundLives(void);
void GroundLives_Delete(s32);
s16 GroundLives_Add(s32 id, const GroundLivesData*, s32 group, s32 sector);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
extern DebugLocation gUnknown_811808C;
extern u8 gUnknown_8118098[];
extern u8 gUnknown_81180BC[];

void AllocGroundLives(void)
{
    s32 index;
    struct unkStruct_3001B84_sub *ptr;

    gGroundLivesMeta = MemoryAlloc(sizeof(struct unkStruct_3001B80),6);
    gGroundLives = MemoryAlloc(sizeof(struct unkStruct_3001B84),6);

    for(index = 0, ptr = &gGroundLives->array[index]; index < 0x18; index = (s16)(index + 1), ptr++)
    {
        ptr->unk2 = -1;
    }
    GetFunctionScript(0,&gGroundLivesMeta->unk32C,0x19);
    gGroundLivesMeta->unk32C.state = 1;
    DeleteGroundLives();
}


void DeleteGroundLives(void)
{
  int index;
  struct unkStruct_3001B84_sub *iVar4;
  struct GroundLivesMeta_Sub1 *ptr;

    
  iVar4 = &gGroundLives->array[0];
  for(index = 0; index < 0x18; index = (s16)(index + 1), iVar4++)
  {
    if (iVar4->unk2 != -1) {
      GroundLives_Delete(index);
    }
  }
    
  gGroundLivesMeta->unk24 = -1;  
  gGroundLivesMeta->unk28 = -1;

  
  for(index = 0; index < 3; ptr++, index++)
  {
      ptr = &gGroundLivesMeta->unk0[index];
      ptr->unk8 = -1;
      ptr->unk0 = 0;
      ptr->unk4 = 0;
  }
    

  for(index = 0; index < 0x40; ptr++, index++)
  {
     ptr = &gGroundLivesMeta->unk2C[index];
      ptr->unk0 = 0;
      ptr->unk4 = 0;
      ptr->unk8 = 0;
  }
}

void FreeGroundLives(void)
{
    DeleteGroundLives();
    MemoryFree(gGroundLives);
    gGroundLives = NULL;
    MemoryFree(gGroundLivesMeta);
    gGroundLivesMeta = NULL;
}

void GroundLives_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundLivesData *livesData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_811808C);
    Log('\0',gUnknown_8118098, scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    livesData = sectorPtr->lives;

    size = sectorPtr->nLives;
    for (i = 0; i < size; i++, livesData++)
    {
        GroundLives_Add(-1,livesData,group_s32,sector_s32);
    }
}

void GroundLives_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    struct unkStruct_3001B84_sub *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gUnknown_81180BC, scriptID_s32, sector_s32);

    index = 0;
    ptr = &gGroundLives->array[0];
    for(; index < 0x18; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk2 != -1) && (ptr->unk4 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unk6 == sector_s32)
                GroundLives_Delete(index);
    }
}
