#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "code_800D090.h"
#include "data_serializer.h"
#include "dungeon_info.h"
#include "items.h"
#include "moves.h"
#include "pokemon.h"
#include "random.h"
#include "string_format.h"
#include "strings.h"
#include "dungeon_data.h"

static void AppendWithNewLines(u8 *dst, const u8 *src);
static bool8 TeamMonWithMove(u16 moveID);

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
    [DUNGEON_UNOWN_RELIC]             = 12,
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
    [DUNGEON_UNOWN_RELIC]             = 0,
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
    [DUNGEON_UNOWN_RELIC] = sFloorMissionDifficulty_UnknownRelic,
    [DUNGEON_JOYOUS_TOWER] = sFloorMissionDifficulty_JoyousTower,
    [DUNGEON_FAR_OFF_SEA] = sFloorMissionDifficulty_FarOffSea,
    [DUNGEON_MT_FARAWAY] = sFloorMissionDifficulty_MtFaraway,
    [DUNGEON_D61] = sFloorMissionDifficulty_D61,
    [DUNGEON_PURITY_FOREST] = sFloorMissionDifficulty_PurityForest,
    [DUNGEON_OUT_ON_RESCUE] = sFloorMissionDifficulty_OutOnRescue,
};

// These item sets are used for KecleonShop Inventory and maybe item rewards from dungeon missions?

// Note: Use NEXT_CHANCE only and ONLY if the next category/item is exactly right after the previous one. Otherwise use SKIP macro
// 10000 is 100%, 6000 is 60 %, 4000 is 40%, 0 is 0% and so on
#define ODDS(x)(x * 100u + (((u16)(x * 100) != (u16)((x + 0.001) * 100)) ? 1 : 0)) // The ugly second part of the macro is because of an off-by-one needed in some cases...I guess it has to do with float->int conversion

#define FIRST_CATEGORY_CHANCE(categoryId, chance) ITEM_SETS_SKIP_NUMBER + categoryId, chance // Note: If starting from category 0(CATEGORY_THROWN_LINE), this can be omitted and table can start directly from NEXT_CHANCE, but functionally it won't make a difference
#define NEXT_CHANCE(categoryId, chance) chance
#define SKIP_CATEGORY_TO_ITEM(prev, next) NUM_ITEM_CATEGORIES - 1 - prev + next + ITEM_SETS_SKIP_NUMBER
#define SKIP(prev, next) next - prev - 1 + ITEM_SETS_SKIP_NUMBER
#define SKIP_REMAINING_ITEMS(prev) NUMBER_OF_ITEM_IDS - prev - 1 + ITEM_SETS_SKIP_NUMBER

// TODO: Find a way to automate building these tables, as right now modifying them is very error-prone(categories and items need to be in the order they're defined)
static const u16 sRandomItemsSet1[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_THROWN_ARC, ODDS(40.0)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(100.0)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_BERRIES_SEEDS_VITAMINS, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.0)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(40.0)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_CHERI_BERRY),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(60.0)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.0)),
    SKIP_REMAINING_ITEMS  (ITEM_MAX_ELIXIR)
};

static const u16 sRandomItemsSet2[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_THROWN_ARC, ODDS(11.76)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(47.06)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(82.35)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_HELD_ITEMS, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_POWER_BAND),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(66.67)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(100.00)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(20.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(40.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_CHERI_BERRY),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(60.00)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_SILVER_GUMMI)
};

