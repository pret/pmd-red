#include "global.h"
#include "globaldata.h"
#include "friend_areas_map.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
#include "code_8009804.h"
#include "bg_palette_buffer.h"
#include "string_format.h"
#include "code_800D090.h"
#include "friend_area.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "code_80118A4.h"
#include "code_800C9CC.h"
#include "pokemon.h"
#include "decompress.h"
#include "constants/friend_area.h"

extern u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_);
extern void sub_801178C(void);
extern void sub_80117C4(void);
extern void PlayCancelSoundEffect(void);
extern void PlayAcceptSoundEffect(void);
extern void PlayCursorUpDownSoundEffect(void);
extern s32 sprintf(char *, const char *, ...);
extern void sub_800CB20(void);
extern void xxx_call_update_bg_sound_input(void);
extern void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
extern s32 Atan2_4096(PixelPos *a);
extern void sub_80117AC(void);
extern void sub_8011760(void);

EWRAM_INIT struct FriendAreasMap *gFriendAreasMapPtr = NULL;
EWRAM_DATA static u8 sCurrDirection = 0;
EWRAM_DATA static u8 sHeldDpadCounter = 0;

extern const FileArchive gTitleMenuFileArchive;
extern const FileArchive gMonsterFileArchive;

static void MoveToNewLocation(s32 a0, s32 a1, s32 count);
static u8 GetChosenDirection(void);
static s32 ChooseLocation(s32 *a0, s32 *newDirection);
static bool8 ChooseAreaInLocation(void);
static void FadeFromFriendAreasMap(void);
static void InitMapLocations(u8 startingFriendAreaId);

extern u16 gUnknown_2026E4E;

#define NO_AREA NUM_FRIEND_AREAS + 5

 // ななし means 'without name'
#define DUMMY_LOCATION \
{                       \
     .name = _("ななし"), \
     .pos = {0, 0}, \
     .areasIds = {NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA}, \
     .adjacentLocations = {-1, -1, -1, -1, -1, -1, -1, -1}, \
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

void ShowFriendAreasMap(struct struct_unk800F990 *param_1)
{
    gFriendAreasMapPtr = param_1->friendAreasMapPtr;
    gUnknown_2026E4E = 0x1010;
    sub_80095CC(0,0x14);
    UpdateFadeInTile(2);
    gFriendAreasMapPtr->locationsInfo = sFriendAreaLocations[0];
    gFriendAreasMapPtr->unk4A2C = param_1->unk5;
    FriendAreasMap_InitGfx();
    gFriendAreasMapPtr->unk4A28 = -1;
    gFriendAreasMapPtr->unk4A1C = -1;
    InitMapLocations(param_1->startingFriendAreaId);
    gFriendAreasMapPtr->locationIdOnBPress = gFriendAreasMapPtr->teamBaseLocationId;
    sCurrDirection = 0xff;
    sHeldDpadCounter = 0;
    sub_8011760();
    while (1) {
        s32 newLocationId = 0;
        s32 newDirection = 0;
        s32 iVar2 = ChooseLocation(&newLocationId, &newDirection);

        if (iVar2 == 1) {
            MoveToNewLocation(newLocationId, newDirection, 50);
        }
        else if (iVar2 == 2) {
            if (!ChooseAreaInLocation())
                continue;
            param_1->unkC = gFriendAreasMapPtr->chosenFriendAreaId;
            break;
        }
        else if (iVar2 == 3) {
            if (gFriendAreasMapPtr->currLocationId == gFriendAreasMapPtr->locationIdOnBPress) {
                param_1->unkC = 0;
                break;
            }
            MoveToNewLocation(gFriendAreasMapPtr->locationIdOnBPress,0,10);
        }
    }

    FadeFromFriendAreasMap();
    FriendAreasMap_CloseFiles();
    nullsub_16();
}

static s32 ChooseLocation(s32 *newLocationId, s32 *newDirection)
{
    s32 ret = 0;

    FriendAreasMap_ShowDirectionArrows();
    FriendAreasMap_PrintCurrAreaName();
    while (ret == 0) {
        s32 direction;

        FriendAreasMap_RunFrameActions();
        direction = GetChosenDirection();
        if (direction != 0xFF) {
            s32 currLocationId = gFriendAreasMapPtr->currLocationId;
            struct MapLocation *currLocation = &gFriendAreasMapPtr->mapLocations[currLocationId];

            if (currLocation->locationsByDirection[direction] >= 0) {
                s32 newlocId = currLocation->locationsByDirection[direction];
                struct MapLocation *newLocation = &gFriendAreasMapPtr->mapLocations[newlocId];

                if (newLocation->isShown) {
                    ret = 1;
                    *newLocationId = newlocId;
                    *newDirection = direction;
                    gFriendAreasMapPtr->unk4A28 = direction;
                    gFriendAreasMapPtr->unk4A1C = currLocationId;
                }
            }
        }

        if (gRealInputs.pressed & A_BUTTON) {
            PlayAcceptSoundEffect();
            ret = 2;
        }
        if (gRealInputs.pressed & B_BUTTON) {
            PlayCancelSoundEffect();
            ret = 3;
        }
    }
    return ret;
}

static bool8 ChooseAreaInLocation(void)
{
    bool8 ret = FALSE;

    FriendAreasMap_PrintAvailableSubAreas();
    while (1) {
        MenuInputStruct *menuPtr = &gFriendAreasMapPtr->menu;

        AddMenuCursorSprite(menuPtr);
        FriendAreasMap_RunFrameActions();
        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(menuPtr);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(menuPtr);
            PlayCursorUpDownSoundEffect();
        }

        if ((gRealInputs.pressed & A_BUTTON) || menuPtr->unk28.a_button) {
            PlayAcceptSoundEffect();
            gFriendAreasMapPtr->chosenFriendAreaId = gFriendAreasMapPtr->displayedAreas[menuPtr->menuIndex];
            ret = TRUE;
            break;
        }
        if ((gRealInputs.pressed & B_BUTTON) || menuPtr->unk28.b_button) {
            PlayCancelSoundEffect();
            break;
        }
    }

    return ret;
}

