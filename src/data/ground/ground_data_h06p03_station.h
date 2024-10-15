




















static const struct ScriptCommand s_gs118_g0_s0_station_sref_script[] = { /* 0x81f5620 */
    DEBUGINFO,
    SELECT_MAP(118),
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

static const struct ScriptRef s_gs118_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs118_g0_s0_station_sref_script }; /* 0x81f589c */

static const struct ScriptCommand s_gs118_g0_s1_lives0_dlg0[] = { /* 0x81f58a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g0_s1_lives1_dlg0[] = { /* 0x81f58e8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g0_s3_lives0_dlg0[] = { /* 0x81f5928 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g0_s3_lives1_dlg0[] = { /* 0x81f5968 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g0_s4_lives0_dlg0[] = { /* 0x81f59a8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g0_s4_lives1_dlg0[] = { /* 0x81f59d8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs118_g1_s0_lives0_dlg1[] = { /* 0x81f5a08 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives0_dlg2[] = { /* 0x81f5a38 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives1_dlg1[] = { /* 0x81f5a58 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives1_dlg2[] = { /* 0x81f5a88 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives2_dlg1[] = { /* 0x81f5aa8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives2_dlg2[] = { /* 0x81f5ad8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives3_dlg1[] = { /* 0x81f5af8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives3_dlg2[] = { /* 0x81f5b28 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives4_dlg1[] = { /* 0x81f5b48 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives4_dlg2[] = { /* 0x81f5b78 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives5_dlg1[] = { /* 0x81f5b98 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives5_dlg2[] = { /* 0x81f5bc8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives6_dlg1[] = { /* 0x81f5be8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives6_dlg2[] = { /* 0x81f5c18 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives7_dlg1[] = { /* 0x81f5c38 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives7_dlg2[] = { /* 0x81f5c68 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives8_dlg1[] = { /* 0x81f5c88 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives8_dlg2[] = { /* 0x81f5cb8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives9_dlg1[] = { /* 0x81f5cd8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives9_dlg2[] = { /* 0x81f5d08 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives10_dlg1[] = { /* 0x81f5d28 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives10_dlg2[] = { /* 0x81f5d58 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives11_dlg1[] = { /* 0x81f5d78 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives11_dlg2[] = { /* 0x81f5da8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs118_g1_s0_lives12_dlg1[] = { /* 0x81f5dc8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs118_g1_s0_lives12_dlg2[] = { /* 0x81f5df8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs118_g0_s1_lives[] = { /* 0x81f5e18 */
    /*  0 */ {   0,   4,   0,   0, {  25,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  25,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs118_g0_s3_lives[] = { /* 0x81f5e48 */
    /*  0 */ {   0,   4,   0,   0, {  25,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  25,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs118_g0_s4_lives[] = { /* 0x81f5e78 */
    /*  0 */ {   0,   0,   0,   0, {  25,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  25,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs118_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs118_g1_s0_lives[] = { /* 0x81f5ea8 */
    /*  0 */ {  14,   0,   0,   0, {  18,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives0_dlg1,
        [2] = s_gs118_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  33,  28, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives1_dlg1,
        [2] = s_gs118_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  14,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives2_dlg1,
        [2] = s_gs118_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  36,  34, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives3_dlg1,
        [2] = s_gs118_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {   7,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives4_dlg1,
        [2] = s_gs118_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  44,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives5_dlg1,
        [2] = s_gs118_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  15,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives6_dlg1,
        [2] = s_gs118_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  36,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives7_dlg1,
        [2] = s_gs118_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  21,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives8_dlg1,
        [2] = s_gs118_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  30,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives9_dlg1,
        [2] = s_gs118_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  12,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives10_dlg1,
        [2] = s_gs118_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  40,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives11_dlg1,
        [2] = s_gs118_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {  25,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs118_g1_s0_lives12_dlg1,
        [2] = s_gs118_g1_s0_lives12_dlg2,
    } },
};

static const struct GroundEventData s_gs118_g0_s0_evts[] = { /* 0x81f5fe0 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f6010 */
    &s_gs118_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs118_g0_sectors[] = { /* 0x81f6014 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs118_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs118_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs118_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs118_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs118_g1_sectors[] = { /* 0x81f60dc */
    { LPARRAY(s_gs118_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs118_groups[] = { /* 0x81f6104 */
    { LPARRAY(s_gs118_g0_sectors) },
    { LPARRAY(s_gs118_g1_sectors) },
    {},
};

static const struct GroundLink s_gs118_links[] = { /* 0x81f611c */
    /* link   0 */ { { /*x*/  22, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  36, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/   9, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  27, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  18, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  33, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  12, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  40, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/   5, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  33, /*y*/  32, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  12, /*y*/  32, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  30, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  15, /*y*/  26, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs118 = { LPARRAY(s_gs118_groups), s_gs118_links }; /* 0x81f6184 */
