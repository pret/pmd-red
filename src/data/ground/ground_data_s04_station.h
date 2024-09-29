










static const struct ScriptCommand s_gs226_g0_s0_station_sref_script[] = { /* 0x826f1b4 */
    DEBUGINFO,
    SELECT_MAP(226),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs226_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs226_g0_s0_station_sref_script }; /* 0x826f220 */

static const struct ScriptCommand s_gs226_g1_s0_station_sref_script[] = { /* 0x826f22c */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(226),
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(4),
    RET,
};

static const struct ScriptRef s_gs226_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs226_g1_s0_station_sref_script }; /* 0x826f33c */

static const struct ScriptCommand s_gs226_g1_s0_eff0_script[] = { /* 0x826f348 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x22, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x22, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs226_g1_s0_eff1_script[] = { /* 0x826f4d8 */
    DEBUGINFO,
    { 0x3c, 0x29,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct GroundEffectData s_gs226_g1_s0_effs[] = { /* 0x826f508 */
    /*  0 */ {   0,   0,   1,   1, {  15,  11, 0, CPOS_HALFTILE }, s_gs226_g1_s0_eff0_script },
    /*  1 */ {   2,   0,   1,   1, {   0,   0, 0, CPOS_HALFTILE }, s_gs226_g1_s0_eff1_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826f520 */
    &s_gs226_g0_s0_station_sref,
    &s_gs226_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs226_g0_sectors[] = { /* 0x826f528 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs226_g1_sectors[] = { /* 0x826f550 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs226_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs226_groups[] = { /* 0x826f578 */
    { LPARRAY(s_gs226_g0_sectors) },
    { LPARRAY(s_gs226_g1_sectors) },
};

static const struct GroundLink s_gs226_links[] = { /* 0x826f588 */
    /* link   0 */ { { /*x*/  15, /*y*/  31, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  15, /*y*/  51, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  15, /*y*/  71, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs226 = { LPARRAY(s_gs226_groups), s_gs226_links }; /* 0x826f5a0 */
