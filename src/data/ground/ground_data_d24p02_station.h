







static const struct ScriptCommand s_gs221_g0_s0_station_sref_script[] = { /* 0x826d734 */
    DEBUGINFO_O(10),
    SELECT_MAP(221),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs221_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs221_g0_s0_station_sref_script }; /* 0x826d7a0 */

static const struct ScriptCommand s_gs221_g1_s0_station_sref_script[] = { /* 0x826d7ac */
    DEBUGINFO_O(19),
    SELECT_MAP(221),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_STORMY_SEA),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs221_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs221_g1_s0_station_sref_script }; /* 0x826d81c */

static const struct ScriptCommand s_gs221_g1_s0_eff0_script[] = { /* 0x826d828 */
    DEBUGINFO_O(31),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(20),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs221_g1_s0_lives0_dlg0[] = { /* 0x826d898 */
    DEBUGINFO_O(41),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(7),
    { 0x89, 0x50,  0x0099,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTH),
    MSG_NPC(2, _(" You're going to the\n{COLOR YELLOW_D}Murky Cave{RESET}?")),
    MSG_NPC(2, _(" Don't forget to take me,\nkekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(7),
    { 0x89, 0x50,  0x0080,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs221_g1_s0_lives1_dlg0[] = { /* 0x826d9d8 */
    DEBUGINFO_O(59),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x89, 0x58,  0x0100,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x89, 0x40,  0x0080,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs221_g1_s0_lives[] = { /* 0x826da58 */
    /*  0 */ {   0,   2,   0,   0, {  25,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs221_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  25,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs221_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs221_g1_s0_effs[] = { /* 0x826da88 */
    /*  0 */ {   0,   0,   1,   1, {  25,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs221_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826da94 */
    &s_gs221_g0_s0_station_sref,
    &s_gs221_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs221_g0_sectors[] = { /* 0x826da9c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs221_g1_sectors[] = { /* 0x826dac4 */
    { LPARRAY(s_gs221_g1_s0_lives), 0,NULL, LPARRAY(s_gs221_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs221_groups[] = { /* 0x826daec */
    { LPARRAY(s_gs221_g0_sectors) },
    { LPARRAY(s_gs221_g1_sectors) },
};

static const struct GroundLink s_gs221_links[] = { /* 0x826dafc */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs221 = { LPARRAY(s_gs221_groups), s_gs221_links }; /* 0x826db04 */
