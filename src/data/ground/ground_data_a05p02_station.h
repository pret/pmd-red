







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
    AWAIT_CUE(3),
    { 0x28, 0x01,  0x0005,  0x00000078,  0x00ffffff, NULL },
    WAIT(90),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(90),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 0, 200),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 1, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 2, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 3, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 4, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 5, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 6, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 7, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 8, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 9, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 10, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 11, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 12, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 13, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 14, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 15, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 16, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 17, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 18, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 19, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 20, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 21, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 22, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 23, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 24, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 25, 181),
    WAIT(45),
    SPECIAL_TEXT(SPECIAL_TEXT_CREDITS_NAME, 26, 181),
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
    TEXTBOX_AUTO_PRESS(180, 180),
    WAIT(60),
    MSG_ON_BG_AUTO(90, _("{CENTER_ALIGN}Your friend is heartbroken...")),
    WAIT(80),
    MSG_ON_BG_AUTO(90, _("{CENTER_ALIGN}A true friend...\n{CENTER_ALIGN}A friend for life...")),
    WAIT(80),
    MSG_ON_BG_AUTO(90, _("{CENTER_ALIGN}You finally realize it now...")),
    WAIT(80),
    MSG_ON_BG_AUTO(90, _("{CENTER_ALIGN}If you wish...\n{CENTER_ALIGN}And wish very strongly...")),
    WAIT(80),
    MSG_ON_BG_AUTO(90, _("{CENTER_ALIGN}Perhaps you will meet again.")),
    TEXTBOX_CLEAR2,
    WAIT(60),
    ALERT_CUE(3),
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
