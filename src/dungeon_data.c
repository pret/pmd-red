#include "global.h"
// #include "globaldata.h" TODO: once gDungeons is moved to C
#include "dungeon_data.h"
#include "dungeon_map_access.h"
#include "constants/walkable_tile.h"

// TODO: gDungeons from `dungeon/dungeon_data.inc`

const u8 gInvalidDungeonIDs[11] =
{
    DUNGEON_BOSS_3,
    DUNGEON_BOSS_4,
    DUNGEON_BOSS_9,
    DUNGEON_WONDROUS_SEA,
    DUNGEON_AUTOPILOT,
    DUNGEON_D50,
    DUNGEON_D51,
    DUNGEON_D54,
    DUNGEON_POISON_MAZE,
    DUNGEON_D61,
    DUNGEON_OUT_ON_RESCUE
};

// NDS=020C3448
const u8 gInvalidItemIDs[16] =
{
    ITEM_G_MACHINE_6,
    ITEM_G_MACHINE_7,
    ITEM_G_MACHINE_8,
    ITEM_TM_SPIN_SLASH,
    ITEM_SWITCH_BOX,
    ITEM_ALERT_SPECS,
    ITEM_POSSESS_ORB,
    ITEM_REVIVER_ORB,
    ITEM_TM_EXCAVATE,
    ITEM_TOSS_ORB,
    ITEM_RING_D,
    ITEM_RING_E,
    ITEM_RING_F,
    ITEM_OBSERVER_ORB,
    ITEM_BEATUP_ORB,
    NUMBER_OF_ITEM_IDS
};

const bool8 gTacticsTargetLeader[NUM_TACTICS] =
{
    [TACTIC_LETS_GO_TOGETHER] = TRUE,
    [TACTIC_GO_THE_OTHER_WAY] = FALSE,
    [TACTIC_GO_AFTER_FOES] = FALSE,
    [TACTIC_AVOID_THE_FIRST_HIT] = FALSE,
    [TACTIC_ALL_FOR_ONE] = TRUE,
    [TACTIC_GROUP_SAFETY] = TRUE,
    [TACTIC_AVOID_TROUBLE] = TRUE,
    [TACTIC_BE_PATIENT] = TRUE,
    [TACTIC_KEEP_YOUR_DISTANCE] = TRUE,
    [TACTIC_WAIT_THERE] = FALSE,
    [TACTIC_GET_AWAY] = TRUE,
    [TACTIC_UNUSED] = FALSE
};

const s16 gReqTacticLvls[NUM_TACTICS] =
{
    [TACTIC_LETS_GO_TOGETHER] = 1,
    [TACTIC_GO_THE_OTHER_WAY] = 25,
    [TACTIC_GO_AFTER_FOES] = 1,
    [TACTIC_AVOID_THE_FIRST_HIT] = 1,
    [TACTIC_ALL_FOR_ONE] = 999,
    [TACTIC_GROUP_SAFETY] = 999,
    [TACTIC_AVOID_TROUBLE] = 35,
    [TACTIC_BE_PATIENT] = 40,
    [TACTIC_KEEP_YOUR_DISTANCE] = 20,
    [TACTIC_WAIT_THERE] = 15,
    [TACTIC_GET_AWAY] = 10,
    [TACTIC_UNUSED] = 999,
};

