#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "code_800D090.h"
#include "code_8092334.h"
#include "dungeon_info.h"
#include "items.h"
#include "moves.h"
#include "pokemon.h"
#include "random.h"
#include "string_format.h"
#include "strings.h"
#include "dungeon_data.h"

extern const char gUnknown_8108F10[];
extern const char gUnknown_8108F18[];
extern const char gUnknown_8108F2C[];
extern u8 gUnknown_8108F40[];
extern u16 gUnknown_8108F42[];
extern u8 gUnknown_8108F4A[4];
extern u8 gUnknown_8108F50[];

static void sub_8090888(u8 *param_1, u8 *param_2);
static bool8 sub_8090820(u16 moveID);

static const u8 sDungeonFloorCount[] = {
    [DUNGEON_TINY_WOODS]                = 4,
    [DUNGEON_THUNDERWAVE_CAVE]          = 6,
    [DUNGEON_MT_STEEL]                  = 10,
    [DUNGEON_SINISTER_WOODS]            = 14,
    [DUNGEON_SILENT_CHASM]              = 10,
    [DUNGEON_MT_THUNDER]                = 11,
    [DUNGEON_MT_THUNDER_PEAK]           = 4,
    [DUNGEON_GREAT_CANYON]              = 13,
    [DUNGEON_LAPIS_CAVE]                = 15,
    [DUNGEON_MT_BLAZE]                  = 13,
    [DUNGEON_MT_BLAZE_PEAK]             = 4,
    [DUNGEON_FROSTY_FOREST]             = 10,
    [DUNGEON_FROSTY_GROTTO]             = 6,
    [DUNGEON_MT_FREEZE]                 = 16,
    [DUNGEON_MT_FREEZE_PEAK]            = 6,
    [DUNGEON_MAGMA_CAVERN]              = 24,
    [DUNGEON_MAGMA_CAVERN_PIT]          = 4,
    [DUNGEON_SKY_TOWER]                 = 26,
    [DUNGEON_SKY_TOWER_SUMMIT]          = 10,
    [DUNGEON_STORMY_SEA]                = 41,
    [DUNGEON_SILVER_TRENCH]             = 100,
    [DUNGEON_METEOR_CAVE]               = 21,
    [DUNGEON_MT_FREEZE_PEAK_2]          = 5,
    [DUNGEON_WESTERN_CAVE]              = 100,
    [DUNGEON_BOSS_3]                    = 21,
    [DUNGEON_BOSS_4]                    = 12,
    [DUNGEON_WISH_CAVE]                 = 100,
    [DUNGEON_BURIED_RELIC]              = 100,
    [DUNGEON_PITFALL_VALLEY]            = 26,
    [DUNGEON_NORTHERN_RANGE]            = 26,
    [DUNGEON_BOSS_9]                    = 13,
    [DUNGEON_DESERT_REGION]             = 21,
    [DUNGEON_SOUTHERN_CAVERN]           = 51,
    [DUNGEON_WYVERN_HILL]               = 31,
    [DUNGEON_FIERY_FIELD]               = 31,
    [DUNGEON_NORTHWIND_FIELD]           = 31,
    [DUNGEON_SOLAR_CAVE]                = 21,
    [DUNGEON_LIGHTNING_FIELD]           = 31,
    [DUNGEON_DARKNIGHT_RELIC]           = 16,
    [DUNGEON_WONDROUS_SEA]              = 13,
    [DUNGEON_MURKY_CAVE]                = 20,
    [DUNGEON_GRAND_SEA]                 = 31,
    [DUNGEON_UPROAR_FOREST]             = 11,
    [DUNGEON_ODDITY_CAVE]               = 16,
    [DUNGEON_REMAINS_ISLAND]            = 21,
    [DUNGEON_MARVELOUS_SEA]             = 21,
    [DUNGEON_FANTASY_STRAIT]            = 31,
    [DUNGEON_ROCK_PATH]                 = 5,
    [DUNGEON_SNOW_PATH]                 = 5,
    [DUNGEON_AUTOPILOT]                 = 11,
    [DUNGEON_D50]                       = 3,
    [DUNGEON_D51]                       = 51,
    [DUNGEON_NORMAL_MAZE]               = 70,
    [DUNGEON_HOWLING_FOREST]            = 16,
    [DUNGEON_D54]                       = 31,
    [DUNGEON_POISON_MAZE]               = 20,
    [DUNGEON_WATERFALL_POND]            = 20,
    [DUNGEON_UNKNOWN_RELIC]             = 12,
    [DUNGEON_JOYOUS_TOWER]              = 100,
    [DUNGEON_FAR_OFF_SEA]               = 76,
    [DUNGEON_MT_FARAWAY]                = 41,
    [DUNGEON_D61]                       = 100,
    [DUNGEON_PURITY_FOREST]             = 100,
    [DUNGEON_OUT_ON_RESCUE]             = 2,
};

