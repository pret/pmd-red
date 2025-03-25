#ifndef GUARD_STR_DUNGEON_LOCATION_H
#define GUARD_STR_DUNGEON_LOCATION_H

// size: R=0x4 | B=0x2
typedef struct DungeonLocation
{
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 floor;
} DungeonLocation;

#endif // GUARD_STR_DUNGEON_LOCATION_H