const s32 gReqIQSkillPts[NUM_IQ_SKILLS] =
{
    [IQ_NONE] = 9999,
    [IQ_TYPE_ADVANTAGE_MASTER] = 105,
    [IQ_ITEM_CATCHER] = 1,
    [IQ_COURSE_CHECKER] = 1,
    [IQ_SURE_HIT_ATTACKER] = 500,
    [IQ_QUICK_DODGER] = 100,
    [IQ_PP_CHECKER] = 2,
    [IQ_NONTRAITOR] = 40,
    [IQ_STATUS_CHECKER] = 25,
    [IQ_EXP_GO_GETTER] = 200,
    [IQ_EFFICIENCY_EXPERT] = 10,
    [IQ_WEAK_TYPE_PICKER] = 125,
    [IQ_ALL_TERRAIN_HIKER] = 400,
    [IQ_SUPER_MOBILE] = 990,
    [IQ_TRAP_AVOIDER] = 140,
    [IQ_HOUSE_AVOIDER] = 800,
    [IQ_ENERGY_SAVER] = 250,
    [IQ_NONSLEEPER] = 160,
    [IQ_SELF_CURER] = 70,
    [IQ_TRAP_SEER] = 600,
    [IQ_LAVA_EVADER] = 300,
    [IQ_DEDICATED_TRAVELER] = 1,
    [IQ_ITEM_MASTER] = 1,
    [IQ_EXCLUSIVE_MOVE_USER] = 1,
};

// LUT for money item stack size -> money amount
// NDS=020C359C
const s32 gUnknown_810A3F0[100] = {
    4,     6,    10,    14,    22,    26,    34,    38,    46,    58,
    62,    74,    82,    86,    94,   106,   118,   122,   134,   142,
    146,   158,   166,   178,   194,   202,   206,   214,   218,   226,
    254,   262,   274,   278,   298,   302,   314,   326,   334,   346,
    358,   362,   382,   386,   394,   398,   422,   446,   454,   458,
    466,   478,   482,   502,   514,   526,   538,   542,   554,   562,
    566,   586,   614,   622,   626,   634,   662,   674,   694,   698,
    706,   718,   734,   746,   758,   768,   778,   794,   802,   818,
    838,   842,   862,   866,   878,   886,   898,   914,   922,   926,
    934,   958,   974,   982,   998,  1000,  1100,  1300,  1500, 20000
};

