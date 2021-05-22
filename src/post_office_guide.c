#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "constants/species.h"
#include "menu.h"
#include "memory.h"

struct PostOfficeHelper
{
    // size: 0x18
    u8 state;
    s32 currMenuChoice;
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk10;
    u16 unk12;
    u8 unk14;
    u8 unk15;
    u8 unk16;
};

extern struct PostOfficeHelper *gPostOfficeHelper;


struct unkData
{
    u8 unk0[20];
    const u8 *unk20;
};

struct unkStruct_203B330
{
    // size: 0x78
    struct UnkInputStruct *unk0;
    u8 fill4[0x8];
    u8 unkC;
    u8 unkD;
    u8 fillE[2];
    u32 unk10;
    struct unkData *unk14;
    struct unkData unk18[3];
};
extern struct unkStruct_203B330 *gUnknown_203B330;


extern const char DeletingMailInfo_Text[];
extern const char GetHelp_Text[];
extern const char GoRescue_Text[];
extern const char FriendRescueInfo_Text[];

extern const char SendThankYouMail_Text[];
extern const char ReceiveAOKMail_Text[];
extern const char SendSOSMail_Text[];
extern const char GettingHelp_Text[];
extern const char GetThankYouMail_Text[];
extern const char SendAOKMail_Text[];
extern const char LeaveForRescue_Text[];
extern const char ReceiveSOSMail_Text[];
extern const char RescueProcedures_Text[];
extern const char Exit_80EA0EC[];


extern const char Cancel_80E0A78[];
extern const char FriendRescue_80E0A80[];
extern const char Delivery_Text[];
extern const char BulletinBoard_Text[];
extern const char PostOffice_Text[];

const struct MenuItem gPostOfficeHelpStartMenu[] =
{
    {PostOffice_Text, 0x0},
    {BulletinBoard_Text, 0x1},
    {Delivery_Text, 0x2},
    {FriendRescue_80E0A80,0x3},
    {Cancel_80E0A78,0x4},
    {NULL,0x5}
};

