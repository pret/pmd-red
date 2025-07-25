#ifndef GUARD_CONSTANTS_DUNGEON_H
#define GUARD_CONSTANTS_DUNGEON_H

enum DungeonID
{
    DUNGEON_TINY_WOODS = 0,
    DUNGEON_THUNDERWAVE_CAVE = 1,
    DUNGEON_MT_STEEL = 2,
    DUNGEON_SINISTER_WOODS = 3,
    DUNGEON_SILENT_CHASM = 4,
    DUNGEON_MT_THUNDER = 5,
    DUNGEON_MT_THUNDER_PEAK = 6,
    DUNGEON_GREAT_CANYON = 7,
    DUNGEON_LAPIS_CAVE = 8,
    DUNGEON_MT_BLAZE = 9,
    DUNGEON_MT_BLAZE_PEAK = 10,
    DUNGEON_FROSTY_FOREST = 11,
    DUNGEON_FROSTY_GROTTO = 12,
    DUNGEON_MT_FREEZE = 13,
    DUNGEON_MT_FREEZE_PEAK = 14,
    DUNGEON_MAGMA_CAVERN = 15,
    DUNGEON_MAGMA_CAVERN_PIT = 16,
    DUNGEON_SKY_TOWER = 17,
    DUNGEON_SKY_TOWER_SUMMIT = 18,
    DUNGEON_STORMY_SEA = 19,
    DUNGEON_SILVER_TRENCH = 20,
    DUNGEON_METEOR_CAVE = 21,
    DUNGEON_MT_FREEZE_PEAK_2 = 22, // Duplicate
    DUNGEON_WESTERN_CAVE = 23,
    DUNGEON_BOSS_3 = 24,
    DUNGEON_BOSS_4 = 25,
    DUNGEON_WISH_CAVE = 26,
    DUNGEON_BURIED_RELIC = 27,
    DUNGEON_PITFALL_VALLEY = 28,
    DUNGEON_NORTHERN_RANGE = 29,
    DUNGEON_BOSS_9 = 30,
    DUNGEON_DESERT_REGION = 31,
    DUNGEON_SOUTHERN_CAVERN = 32,
    DUNGEON_WYVERN_HILL = 33,
    DUNGEON_FIERY_FIELD = 34,
    DUNGEON_NORTHWIND_FIELD = 35,
    DUNGEON_SOLAR_CAVE = 36,
    DUNGEON_LIGHTNING_FIELD = 37,
    DUNGEON_DARKNIGHT_RELIC = 38,
    DUNGEON_WONDROUS_SEA = 39,
    DUNGEON_MURKY_CAVE = 40,
    DUNGEON_GRAND_SEA = 41,
    DUNGEON_UPROAR_FOREST = 42,
    DUNGEON_ODDITY_CAVE = 43,
    DUNGEON_REMAINS_ISLAND = 44,
    DUNGEON_MARVELOUS_SEA = 45,
    DUNGEON_FANTASY_STRAIT = 46,
    DUNGEON_ROCK_PATH = 47,
    DUNGEON_SNOW_PATH = 48,
    DUNGEON_AUTOPILOT = 49,
    DUNGEON_D50 = 50,
    DUNGEON_D51 = 51,
    DUNGEON_NORMAL_MAZE = 52,
    DUNGEON_HOWLING_FOREST = 53,
    DUNGEON_D54 = 54,
    DUNGEON_POISON_MAZE = 55,
    DUNGEON_WATERFALL_POND = 56,
    DUNGEON_UNOWN_RELIC = 57,
    DUNGEON_JOYOUS_TOWER = 58,
    DUNGEON_FAR_OFF_SEA = 59,
    DUNGEON_MT_FARAWAY = 60,
    DUNGEON_D61 = 61,
    DUNGEON_PURITY_FOREST = 62,
    DUNGEON_OUT_ON_RESCUE = 63,
    DUNGEON_JOIN_LOCATION_LEADER = 64, // Displays as "???".
    DUNGEON_JOIN_LOCATION_PARTNER = 65, // Displays as "Tiny Woods".
    DUNGEON_UNKNOWN_WORLD = 66,
    DUNGEON_FROSTY_GROTTO_2 = 67, // Duplicate
    DUNGEON_HOWLING_FOREST_2 = 68, // Duplicate
    DUNGEON_POKEMON_SQUARE = 69,
    DUNGEON_POKEMON_SQUARE_2 = 70, // Duplicate
    DUNGEON_RESCUE_TEAM_BASE = 71,
    DUNGEON_RESCUE_TEAM_BASE_2 = 72, // Duplicate
    DUNGEON_AGB_SLOT = 73,
    DUNGEON_JOIN_LOCATION_CLIENT_POKEMON = 74,
    DUNGEON_NORMAL_MAZE_2 = 75, // Duplicate
    DUNGEON_FIRE_MAZE = 76,
    DUNGEON_WATER_MAZE = 77,
    DUNGEON_GRASS_MAZE = 78,
    DUNGEON_ELECTRIC_MAZE = 79,
    DUNGEON_ICE_MAZE = 80,
    DUNGEON_FIGHTING_MAZE = 81,
    DUNGEON_GROUND_MAZE = 82,
    DUNGEON_FLYING_MAZE = 83,
    DUNGEON_PSYCHIC_MAZE = 84,
    DUNGEON_POISON_MAZE_2 = 85, // Duplicate
    DUNGEON_BUG_MAZE = 86,
    DUNGEON_ROCK_MAZE = 87,
    DUNGEON_GHOST_MAZE = 88,
    DUNGEON_DRAGON_MAZE = 89,
    DUNGEON_DARK_MAZE = 90,
    DUNGEON_STEEL_MAZE = 91,
    DUNGEON_TEAM_SHIFTY = 92,
    DUNGEON_TEAM_CONSTRICTOR = 93,
    DUNGEON_TEAM_HYDRO = 94,
    DUNGEON_TEAM_RUMBLEROCK = 95,
    DUNGEON_RESCUE_TEAM_2 = 96,
    DUNGEON_RESCUE_TEAM_MAZE = 97,
    NUM_DUNGEONS,
    DUNGEON_INVALID, // 99
};

#define DUNGEON_FIRST_MAZE DUNGEON_NORMAL_MAZE_2
#define DUNGEON_LAST_MAZE DUNGEON_RESCUE_TEAM_MAZE
#define DUNGEON_LAST_BASIC_MAZE DUNGEON_STEEL_MAZE

#define NUM_DUNGEON_MAZE (DUNGEON_LAST_MAZE - DUNGEON_FIRST_MAZE + 1)
#define NUM_BASIC_DUNGEON_MAZE (DUNGEON_LAST_BASIC_MAZE - DUNGEON_FIRST_MAZE + 1)
#define DUNGEON_IS_MAZE(id)((id) >= DUNGEON_FIRST_MAZE && (id) <= DUNGEON_LAST_MAZE)

static inline bool8 IsExperienceLocked(s32 joinedDungeon)
{
    if (joinedDungeon == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON || joinedDungeon == DUNGEON_RESCUE_TEAM_BASE)
        return TRUE;
    else
        return FALSE;
}

#endif