static void FadeFromFriendAreasMap(void)
{
    s32 i;

    FriendAreasMap_HideTextWindowAndArrows();
    sub_80117AC();
    for (i = 0; i < 60; i++) {
        gFriendAreasMapPtr->brightness -= 2;
        FriendAreasMap_RunFrameActions();
    }
}

struct MaxMin
{
    s16 min;
    s16 max;
};

static const struct MaxMin sDistanceRanges[] =
{
    {0x380, 0x480},
    {0x80, 0x380},
    {0xF80, 0x80},
    {0xC80, 0xF80},
    {0xB80, 0xC80},
    {0x880, 0xB80},
    {0x780, 0x880},
    {0x480, 0x780},
};

static void InitMapLocations(u8 startingFriendAreaId)
{
    s32 startingLocationId = 0;
    s32 i, j, k;

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        bool8 locationShown = FALSE;
        bool8 areaIsBase = FALSE;
        struct MapLocation *mapLocation = &gFriendAreasMapPtr->mapLocations[i];
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[i];

        for (j = 0; j < NUM_DIRECTIONS; j++) {
            mapLocation->locationsByDirection[j] = -1;
        }
        for (j = 0; j < MAX_AREAS_PER_LOCATION; j++) {
            if (IsFriendAreaShownOnMap(locationInfo->areasIds[j])) {
                if (locationInfo->areasIds[j] == startingFriendAreaId) {
                    startingLocationId = i;
                }
                if (locationInfo->areasIds[j] == 0) {
                    gFriendAreasMapPtr->teamBaseLocationId = i;
                    areaIsBase = TRUE;
                }
                locationShown = TRUE;
            }
        }

        if (locationShown) {
            mapLocation->isShown = TRUE;
            AxResInitFile(&mapLocation->sprite, gFriendAreasMapPtr->unk0[2], (areaIsBase) ? 12 : 1, 0, 0x40, 0, 1);
        }
        else {
            mapLocation->isShown = FALSE;
        }
    }

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        s32 var1, var2;
        struct MapLocation *mapLocation = &gFriendAreasMapPtr->mapLocations[i];
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[i];

        if (!mapLocation->isShown) {
            continue;
        }

        // Grab locations which are next to each other.
        for (j = 0; j < NUM_DIRECTIONS; j++) {
            mapLocation->locationsByDirection[j] = -1;
            if (locationInfo->adjacentLocations[j] >= 0) {
                struct MapLocation *ptr = &gFriendAreasMapPtr->mapLocations[locationInfo->adjacentLocations[j]];
                if (ptr->isShown) {
                    mapLocation->locationsByDirection[j] = locationInfo->adjacentLocations[j];
                }
            }
        }

        var1 = gFriendAreasMapPtr->unk4A28;
        var2 = gFriendAreasMapPtr->unk4A1C;
        if (var1 >= 0 && var2 >= 0) {
            struct MapLocation *ptr = &gFriendAreasMapPtr->mapLocations[var2];
            if (ptr->isShown) {
                var1 += 4;
                var1 &= 7;
                mapLocation->locationsByDirection[var1] = var2;
            }
        }

        // Find locations which are the closest from each other.
        for (j = 0; j < NUM_DIRECTIONS; j++) {
            s32 foundLocationId = -1;
            s32 biggestDistance = 999999;

            if (mapLocation->locationsByDirection[j] >= 0)
                continue;

            for (k = 0; k < NUM_FRIEND_AREA_LOCATIONS; k++) {
                bool8 valid;
                PixelPos pixelPos;
                s32 atanVal;
                struct MapLocation *mapLocation2Info = &gFriendAreasMapPtr->mapLocations[k];
                const struct FriendAreaLocationInfo *location2Info = &gFriendAreasMapPtr->locationsInfo[k];

                if (k == i)
                    continue;
                if (!mapLocation2Info->isShown)
                    continue;

                pixelPos.x = (location2Info->pos.x - locationInfo->pos.x) << 8;
                pixelPos.y = (location2Info->pos.y - locationInfo->pos.y) << 8;
                atanVal = Atan2_4096(&pixelPos);
                pixelPos.x /= 4;
                pixelPos.y /= 4;
                pixelPos.x /= 256;
                pixelPos.y /= 256;
                if (pixelPos.x == 0) {
                    pixelPos.x = 1;
                }
                if (pixelPos.y == 0) {
                    pixelPos.y = 1;
                }

                valid = FALSE;
                if (j == DIRECTION_EAST) {
                    while (atanVal >= 0x1000) {
                        atanVal -= 0x1000;
                    }
                    while (atanVal < 0) {
                        atanVal += 0x1000;
                    }
                    if (sDistanceRanges[j].min < atanVal || sDistanceRanges[j].max > atanVal) {
                        valid = TRUE;
                    }
                }
                else {
                    if (sDistanceRanges[j].min <= atanVal && sDistanceRanges[j].max > atanVal) {
                        valid = TRUE;
                    }
                }

                if (valid) {
                    s32 sum = (pixelPos.x * pixelPos.x) + (pixelPos.y * pixelPos.y);
                    if (biggestDistance > sum) {
                        biggestDistance = sum;
                        foundLocationId = k;
                    }
                }
            }

            if (foundLocationId >= 0) {
                mapLocation->locationsByDirection[j] = foundLocationId;
            }
        }
    }

    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, 0, 0, 0, TRUE);
    gFriendAreasMapPtr->currLocationId = startingLocationId;
    gFriendAreasMapPtr->monSpritePos = gFriendAreasMapPtr->locationsInfo[startingLocationId].pos;
    gFriendAreasMapPtr->bgPos.x = gFriendAreasMapPtr->monSpritePos.x - 120;
    gFriendAreasMapPtr->bgPos.y = gFriendAreasMapPtr->monSpritePos.y - 80;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
}

