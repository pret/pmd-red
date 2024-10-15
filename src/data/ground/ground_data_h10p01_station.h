











static const struct ScriptCommand s_gs133_g0_s0_station_sref_script[] = { /* 0x81feb24 */
    DEBUGINFO,
    SELECT_MAP(133),
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

static const struct ScriptRef s_gs133_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs133_g0_s0_station_sref_script }; /* 0x81feda0 */

static const struct ScriptCommand s_gs133_g0_s1_lives0_dlg0[] = { /* 0x81fedac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g0_s1_lives1_dlg0[] = { /* 0x81fedec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g0_s3_lives0_dlg0[] = { /* 0x81fee2c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g0_s3_lives1_dlg0[] = { /* 0x81fee6c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g0_s4_lives0_dlg0[] = { /* 0x81feeac */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g0_s4_lives1_dlg0[] = { /* 0x81feedc */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs133_g1_s0_lives0_dlg1[] = { /* 0x81fef0c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs133_g1_s0_lives0_dlg2[] = { /* 0x81fef3c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs133_g1_s0_lives1_dlg1[] = { /* 0x81fef5c */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs133_g1_s0_lives1_dlg2[] = { /* 0x81fef8c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs133_g1_s0_lives2_dlg1[] = { /* 0x81fefac */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs133_g1_s0_lives2_dlg2[] = { /* 0x81fefdc */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs133_g1_s0_lives3_dlg1[] = { /* 0x81feffc */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs133_g1_s0_lives3_dlg2[] = { /* 0x81ff02c */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs133_g0_s1_lives[] = { /* 0x81ff04c */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs133_g0_s3_lives[] = { /* 0x81ff07c */
    /*  0 */ {   0,   4,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs133_g0_s4_lives[] = { /* 0x81ff0ac */
    /*  0 */ {   0,   0,   0,   0, {  30,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs133_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs133_g1_s0_lives[] = { /* 0x81ff0dc */
    /*  0 */ {  14,   0,   0,   0, {  30,  20, 0, CPOS_HALFTILE }, {
        [1] = s_gs133_g1_s0_lives0_dlg1,
        [2] = s_gs133_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  12,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs133_g1_s0_lives1_dlg1,
        [2] = s_gs133_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  48,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs133_g1_s0_lives2_dlg1,
        [2] = s_gs133_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  30,  10, 0, CPOS_HALFTILE }, {
        [1] = s_gs133_g1_s0_lives3_dlg1,
        [2] = s_gs133_g1_s0_lives3_dlg2,
    } },
};

static const struct GroundEventData s_gs133_g0_s0_evts[] = { /* 0x81ff13c */
    /*  0 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81ff148 */
    &s_gs133_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs133_g0_sectors[] = { /* 0x81ff14c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs133_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs133_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs133_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs133_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs133_g1_sectors[] = { /* 0x81ff214 */
    { LPARRAY(s_gs133_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs133_groups[] = { /* 0x81ff23c */
    { LPARRAY(s_gs133_g0_sectors) },
    { LPARRAY(s_gs133_g1_sectors) },
    {},
};

static const struct GroundLink s_gs133_links[] = { /* 0x81ff254 */
    /* link   0 */ { { /*x*/  27, /*y*/   8, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  45, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/   9, /*y*/  23, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  27, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs133 = { LPARRAY(s_gs133_groups), s_gs133_links }; /* 0x81ff274 */
