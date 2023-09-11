#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B60C.h"
#include "code_80A26CC.h"
#include "common_strings.h"
#include "constants/colors.h"
#include "dungeon.h"
#include "makuhita_dojo1.h"
#include "makuhita_dojo2.h"
#include "memory.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

extern u8 gAvailablePokemonNames[]; // 202DF98
extern u8 gUnknown_202E1C8[];
extern u8 gPlayerName[]; // 202E2B8
extern u8 gUnknown_202E5D8[];

static EWRAM_DATA_2 MakuhitaDojoWork1 *sMakuhitaDojoWork1 = {0};

#include "data/makuhita_dojo1.h"

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
    sub_800641C(NULL, TRUE, TRUE);

    sMakuhitaDojoWork1 = MemoryAlloc(sizeof(MakuhitaDojoWork1), 8);
    sMakuhitaDojoWork1->unk10 = -1;
    sMakuhitaDojoWork1->mode = mode;

    switch (mode) {
        case MAKUHITA_DOJO_INIT_MODE_UNK0_AWAKE:
            initialState = 0;
            sMakuhitaDojoWork1->isAsleep = FALSE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK1_AWAKE:
            initialState = 7;
            sMakuhitaDojoWork1->isAsleep = FALSE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK2_AWAKE:
            initialState = 6;
            sMakuhitaDojoWork1->isAsleep = FALSE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK3_AWAKE:
            initialState = 8;
            sMakuhitaDojoWork1->isAsleep = FALSE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK4_ASLEEP:
            initialState = 0;
            sMakuhitaDojoWork1->isAsleep = TRUE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK5_ASLEEP:
            initialState = 7;
            sMakuhitaDojoWork1->isAsleep = TRUE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK6_ASLEEP:
            initialState = 6;
            sMakuhitaDojoWork1->isAsleep = TRUE;
            break;
        case MAKUHITA_DOJO_INIT_MODE_UNK7_ASLEEP:
        default:
            initialState = 8;
            sMakuhitaDojoWork1->isAsleep = TRUE;
            break;
    }

    if (sMakuhitaDojoWork1->isAsleep == TRUE)
        sMakuhitaDojoWork1->unk68 = NULL;
    else
        sMakuhitaDojoWork1->unk68 = &sMakuhitaDojoWork1->faceFile;

    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_MAKUHITA);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_MAKUHITA);
    monName = GetMonSpecies(MONSTER_MAKUHITA);
    strcpy(gUnknown_202E1C8 - 0x50, monName);

    faceFile = GetDialogueSpriteDataPtr(MONSTER_MAKUHITA);
    sMakuhitaDojoWork1->faceFile = faceFile;
    sMakuhitaDojoWork1->faceData = faceFile->data;
    sMakuhitaDojoWork1->unk64 = 0;
    sMakuhitaDojoWork1->unk65 = 0;
    sMakuhitaDojoWork1->unk66 = 0;
    sMakuhitaDojoWork1->unk60 = 2;
    sMakuhitaDojoWork1->unk62 = 8;
    MakuhitaDojo_SetState(initialState);
    return TRUE;
}

u32 sub_802FE58(void)
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
        CloseFile(sMakuhitaDojoWork1->faceFile);
        MemoryFree(sMakuhitaDojoWork1);
        sMakuhitaDojoWork1 = NULL;
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

    sub_8006518(sMakuhitaDojoWork1->unk6C);

    switch (sMakuhitaDojoWork1->state) {
        case 0:
        case 4:
        case 13:
            for(index = 0; index < 4; index++)
                sMakuhitaDojoWork1->unk6C[index] = sUnknown_80E0760;
            break;
        default:
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sMakuhitaDojoWork1->unk6C, TRUE, TRUE);
}

static void MakuhitaDojo_UpdateDialogue(void)
{
    DungeonLocation dLoc;

    switch (sMakuhitaDojoWork1->state) {
        case 0:
            MakuhitaDojo_DrawMainMenu();
            sub_8014248(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][0], 0, sMakuhitaDojoWork1->menuAction, sMakuhitaDojoWork1->unk18, NULL, 4, 0, sMakuhitaDojoWork1->unk68, 12);
            break;
        case 1:
            sub_8014248(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][1], 0, sMakuhitaDojoWork1->menuAction, sMakuhitaDojoWork1->unk18, NULL, 4, 0, sMakuhitaDojoWork1->unk68, 12);
            break;
        case 2:
            sMakuhitaDojoWork1->fallbackState = 13;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][2], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 3:
            sMakuhitaDojoWork1->fallbackState = 4;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][3], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 4:
            sub_80302E8(3, NULL, 10);
            break;
        case 5:
            sMakuhitaDojoWork1->fallbackState = 13;
            dLoc.id = sub_80A2740(sMakuhitaDojoWork1->unk10);
            dLoc.floor = 1;
            PrintYellowDungeonNametoBuffer(gAvailablePokemonNames, &dLoc);
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][4], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 7:
            sMakuhitaDojoWork1->fallbackState = 13;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][6], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 6:
            sMakuhitaDojoWork1->fallbackState = 13;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][5], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 8:
            sMakuhitaDojoWork1->fallbackState = 9;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][7], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 9:
            PrintColoredPokeNameToBuffer(gPlayerName, GetPlayerPokemonStruct(), COLOR_YELLOW);
            sMakuhitaDojoWork1->fallbackState = 11;
            PlaySound(203);
            sub_80141B4(sReceivedBonslyDoll, 0, 0, 0x101);
            break;
        case 10:
            sMakuhitaDojoWork1->fallbackState = 13;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][8], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 11:
            sub_801B60C(1, ITEM_GINSENG, 1);
            break;
        case 12:
            sMakuhitaDojoWork1->fallbackState = 1;
            sub_80141B4(gCommonMakuhita[sMakuhitaDojoWork1->isAsleep][9], 0, sMakuhitaDojoWork1->unk68, 0x10D);
            break;
        case 13:
            return;
    }
}

static void MakuhitaDojo_DrawMainMenu(void)
{
    s32 loopMax;

    sMakuhitaDojoWork1->menuAction = 2;
    loopMax = 0;
    sMakuhitaDojoWork1->unk18[loopMax].text = sGoTrain;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = 2;

    if (MakuhitaDojo_ReturnFalse()) {
        sMakuhitaDojoWork1->unk18[loopMax].menuAction = -1;
        sMakuhitaDojoWork1->menuAction = 1;
    }

    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = *gCommonInfo;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = 3;
    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = *gCommonCancel;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = 1;
    loopMax += 1;
    sMakuhitaDojoWork1->unk18[loopMax].text = NULL;
    sMakuhitaDojoWork1->unk18[loopMax].menuAction = 1;
}

static void sub_8030208(void)
{
    s32 menuAction;
    if (sub_80144A4(&menuAction) == 0) {
        sMakuhitaDojoWork1->menuAction = menuAction;

        switch (menuAction) {
            case 2:
                MakuhitaDojo_SetState(3);
                break;
            case 3:
                MakuhitaDojo_SetState(12);
                break;
            case 1:
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