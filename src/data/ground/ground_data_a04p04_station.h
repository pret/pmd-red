







static const struct ScriptCommand s_gs174_g0_s0_station_sref_script[] = { /* 0x822a124 */
    DEBUGINFO,
    SELECT_MAP(174),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs174_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs174_g0_s0_station_sref_script }; /* 0x822a190 */

static const struct ScriptCommand s_gs174_g1_s0_station_sref_script[] = { /* 0x822a19c */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(174),
    SELECT_ENTITIES(-1, -1),
    BGM_STOP,
    { 0x27, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(150),
    { 0x28, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    WAIT(180),
    RET,
};

static const struct ScriptRef s_gs174_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs174_g1_s0_station_sref_script }; /* 0x822a24c */

static const struct ScriptCommand s_gs174_g1_s0_lives0_dlg0[] = { /* 0x822a258 */
    DEBUGINFO,
    SELECT_ANIMATION(52),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(30, 37),
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Is this...\na dream...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("No...{WAIT_PRESS}\nThis is no dream...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Yes...{WAIT_PRESS}\nThe star's explosion swallowed me...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("And I'm now adrift...{WAIT_PRESS}\nas a spirit...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("What's going to happen...?") },
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(485),
    { 0x28, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    WAIT(30),
    SELECT_LIVES(-1, 1),
    { 0x27, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(............)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...This shadow...{WAIT_PRESS}\n{NAME_4}...)") },
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Keke! {NAME_0}!{WAIT_PRESS}\nDidn't take much to put you down!{WAIT_PRESS}\nServes you right!")),
    MSG_NPC(4, _(" Kekeke!\nNow, what to do with you?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(465),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000041),
    MSG_NPC(4, _(" I know!")),
    MSG_NPC(4, _(" I'll drag you into the dark\nworld. That'll do it.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    SELECT_ANIMATION(51),
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000005),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(............)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Gengar is dragging me...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...{WAIT_PRESS}Gengar said...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(He would drag me into the dark\nworld...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(What is the dark world...?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Am I going to be abandoned in a world\nI don't know?)") },
    TEXTBOX_CLEAR,
    WAIT(90),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0004, 0x00000000),
    MSG_NPC(4, _(" ......")),
    MSG_NPC(4, _(" ............")),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(9),
    AWAIT_CUE(5),
    SELECT_ANIMATION(52),
    PORTRAIT_REP(0x0004, 0x00000044),
    MSG_NPC(4, _(" ..................{WAIT_PRESS}Hunh?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Darn it...\nI took the wrong path...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(......What?)") },
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    WAIT(60),
    MSG_NPC(4, _(" This isn't like me...{WAIT_PRESS}\nI can't tell which way is which...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0004, 0x00000044),
    MSG_NPC(4, _(" Keh! To heck with this.{WAIT_PRESS}\nI'll just ditch you here...")),
    PORTRAIT_REP(0x0004, 0x00000000),
    MSG_NPC(4, _(" That's it. Good-bye to you.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(9),
    WAIT(20),
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs174_g1_s1_lives0_dlg0[] = { /* 0x822abd8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_RELATIVE(128, 16, 32),
    ROTATE(8, 10, DIRECTION_WEST),
    WAIT(60),
    ROTATE(10, 10, DIRECTION_EAST),
    WAIT(45),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(6, 10, DIRECTION_NORTH),
    WAIT(20),
    ROTATE(6, 10, DIRECTION_SOUTH),
    WAIT(20),
    ROTATE(6, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(6, 10, DIRECTION_NORTH),
    WAIT(20),
    ROTATE(6, 10, DIRECTION_SOUTH),
    WAIT(20),
    ROTATE(6, 10, DIRECTION_EAST),
    WAIT(60),
    { 0x89, 0x10,  0x0100,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x89, 0x50,  0x0099,  0x00000002,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs174_g1_s0_lives[] = { /* 0x822ae98 */
    /*  0 */ {   0,   4,   0,   0, {  20,  11, 0, CPOS_HALFTILE }, {
        [0] = s_gs174_g1_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs174_g1_s1_lives[] = { /* 0x822aeb0 */
    /*  0 */ {  91,   0,   0,   0, {  20,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs174_g1_s1_lives0_dlg0,
    } },
};

static const struct GroundEffectData s_gs174_g1_s0_effs[] = { /* 0x822aec8 */
    /*  0 */ {   0,   0,   1,   1, {  20,  12, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x822aed4 */
    &s_gs174_g0_s0_station_sref,
    &s_gs174_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs174_g0_sectors[] = { /* 0x822aedc */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs174_g1_sectors[] = { /* 0x822af04 */
    { LPARRAY(s_gs174_g1_s0_lives), 0,NULL, LPARRAY(s_gs174_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs174_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs174_groups[] = { /* 0x822af54 */
    { LPARRAY(s_gs174_g0_sectors) },
    { LPARRAY(s_gs174_g1_sectors) },
};

static const struct GroundLink s_gs174_links[] = { /* 0x822af64 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs174 = { LPARRAY(s_gs174_groups), s_gs174_links }; /* 0x822af6c */