// All dungeons always start at the first floor.
static const u8 sDungeonStartingFloor[] = {
    [DUNGEON_TINY_WOODS]                = 0,
    [DUNGEON_THUNDERWAVE_CAVE]          = 0,
    [DUNGEON_MT_STEEL]                  = 0,
    [DUNGEON_SINISTER_WOODS]            = 0,
    [DUNGEON_SILENT_CHASM]              = 0,
    [DUNGEON_MT_THUNDER]                = 0,
    [DUNGEON_MT_THUNDER_PEAK]           = 0,
    [DUNGEON_GREAT_CANYON]              = 0,
    [DUNGEON_LAPIS_CAVE]                = 0,
    [DUNGEON_MT_BLAZE]                  = 0,
    [DUNGEON_MT_BLAZE_PEAK]             = 0,
    [DUNGEON_FROSTY_FOREST]             = 0,
    [DUNGEON_FROSTY_GROTTO]             = 0,
    [DUNGEON_MT_FREEZE]                 = 0,
    [DUNGEON_MT_FREEZE_PEAK]            = 0,
    [DUNGEON_MAGMA_CAVERN]              = 0,
    [DUNGEON_MAGMA_CAVERN_PIT]          = 0,
    [DUNGEON_SKY_TOWER]                 = 0,
    [DUNGEON_SKY_TOWER_SUMMIT]          = 0,
    [DUNGEON_STORMY_SEA]                = 0,
    [DUNGEON_SILVER_TRENCH]             = 0,
    [DUNGEON_METEOR_CAVE]               = 0,
    [DUNGEON_MT_FREEZE_PEAK_2]          = 0,
    [DUNGEON_WESTERN_CAVE]              = 0,
    [DUNGEON_BOSS_3]                    = 0,
    [DUNGEON_BOSS_4]                    = 0,
    [DUNGEON_WISH_CAVE]                 = 0,
    [DUNGEON_BURIED_RELIC]              = 0,
    [DUNGEON_PITFALL_VALLEY]            = 0,
    [DUNGEON_NORTHERN_RANGE]            = 0,
    [DUNGEON_BOSS_9]                    = 0,
    [DUNGEON_DESERT_REGION]             = 0,
    [DUNGEON_SOUTHERN_CAVERN]           = 0,
    [DUNGEON_WYVERN_HILL]               = 0,
    [DUNGEON_FIERY_FIELD]               = 0,
    [DUNGEON_NORTHWIND_FIELD]           = 0,
    [DUNGEON_SOLAR_CAVE]                = 0,
    [DUNGEON_LIGHTNING_FIELD]           = 0,
    [DUNGEON_DARKNIGHT_RELIC]           = 0,
    [DUNGEON_WONDROUS_SEA]              = 0,
    [DUNGEON_MURKY_CAVE]                = 0,
    [DUNGEON_GRAND_SEA]                 = 0,
    [DUNGEON_UPROAR_FOREST]             = 0,
    [DUNGEON_ODDITY_CAVE]               = 0,
    [DUNGEON_REMAINS_ISLAND]            = 0,
    [DUNGEON_MARVELOUS_SEA]             = 0,
    [DUNGEON_FANTASY_STRAIT]            = 0,
    [DUNGEON_ROCK_PATH]                 = 0,
    [DUNGEON_SNOW_PATH]                 = 0,
    [DUNGEON_AUTOPILOT]                 = 0,
    [DUNGEON_D50]                       = 0,
    [DUNGEON_D51]                       = 0,
    [DUNGEON_NORMAL_MAZE]               = 0,
    [DUNGEON_HOWLING_FOREST]            = 0,
    [DUNGEON_D54]                       = 0,
    [DUNGEON_POISON_MAZE]               = 0,
    [DUNGEON_WATERFALL_POND]            = 0,
    [DUNGEON_UNKNOWN_RELIC]             = 0,
    [DUNGEON_JOYOUS_TOWER]              = 0,
    [DUNGEON_FAR_OFF_SEA]               = 0,
    [DUNGEON_MT_FARAWAY]                = 0,
    [DUNGEON_D61]                       = 0,
    [DUNGEON_PURITY_FOREST]             = 0,
    [DUNGEON_OUT_ON_RESCUE]             = 0,
};

