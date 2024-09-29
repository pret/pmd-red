









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
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs218_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs218_g1_s0_station_sref_script }; /* 0x8269e6c */

static const struct ScriptCommand s_gs218_g1_s0_eff1_script[] = { /* 0x8269e78 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a5,  0x00000000, NULL },
    WAIT(180),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a6,  0x00000000, NULL },
    WAIT(120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs218_g1_s0_eff2_script[] = { /* 0x8269f38 */
    DEBUGINFO,
    { 0x59, 0x00,  0x0000, -0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a0,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a1,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a4,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs218_g1_s0_eff3_script[] = { /* 0x826a028 */
    DEBUGINFO,
    { 0x59, 0x00,  0x0000, -0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a0,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a1,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a4,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs218_g1_s0_lives0_dlg0[] = { /* 0x826a108 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ............") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Y-you are...?") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Did you maybe...#W\ncome to save me?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(20, 114),
    WAIT(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0d,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#W\nYes, I'll be fine.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" My wing is still damaged\na little, but...#W\nI can go.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEOUT(90),
    FANFARE_PLAY2(500),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000, -0x000000c8,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs218_g1_s0_lives1_dlg0[] = { /* 0x826a408 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
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
