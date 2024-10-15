













static const struct ScriptCommand s_gs114_g0_s0_station_sref_script[] = { /* 0x81f3124 */
    DEBUGINFO,
    SELECT_MAP(114),
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

static const struct ScriptRef s_gs114_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs114_g0_s0_station_sref_script }; /* 0x81f33a0 */

static const struct ScriptCommand s_gs114_g0_s1_lives0_dlg0[] = { /* 0x81f33ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g0_s1_lives1_dlg0[] = { /* 0x81f33ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g0_s3_lives0_dlg0[] = { /* 0x81f342c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g0_s3_lives1_dlg0[] = { /* 0x81f346c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g0_s4_lives0_dlg0[] = { /* 0x81f34ac */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g0_s4_lives1_dlg0[] = { /* 0x81f34dc */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs114_g1_s0_lives0_dlg1[] = { /* 0x81f350c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives0_dlg2[] = { /* 0x81f353c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs114_g1_s0_lives1_dlg1[] = { /* 0x81f355c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives1_dlg2[] = { /* 0x81f358c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs114_g1_s0_lives2_dlg1[] = { /* 0x81f35ac */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives2_dlg2[] = { /* 0x81f35dc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs114_g1_s0_lives3_dlg1[] = { /* 0x81f35fc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives3_dlg2[] = { /* 0x81f362c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs114_g1_s0_lives4_dlg1[] = { /* 0x81f364c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives4_dlg2[] = { /* 0x81f367c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs114_g1_s0_lives5_dlg1[] = { /* 0x81f369c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs114_g1_s0_lives5_dlg2[] = { /* 0x81f36cc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs114_g0_s1_lives[] = { /* 0x81f36ec */
    /*  0 */ {   0,   4,   0,   0, {  35,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs114_g0_s3_lives[] = { /* 0x81f371c */
    /*  0 */ {   0,   4,   0,   0, {  35,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs114_g0_s4_lives[] = { /* 0x81f374c */
    /*  0 */ {   0,   0,   0,   0, {  35,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs114_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs114_g1_s0_lives[] = { /* 0x81f377c */
    /*  0 */ {  14,   0,   0,   0, {  43,  32, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives0_dlg1,
        [2] = s_gs114_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  24,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives1_dlg1,
        [2] = s_gs114_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  38,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives2_dlg1,
        [2] = s_gs114_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  17,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives3_dlg1,
        [2] = s_gs114_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  17,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives4_dlg1,
        [2] = s_gs114_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  27,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs114_g1_s0_lives5_dlg1,
        [2] = s_gs114_g1_s0_lives5_dlg2,
    } },
};

static const struct GroundEventData s_gs114_g0_s0_evts[] = { /* 0x81f380c */
    /*  0 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f3818 */
    &s_gs114_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs114_g0_sectors[] = { /* 0x81f381c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs114_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs114_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs114_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs114_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs114_g1_sectors[] = { /* 0x81f38e4 */
    { LPARRAY(s_gs114_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs114_groups[] = { /* 0x81f390c */
    { LPARRAY(s_gs114_g0_sectors) },
    { LPARRAY(s_gs114_g1_sectors) },
    {},
};

static const struct GroundLink s_gs114_links[] = { /* 0x81f3924 */
    /* link   0 */ { { /*x*/  40, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  21, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  35, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  14, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  13, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  24, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs114 = { LPARRAY(s_gs114_groups), s_gs114_links }; /* 0x81f3954 */
