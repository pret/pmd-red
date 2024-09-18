#include "global.h"
#include "adventure_log.h"
#include "adventure_log_menu.h"
#include "constants/main_menu.h"
#include "input.h"
#include "text1.h"

void CreateAdventureLogMenu(void)
{
    CreateAdventureLogScreen(0);
}

void CleanAdventureLogMenu(void)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
}

u32 UpdateAdventureLogMenu(void)
{
    u32 nextMenu;
    nextMenu = MENU_NO_SCREEN_CHANGE;

    switch (HandleAdventureLogInput(TRUE)) {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            CleanAdventureLogScreen();
            nextMenu = MENU_MAIN_SCREEN;
        default:
            break;
    }
    return nextMenu;
}