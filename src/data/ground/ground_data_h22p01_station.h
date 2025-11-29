













static const struct ScriptCommand s_gs150_g0_s0_station_sref_script[] = { /* 0x820873c */
    DEBUGINFO_O(16),
    SELECT_MAP(150),
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
    BGM_SWITCH(MUS_FRIEND_AREA_CAVES),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs150_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs150_g0_s0_station_sref_script }; /* 0x82089b8 */

static const struct ScriptCommand s_gs150_g0_s1_lives0_dlg0[] = { /* 0x82089c4 */
    DEBUGINFO_O(58),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g0_s1_lives1_dlg0[] = { /* 0x8208a04 */
    DEBUGINFO_O(65),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g0_s3_lives0_dlg0[] = { /* 0x8208a44 */
    DEBUGINFO_O(72),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g0_s3_lives1_dlg0[] = { /* 0x8208a84 */
    DEBUGINFO_O(79),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g0_s4_lives0_dlg0[] = { /* 0x8208ac4 */
    DEBUGINFO_O(86),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g0_s4_lives1_dlg0[] = { /* 0x8208af4 */
    DEBUGINFO_O(92),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs150_g1_s0_lives0_dlg1[] = { /* 0x8208b24 */
    DEBUGINFO_O(98),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives0_dlg2[] = { /* 0x8208b54 */
    DEBUGINFO_O(104),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs150_g1_s0_lives1_dlg1[] = { /* 0x8208b74 */
    DEBUGINFO_O(109),
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives1_dlg2[] = { /* 0x8208ba4 */
    DEBUGINFO_O(115),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs150_g1_s0_lives2_dlg1[] = { /* 0x8208bc4 */
    DEBUGINFO_O(120),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives2_dlg2[] = { /* 0x8208bf4 */
    DEBUGINFO_O(126),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs150_g1_s0_lives3_dlg1[] = { /* 0x8208c14 */
    DEBUGINFO_O(131),
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives3_dlg2[] = { /* 0x8208c44 */
    DEBUGINFO_O(137),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs150_g1_s0_lives4_dlg1[] = { /* 0x8208c64 */
    DEBUGINFO_O(142),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives4_dlg2[] = { /* 0x8208c94 */
    DEBUGINFO_O(148),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs150_g1_s0_lives5_dlg1[] = { /* 0x8208cb4 */
    DEBUGINFO_O(153),
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs150_g1_s0_lives5_dlg2[] = { /* 0x8208ce4 */
    DEBUGINFO_O(159),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs150_g0_s1_lives[] = { /* 0x8208d04 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs150_g0_s3_lives[] = { /* 0x8208d34 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs150_g0_s4_lives[] = { /* 0x8208d64 */
    /*  0 */ {   0,   0,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs150_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs150_g1_s0_lives[] = { /* 0x8208d94 */
    /*  0 */ {  14,   0,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives0_dlg1,
        [2] = s_gs150_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {   9,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives1_dlg1,
        [2] = s_gs150_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  49,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives2_dlg1,
        [2] = s_gs150_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {   9,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives3_dlg1,
        [2] = s_gs150_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  51,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives4_dlg1,
        [2] = s_gs150_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  30,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs150_g1_s0_lives5_dlg1,
        [2] = s_gs150_g1_s0_lives5_dlg2,
    } },
};

static const struct GroundEventData s_gs150_g0_s0_evts[] = { /* 0x8208e24 */
    /*  0 */ {  60,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  1 */ {  60,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  2 */ {   3,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  3 */ {   3,  39,   0,   0, {  57,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8208e54 */
    &s_gs150_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs150_g0_sectors[] = { /* 0x8208e58 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs150_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs150_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs150_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs150_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs150_g1_sectors[] = { /* 0x8208f20 */
    { LPARRAY(s_gs150_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs150_groups[] = { /* 0x8208f48 */
    { LPARRAY(s_gs150_g0_sectors) },
    { LPARRAY(s_gs150_g1_sectors) },
    {},
};

static const struct GroundLink s_gs150_links[] = { /* 0x8208f60 */
    /* link   0 */ { { /*x*/  27, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  48, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/   6, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  47, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   7, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  27, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

const GroundScriptHeader gGroundScript_gs150 = { LPARRAY(s_gs150_groups), s_gs150_links }; /* 0x8208f90 */
