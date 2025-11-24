








static const struct ScriptCommand s_gs109_g0_s0_station_sref_script[] = { /* 0x81f07c8 */
    DEBUGINFO_O(11),
    SELECT_MAP(109),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 3, /* to label */ 0),
    JUMP_LABEL(1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    SELECT_ENTITIES(1, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 6),
    JUMP_LABEL(4),
  LABEL(6), /* = 0x06 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 7),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(8),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    BGM_SWITCH(MUS_FRIEND_AREA_DEEPSEA_CURRENT),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs109_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs109_g0_s0_station_sref_script }; /* 0x81f0a44 */

static const struct ScriptCommand s_gs109_g0_s1_lives0_dlg0[] = { /* 0x81f0a50 */
    DEBUGINFO_O(53),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g0_s1_lives1_dlg0[] = { /* 0x81f0a90 */
    DEBUGINFO_O(60),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g0_s3_lives0_dlg0[] = { /* 0x81f0ad0 */
    DEBUGINFO_O(67),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g0_s3_lives1_dlg0[] = { /* 0x81f0b10 */
    DEBUGINFO_O(74),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g0_s4_lives0_dlg0[] = { /* 0x81f0b50 */
    DEBUGINFO_O(81),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g0_s4_lives1_dlg0[] = { /* 0x81f0b80 */
    DEBUGINFO_O(87),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs109_g1_s0_lives0_dlg1[] = { /* 0x81f0bb0 */
    DEBUGINFO_O(93),
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs109_g1_s0_lives0_dlg2[] = { /* 0x81f0be0 */
    DEBUGINFO_O(99),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs109_g0_s1_lives[] = { /* 0x81f0c00 */
    /*  0 */ {   0,   4,   0,   0, {  29,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs109_g0_s3_lives[] = { /* 0x81f0c30 */
    /*  0 */ {   0,   4,   0,   0, {  29,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs109_g0_s4_lives[] = { /* 0x81f0c60 */
    /*  0 */ {   0,   0,   0,   0, {  29,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs109_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs109_g1_s0_lives[] = { /* 0x81f0c90 */
    /*  0 */ {  14,   0,   0,   0, {  28,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs109_g1_s0_lives0_dlg1,
        [2] = s_gs109_g1_s0_lives0_dlg2,
    } },
};

static const struct GroundEventData s_gs109_g0_s0_evts[] = { /* 0x81f0ca8 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  1 */ {  57,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  2 */ {   1,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  3 */ {   1,  39,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f0cd8 */
    &s_gs109_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs109_g0_sectors[] = { /* 0x81f0cdc */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs109_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs109_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs109_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs109_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs109_g1_sectors[] = { /* 0x81f0da4 */
    { LPARRAY(s_gs109_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs109_groups[] = { /* 0x81f0dcc */
    { LPARRAY(s_gs109_g0_sectors) },
    { LPARRAY(s_gs109_g1_sectors) },
    {},
};

static const struct GroundLink s_gs109_links[] = { /* 0x81f0de4 */
    /* link   0 */ { { /*x*/  23, /*y*/  12, /*flags*/ 0, 0 }, /*w*/ 10, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
};

const GroundScriptHeader gGroundScript_gs109 = { LPARRAY(s_gs109_groups), s_gs109_links }; /* 0x81f0dec */
