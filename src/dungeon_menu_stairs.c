#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "dungeon_tilemap.h"
#include "dungeon_action.h"
#include "status_strings.h"
#include "dungeon_info.h"
#include "dungeon_action.h"
#include "dungeon_generation.h"
#include "dungeon_map_access.h"
#include "dungeon_menu_moves.h"
#include "dungeon_menu_stairs.h"
#include "dungeon_menu_team.h"
#include "dungeon_music.h"
#include "dungeon_submenu.h"
#include "dungeon_util.h"
#include "dungeon_strings.h"
#include "dungeon_engine.h"
#include "run_dungeon.h"
#include "input.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_3.h"

static void ShowAndPrintOnStairsMenu(DungeonPos *pos, WindowTemplates *windows, WindowHeader *header);
static void AddStairsSubMenuOptions(Entity *mon);
static void ShowStairsDescription(DungeonPos *pos);

// Pretty much a copy of ShowDungeonTileMenu
void ShowDungeonStairsMenu(Entity *mon)
{
    while (TRUE) {
        s32 inputAction = 0;
        WindowHeader header;
        WindowTemplates windows = {
            .id = {
                [0] = {
                    .type = WINDOW_TYPE_WITH_HEADER,
                    .pos = { 2, 2 },
                    .width = 18,
                    .height = 4,
                    .heightInTiles = 16,
                    .unk12 = 0,
                    .header = &header,
                },
                [1] = WIN_TEMPLATE_DUMMY,
                [2] = WIN_TEMPLATE_DUMMY,
                [3] = WIN_TEMPLATE_DUMMY,
            }
        };

        PlayDungeonStartButtonSE();
        ShowAndPrintOnStairsMenu(&mon->pos, &windows, &header);
        DungeonRunFrameActions(0x2E);
        AddStairsSubMenuOptions(mon);
        gDungeonMenu.cursorArrowPos.x = 0;
        gDungeonMenu.cursorArrowPos.y = 0;
        CreateDungeonMenuSubWindow(&windows.id[0], 22);

        while (TRUE) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x2E);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.touchScreen.a_button) {
                if (gDungeonMenu.menuIndex == 1) {
                    PlayDungeonConfirmationSE();
                    ShowStairsDescription(&mon->pos);
                    inputAction = 2;
                    break;
                }
                else if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                    ActionContainer *action = &GetEntInfo(mon)->action;

                    SetMonsterActionFields(action, gDungeonSubMenu[gDungeonMenu.menuIndex].actionId);
                    PlayDungeonConfirmationSE();
                    action->actionParameters[0].actionUseIndex = 0;
                    action->actionParameters[0].itemPos.x = 0;
                    action->actionParameters[0].itemPos.y = 0;
                    action->actionParameters[1].actionUseIndex = 0;
                    action->actionParameters[1].itemPos.x = 0;
                    action->actionParameters[1].itemPos.y = 0;
                    inputAction = 0;
                    break;
                }
                PlayDungeonCancelSE();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.touchScreen.b_button) {
                PlayDungeonCancelSE();
                inputAction = 1;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x2E);
        if (inputAction != 2)
            break;
    }

    sub_803EAF0(0, NULL);
}

static void ShowAndPrintOnStairsMenu(DungeonPos *pos, WindowTemplates *windows, WindowHeader *header)
{
    const u8 *str;

    header->count = 1;
    header->currId = 0;
    header->width = 11;
    header->f3 = 0;
    DungeonShowWindows(windows, TRUE);
    sub_80073B8(0);
    switch (GetFloorType()) {
        default:
        case FLOOR_TYPE_NORMAL:
            str = gUnknown_80FE70C;
            break;
        case FLOOR_TYPE_RESCUE:
            str = gUnknown_80FE720;
            break;
        case FLOOR_TYPE_FIXED:
            str = gUnknown_80FE724;
            break;
    }
    PrintStringOnWindow(12, 0, str, 0, '\0');
    PrintStringOnWindow(8, 18, str, 0, '\0');
    sub_80073E0(0);
}

static void AddStairsSubMenuOptions(Entity *mon)
{
    gDungeonSubMenuItemsCount = 0;
    AddActionToDungeonSubMenu(ACTION_STAIRS, 0);
    AddActionToDungeonSubMenu(ACTION_SHOW_INFO, 0);
    sub_8045064();
}

// Again, almost identical to its Tile counterpart.
static void ShowStairsDescription(DungeonPos *pos)
{
    while (TRUE) {
        u8 floorType;
        bool8 bPress;
        STATUSTEXTS(statuses);
        TouchScreenMenuInput menuSub;
        WindowHeader header;
        WindowTemplates windows = {
            .id = {
                [0] = {
                    .type = WINDOW_TYPE_WITH_HEADER,
                    .pos = { 2, 2 },
                    .width = 26,
                    .height = 12,
                    .heightInTiles = 12,
                    .unk12 = 0,
                    .header = &header,
                },
                [1] = WIN_TEMPLATE_DUMMY,
                [2] = WIN_TEMPLATE_DUMMY,
                [3] = WIN_TEMPLATE_DUMMY,
            }
        };
        s32 i, statusesCount;

        ResetTouchScreenMenuInput(&menuSub);
        header.count = 1;
        header.currId = 0;
        header.width = 16;
        header.f3 = 0;

        DungeonShowWindows(&windows, FALSE);
        floorType = GetFloorType();
        sub_80073B8(0);
        PrintStringOnWindow(16, 0, gUnknown_80F8104[floorType], 0, '\0');
        PrintStringOnWindow(8, 24, gUnknown_80F7F70[floorType], 0, '\0');
        sub_80073E0(0);
        statusesCount = PrepareStatusStringArrays(gUnknown_80F7F70[floorType], statuses);
        while (TRUE) {
            if (statusesCount != 0) {
                ShowStatusDescriptionMenuArrow();
            }
            GetTouchScreenMenuInput(&menuSub, 0);
            DungeonRunFrameActions(0x16);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                PlayDungeonConfirmationSE();
                bPress = FALSE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }
        if (bPress || statusesCount == 0)
            break;

        for (i = 0; i < statusesCount; i++) {
            ShowStatusDescriptionMenu(statuses[i], &menuSub);
            while (TRUE) {
                if (i < statusesCount - 1) {
                    ShowStatusDescriptionMenuArrow();
                }
                GetTouchScreenMenuInput(&menuSub, 0);
                DungeonRunFrameActions(0x16);
                if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                    PlayDungeonConfirmationSE();
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                    PlayDungeonCancelSE();
                    break;
                }
            }
        }
    }

    sub_803EAF0(0, NULL);
}
