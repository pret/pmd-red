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
    u8 unk4[0x1F0 - 0x4];
};

struct unkStruct_3001B84
{
    struct unkStruct_3001B84_sub array[0x18];
};

IWRAM_INIT struct unkStruct_3001B84 *gGroundLives = NULL;

extern void DeleteGroundLives(void);
void GroundLives_Delete(s32);

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
