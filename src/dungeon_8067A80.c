#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/item.h"
#include "constants/move_id.h"
#include "code_803E46C.h"
#include "code_803E724.h"
#include "code_8041AD0.h"
#include "code_8044CC8.h"
#include "code_8066D04.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "code_8084778.h"
#include "dungeon_logic.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
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

extern void sub_80684C4(void);
void sub_8045064(void);
extern void sub_8068344(void);
bool8 CanSubMenuItemBeChosen(s32 param_1);
void sub_8068310(s32 n, PokemonStruct1 **monPtrs);
void sub_8067F00(u8 a0, PokemonStruct1 **a1, s32 a2, s32 a3, s32 a4);
extern void DungeonShowWindows(WindowTemplates *a0, u8 a1);
u32 sub_8014140(s32 a0, const void *a1);
void sub_8083D1C(void);
void PlayDungeonConfirmationSE(void);
void PlayDungeonCancelSE(void);
void sub_806806C(PokemonStruct1 *a0);
void CreateDungeonMenuSubWindow(WindowTemplates *a0, s32 a1);

extern const s32 gUnknown_8106E80[];
extern MenuInputStruct gDungeonMenu;
extern u32 gDungeonFramesCounter;
extern s32 gDungeonSubMenuItemsCount;

static EWRAM_DATA WindowHeader gUnknown_202F308 = {0};
static EWRAM_DATA s32 gUnknown_202F30C = 0;
static EWRAM_DATA s32 gUnknown_202F310 = 0;

