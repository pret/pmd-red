


















static const struct ScriptCommand s_gs143_g0_s0_station_sref_script[] = { /* 0x8203fe4 */
    DEBUGINFO,
    SELECT_MAP(143),
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

static const struct ScriptRef s_gs143_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs143_g0_s0_station_sref_script }; /* 0x8204260 */

static const struct ScriptCommand s_gs143_g0_s1_lives0_dlg0[] = { /* 0x820426c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g0_s1_lives1_dlg0[] = { /* 0x82042ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g0_s3_lives0_dlg0[] = { /* 0x82042ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g0_s3_lives1_dlg0[] = { /* 0x820432c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g0_s4_lives0_dlg0[] = { /* 0x820436c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g0_s4_lives1_dlg0[] = { /* 0x820439c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs143_g1_s0_lives0_dlg1[] = { /* 0x82043cc */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives0_dlg2[] = { /* 0x82043fc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives1_dlg1[] = { /* 0x820441c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives1_dlg2[] = { /* 0x820444c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives2_dlg1[] = { /* 0x820446c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives2_dlg2[] = { /* 0x820449c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives3_dlg1[] = { /* 0x82044bc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives3_dlg2[] = { /* 0x82044ec */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives4_dlg1[] = { /* 0x820450c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives4_dlg2[] = { /* 0x820453c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives5_dlg1[] = { /* 0x820455c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives5_dlg2[] = { /* 0x820458c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives6_dlg1[] = { /* 0x82045ac */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives6_dlg2[] = { /* 0x82045dc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives7_dlg1[] = { /* 0x82045fc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives7_dlg2[] = { /* 0x820462c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives8_dlg1[] = { /* 0x820464c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives8_dlg2[] = { /* 0x820467c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives9_dlg1[] = { /* 0x820469c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives9_dlg2[] = { /* 0x82046cc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs143_g1_s0_lives10_dlg1[] = { /* 0x82046ec */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs143_g1_s0_lives10_dlg2[] = { /* 0x820471c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs143_g0_s1_lives[] = { /* 0x820473c */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs143_g0_s3_lives[] = { /* 0x820476c */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs143_g0_s4_lives[] = { /* 0x820479c */
    /*  0 */ {   0,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs143_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs143_g1_s0_lives[] = { /* 0x82047cc */
    /*  0 */ {  14,   0,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives0_dlg1,
        [2] = s_gs143_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  24,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives1_dlg1,
        [2] = s_gs143_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  36,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives2_dlg1,
        [2] = s_gs143_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  26,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives3_dlg1,
        [2] = s_gs143_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  33,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives4_dlg1,
        [2] = s_gs143_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  20,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives5_dlg1,
        [2] = s_gs143_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  39,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives6_dlg1,
        [2] = s_gs143_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  25,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives7_dlg1,
        [2] = s_gs143_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  32,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives8_dlg1,
        [2] = s_gs143_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  20,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives9_dlg1,
        [2] = s_gs143_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  38,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs143_g1_s0_lives10_dlg1,
        [2] = s_gs143_g1_s0_lives10_dlg2,
    } },
};

static const struct GroundEventData s_gs143_g0_s0_evts[] = { /* 0x82048d4 */
    /*  0 */ {  60,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  42,   0,   0, {  57,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8204904 */
    &s_gs143_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs143_g0_sectors[] = { /* 0x8204908 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs143_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs143_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs143_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs143_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs143_g1_sectors[] = { /* 0x82049d0 */
    { LPARRAY(s_gs143_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs143_groups[] = { /* 0x82049f8 */
    { LPARRAY(s_gs143_g0_sectors) },
    { LPARRAY(s_gs143_g1_sectors) },
    {},
};

static const struct GroundLink s_gs143_links[] = { /* 0x8204a10 */
    /* link   0 */ { { /*x*/  36, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  17, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  30, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  23, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  36, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  17, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  30, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  23, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  33, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  21, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  27, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs143 = { LPARRAY(s_gs143_groups), s_gs143_links }; /* 0x8204a68 */
