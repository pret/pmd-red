#ifndef GUARD_HINTS_MENU1_H
#define GUARD_HINTS_MENU1_H

#include "structs/menu.h"
#include "structs/str_text.h"

void CreateHintSelectionScreen(bool8 cursorSprite);
s32 GetChosenHintIndex(void);

bool8 sub_801E3F0(u32);
u32 sub_801E474(bool8);
void sub_801E54C(void);

#endif // GUARD_HINTS_MENU1_H
