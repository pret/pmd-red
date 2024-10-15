

















static const struct ScriptCommand s_gs120_g0_s0_station_sref_script[] = { /* 0x81f6df0 */
    DEBUGINFO,
    SELECT_MAP(120),
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
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
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
    BGM_SWITCH(107),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs120_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs120_g0_s0_station_sref_script }; /* 0x81f706c */

static const struct ScriptCommand s_gs120_g0_s1_lives0_dlg0[] = { /* 0x81f7078 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g0_s1_lives1_dlg0[] = { /* 0x81f70b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g0_s3_lives0_dlg0[] = { /* 0x81f70f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g0_s3_lives1_dlg0[] = { /* 0x81f7138 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g0_s4_lives0_dlg0[] = { /* 0x81f7178 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g0_s4_lives1_dlg0[] = { /* 0x81f71a8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs120_g1_s0_lives0_dlg1[] = { /* 0x81f71d8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives0_dlg2[] = { /* 0x81f7208 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives1_dlg1[] = { /* 0x81f7228 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives1_dlg2[] = { /* 0x81f7258 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives2_dlg1[] = { /* 0x81f7278 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives2_dlg2[] = { /* 0x81f72a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives3_dlg1[] = { /* 0x81f72c8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives3_dlg2[] = { /* 0x81f72f8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives4_dlg1[] = { /* 0x81f7318 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives4_dlg2[] = { /* 0x81f7348 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives5_dlg1[] = { /* 0x81f7368 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives5_dlg2[] = { /* 0x81f7398 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives6_dlg1[] = { /* 0x81f73b8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives6_dlg2[] = { /* 0x81f73e8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives7_dlg1[] = { /* 0x81f7408 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives7_dlg2[] = { /* 0x81f7438 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives8_dlg1[] = { /* 0x81f7458 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives8_dlg2[] = { /* 0x81f7488 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs120_g1_s0_lives9_dlg1[] = { /* 0x81f74a8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs120_g1_s0_lives9_dlg2[] = { /* 0x81f74d8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs120_g0_s1_lives[] = { /* 0x81f74f8 */
    /*  0 */ {   0,   4,   0,   0, {  28,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs120_g0_s3_lives[] = { /* 0x81f7528 */
    /*  0 */ {   0,   4,   0,   0, {  28,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs120_g0_s4_lives[] = { /* 0x81f7558 */
    /*  0 */ {   0,   0,   0,   0, {  28,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs120_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs120_g1_s0_lives[] = { /* 0x81f7588 */
    /*  0 */ {  14,   0,   0,   0, {  28,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives0_dlg1,
        [2] = s_gs120_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  19,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives1_dlg1,
        [2] = s_gs120_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  37,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives2_dlg1,
        [2] = s_gs120_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  13,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives3_dlg1,
        [2] = s_gs120_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  43,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives4_dlg1,
        [2] = s_gs120_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  18,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives5_dlg1,
        [2] = s_gs120_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  36,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives6_dlg1,
        [2] = s_gs120_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  11,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives7_dlg1,
        [2] = s_gs120_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  45,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives8_dlg1,
        [2] = s_gs120_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  28,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs120_g1_s0_lives9_dlg1,
        [2] = s_gs120_g1_s0_lives9_dlg2,
    } },
};

static const struct GroundEventData s_gs120_g0_s0_evts[] = { /* 0x81f7678 */
    /*  0 */ {  57,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  39, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  42,   0,   0, {  54,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f76a8 */
    &s_gs120_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs120_g0_sectors[] = { /* 0x81f76ac */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs120_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs120_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs120_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs120_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs120_g1_sectors[] = { /* 0x81f7774 */
    { LPARRAY(s_gs120_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs120_groups[] = { /* 0x81f779c */
    { LPARRAY(s_gs120_g0_sectors) },
    { LPARRAY(s_gs120_g1_sectors) },
    {},
};

static const struct GroundLink s_gs120_links[] = { /* 0x81f77b4 */
    /* link   0 */ { { /*x*/  25, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  16, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  34, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  10, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  40, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  16, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  34, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/   8, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  42, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  25, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs120 = { LPARRAY(s_gs120_groups), s_gs120_links }; /* 0x81f7804 */
