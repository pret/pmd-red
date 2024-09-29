







static const struct ScriptCommand s_gs223_g0_s0_station_sref_script[] = { /* 0x826df80 */
    DEBUGINFO,
    SELECT_MAP(223),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs223_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs223_g0_s0_station_sref_script }; /* 0x826dfec */

static const struct ScriptCommand s_gs223_g1_s0_station_sref_script[] = { /* 0x826dff8 - PART 1 0:00:31-0:00:45 - New game intro to personality test */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(223),
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Welcome!") },
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+This is the portal that leads\n#+to the world of Pokémon!") },
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But before I can let you through,\n#+I have several questions for you.") },
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+I want you to answer them sincerely.") },
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Are you ready?") },
    { 0x37, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+OK...#W\n#+Let the interview begin!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(12),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x3c, 0x28,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs223_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs223_g1_s0_station_sref_script }; /* 0x826e200 */
static const struct GroundEffectData s_gs223_g1_s0_effs[] = { /* 0x826e20c */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826e218 */
    &s_gs223_g0_s0_station_sref,
    &s_gs223_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs223_g0_sectors[] = { /* 0x826e220 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs223_g1_sectors[] = { /* 0x826e248 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs223_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs223_groups[] = { /* 0x826e270 */
    { LPARRAY(s_gs223_g0_sectors) },
    { LPARRAY(s_gs223_g1_sectors) },
};

static const struct GroundLink s_gs223_links[] = { /* 0x826e280 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs223 = { LPARRAY(s_gs223_groups), s_gs223_links }; /* 0x826e288 */
