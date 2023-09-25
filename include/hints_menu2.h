#ifndef GUARD_HINTS_MENU2_H
#define GUARD_HINTS_MENU2_H

#include "input.h"
#include "structs/str_text.h"

// size: 0xA0
struct unkStruct_203B268
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

bool8 CreateHintDisplayScreen(u32 index);
void DestroyHintDisplayScreen(void);
u32 HandleHintDisplayScreenInput(void);

#endif // GUARD_HINTS_MENU2_H