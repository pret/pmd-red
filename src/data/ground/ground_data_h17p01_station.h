


















static const struct ScriptCommand s_gs144_g0_s0_station_sref_script[] = { /* 0x8204a7c */
    DEBUGINFO,
    SELECT_MAP(144),
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
    BGM_SWITCH(116),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs144_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs144_g0_s0_station_sref_script }; /* 0x8204cf8 */

static const struct ScriptCommand s_gs144_g0_s1_lives0_dlg0[] = { /* 0x8204d04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g0_s1_lives1_dlg0[] = { /* 0x8204d44 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g0_s3_lives0_dlg0[] = { /* 0x8204d84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g0_s3_lives1_dlg0[] = { /* 0x8204dc4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g0_s4_lives0_dlg0[] = { /* 0x8204e04 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g0_s4_lives1_dlg0[] = { /* 0x8204e34 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs144_g1_s0_lives0_dlg1[] = { /* 0x8204e64 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives0_dlg2[] = { /* 0x8204e94 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives1_dlg1[] = { /* 0x8204eb4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives1_dlg2[] = { /* 0x8204ee4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives2_dlg1[] = { /* 0x8204f04 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives2_dlg2[] = { /* 0x8204f34 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives3_dlg1[] = { /* 0x8204f54 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives3_dlg2[] = { /* 0x8204f84 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives4_dlg1[] = { /* 0x8204fa4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives4_dlg2[] = { /* 0x8204fd4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives5_dlg1[] = { /* 0x8204ff4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives5_dlg2[] = { /* 0x8205024 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives6_dlg1[] = { /* 0x8205044 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives6_dlg2[] = { /* 0x8205074 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives7_dlg1[] = { /* 0x8205094 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives7_dlg2[] = { /* 0x82050c4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives8_dlg1[] = { /* 0x82050e4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives8_dlg2[] = { /* 0x8205114 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives9_dlg1[] = { /* 0x8205134 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives9_dlg2[] = { /* 0x8205164 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs144_g1_s0_lives10_dlg1[] = { /* 0x8205184 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs144_g1_s0_lives10_dlg2[] = { /* 0x82051b4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs144_g0_s1_lives[] = { /* 0x82051d4 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs144_g0_s3_lives[] = { /* 0x8205204 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs144_g0_s4_lives[] = { /* 0x8205234 */
    /*  0 */ {   0,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs144_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs144_g1_s0_lives[] = { /* 0x8205264 */
    /*  0 */ {  14,   0,   0,   0, {  22,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives0_dlg1,
        [2] = s_gs144_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  35,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives1_dlg1,
        [2] = s_gs144_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  16,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives2_dlg1,
        [2] = s_gs144_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  41,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives3_dlg1,
        [2] = s_gs144_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  14,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives4_dlg1,
        [2] = s_gs144_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  43,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives5_dlg1,
        [2] = s_gs144_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {   8,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives6_dlg1,
        [2] = s_gs144_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  49,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives7_dlg1,
        [2] = s_gs144_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  29,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives8_dlg1,
        [2] = s_gs144_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  22,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives9_dlg1,
        [2] = s_gs144_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  35,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs144_g1_s0_lives10_dlg1,
        [2] = s_gs144_g1_s0_lives10_dlg2,
    } },
};

static const struct GroundEventData s_gs144_g0_s0_evts[] = { /* 0x820536c */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820539c */
    &s_gs144_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs144_g0_sectors[] = { /* 0x82053a0 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs144_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs144_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs144_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs144_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs144_g1_sectors[] = { /* 0x8205468 */
    { LPARRAY(s_gs144_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs144_groups[] = { /* 0x8205490 */
    { LPARRAY(s_gs144_g0_sectors) },
    { LPARRAY(s_gs144_g1_sectors) },
    {},
};

static const struct GroundLink s_gs144_links[] = { /* 0x82054a8 */
    /* link   0 */ { { /*x*/  32, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  20, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  26, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  46, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   5, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  40, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  11, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  38, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  13, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  32, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  19, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs144 = { LPARRAY(s_gs144_groups), s_gs144_links }; /* 0x8205500 */