static const DungeonLocation gUnknown_8107828[] =
{
    { .id = DUNGEON_MT_STEEL, .floor = 9 },
    { .id = DUNGEON_SINISTER_WOODS, .floor = 13 },
    { .id = DUNGEON_MT_THUNDER_PEAK, .floor = 3 },
    { .id = DUNGEON_MT_BLAZE_PEAK, .floor = 3 },
    { .id = DUNGEON_FROSTY_GROTTO, .floor = 5 },
    { .id = DUNGEON_MT_FREEZE_PEAK, .floor = 5 },
    { .id = DUNGEON_MAGMA_CAVERN_PIT, .floor = 2 },
    { .id = DUNGEON_MAGMA_CAVERN_PIT, .floor = 3 },
    { .id = DUNGEON_SKY_TOWER_SUMMIT, .floor = 9 },
    { .id = DUNGEON_STORMY_SEA, .floor = 40 },
    { .id = DUNGEON_SILVER_TRENCH, .floor = 99 },
    { .id = DUNGEON_METEOR_CAVE, .floor = 20 },
    { .id = DUNGEON_WESTERN_CAVE, .floor = 59 },
    { .id = DUNGEON_WESTERN_CAVE, .floor = 99 },
    { .id = DUNGEON_WISH_CAVE, .floor = 20 },
    { .id = DUNGEON_WISH_CAVE, .floor = 50 },
    { .id = DUNGEON_WISH_CAVE, .floor = 99 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 15 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 25 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 35 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 45 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 60 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 70 },
    { .id = DUNGEON_BURIED_RELIC, .floor = 80 },
    { .id = DUNGEON_NORTHERN_RANGE, .floor = 25 },
    { .id = DUNGEON_WYVERN_HILL, .floor = 20 },
    { .id = DUNGEON_WYVERN_HILL, .floor = 30 },
    { .id = DUNGEON_FIERY_FIELD, .floor = 30 },
    { .id = DUNGEON_NORTHWIND_FIELD, .floor = 20 },
    { .id = DUNGEON_NORTHWIND_FIELD, .floor = 30 },
    { .id = DUNGEON_SOLAR_CAVE, .floor = 10 },
    { .id = DUNGEON_SOLAR_CAVE, .floor = 15 },
    { .id = DUNGEON_SOLAR_CAVE, .floor = 20 },
    { .id = DUNGEON_LIGHTNING_FIELD, .floor = 30 },
    { .id = DUNGEON_GRAND_SEA, .floor = 15 },
    { .id = DUNGEON_GRAND_SEA, .floor = 25 },
    { .id = DUNGEON_UPROAR_FOREST, .floor = 10 },
    { .id = DUNGEON_AUTOPILOT, .floor = 1 },
    { .id = DUNGEON_AUTOPILOT, .floor = 2 },
    { .id = DUNGEON_AUTOPILOT, .floor = 3 },
    { .id = DUNGEON_AUTOPILOT, .floor = 4 },
    { .id = DUNGEON_AUTOPILOT, .floor = 5 },
    { .id = DUNGEON_AUTOPILOT, .floor = 6 },
    { .id = DUNGEON_AUTOPILOT, .floor = 7 },
    { .id = DUNGEON_AUTOPILOT, .floor = 8 },
    { .id = DUNGEON_AUTOPILOT, .floor = 9 },
    { .id = DUNGEON_AUTOPILOT, .floor = 10 },
    // Used for all mazes, see GeneralizeMazeDungeonLoc
    { .id = DUNGEON_NORMAL_MAZE, .floor = 3 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 6 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 9 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 12 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 15 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 18 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 21 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 24 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 27 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 30 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 33 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 36 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 39 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 42 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 45 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 48 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 51 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 54 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 57 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 60 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 63 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 66 },
    { .id = DUNGEON_NORMAL_MAZE, .floor = 69 },
    { .id = DUNGEON_HOWLING_FOREST, .floor = 15 },
    { .id = DUNGEON_FAR_OFF_SEA, .floor = 50 },
    { .id = DUNGEON_FAR_OFF_SEA, .floor = 72 },
    { .id = DUNGEON_MT_FARAWAY, .floor = 30 },
    { .id = DUNGEON_MT_FARAWAY, .floor = 40 },
    { .id = DUNGEON_PURITY_FOREST, .floor = 99 },
    { .id = DUNGEON_OUT_ON_RESCUE, .floor = 255 }
};

