#ifndef GUARD_PC_SETTINGS_MENU_H
#define GUARD_PC_SETTINGS_MENU_H

// In-game (GBA UI) PC settings screen: Video / Audio / Controls.
// PC-port only; the GBA build compiles none of this.
#ifdef PLATFORM_PC

#include "gba/types.h"

void ShowPcSettingsMenu_AtTitle(void);

#endif // PLATFORM_PC
#endif // GUARD_PC_SETTINGS_MENU_H