bool8 IsFriendAreaShownOnMap(u8 friendAreaId)
{
    if (friendAreaId >= NUM_FRIEND_AREAS) return FALSE;
    if (friendAreaId == 0) return TRUE;
    if (gFriendAreas[friendAreaId]) return TRUE;

    return FALSE;
}

static u8 GetChosenDirection(void)
{
    u8 dirsAll[] = {0xff, DIRECTION_SOUTH, DIRECTION_EAST, DIRECTION_SOUTHEAST, DIRECTION_NORTH, 0xff, DIRECTION_NORTHEAST, 0xff, DIRECTION_WEST, DIRECTION_SOUTHWEST, 0xff, 0xff, DIRECTION_NORTHWEST, 0xff, 0xff, 0xff};
    u8 dirsDiagonal[] = {0xff, 0xff, 0xff, DIRECTION_SOUTHEAST, 0xff, 0xff, DIRECTION_NORTHEAST, 0xff, 0xff, DIRECTION_SOUTHWEST, 0xff, 0xff, DIRECTION_NORTHWEST, 0xff, 0xff, 0xff};
    u32 id = 0;
    u8 *dirs = (gRealInputs.held & R_BUTTON) ? dirsDiagonal : dirsAll;

    if (gRealInputs.held & DPAD_DOWN) {
        id |= 1;
    }
    if (gRealInputs.held & DPAD_RIGHT) {
        id |= 2;
    }
    if (gRealInputs.held & DPAD_UP) {
        id |= 4;
    }
    if (gRealInputs.held & DPAD_LEFT) {
        id |= 8;
    }

    if (sCurrDirection == dirs[id]) {
        if (++sHeldDpadCounter >= 3) { // It'll only choose a New Area, if the DPAD was held for more than 3 frames.
            return dirs[id];
        }
    }
    else {
        sCurrDirection = dirs[id];
        sHeldDpadCounter = 0;
    }
    return 0xFF;
}

