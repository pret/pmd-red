#ifndef GUARD_TRAP_H
#define GUARD_TRAP_H

#include "structs/str_position.h"

bool8 CanLayTrap(Position *pos);
bool8 LayTrap(Position *pos, u8 trapID, u8 param_3);

#endif