static const u16 sRandomItemsSet3[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_THROWN_ARC, ODDS(8.00)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(32.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(80.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(92.00)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(25.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(75.00)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(100.00)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(25.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.57)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.71)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(21.43)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(32.14)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(35.71)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(39.29)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.86)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.43)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(50.00)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.57)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.71)),
    SKIP                  (ITEM_TM_SHOCK_WAVE, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(67.86)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.14)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(85.71)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(92.86)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet4[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_THROWN_ARC, ODDS(7.69)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(30.77)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(76.92)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(88.46)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(80.00)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.57)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.71)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(21.43)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(32.14)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(35.71)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(39.29)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.86)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.43)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(50.00)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.57)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.71)),
    SKIP                  (ITEM_TM_SHOCK_WAVE, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(67.86)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.14)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(85.71)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(92.86)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet5[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(20.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(60.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(80.00)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(16.67)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(66.67)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(83.33)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.57)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.71)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(21.43)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(32.14)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(35.71)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(39.29)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.86)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.43)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(50.00)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.57)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.71)),
    SKIP                  (ITEM_TM_SHOCK_WAVE, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(67.86)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.14)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(85.71)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(92.86)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet6[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(23.08)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(53.85)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(76.92)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(16.67)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(66.67)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(83.33)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet7[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(25.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(50.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(75.00)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(16.67)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(66.67)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(83.33)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet8[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(25.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(50.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(75.00)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(14.29)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(57.14)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(71.43)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(85.71)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet9[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(25.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(50.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(75.00)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_TMS_HMS, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(11.11)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(22.22)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(44.44)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(55.56)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(66.67)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(77.78)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(88.89)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(33.33)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(66.67)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_TM_THIEF)
};

static const u16 sRandomItemsSet10[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(31.58)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(63.16)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(94.74)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(11.11)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(22.22)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(44.44)),
    SKIP                  (ITEM_PECHA_SCARF, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(55.56)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(66.67)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(77.78)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(88.89)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(25.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(75.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSet11[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(31.58)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(63.16)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(94.74)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(10.00)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(50.00)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(80.00)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(90.00)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(25.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(75.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSet12[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(13.33)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(53.33)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(93.33)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(10.00)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(50.00)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(80.00)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(90.00)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(25.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(75.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSet13[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(13.33)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(53.33)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(93.33)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(10.00)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(50.00)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(80.00)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(90.00)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(25.00)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(75.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSet14[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(13.33)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(53.33)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(93.33)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(10.00)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(50.00)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(80.00)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(90.00)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(20.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_PROTEIN),
    NEXT_CHANCE           (ITEM_PROTEIN, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_CALCIUM, ODDS(60.00)),
    NEXT_CHANCE           (ITEM_IRON, ODDS(80.00)),
    NEXT_CHANCE           (ITEM_ZINC, ODDS(100.00)),
    SKIP                  (ITEM_ZINC, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSet15[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(13.33)),
    SKIP                  (CATEGORY_BERRIES_SEEDS_VITAMINS, CATEGORY_HELD_ITEMS),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(53.33)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(93.33)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_LINK_BOX),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(10.00)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_PERSIM_BAND),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(20.00)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.00)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(50.00)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_DEF_SCARF),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(60.00)),
    SKIP                  (ITEM_DEF_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(80.00)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_DODGE_SCARF),
    NEXT_CHANCE           (ITEM_DODGE_SCARF, ODDS(90.00)),
    SKIP                  (ITEM_DODGE_SCARF, ITEM_WEATHER_BAND),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(20.00)),
    SKIP                  (ITEM_JOY_SEED, ITEM_PROTEIN),
    NEXT_CHANCE           (ITEM_PROTEIN, ODDS(40.00)),
    NEXT_CHANCE           (ITEM_CALCIUM, ODDS(60.00)),
    NEXT_CHANCE           (ITEM_IRON, ODDS(80.00)),
    NEXT_CHANCE           (ITEM_ZINC, ODDS(100.00)),
    SKIP                  (ITEM_ZINC, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    SKIP                  (ITEM_TM_TOXIC, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_GIGA_DRAIN),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_TM_FIRE_BLAST),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    SKIP                  (ITEM_TM_FIRE_BLAST, ITEM_TM_AERIAL_ACE),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(55.56)),
    SKIP                  (ITEM_LINK_BOX, ITEM_WEAVILE_FIG),
    NEXT_CHANCE           (ITEM_WEAVILE_FIG, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_MIME_JR_FIG, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_MIME_JR_FIG)
};

static const u16 sRandomItemsSetKecleonShop1[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_THROWN_ARC, ODDS(12.50)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(62.50)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_FOOD_GUMMIES, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_ORAN_BERRY),
    NEXT_CHANCE           (ITEM_ORAN_BERRY, ODDS(16.67)),
    SKIP                  (ITEM_ORAN_BERRY, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(37.50)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_RAWST_BERRY),
    NEXT_CHANCE           (ITEM_RAWST_BERRY, ODDS(45.83)),
    SKIP                  (ITEM_RAWST_BERRY, ITEM_PECHA_BERRY),
    NEXT_CHANCE           (ITEM_PECHA_BERRY, ODDS(54.17)),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(62.50)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_SLEEP_SEED),
    NEXT_CHANCE           (ITEM_SLEEP_SEED, ODDS(70.83)),
    SKIP                  (ITEM_SLEEP_SEED, ITEM_WARP_SEED),
    NEXT_CHANCE           (ITEM_WARP_SEED, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_BLAST_SEED, ODDS(83.33)),
    SKIP                  (ITEM_BLAST_SEED, ITEM_STUN_SEED),
    NEXT_CHANCE           (ITEM_STUN_SEED, ODDS(91.67)),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_APPLE),
    NEXT_CHANCE           (ITEM_APPLE, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_BIG_APPLE, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_BIG_APPLE)
};

static const u16 sRandomItemsSetKecleonWares1[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_TMS_HMS, ODDS(25.00)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.57)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.71)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(21.43)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(32.14)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(35.71)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(39.29)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.86)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.43)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(50.00)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.57)),
    SKIP                  (ITEM_TM_BRICK_BREAK, ITEM_TM_REFLECT),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.71)),
    SKIP                  (ITEM_TM_SHOCK_WAVE, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(67.86)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.14)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(85.71)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(92.86)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_SWITCHER_ORB),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(7.14)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(21.43)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(28.57)),
    SKIP                  (ITEM_WARP_ORB, ITEM_PETRIFY_ORB),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(35.71)),
    SKIP                  (ITEM_PETRIFY_ORB, ITEM_ESCAPE_ORB),
    NEXT_CHANCE           (ITEM_ESCAPE_ORB, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(78.57)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(85.71)),
    SKIP                  (ITEM_RADAR_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HURL_ORB)
};

static const u16 sRandomItemsSetKecleonShop2[] = {
    NEXT_CHANCE           (CATEGORY_THROWN_LINE, ODDS(10.00)),
    NEXT_CHANCE           (CATEGORY_THROWN_ARC, ODDS(20.00)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(60.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(90.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_HELD_ITEMS, ITEM_IRON_THORN),
    NEXT_CHANCE           (ITEM_IRON_THORN, ODDS(83.33)),
    NEXT_CHANCE           (ITEM_SILVER_SPIKE, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_SPIKE, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(14.29)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_X_RAY_SPECS),
    NEXT_CHANCE           (ITEM_X_RAY_SPECS, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(85.71)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_STAMINA_BAND),
    NEXT_CHANCE           (ITEM_STAMINA_BAND, ODDS(100.00)),
    SKIP                  (ITEM_STAMINA_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(14.29)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(42.86)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_CHERI_BERRY),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(57.14)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_SLEEP_SEED),
    NEXT_CHANCE           (ITEM_SLEEP_SEED, ODDS(71.43)),
    SKIP                  (ITEM_SLEEP_SEED, ITEM_WARP_SEED),
    NEXT_CHANCE           (ITEM_WARP_SEED, ODDS(85.71)),
    SKIP                  (ITEM_WARP_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_HUGE_APPLE),
    NEXT_CHANCE           (ITEM_HUGE_APPLE, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HUGE_APPLE)
};

static const u16 sRandomItemsSetKecleonWares2[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_TMS_HMS, ODDS(25.00)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.57)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.71)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(21.43)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(32.14)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(35.71)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(39.29)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.86)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.43)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(50.00)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.57)),
    NEXT_CHANCE           (ITEM_EVASION_ORB, ODDS(6.25)),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.71)),
    SKIP                  (ITEM_TM_SHOCK_WAVE, ITEM_ROCKY_ORB),
    NEXT_CHANCE           (ITEM_ROCKY_ORB, ODDS(12.50)),
    SKIP                  (ITEM_ROCKY_ORB, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(67.86)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.14)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(85.71)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(92.86)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_SWITCHER_ORB),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(18.75)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(31.25)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(37.50)),
    SKIP                  (ITEM_WARP_ORB, ITEM_PETRIFY_ORB),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(43.75)),
    SKIP                  (ITEM_PETRIFY_ORB, ITEM_ESCAPE_ORB),
    NEXT_CHANCE           (ITEM_ESCAPE_ORB, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(81.25)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(87.50)),
    SKIP                  (ITEM_RADAR_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HURL_ORB)
};

