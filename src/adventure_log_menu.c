#include "global.h"
#include "constants/main_menu.h"
#include "adventure_log.h"
#include "adventure_log_menu.h"
#include "input.h"
#include "text_1.h"

void CreateAdventureLogMenu(void)
{
    CreateAdventureLogScreen(0);
}

void CleanAdventureLogMenu(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
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
