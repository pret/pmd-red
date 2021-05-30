#include "global.h"
#include "input.h"
#include "main_menu.h"
#include "adventure_log.h"
#include "text.h"

extern void CreateAdventureLogScreen(u32);
extern u32 HandleAdventureLogInput(u32);
extern void CleanAdventureLogScreen();

void CreateAdventureLogMenu(void)
{
    CreateAdventureLogScreen(0);
}

void CleanAdventureLogMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
}

u32 UpdateAdventureLogMenu(void)
{
    u32 nextMenu;
    nextMenu = MENU_NO_SCREEN_CHANGE;

    switch(HandleAdventureLogInput(1))
    {
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
