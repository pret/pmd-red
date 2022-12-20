#include "global.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "memory.h"

extern struct unkStruct_203B480 gUnknown_2038C88;
extern struct unkStruct_203B480 *gUnknown_203B480;
extern struct unkStruct_203B484 gUnknown_2039288;
extern struct unkStruct_203B484 *gUnknown_203B484;
extern struct unkStruct_203B48C gUnknown_20393C0;
extern struct unkStruct_203B48C *gUnknown_203B48C;
extern u32 *gUnknown_203B488;
extern u32 gUnknown_20392E8;




void sub_80950BC(void)
{
    gUnknown_203B480 = &gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = &gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

struct unkStruct_203B480 *sub_80950F8(void)
{
    return &gUnknown_2038C88;
}

struct unkStruct_203B484 *sub_8095100(void)
{
    return &gUnknown_2039288;
}

u32 *sub_8095108(void)
{
    return &gUnknown_20392E8;
}

struct unkStruct_203B48C *sub_8095110(void)
{
    return &gUnknown_20393C0;
}


void sub_8095118(void)
{
  s32 iVar1;
  struct unkStruct_203B480 *unused;
  
  MemoryFill8((u8*)gUnknown_203B480,0,0x600);
  MemoryFill8((u8*)gUnknown_203B484,0,0x5c);
  for(iVar1 = 0; iVar1 < 0x20; iVar1++){

    // NOTE: we use a temp variable here to force the match
    unused = &gUnknown_203B480[iVar1];
    gUnknown_203B480[iVar1].mailType = 0;
    unused = &gUnknown_203B480[iVar1];
    gUnknown_203B480[iVar1].unk22 = 0;
    unused = &gUnknown_203B480[iVar1];
    gUnknown_203B480[iVar1].unk2D = 0;
  }
  gUnknown_203B48C->unk0 = 0;
  for(iVar1 = 0; iVar1 < 0x20; iVar1++){
    gUnknown_203B48C->unk4[iVar1] = -1;
  }
}

void nullsub_206(void)
{
}

void nullsub_207(void)
{
}

s32 sub_8095190(void)
{
  int index;
  
  for(index = 2; index < 0x20; index++){
    if(gUnknown_203B480[index].mailType == 0)
        return index;
  }
  return -1;
}
