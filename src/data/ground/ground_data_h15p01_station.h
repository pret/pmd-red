














static const struct ScriptCommand s_gs142_g0_s0_station_sref_script[] = { /* 0x8203730 */
    DEBUGINFO,
    SELECT_MAP(142),
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
    BGM_SWITCH(112),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs142_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs142_g0_s0_station_sref_script }; /* 0x82039ac */

static const struct ScriptCommand s_gs142_g0_s1_lives0_dlg0[] = { /* 0x82039b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g0_s1_lives1_dlg0[] = { /* 0x82039f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g0_s3_lives0_dlg0[] = { /* 0x8203a38 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g0_s3_lives1_dlg0[] = { /* 0x8203a78 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g0_s4_lives0_dlg0[] = { /* 0x8203ab8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g0_s4_lives1_dlg0[] = { /* 0x8203ae8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs142_g1_s0_lives0_dlg1[] = { /* 0x8203b18 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives0_dlg2[] = { /* 0x8203b48 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives1_dlg1[] = { /* 0x8203b68 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives1_dlg2[] = { /* 0x8203b98 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives2_dlg1[] = { /* 0x8203bb8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives2_dlg2[] = { /* 0x8203be8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives3_dlg1[] = { /* 0x8203c08 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives3_dlg2[] = { /* 0x8203c38 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives4_dlg1[] = { /* 0x8203c58 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives4_dlg2[] = { /* 0x8203c88 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives5_dlg1[] = { /* 0x8203ca8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives5_dlg2[] = { /* 0x8203cd8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs142_g1_s0_lives6_dlg1[] = { /* 0x8203cf8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs142_g1_s0_lives6_dlg2[] = { /* 0x8203d28 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs142_g0_s1_lives[] = { /* 0x8203d48 */
    /*  0 */ {   0,   4,   0,   0, {  27,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs142_g0_s3_lives[] = { /* 0x8203d78 */
    /*  0 */ {   0,   4,   0,   0, {  27,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs142_g0_s4_lives[] = { /* 0x8203da8 */
    /*  0 */ {   0,   0,   0,   0, {  27,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs142_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs142_g1_s0_lives[] = { /* 0x8203dd8 */
    /*  0 */ {  14,   0,   0,   0, {  17,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives0_dlg1,
        [2] = s_gs142_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  44,  29, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives1_dlg1,
        [2] = s_gs142_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  13,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives2_dlg1,
        [2] = s_gs142_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  48,  23, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives3_dlg1,
        [2] = s_gs142_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  19,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives4_dlg1,
        [2] = s_gs142_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  42,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives5_dlg1,
        [2] = s_gs142_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  30,  15, 0, CPOS_HALFTILE }, {
        [1] = s_gs142_g1_s0_lives6_dlg1,
        [2] = s_gs142_g1_s0_lives6_dlg2,
    } },
};

static const struct GroundEventData s_gs142_g0_s0_evts[] = { /* 0x8203e80 */
    /*  0 */ {  60,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8203e8c */
    &s_gs142_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs142_g0_sectors[] = { /* 0x8203e90 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs142_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs142_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs142_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs142_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs142_g1_sectors[] = { /* 0x8203f58 */
    { LPARRAY(s_gs142_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs142_groups[] = { /* 0x8203f80 */
    { LPARRAY(s_gs142_g0_sectors) },
    { LPARRAY(s_gs142_g1_sectors) },
    {},
};

static const struct GroundLink s_gs142_links[] = { /* 0x8203f98 */
    /* link   0 */ { { /*x*/  27, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  39, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  16, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  45, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  10, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  41, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  14, /*y*/  27, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs142 = { LPARRAY(s_gs142_groups), s_gs142_links }; /* 0x8203fd0 */
