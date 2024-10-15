









static const struct ScriptCommand s_gs159_g0_s0_station_sref_script[] = { /* 0x820ea18 */
    DEBUGINFO,
    SELECT_MAP(159),
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
    BGM_SWITCH(118),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs159_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs159_g0_s0_station_sref_script }; /* 0x820ec94 */

static const struct ScriptCommand s_gs159_g0_s1_lives0_dlg0[] = { /* 0x820eca0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g0_s1_lives1_dlg0[] = { /* 0x820ece0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g0_s3_lives0_dlg0[] = { /* 0x820ed20 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g0_s3_lives1_dlg0[] = { /* 0x820ed60 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g0_s4_lives0_dlg0[] = { /* 0x820eda0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g0_s4_lives1_dlg0[] = { /* 0x820edd0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs159_g1_s0_lives0_dlg1[] = { /* 0x820ee00 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs159_g1_s0_lives0_dlg2[] = { /* 0x820ee30 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs159_g1_s0_lives1_dlg1[] = { /* 0x820ee50 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs159_g1_s0_lives1_dlg2[] = { /* 0x820ee80 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs159_g0_s1_lives[] = { /* 0x820eea0 */
    /*  0 */ {   0,   4,   0,   0, {  20,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  20,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs159_g0_s3_lives[] = { /* 0x820eed0 */
    /*  0 */ {   0,   4,   0,   0, {  20,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  20,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs159_g0_s4_lives[] = { /* 0x820ef00 */
    /*  0 */ {   0,   0,   0,   0, {  20,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  20,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs159_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs159_g1_s0_lives[] = { /* 0x820ef30 */
    /*  0 */ {  14,   0,   0,   0, {  30,  17, 0, CPOS_HALFTILE }, {
        [1] = s_gs159_g1_s0_lives0_dlg1,
        [2] = s_gs159_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  36,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs159_g1_s0_lives1_dlg1,
        [2] = s_gs159_g1_s0_lives1_dlg2,
    } },
};

static const struct GroundEventData s_gs159_g0_s0_evts[] = { /* 0x820ef60 */
    /*  0 */ {  60,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  42,   0,   0, {  57,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820ef90 */
    &s_gs159_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs159_g0_sectors[] = { /* 0x820ef94 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs159_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs159_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs159_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs159_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs159_g1_sectors[] = { /* 0x820f05c */
    { LPARRAY(s_gs159_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs159_groups[] = { /* 0x820f084 */
    { LPARRAY(s_gs159_g0_sectors) },
    { LPARRAY(s_gs159_g1_sectors) },
    {},
};

static const struct GroundLink s_gs159_links[] = { /* 0x820f09c */
    /* link   0 */ { { /*x*/  27, /*y*/  15, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  34, /*y*/  18, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs159 = { LPARRAY(s_gs159_groups), s_gs159_links }; /* 0x820f0ac */
