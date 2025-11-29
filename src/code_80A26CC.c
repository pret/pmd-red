#include "global.h"
#include "globaldata.h"
#include "rescue_scenario.h"
#include "code_80A26CC.h"
#include "event_flag.h"
#include "constants/dungeon.h"
#include "constants/rescue_dungeon_id.h"

static const DungeonInfo sScriptDungeonData[SCRIPT_DUNGEON_COUNT] = {
    [SCRIPT_DUNGEON_TINY_WOODS] = {
        .mapID1 = MAP_TINY_WOODS_ENTRY,
        .mapID2 = MAP_TINY_WOODS_ENTRY,
        .mapID3 = MAP_TINY_WOODS_ENTRY,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E01A,
        .dungeonID = DUNGEON_TINY_WOODS,
        .rescueDungeonID = RESCUE_DUNGEON_TINY_WOODS,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_THUNDERWAVE_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E02A_L003,
        .scriptID2 = EVENT_M01E02A_L005,
        .scriptID3 = GETOUT_M01E02A,
        .dungeonID = DUNGEON_THUNDERWAVE_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_THUNDERWAVE_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_STEEL] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E02B_L005,
        .scriptID2 = EVENT_M01E02B_L007,
        .scriptID3 = GETOUT_M01E02B,
        .dungeonID = DUNGEON_MT_STEEL,
        .rescueDungeonID = RESCUE_DUNGEON_MT_STEEL,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_3] = {
        .mapID1 = -1,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E02B,
        .dungeonID = DUNGEON_MT_STEEL,
        .rescueDungeonID = RESCUE_DUNGEON_MT_STEEL,
        .unk10 = 1,
        .unk11 = FALSE,
    },
    [SCRIPT_DUNGEON_SINISTER_WOODS] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E03A_L008,
        .scriptID2 = EVENT_M01E03A_L010,
        .scriptID3 = GETOUT_M01E03A,
        .dungeonID = DUNGEON_SINISTER_WOODS,
        .rescueDungeonID = RESCUE_DUNGEON_SINISTER_WOODS,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_5] = {
        .mapID1 = -1,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E03A,
        .dungeonID = DUNGEON_SINISTER_WOODS,
        .rescueDungeonID = RESCUE_DUNGEON_SINISTER_WOODS,
        .unk10 = 1,
        .unk11 = FALSE,
    },
    [SCRIPT_DUNGEON_SILENT_CHASM] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E04A_L003,
        .scriptID2 = EVENT_M01E04A_L005,
        .scriptID3 = GETOUT_M01E04A,
        .dungeonID = DUNGEON_SILENT_CHASM,
        .rescueDungeonID = RESCUE_DUNGEON_SILENT_CHASM,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_THUNDER] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_MT_THUNDER_MID,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E04B_L003,
        .scriptID2 = EVENT_M01E04B_L005,
        .scriptID3 = GETOUT_M01E04B,
        .dungeonID = DUNGEON_MT_THUNDER,
        .rescueDungeonID = RESCUE_DUNGEON_MT_THUNDER,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_THUNDER_PEAK] = {
        .mapID1 = -1,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_MT_THUNDER_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E04B,
        .dungeonID = DUNGEON_MT_THUNDER_PEAK,
        .rescueDungeonID = RESCUE_DUNGEON_MT_THUNDER,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GREAT_CANYON] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E05A_L003,
        .scriptID2 = EVENT_M01E05A_L005,
        .scriptID3 = GETOUT_M01E05A,
        .dungeonID = DUNGEON_GREAT_CANYON,
        .rescueDungeonID = RESCUE_DUNGEON_GREAT_CANYON,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_LAPIS_CAVE] = {
        .mapID1 = MAP_LAPIS_CAVE_ENTRY,
        .mapID2 = MAP_LAPIS_CAVE_END,
        .mapID3 = MAP_LAPIS_CAVE_ENTRY,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E07A,
        .dungeonID = DUNGEON_LAPIS_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_LAPIS_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_BLAZE] = {
        .mapID1 = MAP_MT_BLAZE_ENTRY,
        .mapID2 = MAP_MT_BLAZE_MID,
        .mapID3 = MAP_MT_BLAZE_ENTRY,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E07B,
        .dungeonID = DUNGEON_MT_BLAZE,
        .rescueDungeonID = RESCUE_DUNGEON_MT_BLAZE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_BLAZE_PEAK] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_MT_BLAZE_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E07B,
        .dungeonID = DUNGEON_MT_BLAZE_PEAK,
        .rescueDungeonID = RESCUE_DUNGEON_MT_BLAZE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FROSTY_FOREST] = {
        .mapID1 = MAP_FROSTY_FOREST_ENTRY,
        .mapID2 = MAP_FROSTY_FOREST_MID,
        .mapID3 = MAP_FROSTY_FOREST_ENTRY,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E08A,
        .dungeonID = DUNGEON_FROSTY_FOREST,
        .rescueDungeonID = RESCUE_DUNGEON_FROSTY_FOREST,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FROSTY_GROTTO] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_FROSTY_FOREST_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E08A,
        .dungeonID = DUNGEON_FROSTY_GROTTO,
        .rescueDungeonID = RESCUE_DUNGEON_FROSTY_FOREST,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_FREEZE] = {
        .mapID1 = MAP_MT_FREEZE_ENTRY,
        .mapID2 = MAP_MT_FREEZE_MID,
        .mapID3 = MAP_MT_FREEZE_ENTRY,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E08B,
        .dungeonID = DUNGEON_MT_FREEZE,
        .rescueDungeonID = RESCUE_DUNGEON_MT_FREEZE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_PEAK] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_MT_FREEZE_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E08B,
        .dungeonID = DUNGEON_MT_FREEZE_PEAK,
        .rescueDungeonID = RESCUE_DUNGEON_MT_FREEZE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MAGMA_CAVERN] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_MAGMA_CAVERN_MID,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E09A_L011,
        .scriptID2 = EVENT_M01E09A_L013,
        .scriptID3 = GETOUT_M01E09A,
        .dungeonID = DUNGEON_MAGMA_CAVERN,
        .rescueDungeonID = RESCUE_DUNGEON_MAGMA_CAVERN,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MAGMA_CAVERN_PIT] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_MAGMA_CAVERN_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E09A,
        .dungeonID = DUNGEON_MAGMA_CAVERN_PIT,
        .rescueDungeonID = RESCUE_DUNGEON_MAGMA_CAVERN,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SKY_TOWER] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_SKY_TOWER_MID,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_M01E10A_L004,
        .scriptID2 = EVENT_M01E10A_L006,
        .scriptID3 = GETOUT_M01E10A,
        .dungeonID = DUNGEON_SKY_TOWER,
        .rescueDungeonID = RESCUE_DUNGEON_SKY_TOWER,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SKY_TOWER_SUMMIT] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_SKY_TOWER_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E10A,
        .dungeonID = DUNGEON_SKY_TOWER_SUMMIT,
        .rescueDungeonID = RESCUE_DUNGEON_SKY_TOWER,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_DUMMY] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S00E01A,
        .dungeonID = DUNGEON_TINY_WOODS,
        .rescueDungeonID = RESCUE_DUNGEON_DUMMY,
        .unk10 = 1,
        .unk11 = FALSE,
    },
    [SCRIPT_DUNGEON_UPROAR_FOREST] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S01E01A,
        .dungeonID = DUNGEON_UPROAR_FOREST,
        .rescueDungeonID = RESCUE_DUNGEON_UPROAR_FOREST,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_HOWLING_FOREST] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S01E02A,
        .dungeonID = DUNGEON_HOWLING_FOREST,
        .rescueDungeonID = RESCUE_DUNGEON_HOWLING_FOREST,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_STORMY_SEA] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S02E01A,
        .dungeonID = DUNGEON_STORMY_SEA,
        .rescueDungeonID = RESCUE_DUNGEON_STORMY_SEA,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SILVER_TRENCH] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S02E02A,
        .dungeonID = DUNGEON_SILVER_TRENCH,
        .rescueDungeonID = RESCUE_DUNGEON_SILVER_TRENCH,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_METEOR_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S03E01A,
        .dungeonID = DUNGEON_METEOR_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_METEOR_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GREAT_CANYON_2] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S04E01A,
        .dungeonID = DUNGEON_GREAT_CANYON,
        .rescueDungeonID = RESCUE_DUNGEON_GREAT_CANYON_2,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FIERY_FIELD] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S04E01B,
        .dungeonID = DUNGEON_FIERY_FIELD,
        .rescueDungeonID = RESCUE_DUNGEON_FIERY_FIELD,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_LIGHTNING_FIELD] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S04E01C,
        .dungeonID = DUNGEON_LIGHTNING_FIELD,
        .rescueDungeonID = RESCUE_DUNGEON_LIGHTNING_FIELD,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_NORTHWIND_FIELD] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S04E01D,
        .dungeonID = DUNGEON_NORTHWIND_FIELD,
        .rescueDungeonID = RESCUE_DUNGEON_NORTHWIND_FIELD,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_FARAWAY] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S04E01E,
        .dungeonID = DUNGEON_MT_FARAWAY,
        .rescueDungeonID = RESCUE_DUNGEON_MT_FARAWAY,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_WESTERN_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S05E01A,
        .dungeonID = DUNGEON_WESTERN_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_WESTERN_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_NORTHERN_RANGE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S06E01A,
        .dungeonID = DUNGEON_NORTHERN_RANGE,
        .rescueDungeonID = RESCUE_DUNGEON_NORTHERN_RANGE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_PITFALL_VALLEY] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S06E01B,
        .dungeonID = DUNGEON_PITFALL_VALLEY,
        .rescueDungeonID = RESCUE_DUNGEON_PITFALL_VALLEY,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_BURIED_RELIC] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S07E01A,
        .dungeonID = DUNGEON_BURIED_RELIC,
        .rescueDungeonID = RESCUE_DUNGEON_BURIED_RELIC,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_WISH_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S08E01A,
        .dungeonID = DUNGEON_WISH_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_WISH_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_2] = {
        .mapID1 = MAP_MT_FREEZE_ENTRY,
        .mapID2 = MAP_MT_FREEZE_MID,
        .mapID3 = MAP_MT_FREEZE_ENTRY,
        .scriptID1 = EVENT_S09E01A_L004B,
        .scriptID2 = EVENT_S09E01A_L004B,
        .scriptID3 = GETOUT_S09E01A,
        .dungeonID = DUNGEON_MT_FREEZE,
        .rescueDungeonID = RESCUE_DUNGEON_MT_FREEZE_2,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_PEAK_2] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = MAP_MT_FREEZE_MID,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_S09E01A,
        .dungeonID = DUNGEON_MT_FREEZE_PEAK_2,
        .rescueDungeonID = RESCUE_DUNGEON_MT_FREEZE_2,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MURKY_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = EVENT_S09E01B_L001B,
        .scriptID2 = EVENT_S09E01B_L001B,
        .scriptID3 = GETOUT_S09E01B,
        .dungeonID = DUNGEON_MURKY_CAVE,
        .rescueDungeonID = RESCUE_DUNGEON_MURKY_CAVE,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_DESERT_REGION] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_DESERT_REGION,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SOUTHERN_CAVERN] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_SOUTHERN_CAVERN,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_WYVERN_HILL] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_WYVERN_HILL,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SOLAR_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_SOLAR_CAVE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_DARKNIGHT_RELIC] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_DARKNIGHT_RELIC,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GRAND_SEA] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_GRAND_SEA,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_WATERFALL_POND] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_WATERFALL_POND,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_UNOWN_RELIC] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_UNOWN_RELIC,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_JOYOUS_TOWER] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_JOYOUS_TOWER,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FAR_OFF_SEA] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_FAR_OFF_SEA,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_PURITY_FOREST] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_D62E01A,
        .dungeonID = DUNGEON_PURITY_FOREST,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_ODDITY_CAVE] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_D43E01A,
        .dungeonID = DUNGEON_ODDITY_CAVE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_REMAINS_ISLAND] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_D44E01A,
        .dungeonID = DUNGEON_REMAINS_ISLAND,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_MARVELOUS_SEA] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_D45E01A,
        .dungeonID = DUNGEON_MARVELOUS_SEA,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FANTASY_STRAIT] = {
        .mapID1 = MAP_TEAM_BASE,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_D46E01A,
        .dungeonID = DUNGEON_FANTASY_STRAIT,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_NORMAL_MAZE_2] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_NORMAL_MAZE_2,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FIRE_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_FIRE_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_WATER_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_WATER_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GRASS_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_GRASS_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_ELECTRIC_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_ELECTRIC_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_ICE_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_ICE_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FIGHTING_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_FIGHTING_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GROUND_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_GROUND_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_FLYING_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_FLYING_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_PSYCHIC_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_PSYCHIC_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_POISON_MAZE_2] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_POISON_MAZE_2,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_BUG_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_BUG_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_ROCK_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_ROCK_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_GHOST_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_GHOST_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_DRAGON_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_DRAGON_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_DARK_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_DARK_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_STEEL_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_STEEL_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_TEAM_SHIFTY] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_TEAM_SHIFTY,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_TEAM_CONSTRICTOR] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_TEAM_CONSTRICTOR,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_TEAM_HYDRO] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_TEAM_HYDRO,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_TEAM_RUMBLEROCK] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_TEAM_RUMBLEROCK,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_RESCUE_TEAM_2] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_RESCUE_TEAM_2,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_RESCUE_TEAM_MAZE] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_RESCUE_TEAM_MAZE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_ROCK_PATH] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E07T,
        .dungeonID = DUNGEON_ROCK_PATH,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_SNOW_PATH] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_M01E08T,
        .dungeonID = DUNGEON_SNOW_PATH,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = TRUE,
    },
    [SCRIPT_DUNGEON_80] = {
        .mapID1 = -1,
        .mapID2 = MAP_PELIPPER_POST_OFFICE_INSIDE,
        .mapID3 = MAP_PELIPPER_POST_OFFICE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_U00E01A,
        .dungeonID = DUNGEON_OUT_ON_RESCUE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = FALSE,
    },
    [SCRIPT_DUNGEON_81] = {
        .mapID1 = -1,
        .mapID2 = MAP_TEAM_BASE_INSIDE,
        .mapID3 = MAP_TEAM_BASE_INSIDE,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_R00E01A,
        .dungeonID = DUNGEON_OUT_ON_RESCUE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = FALSE,
    },
    [SCRIPT_DUNGEON_82] = {
        .mapID1 = -1,
        .mapID2 = -1,
        .mapID3 = -1,
        .scriptID1 = -1,
        .scriptID2 = -1,
        .scriptID3 = GETOUT_T00E01A,
        .dungeonID = DUNGEON_OUT_ON_RESCUE,
        .rescueDungeonID = -1,
        .unk10 = 1,
        .unk11 = FALSE,
    },
};

