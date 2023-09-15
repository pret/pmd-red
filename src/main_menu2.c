#include "global.h"
#include "code_803D0D8.h"
#include "constants/main_menu.h"
#include "constants/wonder_mail.h"
#include "main_menu1.h"
#include "main_menu2.h"
#include "memory.h"
#include "menu_input.h"
#include "save.h"
#include "text1.h"

static EWRAM_DATA_2 MainMenu2Work *sUnknown_203B34C = {0};
static EWRAM_DATA_2 u32 sUnknown_203B350 = {0};
static EWRAM_DATA_2 u32 sUnknown_203B354 = {0};

#include "data/main_menu2.h"

static void SetMainMenuItems(void);
static bool8 SetMainMenuText(void);

static void sub_803623C(void);

void DrawMainMenu(void)
{
    s32 i;

    if (sUnknown_203B34C == NULL) {
        sUnknown_203B34C = MemoryAlloc(sizeof(MainMenu2Work), 8);
        MemoryFill8((u8 *)sUnknown_203B34C, 0, sizeof(MainMenu2Work));
    }

    for (i = 0; i < 4; i++)
        sUnknown_203B34C->unk144[i] = sUnknown_80E59C8;

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B34C->unk144, TRUE, TRUE);
    SetMainMenuItems();
    sUnknown_203B34C->currMenuChoice = -1;

    if (SetMainMenuText())
        sub_8035CF4(sUnknown_203B34C->unk4, 2, FALSE);

    sub_8035CF4(sUnknown_203B34C->unk4, 0, TRUE);
    sUnknown_203B34C->unk0 = 1;
}

void CleanMainMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);

    if (sUnknown_203B34C != NULL) {
        MemoryFree(sUnknown_203B34C);
        sUnknown_203B34C = NULL;
    }
}

u32 UpdateMainMenu(void)
{
    u32 nextMenu = MENU_NO_SCREEN_CHANGE;

    switch (sUnknown_203B34C->unk0) {
        case 1:
            sub_8012FD8(&sUnknown_203B34C->unk4[2]);

            if (!sub_8012FD8(sUnknown_203B34C->unk4))
                sub_8013114(sUnknown_203B34C->unk4, &nextMenu);

            if (SetMainMenuText()) {
                sub_8035CF4(sUnknown_203B34C->unk4, 0, TRUE);
                sub_8035CF4(sUnknown_203B34C->unk4, 2, FALSE);
            }

            switch (nextMenu) {
                case MENU_NO_SCREEN_CHANGE:
                     nextMenu = MENU_NO_SCREEN_CHANGE;
                     break;
                case 0xFFDD:
                    sUnknown_203B34C->unk0 = 1;
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    ResetUnusedInputStruct();
                    sub_8035CF4(sUnknown_203B34C->unk4, 0, TRUE);
                    sub_8035CF4(sUnknown_203B34C->unk4, 2, FALSE);
                    break;
                case MENU_TRADE_ITEMS:
                    sub_8035DA0();
                    sUnknown_203B350 = nextMenu;
                    break;
                case MENU_NEW_GAME:
                case MENU_AWAITING_RESCUE:
                case MENU_CONTINUE:
                case MENU_DELETE_SAVE_PROMPT:
                case MENU_DELETE_SAVE_CONFIRM:
                case MENU_ADVENTURE_LOG:
                case MENU_FRIEND_RESCUE:
                case MENU_WONDER_MAIL:
                case MENU_DUAL_SLOT:
                case MENU_WIRELESS_COMMS:
                case MENU_DEBUG:
                    sUnknown_203B350 = nextMenu;
                    break;
            }
            break;
        case 12:
            if (!sub_8012FD8(&sUnknown_203B34C->unk4[1]))
                sub_8013114(&sUnknown_203B34C->unk4[1], &nextMenu);

            switch (nextMenu) {
                case 0xFFDD:
                    sub_803623C();
                    sUnknown_203B34C->unk0 = 1;
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    break;
                case MENU_SEND_ITEMS:
                    sUnknown_203B354 = nextMenu;
                    nextMenu = MENU_TRADE_ITEMS;
                    break;
                case MENU_RECEIVE_ITEMS:
                    sUnknown_203B354 = nextMenu;
                    nextMenu = MENU_COMMUNICATION_2;
                    break;
                case MENU_NO_SCREEN_CHANGE:
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    break;
                default:
                    break;
            }
            break;
        default:
        case 13: // forces the bls switch
            break;
    }

    return nextMenu;
}

