#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "constants/species.h"
#include "memory.h"

struct unkData
{
    u8 unk0[24];
};

struct unkStruct_203B318
{
    // size: 0xcc
    u32 unk0;
    u32 unk4;
    s32 state;
    u8 fillC[0x10 - 0xC];
    s16 unk10;
    u8 fill[0x58 - 0x12];
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk60;
    u16 unk62;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    struct OpenedFile** unk68;
    struct unkData unk6C[4];
};

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern struct unkStruct_203B318 *gUnknown_203B318;
extern struct unkData gUnknown_80E0760;

extern void sub_800641C(struct unkData *, u32, u32);
extern void sub_8006518(struct unkData *);

extern void sub_8030208();
extern void sub_8030258();
extern void sub_80302A8();
extern void sub_80302C4();
extern void UpdateMakuhitaDialogue();

void UpdateMakuhitaState(s32);
void sub_802FF1C();

u32 CreateMakuhitaShop(u32 param_1)
{
  char *monName;
  struct OpenedFile *faceFile;
  u32 initialState;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B318 = MemoryAlloc(sizeof(struct unkStruct_203B318),8);
  gUnknown_203B318->unk10 = -1;
  gUnknown_203B318->unk0 = param_1;
  switch(param_1) {
      case 0:
        initialState = 0;
        gUnknown_203B318->unk4 = 0;
        break;
      case 1:
        initialState = 7;
        gUnknown_203B318->unk4 = 0;
        break;
      case 2:
        initialState = 6;
        gUnknown_203B318->unk4 = 0;
        break;
      case 3:
        initialState = 8;
        gUnknown_203B318->unk4 = 0;
        break;
      case 4:
        initialState = 0;
        gUnknown_203B318->unk4 = 1;
        break;
      case 5:
        initialState = 7;
        gUnknown_203B318->unk4 = 1;
        break;
      case 6:
        initialState = 6;
        gUnknown_203B318->unk4 = 1;
        break;
      case 7:
      default:
        initialState = 8;
        gUnknown_203B318->unk4 = 1;
        break;
  }
  if (gUnknown_203B318->unk4 == 1) {
    gUnknown_203B318->unk68 = NULL;
  }
  else {
    gUnknown_203B318->unk68 = &gUnknown_203B318->faceFile;
  }
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8,SPECIES_MAKUHITA);
  CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8,SPECIES_MAKUHITA);
  monName = GetMonSpecies(SPECIES_MAKUHITA);
  strcpy(gUnknown_202E1C8 - 0x50, monName);
  faceFile = GetDialogueSpriteDataPtr(SPECIES_MAKUHITA);
  gUnknown_203B318->faceFile = faceFile;
  gUnknown_203B318->faceData = faceFile->data;
  gUnknown_203B318->unk64 = 0;
  gUnknown_203B318->unk65 = 0;
  gUnknown_203B318->unk66 = 0;
  gUnknown_203B318->unk60 = 2;
  gUnknown_203B318->unk62 = 8;
  UpdateMakuhitaState(initialState);
  return 1;
}

u32 sub_802FE58(void)
{
  
  switch(gUnknown_203B318->state) {
    case 0:
    case 1:
        sub_8030208();
        break;
    case 4:
        sub_8030258();
        break;
    case 11:
        sub_80302A8();
        break;
    case 13:
        return 3;
    default:
        sub_80302C4();
        break;
  }
    return 0;
}

s16 sub_802FED0(void)
{
    return gUnknown_203B318->unk10;
}

void CleanMakuhitaShop(void)
{
    if(gUnknown_203B318 != NULL)
    {
        CloseFile(gUnknown_203B318->faceFile);
        MemoryFree(gUnknown_203B318);
        gUnknown_203B318 = NULL;
    }
}

void UpdateMakuhitaState(s32 newState)
{
    gUnknown_203B318->state = newState;
    sub_802FF1C();
    UpdateMakuhitaDialogue();
}

void sub_802FF1C(void)
{
    s32 iVar3;
    sub_8006518(gUnknown_203B318->unk6C);
    switch(gUnknown_203B318->state)
    {
        case 0:
        case 4:
        case 13:
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B318->unk6C[iVar3] = gUnknown_80E0760;
            }
            break;
        default:
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B318->unk6C, 1, 1);
}