static const s16 gUnknown_8116F24[] = {
    -1, -1, 0, 1, 2, 3, 4, 5, 6, -1, -1, 7,
    8, 9, 10, 11, 12, -1, -1, -1, -1, 13, 14,
    -1, 15, -1, 16, 17, -1, 18, -1, 19, 20,
    21, 22, 23, -1, 24, -1, 25, 26, -1, 27, -1,
    28, -1, 29, 30, -1, -1, -1, 0, 0, 0, 0,
    0, 0, 0, 0
};

static const s16 sRescueToScriptDungeonIdTable[RESCUE_DUNGEON_COUNT] = {
    [RESCUE_DUNGEON_TINY_WOODS]         = SCRIPT_DUNGEON_TINY_WOODS,
    [RESCUE_DUNGEON_THUNDERWAVE_CAVE]   = SCRIPT_DUNGEON_THUNDERWAVE_CAVE,
    [RESCUE_DUNGEON_MT_STEEL]           = SCRIPT_DUNGEON_MT_STEEL,
    [RESCUE_DUNGEON_SINISTER_WOODS]     = SCRIPT_DUNGEON_SINISTER_WOODS,
    [RESCUE_DUNGEON_SILENT_CHASM]       = SCRIPT_DUNGEON_SILENT_CHASM,
    [RESCUE_DUNGEON_MT_THUNDER]         = SCRIPT_DUNGEON_MT_THUNDER,
    [RESCUE_DUNGEON_GREAT_CANYON]       = SCRIPT_DUNGEON_GREAT_CANYON,
    [RESCUE_DUNGEON_LAPIS_CAVE]         = SCRIPT_DUNGEON_LAPIS_CAVE,
    [RESCUE_DUNGEON_MT_BLAZE]           = SCRIPT_DUNGEON_MT_BLAZE,
    [RESCUE_DUNGEON_FROSTY_FOREST]      = SCRIPT_DUNGEON_FROSTY_FOREST,
    [RESCUE_DUNGEON_MT_FREEZE]          = SCRIPT_DUNGEON_MT_FREEZE,
    [RESCUE_DUNGEON_MAGMA_CAVERN]       = SCRIPT_DUNGEON_MAGMA_CAVERN,
    [RESCUE_DUNGEON_SKY_TOWER]          = SCRIPT_DUNGEON_SKY_TOWER,
    [RESCUE_DUNGEON_DUMMY]              = SCRIPT_DUNGEON_DUMMY,
    [RESCUE_DUNGEON_UPROAR_FOREST]      = SCRIPT_DUNGEON_UPROAR_FOREST,
    [RESCUE_DUNGEON_HOWLING_FOREST]     = SCRIPT_DUNGEON_HOWLING_FOREST,
    [RESCUE_DUNGEON_STORMY_SEA]         = SCRIPT_DUNGEON_STORMY_SEA,
    [RESCUE_DUNGEON_SILVER_TRENCH]      = SCRIPT_DUNGEON_SILVER_TRENCH,
    [RESCUE_DUNGEON_METEOR_CAVE]        = SCRIPT_DUNGEON_METEOR_CAVE,
    [RESCUE_DUNGEON_GREAT_CANYON_2]     = SCRIPT_DUNGEON_GREAT_CANYON_2,
    [RESCUE_DUNGEON_FIERY_FIELD]        = SCRIPT_DUNGEON_FIERY_FIELD,
    [RESCUE_DUNGEON_LIGHTNING_FIELD]    = SCRIPT_DUNGEON_LIGHTNING_FIELD,
    [RESCUE_DUNGEON_NORTHWIND_FIELD]    = SCRIPT_DUNGEON_NORTHWIND_FIELD,
    [RESCUE_DUNGEON_MT_FARAWAY]         = SCRIPT_DUNGEON_MT_FARAWAY,
    [RESCUE_DUNGEON_WESTERN_CAVE]       = SCRIPT_DUNGEON_WESTERN_CAVE,
    [RESCUE_DUNGEON_NORTHERN_RANGE]     = SCRIPT_DUNGEON_NORTHERN_RANGE,
    [RESCUE_DUNGEON_PITFALL_VALLEY]     = SCRIPT_DUNGEON_PITFALL_VALLEY,
    [RESCUE_DUNGEON_BURIED_RELIC]       = SCRIPT_DUNGEON_BURIED_RELIC,
    [RESCUE_DUNGEON_WISH_CAVE]          = SCRIPT_DUNGEON_WISH_CAVE,
    [RESCUE_DUNGEON_MT_FREEZE_2]        = SCRIPT_DUNGEON_MT_FREEZE_2,
    [RESCUE_DUNGEON_MURKY_CAVE]         = SCRIPT_DUNGEON_MURKY_CAVE,
    [RESCUE_DUNGEON_DESERT_REGION]      = SCRIPT_DUNGEON_DESERT_REGION,
    [RESCUE_DUNGEON_SOUTHERN_CAVERN]    = SCRIPT_DUNGEON_SOUTHERN_CAVERN,
    [RESCUE_DUNGEON_WYVERN_HILL]        = SCRIPT_DUNGEON_WYVERN_HILL,
    [RESCUE_DUNGEON_SOLAR_CAVE]         = SCRIPT_DUNGEON_SOLAR_CAVE,
    [RESCUE_DUNGEON_DARKNIGHT_RELIC]    = SCRIPT_DUNGEON_DARKNIGHT_RELIC,
    [RESCUE_DUNGEON_GRAND_SEA]          = SCRIPT_DUNGEON_GRAND_SEA,
    [RESCUE_DUNGEON_WATERFALL_POND]     = SCRIPT_DUNGEON_WATERFALL_POND,
    [RESCUE_DUNGEON_UNOWN_RELIC]        = SCRIPT_DUNGEON_UNOWN_RELIC,
    [RESCUE_DUNGEON_JOYOUS_TOWER]       = SCRIPT_DUNGEON_JOYOUS_TOWER,
    [RESCUE_DUNGEON_FAR_OFF_SEA]        = SCRIPT_DUNGEON_FAR_OFF_SEA,
    [RESCUE_DUNGEON_PURITY_FOREST]      = SCRIPT_DUNGEON_PURITY_FOREST,
    [RESCUE_DUNGEON_ODDITY_CAVE]        = SCRIPT_DUNGEON_ODDITY_CAVE,
    [RESCUE_DUNGEON_REMAINS_ISLAND]     = SCRIPT_DUNGEON_REMAINS_ISLAND,
    [RESCUE_DUNGEON_MARVELOUS_SEA]      = SCRIPT_DUNGEON_MARVELOUS_SEA,
    [RESCUE_DUNGEON_FANTASY_STRAIT]     = SCRIPT_DUNGEON_FANTASY_STRAIT,
};

