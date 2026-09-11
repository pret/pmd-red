#ifndef GUARD_PC_SETTINGS_MENU_H
#define GUARD_PC_SETTINGS_MENU_H

// In-game (GBA UI) PC settings screen: Video / Audio / Controls.
// PC-port only; the GBA build compiles none of this.
#ifdef PLATFORM_PC

#include "gba/types.h"

// Title-screen main menu ("PC Settings" entry).
void ShowPcSettingsMenu_AtTitle(void);
// Field overworld: "Others" -> "Game Options".
void ShowPcSettingsMenu_Field(void);
// Dungeon: "Others" -> "Game Options".
void ShowPcSettingsMenu_InDungeon(void);

// "PC Settings" label for the in-game Game Options rows.
extern const u8 *const gFieldMenuPcSettingsPtr;

#endif // PLATFORM_PC
#endif // GUARD_PC_SETTINGS_MENU_H