// These correspond to mission difficulty with 1 being the easiest(F) and 15 being the highest (*)
static const u8 sFloorMissionDifficulty_TinyWoods[] = {
    [0] = 0,
    [1 ... 3] = 1,
};
static const u8 sFloorMissionDifficulty_ThunderwaveCave[] = {
    [0] = 0,
    [1 ... 5] = 1,
};
static const u8 sFloorMissionDifficulty_MtSteel[] = {
    [0] = 0,
    [1 ... 9] = 1,
};
static const u8 sFloorMissionDifficulty_SinisterWoods[] = {
    [0] = 0,
    [1 ... 13] = 2,
};
static const u8 sFloorMissionDifficulty_SilentChasm[] = {
    [0] = 0,
    [1 ... 7] = 2,
    [8 ... 9] = 3,
};
static const u8 sFloorMissionDifficulty_MtThunder[] = {
    [0] = 0,
    [1 ... 10] = 3,
};
static const u8 sFloorMissionDifficulty_MtThunderPeak[] = {
    [0] = 0,
    [1 ... 3] = 3,
};
static const u8 sFloorMissionDifficulty_GreatCanyon[] = {
    [0] = 0,
    [1 ... 12] = 4,
};
static const u8 sFloorMissionDifficulty_LapisCave[] = {
    [0] = 0,
    [1 ... 14] = 4,
};
static const u8 sFloorMissionDifficulty_MtBlaze[] = {
    [0] = 0,
    [1 ... 12] = 4,
};
static const u8 sFloorMissionDifficulty_MtBlazePeak[] = {
    [0] = 0,
    [1 ... 3] = 4,
};
static const u8 sFloorMissionDifficulty_FrostyForest[] = {
    [0] = 0,
    [1 ... 5] = 4,
    [6 ... 9] = 5,
};
static const u8 sFloorMissionDifficulty_FrostyGrotto[] = {
    [0] = 0,
    [1 ... 5] = 5,
};
static const u8 sFloorMissionDifficulty_MtFreeze[] = {
    [0] = 0,
    [1 ... 15] = 5,
};
static const u8 sFloorMissionDifficulty_MtFreezePeak[] = {
    [0] = 0,
    [1 ... 5] = 5,
};
static const u8 sFloorMissionDifficulty_MagmaCavern[] = {
    [0] = 0,
    [1 ... 23] = 6,
};
static const u8 sFloorMissionDifficulty_MagmaCavernPit[] = {
    [0] = 0,
    [1 ... 3] = 6,
};
static const u8 sFloorMissionDifficulty_SkyTower[] = {
    [0] = 0,
    [1 ... 25] = 6,
};
static const u8 sFloorMissionDifficulty_SkyTowerSummit[] = {
    [0] = 0,
    [1 ... 9] = 7,
};
static const u8 sFloorMissionDifficulty_StormySea[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 40] = 9,
};
static const u8 sFloorMissionDifficulty_SilverTrench[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 99] = 11,
};
static const u8 sFloorMissionDifficulty_MeteorCave[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 20] = 8,
};
static const u8 sFloorMissionDifficulty_MtFreezePeak_2[] = {
    [0] = 0,
    [1 ... 4] = 5,
};
static const u8 sFloorMissionDifficulty_WesternCave[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75 ... 99] = 12,
};
static const u8 sFloorMissionDifficulty_Boss_3[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 20] = 8,
};
static const u8 sFloorMissionDifficulty_Boss_4[] = {
    [0] = 0,
    [1 ... 11] = 1,
};
static const u8 sFloorMissionDifficulty_WishCave[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75 ... 99] = 12,
};
static const u8 sFloorMissionDifficulty_BuriedRelic[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75 ... 99] = 12,
};
static const u8 sFloorMissionDifficulty_PitfallValley[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 19] = 8,
    [20 ... 25] = 9,
};
static const u8 sFloorMissionDifficulty_NorthernRange[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 19] = 8,
    [20 ... 25] = 9,
};
static const u8 sFloorMissionDifficulty_Boss_9[] = {
    [0] = 0,
    [1 ... 12] = 1,
};
static const u8 sFloorMissionDifficulty_DesertRegion[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 20] = 8,
};
static const u8 sFloorMissionDifficulty_SouthernCavern[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 50] = 9,
};
static const u8 sFloorMissionDifficulty_WyvernHill[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30] = 9,
};
static const u8 sFloorMissionDifficulty_FieryField[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30] = 9,
};
static const u8 sFloorMissionDifficulty_NorthwindField[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30] = 9,
};
static const u8 sFloorMissionDifficulty_SolarCave[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 20] = 8,
};
static const u8 sFloorMissionDifficulty_LightningField[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30] = 9,
};
static const u8 sFloorMissionDifficulty_DarknightRelic[] = {
    [0] = 0,
    [1 ... 15] = 7,
};
static const u8 sFloorMissionDifficulty_WondrousSea[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 12] = 8,
};
static const u8 sFloorMissionDifficulty_MurkyCave[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 19] = 8,
};
static const u8 sFloorMissionDifficulty_GrandSea[] = {
    [0] = 0,
    [1 ... 10] = 7,
    [11 ... 30] = 8,
};
static const u8 sFloorMissionDifficulty_UproarForest[] = {
    [0] = 0,
    [1 ... 10] = 5,
};
static const u8 sFloorMissionDifficulty_OddityCave[] = {
    [0] = 0,
    [1 ... 15] = 7,
};
static const u8 sFloorMissionDifficulty_RemainsIsland[] = {
    [0] = 0,
    [1 ... 9] = 7,
    [10 ... 20] = 8,
};
static const u8 sFloorMissionDifficulty_MarvelousSea[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20] = 8,
};
static const u8 sFloorMissionDifficulty_FantasyStrait[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30] = 9,
};
static const u8 sFloorMissionDifficulty_RockPath[] = {
    [0] = 0,
    [1 ... 4] = 1,
};
static const u8 sFloorMissionDifficulty_SnowPath[] = {
    [0] = 0,
    [1 ... 4] = 1,
};
static const u8 sFloorMissionDifficulty_Autopilot[] = {
    [0] = 0,
    [1 ... 10] = 1,
};
static const u8 sFloorMissionDifficulty_D50[] = {
    [0] = 0,
    [1 ... 2] = 1,
};
static const u8 sFloorMissionDifficulty_D51[] = {
    [0] = 0,
    [1 ... 50] = 15,
};
static const u8 sFloorMissionDifficulty_NormalMaze[] = {
    [0] = 0,
    [1 ... 69] = 1,
};
static const u8 sFloorMissionDifficulty_HowlingForest[] = {
    [0] = 0,
    [1 ... 15] = 7,
};
static const u8 sFloorMissionDifficulty_D54[] = {
    [0] = 0,
    [1 ... 30] = 1,
};
static const u8 sFloorMissionDifficulty_PoisonMaze[] = {
    [0] = 0,
    [1 ... 19] = 1,
};
static const u8 sFloorMissionDifficulty_WaterfallPond[] = {
    [0] = 0,
    [1 ... 19] = 7,
};
static const u8 sFloorMissionDifficulty_UnknownRelic[] = {
    [0] = 0,
    [1 ... 11] = 7,
};
static const u8 sFloorMissionDifficulty_JoyousTower[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75 ... 99] = 12,
};
static const u8 sFloorMissionDifficulty_FarOffSea[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75] = 12,
};
static const u8 sFloorMissionDifficulty_MtFaraway[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 40] = 10,
};
static const u8 sFloorMissionDifficulty_D61[] = {
    [0] = 0,
    [1 ... 19] = 7,
    [20 ... 29] = 8,
    [30 ... 35] = 9,
    [36 ... 59] = 10,
    [60 ... 74] = 11,
    [75 ... 99] = 12,
};
static const u8 sFloorMissionDifficulty_PurityForest[] = {
    [0] = 0,
    [1 ... 19] = 8,
    [20 ... 24] = 9,
    [25 ... 35] = 10,
    [36 ... 59] = 11,
    [60 ... 74] = 12,
    [75 ... 88] = 13,
    [89 ... 99] = 14,
};
static const u8 sFloorMissionDifficulty_OutOnRescue[] = {
    [0] = 0,
    [1] = 7,
    [2] = 0,
};

