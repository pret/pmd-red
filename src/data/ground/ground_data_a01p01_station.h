







static const struct ScriptCommand s_gs162_g0_s0_station_sref_script[] = { /* 0x820fd30 */
    DEBUGINFO,
    SELECT_MAP(162),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs162_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs162_g0_s0_station_sref_script }; /* 0x820fd9c */

static const struct ScriptCommand s_gs162_g1_s0_station_sref_script[] = { /* 0x820fda8 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(4),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g1_s0_station_sref_script }; /* 0x820fe48 */

static const struct ScriptCommand s_gs162_g1_s0_lives0_dlg0[] = { /* 0x820fe54 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Where...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Where am I?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Maybe...{WAIT_PRESS} Is this a dream...?") },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Oh?{WAIT_PRESS} There's someone here.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Who is it...?{WAIT_PRESS} Someone I know...?") },
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000004),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......{WAIT_PRESS}Hmm... I can't remember.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs162_g2_s0_station_sref_script[] = { /* 0x8210084 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(4),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    FANFARE_FADEOUT2(60, 453),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs162_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g2_s0_station_sref_script }; /* 0x8210144 */

static const struct ScriptCommand s_gs162_g2_s0_eff0_script[] = { /* 0x8210150 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g2_s0_lives0_dlg0[] = { /* 0x8210190 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Again?{WAIT_PRESS} Am I dreaming again...?") },
    TEXTBOX_CLEAR,
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...It's that Pokémon again.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Huh?{WAIT_PRESS}\nThey're...talking to me...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...{WAIT_PRESS}I can't hear them clearly.\nWhat are they saying?") },
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(453),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    WAIT(30),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Huh? It's shaking.{WAIT_PRESS} An earthquake...?") },
    { 0x97, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Whoa! It's getting worse.") },
    PORTRAIT_REP(0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("For a dream, this feels strangely\nreal, but...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs162_g3_s0_station_sref_script[] = { /* 0x82104bc */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(4),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g3_s0_station_sref_script }; /* 0x821055c */

static const struct ScriptCommand s_gs162_g3_s0_lives0_dlg0[] = { /* 0x8210568 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......Again...{WAIT_PRESS}\nIt's that dream again.") },
    TEXTBOX_CLEAR,
    WAIT(30),
    SELECT_LIVES(-1, 1),
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("That Pokémon... Who could it be...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Huh?{WAIT_PRESS} I'm hearing better this time...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...What?{WAIT_PRESS} Human?{WAIT_PRESS} My role?") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000007),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("W-wait.\nPlease, tell me more.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......{WAIT_PRESS}\nI can't... Drifting off...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs162_g3_s1_lives0_dlg0[] = { /* 0x82107fc */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g4_s0_station_sref_script[] = { /* 0x8210bbc */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(4),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g4_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g4_s0_station_sref_script }; /* 0x8210c5c */

static const struct ScriptCommand s_gs162_g4_s0_lives0_dlg0[] = { /* 0x8210c68 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    TEXTBOX_CLEAR,
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......{WAIT_PRESS}Again.") },
    TEXTBOX_CLEAR,
    WAIT(30),
    SELECT_LIVES(-1, 1),
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......It's that dream again.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I always see this silhouette...{WAIT_PRESS}\nWho could it be?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh?{WAIT_PRESS} It's saying something!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("But... I can't quite make it out...{WAIT_PRESS}\nIt's clearer than it was before, but...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'll try talking to it.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Hello.{WAIT_PRESS} Please, tell me.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("You...{WAIT_PRESS}\nWho are you?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...{WAIT_PRESS}I am...") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" I am {NAME_2}.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Ga-{NAME_2}...?!") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000041),
    MSG_NPC(2, _(" I'm so glad. Finally...{WAIT_PRESS}\nI finally got to meet you...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...?{WAIT_PRESS} Finally met me...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("You knew me from before?\nWhat about me?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" I am your...")),
    TEXTBOX_CLEAR,
    WAIT(15),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh! Wait.{WAIT_PRESS} Just a little longer...") },
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0000, 0x00000005),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I want to know more...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("No... It's fading...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs162_g4_s1_lives0_dlg0[] = { /* 0x821124c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g5_s0_station_sref_script[] = { /* 0x821161c */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(5),
    { 0x27, 0x00,  0x0005,  0x00000020,  0x00ffffff, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(506),
    { 0x28, 0x01,  0x0005,  0x00000020,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs162_g5_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g5_s0_station_sref_script }; /* 0x82116ac */

static const struct ScriptCommand s_gs162_g5_s0_lives0_dlg0[] = { /* 0x82116b8 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x91, 0x0a,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" I've been waiting for you.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Ga...{WAIT_PRESS}{NAME_2}!") },
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs162_g6_s0_station_sref_script[] = { /* 0x82117e4 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(5),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    FANFARE_FADEOUT2(60, 453),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g6_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g6_s0_station_sref_script }; /* 0x8211894 */

static const struct ScriptCommand s_gs162_g6_s0_lives0_dlg0[] = { /* 0x82118a0 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    TEXTBOX_CLEAR,
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......This............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......That dream...... Again......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......It's been a while......") },
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(477),
    SELECT_LIVES(-1, 1),
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......You're......{WAIT_PRESS} {NAME_2}...") },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Yes...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...{NAME_2}.{WAIT_PRESS}\nThere's so much I want to ask you.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Why do you appear in my dreams?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" As an agent of spirits...{WAIT_PRESS}\nI must watch over you...")),
    MSG_NPC(2, _(" Because that is my role\nnow.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...An agent of spirits?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.")),
    MSG_NPC(2, _(" I fell under the curse of\nNinetales in the place of a Trainer...")),
    MSG_NPC(2, _(" And became a presence\nwithout a physical form like this.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Trainer...?{WAIT_PRESS}\nYou mean the human that was in the\nlegend about Ninetales?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It's awful that your Trainer would abandon\nyou and run away.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" Yes.{WAIT_PRESS} My Trainer was\na terrible person.")),
    MSG_NPC(2, _(" Mean and conniving...\nMy Trainer wasn't a nice person. Truly.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" But...{WAIT_PRESS}\nI don't hate my Trainer.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Huh? Don't hate your Trainer?{WAIT_PRESS}\nWhy not?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Well...{WAIT_PRESS}\nI wonder why myself.\nI don't quite understand...")),
    MSG_NPC(2, _(" My Trainer did some\nterrible things, but somehow, I can't\nbring myself to feel hatred...")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" My Trainer had some quirks,\nbut there were good qualities too.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" And, when it happened,\nI was desperate...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("When it happened...?{WAIT_PRESS}\nYou mean Ninetales's curse?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.")),
    MSG_NPC(2, _(" I protected my Trainer\nfrom Ninetales's curse with my\nentire being.")),
    MSG_NPC(2, _(" If the Trainer is facing\ndanger...")),
    MSG_NPC(2, _(" It is our duty to protect\nthe Trainer with our lives...{WAIT_PRESS}\nWe {POKEMON_2} are that way.")),
    MSG_NPC(2, _(" I kept my Trainer safe...{WAIT_PRESS}\nThat alone was enough to make me happy.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...Protect the Trainer even at the risk\nof your own life...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...It's amazing what {POKEMON_2}\ndid.)") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" Oh, I must mention, I don't\nmind the form I have taken.")),
    MSG_NPC(2, _(" I live on this way with\npride in the role I have been given.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Role?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Yes.")),
    MSG_NPC(2, _(" All things have a role.\nThey all serve a purpose.")),
    MSG_NPC(2, _(" Just as I have my own\nrole to play...")),
    MSG_NPC(2, _(" You, too, have a role to\nfill...")),
    MSG_NPC(2, _(" You have...{WAIT_PRESS}\ncome here to perform a certain role...")),
    MSG_NPC(2, _(" And, for that role...{WAIT_PRESS}\nyou became a Pokémon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("What...?{WAIT_PRESS}\nWhat are you saying?") },
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(453),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Wah!\nE-earthquake?!") },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("No! Wait!{WAIT_PRESS}\nI need to know more...") },
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};























static const struct ScriptCommand s_gs162_g6_s1_lives0_dlg0[] = { /* 0x8212774 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g7_s0_station_sref_script[] = { /* 0x8212df4 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, -1),
    { 0x27, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs162_g7_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g7_s0_station_sref_script }; /* 0x8212e64 */

static const struct ScriptCommand s_gs162_g7_s0_lives0_dlg0[] = { /* 0x8212e70 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" You have...{WAIT_PRESS}\ncome here to perform a certain role...")),
    MSG_NPC(1, _(" And, for that role...{WAIT_PRESS}\nyou became a Pokémon.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs162_g7_s0_lives1_dlg0[] = { /* 0x8212f40 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs162_g8_s0_station_sref_script[] = { /* 0x8212f90 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(5),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g8_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g8_s0_station_sref_script }; /* 0x8213030 */

static const struct ScriptCommand s_gs162_g8_s0_lives0_dlg0[] = { /* 0x821303c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    TEXTBOX_CLEAR,
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......I'm......{WAIT_PRESS}\nIn that dream again...") },
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(477),
    SELECT_LIVES(-1, 1),
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............{WAIT_PRESS}{NAME_1}...") },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" It's tomorrow, isn't it?{WAIT_PRESS}\nThat you take to that underground dungeon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Yes.{WAIT_PRESS} They make it sound like one\nterrible place...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I wonder if we'll be OK...") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000041),
    MSG_NPC(1, _(" You will be fine.")),
    MSG_NPC(1, _(" I am certain that you\nwill succeed, {NAME_0}.")),
    MSG_NPC(1, _(" You have my support.\nPlease, go with strength.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000009),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I will. Thank you.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'm feeling a little braver now.\nI will go for it.") },
    PORTRAIT_REP(0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("By the way...{WAIT_PRESS}\nGardevoir, do you know?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("What it's like underground?{WAIT_PRESS}\nOr what Groudon is like?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000042),
    MSG_NPC(1, _(" No... I'm sorry to say...{WAIT_PRESS}\nI can't envision it...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...OK.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I thought maybe you knew something,\nthe way you said it.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" No. I only wanted to give\nyou encouragement...")),
    MSG_NPC(1, _(" I'm sorry...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x00000009),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("No, no.\nThat's fine, too.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'm happy you tried to cheer me up.\nThank you.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" But...{WAIT_PRESS}\nThere is one thing that I can foresee.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Huh?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Your role...{WAIT_PRESS}\nis coming to its end, little by little.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("My role...{WAIT_PRESS}\nis ending...?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" You became a Pokémon in\norder to fulfill a certain role...")),
    MSG_NPC(1, _(" And that role brought\nyou here.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" Now, that role...{WAIT_PRESS}\nis finally drawing to its conclusion.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Gardevoir, tell me!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("What is my role?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Why did I become a Pokémon?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" When the time comes...")),
    MSG_NPC(1, _(" I think I can tell you when\nthis adventure is finished.")),
    MSG_NPC(1, _(" Au revoir...")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs162_g8_s1_lives0_dlg0[] = { /* 0x8213b50 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g9_s0_station_sref_script[] = { /* 0x8214480 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(5),
    { 0x27, 0x00,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs162_g9_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g9_s0_station_sref_script }; /* 0x8214520 */

static const struct ScriptCommand s_gs162_g9_s0_lives0_dlg0[] = { /* 0x821452c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............{WAIT_PRESS}Gardevoir...?") },
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(477),
    SELECT_LIVES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Gardevoir...{WAIT_PRESS}\nWill you tell me now?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Who or what I am...?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Yes.")),
    MSG_NPC(2, _(" The time has arrived.")),
    MSG_NPC(2, _(" Why you have come here?")),
    MSG_NPC(2, _(" I will tell you all there is\nto tell.")),
    MSG_NPC(2, _(" {NAME_0}, you have...")),
    MSG_NPC(2, _(" Come to save this world.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............{WAIT_PRESS}\nCame to save the world of Pokémon?{WAIT_PRESS}\nI did...?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.{WAIT_PRESS} We learned that\nthis world faced extinction.")),
    MSG_NPC(2, _(" And so we sought a hero.")),
    MSG_NPC(2, _(" But though we searched,\nnowhere could we find our hero.\nWe were becoming discouraged...")),
    MSG_NPC(2, _(" When we came across\na human.")),
    MSG_NPC(2, _(" {NAME_0}...{WAIT_PRESS}\nYou were that human.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Wa... {WAIT_PRESS}Wait a second!{WAIT_PRESS}\nHero? Me? That's too much!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'm not anything special like that?!") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" Yes.{WAIT_PRESS} That is also what you\nsaid the first time we met.")),
    MSG_NPC(2, _(" You said you were not\nstrong.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" But what we sought was\nnot power merely for display...")),
    MSG_NPC(2, _(" We sought true courage.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x00000000),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("True courage...?{WAIT_PRESS}\nThat...{WAIT_PRESS} I'm even less confident about that.") },
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" That, too, is what\nyou said when we met.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" It was then that you said\nthis.")),
    MSG_NPC(2, _(" To see if you were worthy\nto be our hero or not...")),
    MSG_NPC(2, _(" You asked that we put you\nto the test.")),
    MSG_NPC(2, _(" And only if you were found\nto be truly worthy...")),
    MSG_NPC(2, _(" Then you were to be told\nthe truth.")),
    MSG_NPC(2, _(" To fulfill your role\nclear of heart and mind, you then chose\nto erase your memory as a human...")),
    MSG_NPC(2, _(" And became a Pokémon of\nyour own will to fight alongside your\nfriends.")),
    MSG_NPC(2, _(" That is how you came to\nbe in this world.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I...{WAIT_PRESS}\nI did that?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Your courage has been\nproven.")),
    MSG_NPC(2, _(" Without question, you bear\nthe role of saving the world.")),
    MSG_NPC(2, _(" And that role...{WAIT_PRESS}\nIt is soon coming to its end.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...{WAIT_PRESS}Stopping the meteor from\ncrashing into this world...?{WAIT_PRESS}\nThat's my role?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.{WAIT_PRESS}\nAnd when that is accomplished...")),
    MSG_NPC(2, _(" You can return to your\nhuman world.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh...{WAIT_PRESS}\nSo I can go back to being a human...") },
    PORTRAIT_REP(0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Wait!{WAIT_PRESS}\nBut that means...") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.{WAIT_PRESS} It means...{WAIT_PRESS}\nParting ways with {NAME_1}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x00000005),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("{NAME_1}......{WAIT_PRESS}\nI have to leave?") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" {NAME_1} feels great\nkinship with you, {NAME_0}.")),
    MSG_NPC(2, _(" So, {NAME_0}, if you\nwere to leave...")),
    MSG_NPC(2, _(" Your friend would be\nheartbroken.")),
    MSG_NPC(2, _(" ...But there can be nothing\ndone.")),
    MSG_NPC(2, _(" Because there are\nencounters, there are also farewells...")),
    MSG_NPC(2, _(" ...{WAIT_PRESS}I, too, once had\na friend beyond value.")),
    MSG_NPC(2, _(" Truly, I cherished our\nfriendship...")),
    MSG_NPC(2, _(" But my friend has gone\naway.")),
    MSG_NPC(2, _(" It fills me with sadness\nstill, losing my friend...")),
    MSG_NPC(2, _(" ......{WAIT_PRESS}\nBut...{WAIT_PRESS} We will meet again...{WAIT_PRESS}\nThat is what I believe.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(485),
    { 0x28, 0x01,  0x0005,  0x00000018,  0x00ffffff, NULL },
    WAIT(10),
    { 0x27, 0x00,  0x0005,  0x00000018,  0x00ffffff, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0000, 0x0000000c),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...!{WAIT_PRESS} W-what was that?!") },
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" ............{WAIT_PRESS}Who was it?{WAIT_PRESS}\nSomeone appears to have been looking\ninto your dream.")),
    MSG_NPC(2, _(" But it is fine now.\nWhoever it was ran off.")),
    MSG_NPC(2, _(" ...All that remains in this\ndream is a feeling of sadness.")),
    MSG_NPC(2, _(" ...That Pokémon...\nI think ran off crying...")),
    MSG_NPC(2, _(" ............{WAIT_PRESS}\nIt will be morning soon.{WAIT_PRESS}\nAu revoir.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




















static const struct ScriptCommand s_gs162_g9_s1_lives0_dlg0[] = { /* 0x82157b8 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs162_g10_s0_station_sref_script[] = { /* 0x8215d28 */
    DEBUGINFO,
    SELECT_MAP(162),
    SELECT_ENTITIES(-1, 0),
    { 0x27, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs162_g10_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs162_g10_s0_station_sref_script }; /* 0x8215d98 */

static const struct ScriptCommand s_gs162_g10_s0_lives0_dlg0[] = { /* 0x8215da4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" You can return to your\nhuman world.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs162_g10_s0_lives1_dlg0[] = { /* 0x8215e54 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs162_g1_s0_lives[] = { /* 0x8215ea4 */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g1_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g2_s0_lives[] = { /* 0x8215ebc */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g2_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g3_s0_lives[] = { /* 0x8215ed4 */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g3_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g3_s1_lives[] = { /* 0x8215eec */
    /*  0 */ {  82,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g3_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g4_s0_lives[] = { /* 0x8215f04 */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g4_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g4_s1_lives[] = { /* 0x8215f1c */
    /*  0 */ {  82,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g4_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g5_s0_lives[] = { /* 0x8215f34 */
    /*  0 */ {  82,   4,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g5_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g6_s0_lives[] = { /* 0x8215f4c */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g6_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g6_s1_lives[] = { /* 0x8215f64 */
    /*  0 */ {  82,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g6_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g7_s0_lives[] = { /* 0x8215f7c */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g7_s0_lives0_dlg0,
    } },
    /*  1 */ {  82,   7,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g7_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g8_s0_lives[] = { /* 0x8215fac */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g8_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g8_s1_lives[] = { /* 0x8215fc4 */
    /*  0 */ {  82,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g8_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g9_s0_lives[] = { /* 0x8215fdc */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g9_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g9_s1_lives[] = { /* 0x8215ff4 */
    /*  0 */ {  82,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g9_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs162_g10_s0_lives[] = { /* 0x821600c */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g10_s0_lives0_dlg0,
    } },
    /*  1 */ {  82,   7,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs162_g10_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs162_g1_s0_effs[] = { /* 0x821603c */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g2_s0_effs[] = { /* 0x8216048 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs162_g2_s0_eff0_script },
};

static const struct GroundEffectData s_gs162_g3_s0_effs[] = { /* 0x8216054 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g4_s0_effs[] = { /* 0x8216060 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g5_s0_effs[] = { /* 0x821606c */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g6_s0_effs[] = { /* 0x8216078 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g7_s0_effs[] = { /* 0x8216084 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g8_s0_effs[] = { /* 0x8216090 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g9_s0_effs[] = { /* 0x821609c */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs162_g10_s0_effs[] = { /* 0x82160a8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82160b4 */
    &s_gs162_g0_s0_station_sref,
    &s_gs162_g1_s0_station_sref,
    &s_gs162_g2_s0_station_sref,
    &s_gs162_g3_s0_station_sref,
    &s_gs162_g4_s0_station_sref,
    &s_gs162_g5_s0_station_sref,
    &s_gs162_g6_s0_station_sref,
    &s_gs162_g7_s0_station_sref,
    &s_gs162_g8_s0_station_sref,
    &s_gs162_g9_s0_station_sref,
    &s_gs162_g10_s0_station_sref,
};

static const struct GroundScriptSector s_gs162_g0_sectors[] = { /* 0x82160e0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs162_g1_sectors[] = { /* 0x8216108 */
    { LPARRAY(s_gs162_g1_s0_lives), 0,NULL, LPARRAY(s_gs162_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs162_g2_sectors[] = { /* 0x8216130 */
    { LPARRAY(s_gs162_g2_s0_lives), 0,NULL, LPARRAY(s_gs162_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs162_g3_sectors[] = { /* 0x8216158 */
    { LPARRAY(s_gs162_g3_s0_lives), 0,NULL, LPARRAY(s_gs162_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
    { LPARRAY(s_gs162_g3_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs162_g4_sectors[] = { /* 0x82161a8 */
    { LPARRAY(s_gs162_g4_s0_lives), 0,NULL, LPARRAY(s_gs162_g4_s0_effs), 0,NULL, 1,&sStationScripts[4], },
    { LPARRAY(s_gs162_g4_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs162_g5_sectors[] = { /* 0x82161f8 */
    { LPARRAY(s_gs162_g5_s0_lives), 0,NULL, LPARRAY(s_gs162_g5_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs162_g6_sectors[] = { /* 0x8216220 */
    { LPARRAY(s_gs162_g6_s0_lives), 0,NULL, LPARRAY(s_gs162_g6_s0_effs), 0,NULL, 1,&sStationScripts[6], },
    { LPARRAY(s_gs162_g6_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs162_g7_sectors[] = { /* 0x8216270 */
    { LPARRAY(s_gs162_g7_s0_lives), 0,NULL, LPARRAY(s_gs162_g7_s0_effs), 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptSector s_gs162_g8_sectors[] = { /* 0x8216298 */
    { LPARRAY(s_gs162_g8_s0_lives), 0,NULL, LPARRAY(s_gs162_g8_s0_effs), 0,NULL, 1,&sStationScripts[8], },
    { LPARRAY(s_gs162_g8_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs162_g9_sectors[] = { /* 0x82162e8 */
    { LPARRAY(s_gs162_g9_s0_lives), 0,NULL, LPARRAY(s_gs162_g9_s0_effs), 0,NULL, 1,&sStationScripts[9], },
    { LPARRAY(s_gs162_g9_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs162_g10_sectors[] = { /* 0x8216338 */
    { LPARRAY(s_gs162_g10_s0_lives), 0,NULL, LPARRAY(s_gs162_g10_s0_effs), 0,NULL, 1,&sStationScripts[10], },
};

static const struct GroundScriptGroup s_gs162_groups[] = { /* 0x8216360 */
    { LPARRAY(s_gs162_g0_sectors) },
    { LPARRAY(s_gs162_g1_sectors) },
    { LPARRAY(s_gs162_g2_sectors) },
    { LPARRAY(s_gs162_g3_sectors) },
    { LPARRAY(s_gs162_g4_sectors) },
    { LPARRAY(s_gs162_g5_sectors) },
    { LPARRAY(s_gs162_g6_sectors) },
    { LPARRAY(s_gs162_g7_sectors) },
    { LPARRAY(s_gs162_g8_sectors) },
    { LPARRAY(s_gs162_g9_sectors) },
    { LPARRAY(s_gs162_g10_sectors) },
};

static const struct GroundLink s_gs162_links[] = { /* 0x82163b8 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs162 = { LPARRAY(s_gs162_groups), s_gs162_links }; /* 0x82163c0 */
