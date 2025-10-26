#ifndef GUARD_STATUS_CHECKS_H
#define GUARD_STATUS_CHECKS_H

#include "structs/dungeon_entity.h"

bool8 HasStatusThatPreventsActing(Entity *pokemon);
bool8 sub_80701A4(Entity *pokemon);

#endif
