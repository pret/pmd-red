#ifndef GUARD_ADVENTURE_LOG_H
#define GUARD_ADVENTURE_LOG_H

#include "structs/menu.h"
#include "structs/str_text.h"

void CleanAdventureLogScreen(void);
bool8 CreateAdventureLogScreen(u32 kind);
u32 HandleAdventureLogInput(bool8);

#endif // GUARD_ADVENTURE_LOG_H
