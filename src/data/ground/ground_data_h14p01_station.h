




















static const struct ScriptCommand s_gs141_g0_s0_station_sref_script[] = { /* 0x8202bb8 */
    DEBUGINFO,
    SELECT_MAP(141),
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

static const struct ScriptRef s_gs141_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs141_g0_s0_station_sref_script }; /* 0x8202e34 */

static const struct ScriptCommand s_gs141_g0_s1_lives0_dlg0[] = { /* 0x8202e40 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g0_s1_lives1_dlg0[] = { /* 0x8202e80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g0_s3_lives0_dlg0[] = { /* 0x8202ec0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g0_s3_lives1_dlg0[] = { /* 0x8202f00 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g0_s4_lives0_dlg0[] = { /* 0x8202f40 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g0_s4_lives1_dlg0[] = { /* 0x8202f70 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs141_g1_s0_lives0_dlg1[] = { /* 0x8202fa0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives0_dlg2[] = { /* 0x8202fd0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives1_dlg1[] = { /* 0x8202ff0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives1_dlg2[] = { /* 0x8203020 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives2_dlg1[] = { /* 0x8203040 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives2_dlg2[] = { /* 0x8203070 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives3_dlg1[] = { /* 0x8203090 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives3_dlg2[] = { /* 0x82030c0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives4_dlg1[] = { /* 0x82030e0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives4_dlg2[] = { /* 0x8203110 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives5_dlg1[] = { /* 0x8203130 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives5_dlg2[] = { /* 0x8203160 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives6_dlg1[] = { /* 0x8203180 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives6_dlg2[] = { /* 0x82031b0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives7_dlg1[] = { /* 0x82031d0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives7_dlg2[] = { /* 0x8203200 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives8_dlg1[] = { /* 0x8203220 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives8_dlg2[] = { /* 0x8203250 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives9_dlg1[] = { /* 0x8203270 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives9_dlg2[] = { /* 0x82032a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives10_dlg1[] = { /* 0x82032c0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives10_dlg2[] = { /* 0x82032f0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives11_dlg1[] = { /* 0x8203310 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives11_dlg2[] = { /* 0x8203340 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs141_g1_s0_lives12_dlg1[] = { /* 0x8203360 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs141_g1_s0_lives12_dlg2[] = { /* 0x8203390 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs141_g0_s1_lives[] = { /* 0x82033b0 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs141_g0_s3_lives[] = { /* 0x82033e0 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs141_g0_s4_lives[] = { /* 0x8203410 */
    /*  0 */ {   0,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs141_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs141_g1_s0_lives[] = { /* 0x8203440 */
    /*  0 */ {  14,   0,   0,   0, {  29,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives0_dlg1,
        [2] = s_gs141_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  23,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives1_dlg1,
        [2] = s_gs141_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  35,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives2_dlg1,
        [2] = s_gs141_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  23,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives3_dlg1,
        [2] = s_gs141_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  35,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives4_dlg1,
        [2] = s_gs141_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  29,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives5_dlg1,
        [2] = s_gs141_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  13,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives6_dlg1,
        [2] = s_gs141_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  43,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives7_dlg1,
        [2] = s_gs141_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {   9,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives8_dlg1,
        [2] = s_gs141_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  47,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives9_dlg1,
        [2] = s_gs141_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {   7,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives10_dlg1,
        [2] = s_gs141_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  51,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives11_dlg1,
        [2] = s_gs141_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {   9,   8, 0, CPOS_HALFTILE }, {
        [1] = s_gs141_g1_s0_lives12_dlg1,
        [2] = s_gs141_g1_s0_lives12_dlg2,
    } },
};

static const struct GroundEventData s_gs141_g0_s0_evts[] = { /* 0x8203578 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82035a8 */
    &s_gs141_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs141_g0_sectors[] = { /* 0x82035ac */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs141_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs141_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs141_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs141_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs141_g1_sectors[] = { /* 0x8203674 */
    { LPARRAY(s_gs141_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs141_groups[] = { /* 0x820369c */
    { LPARRAY(s_gs141_g0_sectors) },
    { LPARRAY(s_gs141_g1_sectors) },
    {},
};

static const struct GroundLink s_gs141_links[] = { /* 0x82036b4 */
    /* link   0 */ { { /*x*/   6, /*y*/   6, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  47, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/   4, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  44, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   6, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  40, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  10, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  26, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  32, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  20, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  32, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  20, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  26, /*y*/  25, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs141 = { LPARRAY(s_gs141_groups), s_gs141_links }; /* 0x820371c */