// [id][floor]
static const u8 *const sDungeonMissionDifficulty[] = {
    [DUNGEON_TINY_WOODS] = sFloorMissionDifficulty_TinyWoods,
    [DUNGEON_THUNDERWAVE_CAVE] = sFloorMissionDifficulty_ThunderwaveCave,
    [DUNGEON_MT_STEEL] = sFloorMissionDifficulty_MtSteel,
    [DUNGEON_SINISTER_WOODS] = sFloorMissionDifficulty_SinisterWoods,
    [DUNGEON_SILENT_CHASM] = sFloorMissionDifficulty_SilentChasm,
    [DUNGEON_MT_THUNDER] = sFloorMissionDifficulty_MtThunder,
    [DUNGEON_MT_THUNDER_PEAK] = sFloorMissionDifficulty_MtThunderPeak,
    [DUNGEON_GREAT_CANYON] = sFloorMissionDifficulty_GreatCanyon,
    [DUNGEON_LAPIS_CAVE] = sFloorMissionDifficulty_LapisCave,
    [DUNGEON_MT_BLAZE] = sFloorMissionDifficulty_MtBlaze,
    [DUNGEON_MT_BLAZE_PEAK] = sFloorMissionDifficulty_MtBlazePeak,
    [DUNGEON_FROSTY_FOREST] = sFloorMissionDifficulty_FrostyForest,
    [DUNGEON_FROSTY_GROTTO] = sFloorMissionDifficulty_FrostyGrotto,
    [DUNGEON_MT_FREEZE] = sFloorMissionDifficulty_MtFreeze,
    [DUNGEON_MT_FREEZE_PEAK] = sFloorMissionDifficulty_MtFreezePeak,
    [DUNGEON_MAGMA_CAVERN] = sFloorMissionDifficulty_MagmaCavern,
    [DUNGEON_MAGMA_CAVERN_PIT] = sFloorMissionDifficulty_MagmaCavernPit,
    [DUNGEON_SKY_TOWER] = sFloorMissionDifficulty_SkyTower,
    [DUNGEON_SKY_TOWER_SUMMIT] = sFloorMissionDifficulty_SkyTowerSummit,
    [DUNGEON_STORMY_SEA] = sFloorMissionDifficulty_StormySea,
    [DUNGEON_SILVER_TRENCH] = sFloorMissionDifficulty_SilverTrench,
    [DUNGEON_METEOR_CAVE] = sFloorMissionDifficulty_MeteorCave,
    [DUNGEON_MT_FREEZE_PEAK_2] = sFloorMissionDifficulty_MtFreezePeak_2,
    [DUNGEON_WESTERN_CAVE] = sFloorMissionDifficulty_WesternCave,
    [DUNGEON_BOSS_3] = sFloorMissionDifficulty_Boss_3,
    [DUNGEON_BOSS_4] = sFloorMissionDifficulty_Boss_4,
    [DUNGEON_WISH_CAVE] = sFloorMissionDifficulty_WishCave,
    [DUNGEON_BURIED_RELIC] = sFloorMissionDifficulty_BuriedRelic,
    [DUNGEON_PITFALL_VALLEY] = sFloorMissionDifficulty_PitfallValley,
    [DUNGEON_NORTHERN_RANGE] = sFloorMissionDifficulty_NorthernRange,
    [DUNGEON_BOSS_9] = sFloorMissionDifficulty_Boss_9,
    [DUNGEON_DESERT_REGION] = sFloorMissionDifficulty_DesertRegion,
    [DUNGEON_SOUTHERN_CAVERN] = sFloorMissionDifficulty_SouthernCavern,
    [DUNGEON_WYVERN_HILL] = sFloorMissionDifficulty_WyvernHill,
    [DUNGEON_FIERY_FIELD] = sFloorMissionDifficulty_FieryField,
    [DUNGEON_NORTHWIND_FIELD] = sFloorMissionDifficulty_NorthwindField,
    [DUNGEON_SOLAR_CAVE] = sFloorMissionDifficulty_SolarCave,
    [DUNGEON_LIGHTNING_FIELD] = sFloorMissionDifficulty_LightningField,
    [DUNGEON_DARKNIGHT_RELIC] = sFloorMissionDifficulty_DarknightRelic,
    [DUNGEON_WONDROUS_SEA] = sFloorMissionDifficulty_WondrousSea,
    [DUNGEON_MURKY_CAVE] = sFloorMissionDifficulty_MurkyCave,
    [DUNGEON_GRAND_SEA] = sFloorMissionDifficulty_GrandSea,
    [DUNGEON_UPROAR_FOREST] = sFloorMissionDifficulty_UproarForest,
    [DUNGEON_ODDITY_CAVE] = sFloorMissionDifficulty_OddityCave,
    [DUNGEON_REMAINS_ISLAND] = sFloorMissionDifficulty_RemainsIsland,
    [DUNGEON_MARVELOUS_SEA] = sFloorMissionDifficulty_MarvelousSea,
    [DUNGEON_FANTASY_STRAIT] = sFloorMissionDifficulty_FantasyStrait,
    [DUNGEON_ROCK_PATH] = sFloorMissionDifficulty_RockPath,
    [DUNGEON_SNOW_PATH] = sFloorMissionDifficulty_SnowPath,
    [DUNGEON_AUTOPILOT] = sFloorMissionDifficulty_Autopilot,
    [DUNGEON_D50] = sFloorMissionDifficulty_D50,
    [DUNGEON_D51] = sFloorMissionDifficulty_D51,
    [DUNGEON_NORMAL_MAZE] = sFloorMissionDifficulty_NormalMaze,
    [DUNGEON_HOWLING_FOREST] = sFloorMissionDifficulty_HowlingForest,
    [DUNGEON_D54] = sFloorMissionDifficulty_D54,
    [DUNGEON_POISON_MAZE] = sFloorMissionDifficulty_PoisonMaze,
    [DUNGEON_WATERFALL_POND] = sFloorMissionDifficulty_WaterfallPond,
    [DUNGEON_UNKNOWN_RELIC] = sFloorMissionDifficulty_UnknownRelic,
    [DUNGEON_JOYOUS_TOWER] = sFloorMissionDifficulty_JoyousTower,
    [DUNGEON_FAR_OFF_SEA] = sFloorMissionDifficulty_FarOffSea,
    [DUNGEON_MT_FARAWAY] = sFloorMissionDifficulty_MtFaraway,
    [DUNGEON_D61] = sFloorMissionDifficulty_D61,
    [DUNGEON_PURITY_FOREST] = sFloorMissionDifficulty_PurityForest,
    [DUNGEON_OUT_ON_RESCUE] = sFloorMissionDifficulty_OutOnRescue,
};

