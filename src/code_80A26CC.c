#include "global.h"
#include "globaldata.h"
#include "rescue_scenario.h"
#include "code_80A26CC.h"
#include "event_flag.h"
#include "constants/dungeon.h"
#include "constants/rescue_dungeon_id.h"

static const DungeonInfo gUnknown_81168A8[SCRIPT_DUNGEON_COUNT] = {
    [SCRIPT_DUNGEON_TINY_WOODS] = {
        .unk0 = 178,
        .unk2 = 178,
        .unk4 = 178,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 359,
        .dungeonIndex = DUNGEON_TINY_WOODS,
        .unkD = 0,
        .unkE = 0,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_THUNDERWAVE_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 127,
        .unk8 = 129,
        .unkA = 360,
        .dungeonIndex = DUNGEON_THUNDERWAVE_CAVE,
        .unkD = 0,
        .unkE = 1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_STEEL] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 136,
        .unk8 = 138,
        .unkA = 361,
        .dungeonIndex = DUNGEON_MT_STEEL,
        .unkD = 0,
        .unkE = 2,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_3] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 361,
        .dungeonIndex = DUNGEON_MT_STEEL,
        .unkD = 0,
        .unkE = 2,
        .unk10 = 1,
        .unk11 = 0,
    },
    [SCRIPT_DUNGEON_SINISTER_WOODS] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 148,
        .unk8 = 150,
        .unkA = 362,
        .dungeonIndex = DUNGEON_SINISTER_WOODS,
        .unkD = 0,
        .unkE = 3,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_5] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 362,
        .dungeonIndex = DUNGEON_SINISTER_WOODS,
        .unkD = 0,
        .unkE = 3,
        .unk10 = 1,
        .unk11 = 0,
    },
    [SCRIPT_DUNGEON_SILENT_CHASM] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 155,
        .unk8 = 157,
        .unkA = 363,
        .dungeonIndex = DUNGEON_SILENT_CHASM,
        .unkD = 0,
        .unkE = 4,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_THUNDER] = {
        .unk0 = 9,
        .unk2 = 189,
        .unk4 = 12,
        .unk6 = 162,
        .unk8 = 164,
        .unkA = 364,
        .dungeonIndex = DUNGEON_MT_THUNDER,
        .unkD = 0,
        .unkE = 5,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_THUNDER_PEAK] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 189,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 364,
        .dungeonIndex = DUNGEON_MT_THUNDER_PEAK,
        .unkD = 0,
        .unkE = 5,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GREAT_CANYON] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 170,
        .unk8 = 172,
        .unkA = 365,
        .dungeonIndex = DUNGEON_GREAT_CANYON,
        .unkD = 0,
        .unkE = 6,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_LAPIS_CAVE] = {
        .unk0 = 193,
        .unk2 = 194,
        .unk4 = 193,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 366,
        .dungeonIndex = DUNGEON_LAPIS_CAVE,
        .unkD = 0,
        .unkE = 7,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_BLAZE] = {
        .unk0 = 195,
        .unk2 = 196,
        .unk4 = 195,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 367,
        .dungeonIndex = DUNGEON_MT_BLAZE,
        .unkD = 0,
        .unkE = 8,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_BLAZE_PEAK] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 196,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 367,
        .dungeonIndex = DUNGEON_MT_BLAZE_PEAK,
        .unkD = 0,
        .unkE = 8,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FROSTY_FOREST] = {
        .unk0 = 198,
        .unk2 = 199,
        .unk4 = 198,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 368,
        .dungeonIndex = DUNGEON_FROSTY_FOREST,
        .unkD = 0,
        .unkE = 9,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FROSTY_GROTTO] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 199,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 368,
        .dungeonIndex = DUNGEON_FROSTY_GROTTO,
        .unkD = 0,
        .unkE = 9,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_FREEZE] = {
        .unk0 = 201,
        .unk2 = 202,
        .unk4 = 201,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 369,
        .dungeonIndex = DUNGEON_MT_FREEZE,
        .unkD = 0,
        .unkE = 10,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_PEAK] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 202,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 369,
        .dungeonIndex = DUNGEON_MT_FREEZE_PEAK,
        .unkD = 0,
        .unkE = 10,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MAGMA_CAVERN] = {
        .unk0 = 9,
        .unk2 = 205,
        .unk4 = 12,
        .unk6 = 222,
        .unk8 = 224,
        .unkA = 370,
        .dungeonIndex = DUNGEON_MAGMA_CAVERN,
        .unkD = 0,
        .unkE = 11,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MAGMA_CAVERN_PIT] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 205,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 370,
        .dungeonIndex = DUNGEON_MAGMA_CAVERN_PIT,
        .unkD = 0,
        .unkE = 11,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SKY_TOWER] = {
        .unk0 = 9,
        .unk2 = 208,
        .unk4 = 12,
        .unk6 = 230,
        .unk8 = 232,
        .unkA = 371,
        .dungeonIndex = DUNGEON_SKY_TOWER,
        .unkD = 0,
        .unkE = 12,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SKY_TOWER_SUMMIT] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 208,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 371,
        .dungeonIndex = DUNGEON_SKY_TOWER_SUMMIT,
        .unkD = 0,
        .unkE = 12,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_21] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 372,
        .dungeonIndex = DUNGEON_TINY_WOODS,
        .unkD = 0,
        .unkE = 13,
        .unk10 = 1,
        .unk11 = 0,
    },
    [SCRIPT_DUNGEON_UPROAR_FOREST] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 373,
        .dungeonIndex = DUNGEON_UPROAR_FOREST,
        .unkD = 0,
        .unkE = 14,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_HOWLING_FOREST] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 374,
        .dungeonIndex = DUNGEON_HOWLING_FOREST,
        .unkD = 0,
        .unkE = 15,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_STORMY_SEA] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 375,
        .dungeonIndex = DUNGEON_STORMY_SEA,
        .unkD = 0,
        .unkE = 16,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SILVER_TRENCH] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 376,
        .dungeonIndex = DUNGEON_SILVER_TRENCH,
        .unkD = 0,
        .unkE = 17,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_METEOR_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 377,
        .dungeonIndex = DUNGEON_METEOR_CAVE,
        .unkD = 0,
        .unkE = 18,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GREAT_CANYON_2] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 378,
        .dungeonIndex = DUNGEON_GREAT_CANYON,
        .unkD = 0,
        .unkE = 19,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FIERY_FIELD] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 379,
        .dungeonIndex = DUNGEON_FIERY_FIELD,
        .unkD = 0,
        .unkE = 20,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_LIGHTNING_FIELD] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 380,
        .dungeonIndex = DUNGEON_LIGHTNING_FIELD,
        .unkD = 0,
        .unkE = 21,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_NORTHWIND_FIELD] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 381,
        .dungeonIndex = DUNGEON_NORTHWIND_FIELD,
        .unkD = 0,
        .unkE = 22,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_FARAWAY] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 382,
        .dungeonIndex = DUNGEON_MT_FARAWAY,
        .unkD = 0,
        .unkE = 23,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_WESTERN_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 383,
        .dungeonIndex = DUNGEON_WESTERN_CAVE,
        .unkD = 0,
        .unkE = 24,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_NORTHERN_RANGE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 384,
        .dungeonIndex = DUNGEON_NORTHERN_RANGE,
        .unkD = 0,
        .unkE = 25,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_PITFALL_VALLEY] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 385,
        .dungeonIndex = DUNGEON_PITFALL_VALLEY,
        .unkD = 0,
        .unkE = 26,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_BURIED_RELIC] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 386,
        .dungeonIndex = DUNGEON_BURIED_RELIC,
        .unkD = 0,
        .unkE = 27,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_WISH_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 387,
        .dungeonIndex = DUNGEON_WISH_CAVE,
        .unkD = 0,
        .unkE = 28,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_2] = {
        .unk0 = 201,
        .unk2 = 202,
        .unk4 = 201,
        .unk6 = 346,
        .unk8 = 346,
        .unkA = 388,
        .dungeonIndex = DUNGEON_MT_FREEZE,
        .unkD = 0,
        .unkE = 29,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MT_FREEZE_PEAK_2] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 202,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 388,
        .dungeonIndex = DUNGEON_MT_FREEZE_PEAK_2,
        .unkD = 0,
        .unkE = 29,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MURKY_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 350,
        .unk8 = 350,
        .unkA = 389,
        .dungeonIndex = DUNGEON_MURKY_CAVE,
        .unkD = 0,
        .unkE = 30,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_DESERT_REGION] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_DESERT_REGION,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SOUTHERN_CAVERN] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_SOUTHERN_CAVERN,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_WYVERN_HILL] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_WYVERN_HILL,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SOLAR_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_SOLAR_CAVE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_DARKNIGHT_RELIC] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_DARKNIGHT_RELIC,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GRAND_SEA] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_GRAND_SEA,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_WATERFALL_POND] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_WATERFALL_POND,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_UNOWN_RELIC] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_UNOWN_RELIC,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_JOYOUS_TOWER] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_JOYOUS_TOWER,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FAR_OFF_SEA] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_FAR_OFF_SEA,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_PURITY_FOREST] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 390,
        .dungeonIndex = DUNGEON_PURITY_FOREST,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_ODDITY_CAVE] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 391,
        .dungeonIndex = DUNGEON_ODDITY_CAVE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_REMAINS_ISLAND] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 392,
        .dungeonIndex = DUNGEON_REMAINS_ISLAND,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_MARVELOUS_SEA] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 393,
        .dungeonIndex = DUNGEON_MARVELOUS_SEA,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FANTASY_STRAIT] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 394,
        .dungeonIndex = DUNGEON_FANTASY_STRAIT,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_NORMAL_MAZE_2] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_NORMAL_MAZE_2,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FIRE_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_FIRE_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_WATER_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_WATER_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GRASS_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_GRASS_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_ELECTRIC_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_ELECTRIC_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_ICE_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_ICE_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FIGHTING_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_FIGHTING_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GROUND_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_GROUND_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_FLYING_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_FLYING_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_PSYCHIC_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_PSYCHIC_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_POISON_MAZE_2] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_POISON_MAZE_2,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_BUG_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_BUG_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_ROCK_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_ROCK_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_GHOST_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_GHOST_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_DRAGON_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_DRAGON_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_DARK_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_DARK_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_STEEL_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_STEEL_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_TEAM_SHIFTY] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_TEAM_SHIFTY,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_TEAM_CONSTRICTOR] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_TEAM_CONSTRICTOR,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_TEAM_HYDRO] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_TEAM_HYDRO,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_TEAM_RUMBLEROCK] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_TEAM_RUMBLEROCK,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_RESCUE_TEAM_2] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_RESCUE_TEAM_2,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_RESCUE_TEAM_MAZE] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_RESCUE_TEAM_MAZE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_ROCK_PATH] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 398,
        .dungeonIndex = DUNGEON_ROCK_PATH,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_SNOW_PATH] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 399,
        .dungeonIndex = DUNGEON_SNOW_PATH,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [SCRIPT_DUNGEON_80] = {
        .unk0 = -1,
        .unk2 = 5,
        .unk4 = 5,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 395,
        .dungeonIndex = DUNGEON_OUT_ON_RESCUE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
    },
    [SCRIPT_DUNGEON_81] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = DUNGEON_OUT_ON_RESCUE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
    },
    [SCRIPT_DUNGEON_82] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = DUNGEON_OUT_ON_RESCUE,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
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
    [RESCUE_DUNGEON_DUMMY]              = SCRIPT_DUNGEON_21,
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

