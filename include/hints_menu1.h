#ifndef GUARD_HINTS_MENU1_H
#define GUARD_HINTS_MENU1_H

#include "input.h"
#include "structs/str_text.h"

// size: 0x9C
struct unkStruct_203B264
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
};

void CreateHintSelectionScreen(bool8 cursorSprite);
s32 GetChosenHintIndex(void);

bool8 sub_801E3F0(u32);
u32 sub_801E474(bool8);
void sub_801E54C(void);

#endif // GUARD_HINTS_MENU1_H