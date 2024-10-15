



















static const struct ScriptCommand s_gs108_g0_s0_station_sref_script[] = { /* 0x81efcc0 */
    DEBUGINFO,
    SELECT_MAP(108),
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

static const struct ScriptRef s_gs108_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs108_g0_s0_station_sref_script }; /* 0x81eff3c */

static const struct ScriptCommand s_gs108_g0_s1_lives0_dlg0[] = { /* 0x81eff48 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g0_s1_lives1_dlg0[] = { /* 0x81eff88 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g0_s3_lives0_dlg0[] = { /* 0x81effc8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g0_s3_lives1_dlg0[] = { /* 0x81f0008 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g0_s4_lives0_dlg0[] = { /* 0x81f0048 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g0_s4_lives1_dlg0[] = { /* 0x81f0078 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs108_g1_s0_lives0_dlg1[] = { /* 0x81f00a8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives0_dlg2[] = { /* 0x81f00d8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives1_dlg1[] = { /* 0x81f00f8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives1_dlg2[] = { /* 0x81f0128 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives2_dlg1[] = { /* 0x81f0148 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives2_dlg2[] = { /* 0x81f0178 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives3_dlg1[] = { /* 0x81f0198 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives3_dlg2[] = { /* 0x81f01c8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives4_dlg1[] = { /* 0x81f01e8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives4_dlg2[] = { /* 0x81f0218 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives5_dlg1[] = { /* 0x81f0238 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives5_dlg2[] = { /* 0x81f0268 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives6_dlg1[] = { /* 0x81f0288 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives6_dlg2[] = { /* 0x81f02b8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives7_dlg1[] = { /* 0x81f02d8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives7_dlg2[] = { /* 0x81f0308 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives8_dlg1[] = { /* 0x81f0328 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives8_dlg2[] = { /* 0x81f0358 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives9_dlg1[] = { /* 0x81f0378 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives9_dlg2[] = { /* 0x81f03a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives10_dlg1[] = { /* 0x81f03c8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives10_dlg2[] = { /* 0x81f03f8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs108_g1_s0_lives11_dlg1[] = { /* 0x81f0418 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs108_g1_s0_lives11_dlg2[] = { /* 0x81f0448 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs108_g0_s1_lives[] = { /* 0x81f0468 */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs108_g0_s3_lives[] = { /* 0x81f0498 */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs108_g0_s4_lives[] = { /* 0x81f04c8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs108_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs108_g1_s0_lives[] = { /* 0x81f04f8 */
    /*  0 */ {  14,   0,   0,   0, {  26,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives0_dlg1,
        [2] = s_gs108_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  32,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives1_dlg1,
        [2] = s_gs108_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  18,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives2_dlg1,
        [2] = s_gs108_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  41,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives3_dlg1,
        [2] = s_gs108_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  16,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives4_dlg1,
        [2] = s_gs108_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  44,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives5_dlg1,
        [2] = s_gs108_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {   9,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives6_dlg1,
        [2] = s_gs108_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  51,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives7_dlg1,
        [2] = s_gs108_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  17,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives8_dlg1,
        [2] = s_gs108_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  42,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives9_dlg1,
        [2] = s_gs108_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  25,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives10_dlg1,
        [2] = s_gs108_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  35,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs108_g1_s0_lives11_dlg1,
        [2] = s_gs108_g1_s0_lives11_dlg2,
    } },
};

static const struct GroundEventData s_gs108_g0_s0_evts[] = { /* 0x81f0618 */
    /*  0 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  59,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f0648 */
    &s_gs108_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs108_g0_sectors[] = { /* 0x81f064c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs108_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs108_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs108_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs108_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs108_g1_sectors[] = { /* 0x81f0714 */
    { LPARRAY(s_gs108_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs108_groups[] = { /* 0x81f073c */
    { LPARRAY(s_gs108_g0_sectors) },
    { LPARRAY(s_gs108_g1_sectors) },
    {},
};

static const struct GroundLink s_gs108_links[] = { /* 0x81f0754 */
    /* link   0 */ { { /*x*/  32, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/   6, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  22, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  30, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  40, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  14, /*y*/  11, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  48, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  41, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  13, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  38, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/  15, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  23, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs108 = { LPARRAY(s_gs108_groups), s_gs108_links }; /* 0x81f07b4 */
