#ifndef GUARD_ADVENTURE_LOG_H
#define GUARD_ADVENTURE_LOG_H

#include "input.h"
#include "text.h"

// size: 0xA0
typedef struct AdventureLog
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
} AdventureLog;

void CleanAdventureLogScreen(void);
bool8 CreateAdventureLogScreen(u32);
u32 HandleAdventureLogInput(u8);

#endif // GUARD_ADVENTURE_LOG_H