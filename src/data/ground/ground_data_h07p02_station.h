



















static const struct ScriptCommand s_gs123_g0_s0_station_sref_script[] = { /* 0x81f8b18 */
    DEBUGINFO,
    SELECT_MAP(123),
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

static const struct ScriptRef s_gs123_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs123_g0_s0_station_sref_script }; /* 0x81f8d94 */

static const struct ScriptCommand s_gs123_g0_s1_lives0_dlg0[] = { /* 0x81f8da0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g0_s1_lives1_dlg0[] = { /* 0x81f8de0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g0_s3_lives0_dlg0[] = { /* 0x81f8e20 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g0_s3_lives1_dlg0[] = { /* 0x81f8e60 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g0_s4_lives0_dlg0[] = { /* 0x81f8ea0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g0_s4_lives1_dlg0[] = { /* 0x81f8ed0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs123_g1_s0_lives0_dlg1[] = { /* 0x81f8f00 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives0_dlg2[] = { /* 0x81f8f30 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives1_dlg1[] = { /* 0x81f8f50 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives1_dlg2[] = { /* 0x81f8f80 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives2_dlg1[] = { /* 0x81f8fa0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives2_dlg2[] = { /* 0x81f8fd0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives3_dlg1[] = { /* 0x81f8ff0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives3_dlg2[] = { /* 0x81f9020 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives4_dlg1[] = { /* 0x81f9040 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives4_dlg2[] = { /* 0x81f9070 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives5_dlg1[] = { /* 0x81f9090 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives5_dlg2[] = { /* 0x81f90c0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives6_dlg1[] = { /* 0x81f90e0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives6_dlg2[] = { /* 0x81f9110 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives7_dlg1[] = { /* 0x81f9130 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives7_dlg2[] = { /* 0x81f9160 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives8_dlg1[] = { /* 0x81f9180 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives8_dlg2[] = { /* 0x81f91b0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives9_dlg1[] = { /* 0x81f91d0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives9_dlg2[] = { /* 0x81f9200 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives10_dlg1[] = { /* 0x81f9220 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives10_dlg2[] = { /* 0x81f9250 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs123_g1_s0_lives11_dlg1[] = { /* 0x81f9270 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs123_g1_s0_lives11_dlg2[] = { /* 0x81f92a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs123_g0_s1_lives[] = { /* 0x81f92c0 */
    /*  0 */ {   0,   4,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs123_g0_s3_lives[] = { /* 0x81f92f0 */
    /*  0 */ {   0,   4,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs123_g0_s4_lives[] = { /* 0x81f9320 */
    /*  0 */ {   0,   0,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs123_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs123_g1_s0_lives[] = { /* 0x81f9350 */
    /*  0 */ {  14,   0,   0,   0, {  28,   9, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives0_dlg1,
        [2] = s_gs123_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  23,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives1_dlg1,
        [2] = s_gs123_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  33,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives2_dlg1,
        [2] = s_gs123_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  28,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives3_dlg1,
        [2] = s_gs123_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  19,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives4_dlg1,
        [2] = s_gs123_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  39,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives5_dlg1,
        [2] = s_gs123_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {   7,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives6_dlg1,
        [2] = s_gs123_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  50,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives7_dlg1,
        [2] = s_gs123_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  13,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives8_dlg1,
        [2] = s_gs123_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  45,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives9_dlg1,
        [2] = s_gs123_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  14,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives10_dlg1,
        [2] = s_gs123_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  42,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs123_g1_s0_lives11_dlg1,
        [2] = s_gs123_g1_s0_lives11_dlg2,
    } },
};

static const struct GroundEventData s_gs123_g0_s0_evts[] = { /* 0x81f9470 */
    /*  0 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f9488 */
    &s_gs123_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs123_g0_sectors[] = { /* 0x81f948c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs123_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs123_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs123_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs123_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs123_g1_sectors[] = { /* 0x81f9554 */
    { LPARRAY(s_gs123_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs123_groups[] = { /* 0x81f957c */
    { LPARRAY(s_gs123_g0_sectors) },
    { LPARRAY(s_gs123_g1_sectors) },
    {},
};

static const struct GroundLink s_gs123_links[] = { /* 0x81f9594 */
    /* link   0 */ { { /*x*/  39, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  11, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  41, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  10, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  48, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/   3, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  35, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  16, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  25, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  31, /*y*/   7, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  19, /*y*/   7, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  25, /*y*/   7, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs123 = { LPARRAY(s_gs123_groups), s_gs123_links }; /* 0x81f95f4 */
