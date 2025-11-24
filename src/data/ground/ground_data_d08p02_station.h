









static const struct ScriptCommand s_gs194_g0_s0_station_sref_script[] = { /* 0x8245514 */
    DEBUGINFO_O(12),
    SELECT_MAP(194),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs194_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs194_g0_s0_station_sref_script }; /* 0x8245580 */

static const struct ScriptCommand s_gs194_g1_s0_station_sref_script[] = { /* 0x824558c */
    DEBUGINFO_O(21),
    SELECT_MAP(194),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_THERES_TROUBLE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    MSG_NPC(-1, _(" Stop right there!\nDon't let them get away!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sure. Like we're really\ngoing to wait because they said so.")),
    VARIANT_DEFAULT(_(" They expect us to stop and\nwait for them?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs194_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs194_g1_s0_station_sref_script }; /* 0x8245728 */



static const struct ScriptCommand s_gs194_g1_s0_lives0_dlg0[] = { /* 0x8245734 */
    DEBUGINFO_O(44),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(15),
    WALK_GRID(153, 0),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTHWEST),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(45),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    CMD_UNK_93(4, DIR_TRANS_11, 34),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew...\nWe finally got through that cave.")),
    VARIANT(/* == */  1, _(" Where are the Pokémon\nwho are chasing us?")),
    VARIANT_DEFAULT(_(" Whew!\nFinally, we made it through that cave.")),
    VARIANT_DEFAULT(_(" Where's the Pokémon mob\nthat's after us?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    WAIT(10),
    MSG_NPC(-1, _(" Hey, look! There they are!\nOver there!")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    MSG_NPC(-1, _(" Catch {NAME_0}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTHWEST),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Whoa! Here they come!\nRun!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    WAIT(5),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs194_g1_s0_lives1_dlg0[] = { /* 0x8245ab0 */
    DEBUGINFO_O(89),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(153, 1),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTHWEST),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_11, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs194_g1_s0_lives[] = { /* 0x8245c00 */
    /*  0 */ {   0,   0,   0,   0, {  10,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs194_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  12,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs194_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs194_g1_s0_effs[] = { /* 0x8245c30 */
    /*  0 */ {   0,   0,   1,   1, {  17,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8245c3c */
    &s_gs194_g0_s0_station_sref,
    &s_gs194_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs194_g0_sectors[] = { /* 0x8245c44 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs194_g1_sectors[] = { /* 0x8245c6c */
    { LPARRAY(s_gs194_g1_s0_lives), 0,NULL, LPARRAY(s_gs194_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs194_groups[] = { /* 0x8245c94 */
    { LPARRAY(s_gs194_g0_sectors) },
    { LPARRAY(s_gs194_g1_sectors) },
};

static const struct GroundLink s_gs194_links[] = { /* 0x8245ca4 */
    /* link   0 */ { { /*x*/  15, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  19, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs194 = { LPARRAY(s_gs194_groups), s_gs194_links }; /* 0x8245cb4 */
