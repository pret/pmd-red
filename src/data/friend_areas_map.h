#define NO_AREA FRIEND_AREA_COUNT + 5

 // ななし means 'without name'
#define DUMMY_LOCATION                                                                      \
{                                                                                           \
    .name = _("ななし"),                                                                     \
    .pos = { 0, 0 },                                                                        \
    .areasIds = { NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA }, \
    .adjacentLocations = { -1, -1, -1, -1, -1, -1, -1, -1 },                                \
}

// The second set is all dummies, maybe it was used for testing purposes?
static const struct FriendAreaLocationInfo sFriendAreaLocations[2][NUM_FRIEND_AREA_LOCATIONS] =
{
    {
        [LOCATION_MOUNTAIN_RANGE] =
        {
            .name = "Mountain Range",
            .pos = {0x1C5, 0x71},
            .areasIds = {FRIEND_AREA_MT_DEEPGREEN, FRIEND_AREA_MT_CLEFT, FRIEND_AREA_MT_MOONVIEW, FRIEND_AREA_MT_DISCIPLINE, FRIEND_AREA_DARKNESS_RIDGE, FRIEND_AREA_RAINBOW_PEAK, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_EASTERN_FOREST,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_MARSH,
                [DIRECTION_WEST] = LOCATION_PLAINS,
                [DIRECTION_SOUTHWEST] = LOCATION_RIVER,
            },
        },
        [LOCATION_GLACIER] =
        {
            .name = "Glacier",
            .pos = {0x1CD, 0x1C},
            .areasIds = {FRIEND_AREA_FRIGID_CAVERN, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_NORTHERN_LAKES,
                [DIRECTION_SOUTHWEST] = LOCATION_MARSH,
            },
        },
        [LOCATION_PLAINS] =
        {
            .name = "Plains",
            .pos = {0x161, 0x78},
            .areasIds = {FRIEND_AREA_BEAU_PLAINS, FRIEND_AREA_SKY_BLUE_PLAINS, FRIEND_AREA_SACRED_FIELD, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_TEAM_BASE,
                [DIRECTION_SOUTHEAST] = LOCATION_RIVER,
                [DIRECTION_EAST] = 0,
                [DIRECTION_NORTHEAST] = LOCATION_MARSH,
                [DIRECTION_NORTH] = LOCATION_CAVE,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_POND,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_SOUTH_PLAINS] =
        {
            .name = "South Plains",
            .pos = {0x162, 0x12D},
            .areasIds = {FRIEND_AREA_SAFARI, FRIEND_AREA_WILD_PLAINS, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = LOCATION_BADLANDS,
                [DIRECTION_NORTH] = LOCATION_JUNGLE,
                [DIRECTION_NORTHWEST] = LOCATION_RELICS,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_BADLANDS] =
        {
            .name = "Badlands",
            .pos = {0x194, 0x102},
            .areasIds = {FRIEND_AREA_RAVAGED_FIELD, FRIEND_AREA_MAGNETIC_QUARRY, FRIEND_AREA_THUNDER_MEADOW, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_DESERT,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = LOCATION_EASTERN_LAKES,
                [DIRECTION_NORTH] = LOCATION_EASTERN_PONDS,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_JUNGLE,
                [DIRECTION_SOUTHWEST] = LOCATION_SOUTH_PLAINS,
            },
        },
        [LOCATION_EASTERN_FOREST] =
        {
            .name = "Eastern Forest",
            .pos = {0x1C7, 0x9D},
            .areasIds = {FRIEND_AREA_MIST_RISE_FOREST, FRIEND_AREA_FLYAWAY_FOREST, FRIEND_AREA_OVERGROWN_FOREST, FRIEND_AREA_ENERGETIC_FOREST, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_EASTERN_LAKES,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = 0,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_RIVER,
                [DIRECTION_SOUTHWEST] = LOCATION_EASTERN_PONDS,
            },
        },
        [LOCATION_WESTERN_FOREST] =
        {
            .name = "Western Forest",
            .pos = {0x108, 0x9D},
            .areasIds = {FRIEND_AREA_MUSHROOM_FOREST, FRIEND_AREA_HEALING_FOREST, FRIEND_AREA_TRANSFORM_FOREST, FRIEND_AREA_SECRETIVE_FOREST, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_VOLCANO,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_TEAM_BASE,
                [DIRECTION_NORTHEAST] = LOCATION_POND,
                [DIRECTION_NORTH] = LOCATION_NORTHERN_ISLES,
                [DIRECTION_NORTHWEST] = LOCATION_BEACH,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_RIVER] =
        {
            .name = "River",
            .pos = {0x197, 0xA0},
            .areasIds = {FRIEND_AREA_RUB_A_DUB_RIVER, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_EASTERN_PONDS,
                [DIRECTION_SOUTHEAST] = LOCATION_EASTERN_LAKES,
                [DIRECTION_EAST] = LOCATION_EASTERN_FOREST,
                [DIRECTION_NORTHEAST] = LOCATION_MOUNTAIN_RANGE,
                [DIRECTION_NORTH] = LOCATION_MARSH,
                [DIRECTION_NORTHWEST] = LOCATION_PLAINS,
                [DIRECTION_WEST] = LOCATION_TEAM_BASE,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_EASTERN_PONDS] =
        {
            .name = "Eastern Ponds",
            .pos = {0x198, 0xCF},
            .areasIds = {FRIEND_AREA_TADPOLE_POND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_BADLANDS,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_EASTERN_LAKES,
                [DIRECTION_NORTHEAST] = LOCATION_EASTERN_FOREST,
                [DIRECTION_NORTH] = LOCATION_RIVER,
                [DIRECTION_NORTHWEST] = LOCATION_TEAM_BASE,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = LOCATION_JUNGLE,
            },
        },
        [LOCATION_POND] =
        {
            .name = "Pond",
            .pos = {0x133, 0x79},
            .areasIds = {FRIEND_AREA_TURTLESHELL_POND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_TEAM_BASE,
                [DIRECTION_EAST] = LOCATION_PLAINS,
                [DIRECTION_NORTHEAST] = LOCATION_CAVE,
                [DIRECTION_NORTH] = LOCATION_RUINS,
                [DIRECTION_NORTHWEST] = LOCATION_NORTHERN_ISLES,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = LOCATION_WESTERN_FOREST,
            },
        },
        [LOCATION_NORTHERN_LAKES] =
        {
            .name = "Northern Lakes",
            .pos = {0x182, 0x1D},
            .areasIds = {FRIEND_AREA_MYSTIC_LAKE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_MARSH,
                [DIRECTION_EAST] = 1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_RUINS,
                [DIRECTION_SOUTHWEST] = LOCATION_CAVE,
            },
        },
        [LOCATION_EASTERN_LAKES] =
        {
            .name = "Eastern Lakes",
            .pos = {0x1C6, 0xD0},
            .areasIds = {FRIEND_AREA_WATERFALL_LAKE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = LOCATION_EASTERN_FOREST,
                [DIRECTION_NORTHWEST] = LOCATION_RIVER,
                [DIRECTION_WEST] = LOCATION_EASTERN_PONDS,
                [DIRECTION_SOUTHWEST] = LOCATION_BADLANDS,
            },
        },
        [LOCATION_MARSH] =
        {
            .name = "Marsh",
            .pos = {0x1A2, 0x46},
            .areasIds = {FRIEND_AREA_PEANUT_SWAMP, FRIEND_AREA_POISON_SWAMP, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_RIVER,
                [DIRECTION_SOUTHEAST] = LOCATION_MOUNTAIN_RANGE,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = 1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_NORTHERN_LAKES,
                [DIRECTION_WEST] = LOCATION_CAVE,
                [DIRECTION_SOUTHWEST] = LOCATION_PLAINS,
            },
        },
        [LOCATION_CAVE] =
        {
            .name = "Cave",
            .pos = {0x160, 0x47},
            .areasIds = {FRIEND_AREA_ECHO_CAVE, FRIEND_AREA_DRAGON_CAVE, FRIEND_AREA_BOULDER_CAVE, FRIEND_AREA_CRYPTIC_CAVE, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_PLAINS,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_MARSH,
                [DIRECTION_NORTHEAST] = LOCATION_NORTHERN_LAKES,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_RUINS,
                [DIRECTION_WEST] = LOCATION_NORTHERN_ISLES,
                [DIRECTION_SOUTHWEST] = LOCATION_POND,
            },
        },
        [LOCATION_JUNGLE] =
        {
            .name = "Jungle",
            .pos = {0x163, 0x104},
            .areasIds = {FRIEND_AREA_JUNGLE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_SOUTH_PLAINS,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_BADLANDS,
                [DIRECTION_NORTHEAST] = LOCATION_EASTERN_PONDS,
                [DIRECTION_NORTH] = LOCATION_TEAM_BASE,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_RELICS,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_RUINS] =
        {
            .name = "Ruins",
            .pos = {0x136, 0x1C},
            .areasIds = {FRIEND_AREA_DECREPIT_LAB, FRIEND_AREA_POWER_PLANT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_POND,
                [DIRECTION_SOUTHEAST] = LOCATION_CAVE,
                [DIRECTION_EAST] = LOCATION_NORTHERN_LAKES,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_NORTHERN_SEA,
                [DIRECTION_SOUTHWEST] = LOCATION_NORTHERN_ISLES,
            },
        },
        [LOCATION_VOLCANO] =
        {
            .name = "Volcano",
            .pos = {0x107, 0xCB},
            .areasIds = {FRIEND_AREA_SCORCHED_PLAINS, FRIEND_AREA_CRATER, FRIEND_AREA_VOLCANIC_PIT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_RELICS,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = LOCATION_TEAM_BASE,
                [DIRECTION_NORTH] = LOCATION_WESTERN_FOREST,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = LOCATION_SOUTHERN_SEA,
            },
        },
        [LOCATION_DESERT] =
        {
            .name = "Desert",
            .pos = {0x1C4, 0x12D},
            .areasIds = {FRIEND_AREA_FURNACE_DESERT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_BADLANDS,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_RELICS] =
        {
            .name = "Relics",
            .pos = {0x131, 0x105},
            .areasIds = {FRIEND_AREA_ANCIENT_RELIC, FRIEND_AREA_AGED_CHAMBER_AN, FRIEND_AREA_AGED_CHAMBER_O_EXCLAIM, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_SOUTH_PLAINS,
                [DIRECTION_EAST] = LOCATION_JUNGLE,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_VOLCANO,
                [DIRECTION_WEST] = LOCATION_SOUTHERN_SEA,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_SKY] =
        {
            .name = "Sky",
            .pos = {0x2F, 0x15},
            .areasIds = {FRIEND_AREA_STRATOS_LOOKOUT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_WESTERN_ISLES,
                [DIRECTION_SOUTHEAST] = LOCATION_BEACH,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_NORTHERN_ISLES] =
        {
            .name = "Northern Isles",
            .pos = {0x107, 0x47},
            .areasIds = {FRIEND_AREA_LEGENDARY_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = 6,
                [DIRECTION_SOUTHEAST] = 9,
                [DIRECTION_EAST] = 0xD,
                [DIRECTION_NORTHEAST] = 0xF,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = 0x18,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_SOUTHERN_ISLES] =
        {
            .name = "Southern Isles",
            .pos = {0x5D, 0x10C},
            .areasIds = {FRIEND_AREA_SOUTHERN_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_SOUTHERN_SEA,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_SOUTHWEST_ISLES,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_SOUTHWEST_ISLES] =
        {
            .name = "Southwest Isles",
            .pos = {0x2D, 0xCB},
            .areasIds = {FRIEND_AREA_ENCLOSED_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_SOUTHERN_ISLES,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = LOCATION_WESTERN_ISLES,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_WESTERN_ISLES] =
        {
            .name = "Western Isles",
            .pos = {0x2D, 0x70},
            .areasIds = {FRIEND_AREA_FINAL_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_SOUTHWEST_ISLES,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = LOCATION_BEACH,
                [DIRECTION_NORTH] = LOCATION_SKY,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_NORTHERN_SEA] =
        {
            .name = "Northern Sea",
            .pos = {0xD0, 0x16},
            .areasIds = {FRIEND_AREA_BOUNTIFUL_SEA, FRIEND_AREA_SERENE_SEA, FRIEND_AREA_DEEP_SEA_CURRENT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_NORTHERN_ISLES,
                [DIRECTION_EAST] = LOCATION_RUINS,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = LOCATION_BEACH,
            },
        },
        [LOCATION_SOUTHERN_SEA] =
        {
            .name = "Southern Sea",
            .pos = {0xB2, 0x10D},
            .areasIds = {FRIEND_AREA_TREASURE_SEA, FRIEND_AREA_DEEP_SEA_FLOOR, FRIEND_AREA_SEAFLOOR_CAVE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = -1,
                [DIRECTION_EAST] = LOCATION_RELICS,
                [DIRECTION_NORTHEAST] = LOCATION_VOLCANO,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = -1,
                [DIRECTION_WEST] = LOCATION_SOUTHERN_ISLES,
                [DIRECTION_SOUTHWEST] = -1,
            },
        },
        [LOCATION_BEACH] =
        {
            .name = "Beach",
            .pos = {0x81, 0x42},
            .areasIds = {FRIEND_AREA_SHALLOW_BEACH, FRIEND_AREA_ICE_FLOE_BEACH, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = -1,
                [DIRECTION_SOUTHEAST] = LOCATION_WESTERN_FOREST,
                [DIRECTION_EAST] = -1,
                [DIRECTION_NORTHEAST] = LOCATION_NORTHERN_SEA,
                [DIRECTION_NORTH] = -1,
                [DIRECTION_NORTHWEST] = LOCATION_SKY,
                [DIRECTION_WEST] = -1,
                [DIRECTION_SOUTHWEST] = LOCATION_WESTERN_ISLES,
            },
        },
        [LOCATION_TEAM_BASE] =
        {
            .name = _("$t"),
            .pos = {0x163, 0xA1},
            .areasIds = {FRIEND_AREA_NONE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
            .adjacentLocations = {
                [DIRECTION_SOUTH] = LOCATION_JUNGLE,
                [DIRECTION_SOUTHEAST] = LOCATION_EASTERN_PONDS,
                [DIRECTION_EAST] = LOCATION_RIVER,
                [DIRECTION_NORTHEAST] = -1,
                [DIRECTION_NORTH] = LOCATION_PLAINS,
                [DIRECTION_NORTHWEST] = LOCATION_POND,
                [DIRECTION_WEST] = LOCATION_WESTERN_FOREST,
                [DIRECTION_SOUTHWEST] = LOCATION_VOLCANO,
            },
        },
        [LOCATION_UNUSED_28] = DUMMY_LOCATION,
        [LOCATION_UNUSED_29] = DUMMY_LOCATION,
        [LOCATION_UNUSED_30] = DUMMY_LOCATION,
        [LOCATION_UNUSED_31] = DUMMY_LOCATION,
    },
    {
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
        DUMMY_LOCATION,
    }
};
