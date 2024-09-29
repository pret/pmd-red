









static const struct ScriptCommand s_gs227_g0_s0_station_sref_script[] = { /* 0x826f5b4 */
    DEBUGINFO,
    SELECT_MAP(227),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs227_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs227_g0_s0_station_sref_script }; /* 0x826f620 */

static const struct ScriptCommand s_gs227_g1_s0_station_sref_script[] = { /* 0x826f62c */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(227),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(180),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x40,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(3600),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs227_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs227_g1_s0_station_sref_script }; /* 0x826f6dc */

static const struct ScriptCommand s_gs227_g1_s0_eff0_script[] = { /* 0x826f6e8 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x5b, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x5b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    JUMP_LABEL(0),
};

static const struct GroundEffectData s_gs227_g1_s0_effs[] = { /* 0x826f778 */
    /*  0 */ {   0,   0,   1,   1, {  15,  11, 0, CPOS_HALFTILE }, s_gs227_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826f784 */
    &s_gs227_g0_s0_station_sref,
    &s_gs227_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs227_g0_sectors[] = { /* 0x826f78c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs227_g1_sectors[] = { /* 0x826f7b4 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs227_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs227_groups[] = { /* 0x826f7dc */
    { LPARRAY(s_gs227_g0_sectors) },
    { LPARRAY(s_gs227_g1_sectors) },
};

static const struct GroundLink s_gs227_links[] = { /* 0x826f7ec */
    /* link   0 */ { { /*x*/  15, /*y*/  11, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  15, /*y*/  31, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs227 = { LPARRAY(s_gs227_groups), s_gs227_links }; /* 0x826f7fc */
