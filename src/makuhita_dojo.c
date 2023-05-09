#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "makuhita_dojo.h"

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern struct unkStruct_203B318 *gUnknown_203B318;

ALIGNED(4) const u8 gUnknown_80E0744[] = "Dungeons";
ALIGNED(4) const u8 gUnknown_80E0750[] =  {0x83, 0xC2};
ALIGNED(4) const u8 gUnknown_80E0754[] = {0x83, 0xC0};
static const u8 makuhita_dojo_fill[] = "pksdir0";
const struct UnkTextStruct2 gUnknown_80E0760 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
ALIGNED(4) const u8 gMakuhitaDojoBonslyDoll[] = _(
        "{CENTER_ALIGN}{COLOR_1 YELLOW_5}$n0{END_COLOR_TEXT_1} received the {COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}!\n"
        "{CENTER_ALIGN}It has been placed outside your\n"
        "{CENTER_ALIGN}rescue team base.");

const u8 gMakuhitaDojoGoTrain[] = "Go Train";

extern void sub_8030208();
extern void sub_8030258();
extern void sub_80302A8();
extern void GotoMakuhitaFallbackState();
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
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_MAKUHITA);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_MAKUHITA);
  monName = GetMonSpecies(MONSTER_MAKUHITA);
  strcpy(gUnknown_202E1C8 - 0x50, monName);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_MAKUHITA);
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
        GotoMakuhitaFallbackState();
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
    s32 index;
    sub_8006518(gUnknown_203B318->unk6C);
    switch(gUnknown_203B318->state)
    {
        case 0:
        case 4:
        case 13:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B318->unk6C[index] = gUnknown_80E0760;
            }
            break;
        default:
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B318->unk6C, 1, 1);
}
