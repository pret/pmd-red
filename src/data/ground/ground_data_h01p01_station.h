
















static const struct ScriptCommand s_gs105_g0_s0_station_sref_script[] = { /* 0x81ee228 */
    DEBUGINFO_O(19),
    SELECT_MAP(105),
    SELECT_ENTITIES(1, 0),
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 4),
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 5),
    JUMP_LABEL(5),
  LABEL(2), /* = 0x02 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(6),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(6),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(6),
  LABEL(6), /* = 0x06 */
    BGM_SWITCH(MUS_FRIEND_AREA_OCEANIC),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs105_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs105_g0_s0_station_sref_script }; /* 0x81ee3f4 */


static const struct ScriptCommand s_gs105_g0_s1_lives0_dlg0[] = { /* 0x81ee400 */
    DEBUGINFO_O(51),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g0_s1_lives1_dlg0[] = { /* 0x81ee440 */
    DEBUGINFO_O(58),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g0_s3_lives0_dlg0[] = { /* 0x81ee480 */
    DEBUGINFO_O(65),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g0_s3_lives1_dlg0[] = { /* 0x81ee4c0 */
    DEBUGINFO_O(72),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g0_s4_lives0_dlg0[] = { /* 0x81ee500 */
    DEBUGINFO_O(79),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g0_s4_lives1_dlg0[] = { /* 0x81ee530 */
    DEBUGINFO_O(85),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs105_g1_s0_lives0_dlg1[] = { /* 0x81ee560 */
    DEBUGINFO_O(91),
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives0_dlg2[] = { /* 0x81ee590 */
    DEBUGINFO_O(97),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives1_dlg1[] = { /* 0x81ee5b0 */
    DEBUGINFO_O(102),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives1_dlg2[] = { /* 0x81ee5e0 */
    DEBUGINFO_O(108),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives2_dlg1[] = { /* 0x81ee600 */
    DEBUGINFO_O(113),
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives2_dlg2[] = { /* 0x81ee630 */
    DEBUGINFO_O(119),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives3_dlg1[] = { /* 0x81ee650 */
    DEBUGINFO_O(124),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives3_dlg2[] = { /* 0x81ee680 */
    DEBUGINFO_O(130),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives4_dlg1[] = { /* 0x81ee6a0 */
    DEBUGINFO_O(135),
    { 0x51, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives4_dlg2[] = { /* 0x81ee6d0 */
    DEBUGINFO_O(141),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives5_dlg1[] = { /* 0x81ee6f0 */
    DEBUGINFO_O(146),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives5_dlg2[] = { /* 0x81ee720 */
    DEBUGINFO_O(152),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives6_dlg1[] = { /* 0x81ee740 */
    DEBUGINFO_O(157),
    { 0x51, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives6_dlg2[] = { /* 0x81ee770 */
    DEBUGINFO_O(163),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives7_dlg1[] = { /* 0x81ee790 */
    DEBUGINFO_O(168),
    { 0x51, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives7_dlg2[] = { /* 0x81ee7c0 */
    DEBUGINFO_O(174),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs105_g1_s0_lives8_dlg1[] = { /* 0x81ee7e0 */
    DEBUGINFO_O(179),
    { 0x51, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs105_g1_s0_lives8_dlg2[] = { /* 0x81ee810 */
    DEBUGINFO_O(185),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs105_g0_s1_lives[] = { /* 0x81ee830 */
    /*  0 */ {   0,   4,   0,   0, {  28,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs105_g0_s3_lives[] = { /* 0x81ee860 */
    /*  0 */ {   0,   4,   0,   0, {  28,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs105_g0_s4_lives[] = { /* 0x81ee890 */
    /*  0 */ {   0,   0,   0,   0, {  28,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  28,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs105_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs105_g1_s0_lives[] = { /* 0x81ee8c0 */
    /*  0 */ {  14,   0,   0,   0, {  21,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives0_dlg1,
        [2] = s_gs105_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  36,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives1_dlg1,
        [2] = s_gs105_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  10,  22, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives2_dlg1,
        [2] = s_gs105_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  47,  21, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives3_dlg1,
        [2] = s_gs105_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  18,   0,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives4_dlg1,
        [2] = s_gs105_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  19,   0,   0,   0, {  41,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives5_dlg1,
        [2] = s_gs105_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  20,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives6_dlg1,
        [2] = s_gs105_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  21,   0,   0,   0, {  23,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives7_dlg1,
        [2] = s_gs105_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  22,   0,   0,   0, {  34,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs105_g1_s0_lives8_dlg1,
        [2] = s_gs105_g1_s0_lives8_dlg2,
    } },
};

static const struct GroundEventData s_gs105_g0_s0_evts[] = { /* 0x81ee998 */
    /*  0 */ {  58,   1,   0,   0, {   0,  29, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
    /*  1 */ {  58,   1,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[GETOUT_HABITAT] },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x81ee9b0 */
    &s_gs105_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs105_g0_sectors[] = { /* 0x81ee9b4 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs105_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs105_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs105_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs105_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs105_g1_sectors[] = { /* 0x81eea7c */
    { LPARRAY(s_gs105_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs105_groups[] = { /* 0x81eeaa4 */
    { LPARRAY(s_gs105_g0_sectors) },
    { LPARRAY(s_gs105_g1_sectors) },
};

static const struct GroundLink s_gs105_links[] = { /* 0x81eeab4 */
    /* link   0 */ { { /*x*/  19, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  32, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/   7, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  44, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  13, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   5 */ { { /*x*/  38, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  25, /*y*/  16, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   7 */ { { /*x*/  19, /*y*/  13, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   8 */ { { /*x*/  32, /*y*/  13, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

const GroundScriptHeader gGroundScript_gs105 = { LPARRAY(s_gs105_groups), s_gs105_links }; /* 0x81eeafc */
