









static const struct ScriptCommand s_gs164_g0_s0_station_sref_script[] = { /* 0x8218140 */
    DEBUGINFO,
    SELECT_MAP(164),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs164_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs164_g0_s0_station_sref_script }; /* 0x82181ac */

static const struct ScriptCommand s_gs164_g1_s0_station_sref_script[] = { /* 0x82181b8 */
    DEBUGINFO,
    BGM_SWITCH(24),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(164),
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}Thus began\n{CENTER_ALIGN}{NAME_0}'s")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}cruel and arduous\n{CENTER_ALIGN}journey as a fugitive.")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}Over forbidding mountains...")),
    TEXTBOX_CLEAR,
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs164_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs164_g1_s0_station_sref_script }; /* 0x8218330 */


static const struct ScriptCommand s_gs164_g1_s0_lives0_dlg0[] = { /* 0x821833c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    { 0x86, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whoa!\nThese cracks go down deep!")),
    VARIANT_DEFAULT(_(" Wow!\nAren't these fissures amazing?!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs164_g1_s0_lives1_dlg0[] = { /* 0x8218458 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(6),
    HALT,
};

static const struct GroundLivesData s_gs164_g1_s0_lives[] = { /* 0x82184d8 */
    /*  0 */ {   0,   2,   0,   0, {  25,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs164_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  26,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs164_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs164_g1_s0_effs[] = { /* 0x8218508 */
    /*  0 */ {   0,   0,   1,   1, {  40,  20, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8218514 */
    &s_gs164_g0_s0_station_sref,
    &s_gs164_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs164_g0_sectors[] = { /* 0x821851c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs164_g1_sectors[] = { /* 0x8218544 */
    { LPARRAY(s_gs164_g1_s0_lives), 0,NULL, LPARRAY(s_gs164_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs164_groups[] = { /* 0x821856c */
    { LPARRAY(s_gs164_g0_sectors) },
    { LPARRAY(s_gs164_g1_sectors) },
};

static const struct GroundLink s_gs164_links[] = { /* 0x821857c */
    /* link   0 */ { { /*x*/  34, /*y*/  19, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  35, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs164 = { LPARRAY(s_gs164_groups), s_gs164_links }; /* 0x821858c */
