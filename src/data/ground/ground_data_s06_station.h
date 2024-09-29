







static const struct ScriptCommand s_gs228_g0_s0_station_sref_script[] = { /* 0x826f810 */
    DEBUGINFO,
    SELECT_MAP(228),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs228_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs228_g0_s0_station_sref_script }; /* 0x826f87c */

static const struct ScriptCommand s_gs228_g1_s0_station_sref_script[] = { /* 0x826f888 */
    DEBUGINFO,
    SELECT_MAP(228),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x3c, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs228_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs228_g1_s0_station_sref_script }; /* 0x826f8f8 */
static const struct GroundEffectData s_gs228_g1_s0_effs[] = { /* 0x826f904 */
    /*  0 */ {   0,   0,   1,   1, {  15,  11, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826f910 */
    &s_gs228_g0_s0_station_sref,
    &s_gs228_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs228_g0_sectors[] = { /* 0x826f918 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs228_g1_sectors[] = { /* 0x826f940 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs228_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs228_groups[] = { /* 0x826f968 */
    { LPARRAY(s_gs228_g0_sectors) },
    { LPARRAY(s_gs228_g1_sectors) },
};

static const struct GroundLink s_gs228_links[] = { /* 0x826f978 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs228 = { LPARRAY(s_gs228_groups), s_gs228_links }; /* 0x826f980 */
