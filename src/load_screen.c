#include "global.h"
#include "globaldata.h"
#include "constants/main_menu.h"
#include "constants/wonder_mail.h"
#include "structs/menu.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "code_8094F88.h"
#include "adventure_info.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "file_system.h"
#include "ground_main.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "play_time.h"
#include "pokemon.h"
#include "rescue_team_info.h"
#include "save.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_util.h"

#define LEGEND_ICON_W 16
#define LEGEND_ICON_H 16
#define LEGEND_ICON_4BPP_LEN (LEGEND_ICON_W * LEGEND_ICON_H / 8)

// Size: 0x8
typedef struct ClmkFileData
{
    /* 0x0 */ /*const */u32 (*packedGFX)[LEGEND_ICON_4BPP_LEN];
    /* 0x4 */ /*const */RGB_Struct (*palette)[16 * 4]; // Contains 4 palettes
} ClmkFileData;

enum
{
    LEGEND_ICON_ZAPDOS,
    LEGEND_ICON_MOLTRES,
    LEGEND_ICON_ARTICUNO,
    LEGEND_ICON_GROUDON,
    LEGEND_ICON_RAYQUAZA,
    LEGEND_ICON_KYOGRE,
    LEGEND_ICON_MEW,
    LEGEND_ICON_HO_OH,
    LEGEND_ICON_CELEBI,
    LEGEND_ICON_LUGIA,
    LEGEND_ICON_MEWTWO,
    LEGEND_ICON_DEOXYS,
    NUM_LEGEND_ICONS
};

// Size: 0x27C
struct LoadScreen
{
    /* 0x000 */ u32 currMenu;
    /* 0x004 */ MenuStruct unk4[4];
    /* 0x144 */ WindowTemplates unk144;
    /* 0x1A4 */ u8 formattedTeamName[36];
    /* 0x1C8 */ u8 formattedPlayerName[36];
    /* 0x1EC */ u8 formattedLocation[36];
    /* 0x210 */ u8 formattedPlayTime[36];
    /* 0x234 */ u8 formattedAdventures[36];
    /* 0x258 */ u8 formattedHelperInfo[36];
};

EWRAM_INIT struct LoadScreen *gLoadScreen = { NULL };

extern unkStruct_203B484 *gUnknown_203B484;

const WindowTemplate gUnknown_80E75F8 = WIN_TEMPLATE_DUMMY;

const WindowTemplate gUnknown_80E7610 = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_NORMAL,
    .pos = { 2, 2 },
    .width = 26,
    .height = 11,
    .totalHeight = 11,
    .unk12 = 0,
    .header = NULL
};

static EWRAM_INIT MenuItem gUnknown_203B378[] = {
    { " ", 5 },
    { NULL, 3 },
};

static EWRAM_INIT u32 sLegendaryQuestIconPalNums[NUM_LEGEND_ICONS] = {
    [LEGEND_ICON_ZAPDOS] =   12,
    [LEGEND_ICON_MOLTRES] =  12,
    [LEGEND_ICON_ARTICUNO] = 14,
    [LEGEND_ICON_GROUDON] =  14,
    [LEGEND_ICON_RAYQUAZA] = 13,
    [LEGEND_ICON_KYOGRE] =   14,
    [LEGEND_ICON_MEW] =      12,
    [LEGEND_ICON_HO_OH] =    13,
    [LEGEND_ICON_CELEBI] =   13,
    [LEGEND_ICON_LUGIA] =    11,
    [LEGEND_ICON_MEWTWO] =   11,
    [LEGEND_ICON_DEOXYS] =   11,
};

static EWRAM_INIT u32 sLegendaryQuestIDs[NUM_LEGEND_ICONS] = {
    [LEGEND_ICON_ZAPDOS] =   QUEST_LEGEND_ZAPDOS,
    [LEGEND_ICON_MOLTRES] =  QUEST_LEGEND_MOLTRES,
    [LEGEND_ICON_ARTICUNO] = QUEST_LEGEND_ARTICUNO,
    [LEGEND_ICON_GROUDON] =  QUEST_LEGEND_GROUDON,
    [LEGEND_ICON_RAYQUAZA] = QUEST_LEGEND_RAYQUAZA,
    [LEGEND_ICON_KYOGRE] =   QUEST_LEGEND_KYOGRE,
    [LEGEND_ICON_MEW] =      QUEST_LEGEND_MEW,
    [LEGEND_ICON_HO_OH] =    QUEST_LEGEND_HO_OH,
    [LEGEND_ICON_CELEBI] =   QUEST_LEGEND_CELEBI,
    [LEGEND_ICON_LUGIA] =    QUEST_LEGEND_LUGIA,
    [LEGEND_ICON_MEWTWO] =   QUEST_LEGEND_MEWTWO,
    [LEGEND_ICON_DEOXYS] =   QUEST_LEGEND_DEOXYS,
};

