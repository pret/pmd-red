#include "global.h"
#include "exclusive_pokemon.h"
#include "input.h"
#include "item.h"
#include "memory.h"
#include "text.h"
#include "wonder_mail.h"

struct unkStruct_203B2FC
{
    // size: 0xA8
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fallbackState;
    u32 unk8;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    u8 fill11[0x30 - 0x11];
    u8 jobSlot;
    struct WonderMail *jobInfo;
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk40;
    u16 unk42;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 fill47[0x48 - 0x47];
    struct UnkTextStruct2 unk48[4];
};
extern struct unkStruct_203B2FC *gUnknown_203B2FC;


struct unkStruct_203B300
{
    // size: 0x7C
    u8 fill0[0xC];
    u32 *unkC;
    u32 unk10;
    struct UnkTextStruct2 *unk14;
    struct UnkTextStruct2 unk18[4];
    u8 unk78[4];
};

extern struct unkStruct_203B300 *gUnknown_203B300;
extern struct UnkTextStruct2 gUnknown_80E0248;
extern struct UnkTextStruct2 gUnknown_80E0264;
extern struct UnkTextStruct2 gUnknown_80E016C;
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void CreateRescueDescription(u32 *);
extern void PlayMenuSoundEffect(u32);
extern s32 sub_8012A64(void *, u32);
void sub_802DF6C(void);
void sub_802DF88(void);
void sub_802DF14(void);
void sub_801317C(void);
extern s32 sub_80144A4(s32 *);
extern void sub_802DC28(u32);
extern void sub_802F2C0(void);
extern void sub_802DC28(u32);
extern u32 sub_802F298(void);
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202DE58[];

extern u8 gWonderMailClientThanksForRescuingMe[];
extern u8 gWonderMailClientThanksForRescuingThem[];
extern u8 gWonderMailClientEscorted[];
extern u8 gWonderMailClientItemDelivered1[];
extern u8 gWonderMailClientItemDelivered2[];
extern void sub_802F204(u32 *, u32);
extern void sub_80141B4(u8 *r0, u32, struct OpenedFile **r1, u32);
extern void sub_802DC40(void);
extern void sub_802DC9C(void);
void sub_802DE44(void);
void sub_802DE60(void);
struct WonderMail *GetJobSlotInfo(u8);
extern void sub_8096AF8(u8 *, u32, u32);
extern void sub_8096EEC(void);
extern void sub_803C21C(struct WonderMail *, u32 *);

u32 sub_802DB28(u8 jobSlot, u8 param_2)
{
  char local_18 [8];
  
  sub_8096AF8(local_18,jobSlot,param_2);
  if (local_18[0] == '\0') {
      return 0;
  }
  else {
    ResetUnusedInputStruct();
    sub_800641C(0,1,1);
    gUnknown_203B2FC = MemoryAlloc(sizeof(struct unkStruct_203B2FC),8);
    gUnknown_203B2FC->jobSlot = jobSlot;
    gUnknown_203B2FC->jobInfo = GetJobSlotInfo(jobSlot);
    sub_8096EEC();
    sub_803C21C(gUnknown_203B2FC->jobInfo,&gUnknown_203B2FC->unk8);
    gUnknown_203B2FC->faceFile = GetDialogueSpriteDataPtr(gUnknown_203B2FC->jobInfo->clientSpecies);
    gUnknown_203B2FC->faceData = NULL;
    gUnknown_203B2FC->unk44 = 0;
    gUnknown_203B2FC->unk45 = 0;
    gUnknown_203B2FC->unk46 = 0;
    gUnknown_203B2FC->unk40 = 2;
    gUnknown_203B2FC->unk42 = 8;
    if (gUnknown_203B2FC->faceFile != NULL) {
      gUnknown_203B2FC->faceData = gUnknown_203B2FC->faceFile->data;
    }
    sub_802DC28(0);
    return 1;
  }
}

u32 sub_802DBD4(void)
{
    switch(gUnknown_203B2FC->state)
    {
        case 7:
            gUnknown_203B2FC->jobInfo->mailType = 7;
            return 3;
        case 6:
            sub_802DE44();
            return 0;
        default:
            sub_802DE60();
            return 0;
    }
}

void sub_802DC00(void)
{
    if(gUnknown_203B2FC != NULL)
    {
        if(gUnknown_203B2FC->faceFile != NULL)
        {
            CloseFile(gUnknown_203B2FC->faceFile);
        }
        MemoryFree(gUnknown_203B2FC);
        gUnknown_203B2FC = NULL;
    }
}

void sub_802DC28(u32 newState)
{
    gUnknown_203B2FC->state = newState;
    sub_802DC40();
    sub_802DC9C();
}

