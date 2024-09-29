







static const struct ScriptCommand s_gs169_g0_s0_station_sref_script[] = { /* 0x821cea0 */
    DEBUGINFO,
    SELECT_MAP(169),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs169_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs169_g0_s0_station_sref_script }; /* 0x821cf0c */

static const struct ScriptCommand s_gs169_g1_s0_station_sref_script[] = { /* 0x821cf18 */
    DEBUGINFO,
    SELECT_MAP(169),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs169_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs169_g1_s0_station_sref_script }; /* 0x821cf98 */

static const struct ScriptCommand s_gs169_g1_s0_lives0_dlg0[] = { /* 0x821cfa4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(90),
    { 0x2e, 0x02,  0x0001,  0x0000000b,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wow!#W\nThe snow is like frozen powder!") },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" It looks pretty, but...#W\nIt must be harsh there...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs169_g1_s0_lives1_dlg0[] = { /* 0x821d0e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs169_g1_s0_lives[] = { /* 0x821d124 */
    /*  0 */ {   0,   4,   0,   0, {  15,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs169_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  19,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs169_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs169_g1_s0_effs[] = { /* 0x821d154 */
    /*  0 */ {   0,   0,   1,   1, {  17,  18, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x821d160 */
    &s_gs169_g0_s0_station_sref,
    &s_gs169_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs169_g0_sectors[] = { /* 0x821d168 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs169_g1_sectors[] = { /* 0x821d190 */
    { LPARRAY(s_gs169_g1_s0_lives), 0,NULL, LPARRAY(s_gs169_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs169_groups[] = { /* 0x821d1b8 */
    { LPARRAY(s_gs169_g0_sectors) },
    { LPARRAY(s_gs169_g1_sectors) },
};

static const struct GroundLink s_gs169_links[] = { /* 0x821d1c8 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs169 = { LPARRAY(s_gs169_groups), s_gs169_links }; /* 0x821d1d0 */
