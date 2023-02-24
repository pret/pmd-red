#ifndef GUARD_STATUS_CHECKS_1_H
#define GUARD_STATUS_CHECKS_1_H

#include "dungeon_entity.h"

bool8 HasNegativeStatus(struct Entity *pokemon);
bool8 IsSleeping(struct Entity *pokemon);
bool8 HasLowHealth(struct Entity *pokemon);
s32 sub_8070828(struct Entity *pokemon, bool8 displayMessage);

#endif
