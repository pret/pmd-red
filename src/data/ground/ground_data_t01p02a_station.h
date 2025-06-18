

































static const struct ScriptCommand s_gs2_g0_s0_station_sref_script[] = { /* 0x817d60c */
    DEBUGINFO,
    SELECT_MAP(2),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_LE, 4, /* to label */ 0),
    COND(JUDGE_LE, 5, /* to label */ 1),
    COND(JUDGE_EQ, 6, /* to label */ 2),
    COND(JUDGE_EQ, 7, /* to label */ 3),
    COND(JUDGE_EQ, 8, /* to label */ 4),
    COND(JUDGE_EQ, 9, /* to label */ 5),
    COND(JUDGE_LE, 9, /* to label */ 6),
    COND(JUDGE_LT, 15, /* to label */ 6),
    COND(JUDGE_EQ, 15, /* to label */ 7),
    COND(JUDGE_EQ, 16, /* to label */ 8),
    COND(JUDGE_LT, 18, /* to label */ 9),
    COND(JUDGE_EQ, 18, /* to label */ 10),
    JUMP_LABEL(11),
  LABEL(0), /* = 0x00 */
    CALL_STATION( 10,  0),
    JUMP_LABEL(12),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 13),
    COND(JUDGE_LE, 4, /* to label */ 14),
    COND(JUDGE_LE, 7, /* to label */ 15),
    CALL_STATION( 13,  0),
    JUMP_LABEL(12),
  LABEL(13), /* = 0x0d */
    CALL_STATION( 10,  0),
    JUMP_LABEL(12),
  LABEL(14), /* = 0x0e */
    CALL_STATION( 11,  0),
    JUMP_LABEL(12),
  LABEL(15), /* = 0x0f */
    CALL_STATION( 12,  0),
    JUMP_LABEL(12),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 16),
    CALL_STATION( 14,  0),
    JUMP_LABEL(12),
  LABEL(16), /* = 0x10 */
    CALL_STATION( 13,  0),
    JUMP_LABEL(12),
  LABEL(3), /* = 0x03 */
    CALL_STATION( 14,  0),
    JUMP_LABEL(12),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 17),
    CALL_STATION( 15,  0),
    JUMP_LABEL(12),
  LABEL(17), /* = 0x11 */
    CALL_STATION( 14,  0),
    JUMP_LABEL(12),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 18),
    COND(JUDGE_LE, 5, /* to label */ 19),
    JUMP_LABEL(12),
  LABEL(18), /* = 0x12 */
    CALL_STATION( 15,  0),
    JUMP_LABEL(12),
  LABEL(19), /* = 0x13 */
    CALL_STATION( 16,  0),
    JUMP_LABEL(12),
  LABEL(6), /* = 0x06 */
    CALL_STATION( 19,  0),
    JUMP_LABEL(12),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 20),
    COND(JUDGE_LE, 5, /* to label */ 21),
    COND(JUDGE_LE, 7, /* to label */ 22),
    COND(JUDGE_LE, 11, /* to label */ 23),
    JUMP_LABEL(24),
  LABEL(20), /* = 0x14 */
    CALL_STATION( 20,  0),
    JUMP_LABEL(12),
  LABEL(21), /* = 0x15 */
    CALL_STATION( 21,  0),
    JUMP_LABEL(12),
  LABEL(22), /* = 0x16 */
    CALL_STATION( 22,  0),
    JUMP_LABEL(12),
  LABEL(23), /* = 0x17 */
    CALL_STATION( 23,  0),
    JUMP_LABEL(12),
  LABEL(24), /* = 0x18 */
    CALL_STATION( 24,  0),
    JUMP_LABEL(12),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 25),
    COND(JUDGE_LE, 4, /* to label */ 26),
    JUMP_LABEL(27),
  LABEL(25), /* = 0x19 */
    CALL_STATION( 25,  0),
    JUMP_LABEL(12),
  LABEL(26), /* = 0x1a */
    CALL_STATION( 26,  0),
    JUMP_LABEL(12),
  LABEL(27), /* = 0x1b */
    CALL_STATION( 27,  0),
    JUMP_LABEL(12),
  LABEL(9), /* = 0x09 */
    CALL_STATION( 27,  0),
    JUMP_LABEL(12),
  LABEL(10), /* = 0x0a */
    CALL_STATION( 30,  0),
    JUMP_LABEL(12),
  LABEL(11), /* = 0x0b */
    CALL_STATION(  1,  0),
    JUMP_LABEL(12),
  LABEL(12), /* = 0x0c */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 28),
    COND_EQUAL(8, /* to label */ 29),
  LABEL(28), /* = 0x1c */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(30),
  LABEL(29), /* = 0x1d */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(30),
  LABEL(30), /* = 0x1e */
    BGM_SWITCH(8),
    JUMPIF_SCENARIOCHECK(6, /* to label */ 31),
    JUMP_LABEL(32),
  LABEL(31), /* = 0x1f */
    SELECT_EVENTS(0, 2),
  LABEL(32), /* = 0x20 */
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs2_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs2_g0_s0_station_sref_script }; /* 0x817de6c */

static const struct ScriptCommand s_gs2_g0_s0_evt0_sref_script[] = { /* 0x817de78 */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs2_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs2_g0_s0_evt0_sref_script }; /* 0x817dea8 */

static const struct ScriptCommand s_gs2_g0_s1_lives0_dlg0[] = { /* 0x817deb4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs2_g0_s1_lives1_dlg0[] = { /* 0x817def4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs2_g0_s2_evt0_sref_script[] = { /* 0x817df34 */
    DEBUGINFO,
    JUMPIF(JUDGE_GT, UNIT_SUM, 1, /* to label */ 0),
    { 0x01, 0x00, -0x0001,  0x00000008,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The entrance is too narrow.\n{CENTER_ALIGN}There is only room for one.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Come alone to enter!") },
    TEXTBOX_CLEAR,
    RET,
};

static const struct ScriptRef s_gs2_g0_s2_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs2_g0_s2_evt0_sref_script }; /* 0x817e018 */

static const struct ScriptCommand s_gs2_g0_s2_lives0_dlg0[] = { /* 0x817e024 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs2_g0_s2_lives1_dlg0[] = { /* 0x817e064 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs2_g1_s0_station_sref_script[] = { /* 0x817e0a4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g1_s0_station_sref_script }; /* 0x817e0e4 */

static const struct ScriptCommand s_gs2_g1_s0_lives0_dlg0[] = { /* 0x817e0f0 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g1_s0_lives0_dlg2[] = { /* 0x817e130 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    MSG_NPC(3, _(" I went into the cave, but...{WAIT_PRESS}\nI couldn't evolve into Butterfree.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" That's too bad, Metapod.")),
    MSG_NPC(2, _(" I bet you weren't high\nenough in level, Metapod.")),
    MSG_NPC(2, _(" If you train and raise your\nlevel, I think you'll be able to evolve.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh, so it's my level!{WAIT_PRESS}\nI get it! I'll work at leveling up!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g1_s0_lives1_dlg0[] = { /* 0x817e380 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g1_s0_lives1_dlg2[] = { /* 0x817e3c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    MSG_NPC(3, _(" I went into the cave, but...{WAIT_PRESS}\nI couldn't evolve into Butterfree.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" That's too bad, Metapod.")),
    MSG_NPC(2, _(" I bet you weren't high\nenough in level, Metapod.")),
    MSG_NPC(2, _(" If you train and raise your\nlevel, I think you'll be able to evolve.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh, so it's my level!{WAIT_PRESS}\nI get it! I'll work at leveling up!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g1_s0_lives2_dlg0[] = { /* 0x817e4e0 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g1_s0_lives2_dlg2[] = { /* 0x817e520 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" The Jumpluff appear to\nhave left on the winds.")),
    MSG_NPC(1, _(" I shall miss them...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g1_s0_obj0_dlg2[] = { /* 0x817e5d8 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g2_s0_station_sref_script[] = { /* 0x817e608 */
    DEBUGINFO,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB2, 33, 3, /* to label */ 1),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 1, /* to label */ 2),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 3, /* to label */ 3),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 5, /* to label */ 4),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 6, /* to label */ 4),
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 2, /* to label */ 5),
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, -1, /* to label */ 5),
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 4, /* to label */ 6),
    JUMPIF_SUM(JUDGE_LT, EVENT_S07E01, 11, /* to label */ 6),
  LABEL(5), /* = 0x05 */
    RET_DIRECT,
  LABEL(1), /* = 0x01 */
    SELECT_ENTITIES(3, 0),
    RET_DIRECT,
  LABEL(6), /* = 0x06 */
    SELECT_ENTITIES(4, 0),
    RET_DIRECT,
  LABEL(2), /* = 0x02 */
    SELECT_ENTITIES(5, 0),
    RET_DIRECT,
  LABEL(3), /* = 0x03 */
    SELECT_ENTITIES(7, 0),
    RET_DIRECT,
  LABEL(4), /* = 0x04 */
    SELECT_ENTITIES(9, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g2_s0_station_sref_script }; /* 0x817e7e8 */