const DungeonInfo *GetDungeonInfo_80A2608(s32 scriptDungeon_)
{
    s32 scriptDungeon = (s16)scriptDungeon_;
    return &gUnknown_81168A8[scriptDungeon];
}

static const DungeonInfo *GetRescueDungeonInfo(s16 rescueDungeonId)
{
    return &gUnknown_81168A8[RescueDungeonToScriptDungeonId(rescueDungeonId)];
}

UNUSED static s16 sub_80A2644(u32 index)
{
    return gUnknown_8116F24[index];
}

s16 sub_80A2654(s16 index)
{
    const DungeonInfo *temp;

    temp = GetDungeonInfo_80A2608(index);
    return temp->unkE;
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

UNUSED static s16 sub_80A26D8(u8 index)
{
    s32 i;
    s16 counter2;
    const DungeonInfo *temp;

    for (i = 0; i < 83; i++) {
        counter2 = i;
        temp = GetDungeonInfo_80A2608(counter2);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index)
                return counter2;
        }
    }
    return -1;
}

u8 RescueDungeonToDungeonId(s16 _rescueDungeonId)
{
    s32 rescueDungeonId = _rescueDungeonId; // forcing a shift before addressing
    const DungeonInfo *info = GetDungeonInfo_80A2608(sRescueToScriptDungeonIdTable[rescueDungeonId]);

    return info->dungeonIndex;
}

