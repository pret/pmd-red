#define NO_AREA NUM_FRIEND_AREAS + 5

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
            .areasIds = {MT_DEEPGREEN, MT_CLEFT, MT_MOONVIEW, MT_DISCIPLINE, DARKNESS_RIDGE, RAINBOW_PEAK, NO_AREA, NO_AREA},
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
            .areasIds = {FRIGID_CAVERN, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {BEAU_PLAINS, SKY_BLUE_PLAINS, SACRED_FIELD, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {SAFARI, WILD_PLAINS, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {RAVAGED_FIELD, MAGNETIC_QUARRY, THUNDER_MEADOW, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {MIST_RISE_FOREST, FLYAWAY_FOREST, OVERGROWN_FOREST, ENERGETIC_FOREST, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {MUSHROOM_FOREST, HEALING_FOREST, TRANSFORM_FOREST, SECRETIVE_FOREST, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {RUB_A_DUB_RIVER, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {TADPOLE_POND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {TURTLESHELL_POND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {MYSTIC_LAKE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {WATERFALL_LAKE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {PEANUT_SWAMP, POISON_SWAMP, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {ECHO_CAVE, DRAGON_CAVE, BOULDER_CAVE, CRYPTIC_CAVE, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {JUNGLE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {DECREPIT_LAB, POWER_PLANT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {SCORCHED_PLAINS, CRATER, VOLCANIC_PIT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {FURNACE_DESERT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {ANCIENT_RELIC, AGED_CHAMBER_AN, AGED_CHAMBER_O_EXCLAIM, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {STRATOS_LOOKOUT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {LEGENDARY_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {SOUTHERN_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {ENCLOSED_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {FINAL_ISLAND, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {BOUNTIFUL_SEA, SERENE_SEA, DEEP_SEA_CURRENT, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {TREASURE_SEA, DEEP_SEA_FLOOR, SEAFLOOR_CAVE, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
            .areasIds = {SHALLOW_BEACH, ICE_FLOE_BEACH, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA},
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
