#ifndef GUARD_DEBUG_MENU_H
#define GUARD_DEBUG_MENU_H

enum DebugMenuAction
{
    MENU_DEBUG_DUNGEONS = 0,
    MENU_DEBUG_FIELD,
    MENU_DEBUG_FIELD_MAP,
    MENU_DEBUG_FIELD_SCRIPT,
    MENU_DEBUG_MENU,
    MENU_DEBUG_STORAGE = 6,
    MENU_DEBUG_H_OPEN = 9,
};

void CreateDebugMenu(void);
void DeleteDebugMenu(void);
u32 UpdateDebugMenu(void);
void SetDebugMenuItems(void);
void sub_803A3A0(void);

#endif
