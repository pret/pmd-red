











static const struct ScriptCommand s_gs181_g0_s0_station_sref_script[] = { /* 0x8231c70 */
    DEBUGINFO,
    SELECT_MAP(181),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs181_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs181_g0_s0_station_sref_script }; /* 0x8231cdc */

static const struct ScriptCommand s_gs181_g1_s0_station_sref_script[] = { /* 0x8231ce8 */
    DEBUGINFO,
    SELECT_MAP(181),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs181_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs181_g1_s0_station_sref_script }; /* 0x8231d78 */

static const struct ScriptCommand s_gs181_g1_s0_lives0_dlg0[] = { /* 0x8231d84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, hey, there they are.\nLet's get them out.")),
    VARIANT_DEFAULT(_(" Oh, there they are!\nLet's get them out safely.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x6b, 0x00,  0x00cc,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs181_g1_s0_lives1_dlg0[] = { /* 0x8231f0c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00cc,  0x00000003,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs181_g1_s0_lives2_dlg0[] = { /* 0x8231f9c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs181_g1_s0_lives3_dlg0[] = { /* 0x8231fdc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs181_g1_s0_lives[] = { /* 0x823201c */
    /*  0 */ {   0,   4,   0,   0, {  20,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs181_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  24,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs181_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  61,   7,   0,   0, {  22,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs181_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  62,   1,   0,   0, {  23,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs181_g1_s0_lives3_dlg0,
    } },
};

static const struct GroundEffectData s_gs181_g1_s0_effs[] = { /* 0x823207c */
    /*  0 */ {   0,   0,   1,   1, {  22,  20, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8232088 */
    &s_gs181_g0_s0_station_sref,
    &s_gs181_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs181_g0_sectors[] = { /* 0x8232090 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs181_g1_sectors[] = { /* 0x82320b8 */
    { LPARRAY(s_gs181_g1_s0_lives), 0,NULL, LPARRAY(s_gs181_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs181_groups[] = { /* 0x82320e0 */
    { LPARRAY(s_gs181_g0_sectors) },
    { LPARRAY(s_gs181_g1_sectors) },
};

static const struct GroundLink s_gs181_links[] = { /* 0x82320f0 */
    /* link   0 */ { { /*x*/  20, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  20, /*y*/  19, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  24, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  24, /*y*/  19, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs181 = { LPARRAY(s_gs181_groups), s_gs181_links }; /* 0x8232110 */
