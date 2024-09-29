

















static const struct ScriptCommand s_gs106_g0_s0_station_sref_script[] = { /* 0x81eeb10 */
    DEBUGINFO,
    SELECT_MAP(106),
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
    BGM_SWITCH(106),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs106_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs106_g0_s0_station_sref_script }; /* 0x81eed8c */

static const struct ScriptCommand s_gs106_g0_s1_lives0_dlg0[] = { /* 0x81eed98 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g0_s1_lives1_dlg0[] = { /* 0x81eedd8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g0_s3_lives0_dlg0[] = { /* 0x81eee18 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g0_s3_lives1_dlg0[] = { /* 0x81eee58 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g0_s4_lives0_dlg0[] = { /* 0x81eee98 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g0_s4_lives1_dlg0[] = { /* 0x81eeec8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs106_g1_s0_lives0_dlg1[] = { /* 0x81eeef8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives0_dlg2[] = { /* 0x81eef28 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives1_dlg1[] = { /* 0x81eef48 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives1_dlg2[] = { /* 0x81eef78 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives2_dlg1[] = { /* 0x81eef98 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives2_dlg2[] = { /* 0x81eefc8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives3_dlg1[] = { /* 0x81eefe8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives3_dlg2[] = { /* 0x81ef018 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives4_dlg1[] = { /* 0x81ef038 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives4_dlg2[] = { /* 0x81ef068 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives5_dlg1[] = { /* 0x81ef088 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives5_dlg2[] = { /* 0x81ef0b8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives6_dlg1[] = { /* 0x81ef0d8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives6_dlg2[] = { /* 0x81ef108 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives7_dlg1[] = { /* 0x81ef128 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives7_dlg2[] = { /* 0x81ef158 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives8_dlg1[] = { /* 0x81ef178 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives8_dlg2[] = { /* 0x81ef1a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs106_g1_s0_lives9_dlg1[] = { /* 0x81ef1c8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs106_g1_s0_lives9_dlg2[] = { /* 0x81ef1f8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs106_g0_s1_lives[] = { /* 0x81ef218 */
    /*  0 */ {   0,   4,   0,   0, {  36,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  36,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs106_g0_s3_lives[] = { /* 0x81ef248 */
    /*  0 */ {   0,   4,   0,   0, {  36,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  36,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs106_g0_s4_lives[] = { /* 0x81ef278 */
    /*  0 */ {   0,   0,   0,   0, {  36,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  36,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs106_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs106_g1_s0_lives[] = { /* 0x81ef2a8 */
    /*  0 */ {  14,   0,   0,   0, {  36,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives0_dlg1,
        [2] = s_gs106_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  45,  27, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives1_dlg1,
        [2] = s_gs106_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  28,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives2_dlg1,
        [2] = s_gs106_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  52,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives3_dlg1,
        [2] = s_gs106_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  20,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives4_dlg1,
        [2] = s_gs106_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  46,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives5_dlg1,
        [2] = s_gs106_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  12,  32, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives6_dlg1,
        [2] = s_gs106_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  40,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives7_dlg1,
        [2] = s_gs106_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  35,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives8_dlg1,
        [2] = s_gs106_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  24,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs106_g1_s0_lives9_dlg1,
        [2] = s_gs106_g1_s0_lives9_dlg2,
    } },
};

static const struct GroundEventData s_gs106_g0_s0_evts[] = { /* 0x81ef398 */
    /*  0 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {  60,   1,   0,   0, {   1,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  59,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81ef3c8 */
    &s_gs106_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs106_g0_sectors[] = { /* 0x81ef3cc */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs106_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs106_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs106_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs106_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs106_g1_sectors[] = { /* 0x81ef494 */
    { LPARRAY(s_gs106_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs106_groups[] = { /* 0x81ef4bc */
    { LPARRAY(s_gs106_g0_sectors) },
    { LPARRAY(s_gs106_g1_sectors) },
    {},
};

static const struct GroundLink s_gs106_links[] = { /* 0x81ef4d4 */
    /* link   0 */ { { /*x*/  33, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  42, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  25, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  49, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  17, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  37, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  21, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  32, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/   9, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  43, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs106 = { LPARRAY(s_gs106_groups), s_gs106_links }; /* 0x81ef524 */