static bool8 SetMainMenuText(void)
{
    u32 menuChoice;
    const MenuItem *preload;

    // Have to load the pointer before the index
    preload = sUnknown_203B34C->unk4[0].menuItems;
    menuChoice = preload[sUnknown_203B34C->unk4[0].input.menuIndex].menuAction; // chosen menu action?
    if (sUnknown_203B34C->currMenuChoice == menuChoice)
        return FALSE;

    sUnknown_203B34C->currMenuChoice = menuChoice;
    sub_8035CC0(sUnknown_203B34C->unk144, 2);
    sub_8035CC0(sUnknown_203B34C->unk144, 3);

    switch (menuChoice) {
        case MENU_WIRELESS_COMMS:
            // Using wireless communications, you can go on an adventure to unknown worlds.
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E6030, FALSE, 0, FALSE);
            break;
        case MENU_WONDER_MAIL:
            // Using passwords, you can receive Wonder Mail
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5F80, FALSE, 0, FALSE);
            break;
        case MENU_AWAITING_RESCUE:
            // You are awaiting resuce by a friend
            // You can give up waiting for rescue
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5F1C, FALSE, 0, FALSE);
            break;
        case MENU_NEW_GAME:
            // Start an entirely new adventure
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5CCC, FALSE, 0, FALSE);
            break;
        case MENU_CONTINUE:
            // Resume your adventure from where you last saved
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5DA0, FALSE, 0, FALSE);
            break;
        case MENU_DELETE_SAVE_PROMPT:
            // This will delete your saved game data.
            // Beware! This will delete it forever
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5DF0, FALSE, 0, FALSE);
            break;
        case MENU_ADVENTURE_LOG:
            // Check your career as an adventurer
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5D0C, FALSE, 0, FALSE);
            break;
        case MENU_FRIEND_RESCUE:
            // Using a Game Link cable or passwords, friends may rescue each other
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5E5C, FALSE, 0, FALSE);
            break;
        case MENU_TRADE_ITEMS:
            // Using a Game Link cable you can trade stored items with a friend
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5EBC, FALSE, 0, FALSE);
            break;
        case MENU_DUAL_SLOT:
            // Using Dual Slot function, you can receive teams from your friends
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5FCC, FALSE, 0, FALSE);
            break;
        case MENU_DEBUG:
            // This is the Debug Mode.
            // It won't be in the release version
            SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 2, &sUnknown_80E5CB4, sUnknown_80E5D48, FALSE, 0, FALSE);
            break;
        default:
            break;
    }

    return TRUE;
}

static void sub_803623C(void)
{
    sub_8035CC0(sUnknown_203B34C->unk144, 1);
    SetMainMenuItems();
    sUnknown_203B34C->currMenuChoice = -1;

    if (SetMainMenuText())
        sub_8035CF4(sUnknown_203B34C->unk4, 2, FALSE);

    sub_8035CF4(sUnknown_203B34C->unk4, 0, TRUE);
}

static void SetMainMenuItems(void)
{
    if (sub_8011C34() != -1) {
        if (CountMailType(WONDER_MAIL_TYPE_SOS) == 0) {
            if (CountMailType(WONDER_MAIL_TYPE_OKD) != 0) {
                if (sub_803D0D8()) {
                    // Revive Team
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                    // Wonder Mail
                    SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5A78, sUnknown_80E5C18, TRUE, sUnknown_203B350, TRUE);
                }
                else {
                    // Revive Team
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                    SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5BC4, sUnknown_80E5BDC, TRUE, sUnknown_203B350, TRUE);
                }
            }
            else {
                if (sub_803D0D8()) {
                    // Continue
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                    // Wonder Mail
                    SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5A78, sUnknown_80E5AFC, TRUE, sUnknown_203B350, TRUE);
                }
                else {
                    // Continue
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                    SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5A60, sUnknown_80E5A90, TRUE, sUnknown_203B350, TRUE);
                }
            }
        }
        else {
            if (sub_803D0D8()) {
                    // Awaiting Rescue
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                    // Wonder Mail
                SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5A78, sUnknown_80E5B8C, TRUE, sUnknown_203B350, TRUE);
            }
            else {
                    // Awaiting Rescue
                    // Delete Save Data
                    // Adventure Log
                    // Friend Rescue
                    // Trade Items
                SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E5B34, sUnknown_80E5B4C, TRUE, sUnknown_203B350, TRUE);
            }
        }
    }
    else {
        // New Game
        // Adventure Log
        SetMenuItems(sUnknown_203B34C->unk4, sUnknown_203B34C->unk144, 0, &sUnknown_80E59E0, sUnknown_80E59F8, TRUE, sUnknown_203B350, TRUE);
    }
}

bool8 sub_80363E0(void)
{
    if (sUnknown_203B34C == NULL)
        return FALSE;
    if (sUnknown_203B34C->unk0 == 12)
        return FALSE;
    return TRUE;
}