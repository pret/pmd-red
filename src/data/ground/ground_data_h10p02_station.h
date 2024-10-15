











static const struct ScriptCommand s_gs134_g0_s0_station_sref_script[] = { /* 0x81ff288 */
    DEBUGINFO,
    SELECT_MAP(134),
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
    BGM_SWITCH(16),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs134_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs134_g0_s0_station_sref_script }; /* 0x81ff504 */

static const struct ScriptCommand s_gs134_g0_s1_lives0_dlg0[] = { /* 0x81ff510 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs134_g0_s1_lives1_dlg0[] = { /* 0x81ff560 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs134_g0_s3_lives0_dlg0[] = { /* 0x81ff5b0 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs134_g0_s3_lives1_dlg0[] = { /* 0x81ff600 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs134_g0_s4_lives0_dlg0[] = { /* 0x81ff650 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs134_g0_s4_lives1_dlg0[] = { /* 0x81ff690 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs134_g1_s0_lives0_dlg1[] = { /* 0x81ff6d0 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs134_g1_s0_lives0_dlg2[] = { /* 0x81ff710 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs134_g1_s0_lives1_dlg1[] = { /* 0x81ff730 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs134_g1_s0_lives1_dlg2[] = { /* 0x81ff770 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs134_g1_s0_lives2_dlg1[] = { /* 0x81ff790 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs134_g1_s0_lives2_dlg2[] = { /* 0x81ff7d0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs134_g1_s0_lives3_dlg1[] = { /* 0x81ff7f0 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00004000,  0x00000000, NULL },
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs134_g1_s0_lives3_dlg2[] = { /* 0x81ff830 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs134_g0_s1_lives[] = { /* 0x81ff850 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs134_g0_s3_lives[] = { /* 0x81ff880 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs134_g0_s4_lives[] = { /* 0x81ff8b0 */
    /*  0 */ {   0,   0,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs134_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs134_g1_s0_lives[] = { /* 0x81ff8e0 */
    /*  0 */ {  14,   0,   0,   0, {  14,  12, 0, CPOS_HALFTILE }, {
        [1] = s_gs134_g1_s0_lives0_dlg1,
        [2] = s_gs134_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  42,  13, 0, CPOS_HALFTILE }, {
        [1] = s_gs134_g1_s0_lives1_dlg1,
        [2] = s_gs134_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {   6,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs134_g1_s0_lives2_dlg1,
        [2] = s_gs134_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  51,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs134_g1_s0_lives3_dlg1,
        [2] = s_gs134_g1_s0_lives3_dlg2,
    } },
};

static const struct GroundEventData s_gs134_g0_s0_evts[] = { /* 0x81ff940 */
    /*  0 */ {  57,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  57,   1,   0,   0, {   1,  38, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  39,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  39,   0,   0, {  56,   1, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81ff970 */
    &s_gs134_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs134_g0_sectors[] = { /* 0x81ff974 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs134_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs134_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs134_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs134_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs134_g1_sectors[] = { /* 0x81ffa3c */
    { LPARRAY(s_gs134_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs134_groups[] = { /* 0x81ffa64 */
    { LPARRAY(s_gs134_g0_sectors) },
    { LPARRAY(s_gs134_g1_sectors) },
    {},
};

static const struct GroundLink s_gs134_links[] = { /* 0x81ffa7c */
    /* link   0 */ { { /*x*/  48, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/   3, /*y*/  20, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  39, /*y*/  10, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  11, /*y*/  10, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs134 = { LPARRAY(s_gs134_groups), s_gs134_links }; /* 0x81ffa9c */