const u8 *GetDungeonName1(u8 dungeon)
{
    return gDungeonNames[dungeon].name1;
}

const u8 *GetDungeonName2(u8 dungeon)
{
    return gDungeonNames[dungeon].name2;
}

bool8 IsStairDirectionUp(u8 dungeon)
{
    return gDungeons[dungeon].stairDirectionUp;
}

s16 GetTurnLimit(u8 dungeon)
{
    return gDungeons[dungeon].turnLimit;
}

bool8 IsEnterWithoutGameSave(u8 dungeon)
{
    return gDungeons[dungeon].enterWithoutGameSave;
}

u8 HasCheckpoint(u8 dungeon)
{
    return gDungeons[dungeon].hasCheckpoint;
}

bool8 IsLevelResetTo1(u8 dungeon)
{
    return gDungeons[dungeon].levelResetTo1;
}

u32 GetMaxItemsAllowed(u8 dungeon)
{
    return gDungeons[dungeon].maxItemsAllowed;
}

bool8 IsKeepMoney(u8 dungeon)
{
    return gDungeons[dungeon].keepMoney;
}

s8 GetRescuesAllowed(u8 dungeon)
{
    return gDungeons[dungeon].rescuesAllowed;
}

bool8 IsRecruitingEnabled(u8 dungeon)
{
    return gDungeons[dungeon].recruitingEnabled;
}

bool8 CanLeaderSwitch(u8 dungeon)
{
    return gDungeons[dungeon].leaderCanSwitch;
}

s16 GetRandomMovementChance(u8 dungeon)
{
    return gDungeons[dungeon].randomMovementChance;
}

bool8 sub_809017C(DungeonLocation* a1)
{
    DungeonLocation location;
    int i;
    GeneralizeMazeDungeonLoc(&location, a1);
    for (i = 0; i < 999 && gUnknown_8107828[i].id != DUNGEON_OUT_ON_RESCUE; ++i) {
        if (location.id == gUnknown_8107828[i].id &&
            location.floor == gUnknown_8107828[i].floor) {
            return TRUE;
        }
    }
    return FALSE;
}

// Treats all mazes as DUNGEON_NORMAL_MAZE
void GeneralizeMazeDungeonLoc(DungeonLocation *dst, const DungeonLocation *src)
{
    if (DUNGEON_IS_MAZE(src->id)) {
        dst->id = DUNGEON_NORMAL_MAZE;
        dst->floor = (src->id - DUNGEON_NORMAL_MAZE_2) * 3 + src->floor;
    }
    else {
        *dst = *src;
    }
}

void PrintYellowDungeonNametoBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    sprintfStatic(buffer, gUnknown_8108F10, gDungeonNames[dungeonLocation->id].name1); // {color YELLOW_D}%s{reset} (normal floor print (no B)
}

