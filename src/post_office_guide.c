#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "menu.h"
#include "memory.h"
#include "text.h"

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

EWRAM_DATA struct PostOfficeHelper *gPostOfficeHelper;


struct unkStruct_203B330
{
    // size: 0x78
    struct UnkInputStruct *unk0;
    u8 fill4[0x8];
    u8 unkC;
    u8 unkD;
    u8 fillE[2];
    u32 unk10;
    struct UnkTextStruct2 *unk14;
    struct UnkTextStruct2 unk18[4];
};
EWRAM_DATA struct unkStruct_203B330 *gUnknown_203B330;


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

enum PostOfficeStates
{
    EXIT_POST_OFFICE_MENU,
    IM_GUIDE_START_MENU,
    ANYTHING_ELSE_START_MENU,
    RETURN_TO_START_MENU,
    DISPLAY_FRIEND_RESCUE_MENU,
    RETURN_TO_FRIEND_RESCUE,
    DISPLAY_GO_RESCUE_MENU,
    RETURN_TO_GO_RESCUE,
    DISPLAY_GET_HELP_MENU,
    RETURN_TO_GET_HELP,
};

enum PostOfficeMenuActions
{
    POST_OFFICE,
    BULLETIN_BOARD,
    DELIVERY,
    FRIEND_RESCUE,
    CANCEL,
    EXIT,
    FRIEND_RESCUE_INFO,
    GO_RESCUE,
    GET_HELP_MENU,
    DELETING_MAIL,
    RESCUE_PROCEDURES,
    RECEIVE_SOS_MAIL,
    LEAVE_FOR_RESCUE,
    SEND_AOK_MAIL,
    GET_THANK_YOU_MAIL,
    GETTING_HELP,
    SEND_SOS_MAIL,
    RECEIVE_AOK_MAIL,
    SEND_THANK_YOU_MAIL
};

const struct MenuItem gPostOfficeHelpStartMenu[] =
{
    {PostOffice_Text, POST_OFFICE},
    {BulletinBoard_Text, BULLETIN_BOARD},
    {Delivery_Text, DELIVERY},
    {FriendRescue_80E0A80, FRIEND_RESCUE},
    {Cancel_80E0A78, CANCEL},
    {NULL, EXIT}
};

