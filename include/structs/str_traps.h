#ifndef GUARD_STR_TRAPS_H
#define GUARD_STR_TRAPS_H

#include "constants/trap.h"

// size: 0x4
typedef struct Trap
{
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 unk1;
} Trap;

#endif // GUARD_STR_TRAPS_H