void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    if(gDungeons[dungeonLocation->id].stairDirectionUp){
        sprintfStatic(buffer, gUnknown_8108F18, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); //_F
    }
    else
    {
        sprintfStatic(buffer, gUnknown_8108F2C, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); // B _F
    }
}

void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    strncpy(buffer, gDungeonNames[dungeonLocation->id].name1, 0x50);
}

s32 GetDungeonFloorCount(u8 dungeon)
{
    if (DUNGEON_IS_MAZE(dungeon))
        return 4;
    else if (dungeon > DUNGEON_PURITY_FOREST)
        return 1;
    else
        return sDungeonFloorCount[dungeon];
}

s32 GetDungeonStartingFloor(u8 dungeon)
{
    if (DUNGEON_IS_MAZE(dungeon))
        return 0;
    else if (dungeon > DUNGEON_PURITY_FOREST)
        return 0;
    else
        return sDungeonStartingFloor[dungeon];
}

// arm9.bin::0205ECA0
void WriteDungeonLocationBits(DataSerializer* r0, DungeonLocation* src)
{
    WriteBits(r0, &src->id, 7);
    WriteBits(r0, &src->floor, 7);
}

// arm9.bin::0205EC64
void ReadDungeonLocationBits(DataSerializer* r0, DungeonLocation* dst)
{
    dst->id = 0;
    dst->floor = 0;
    ReadBits(r0, &dst->id, 7);
    ReadBits(r0, &dst->floor, 7);
}

bool8 DoEnemiesEvolveWhenKOed(u8 dungeon)
{
    return gDungeons[dungeon].enemiesEvolveWhenKOed;
}

// Needed to match.
static inline void AddNewLine(const u8 *str, u8 *buffer, u8 *newLine)
{
    FormatString(str, buffer, newLine, 0);
}

