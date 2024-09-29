





















static const struct ScriptCommand s_gs149_g0_s0_station_sref_script[] = { /* 0x8207b6c */
    DEBUGINFO,
    SELECT_MAP(149),
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
    BGM_SWITCH(3),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs149_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs149_g0_s0_station_sref_script }; /* 0x8207de8 */

static const struct ScriptCommand s_gs149_g0_s1_lives0_dlg0[] = { /* 0x8207df4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g0_s1_lives1_dlg0[] = { /* 0x8207e34 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g0_s3_lives0_dlg0[] = { /* 0x8207e74 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g0_s3_lives1_dlg0[] = { /* 0x8207eb4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g0_s4_lives0_dlg0[] = { /* 0x8207ef4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g0_s4_lives1_dlg0[] = { /* 0x8207f24 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs149_g1_s0_lives0_dlg1[] = { /* 0x8207f54 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives0_dlg2[] = { /* 0x8207f84 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives1_dlg1[] = { /* 0x8207fa4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives1_dlg2[] = { /* 0x8207fd4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives2_dlg1[] = { /* 0x8207ff4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives2_dlg2[] = { /* 0x8208024 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives3_dlg1[] = { /* 0x8208044 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives3_dlg2[] = { /* 0x8208074 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives4_dlg1[] = { /* 0x8208094 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives4_dlg2[] = { /* 0x82080c4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives5_dlg1[] = { /* 0x82080e4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives5_dlg2[] = { /* 0x8208114 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives6_dlg1[] = { /* 0x8208134 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives6_dlg2[] = { /* 0x8208164 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives7_dlg1[] = { /* 0x8208184 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives7_dlg2[] = { /* 0x82081b4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives8_dlg1[] = { /* 0x82081d4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives8_dlg2[] = { /* 0x8208204 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives9_dlg1[] = { /* 0x8208224 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives9_dlg2[] = { /* 0x8208254 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives10_dlg1[] = { /* 0x8208274 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives10_dlg2[] = { /* 0x82082a4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives11_dlg1[] = { /* 0x82082c4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives11_dlg2[] = { /* 0x82082f4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives12_dlg1[] = { /* 0x8208314 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives12_dlg2[] = { /* 0x8208344 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs149_g1_s0_lives13_dlg1[] = { /* 0x8208364 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs149_g1_s0_lives13_dlg2[] = { /* 0x8208394 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs149_g0_s1_lives[] = { /* 0x82083b4 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs149_g0_s3_lives[] = { /* 0x82083e4 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs149_g0_s4_lives[] = { /* 0x8208414 */
    /*  0 */ {   0,   0,   0,   0, {  30,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs149_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs149_g1_s0_lives[] = { /* 0x8208444 */
    /*  0 */ {  14,   0,   0,   0, {  30,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives0_dlg1,
        [2] = s_gs149_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  24,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives1_dlg1,
        [2] = s_gs149_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  36,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives2_dlg1,
        [2] = s_gs149_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  19,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives3_dlg1,
        [2] = s_gs149_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  41,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives4_dlg1,
        [2] = s_gs149_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  30,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives5_dlg1,
        [2] = s_gs149_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  19,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives6_dlg1,
        [2] = s_gs149_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  41,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives7_dlg1,
        [2] = s_gs149_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  21,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives8_dlg1,
        [2] = s_gs149_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  38,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives9_dlg1,
        [2] = s_gs149_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  13,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives10_dlg1,
        [2] = s_gs149_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  47,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives11_dlg1,
        [2] = s_gs149_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {   7,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives12_dlg1,
        [2] = s_gs149_g1_s0_lives12_dlg2,
    } },
    /* 13 */ {  27,   0,   0,   0, {  52,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs149_g1_s0_lives13_dlg1,
        [2] = s_gs149_g1_s0_lives13_dlg2,
    } },
};

static const struct GroundEventData s_gs149_g0_s0_evts[] = { /* 0x8208594 */
    /*  0 */ {  60,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82085ac */
    &s_gs149_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs149_g0_sectors[] = { /* 0x82085b0 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs149_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs149_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs149_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs149_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs149_g1_sectors[] = { /* 0x8208678 */
    { LPARRAY(s_gs149_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs149_groups[] = { /* 0x82086a0 */
    { LPARRAY(s_gs149_g0_sectors) },
    { LPARRAY(s_gs149_g1_sectors) },
    {},
};

static const struct GroundLink s_gs149_links[] = { /* 0x82086b8 */
    /* link   0 */ { { /*x*/  50, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/   4, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  44, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  10, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  35, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  18, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  37, /*y*/   8, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  17, /*y*/   8, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  27, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  39, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  15, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  33, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  21, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  13 */ { { /*x*/  27, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs149 = { LPARRAY(s_gs149_groups), s_gs149_links }; /* 0x8208728 */
