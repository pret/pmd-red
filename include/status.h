#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "dungeon_entity.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 GetFlashFireStatus(struct DungeonEntity *pokemon);

#endif
