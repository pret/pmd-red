#ifndef GUARD_DEBUG_MENU_H
#define GUARD_DEBUG_MENU_H

enum DebugMenuOptions
{
    MENU_DEBUG_MENU_DUNGEONS = 0,
    MENU_DEBUG_MENU_FIELD,
    MENU_DEBUG_MENU_FIELD_MAP,
    MENU_DEBUG_MENU_FIELD_SCRIPT,
    MENU_DEBUG_MENU_DEBUG_MENU,
    MENU_DEBUG_MENU_UNKNOWN_1,
    MENU_DEBUG_MENU_STORAGE,
    MENU_DEBUG_MENU_H_OPEN = 9,
};

void CreateDebugMenu(void);
void DeleteDebugMenu(void);
u32 UpdateDebugMenu(void);
void SetDebugMenuItems(void);
void sub_803A3A0(void);

#endif
