#include "global.h"
#include "menu.h"

extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(u32 *);
extern u32 sub_80137A8(u32 *);
extern void sub_8012EBC(void *);

u8 sub_80130A8(struct MenuStruct *param_1) {
  int keyPress;
  int index;
  int menuAction;
  u8 *ptr;
  u32 unused; // needed for matching
  struct MenuItem *menuItem;
  
  ptr = &param_1->unk4C;
  if (*ptr != 0) {
    keyPress = GetKeyPress(&param_1->unk14);

    switch(keyPress)
    {
        // A_BUTTON
        case 1:
            index = sub_80137A8(&param_1->unk14);
            menuItem = &param_1->menuItems[index];
            param_1->menuAction = menuItem->menuAction;
            unused = 0;
            *ptr = 0;
            param_1->unk38 = 0;
            PlayMenuSoundEffect(0);
            break;
        // B_BUTTON
        case 2:
            if(menuAction = param_1->menuItems[param_1->unk2E].menuAction, -1 < menuAction) {
              param_1->menuAction = menuAction;
              unused = 0;
              *ptr = 0;
              PlayMenuSoundEffect(0);
            }
            break;
    }
  }
  sub_8012EBC(param_1);
  return param_1->unk4C;
}

bool8 sub_8013114(struct MenuStruct *param_1, s32 *menuAction){
    if(param_1->unk4C != 0){
        return TRUE;
    }
    if (menuAction != NULL){
        *menuAction = param_1->menuAction;
    }
    return FALSE;
}
