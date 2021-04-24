#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "constants/species.h"

struct unkStruct_203B208
{
    // size: 0x14C
    u32 unk0;
    u32 currState;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u8 fill24[0xD8 - 0x24];
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unkE0;
    u16 unkE2;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    u8 unkE7;
    struct OpenedFile **unkE8;
};
extern struct unkStruct_203B208 *gUnknown_203B208;

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern void *MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void sub_800641C(u32 *, u32, u32);
extern void UpdateKangaskhanStorageState(u32);

extern void sub_8017828();
extern void sub_8017AF8();
extern void sub_8017C7C();
extern void sub_8017DC0();
extern void sub_80178D0();
extern void sub_80179A8();
extern void sub_8017B88();
extern void sub_8017C28();
extern void sub_8017D24();
extern void sub_8017DDC();
extern void sub_8017928();
extern void sub_8017A1C();
extern void sub_8017DF8();
extern void sub_8016E80();
extern void sub_8016FF8();


u32 DisplayKangaskhanDialogueSprite(s32 param_1)
{
  char *monName;
  struct OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B208 = MemoryAlloc(0x14c,8);
  gUnknown_203B208->unk18 = 0;
  gUnknown_203B208->unk1C = 0;
  gUnknown_203B208->unk20 = 0;
  gUnknown_203B208->unk0 = param_1;
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_KANGASKHAN);
  CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8, SPECIES_KANGASKHAN);
  monName = GetMonSpecies(SPECIES_KANGASKHAN);
  strcpy(gUnknown_202E1C8 - 0x50, monName);
  if (gUnknown_203B208->unk0 == 1) {
    gUnknown_203B208->unkE8 = 0;
  }
  else {
    gUnknown_203B208->unkE8 = &gUnknown_203B208->faceFile;
  }
  faceFile = GetDialogueSpriteDataPtr(SPECIES_KANGASKHAN);
  gUnknown_203B208->faceFile = faceFile;
  gUnknown_203B208->faceData = faceFile->data;
  gUnknown_203B208->unkE4 = 0;
  gUnknown_203B208->unkE5 = 0;
  gUnknown_203B208->unkE6 = 0;
  gUnknown_203B208->unkE0 = 2;
  gUnknown_203B208->unkE2 = 8;
  UpdateKangaskhanStorageState(0);
  return 1;
}

u32 sub_8016D54(void)
{ 
  switch(gUnknown_203B208->currState) {
    case 0:
    case 1:
        sub_8017828();
        break;
    case 0xd:
    case 0xe:
        sub_8017AF8();
        break;
    case 0xf:
        sub_8017C7C();
        break;
    case 0x10:
        sub_8017DC0();
        break;
    case 0x11:
        sub_80178D0();
        break;
    case 0x12:
        sub_80179A8();
        break;
    case 0x16:
    case 0x17:
        sub_8017B88();
        break;
    case 0x18:
        sub_8017C28();
        break;
    case 0x19:
        sub_8017D24();
        break;
    case 0x1a:
        sub_8017DDC();
        break;
    case 0x1b:
        sub_8017928();
        break;
    case 0x1c:
        sub_8017A1C();
        break;
    case 4:
        return 3;
    default:
        sub_8017DF8();
        break;
  }
    return 0;
}

void sub_8016E40(void)
{
    if(gUnknown_203B208 != NULL)
    {
        CloseFile(gUnknown_203B208->faceFile);
        MemoryFree(gUnknown_203B208);
        gUnknown_203B208 = NULL;
    }
}

void UpdateKangaskhanStorageState(u32 newState)
{
    gUnknown_203B208->currState = newState;
    sub_8016E80();
    sub_8016FF8();
}
