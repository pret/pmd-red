








static const struct ScriptCommand s_gs110_g0_s0_station_sref_script[] = { /* 0x81f0e00 */
    DEBUGINFO,
    SELECT_MAP(110),
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
    BGM_SWITCH(31),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs110_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs110_g0_s0_station_sref_script }; /* 0x81f107c */

static const struct ScriptCommand s_gs110_g0_s1_lives0_dlg0[] = { /* 0x81f1088 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g0_s1_lives1_dlg0[] = { /* 0x81f10c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g0_s3_lives0_dlg0[] = { /* 0x81f1108 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g0_s3_lives1_dlg0[] = { /* 0x81f1148 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g0_s4_lives0_dlg0[] = { /* 0x81f1188 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g0_s4_lives1_dlg0[] = { /* 0x81f11b8 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs110_g1_s0_lives0_dlg1[] = { /* 0x81f11e8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs110_g1_s0_lives0_dlg2[] = { /* 0x81f1218 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs110_g0_s1_lives[] = { /* 0x81f1238 */
    /*  0 */ {   0,   4,   0,   0, {  23,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  23,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs110_g0_s3_lives[] = { /* 0x81f1268 */
    /*  0 */ {   0,   4,   0,   0, {  23,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  23,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs110_g0_s4_lives[] = { /* 0x81f1298 */
    /*  0 */ {   0,   0,   0,   0, {  23,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  23,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs110_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs110_g1_s0_lives[] = { /* 0x81f12c8 */
    /*  0 */ {  14,   0,   0,   0, {  22,  13, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs110_g1_s0_lives0_dlg1,
        [2] = s_gs110_g1_s0_lives0_dlg2,
    } },
};

static const struct GroundEventData s_gs110_g0_s0_evts[] = { /* 0x81f12e0 */
    /*  0 */ {  45,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {   3,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  42,   0,   0, {  42,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {  45,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81f1310 */
    &s_gs110_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs110_g0_sectors[] = { /* 0x81f1314 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs110_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs110_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs110_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs110_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs110_g1_sectors[] = { /* 0x81f13dc */
    { LPARRAY(s_gs110_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs110_groups[] = { /* 0x81f1404 */
    { LPARRAY(s_gs110_g0_sectors) },
    { LPARRAY(s_gs110_g1_sectors) },
    {},
};

static const struct GroundLink s_gs110_links[] = { /* 0x81f141c */
    /* link   0 */ { { /*x*/  19, /*y*/  10, /*flags*/ 0, 0 }, /*w*/  7, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs110 = { LPARRAY(s_gs110_groups), s_gs110_links }; /* 0x81f1424 */
