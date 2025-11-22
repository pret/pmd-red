










static const struct ScriptCommand s_gs188_g0_s0_station_sref_script[] = { /* 0x8239178 */
    DEBUGINFO_O(13),
    SELECT_MAP(MAP_MT_THUNDER_ENTRY),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs188_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs188_g0_s0_station_sref_script }; /* 0x82391e4 */

static const struct ScriptCommand s_gs188_g1_s0_station_sref_script[] = { /* 0x82391f0 */
    DEBUGINFO_O(22),
    SELECT_MAP(MAP_MT_THUNDER_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_THUNDER),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_MT_THUNDER),
    RET,
};

static const struct ScriptRef s_gs188_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs188_g1_s0_station_sref_script }; /* 0x8239280 */

static const struct ScriptCommand s_gs188_g1_s0_eff0_script[] = { /* 0x823928c */
    DEBUGINFO_O(36),
    CAMERA_END_PAN,
    AWAIT_CUE(4),
    HALT,
};

static const struct ScriptCommand s_gs188_g1_s0_lives0_dlg0[] = { /* 0x82392cc */
    DEBUGINFO_O(43),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000060,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x00000055,  0x00000000, NULL },
    WAIT(60),
    ALERT_CUE(6),
    WALK_GRID(256, 0),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This must be the foot of\n{COLOR YELLOW_D}Mt. Thunder{RESET}...")),
    VARIANT(/* == */  1, _(" I wonder if {NAME_3}'s\nteam is already on the way...")),
    VARIANT_DEFAULT(_(" This is the foot of\n{COLOR YELLOW_D}Mt. Thunder{RESET}.")),
    VARIANT_DEFAULT(_(" I wonder...\nIs {NAME_3}'s team already on\ntheir way?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_2}, huh...{WAIT_PRESS}\nIt sounds really tough.")),
    VARIANT_DEFAULT(_(" {NAME_2}...{WAIT_PRESS}\nIt sounds very tough...")),
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_NPC(1, _(" Brr... I'm shaking...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_EAST),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But I can't be spooked\nby this.")),
    VARIANT(/* == */  1, _(" Our mission is to rescue\n{NAME_4}.")),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT(/* == */  3, _(" I shouldn't get all scared\nnow!")),
    VARIANT(/* == */  3, _(" Our objective is to rescue\n{NAME_4}.")),
    VARIANT(/* == */  3, _(" {NAME_0}, let's do our\nbest!")),
    VARIANT_DEFAULT(_(" I can't be scared now.")),
    VARIANT_DEFAULT(_(" Our objective is simple.\nWe're rescuing {NAME_4}.")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's try\nour best!")),
    TEXTBOX_CLEAR,
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 2),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs188_g1_s0_lives1_dlg0[] = { /* 0x8239824 */
    DEBUGINFO_O(94),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 1),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_NORTH),
    WAIT(8),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(9),
    WAIT(30),
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_WEST),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 2),
    HALT,
};

static const struct ScriptCommand s_gs188_g2_s0_station_sref_script[] = { /* 0x8239954 */
    DEBUGINFO_O(116),
    SELECT_MAP(MAP_MT_THUNDER_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_THUNDER),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_MT_THUNDER),
    RET,
};

static const struct ScriptRef s_gs188_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs188_g2_s0_station_sref_script }; /* 0x82399e4 */

static const struct ScriptCommand s_gs188_g2_s0_eff0_script[] = { /* 0x82399f0 */
    DEBUGINFO_O(130),
    CAMERA_END_PAN,
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs188_g2_s0_lives0_dlg0[] = { /* 0x8239a30 */
    DEBUGINFO_O(137),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000055,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    WALK_GRID(256, 0),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_EAST),
    WAIT(20),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}!\nThis time, we're gonna rescue\n{NAME_2}!")),
    VARIANT(/* == */  1, _(" Let's give it our best!")),
    VARIANT_DEFAULT(_(" {NAME_0}!\nWe'll rescue {NAME_2} this time for\nsure!")),
    VARIANT_DEFAULT(_(" Let's work hard at it!")),
    TEXTBOX_CLEAR,
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 2),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs188_g2_s0_lives1_dlg0[] = { /* 0x8239c48 */
    DEBUGINFO_O(165),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 1),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_WEST),
    WAIT(8),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 2),
    HALT,
};

static const struct GroundLivesData s_gs188_g1_s0_lives[] = { /* 0x8239d08 */
    /*  0 */ {   0,   2,   0,   0, {  23,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  27,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs188_g2_s0_lives[] = { /* 0x8239d38 */
    /*  0 */ {   0,   2,   0,   0, {  23,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  27,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs188_g1_s0_effs[] = { /* 0x8239d68 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs188_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs188_g2_s0_effs[] = { /* 0x8239d74 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs188_g2_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8239d80 */
    &s_gs188_g0_s0_station_sref,
    &s_gs188_g1_s0_station_sref,
    &s_gs188_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs188_g0_sectors[] = { /* 0x8239d8c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs188_g1_sectors[] = { /* 0x8239db4 */
    { LPARRAY(s_gs188_g1_s0_lives), 0,NULL, LPARRAY(s_gs188_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs188_g2_sectors[] = { /* 0x8239ddc */
    { LPARRAY(s_gs188_g2_s0_lives), 0,NULL, LPARRAY(s_gs188_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs188_groups[] = { /* 0x8239e04 */
    { LPARRAY(s_gs188_g0_sectors) },
    { LPARRAY(s_gs188_g1_sectors) },
    { LPARRAY(s_gs188_g2_sectors) },
    {},
};

static const struct GroundLink s_gs188_links[] = { /* 0x8239e24 */
    /* link   0 */ { { /*x*/  23, /*y*/  18, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  27, /*y*/  18, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  25, /*y*/  11, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs188 = { LPARRAY(s_gs188_groups), s_gs188_links }; /* 0x8239e3c */