void sub_802DC40(void)
{
    s32 iVar3;
    sub_8006518(gUnknown_203B2FC->unk48);
    switch(gUnknown_203B2FC->state)
    {
        case 0:
        case 7:
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B2FC->unk48[iVar3]  = gUnknown_80E016C;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2FC->unk48, 1, 1);
}

void sub_802DC9C(void)
{
  char *speciesText;
  s32 index;
  
  switch(gUnknown_203B2FC->state) {
      case 0:
        CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8,gUnknown_203B2FC->jobInfo->clientSpecies);
        CopyYellowSpeciesNametoBuffer(gUnknown_202E1C8,gUnknown_203B2FC->jobInfo->clientSpecies);
        speciesText = GetMonSpecies(gUnknown_203B2FC->jobInfo->clientSpecies);
        strcpy(gUnknown_202E1C8 + 0xfffffdd0,speciesText);
        speciesText = GetMonSpecies(gUnknown_203B2FC->jobInfo->targetSpecies);
        strcpy(gUnknown_202E1C8 + 0xfffffe20,speciesText);
        UnlockExclusivePokemon(gUnknown_203B2FC->jobInfo->clientSpecies);
        sub_8090DC4(gUnknown_202DE58,gUnknown_203B2FC->jobInfo->targetItem,0);
        gUnknown_203B2FC->fallbackState = 6;
        switch(gUnknown_203B2FC->jobInfo->missionType) {
            case WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM:
                sub_802DC28(5);
                break;
            case WONDER_MAIL_MISSION_TYPE_FIND_ITEM:
                sub_802DC28(4);
                break;
            case WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET:
                sub_802DC28(2);
                UnlockExclusivePokemon(gUnknown_203B2FC->jobInfo->targetSpecies);
                break;
            case WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT:
                sub_802DC28(3);
                UnlockExclusivePokemon(gUnknown_203B2FC->jobInfo->targetSpecies);
                break;
            default:
            case WONDER_MAIL_MISSION_TYPE_RESCUE_CLIENT:
                sub_802DC28(1);
                break;
        }
        break;
      case 1:
        sub_80141B4(gWonderMailClientThanksForRescuingMe,0,&gUnknown_203B2FC->faceFile,0x10d);
        break;
      case 2:
        sub_80141B4(gWonderMailClientThanksForRescuingThem,0,&gUnknown_203B2FC->faceFile,0x10d);
        break;
      case 3:
        sub_80141B4(gWonderMailClientEscorted,0,&gUnknown_203B2FC->faceFile,0x10d);
        break;
      case 5:
        sub_80141B4(gWonderMailClientItemDelivered1,0,&gUnknown_203B2FC->faceFile,0x10d);
        break;
      case 4:
        index = FindItemInInventory(gUnknown_203B2FC->jobInfo->targetItem);
        if (index != -1) {
          ShiftItemsDownFrom(index);
          FillInventoryGaps();
        }
        sub_80141B4(gWonderMailClientItemDelivered2,0,&gUnknown_203B2FC->faceFile,0x10d);
        break;
      case 6:
          sub_802F204(&gUnknown_203B2FC->unk8,1);
          break;
      case 7:
      default:
          break;
  }
}

void sub_802DE44(void)
{
    switch(sub_802F298())
    {
        case 2:
        case 3:
            sub_802F2C0();
            sub_802DC28(7);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_802DE60(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802DC28(gUnknown_203B2FC->fallbackState);
    }
}

u32 sub_802DE84(u32 *r0)
{
    gUnknown_203B300 = MemoryAlloc(sizeof(struct unkStruct_203B300), 8);
    gUnknown_203B300->unkC = r0;
    sub_801317C();
    gUnknown_203B300->unk10 = *gUnknown_203B300->unkC;
    gUnknown_203B300->unk14 = &gUnknown_203B300->unk18[gUnknown_203B300->unk10];
    sub_8006518(gUnknown_203B300->unk18);
    gUnknown_203B300->unk18[gUnknown_203B300->unk10] = gUnknown_80E0264;
    sub_802DF14();
    return 1;
}

u32 sub_802DEE0(void)
{
    switch(sub_8012A64(gUnknown_203B300, gUnknown_203B300->unk10))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

void sub_802DF14(void)
{
    sub_802DF6C();
    sub_802DF88();
}

void sub_802DF24(void)
{
    if(gUnknown_203B300 != NULL)
    {
        gUnknown_203B300->unk18[gUnknown_203B300->unk10] = gUnknown_80E0248;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B300->unk18, 1, 1);
        MemoryFree(gUnknown_203B300);
        gUnknown_203B300 = NULL;
    }
}

void sub_802DF6C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B300->unk18, 1, 1);
}

void sub_802DF88(void)
{
    sub_80073B8(gUnknown_203B300->unk10);
    CreateRescueDescription(gUnknown_203B300->unkC);
    sub_80073E0(gUnknown_203B300->unk10);
}