static const u16 sRandomItemsSetKecleonShop3[] = {
    NEXT_CHANCE           (CATEGORY_THROWN_LINE, ODDS(10.00)),
    NEXT_CHANCE           (CATEGORY_THROWN_ARC, ODDS(20.00)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(60.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(90.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_HELD_ITEMS, ITEM_IRON_THORN),
    NEXT_CHANCE           (ITEM_IRON_THORN, ODDS(83.33)),
    NEXT_CHANCE           (ITEM_SILVER_SPIKE, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_SPIKE, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(14.29)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_X_RAY_SPECS),
    NEXT_CHANCE           (ITEM_X_RAY_SPECS, ODDS(28.57)),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(85.71)),
    SKIP                  (ITEM_INSOMNISCOPE, ITEM_STAMINA_BAND),
    NEXT_CHANCE           (ITEM_STAMINA_BAND, ODDS(100.00)),
    SKIP                  (ITEM_STAMINA_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(14.29)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(42.86)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_CHERI_BERRY),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(57.14)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_SLEEP_SEED),
    NEXT_CHANCE           (ITEM_SLEEP_SEED, ODDS(71.43)),
    SKIP                  (ITEM_SLEEP_SEED, ITEM_WARP_SEED),
    NEXT_CHANCE           (ITEM_WARP_SEED, ODDS(85.71)),
    SKIP                  (ITEM_WARP_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_HUGE_APPLE),
    NEXT_CHANCE           (ITEM_HUGE_APPLE, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HUGE_APPLE)
};

static const u16 sRandomItemsSetKecleonWares3[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_TMS_HMS, ODDS(62.50)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.45)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.34)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(13.79)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.69)),
    SKIP                  (ITEM_TM_HIDDEN_POWER, ITEM_TM_TAUNT),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(27.59)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(31.03)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(34.48)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(37.93)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(41.38)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(44.83)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(48.28)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(51.72)),
    NEXT_CHANCE           (ITEM_EVASION_ORB, ODDS(6.25)),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(55.17)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(58.62)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(62.07)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_ROCKY_ORB),
    NEXT_CHANCE           (ITEM_ROCKY_ORB, ODDS(12.50)),
    SKIP                  (ITEM_ROCKY_ORB, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(68.97)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.86)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.76)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(86.21)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.10)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_SWITCHER_ORB),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(18.75)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(31.25)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(37.50)),
    SKIP                  (ITEM_WARP_ORB, ITEM_PETRIFY_ORB),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(43.75)),
    SKIP                  (ITEM_PETRIFY_ORB, ITEM_ESCAPE_ORB),
    NEXT_CHANCE           (ITEM_ESCAPE_ORB, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(81.25)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(87.50)),
    SKIP                  (ITEM_RADAR_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HURL_ORB)
};

static const u16 sRandomItemsSetKecleonShop4[] = {
    NEXT_CHANCE           (CATEGORY_THROWN_LINE, ODDS(10.00)),
    NEXT_CHANCE           (CATEGORY_THROWN_ARC, ODDS(20.00)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(70.00)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(90.00)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_HELD_ITEMS, ITEM_IRON_THORN),
    NEXT_CHANCE           (ITEM_IRON_THORN, ODDS(83.33)),
    NEXT_CHANCE           (ITEM_SILVER_SPIKE, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_SPIKE, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(100.00)),
    SKIP                  (ITEM_GRAVELEROCK, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(11.11)),
    SKIP                  (ITEM_HEAL_RIBBON, ITEM_X_RAY_SPECS),
    NEXT_CHANCE           (ITEM_X_RAY_SPECS, ODDS(22.22)),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(44.44)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(55.56)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(66.67)),
    NEXT_CHANCE           (ITEM_WARP_SCARF, ODDS(77.78)),
    SKIP                  (ITEM_WARP_SCARF, ITEM_SPECIAL_BAND),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(88.89)),
    SKIP                  (ITEM_SPECIAL_BAND, ITEM_PASS_SCARF),
    NEXT_CHANCE           (ITEM_PASS_SCARF, ODDS(94.44)),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_HEAL_SEED),
    NEXT_CHANCE           (ITEM_HEAL_SEED, ODDS(7.41)),
    SKIP                  (ITEM_HEAL_SEED, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(22.22)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_RAWST_BERRY),
    NEXT_CHANCE           (ITEM_RAWST_BERRY, ODDS(37.04)),
    NEXT_CHANCE           (ITEM_HUNGER_SEED, ODDS(51.85)),
    SKIP                  (ITEM_HUNGER_SEED, ITEM_CHERI_BERRY),
    NEXT_CHANCE           (ITEM_CHERI_BERRY, ODDS(66.67)),
    SKIP                  (ITEM_CHERI_BERRY, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(70.37)),
    SKIP                  (ITEM_JOY_SEED, ITEM_STUN_SEED),
    NEXT_CHANCE           (ITEM_STUN_SEED, ODDS(85.19)),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_HUGE_APPLE),
    NEXT_CHANCE           (ITEM_HUGE_APPLE, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HUGE_APPLE)
};

