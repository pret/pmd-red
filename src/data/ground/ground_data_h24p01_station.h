














static const struct ScriptCommand s_gs152_g0_s0_station_sref_script[] = { /* 0x8209b1c */
    DEBUGINFO,
    SELECT_MAP(152),
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

static const struct ScriptRef s_gs152_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs152_g0_s0_station_sref_script }; /* 0x8209d98 */

static const struct ScriptCommand s_gs152_g0_s1_lives0_dlg0[] = { /* 0x8209da4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g0_s1_lives1_dlg0[] = { /* 0x8209de4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g0_s3_lives0_dlg0[] = { /* 0x8209e24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g0_s3_lives1_dlg0[] = { /* 0x8209e64 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g0_s4_lives0_dlg0[] = { /* 0x8209ea4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g0_s4_lives1_dlg0[] = { /* 0x8209ed4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs152_g1_s0_lives0_dlg1[] = { /* 0x8209f04 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives0_dlg2[] = { /* 0x8209f34 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives1_dlg1[] = { /* 0x8209f54 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives1_dlg2[] = { /* 0x8209f84 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives2_dlg1[] = { /* 0x8209fa4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives2_dlg2[] = { /* 0x8209fd4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives3_dlg1[] = { /* 0x8209ff4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives3_dlg2[] = { /* 0x820a024 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives4_dlg1[] = { /* 0x820a044 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives4_dlg2[] = { /* 0x820a074 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives5_dlg1[] = { /* 0x820a094 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives5_dlg2[] = { /* 0x820a0c4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs152_g1_s0_lives6_dlg1[] = { /* 0x820a0e4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs152_g1_s0_lives6_dlg2[] = { /* 0x820a114 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs152_g0_s1_lives[] = { /* 0x820a134 */
    /*  0 */ {   0,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs152_g0_s3_lives[] = { /* 0x820a164 */
    /*  0 */ {   0,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs152_g0_s4_lives[] = { /* 0x820a194 */
    /*  0 */ {   0,   0,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs152_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs152_g1_s0_lives[] = { /* 0x820a1c4 */
    /*  0 */ {  14,   0,   0,   0, {  30,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives0_dlg1,
        [2] = s_gs152_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  24,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives1_dlg1,
        [2] = s_gs152_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  36,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives2_dlg1,
        [2] = s_gs152_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  17,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives3_dlg1,
        [2] = s_gs152_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  43,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives4_dlg1,
        [2] = s_gs152_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  17,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives5_dlg1,
        [2] = s_gs152_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  43,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs152_g1_s0_lives6_dlg1,
        [2] = s_gs152_g1_s0_lives6_dlg2,
    } },
};

static const struct GroundEventData s_gs152_g0_s0_evts[] = { /* 0x820a26c */
    /*  0 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  44, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  45,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  45,   0,   0, {  59,   1, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820a29c */
    &s_gs152_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs152_g0_sectors[] = { /* 0x820a2a0 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs152_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs152_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs152_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs152_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs152_g1_sectors[] = { /* 0x820a368 */
    { LPARRAY(s_gs152_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs152_groups[] = { /* 0x820a390 */
    { LPARRAY(s_gs152_g0_sectors) },
    { LPARRAY(s_gs152_g1_sectors) },
    {},
};

static const struct GroundLink s_gs152_links[] = { /* 0x820a3a8 */
    /* link   0 */ { { /*x*/  40, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  14, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  40, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  14, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  33, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  21, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  27, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs152 = { LPARRAY(s_gs152_groups), s_gs152_links }; /* 0x820a3e0 */