const s16 gTypeGummiIQBoost[NUM_TYPES][NUMBER_OF_GUMMIS] =
{
    [TYPE_NONE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    [TYPE_NORMAL] = {0x00, 0x07,  0x03,  0x03,  0x03,  0x03,  0x03,  0x04,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x01,  0x03,  0x03,  0x03},
    [TYPE_FIRE] = {0x00, 0x03,  0x07,  0x04,  0x02,  0x03,  0x02,  0x03,  0x03,  0x04,  0x03,  0x03,  0x02,  0x04,  0x03,  0x03,  0x03,  0x02},
    [TYPE_WATER] = {0x00, 0x03,  0x02,  0x07,  0x04,  0x04,  0x02,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x02},
    [TYPE_GRASS] = {0x00, 0x03,  0x04,  0x02,  0x07,  0x02,  0x04,  0x03,  0x04,  0x02,  0x04,  0x03,  0x04,  0x03,  0x03,  0x03,  0x03,  0x03},
    [TYPE_ELECTRIC] = {0x00, 0x03,  0x03,  0x03,  0x03,  0x07,  0x03,  0x03,  0x03,  0x04,  0x02,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x02},
    [TYPE_ICE] = {0x00, 0x03,  0x04,  0x03,  0x03,  0x03,  0x07,  0x04,  0x03,  0x03,  0x03,  0x03,  0x03,  0x04,  0x03,  0x03,  0x03,  0x04},
    [TYPE_FIGHTING] = {0x00, 0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x07,  0x03,  0x03,  0x04,  0x04,  0x02,  0x02,  0x03,  0x03,  0x02,  0x03},
    [TYPE_POISON] = {0x00, 0x03,  0x03,  0x03,  0x02,  0x03,  0x03,  0x02,  0x07,  0x04,  0x03,  0x04,  0x02,  0x03,  0x03,  0x03,  0x03,  0x03},
    [TYPE_GROUND] = {0x00, 0x03,  0x03,  0x04,  0x04,  0x01,  0x04,  0x03,  0x02,  0x07,  0x03,  0x03,  0x03,  0x02,  0x03,  0x03,  0x03,  0x03},
    [TYPE_FLYING] = {0x00, 0x03,  0x03,  0x03,  0x02,  0x04,  0x04,  0x02,  0x03,  0x01,  0x07,  0x03,  0x02,  0x04,  0x03,  0x03,  0x03,  0x03},
    [TYPE_PSYCHIC] = {0x00, 0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x02,  0x03,  0x03,  0x03,  0x07,  0x04,  0x03,  0x04,  0x03,  0x04,  0x03},
    [TYPE_BUG] = {0x00, 0x03,  0x04,  0x03,  0x02,  0x03,  0x03,  0x02,  0x03,  0x02,  0x04,  0x03,  0x07,  0x04,  0x03,  0x03,  0x03,  0x03},
    [TYPE_ROCK] = {0x00, 0x02,  0x02,  0x04,  0x04,  0x03,  0x03,  0x04,  0x02,  0x04,  0x02,  0x03,  0x03,  0x07,  0x03,  0x03,  0x03,  0x04},
    [TYPE_GHOST] = {0x00, 0x01,  0x03,  0x03,  0x03,  0x03,  0x03,  0x01,  0x02,  0x03,  0x03,  0x04,  0x02,  0x03,  0x07,  0x03,  0x04,  0x03},
    [TYPE_DRAGON] = {0x00, 0x03,  0x02,  0x02,  0x02,  0x02,  0x04,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x07,  0x03,  0x03},
    [TYPE_DARK] = {0x00, 0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x04,  0x03,  0x03,  0x03,  0x01,  0x04,  0x03,  0x02,  0x03,  0x07,  0x03},
    [TYPE_STEEL] = {0x00, 0x02,  0x04,  0x03,  0x02,  0x03,  0x02,  0x04,  0x01,  0x04,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x07},
};

const s16 gUnknown_810A808[NUM_TYPES][NUMBER_OF_GUMMIS] =
{
    [TYPE_NONE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    [TYPE_NORMAL] = {0x00, 0x3c, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1e, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x05, 0x19, 0x19, 0x19},
    [TYPE_FIRE] = {0x00, 0x19, 0x3c, 0x1e, 0x14, 0x19, 0x14, 0x19, 0x19, 0x1e, 0x19, 0x19, 0x14, 0x1e, 0x19, 0x19, 0x19, 0x14},
    [TYPE_WATER] = {0x00, 0x19, 0x14, 0x3c, 0x1e, 0x1e, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x14},
    [TYPE_GRASS] = {0x00, 0x19, 0x1e, 0x14, 0x3c, 0x14, 0x1e, 0x19, 0x1e, 0x14, 0x1e, 0x19, 0x1e, 0x19, 0x19, 0x19, 0x19, 0x19},
    [TYPE_ELECTRIC] = {0x00, 0x19, 0x19, 0x19, 0x19, 0x3c, 0x19, 0x19, 0x19, 0x1e, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x14},
    [TYPE_ICE] = {0x00, 0x19, 0x1e, 0x19, 0x19, 0x19, 0x3c, 0x1e, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1e, 0x19, 0x19, 0x19, 0x1e},
    [TYPE_FIGHTING] = {0x00, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x3c, 0x19, 0x19, 0x1e, 0x1e, 0x14, 0x14, 0x19, 0x19, 0x14, 0x19},
    [TYPE_POISON] = {0x00, 0x19, 0x19, 0x19, 0x14, 0x19, 0x19, 0x14, 0x3c, 0x1e, 0x19, 0x1e, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19},
    [TYPE_GROUND] = {0x00, 0x19, 0x19, 0x1e, 0x1e, 0x05, 0x1e, 0x19, 0x14, 0x3c, 0x19, 0x19, 0x19, 0x14, 0x19, 0x19, 0x19, 0x19},
    [TYPE_FLYING] = {0x00, 0x19, 0x19, 0x19, 0x14, 0x1e, 0x1e, 0x14, 0x19, 0x05, 0x3c, 0x19, 0x14, 0x1e, 0x19, 0x19, 0x19, 0x19},
    [TYPE_PSYCHIC] = {0x00, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x14, 0x19, 0x19, 0x19, 0x3c, 0x1e, 0x19, 0x1e, 0x19, 0x1e, 0x19},
    [TYPE_BUG] = {0x00, 0x19, 0x1e, 0x19, 0x14, 0x19, 0x19, 0x14, 0x19, 0x14, 0x1e, 0x19, 0x3c, 0x1e, 0x19, 0x19, 0x19, 0x19},
    [TYPE_ROCK] = {0x00, 0x14, 0x14, 0x1e, 0x1e, 0x19, 0x19, 0x1e, 0x14, 0x1e, 0x14, 0x19, 0x19, 0x3c, 0x19, 0x19, 0x19, 0x1e},
    [TYPE_GHOST] = {0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x05, 0x14, 0x19, 0x19, 0x1e, 0x14, 0x19, 0x3c, 0x19, 0x1e, 0x19},
    [TYPE_DRAGON] = {0x00, 0x19, 0x14, 0x14, 0x14, 0x14, 0x1e, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x3c, 0x19, 0x19},
    [TYPE_DARK] = {0x00, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1e, 0x19, 0x19, 0x19, 0x05, 0x1e, 0x19, 0x14, 0x19, 0x3c, 0x19},
    [TYPE_STEEL] = {0x00, 0x14, 0x1e, 0x19, 0x14, 0x19, 0x14, 0x1e, 0x05, 0x1e, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x3c},
};

const FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS] =
{
    [FRIEND_AREA_NONE] = {
        .num_pokemon = 0,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 0,
    },
    [BOUNTIFUL_SEA] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500,
    },
    [TREASURE_SEA] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 4500,
    },
    [SERENE_SEA] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8000,
    },
    [DEEP_SEA_FLOOR] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500,
    },
    [DEEP_SEA_CURRENT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0,
    },
    [SEAFLOOR_CAVE] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0,
    },
    [SHALLOW_BEACH] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [MT_DEEPGREEN] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 130,
    },
    [MT_CLEFT] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [MT_MOONVIEW] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0,
    },
    [RAINBOW_PEAK] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500,
    },
    [WILD_PLAINS] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 100,
    },
    [BEAU_PLAINS] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600,
    },
    [SKY_BLUE_PLAINS] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0,
    },
    [SAFARI] = {
        .num_pokemon = 15,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 700,
    },
    [SCORCHED_PLAINS] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [SACRED_FIELD] =  {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [MIST_RISE_FOREST] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 150
    },
    [FLYAWAY_FOREST] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 550
    },
    [OVERGROWN_FOREST] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600
    },
    [ENERGETIC_FOREST] = {
        .num_pokemon = 15,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000
    },
    [MUSHROOM_FOREST] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [HEALING_FOREST] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [TRANSFORM_FOREST] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [SECRETIVE_FOREST] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [RUB_A_DUB_RIVER] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [TADPOLE_POND] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [TURTLESHELL_POND] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [MYSTIC_LAKE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 2500
    },
    [WATERFALL_LAKE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 3500
    },
    [PEANUT_SWAMP] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 2500
    },
    [POISON_SWAMP] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
    [ECHO_CAVE] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 7500
    },
    [CRYPTIC_CAVE] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [DRAGON_CAVE] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0
    },
    [BOULDER_CAVE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0
    },
    [JUNGLE] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 800
    },
    [DECREPIT_LAB] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [MT_DISCIPLINE] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1200
    },
    [THUNDER_MEADOW] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [POWER_PLANT] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600
    },
    [CRATER] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 7500
    },
    [FURNACE_DESERT] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
    [AGED_CHAMBER_AN] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [AGED_CHAMBER_O_EXCLAIM] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [ANCIENT_RELIC] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8000
    },
    [DARKNESS_RIDGE] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [FRIGID_CAVERN] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9000
    },
    [ICE_FLOE_BEACH] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9500
    },
    [VOLCANIC_PIT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [STRATOS_LOOKOUT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [RAVAGED_FIELD] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [MAGNETIC_QUARRY] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [LEGENDARY_ISLAND] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 7500
    },
    [SOUTHERN_ISLAND] = {
        .num_pokemon = 2,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9500
    },
    [ENCLOSED_ISLAND] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [FINAL_ISLAND] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
};

