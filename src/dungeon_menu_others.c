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
#include "code_8045A00.h"
#include "code_8097DD0.h"
#include "dungeon_message.h"

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

extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonSubMenuItemsCount;
extern s32 gUnknown_202F2E0;

void sub_8065250(void);
void sub_8064D74(void);
void sub_80650C0(void);
void sub_806519C(void);
void sub_8065FB4(void);
void sub_8065BF4(void);

void ShowDungeonOthersMenu(void)
{
    bool8 unkAlwaysFalse;
    s32 lastId = (gDungeon->unk644.unk14) ? 5 : 4;

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
                if (gDungeonMenu.menuIndex != 4 || (gDungeon->unk644.unk14 && !IsBossFight())) {
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
        if (gUnknown_202F2E0 == 0) {
            sub_8064D74();
        }
        if (gUnknown_202F2E0 == 1) {
            sub_80650C0();
        }
        if (gUnknown_202F2E0 == 2) {
            DisplayMessageLog();
        }
        if (gUnknown_202F2E0 == 3) {
            sub_806519C();
        }
        if (gDungeon->unk644.unk14 && !IsBossFight() && gUnknown_202F2E0 == 4) {
            sub_8065FB4();
        }
        if (gUnknown_202F2E0 == lastId) {
            sub_8065BF4();
        }

        if (gDungeon->unk4)
            break;
        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }

    sub_8040A84();
    sub_803EAF0(0, NULL);
}

//