static void MoveToNewLocation(s32 destLocationId, s32 a1, s32 nFrames)
{
    s32 i, currLocationId;
    DungeonPos startingPos, dstPos;

    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, a1 & 7, 0, 0, TRUE);
    FriendAreasMap_HideTextWindowAndArrows();

    currLocationId = gFriendAreasMapPtr->currLocationId;
    startingPos = gFriendAreasMapPtr->locationsInfo[currLocationId].pos;
    dstPos = gFriendAreasMapPtr->locationsInfo[destLocationId].pos;

    PlayCursorUpDownSoundEffect();
    for (i = 0; i < nFrames; i++) {
        gFriendAreasMapPtr->monSpritePos.x = ((((dstPos.x - startingPos.x) * (i << 8)) / nFrames) / 256) + startingPos.x;
        gFriendAreasMapPtr->monSpritePos.y = ((((dstPos.y - startingPos.y) * (i << 8)) / nFrames) / 256) + startingPos.y;

        FriendAreasMap_UpdateMonSpritePosition();
        FriendAreasMap_UpdateBg();
        FriendAreasMap_RunFrameActions();
    }

    gFriendAreasMapPtr->currLocationId = destLocationId;
    gFriendAreasMapPtr->monSpritePos = gFriendAreasMapPtr->locationsInfo[destLocationId].pos;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
    FriendAreasMap_RunFrameActions();
    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, 0, 0, 0, TRUE);
}

void PrintFriendAreaNameInMap(u8 *strBuffer, u8 index)
{
    if (index == 0) {
        FormatString("$t Team Base", strBuffer, strBuffer + 0x50, 0);
    }
    else {
        WriteFriendAreaName(strBuffer, index, FALSE);
    }
}

static UNUSED void GetAreaMapPosition(u8 areaId, DungeonPos *dst)
{
    s32 i, j;

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        const struct FriendAreaLocationInfo *locationInfo = &sFriendAreaLocations[0][i];
        for (j = 0; j < MAX_AREAS_PER_LOCATION; j++) {
            if (locationInfo->areasIds[j] == areaId) {
                dst->x = locationInfo->pos.x;
                dst->y = locationInfo->pos.y;
                return;
            }
        }
    }
    dst->x = 0;
    dst->y = 0;
}
