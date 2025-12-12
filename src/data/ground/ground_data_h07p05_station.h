














static const struct ScriptCommand s_gs126_g0_s0_station_sref_script[] = { /* 0x81fac40 */
    DEBUGINFO_O(17),
    SELECT_MAP(126),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    JUMP_LABEL(0),
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(1, 0),
    JUMP_LABEL(3),
  LABEL(3), /* = 0x03 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 6),
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
    BGM_SWITCH(MUS_FRIEND_AREA_FOREST),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs126_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs126_g0_s0_station_sref_script }; /* 0x81fae8c */


static const struct ScriptCommand s_gs126_g0_s1_lives0_dlg0[] = { /* 0x81fae98 */
    DEBUGINFO_O(57),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g0_s1_lives1_dlg0[] = { /* 0x81faed8 */
    DEBUGINFO_O(64),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g0_s3_lives0_dlg0[] = { /* 0x81faf18 */
    DEBUGINFO_O(71),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g0_s3_lives1_dlg0[] = { /* 0x81faf58 */
    DEBUGINFO_O(78),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g0_s4_lives0_dlg0[] = { /* 0x81faf98 */
    DEBUGINFO_O(85),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g0_s4_lives1_dlg0[] = { /* 0x81fafc8 */
    DEBUGINFO_O(91),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs126_g1_s0_lives0_dlg1[] = { /* 0x81faff8 */
    DEBUGINFO_O(97),
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives0_dlg2[] = { /* 0x81fb028 */
    DEBUGINFO_O(103),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives1_dlg1[] = { /* 0x81fb048 */
    DEBUGINFO_O(108),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives1_dlg2[] = { /* 0x81fb078 */
    DEBUGINFO_O(114),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives2_dlg1[] = { /* 0x81fb098 */
    DEBUGINFO_O(119),
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives2_dlg2[] = { /* 0x81fb0c8 */
    DEBUGINFO_O(125),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives3_dlg1[] = { /* 0x81fb0e8 */
    DEBUGINFO_O(130),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives3_dlg2[] = { /* 0x81fb118 */
    DEBUGINFO_O(136),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives4_dlg1[] = { /* 0x81fb138 */
    DEBUGINFO_O(141),
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives4_dlg2[] = { /* 0x81fb168 */
    DEBUGINFO_O(147),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives5_dlg1[] = { /* 0x81fb188 */
    DEBUGINFO_O(152),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives5_dlg2[] = { /* 0x81fb1b8 */
    DEBUGINFO_O(158),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs126_g1_s0_lives6_dlg1[] = { /* 0x81fb1d8 */
    DEBUGINFO_O(163),
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs126_g1_s0_lives6_dlg2[] = { /* 0x81fb208 */
    DEBUGINFO_O(169),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs126_g0_s1_lives[] = { /* 0x81fb228 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs126_g0_s3_lives[] = { /* 0x81fb258 */
    /*  0 */ {   0,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs126_g0_s4_lives[] = { /* 0x81fb288 */
    /*  0 */ {   0,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs126_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs126_g1_s0_lives[] = { /* 0x81fb2b8 */
    /*  0 */ {  14,   0,   0,   0, {  22,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives0_dlg1,
        [2] = s_gs126_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  35,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives1_dlg1,
        [2] = s_gs126_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  16,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives2_dlg1,
        [2] = s_gs126_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  41,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives3_dlg1,
        [2] = s_gs126_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  28,  19, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives4_dlg1,
        [2] = s_gs126_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  15,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives5_dlg1,
        [2] = s_gs126_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  43,  11, 0, CPOS_HALFTILE }, {
        [1] = s_gs126_g1_s0_lives6_dlg1,
        [2] = s_gs126_g1_s0_lives6_dlg2,
    } },
};

static const struct GroundEventData s_gs126_g0_s0_evts[] = { /* 0x81fb360 */
    /*  0 */ {  57,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  1 */ {  57,   1,   0,   0, {   0,  41, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  2 */ {   1,  42,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  3 */ {   1,  42,   0,   0, {  56,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x81fb390 */
    &s_gs126_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs126_g0_sectors[] = { /* 0x81fb394 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs126_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs126_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs126_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs126_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs126_g1_sectors[] = { /* 0x81fb45c */
    { LPARRAY(s_gs126_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs126_groups[] = { /* 0x81fb484 */
    { LPARRAY(s_gs126_g0_sectors) },
    { LPARRAY(s_gs126_g1_sectors) },
    {},
};

static const struct GroundLink s_gs126_links[] = { /* 0x81fb49c */
    /* link   0 */ { { /*x*/  40, /*y*/   8, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  12, /*y*/   9, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  25, /*y*/  17, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  38, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  13, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  32, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  19, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

const GroundScriptHeader gGroundScript_gs126 = { LPARRAY(s_gs126_groups), s_gs126_links }; /* 0x81fb4d4 */