const WindowTemplate gUnknown_80E762C = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_NORMAL,
    .pos = { 2, 15 },
    .width = 19,
    .height = 3,
    .totalHeight = 3,
    .unk12 = 0,
    .header = NULL
};

const MenuItem gResumeQuicksaveMenuItems[] = {
    { "Resuming from quicksave.", 5 },
    { "Is that OK?", 5 },
    { NULL, 3 },
};

const MenuItem gResumeAdventureMenuItems[] = {
    { "Resuming saved adventure.", 5 },
    { "Is that OK?", 5 },
    { NULL, 3 },
};

const MenuItem gQuitWaitingRescueMenuItems[] = {
    { "Quit awaiting rescue?", 5 },
    { "Is that OK?", 5 },
    { NULL, 3 },
};

const MenuItem gDeleteSavePromptMenuItems[] = {
    { "Your saved data will be", 5 },
    { "deleted. Is that OK?", 5 },
    { NULL, 3 },
};

const MenuItem gDeleteSaveConfirmMenuItems[] = {
    { "Are you sure you want to", 5 },
    { "delete all of your saved data?", 5 },
    { NULL, 3 },
};

const WindowTemplate gUnknown_80E7784 = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_NORMAL,
    .pos = { 23, 15 },
    .width = 5,
    .height = 3,
    .totalHeight = 3,
    .unk12 = 0,
    .header = NULL
};

const MenuItem gLoadScreenYesNoMenu[] = {
    { "Yes", 1 },
    { "No", 2 },
    { NULL, 3 },
};

static void DrawLoadScreenText(void);
static void DrawQuestIcons(void);
static u8 IsQuickSave(void);

void CreateLoadScreen(u32 currMenu)
{
    s32 i;

    if (gLoadScreen == NULL) {
        gLoadScreen = MemoryAlloc(sizeof(struct LoadScreen), 8);
        MemoryFill8(gLoadScreen, 0, sizeof(struct LoadScreen));
    }

    gLoadScreen->currMenu = currMenu;
    for (i = 0; i < MAX_WINDOWS; i++)
        gLoadScreen->unk144.id[i] = gUnknown_80E75F8;

    ResetUnusedInputStruct();
    ShowWindows(&gLoadScreen->unk144, TRUE, TRUE);
    SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 0, &gUnknown_80E7610, gUnknown_203B378, FALSE, 6, FALSE);

    switch (gLoadScreen->currMenu) {
        case MENU_CONTINUE: {
            if (IsQuickSave())
                SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 1, &gUnknown_80E762C, gResumeQuicksaveMenuItems, FALSE, 6, FALSE);
            else
                SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 1, &gUnknown_80E762C, gResumeAdventureMenuItems, FALSE, 6, FALSE);
            break;
        }
        case MENU_AWAITING_RESCUE: {
            SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 1, &gUnknown_80E762C, gQuitWaitingRescueMenuItems, FALSE, 6, FALSE);
            break;
        }
        case MENU_DELETE_SAVE_PROMPT: {
            SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 1, &gUnknown_80E762C, gDeleteSavePromptMenuItems, FALSE, 6, FALSE);
            break;
        }
        case MENU_DELETE_SAVE_CONFIRM: {
            SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 1, &gUnknown_80E762C, gDeleteSaveConfirmMenuItems, FALSE, 6, FALSE);
            break;
        }
    }

    SetMenuItems(gLoadScreen->unk4, &gLoadScreen->unk144, 2, &gUnknown_80E7784, gLoadScreenYesNoMenu, TRUE, 2, FALSE);
    sub_8035CF4(gLoadScreen->unk4, 0, FALSE);
    sub_8035CF4(gLoadScreen->unk4, 1, FALSE);
    sub_8035CF4(gLoadScreen->unk4, 2, TRUE);
    DrawLoadScreenText();
}