const DungeonInfo *GetScriptDungeonInfo(s32 scriptDungeon_)
{
    s32 scriptDungeon = (s16)scriptDungeon_;
    return &sScriptDungeonData[scriptDungeon];
}

static const DungeonInfo *GetRescueDungeonInfo(s16 rescueDungeonId)
{
    return &sScriptDungeonData[RescueDungeonToScriptDungeonId(rescueDungeonId)];
}

UNUSED static s16 sub_80A2644(u32 index)
{
    return gUnknown_8116F24[index];
}

s16 ScriptDungeonIDToRescueDungeonID(s16 scriptDungeonID)
{
    const DungeonInfo *info = GetScriptDungeonInfo(scriptDungeonID);
    return info->rescueDungeonID;
}

s16 sub_80A2668(s16 a0)
{
    if (a0 >= 55 && a0 <= 79)
        return a0 - 55;

    return -1;
}

s16 sub_80A2688(u8 r0)
{
    if (r0 >= 75 && r0 < 98)
        return r0 - 75;
    if (r0 == 47)
        return 23;
    if (r0 == 48)
        return 24;
    return -1;
}

s16 RescueDungeonToScriptDungeonId(s16 _rescueDungId)
{
    s32 rescueDungId = (s16) _rescueDungId;
    return sRescueToScriptDungeonIdTable[rescueDungId];
}

