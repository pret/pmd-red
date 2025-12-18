#include "global.h"
#include "globaldata.h"
#include "structs/menu.h"
#include "input.h"
#include "memory.h"
#include "pokemon.h"
#include "post_office_guide1.h"
#include "string_format.h"
#include "text_1.h"

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

extern u8 gSpeakerNameBuffer[];

static EWRAM_INIT PostOfficeWork *sPostOfficeHelper = {NULL};

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

    species_32 = SpeciesId(speciesID);
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sPostOfficeHelper = MemoryAlloc(sizeof(PostOfficeWork), MEMALLOC_GROUP_8);
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, species_32);
    monName = GetMonSpecies(species_32);
    strcpy(gFormatBuffer_Monsters[0], monName);
    sPostOfficeHelper->monPortrait.faceFile = NULL;
    sPostOfficeHelper->monPortrait.faceData = NULL;

    if (species_32 != MONSTER_NONE) {
        faceFile = GetDialogueSpriteDataPtr(species_32);
        sPostOfficeHelper->monPortrait.faceFile = faceFile;
        sPostOfficeHelper->monPortrait.spriteId = 0;
        sPostOfficeHelper->monPortrait.flip = FALSE;
        sPostOfficeHelper->monPortrait.unkE = 0;
        sPostOfficeHelper->monPortrait.pos.x = 2;
        sPostOfficeHelper->monPortrait.pos.y = 8;

        if (sPostOfficeHelper->monPortrait.faceFile != NULL)
            sPostOfficeHelper->monPortrait.faceData = (PortraitGfx *) sPostOfficeHelper->monPortrait.faceFile->data;
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
        if (sPostOfficeHelper->monPortrait.faceFile != NULL)
            CloseFile(sPostOfficeHelper->monPortrait.faceFile);
        FREE_AND_SET_NULL(sPostOfficeHelper);
    }
}

static void nullsub_39(void)
{
}

static void UpdateHelperPelipperText(void)
{
    MonPortraitMsg *monPortraitPtr;
    monPortraitPtr = NULL;

    if (sPostOfficeHelper->monPortrait.faceFile != NULL)
        monPortraitPtr = &sPostOfficeHelper->monPortrait;

    switch (sPostOfficeHelper->state) {
        case DISPLAY_GET_HELP_MENU:
            CreateMenuDialogueBoxAndPortrait(sWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, sPostOfficeHelpGetHelpMenu, 0, 4, 0, monPortraitPtr, 12);
            break;
        case RETURN_TO_GET_HELP:
            switch (sPostOfficeHelper->currMenuChoice) {
                case GETTING_HELP:
                    CreateDialogueBoxAndPortrait(sGettingHelpExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case SEND_SOS_MAIL:
                    CreateDialogueBoxAndPortrait(sSendSOSMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case RECEIVE_AOK_MAIL:
                    CreateDialogueBoxAndPortrait(sReceiveAOKMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case SEND_THANK_YOU_MAIL:
                    CreateDialogueBoxAndPortrait(sSendThankYouMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case DISPLAY_GO_RESCUE_MENU:
            CreateMenuDialogueBoxAndPortrait(sWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, sPostOfficeHelpGoRescueMenu, 0, 4, 0, monPortraitPtr, 12);
            break;
        case RETURN_TO_GO_RESCUE:
            switch (sPostOfficeHelper->currMenuChoice) {
                case RESCUE_PROCEDURES:
                    CreateDialogueBoxAndPortrait(sRescueProceduresExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case RECEIVE_SOS_MAIL:
                    CreateDialogueBoxAndPortrait(sReceiveSOSMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case SEND_AOK_MAIL:
                    CreateDialogueBoxAndPortrait(sSendAOKMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case LEAVE_FOR_RESCUE:
                    CreateDialogueBoxAndPortrait(sLeaveForRescueExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case GET_THANK_YOU_MAIL:
                    CreateDialogueBoxAndPortrait(sGetThankYouMailExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case IM_GUIDE_START_MENU:
            CreateMenuDialogueBoxAndPortrait(sImYourGuide, 0, sPostOfficeHelper->currMenuChoice, sPostOfficeHelpStartMenu, 0, 4, 0, monPortraitPtr, 12);
            break;
        case ANYTHING_ELSE_START_MENU:
            CreateMenuDialogueBoxAndPortrait(sAnythingElse, 0, sPostOfficeHelper->currMenuChoice, sPostOfficeHelpStartMenu, 0, 4, 0, monPortraitPtr, 12);
            break;
        case RETURN_TO_START_MENU:
            switch (sPostOfficeHelper->currMenuChoice) {
                case POST_OFFICE:
                    CreateDialogueBoxAndPortrait(sPostOfficeExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case BULLETIN_BOARD:
                    CreateDialogueBoxAndPortrait(sBulletinBoardExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case DELIVERY:
                    CreateDialogueBoxAndPortrait(sDeliveryExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                default:
                    break;
            }
            break;
        case DISPLAY_FRIEND_RESCUE_MENU:
            CreateMenuDialogueBoxAndPortrait(sWhatdYouWantToKnow, 0, sPostOfficeHelper->currMenuChoice, gPostOfficeHelpFriendRescueMenu, 0, 4, 0, monPortraitPtr, 12);
            break;
        case RETURN_TO_FRIEND_RESCUE:
            switch (sPostOfficeHelper->currMenuChoice) {
                case FRIEND_RESCUE_INFO:
                    CreateDialogueBoxAndPortrait(sFriendRescueExplanation, 0, monPortraitPtr, 0x10d);
                    break;
                case DELETING_MAIL:
                    CreateDialogueBoxAndPortrait(sDeletingMailExplanation, 0, monPortraitPtr, 0x10d);
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
