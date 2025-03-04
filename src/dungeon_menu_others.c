#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_others.h"
#include "dungeon_submenu.h"
#include "dungeon.h"
#include "text.h"
#include "menu_input.h"
#include "input.h"
#include "code_8044CC8.h"
#include "dungeon_action.h"
#include "dungeon_util.h"
#include "dungeon_map_access.h"
#include "dungeon_leader.h"
#include "code_8045A00.h"
#include "code_8097DD0.h"
#include "dungeon_message.h"
#include "game_options.h"
#include "post_office_guide2.h"
#include "dungeon_main.h"

extern void PlayDungeonStartButtonSE(void);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void PlayDungeonCursorSE(u8 param_1);
extern void sub_803EAF0(u32, u8 *);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void DungeonRunFrameActions(u32 a0);
extern void DungeonShowWindows(WindowTemplates *a0, bool8 a1);
extern void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
extern void sub_8045064(void);
extern void sub_8040A84(void);
extern bool8 IsBossFight(void);
extern u16 GetLeaderActionId(void);
extern void sub_803E13C(void);
extern void sub_8040238(void);
extern void sub_8083AB0(s16 param_0, Entity * target, Entity * entity);

extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonSubMenuItemsCount;
extern s32 gUnknown_202F2E0;
extern GameOptions gUnknown_202F2E8;

extern const u8 *const gUnknown_80FEBF8;
extern const u8 *const gUnknown_80FEC28;
extern const u8 *const gUnknown_80FDE6C;
extern const u8 *const gUnknown_80FDEB8;
extern const u8 *const gUnknown_80FEA44;
extern const u8 *const gUnknown_80FEA50;
extern const u8 *const gUnknown_80FEA28;
extern const u8 *const gUnknown_80FEA10;
extern const u8 *const gUnknown_80FE9F8;
extern const u8 *const gUnknown_80FE9E8;
extern const u8 *const gUnknown_80FE9CC;
extern const u8 *const gUnknown_80FE8F8;
extern const u8 *const gUnknown_80FE8F4;
extern const u8 *const gGameOptionsTextPtr;
extern const u8 *const gOptionsDungeonTextPtr;
extern const u8 *const gOptionsOthersTextPtr;
extern const u8 *const gUnknown_80FE748;
extern const u8 *const gUnknown_80FE764;
extern const u8 *const gUnknown_80FE7C0;
extern const u8 *const gUnknown_80FE788;
extern const u8 *const gUnknown_80FE7A8;
extern const u8 *const gUnknown_80FE7E4;

void PrintOthersMenuOptions(void);
void ShowGameOptionsMenu(void);
void ShowQuickSaveGiveUpMenu(void);
void ShowMissionObjectivesMenu(void);
void ShowRecruitmentSearchMenu(void);
void ShowHintsMenu(void);
bool8 ShowDungeonOptions(void);
bool8 ShowOthersOptions(void);
void TrySetNewGameOptions(bool8 bPressed);
void AskToResetToDefault(void);
void PrintGameOptions(void);
void PrintDungeonOptions(void);
void sub_8065948(void);
void sub_8065A8C(s32 optionId);
void sub_8065B3C(s32 optionId);
bool8 sub_8065BEC(void);
bool8 sub_8065BF0(void);
bool8 AskToQuickSave(void);
bool8 AskToGiveUp(void);
void PrintQuickSaveMenuOptions(void);

enum {
    OTHERS_GAME_OPTIONS,
    OTHERS_QUICKSAVE_GIVEUP,
    OTHERS_MESSAGE_LOG,
    OTHERS_MISSION_OBJECTIVES,
    OTHERS_RECRUITMENT_SEARCH,
    OTHERS_HINTS,
    OTHERS_COUNT
};

void ShowDungeonOthersMenu(void)
{
    bool8 unkAlwaysFalse;
    s32 hintsMenuId = (gDungeon->unk644.canRecruit) ? OTHERS_HINTS : OTHERS_HINTS - 1;

    gUnknown_202F2E0 = 0;
    unkAlwaysFalse = FALSE;
    while (1) {
        bool8 bPress = FALSE;

        PrintOthersMenuOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                if (gDungeonMenu.menuIndex != OTHERS_RECRUITMENT_SEARCH || (gDungeon->unk644.canRecruit && !IsBossFight())) {
                    PlayDungeonConfirmationSE();
                }
                else {
                    PlayDungeonCancelSE();
                }
                break;
            }
            else if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (unkAlwaysFalse)
            continue;
        if (bPress)
            break;

        gUnknown_202F2E0 = gDungeonMenu.menuIndex;
        if (gUnknown_202F2E0 == OTHERS_GAME_OPTIONS) {
            ShowGameOptionsMenu();
        }
        if (gUnknown_202F2E0 == OTHERS_QUICKSAVE_GIVEUP) {
            ShowQuickSaveGiveUpMenu();
        }
        if (gUnknown_202F2E0 == OTHERS_MESSAGE_LOG) {
            DisplayMessageLog();
        }
        if (gUnknown_202F2E0 == OTHERS_MISSION_OBJECTIVES) {
            ShowMissionObjectivesMenu();
        }
        if (gDungeon->unk644.canRecruit && !IsBossFight() && gUnknown_202F2E0 == OTHERS_RECRUITMENT_SEARCH) {
            ShowRecruitmentSearchMenu();
        }
        if (gUnknown_202F2E0 == hintsMenuId) {
            ShowHintsMenu();
        }

        if (gDungeon->unk4)
            break;
        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }

    sub_8040A84();
    sub_803EAF0(0, NULL);
}