static const struct ScriptCommand s_gs2_g3_s0_lives0_dlg0[] = { /* 0x817e7f4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g3_s0_lives0_dlg2[] = { /* 0x817e834 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 33, 3, /* to label */ 0),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" Ah, so you wish to know\nabout the dungeon in the sea?")),
    MSG_NPC(1, _(" I, too, have heard of it.")),
    MSG_NPC(1, _(" I have heard of a place that\nis far off our coast...")),
    MSG_NPC(1, _(" It is a sea churned by\ntorrential storms and violent waves.")),
    MSG_NPC(1, _(" It is a place appropriately\nnamed the {COLOR YELLOW_D}Stormy Sea{RESET}.")),
    MSG_NPC(1, _(" There, one will find a\ndungeon that leads to the bottom of\nthe sea.")),
    MSG_NPC(1, _(" The sea is infinitely dark,\nand its depth unimaginable.\nThat is what I have heard.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" Hohoho!{WAIT_PRESS}\nYou look eager to go.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" However...{WAIT_PRESS}\nTo go beneath the sea, a Hidden Machine\nnamed {COLOR GREEN_I}Dive{RESET} is needed.")),
    MSG_NPC(1, _(" Without {COLOR GREEN_I}Dive{RESET}, you cannot\ngo to the {COLOR YELLOW_D}Stormy Sea{RESET}.")),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" Hohoho! Your face tells me\nyou are desperate to go.")),
    MSG_NPC(1, _(" So be it.{WAIT_PRESS}\nYou may have this.")),
    TEXTBOX_CLEAR,
    WAIT(20),
    { 0x3c, 0x2c,  0x0000,  0x000000e7,  0x00000000, NULL },
    WAIT(20),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" I understand that it is\na very rare item that was found in a place\ncalled the {COLOR YELLOW_D}Solar Cave{RESET}.")),
    MSG_NPC(1, _(" If you were to carry that\nHidden Machine as an item...")),
    MSG_NPC(1, _(" Or if any team member\nwishing to enter the dungeon used that\nHidden Machine to learn {COLOR GREEN_I}Dive{RESET}...")),
    MSG_NPC(1, _(" You would be able to enter\nthe {COLOR YELLOW_D}Stormy Sea{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Stormy Sea{RESET}!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(20),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Beware--you must take the HM {COLOR GREEN_I}Dive{RESET},\n{CENTER_ALIGN}or a team member must learn {COLOR GREEN_I}Dive{RESET}\n{CENTER_ALIGN}as a move for the team to enter!") },
    TEXTBOX_CLEAR,
    BGM_SWITCH(8),
    { 0xaf, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB2, 33,  4),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    MSG_NPC(1, _(" If you were to carry the\nHidden Machine {COLOR GREEN_I}Dive{RESET} as an item...")),
    MSG_NPC(1, _(" Or if any team member\nwishing to enter the dungeon used that\nHidden Machine to learn {COLOR GREEN_I}Dive{RESET}...")),
    MSG_NPC(1, _(" You would be able to enter\nthe {COLOR YELLOW_D}Stormy Sea{RESET}.")),
    MSG_NPC(1, _(" Oh?{WAIT_PRESS}\nWhat happens if you lose the\nHidden Machine {COLOR GREEN_I}Dive{RESET}?")),
    MSG_NPC(1, _(" All I had was the one\nI gave you...{WAIT_PRESS}\nHmm... What should one do?")),
    MSG_NPC(1, _(" The Hidden Machine {COLOR GREEN_I}Dive{RESET}\nwas apparently found in the {COLOR YELLOW_D}Solar Cave{RESET}.")),
    MSG_NPC(1, _(" I suppose it wouldn't hurt\nto search there.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" Hohoho.{WAIT_PRESS}\nAdventures keep you young.")),
    MSG_NPC(1, _(" Why, if I were only a little\nyounger, I might have joined you on your\nadventures.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
    RET,
};





static const struct ScriptCommand s_gs2_g3_s0_lives0_dlg3[] = { /* 0x817f2d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 33, 3, /* to label */ 0),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(12),
    RET,
  LABEL(0), /* = 0x00 */
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g3_s0_obj0_dlg2[] = { /* 0x817f474 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g4_s0_lives0_dlg0[] = { /* 0x817f4a4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g4_s0_lives0_dlg2[] = { /* 0x817f4e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SET_ARRAYVAL(EVENT_S07E01,  3,  1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" Hohoho.{WAIT_PRESS}\nThere is an old saying about the {COLOR YELLOW_D}Buried\nRelic{RESET}.")),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" Three parts there are,\nguarded by three disciples.")),
    MSG_NPC(1, _(" When the three parts\nare gathered in hand...{WAIT_PRESS}\nA mirage shall appear to the bearer...")),
    MSG_NPC(1, _(" ...What this actually means,\nthere is no telling now. Hohoho.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs2_g4_s0_lives0_dlg3[] = { /* 0x817f6b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g4_s0_obj0_dlg2[] = { /* 0x817f758 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g5_s0_lives0_dlg2[] = { /* 0x817f788 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 6, 0),
    HALT,
};

static const struct ScriptCommand s_gs2_g5_s0_lives1_dlg2[] = { /* 0x817f7b8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 6, 0),
    HALT,
};

static const struct ScriptCommand s_gs2_g5_s0_evt0_sref_script[] = { /* 0x817f7e8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 6, 0),
    HALT,
};

static const struct ScriptRef s_gs2_g5_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs2_g5_s0_evt0_sref_script }; /* 0x817f818 */

static const struct ScriptCommand s_gs2_g6_s0_station_sref_script[] = { /* 0x817f824 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_SUB8, 51, 2, /* to label */ 0),
    SCENARIO_CALC(SCENARIO_SUB8, 51,  2),
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptRef s_gs2_g6_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs2_g6_s0_station_sref_script }; /* 0x817f894 */

static const struct ScriptCommand s_gs2_g6_s0_eff0_script[] = { /* 0x817f8a0 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g6_s0_lives0_dlg0[] = { /* 0x817f910 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x95, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" ........................")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" ........................")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" ...We've found it at last!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yesss! Find it we did!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000001),
    PORTRAIT_REP(0x0003, 0x00000002),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" My wish...\nIt will finally come true!{WAIT_PRESS}\nPshehehe!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(3, _(" Hey, now, don't forget about\nmy wish!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" Listen, {NAME_3}.{WAIT_PRESS}\nWe must keep this a secret just between\nthe two of us.")),
    MSG_NPC(2, _(" We can't tell any Pokémon.\nNot even Gengar.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" I know that!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Let's decide on how\nwe're going to do this...{WAIT_PRESS} First...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0002, 0x00000002),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0003, 0x00000001),
    CJUMP_UNK_C8(92),
    COND_EQUAL(6, /* to label */ 3),
    COND_EQUAL(5, /* to label */ 3),
    COND_EQUAL(7, /* to label */ 3),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000001),
  LABEL(3), /* = 0x03 */
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Aiyeeeeeeeeeeeh!")),
    TEXTBOX_CLEAR,
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT_REP(0x0002, 0x00000000),
    PORTRAIT_REP(0x0003, 0x00000000),
    MSG_NPC(2, _(" I...{WAIT_PRESS}\nI don't know anything!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Me too!\nI don't know a thing!")),
    MSG_NPC(3, _(" I don't know anything about\nmaking wishes come true!{WAIT_PRESS}\nI know nothing!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x93, 0x08,  0x000a,  0x0000005d,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CANCEL_EVENTS(5, 0),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs2_g6_s0_lives1_dlg0[] = { /* 0x818009c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g6_s0_lives2_dlg0[] = { /* 0x81800fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(60),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    CJUMP_UNK_C8(0),
    COND_EQUAL(2, /* to label */ 0),
    { 0x6b, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x6b, 0x00,  0x0200,  0x00000001,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x6b, 0x00,  0x0200,  0x00000003,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g6_s0_lives3_dlg0[] = { /* 0x818034c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(60),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(0),
    COND_EQUAL(2, /* to label */ 0),
    { 0x6b, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x6b, 0x00,  0x0200,  0x00000002,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x6b, 0x00,  0x0200,  0x00000003,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g7_s0_lives0_dlg2[] = { /* 0x81804fc */
    DEBUGINFO,
    EXECUTE_STATION(-1, 8, 0),
    HALT,
};

static const struct ScriptCommand s_gs2_g7_s0_lives1_dlg2[] = { /* 0x818052c */
    DEBUGINFO,
    EXECUTE_STATION(-1, 8, 0),
    HALT,
};

static const struct ScriptCommand s_gs2_g7_s0_evt0_sref_script[] = { /* 0x818055c */
    DEBUGINFO,
    EXECUTE_STATION(-1, 8, 0),
    HALT,
};

static const struct ScriptRef s_gs2_g7_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs2_g7_s0_evt0_sref_script }; /* 0x818058c */

static const struct ScriptCommand s_gs2_g8_s0_station_sref_script[] = { /* 0x8180598 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_SUB8, 51, 3, /* to label */ 0),
    SCENARIO_CALC(SCENARIO_SUB8, 51,  4),
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptRef s_gs2_g8_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs2_g8_s0_station_sref_script }; /* 0x8180608 */

static const struct ScriptCommand s_gs2_g8_s0_eff0_script[] = { /* 0x8180614 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g8_s0_lives0_dlg0[] = { /* 0x8180674 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x95, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" {NAME_3}, listen.{WAIT_PRESS}\nI'm thinking it is best if only we go\ninto the dungeon.")),
    MSG_NPC(2, _(" If either one of us\nfalls before the end...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh, I get it.{WAIT_PRESS}\nThe other one can still go make wishes!")),
    MSG_NPC(3, _(" That's smart, {NAME_2}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000001),
    MSG_NPC(2, _(" But of course.\nI can't wait until our wishes\ncome true〜♪")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0003, 0x00000002),
    MSG_NPC(3, _(" My wish is for a broader\nlower jaw.")),
    MSG_NPC(3, _(" I want bigger jaws so I can\nswallow bigger things whole.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000003),
    MSG_NPC(2, _(" My wish is for a place\nwhere I can meditate in peace〜♪")),
    MSG_NPC(2, _(" With no one to bother me...")),
    MSG_NPC(2, _(" It would be magnificent\nif I could meditate for a year without\nfood〜♪")),
    TEXTBOX_CLEAR,
    WAIT(60),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0002, 0x00000002),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0003, 0x00000001),
    CJUMP_UNK_C8(92),
    COND_EQUAL(6, /* to label */ 4),
    COND_EQUAL(5, /* to label */ 4),
    COND_EQUAL(7, /* to label */ 4),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000001),
  LABEL(4), /* = 0x04 */
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Giyaaaaaaaaaaaaaaaaah!")),
    TEXTBOX_CLEAR,
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT_REP(0x0002, 0x00000000),
    PORTRAIT_REP(0x0003, 0x00000000),
    MSG_NPC(2, _(" I...{WAIT_PRESS}\nI don't know anything!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Me too!\nI don't know a thing!")),
    MSG_NPC(3, _(" I don't know anything about\na dungeon that makes wishes come true!{WAIT_PRESS}\nI know nothing!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x93, 0x08,  0x000a,  0x0000005d,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CANCEL_EVENTS(7, 0),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};





static const struct ScriptCommand s_gs2_g8_s0_lives1_dlg0[] = { /* 0x8180dc0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g8_s0_lives2_dlg0[] = { /* 0x8180e20 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(60),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    CJUMP_UNK_C8(0),
    COND_EQUAL(2, /* to label */ 0),
    { 0x6b, 0x00,  0x0200,  0x00000006,  0x00000000, NULL },
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x6b, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x6b, 0x00,  0x0200,  0x00000009,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g8_s0_lives3_dlg0[] = { /* 0x8181010 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(60),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(0),
    COND_EQUAL(2, /* to label */ 0),
    { 0x6b, 0x00,  0x0200,  0x00000006,  0x00000000, NULL },
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x6b, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x6b, 0x00,  0x0200,  0x00000009,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g9_s0_lives0_dlg0[] = { /* 0x81811c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g9_s0_lives0_dlg2[] = { /* 0x8181200 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 9, 1),
    HALT,
};

static const struct ScriptCommand s_gs2_g9_s1_station_sref_script[] = { /* 0x8181230 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_SUB8, 51, 5, /* to label */ 0),
    SCENARIO_CALC(SCENARIO_SUB8, 51,  6),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(9, 0),
    RET,
};

static const struct ScriptRef s_gs2_g9_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs2_g9_s1_station_sref_script }; /* 0x81812b0 */

static const struct ScriptCommand s_gs2_g9_s1_eff0_script[] = { /* 0x81812bc */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xa1, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g9_s1_lives0_dlg0[] = { /* 0x818131c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" ...I got KO'd in that\ndungeon, but what about Medicham?\nHope she's OK...")),
    MSG_NPC(2, _(" I hope she gets to the end\nand gets my wish to come true...")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000001),
    MSG_NPC(2, _(" Giyah!")),
    TEXTBOX_CLEAR,
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(2, _(" Wh-what are you staring\nat, you?!")),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" I'm having a hard time\ntrying to make up my mind!{WAIT_PRESS}\nGet lost!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" ...Hunh? Wait a second...\nMaybe I shouldn't be wishing for\na bigger lower jaw...?")),
    MSG_NPC(2, _(" I wonder if it'd be better\nif I could coil myself tighter...")),
    MSG_NPC(2, _(" ...Hmm...\nMutter...")),
    TEXTBOX_CLEAR,
    { 0xa1, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs2_g9_s1_lives1_dlg0[] = { /* 0x81816d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g9_s1_lives2_dlg0[] = { /* 0x8181730 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(60),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x92, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g10_s0_station_sref_script[] = { /* 0x8181870 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g10_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g10_s0_station_sref_script }; /* 0x81818a0 */

static const struct ScriptCommand s_gs2_g10_s0_lives0_dlg0[] = { /* 0x81818ac */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g10_s0_lives0_dlg2[] = { /* 0x81818ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" I've heard fissures have\nopened up in the ground here and there.\nThey're trouble for everyone.")),
    MSG_NPC(1, _(" It worries me to no\nend, thinking that children will fall\ndown into them...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g10_s0_obj0_dlg2[] = { /* 0x8181a20 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g11_s0_station_sref_script[] = { /* 0x8181a50 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g11_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g11_s0_station_sref_script }; /* 0x8181a80 */

static const struct ScriptCommand s_gs2_g11_s0_lives0_dlg0[] = { /* 0x8181a8c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g11_s0_lives0_dlg2[] = { /* 0x8181acc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I've lived in this pond for\nmany long years...")),
    MSG_NPC(1, _(" But never have I seen such\nfrequent natural disasters...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g11_s0_obj0_dlg2[] = { /* 0x8181bac */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g12_s0_station_sref_script[] = { /* 0x8181bdc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g12_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g12_s0_station_sref_script }; /* 0x8181c0c */

static const struct ScriptCommand s_gs2_g12_s0_lives0_dlg0[] = { /* 0x8181c18 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g12_s0_lives0_dlg2[] = { /* 0x8181c58 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Seeing the innocence of\nchildren at play is a good thing.\nHohoho.")),
    MSG_NPC(1, _(" When I was small...{WAIT_PRESS}\nI was tiny...{WAIT_PRESS}\nHohoho.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g12_s0_obj0_dlg2[] = { /* 0x8181d3c */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g12_s0_lives1_dlg2[] = { /* 0x8181d6c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh! {NAME_0} and\n{NAME_2}! Long time no see!")),
    MSG_NPC(1, _(" I have a new friend!")),
    MSG_NPC(1, _(" His name is {NAME_3}.")),
    MSG_NPC(1, _(" I'm going to call on\n{NAME_3} and go play in the woods!\nIt's going to be fun!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g13_s0_station_sref_script[] = { /* 0x8181ebc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g13_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g13_s0_station_sref_script }; /* 0x8181eec */

static const struct ScriptCommand s_gs2_g13_s0_lives0_dlg0[] = { /* 0x8181ef8 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g13_s0_lives0_dlg2[] = { /* 0x8181f38 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I've not seen {NAME_2}\nor other children lately.\nI wonder how they are keeping.")),
    MSG_NPC(1, _(" Not seeing the children\ngives me a twinge of sadness...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g13_s0_obj0_dlg2[] = { /* 0x8182044 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g14_s0_station_sref_script[] = { /* 0x8182074 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g14_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g14_s0_station_sref_script }; /* 0x81820a4 */

static const struct ScriptCommand s_gs2_g14_s0_lives0_dlg0[] = { /* 0x81820b0 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g14_s0_lives0_dlg2[] = { /* 0x81820f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" It's good to see the\nyoungsters back.")),
    MSG_NPC(1, _(" I heard you saved them.{WAIT_PRESS}\nGetting through the dungeon must have\nbeen very taxing on you.")),
    MSG_NPC(1, _(" I'm also grateful for what\nyou've done. Thank you.")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Incidentally...{WAIT_PRESS}\nI have heard of a particularly challenging\ndungeon somewhere in our world.")),
    MSG_NPC(1, _(" It starts your level at one...{WAIT_PRESS}\nclears all your gained stats...{WAIT_PRESS}\nand empties your Toolbox at the start.")),
    MSG_NPC(1, _(" In other words, it forces\none to enter in a completely clean state.")),
    MSG_NPC(1, _(" It has never been conquered\nby any rescue team...")),
    MSG_NPC(1, _(" It has earned its title as\nthe {COLOR YELLOW_D}Ultimate Dungeon{RESET}...")),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" Perhaps your team will take\non that challenge one day? Hohoho!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g14_s0_obj0_dlg2[] = { /* 0x8182484 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g14_s0_lives1_dlg2[] = { /* 0x81824b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I can play with {NAME_2}\nagain!")),
    MSG_NPC(1, _(" Thank you!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g14_s0_lives2_dlg2[] = { /* 0x818255c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_0} and\n{NAME_2}, thank you!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g15_s0_station_sref_script[] = { /* 0x81825e8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g15_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g15_s0_station_sref_script }; /* 0x8182618 */

static const struct ScriptCommand s_gs2_g15_s0_lives0_dlg0[] = { /* 0x8182624 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g15_s0_lives0_dlg2[] = { /* 0x8182664 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0001, 0x00000001),
    MSG_NPC(1, _(" Seeing children at play is\nwhat I most enjoy now.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g15_s0_obj0_dlg2[] = { /* 0x8182708 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g15_s0_lives1_dlg0[] = { /* 0x8182738 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g15_s0_lives1_dlg2[] = { /* 0x8182768 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" Yay, {NAME_3}!\nWhat'll we do next?")),
    MSG_NPC(3, _(" Let's play battle!")),
    MSG_NPC(2, _(" OK, I use String Shot!")),
    MSG_NPC(3, _(" Then, I use Harden!")),
    MSG_NPC(2, _(" Ahahaha!")),
    MSG_NPC(3, _(" Ahahaha!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g15_s0_lives2_dlg0[] = { /* 0x81828d4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g15_s0_lives2_dlg2[] = { /* 0x8182904 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" Yay, {NAME_3}!\nWhat'll we do next?")),
    MSG_NPC(3, _(" Let's play battle!")),
    MSG_NPC(2, _(" OK, I use String Shot!")),
    MSG_NPC(3, _(" Then, I use Harden!")),
    MSG_NPC(2, _(" Ahahaha!")),
    MSG_NPC(3, _(" Ahahaha!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g16_s0_station_sref_script[] = { /* 0x81829f4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g16_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g16_s0_station_sref_script }; /* 0x8182a24 */

static const struct ScriptCommand s_gs2_g16_s0_lives0_dlg0[] = { /* 0x8182a30 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g16_s0_lives0_dlg2[] = { /* 0x8182a70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000063,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Hohoho.\nYou wish to hear me tell old folklore?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" What was that?\nYou wish to hear the {COLOR GREEN}{NAME_2} legend{RESET}?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("No.")),
  LABEL(1), /* = 0x01 */
    BGM_FADEOUT(90),
    MSG_NPC(1, _(" Hohoho. Fine, then.{WAIT_PRESS}\nLet me recount the tale.")),
    TEXTBOX_CLEAR,
    EXECUTE_STATION(-1, 16, 1),
    HALT,
  LABEL(2), /* = 0x02 */
    MSG_NPC(1, _(" I see.")),
    MSG_NPC(1, _(" If you feel the urge to hear\nmy tale, come see me anytime. Hohoho.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs2_g16_s0_obj0_dlg2[] = { /* 0x8182cb8 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g16_s0_lives1_dlg2[] = { /* 0x8182ce8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000062,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_2} told us\nfolklore from long ago.")),
    MSG_NPC(1, _(" It was fun.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g16_s0_lives2_dlg2[] = { /* 0x8182da0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000062,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" The folklore was fun and\ninteresting.{WAIT_PRESS}\n{NAME_2} is very wise.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g16_s0_eff0_script[] = { /* 0x8182e4c */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g16_s1_station_sref_script[] = { /* 0x8182eac */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 9, 5, /* to label */ 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  5),
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptRef s_gs2_g16_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs2_g16_s1_station_sref_script }; /* 0x8182f0c */

static const struct ScriptCommand s_gs2_g16_s1_lives0_dlg0[] = { /* 0x8182f18 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000063,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x00000052,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x6b, 0x00,  0x0100,  0x0000000c,  0x00000000, NULL },
    { 0x8b, 0x1e,  0x0004,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(6),
    MSG_NPC(1, _(" There once lived a Pokémon\nby the name of {NAME_2}.")),
    TEXTBOX_CLEAR,
    MSG_NPC(1, _(" Now, {NAME_2} had\nmany tails, all of them imbued with\npsychic power...")),
    MSG_NPC(1, _(" It was said that anyone so\nfoolish as to touch a tail would be cursed\nfor a thousand years.")),
    MSG_NPC(1, _(" But there was someone\nso foolish as to grab a tail.{WAIT_PRESS}\nAnd it was a human.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000004),
    MSG_NPC(3, _(" A human?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Yes, a human.")),
    MSG_NPC(1, _(" As one might expect, the\nhuman that grabbed the tail was subjected\nto a thousand-year curse.")),
    MSG_NPC(1, _(" However, just when the\ncurse was cast, a Pokémon named\n{NAME_4} shielded the human...")),
    MSG_NPC(1, _(" And sacrificed herself to\nabsorb the curse.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Why?")),
    MSG_NPC(3, _(" Why would that Pokémon,\nGardevoir, take the human's place?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" To {NAME_4}, that human\nwas her partner.")),
    MSG_NPC(1, _(" There exist strong bonds\nbetween humans and Pokémon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 3),
    VARIANT(/* == */  1, _(" ...All right.{WAIT_PRESS}\nBut humans... Aren't there good ones and\nbad ones too?")),
    VARIANT_DEFAULT(_(" ...OK.{WAIT_PRESS}\nBut humans... Aren't there good humans\nand bad ones too?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Correct.")),
    MSG_NPC(1, _(" Taking pity on {NAME_4},\n{NAME_2} asked the human this...")),
    MSG_NPC(1, _(" “Do you wish to save\n{NAME_4}?” it asked...")),
    MSG_NPC(1, _(" But the human had already\nabandoned {NAME_4} and fled.")),
    MSG_NPC(1, _(" {NAME_2} became\ndisillusioned with the human...")),
    MSG_NPC(1, _(" And it made this prediction...")),
    MSG_NPC(1, _(" “That human will one day\nbe reborn as a Pokémon...”")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(466),
    CALL_SCRIPT(SHOCK_FUNC),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x0000000c),
    MSG_NPC(3, _(" What?!{WAIT_PRESS}\nA human turn into a Pokémon?!")),
    TEXTBOX_CLEAR,
    WAIT(20),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    WAIT(60),
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    MSG_NPC(1, _(" “And when the human \nbecomes a Pokémon...”")),
    MSG_NPC(1, _(" “The world's balance will\nbe upset...”")),
    MSG_NPC(1, _(" ...And that is how the legend\nends.")),
    MSG_NPC(1, _(" Well?\nDid you find it interesting?")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(120),
    WAIT(80),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000005),
    MSG_NPC(3, _(" ........................")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Ah-hah!{WAIT_PRESS}\nYou found it so interesting, you're at\na loss for words? Hohoho.")),
    MSG_NPC(1, _(" There's no need to wear\nsuch a serious expression.")),
    MSG_NPC(1, _(" Certainly some rumors say\nthat the legend may actually be true...")),
    MSG_NPC(1, _(" But it is only ancient\nfolklore, nothing more.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000001),
    MSG_NPC(1, _(" If you feel the urge to hear\nmy tale again, come see me. Hohoho.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(8),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g16_s1_lives1_dlg0[] = { /* 0x8183b64 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000d,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(466),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    WAIT(60),
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g16_s1_lives2_dlg0[] = { /* 0x8183c84 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs2_g16_s1_lives2_dlg2[] = { /* 0x8183d24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000063,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Hohoho.\nYou wish to hear me tell old folklore?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" What was that?\nYou wish to hear the {COLOR GREEN}{NAME_2} legend{RESET}?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("No.")),
  LABEL(1), /* = 0x01 */
    MSG_NPC(1, _(" Hohoho. Fine, then.{WAIT_PRESS}\nLet me recount the tale.")),
    EXECUTE_STATION(-1, 16, 1),
    HALT,
  LABEL(2), /* = 0x02 */
    MSG_NPC(1, _(" I see.")),
    MSG_NPC(1, _(" If you feel the urge to hear\nmy tale again, come see me anytime.\nHohoho.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs2_g17_s0_station_sref_script[] = { /* 0x8183ea0 */
    DEBUGINFO,
    SELECT_MAP(2),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs2_g17_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs2_g17_s0_station_sref_script }; /* 0x8183f10 */

static const struct ScriptCommand s_gs2_g18_s0_station_sref_script[] = { /* 0x8183f1c */
    DEBUGINFO,
    SELECT_MAP(2),
    SELECT_ENTITIES(-1, 0),
    { 0x27, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs2_g18_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs2_g18_s0_station_sref_script }; /* 0x8183f8c */

static const struct ScriptCommand s_gs2_g18_s0_lives0_dlg0[] = { /* 0x8183f98 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_NPC(2, _(" Yes, a human.")),
    MSG_NPC(2, _(" As one might expect, the\nhuman that grabbed the tail was subjected\nto a curse of a thousand years.")),
    MSG_NPC(2, _(" However, just when the\ncurse was cast, a Pokémon named\n{NAME_3} shielded the human...")),
    MSG_NPC(2, _(" And sacrificed herself to\nabsorb the curse.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000004),
    MSG_NPC(1, _(" Why?")),
    MSG_NPC(1, _(" Why would that Pokémon,\nGardevoir, take the human's place?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" To {NAME_3}, that human\nwas her partner.")),
    MSG_NPC(2, _(" There exist strong bonds\nbetween humans and Pokémon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs2_g18_s0_lives1_dlg0[] = { /* 0x81841f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g18_s0_lives2_dlg0[] = { /* 0x8184230 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g19_s0_station_sref_script[] = { /* 0x8184280 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g19_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g19_s0_station_sref_script }; /* 0x81842b0 */

static const struct ScriptCommand s_gs2_g19_s0_lives0_dlg0[] = { /* 0x81842bc */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g19_s0_lives0_dlg1[] = { /* 0x81842fc */
    DEBUGINFO,
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs2_g20_s0_station_sref_script[] = { /* 0x818431c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g20_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g20_s0_station_sref_script }; /* 0x818435c */

static const struct ScriptCommand s_gs2_g20_s0_lives0_dlg0[] = { /* 0x8184368 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g20_s0_lives0_dlg2[] = { /* 0x81843a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I regret this...{WAIT_PRESS}\nHow some old folklore I told...{WAIT_PRESS}\ncould cause such an uproar...")),
    MSG_NPC(1, _(" I got carried away and\nrecounted that tale...{WAIT_PRESS}\nI should've left well enough alone...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g20_s0_obj0_dlg2[] = { /* 0x81844c8 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g20_s0_lives1_dlg0[] = { /* 0x81844f8 */
    DEBUGINFO,
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 30, -1, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g20_s0_lives1_dlg2[] = { /* 0x8184568 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm so glad {NAME_0}\nisn't under suspicion anymore.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g20_s0_lives2_dlg2[] = { /* 0x81845fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I just knew {NAME_0}\ncouldn't be evil.")),
    MSG_NPC(1, _(" I hope you keep doing good\nwith your rescue work!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g21_s0_station_sref_script[] = { /* 0x81846c8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g21_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g21_s0_station_sref_script }; /* 0x8184708 */

static const struct ScriptCommand s_gs2_g21_s0_lives0_dlg0[] = { /* 0x8184714 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g21_s0_lives0_dlg2[] = { /* 0x8184754 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Wroooar!\nI can't relax!")),
    MSG_NPC(1, _(" My whiskers...{WAIT_PRESS}\nThey tell me of coming earthquakes.")),
    MSG_NPC(1, _(" And many quakes are indeed\ncoming.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g21_s0_obj0_dlg2[] = { /* 0x818484c */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g21_s0_lives1_dlg0[] = { /* 0x818487c */
    DEBUGINFO,
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 30, -1, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g21_s0_lives1_dlg2[] = { /* 0x81848ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" That earthquake really\nfrightened me...")),
    MSG_NPC(1, _(" I was so scared, I spat silk\nall over the place...{WAIT_PRESS}\nIt was a mess for everyone...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g21_s0_lives2_dlg2[] = { /* 0x81849e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I hardened when the quake\nhit...")),
    MSG_NPC(1, _(" I couldn't take a step...{WAIT_PRESS}\nI was just shaking inside my shell...")),
    MSG_NPC(1, _(" Waaah!\nThinking about it is scary!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g22_s0_station_sref_script[] = { /* 0x8184af0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g22_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g22_s0_station_sref_script }; /* 0x8184b30 */

static const struct ScriptCommand s_gs2_g22_s0_lives0_dlg0[] = { /* 0x8184b3c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g22_s0_lives0_dlg2[] = { /* 0x8184b7c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Wroooar!\nI can't relax!")),
    MSG_NPC(1, _(" My whiskers...{WAIT_PRESS}\nThey tell me of coming earthquakes.")),
    MSG_NPC(1, _(" And many quakes are indeed\ncoming.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g22_s0_obj0_dlg2[] = { /* 0x8184bfc */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g22_s0_lives1_dlg0[] = { /* 0x8184c2c */
    DEBUGINFO,
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 30, -1, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g22_s0_lives1_dlg2[] = { /* 0x8184c9c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm terrified of all the\nearthquakes...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g22_s0_lives2_dlg2[] = { /* 0x8184d28 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I haven't relaxed from\nhardening at all...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g23_s0_station_sref_script[] = { /* 0x8184db8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g23_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g23_s0_station_sref_script }; /* 0x8184df8 */

static const struct ScriptCommand s_gs2_g23_s0_lives0_dlg0[] = { /* 0x8184e04 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g23_s0_lives0_dlg2[] = { /* 0x8184e44 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Your words in the square\nstruck me to my heart.")),
    MSG_NPC(1, _(" I shouldn't be panicking.{WAIT_PRESS}\nI have the ability to sense quakes.\nI must remain calm.")),
    MSG_NPC(1, _(" It appears I've learned\nsomething from you youngsters.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g23_s0_obj0_dlg2[] = { /* 0x8184f8c */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g23_s0_lives1_dlg0[] = { /* 0x8184fbc */
    DEBUGINFO,
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 30, -1, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g23_s0_lives1_dlg2[] = { /* 0x818502c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_0}!\nPlease take care!")),
    MSG_NPC(1, _(" We'll be OK.\nWe'll try not to be scared of the quakes!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g23_s0_lives2_dlg2[] = { /* 0x8185100 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'll do my best to harden\nmyself!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g24_s0_station_sref_script[] = { /* 0x8185188 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g24_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g24_s0_station_sref_script }; /* 0x81851c8 */

static const struct ScriptCommand s_gs2_g24_s0_lives0_dlg0[] = { /* 0x81851d4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g24_s0_lives0_dlg2[] = { /* 0x8185214 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Sniffle...\nThis is so inspiring...")),
    MSG_NPC(1, _(" Pokémon have united in\ntheir efforts to rescue Alakazam's team...")),
    MSG_NPC(1, _(" I can feel their resolve...{WAIT_PRESS}\nThe same feeling...from everyone.\nSniffle...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g24_s0_obj0_dlg2[] = { /* 0x818534c */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g24_s0_lives1_dlg0[] = { /* 0x818537c */
    DEBUGINFO,
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 30, -1, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g24_s0_lives1_dlg2[] = { /* 0x81853ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" My mom has joined other\nPokémon to fight in the {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    MSG_NPC(1, _(" Mom is weak to fire, so it\nisn't easy for her...")),
    MSG_NPC(1, _(" But she is doing her best.")),
    MSG_NPC(1, _(" Mom also told me...{WAIT_PRESS}\nIt is hard going because there are so many\nmonster houses.")),
    MSG_NPC(1, _(" If my information helps\neven a little, {NAME_0}, I'm happy.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g24_s0_lives2_dlg2[] = { /* 0x81855b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I've hardened quite a lot!\nNo earthquake can touch me now!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g25_s0_station_sref_script[] = { /* 0x8185658 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs2_g25_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g25_s0_station_sref_script }; /* 0x8185688 */

static const struct ScriptCommand s_gs2_g25_s0_lives0_dlg0[] = { /* 0x8185694 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g25_s0_lives0_dlg2[] = { /* 0x81856d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" A shooting star is on\na collision course...{WAIT_PRESS}\nThis is indeed a desperate time.")),
    MSG_NPC(1, _(" But there is nothing that\nI can do.{WAIT_PRESS}\nAll our hopes ride with you.")),
    MSG_NPC(1, _(" I realize that it is a heavy\nburden to bear, but...{WAIT_PRESS}\nwe must count on you to succeed.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g25_s0_obj0_dlg2[] = { /* 0x8185844 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g25_s0_lives1_dlg2[] = { /* 0x8185874 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'll use Harden and wait for\n{NAME_0}'s team to come back!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g26_s0_station_sref_script[] = { /* 0x8185910 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g26_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g26_s0_station_sref_script }; /* 0x8185950 */

static const struct ScriptCommand s_gs2_g26_s0_lives0_dlg0[] = { /* 0x818595c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g26_s0_lives0_dlg2[] = { /* 0x818599c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I see...\nYou are finally off.")),
    MSG_NPC(1, _(" This journey promises to be\nharsh.\nI count on your perseverance.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g26_s0_obj0_dlg2[] = { /* 0x8185a70 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g26_s0_lives1_dlg2[] = { /* 0x8185aa0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You're soon going...")),
    MSG_NPC(1, _(" But this is {NAME_0}\nand {NAME_2}.{WAIT_PRESS}\nYou can't fail.")),
    MSG_NPC(1, _(" I believe in you.\nSo I'll be waiting for you.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g26_s0_lives2_dlg2[] = { /* 0x8185bac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Hello, I am Caterpie's\nmother. It's been a while.")),
    MSG_NPC(1, _(" You also have my support.{WAIT_PRESS}\nPlease do your best. And please be careful!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g26_s0_lives3_dlg2[] = { /* 0x8185ca4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'll use Harden and wait for\n{NAME_0}'s team to come back!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g27_s0_station_sref_script[] = { /* 0x8185d04 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g27_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g27_s0_station_sref_script }; /* 0x8185d44 */

static const struct ScriptCommand s_gs2_g27_s0_lives0_dlg0[] = { /* 0x8185d50 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g27_s0_lives0_dlg2[] = { /* 0x8185d90 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Ah...{WAIT_PRESS} The {COLOR YELLOW_D}Sky Tower{RESET},\nyou say...")),
    MSG_NPC(1, _(" In all my long years, I'd\nnot known of any world above the clouds.")),
    MSG_NPC(1, _(" The world remains a vast\nmystery...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g27_s0_obj0_dlg2[] = { /* 0x8185eac */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g27_s0_lives1_dlg2[] = { /* 0x8185edc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" This is {NAME_0}\nand {NAME_2} after all.{WAIT_PRESS}\nYou can't fail.")),
    MSG_NPC(1, _(" I believe in you.\nSo I'll be waiting for you.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g27_s0_lives2_dlg2[] = { /* 0x8185f90 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I believe too.\n{NAME_0}, don't let us down!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g27_s0_lives3_dlg2[] = { /* 0x818601c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, is that right?\nYou can climb above the clouds?")),
    MSG_NPC(1, _(" I wish I could use Harden\nup on the clouds...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g28_s0_station_sref_script[] = { /* 0x81860f4 */
    DEBUGINFO,
    SELECT_MAP(2),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(41),
    { 0x22, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(240),
    { 0x23, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs2_g28_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs2_g28_s0_station_sref_script }; /* 0x8186174 */

static const struct ScriptCommand s_gs2_g28_s0_eff0_script[] = { /* 0x8186180 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x0000000e,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g28_s0_lives0_dlg0[] = { /* 0x81861c0 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g29_s0_station_sref_script[] = { /* 0x8186200 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 2),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 1),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(3),
    SELECT_ENTITIES(-1, 0),
    WAIT(30),
    BGM_SWITCH(8),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    SELECT_EVENTS(0, 2),
    CALL_STATION( 30,  0),
    RET,
};

static const struct ScriptRef s_gs2_g29_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs2_g29_s0_station_sref_script }; /* 0x8186300 */

static const struct ScriptCommand s_gs2_g29_s0_eff0_script[] = { /* 0x818630c */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000017,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0200,  0x00000019,  0x00000000, NULL },
    WAIT(150),
    { 0x86, 0x00,  0x0200,  0x00000018,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs2_g29_s0_lives0_dlg0[] = { /* 0x81863ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000f,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Hi, {NAME_4}!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_4}?{WAIT_PRESS}\nHave you seen Snubbull around?")),
    VARIANT(/* == */  1, _(" I heard something weird\nhappened to him.")),
    VARIANT_DEFAULT(_(" Hi, {NAME_4}.\nHave you seen Snubbull?")),
    VARIANT_DEFAULT(_(" I heard something strange\nhappened to him.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0005, 0x00000000),
    PORTRAIT_POS(5, 2, 3),
    MSG_NPC(5, _(" I'm Snubbull.")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Whaaaat?!{WAIT_PRESS}\nYou're Snubbull?")),
    MSG_NPC(1, _(" But you don't look anything\nlike the way you did before!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(5, _(" I don't really understand,\neither.")),
    MSG_NPC(5, _(" I went into the cave there,\nand all of a sudden...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_NPC(1, _(" What cave?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0006, 0x00000000),
    PORTRAIT_POS(6, 0, -1),
    MSG_NPC(6, _(" It appeared without me\nnoticing.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(6, _(" See?\nRight there.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" So you went in there...")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(5, _(" Yup.{WAIT_PRESS}\nAnd I came out looking like this...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Snubbull underwent\n“evolution.”{WAIT_PRESS}\nHe evolved.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Evolution? Evolved?{WAIT_PRESS}\nWhat's that about?")),
    VARIANT_DEFAULT(_(" Evolution? Evolved?{WAIT_PRESS}\nI don't follow.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" Pokémon, upon satisfying\ncertain conditions, may evolve.")),
    MSG_NPC(4, _(" When a Pokémon undergoes\nevolution, its appearance changes.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Oh, wow!{WAIT_PRESS}\nYour own appearance...{WAIT_PRESS}\nThat can change?!")),
    TEXTBOX_CLEAR,
    WAIT(20),
    MSG_NPC(4, _(" I suspect that cave is where\nevolution can take place.")),
    MSG_NPC(4, _(" This is merely a guess...")),
    MSG_NPC(4, _(" Perhaps evolution could\nnot take place before because the world's\nbalance was askew.")),
    MSG_NPC(4, _(" However, now that the star\nhas been destroyed...{WAIT_PRESS}\nThe world's balance has been restored...")),
    MSG_NPC(4, _(" And perhaps that cave\nbecame unsealed.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_LEFT, 0x0002, 0x00000000),
    PORTRAIT_POS(2, -2, 0),
    MSG_NPC(2, _(" So if I evolved, I would\nbecome like {NAME_3}?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, -1, 0),
    MSG_NPC(3, _(" I wish...{WAIT_PRESS}\nI want to be Butterfree quickly...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(5, _(" W-wait a second.{WAIT_PRESS}\nI don't know if I like this or not...")),
    MSG_NPC(5, _(" My cute little face turned\nall craggy...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(4, _(" Evolution is not a bad\nthing.")),
    MSG_NPC(4, _(" Appearance isn't the only\nthing that changes through evolution.")),
    MSG_NPC(4, _(" One's power and abilities\nmay be enhanced, for example.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    MSG_NPC(5, _(" Oh! Really?!{WAIT_PRESS}\nI...{WAIT_PRESS} I might be stronger?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" That makes me want to\nevolve even more!")),
    MSG_NPC(3, _(" I wish I could be Butterfree\nsoon...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" M-me too!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Can we evolve if we go to\nthat cave?")),
    VARIANT(/* == */  3, _(" Can we evolve if we go to\nthat cave?")),
    VARIANT_DEFAULT(_(" Can we evolve if we go to\nthat cave?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(4, _(" Yes.{WAIT_PRESS}\nBut it would depend on the conditions.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}.{WAIT_PRESS}\nWe should go to the cave if we want to\nevolve.")),
    VARIANT(/* == */  3, _(" {NAME_0}.{WAIT_PRESS}\nLet's go to the cave if we're ready to\nevolve.")),
    VARIANT_DEFAULT(_(" {NAME_0}.{WAIT_PRESS}\nLet's go to the cave if we're ready to\nevolve.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};
























static const struct ScriptCommand s_gs2_g29_s0_lives1_dlg0[] = { /* 0x8187888 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000011,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000012,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(90),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g29_s0_lives2_dlg0[] = { /* 0x8187b78 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000013,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x6b, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(3),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g29_s0_lives3_dlg0[] = { /* 0x8187d98 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000015,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6b, 0x00,  0x0100,  0x00000016,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g29_s0_lives4_dlg0[] = { /* 0x8187f58 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g29_s0_lives5_dlg0[] = { /* 0x81880b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x08,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g29_s0_lives6_dlg0[] = { /* 0x81882a8 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x91, 0x0c,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs2_g30_s0_station_sref_script[] = { /* 0x8188368 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs2_g30_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs2_g30_s0_station_sref_script }; /* 0x81883a8 */

static const struct ScriptCommand s_gs2_g30_s0_lives0_dlg2[] = { /* 0x81883b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" First I have to evolve like\nMetapod!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g30_s0_lives1_dlg2[] = { /* 0x818843c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, I hope I can be\nButterfree soon...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g30_s0_lives2_dlg2[] = { /* 0x81884c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I suspect that cave is where\nevolution can take place.")),
    MSG_NPC(1, _(" You should enter that cave\nif you wish to evolve.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g30_s0_lives3_dlg2[] = { /* 0x818856c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I might become\nstronger!{WAIT_PRESS}\nOoh, it's exciting...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g30_s0_lives4_dlg0[] = { /* 0x8188604 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs2_g30_s0_lives4_dlg2[] = { /* 0x8188644 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" That cave's entrance\nappears rather narrow.\nOnly one may enter at a time, it seems.")),
    MSG_NPC(1, _(" If you wish to enter the\ncave, you must come alone.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs2_g30_s0_obj0_dlg2[] = { /* 0x8188748 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs2_g0_s1_lives[] = { /* 0x8188778 */
    /*  0 */ {   0,   4,   0,   0, {  28,  71, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  73, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g0_s2_lives[] = { /* 0x81887a8 */
    /*  0 */ {   0,   0,   0,   0, {  28,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  28,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g1_s0_lives[] = { /* 0x81887d8 */
    /*  0 */ {  54,   6,   0,   0, {  35,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g1_s0_lives0_dlg0,
        [2] = s_gs2_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  94,   2,   0,   0, {  31,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g1_s0_lives1_dlg0,
        [2] = s_gs2_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  98,   0,   0,   0, {  40,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g1_s0_lives2_dlg0,
        [2] = s_gs2_g1_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g3_s0_lives[] = { /* 0x8188820 */
    /*  0 */ {  98,   0,   0,   0, {  40,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g3_s0_lives0_dlg0,
        [2] = s_gs2_g3_s0_lives0_dlg2,
        [3] = s_gs2_g3_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs2_g4_s0_lives[] = { /* 0x8188838 */
    /*  0 */ {  98,   0,   0,   0, {  40,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g4_s0_lives0_dlg0,
        [2] = s_gs2_g4_s0_lives0_dlg2,
        [3] = s_gs2_g4_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs2_g5_s0_lives[] = { /* 0x8188850 */
    /*  0 */ {  93,   2,   0,   0, {  16,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g5_s0_lives0_dlg2,
    } },
    /*  1 */ {  92,   6,   0,   0, {  20,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g5_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g6_s0_lives[] = { /* 0x8188880 */
    /*  0 */ {   0,   4,   0,   0, {  16,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g6_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  20,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g6_s0_lives1_dlg0,
    } },
    /*  2 */ {  93,   0,   0,   0, {  16,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g6_s0_lives2_dlg0,
    } },
    /*  3 */ {  92,   0,   0,   0, {  20,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g6_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g7_s0_lives[] = { /* 0x81888e0 */
    /*  0 */ {  93,   2,   0,   0, {  16,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g7_s0_lives0_dlg2,
    } },
    /*  1 */ {  92,   6,   0,   0, {  20,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g7_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g8_s0_lives[] = { /* 0x8188910 */
    /*  0 */ {   0,   2,   0,   0, {  16,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g8_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  20,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g8_s0_lives1_dlg0,
    } },
    /*  2 */ {  93,   2,   0,   0, {  16,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g8_s0_lives2_dlg0,
    } },
    /*  3 */ {  92,   6,   0,   0, {  20,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g8_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g9_s0_lives[] = { /* 0x8188970 */
    /*  0 */ {  92,   6,   0,   0, {  18,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g9_s0_lives0_dlg0,
        [2] = s_gs2_g9_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g9_s1_lives[] = { /* 0x8188988 */
    /*  0 */ {   0,   2,   0,   0, {  16,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g9_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  20,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g9_s1_lives1_dlg0,
    } },
    /*  2 */ {  92,   2,   0,   0, {  18,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g9_s1_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g10_s0_lives[] = { /* 0x81889d0 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g10_s0_lives0_dlg0,
        [2] = s_gs2_g10_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g11_s0_lives[] = { /* 0x81889e8 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g11_s0_lives0_dlg0,
        [2] = s_gs2_g11_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g12_s0_lives[] = { /* 0x8188a00 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g12_s0_lives0_dlg0,
        [2] = s_gs2_g12_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g12_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g13_s0_lives[] = { /* 0x8188a30 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g13_s0_lives0_dlg0,
        [2] = s_gs2_g13_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g14_s0_lives[] = { /* 0x8188a48 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g14_s0_lives0_dlg0,
        [2] = s_gs2_g14_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   2,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g14_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   6,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g14_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g15_s0_lives[] = { /* 0x8188a90 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g15_s0_lives0_dlg0,
        [2] = s_gs2_g15_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   2,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g15_s0_lives1_dlg0,
        [2] = s_gs2_g15_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   6,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g15_s0_lives2_dlg0,
        [2] = s_gs2_g15_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g16_s0_lives[] = { /* 0x8188ad8 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g16_s0_lives0_dlg0,
        [2] = s_gs2_g16_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g16_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g16_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g16_s1_lives[] = { /* 0x8188b20 */
    /*  0 */ {   0,   4,   0,   0, {  27,  23, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g16_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  23, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g16_s1_lives1_dlg0,
    } },
    /*  2 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g16_s1_lives2_dlg0,
        [2] = s_gs2_g16_s1_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g18_s0_lives[] = { /* 0x8188b68 */
    /*  0 */ {   0,   4,   0,   0, {  27,  23, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g18_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  23, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g18_s0_lives1_dlg0,
    } },
    /*  2 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g18_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g19_s0_lives[] = { /* 0x8188bb0 */
    /*  0 */ {  98,   0,   0,   0, {  35,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g19_s0_lives0_dlg0,
        [1] = s_gs2_g19_s0_lives0_dlg1,
    } },
};

static const struct GroundLivesData s_gs2_g20_s0_lives[] = { /* 0x8188bc8 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g20_s0_lives0_dlg0,
        [2] = s_gs2_g20_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g20_s0_lives1_dlg0,
        [2] = s_gs2_g20_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g20_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g21_s0_lives[] = { /* 0x8188c10 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g21_s0_lives0_dlg0,
        [2] = s_gs2_g21_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g21_s0_lives1_dlg0,
        [2] = s_gs2_g21_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g21_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g22_s0_lives[] = { /* 0x8188c58 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g22_s0_lives0_dlg0,
        [2] = s_gs2_g22_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g22_s0_lives1_dlg0,
        [2] = s_gs2_g22_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g22_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g23_s0_lives[] = { /* 0x8188ca0 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g23_s0_lives0_dlg0,
        [2] = s_gs2_g23_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g23_s0_lives1_dlg0,
        [2] = s_gs2_g23_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g23_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g24_s0_lives[] = { /* 0x8188ce8 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g24_s0_lives0_dlg0,
        [2] = s_gs2_g24_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  32,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g24_s0_lives1_dlg0,
        [2] = s_gs2_g24_s0_lives1_dlg2,
    } },
    /*  2 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g24_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g25_s0_lives[] = { /* 0x8188d30 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g25_s0_lives0_dlg0,
        [2] = s_gs2_g25_s0_lives0_dlg2,
    } },
    /*  1 */ {  94,   0,   0,   0, {  36,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g25_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g26_s0_lives[] = { /* 0x8188d60 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g26_s0_lives0_dlg0,
        [2] = s_gs2_g26_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  35,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g26_s0_lives1_dlg2,
    } },
    /*  2 */ {  53,   0,   0,   0, {  31,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g26_s0_lives2_dlg2,
    } },
    /*  3 */ {  94,   0,   0,   0, {  39,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g26_s0_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g27_s0_lives[] = { /* 0x8188dc0 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g27_s0_lives0_dlg0,
        [2] = s_gs2_g27_s0_lives0_dlg2,
    } },
    /*  1 */ {  54,   0,   0,   0, {  35,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g27_s0_lives1_dlg2,
    } },
    /*  2 */ {  53,   0,   0,   0, {  31,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g27_s0_lives2_dlg2,
    } },
    /*  3 */ {  94,   0,   0,   0, {  39,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g27_s0_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs2_g28_s0_lives[] = { /* 0x8188e20 */
    /*  0 */ {  98,   0,   0,   0, {  28,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g28_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g29_s0_lives[] = { /* 0x8188e38 */
    /*  0 */ {   0,   4,   0,   0, {  30,  65, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  27,  65, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   4,   0,   0, {  27,  68, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives2_dlg0,
    } },
    /*  3 */ {  94,   4,   0,   0, {  30,  69, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives3_dlg0,
    } },
    /*  4 */ {  88,   4,   0,   0, {  34,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives4_dlg0,
    } },
    /*  5 */ {  81,   4,   0,   0, {  38,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives5_dlg0,
    } },
    /*  6 */ {  98,   0,   0,   0, {  40,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g29_s0_lives6_dlg0,
    } },
};

static const struct GroundLivesData s_gs2_g30_s0_lives[] = { /* 0x8188ee0 */
    /*  0 */ {  54,   3,   0,   0, {  33,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g30_s0_lives0_dlg2,
    } },
    /*  1 */ {  94,   4,   0,   0, {  39,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g30_s0_lives1_dlg2,
    } },
    /*  2 */ {  88,   0,   0,   0, {  34,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g30_s0_lives2_dlg2,
    } },
    /*  3 */ {  81,   0,   0,   0, {  38,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs2_g30_s0_lives3_dlg2,
    } },
    /*  4 */ {  98,   0,   0,   0, {  40,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs2_g30_s0_lives4_dlg0,
        [2] = s_gs2_g30_s0_lives4_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g1_s0_objs[] = { /* 0x8188f58 */
    /*  0 */ {   4,   0,   3,   1, {  40,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g1_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g3_s0_objs[] = { /* 0x8188f70 */
    /*  0 */ {   4,   0,   3,   1, {  40,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g3_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g4_s0_objs[] = { /* 0x8188f88 */
    /*  0 */ {   4,   0,   3,   1, {  40,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g4_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g10_s0_objs[] = { /* 0x8188fa0 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g10_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g11_s0_objs[] = { /* 0x8188fb8 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g11_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g12_s0_objs[] = { /* 0x8188fd0 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g12_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g13_s0_objs[] = { /* 0x8188fe8 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g13_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g14_s0_objs[] = { /* 0x8189000 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g14_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g15_s0_objs[] = { /* 0x8189018 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g15_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g16_s0_objs[] = { /* 0x8189030 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g16_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g20_s0_objs[] = { /* 0x8189048 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g20_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g21_s0_objs[] = { /* 0x8189060 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g21_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g22_s0_objs[] = { /* 0x8189078 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g22_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g23_s0_objs[] = { /* 0x8189090 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g23_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g24_s0_objs[] = { /* 0x81890a8 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g24_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g25_s0_objs[] = { /* 0x81890c0 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g25_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g26_s0_objs[] = { /* 0x81890d8 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g26_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g27_s0_objs[] = { /* 0x81890f0 */
    /*  0 */ {   4,   0,   3,   1, {  28,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g27_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs2_g30_s0_objs[] = { /* 0x8189108 */
    /*  0 */ {   4,   0,   3,   1, {  40,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs2_g30_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs2_g6_s0_effs[] = { /* 0x8189120 */
    /*  0 */ {   0,   0,   1,   1, {  18,  46, 0, 0 }, s_gs2_g6_s0_eff0_script },
};

static const struct GroundEffectData s_gs2_g8_s0_effs[] = { /* 0x818912c */
    /*  0 */ {   0,   0,   1,   1, {  18,  46, 0, 0 }, s_gs2_g8_s0_eff0_script },
};

static const struct GroundEffectData s_gs2_g9_s1_effs[] = { /* 0x8189138 */
    /*  0 */ {   0,   0,   1,   1, {  18,  46, 0, 0 }, s_gs2_g9_s1_eff0_script },
};

static const struct GroundEffectData s_gs2_g16_s0_effs[] = { /* 0x8189144 */
    /*  0 */ {   0,   0,   1,   1, {  28,  22, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs2_g16_s0_eff0_script },
};

static const struct GroundEffectData s_gs2_g18_s0_effs[] = { /* 0x8189150 */
    /*  0 */ {   0,   0,   1,   1, {  28,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs2_g28_s0_effs[] = { /* 0x818915c */
    /*  0 */ {   0,   0,   1,   1, {  28,  40, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs2_g28_s0_eff0_script },
};

static const struct GroundEffectData s_gs2_g29_s0_effs[] = { /* 0x8189168 */
    /*  0 */ {   0,   0,   1,   1, {  28,  64, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs2_g29_s0_eff0_script },
};

static const struct GroundEventData s_gs2_g0_s0_evts[] = { /* 0x8189174 */
    /*  0 */ {   9,   3,   0,   0, {  24,  75, 0, 0 }, &s_gs2_g0_s0_evt0_sref },
};

static const struct GroundEventData s_gs2_g0_s2_evts[] = { /* 0x8189180 */
    /*  0 */ {   3,   3,   0,   0, {  27,  22, 0, 0 }, &s_gs2_g0_s2_evt0_sref },
};

static const struct GroundEventData s_gs2_g5_s0_evts[] = { /* 0x818918c */
    /*  0 */ {   9,   5,   0,   0, {  14,  41, 0, 0 }, &s_gs2_g5_s0_evt0_sref },
};

static const struct GroundEventData s_gs2_g7_s0_evts[] = { /* 0x8189198 */
    /*  0 */ {   9,   5,   0,   0, {  14,  41, 0, 0 }, &s_gs2_g7_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81891a4 */
    &s_gs2_g0_s0_station_sref,
    &s_gs2_g1_s0_station_sref,
    &s_gs2_g2_s0_station_sref,
    &s_gs2_g6_s0_station_sref,
    &s_gs2_g8_s0_station_sref,
    &s_gs2_g9_s1_station_sref,
    &s_gs2_g10_s0_station_sref,
    &s_gs2_g11_s0_station_sref,
    &s_gs2_g12_s0_station_sref,
    &s_gs2_g13_s0_station_sref,
    &s_gs2_g14_s0_station_sref,
    &s_gs2_g15_s0_station_sref,
    &s_gs2_g16_s0_station_sref,
    &s_gs2_g16_s1_station_sref,
    &s_gs2_g17_s0_station_sref,
    &s_gs2_g18_s0_station_sref,
    &s_gs2_g19_s0_station_sref,
    &s_gs2_g20_s0_station_sref,
    &s_gs2_g21_s0_station_sref,
    &s_gs2_g22_s0_station_sref,
    &s_gs2_g23_s0_station_sref,
    &s_gs2_g24_s0_station_sref,
    &s_gs2_g25_s0_station_sref,
    &s_gs2_g26_s0_station_sref,
    &s_gs2_g27_s0_station_sref,
    &s_gs2_g28_s0_station_sref,
    &s_gs2_g29_s0_station_sref,
    &s_gs2_g30_s0_station_sref,
};

static const struct GroundScriptSector s_gs2_g0_sectors[] = { /* 0x8189214 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs2_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs2_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs2_g0_s2_lives), 0,NULL, 0,NULL, LPARRAY(s_gs2_g0_s2_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs2_g1_sectors[] = { /* 0x818928c */
    { LPARRAY(s_gs2_g1_s0_lives), LPARRAY(s_gs2_g1_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs2_g2_sectors[] = { /* 0x81892b4 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs2_g3_sectors[] = { /* 0x81892dc */
    { LPARRAY(s_gs2_g3_s0_lives), LPARRAY(s_gs2_g3_s0_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs2_g4_sectors[] = { /* 0x8189304 */
    { LPARRAY(s_gs2_g4_s0_lives), LPARRAY(s_gs2_g4_s0_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs2_g5_sectors[] = { /* 0x818932c */
    { LPARRAY(s_gs2_g5_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs2_g5_s0_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs2_g6_sectors[] = { /* 0x8189354 */
    { LPARRAY(s_gs2_g6_s0_lives), 0,NULL, LPARRAY(s_gs2_g6_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs2_g7_sectors[] = { /* 0x818937c */
    { LPARRAY(s_gs2_g7_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs2_g7_s0_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs2_g8_sectors[] = { /* 0x81893a4 */
    { LPARRAY(s_gs2_g8_s0_lives), 0,NULL, LPARRAY(s_gs2_g8_s0_effs), 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs2_g9_sectors[] = { /* 0x81893cc */
    { LPARRAY(s_gs2_g9_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs2_g9_s1_lives), 0,NULL, LPARRAY(s_gs2_g9_s1_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs2_g10_sectors[] = { /* 0x818941c */
    { LPARRAY(s_gs2_g10_s0_lives), LPARRAY(s_gs2_g10_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs2_g11_sectors[] = { /* 0x8189444 */
    { LPARRAY(s_gs2_g11_s0_lives), LPARRAY(s_gs2_g11_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptSector s_gs2_g12_sectors[] = { /* 0x818946c */
    { LPARRAY(s_gs2_g12_s0_lives), LPARRAY(s_gs2_g12_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[8], },
};

static const struct GroundScriptSector s_gs2_g13_sectors[] = { /* 0x8189494 */
    { LPARRAY(s_gs2_g13_s0_lives), LPARRAY(s_gs2_g13_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[9], },
};

static const struct GroundScriptSector s_gs2_g14_sectors[] = { /* 0x81894bc */
    { LPARRAY(s_gs2_g14_s0_lives), LPARRAY(s_gs2_g14_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[10], },
};

static const struct GroundScriptSector s_gs2_g15_sectors[] = { /* 0x81894e4 */
    { LPARRAY(s_gs2_g15_s0_lives), LPARRAY(s_gs2_g15_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[11], },
};

static const struct GroundScriptSector s_gs2_g16_sectors[] = { /* 0x818950c */
    { LPARRAY(s_gs2_g16_s0_lives), LPARRAY(s_gs2_g16_s0_objs), LPARRAY(s_gs2_g16_s0_effs), 0,NULL, 1,&sStationScripts[12], },
    { LPARRAY(s_gs2_g16_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[13], },
};

static const struct GroundScriptSector s_gs2_g17_sectors[] = { /* 0x818955c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[14], },
};

static const struct GroundScriptSector s_gs2_g18_sectors[] = { /* 0x8189584 */
    { LPARRAY(s_gs2_g18_s0_lives), 0,NULL, LPARRAY(s_gs2_g18_s0_effs), 0,NULL, 1,&sStationScripts[15], },
};

static const struct GroundScriptSector s_gs2_g19_sectors[] = { /* 0x81895ac */
    { LPARRAY(s_gs2_g19_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[16], },
};

static const struct GroundScriptSector s_gs2_g20_sectors[] = { /* 0x81895d4 */
    { LPARRAY(s_gs2_g20_s0_lives), LPARRAY(s_gs2_g20_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[17], },
};

static const struct GroundScriptSector s_gs2_g21_sectors[] = { /* 0x81895fc */
    { LPARRAY(s_gs2_g21_s0_lives), LPARRAY(s_gs2_g21_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[18], },
};

static const struct GroundScriptSector s_gs2_g22_sectors[] = { /* 0x8189624 */
    { LPARRAY(s_gs2_g22_s0_lives), LPARRAY(s_gs2_g22_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[19], },
};

static const struct GroundScriptSector s_gs2_g23_sectors[] = { /* 0x818964c */
    { LPARRAY(s_gs2_g23_s0_lives), LPARRAY(s_gs2_g23_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[20], },
};

static const struct GroundScriptSector s_gs2_g24_sectors[] = { /* 0x8189674 */
    { LPARRAY(s_gs2_g24_s0_lives), LPARRAY(s_gs2_g24_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[21], },
};

static const struct GroundScriptSector s_gs2_g25_sectors[] = { /* 0x818969c */
    { LPARRAY(s_gs2_g25_s0_lives), LPARRAY(s_gs2_g25_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[22], },
};

static const struct GroundScriptSector s_gs2_g26_sectors[] = { /* 0x81896c4 */
    { LPARRAY(s_gs2_g26_s0_lives), LPARRAY(s_gs2_g26_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[23], },
};

static const struct GroundScriptSector s_gs2_g27_sectors[] = { /* 0x81896ec */
    { LPARRAY(s_gs2_g27_s0_lives), LPARRAY(s_gs2_g27_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[24], },
};

static const struct GroundScriptSector s_gs2_g28_sectors[] = { /* 0x8189714 */
    { LPARRAY(s_gs2_g28_s0_lives), 0,NULL, LPARRAY(s_gs2_g28_s0_effs), 0,NULL, 1,&sStationScripts[25], },
};

static const struct GroundScriptSector s_gs2_g29_sectors[] = { /* 0x818973c */
    { LPARRAY(s_gs2_g29_s0_lives), 0,NULL, LPARRAY(s_gs2_g29_s0_effs), 0,NULL, 1,&sStationScripts[26], },
};

static const struct GroundScriptSector s_gs2_g30_sectors[] = { /* 0x8189764 */
    { LPARRAY(s_gs2_g30_s0_lives), LPARRAY(s_gs2_g30_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[27], },
};

static const struct GroundScriptGroup s_gs2_groups[] = { /* 0x818978c */
    { LPARRAY(s_gs2_g0_sectors) },
    { LPARRAY(s_gs2_g1_sectors) },
    { LPARRAY(s_gs2_g2_sectors) },
    { LPARRAY(s_gs2_g3_sectors) },
    { LPARRAY(s_gs2_g4_sectors) },
    { LPARRAY(s_gs2_g5_sectors) },
    { LPARRAY(s_gs2_g6_sectors) },
    { LPARRAY(s_gs2_g7_sectors) },
    { LPARRAY(s_gs2_g8_sectors) },
    { LPARRAY(s_gs2_g9_sectors) },
    { LPARRAY(s_gs2_g10_sectors) },
    { LPARRAY(s_gs2_g11_sectors) },
    { LPARRAY(s_gs2_g12_sectors) },
    { LPARRAY(s_gs2_g13_sectors) },
    { LPARRAY(s_gs2_g14_sectors) },
    { LPARRAY(s_gs2_g15_sectors) },
    { LPARRAY(s_gs2_g16_sectors) },
    { LPARRAY(s_gs2_g17_sectors) },
    { LPARRAY(s_gs2_g18_sectors) },
    { LPARRAY(s_gs2_g19_sectors) },
    { LPARRAY(s_gs2_g20_sectors) },
    { LPARRAY(s_gs2_g21_sectors) },
    { LPARRAY(s_gs2_g22_sectors) },
    { LPARRAY(s_gs2_g23_sectors) },
    { LPARRAY(s_gs2_g24_sectors) },
    { LPARRAY(s_gs2_g25_sectors) },
    { LPARRAY(s_gs2_g26_sectors) },
    { LPARRAY(s_gs2_g27_sectors) },
    { LPARRAY(s_gs2_g28_sectors) },
    { LPARRAY(s_gs2_g29_sectors) },
    { LPARRAY(s_gs2_g30_sectors) },
};

static const struct GroundLink s_gs2_links[] = { /* 0x8189884 */
    /* link   0 */ { { /*x*/  28, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  16, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  20, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  28, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  28, /*y*/  60, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  18, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 3 },
    /* link   6 */ { { /*x*/  28, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   7 */ { { /*x*/  16, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/  20, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/  28, /*y*/  48, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/  28, /*y*/  60, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  11 */ { { /*x*/  18, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 3 },
    /* link  12 */ { { /*x*/  27, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  13 */ { { /*x*/  30, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  14 */ { { /*x*/  28, /*y*/   9, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  15 */ { { /*x*/  30, /*y*/  49, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  16 */ { { /*x*/  38, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  17 */ { { /*x*/  27, /*y*/  49, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  18 */ { { /*x*/  34, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  19 */ { { /*x*/  27, /*y*/  51, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  20 */ { { /*x*/  33, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  21 */ { { /*x*/  30, /*y*/  51, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  22 */ { { /*x*/  39, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  23 */ { { /*x*/  28, /*y*/  48, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  24 */ { { /*x*/  35, /*y*/  42, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  25 */ { { /*x*/  28, /*y*/  24, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs2 = { LPARRAY(s_gs2_groups), s_gs2_links }; /* 0x8189954 */
