








static const struct ScriptCommand s_gs138_g0_s0_station_sref_script[] = { /* 0x8201688 */
    DEBUGINFO,
    SELECT_MAP(138),
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
    BGM_SWITCH(35),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs138_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs138_g0_s0_station_sref_script }; /* 0x8201904 */

static const struct ScriptCommand s_gs138_g0_s1_lives0_dlg0[] = { /* 0x8201910 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g0_s1_lives1_dlg0[] = { /* 0x8201950 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g0_s3_lives0_dlg0[] = { /* 0x8201990 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g0_s3_lives1_dlg0[] = { /* 0x82019d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g0_s4_lives0_dlg0[] = { /* 0x8201a10 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g0_s4_lives1_dlg0[] = { /* 0x8201a40 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs138_g1_s0_lives0_dlg1[] = { /* 0x8201a70 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs138_g1_s0_lives0_dlg2[] = { /* 0x8201aa0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs138_g0_s1_lives[] = { /* 0x8201ac0 */
    /*  0 */ {   0,   4,   0,   0, {  22,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs138_g0_s3_lives[] = { /* 0x8201af0 */
    /*  0 */ {   0,   4,   0,   0, {  22,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs138_g0_s4_lives[] = { /* 0x8201b20 */
    /*  0 */ {   0,   0,   0,   0, {  22,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs138_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs138_g1_s0_lives[] = { /* 0x8201b50 */
    /*  0 */ {  14,   0,   0,   0, {  22,  10, 0, CPOS_HALFTILE }, {
        [1] = s_gs138_g1_s0_lives0_dlg1,
        [2] = s_gs138_g1_s0_lives0_dlg2,
    } },
};

static const struct GroundEventData s_gs138_g0_s0_evts[] = { /* 0x8201b68 */
    /*  0 */ {  45,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  45,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  39,   0,   0, {  42,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8201b98 */
    &s_gs138_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs138_g0_sectors[] = { /* 0x8201b9c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs138_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs138_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs138_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs138_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs138_g1_sectors[] = { /* 0x8201c64 */
    { LPARRAY(s_gs138_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs138_groups[] = { /* 0x8201c8c */
    { LPARRAY(s_gs138_g0_sectors) },
    { LPARRAY(s_gs138_g1_sectors) },
    {},
};

static const struct GroundLink s_gs138_links[] = { /* 0x8201ca4 */
    /* link   0 */ { { /*x*/  19, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  7, /*h*/  3, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs138 = { LPARRAY(s_gs138_groups), s_gs138_links }; /* 0x8201cac */