static const u16 sRandomItemsSetKecleonWares4[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_TMS_HMS, ODDS(50.00)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.45)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.34)),
    SKIP                  (ITEM_TM_ROAR, ITEM_TM_HAIL),
    NEXT_CHANCE           (ITEM_TM_HAIL, ODDS(4.17)),
    SKIP                  (ITEM_TM_HAIL, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(13.79)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.69)),
    NEXT_CHANCE           (ITEM_TM_SUNNY_DAY, ODDS(8.33)),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(27.59)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(31.03)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(34.48)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_RAINY_ORB),
    NEXT_CHANCE           (ITEM_RAINY_ORB, ODDS(12.50)),
    SKIP                  (ITEM_RAINY_ORB, ITEM_TM_FRUSTRATION),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(37.93)),
    SKIP                  (ITEM_TM_FRUSTRATION, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(41.38)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_RETURN),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(44.83)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(48.28)),
    SKIP                  (ITEM_TM_DIG, ITEM_TM_BRICK_BREAK),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(51.72)),
    NEXT_CHANCE           (ITEM_EVASION_ORB, ODDS(16.67)),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(55.17)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(58.62)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(62.07)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_SANDY_ORB),
    NEXT_CHANCE           (ITEM_SANDY_ORB, ODDS(20.83)),
    SKIP                  (ITEM_SANDY_ORB, ITEM_ROCKY_ORB),
    NEXT_CHANCE           (ITEM_ROCKY_ORB, ODDS(25.00)),
    SKIP                  (ITEM_ROCKY_ORB, ITEM_TM_TORMENT),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(68.97)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(75.86)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(82.76)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(86.21)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.10)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_MUG_ORB),
    NEXT_CHANCE           (ITEM_MUG_ORB, ODDS(29.17)),
    SKIP                  (ITEM_MUG_ORB, ITEM_SWITCHER_ORB),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(41.67)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(45.83)),
    NEXT_CHANCE           (ITEM_TRANSFER_ORB, ODDS(50.00)),
    SKIP                  (ITEM_TRANSFER_ORB, ITEM_PETRIFY_ORB),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(54.17)),
    SKIP                  (ITEM_PETRIFY_ORB, ITEM_DECOY_ORB),
    NEXT_CHANCE           (ITEM_DECOY_ORB, ODDS(62.50)),
    NEXT_CHANCE           (ITEM_SLUMBER_ORB, ODDS(70.83)),
    SKIP                  (ITEM_SLUMBER_ORB, ITEM_SCANNER_ORB),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(75.00)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(79.17)),
    NEXT_CHANCE           (ITEM_DROUGHT_ORB, ODDS(83.33)),
    NEXT_CHANCE           (ITEM_TRAPBUST_ORB, ODDS(87.50)),
    NEXT_CHANCE           (ITEM_ROLLCALL_ORB, ODDS(91.67)),
    SKIP                  (ITEM_ROLLCALL_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HURL_ORB)
};

static const u16 sRandomItemsSet24[] = {
    NEXT_CHANCE           (CATEGORY_THROWN_LINE, ODDS(7.69)),
    NEXT_CHANCE           (CATEGORY_THROWN_ARC, ODDS(15.38)),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(61.54)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(69.23)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(76.92)),
    SKIP                  (CATEGORY_HELD_ITEMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_STICK),
    NEXT_CHANCE           (ITEM_STICK, ODDS(58.14)),
    NEXT_CHANCE           (ITEM_IRON_THORN, ODDS(93.02)),
    NEXT_CHANCE           (ITEM_SILVER_SPIKE, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_SPIKE, ITEM_GRAVELEROCK),
    NEXT_CHANCE           (ITEM_GRAVELEROCK, ODDS(70.00)),
    NEXT_CHANCE           (ITEM_GEO_PEBBLE, ODDS(100.00)),
    SKIP                  (ITEM_GEO_PEBBLE, ITEM_GOLD_RIBBON),
    NEXT_CHANCE           (ITEM_GOLD_RIBBON, ODDS(100.00)),
    SKIP                  (ITEM_GOLD_RIBBON, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(50.00)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_WHITE_GUMMI),
    NEXT_CHANCE           (ITEM_WHITE_GUMMI, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_RED_GUMMI, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_BLUE_GUMMI, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_GRASS_GUMMI, ODDS(23.53)),
    NEXT_CHANCE           (ITEM_YELLOW_GUMMI, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_CLEAR_GUMMI, ODDS(35.29)),
    NEXT_CHANCE           (ITEM_ORANGE_GUMMI, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_PINK_GUMMI, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_BROWN_GUMMI, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SKY_GUMMI, ODDS(58.82)),
    NEXT_CHANCE           (ITEM_GOLD_GUMMI, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_GREEN_GUMMI, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_GRAY_GUMMI, ODDS(76.47)),
    NEXT_CHANCE           (ITEM_PURPLE_GUMMI, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ROYAL_GUMMI, ODDS(88.24)),
    NEXT_CHANCE           (ITEM_BLACK_GUMMI, ODDS(94.12)),
    NEXT_CHANCE           (ITEM_SILVER_GUMMI, ODDS(100.00)),
    SKIP                  (ITEM_SILVER_GUMMI, ITEM_MUG_ORB),
    NEXT_CHANCE           (ITEM_MUG_ORB, ODDS(3.85)),
    SKIP                  (ITEM_MUG_ORB, ITEM_SWITCHER_ORB),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(7.69)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(15.38)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(19.23)),
    NEXT_CHANCE           (ITEM_TRANSFER_ORB, ODDS(23.08)),
    NEXT_CHANCE           (ITEM_SLOW_ORB, ODDS(26.92)),
    SKIP                  (ITEM_SLOW_ORB, ITEM_LUMINOUS_ORB),
    NEXT_CHANCE           (ITEM_LUMINOUS_ORB, ODDS(34.62)),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(38.46)),
    NEXT_CHANCE           (ITEM_STAYAWAY_ORB, ODDS(42.31)),
    NEXT_CHANCE           (ITEM_POUNCE_ORB, ODDS(50.00)),
    SKIP                  (ITEM_POUNCE_ORB, ITEM_DECOY_ORB),
    NEXT_CHANCE           (ITEM_DECOY_ORB, ODDS(57.69)),
    NEXT_CHANCE           (ITEM_SLUMBER_ORB, ODDS(65.38)),
    NEXT_CHANCE           (ITEM_TOTTER_ORB, ODDS(73.08)),
    SKIP                  (ITEM_TOTTER_ORB, ITEM_SILENCE_ORB),
    NEXT_CHANCE           (ITEM_SILENCE_ORB, ODDS(76.92)),
    SKIP                  (ITEM_SILENCE_ORB, ITEM_SCANNER_ORB),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(80.77)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(84.62)),
    SKIP                  (ITEM_RADAR_ORB, ITEM_ONE_SHOT_ORB),
    NEXT_CHANCE           (ITEM_ONE_SHOT_ORB, ODDS(88.46)),
    SKIP                  (ITEM_ONE_SHOT_ORB, ITEM_SHOCKER_ORB),
    NEXT_CHANCE           (ITEM_SHOCKER_ORB, ODDS(92.31)),
    SKIP                  (ITEM_SHOCKER_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_HURL_ORB)
};

