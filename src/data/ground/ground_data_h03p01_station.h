













static const struct ScriptCommand s_gs111_g0_s0_station_sref_script[] = { /* 0x81f1438 */
    DEBUGINFO,
    SELECT_MAP(111),
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
    BGM_SWITCH(16),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs111_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs111_g0_s0_station_sref_script }; /* 0x81f16b4 */

static const struct ScriptCommand s_gs111_g0_s1_lives0_dlg0[] = { /* 0x81f16c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g0_s1_lives1_dlg0[] = { /* 0x81f1700 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g0_s3_lives0_dlg0[] = { /* 0x81f1740 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g0_s3_lives1_dlg0[] = { /* 0x81f1780 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g0_s4_lives0_dlg0[] = { /* 0x81f17c0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g0_s4_lives1_dlg0[] = { /* 0x81f17f0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs111_g1_s0_lives0_dlg1[] = { /* 0x81f1820 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives0_dlg2[] = { /* 0x81f1850 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs111_g1_s0_lives1_dlg1[] = { /* 0x81f1870 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives1_dlg2[] = { /* 0x81f18a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs111_g1_s0_lives2_dlg1[] = { /* 0x81f18c0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives2_dlg2[] = { /* 0x81f18f0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs111_g1_s0_lives3_dlg1[] = { /* 0x81f1910 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives3_dlg2[] = { /* 0x81f1940 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs111_g1_s0_lives4_dlg1[] = { /* 0x81f1960 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives4_dlg2[] = { /* 0x81f1990 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs111_g1_s0_lives5_dlg1[] = { /* 0x81f19b0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs111_g1_s0_lives5_dlg2[] = { /* 0x81f19e0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs111_g0_s1_lives[] = { /* 0x81f1a00 */
    /*  0 */ {   0,   4,   0,   0, {  33,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs111_g0_s3_lives[] = { /* 0x81f1a30 */
    /*  0 */ {   0,   4,   0,   0, {  33,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs111_g0_s4_lives[] = { /* 0x81f1a60 */
    /*  0 */ {   0,   0,   0,   0, {  33,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  33,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs111_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs111_g1_s0_lives[] = { /* 0x81f1a90 */
    /*  0 */ {  14,   0,   0,   0, {  31,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives0_dlg1,
        [2] = s_gs111_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  42,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives1_dlg1,
        [2] = s_gs111_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  41,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives2_dlg1,
        [2] = s_gs111_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  24,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives3_dlg1,
        [2] = s_gs111_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  51,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives4_dlg1,
        [2] = s_gs111_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  17,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs111_g1_s0_lives5_dlg1,
        [2] = s_gs111_g1_s0_lives5_dlg2,
    } },
};

static const struct GroundEventData s_gs111_g0_s0_evts[] = { /* 0x81f1b20 */
    /*  0 */ {  69,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  69,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  68,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f1b50 */
    &s_gs111_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs111_g0_sectors[] = { /* 0x81f1b54 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs111_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs111_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs111_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs111_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs111_g1_sectors[] = { /* 0x81f1c1c */
    { LPARRAY(s_gs111_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs111_groups[] = { /* 0x81f1c44 */
    { LPARRAY(s_gs111_g0_sectors) },
    { LPARRAY(s_gs111_g1_sectors) },
    {},
};

static const struct GroundLink s_gs111_links[] = { /* 0x81f1c5c */
    /* link   0 */ { { /*x*/  14, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  48, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  21, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  38, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  39, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  28, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs111 = { LPARRAY(s_gs111_groups), s_gs111_links }; /* 0x81f1c8c */