enum {
    GAME_OPTION_DUNGEON,
    GAME_OPTION_OTHERS,
    GAME_OPTION_DEFAULT,
};

void ShowGameOptionsMenu(void)
{
    while (1) {
        bool8 bPress = FALSE;

        PrintGameOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (bPress)
            break;

        gUnknown_202F2E8 = *gGameOptionsRef;
        if (gDungeonMenu.menuIndex == GAME_OPTION_DUNGEON) {
            bPress = ShowDungeonOptions();
            TrySetNewGameOptions(bPress);
        }
        else if (gDungeonMenu.menuIndex == GAME_OPTION_OTHERS) {
            bPress = ShowOthersOptions();
            TrySetNewGameOptions(bPress);
        }
        else if (gDungeonMenu.menuIndex == GAME_OPTION_DEFAULT) {
            AskToResetToDefault();
        }
    }

    sub_803EAF0(0, NULL);
}

enum {
    OPTION_SPEED,
    OPTION_FAR_OFF_PALS,
    OPTION_DAMAGE_TURN,
    OPTION_GRIDS,
    OPTION_MAP,
    OPTION_WINDOWS,
};

#define DUNGEON_OPTIONS_COUNT OPTION_WINDOWS

bool8 ShowDungeonOptions(void)
{
    bool8 dpadMoved;
    bool8 bPress = FALSE;

    gDungeonMenu.menuIndex = 0;
    while (1) {
        bPress = FALSE;
        dpadMoved = FALSE;

        PrintDungeonOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if (gRealInputs.repeated & DPAD_LEFT) {
                PlayDungeonCursorSE(FALSE);
                sub_8065A8C(gDungeonMenu.menuIndex);
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayDungeonCursorSE(FALSE);
                sub_8065B3C(gDungeonMenu.menuIndex);
                dpadMoved = TRUE;
                break;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }

            if (sub_8065BEC()) {
                dpadMoved = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (!dpadMoved)
            break;
    }

    return bPress;
}

bool8 ShowOthersOptions(void)
{
    bool8 dpadMoved;
    bool8 bPress = FALSE;

    gDungeonMenu.menuIndex = 0;
    while (1) {
        bPress = FALSE;
        dpadMoved = FALSE;

        sub_8065948();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if (gRealInputs.repeated & DPAD_LEFT) {
                PlayDungeonCursorSE(FALSE);
                sub_8065A8C(gDungeonMenu.menuIndex + DUNGEON_OPTIONS_COUNT);
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayDungeonCursorSE(FALSE);
                sub_8065B3C(gDungeonMenu.menuIndex + DUNGEON_OPTIONS_COUNT);
                dpadMoved = TRUE;
                break;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }

            if (sub_8065BF0()) {
                dpadMoved = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (!dpadMoved)
            break;
    }

    return bPress;
}

void TrySetNewGameOptions(bool8 bPressed)
{
    bool8 optionsChanged = FALSE;

    if (bPressed) {
        if (!GameOptionsNotChange(&gUnknown_202F2E8))
            optionsChanged = TRUE;
    }
    else {
        optionsChanged = TRUE;
    }

    if (optionsChanged) {
        if (DisplayDungeonYesNoMessage(0, gUnknown_80FEBF8, TRUE) == 1) {
            *gGameOptionsRef = gUnknown_202F2E8;
            sub_803E13C();
            sub_8040238();
        }
    }
}

void AskToResetToDefault(void)
{
    if (DisplayDungeonYesNoMessage(0, gUnknown_80FEC28, FALSE) == 1) {
        InitializeGameOptions(FALSE);
        sub_803E13C();
    }
}

void ShowQuickSaveGiveUpMenu(void)
{
    bool8 unkAlwaysFalse = FALSE;
    while (1) {
        bool8 bPress = FALSE;

        PrintQuickSaveMenuOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);

        if (unkAlwaysFalse)
            continue;
        if (bPress)
            break;

        if (gDungeonMenu.menuIndex == 0) {
            AskToQuickSave();
        }
        else if (gDungeonMenu.menuIndex == 1) {
            AskToGiveUp();
        }

        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }
}

void ShowMissionObjectivesMenu(void)
{
    sub_80319A4(gDungeon->unk644.unk34, gDungeon->unk644.dungeonLocation.id, 0);
    do {
        DungeonRunFrameActions(0x47);
    } while (sub_80319F8() == 0);
    sub_8031A3C();
}

bool8 AskToQuickSave(void)
{
    if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDE6C, FALSE) != 1) {
        return TRUE;
    }
    SetMonsterActionFields(GetLeaderActionContainer(), ACTION_QUICK_SAVE);
    return FALSE;
}