static const u16 sRandomItemsSet25[] = {
    NEXT_CHANCE           (CATEGORY_THROWN_LINE, ODDS(31.58)),
    SKIP                  (CATEGORY_THROWN_LINE, CATEGORY_BERRIES_SEEDS_VITAMINS),
    NEXT_CHANCE           (CATEGORY_BERRIES_SEEDS_VITAMINS, ODDS(47.37)),
    NEXT_CHANCE           (CATEGORY_FOOD_GUMMIES, ODDS(57.89)),
    NEXT_CHANCE           (CATEGORY_HELD_ITEMS, ODDS(68.42)),
    NEXT_CHANCE           (CATEGORY_TMS_HMS, ODDS(78.95)),
    SKIP                  (CATEGORY_TMS_HMS, CATEGORY_ORBS),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(89.47)),
    NEXT_CHANCE           (CATEGORY_LINK_BOX, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_LINK_BOX, ITEM_GOLD_FANG),
    NEXT_CHANCE           (ITEM_GOLD_FANG, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_CACNEA_SPIKE, ODDS(66.67)),
    NEXT_CHANCE           (ITEM_CORSOLA_TWIG, ODDS(100.00)),
    SKIP                  (ITEM_CORSOLA_TWIG, ITEM_HEAL_RIBBON),
    NEXT_CHANCE           (ITEM_HEAL_RIBBON, ODDS(4.35)),
    NEXT_CHANCE           (ITEM_TWIST_BAND, ODDS(8.70)),
    SKIP                  (ITEM_TWIST_BAND, ITEM_PATSY_BAND),
    NEXT_CHANCE           (ITEM_PATSY_BAND, ODDS(13.04)),
    NEXT_CHANCE           (ITEM_NOSTICK_CAP, ODDS(17.39)),
    SKIP                  (ITEM_NOSTICK_CAP, ITEM_X_RAY_SPECS),
    NEXT_CHANCE           (ITEM_X_RAY_SPECS, ODDS(21.74)),
    NEXT_CHANCE           (ITEM_PERSIM_BAND, ODDS(26.09)),
    NEXT_CHANCE           (ITEM_POWER_BAND, ODDS(30.43)),
    NEXT_CHANCE           (ITEM_PECHA_SCARF, ODDS(34.78)),
    NEXT_CHANCE           (ITEM_INSOMNISCOPE, ODDS(39.13)),
    NEXT_CHANCE           (ITEM_WARP_SCARF, ODDS(43.48)),
    SKIP                  (ITEM_WARP_SCARF, ITEM_RACKET_BAND),
    NEXT_CHANCE           (ITEM_RACKET_BAND, ODDS(47.83)),
    NEXT_CHANCE           (ITEM_DEF_SCARF, ODDS(52.17)),
    NEXT_CHANCE           (ITEM_STAMINA_BAND, ODDS(56.52)),
    NEXT_CHANCE           (ITEM_PLAIN_RIBBON, ODDS(60.87)),
    NEXT_CHANCE           (ITEM_SPECIAL_BAND, ODDS(65.22)),
    NEXT_CHANCE           (ITEM_ZINC_BAND, ODDS(69.57)),
    SKIP                  (ITEM_ZINC_BAND, ITEM_BOUNCE_BAND),
    NEXT_CHANCE           (ITEM_BOUNCE_BAND, ODDS(73.91)),
    NEXT_CHANCE           (ITEM_CURVE_BAND, ODDS(78.26)),
    NEXT_CHANCE           (ITEM_WHIFF_SPECS, ODDS(82.61)),
    NEXT_CHANCE           (ITEM_NO_AIM_SCOPE, ODDS(86.96)),
    NEXT_CHANCE           (ITEM_LOCKON_SPECS, ODDS(91.30)),
    SKIP                  (ITEM_LOCKON_SPECS, ITEM_PASS_SCARF),
    NEXT_CHANCE           (ITEM_PASS_SCARF, ODDS(95.65)),
    NEXT_CHANCE           (ITEM_WEATHER_BAND, ODDS(100.00)),
    SKIP                  (ITEM_WEATHER_BAND, ITEM_REVIVER_SEED),
    NEXT_CHANCE           (ITEM_REVIVER_SEED, ODDS(33.33)),
    SKIP                  (ITEM_REVIVER_SEED, ITEM_JOY_SEED),
    NEXT_CHANCE           (ITEM_JOY_SEED, ODDS(66.67)),
    SKIP                  (ITEM_JOY_SEED, ITEM_MAX_ELIXIR),
    NEXT_CHANCE           (ITEM_MAX_ELIXIR, ODDS(100.00)),
    SKIP                  (ITEM_MAX_ELIXIR, ITEM_BANANA),
    NEXT_CHANCE           (ITEM_BANANA, ODDS(100.00)),
    SKIP                  (ITEM_BANANA, ITEM_TM_FOCUS_PUNCH),
    NEXT_CHANCE           (ITEM_TM_FOCUS_PUNCH, ODDS(0.79)),
    SKIP                  (ITEM_TM_FOCUS_PUNCH, ITEM_TM_CALM_MIND),
    NEXT_CHANCE           (ITEM_TM_CALM_MIND, ODDS(3.97)),
    NEXT_CHANCE           (ITEM_TM_ROAR, ODDS(10.32)),
    NEXT_CHANCE           (ITEM_TM_TOXIC, ODDS(11.11)),
    NEXT_CHANCE           (ITEM_TM_HAIL, ODDS(1.96)),
    SKIP                  (ITEM_TM_HAIL, ITEM_TM_BULLET_SEED),
    NEXT_CHANCE           (ITEM_TM_BULLET_SEED, ODDS(14.29)),
    NEXT_CHANCE           (ITEM_TM_HIDDEN_POWER, ODDS(20.63)),
    NEXT_CHANCE           (ITEM_TM_SUNNY_DAY, ODDS(3.92)),
    NEXT_CHANCE           (ITEM_TM_TAUNT, ODDS(26.98)),
    NEXT_CHANCE           (ITEM_TM_ICE_BEAM, ODDS(30.16)),
    SKIP                  (ITEM_TM_ICE_BEAM, ITEM_TM_LIGHT_SCREEN),
    NEXT_CHANCE           (ITEM_TM_LIGHT_SCREEN, ODDS(33.33)),
    SKIP                  (ITEM_TM_LIGHT_SCREEN, ITEM_RAINY_ORB),
    NEXT_CHANCE           (ITEM_RAINY_ORB, ODDS(5.88)),
    NEXT_CHANCE           (ITEM_TM_GIGA_DRAIN, ODDS(34.13)),
    NEXT_CHANCE           (ITEM_TM_SAFEGUARD, ODDS(34.92)),
    NEXT_CHANCE           (ITEM_TM_FRUSTRATION, ODDS(38.10)),
    NEXT_CHANCE           (ITEM_TM_SOLARBEAM, ODDS(38.89)),
    SKIP                  (ITEM_TM_SOLARBEAM, ITEM_TM_THUNDERBOLT),
    NEXT_CHANCE           (ITEM_TM_THUNDERBOLT, ODDS(42.06)),
    SKIP                  (ITEM_TM_THUNDERBOLT, ITEM_TM_EARTHQUAKE),
    NEXT_CHANCE           (ITEM_TM_EARTHQUAKE, ODDS(42.86)),
    NEXT_CHANCE           (ITEM_TM_RETURN, ODDS(46.03)),
    NEXT_CHANCE           (ITEM_TM_DIG, ODDS(49.21)),
    NEXT_CHANCE           (ITEM_TM_PSYCHIC, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_TM_SHADOW_BALL, ODDS(50.79)),
    NEXT_CHANCE           (ITEM_TM_BRICK_BREAK, ODDS(53.97)),
    NEXT_CHANCE           (ITEM_EVASION_ORB, ODDS(7.84)),
    NEXT_CHANCE           (ITEM_TM_REFLECT, ODDS(57.14)),
    NEXT_CHANCE           (ITEM_TM_SHOCK_WAVE, ODDS(60.32)),
    NEXT_CHANCE           (ITEM_TM_FLAMETHROWER, ODDS(63.49)),
    SKIP                  (ITEM_TM_FLAMETHROWER, ITEM_SANDY_ORB),
    NEXT_CHANCE           (ITEM_SANDY_ORB, ODDS(9.80)),
    NEXT_CHANCE           (ITEM_TM_FIRE_BLAST, ODDS(64.29)),
    NEXT_CHANCE           (ITEM_ROCKY_ORB, ODDS(11.76)),
    NEXT_CHANCE           (ITEM_TM_AERIAL_ACE, ODDS(65.08)),
    NEXT_CHANCE           (ITEM_TM_TORMENT, ODDS(71.43)),
    NEXT_CHANCE           (ITEM_TM_FACADE, ODDS(77.78)),
    NEXT_CHANCE           (ITEM_TM_SECRET_POWER, ODDS(84.13)),
    NEXT_CHANCE           (ITEM_TM_REST, ODDS(87.30)),
    NEXT_CHANCE           (ITEM_TM_ATTRACT, ODDS(93.65)),
    NEXT_CHANCE           (ITEM_TM_THIEF, ODDS(100.00)),
    SKIP                  (ITEM_TM_THIEF, ITEM_SNATCH_ORB),
    NEXT_CHANCE           (ITEM_SNATCH_ORB, ODDS(13.73)),
    SKIP                  (ITEM_SNATCH_ORB, ITEM_MUG_ORB),
    NEXT_CHANCE           (ITEM_MUG_ORB, ODDS(15.69)),
    NEXT_CHANCE           (ITEM_REBOUND_ORB, ODDS(17.65)),
    NEXT_CHANCE           (ITEM_LOB_ORB, ODDS(19.61)),
    NEXT_CHANCE           (ITEM_SWITCHER_ORB, ODDS(21.57)),
    NEXT_CHANCE           (ITEM_BLOWBACK_ORB, ODDS(25.49)),
    NEXT_CHANCE           (ITEM_WARP_ORB, ODDS(27.45)),
    NEXT_CHANCE           (ITEM_TRANSFER_ORB, ODDS(29.41)),
    NEXT_CHANCE           (ITEM_SLOW_ORB, ODDS(31.37)),
    NEXT_CHANCE           (ITEM_QUICK_ORB, ODDS(33.33)),
    NEXT_CHANCE           (ITEM_LUMINOUS_ORB, ODDS(37.25)),
    NEXT_CHANCE           (ITEM_PETRIFY_ORB, ODDS(39.22)),
    NEXT_CHANCE           (ITEM_STAYAWAY_ORB, ODDS(41.18)),
    NEXT_CHANCE           (ITEM_POUNCE_ORB, ODDS(45.10)),
    NEXT_CHANCE           (ITEM_TRAWL_ORB, ODDS(47.06)),
    NEXT_CHANCE           (ITEM_CLEANSE_ORB, ODDS(49.02)),
    SKIP                  (ITEM_CLEANSE_ORB, ITEM_DECOY_ORB),
    NEXT_CHANCE           (ITEM_DECOY_ORB, ODDS(52.94)),
    NEXT_CHANCE           (ITEM_SLUMBER_ORB, ODDS(56.86)),
    NEXT_CHANCE           (ITEM_TOTTER_ORB, ODDS(60.78)),
    NEXT_CHANCE           (ITEM_TWO_EDGE_ORB, ODDS(62.75)),
    NEXT_CHANCE           (ITEM_SILENCE_ORB, ODDS(64.71)),
    NEXT_CHANCE           (ITEM_ESCAPE_ORB, ODDS(66.67)),
    NEXT_CHANCE           (ITEM_SCANNER_ORB, ODDS(68.63)),
    NEXT_CHANCE           (ITEM_RADAR_ORB, ODDS(70.59)),
    NEXT_CHANCE           (ITEM_DROUGHT_ORB, ODDS(72.55)),
    NEXT_CHANCE           (ITEM_TRAPBUST_ORB, ODDS(74.51)),
    NEXT_CHANCE           (ITEM_ROLLCALL_ORB, ODDS(76.47)),
    SKIP                  (ITEM_ROLLCALL_ORB, ITEM_ONE_SHOT_ORB),
    NEXT_CHANCE           (ITEM_ONE_SHOT_ORB, ODDS(78.43)),
    SKIP                  (ITEM_ONE_SHOT_ORB, ITEM_SHOCKER_ORB),
    NEXT_CHANCE           (ITEM_SHOCKER_ORB, ODDS(80.39)),
    NEXT_CHANCE           (ITEM_SIZEBUST_ORB, ODDS(82.35)),
    NEXT_CHANCE           (ITEM_ONE_ROOM_ORB, ODDS(84.31)),
    NEXT_CHANCE           (ITEM_FILL_IN_ORB, ODDS(86.27)),
    NEXT_CHANCE           (ITEM_TRAPPER_ORB, ODDS(88.24)),
    SKIP                  (ITEM_TRAPPER_ORB, ITEM_HURL_ORB),
    NEXT_CHANCE           (ITEM_HURL_ORB, ODDS(92.16)),
    NEXT_CHANCE           (ITEM_MOBILE_ORB, ODDS(94.12)),
    SKIP                  (ITEM_MOBILE_ORB, ITEM_STAIRS_ORB),
    NEXT_CHANCE           (ITEM_STAIRS_ORB, ODDS(96.08)),
    NEXT_CHANCE           (ITEM_LONGTOSS_ORB, ODDS(98.04)),
    NEXT_CHANCE           (ITEM_PIERCE_ORB, ODDS(100.00)),
    SKIP                  (ITEM_PIERCE_ORB, ITEM_LINK_BOX),
    NEXT_CHANCE           (ITEM_LINK_BOX, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_LINK_BOX)
};

