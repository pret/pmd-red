#ifndef GUARD_DEBUG_MENU1_H
#define GUARD_DEBUG_MENU1_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x1A4
struct DebugMenu
{
    MenuStruct unk0[4];
    UnkTextStruct2 unk140[4];
    u32 fill1A0;
};

void CreateDebugMenu(void);
void DeleteDebugMenu(void);
u32 UpdateDebugMenu(void);

#endif // GUARD_DEBUG_MENU1_H