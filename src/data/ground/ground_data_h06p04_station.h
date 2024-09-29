






















static const struct ScriptCommand s_gs119_g0_s0_station_sref_script[] = { /* 0x81f6198 */
    DEBUGINFO,
    SELECT_MAP(119),
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
    BGM_SWITCH(105),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs119_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs119_g0_s0_station_sref_script }; /* 0x81f6414 */

static const struct ScriptCommand s_gs119_g0_s1_lives0_dlg0[] = { /* 0x81f6420 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g0_s1_lives1_dlg0[] = { /* 0x81f6460 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g0_s3_lives0_dlg0[] = { /* 0x81f64a0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g0_s3_lives1_dlg0[] = { /* 0x81f64e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g0_s4_lives0_dlg0[] = { /* 0x81f6520 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g0_s4_lives1_dlg0[] = { /* 0x81f6550 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs119_g1_s0_lives0_dlg1[] = { /* 0x81f6580 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives0_dlg2[] = { /* 0x81f65b0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives1_dlg1[] = { /* 0x81f65d0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives1_dlg2[] = { /* 0x81f6600 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives2_dlg1[] = { /* 0x81f6620 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives2_dlg2[] = { /* 0x81f6650 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives3_dlg1[] = { /* 0x81f6670 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives3_dlg2[] = { /* 0x81f66a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives4_dlg1[] = { /* 0x81f66c0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives4_dlg2[] = { /* 0x81f66f0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives5_dlg1[] = { /* 0x81f6710 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives5_dlg2[] = { /* 0x81f6740 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives6_dlg1[] = { /* 0x81f6760 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives6_dlg2[] = { /* 0x81f6790 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives7_dlg1[] = { /* 0x81f67b0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives7_dlg2[] = { /* 0x81f67e0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives8_dlg1[] = { /* 0x81f6800 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives8_dlg2[] = { /* 0x81f6830 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives9_dlg1[] = { /* 0x81f6850 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives9_dlg2[] = { /* 0x81f6880 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives10_dlg1[] = { /* 0x81f68a0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives10_dlg2[] = { /* 0x81f68d0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives11_dlg1[] = { /* 0x81f68f0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives11_dlg2[] = { /* 0x81f6920 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives12_dlg1[] = { /* 0x81f6940 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives12_dlg2[] = { /* 0x81f6970 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives13_dlg1[] = { /* 0x81f6990 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives13_dlg2[] = { /* 0x81f69c0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs119_g1_s0_lives14_dlg1[] = { /* 0x81f69e0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs119_g1_s0_lives14_dlg2[] = { /* 0x81f6a10 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs119_g0_s1_lives[] = { /* 0x81f6a30 */
    /*  0 */ {   0,   4,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs119_g0_s3_lives[] = { /* 0x81f6a60 */
    /*  0 */ {   0,   4,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs119_g0_s4_lives[] = { /* 0x81f6a90 */
    /*  0 */ {   0,   0,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs119_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs119_g1_s0_lives[] = { /* 0x81f6ac0 */
    /*  0 */ {  14,   0,   0,   0, {  29,  27, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives0_dlg1,
        [2] = s_gs119_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  18,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives1_dlg1,
        [2] = s_gs119_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  38,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives2_dlg1,
        [2] = s_gs119_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  15,  35, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives3_dlg1,
        [2] = s_gs119_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  41,  34, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives4_dlg1,
        [2] = s_gs119_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  10,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives5_dlg1,
        [2] = s_gs119_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  48,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives6_dlg1,
        [2] = s_gs119_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  20,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives7_dlg1,
        [2] = s_gs119_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  37,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives8_dlg1,
        [2] = s_gs119_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  29,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives9_dlg1,
        [2] = s_gs119_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  43,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives10_dlg1,
        [2] = s_gs119_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  11,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives11_dlg1,
        [2] = s_gs119_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {  29,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives12_dlg1,
        [2] = s_gs119_g1_s0_lives12_dlg2,
    } },
    /* 13 */ {  27,   0,   0,   0, {  20,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives13_dlg1,
        [2] = s_gs119_g1_s0_lives13_dlg2,
    } },
    /* 14 */ {  28,   0,   0,   0, {  39,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs119_g1_s0_lives14_dlg1,
        [2] = s_gs119_g1_s0_lives14_dlg2,
    } },
};

static const struct GroundEventData s_gs119_g0_s0_evts[] = { /* 0x81f6c28 */
    /*  0 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  40, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  59,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f6c58 */
    &s_gs119_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs119_g0_sectors[] = { /* 0x81f6c5c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs119_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs119_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs119_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs119_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs119_g1_sectors[] = { /* 0x81f6d24 */
    { LPARRAY(s_gs119_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs119_groups[] = { /* 0x81f6d4c */
    { LPARRAY(s_gs119_g0_sectors) },
    { LPARRAY(s_gs119_g1_sectors) },
    {},
};

static const struct GroundLink s_gs119_links[] = { /* 0x81f6d64 */
    /* link   0 */ { { /*x*/  36, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  26, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  17, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  40, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   8, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  26, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  34, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  18, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  44, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/   7, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  38, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  13, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  35, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  13 */ { { /*x*/  16, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  14 */ { { /*x*/  26, /*y*/  25, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs119 = { LPARRAY(s_gs119_groups), s_gs119_links }; /* 0x81f6ddc */
