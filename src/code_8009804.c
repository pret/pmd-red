#include "global.h"

extern u8 gUnknown_202D238[4];

extern s32 gUnknown_202D23C;
extern u16 gUnknown_202B038[2][32][32];
extern u8 gUnknown_202B838[0x800];
extern u8 gUnknown_202C038[0x800];
extern u8 gUnknown_202C838[0x720];

struct unkStruct_202D240
{
    u32 *unk0;
    u32 *unk4;
    u32 size;
};
extern struct unkStruct_202D240 gUnknown_202D240[8];

extern void CpuCopy(void* dest, void *src, s32 size);

void vram_related_8009804(void)
{
    u32 counter;
    u32 *r1;

    r1 = (u32 *) VRAM;
    for(counter = 0; counter < 0x13C0; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) 0x06007000;
    for(counter = 0; counter < 0x400; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) 0x06008000;
    for(counter = 0; counter < 0x2000; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OBJ_VRAM0;
    for(counter = 0; counter < 0x1f80; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) PLTT;
    for(counter = 0; counter < 120; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OBJ_PLTT;
    for(counter = 0; counter < 120; counter++)
    {
        *r1++ = 0;
    }
    r1 = (u32 *) OAM;
    for(counter = 0; counter < 256; counter++)
    {
        *r1++ = 0xa000a0;
    }
}

void sub_80098A0(void)
{
    gUnknown_202D23C = 0;
    gUnknown_202D238[0] = 0;
    gUnknown_202D238[1] = 0;
    gUnknown_202D238[2] = 0;
    gUnknown_202D238[3] = 0;
}

void sub_80098BC(u32 *r0, u32 *r1, u32 r2)
{
    if(gUnknown_202D23C < 8){
        gUnknown_202D240[gUnknown_202D23C].unk0 = r0;
        gUnknown_202D240[gUnknown_202D23C].unk4 = r1;
        gUnknown_202D240[gUnknown_202D23C].size = r2;
        gUnknown_202D23C++;
    }
}

void sub_80098F8(u32 r0)
{
    gUnknown_202D238[r0] = 1;
}

void sub_8009908(void)
{
  s32 index;
  u32 iVar3;
  
  index = 0;
  if (index < gUnknown_202D23C) {
    iVar3 = 0;
    do {
      CpuCopy(gUnknown_202D240[index].unk0,gUnknown_202D240[index].unk4,gUnknown_202D240[index].size);
      iVar3 += sizeof(struct unkStruct_202D240);
      index++;
    } while (index < gUnknown_202D23C);
  }
  gUnknown_202D23C = 0;
  if (gUnknown_202D238[0] != 0) {
    gUnknown_202D238[0] = 0;
    CpuCopy(BG_SCREEN_ADDR(12),gUnknown_202B038, BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[1] != 0) {
    gUnknown_202D238[1] = 0;
    CpuCopy(BG_SCREEN_ADDR(13),gUnknown_202B838, BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[2] != 0) {
    gUnknown_202D238[2] = 0;
    CpuCopy(BG_SCREEN_ADDR(14),gUnknown_202C038, BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[3] != 0) {
    gUnknown_202D238[3] = 0;
    CpuCopy(BG_SCREEN_ADDR(15),gUnknown_202C838, BG_SCREEN_SIZE);
  }
}

void sub_80099C0(void)
{
  CpuCopy(BG_SCREEN_ADDR(12),gUnknown_202B038, BG_SCREEN_SIZE);
  // TODO shouldn't this be 202B838? It didn't match... might need raw address
  CpuCopy(BG_SCREEN_ADDR(13),gUnknown_202B038 + 0x1, BG_SCREEN_SIZE);
}