s16 sub_80A26CC(s16 r0)
{
    return 55 + r0;
}

UNUSED static s16 sub_80A26D8(u8 dungeonID)
{
    s32 i;
    s16 counter2;
    const DungeonInfo *temp;

    for (i = 0; i < 83; i++) {
        counter2 = i;
        temp = GetScriptDungeonInfo(counter2);

        if (temp->unk11) {
            if (temp->dungeonID == dungeonID)
                return counter2;
        }
    }
    return -1;
}

u8 RescueDungeonToDungeonId(s16 _rescueDungeonId)
{
    s32 rescueDungeonId = _rescueDungeonId; // forcing a shift before addressing
    const DungeonInfo *info = GetScriptDungeonInfo(sRescueToScriptDungeonIdTable[rescueDungeonId]);

    return info->dungeonID;
}

u8 sub_80A2728(s16 index)
{
    const DungeonInfo *temp;

    s16 temp_number = SCRIPT_DUNGEON_NORMAL_MAZE_2 + index;
    temp = GetScriptDungeonInfo(temp_number);
    return temp->dungeonID;
}

u8 ScriptDungeonIdToDungeonId(s16 scriptDungeonId_)
{
    s32 scriptDungeonId = scriptDungeonId_;
    const DungeonInfo *data = GetScriptDungeonInfo(scriptDungeonId);
    return data->dungeonID;
}

