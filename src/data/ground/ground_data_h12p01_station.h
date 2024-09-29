













static const struct ScriptCommand s_gs136_g0_s0_station_sref_script[] = { /* 0x8200388 */
    DEBUGINFO,
    SELECT_MAP(136),
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
    BGM_SWITCH(2),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs136_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs136_g0_s0_station_sref_script }; /* 0x8200604 */

static const struct ScriptCommand s_gs136_g0_s1_lives0_dlg0[] = { /* 0x8200610 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g0_s1_lives1_dlg0[] = { /* 0x8200650 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g0_s3_lives0_dlg0[] = { /* 0x8200690 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g0_s3_lives1_dlg0[] = { /* 0x82006d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g0_s4_lives0_dlg0[] = { /* 0x8200710 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g0_s4_lives1_dlg0[] = { /* 0x8200740 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs136_g1_s0_lives0_dlg1[] = { /* 0x8200770 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives0_dlg2[] = { /* 0x82007a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs136_g1_s0_lives1_dlg1[] = { /* 0x82007c0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives1_dlg2[] = { /* 0x82007f0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs136_g1_s0_lives2_dlg1[] = { /* 0x8200810 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives2_dlg2[] = { /* 0x8200840 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs136_g1_s0_lives3_dlg1[] = { /* 0x8200860 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives3_dlg2[] = { /* 0x8200890 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs136_g1_s0_lives4_dlg1[] = { /* 0x82008b0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives4_dlg2[] = { /* 0x82008e0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs136_g1_s0_lives5_dlg1[] = { /* 0x8200900 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs136_g1_s0_lives5_dlg2[] = { /* 0x8200930 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs136_g0_s1_lives[] = { /* 0x8200950 */
    /*  0 */ {   0,   4,   0,   0, {  38,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  38,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs136_g0_s3_lives[] = { /* 0x8200980 */
    /*  0 */ {   0,   4,   0,   0, {  38,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  38,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs136_g0_s4_lives[] = { /* 0x82009b0 */
    /*  0 */ {   0,   0,   0,   0, {  38,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  38,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs136_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs136_g1_s0_lives[] = { /* 0x82009e0 */
    /*  0 */ {  14,   0,   0,   0, {  34,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives0_dlg1,
        [2] = s_gs136_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {   7,   8, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives1_dlg1,
        [2] = s_gs136_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  51,   9, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives2_dlg1,
        [2] = s_gs136_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  43,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives3_dlg1,
        [2] = s_gs136_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  14,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives4_dlg1,
        [2] = s_gs136_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  19,   7, 0, CPOS_HALFTILE }, {
        [1] = s_gs136_g1_s0_lives5_dlg1,
        [2] = s_gs136_g1_s0_lives5_dlg2,
    } },
};

static const struct GroundEventData s_gs136_g0_s0_evts[] = { /* 0x8200a70 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8200aa0 */
    &s_gs136_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs136_g0_sectors[] = { /* 0x8200aa4 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs136_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs136_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs136_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs136_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs136_g1_sectors[] = { /* 0x8200b6c */
    { LPARRAY(s_gs136_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs136_groups[] = { /* 0x8200b94 */
    { LPARRAY(s_gs136_g0_sectors) },
    { LPARRAY(s_gs136_g1_sectors) },
    {},
};

static const struct GroundLink s_gs136_links[] = { /* 0x8200bac */
    /* link   0 */ { { /*x*/  16, /*y*/   5, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  40, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  11, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  47, /*y*/   7, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   4, /*y*/   6, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  31, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs136 = { LPARRAY(s_gs136_groups), s_gs136_links }; /* 0x8200bdc */
