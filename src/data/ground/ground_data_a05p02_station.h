







static const struct ScriptCommand s_gs176_g0_s0_station_sref_script[] = { /* 0x822b66c */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(176),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs176_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs176_g0_s0_station_sref_script }; /* 0x822b6d8 */

static const struct ScriptCommand s_gs176_g1_s0_station_sref_script[] = { /* 0x822b6e4 */
    DEBUGINFO,
    SELECT_MAP(176),
    SELECT_ENTITIES(-1, 0),
    { 0x3b, 0x36,  0x0000, -0x00000002,  0x00000000, NULL },
    { 0x27, 0x01,  0x0001,  0x0000001e,  0x00ffffff, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000078,  0x00ffffff, NULL },
    WAIT(90),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(90),
    { 0x3c, 0x2e,  0x0000,  0x00000000,  0x000000c8, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000001,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000002,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000003,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000004,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000005,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000006,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000007,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000008,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000009,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000a,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000b,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000c,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000d,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000e,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000000f,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000010,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000011,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000012,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000013,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000014,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000015,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000016,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000017,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000018,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x00000019,  0x000000b5, NULL },
    WAIT(45),
    { 0x3c, 0x2e,  0x0000,  0x0000001a,  0x000000b5, NULL },
    WAIT(120),
    BGM_FADEOUT(330),
    { 0x23, 0x01,  0x0078,  0x00000000,  0x00000000, NULL },
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(210),
    RET,
};

static const struct ScriptRef s_gs176_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs176_g1_s0_station_sref_script }; /* 0x822bb44 */

static const struct ScriptCommand s_gs176_g1_s0_eff1_script[] = { /* 0x822bb50 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x2b, 0x00,  0x0000,  0x000000b4,  0x000000b4, NULL },
    WAIT(60),
    { 0x39, 0x00,  0x005a,  0x00000000,  0x00000000, _("#+Your friend is heartbroken...") },
    WAIT(80),
    { 0x39, 0x00,  0x005a,  0x00000000,  0x00000000, _("#+A true friend...\n#+A friend for life...") },
    WAIT(80),
    { 0x39, 0x00,  0x005a,  0x00000000,  0x00000000, _("#+You finally realize it now...") },
    WAIT(80),
    { 0x39, 0x00,  0x005a,  0x00000000,  0x00000000, _("#+If you wish...\n#+And wish very strongly...") },
    WAIT(80),
    { 0x39, 0x00,  0x005a,  0x00000000,  0x00000000, _("#+Perhaps you will meet again.") },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundEffectData s_gs176_g1_s0_effs[] = { /* 0x822bd4c */
    /*  0 */ {   0,   0,   1,   1, {  21,  15, 0, CPOS_HALFTILE }, NULL },
    /*  1 */ {   3,   4,   2,   1, {  22,  15, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs176_g1_s0_eff1_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x822bd64 */
    &s_gs176_g0_s0_station_sref,
    &s_gs176_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs176_g0_sectors[] = { /* 0x822bd6c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs176_g1_sectors[] = { /* 0x822bd94 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs176_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs176_groups[] = { /* 0x822bdbc */
    { LPARRAY(s_gs176_g0_sectors) },
    { LPARRAY(s_gs176_g1_sectors) },
};

static const struct GroundLink s_gs176_links[] = { /* 0x822bdcc */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs176 = { LPARRAY(s_gs176_groups), s_gs176_links }; /* 0x822bdd4 */
