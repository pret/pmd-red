













static const struct ScriptCommand s_gs153_g0_s0_station_sref_script[] = { /* 0x820a3f4 */
    DEBUGINFO,
    SELECT_MAP(153),
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

static const struct ScriptRef s_gs153_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs153_g0_s0_station_sref_script }; /* 0x820a670 */

static const struct ScriptCommand s_gs153_g0_s1_lives0_dlg0[] = { /* 0x820a67c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g0_s1_lives1_dlg0[] = { /* 0x820a6bc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g0_s3_lives0_dlg0[] = { /* 0x820a6fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g0_s3_lives1_dlg0[] = { /* 0x820a73c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g0_s4_lives0_dlg0[] = { /* 0x820a77c */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g0_s4_lives1_dlg0[] = { /* 0x820a7ac */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs153_g1_s0_lives0_dlg1[] = { /* 0x820a7dc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives0_dlg2[] = { /* 0x820a80c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs153_g1_s0_lives1_dlg1[] = { /* 0x820a82c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives1_dlg2[] = { /* 0x820a85c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs153_g1_s0_lives2_dlg1[] = { /* 0x820a87c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives2_dlg2[] = { /* 0x820a8ac */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs153_g1_s0_lives3_dlg1[] = { /* 0x820a8cc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives3_dlg2[] = { /* 0x820a8fc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs153_g1_s0_lives4_dlg1[] = { /* 0x820a91c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives4_dlg2[] = { /* 0x820a94c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs153_g1_s0_lives5_dlg1[] = { /* 0x820a96c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs153_g1_s0_lives5_dlg2[] = { /* 0x820a99c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs153_g0_s1_lives[] = { /* 0x820a9bc */
    /*  0 */ {   0,   4,   0,   0, {  32,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs153_g0_s3_lives[] = { /* 0x820a9ec */
    /*  0 */ {   0,   4,   0,   0, {  32,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  32,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs153_g0_s4_lives[] = { /* 0x820aa1c */
    /*  0 */ {   0,   0,   0,   0, {  32,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  32,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs153_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs153_g1_s0_lives[] = { /* 0x820aa4c */
    /*  0 */ {  14,   0,   0,   0, {  29,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives0_dlg1,
        [2] = s_gs153_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  31,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives1_dlg1,
        [2] = s_gs153_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  21,  14, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives2_dlg1,
        [2] = s_gs153_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  13,   6, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives3_dlg1,
        [2] = s_gs153_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  44,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives4_dlg1,
        [2] = s_gs153_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  37,  10, 0, CPOS_HALFTILE }, {
        [1] = s_gs153_g1_s0_lives5_dlg1,
        [2] = s_gs153_g1_s0_lives5_dlg2,
    } },
};

static const struct GroundEventData s_gs153_g0_s0_evts[] = { /* 0x820aadc */
    /*  0 */ {  60,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  35, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  36,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  36,   0,   0, {  59,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820ab0c */
    &s_gs153_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs153_g0_sectors[] = { /* 0x820ab10 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs153_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs153_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs153_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs153_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs153_g1_sectors[] = { /* 0x820abd8 */
    { LPARRAY(s_gs153_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs153_groups[] = { /* 0x820ac00 */
    { LPARRAY(s_gs153_g0_sectors) },
    { LPARRAY(s_gs153_g1_sectors) },
    {},
};

static const struct GroundLink s_gs153_links[] = { /* 0x820ac18 */
    /* link   0 */ { { /*x*/  34, /*y*/   7, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  41, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  10, /*y*/   4, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  18, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  28, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  26, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs153 = { LPARRAY(s_gs153_groups), s_gs153_links }; /* 0x820ac48 */
