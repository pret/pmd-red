























static const struct ScriptCommand s_gs125_g0_s0_station_sref_script[] = { /* 0x81f9f9c */
    DEBUGINFO,
    SELECT_MAP(125),
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

static const struct ScriptRef s_gs125_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs125_g0_s0_station_sref_script }; /* 0x81fa218 */

static const struct ScriptCommand s_gs125_g0_s1_lives0_dlg0[] = { /* 0x81fa224 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g0_s1_lives1_dlg0[] = { /* 0x81fa264 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g0_s3_lives0_dlg0[] = { /* 0x81fa2a4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g0_s3_lives1_dlg0[] = { /* 0x81fa2e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g0_s4_lives0_dlg0[] = { /* 0x81fa324 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g0_s4_lives1_dlg0[] = { /* 0x81fa354 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs125_g1_s0_lives0_dlg1[] = { /* 0x81fa384 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives0_dlg2[] = { /* 0x81fa3b4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives1_dlg1[] = { /* 0x81fa3d4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives1_dlg2[] = { /* 0x81fa404 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives2_dlg1[] = { /* 0x81fa424 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives2_dlg2[] = { /* 0x81fa454 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives3_dlg1[] = { /* 0x81fa474 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives3_dlg2[] = { /* 0x81fa4a4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives4_dlg1[] = { /* 0x81fa4c4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives4_dlg2[] = { /* 0x81fa4f4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives5_dlg1[] = { /* 0x81fa514 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives5_dlg2[] = { /* 0x81fa544 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives6_dlg1[] = { /* 0x81fa564 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives6_dlg2[] = { /* 0x81fa594 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives7_dlg1[] = { /* 0x81fa5b4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives7_dlg2[] = { /* 0x81fa5e4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives8_dlg1[] = { /* 0x81fa604 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives8_dlg2[] = { /* 0x81fa634 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives9_dlg1[] = { /* 0x81fa654 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives9_dlg2[] = { /* 0x81fa684 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives10_dlg1[] = { /* 0x81fa6a4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives10_dlg2[] = { /* 0x81fa6d4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives11_dlg1[] = { /* 0x81fa6f4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives11_dlg2[] = { /* 0x81fa724 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives12_dlg1[] = { /* 0x81fa744 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives12_dlg2[] = { /* 0x81fa774 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives13_dlg1[] = { /* 0x81fa794 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives13_dlg2[] = { /* 0x81fa7c4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives14_dlg1[] = { /* 0x81fa7e4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives14_dlg2[] = { /* 0x81fa814 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs125_g1_s0_lives15_dlg1[] = { /* 0x81fa834 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs125_g1_s0_lives15_dlg2[] = { /* 0x81fa864 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs125_g0_s1_lives[] = { /* 0x81fa884 */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs125_g0_s3_lives[] = { /* 0x81fa8b4 */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs125_g0_s4_lives[] = { /* 0x81fa8e4 */
    /*  0 */ {   0,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs125_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs125_g1_s0_lives[] = { /* 0x81fa914 */
    /*  0 */ {  14,   0,   0,   0, {  30,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives0_dlg1,
        [2] = s_gs125_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  25,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives1_dlg1,
        [2] = s_gs125_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  35,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives2_dlg1,
        [2] = s_gs125_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  21,  36, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives3_dlg1,
        [2] = s_gs125_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  39,  36, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives4_dlg1,
        [2] = s_gs125_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  19,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives5_dlg1,
        [2] = s_gs125_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  41,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives6_dlg1,
        [2] = s_gs125_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  25,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives7_dlg1,
        [2] = s_gs125_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  35,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives8_dlg1,
        [2] = s_gs125_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives9_dlg1,
        [2] = s_gs125_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  21,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives10_dlg1,
        [2] = s_gs125_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  39,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives11_dlg1,
        [2] = s_gs125_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {  27,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives12_dlg1,
        [2] = s_gs125_g1_s0_lives12_dlg2,
    } },
    /* 13 */ {  27,   0,   0,   0, {  33,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives13_dlg1,
        [2] = s_gs125_g1_s0_lives13_dlg2,
    } },
    /* 14 */ {  28,   0,   0,   0, {  21,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives14_dlg1,
        [2] = s_gs125_g1_s0_lives14_dlg2,
    } },
    /* 15 */ {  29,   0,   0,   0, {  39,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs125_g1_s0_lives15_dlg1,
        [2] = s_gs125_g1_s0_lives15_dlg2,
    } },
};

static const struct GroundEventData s_gs125_g0_s0_evts[] = { /* 0x81faa94 */
    /*  0 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81faaa0 */
    &s_gs125_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs125_g0_sectors[] = { /* 0x81faaa4 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs125_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs125_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs125_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs125_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs125_g1_sectors[] = { /* 0x81fab6c */
    { LPARRAY(s_gs125_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs125_groups[] = { /* 0x81fab94 */
    { LPARRAY(s_gs125_g0_sectors) },
    { LPARRAY(s_gs125_g1_sectors) },
    {},
};

static const struct GroundLink s_gs125_links[] = { /* 0x81fabac */
    /* link   0 */ { { /*x*/  37, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  19, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  31, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  25, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  37, /*y*/  25, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  19, /*y*/  25, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  28, /*y*/  25, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  33, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  23, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  39, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  17, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  37, /*y*/  34, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  19, /*y*/  34, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  13 */ { { /*x*/  33, /*y*/  31, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  14 */ { { /*x*/  23, /*y*/  31, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
    /* link  15 */ { { /*x*/  28, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  4, /*h*/  4, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs125 = { LPARRAY(s_gs125_groups), s_gs125_links }; /* 0x81fac2c */
