







static const struct ScriptCommand s_gs210_g0_s0_station_sref_script[] = { /* 0x8263ee4 */
    DEBUGINFO,
    SELECT_MAP(210),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs210_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs210_g0_s0_station_sref_script }; /* 0x8263f50 */

static const struct ScriptCommand s_gs210_g1_s0_station_sref_script[] = { /* 0x8263f5c */
    DEBUGINFO,
    SELECT_MAP(210),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs210_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs210_g1_s0_station_sref_script }; /* 0x8263fdc */

static const struct ScriptCommand s_gs210_g1_s0_lives0_dlg0[] = { /* 0x8263fe8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs210_g1_s0_lives1_dlg0[] = { /* 0x8264058 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs210_g1_s0_lives[] = { /* 0x8264098 */
    /*  0 */ {   0,   4,   0,   0, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs210_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 132,   0,   0,   0, {  34,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs210_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs210_g1_s0_effs[] = { /* 0x82640c8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  27, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82640d4 */
    &s_gs210_g0_s0_station_sref,
    &s_gs210_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs210_g0_sectors[] = { /* 0x82640dc */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs210_g1_sectors[] = { /* 0x8264104 */
    { LPARRAY(s_gs210_g1_s0_lives), 0,NULL, LPARRAY(s_gs210_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs210_groups[] = { /* 0x826412c */
    { LPARRAY(s_gs210_g0_sectors) },
    { LPARRAY(s_gs210_g1_sectors) },
};

static const struct GroundLink s_gs210_links[] = { /* 0x826413c */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs210 = { LPARRAY(s_gs210_groups), s_gs210_links }; /* 0x8264144 */
