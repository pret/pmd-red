


















static const struct ScriptCommand s_gs137_g0_s0_station_sref_script[] = { /* 0x8200bf0 */
    DEBUGINFO,
    SELECT_MAP(137),
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

static const struct ScriptRef s_gs137_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs137_g0_s0_station_sref_script }; /* 0x8200e6c */

static const struct ScriptCommand s_gs137_g0_s1_lives0_dlg0[] = { /* 0x8200e78 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g0_s1_lives1_dlg0[] = { /* 0x8200eb8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g0_s3_lives0_dlg0[] = { /* 0x8200ef8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g0_s3_lives1_dlg0[] = { /* 0x8200f38 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g0_s4_lives0_dlg0[] = { /* 0x8200f78 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g0_s4_lives1_dlg0[] = { /* 0x8200fa8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs137_g1_s0_lives0_dlg1[] = { /* 0x8200fd8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives0_dlg2[] = { /* 0x8201008 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives1_dlg1[] = { /* 0x8201028 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives1_dlg2[] = { /* 0x8201058 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives2_dlg1[] = { /* 0x8201078 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives2_dlg2[] = { /* 0x82010a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives3_dlg1[] = { /* 0x82010c8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives3_dlg2[] = { /* 0x82010f8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives4_dlg1[] = { /* 0x8201118 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives4_dlg2[] = { /* 0x8201148 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives5_dlg1[] = { /* 0x8201168 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives5_dlg2[] = { /* 0x8201198 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives6_dlg1[] = { /* 0x82011b8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives6_dlg2[] = { /* 0x82011e8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives7_dlg1[] = { /* 0x8201208 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives7_dlg2[] = { /* 0x8201238 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives8_dlg1[] = { /* 0x8201258 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives8_dlg2[] = { /* 0x8201288 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives9_dlg1[] = { /* 0x82012a8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives9_dlg2[] = { /* 0x82012d8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs137_g1_s0_lives10_dlg1[] = { /* 0x82012f8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs137_g1_s0_lives10_dlg2[] = { /* 0x8201328 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs137_g0_s1_lives[] = { /* 0x8201348 */
    /*  0 */ {   0,   4,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs137_g0_s3_lives[] = { /* 0x8201378 */
    /*  0 */ {   0,   4,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs137_g0_s4_lives[] = { /* 0x82013a8 */
    /*  0 */ {   0,   0,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  32,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs137_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs137_g1_s0_lives[] = { /* 0x82013d8 */
    /*  0 */ {  14,   0,   0,   0, {  31,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives0_dlg1,
        [2] = s_gs137_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  11,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives1_dlg1,
        [2] = s_gs137_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  52,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives2_dlg1,
        [2] = s_gs137_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  32,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives3_dlg1,
        [2] = s_gs137_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  25,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives4_dlg1,
        [2] = s_gs137_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives5_dlg1,
        [2] = s_gs137_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  32,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives6_dlg1,
        [2] = s_gs137_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  25,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives7_dlg1,
        [2] = s_gs137_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  39,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives8_dlg1,
        [2] = s_gs137_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  18,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives9_dlg1,
        [2] = s_gs137_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  45,  27, 0, CPOS_HALFTILE }, {
        [1] = s_gs137_g1_s0_lives10_dlg1,
        [2] = s_gs137_g1_s0_lives10_dlg2,
    } },
};

static const struct GroundEventData s_gs137_g0_s0_evts[] = { /* 0x82014e0 */
    /*  0 */ {  63,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  63,   1,   0,   0, {   0,  44, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  45,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  45,   0,   0, {  60,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8201510 */
    &s_gs137_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs137_g0_sectors[] = { /* 0x8201514 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs137_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs137_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs137_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs137_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs137_g1_sectors[] = { /* 0x82015dc */
    { LPARRAY(s_gs137_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs137_groups[] = { /* 0x8201604 */
    { LPARRAY(s_gs137_g0_sectors) },
    { LPARRAY(s_gs137_g1_sectors) },
    {},
};

static const struct GroundLink s_gs137_links[] = { /* 0x820161c */
    /* link   0 */ { { /*x*/  43, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  15, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  36, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  22, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  29, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  36, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  22, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  29, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  49, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/   8, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  29, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs137 = { LPARRAY(s_gs137_groups), s_gs137_links }; /* 0x8201674 */