const s16 gUnknown_810AC60 = 12;
const s16 gUnknown_810AC62 = 12;
const s16 gUnknown_810AC64 = 8;
const s16 gUnknown_810AC66 = 8;
const s16 gUnknown_810AC68 = 8;

const u8 gUnknown_810AC6A[NUM_TYPES] =
{
    [TYPE_NONE] = TYPE_NONE,
    [TYPE_NORMAL] = TYPE_GHOST,
    [TYPE_FIRE] = TYPE_WATER,
    [TYPE_WATER] = TYPE_GRASS,
    [TYPE_GRASS] = TYPE_BUG,
    [TYPE_ELECTRIC] = TYPE_GROUND,
    [TYPE_ICE] = TYPE_FIRE,
    [TYPE_FIGHTING] = TYPE_GHOST,
    [TYPE_POISON] = TYPE_STEEL,
    [TYPE_GROUND] = TYPE_FLYING,
    [TYPE_FLYING] = TYPE_ROCK,
    [TYPE_PSYCHIC] = TYPE_DARK,
    [TYPE_BUG] = TYPE_POISON,
    [TYPE_ROCK] = TYPE_FIGHTING,
    [TYPE_GHOST] = TYPE_NORMAL,
    [TYPE_DRAGON] = TYPE_STEEL,
    [TYPE_DARK] = TYPE_DARK,
    [TYPE_STEEL] = TYPE_ELECTRIC,
};