ALIGNED(4) const char Cancel_80E0A78[] = _("Cancel");
ALIGNED(4) const char FriendRescue_80E0A80[] = _("{COLOR_1 YELLOW}Friend Rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char Delivery_Text[] = _("Delivery");
ALIGNED(4) const char BulletinBoard_Text[] = _("Bulletin Board");
ALIGNED(4) const char PostOffice_Text[] = _("Post Office");

const struct MenuItem gPostOfficeHelpFriendRescueMenu[] =
{
    {FriendRescueInfo_Text, FRIEND_RESCUE_INFO},
    {GoRescue_Text, GO_RESCUE},
    {GetHelp_Text, GET_HELP_MENU},
    {DeletingMailInfo_Text, DELETING_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char Exit_80EA0EC[] = _("Exit");
ALIGNED(4) const char DeletingMailInfo_Text[] = _("Deleting Mail Info");
ALIGNED(4) const char GetHelp_Text[] = _("{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} ");
ALIGNED(4) const char GoRescue_Text[] = _("{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char FriendRescueInfo_Text[] = _("Friend Rescue Info");


const struct MenuItem gPostOfficeHelpGoRescueMenu[] =
{
    {RescueProcedures_Text, RESCUE_PROCEDURES},
    {ReceiveSOSMail_Text, RECEIVE_SOS_MAIL},
    {LeaveForRescue_Text, LEAVE_FOR_RESCUE},
    {SendAOKMail_Text, SEND_AOK_MAIL},
    {GetThankYouMail_Text, GET_THANK_YOU_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char GetThankYouMail_Text[] = _("Get Thank-You Mail");
ALIGNED(4) const char SendAOKMail_Text[] = _("Send A-OK Mail");
ALIGNED(4) const char LeaveForRescue_Text[] = _("Leave for Rescue");
ALIGNED(4) const char ReceiveSOSMail_Text[] = _("Receive SOS Mail");
ALIGNED(4) const char RescueProcedures_Text[] = _("Rescue Procedures");


const struct MenuItem gPostOfficeHelpGetHelpMenu[] =
{
    {GettingHelp_Text, GETTING_HELP},
    {SendSOSMail_Text, SEND_SOS_MAIL},
    {ReceiveAOKMail_Text, RECEIVE_AOK_MAIL},
    {SendThankYouMail_Text, SEND_THANK_YOU_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char SendThankYouMail_Text[] = _("Send Thank-You Mail");
ALIGNED(4) const char ReceiveAOKMail_Text[] = _("Receive A-OK Mail");
ALIGNED(4) const char SendSOSMail_Text[] = _("Send SOS Mail");
ALIGNED(4) const char GettingHelp_Text[] = _("Getting Help");

#include "data/pelipper_help_guide_dialogue.h"

ALIGNED(4) const u8 wonder_mail_fill[] = _("pksdir0");

const struct UnkTextStruct2 gUnknown_80E1EFC =
{
    0, 0, 0, 0,
    3, 0, 0, 0,
    0, 0, 0, 0,
    0, 0,
    0, 0,
    NULL
};

const u8 gUnkData_80E1F14[] = {1, 0, 8, 0};

const struct UnkTextStruct2 gUnknown_80E1F18 =
{
    0, 0, 0, 0,
    6, 0, 0, 0,
    2, 0, 2, 0,
    0x14, 4,
    4, 0,
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
extern void sub_8031A2C(void);
extern void sub_801317C(void *);

void UpdateHelperPelipperState(u8);
void HandlePostOfficeHelpStartMenuSelection();
void ReturnToPostOfficeStartMenu();
extern void HandlePostOfficeHelpFriendRescueMenuSelection();
extern void ReturnToFriendRescueMenu();
extern void HandlePostOfficeHelpGoRescueMenuSelection();
extern void ReturntoGoRescueMenu();
extern void HandlePostOfficeHelpGetHelpMenuSelection();
extern void ReturnToGetHelpMenu();
extern s32 sub_80144A4(s32 *);
extern s32 sub_80969D0(u8);
extern void sub_8012D08(struct UnkTextStruct2 *, s32);


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
  UpdateHelperPelipperState(IM_GUIDE_START_MENU);
  return 1;
}


u32 HelperPelipperCallback(void)
{
  switch(gPostOfficeHelper->state) {
      case IM_GUIDE_START_MENU:
      case ANYTHING_ELSE_START_MENU:
        HandlePostOfficeHelpStartMenuSelection();
        break;
      case RETURN_TO_START_MENU:
        ReturnToPostOfficeStartMenu();
        break;
      case DISPLAY_FRIEND_RESCUE_MENU:
        HandlePostOfficeHelpFriendRescueMenuSelection();
        break;
      case RETURN_TO_FRIEND_RESCUE:
        ReturnToFriendRescueMenu();
        break;
      case DISPLAY_GO_RESCUE_MENU:
        HandlePostOfficeHelpGoRescueMenuSelection();
        break;
      case RETURN_TO_GO_RESCUE:
        ReturntoGoRescueMenu();
        break;
      case EXIT_POST_OFFICE_MENU:
          return 3;
      case DISPLAY_GET_HELP_MENU:
        HandlePostOfficeHelpGetHelpMenuSelection();
        break;
      case RETURN_TO_GET_HELP:
        ReturnToGetHelpMenu();
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
        case DISPLAY_GET_HELP_MENU:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpGetHelpMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case RETURN_TO_GET_HELP:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case GETTING_HELP:
                    sub_80141B4(gGettingHelpExplanation, 0, faceFile, 0x10d);
                    break;
                case SEND_SOS_MAIL:
                    sub_80141B4(gSendSOSMailExplanation, 0, faceFile, 0x10d);
                    break;
                case RECEIVE_AOK_MAIL:
                    sub_80141B4(gReceiveAOKMailExplanation, 0, faceFile, 0x10d);
                    break;
                case SEND_THANK_YOU_MAIL:
                    sub_80141B4(gSendThankYouMailExplanation, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case DISPLAY_GO_RESCUE_MENU:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpGoRescueMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case RETURN_TO_GO_RESCUE:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case RESCUE_PROCEDURES:
                    sub_80141B4(gRescueProceduresExplanation, 0, faceFile, 0x10d);
                    break;
                case RECEIVE_SOS_MAIL:
                    sub_80141B4(gReceiveSOSMailExplanation, 0, faceFile, 0x10d);
                    break;
                case SEND_AOK_MAIL:
                    sub_80141B4(gSendAOKMailExplanation, 0, faceFile, 0x10d);
                    break;
                case LEAVE_FOR_RESCUE:
                    sub_80141B4(gLeaveForRescueExplanation, 0, faceFile, 0x10d);
                    break;
                case GET_THANK_YOU_MAIL:
                    sub_80141B4(gGetThankYouMailExplanation, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case IM_GUIDE_START_MENU:
            sub_8014248(gImYourGuide, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case ANYTHING_ELSE_START_MENU:
            sub_8014248(gAnythingElse, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case RETURN_TO_START_MENU:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case POST_OFFICE:
                    sub_80141B4(gPostOfficeExplanation, 0, faceFile, 0x10d);
                    break;
                case BULLETIN_BOARD:
                    sub_80141B4(gBulletinBoardExplanation, 0, faceFile, 0x10d);
                    break;
                case DELIVERY:
                    sub_80141B4(gDeliveryExplanation, 0, faceFile, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case DISPLAY_FRIEND_RESCUE_MENU:
            sub_8014248(gWhatdYouWantToKnow, 0, gPostOfficeHelper->currMenuChoice, gPostOfficeHelpFriendRescueMenu, 0, 4, 0, faceFile, 0xC);
            break;
        case RETURN_TO_FRIEND_RESCUE:
            switch(gPostOfficeHelper->currMenuChoice)
            {
                case FRIEND_RESCUE_INFO:
                    sub_80141B4(gFriendRescueExplanation, 0, faceFile, 0x10d);
                    break;
                case DELETING_MAIL:
                    sub_80141B4(gDeletingMailExplanation, 0, faceFile, 0x10d);
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
            case CANCEL:
            case EXIT:
                UpdateHelperPelipperState(EXIT_POST_OFFICE_MENU);
                break;
            case FRIEND_RESCUE:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
                break;
            case POST_OFFICE:
            case BULLETIN_BOARD:
            case DELIVERY:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_START_MENU);
                break;
        }
    }
}

void ReturnToPostOfficeStartMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(ANYTHING_ELSE_START_MENU);
    }
}

void HandlePostOfficeHelpFriendRescueMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case EXIT:
                UpdateHelperPelipperState(ANYTHING_ELSE_START_MENU);
                break;
            case GO_RESCUE:
                UpdateHelperPelipperState(DISPLAY_GO_RESCUE_MENU);
                break;
            case GET_HELP_MENU:
                UpdateHelperPelipperState(DISPLAY_GET_HELP_MENU);
                break;
            case FRIEND_RESCUE_INFO:
            case DELETING_MAIL:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_FRIEND_RESCUE);
                break;
        }
    }
}

void ReturnToFriendRescueMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
    }
}

void HandlePostOfficeHelpGoRescueMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case EXIT:
                UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
                break;
            case RESCUE_PROCEDURES:
            case RECEIVE_SOS_MAIL:
            case LEAVE_FOR_RESCUE:
            case SEND_AOK_MAIL:
            case GET_THANK_YOU_MAIL:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_GO_RESCUE);
                break;
        }
    }
}

void ReturntoGoRescueMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(DISPLAY_GO_RESCUE_MENU);
    }
}

void HandlePostOfficeHelpGetHelpMenuSelection(void)
{
    s32 chosenAction;
    if(sub_80144A4(&chosenAction) == 0)
    {
        switch(chosenAction)
        {
            case EXIT:
                UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
                break;
            case GETTING_HELP:
            case SEND_SOS_MAIL:
            case RECEIVE_AOK_MAIL:
            case SEND_THANK_YOU_MAIL:
                gPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_GET_HELP);
                break;
        }
    }
}

void ReturnToGetHelpMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateHelperPelipperState(DISPLAY_GET_HELP_MENU);
    }
}

u32 sub_80319A4(u8 param_1,u8 param_2,int param_3)
{

  gUnknown_203B330 = MemoryAlloc(sizeof(struct unkStruct_203B330),8);
  gUnknown_203B330->unkC = param_1;
  gUnknown_203B330->unkD = param_2;
  sub_801317C(&gUnknown_203B330->unk0);
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
