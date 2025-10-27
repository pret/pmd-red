#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "dungeon_tilemap.h"
#include "dungeon_action.h"
#include "status_strings.h"
#include "dungeon_info.h"
#include "dungeon_action.h"
#include "dungeon_engine.h"
#include "dungeon_map_access.h"
#include "dungeon_menu_moves.h"
#include "dungeon_menu_team.h"
#include "dungeon_menu_tile.h"
#include "dungeon_music.h"
#include "dungeon_submenu.h"
#include "dungeon_util.h"
#include "dungeon_strings.h"
#include "input.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_3.h"
#include "trap.h"

static void ShowAndPrintOnTileMenu(DungeonPos *pos, WindowTemplates *windows, WindowHeader *header);
static void AddTileSubMenuOptions(Entity *mon);
static void ShowTileDescription(DungeonPos *pos);

void ShowDungeonTileMenu(Entity *mon)
{
    while (1) {
        s32 inputAction = 0;
        WindowHeader header;
        WindowTemplates windows = {
            .id = {
                [0] = {
                    .type = WINDOW_TYPE_WITH_HEADER,
                    .pos = {2, 2},
                    .width = 18,
                    .height = 4,
                    .unk10 = 16,
                    .unk12 = 0,
                    .header = &header,
                },
                [1] = WIN_TEMPLATE_DUMMY,
                [2] = WIN_TEMPLATE_DUMMY,
                [3] = WIN_TEMPLATE_DUMMY,
            }
        };

        PlayDungeonStartButtonSE();
        ShowAndPrintOnTileMenu(&mon->pos, &windows, &header);
        DungeonRunFrameActions(0x2D);
        AddTileSubMenuOptions(mon);
        gDungeonMenu.cursorArrowPos.x = 0;
        gDungeonMenu.cursorArrowPos.y = 0;
        CreateDungeonMenuSubWindow(&windows.id[0], 22);

        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x2D);
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
                    ShowTileDescription(&mon->pos);
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
        DungeonRunFrameActions(0x2D);
        if (inputAction != 2)
            break;
    }

    sub_803EAF0(0, NULL);
}

static void ShowAndPrintOnTileMenu(DungeonPos *pos, WindowTemplates *windows, WindowHeader *header)
{
    u8 text[80];
    const Tile *tile;

    header->count = 1;
    header->currId = 0;
    header->width = 12;
    header->f3 = 0;
    DungeonShowWindows(windows, TRUE);
    sub_80073B8(0);
    tile = GetTile(pos->x, pos->y);

    PrintStringOnWindow(12, 0, gUnknown_80FE708, 0, '\0');
    if (EntityIsValid(tile->object)) {
        SubstitutePlaceholderStringTags(text, tile->object, 0);
        PrintStringOnWindow(8, 18, text, 0, '\0');
    }
    sub_80073E0(0);
}

static void AddTileSubMenuOptions(Entity *mon)
{
    gDungeonSubMenuItemsCount = 0;
    AddActionToDungeonSubMenu(ACTION_STEPPED_ON_TRAP, 0);
    AddActionToDungeonSubMenu(ACTION_SHOW_INFO, 0);
    sub_8045064();
}

static void ShowTileDescription(DungeonPos *pos)
{
    while (1) {
        const Tile *tile;
        Entity *object;
        Trap *trap;
        bool8 bPress = FALSE;
        STATUSTEXTS(statuses);
        TouchScreenMenuInput menuSub;
        WindowHeader header;
        WindowTemplates windows = {
            .id = {
                [0] = {
                    .type = WINDOW_TYPE_WITH_HEADER,
                    .pos = {2, 2},
                    .width = 26,
                    .height = 12,
                    .unk10 = 12,
                    .unk12 = 0,
                    .header = &header,
                },
                [1] = WIN_TEMPLATE_DUMMY,
                [2] = WIN_TEMPLATE_DUMMY,
                [3] = WIN_TEMPLATE_DUMMY,
            }
        };
        u8 trapName[0x60];
        s32 i, statusesCount;

        ResetTouchScreenMenuInput(&menuSub);
        header.count = 1;
        header.currId = 0;
        header.width = 16;
        header.f3 = 0;

        tile = GetTile(pos->x, pos->y);
        object = tile->object;
        if (object == NULL)
            break;
        if (GetEntityType(object) != ENTITY_TRAP)
            break;

        DungeonShowWindows(&windows, FALSE);
        trap = GetTrapInfo(object);
        GetTrapName(trapName, trap->id);
        sub_80073B8(0);
        PrintStringOnWindow(16, 0, trapName, 0, '\0');
        PrintStringOnWindow(8, 24, gTrapDescriptions[trap->id], 0, '\0');
        sub_80073E0(0);
        statusesCount = PrepareStatusStringArrays(gTrapDescriptions[trap->id], statuses);
        while (1) {
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
            while (1) {
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
