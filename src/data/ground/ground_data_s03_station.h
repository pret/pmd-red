



















static const struct ScriptCommand s_gs225_g0_s0_station_sref_script[] = { /* 0x826ec58 */
    DEBUGINFO,
    SELECT_MAP(225),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs225_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs225_g0_s0_station_sref_script }; /* 0x826ecc4 */

static const struct ScriptCommand s_gs225_g1_s0_station_sref_script[] = { /* 0x826ecd0 */
    DEBUGINFO,
    SELECT_MAP(225),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(40),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    { 0x3b, 0x38,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    { 0xe0, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs225_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs225_g1_s0_station_sref_script }; /* 0x826edc0 */

static const struct ScriptCommand s_gs225_g1_s0_eff0_script[] = { /* 0x826edcc */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0040,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs225_g1_s0_obj0_dlg0[] = { /* 0x826ee1c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00040000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0033,  0x00000001,  0x00000000, NULL },
    { 0x80, 0x00,  0x0066,  0x00000002,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0180,  0x00000003,  0x00000000, NULL },
    { 0x54, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0x54, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0300,  0x00000005,  0x00000000, NULL },
    { 0x54, 0x00,  0x0012,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0400,  0x00000006,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0500,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0600,  0x00000008,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0015,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0800,  0x00000009,  0x00000000, NULL },
    { 0x54, 0x00,  0x0015,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0800,  0x0000000a,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs225_g1_s0_obj1_dlg0[] = { /* 0x826efec */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0033,  0x0000000b,  0x00000000, NULL },
    HALT,
};

static const struct GroundObjectData s_gs225_g1_s0_objs[] = { /* 0x826f09c */
    /*  0 */ {  59,   0,   2,   1, {  29,  15, 0, CPOS_HALFTILE }, {
        [0] = s_gs225_g1_s0_obj0_dlg0,
    } },
    /*  1 */ {  60,   0,   2,   1, {  13,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs225_g1_s0_obj1_dlg0,
    } },
};

static const struct GroundEffectData s_gs225_g1_s0_effs[] = { /* 0x826f0cc */
    /*  0 */ {   0,   0,   1,   1, {  18,  27, 0, CPOS_HALFTILE }, s_gs225_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826f0d8 */
    &s_gs225_g0_s0_station_sref,
    &s_gs225_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs225_g0_sectors[] = { /* 0x826f0e0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs225_g1_sectors[] = { /* 0x826f108 */
    { 0,NULL, LPARRAY(s_gs225_g1_s0_objs), LPARRAY(s_gs225_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs225_groups[] = { /* 0x826f130 */
    { LPARRAY(s_gs225_g0_sectors) },
    { LPARRAY(s_gs225_g1_sectors) },
};

static const struct GroundLink s_gs225_links[] = { /* 0x826f140 */
    /* link   0 */ { { /*x*/  18, /*y*/  11, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  32, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  35, /*y*/  19, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  32, /*y*/  22, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  27, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  22, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   6 */ { { /*x*/  17, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   7 */ { { /*x*/  13, /*y*/  17, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/   9, /*y*/  13, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/   4, /*y*/   7, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/   1, /*y*/   0, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  11 */ { { /*x*/  13, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs225 = { LPARRAY(s_gs225_groups), s_gs225_links }; /* 0x826f1a0 */