void CleanLoadScreen(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    if (gLoadScreen != NULL) {
        MemoryFree(gLoadScreen);
        gLoadScreen = NULL;
    }
}

u32 UpdateLoadScreenMenu(void)
{
    u32 nextMenu;
    u32 menuAction;

    nextMenu = MENU_NO_SCREEN_CHANGE;
    menuAction = 4;
    sub_8012FD8(&gLoadScreen->unk4[1]);

    if (!sub_8012FD8(&gLoadScreen->unk4[2]))
        sub_8013114(&gLoadScreen->unk4[2], &menuAction);

    switch (menuAction) {
        case 3:
        case 2: {
            nextMenu =  MENU_MAIN_SCREEN;
            break;
        }
        case 1: {
            switch (gLoadScreen->currMenu) {
                case MENU_CONTINUE: {
                    nextMenu = 2; // MENU_???
                    break;
                }
                case MENU_AWAITING_RESCUE: {
                    DeleteMailAtIndex(0);
                    nextMenu = 4; // MENU_???
                    break;
                }
                case MENU_DELETE_SAVE_PROMPT: {
                    nextMenu = MENU_DELETE_SAVE_CONFIRM;
                    break;
                }
                case MENU_DELETE_SAVE_CONFIRM: {
                    sub_80122A8();
                    nextMenu = MENU_DELETE_SAVE;
                    break;
                }
            }
            break;
        }
        case 5:
        default: {
            break;
        }
    }

    return nextMenu;
}

static void DrawLoadScreenText(void)
{
    s32 iVar2;
    u32 numAdventures;
    u8 auStack356[100];
    u8 teamNameBuffer[40];
    u8 playerName[80];
    u8 nameHelper[80];
    u8 speciesHelper[20];
    u32 hours;
    u32 minutes;
    u32 seconds;
    Pokemon *playerInfo;
    unkStruct_203B484 *temp2;

    iVar2 = sub_8011FA8();
    CallPrepareTextbox_8008C54(0);
    sub_80073B8(0);
    PrintStringOnWindow(8, 0, _("Team:"), 0, 0);
    PrintStringOnWindow(8, 12, _("Name:"), 0, 0);
    PrintStringOnWindow(8, 24, _("Location:"), 0, 0);
    PrintStringOnWindow(8, 36, _("Play time:"), 0, 0);
    PrintStringOnWindow(8, 48, _("Adventures:"), 0, 0);
    PrintStringOnWindow(8, 60, _("Helper:"), 0, 0);

    // Draw Team Name
    if (CheckQuest(QUEST_SET_TEAM_NAME))
        sub_80920D8(teamNameBuffer);
    else
        InlineStrcpy(teamNameBuffer, _("？？？？"));

    sprintfStatic(gLoadScreen->formattedTeamName, "%s ", teamNameBuffer);
    PrintStringOnWindow(64, 0, gLoadScreen->formattedTeamName, 0, 0);

    // Draw Player Name
    playerInfo = GetLeaderMon1();
    if (playerInfo == NULL)
        StrncpyCustom(playerName, _("???"), POKEMON_NAME_LENGTH);
    else
        StrncpyCustom(playerName, playerInfo->name, POKEMON_NAME_LENGTH);

    sprintfStatic(gLoadScreen->formattedPlayerName, "%s ", playerName);
    PrintStringOnWindow(64, 12, gLoadScreen->formattedPlayerName, 0, 0);

    // Draw Location Info
    if (CountMailType(WONDER_MAIL_TYPE_SOS) != 0 || CountMailType(WONDER_MAIL_TYPE_OKD) != 0) {
        if (iVar2 == 0xF1207)
            PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation,GetDungeonLocationInfo());
        else
            sprintfStatic(gLoadScreen->formattedLocation, _("Quicksave data deleted."));
    }
    else {
        switch (sub_8011C1C()) {
            case 1: {
                switch (GetScriptVarValue(NULL, START_MODE)) {
                    default: {
                        sprintfStatic(auStack356, "%s ", GetCurrentGroundPlaceName());
                        FormatString(auStack356, gLoadScreen->formattedLocation, gLoadScreen->formattedPlayTime, 0);
                        break;
                    }
                    case STARTMODE_CONTINUE_QUICKSAVE:
                    case STARTMODE_11: {
                        sprintfStatic(gLoadScreen->formattedLocation, _("Quicksave data deleted."));
                        break;
                    }
                }
                break;
            }
            case 2: {
                if (iVar2 == 0xF1207)
                    PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation, GetDungeonLocationInfo());
                else
                    sprintfStatic(gLoadScreen->formattedLocation, _("Quicksave data deleted."));
                break;
            }
            default: {
                sprintfStatic(gLoadScreen->formattedLocation, _("Location unknown."));
                break;
            }
        }
    }

    PrintStringOnWindow(64, 24, gLoadScreen->formattedLocation, 0, 0);

    // Draw Play Time
    DeconstructPlayTime(gPlayTimeRef, &hours, &minutes, &seconds);
    sprintfStatic(gLoadScreen->formattedPlayTime, "%d:%02d:%02d ", hours, minutes, seconds);
    PrintStringOnWindow(64, 36, gLoadScreen->formattedPlayTime, 0, 0);

    // Draw Adventures Info
    numAdventures = GetNumAdventures();
    sprintfStatic(gLoadScreen->formattedAdventures, "%d", numAdventures);
    PrintStringOnWindow(64, 48, gLoadScreen->formattedAdventures, 0, 0);

    // Draw Helper Info
    if (iVar2 == 0xF1207) {
        // NOTE: very hacky match here but needed var here to match
        temp2 = gUnknown_203B484;
        if (temp2->unk4.speciesNum != MONSTER_NONE) {
            sub_808D930(speciesHelper, temp2->unk4.speciesNum);
            StrncpyCustom(nameHelper, temp2->unk4.name, POKEMON_NAME_LENGTH);
            sprintfStatic(gLoadScreen->formattedHelperInfo, "%s (%s)", nameHelper, speciesHelper);
        }
        else
            goto print_helper_placeholder; // TODO: Fix
    }
    else {
print_helper_placeholder:
        sprintfStatic(gLoadScreen->formattedHelperInfo, "-----");
    }

    PrintStringOnWindow(64, 60, gLoadScreen->formattedHelperInfo, 0, 0);

    DrawQuestIcons();
    sub_80073E0(0);
}