// I think this checks if the dungeon HM requirement is met
u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_)
{
    s32 maxPartyMembers, i;

    s32 speciesId = (s16) speciesId_;
    bool32 param_4 = (bool8) (param_4_);
    bool32 param_5 = (bool8) (param_5_);

    s32 numInvSlots = GetNumberOfFilledInventorySlots();
    s32 counter = 0;
    s32 sp_0xf0;
    bool8 sp_0xf4 = FALSE;
    bool8 r8 = FALSE;
    u8 text[200];
    u8 newLine[2];

    newLine[0] = '\n';
    newLine[1] = 0;

    strcpy(buffer,gUnknown_8108F40);
    sp_0xf0 = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonFlag1(mon) && PokemonFlag2(mon)) {
            if (mon->heldItem.id != 0) {
                sp_0xf0++;
            }
            if (++counter == 4) break;
        }
    }

    maxPartyMembers = gDungeons[dungeonIndex].maxPartyMembers;
    if (!param_4 && maxPartyMembers > 3) {
        maxPartyMembers = 3;
    }
    if (counter > maxPartyMembers) {
        if (maxPartyMembers == 1) {
            AddNewLine(gText_OnlyOneMonMayEnterDungeon,text,newLine);
        }
        else {
            gFormatArgs[0] = counter - maxPartyMembers;
            AddNewLine(gText_TooManyMembersToEnterDungeon,text,newLine);
        }
        sub_8090888(buffer,text);
        r8 = TRUE;
    }

    if (gDungeons[dungeonIndex].maxItemsAllowed != 0 && gDungeons[dungeonIndex].maxItemsAllowed < numInvSlots) {
        gFormatArgs[0] = gDungeons[dungeonIndex].maxItemsAllowed;
        gFormatArgs[1] = numInvSlots - gDungeons[dungeonIndex].maxItemsAllowed;
        AddNewLine((!r8) ? gText_OnlyXItemsMayBeBroughtIntoDungeon : gText_AlsoOnlyXItemsMayBeBroughtIntoDungeon, text, newLine);
        sub_8090888(buffer,text);
        r8 = TRUE;
    }

    if (speciesId != MONSTER_NONE) {
        s32 i, bodySize;

        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[0],speciesId);
        if (counter > 3) {
            AddNewLine((!r8) ? gText_ClientCouldNotJoinTooManyMembers : gText_AlsoClientCouldNotJoinTooManyMembers, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
        bodySize = GetBodySize(speciesId);
        for (i = 0; i < NUM_MONSTERS; i++) {
            struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[i];

            if (PokemonFlag1(mon) && PokemonFlag2(mon)){
                bodySize += GetBodySize(mon->speciesNum);
            }
        }
        if (bodySize > 6) {
            AddNewLine((!r8) ? gText_ClientCouldNotJoinNoSpace : gText_AlsoClientCouldNotJoinNoSpace, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
    }
    if (param_4) {
        s32 i;
        //u16 local_4c[4] = {0x99, 0x9C, 0x9b, 0xdb};
        //u8 local_44[4] = {0xe1, 0xe7, 0xe6, 0xe2};
        u16 local_4c[4];
        u8 local_44[4];
        memcpy(local_4c,gUnknown_8108F42,8);
        memcpy(local_44,gUnknown_8108F4A,4);

        for (i = 0; i < 4; i++) {
            if ((((gDungeons[dungeonIndex].HMMask >> (i) & 1) != 0) && !sub_8090820(local_4c[i])) && GetItemPossessionCount(local_44[i]) == 0) {
                break;
            }
        }

        if (i < 4) {
            struct Move move;

            InitPokemonMove(&move,local_4c[i]);
            BufferMoveName(gFormatBuffer_Items[0],&move,0);
            AddNewLine((!r8) ? gText_MustHaveMonWithMove : gText_AlsoMustHaveMonWithMove, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
    }

    if (gDungeons[dungeonIndex].HMMask & 0x10) {
        s32 otherSpeciesId = NUM_MONSTERS;

        if (speciesId != MONSTER_NONE && (GetPokemonType(speciesId,0) == TYPE_WATER || (GetPokemonType(speciesId,1) == TYPE_WATER))) {
            otherSpeciesId = 0;
        }

        if (otherSpeciesId == NUM_MONSTERS) {
            for (otherSpeciesId = 0; otherSpeciesId < NUM_MONSTERS; otherSpeciesId++) {
                struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[otherSpeciesId];

                if (PokemonFlag1(mon) && PokemonFlag2(mon)
                    && (GetPokemonType(mon->speciesNum,0) == TYPE_WATER || GetPokemonType(mon->speciesNum,1) == TYPE_WATER))
                {
                    break;
                }
            }
            if (otherSpeciesId == NUM_MONSTERS) {
                AddNewLine((!r8) ? gText_MustHaveWaterTypeMon : gText_AlsoMustHaveWaterTypeMon, text,newLine);
                sub_8090888(buffer,text);
                r8 = TRUE;
            }
        }
    }

    if (r8) {
        return 1;
    }

    if ((!gDungeons[dungeonIndex].enterWithoutGameSave) || (param_5)) {
        if (!sp_0xf4) {
            strcpy(buffer,gText_IsOkToEnterWithFollowingRules);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,gText_GameWilllBeSavedBeforeEntering);
        strcat(buffer,newLine);
    }
    if (gDungeons[dungeonIndex].levelResetTo1) {
        if (!sp_0xf4) {
            strcpy(buffer,gText_IsOkToEnterWithFollowingRules);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,gText_TeamWillEnterAtLv1);
        strcat(buffer,newLine);
    }
    if ((gDungeons[dungeonIndex].maxItemsAllowed == 0) && (numInvSlots + sp_0xf0 != 0)) {
        if (!sp_0xf4) {
            strcpy(buffer,gText_IsOkToEnterWithFollowingRules);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,gText_AllItemsLostOnEntering);
        strcat(buffer,newLine);
    }
    if ((!gDungeons[dungeonIndex].keepMoney) && (gTeamInventoryRef->teamMoney != 0)) {
        if (!sp_0xf4) {
            strcpy(buffer,gText_IsOkToEnterWithFollowingRules);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer, gText_AllMoneyLostOnEntering);
        strcat(buffer,newLine);
    }

    if (sp_0xf4) {
        return 2;
    }
    else {
        sprintfStatic(buffer,gUnknown_8108F50);
        return 0;
    }
}

static bool8 sub_8090820(u16 moveID)
{
    s32 speciesId, moveIndex;

    for (speciesId = 0; speciesId < NUM_MONSTERS; speciesId++) {
        PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[speciesId];
        if (PokemonFlag1(pokeStruct) && PokemonFlag2(pokeStruct)) {
            for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
                Move *move = &pokeStruct->moves[moveIndex];
                if (MoveFlagExists(move) && move->id == moveID) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

static void sub_8090888(u8 *param_1, u8 *param_2)
{
    s32 iVar3 = 0;

    while (*param_1 != '\0') {
        switch (*param_1) {
            case '\n':
                iVar3++;
                break;
        }
        param_1++;
    }

    while (iVar3 % 3) {
        *param_1++ = '\n';
        iVar3++;
    }

    while (*param_2 != '\0') {
        *param_1++ = *param_2;
        param_2++;
    }

    *param_1 = '\0';
}

u32 GetDungeonLocMissionDifficulty(DungeonLocation *dungeon)
{
    if (dungeon->id < DUNGEON_OUT_ON_RESCUE && dungeon->floor < sDungeonFloorCount[dungeon->id]) {
        return sDungeonMissionDifficulty[dungeon->id][dungeon->floor];
    }
    else {
        return 1;
    }
}

u8 sub_8090910(DungeonLocation *dungeon, u32 param_2)
{
    s32 rand1 = RandInt(9999);
    s32 rand2 = RandInt(9999);
    if (dungeon->id < DUNGEON_OUT_ON_RESCUE && dungeon->floor < sDungeonFloorCount[dungeon->id]) {
        return sub_8091E94(param_2, rand1, rand2);
    }
    else {
        return 0x46;
    }
}

bool8 IsNotValidDungeon(u8 dungeon)
{
    if (dungeon >= DUNGEON_OUT_ON_RESCUE) {
        return TRUE;
    }
    else {
        s32 i;
        for (i = 0; gInvalidDungeonIDs[i] != DUNGEON_OUT_ON_RESCUE; i++) {
            if (gInvalidDungeonIDs[i] == dungeon)
                return TRUE;
        }
        return FALSE;
    }
}