static const u16 sRandomItemsSet26[] = {
    FIRST_CATEGORY_CHANCE (CATEGORY_FOOD_GUMMIES, ODDS(16.67)),
    SKIP                  (CATEGORY_FOOD_GUMMIES, CATEGORY_OTHER),
    NEXT_CHANCE           (CATEGORY_OTHER, ODDS(83.33)),
    NEXT_CHANCE           (CATEGORY_ORBS, ODDS(100.00)),
    SKIP_CATEGORY_TO_ITEM (CATEGORY_ORBS, ITEM_BANANA),
    NEXT_CHANCE           (ITEM_BANANA, ODDS(100.00)),
    SKIP                  (ITEM_BANANA, ITEM_THUNDERSTONE),
    NEXT_CHANCE           (ITEM_THUNDERSTONE, ODDS(25.00)),
    SKIP                  (ITEM_THUNDERSTONE, ITEM_SUN_STONE),
    NEXT_CHANCE           (ITEM_SUN_STONE, ODDS(50.00)),
    NEXT_CHANCE           (ITEM_MOON_STONE, ODDS(75.00)),
    SKIP                  (ITEM_MOON_STONE, ITEM_KEY),
    NEXT_CHANCE           (ITEM_KEY, ODDS(100.00)),
    SKIP                  (ITEM_KEY, ITEM_ONE_ROOM_ORB),
    NEXT_CHANCE           (ITEM_ONE_ROOM_ORB, ODDS(100.00)),
    SKIP_REMAINING_ITEMS  (ITEM_ONE_ROOM_ORB)
};

