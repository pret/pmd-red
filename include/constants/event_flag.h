#ifndef GUARD_CONSTANTS_EVENT_FLAG_H
#define GUARD_CONSTANTS_EVENT_FLAG_H

enum MainQuest
{
    // SCENARIO_MAIN:

    QUEST_SET_TEAM_NAME,
    QUEST_UNK1, // Rescue dungeon related. For some reason it scans all rescue dungeons.
    QUEST_CAN_ACCESS_JOBS,
    QUEST_CAN_RECRUIT,
    QUEST_SQUARE_ASLEEP,
    QUEST_UNK5, // Run away related? It disallows "friend rescue" features.
    QUEST_REACHED_POSTGAME,
    QUEST_UNLOCKED_EVOLUTIONS,
    QUEST_CAN_CHANGE_LEADER,
    QUEST_CAN_DEPOSIT_PARTNER,
    QUEST_UNK10, // Dojo-related
    QUEST_UNK11,
    QUEST_UNK12, // Music-related
    QUEST_IN_WORLD_CALAMITY,
    QUEST_MAZE_14,
    QUEST_MAZE_15,
    QUEST_LEGEND_ZAPDOS,
    QUEST_LEGEND_MOLTRES,
    QUEST_LEGEND_ARTICUNO,
    QUEST_LEGEND_GROUDON,
    QUEST_LEGEND_RAYQUAZA,

    // SCENARIO_SUB2:

    QUEST_LEGEND_KYOGRE,
    QUEST_LEGEND_LUGIA,

    // SCENARIO_SUB3:

    QUEST_LEGEND_DEOXYS,

    // SCENARIO_SUB4:

    QUEST_LEGEND_HO_OH,

    // SCENARIO_SUB5:

    QUEST_LEGEND_MEWTWO,

    // SCENARIO_SUB7:

    QUEST_LEGEND_MEW,

    // RESCUE_SCENARIO_CONQUEST_LIST:

    QUEST_LEGEND_CELEBI,

    // Special check:

    QUEST_LUCARIO_RANK,

    // TRAINING_CONQUEST_LIST:

    QUEST_COMPLETED_ALL_MAZES,
};

enum FlagCalcOperation
{
    CALC_SET,
    CALC_SUB,
    CALC_ADD,
    CALC_MUL,
    CALC_DIV,
    CALC_MOD,
    CALC_AND,
    CALC_OR,
    CALC_XOR,
    CALC_SETBIT,
    CALC_CLEARBIT,
    CALC_RANDOM,
};

enum FlagJudgeOperation
{
    JUDGE_TRUE,
    JUDGE_FALSE,
    JUDGE_EQ,
    JUDGE_GT,
    JUDGE_LT,
    JUDGE_GE,
    JUDGE_LE,
    JUDGE_NE,
    JUDGE_AND_NONZERO,
    JUDGE_XOR_NONZERO, // logically identical to JUDGE_NE
    JUDGE_BIT_SET,
};

enum StartModeVal
{
    STARTMODE_NEW_GAME,
    STARTMODE_CONTINUE_GAME,
    STARTMODE_GROUND, // Overworld
    STARTMODE_3,
    STARTMODE_FRIEND_AREAS,
    STARTMODE_DUNGEON_FROM_WORLD_MAP,
    STARTMODE_6,
    STARTMODE_CONTINUE_QUICKSAVE,
    STARTMODE_8,
    STARTMODE_DUNGEON_WON,
    STARTMODE_10,
    STARTMODE_11,
    STARTMODE_DUNGEON_LOST,
    STARTMODE_13,
    STARTMODE_14,
    STARTMODE_15,
    STARTMODE_16,
    STARTMODE_17,
};