u8 sub_80A2728(s16 index)
{
    const DungeonInfo *temp;

    s16 temp_number = 55 + index;
    temp = GetDungeonInfo_80A2608(temp_number);
    return temp->dungeonIndex;
}

u8 ScriptDungeonIdToDungeonId(s16 scriptDungeonId_)
{
    s32 scriptDungeonId = scriptDungeonId_;
    const DungeonInfo *data = GetDungeonInfo_80A2608(scriptDungeonId);
    return data->dungeonIndex;
}

s16 sub_80A2750(s16 r0)
{
    const DungeonInfo *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = r0;
    temp_2 = temp_32;

    if (r0 == 80)
        return 3;
    if (r0 == 81)
        return 2;
    if (r0 == 82)
        return 4;
    if ((u16)(r0 - 40) <= 14)
        return 2;
    if ((u16)(r0 - 55) <= 24)
        return 4;

    temp = GetDungeonInfo_80A2608(temp_2);
    if (temp->unkE == -1)
        return 1;
    if (CheckQuest(QUEST_UNK5))
        return 1;
    if (!RescueScenarioConquered((s16)temp->unkE))
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

    if (GetRescueDungeonInfo(_rescueDungeonId)->unk0 == -1)
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

bool8 sub_80A2824(u8 index)
{
    s32 i;
    const DungeonInfo *temp;

    if (CheckQuest(QUEST_UNK5))
        return FALSE;

    if (CheckQuest(QUEST_UNK1)) {
        for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
            temp = GetRescueDungeonInfo(i);

            if (temp->unk11 != 0) {
                if (temp->dungeonIndex == index) {
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

            if (temp->unk11 != 0)
                if (temp->dungeonIndex == index)
                    if (sub_8097384((s16) i))
                        return TRUE;
        }
    }

    return FALSE;
}

UNUSED static bool8 sub_80A28B4(s16 r0)
{
    const DungeonInfo *temp;

    temp = GetRescueDungeonInfo(r0);

    if (temp->unk0 != -1) {
        if (!sub_8097384(r0) && !RescueScenarioConquered(r0))
            return FALSE;
        else
            return TRUE;
    }

    return FALSE;
}

bool8 sub_80A28F0(u8 index)
{
    s32 counter;
    const DungeonInfo *temp;

    for (counter = 0; counter < 0x2E; counter++) {
        temp = GetRescueDungeonInfo(counter);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index) {
                if (sub_8097384((s16) counter))
                    return TRUE;
                if (RescueScenarioConquered((s16) counter))
                    return TRUE;
            }
        }
    }

    return FALSE;
}

