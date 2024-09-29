
















static const struct ScriptCommand s_gs113_g0_s0_station_sref_script[] = { /* 0x81f2784 */
    DEBUGINFO,
    SELECT_MAP(113),
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

static const struct ScriptRef s_gs113_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs113_g0_s0_station_sref_script }; /* 0x81f2a00 */

static const struct ScriptCommand s_gs113_g0_s1_lives0_dlg0[] = { /* 0x81f2a0c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g0_s1_lives1_dlg0[] = { /* 0x81f2a4c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g0_s3_lives0_dlg0[] = { /* 0x81f2a8c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g0_s3_lives1_dlg0[] = { /* 0x81f2acc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g0_s4_lives0_dlg0[] = { /* 0x81f2b0c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g0_s4_lives1_dlg0[] = { /* 0x81f2b3c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs113_g1_s0_lives0_dlg1[] = { /* 0x81f2b6c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives0_dlg2[] = { /* 0x81f2b9c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives1_dlg1[] = { /* 0x81f2bbc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives1_dlg2[] = { /* 0x81f2bec */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives2_dlg1[] = { /* 0x81f2c0c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives2_dlg2[] = { /* 0x81f2c3c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives3_dlg1[] = { /* 0x81f2c5c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives3_dlg2[] = { /* 0x81f2c8c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives4_dlg1[] = { /* 0x81f2cac */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives4_dlg2[] = { /* 0x81f2cdc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives5_dlg1[] = { /* 0x81f2cfc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives5_dlg2[] = { /* 0x81f2d2c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives6_dlg1[] = { /* 0x81f2d4c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives6_dlg2[] = { /* 0x81f2d7c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives7_dlg1[] = { /* 0x81f2d9c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives7_dlg2[] = { /* 0x81f2dcc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs113_g1_s0_lives8_dlg1[] = { /* 0x81f2dec */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs113_g1_s0_lives8_dlg2[] = { /* 0x81f2e1c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs113_g0_s1_lives[] = { /* 0x81f2e3c */
    /*  0 */ {   0,   4,   0,   0, {  12,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  12,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs113_g0_s3_lives[] = { /* 0x81f2e6c */
    /*  0 */ {   0,   4,   0,   0, {  12,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  12,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs113_g0_s4_lives[] = { /* 0x81f2e9c */
    /*  0 */ {   0,   0,   0,   0, {  12,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  12,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs113_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs113_g1_s0_lives[] = { /* 0x81f2ecc */
    /*  0 */ {  14,   0,   0,   0, {  12,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives0_dlg1,
        [2] = s_gs113_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  21,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives1_dlg1,
        [2] = s_gs113_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {   6,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives2_dlg1,
        [2] = s_gs113_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  30,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives3_dlg1,
        [2] = s_gs113_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  34,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives4_dlg1,
        [2] = s_gs113_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  40,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives5_dlg1,
        [2] = s_gs113_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  31,   8, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives6_dlg1,
        [2] = s_gs113_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  45,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives7_dlg1,
        [2] = s_gs113_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  50,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs113_g1_s0_lives8_dlg1,
        [2] = s_gs113_g1_s0_lives8_dlg2,
    } },
};

static const struct GroundEventData s_gs113_g0_s0_evts[] = { /* 0x81f2fa4 */
    /*  0 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f2fbc */
    &s_gs113_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs113_g0_sectors[] = { /* 0x81f2fc0 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs113_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs113_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs113_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs113_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs113_g1_sectors[] = { /* 0x81f3088 */
    { LPARRAY(s_gs113_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs113_groups[] = { /* 0x81f30b0 */
    { LPARRAY(s_gs113_g0_sectors) },
    { LPARRAY(s_gs113_g1_sectors) },
    {},
};

static const struct GroundLink s_gs113_links[] = { /* 0x81f30c8 */
    /* link   0 */ { { /*x*/  47, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  43, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  29, /*y*/   6, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  37, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  31, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  27, /*y*/  31, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/   3, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  18, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/   9, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs113 = { LPARRAY(s_gs113_groups), s_gs113_links }; /* 0x81f3110 */
