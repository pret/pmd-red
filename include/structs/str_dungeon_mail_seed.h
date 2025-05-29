#ifndef GUARD_STR_DUNGEON_MAIL_SEED_H
#define GUARD_STR_DUNGEON_MAIL_SEED_H

#include "structs/str_dungeon_location.h"

// size: 0x8
typedef struct DungeonMailSeed
{
    /* 0x0 */ DungeonLocation location;
    /* 0x4 */ u32 seed;
} DungeonMailSeed;

#endif // GUARD_STR_DUNGEON_MAIL_SEED_H
