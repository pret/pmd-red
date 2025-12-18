#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "music_util.h"
#include "code_801B60C.h"
#include "code_80A26CC.h"
#include "common_strings.h"
#include "dungeon_info.h"
#include "input.h"
#include "makuhita_dojo1.h"
#include "makuhita_dojo2.h"
#include "memory.h"
#include "pokemon.h"
#include "string_format.h"
#include "text_1.h"

static EWRAM_INIT MakuhitaDojoWork1 *sMakuhitaDojoWork1 = {NULL};

#include "data/makuhita_dojo1.h"

enum menuActions {
    CANCEL_ACTION = 1,
    GO_TRAIN_ACTION,
    INFO_ACTION
};

static void MakuhitaDojo_DrawMainMenu(void);
static void MakuhitaDojo_GoToFallbackState(void);
static void MakuhitaDojo_SetState(s32);
static void MakuhitaDojo_UpdateDialogue(void);

static void sub_802FF1C(void);
static void sub_8030208(void);
static void sub_8030258(void);
static void sub_80302A8(void);

bool8 MakuhitaDojo_New(u32 mode)
{
    u8 *monName;
    OpenedFile *faceFile;
    u32 initialState;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sMakuhitaDojoWork1 = MemoryAlloc(sizeof(MakuhitaDojoWork1), MEMALLOC_GROUP_8);
    sMakuhitaDojoWork1->unk10 = -1;
    sMakuhitaDojoWork1->mode = mode;

    switch (mode) {
        case MAKUHITA_DOJO_INIT_MODE_UNK0_AWAKE:
            initialState = 0;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_AWAKE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK1_AWAKE:
            initialState = 7;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_AWAKE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK2_AWAKE:
            initialState = 6;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_AWAKE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK3_AWAKE:
            initialState = 8;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_AWAKE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK4_ASLEEP:
            initialState = 0;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_ASLEEP;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK5_ASLEEP:
            initialState = 7;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_ASLEEP;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK6_ASLEEP:
            initialState = 6;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_ASLEEP;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK7_ASLEEP:
        default:
            initialState = 8;
            sMakuhitaDojoWork1->dlgMode = MAKUHITA_DOJO_MODE_ASLEEP;
            break;
    }

    if (sMakuhitaDojoWork1->dlgMode == MAKUHITA_DOJO_MODE_ASLEEP)
        sMakuhitaDojoWork1->monPortraitPtr = NULL;
    else
        sMakuhitaDojoWork1->monPortraitPtr = &sMakuhitaDojoWork1->monPortrait;

    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_MAKUHITA);
    CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_MAKUHITA);
    monName = GetMonSpecies(MONSTER_MAKUHITA);
    strcpy(gFormatBuffer_Monsters[6], monName);

    faceFile = GetDialogueSpriteDataPtr(MONSTER_MAKUHITA);
    sMakuhitaDojoWork1->monPortrait.faceFile = faceFile;
    sMakuhitaDojoWork1->monPortrait.faceData = (PortraitGfx *) faceFile->data;
    sMakuhitaDojoWork1->monPortrait.spriteId = 0;
    sMakuhitaDojoWork1->monPortrait.flip = FALSE;
    sMakuhitaDojoWork1->monPortrait.unkE = 0;
    sMakuhitaDojoWork1->monPortrait.pos.x = 2;
    sMakuhitaDojoWork1->monPortrait.pos.y = 8;
    MakuhitaDojo_SetState(initialState);
    return TRUE;
}

u32 HandleMakuhitaDojoState(void)
{
    switch (sMakuhitaDojoWork1->state) {
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
            MakuhitaDojo_GoToFallbackState();
            break;
    }
    return 0;
}

s16 sub_802FED0(void)
{
    return sMakuhitaDojoWork1->unk10;
}

void MakuhitaDojo_Delete(void)
{
    if (sMakuhitaDojoWork1 != NULL) {
        CloseFile(sMakuhitaDojoWork1->monPortrait.faceFile);
        FREE_AND_SET_NULL(sMakuhitaDojoWork1);
    }
}

static void MakuhitaDojo_SetState(s32 newState)
{
    sMakuhitaDojoWork1->state = newState;
    sub_802FF1C();
    MakuhitaDojo_UpdateDialogue();
}

static void sub_802FF1C(void)
{
    s32 index;

    RestoreSavedWindows(&sMakuhitaDojoWork1->unk6C);

    switch (sMakuhitaDojoWork1->state) {
        case 0:
        case 4:
        case 13:
            for(index = 0; index < 4; index++)
                sMakuhitaDojoWork1->unk6C.id[index] = sUnknown_80E0760;
            break;
        default:
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sMakuhitaDojoWork1->unk6C, TRUE, TRUE);
}