// SCENARIO_MAIN:
//  0,  0 = New game
//  1,  0 = ???
//  2,  0 = ???
//  2,  1 = ???
//  2,  2 = ??? Set upon exiting Tiny Woods.
//  3,  0 = Chose team name. See QUEST_SET_TEAM_NAME. Set in EVENT_M01E01A_L003
//  3,  1 = ???
//  3,  2 = ???
//  3,  3 = ??? Bed tutorial related.
//  3,  4 = ??? See QUEST_UNK1 also
//  3,  5 = ???
//  3,  6 = ??? Thunderwave cave related
//  4,  0 = ??? Set upon exiting Thunderwave Cave.
//  4,  1 = ???
//  4,  2 = ???
//  4,  3 = ???
//  4,  4 = ??? See QUEST_CAN_ACCESS_JOBS also
//  4,  5 = ??? Mt Steel related
//  4,  6 = ???
//  4,  7 = ???
//  4,  8 = ???
//  5,  0 = ???
//  5,  1 = ??? See QUEST_CAN_RECRUIT also
//  5,  2 = ???
//  5,  3 = ???
//  5,  4 = ???
//  5,  5 = ??? See QUEST_UNK10 and QUEST_UNK11 also
//  5,  6 = ???
//  5,  7 = ??? See QUEST_MAZE_14 also
//  5,  8 = ???
//  5,  9 = ??? Sinister Woods related
//  5, 10 = ???
//  5, 11 = ???
//  6,  0 = ???
//  6,  1 = ???
//  6,  2 = ???
//  6,  3 = ??? Silent Chasm related
//  7,  0 = ???
//  7,  1 = ???
//  7,  2 = ???
//  7,  3 = ??? Mt Thunder related
//  7,  4 = ???
//  7,  5 = ???
//  8,  0 = ??? See QUEST_LEGEND_ZAPDOS also
//  8,  1 = ???
//  8,  2 = ???
//  8,  3 = ??? Great Canyon related
//  8,  4 = ???
//  9,  0 = ???
//  9,  1 = ???
//  9,  2 = ???
//  9,  3 = ???
//  9,  4 = ???
//  9,  5 = ???
// 10,  0 = ???
// 10,  1 = ???
// 10,  2 = ???
// 10,  3 = ???
// 11,  0 = Fugitive story begins. See QUEST_SQUARE_ASLEEP also
// 11,  1 = ???
// 11,  2 = ??? See QUEST_UNK12 also
// 11,  3 = ??? See QUEST_UNK12 also
// 11,  4 = ??? See QUEST_UNK5 also
// 11,  5 = ???
// 12,  0 = Lapis Cave completed? Mt Blaze story begins?
// 12,  1 = ???
// 12,  2 = ???
// 12,  3 = ???
// 12,  4 = ???
// 13,  0 = Mt Blaze completed. Frosty Grotto story begins. See QUEST_SQUARE_ASLEEP and QUEST_LEGEND_MOLTRES also
// 13,  1 = ???
// 13,  2 = ???
// 13,  3 = ???
// 13,  4 = ???
// 14,  0 = Frosty Grotto completed. Mt Freeze story begins? See QUEST_LEGEND_ARTICUNO also
// 14,  1 = ???
// 14,  2 = ???
// 14,  3 = ???
// 15,  0 = Mt Freeze completed? See QUEST_UNK5 and QUEST_MAZE_14 also
// 15,  1 = ???
// 15,  2 = ???
// 15,  3 = ???
// 15,  4 = ???
// 15,  5 = ??? Uproar Forest related
// 15,  6 = ???
// 15,  7 = ???
// 15,  8 = ???
// 15,  9 = ???
// 15, 10 = ??? Magma Cavern related
// 15, 11 = ??? Magma Cavern related
// 15, 12 = ???
// 16,  0 = Magma Cavern completed. Sky Tower story begins. See QUEST_LEGEND_GROUDON also
// 16,  1 = ???
// 16,  2 = World calamity music is forced. Partner awaits in Pokémon Square for you to confirm you're ready for Sky Tower. You begin dreaming with Gardevoir and Gengar is there. See QUEST_IN_WORLD_CALAMITY
// 16,  3 = ???
// 16,  4 = ??? Sky Tower related
// 16,  5 = ???
// 16,  6 = ???
// 17,  0 = Sky Tower completed. See QUEST_LEGEND_RAYQUAZA also
// 17,  1 = ???
// 18,  0 = ??? See QUEST_REACHED_POSTGAME also
// 18,  1 = ???
// 18,  2 = ??? See QUEST_UNLOCKED_EVOLUTIONS also
// 18,  3 = ??? See QUEST_CAN_CHANGE_LEADER also
// 18,  4 = ???
// 19,  0 = ??? See QUEST_CAN_DEPOSIT_PARTNER also
// 19,  1 = ???
// 19,  2 = ???
// 20,  1 = ???
// 20,  2 = ???
// 21,  1 = ???
// 21,  2 = ???
// 22,  1 = ???
// 22,  2 = ???
// 23,  1 = ???
// 23,  2 = ???
// 24,  1 = ???
// 24,  2 = ???
// 25,  1 = ???
// 25,  2 = ???
// 26,  1 = ???
// 26,  2 = ???
// 27,  1 = ??? Set from EVENT_DIVIDE_AFTER
// 27,  2 = ???
// 58,  1 = ???