// It's likely a struct only used in Blue version. Touchpad maybe?
static const u8 gUnknown_8106DA4[] = {
    0x01, 0, 0x38, 0, 0, 0, 0x18, 0, 0x18, 0, 0, 0, 0x02, 0, 0x38, 0, 0x68, 0, 0x18, 0, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const WindowTemplates gUnknown_8106DC8 = {
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
            .header = &gUnknown_202F308
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

void sub_8067A80(u8 a0, s32 a1, s32 a2, PokemonStruct1 **a3)
{
    s32 i;
    s32 r10;
    WindowTemplates spTxtStruct = gUnknown_8106DC8;

    gUnknown_202F30C = 0;
    r10 = 0;
    for (i = 0; i < a2; i++) {
        a3[i]->unk0 &= ~(0x8000);
    }

    while (1) {
        sub_8068310(a2, a3);
        if (gUnknown_202F310 >= a1)
            break;
        while (1) {
            s32 r7 = 0, r5 = 0;

            gUnknown_202F308.count = 1;
            gUnknown_202F308.currId = 0;
            gUnknown_202F308.width = 0xE;
            gUnknown_202F308.f3 = 0;

            ASM_MATCH_TRICK(r7);

            DungeonShowWindows(&spTxtStruct, 1);
            sub_8067F00(a0, a3, gUnknown_202F30C, a2, a1);
            gDungeonMenu.unk1A = min(a2, 8);
            gDungeonMenu.menuIndex = r10;
            gDungeonMenu.unk1C = 8;
            gDungeonMenu.unk1E = 0;
            gDungeonMenu.unk20 = 0;
            gDungeonMenu.unk4 = 0;
            gDungeonMenu.firstEntryY = 18;
            gDungeonMenu.unkC = 0;
            gDungeonMenu.unkE = 0;
            gDungeonMenu.unk14.x = 0;
            gDungeonMenu.unk0 = 0;
            sub_801317C(&gDungeonMenu.unk28);
            sub_80137B0(&gDungeonMenu, 0);
            while (1) {
                s32 r4;

                AddMenuCursorSprite(&gDungeonMenu);
                r5 = 0;
                r7 = 0;
                if (a2 - gUnknown_202F30C > 8) {
                    r5 = 1;
                    sub_80684C4();
                }
                if (gUnknown_202F30C != 0) {
                    r7 = 1;
                    sub_8068344();
                }

                r4 = sub_8014140(0, gUnknown_8106DA4);
                DungeonRunFrameActions(0x37);
                if (r4 == 2 && r5) {
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

                if (r4 == 1 && r7 != 0) {
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
                if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                    PlayDungeonConfirmationSE();
                    r7 = 1;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
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
                sub_806806C(a3[gUnknown_202F30C + r10]);
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
                if (a3[arrId]->unk0 & 0x8000) {
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
                CreateDungeonMenuSubWindow(&spTxtStruct, 0x15);

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

                    if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                        if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                            PlayDungeonConfirmationSE();
                            r7 = 1;
                            break;
                        }
                        PlayDungeonCancelSE();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                        PlayDungeonCancelSE();
                        r7 = 0;
                        break;
                    }
                }

                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x37);
                if (r7 != 0) {
                    if (gDungeonMenu.menuIndex == 0) {
                        a3[arrId]->unk0 |= 0x8000;
                        sub_8068310(a2, a3);
                    }
                    else if (gDungeonMenu.menuIndex == 1) {
                        a3[arrId]->unk0 &= ~(0x8000);
                        sub_8068310(a2, a3);
                    }
                    else {
                        sub_806806C(a3[arrId]);
                    }
                }
                continue;
            }
        }
    }
}

void sub_8067F00(u8 a0, PokemonStruct1 **a1, s32 a2_, s32 a3, s32 a4)
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
            if (a1[a2]->unk0 & 0x8000) {
                InlineStrcpy(gFormatBuffer_Items[0], _("{STAR_BULLET}"));
            }
            else {
                InlineStrcpy(gFormatBuffer_Items[0], _("{ICON_BLANK}"));
            }

            if (a1[a2]->unk0 & 0x4000) {
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

void sub_806806C(PokemonStruct1 *a0)
{
    struct unkStruct_808FF20 unkStruct;
    struct UnkInfoTabStruct var_C8;
    WindowTemplates spTxtStruct = {0};
    s32 r7;

    spTxtStruct.id[0].type = WINDOW_TYPE_WITH_HEADER;
    spTxtStruct.id[0].pos.x = 2;
    spTxtStruct.id[0].pos.y = 2;
    spTxtStruct.id[0].width = 0x12;
    spTxtStruct.id[0].height = 0xE;
    spTxtStruct.id[0].unk10 = 0x12;
    spTxtStruct.id[0].unk12 = 2;
    spTxtStruct.id[0].header = &gUnknown_202F308;
    spTxtStruct.id[1].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.id[2].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.id[3].type = WINDOW_TYPE_NORMAL;

    r7 = 0;
    unkStruct.unk40 = 0;
    unkStruct.unk56 = 0;
    gDungeonMenu.menuIndex = 0;

    while (1) {
        bool32 loopBreak = FALSE;
        s32 spF8[4] = {2, 3, 4, 5};

        gUnknown_202F308.count = 4;
        gUnknown_202F308.currId = r7;
        gUnknown_202F308.width = 10;
        gUnknown_202F308.f3 = 0;

        gDungeonMenu.unk1E = r7;
        gDungeonMenu.unk20 = 4;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1C = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk0 = 0;

        sub_801317C(&gDungeonMenu.unk28);
        DungeonShowWindows(&spTxtStruct, 1);
        sub_808FF20(&unkStruct, a0, gDungeon->unk644.unk16);
        CreatePokemonInfoTabScreen(spF8[r7], r7, &unkStruct, &var_C8, 0);

        gDungeonMenu.unkC = (gWindows[0].x + 15) * 8;
        gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;

        while (1) {
            s32 r5;

            AddMenuCursorSprite(&gDungeonMenu);
            if (spF8[r7] == 4) {
                if (var_C8.unk0[8] != 0) {
                    sub_80684C4();
                }
                if (unkStruct.unk40 != 0) {
                    sub_8068344();
                }
            }

            r5 = sub_8014140(0, gUnknown_8106DA4);
            DungeonRunFrameActions(0x1C);
            if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                PlayDungeonCursorSE(0);
                if (++r7 == 4) {
                    r7 = 0;
                }
                break;
            }
            if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
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

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                loopBreak = TRUE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
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

void sub_8068310(s32 n, PokemonStruct1 **monPtrs)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < n; i++) {
        if ((monPtrs[i]->unk0 & 0x8000) != 0) {
            counter++;
        }
    }
    gUnknown_202F310 = counter;
}

void sub_8068344(void)
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

// The same as sub_80623B0
void sub_80684C4(void)
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
