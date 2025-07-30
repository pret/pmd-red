







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
    MSG_ON_BG(_("{CENTER_ALIGN}Welcome!")),
    MSG_ON_BG(_("{CENTER_ALIGN}This is the portal that leads\n{CENTER_ALIGN}to the world of Pokémon!")),
    MSG_ON_BG(_("{CENTER_ALIGN}But before I can let you through,\n{CENTER_ALIGN}I have several questions for you.")),
    MSG_ON_BG(_("{CENTER_ALIGN}I want you to answer them sincerely.")),
    MSG_ON_BG(_("{CENTER_ALIGN}Are you ready?")),
    MSG_ON_BG(_("{CENTER_ALIGN}OK...{WAIT_PRESS}\n{CENTER_ALIGN}Let the interview begin!")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(12),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_PERSONALITY_QUIZ, 0, 0),
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
