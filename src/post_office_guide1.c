#include "global.h"
#include "code_80130A8.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "post_office_guide1.h"
#include "text1.h"

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

extern u8 gAvailablePokemonNames[]; // 202DF98
extern u8 gUnknown_202E5D8[];

static EWRAM_DATA_2 PostOfficeWork *sPostOfficeHelper = {0};

#include "data/post_office_guide1.h"

static void HandlePostOfficeHelpFriendRescueMenuSelection(void);
static void HandlePostOfficeHelpGetHelpMenuSelection(void);
static void HandlePostOfficeHelpGoRescueMenuSelection(void);
static void HandlePostOfficeHelpStartMenuSelection(void);
static void ReturnToFriendRescueMenu(void);
static void ReturnToGetHelpMenu(void);
static void ReturntoGoRescueMenu(void);
static void ReturnToPostOfficeStartMenu(void);
static void UpdateHelperPelipperState(u8);

bool8 CreateHelperPelipperMenu(s16 speciesID)
{
    u8 *monName;
    OpenedFile *faceFile;
    s32 species_32;

    species_32 = speciesID;
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);

    sPostOfficeHelper = MemoryAlloc(sizeof(PostOfficeWork), 8);
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, speciesID);
    monName = GetMonSpecies(speciesID);
    strcpy(gAvailablePokemonNames, monName);
    sPostOfficeHelper->faceFile = NULL;
    sPostOfficeHelper->faceData = NULL;

    if (speciesID != MONSTER_NONE) {
        faceFile = GetDialogueSpriteDataPtr(species_32);
        sPostOfficeHelper->faceFile = faceFile;
        sPostOfficeHelper->unk14 = 0;
        sPostOfficeHelper->unk15 = 0;
        sPostOfficeHelper->unk16 = 0;
        sPostOfficeHelper->unk10 = 2;
        sPostOfficeHelper->unk12 = 8;

        if (sPostOfficeHelper->faceFile != NULL)
            sPostOfficeHelper->faceData = sPostOfficeHelper->faceFile->data;
    }

    sPostOfficeHelper->currMenuChoice = 0;
    UpdateHelperPelipperState(IM_GUIDE_START_MENU);
    return TRUE;
}

u32 HelperPelipperCallback(void)
{
    switch (sPostOfficeHelper->state) {
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
    if (sPostOfficeHelper != NULL) {
        if (sPostOfficeHelper->faceFile != NULL)
            CloseFile(sPostOfficeHelper->faceFile);
        MemoryFree(sPostOfficeHelper);
        sPostOfficeHelper = NULL;
    }
}

static void nullsub_39(void)
{
}

static void UpdateHelperPelipperText(void)
{
    OpenedFile **faceFile;
    faceFile = NULL;

    if (sPostOfficeHelper->faceFile != NULL)
        faceFile = &sPostOfficeHelper->faceFile;

    switch (sPostOfficeHelper->state) {
        case DISPLAY_GET_HELP_MENU:
            sub_8014248(gWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpGetHelpMenu, 0, 4, 0, faceFile, 12);
            break;
        case RETURN_TO_GET_HELP:
            switch (sPostOfficeHelper->currMenuChoice) {
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
            sub_8014248(gWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpGoRescueMenu, 0, 4, 0, faceFile, 12);
            break;
        case RETURN_TO_GO_RESCUE:
            switch (sPostOfficeHelper->currMenuChoice) {
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
            sub_8014248(gImYourGuide, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 12);
            break;
        case ANYTHING_ELSE_START_MENU:
            sub_8014248(gAnythingElse, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpStartMenu, 0, 4, 0, faceFile, 12);
            break;
        case RETURN_TO_START_MENU:
            switch (sPostOfficeHelper->currMenuChoice) {
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
            sub_8014248(gWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpFriendRescueMenu, 0, 4, 0, faceFile, 12);
            break;
        case RETURN_TO_FRIEND_RESCUE:
            switch (sPostOfficeHelper->currMenuChoice) {
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

static void UpdateHelperPelipperState(u8 newState)
{
    sPostOfficeHelper->state = newState;
    nullsub_39();
    UpdateHelperPelipperText();
}

static void HandlePostOfficeHelpStartMenuSelection(void)
{
    s32 chosenAction;

    if (sub_80144A4(&chosenAction) == 0) {
        switch (chosenAction) {
            case CANCEL:
            case EXIT:
                UpdateHelperPelipperState(EXIT_POST_OFFICE_MENU);
                break;
            case FRIEND_RESCUE:
                sPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
                break;
            case POST_OFFICE:
            case BULLETIN_BOARD:
            case DELIVERY:
                sPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_START_MENU);
                break;
        }
    }
}

static void ReturnToPostOfficeStartMenu(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        UpdateHelperPelipperState(ANYTHING_ELSE_START_MENU);
}

static void HandlePostOfficeHelpFriendRescueMenuSelection(void)
{
    s32 chosenAction;

    if (sub_80144A4(&chosenAction) == 0) {
        switch (chosenAction) {
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
                sPostOfficeHelper->currMenuChoice = chosenAction;
                UpdateHelperPelipperState(RETURN_TO_FRIEND_RESCUE);
                break;
        }
    }
}

static void ReturnToFriendRescueMenu(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
}

static void HandlePostOfficeHelpGoRescueMenuSelection(void)
{
    s32 chosenAction;

    if (sub_80144A4(&chosenAction) != 0)
        return;

    switch (chosenAction) {
        case EXIT:
            UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
            break;
        case RESCUE_PROCEDURES:
        case RECEIVE_SOS_MAIL:
        case LEAVE_FOR_RESCUE:
        case SEND_AOK_MAIL:
        case GET_THANK_YOU_MAIL:
            sPostOfficeHelper->currMenuChoice = chosenAction;
            UpdateHelperPelipperState(RETURN_TO_GO_RESCUE);
            break;
    }
}

static void ReturntoGoRescueMenu(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        UpdateHelperPelipperState(DISPLAY_GO_RESCUE_MENU);
}

static void HandlePostOfficeHelpGetHelpMenuSelection(void)
{
    s32 chosenAction;

    if (sub_80144A4(&chosenAction) != 0)
        return;

    switch (chosenAction) {
        case EXIT:
            UpdateHelperPelipperState(DISPLAY_FRIEND_RESCUE_MENU);
            break;
        case GETTING_HELP:
        case SEND_SOS_MAIL:
        case RECEIVE_AOK_MAIL:
        case SEND_THANK_YOU_MAIL:
            sPostOfficeHelper->currMenuChoice = chosenAction;
            UpdateHelperPelipperState(RETURN_TO_GET_HELP);
            break;
    }
}

static void ReturnToGetHelpMenu(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        UpdateHelperPelipperState(DISPLAY_GET_HELP_MENU);
}