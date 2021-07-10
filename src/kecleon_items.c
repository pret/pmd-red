#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kecleon_items.h"
#include "memory.h"

extern struct unkStruct_203B210 *gUnknown_203B210;
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern struct UnkTextStruct2 gUnknown_80DB840;
extern struct UnkTextStruct2 gUnknown_80DB870;
extern struct UnkTextStruct2 gUnknown_80DB888;
extern struct UnkTextStruct2 gUnknown_80DB858;

void UpdateKecleonStoreState(u32);

extern void sub_8019730();
extern void sub_80199CC();
extern void sub_8019B08();
extern void sub_8019BBC();
extern void sub_8019C78();
extern void sub_8019850();
extern void sub_80198E8();
extern void sub_8019944();
extern void sub_8019D30();
extern void sub_8019D4C();
extern void sub_8019D68();
extern void sub_8018D30();
extern void UpdateKecleonStoreDialogue();

u32 DisplayKeckleonDialogueSprite(u32 param_1)
{
  char *monName;
  struct OpenedFile *faceFile;
  
  gUnknown_203B210 = MemoryAlloc(sizeof(struct unkStruct_203B210),8);
  gUnknown_203B210->unk28 = 0;
  gUnknown_203B210->unk2C = 0;
  gUnknown_203B210->unk30 = 0;
  gUnknown_203B210->unk0 = param_1;
  switch(param_1)
  {
      case 0:
        gUnknown_203B210->unk4 = TRUE;
        gUnknown_203B210->unkE4 = &gUnknown_203B210->faceFile;
        CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_KECLEON);
        CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8, SPECIES_KECLEON);
        monName = GetMonSpecies( SPECIES_KECLEON);
        strcpy(gUnknown_202E1C8 - 0x50, monName);
        break;
      case 1:
        gUnknown_203B210->unk4 = TRUE;
        gUnknown_203B210->unkE4 = NULL;
        CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_KECLEON);
        CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8, SPECIES_KECLEON);
        monName = GetMonSpecies( SPECIES_KECLEON);
        strcpy(gUnknown_202E1C8 - 0x50, monName);
        break;
      case 2:
        gUnknown_203B210->unk4 = FALSE;
        gUnknown_203B210->unkE4 = &gUnknown_203B210->faceFile;
        CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_KECLEON);
        CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8, SPECIES_KECLEON);
        monName = GetMonSpecies( SPECIES_KECLEON);
        strcpy(gUnknown_202E1C8 - 0x50, monName);
        break;
      case 3:
        gUnknown_203B210->unk4 = FALSE;
        gUnknown_203B210->unkE4 = NULL;
        CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_KECLEON);
        CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8, SPECIES_KECLEON);
        monName = GetMonSpecies( SPECIES_KECLEON);
        strcpy(gUnknown_202E1C8 - 0x50, monName);
        break;
      default:
        break;
  }
  faceFile = GetDialogueSpriteDataPtr(SPECIES_KECLEON);
  gUnknown_203B210->faceFile = faceFile;
  gUnknown_203B210->unkD8 = faceFile->data;
  gUnknown_203B210->unkE0 = 0;
  gUnknown_203B210->unkE1 = 0;
  gUnknown_203B210->unkE2 = 0;
  gUnknown_203B210->unkDC = 2;
  gUnknown_203B210->unkDE = 8;
  UpdateKecleonStoreState(0);
  return 1;
}

u32 sub_8018C04(void)
{
  switch(gUnknown_203B210->currState) {
    case 0:
    case 1:
        sub_8019730();
        break;
    case 0x12:
    case 0x13:
        sub_80199CC();
        break;
    case 0x1a:
    case 0x1b:
        sub_8019B08();
        break;
    case 0x14:
        sub_8019BBC();
        break;
    case 0x1c:
        sub_8019C78();
        break;
    case 0x16:
        sub_8019850();
        break;
    case 0x1e:
        sub_80198E8();
        break;
    case 0x1f:
        sub_8019944();
        break;
    case 0x15:
        sub_8019D30();
        break;
    case 0x1d:
        sub_8019D4C();
        break;
    case 4:
        return 3;
    default:
        sub_8019D68();
        break;
  }
  return 0;
}

void sub_8018CF0(void)
{
    if(gUnknown_203B210 != NULL)
    {
        CloseFile(gUnknown_203B210->faceFile);
        MemoryFree(gUnknown_203B210);
        gUnknown_203B210 = NULL;
    }
}

void UpdateKecleonStoreState(u32 newState)
{
    gUnknown_203B210->currState = newState;
    sub_8018D30();
    UpdateKecleonStoreDialogue();
}

void sub_8018D30(void)
{
    s32 iVar3;
    sub_8006518(gUnknown_203B210->unkE8);
    switch(gUnknown_203B210->currState)
    {
        case 0x12:
        case 0x13:
            gUnknown_203B210->unkE8[0] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[2] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[0] = gUnknown_80DB870;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x1A:
        case 0x1B:
            gUnknown_203B210->unkE8[0] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[2] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x14:
        case 0x1C:
            gUnknown_203B210->unkE8[2] = gUnknown_80DB858;
            break;
        default:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
            for(iVar3 = 0; iVar3 < 4; iVar3++)
                gUnknown_203B210->unkE8[iVar3] = gUnknown_80DB840;
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B210->unkE8, 1, 1);
}