const u16 *const gRandomItemsSets[] = {
    [RANDOM_ITEMS_SET_1 - 1] = sRandomItemsSet1,
    [RANDOM_ITEMS_SET_2 - 1] = sRandomItemsSet2,
    [RANDOM_ITEMS_SET_3 - 1] = sRandomItemsSet3,
    [RANDOM_ITEMS_SET_4 - 1] = sRandomItemsSet4,
    [RANDOM_ITEMS_SET_5 - 1] = sRandomItemsSet5,
    [RANDOM_ITEMS_SET_6 - 1] = sRandomItemsSet6,
    [RANDOM_ITEMS_SET_7 - 1] = sRandomItemsSet7,
    [RANDOM_ITEMS_SET_8 - 1] = sRandomItemsSet8,
    [RANDOM_ITEMS_SET_9 - 1] = sRandomItemsSet9,
    [RANDOM_ITEMS_SET_10 - 1] = sRandomItemsSet10,
    [RANDOM_ITEMS_SET_11 - 1] = sRandomItemsSet11,
    [RANDOM_ITEMS_SET_12 - 1] = sRandomItemsSet12,
    [RANDOM_ITEMS_SET_13 - 1] = sRandomItemsSet13,
    [RANDOM_ITEMS_SET_14 - 1] = sRandomItemsSet14,
    [RANDOM_ITEMS_SET_15 - 1] = sRandomItemsSet15,
    [RANDOM_ITEMS_SET_KECLEON_SHOP_1 - 1] = sRandomItemsSetKecleonShop1,
    [RANDOM_ITEMS_SET_KECLEON_WARES_1 - 1] = sRandomItemsSetKecleonWares1,
    [RANDOM_ITEMS_SET_KECLEON_SHOP_2 - 1] = sRandomItemsSetKecleonShop2,
    [RANDOM_ITEMS_SET_KECLEON_WARES_2 - 1] = sRandomItemsSetKecleonWares2,
    [RANDOM_ITEMS_SET_KECLEON_SHOP_3 - 1] = sRandomItemsSetKecleonShop3,
    [RANDOM_ITEMS_SET_KECLEON_WARES_3 - 1] = sRandomItemsSetKecleonWares3,
    [RANDOM_ITEMS_SET_KECLEON_SHOP_4 - 1] = sRandomItemsSetKecleonShop4,
    [RANDOM_ITEMS_SET_KECLEON_WARES_4 - 1] = sRandomItemsSetKecleonWares4,
    [RANDOM_ITEMS_SET_24 - 1] = sRandomItemsSet24,
    [RANDOM_ITEMS_SET_25 - 1] = sRandomItemsSet25,
    [RANDOM_ITEMS_SET_26 - 1] = sRandomItemsSet26,
};