s16 sub_80A2750(s16 scriptDungeon)
{
    const DungeonInfo *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = scriptDungeon;
    temp_2 = temp_32;

    if (scriptDungeon == SCRIPT_DUNGEON_80)
        return 3;
    if (scriptDungeon == SCRIPT_DUNGEON_81)
        return 2;
    if (scriptDungeon == SCRIPT_DUNGEON_82)
        return 4;
    if (scriptDungeon >= SCRIPT_DUNGEON_DESERT_REGION && scriptDungeon <= SCRIPT_DUNGEON_FANTASY_STRAIT)
        return 2;
    if (scriptDungeon >= SCRIPT_DUNGEON_NORMAL_MAZE_2 && scriptDungeon <= SCRIPT_DUNGEON_SNOW_PATH)
        return 4;

    temp = GetScriptDungeonInfo(temp_2);
    if (temp->rescueDungeonID == -1)
        return 1;
    if (CheckQuest(QUEST_UNK5))
        return 1;
    if (!RescueScenarioConquered((s16)temp->rescueDungeonID))
        return 1;
    if (!CheckQuest(QUEST_UNK1))
        return 1;
    return 2;
}

bool8 IsRescueDungeonAvailable(s16 _rescueDungeonId)
{
    // Same dumbness as above to get a match
    s32 _rescueDungeonIdMatch = _rescueDungeonId;
    s32 rescueDungeonId = _rescueDungeonIdMatch;

    if (GetRescueDungeonInfo(_rescueDungeonId)->mapID1 == -1)
        return FALSE;
    if (CheckQuest(QUEST_UNK5))
        return FALSE;
    if (sub_8097384(_rescueDungeonId))
        return TRUE;
    if (!CheckQuest(QUEST_UNK1))
        return FALSE;
    if (!RescueScenarioConquered((s16) rescueDungeonId))
        return FALSE;
    return TRUE;
}

