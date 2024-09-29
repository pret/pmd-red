














static const struct ScriptCommand s_gs146_g0_s0_station_sref_script[] = { /* 0x8205dec */
    DEBUGINFO,
    SELECT_MAP(146),
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
    BGM_SWITCH(3),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs146_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs146_g0_s0_station_sref_script }; /* 0x8206068 */

static const struct ScriptCommand s_gs146_g0_s1_lives0_dlg0[] = { /* 0x8206074 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g0_s1_lives1_dlg0[] = { /* 0x82060b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g0_s3_lives0_dlg0[] = { /* 0x82060f4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g0_s3_lives1_dlg0[] = { /* 0x8206134 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g0_s4_lives0_dlg0[] = { /* 0x8206174 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g0_s4_lives1_dlg0[] = { /* 0x82061a4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs146_g1_s0_lives0_dlg1[] = { /* 0x82061d4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives0_dlg2[] = { /* 0x8206204 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives1_dlg1[] = { /* 0x8206224 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives1_dlg2[] = { /* 0x8206254 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives2_dlg1[] = { /* 0x8206274 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives2_dlg2[] = { /* 0x82062a4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives3_dlg1[] = { /* 0x82062c4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives3_dlg2[] = { /* 0x82062f4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives4_dlg1[] = { /* 0x8206314 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives4_dlg2[] = { /* 0x8206344 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives5_dlg1[] = { /* 0x8206364 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives5_dlg2[] = { /* 0x8206394 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs146_g1_s0_lives6_dlg1[] = { /* 0x82063b4 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs146_g1_s0_lives6_dlg2[] = { /* 0x82063e4 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs146_g0_s1_lives[] = { /* 0x8206404 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs146_g0_s3_lives[] = { /* 0x8206434 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs146_g0_s4_lives[] = { /* 0x8206464 */
    /*  0 */ {   0,   0,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs146_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs146_g1_s0_lives[] = { /* 0x8206494 */
    /*  0 */ {  14,   0,   0,   0, {  19,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives0_dlg1,
        [2] = s_gs146_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives1_dlg1,
        [2] = s_gs146_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  36,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives2_dlg1,
        [2] = s_gs146_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  29,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives3_dlg1,
        [2] = s_gs146_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  38,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives4_dlg1,
        [2] = s_gs146_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  24,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives5_dlg1,
        [2] = s_gs146_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  32,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs146_g1_s0_lives6_dlg1,
        [2] = s_gs146_g1_s0_lives6_dlg2,
    } },
};

static const struct GroundEventData s_gs146_g0_s0_evts[] = { /* 0x820653c */
    /*  0 */ {  57,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  39,   0,   0, {  54,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820656c */
    &s_gs146_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs146_g0_sectors[] = { /* 0x8206570 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs146_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs146_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs146_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs146_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs146_g1_sectors[] = { /* 0x8206638 */
    { LPARRAY(s_gs146_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs146_groups[] = { /* 0x8206660 */
    { LPARRAY(s_gs146_g0_sectors) },
    { LPARRAY(s_gs146_g1_sectors) },
    {},
};

static const struct GroundLink s_gs146_links[] = { /* 0x8206678 */
    /* link   0 */ { { /*x*/  29, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  22, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  35, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  16, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  34, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  18, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  26, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs146 = { LPARRAY(s_gs146_groups), s_gs146_links }; /* 0x82066b0 */
