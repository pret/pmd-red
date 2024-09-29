




















static const struct ScriptCommand s_gs116_g0_s0_station_sref_script[] = { /* 0x81f3fa0 */
    DEBUGINFO,
    SELECT_MAP(116),
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
    BGM_SWITCH(107),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs116_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs116_g0_s0_station_sref_script }; /* 0x81f421c */

static const struct ScriptCommand s_gs116_g0_s1_lives0_dlg0[] = { /* 0x81f4228 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g0_s1_lives1_dlg0[] = { /* 0x81f4268 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g0_s3_lives0_dlg0[] = { /* 0x81f42a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g0_s3_lives1_dlg0[] = { /* 0x81f42e8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g0_s4_lives0_dlg0[] = { /* 0x81f4328 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g0_s4_lives1_dlg0[] = { /* 0x81f4358 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs116_g1_s0_lives0_dlg1[] = { /* 0x81f4388 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives0_dlg2[] = { /* 0x81f43b8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives1_dlg1[] = { /* 0x81f43d8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives1_dlg2[] = { /* 0x81f4408 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives2_dlg1[] = { /* 0x81f4428 */
    DEBUGINFO,
    { 0x51, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives2_dlg2[] = { /* 0x81f4458 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives3_dlg1[] = { /* 0x81f4478 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives3_dlg2[] = { /* 0x81f44a8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives4_dlg1[] = { /* 0x81f44c8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives4_dlg2[] = { /* 0x81f44f8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives5_dlg1[] = { /* 0x81f4518 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives5_dlg2[] = { /* 0x81f4548 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives6_dlg1[] = { /* 0x81f4568 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives6_dlg2[] = { /* 0x81f4598 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives7_dlg1[] = { /* 0x81f45b8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives7_dlg2[] = { /* 0x81f45e8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives8_dlg1[] = { /* 0x81f4608 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives8_dlg2[] = { /* 0x81f4638 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives9_dlg1[] = { /* 0x81f4658 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives9_dlg2[] = { /* 0x81f4688 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives10_dlg1[] = { /* 0x81f46a8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives10_dlg2[] = { /* 0x81f46d8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives11_dlg1[] = { /* 0x81f46f8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives11_dlg2[] = { /* 0x81f4728 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs116_g1_s0_lives12_dlg1[] = { /* 0x81f4748 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs116_g1_s0_lives12_dlg2[] = { /* 0x81f4778 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs116_g0_s1_lives[] = { /* 0x81f4798 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs116_g0_s3_lives[] = { /* 0x81f47c8 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs116_g0_s4_lives[] = { /* 0x81f47f8 */
    /*  0 */ {   0,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs116_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs116_g1_s0_lives[] = { /* 0x81f4828 */
    /*  0 */ {  14,   0,   0,   0, {  18,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives0_dlg1,
        [2] = s_gs116_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  40,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives1_dlg1,
        [2] = s_gs116_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  12,  37, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives2_dlg1,
        [2] = s_gs116_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  46,  37, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives3_dlg1,
        [2] = s_gs116_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {   7,  32, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives4_dlg1,
        [2] = s_gs116_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  51,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives5_dlg1,
        [2] = s_gs116_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  15,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives6_dlg1,
        [2] = s_gs116_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  42,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives7_dlg1,
        [2] = s_gs116_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {   9,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives8_dlg1,
        [2] = s_gs116_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  23,   0,   0,   0, {  48,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives9_dlg1,
        [2] = s_gs116_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  24,   0,   0,   0, {  17,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives10_dlg1,
        [2] = s_gs116_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  25,   0,   0,   0, {  37,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives11_dlg1,
        [2] = s_gs116_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  26,   0,   0,   0, {  28,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs116_g1_s0_lives12_dlg1,
        [2] = s_gs116_g1_s0_lives12_dlg2,
    } },
};

static const struct GroundEventData s_gs116_g0_s0_evts[] = { /* 0x81f4960 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f4990 */
    &s_gs116_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs116_g0_sectors[] = { /* 0x81f4994 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs116_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs116_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs116_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs116_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs116_g1_sectors[] = { /* 0x81f4a5c */
    { LPARRAY(s_gs116_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs116_groups[] = { /* 0x81f4a84 */
    { LPARRAY(s_gs116_g0_sectors) },
    { LPARRAY(s_gs116_g1_sectors) },
    {},
};

static const struct GroundLink s_gs116_links[] = { /* 0x81f4a9c */
    /* link   0 */ { { /*x*/  25, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  35, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  14, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  45, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/   6, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  39, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  12, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  48, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/   3, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   9 */ { { /*x*/  42, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  10 */ { { /*x*/   9, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  11 */ { { /*x*/  36, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link  12 */ { { /*x*/  15, /*y*/  28, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs116 = { LPARRAY(s_gs116_groups), s_gs116_links }; /* 0x81f4b04 */
