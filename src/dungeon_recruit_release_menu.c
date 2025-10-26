#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/item.h"
#include "constants/move_id.h"
#include "dungeon_vram.h"
#include "dungeon_tilemap.h"
#include "dungeon_8041AD0.h"
#include "dungeon_action.h"
#include "dungeon_mon_sprite_render.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_move.h"
#include "dungeon_move_util.h"
#include "dungeon_logic.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "position_util.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "trap.h"
#include "dungeon_submenu.h"
#include "dungeon_engine.h"

static EWRAM_DATA WindowHeader sReleaseMenuWinHeader = {0};
static EWRAM_DATA s32 gUnknown_202F30C = 0;
static EWRAM_DATA s32 gUnknown_202F310 = 0;

static void sub_8067F00(u8 a0, Pokemon **a1, s32 a2_, s32 a3, s32 a4);
static void ShowPokemonSummary(Pokemon *a0);
static void sub_8068310(s32 n, Pokemon **monPtrs);
static void ShowUpArrowSprite(void);
static void ShowDownArrowSprite(void);

// It's likely a struct only used in Blue version. Touchpad maybe?
static const u8 sTouchScreenArrowPressData[] = {
    0x01, 0, 0x38, 0, 0, 0, 0x18, 0, 0x18, 0, 0, 0, 0x02, 0, 0x38, 0, 0x68, 0, 0x18, 0, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const WindowTemplates sReleaseMenuWindowTemplates = {
    .id = {
        [0] =
        {
            .unk0 = 0,
            .type = WINDOW_TYPE_WITH_HEADER,
            .pos = {0x02, 0x02},
            .width = 0x11,
            .height = 0x0E,
            .unk10 = 0x12,
            .unk12 = 0x02,
            .header = &sReleaseMenuWinHeader
        },
        [1] =
        {
            .unk0 = 0,
            .type = WINDOW_TYPE_NORMAL,
            .pos = {0x15, 0x04},
            .width = 0x07,
            .height = 0x04,
            .unk10 = 0x04,
            .unk12 = 0,
            .header = NULL
        },
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

void ShowRecruitReleaseMenu(u8 a0, s32 a1, s32 a2, Pokemon **a3)
{
    s32 i;
    s32 r10;
    WindowTemplates winTemplates = sReleaseMenuWindowTemplates;

    gUnknown_202F30C = 0;
    r10 = 0;
    for (i = 0; i < a2; i++) {
        a3[i]->flags &= ~(POKEMON_FLAG_x8000);
    }

    while (1) {
        sub_8068310(a2, a3);
        if (gUnknown_202F310 >= a1)
            break;
        while (1) {
            s32 r7 = 0, r5 = 0;

            sReleaseMenuWinHeader.count = 1;
            sReleaseMenuWinHeader.currId = 0;
            sReleaseMenuWinHeader.width = 0xE;
            sReleaseMenuWinHeader.f3 = 0;

            ASM_MATCH_TRICK(r7);

            DungeonShowWindows(&winTemplates, 1);
            sub_8067F00(a0, a3, gUnknown_202F30C, a2, a1);
            gDungeonMenu.currPageEntries = min(a2, 8);
            gDungeonMenu.menuIndex = r10;
            gDungeonMenu.entriesPerPage = 8;
            gDungeonMenu.currPage = 0;
            gDungeonMenu.pagesCount = 0;
            gDungeonMenu.unk4 = 0;
            gDungeonMenu.firstEntryY = 18;
            gDungeonMenu.leftRightArrowsPos.x = 0;
            gDungeonMenu.leftRightArrowsPos.y = 0;
            gDungeonMenu.unk14.x = 0;
            gDungeonMenu.windowId = 0;
            ResetTouchScreenMenuInput(&gDungeonMenu.touchScreen);
            sub_80137B0(&gDungeonMenu, 0);
            while (1) {
                s32 touchScreenArrow;

                AddMenuCursorSprite(&gDungeonMenu);
                r5 = 0;
                r7 = 0;
                if (a2 - gUnknown_202F30C > 8) {
                    r5 = 1;
                    ShowDownArrowSprite();
                }
                if (gUnknown_202F30C != 0) {
                    r7 = 1;
                    ShowUpArrowSprite();
                }

                touchScreenArrow = GetTouchScreenArrowPress(0, sTouchScreenArrowPressData);
                DungeonRunFrameActions(0x37);
                if (touchScreenArrow == TOUCH_SCREEN_ARROW_DOWN_PRESS && r5) {
                    if (a2 - gUnknown_202F30C > 8) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollDownWindowFunc(0);
                            DungeonRunFrameActions(0x37);
                        }
                        gUnknown_202F30C++;
                    }
                    r7 = 0;
                    r10 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 7) {
                        if (a2 - gUnknown_202F30C > 8) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                ScrollDownWindowFunc(0);
                                DungeonRunFrameActions(0x37);
                            }
                            gUnknown_202F30C++;
                        }
                        r7 = 0;
                        r10 = 7;
                        break;
                    }
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, 0);
                }

                if (touchScreenArrow == TOUCH_SCREEN_ARROW_UP_PRESS && r7 != 0) {
                    if (gUnknown_202F30C != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollUpWindowFunc(0);
                            DungeonRunFrameActions(0x37);
                        }
                        gUnknown_202F30C--;
                    }
                    r7 = 0;
                    r10 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 0) {
                        if (gUnknown_202F30C != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                ScrollUpWindowFunc(0);
                                DungeonRunFrameActions(0x37);
                            }
                            gUnknown_202F30C--;
                        }
                        r7 = 0;
                        r10 = 0;
                        break;
                    }
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, 0);
                }

                if (sub_80048C8()) {
                    continue;
                }

                if (gRealInputs.pressed & START_BUTTON) {
                    sub_8083D1C();
                    r7 = 3;
                    break;
                }
                if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.touchScreen.a_button) {
                    PlayDungeonConfirmationSE();
                    r7 = 1;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.touchScreen.b_button) {
                    PlayDungeonCancelSE();
                    r7 = 2;
                    break;
                }
            }

            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x37);
            if (r7 == 0) {
                continue;
            }
            else if (r7 == 2) {
                r10 = gDungeonMenu.menuIndex;
                if (gUnknown_202F310 < a1) {
                    continue;
                }

                if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDFB8, TRUE) == 1) {
                    break;
                }
                else {
                    continue;
                }
            }
            else if (r7 == 3) {
                r10 = gDungeonMenu.menuIndex;
                ShowPokemonSummary(a3[gUnknown_202F30C + r10]);
                continue;
            }
            else {
                s32 arrId;
                u8 locIdIsPartner;

                r10 = gDungeonMenu.menuIndex;
                arrId = gUnknown_202F30C + r10;
                gDungeonSubMenuItemsCount = 0;
                AddActionToDungeonSubMenu(0x29, 0);
                AddActionToDungeonSubMenu(0x2A, 0);
                AddActionToDungeonSubMenu(0x40, 0);
                if (a3[arrId]->flags & POKEMON_FLAG_x8000) {
                    SetActionUnusableInDungeonSubMenu(0x29);
                }
                else {
                    SetActionUnusableInDungeonSubMenu(0x2A);
                }

                // This unnecessary variable is required to match.
                locIdIsPartner = DUNGEON_JOIN_LOCATION_PARTNER;
                if (a3[arrId]->isTeamLeader || (a3[arrId]->dungeonLocation.id == DUNGEON_JOIN_LOCATION_LEADER || a3[arrId]->dungeonLocation.id == locIdIsPartner)) {
                    SetActionUnusableInDungeonSubMenu(0x29);
                }

                sub_8045064();
                CreateDungeonMenuSubWindow(&winTemplates.id[0], 0x15);

                while (1) {
                    AddMenuCursorSprite(&gDungeonMenu);
                    DungeonRunFrameActions(0x37);

                    if (gRealInputs.repeated & DPAD_DOWN) {
                        PlayDungeonCursorSE(1);
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, 1);
                    }
                    if (gRealInputs.repeated & DPAD_UP) {
                        PlayDungeonCursorSE(1);
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, 1);
                    }

                    if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.touchScreen.a_button) {
                        if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                            PlayDungeonConfirmationSE();
                            r7 = 1;
                            break;
                        }
                        PlayDungeonCancelSE();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.touchScreen.b_button) {
                        PlayDungeonCancelSE();
                        r7 = 0;
                        break;
                    }
                }

                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x37);
                if (r7 != 0) {
                    if (gDungeonMenu.menuIndex == 0) {
                        a3[arrId]->flags |= POKEMON_FLAG_x8000;
                        sub_8068310(a2, a3);
                    }
                    else if (gDungeonMenu.menuIndex == 1) {
                        a3[arrId]->flags &= ~(POKEMON_FLAG_x8000);
                        sub_8068310(a2, a3);
                    }
                    else {
                        ShowPokemonSummary(a3[arrId]);
                    }
                }
                continue;
            }
        }
    }
}

