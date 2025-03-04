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

void sub_8065250(void);
void ShowGameOptionsMenu(void);
void ShowQuickSaveGiveUpMenu(void);
void ShowMissionObjectivesMenu(void);
void ShowRecruitmentSearchMenu(void);
void ShowHintsMenu(void);
bool8 ShowDungeonOptions(void);
bool8 ShowOthersOptions(void);
void TrySetNewGameOptions(bool8 bPressed);
void AskToResetToDefault(void);
void sub_8065574(void);
void sub_80656C0(void);
void sub_8065948(void);
void sub_8065A8C(s32 optionId);
void sub_8065B3C(s32 optionId);
bool8 sub_8065BEC(void);
bool8 sub_8065BF0(void);
bool8 AskToQuickSave(void);
bool8 AskToGiveUp(void);
void sub_806544C(void);

enum {
    OTHERS_GAME_OPTIONS,
    OTHERS_QUICKSAVE_GIVEUP,
    OTHERS_MESSAGE_LOG,
    OTHERS_MISSION_OBJECTIVES,
    OTHERS_RECRUITMENT_SEARCH,
    OTHERS_HINTS,
};

void ShowDungeonOthersMenu(void)
{
    bool8 unkAlwaysFalse;
    s32 hintsMenuId = (gDungeon->unk644.canRecruit) ? OTHERS_HINTS : OTHERS_HINTS - 1;

    gUnknown_202F2E0 = 0;
    unkAlwaysFalse = FALSE;
    while (1) {
        bool8 bPress = FALSE;

        sub_8065250();
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

        sub_8065574();
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

#define FIRST_OTHERS_OPTION OPTION_WINDOWS

bool8 ShowDungeonOptions(void)
{
    bool8 dpadMoved;
    bool8 bPress = FALSE;

    gDungeonMenu.menuIndex = 0;
    while (1) {
        bPress = FALSE;
        dpadMoved = FALSE;

        sub_80656C0();
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
                sub_8065A8C(gDungeonMenu.menuIndex + FIRST_OTHERS_OPTION);
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayDungeonCursorSE(FALSE);
                sub_8065B3C(gDungeonMenu.menuIndex + FIRST_OTHERS_OPTION);
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

        sub_806544C();
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

//