ALIGNED(4) const char Cancel_80E0A78[] = _("Cancel");
ALIGNED(4) const char FriendRescue_80E0A80[] = _("{COLOR_1 YELLOW}Friend Rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char Delivery_Text[] = _("Delivery");
ALIGNED(4) const char BulletinBoard_Text[] = _("Bulletin Board");
ALIGNED(4) const char PostOffice_Text[] = _("Post Office");

const struct MenuItem gPostOfficeHelpFriendRescueMenu[] =
{
    {FriendRescueInfo_Text, 0x6},
    {GoRescue_Text, 0x7},
    {GetHelp_Text, 0x8},
    {DeletingMailInfo_Text,0x9},
    {Exit_80EA0EC,0x5},
    {NULL,0x5}
};

ALIGNED(4) const char Exit_80EA0EC[] = _("Exit");
ALIGNED(4) const char DeletingMailInfo_Text[] = _("Deleting Mail Info");
ALIGNED(4) const char GetHelp_Text[] = _("{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} ");
ALIGNED(4) const char GoRescue_Text[] = _("{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char FriendRescueInfo_Text[] = _("Friend Rescue Info");


const struct MenuItem gPostOfficeHelpGoRescueMenu[] =
{
    {RescueProcedures_Text, 0xA},
    {ReceiveSOSMail_Text, 0xB},
    {LeaveForRescue_Text, 0xC},
    {SendAOKMail_Text, 0xD},
    {GetThankYouMail_Text,0xE},
    {Exit_80EA0EC,0x5},
    {NULL,0x5}
};

ALIGNED(4) const char GetThankYouMail_Text[] = _("Get Thank-You Mail");
ALIGNED(4) const char SendAOKMail_Text[] = _("Send A-OK Mail");
ALIGNED(4) const char LeaveForRescue_Text[] = _("Leave for Rescue");
ALIGNED(4) const char ReceiveSOSMail_Text[] = _("Receive SOS Mail");
ALIGNED(4) const char RescueProcedures_Text[] = _("Rescue Procedures");


const struct MenuItem gPostOfficeHelpGetHelpMenu[] =
{
    {GettingHelp_Text, 0xF},
    {SendSOSMail_Text, 0x10},
    {ReceiveAOKMail_Text, 0x11},
    {SendThankYouMail_Text,0x12},
    {Exit_80EA0EC,0x5},
    {NULL,0x5}
};

ALIGNED(4) const char SendThankYouMail_Text[] = _("Send Thank-You Mail");
ALIGNED(4) const char ReceiveAOKMail_Text[] = _("Receive A-OK Mail");
ALIGNED(4) const char SendSOSMail_Text[] = _("Send SOS Mail");
ALIGNED(4) const char GettingHelp_Text[] = _("Getting Help");

#include "data/pelipper_help_guide_dialogue.h"

ALIGNED(4) const u8 wonder_mail_fill[] = _("pksdir0");

const struct unkData gUnknown_80E1EFC = 
{
    0, 0, 0, 0,
    3, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    NULL
};

const u8 gUnkData_80E1F14[] = {1, 0, 8, 0};

const struct unkData gUnknown_80E1F18 = 
{
    0, 0, 0, 0,
    6, 0, 0, 0,
    2, 0, 2, 0,
    0x14, 0, 4, 0,
    4, 0, 0, 0,
    gUnkData_80E1F14
};

extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);
extern u32 sub_8012A64(struct UnkInputStruct**, u32);
extern void PlayMenuSoundEffect(u32);
extern void sub_8031A84();
extern void sub_8031AE8();

extern u8 gUnknown_202E5D8[];
extern u8 gAvailablePokemonNames[];
extern void sub_800641C(struct unkData *, u32, u32);
extern void sub_8006518(struct unkData *);
extern void sub_8031A2C(void);
extern void sub_801317C(void *);

void UpdateHelperPelipperState(u8);
void HandlePostOfficeHelpStartMenuSelection();
void sub_8031848();
extern void HandlePostOfficeHelpFriendRescueMenuSelection();
extern void sub_80318D0();
extern void HandlePostOfficeHelpGoRescueMenuSelection();
extern void sub_803192C();
extern void HandlePostOfficeHelpGetHelpMenuSelection();
extern void sub_8031988();
extern s32 sub_80144A4(s32 *);
extern s32 sub_80969D0(u8);
extern void sub_8012D08(struct unkData *, s32);


u32 CreateHelperPelipperMenu(s16 speciesID)
{
  char *monName;
  struct OpenedFile *faceFile;
  int species_32;
  
  species_32 = speciesID;
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gPostOfficeHelper = MemoryAlloc(sizeof(struct PostOfficeHelper), 8);
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, speciesID);
  monName = GetMonSpecies(speciesID);
  strcpy(gAvailablePokemonNames, monName);
  gPostOfficeHelper->faceFile = NULL;
  gPostOfficeHelper->faceData = NULL;
  if (speciesID != SPECIES_NONE) {
    faceFile = GetDialogueSpriteDataPtr(species_32);
    gPostOfficeHelper->faceFile = faceFile;
    gPostOfficeHelper->unk14 = 0;
    gPostOfficeHelper->unk15 = 0;
    gPostOfficeHelper->unk16 = 0;
    gPostOfficeHelper->unk10 = 2;
    gPostOfficeHelper->unk12 = 8;
    if (gPostOfficeHelper->faceFile != NULL) {
      gPostOfficeHelper->faceData = gPostOfficeHelper->faceFile->data;
    }
  }
  gPostOfficeHelper->currMenuChoice = 0;
  UpdateHelperPelipperState(1);
  return 1;
}


u32 sub_8031540(void)
{
  switch(gPostOfficeHelper->state) {
      case 1:
      case 2:
        HandlePostOfficeHelpStartMenuSelection();
        break;
      case 3:
        sub_8031848();
        break;
      case 4:
        HandlePostOfficeHelpFriendRescueMenuSelection();
        break;
      case 5:
        sub_80318D0();
        break;
      case 6:
        HandlePostOfficeHelpGoRescueMenuSelection();
        break;
      case 7:
        sub_803192C();
        break;
      case 0:
          return 3;
      case 8:
        HandlePostOfficeHelpGetHelpMenuSelection();
        break;
      case 9:
        sub_8031988();
        break;
  }
  return 0;
}

void CleanHelperPelipper(void)
{
    if(gPostOfficeHelper != NULL)
    {
        if(gPostOfficeHelper->faceFile != NULL)
            CloseFile(gPostOfficeHelper->faceFile);
        MemoryFree(gPostOfficeHelper);
        gPostOfficeHelper = NULL;
    }
}

void nullsub_39(void)
{
}

