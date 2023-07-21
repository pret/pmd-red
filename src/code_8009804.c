#include "global.h"
#include "file_system.h"

extern u8 gUnknown_202D238[4];
extern s32 gUnknown_202D23C;
extern u16 gUnknown_202B038[4][32][32];
extern u8 gUnknown_80B88CC[];
struct FileArchive gSystemFileArchive;

struct unkStruct_202D240
{
    u32 *unk0;
    u32 *unk4;
    u32 size;
};
extern struct unkStruct_202D240 gUnknown_202D240[8];

struct unkStruct_202D038
{
     // size: 0x40
     u32 unk0[0x10];
};

extern struct unkStruct_202D038 gUnknown_202D038[8];

extern void CpuCopy(void* dest, void *src, s32 size);
extern void SetBGPaletteBufferColorArray(s32 index, void *colorArray);
extern void sub_8009A1C(u32);
u32 sub_80063B0(void);

void sub_80097B0(void)
{
    struct OpenedFile *fontpalFile;
    s32 index;
    u32 *ptr;

    fontpalFile = OpenFileAndGetFileDataPtr(gUnknown_80B88CC,&gSystemFileArchive); // fontpal
    CpuCopy(gUnknown_202D038, fontpalFile->data, sizeof(gUnknown_202D038));
    if (sub_80063B0() == 1) {
        ptr = &gUnknown_202D038[0].unk0[0];
    }
    else
    {
        ptr = &gUnknown_202D038[1].unk0[0];
    }
    for(index = 0; index < 0x10; ptr++, index++)
    {
        SetBGPaletteBufferColorArray(index + 0xf0, ptr);
    }
    CloseFile(fontpalFile);
}

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
  
  for(index = 0; index < gUnknown_202D23C; index++)
  {
      CpuCopy(gUnknown_202D240[index].unk0, gUnknown_202D240[index].unk4, gUnknown_202D240[index].size);
  }
  gUnknown_202D23C = 0;
  if (gUnknown_202D238[0] != 0) {
    gUnknown_202D238[0] = 0;
    CpuCopy(BG_SCREEN_ADDR(12), gUnknown_202B038[0], BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[1] != 0) {
    gUnknown_202D238[1] = 0;
    CpuCopy(BG_SCREEN_ADDR(13), gUnknown_202B038[1], BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[2] != 0) {
    gUnknown_202D238[2] = 0;
    CpuCopy(BG_SCREEN_ADDR(14), gUnknown_202B038[2], BG_SCREEN_SIZE);
  }
  if (gUnknown_202D238[3] != 0) {
    gUnknown_202D238[3] = 0;
    CpuCopy(BG_SCREEN_ADDR(15), gUnknown_202B038[3], BG_SCREEN_SIZE);
  }
}

void sub_80099C0(void)
{
    CpuCopy(BG_SCREEN_ADDR(12), gUnknown_202B038[0], BG_SCREEN_SIZE);
    CpuCopy(BG_SCREEN_ADDR(13), gUnknown_202B038[1], BG_SCREEN_SIZE);
}

void sub_80099F0(u32 r0)
{
    s32 iVar2;
    for(iVar2 = 0; iVar2 < 8; iVar2++)
    {
        gUnknown_202D038[iVar2].unk0[1] = r0;
    }
}

void sub_8009A10(u32 *r0)
{
    sub_8009A1C(r0[1]);
}