bool8 sub_80A2824(u8 dungeonID)
{
    s32 i;
    const DungeonInfo *temp;

    if (CheckQuest(QUEST_UNK5))
        return FALSE;

    if (CheckQuest(QUEST_UNK1)) {
        for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
            temp = GetRescueDungeonInfo(i);

            if (temp->unk11) {
                if (temp->dungeonID == dungeonID) {
                    if (sub_8097384((s16) i))
                        return TRUE;
                    if (RescueScenarioConquered((s16) i))
                        return TRUE;
                }
            }
        }
    }
    else {
        for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
            temp = GetRescueDungeonInfo(i);

            if (temp->unk11)
                if (temp->dungeonID == dungeonID)
                    if (sub_8097384((s16) i))
                        return TRUE;
        }
    }

    return FALSE;
}

UNUSED static bool8 sub_80A28B4(s16 rescueDungeon)
{
    const DungeonInfo *temp;

    temp = GetRescueDungeonInfo(rescueDungeon);

    if (temp->mapID1 != -1) {
        if (!sub_8097384(rescueDungeon) && !RescueScenarioConquered(rescueDungeon))
            return FALSE;
        else
            return TRUE;
    }

    return FALSE;
}

bool8 sub_80A28F0(u8 dungeonID)
{
    s32 i;

    for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
        const DungeonInfo *info = GetRescueDungeonInfo(i);

        if (info->unk11 && info->dungeonID == dungeonID) {
            if (sub_8097384((s16)i))
                return TRUE;
            if (RescueScenarioConquered((s16)i))
                return TRUE;
        }
    }

    return FALSE;
}