void UpdateHelperPelipperText(void)
{
    struct OpenedFile **faceFile;
    faceFile = NULL;
    if(gPostOfficeHelper->faceFile != NULL)
        faceFile = &gPostOfficeHelper->faceFile;
    
    switch(gPostOfficeHelper->state)
    {
        case 8:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpGetHelpMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case 9:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case 15:
                    sub_80141B4(gGettingHelpExplaination, 0, faceFile, 0x10d);
                    break;
                case 16:
                    sub_80141B4(gSendSOSMailExplaination, 0, faceFile, 0x10d);
                    break;
                case 17:
                    sub_80141B4(gReceiveAOKMailExplaination, 0, faceFile, 0x10d);
                    break;
                case 18:
                    sub_80141B4(gSendThankYouMailExplaination, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case 6:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpGoRescueMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case 7:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case 10:
                    sub_80141B4(gRescueProceduresExplaination, 0, faceFile, 0x10d);
                    break;
                case 11:
                    sub_80141B4(gReceiveSOSMailExplaination, 0, faceFile, 0x10d);
                    break;
                case 13:
                    sub_80141B4(gSendAOKMailExplaination, 0, faceFile, 0x10d);
                    break;
                case 12:
                    sub_80141B4(gLeaveForRescueExplaination, 0, faceFile, 0x10d);
                    break;
                case 14:
                    sub_80141B4(gGetThankYouMailExplaination, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case 1:
            sub_8014248(gImYourGuide, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case 2:
            sub_8014248(gAnythingElse, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case 3:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case 0:
                    sub_80141B4(gPostOfficeExplaination, 0, faceFile, 0x10d);
                    break;
                case 1:
                    sub_80141B4(gBulletinBoardExplaination, 0, faceFile, 0x10d);
                    break;
                case 2:
                    sub_80141B4(gDeliveryExplaination, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case 4:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpFriendRescueMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case 5:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case 6:
                    sub_80141B4(gFriendRescueExplaination, 0, faceFile, 0x10d);
                    break;
                case 9:
                    sub_80141B4(gDeletingMailExplaination, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void UpdateHelperPelipperState(u8 newState)
{
    gPostOfficeHelper->state = newState;
    nullsub_39();
    UpdateHelperPelipperText();
}

void HandlePostOfficeHelpStartMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case 4:
            case 5:
                UpdateHelperPelipperState(0);
                break;
            case 3:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(4);
                break;
            case 0:
            case 1:
            case 2:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(3);
                break;
        }
    }
}

void sub_8031848(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(2);
    }
}

void HandlePostOfficeHelpFriendRescueMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case 5:
                UpdateHelperPelipperState(2);
                break;
            case 7:
                UpdateHelperPelipperState(6);
                break;
            case 8:
                UpdateHelperPelipperState(8);
                break;
            case 6:
            case 9:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(5);
                break;
        }
    }
}

void sub_80318D0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(4);
    }
}

void HandlePostOfficeHelpGoRescueMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case 5:
                UpdateHelperPelipperState(4);
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(7);
                break;
        }
    }
}

void sub_803192C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(6);
    }
}

void HandlePostOfficeHelpGetHelpMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case 5:
                UpdateHelperPelipperState(4);
                break;
            case 15:
            case 16:
            case 17:
            case 18:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(9);
                break;
        }
    }
}

void sub_8031988(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(8);
    }
}

u32 sub_80319A4(u8 param_1,u8 param_2,int param_3)
{
  
  gUnknown_203B330 = MemoryAlloc(0x78,8);
  gUnknown_203B330->unkC = param_1;
  gUnknown_203B330->unkD = param_2;
  sub_801317C(gUnknown_203B330);
  gUnknown_203B330->unk10 = param_3;
  gUnknown_203B330->unk14 = &gUnknown_203B330->unk18[param_3];
  sub_8031A2C();
  return 1;
}

u32 sub_80319F8(void)
{
    switch(sub_8012A64(&gUnknown_203B330->unk0, gUnknown_203B330->unk10))
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

void sub_8031A2C(void)
{
    sub_8031A84();
    sub_8031AE8();
}

void sub_8031A3C(void)
{
    if(gUnknown_203B330 != NULL)
    {
        gUnknown_203B330->unk18[gUnknown_203B330->unk10] = gUnknown_80E1EFC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B330->unk18, 1, 1);
        MemoryFree(gUnknown_203B330);
        gUnknown_203B330 = NULL;
    }
}

void sub_8031A84(void)
{
  s32 iVar1;
  
  sub_8006518(gUnknown_203B330->unk18);
  gUnknown_203B330->unk18[gUnknown_203B330->unk10] = gUnknown_80E1F18;
  if (gUnknown_203B330->unkC == 2) {
    iVar1 = sub_80969D0(gUnknown_203B330->unkD);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    sub_8012D08(gUnknown_203B330->unk14,iVar1);
  }
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B330->unk18,1,1);
}
