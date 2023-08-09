#ifndef GUARD_DEBUG_MENU1_H
#define GUARD_DEBUG_MENU1_H

#include "menu.h"
#include "text.h"

// size: 0x1A4
struct DebugMenu
{
    struct MenuStruct unk0[4];
    struct UnkTextStruct2 unk140[4];
    u32 fill1A0;
};

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

#endif // GUARD_DEBUG_MENU1_H