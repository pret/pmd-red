














static const struct ScriptCommand s_gs135_g0_s0_station_sref_script[] = { /* 0x81ffab0 */
    DEBUGINFO,
    SELECT_MAP(135),
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
    BGM_SWITCH(2),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs135_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs135_g0_s0_station_sref_script }; /* 0x81ffd2c */

static const struct ScriptCommand s_gs135_g0_s1_lives0_dlg0[] = { /* 0x81ffd38 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g0_s1_lives1_dlg0[] = { /* 0x81ffd78 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g0_s3_lives0_dlg0[] = { /* 0x81ffdb8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g0_s3_lives1_dlg0[] = { /* 0x81ffdf8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g0_s4_lives0_dlg0[] = { /* 0x81ffe38 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g0_s4_lives1_dlg0[] = { /* 0x81ffe68 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs135_g1_s0_lives0_dlg1[] = { /* 0x81ffe98 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives0_dlg2[] = { /* 0x81ffec8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives1_dlg1[] = { /* 0x81ffee8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives1_dlg2[] = { /* 0x81fff18 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives2_dlg1[] = { /* 0x81fff38 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives2_dlg2[] = { /* 0x81fff68 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives3_dlg1[] = { /* 0x81fff88 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives3_dlg2[] = { /* 0x81fffb8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives4_dlg1[] = { /* 0x81fffd8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives4_dlg2[] = { /* 0x8200008 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives5_dlg1[] = { /* 0x8200028 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives5_dlg2[] = { /* 0x8200058 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs135_g1_s0_lives6_dlg1[] = { /* 0x8200078 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs135_g1_s0_lives6_dlg2[] = { /* 0x82000a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs135_g0_s1_lives[] = { /* 0x82000c8 */
    /*  0 */ {   0,   4,   0,   0, {   8,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {   3,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs135_g0_s3_lives[] = { /* 0x82000f8 */
    /*  0 */ {   0,   4,   0,   0, {   8,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {   3,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs135_g0_s4_lives[] = { /* 0x8200128 */
    /*  0 */ {   0,   0,   0,   0, {   8,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {   3,   6, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs135_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs135_g1_s0_lives[] = { /* 0x8200158 */
    /*  0 */ {  14,   0,   0,   0, {  15,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives0_dlg1,
        [2] = s_gs135_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  24,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives1_dlg1,
        [2] = s_gs135_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  16,  34, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives2_dlg1,
        [2] = s_gs135_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  34,  27, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives3_dlg1,
        [2] = s_gs135_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  50,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives4_dlg1,
        [2] = s_gs135_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  55,   4, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives5_dlg1,
        [2] = s_gs135_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  61,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs135_g1_s0_lives6_dlg1,
        [2] = s_gs135_g1_s0_lives6_dlg2,
    } },
};

static const struct GroundEventData s_gs135_g0_s0_evts[] = { /* 0x8200200 */
    /*  0 */ {  66,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  66,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  65,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8200230 */
    &s_gs135_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs135_g0_sectors[] = { /* 0x8200234 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs135_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs135_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs135_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs135_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs135_g1_sectors[] = { /* 0x82002fc */
    { LPARRAY(s_gs135_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs135_groups[] = { /* 0x8200324 */
    { LPARRAY(s_gs135_g0_sectors) },
    { LPARRAY(s_gs135_g1_sectors) },
    {},
};

static const struct GroundLink s_gs135_links[] = { /* 0x820033c */
    /* link   0 */ { { /*x*/  58, /*y*/  31, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  52, /*y*/   2, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  47, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  31, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  13, /*y*/  32, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  21, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  12, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs135 = { LPARRAY(s_gs135_groups), s_gs135_links }; /* 0x8200374 */
