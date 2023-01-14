#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "felicity_bank.h"
#include "memory.h"

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];

extern struct unkStruct_203B204 *gUnknown_203B204;
extern struct UnkTextStruct2 gUnknown_80DB6DC;
extern struct UnkTextStruct2 gUnknown_80DB6F4;
extern struct UnkTextStruct2 gUnknown_80DB70C;

extern void sub_8016B24();
extern void sub_80169BC();
extern void Felicity_DepositMoney();
extern void Felicity_WithdrawMoney();
extern void sub_8016B00();
extern void sub_801645C();
extern void UpdateFelicityBankDialogue();

void UpdateFelicityBankState(u32);

u32 CreateFelicityBank(s32 param_1)
{
  char *monName;
  struct OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B204 = MemoryAlloc(sizeof(struct unkStruct_203B204),8);
  gUnknown_203B204->unk10 = 0;
  gUnknown_203B204->unk0 = param_1;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PERSIAN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_PERSIAN);
  monName = GetMonSpecies(MONSTER_PERSIAN);
  strcpy(gUnknown_202E1C8 - 0x50, monName);
  if (gUnknown_203B204->unk0 == 1) {
    gUnknown_203B204->unkA4 = NULL;
  }
  else {
    gUnknown_203B204->unkA4 = &gUnknown_203B204->faceFile;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PERSIAN);
  gUnknown_203B204->faceFile = faceFile;
  gUnknown_203B204->faceData = faceFile->data;
  gUnknown_203B204->unkA0 = 0;
  gUnknown_203B204->unkA1 = 0;
  gUnknown_203B204->unkA2 = 0;
  gUnknown_203B204->unk9C = 2;
  gUnknown_203B204->unk9E = 8;
  UpdateFelicityBankState(0);
  return 1;
}

u32 FelicityBankCallback(void)
{ 
  switch(gUnknown_203B204->currState) {
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
    if(gUnknown_203B204 != NULL)
    {
        CloseFile(gUnknown_203B204->faceFile);
        MemoryFree(gUnknown_203B204);
        gUnknown_203B204 = NULL;
    }
}

void UpdateFelicityBankState(u32 newState)
{
    gUnknown_203B204->currState = newState;
    sub_801645C();
    UpdateFelicityBankDialogue();
}

void sub_801645C(void)
{
    s32 uVar3;

    sub_8006518(gUnknown_203B204->unkA8);
    switch(gUnknown_203B204->currState)
    {
        case 2:
            gUnknown_203B204->unkA8[0].fill00[0] = 0x80;
            gUnknown_203B204->unkA8[1].fill00[0] = 0x80;
            gUnknown_203B204->unkA8[2].fill00[0] = 0x80;
            gUnknown_203B204->unkA8[3] = gUnknown_80DB6F4;
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B204->unkA8, 1, 0);
            break;
        case 8:
        case 11:
            gUnknown_203B204->unkA8[0].fill00[0] = 0x80;
            gUnknown_203B204->unkA8[1].fill00[0] = 0x80;
            gUnknown_203B204->unkA8[3] = gUnknown_80DB6F4;
            gUnknown_203B204->unkA8[2] = gUnknown_80DB70C;
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B204->unkA8, 1, 0);
            break;
        default:
            for(uVar3 = 0; uVar3 < 4; uVar3++)
            {
                gUnknown_203B204->unkA8[uVar3] = gUnknown_80DB6DC;
            }
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B204->unkA8, 1, 1);
            break;
    }
}