// Values are used for file reading(probably related to dungeon gfx), indexed by gDungeon->tileset
const u8 gUnknown_8108EC0[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 16, 23, 24, 25, 20, 23, 28,
    29, 30, 31, 32, 33, 28, 35, 36, 37, 30, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
    55, 56, 45, 45, 59, 60, 48, 62, 63, 64, 65, 66, 67,
    68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
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
    sprintfStatic(buffer, _("{color YELLOW_D}%s{reset}"), gDungeonNames[dungeonLocation->id].name1);
}

void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    if (gDungeons[dungeonLocation->id].stairDirectionUp){
        sprintfStatic(buffer, _("{color YELLOW_D}%s{reset}　{color CYAN}%d{reset}F"), gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); //_F
    }
    else {
        sprintfStatic(buffer, _("{color YELLOW_D}%s{reset}　B{color CYAN}%d{reset}F"), gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); // B _F
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
u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 requireHm_, bool32 param_5_)
{
    s32 maxPartyMembers, i;

    s32 speciesId = (s16) speciesId_;
    bool32 requireHm = (bool8) (requireHm_);
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

    InlineStrcpy(buffer,""); // Empty string
    sp_0xf0 = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        struct Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(mon) && PokemonFlag2(mon)) {
            if (mon->heldItem.id != 0) {
                sp_0xf0++;
            }
            if (++counter == 4) break;
        }
    }

    maxPartyMembers = gDungeons[dungeonIndex].maxPartyMembers;
    if (!requireHm && maxPartyMembers > 3) {
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
        AppendWithNewLines(buffer,text);
        r8 = TRUE;
    }

    if (gDungeons[dungeonIndex].maxItemsAllowed != 0 && gDungeons[dungeonIndex].maxItemsAllowed < numInvSlots) {
        gFormatArgs[0] = gDungeons[dungeonIndex].maxItemsAllowed;
        gFormatArgs[1] = numInvSlots - gDungeons[dungeonIndex].maxItemsAllowed;
        AddNewLine((!r8) ? gText_OnlyXItemsMayBeBroughtIntoDungeon : gText_AlsoOnlyXItemsMayBeBroughtIntoDungeon, text, newLine);
        AppendWithNewLines(buffer,text);
        r8 = TRUE;
    }

    if (speciesId != MONSTER_NONE) {
        s32 i, bodySize;

        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[0],speciesId);
        if (counter > 3) {
            AddNewLine((!r8) ? gText_ClientCouldNotJoinTooManyMembers : gText_AlsoClientCouldNotJoinTooManyMembers, text,newLine);
            AppendWithNewLines(buffer,text);
            r8 = TRUE;
        }
        bodySize = GetBodySize(speciesId);
        for (i = 0; i < NUM_MONSTERS; i++) {
            struct Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];

            if (PokemonExists(mon) && PokemonFlag2(mon)){
                bodySize += GetBodySize(mon->speciesNum);
            }
        }
        if (bodySize > 6) {
            AddNewLine((!r8) ? gText_ClientCouldNotJoinNoSpace : gText_AlsoClientCouldNotJoinNoSpace, text,newLine);
            AppendWithNewLines(buffer,text);
            r8 = TRUE;
        }
    }

    if (requireHm) {
        s32 i;
        u16 movesNeeded[4] = {MOVE_FLY, MOVE_DIVE, MOVE_WATERFALL, MOVE_SURF};
        u8 hmsNeeded[4] = {ITEM_HM_FLY, ITEM_HM_DIVE, ITEM_HM_WATERFALL, ITEM_HM_SURF};

        for (i = 0; i < 4; i++) {
            if ((((gDungeons[dungeonIndex].HMMask >> (i) & 1) != 0) && !TeamMonWithMove(movesNeeded[i])) && GetItemPossessionCount(hmsNeeded[i]) == 0) {
                break;
            }
        }

        if (i < 4) {
            struct Move move;

            InitPokemonMove(&move,movesNeeded[i]);
            BufferMoveName(gFormatBuffer_Items[0],&move,0);
            AddNewLine((!r8) ? gText_MustHaveMonWithMove : gText_AlsoMustHaveMonWithMove, text,newLine);
            AppendWithNewLines(buffer,text);
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
                struct Pokemon *mon = &gRecruitedPokemonRef->pokemon[otherSpeciesId];

                if (PokemonExists(mon) && PokemonFlag2(mon)
                    && (GetPokemonType(mon->speciesNum,0) == TYPE_WATER || GetPokemonType(mon->speciesNum,1) == TYPE_WATER))
                {
                    break;
                }
            }
            if (otherSpeciesId == NUM_MONSTERS) {
                AddNewLine((!r8) ? gText_MustHaveWaterTypeMon : gText_AlsoMustHaveWaterTypeMon, text,newLine);
                AppendWithNewLines(buffer,text);
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
        sprintfStatic(buffer,_("No problem."));
        return 0;
    }
}

static bool8 TeamMonWithMove(u16 moveID)
{
    s32 speciesId, moveIndex;

    for (speciesId = 0; speciesId < NUM_MONSTERS; speciesId++) {
        Pokemon *pokeStruct = &gRecruitedPokemonRef->pokemon[speciesId];
        if (PokemonExists(pokeStruct) && PokemonFlag2(pokeStruct)) {
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

static void AppendWithNewLines(u8 *dst, const u8 *src)
{
    s32 newLinesCount = 0;

    while (*dst != '\0') {
        switch (*dst) {
            case '\n':
                newLinesCount++;
                break;
        }
        dst++;
    }

    while (newLinesCount % 3) {
        *dst++ = '\n';
        newLinesCount++;
    }

    while (*src != '\0') {
        *dst++ = *src;
        src++;
    }

    *dst = '\0';
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

u8 GetRandomItemForValidDungeonLoc(DungeonLocation *dungeon, u32 setId)
{
    s32 rand1 = RandInt(ITEM_SETS_RANDOM_CAP);
    s32 rand2 = RandInt(ITEM_SETS_RANDOM_CAP);
    if (dungeon->id < DUNGEON_OUT_ON_RESCUE && dungeon->floor < sDungeonFloorCount[dungeon->id]) {
        return GetRandomItemForSet(setId, rand1, rand2);
    }
    else {
        return ITEM_PLAIN_SEED;
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