static void MakuhitaDojo_UpdateDialogue(void)
{
    DungeonLocation dLoc;

    switch (sMakuhitaDojoWork1->state) {
        case 0:
            MakuhitaDojo_DrawMainMenu();
            CreateMenuDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_0], 0, sMakuhitaDojoWork1->menuAction, sMakuhitaDojoWork1->unk18, NULL, 4, 0, sMakuhitaDojoWork1->monPortraitPtr, 12);
            break;
        case 1:
            CreateMenuDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_1], 0, sMakuhitaDojoWork1->menuAction, sMakuhitaDojoWork1->unk18, NULL, 4, 0, sMakuhitaDojoWork1->monPortraitPtr, 12);
            break;
        case 2:
            sMakuhitaDojoWork1->fallbackState = 13;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_2], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 3:
            sMakuhitaDojoWork1->fallbackState = 4;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_3], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 4:
            sub_80302E8(3, NULL, 10);
            break;
        case 5:
            sMakuhitaDojoWork1->fallbackState = 13;
            dLoc.id = ScriptDungeonIdToDungeonId(sMakuhitaDojoWork1->unk10);
            dLoc.floor = 1;
            PrintYellowDungeonNametoBuffer(gFormatBuffer_Monsters[0], &dLoc);
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_4], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 7:
            sMakuhitaDojoWork1->fallbackState = 13;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_6], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 6:
            sMakuhitaDojoWork1->fallbackState = 13;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_5], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 8:
            sMakuhitaDojoWork1->fallbackState = 9;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_7], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 9:
            PrintColoredPokeNameToBuffer(gFormatBuffer_Names[0], GetLeaderMon1(), COLOR_YELLOW);
            sMakuhitaDojoWork1->fallbackState = 11;
            PlaySound(203);
            CreateDialogueBoxAndPortrait(sReceivedBonslyDoll, 0, 0, 0x101);
            break;
        case 10:
            sMakuhitaDojoWork1->fallbackState = 13;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_8], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 11:
            sub_801B60C(1, ITEM_GINSENG, 1);
            break;
        case 12:
            sMakuhitaDojoWork1->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonMakuhita[sMakuhitaDojoWork1->dlgMode][MAKUHITA_DLG_9], 0, sMakuhitaDojoWork1->monPortraitPtr, 0x10D);
            break;
        case 13:
            return;
    }
}

static void MakuhitaDojo_DrawMainMenu(void)
{
    s32 loopMax;

    sMakuhitaDojoWork1->menuAction = GO_TRAIN_ACTION;
    loopMax = 0;
    sMakuhitaDojoWork1->unk18[loopMax].text = sGoTrain;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = GO_TRAIN_ACTION;

    if (MakuhitaDojo_ReturnFalse()) {
        sMakuhitaDojoWork1->unk18[loopMax].menuAction = -1;
        sMakuhitaDojoWork1->menuAction = 1;
    }

    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = gCommonInfo[0];
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = INFO_ACTION;
    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = gCommonCancel[0];
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = CANCEL_ACTION;
    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = NULL;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_8030208(void)
{
    s32 menuAction;
    if (sub_80144A4(&menuAction) == 0) {
        sMakuhitaDojoWork1->menuAction = menuAction;

        switch (menuAction) {
            case GO_TRAIN_ACTION:
                MakuhitaDojo_SetState(3);
                break;
            case INFO_ACTION:
                MakuhitaDojo_SetState(12);
                break;
            case CANCEL_ACTION:
                MakuhitaDojo_SetState(2);
                break;
        }
    }
}

static void sub_8030258(void)
{
    switch (sub_80303AC(TRUE)) {
        case 3:
            sMakuhitaDojoWork1->unk10 = sub_8030418();
            sub_8030480();
            MakuhitaDojo_SetState(5);
            break;
        case 2:
            sub_8030480();
            sMakuhitaDojoWork1->unk10 = -1;
            MakuhitaDojo_SetState(1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_80302A8(void)
{
    switch (sub_801B6AC()) {
        case 2:
        case 3:
            sub_801B72C();
            MakuhitaDojo_SetState(10);
            break;
        case 0:
        case 1:
            break;
    }
}

static void MakuhitaDojo_GoToFallbackState(void)
{
    s32 temp;
    if (sub_80144A4(&temp) == 0)
        MakuhitaDojo_SetState(sMakuhitaDojoWork1->fallbackState);
}