static void sub_8067F00(u8 a0, Pokemon **a1, s32 a2_, s32 a3, s32 a4)
{
    s32 i, y;
    s32 a2;

    a2 = a2_ - 1;
    y = 0x16;

    sub_80073B8(0);
    WriteFriendAreaName(gFormatBuffer_Monsters[0], a0, FALSE);
    PrintFormattedStringOnWindow(12, 0, _("{POKEMON_0}"), 0, '\0');
    i = 0;
    while (i < 10) {
        if (a2 >= 0) {
            if (a2 >= a3) {
                break;
            }

            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0], a1[a2], 0);
            sub_808D930(gFormatBuffer_Monsters[1], a1[a2]->speciesNum);
            gFormatArgs[0] = a2 + 1;
            if (a1[a2]->flags & POKEMON_FLAG_x8000) {
                InlineStrcpy(gFormatBuffer_Items[0], _("{STAR_BULLET}"));
            }
            else {
                InlineStrcpy(gFormatBuffer_Items[0], _("{ICON_BLANK}"));
            }

            if (a1[a2]->flags & POKEMON_FLAG_x4000) {
                PrintFormattedStringOnWindow(7, y, _("{MOVE_ITEM_0}{color CYAN}$v02:{POKEMON_0}{reset}"), 0, '\0');
            }
            else {
                PrintFormattedStringOnWindow(7, y, _("{MOVE_ITEM_0}{color YELLOW}$v02:{POKEMON_0}{reset}"), 0, '\0');
            }
        }

        i++;
        y += 12;
        a2++;
    }

    sub_80073E0(0);
    sub_80073B8(1);
    if (gUnknown_202F310 >= a4) {
        PrintFormattedStringOnWindow(8, 2, _("Press {B_BUTTON}\nif OK."), 1, '\0');
    }
    else {
        gFormatArgs[0] = a4 - gUnknown_202F310;
        PrintFormattedStringOnWindow(8, 2, _("Say bye to\n{VALUE_0} more"), 1, '\0');
    }

    sub_80073E0(1);
}

