
















static const struct ScriptCommand s_gs124_g0_s0_station_sref_script[] = { /* 0x81f9608 */
    DEBUGINFO,
    SELECT_MAP(124),
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
    BGM_SWITCH(121),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs124_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs124_g0_s0_station_sref_script }; /* 0x81f9884 */

static const struct ScriptCommand s_gs124_g0_s1_lives0_dlg0[] = { /* 0x81f9890 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g0_s1_lives1_dlg0[] = { /* 0x81f98d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g0_s3_lives0_dlg0[] = { /* 0x81f9910 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g0_s3_lives1_dlg0[] = { /* 0x81f9950 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g0_s4_lives0_dlg0[] = { /* 0x81f9990 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g0_s4_lives1_dlg0[] = { /* 0x81f99c0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs124_g1_s0_lives0_dlg1[] = { /* 0x81f99f0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives0_dlg2[] = { /* 0x81f9a20 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives1_dlg1[] = { /* 0x81f9a40 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives1_dlg2[] = { /* 0x81f9a70 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives2_dlg1[] = { /* 0x81f9a90 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives2_dlg2[] = { /* 0x81f9ac0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives3_dlg1[] = { /* 0x81f9ae0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives3_dlg2[] = { /* 0x81f9b10 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives4_dlg1[] = { /* 0x81f9b30 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives4_dlg2[] = { /* 0x81f9b60 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives5_dlg1[] = { /* 0x81f9b80 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives5_dlg2[] = { /* 0x81f9bb0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives6_dlg1[] = { /* 0x81f9bd0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives6_dlg2[] = { /* 0x81f9c00 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives7_dlg1[] = { /* 0x81f9c20 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives7_dlg2[] = { /* 0x81f9c50 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs124_g1_s0_lives8_dlg1[] = { /* 0x81f9c70 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs124_g1_s0_lives8_dlg2[] = { /* 0x81f9ca0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs124_g0_s1_lives[] = { /* 0x81f9cc0 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs124_g0_s3_lives[] = { /* 0x81f9cf0 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs124_g0_s4_lives[] = { /* 0x81f9d20 */
    /*  0 */ {   0,   0,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs124_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs124_g1_s0_lives[] = { /* 0x81f9d50 */
    /*  0 */ {  14,   0,   0,   0, {  27,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives0_dlg1,
        [2] = s_gs124_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  33,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives1_dlg1,
        [2] = s_gs124_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  22,  32, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives2_dlg1,
        [2] = s_gs124_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  38,  32, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives3_dlg1,
        [2] = s_gs124_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  18,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives4_dlg1,
        [2] = s_gs124_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  42,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives5_dlg1,
        [2] = s_gs124_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  24,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives6_dlg1,
        [2] = s_gs124_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  36,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives7_dlg1,
        [2] = s_gs124_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  30,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs124_g1_s0_lives8_dlg1,
        [2] = s_gs124_g1_s0_lives8_dlg2,
    } },
};

static const struct GroundEventData s_gs124_g0_s0_evts[] = { /* 0x81f9e28 */
    /*  0 */ {  60,   1,   0,   0, {   1,  38, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f9e34 */
    &s_gs124_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs124_g0_sectors[] = { /* 0x81f9e38 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs124_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs124_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs124_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs124_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs124_g1_sectors[] = { /* 0x81f9f00 */
    { LPARRAY(s_gs124_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs124_groups[] = { /* 0x81f9f28 */
    { LPARRAY(s_gs124_g0_sectors) },
    { LPARRAY(s_gs124_g1_sectors) },
    {},
};

static const struct GroundLink s_gs124_links[] = { /* 0x81f9f40 */
    /* link   0 */ { { /*x*/  27, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  33, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  21, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  39, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  15, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  35, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  19, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  30, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  24, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs124 = { LPARRAY(s_gs124_groups), s_gs124_links }; /* 0x81f9f88 */
