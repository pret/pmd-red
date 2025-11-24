







static const struct ScriptCommand s_gs8_g0_s0_station_sref_script[] = { /* 0x819a750 */
    DEBUGINFO_O(10),
    SELECT_MAP(8),
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 1),
    SELECT_LIVES(0, 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    JUMP_STATION(  1,  0),
  LABEL(2), /* = 0x02 */
    BGM_SWITCH(MUS_FILE_SELECT),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs8_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs8_g0_s0_station_sref_script }; /* 0x819a83c */


static const struct ScriptCommand s_gs8_g0_s0_evt0_sref_script[] = { /* 0x819a848 */
    DEBUGINFO_O(28),
    { 0x01, 0x00, -0x0001,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs8_g0_s0_evt0_sref = { GETOUT_NORMAL, 2, NULL, s_gs8_g0_s0_evt0_sref_script }; /* 0x819a878 */

static const struct ScriptCommand s_gs8_g0_s1_lives0_dlg0[] = { /* 0x819a884 */
    DEBUGINFO_O(36),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs8_g0_s1_lives1_dlg0[] = { /* 0x819a8c4 */
    DEBUGINFO_O(43),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs8_g1_s0_station_sref_script[] = { /* 0x819a904 */
    DEBUGINFO_O(50),
    SELECT_MAP(8),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_FILE_SELECT),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs8_g1_s0_station_sref = { EVENT_STATION , 7, NULL, s_gs8_g1_s0_station_sref_script }; /* 0x819a984 */

static const struct ScriptCommand s_gs8_g1_s0_eff0_script[] = { /* 0x819a990 */
    DEBUGINFO_O(63),
    CAMERA_INIT_PAN,
    CALL_SCRIPT(WAIT_START_FUNC),
    CAMERA_END_PAN,
    SPECIAL_TEXT(SPECIAL_TEXT_LUMINOUS_CAVE, 0, 0),
    ALERT_CUE(3),
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs8_g1_s0_lives0_dlg0[] = { /* 0x819aa10 */
    DEBUGINFO_O(74),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs8_g1_s1_station_sref_script[] = { /* 0x819aa80 */
    DEBUGINFO_O(84),
    SELECT_EFFECTS(-1, 1),
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs8_g1_s1_station_sref = { EVENT_WAKEUP, 7, NULL, s_gs8_g1_s1_station_sref_script }; /* 0x819aad0 */

static const struct ScriptCommand s_gs8_g1_s1_eff0_script[] = { /* 0x819aadc */
    DEBUGINFO_O(94),
    { 0x56, 0x00,  0x0000,  0x000001b4,  0x00000000, NULL },
    WAIT(30),
    CANCEL_LIVES(-1, 0),
    SELECT_LIVES(-1, 1),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs8_g1_s1_lives0_dlg0[] = { /* 0x819ab4c */
    DEBUGINFO_O(104),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct GroundLivesData s_gs8_g0_s1_lives[] = { /* 0x819abbc */
    /*  0 */ {   0,   4,   0,   0, {  25,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs8_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  25,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs8_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs8_g1_s0_lives[] = { /* 0x819abec */
    /*  0 */ {   0,   4,   0,   0, {  25,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs8_g1_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs8_g1_s1_lives[] = { /* 0x819ac04 */
    /*  0 */ {   0,   4,   0,   0, {  25,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs8_g1_s1_lives0_dlg0,
    } },
};

static const struct GroundEffectData s_gs8_g1_s0_effs[] = { /* 0x819ac1c */
    /*  0 */ {   0,   0,   1,   1, {  25,  21, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs8_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs8_g1_s1_effs[] = { /* 0x819ac28 */
    /*  0 */ {   3,   0,   1,   1, {  25,  21, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs8_g1_s1_eff0_script },
};

static const struct GroundEventData s_gs8_g0_s0_evts[] = { /* 0x819ac34 */
    /*  0 */ {   9,   3,   0,   0, {  21,  30, 0, 0 }, &s_gs8_g0_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x819ac40 */
    &s_gs8_g0_s0_station_sref,
    &s_gs8_g1_s0_station_sref,
    &s_gs8_g1_s1_station_sref,
};

static const struct GroundScriptSector s_gs8_g0_sectors[] = { /* 0x819ac4c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs8_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs8_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs8_g1_sectors[] = { /* 0x819ac9c */
    { LPARRAY(s_gs8_g1_s0_lives), 0,NULL, LPARRAY(s_gs8_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs8_g1_s1_lives), 0,NULL, LPARRAY(s_gs8_g1_s1_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs8_groups[] = { /* 0x819acec */
    { LPARRAY(s_gs8_g0_sectors) },
    { LPARRAY(s_gs8_g1_sectors) },
};

static const struct GroundLink s_gs8_links[] = { /* 0x819acfc */
    {},
};

const GroundScriptHeader gGroundScript_gs8 = { LPARRAY(s_gs8_groups), s_gs8_links }; /* 0x819ad04 */