// SCENARIO_SUB1:
// 29,  1 = Mankey Quest activated.
// 29,  2 = ??? Uproar Forest related
// 29,  3 = ??? Uproar Forest related
// 30,  0 = Mankey gang brought to base?
// 30,  2 = Enough chestnuts collected to complete team base renovation.
// 31,  0 = ??? Uproar Forest related
// 31,  1 = ??? Howling Forest related
// 31,  2 = ??? Howling Forest related
// 31,  3 = ???
// 32,  0 = ??? Howling Forest related
// 32,  2 = Smeargle cannot join because its friend area is full.
// 32,  3 = Smeargle joined.

// SCENARIO_SUB2:
// 33,  1 = Stormy Sea story activated.
// 33,  2 = Heard Lombre's story about the Stormy Sea.
// 33,  3 = Ready to speak to Whiscash about Stormy Sea.
// 33,  4 = Stormy Sea unlocked from Whiscash.
// 33,  5 = ???
// 34,  0 = Stormy Sea completed. See QUEST_LEGEND_KYOGRE
// 34,  1 = ???
// 34,  2 = ??? Legendary Island friend area related
// 34,  3 = ??? Silver Trench related
// 34,  5 = ???
// 35,  0 = Silver Trench completed. See QUEST_LEGEND_LUGIA

// SCENARIO_SUB3:
// 36,  1 = Meteor Cave story activated.
// 36,  2 = ??? Meteor Cave related
// 36,  3 = ???
// 37,  0 = Meteor Cave completed. See QUEST_LEGEND_DEOXYS

// SCENARIO_SUB4:
// 38,  1 = Ho-Oh story activated.
// 38,  2 = Xatu awaits for Ho-Oh story.
// 39,  0 = Xatu met for Ho-Oh story. Fiery Field opens.
// 39,  3 = ???
// 40,  0 = Fiery Field completed. Lightning Field opens.
// 40,  3 = ???
// 41,  0 = Lightning Field completed. Northwind Field opens.
// 41,  3 = ???
// 42,  0 = Northwind Field completed. Mt Faraway opens.
// 42,  3 = ???
// 43,  0 = Mt Faraway completed. See QUEST_LEGEND_HO_OH
// 43,  2 = ??? RESCUE_DUNGEON_GREAT_CANYON_2 and Fields/MtFaraway related

// SCENARIO_SUB5:
// 44,  1 = Western Cave story activated.
// 44,  2 = Western Cave opens.
// 44,  3 = ???
// 45,  0 = Western Cave completed. See QUEST_LEGEND_MEWTWO

// SCENARIO_SUB6:
// 46,  1 = Latios/Latias story activated.
// 46,  2 = Northern Range opens.
// 46,  3 = ???
// 47,  2 = Pitfall Valley opens.
// 47,  3 = ???
// 48,  0 = Latios/Latias story completed.

// SCENARIO_SUB7:
// 49,  1 = Buried Relic story activated.
// 49,  2 = Read Buried Relic news
// 49,  3 = Buried Relic opens.
// 49,  4 = ???
// 50,  0 = Buried Relic completed. See QUEST_LEGEND_MEW

// SCENARIO_SUB8:
// 51,  1 = Wish Cave story activated.
// 51,  2 = ???
// 51,  3 = ???
// 51,  4 = ???
// 51,  5 = ???
// 51,  6 = ???
// 51,  7 = ??? Wish Cave related
// 51,  8 = ??? Wish Cave related
// 51,  9 = ??? Set upon exiting Wish Cave.
// 52,  0 = Wish Cave completed.

// SCENARIO_SUB9:
// 53,  1 = Curse lifting story activated.
// 53,  2 = ???
// 53,  3 = ???
// 53,  4 = ??? Genger Mt Freeze related
// 53,  5 = ???
// 53,  6 = ??? RESCUE_DUNGEON_MT_FREEZE_2 related
// 54,  0 = ??? RESCUE_DUNGEON_MT_FREEZE_2 related
// 54,  2 = ??? Murky Cave related (EVENT_S09E01B_L001)
// 54,  4 = ??? Set upon exiting Murky Cave.
// 55,  2 = ??? RESCUE_DUNGEON_MT_FREEZE_2 and Murky Cave related
// 55,  3 = Gardevoir recruited

