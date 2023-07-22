#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "felicity_bank.h"
#include "memory.h"

extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];
extern struct FelicityBankWork *gFelicityBankWork;

extern struct UnkTextStruct2 gUnknown_80DB6DC;
extern struct UnkTextStruct2 gUnknown_80DB6F4;
extern struct UnkTextStruct2 gUnknown_80DB70C;

extern void Felicity_DepositMoney();
extern void Felicity_WithdrawMoney();

extern void sub_801645C();
extern void sub_80169BC();
extern void sub_8016B00();
extern void sub_8016B24();

void UpdateFelicityBankDialogue();
void UpdateFelicityBankState(u32);

u32 CreateFelicityBank(s32 isAsleep)
{
  char *monName;
  struct OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0, 1, 1);
  gFelicityBankWork = MemoryAlloc(sizeof(struct FelicityBankWork), 8);
  gFelicityBankWork->menuAction = 0;
  gFelicityBankWork->isAsleep = isAsleep;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PERSIAN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_PERSIAN);
  monName = GetMonSpecies(MONSTER_PERSIAN);
  strcpy(gUnknown_202E1C8 - 0x50, monName);

  if (gFelicityBankWork->isAsleep == 1)
    gFelicityBankWork->unkA4 = NULL;
  else
    gFelicityBankWork->unkA4 = &gFelicityBankWork->faceFile;

  faceFile = GetDialogueSpriteDataPtr(MONSTER_PERSIAN);
  gFelicityBankWork->faceFile = faceFile;
  gFelicityBankWork->faceData = faceFile->data;
  gFelicityBankWork->unkA0 = 0;
  gFelicityBankWork->unkA1 = 0;
  gFelicityBankWork->unkA2 = 0;
  gFelicityBankWork->unk9C = 2;
  gFelicityBankWork->unk9E = 8;
  UpdateFelicityBankState(0);
  return 1;
}

u32 FelicityBankCallback(void)
{ 
  switch (gFelicityBankWork->currState) {
    case 1:
        sub_8016B24();
        break;
    case 2:
        sub_80169BC();
        break;
    case 8:
        Felicity_DepositMoney();
        break;
    case 11:
        Felicity_WithdrawMoney();
        break;
    case 6:
        return 3;
    case 0:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
    case 10:
    case 12:
    default:
        sub_8016B00();
        break;
  }
  return 0;
}

void CleanFelicityBank(void)
{
    if (gFelicityBankWork != NULL) {
        CloseFile(gFelicityBankWork->faceFile);
        MemoryFree(gFelicityBankWork);
        gFelicityBankWork = NULL;
    }
}

void UpdateFelicityBankState(u32 newState)
{
    gFelicityBankWork->currState = newState;
    sub_801645C();
    UpdateFelicityBankDialogue();
}

void sub_801645C(void)
{
    s32 index;

    sub_8006518(gFelicityBankWork->unkA8);
    switch (gFelicityBankWork->currState)
    {
        case 2:
            gFelicityBankWork->unkA8[0].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[1].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[2].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 0);
            break;
        case 8:
        case 11:
            gFelicityBankWork->unkA8[0].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[1].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            gFelicityBankWork->unkA8[2] = gUnknown_80DB70C;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 0);
            break;
        default:
            for (index = 0; index < 4; index++) {
                gFelicityBankWork->unkA8[index] = gUnknown_80DB6DC;
            }
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 1);
            break;
    }
}
