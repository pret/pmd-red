#include "global.h"
#include "code_800DAC0.h"
#include "file_system.h"
#include "memory.h"

struct unkStruct_203B0CC_sub
{
    // size: 0xD0
    u32 unk0;
    s32 unk4;
    u8 fill8[0x34 - 8];
    u32 unk34;
    u32 unk38;
    u8 fill3C[0x4C - 0x3C];
    u32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 fill55[0xB8 - 0x55];
    u32 unkB8;
    u8 fillBC[0xD0 - 0xBC];
};

struct unkStruct_203B0CC
{
    // size: 0x1A18
    struct unkStruct_203B0CC_sub unk0[0x20];
    u32 unk1A00;
    /* 0x1A04 */ u32 fileSelection;
    u32 unk1A08;
    u32 unk1A0C;
    u32 unk1A10;
    u8 fill1A14[0x1A18 - 0x1A14];
};

struct unkStruct_203B0CC *gUnknown_203B0CC;

struct unkStruct_800F18C
{
    u32 unk0;
    u32 unk4;
};

extern s32 sub_800E2C0(void);
extern s32 sub_8000728(void);
extern u32 sub_800E900(void);
extern void sub_8009BE4(void);
extern void sub_8040238(void);
extern void sub_800F204(void);
extern void sub_803EAF0(u32, u32);
extern void sub_800CD64(u32, u32);
extern struct unkStruct_800F18C *sub_800F18C(s32);
extern void sub_800DCA8(struct unkStruct_203B0CC_sub *);
extern void PlaySound(u16);

extern u8 gefob000_string[];
extern u8 gefob001_string[];
extern struct FileArchive gEffectFileArchive;

extern void sub_8005610(struct OpenedFile *, u32, u32,u32);
extern void sub_800DB7C(void);
extern void sub_800F034(void);
extern void sub_800ED38(u32);
extern void sub_800DC14(void);
extern void sub_800F078();
extern void sub_800ED64();
extern void sub_800ED80();
extern void sub_800F094();

void sub_800DAC0(u32 fileSelection)
{
  s32 index;
  struct OpenedFile *filePtr;
  struct unkStruct_203B0CC_sub *preload;
  
  if (gUnknown_203B0CC != NULL) {
    sub_800DB7C();
  }
  gUnknown_203B0CC = MemoryAlloc(sizeof(struct unkStruct_203B0CC), 0xb);
  MemoryClear8((u8 *)gUnknown_203B0CC, sizeof(struct unkStruct_203B0CC));
  gUnknown_203B0CC->fileSelection = fileSelection;
  for(index = 0, preload = &gUnknown_203B0CC->unk0[index]; index < 0x20; index++, preload++)
  {
    preload->unk4 = -1;
  }
  sub_800ED38(fileSelection);
  sub_800F034();

  switch(gUnknown_203B0CC->fileSelection)
  {
      case 1:
        filePtr = Call_OpenFileAndGetFileDataPtr(gefob001_string, &gEffectFileArchive);
        if (filePtr != NULL) {
            sub_8005610(filePtr,0x248,0x1f,0);
            CloseFile(filePtr);
        }
        break;
      case 0:
        filePtr = Call_OpenFileAndGetFileDataPtr(gefob000_string, &gEffectFileArchive);
        if (filePtr != NULL) {
            sub_8005610(filePtr,0x248,0x1f,0);
            CloseFile(filePtr);
        }
        break;
  }
}

void sub_800DB7C(void)
{
  s32 index;
  struct unkStruct_203B0CC_sub *preload;
  
  for(index = 0, preload = &gUnknown_203B0CC->unk0[index]; index < 0x20; index++, preload++)
  {
    if(preload->unk4 != -1)
        sub_800DC14();
  }


  sub_800F078();
  sub_800ED64();
  if(gUnknown_203B0CC != NULL)
  {
    MemoryFree(gUnknown_203B0CC);
    gUnknown_203B0CC = NULL;
  }
}

void sub_800DBBC(void)
{
  s32 index1;
  s32 index2;
  struct unkStruct_203B0CC_sub *preload;
  struct unkStruct_203B0CC_sub *preload2;
  
  for(index1 = 0, preload = &gUnknown_203B0CC->unk0[index1]; index1 < 0x20; index1++, preload++)
  {
    if(preload->unk4 != -1)
        sub_800DC14();
  }


  for(index2 = 0, preload2 = &gUnknown_203B0CC->unk0[index2]; index2 < 0x20; index2++, preload2++)
  {
    preload2->unk4 = -1;
  }
  sub_800ED80();
  sub_800F094();
}

bool8 sub_800DCC0(void)
{
  return gUnknown_203B0CC != NULL;
}

void sub_800DC14(void)
{
  s32 index1;
  s32 index2;
  struct unkStruct_800F18C *piVar3;
  struct unkStruct_800F18C *puVar4;
  struct unkStruct_203B0CC_sub *preload;
  
  index1 = sub_800E2C0();
  if (index1 != -1) {
    preload = &gUnknown_203B0CC->unk0[index1];
    if (preload->unk34 == 4) {
      sub_8009BE4();
      if (sub_8000728() == 1) {
        sub_8040238();
        sub_803EAF0(0,0);
        sub_800CD64(0x8000,0);
      }
    }
    if (preload->unk34 == 3) {
      for (index2 = 0; index2 < 2; index2 = index2 + 1) {
        piVar3 = sub_800F18C(index2);
        if (piVar3->unk0 == preload->unk38) {
          piVar3->unk4--;
          break;
        }
      }
    }
    else {
      puVar4 = sub_800F18C(1);
      puVar4->unk4  = 0;
      puVar4->unk0  = 0xffffffff;
    }
    sub_800DCA8(preload);
  }
}

u32 sub_800DC9C(void) {
    return sub_800E900();
}

void sub_800DCA8(struct unkStruct_203B0CC_sub *param_1)
{
    param_1->unk4 = -1;
    param_1->unk54 = 0;
    if(param_1->unkB8 != 0)
    {
        sub_800F204();
        param_1->unkB8 = 0;
    }
}

void sub_800DCD0(struct unkStruct_203B0CC_sub *param_1)
{
  if ((param_1->unk4C != -1) && (param_1->unk50 == 0)) {
    if (sub_8000728() != 2) {
      PlaySound(param_1->unk4C);
    }
    param_1->unk4C = -1;
    param_1->unk50 = -1;
  }
  if (param_1->unk50 > 0) {
   param_1->unk50--;
  }
}
