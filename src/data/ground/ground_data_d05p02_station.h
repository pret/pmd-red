







static const struct ScriptCommand s_gs187_g0_s0_station_sref_script[] = { /* 0x8237b78 */
    DEBUGINFO,
    SELECT_MAP(187),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs187_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs187_g0_s0_station_sref_script }; /* 0x8237be4 */

static const struct ScriptCommand s_gs187_g1_s0_station_sref_script[] = { /* 0x8237bf0 */
    DEBUGINFO,
    SELECT_MAP(187),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs187_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs187_g1_s0_station_sref_script }; /* 0x8237c90 */

static const struct ScriptCommand s_gs187_g1_s0_eff0_script[] = { /* 0x8237c9c */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    AWAIT_CUE(4),
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x44,  0x01cc,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs187_g1_s0_lives0_dlg0[] = { /* 0x8237d1c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    ALERT_CUE(12),
    { 0x89, 0x50,  0x0100,  0x00000004,  0x00000000, NULL },
    WAIT(32),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_2}'s friend is\nsupposed to be around here, right?")),
    VARIANT_DEFAULT(_(" Isn't this the place?\nWhere {NAME_2}'s friend is supposed\nto be?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    WAIT(60),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Oh, hey!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(12),
    { 0x89, 0x20,  0x0100,  0x00000004,  0x00000000, NULL },
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" We came for you!\nAre you all right?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0002, 0x00000041),
    MSG_NPC(2, _(" Yes...\nI'm fine, but...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" Great!\nYour friend is waiting for you.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" {NAME_3} is in the\nback...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Huh? {NAME_3}?")),
    TEXTBOX_CLEAR,
    ROTATE(4, 2, DIRECTION_NORTH),
    WAIT(5),
    ALERT_CUE(6),
    ALERT_CUE(12),
    WAIT(40),
    ROTATE(2, 1, DIRECTION_EAST),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Let's go!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(4),
    { 0x89, 0x3c,  0x01cc,  0x00000004,  0x00000000, NULL },
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! Are you all right?\nGet it together!")),
    VARIANT_DEFAULT(_(" Listen! Are you OK?\nSnap out of it!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0003, 0x00000041),
    MSG_NPC(3, _(" ...Urrrgh.\nForget about me...")),
    MSG_NPC(3, _(" Get away from here!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Get...{WAIT_PRESS}\nGet away?!")),
    TEXTBOX_CLEAR,
    BGM_STOP,
    FANFARE_PLAY2(502),
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x27, 0x01,  0x0005,  0x00000003,  0x00777700, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x27, 0x01,  0x0005,  0x00000003,  0x00777700, NULL },
    { 0x28, 0x01,  0x0005,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-what happened?!\nIt's pitch-black! I can't see!")),
    VARIANT_DEFAULT(_(" Wh-what's going on?!\nWhy did it turn pitch-black?")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 1),
    FANFARE_PLAY2(474),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gyaoooooh!") },
    WAIT(90),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" It's coming!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(502),
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x28, 0x00,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00000000, NULL },
    MSG_NPC(-1, _(" Move aside, you!")),
    MSG_NPC(-1, _(" He dared to disturb my sleep!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(502),
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x28, 0x00,  0x0005,  0x00000002,  0x00777700, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00000000, NULL },
    MSG_NPC(-1, _(" I have no mercy for meddlers!\nAnd that includes you!")),
    TEXTBOX_CLEAR,
    { 0x27, 0x00,  0x0005,  0x00000020,  0x00000000, NULL },
    WAIT(32),
    FANFARE_PLAY2(517),
    { 0x28, 0x01,  0x0005,  0x00000010,  0x00ffffff, NULL },
    WAIT(32),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gyaooooh!") },
    WAIT(90),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    { 0x27, 0x00,  0x0005,  0x00000010,  0x00ffffff, NULL },
    WAIT(64),
    ALERT_CUE(6),
    ALERT_CUE(12),
    WAIT(8),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(30),
    MSG_NPC(1, _(" Shi-{NAME_3}'s gone!")),
    TEXTBOX_CLEAR,
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(6),
    ALERT_CUE(12),
    WAIT(15),
    BGM_SWITCH(9),
    MSG_NPC(-1, _(" I am {NAME_6}!\nThe embodiment of lightning!")),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" If you wish to save\n{NAME_3}, then scale {COLOR YELLOW_D}Mt. Thunder{RESET}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" {NAME_6}...")),
    MSG_NPC(1, _(" So that's the legendary\nmonster...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};













static const struct ScriptCommand s_gs187_g1_s0_lives1_dlg0[] = { /* 0x82389a8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x89, 0x50,  0x0100,  0x00000004,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x89, 0x20,  0x0100,  0x00000004,  0x00000000, NULL },
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x89, 0x3c,  0x01cc,  0x00000004,  0x00000000, NULL },
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    FANFARE_PLAY2(466),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(6),
    ROTATE(8, 1, DIRECTION_NORTH),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs187_g1_s0_lives2_dlg0[] = { /* 0x8238b68 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x89, 0x58,  0x0100,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x89, 0x20,  0x0100,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(12),
    { 0x89, 0x3c,  0x01cc,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(12),
    HALT,
};

static const struct ScriptCommand s_gs187_g1_s0_lives3_dlg0[] = { /* 0x8238cb8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x89, 0x58,  0x0100,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x89, 0x20,  0x0100,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(12),
    { 0x89, 0x3c,  0x01cc,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(12),
    WAIT(7),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(12),
    HALT,
};

static const struct ScriptCommand s_gs187_g1_s0_lives4_dlg0[] = { /* 0x8238e18 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x89, 0x60,  0x0100,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(9),
    AWAIT_CUE(7),
    WAIT(20),
    SELECT_ANIMATION(5),
    { 0x89, 0x46,  0x0100,  0x00000004,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs187_g1_s0_lives5_dlg0[] = { /* 0x8238ee8 */
    DEBUGINFO,
    SELECT_ANIMATION(22),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    END_DELETE,
};

static const struct ScriptCommand s_gs187_g1_s1_lives0_dlg0[] = { /* 0x8238f38 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x70, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT(16),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gyaoooooooh!") },
    FANFARE_PLAY2(459),
    { 0x70, 0x00,  0x0400,  0x00000080,  0x00000000, NULL },
    WAIT(90),
    TEXTBOX_CLEAR,
    ALERT_CUE(5),
    END_DELETE,
};

static const struct GroundLivesData s_gs187_g1_s0_lives[] = { /* 0x8239018 */
    /*  0 */ {   0,   4,   0,   0, {  20,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  24,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  19,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  25,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives3_dlg0,
    } },
    /*  4 */ {  95,   0,   0,   0, {  22,  13, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives4_dlg0,
    } },
    /*  5 */ {  85,   2,   0,   0, {  22,  11, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s0_lives5_dlg0,
    } },
};

static const struct GroundLivesData s_gs187_g1_s1_lives[] = { /* 0x82390a8 */
    /*  0 */ {  96,   0,   0,   0, {  22,   9, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs187_g1_s1_lives0_dlg0,
    } },
};

static const struct GroundEffectData s_gs187_g1_s0_effs[] = { /* 0x82390c0 */
    /*  0 */ {   0,   0,   1,   1, {  22,  29, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs187_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82390cc */
    &s_gs187_g0_s0_station_sref,
    &s_gs187_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs187_g0_sectors[] = { /* 0x82390d4 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs187_g1_sectors[] = { /* 0x82390fc */
    { LPARRAY(s_gs187_g1_s0_lives), 0,NULL, LPARRAY(s_gs187_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs187_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs187_groups[] = { /* 0x823914c */
    { LPARRAY(s_gs187_g0_sectors) },
    { LPARRAY(s_gs187_g1_sectors) },
};

static const struct GroundLink s_gs187_links[] = { /* 0x823915c */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs187 = { LPARRAY(s_gs187_groups), s_gs187_links }; /* 0x8239164 */
