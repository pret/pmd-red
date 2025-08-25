









static const struct ScriptCommand s_gs218_g0_s0_station_sref_script[] = { /* 0x8269d74 */
    DEBUGINFO,
    SELECT_MAP(218),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs218_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs218_g0_s0_station_sref_script }; /* 0x8269de0 */

static const struct ScriptCommand s_gs218_g1_s0_station_sref_script[] = { /* 0x8269dec */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(218),
    SELECT_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs218_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs218_g1_s0_station_sref_script }; /* 0x8269e6c */

static const struct ScriptCommand s_gs218_g1_s0_eff1_script[] = { /* 0x8269e78 */
    DEBUGINFO,
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x000000a5,  0x00000000, NULL },
    WAIT(180),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a6,  0x00000000, NULL },
    WAIT(120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    HALT,
};

static const struct ScriptCommand s_gs218_g1_s0_eff2_script[] = { /* 0x8269f38 */
    DEBUGINFO,
    { 0x59, 0x00,  0x0000, -0x00000004,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x56, 0x00,  0x0000,  0x000000a0,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a1,  0x00000000, NULL },
    ALERT_CUE(5),
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a4,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    RET,
};

static const struct ScriptCommand s_gs218_g1_s0_eff3_script[] = { /* 0x826a028 */
    DEBUGINFO,
    { 0x59, 0x00,  0x0000, -0x00000004,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x000000a0,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a1,  0x00000000, NULL },
    ALERT_CUE(7),
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a4,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs218_g1_s0_lives0_dlg0[] = { /* 0x826a108 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(-1, _(" ............")),
    MSG_NPC(-1, _(" ...Y-you are...?")),
    MSG_NPC(-1, _(" ...Did you maybe...{WAIT_PRESS}\ncome to save me?")),
    TEXTBOX_CLEAR,
    BGM_FADEIN(20, 114),
    WAIT(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    WALK_GRID(256, 1),
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" ............{WAIT_PRESS}\nYes, I'll be fine.")),
    MSG_NPC(2, _(" My wing is still damaged\na little, but...{WAIT_PRESS}\nI can go.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    WALK_RELATIVE(256, 8, 0),
    WALK_GRID(256, 0),
    ALERT_CUE(7),
    ROTATE(4, 2, DIRECTION_WEST),
    WAIT(30),
    BGM_FADEOUT(90),
    FANFARE_PLAY2(500),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    { 0x59, 0x00,  0x0000, -0x000000c8,  0x00000000, NULL },
    AWAIT_CUE(5),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs218_g1_s0_lives1_dlg0[] = { /* 0x826a408 */
    DEBUGINFO,
    SELECT_ANIMATION(4),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    WAIT(30),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    AWAIT_CUE(7),
    { 0x59, 0x00,  0x0000, -0x000000c8,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs218_g1_s0_lives[] = { /* 0x826a4b8 */
    /*  0 */ {   0,   4,   0,   0, {  25,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs218_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 122,   0,   0,   0, {  25,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs218_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs218_g1_s0_effs[] = { /* 0x826a4e8 */
    /*  0 */ {   0,   0,   1,   1, {  24,  27, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
    /*  1 */ {   4,   0,   1,   1, {  28,  24, 0, 0 }, s_gs218_g1_s0_eff1_script },
    /*  2 */ {   4,   0,   1,   1, {  29,  23, 0, CPOS_HALFTILE }, s_gs218_g1_s0_eff2_script },
    /*  3 */ {   4,   0,   1,   1, {  25,  23, 0, CPOS_HALFTILE }, s_gs218_g1_s0_eff3_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826a518 */
    &s_gs218_g0_s0_station_sref,
    &s_gs218_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs218_g0_sectors[] = { /* 0x826a520 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs218_g1_sectors[] = { /* 0x826a548 */
    { LPARRAY(s_gs218_g1_s0_lives), 0,NULL, LPARRAY(s_gs218_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs218_groups[] = { /* 0x826a570 */
    { LPARRAY(s_gs218_g0_sectors) },
    { LPARRAY(s_gs218_g1_sectors) },
};

static const struct GroundLink s_gs218_links[] = { /* 0x826a580 */
    /* link   0 */ { { /*x*/  29, /*y*/  24, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  25, /*y*/  27, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs218 = { LPARRAY(s_gs218_groups), s_gs218_links }; /* 0x826a590 */
