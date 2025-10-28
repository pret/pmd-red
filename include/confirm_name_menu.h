#ifndef GUARD_CONFIRM_NAME_MENU_H
#define GUARD_CONFIRM_NAME_MENU_H

#include "structs/menu.h"

u32 CreateConfirmNameMenu(u32 mode, u8 *name);
u32 sub_8016080(void);
void CleanConfirmNameMenu(void);

#endif // GUARD_CONFIRM_NAME_MENU_H