const bool8 gIsTypePhysicalTable[NUM_TYPES] = {
    [TYPE_NONE] = TRUE,
    [TYPE_NORMAL] = TRUE,
    [TYPE_FIGHTING] = TRUE,
    [TYPE_POISON] = TRUE,
    [TYPE_GROUND] = TRUE,
    [TYPE_FLYING] = TRUE,
    [TYPE_BUG] = TRUE,
    [TYPE_ROCK] = TRUE,
    [TYPE_GHOST] = TRUE,
    [TYPE_STEEL] = TRUE,
};
const s32 gUnknown_810AC90[10] = {2, 4, 6, 7, 8, 9, 0xA, 0xD, 0xF, 0x11};
const s16 gFrenzyPlantIQReq = 333;
const s16 gHydroCannonIQReq = 333;
const s16 gBlastBurnIQReq = 333;
const s16 gVoltTackleIQReq = 333;

const u8 gDungeonWaterType[76] = {
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_WATER,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_WATER,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_LAVA,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
    DUNGEON_WATER_TYPE_NONE,
};

const struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON] = {

    RED_EXCLUSIVE(MONSTER_PORYGON),
    BLUE_EXCLUSIVE(MONSTER_PORYGON2),
    BLUE_EXCLUSIVE(MONSTER_MAGIKARP),
    BLUE_EXCLUSIVE(MONSTER_GYARADOS),
    RED_EXCLUSIVE(MONSTER_FEEBAS),
    RED_EXCLUSIVE(MONSTER_MILOTIC),
    RED_EXCLUSIVE(MONSTER_PLUSLE),
    BLUE_EXCLUSIVE(MONSTER_MINUN),
    BLUE_EXCLUSIVE(MONSTER_LAPRAS),
    RED_EXCLUSIVE(MONSTER_MANTINE),
    RED_EXCLUSIVE(MONSTER_ROSELIA),
    BLUE_EXCLUSIVE(MONSTER_AIPOM),
};