UNUSED static s32 sub_80A293C(u8 *param_1)
{
    u8 *pcVar2;
    s32 i;
    s32 counter;
    bool8 local_68[64];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((int)pcVar2 >= (int)local_68);


    for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
        const DungeonInfo *info = GetRescueDungeonInfo(i);
        if (info->unk11 && sub_8097384((s16)i))
            local_68[info->dungeonID] = TRUE;
    }

    for (i = 0; i < 63; i++) {
        if (local_68[i]) {
            param_1[counter] = i;
            counter++;
        }
    }

    return counter;
}

s32 sub_80A29B0(u8 *param_1)
{
    bool8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 *local1;
    u8 *local2;
    u8 *local3;
    u8 *local4;
    bool8 local_68[64];
    bool8 zero;

    counter = 0;
    local1 = &local_68[43];
    local2 = &local_68[44];
    local3 = &local_68[45];
    local4 = &local_68[46];
    zero = FALSE;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((int)pcVar2 >= (int)local_68);


    if (CheckQuest(QUEST_UNK1)) {
        for (index = 0; index < RESCUE_DUNGEON_COUNT; index++) {
            iVar3 = GetRescueDungeonInfo(index);

            if (iVar3->unk11 && RescueScenarioConquered((s16) index))
                local_68[iVar3->dungeonID] = TRUE;
        }
    }

    *local1 = 0;
    *local2 = 0;
    *local3 = 0;
    *local4 = 0;

    for (index = 0; index < 63; index++) {
        if (local_68[index]) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

UNUSED static s32 sub_80A2A5C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 i;
    s32 count;
    bool8 local_58[64];
    u8 zero;

    count = 0;
    zero = 0;

    pcVar2 = &local_58[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((s32)pcVar2 >= (s32)local_58);

    if (CheckQuest(QUEST_UNK1)) {
        for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
            iVar3 = GetRescueDungeonInfo(i);

            if (iVar3->unk11 && (sub_8097384((s16)i) || RescueScenarioConquered((s16)i)))
                local_58[iVar3->dungeonID] = TRUE;
        }
    }
    else {
        for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
            iVar3 = GetRescueDungeonInfo(i);

            if (iVar3->unk11 && sub_8097384((s16)i))
                local_58[iVar3->dungeonID] = TRUE;
        }
    }

    for (i = 0; i < 63; i++) {
        if (local_58[i]) {
            param_1[count] = i;
            count++;
        }
    }

    return count;
}