enum ScriptVarId
{
    /* 0x00 */ VERSION,
    /* 0x01 */ CONDITION,
    /* 0x02 */ SCENARIO_SELECT,
    /* 0x03 */ SCENARIO_MAIN,
    /* 0x04 */ SCENARIO_SUB1,
    /* 0x05 */ SCENARIO_SUB2,
    /* 0x06 */ SCENARIO_SUB3,
    /* 0x07 */ SCENARIO_SUB4,
    /* 0x08 */ SCENARIO_SUB5,
    /* 0x09 */ SCENARIO_SUB6,
    /* 0x0a */ SCENARIO_SUB7,
    /* 0x0b */ SCENARIO_SUB8,
    /* 0x0c */ SCENARIO_SUB9,
    /* 0x0d */ GROUND_ENTER,
    /* 0x0e */ GROUND_ENTER_LINK,
    /* 0x0f */ GROUND_GETOUT,
    /* 0x10 */ GROUND_MAP,
    /* 0x11 */ GROUND_PLACE,
    /* 0x12 */ DUNGEON_SELECT,
    /* 0x13 */ DUNGEON_ENTER,
    /* 0x14 */ DUNGEON_ENTER_INDEX,
    /* 0x15 */ DUNGEON_ENTER_FREQUENCY,
    /* 0x16 */ DUNGEON_RESULT,
    /* 0x17 */ SCRIPT_MODE,
    /* 0x18 */ START_MODE, // See enum "StartModeVal"
    /* 0x19 */ CLEAR_COUNT,
    /* 0x1a */ CONDITION_KIND,
    /* 0x1b */ WEATHER_KIND,
    /* 0x1c */ PLAYER_KIND,
    /* 0x1d */ PARTNER1_KIND,
    /* 0x1e */ PARTNER2_KIND,
    /* 0x1f */ NEW_FRIEND_KIND,
    /* 0x20 */ FRIEND_SUM,
    /* 0x21 */ UNIT_SUM,
    /* 0x22 */ GOLD,
    /* 0x23 */ BANK_GOLD,
    /* 0x24 */ WARP_LIST,
    /* 0x25 */ WARP_LOCK,
    /* 0x26 */ PARTNER_TALK_KIND,
    /* 0x27 */ BASE_KIND,
    /* 0x28 */ BASE_LEVEL,
    /* 0x29 */ FLAG_KIND,
    /* 0x2a */ FLAG_KIND_CHANGE_REQUEST,
    /* 0x2b */ RESCUE_SCENARIO_ORDER_LIST,
    /* 0x2c */ RESCUE_SCENARIO_JOB_LIST,
    /* 0x2d */ RESCUE_SCENARIO_CONQUEST_LIST,
    /* 0x2e */ TRAINING_CONQUEST_LIST,
    /* 0x2f */ TRAINING_PRESENT_LIST,
    /* 0x30 */ DUNGEON_ENTER_LIST,
    /* 0x31 */ DUNGEON_CLEAR_LIST,
    /* 0x32 */ POSITION_X,
    /* 0x33 */ POSITION_Y,
    /* 0x34 */ POSITION_HEIGHT,
    /* 0x35 */ POSITION_DIRECTION,
    /* 0x36 */ GROUND_LOCAL,
    /* 0x37 */ MAP_LOCAL,
    /* 0x38 */ MAP_LOCAL_DOOR,
    /* 0x39 */ EVENT_LOCAL,
    /* 0x3a */ STATION_ITEM_STATIC,
    /* 0x3b */ STATION_ITEM_TEMP,
    /* 0x3c */ DELIVER_ITEM_STATIC,
    /* 0x3d */ DELIVER_ITEM_TEMP,
    /* 0x3e */ SHOP_TEMP,
    /* 0x3f */ INN_TEMP,
    /* 0x40 */ EVENT_S07E01,
    /* 0x41 */ EVENT_S08E01,
    /* 0x42 */ EVENT_GONBE,
    /* 0x43 */ EVENT_ORNAMENT_01,
    /* 0x44 */ EVENT_ORNAMENT_02,
    /* 0x45 */ EVENT_ORNAMENT_03,
    /* 0x46 */ EVENT_ORNAMENT_04,
    /* 0x47 */ EVENT_B01P01,
    /* 0x48 */ EVENT_T01P01,
    /* 0x49 */ EVENT_T01P02,
    /* 0x4a */ EVENT_T01P03,
    /* 0x4b */ EVENT_M01E09A_2N,
    /* 0x4c */ EVENT_M01E09A_8N,
    /* 0x4d */ EVENT_M01E10A_1N,
    /* 0x4e */ EVENT_M01E10A_3N,
    /* 0x4f */ EVENT_M01E10A_5N,
    /* 0x50 */ EVENT_M02E01A_2N,
    /* 0x51 */ SUM,
    /* 0x52 */ SCRIPT_VARS_COUNT,
    /* 0x400 */ LOCAL0 = 0x400,
    /* 0x401 */ LOCAL1,
    /* 0x402 */ LOCAL2,
    /* 0x403 */ LOCAL3,
};

#endif // GUARD_CONSTANTS_EVENT_FLAG_H