static void ShowPokemonSummary(Pokemon *a0)
{
    struct MonSummaryInfo unkStruct;
    struct UnkInfoTabStruct var_C8;
    WindowTemplates winTemplates = {0};
    s32 r7;

    winTemplates.id[0].type = WINDOW_TYPE_WITH_HEADER;
    winTemplates.id[0].pos.x = 2;
    winTemplates.id[0].pos.y = 2;
    winTemplates.id[0].width = 0x12;
    winTemplates.id[0].height = 0xE;
    winTemplates.id[0].unk10 = 0x12;
    winTemplates.id[0].unk12 = 2;
    winTemplates.id[0].header = &sReleaseMenuWinHeader;
    winTemplates.id[1].type = WINDOW_TYPE_NORMAL;
    winTemplates.id[2].type = WINDOW_TYPE_NORMAL;
    winTemplates.id[3].type = WINDOW_TYPE_NORMAL;

    r7 = 0;
    unkStruct.unk40 = 0;
    unkStruct.unk56 = 0;
    gDungeonMenu.menuIndex = 0;

    while (1) {
        bool32 loopBreak = FALSE;
        s32 spF8[4] = {2, 3, 4, 5};

        sReleaseMenuWinHeader.count = 4;
        sReleaseMenuWinHeader.currId = r7;
        sReleaseMenuWinHeader.width = 10;
        sReleaseMenuWinHeader.f3 = 0;

        gDungeonMenu.currPage = r7;
        gDungeonMenu.pagesCount = 4;
        gDungeonMenu.currPageEntries = 0;
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.entriesPerPage = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.windowId = 0;

        ResetTouchScreenMenuInput(&gDungeonMenu.touchScreen);
        DungeonShowWindows(&winTemplates, 1);
        SetMonSummaryInfo(&unkStruct, a0, gDungeon->unk644.unk16);
        ShowPokemonSummaryWindow(spF8[r7], r7, &unkStruct, &var_C8, 0);

        gDungeonMenu.leftRightArrowsPos.x = (gWindows[0].x + 15) * 8;
        gDungeonMenu.leftRightArrowsPos.y = ((gWindows[0].y + 1) * 8) - 2;

        while (1) {
            s32 r5;

            AddMenuCursorSprite(&gDungeonMenu);
            if (spF8[r7] == 4) {
                if (var_C8.unk0[8] != 0) {
                    ShowDownArrowSprite();
                }
                if (unkStruct.unk40 != 0) {
                    ShowUpArrowSprite();
                }
            }

            r5 = GetTouchScreenArrowPress(0, sTouchScreenArrowPressData);
            DungeonRunFrameActions(0x1C);
            if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.touchScreen.dpad_right) {
                PlayDungeonCursorSE(0);
                if (++r7 == 4) {
                    r7 = 0;
                }
                break;
            }
            if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.touchScreen.dpad_left) {
                PlayDungeonCursorSE(0);
                if (--r7 == -1) {
                    r7 = 3;
                }
                break;
            }

            if (spF8[r7] == 4) {
                if (((gRealInputs.repeated & DPAD_DOWN) || r5 == 2) && var_C8.unk0[8] != 0) {
                    s32 i;

                    PlayDungeonCursorSE(0);
                    for (i = 0; i < 6; i++) {
                        ScrollDownWindowFunc(0);
                        DungeonRunFrameActions(0x1C);
                    }
                    unkStruct.unk40++;
                    break;
                }
                if (((gRealInputs.repeated & DPAD_UP) || r5 == 1) && unkStruct.unk40 != 0) {
                    s32 i;

                    PlayDungeonCursorSE(0);
                    for (i = 0; i < 6; i++) {
                        ScrollUpWindowFunc(0);
                        DungeonRunFrameActions(0x1C);
                    }
                    unkStruct.unk40--;
                    break;
                }
            }

            if (sub_80048C8()) {
                continue;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.touchScreen.a_button) {
                PlayDungeonConfirmationSE();
                loopBreak = TRUE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.touchScreen.b_button) {
                PlayDungeonCancelSE();
                loopBreak = TRUE;
                break;
            }
        }

        DungeonRunFrameActions(0x37);
        if (loopBreak) {
            break;
        }
    }

    sub_803EAF0(0, NULL);
}

static void sub_8068310(s32 n, Pokemon **monPtrs)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < n; i++) {
        if ((monPtrs[i]->flags & POKEMON_FLAG_x8000) != 0) {
            counter++;
        }
    }
    gUnknown_202F310 = counter;
}

// Identical to the functions in dungeon_menu_team.c
static void ShowUpArrowSprite(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 16);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x8);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

static void ShowDownArrowSprite(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 0);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x70);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}
