











static const struct ScriptCommand s_gs185_g0_s0_station_sref_script[] = { /* 0x8234c90 */
    DEBUGINFO_O(14),
    SELECT_MAP(185),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs185_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs185_g0_s0_station_sref_script }; /* 0x8234cfc */

static const struct ScriptCommand s_gs185_g1_s0_station_sref_script[] = { /* 0x8234d08 */
    DEBUGINFO_O(23),
    SELECT_MAP(185),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs185_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs185_g1_s0_station_sref_script }; /* 0x8234d88 */

static const struct ScriptCommand s_gs185_g1_s0_lives0_dlg0[] = { /* 0x8234d94 */
    DEBUGINFO_O(36),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005e,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0003, 0x00000043),
    MSG_NPC(3, _(" Owowowow...{WAIT_PRESS}\nYou'll pay for this!\nDon't you forget it!")),
    TEXTBOX_CLEAR,
    WAIT(16),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    WAIT(10),
    ALERT_CUE(6),
    ALERT_CUE(11),
    ROTATE(10, 2, DIRECTION_WEST),
    AWAIT_CUE(5),
    WAIT(60),
    ALERT_CUE(6),
    ALERT_CUE(11),
    ROTATE(4, 1, DIRECTION_EAST),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000009),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, those pests are gone.\nLet's find {NAME_2}.")),
    VARIANT_DEFAULT(_(" No one should hold us back\nnow. Let's find {NAME_2}.")),
    TEXTBOX_CLEAR,
    WAIT(16),
    MSG_NPC(-1, _(" Um, excuse me...")),
    TEXTBOX_CLEAR,
    WAIT(16),
    ALERT_CUE(7),
    ALERT_CUE(6),
    ALERT_CUE(11),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x0002,  0x0000005e,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_LEFT, 0x0002, 0x00000000),
    PORTRAIT_POS(2, 0, -3),
    MSG_NPC(2, _(" Did you maybe come looking\nfor me?")),
    TEXTBOX_CLEAR,
    WAIT(16),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" You must be {NAME_2}.")),
    MSG_NPC(1, _(" Let's get you home.\nCaterpie was worried about you.")),
    TEXTBOX_CLEAR,
    WAIT(16),
    ALERT_CUE(7),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Yay!")),
    MSG_NPC(2, _(" I was scared, so I kept my\nshell hardened...and waited and waited.")),
    MSG_NPC(2, _(" Thank you!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(3),
    HALT,
};






static const struct ScriptCommand s_gs185_g1_s0_lives1_dlg0[] = { /* 0x823531c */
    DEBUGINFO_O(108),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(10, 2, DIRECTION_WEST),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x0001,  0x0000005e,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives2_dlg0[] = { /* 0x82353ec */
    DEBUGINFO_O(124),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 0),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(7),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(10),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(16),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives3_dlg0[] = { /* 0x823550c */
    DEBUGINFO_O(145),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01c9,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(512, 1),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives4_dlg0[] = { /* 0x82355ec */
    DEBUGINFO_O(162),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(512, 2),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives5_dlg0[] = { /* 0x823565c */
    DEBUGINFO_O(172),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(512, 3),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives6_dlg0[] = { /* 0x82356cc */
    DEBUGINFO_O(182),
    SELECT_ANIMATION(2),
    AWAIT_CUE(11),
    ROTATE(10, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(11),
    { 0x93, 0x04,  0x000a,  0x0000005e,  0x00000000, NULL },
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives7_dlg0[] = { /* 0x823576c */
    DEBUGINFO_O(195),
    SELECT_ANIMATION(2),
    AWAIT_CUE(11),
    ROTATE(8, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(11),
    { 0x93, 0x04,  0x000a,  0x0000005e,  0x00000000, NULL },
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives8_dlg0[] = { /* 0x823580c */
    DEBUGINFO_O(208),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives9_dlg0[] = { /* 0x823583c */
    DEBUGINFO_O(214),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct GroundLivesData s_gs185_g1_s0_lives[] = { /* 0x823586c */
    /*  0 */ {   0,   4,   0,   0, {  32,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  37,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  94,   0,   0,   0, {  34,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  91,   0,   0,   0, {  34,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives3_dlg0,
    } },
    /*  4 */ {  92,   0,   0,   0, {  39,  28, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives4_dlg0,
    } },
    /*  5 */ {  93,   0,   0,   0, {  30,  28, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives5_dlg0,
    } },
    /*  6 */ {  10,   4,   0,   0, {  33,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives6_dlg0,
    } },
    /*  7 */ {  11,   4,   0,   0, {  36,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives7_dlg0,
    } },
    /*  8 */ {  12,   4,   0,   0, {  30,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives8_dlg0,
    } },
    /*  9 */ {  13,   4,   0,   0, {  39,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives9_dlg0,
    } },
};

static const struct GroundEffectData s_gs185_g1_s0_effs[] = { /* 0x823595c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8235968 */
    &s_gs185_g0_s0_station_sref,
    &s_gs185_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs185_g0_sectors[] = { /* 0x8235970 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs185_g1_sectors[] = { /* 0x8235998 */
    { LPARRAY(s_gs185_g1_s0_lives), 0,NULL, LPARRAY(s_gs185_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs185_groups[] = { /* 0x82359c0 */
    { LPARRAY(s_gs185_g0_sectors) },
    { LPARRAY(s_gs185_g1_sectors) },
};

static const struct GroundLink s_gs185_links[] = { /* 0x82359d0 */
    /* link   0 */ { { /*x*/  34, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  13, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  13, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  14, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs185 = { LPARRAY(s_gs185_groups), s_gs185_links }; /* 0x82359f0 */