UNUSED static s32 sub_80A293C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 local_68[64];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((int)pcVar2 >= (int)local_68);


    for (index = 0; index < RESCUE_DUNGEON_COUNT; index++) {
        iVar3 = GetRescueDungeonInfo(index);
        if (iVar3->unk11 != 0 && sub_8097384((s16) index))
            local_68[iVar3->dungeonIndex] = 1;
    }

    for (index = 0; index < 63; index++) {
        if (local_68[index] != 0) {
            param_1[counter] = index;
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
    bool8 local_68[0x40];
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

            if (iVar3->unk11 != 0 && RescueScenarioConquered((s16) index))
                local_68[iVar3->dungeonIndex] = TRUE;
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
    s32 index;
    s32 counter;
    u8 local_58[0x40];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_58[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((s32)pcVar2 >= (s32)local_58);

    if (CheckQuest(QUEST_UNK1)) {
        for (index = 0; index < RESCUE_DUNGEON_COUNT; index++) {
            iVar3 = GetRescueDungeonInfo(index);

            if (iVar3->unk11 != 0 && (sub_8097384((s16) index) || RescueScenarioConquered((s16) index)))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }
    else {
        for (index = 0; index < RESCUE_DUNGEON_COUNT; index++) {
            iVar3 = GetRescueDungeonInfo(index);

            if (iVar3->unk11 != 0 && sub_8097384((s16) index))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }

    for (index = 0; index < 63; index++) {
        if (local_58[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}
