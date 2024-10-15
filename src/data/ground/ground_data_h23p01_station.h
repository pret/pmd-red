




















static const struct ScriptCommand s_gs151_g0_s0_station_sref_script[] = { /* 0x8208fa4 */
    DEBUGINFO,
    SELECT_MAP(151),
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

static const struct ScriptRef s_gs151_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs151_g0_s0_station_sref_script }; /* 0x8209220 */

static const struct ScriptCommand s_gs151_g0_s1_lives0_dlg0[] = { /* 0x820922c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g0_s1_lives1_dlg0[] = { /* 0x820926c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g0_s3_lives0_dlg0[] = { /* 0x82092ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g0_s3_lives1_dlg0[] = { /* 0x82092ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g0_s4_lives0_dlg0[] = { /* 0x820932c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g0_s4_lives1_dlg0[] = { /* 0x820935c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs151_g1_s0_lives0_dlg1[] = { /* 0x820938c */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives0_dlg2[] = { /* 0x82093bc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives1_dlg1[] = { /* 0x82093dc */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives1_dlg2[] = { /* 0x820940c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives2_dlg1[] = { /* 0x820942c */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives2_dlg2[] = { /* 0x820945c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives3_dlg1[] = { /* 0x820947c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives3_dlg2[] = { /* 0x82094ac */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives4_dlg1[] = { /* 0x82094cc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives4_dlg2[] = { /* 0x82094fc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives5_dlg1[] = { /* 0x820951c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives5_dlg2[] = { /* 0x820954c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives6_dlg1[] = { /* 0x820956c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives6_dlg2[] = { /* 0x820959c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives7_dlg1[] = { /* 0x82095bc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives7_dlg2[] = { /* 0x82095ec */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives8_dlg1[] = { /* 0x820960c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives8_dlg2[] = { /* 0x820963c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives9_dlg1[] = { /* 0x820965c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives9_dlg2[] = { /* 0x820968c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives10_dlg1[] = { /* 0x82096ac */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives10_dlg2[] = { /* 0x82096dc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives11_dlg1[] = { /* 0x82096fc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives11_dlg2[] = { /* 0x820972c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs151_g1_s0_lives12_dlg1[] = { /* 0x820974c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs151_g1_s0_lives12_dlg2[] = { /* 0x820977c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs151_g0_s1_lives[] = { /* 0x820979c */
    /*  0 */ {   0,   4,   0,   0, {  32,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs151_g0_s3_lives[] = { /* 0x82097cc */
    /*  0 */ {   0,   4,   0,   0, {  32,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs151_g0_s4_lives[] = { /* 0x82097fc */
    /*  0 */ {   0,   0,   0,   0, {  32,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  33,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs151_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs151_g1_s0_lives[] = { /* 0x820982c */
    /*  0 */ {  14,   0,   0,   0, {  33,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives0_dlg1,
        [2] = s_gs151_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  39,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives1_dlg1,
        [2] = s_gs151_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  33,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives2_dlg1,
        [2] = s_gs151_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  39,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives3_dlg1,
        [2] = s_gs151_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  33,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives4_dlg1,
        [2] = s_gs151_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  27,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives5_dlg1,
        [2] = s_gs151_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  45,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives6_dlg1,
        [2] = s_gs151_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  27,  10, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives7_dlg1,
        [2] = s_gs151_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  45,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives8_dlg1,
        [2] = s_gs151_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  21,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives9_dlg1,
        [2] = s_gs151_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  51,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives10_dlg1,
        [2] = s_gs151_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  15,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives11_dlg1,
        [2] = s_gs151_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {   9,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs151_g1_s0_lives12_dlg1,
        [2] = s_gs151_g1_s0_lives12_dlg2,
    } },
};

static const struct GroundEventData s_gs151_g0_s0_evts[] = { /* 0x8209964 */
    /*  0 */ {  57,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  39,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8209994 */
    &s_gs151_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs151_g0_sectors[] = { /* 0x8209998 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs151_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs151_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs151_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs151_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs151_g1_sectors[] = { /* 0x8209a60 */
    { LPARRAY(s_gs151_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs151_groups[] = { /* 0x8209a88 */
    { LPARRAY(s_gs151_g0_sectors) },
    { LPARRAY(s_gs151_g1_sectors) },
    {},
};

static const struct GroundLink s_gs151_links[] = { /* 0x8209aa0 */
    /* link   0 */ { { /*x*/   6, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  12, /*y*/  10, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  48, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  18, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  42, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  24, /*y*/   8, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  42, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  24, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  30, /*y*/  10, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  36, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  30, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  36, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  30, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs151 = { LPARRAY(s_gs151_groups), s_gs151_links }; /* 0x8209b08 */