bool8 AskToGiveUp(void)
{
    if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDEB8, FALSE) != 1) {
        return TRUE;
    }
    SetMonsterActionFields(GetLeaderActionContainer(), ACTION_GIVE_UP);
    sub_8083AB0(0x21B, NULL, GetLeader());
    gDungeon->unk644.unk10 = 1;
    return FALSE;
}

void PrintOthersMenuOptions(void)
{
    s32 optionsCount, currOptionId;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;
    gDungeonMenu.menuIndex = gUnknown_202F2E0;
    optionsCount = (gDungeon->unk644.canRecruit) ? OTHERS_COUNT : OTHERS_COUNT - 1;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 18;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    currOptionId = 0;
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE8F8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9CC, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9E8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9F8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA10, 0, '\0');
    if (gDungeon->unk644.canRecruit) {
        if (!IsBossFight()) {
            PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA28, 0, '\0');
        }
        else {
            PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA44, 0, '\0');
        }
    }
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId), gUnknown_80FEA50, 0, '\0');

    sub_80073E0(0);
}

struct Struct_80F7C50
{
    const u8 *str;
    s32 val;
};

// TODO: Fix this table in other file

extern const struct Struct_80F7C50 gUnknown_80F7C50[];

void PrintQuickSaveMenuOptions(void)
{
    s32 optionsCount, currOptionId;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;
    gDungeonMenu.menuIndex = 0;
    optionsCount = 2;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 18;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    currOptionId = 0;
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE8F4, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80F7C50[43].str, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80F7C50[46].str, 0, '\0');

    sub_80073E0(0);
}

void PrintGameOptions(void)
{
    s32 optionsCount;
    s32 y[3];
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 12,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;
    gDungeonMenu.menuIndex = 0;
    optionsCount = 3;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 12;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);

    y[0] = GetMenuEntryYCoord(&gDungeonMenu, 0);
    y[1] = GetMenuEntryYCoord(&gDungeonMenu, 1);
    y[2] = GetMenuEntryYCoord(&gDungeonMenu, 2);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gGameOptionsTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[0], gOptionsDungeonTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[1], gOptionsOthersTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[2], gUnknown_80FE748, 0, '\0');
    sub_80073E0(0);
}

void PrintDungeonOptions(void)
{
    s32 y[DUNGEON_OPTIONS_COUNT];
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };
    s32 arr[] = {16, 25, 27};

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;

    gDungeonMenu.unk1A = DUNGEON_OPTIONS_COUNT;
    gDungeonMenu.unk1C = DUNGEON_OPTIONS_COUNT;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 24;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(DUNGEON_OPTIONS_COUNT, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);

    y[0] = GetMenuEntryYCoord(&gDungeonMenu, 0);
    y[1] = GetMenuEntryYCoord(&gDungeonMenu, 1);
    y[2] = GetMenuEntryYCoord(&gDungeonMenu, 2);
    y[3] = GetMenuEntryYCoord(&gDungeonMenu, 3);
    y[4] = GetMenuEntryYCoord(&gDungeonMenu, 4);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gOptionsDungeonTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[0], gUnknown_80FE764, 0, '\0');
    PrintFormattedStringOnWindow(8, y[1], gUnknown_80FE788, 0, '\0');
    PrintFormattedStringOnWindow(8, y[2], gUnknown_80FE7A8, 0, '\0');
    PrintFormattedStringOnWindow(8, y[3], gUnknown_80FE7C0, 0, '\0');
    PrintFormattedStringOnWindow(8, y[4], gUnknown_80FE7E4, 0, '\0');

    if (gUnknown_202F2E8.dungeonSpeed != DUNGEON_SPEED_SLOW) {
        AddDoubleUnderScoreHighlight(0, 136, y[0] + 10, 21, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[0] + 10, 22, 7);
    }

    if (gUnknown_202F2E8.FarOffPals != FAROFFPALS_SELF) {
        AddDoubleUnderScoreHighlight(0, 136, y[1] + 10, 22, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[1] + 10, 18, 7);
    }

    if (gUnknown_202F2E8.damageTurn) {
        AddDoubleUnderScoreHighlight(0, 136, y[2] + 10, 16, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[2] + 10, 12, 7);
    }

    if (gUnknown_202F2E8.gridEnable) {
        AddDoubleUnderScoreHighlight(0, 136, y[3] + 10, 12, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[3] + 10, 16, 7);
    }

    AddDoubleUnderScoreHighlight(0, 80 + (gUnknown_202F2E8.mapOption * 40), y[4] + 10, arr[gUnknown_202F2E8.mapOption], 7);

    sub_80073E0(0);
}

//