static void DrawQuestIcons(void)
{
    OpenedFile *clmkFile;
    s32 i;
    s32 x;
    s32 y;

    clmkFile = OpenFileAndGetFileDataPtr("clmkpat", &gTitleMenuFileArchive);
#define CLMKPAT_DATA ((ClmkFileData *)clmkFile->data)

    // Load all 4 palettes
    for (i = 0; i < 16 * 4; i++)
        SetBGPaletteBufferColorArray(i + 0xB0, &(*CLMKPAT_DATA->palette)[i]);

    x = 8;
    y = 73; // Shouldn't this be 72?

    // Draw the legendary icons
    for (i = 0; i < NUM_LEGEND_ICONS; i++) {
        if (CheckQuest(sLegendaryQuestIDs[i])) {
            WriteGFXToBG0Window(0, x, y, LEGEND_ICON_W, LEGEND_ICON_H, CLMKPAT_DATA->packedGFX[i], sLegendaryQuestIconPalNums[i]);
            x += 16;
        }
    }

#undef CLMKPAT_DATA
    CloseFile(clmkFile);
}

static bool8 IsQuickSave(void)
{
    s32 iVar1;
    bool8 isQuicksave;

    iVar1 = sub_8011FA8();
    isQuicksave = FALSE;

    if (CountMailType(WONDER_MAIL_TYPE_SOS) != 0 || CountMailType(WONDER_MAIL_TYPE_OKD) != 0) {
        if (iVar1 == 0xF1207)
            isQuicksave  = TRUE;
    }
    else if (sub_8011C1C() == 2 && iVar1 == 0xF1207)
        isQuicksave = TRUE;

    return isQuicksave;
}

bool8 sub_8039880(void)
{
    return (CountMailType(WONDER_MAIL_TYPE_SOS) != 0 || CountMailType(WONDER_MAIL_TYPE_OKD) != 0 || sub_8011C1C() == 2);
}
