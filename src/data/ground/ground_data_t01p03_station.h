



























static const struct ScriptCommand s_gs4_g0_s0_station_sref_script[] = { /* 0x8189968 */
    DEBUGINFO,
    SELECT_MAP(4),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_LT, 4, /* to label */ 0),
    COND(JUDGE_EQ, 4, /* to label */ 1),
    COND(JUDGE_EQ, 5, /* to label */ 2),
    COND(JUDGE_EQ, 6, /* to label */ 3),
    COND(JUDGE_EQ, 7, /* to label */ 4),
    COND(JUDGE_EQ, 8, /* to label */ 5),
    COND(JUDGE_EQ, 9, /* to label */ 6),
    COND(JUDGE_LT, 15, /* to label */ 7),
    COND(JUDGE_EQ, 15, /* to label */ 8),
    COND(JUDGE_EQ, 16, /* to label */ 9),
    COND(JUDGE_LT, 18, /* to label */ 10),
    COND(JUDGE_EQ, 18, /* to label */ 11),
    JUMP_LABEL(12),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 13),
    JUMP_LABEL(14),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(EVENT_M01E02B_L003),
  LABEL(14), /* = 0x0e */
    CALL_STATION( 13,  0),
    JUMP_LABEL(0),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 15),
    COND(JUDGE_LE, 4, /* to label */ 16),
    SELECT_ENTITIES(15, 0),
    JUMP_LABEL(0),
  LABEL(15), /* = 0x0f */
    CALL_STATION( 13,  0),
    JUMP_LABEL(0),
  LABEL(16), /* = 0x10 */
    SELECT_ENTITIES(14, 0),
    JUMP_LABEL(0),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 17),
    CALL_STATION( 16,  0),
    JUMP_LABEL(0),
  LABEL(17), /* = 0x11 */
    CALL_STATION( 15,  0),
    JUMP_LABEL(0),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 18),
    CALL_STATION( 17,  0),
    JUMP_LABEL(0),
  LABEL(18), /* = 0x12 */
    CALL_STATION( 16,  0),
    JUMP_LABEL(0),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 19),
    CALL_STATION( 18,  0),
    JUMP_LABEL(0),
  LABEL(19), /* = 0x13 */
    CALL_STATION( 17,  0),
    JUMP_LABEL(0),
  LABEL(6), /* = 0x06 */
    CALL_STATION( 18,  0),
    JUMP_LABEL(0),
  LABEL(7), /* = 0x07 */
    JUMP_LABEL(0),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 20),
    COND(JUDGE_LE, 5, /* to label */ 21),
    COND(JUDGE_LE, 7, /* to label */ 22),
    COND(JUDGE_LE, 11, /* to label */ 23),
    JUMP_LABEL(24),
  LABEL(20), /* = 0x14 */
    CALL_STATION( 19,  0),
    JUMP_LABEL(0),
  LABEL(21), /* = 0x15 */
    CALL_STATION( 20,  0),
    JUMP_LABEL(0),
  LABEL(22), /* = 0x16 */
    CALL_STATION( 21,  0),
    JUMP_LABEL(0),
  LABEL(23), /* = 0x17 */
    CALL_STATION( 22,  0),
    JUMP_LABEL(0),
  LABEL(24), /* = 0x18 */
    CALL_STATION( 23,  0),
    JUMP_LABEL(0),
  LABEL(9), /* = 0x09 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 25),
    COND(JUDGE_LE, 4, /* to label */ 26),
    JUMP_LABEL(27),
  LABEL(25), /* = 0x19 */
    CALL_STATION( 24,  0),
    JUMP_LABEL(0),
  LABEL(26), /* = 0x1a */
    CALL_STATION( 25,  0),
    JUMP_LABEL(0),
  LABEL(27), /* = 0x1b */
    CALL_STATION( 26,  0),
    JUMP_LABEL(0),
  LABEL(10), /* = 0x0a */
    CALL_STATION( 26,  0),
    JUMP_LABEL(0),
  LABEL(11), /* = 0x0b */
    CALL_STATION( 28,  0),
    JUMP_LABEL(0),
  LABEL(12), /* = 0x0c */
    CALL_STATION(  1,  0),
    JUMP_LABEL(0),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 28),
    COND_EQUAL(5, /* to label */ 29),
    SELECT_LIVES(0, 4),
    JUMP_LABEL(31),
  LABEL(28), /* = 0x1c */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(31),
  LABEL(29), /* = 0x1d */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(31),
  LABEL(31), /* = 0x1f */
    BGM_SWITCH(7),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs4_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs4_g0_s0_station_sref_script }; /* 0x818a174 */


static const struct ScriptCommand s_gs4_g0_s0_evt0_sref_script[] = { /* 0x818a180 */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs4_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs4_g0_s0_evt0_sref_script }; /* 0x818a1b0 */

static const struct ScriptCommand s_gs4_g0_s0_evt1_sref_script[] = { /* 0x818a1bc */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000005,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs4_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs4_g0_s0_evt1_sref_script }; /* 0x818a1ec */

static const struct ScriptCommand s_gs4_g0_s0_obj0_dlg2[] = { /* 0x818a1f8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xaf, 0x01,  0x000d,  0x00000000,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_BULLETIN_BOARD_JOBS, 0, 0),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S01E01A_L002),
    HALT,
  LABEL(1), /* = 0x01 */
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S01E02A_L001),
    HALT,
  LABEL(2), /* = 0x02 */
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S08E01A_L005B),
    HALT,
};

static const struct ScriptCommand s_gs4_g0_s0_lives0_dlg0[] = { /* 0x818a358 */
    DEBUGINFO,
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 0),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    { 0x60, 0x00,  0x0000,  0x00000018,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    WAIT(15),
    ROTATE(30, 10, DIRECTION_WEST),
    WALK_DIRECT(300, 1),
    WALK_DIRECT(300, 0),
    ROTATE(30, 10, DIRECTION_SOUTH),
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT(15),
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    WAIT(300),
    JUMP_LABEL(1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g0_s0_lives1_dlg0[] = { /* 0x818a4f8 */
    DEBUGINFO,
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 0),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    { 0x60, 0x00,  0x0000,  0x00000018,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    WAIT(90),
    WALK_DIRECT(300, 2),
    ROTATE(30, 10, DIRECTION_SOUTH),
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT(15),
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    WAIT(300),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    WAIT(15),
    ROTATE(30, 10, DIRECTION_EAST),
    WALK_DIRECT(300, 3),
    JUMP_LABEL(1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g0_s1_lives0_dlg0[] = { /* 0x818a6a8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s1_lives1_dlg0[] = { /* 0x818a6e8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s2_lives0_dlg0[] = { /* 0x818a728 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s2_lives1_dlg0[] = { /* 0x818a768 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s3_lives0_dlg0[] = { /* 0x818a7a8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s3_lives1_dlg0[] = { /* 0x818a7e8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s4_lives0_dlg0[] = { /* 0x818a828 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g0_s4_lives1_dlg0[] = { /* 0x818a868 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs4_g1_s0_station_sref_script[] = { /* 0x818a8a8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMPIF_ARRAY(EVENT_T01P03, 1, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(-1, 2),
  LABEL(1), /* = 0x01 */
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g1_s0_station_sref_script }; /* 0x818a938 */

static const struct ScriptCommand s_gs4_g1_s0_lives0_dlg2[] = { /* 0x818a944 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g1_s0_lives1_dlg2[] = { /* 0x818a974 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" My {COLOR CYAN}Team Hydro{RESET} is Bronze\nRank.")),
    MSG_NPC(1, _(" We need to do better.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g1_s0_lives2_dlg2[] = { /* 0x818aa20 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Our {COLOR CYAN}Team Rumblerock{RESET}\nis famous for savagery...")),
    MSG_NPC(1, _(" But we're actually only\nNormal Rank.{WAIT_PRESS}\nIt's an embarrassment...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g1_s0_lives3_dlg2[] = { /* 0x818ab0c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_UNK_BD(118, /* to label */ 0), /* likely "is friend area unlocked" (by GroundEnter id) */
    MSG_NPC(1, _(" Darlings, did you know?")),
    MSG_NPC(1, _(" Every so often, there are\nrescue jobs that reward you with a new\nFriend Area...")),
    MSG_NPC(1, _(" Well, lately there've been\nrumors about a new Friend Area!{WAIT_PRESS}\nThe {COLOR GREEN_H}Sky Blue Plains{RESET}, they say!")),
    MSG_NPC(1, _(" Just maybe, getting that\nFriend Area could be the start of\nsomething enchanting.")),
    MSG_NPC(1, _(" Darlings, if you spot rescue\njobs that seem promising, you should\ntry them!")),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    MSG_NPC(1, _(" Darlings, I'll have you know\nthat my {COLOR CYAN}Team Constrictor{RESET} is actually\nSilver Rank.")),
    MSG_NPC(1, _(" Not too bad, is it?{WAIT_PRESS}\nWe surprise people with our excellence.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g1_s0_lives4_dlg0[] = { /* 0x818ae1c */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 2, /* to label */ 0),
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, -1, /* to label */ 0),
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 4, /* to label */ 1),
    JUMPIF_SUM(JUDGE_LT, EVENT_S07E01, 11, /* to label */ 1),
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
  LABEL(1), /* = 0x01 */
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g1_s0_lives4_dlg2[] = { /* 0x818aecc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_T01P03, 2, /* to label */ 0),
    { 0x3b, 0x35,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 1),
    COND_EQUAL(2, /* to label */ 2),
    MSG_NPC(1, _(" Oh, hello!\nDid you know?")),
    MSG_NPC(1, _(" Somewhere in the world\nthere is an extremely rare Pokémon...{WAIT_PRESS}\nnamed Chansey.")),
    MSG_NPC(1, _(" This is what they say about\nChansey...{WAIT_PRESS} If you are lucky enough to\nmeet one, you will be filled with happiness.")),
    MSG_NPC(1, _(" I wonder what sort of\na Pokémon it is.{WAIT_PRESS}\nWouldn't you like to meet one, even once?")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_NPC(1, _(" ............{WAIT_PRESS}Oh-oh-oh?!{WAIT_PRESS}\nYou've met Chansey?")),
    MSG_NPC(1, _(" That is so lucky!\nWhat are the chances of that?")),
    MSG_NPC(1, _(" Oh, my gosh!\nHow wonderful for you!\nHow I envy you!")),
    MSG_NPC(1, _(" I wish I could meet Chansey\nand be filled with happiness...")),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    MSG_NPC(1, _(" Oh, hello!\nDid you know?")),
    MSG_NPC(1, _(" Somewhere in the world\nthere is an extremely rare Pokémon...{WAIT_PRESS}\nnamed Chansey.")),
    MSG_NPC(1, _(" This is what they say about\nChansey.{WAIT_PRESS} If you are lucky enough to meet\none, you will be filled with happiness.")),
    MSG_NPC(1, _(" I wonder what sort of\na Pokémon it is.{WAIT_PRESS} Wouldn't you like to meet\none, even once?{WAIT_PRESS} Wait a second...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Waaaaaaaaaaaaaaaaaaaah!")),
    MSG_NPC(1, _(" You're...{WAIT_PRESS}\nMaybe...{WAIT_PRESS} Chansey?!")),
    MSG_NPC(1, _(" You are! You really are!{WAIT_PRESS}\nI'm so lucky!")),
    SET_ARRAYVAL(EVENT_T01P03,  2,  1),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    MSG_NPC(1, _(" Oh, my gosh...\nI've finally met you...")),
    MSG_NPC(1, _(" I'm bursting with happiness!{WAIT_PRESS}\nOh, I am so lucky!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g1_s0_lives4_dlg3[] = { /* 0x818b4d4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMPIF_ARRAY(EVENT_T01P03, 2, /* to label */ 1),
    { 0x3b, 0x35,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 1),
    COND_EQUAL(2, /* to label */ 2),
  LABEL(1), /* = 0x01 */
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(2),
    WAIT(12),
    RET,
  LABEL(2), /* = 0x02 */
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    WAIT(12),
    RET,
};


static const struct ScriptCommand s_gs4_g1_s1_station_sref_script[] = { /* 0x818b624 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 2),
    RET,
};

static const struct ScriptRef s_gs4_g1_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g1_s1_station_sref_script }; /* 0x818b674 */

static const struct ScriptCommand s_gs4_g1_s1_eff0_script[] = { /* 0x818b680 */
    DEBUGINFO,
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(256, 4),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g1_s1_lives0_dlg0[] = { /* 0x818b710 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" (Papa still hasn't come\nhome...)") },
    MSG_NPC(-1, _(" Our son!{WAIT_PRESS}\nSorry to make you wait!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(465),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" ...Oh!{WAIT_PRESS}\nThat voice!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    FANFARE_PLAY2(453),
    { 0x97, 0x00,  0x0002,  0x00000003,  0x00000002, NULL },
    WAIT(120),
    FANFARE_STOP2(453),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Get set!")),
    TEXTBOX_CLEAR,
    TEXTBOX_AUTO_PRESS(0, 0),
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ha!")),
    ALERT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ha!")),
    ALERT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ha!")),
    ALERT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ha!")),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ha!")),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(30),
    TEXTBOX_AUTO_PRESS(-1, -1),
    ALERT_CUE(8),
    MSG_NPC(3, _(" Papa!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    WAIT(10),
    MSG_NPC(2, _(" Our son, we're sorry for\ncausing you anxiety.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Papa.{WAIT_PRESS}\nWhere were you?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" We were traveling the\nworld.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" The world is vast.{WAIT_PRESS}\nThere are countless Pokémon around the\nworld that are unknown in these areas.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" That's why you were gone...{WAIT_PRESS}\nPapa, did you see all the Pokémon that\naren't known in these areas?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nOf course.")),
    MSG_NPC(2, _(" What do you take us for?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh! Of course!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    SET_ARRAYVAL(EVENT_T01P03,  1,  1),
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs4_g1_s1_lives1_dlg0[] = { /* 0x818bfec */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g1_s1_lives2_dlg0[] = { /* 0x818c05c */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WARP_WAYPOINT(0, 5),
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WARP_WAYPOINT(0, 6),
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WARP_WAYPOINT(0, 7),
    { 0x8b, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WARP_WAYPOINT(0, 8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WARP_WAYPOINT(0, 9),
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(8, 1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(4),
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs4_g1_s1_lives3_dlg0[] = { /* 0x818c4dc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTH),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTH),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_EAST),
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs4_g1_s2_station_sref_script[] = { /* 0x818c72c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 2),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g1_s2_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g1_s2_station_sref_script }; /* 0x818c75c */

static const struct ScriptCommand s_gs4_g1_s2_lives0_dlg2[] = { /* 0x818c768 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" What do you take us for?!{WAIT_PRESS}\n...Uh, er... Um, yes.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g1_s2_lives1_dlg2[] = { /* 0x818c7f0 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" My papa is so special!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g2_s0_station_sref_script[] = { /* 0x818c858 */
    DEBUGINFO,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 1, /* to label */ 1),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 2, /* to label */ 2),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 7, /* to label */ 3),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 8, /* to label */ 3),
    RET_DIRECT,
  LABEL(3), /* = 0x03 */
    SELECT_ENTITIES(6, 0),
    RET_DIRECT,
  LABEL(1), /* = 0x01 */
    SELECT_ENTITIES(8, 0),
    RET_DIRECT,
  LABEL(2), /* = 0x02 */
    SELECT_ENTITIES(10, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g2_s0_station_sref_script }; /* 0x818c978 */

static const struct ScriptCommand s_gs4_g3_s0_station_sref_script[] = { /* 0x818c984 */
    DEBUGINFO,
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs4_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g3_s0_station_sref_script }; /* 0x818ca04 */

static const struct ScriptCommand s_gs4_g3_s0_eff0_script[] = { /* 0x818ca10 */
    DEBUGINFO,
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g3_s0_lives0_dlg0[] = { /* 0x818ca80 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0003, 0x00000000),
    MSG_NPC(1, _(" There was a job posted on\nthe Bulletin Board which said, “Punish bad\n{COLOR YELLOW_N}Mankey{RESET}.”")),
    MSG_NPC(1, _(" Did you two put up that job?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    ALERT_CUE(7),
    MSG_NPC(2, _(" Yup, yup!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(6),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0003, 0x00000041),
    MSG_NPC(3, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    WAIT(10),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    ALERT_CUE(6),
    MSG_NPC(2, _(" A bad Mankey gang is going\nwild in our forest.\nEveryone is upset.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(6),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    WAIT(10),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    ALERT_CUE(7),
    MSG_NPC(2, _(" We don't know why they\nrampage around...")),
    MSG_NPC(2, _(" But they are always angry\nand attack anyone they see!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(6),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm... That is a problem.")),
    VARIANT_DEFAULT(_(" Oh, no... That is a problem.")),
    ROTATE(4, 1, DIRECTION_EAST),
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}, we should go.")),
    VARIANT_DEFAULT(_(" {NAME_0}, we should go.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Thank you!\nWe're counting on you!")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}The place where the Mankey gang\n{CENTER_ALIGN}is wreaking havoc on others...")),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR YELLOW_D}Uproar Forest{RESET} is now\n{CENTER_ALIGN}open for exploration!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};







static const struct ScriptCommand s_gs4_g3_s0_lives1_dlg0[] = { /* 0x818d208 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_WEST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(6),
    WALK_RELATIVE(256, -80, 0),
    HALT,
};

static const struct ScriptCommand s_gs4_g3_s0_lives2_dlg0[] = { /* 0x818d328 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    SELECT_ANIMATION(19),
    WAIT(15),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs4_g3_s0_lives3_dlg0[] = { /* 0x818d3c8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    AWAIT_CUE(8),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    AWAIT_CUE(8),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    AWAIT_CUE(8),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs4_g4_s0_lives0_dlg2[] = { /* 0x818d588 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Activate sub-scenario 1-2\n“Team Flag”?")),
    CHOICE(/* label */  1, _("Activate.")),
    CHOICE(/* label */  2, _("*Cancel.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    EXECUTE_FUNCTION(EVENT_S01E02A_L001),
    CANCEL_ENTITIES(4, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs4_g5_s0_station_sref_script[] = { /* 0x818d6ac */
    DEBUGINFO,
    SELECT_MAP(4),
    WAIT(30),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs4_g5_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g5_s0_station_sref_script }; /* 0x818d74c */

static const struct ScriptCommand s_gs4_g5_s0_lives0_dlg0[] = { /* 0x818d758 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" “Smeargle's desperate plea,“\nhuh...?{WAIT_PRESS}\nThat's some title.")),
    VARIANT(/* == */  1, _(" What's it say?{WAIT_PRESS}\nCan you read it?")),
    VARIANT_DEFAULT(_(" “Smeargle's desperate plea,”\nhuh...?{WAIT_PRESS}\nThat's quite the title.")),
    VARIANT_DEFAULT(_(" What does it say?{WAIT_PRESS}\nCan you read it?")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} read the letter.")),
    TEXTBOX_CLEAR,
    WAIT(20),
    MSG_LETTER(_("“Please allow me to introduce myself.\nMy name is Smeargle.")),
    MSG_LETTER(_("I once had aspirations of becoming\nan artist.")),
    MSG_LETTER(_("Then, one day...{WAIT_PRESS}\nThere was an incident of an unforgivable\nnature...")),
    MSG_LETTER(_("I fled because I didn't want to become an\nadult.{WAIT_PRESS}\nBut then I lost my way...")),
    MSG_LETTER(_("I now find myself in this forest, unable to\nextricate myself...")),
    MSG_LETTER(_("I am lost in the {COLOR YELLOW_D}Howling Forest{RESET}!{WAIT_PRESS}\nSomebody!{WAIT_PRESS} Please save me!”")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" .............{WAIT_PRESS}\nIt says he ran away because he didn't want\nto be an adult...{WAIT_PRESS} What's up with that?")),
    VARIANT(/* == */  1, _(" I don't really get it, but...{WAIT_PRESS}\nWell, let's go rescue this Smeargle!")),
    VARIANT_DEFAULT(_(" .............{WAIT_PRESS}\nHe ran away because he didn't want to\nbecome an adult...{WAIT_PRESS} What's that about?")),
    VARIANT_DEFAULT(_(" I don't really get this...{WAIT_PRESS}\nBut let's go rescue this Smeargle anyway!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}The forest in which Smeargle\n{CENTER_ALIGN}is thought to have gone missing...")),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR YELLOW_D}Howling Forest{RESET}\n{CENTER_ALIGN}is now open for exploration!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};





static const struct ScriptCommand s_gs4_g5_s0_lives1_dlg0[] = { /* 0x818def4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs4_g6_s0_lives0_dlg0[] = { /* 0x818dfd4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
  LABEL(0), /* = 0x00 */
    WAIT(90),
    SELECT_ANIMATION(17),
    WAIT(1),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(17),
    WAIT(1),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    JUMP_LABEL(0),
    RET,
};

static const struct ScriptCommand s_gs4_g6_s0_lives0_dlg2[] = { /* 0x818e0a4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh, no...\nMedicham went down...\nWhat should I do...?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" If I went, I'd only last a\nlittle while... Oh, no...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    WAIT(1),
    SELECT_LIVES(6, 0),
    ALERT_CUE(2),
    RET,
};


static const struct ScriptCommand s_gs4_g6_s0_lives0_dlg3[] = { /* 0x818e248 */
    DEBUGINFO,
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(30),
    { 0x92, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    WAIT(5),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(5),
    { 0x92, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x92, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    WAIT(5),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(5),
    { 0x92, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(5),
    RET,
};

static const struct ScriptCommand s_gs4_g7_s0_station_sref_script[] = { /* 0x818e3b8 */
    DEBUGINFO,
    SELECT_MAP(4),
    WAIT(30),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs4_g7_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g7_s0_station_sref_script }; /* 0x818e458 */

static const struct ScriptCommand s_gs4_g7_s0_lives0_dlg0[] = { /* 0x818e464 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} read the SOS Mail\n{CENTER_ALIGN}apparently sent by Medicham.")),
    TEXTBOX_CLEAR,
    WAIT(20),
    MSG_LETTER(_("“My name is Medicham.")),
    MSG_LETTER(_("We had no trouble entering this dungeon...{WAIT_PRESS}\nBut it's horrible here!\nIt is much too difficult!")),
    MSG_LETTER(_("Ekans, he was defeated right away.\nIt makes me want to scream!")),
    MSG_LETTER(_("Somebody!{WAIT_PRESS}\nPlease help me!")),
    MSG_LETTER(_("The place is the {COLOR YELLOW_D}Wish Cave{RESET}.")),
    MSG_LETTER(_("The reward is a secret〜♪{WAIT_PRESS}\nBut it's really very nice--you can be\nsure of that〜♪”")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}The place in which Medicham\n{CENTER_ALIGN}is thought to have gone missing...")),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR YELLOW_D}Wish Cave{RESET} is now\n{CENTER_ALIGN}open for exploration!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs4_g7_s0_lives1_dlg0[] = { /* 0x818e800 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs4_g7_s0_lives2_dlg0[] = { /* 0x818e840 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs4_g7_s0_lives3_dlg0[] = { /* 0x818e880 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs4_g7_s0_lives4_dlg0[] = { /* 0x818e8c0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
  LABEL(0), /* = 0x00 */
    WAIT(90),
    SELECT_ANIMATION(17),
    WAIT(1),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(17),
    WAIT(1),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    JUMP_LABEL(0),
    HALT,
};

static const struct ScriptCommand s_gs4_g8_s0_lives0_dlg0[] = { /* 0x818e990 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g8_s0_lives0_dlg2[] = { /* 0x818e9e0 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 9, 0),
    HALT,
};

static const struct ScriptCommand s_gs4_g8_s0_lives1_dlg0[] = { /* 0x818ea10 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g8_s0_lives1_dlg2[] = { /* 0x818ea60 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 9, 0),
    HALT,
};

static const struct ScriptCommand s_gs4_g9_s0_station_sref_script[] = { /* 0x818ea90 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    AWAIT_CUE(3),
    SELECT_ENTITIES(10, 0),
    EXECUTE_FUNCTION(EVENT_S09E01A_L002),
    RET,
};

static const struct ScriptRef s_gs4_g9_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g9_s0_station_sref_script }; /* 0x818eaf0 */

static const struct ScriptCommand s_gs4_g9_s0_lives0_dlg0[] = { /* 0x818eafc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" Say, sweetie.{WAIT_PRESS}\nHave you seen Gengar around?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000042),
    MSG_NPC(2, _(" Hunh? You did?{WAIT_PRESS}\n...Wh-where?")),
    TEXTBOX_CLEAR,
    WAIT(45),
    PORTRAIT_REP(0x0002, 0x00000044),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nOh, you're just joking.")),
    TEXTBOX_CLEAR,
  LABEL(3), /* = 0x03 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    PORTRAIT_REP(0x0002, 0x00000046),
    MSG_NPC(2, _(" ...Oh, OK.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x93, 0x04,  0x000a,  0x0000005c,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Something seems to be\nwrong with Gengar lately.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" He won't do anything wicked\nwith us anymore...")),
    MSG_NPC(2, _(" I wonder what's wrong with\nhim?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yeah... He looks like he has\na lot on his mind...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" You think so?{WAIT_PRESS}\nHis expression...\nIt looks the same as usual, no?")),
    MSG_NPC(2, _(" All I have seen is him\nlaughing in his usual mean way?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x0000005c,  0x00000000, NULL },
    MSG_NPC(3, _(" No, it's different.{WAIT_PRESS}\nI can tell.")),
    MSG_NPC(3, _(" The way he sets his mouth.\nIt's different just a little at the corners.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" ...Hmm...{WAIT_PRESS}\nPerhaps that is so.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    MSG_NPC(2, _(" Anyway, without Gengar\naround, {COLOR CYAN}Team Meanies{RESET} can't operate.")),
    MSG_NPC(2, _(" Such a vexing problem!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};










static const struct ScriptCommand s_gs4_g9_s0_lives1_dlg0[] = { /* 0x818f284 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g9_s0_lives2_dlg0[] = { /* 0x818f2e4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 0),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 0),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005c,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    HALT,
};


static const struct ScriptCommand s_gs4_g9_s0_lives3_dlg0[] = { /* 0x818f434 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(5),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    HALT,
};

static const struct ScriptCommand s_gs4_g10_s0_lives0_dlg2[] = { /* 0x818f4f4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Anyway, without Gengar\naround, {COLOR CYAN}Team Meanies{RESET} can't operate.")),
    MSG_NPC(1, _(" Such a vexing problem!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g10_s0_lives1_dlg2[] = { /* 0x818f564 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Something seems to be\nwrong with Gengar lately.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g11_s0_station_sref_script[] = { /* 0x818f5c4 */
    DEBUGINFO,
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_22, 0, 0),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
    BGM_FADEOUT(60),
    WAIT(60),
    RET,
  LABEL(0), /* = 0x00 */
    WAIT(60),
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(-1, 3),
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    WAIT(60),
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(-1, 4),
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    WAIT(60),
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(-1, 5),
    JUMP_LABEL(3),
  LABEL(3), /* = 0x03 */
    JUMPIF_EQUAL(PARTNER1_KIND, 0, /* to label */ 4),
    SELECT_ENTITIES(-1, 1),
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    SELECT_ENTITIES(-1, 2),
    JUMP_LABEL(5),
  LABEL(5), /* = 0x05 */
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs4_g11_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g11_s0_station_sref_script }; /* 0x818f834 */


static const struct ScriptCommand s_gs4_g11_s1_lives0_dlg0[] = { /* 0x818f840 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_23, 0, 0),
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s1_lives1_dlg0[] = { /* 0x818f8e0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s2_lives0_dlg0[] = { /* 0x818f920 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_23, 0, 0),
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s3_lives0_dlg0[] = { /* 0x818f9b0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0002, 0x00000000),
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s4_lives0_dlg0[] = { /* 0x818fa00 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0003, 0x00000000),
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s5_lives0_dlg0[] = { /* 0x818fa50 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    HALT,
};

static const struct ScriptCommand s_gs4_g11_s5_lives1_dlg0[] = { /* 0x818faa0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    HALT,
};

static const struct ScriptCommand s_gs4_g12_s0_station_sref_script[] = { /* 0x818faf0 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 4),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 1),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, -1),
    CANCEL_LIVES(0, 0),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    SELECT_LIVES(0, 0),
    { 0xaf, 0x01,  0x000d,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs4_g12_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs4_g12_s0_station_sref_script }; /* 0x818fbe0 */

static const struct ScriptCommand s_gs4_g12_s0_eff0_script[] = { /* 0x818fbec */
    DEBUGINFO,
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    ALERT_CUE(7),
    ALERT_CUE(8),
    WALK_DIRECT(140, 10),
    FANFARE_PLAY2(451),
    WAIT(150),
    ALERT_CUE(5),
    WAIT(60),
    FANFARE_STOP2(451),
    WALK_DIRECT(60, 11),
    CAMERA_END_PAN,
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g12_s0_lives0_dlg0[] = { /* 0x818fcdc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x00cc,  0x00000002,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Over there... The\n{COLOR CYAN}Pelipper Post Office{RESET}.")),
    VARIANT_DEFAULT(_(" That building is the\n{COLOR CYAN}Pelipper Post Office{RESET}.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    WALK_GRID(256, 12),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is where information\nis gathered from Pokémon needing rescue\nin all sorts of places.")),
    VARIANT_DEFAULT(_(" This is where information\nis gathered from Pokémon needing rescue\nin various locations.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_NORTH),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Take a look at this!\nSee this Bulletin Board?")),
    VARIANT_DEFAULT(_(" See?\nHave a look at this Bulletin Board.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x8b, 0x14,  0x0004,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" It lists rescue jobs.\nCheck it out?")),
    TEXTBOX_CLEAR,
    SPECIAL_TEXT(SPECIAL_TEXT_BULLETIN_BOARD_JOBS, 0, 0),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" See?\nThere were jobs listed, right?")),
    VARIANT(/* == */  1, _(" If you want to go on a\nrescue, you first choose the job by\nselecting it with {COLOR YELLOW}Accept{RESET}...")),
    VARIANT(/* == */  1, _(" Then, on the {COLOR CYAN}Job List{RESET},\nchoose the job, then confirm it with\n{COLOR YELLOW}Take Job{RESET} to go on that rescue mission.")),
    VARIANT(/* == */  1, _(" If you don't select {COLOR YELLOW}Take Job{RESET},\nyou won't be able to do the rescue job even\nif you go to the dungeon.")),
    VARIANT(/* == */  1, _(" For the time being, we\nshould just stick with the jobs posted\nhere.")),
    VARIANT(/* == */  1, _(" Our team'll become known\nafter we do some rescue jobs.")),
    VARIANT(/* == */  1, _(" I bet we'll get job offers\nin our Mailbox soon.")),
    VARIANT(/* == */  3, _(" See?\nThere were jobs listed, right?")),
    VARIANT(/* == */  3, _(" If you want to do a rescue\njob, you first select it with {COLOR YELLOW}Accept{RESET}...")),
    VARIANT(/* == */  3, _(" Then, on the {COLOR CYAN}Job List{RESET},\nchoose the job, then confirm it with\n{COLOR YELLOW}Take Job{RESET} to go on that rescue mission.")),
    VARIANT(/* == */  3, _(" If you don't select {COLOR YELLOW}Take Job{RESET},\nyou can't do that rescue job even if you go\nto the dungeon. Be careful!")),
    VARIANT(/* == */  3, _(" While we're starting out,\nwe should handle the jobs that are posted\nhere.")),
    VARIANT(/* == */  3, _(" Doing that should get our\nteam some recognition.")),
    VARIANT(/* == */  3, _(" That should pull in job\noffers to our Mailbox soon.")),
    VARIANT_DEFAULT(_(" See?\nThere were jobs listed, right?")),
    VARIANT_DEFAULT(_(" To do a rescue job, you first\nselect it with {COLOR YELLOW}Accept{RESET}...")),
    VARIANT_DEFAULT(_(" Then, on the {COLOR CYAN}Job List{RESET},\nchoose the job, then confirm it with\n{COLOR YELLOW}Take Job{RESET} to go on that rescue mission.")),
    VARIANT_DEFAULT(_(" If you don't select {COLOR YELLOW}Take Job{RESET},\nyou can't do that rescue job even if you go\nto the dungeon.")),
    VARIANT_DEFAULT(_(" Since we're just starting up,\nwe should handle the jobs that are posted\nhere.")),
    VARIANT_DEFAULT(_(" Our team name will get\nbetter known by doing that.")),
    VARIANT_DEFAULT(_(" I think that will bring\njob offers to our Mailbox.")),
    TEXTBOX_CLEAR,
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" And if you want to take on\na rescue job...")),
    VARIANT(/* == */  1, _(" Choose the job on the {COLOR CYAN}Job\nList{RESET}...{WAIT_PRESS} Then, select {COLOR YELLOW}Take Job{RESET}.{WAIT_PRESS}\nGet in the habit of doing that regularly!")),
    VARIANT(/* == */  3, _(" And if you want to go on\na rescue mission...")),
    VARIANT(/* == */  3, _(" Choose the job on the {COLOR CYAN}Job\nList{RESET}...{WAIT_PRESS} Then, select {COLOR YELLOW}Take Job{RESET}.{WAIT_PRESS}\nDon't forget to do that before you leave!")),
    VARIANT_DEFAULT(_(" And if you want to go on\na rescue mission...")),
    VARIANT_DEFAULT(_(" Choose the job on the {COLOR CYAN}Job\nList{RESET}...{WAIT_PRESS} Then, select {COLOR YELLOW}Take Job{RESET}.{WAIT_PRESS}\nTry to always do that before you leave!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};


static const struct ScriptCommand s_gs4_g12_s0_lives1_dlg0[] = { /* 0x81909bc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x00cc,  0x00000002,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 13),
    WAIT(20),
    { 0x8e, 0x14,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WAIT(20),
    { 0x8b, 0x14,  0x0004,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g12_s0_lives2_dlg0[] = { /* 0x8190aec */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    { 0x60, 0x00,  0x0000,  0x00000008,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(60),
    { 0x68, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    WAIT(15),
    ROTATE(30, 10, DIRECTION_WEST),
    WAIT(15),
    WALK_DIRECT(120, 14),
    WAIT(15),
    END_DELETE,
    RET,
};

static const struct ScriptCommand s_gs4_g12_s0_lives3_dlg0[] = { /* 0x8190bec */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    { 0x60, 0x00,  0x0000,  0x00000018,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(160),
    WALK_DIRECT(120, 15),
    WAIT(15),
    ROTATE(30, 10, DIRECTION_SOUTH),
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT(15),
    END_DELETE,
    RET,
};

static const struct ScriptCommand s_gs4_g13_s0_station_sref_script[] = { /* 0x8190cec */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g13_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g13_s0_station_sref_script }; /* 0x8190d0c */

static const struct ScriptCommand s_gs4_g14_s0_station_sref_script[] = { /* 0x8190d18 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g14_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g14_s0_station_sref_script }; /* 0x8190d48 */

static const struct ScriptCommand s_gs4_g15_s0_station_sref_script[] = { /* 0x8190d54 */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g15_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g15_s0_station_sref_script }; /* 0x8190d74 */

static const struct ScriptCommand s_gs4_g16_s0_station_sref_script[] = { /* 0x8190d80 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g16_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g16_s0_station_sref_script }; /* 0x8190db0 */

static const struct ScriptCommand s_gs4_g16_s0_lives0_dlg2[] = { /* 0x8190dbc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Did you know that you get\na reward if you complete a rescue job?")),
    MSG_NPC(1, _(" Some Pokémon run rescue\nteams because they want the rewards.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g16_s0_lives1_dlg0[] = { /* 0x8190eb0 */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g16_s0_lives1_dlg2[] = { /* 0x8190ef0 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g16_s0_lives2_dlg0[] = { /* 0x8190f20 */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g16_s0_lives2_dlg2[] = { /* 0x8190f60 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g16_s1_station_sref_script[] = { /* 0x8190f90 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    RET,
};

static const struct ScriptRef s_gs4_g16_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g16_s1_station_sref_script }; /* 0x8190fc0 */

static const struct ScriptCommand s_gs4_g16_s1_lives0_dlg0[] = { /* 0x8190fcc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" What do you think, our son?\nIsn't the sea vast?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nPapa, have you ever gone out to sea?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nOf course.")),
    MSG_NPC(2, _(" What do you take us for?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh! You have!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g16_s1_lives1_dlg0[] = { /* 0x8191244 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs4_g16_s1_lives1_dlg2[] = { /* 0x81912f4 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g16_s1_lives2_dlg0[] = { /* 0x8191324 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    HALT,
};

static const struct ScriptCommand s_gs4_g16_s1_lives2_dlg2[] = { /* 0x81913c4 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s0_station_sref_script[] = { /* 0x81913f4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g17_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g17_s0_station_sref_script }; /* 0x8191424 */

static const struct ScriptCommand s_gs4_g17_s0_lives0_dlg0[] = { /* 0x8191430 */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g17_s0_lives0_dlg2[] = { /* 0x8191470 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s0_lives1_dlg0[] = { /* 0x81914a0 */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g17_s0_lives1_dlg2[] = { /* 0x81914e0 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s1_station_sref_script[] = { /* 0x8191510 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    RET,
};

static const struct ScriptRef s_gs4_g17_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g17_s1_station_sref_script }; /* 0x8191540 */

static const struct ScriptCommand s_gs4_g17_s1_lives0_dlg0[] = { /* 0x819154c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" What do you think, our son?\nIsn't the sea vast?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nPapa, have you ever gone out to sea?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nOf course.")),
    MSG_NPC(2, _(" What do you take us for?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh! You have!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g17_s1_lives1_dlg0[] = { /* 0x819171c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s1_lives1_dlg2[] = { /* 0x81917cc */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s1_lives2_dlg0[] = { /* 0x81917fc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    HALT,
};

static const struct ScriptCommand s_gs4_g17_s1_lives2_dlg2[] = { /* 0x819189c */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g18_s0_station_sref_script[] = { /* 0x81918cc */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 9, 4, /* to label */ 0),
    SELECT_ENTITIES(-1, -1),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(-1, -1),
    SELECT_LIVES(-1, 1),
  LABEL(1), /* = 0x01 */
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g18_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g18_s0_station_sref_script }; /* 0x819195c */

static const struct ScriptCommand s_gs4_g18_s0_lives0_dlg2[] = { /* 0x8191968 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(3, _(" ............Papa said they've\ngone to sea before...")),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" .........(Does that mean Papa\ncan swim...?)") },
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 3, _(" {NAME_0}.{WAIT_PRESS}\n{NAME_0}, can you swim?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("No.")),
  LABEL(0), /* = 0x00 */
    MSG_NPC(3, _(" Oh.\nSo you can swim too, {NAME_0}...")),
    MSG_NPC(3, _(" OK!\nI'm going to try hard to swim too!")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_NPC(3, _(" Oh.\nSo you can't swim either, {NAME_0}...")),
    MSG_NPC(3, _(" But that's natural.\nSwimming isn't very easy.")),
    MSG_NPC(3, _(" My papa is special!\nI'm going to try hard to swim too!")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g18_s0_lives0_dlg3[] = { /* 0x8191c7c */
    DEBUGINFO,
    { 0x2d, 0x09,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x8e, 0x0a,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs4_g18_s1_lives0_dlg2[] = { /* 0x8191d1c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You know what?\nThe jobs on the Bulletin Board...")),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" You can do several rescue\njobs at the same time.\nDid you know that?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("No.")),
  LABEL(0), /* = 0x00 */
    MSG_NPC(1, _(" Oh, you already knew?{WAIT_PRESS}\nThat's OK, then.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_NPC(1, _(" If you choose jobs in the\nsame dungeon on the {COLOR CYAN}Job List{RESET}, you can\ndo them at the same time.")),
    MSG_NPC(1, _(" For example, say there are\ntwo rescue jobs in the same dungeon, but\none on 5F and one on 10F.")),
    MSG_NPC(1, _(" You can accept these two\njobs, then select {COLOR YELLOW}Take Job{RESET} on both of them\nbefore heading into that dungeon.")),
    MSG_NPC(1, _(" You can complete the first\nrescue on 5F. Then, instead of exiting,\ngo on to the job on 10F.")),
    MSG_NPC(1, _(" That way, you can do two\nrescue jobs in one outing.")),
    MSG_NPC(1, _(" See?{WAIT_PRESS} If you do that, you\ncan take care of rescue jobs efficiently.")),
    MSG_NPC(1, _(" ...Ehe, this is what Alakazam\ntold me.{WAIT_PRESS} I just repeated what he said,\nso don't tell anyone else.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g19_s0_station_sref_script[] = { /* 0x8192190 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g19_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g19_s0_station_sref_script }; /* 0x81921d0 */

static const struct ScriptCommand s_gs4_g19_s0_lives0_dlg0[] = { /* 0x81921dc */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g19_s0_lives0_dlg2[] = { /* 0x819221c */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g19_s0_lives1_dlg0[] = { /* 0x819224c */
    DEBUGINFO,
    SELECT_ANIMATION(1),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g19_s0_lives1_dlg2[] = { /* 0x819228c */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g19_s1_station_sref_script[] = { /* 0x81922bc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    RET,
};

static const struct ScriptRef s_gs4_g19_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g19_s1_station_sref_script }; /* 0x81922ec */

static const struct ScriptCommand s_gs4_g19_s1_lives0_dlg0[] = { /* 0x81922f8 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" What do you think, Son?\nIsn't the sea wonderful?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.")),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nPapa, can you swim?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nOf course.")),
    MSG_NPC(2, _(" What do you take us for?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Oh! So you can swim!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs4_g19_s1_lives1_dlg0[] = { /* 0x8192548 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    RET,
};

static const struct ScriptCommand s_gs4_g19_s1_lives1_dlg2[] = { /* 0x81925f8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g19_s1_lives2_dlg0[] = { /* 0x8192628 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    RET,
};

static const struct ScriptCommand s_gs4_g19_s1_lives2_dlg2[] = { /* 0x81926c8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s0_station_sref_script[] = { /* 0x81926f8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g20_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g20_s0_station_sref_script }; /* 0x8192738 */

static const struct ScriptCommand s_gs4_g20_s0_lives0_dlg0[] = { /* 0x8192744 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs4_g20_s0_lives0_dlg2[] = { /* 0x8192784 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s0_lives1_dlg0[] = { /* 0x81927b4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s0_lives1_dlg2[] = { /* 0x8192854 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s1_lives0_dlg0[] = { /* 0x8192884 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g20_s1_station_sref_script[] = { /* 0x81928e4 */
    DEBUGINFO,
    CANCEL_LIVES(-1, 0),
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs4_g20_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g20_s1_station_sref_script }; /* 0x8192934 */

static const struct ScriptCommand s_gs4_g20_s1_eff0_script[] = { /* 0x8192940 */
    DEBUGINFO,
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    CAMERA_END_PAN,
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g20_s1_lives1_dlg0[] = { /* 0x81929a0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" Well, Son, doesn't it feel\ngood to look out over the sea?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nPapa, how do you swim in the sea?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nWell, Son...{WAIT_PRESS}\nThe three of us cooperate, and...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    TEXTBOX_AUTO_PRESS(0, 0),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_AUTO_PRESS(30, 30),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    TEXTBOX_AUTO_PRESS(-1, -1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    MSG_NPC(2, _(" ...And that's sort of how\nwe swim!{WAIT_PRESS}\nGasp, gasp...")),
    MSG_NPC(2, _(" What do you...{WAIT_PRESS}\nTake us for?!{WAIT_PRESS}\nGasp, gasp...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" OK!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs4_g20_s1_lives2_dlg0[] = { /* 0x8192fa8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g20_s1_lives3_dlg0[] = { /* 0x8193098 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01, -0x0050,  0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01,  0x0050, -0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01, -0x0030,  0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01,  0x0030, -0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ROTATE(8, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g20_s1_lives3_dlg2[] = { /* 0x81934f8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s1_lives4_dlg0[] = { /* 0x8193528 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    RET,
    HALT,
};

static const struct ScriptCommand s_gs4_g20_s1_lives4_dlg2[] = { /* 0x8193668 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g21_s0_station_sref_script[] = { /* 0x8193698 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g21_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g21_s0_station_sref_script }; /* 0x81936d8 */

static const struct ScriptCommand s_gs4_g21_s0_lives0_dlg0[] = { /* 0x81936e4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs4_g21_s0_lives0_dlg2[] = { /* 0x8193724 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g21_s0_lives1_dlg0[] = { /* 0x8193754 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs4_g21_s0_lives1_dlg2[] = { /* 0x8193794 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g21_s1_station_sref_script[] = { /* 0x81937c4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs4_g21_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g21_s1_station_sref_script }; /* 0x8193804 */

static const struct ScriptCommand s_gs4_g21_s1_eff0_script[] = { /* 0x8193810 */
    DEBUGINFO,
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    CAMERA_END_PAN,
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g21_s1_lives0_dlg0[] = { /* 0x8193870 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" Well, our son!\nTell me, do the earthquakes frighten you?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.{WAIT_PRESS}\nThey are very scary.")),
    MSG_NPC(3, _(" Especially when I'm\nburrowing. It makes me twitchy because\nI get so scared.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nPapa, aren't you afraid of earthquakes?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ........................{WAIT_PRESS}\nOf course they don't scare us.")),
    MSG_NPC(2, _(" What do you...{WAIT_PRESS}\nTake us for?!")),
    MSG_NPC(2, _(" If we were in charge...{WAIT_PRESS}\nThis is what we'd do to any earthquake!")),
    TEXTBOX_CLEAR,
    TEXTBOX_AUTO_PRESS(0, 0),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT_FLIP, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    TEXTBOX_AUTO_PRESS(30, 30),
    PORTRAIT(PLACEMENT_RIGHT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hah!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    TEXTBOX_AUTO_PRESS(-1, -1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Gasp, gasp...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" OK!{WAIT_PRESS}\nPapa, you're so special!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs4_g21_s1_lives1_dlg0[] = { /* 0x8193edc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g21_s1_lives2_dlg0[] = { /* 0x8193fcc */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01, -0x0050,  0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01,  0x0050, -0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01, -0x0030,  0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x59, 0x01,  0x0030, -0x00000030,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ROTATE(8, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g21_s1_lives2_dlg2[] = { /* 0x819442c */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g21_s1_lives3_dlg0[] = { /* 0x819445c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    RET,
};

static const struct ScriptCommand s_gs4_g21_s1_lives3_dlg2[] = { /* 0x819458c */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g22_s0_station_sref_script[] = { /* 0x81945bc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMPIF_ARRAY(EVENT_T01P03, 0, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(-1, 2),
  LABEL(1), /* = 0x01 */
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g22_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g22_s0_station_sref_script }; /* 0x819464c */

static const struct ScriptCommand s_gs4_g22_s0_lives0_dlg0[] = { /* 0x8194658 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs4_g22_s0_lives0_dlg2[] = { /* 0x8194698 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g22_s0_lives1_dlg2[] = { /* 0x81946c8 */
    DEBUGINFO,
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs4_g22_s1_station_sref_script[] = { /* 0x81946f8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 2),
    RET,
};

static const struct ScriptRef s_gs4_g22_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs4_g22_s1_station_sref_script }; /* 0x8194748 */

static const struct ScriptCommand s_gs4_g22_s1_eff0_script[] = { /* 0x8194754 */
    DEBUGINFO,
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    CAMERA_END_PAN,
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g22_s1_lives0_dlg0[] = { /* 0x81947b4 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(2, _(" Well, my son?\nDoes Groudon frighten you?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Yes, Papa.{WAIT_PRESS}\nIt frightens me so much I don't know\nwhat to think.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Papa?{WAIT_PRESS}\nAre you going to the {COLOR YELLOW_D}Magma Cavern{RESET} too,\nPapa?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ........................{WAIT_PRESS}\nOf course.")),
    MSG_NPC(2, _(" What do you take us for?!")),
    MSG_NPC(2, _(" If we were in charge...{WAIT_PRESS}\nThis is what we'd do to the {COLOR YELLOW_D}Magma\nCavern{RESET}!{WAIT_PRESS} Hah!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    TEXTBOX_AUTO_PRESS(10, 10),
    MSG_NPC(2, _(" Hah!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(486),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    TEXTBOX_AUTO_PRESS(-1, -1),
    MSG_NPC(3, _(" ............")),
    MSG_NPC(3, _(" ........................")),
    MSG_NPC(3, _(" ....................................{WAIT_PRESS}Huh?{WAIT_PRESS}\nPapa?{WAIT_PRESS} Where did you go, Papa?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    SET_ARRAYVAL(EVENT_T01P03,  0,  1),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs4_g22_s1_lives1_dlg0[] = { /* 0x8194c3c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g22_s1_lives2_dlg0[] = { /* 0x8194cac */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(5),
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g22_s1_lives3_dlg0[] = { /* 0x8194d7c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x8e, 0x04,  0x000a,  0x00000042,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(30),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs4_g22_s2_lives0_dlg0[] = { /* 0x8194e7c */
    DEBUGINFO,
    END_DELETE,
};

static const struct ScriptCommand s_gs4_g22_s2_lives1_dlg0[] = { /* 0x8194e9c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs4_g22_s2_lives1_dlg2[] = { /* 0x8194ecc */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" ?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g23_s0_station_sref_script[] = { /* 0x8194f20 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g23_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g23_s0_station_sref_script }; /* 0x8194f60 */

static const struct ScriptCommand s_gs4_g23_s0_lives0_dlg1[] = { /* 0x8194f6c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    HALT,
};

static const struct ScriptCommand s_gs4_g23_s0_lives0_dlg2[] = { /* 0x8194fac */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Papa hasn't come back...{WAIT_PRESS}\nI wonder where they went?")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh!{WAIT_PRESS} Maybe they've already\ngone to the {COLOR YELLOW_D}Magma Cavern{RESET}...")),
    MSG_NPC(1, _(" And maybe they're already\nfighting Groudon.")),
    MSG_NPC(1, _(" And, maybe, maybe...{WAIT_PRESS}\nMaybe they've already won.{WAIT_PRESS}\nMaybe they've already beaten Groudon!")),
    MSG_NPC(1, _(" Oh, wow! That's amazing!{WAIT_PRESS}\nMaybe Papa is special!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g23_s0_lives0_dlg3[] = { /* 0x81951c0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs4_g24_s0_station_sref_script[] = { /* 0x8195240 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g24_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g24_s0_station_sref_script }; /* 0x8195270 */

static const struct ScriptCommand s_gs4_g24_s0_lives0_dlg0[] = { /* 0x819527c */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g24_s0_lives0_dlg2[] = { /* 0x81952bc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Papa hasn't come back yet...\nI wonder what happened to them?")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh!{WAIT_PRESS}\nMaybe they've already gone to the sky...")),
    MSG_NPC(1, _(" And maybe they've already\nmet Rayquaza...")),
    MSG_NPC(1, _(" ...That's not possible.\nEven Papa can't fly.")),
    MSG_NPC(1, _(" Sigh...\nWhere did Papa go...?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g24_s0_lives0_dlg3[] = { /* 0x8195484 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs4_g24_s0_lives1_dlg2[] = { /* 0x8195504 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" If that shooting star\ncrashes, it's going to be terrible!")),
    MSG_NPC(1, _(" You're our only hope!\nGo for it!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g24_s0_lives2_dlg2[] = { /* 0x81955d8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh my, isn't this awful!")),
    MSG_NPC(1, _(" But I get the feeling that\nyou can make a difference, {NAME_0}!\nPlease don't let us down!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g25_s0_station_sref_script[] = { /* 0x81956c4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g25_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g25_s0_station_sref_script }; /* 0x8195704 */

static const struct ScriptCommand s_gs4_g25_s0_lives0_dlg0[] = { /* 0x8195710 */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g25_s0_lives0_dlg2[] = { /* 0x8195750 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Papa hasn't come back yet...\nI wonder what happened to them?")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh!{WAIT_PRESS}\nMaybe they've already gone to the sky...")),
    MSG_NPC(1, _(" And maybe they've already\nmet Rayquaza...")),
    MSG_NPC(1, _(" ...That's not possible.\nEven Papa can't fly.")),
    MSG_NPC(1, _(" Sigh...\nWhere did Papa go...?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g25_s0_lives0_dlg3[] = { /* 0x8195820 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs4_g25_s0_lives1_dlg2[] = { /* 0x81958a0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You're going, aren't you?\nGo for it!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g25_s0_lives2_dlg2[] = { /* 0x819592c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh my, it's time to go?")),
    MSG_NPC(1, _(" Please take care.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g26_s0_station_sref_script[] = { /* 0x81959d0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs4_g26_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g26_s0_station_sref_script }; /* 0x8195a10 */

static const struct ScriptCommand s_gs4_g26_s0_lives0_dlg0[] = { /* 0x8195a1c */
    DEBUGINFO,
    { 0x52, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g26_s0_lives0_dlg2[] = { /* 0x8195a5c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Papa hasn't come back yet...\nI wonder what happened to them?")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh!{WAIT_PRESS}\nMaybe they've already gone to the sky...")),
    MSG_NPC(1, _(" And maybe they've already\nmet Rayquaza...")),
    MSG_NPC(1, _(" ...That's not possible.\nEven Papa can't fly.")),
    MSG_NPC(1, _(" Sigh...\nWhere did Papa go...?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g26_s0_lives0_dlg3[] = { /* 0x8195b2c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs4_g26_s0_lives1_dlg2[] = { /* 0x8195bac */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You'll get it done next time!\nGo for it!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g26_s0_lives2_dlg2[] = { /* 0x8195c38 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You must make another\nchallenge.")),
    MSG_NPC(1, _(" You have my support!\nPlease don't fail us!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g27_s0_station_sref_script[] = { /* 0x8195cfc */
    DEBUGINFO,
    SELECT_MAP(4),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(41),
    { 0x22, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(240),
    { 0x23, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs4_g27_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g27_s0_station_sref_script }; /* 0x8195d7c */

static const struct ScriptCommand s_gs4_g27_s0_eff0_script[] = { /* 0x8195d88 */
    DEBUGINFO,
    CAMERA_INIT_PAN,
    WALK_GRID(153, 16),
    HALT,
};

static const struct ScriptCommand s_gs4_g28_s0_station_sref_script[] = { /* 0x8195dc8 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs4_g28_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs4_g28_s0_station_sref_script }; /* 0x8195df8 */

static const struct ScriptCommand s_gs4_g28_s0_lives0_dlg1[] = { /* 0x8195e04 */
    DEBUGINFO,
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs4_g28_s0_lives0_dlg2[] = { /* 0x8195e54 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" (Everything returned to\npeace...)") },
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" But Papa still hasn't come\nback...")),
    MSG_NPC(1, _(" Everyone says they haven't\nseen them...{WAIT_PRESS}\nWhere did my papa go?")),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh!{WAIT_PRESS}\nMaybe they got left behind in the sky...")),
    MSG_NPC(1, _(" And maybe Rayquaza is\nhaving them as a meal...")),
    MSG_NPC(1, _(" ......{WAIT_PRESS}That's not possible.{WAIT_PRESS}\nPapa can't fly in the first place.")),
    MSG_NPC(1, _(" Sigh...\nWhere did Papa go...?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g28_s0_lives0_dlg3[] = { /* 0x819609c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs4_g28_s0_lives1_dlg2[] = { /* 0x819614c */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, how marvelous,\n{NAME_0}!")),
    MSG_NPC(1, _(" I can go on living again\nwithout fear. Thank you!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g28_s0_lives2_dlg2[] = { /* 0x8196210 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You were flat-out\nincredible!")),
    MSG_NPC(1, _(" Seriously, consider teaming\nup with me! Gahahaha!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g28_s0_lives3_dlg2[] = { /* 0x81962d8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, darlings, you've outdone\nyourselves, {NAME_0}!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g28_s0_lives4_dlg2[] = { /* 0x8196370 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You fought your way up\na tower of clouds?{WAIT_PRESS} I can't even imagine\nthat. Sounds kind of wow!{WAIT_PRESS} Ayup!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs4_g29_s0_station_sref_script[] = { /* 0x8196438 */
    DEBUGINFO,
    SELECT_MAP(4),
    CANCEL_ENTITIES(0, 0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(40),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs4_g29_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs4_g29_s0_station_sref_script }; /* 0x81964c8 */

static const struct ScriptCommand s_gs4_g29_s0_lives0_dlg0[] = { /* 0x81964d4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0100,  0x00000011,  0x00000000, NULL },
    { 0x80, 0x00,  0x0180,  0x00000012,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x80, 0x00,  0x0200,  0x00000013,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs4_g0_s0_lives[] = { /* 0x8196574 */
    /*  0 */ {  56,   0,   0,   0, {  49,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s0_lives0_dlg0,
    } },
    /*  1 */ {  57,   0,   0,   0, {  89,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g0_s1_lives[] = { /* 0x81965a4 */
    /*  0 */ {   0,   2,   0,   0, {   9,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   6,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g0_s2_lives[] = { /* 0x81965d4 */
    /*  0 */ {   0,   0,   0,   0, {  49,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  49,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g0_s3_lives[] = { /* 0x8196604 */
    /*  0 */ {   0,   0,   0,   0, {  27,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  23,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g0_s4_lives[] = { /* 0x8196634 */
    /*  0 */ {   0,   4,   0,   0, {  37,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  37,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g1_s0_lives[] = { /* 0x8196664 */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s0_lives0_dlg2,
    } },
    /*  1 */ { 104,   3,   0,   0, {  33,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s0_lives1_dlg2,
    } },
    /*  2 */ { 106,   4,   0,   0, {  37,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s0_lives2_dlg2,
    } },
    /*  3 */ { 105,   5,   0,   0, {  41,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  79,   0,   0,   0, {  29,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g1_s0_lives4_dlg0,
        [2] = s_gs4_g1_s0_lives4_dlg2,
        [3] = s_gs4_g1_s0_lives4_dlg3,
    } },
};

static const struct GroundLivesData s_gs4_g1_s1_lives[] = { /* 0x81966dc */
    /*  0 */ {   0,   2,   0,   0, {  60,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g1_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  60,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g1_s1_lives1_dlg0,
    } },
    /*  2 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g1_s1_lives2_dlg0,
    } },
    /*  3 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g1_s1_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g1_s2_lives[] = { /* 0x819673c */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s2_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g1_s2_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g3_s0_lives[] = { /* 0x819676c */
    /*  0 */ {   0,   4,   0,   0, {  23,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  27,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g3_s0_lives1_dlg0,
    } },
    /*  2 */ { 109,   0,   0,   0, {  27,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g3_s0_lives2_dlg0,
    } },
    /*  3 */ { 110,   0,   0,   0, {  23,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g3_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g4_s0_lives[] = { /* 0x81967cc */
    /*  0 */ { 124,   0,   0,   0, {  27,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g4_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g5_s0_lives[] = { /* 0x81967e4 */
    /*  0 */ {   1,   4,   0,   0, {  35,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  39,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g6_s0_lives[] = { /* 0x8196814 */
    /*  0 */ {  92,   4,   0,   0, {  39,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g6_s0_lives0_dlg0,
        [2] = s_gs4_g6_s0_lives0_dlg2,
        [3] = s_gs4_g6_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs4_g7_s0_lives[] = { /* 0x819682c */
    /*  0 */ {   0,   4,   0,   0, {  37,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g7_s0_lives0_dlg0,
    } },
    /*  1 */ { 104,   3,   0,   0, {  33,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g7_s0_lives1_dlg0,
    } },
    /*  2 */ { 106,   4,   0,   0, {  37,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g7_s0_lives2_dlg0,
    } },
    /*  3 */ { 105,   5,   0,   0, {  41,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g7_s0_lives3_dlg0,
    } },
    /*  4 */ {  92,   4,   0,   0, {  39,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g7_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g8_s0_lives[] = { /* 0x81968a4 */
    /*  0 */ {  93,   2,   0,   0, {  26,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g8_s0_lives0_dlg0,
        [2] = s_gs4_g8_s0_lives0_dlg2,
    } },
    /*  1 */ {  92,   6,   0,   0, {  30,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g8_s0_lives1_dlg0,
        [2] = s_gs4_g8_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g9_s0_lives[] = { /* 0x81968d4 */
    /*  0 */ {   0,   0,   0,   0, {  28,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g9_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  28,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g9_s0_lives1_dlg0,
    } },
    /*  2 */ {  93,   2,   0,   0, {  30,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g9_s0_lives2_dlg0,
    } },
    /*  3 */ {  92,   6,   0,   0, {  26,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g9_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g10_s0_lives[] = { /* 0x8196934 */
    /*  0 */ {  93,   2,   0,   0, {  26,  47, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g10_s0_lives0_dlg2,
    } },
    /*  1 */ {  92,   6,   0,   0, {  30,  47, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g10_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g11_s1_lives[] = { /* 0x8196964 */
    /*  0 */ {   0,   4,   0,   0, {  35,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  40,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g11_s2_lives[] = { /* 0x8196994 */
    /*  0 */ {   0,   4,   0,   0, {  37,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g11_s3_lives[] = { /* 0x81969ac */
    /*  0 */ {  30,   0,   0,   0, {  37,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s3_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g11_s4_lives[] = { /* 0x81969c4 */
    /*  0 */ {  31,   0,   0,   0, {  37,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s4_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g11_s5_lives[] = { /* 0x81969dc */
    /*  0 */ {  30,   0,   0,   0, {  35,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s5_lives0_dlg0,
    } },
    /*  1 */ {  31,   0,   0,   0, {  40,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g11_s5_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g12_s0_lives[] = { /* 0x8196a0c */
    /*  0 */ {   0,   2,   0,   0, {   3,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g12_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   6,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g12_s0_lives1_dlg0,
    } },
    /*  2 */ {  58,   0,   0,   0, {  50,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g12_s0_lives2_dlg0,
    } },
    /*  3 */ {  59,   6,   0,   0, {  73,  21, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g12_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g16_s0_lives[] = { /* 0x8196a6c */
    /*  0 */ {  80,   4,   0,   0, {  40,  42, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g16_s0_lives0_dlg2,
    } },
    /*  1 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g16_s0_lives1_dlg0,
        [2] = s_gs4_g16_s0_lives1_dlg2,
    } },
    /*  2 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g16_s0_lives2_dlg0,
        [2] = s_gs4_g16_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g16_s1_lives[] = { /* 0x8196ab4 */
    /*  0 */ {   0,   0,   0,   0, {  61,  20, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g16_s1_lives0_dlg0,
    } },
    /*  1 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g16_s1_lives1_dlg0,
        [2] = s_gs4_g16_s1_lives1_dlg2,
    } },
    /*  2 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g16_s1_lives2_dlg0,
        [2] = s_gs4_g16_s1_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g17_s0_lives[] = { /* 0x8196afc */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g17_s0_lives0_dlg0,
        [2] = s_gs4_g17_s0_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g17_s0_lives1_dlg0,
        [2] = s_gs4_g17_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g17_s1_lives[] = { /* 0x8196b2c */
    /*  0 */ {   0,   0,   0,   0, {  61,  20, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g17_s1_lives0_dlg0,
    } },
    /*  1 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g17_s1_lives1_dlg0,
        [2] = s_gs4_g17_s1_lives1_dlg2,
    } },
    /*  2 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g17_s1_lives2_dlg0,
        [2] = s_gs4_g17_s1_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g18_s0_lives[] = { /* 0x8196b74 */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g18_s0_lives0_dlg2,
        [3] = s_gs4_g18_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs4_g18_s1_lives[] = { /* 0x8196b8c */
    /*  0 */ {  80,   4,   0,   0, {  40,  42, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g18_s1_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g19_s0_lives[] = { /* 0x8196ba4 */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g19_s0_lives0_dlg0,
        [2] = s_gs4_g19_s0_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g19_s0_lives1_dlg0,
        [2] = s_gs4_g19_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g19_s1_lives[] = { /* 0x8196bd4 */
    /*  0 */ {   0,   0,   0,   0, {   7,  10, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g19_s1_lives0_dlg0,
    } },
    /*  1 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g19_s1_lives1_dlg0,
        [2] = s_gs4_g19_s1_lives1_dlg2,
    } },
    /*  2 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g19_s1_lives2_dlg0,
        [2] = s_gs4_g19_s1_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g20_s0_lives[] = { /* 0x8196c1c */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s0_lives0_dlg0,
        [2] = s_gs4_g20_s0_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s0_lives1_dlg0,
        [2] = s_gs4_g20_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g20_s1_lives[] = { /* 0x8196c4c */
    /*  0 */ {   4,   2,   0,   0, {  60,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s1_lives0_dlg0,
    } },
    /*  1 */ {   0,   2,   0,   0, {  60,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s1_lives1_dlg0,
    } },
    /*  2 */ {   4,   2,   0,   0, {  60,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s1_lives2_dlg0,
    } },
    /*  3 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s1_lives3_dlg0,
        [2] = s_gs4_g20_s1_lives3_dlg2,
    } },
    /*  4 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g20_s1_lives4_dlg0,
        [2] = s_gs4_g20_s1_lives4_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g21_s0_lives[] = { /* 0x8196cc4 */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s0_lives0_dlg0,
        [2] = s_gs4_g21_s0_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s0_lives1_dlg0,
        [2] = s_gs4_g21_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g21_s1_lives[] = { /* 0x8196cf4 */
    /*  0 */ {   0,   2,   0,   0, {  60,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  60,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s1_lives1_dlg0,
    } },
    /*  2 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s1_lives2_dlg0,
        [2] = s_gs4_g21_s1_lives2_dlg2,
    } },
    /*  3 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g21_s1_lives3_dlg0,
        [2] = s_gs4_g21_s1_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g22_s0_lives[] = { /* 0x8196d54 */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s0_lives0_dlg0,
        [2] = s_gs4_g22_s0_lives0_dlg2,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g22_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g22_s1_lives[] = { /* 0x8196d84 */
    /*  0 */ {   0,   2,   0,   0, {  60,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  60,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s1_lives1_dlg0,
    } },
    /*  2 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s1_lives2_dlg0,
    } },
    /*  3 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s1_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs4_g22_s2_lives[] = { /* 0x8196de4 */
    /*  0 */ {  66,   2,   0,   0, {  63,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s2_lives0_dlg0,
    } },
    /*  1 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g22_s2_lives1_dlg0,
        [2] = s_gs4_g22_s2_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g23_s0_lives[] = { /* 0x8196e14 */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [1] = s_gs4_g23_s0_lives0_dlg1,
        [2] = s_gs4_g23_s0_lives0_dlg2,
        [3] = s_gs4_g23_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs4_g24_s0_lives[] = { /* 0x8196e2c */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g24_s0_lives0_dlg0,
        [2] = s_gs4_g24_s0_lives0_dlg2,
        [3] = s_gs4_g24_s0_lives0_dlg3,
    } },
    /*  1 */ {  80,   4,   0,   0, {  40,  42, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g24_s0_lives1_dlg2,
    } },
    /*  2 */ {  79,   0,   0,   0, {  29,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g24_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g25_s0_lives[] = { /* 0x8196e74 */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g25_s0_lives0_dlg0,
        [2] = s_gs4_g25_s0_lives0_dlg2,
        [3] = s_gs4_g25_s0_lives0_dlg3,
    } },
    /*  1 */ {  80,   4,   0,   0, {  40,  42, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g25_s0_lives1_dlg2,
    } },
    /*  2 */ {  79,   0,   0,   0, {  29,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g25_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g26_s0_lives[] = { /* 0x8196ebc */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g26_s0_lives0_dlg0,
        [2] = s_gs4_g26_s0_lives0_dlg2,
        [3] = s_gs4_g26_s0_lives0_dlg3,
    } },
    /*  1 */ {  80,   4,   0,   0, {  40,  42, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g26_s0_lives1_dlg2,
    } },
    /*  2 */ {  79,   0,   0,   0, {  29,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g26_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g28_s0_lives[] = { /* 0x8196f04 */
    /*  0 */ {  68,   2,   0,   0, {  63,  34, 0, CPOS_HALFTILE }, {
        [1] = s_gs4_g28_s0_lives0_dlg1,
        [2] = s_gs4_g28_s0_lives0_dlg2,
        [3] = s_gs4_g28_s0_lives0_dlg3,
    } },
    /*  1 */ {  79,   0,   0,   0, {  29,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g28_s0_lives1_dlg2,
    } },
    /*  2 */ { 104,   6,   0,   0, {  40,  41, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g28_s0_lives2_dlg2,
    } },
    /*  3 */ { 105,   6,   0,   0, {  40,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs4_g28_s0_lives3_dlg2,
    } },
    /*  4 */ { 106,   2,   0,   0, {  34,  43, 0, 0 }, {
        [2] = s_gs4_g28_s0_lives4_dlg2,
    } },
};

static const struct GroundLivesData s_gs4_g29_s0_lives[] = { /* 0x8196f7c */
    /*  0 */ {  55,   2,   0,   0, {  51,  25, 0, CPOS_HALFTILE }, {
        [0] = s_gs4_g29_s0_lives0_dlg0,
    } },
};

static const struct GroundObjectData s_gs4_g0_s0_objs[] = { /* 0x8196f94 */
    /*  0 */ {  14,   0,   5,   2, {  37,  38, CPOS_HALFTILE, 0 }, {
        [2] = s_gs4_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs4_g1_s1_effs[] = { /* 0x8196fac */
    /*  0 */ {   0,   0,   1,   1, {  56,  39, 0, 0 }, s_gs4_g1_s1_eff0_script },
};

static const struct GroundEffectData s_gs4_g3_s0_effs[] = { /* 0x8196fb8 */
    /*  0 */ {   0,   0,   1,   1, {  25,  38, 0, CPOS_HALFTILE }, s_gs4_g3_s0_eff0_script },
};

static const struct GroundEffectData s_gs4_g5_s0_effs[] = { /* 0x8196fc4 */
    /*  0 */ {   0,   0,   1,   1, {  37,  38, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs4_g7_s0_effs[] = { /* 0x8196fd0 */
    /*  0 */ {   0,   0,   1,   1, {  37,  38, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs4_g11_s0_effs[] = { /* 0x8196fdc */
    /*  0 */ {   0,   0,   1,   1, {  37,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs4_g12_s0_effs[] = { /* 0x8196fe8 */
    /*  0 */ {   0,   0,   1,   1, {  15,  40, 0, CPOS_HALFTILE }, s_gs4_g12_s0_eff0_script },
};

static const struct GroundEffectData s_gs4_g20_s1_effs[] = { /* 0x8196ff4 */
    /*  0 */ {   0,   0,   1,   1, {  61,  34, 0, 0 }, s_gs4_g20_s1_eff0_script },
};

static const struct GroundEffectData s_gs4_g21_s1_effs[] = { /* 0x8197000 */
    /*  0 */ {   0,   0,   1,   1, {  61,  34, 0, 0 }, s_gs4_g21_s1_eff0_script },
};

static const struct GroundEffectData s_gs4_g22_s1_effs[] = { /* 0x819700c */
    /*  0 */ {   0,   0,   1,   1, {  61,  34, 0, 0 }, s_gs4_g22_s1_eff0_script },
};

static const struct GroundEffectData s_gs4_g27_s0_effs[] = { /* 0x8197018 */
    /*  0 */ {   0,   0,   1,   1, {  32,  29, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs4_g27_s0_eff0_script },
};

static const struct GroundEffectData s_gs4_g29_s0_effs[] = { /* 0x8197024 */
    /*  0 */ {   0,   0,   1,   1, {  55,  27, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs4_g0_s0_evts[] = { /* 0x8197030 */
    /*  0 */ {   3,  66,   0,   0, {   0,   0, 0, 0 }, &s_gs4_g0_s0_evt0_sref },
    /*  1 */ {   3,   3,   0,   0, {  48,  31, 0, 0 }, &s_gs4_g0_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8197048 */
    &s_gs4_g0_s0_station_sref,
    &s_gs4_g1_s0_station_sref,
    &s_gs4_g1_s1_station_sref,
    &s_gs4_g1_s2_station_sref,
    &s_gs4_g2_s0_station_sref,
    &s_gs4_g3_s0_station_sref,
    &s_gs4_g5_s0_station_sref,
    &s_gs4_g7_s0_station_sref,
    &s_gs4_g9_s0_station_sref,
    &s_gs4_g11_s0_station_sref,
    &s_gs4_g12_s0_station_sref,
    &s_gs4_g13_s0_station_sref,
    &s_gs4_g14_s0_station_sref,
    &s_gs4_g15_s0_station_sref,
    &s_gs4_g16_s0_station_sref,
    &s_gs4_g16_s1_station_sref,
    &s_gs4_g17_s0_station_sref,
    &s_gs4_g17_s1_station_sref,
    &s_gs4_g18_s0_station_sref,
    &s_gs4_g19_s0_station_sref,
    &s_gs4_g19_s1_station_sref,
    &s_gs4_g20_s0_station_sref,
    &s_gs4_g20_s1_station_sref,
    &s_gs4_g21_s0_station_sref,
    &s_gs4_g21_s1_station_sref,
    &s_gs4_g22_s0_station_sref,
    &s_gs4_g22_s1_station_sref,
    &s_gs4_g23_s0_station_sref,
    &s_gs4_g24_s0_station_sref,
    &s_gs4_g25_s0_station_sref,
    &s_gs4_g26_s0_station_sref,
    &s_gs4_g27_s0_station_sref,
    &s_gs4_g28_s0_station_sref,
    &s_gs4_g29_s0_station_sref,
};

static const struct GroundScriptSector s_gs4_g0_sectors[] = { /* 0x81970d0 */
    { LPARRAY(s_gs4_g0_s0_lives), LPARRAY(s_gs4_g0_s0_objs), 0,NULL, LPARRAY(s_gs4_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs4_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g1_sectors[] = { /* 0x8197198 */
    { LPARRAY(s_gs4_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs4_g1_s1_lives), 0,NULL, LPARRAY(s_gs4_g1_s1_effs), 0,NULL, 1,&sStationScripts[2], },
    { LPARRAY(s_gs4_g1_s2_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs4_g2_sectors[] = { /* 0x8197210 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs4_g3_sectors[] = { /* 0x8197238 */
    { LPARRAY(s_gs4_g3_s0_lives), 0,NULL, LPARRAY(s_gs4_g3_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs4_g4_sectors[] = { /* 0x8197260 */
    { LPARRAY(s_gs4_g4_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g5_sectors[] = { /* 0x8197288 */
    { LPARRAY(s_gs4_g5_s0_lives), 0,NULL, LPARRAY(s_gs4_g5_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs4_g6_sectors[] = { /* 0x81972b0 */
    { LPARRAY(s_gs4_g6_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g7_sectors[] = { /* 0x81972d8 */
    { LPARRAY(s_gs4_g7_s0_lives), 0,NULL, LPARRAY(s_gs4_g7_s0_effs), 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptSector s_gs4_g8_sectors[] = { /* 0x8197300 */
    { LPARRAY(s_gs4_g8_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g9_sectors[] = { /* 0x8197328 */
    { LPARRAY(s_gs4_g9_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[8], },
};

static const struct GroundScriptSector s_gs4_g10_sectors[] = { /* 0x8197350 */
    { LPARRAY(s_gs4_g10_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g11_sectors[] = { /* 0x8197378 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs4_g11_s0_effs), 0,NULL, 1,&sStationScripts[9], },
    { LPARRAY(s_gs4_g11_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g11_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g11_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g11_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs4_g11_s5_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g12_sectors[] = { /* 0x8197468 */
    { LPARRAY(s_gs4_g12_s0_lives), 0,NULL, LPARRAY(s_gs4_g12_s0_effs), 0,NULL, 1,&sStationScripts[10], },
};

static const struct GroundScriptSector s_gs4_g13_sectors[] = { /* 0x8197490 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[11], },
};

static const struct GroundScriptSector s_gs4_g14_sectors[] = { /* 0x81974b8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[12], },
};

static const struct GroundScriptSector s_gs4_g15_sectors[] = { /* 0x81974e0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[13], },
};

static const struct GroundScriptSector s_gs4_g16_sectors[] = { /* 0x8197508 */
    { LPARRAY(s_gs4_g16_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[14], },
    { LPARRAY(s_gs4_g16_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[15], },
};

static const struct GroundScriptSector s_gs4_g17_sectors[] = { /* 0x8197558 */
    { LPARRAY(s_gs4_g17_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[16], },
    { LPARRAY(s_gs4_g17_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[17], },
};

static const struct GroundScriptSector s_gs4_g18_sectors[] = { /* 0x81975a8 */
    { LPARRAY(s_gs4_g18_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[18], },
    { LPARRAY(s_gs4_g18_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g19_sectors[] = { /* 0x81975f8 */
    { LPARRAY(s_gs4_g19_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[19], },
    { LPARRAY(s_gs4_g19_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[20], },
};

static const struct GroundScriptSector s_gs4_g20_sectors[] = { /* 0x8197648 */
    { LPARRAY(s_gs4_g20_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[21], },
    { LPARRAY(s_gs4_g20_s1_lives), 0,NULL, LPARRAY(s_gs4_g20_s1_effs), 0,NULL, 1,&sStationScripts[22], },
};

static const struct GroundScriptSector s_gs4_g21_sectors[] = { /* 0x8197698 */
    { LPARRAY(s_gs4_g21_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[23], },
    { LPARRAY(s_gs4_g21_s1_lives), 0,NULL, LPARRAY(s_gs4_g21_s1_effs), 0,NULL, 1,&sStationScripts[24], },
};

static const struct GroundScriptSector s_gs4_g22_sectors[] = { /* 0x81976e8 */
    { LPARRAY(s_gs4_g22_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[25], },
    { LPARRAY(s_gs4_g22_s1_lives), 0,NULL, LPARRAY(s_gs4_g22_s1_effs), 0,NULL, 1,&sStationScripts[26], },
    { LPARRAY(s_gs4_g22_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs4_g23_sectors[] = { /* 0x8197760 */
    { LPARRAY(s_gs4_g23_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[27], },
};

static const struct GroundScriptSector s_gs4_g24_sectors[] = { /* 0x8197788 */
    { LPARRAY(s_gs4_g24_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[28], },
};

static const struct GroundScriptSector s_gs4_g25_sectors[] = { /* 0x81977b0 */
    { LPARRAY(s_gs4_g25_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[29], },
};

static const struct GroundScriptSector s_gs4_g26_sectors[] = { /* 0x81977d8 */
    { LPARRAY(s_gs4_g26_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[30], },
};

static const struct GroundScriptSector s_gs4_g27_sectors[] = { /* 0x8197800 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs4_g27_s0_effs), 0,NULL, 1,&sStationScripts[31], },
};

static const struct GroundScriptSector s_gs4_g28_sectors[] = { /* 0x8197828 */
    { LPARRAY(s_gs4_g28_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[32], },
};

static const struct GroundScriptSector s_gs4_g29_sectors[] = { /* 0x8197850 */
    { LPARRAY(s_gs4_g29_s0_lives), 0,NULL, LPARRAY(s_gs4_g29_s0_effs), 0,NULL, 1,&sStationScripts[33], },
};

static const struct GroundScriptGroup s_gs4_groups[] = { /* 0x8197878 */
    { LPARRAY(s_gs4_g0_sectors) },
    { LPARRAY(s_gs4_g1_sectors) },
    { LPARRAY(s_gs4_g2_sectors) },
    { LPARRAY(s_gs4_g3_sectors) },
    { LPARRAY(s_gs4_g4_sectors) },
    { LPARRAY(s_gs4_g5_sectors) },
    { LPARRAY(s_gs4_g6_sectors) },
    { LPARRAY(s_gs4_g7_sectors) },
    { LPARRAY(s_gs4_g8_sectors) },
    { LPARRAY(s_gs4_g9_sectors) },
    { LPARRAY(s_gs4_g10_sectors) },
    { LPARRAY(s_gs4_g11_sectors) },
    { LPARRAY(s_gs4_g12_sectors) },
    { LPARRAY(s_gs4_g13_sectors) },
    { LPARRAY(s_gs4_g14_sectors) },
    { LPARRAY(s_gs4_g15_sectors) },
    { LPARRAY(s_gs4_g16_sectors) },
    { LPARRAY(s_gs4_g17_sectors) },
    { LPARRAY(s_gs4_g18_sectors) },
    { LPARRAY(s_gs4_g19_sectors) },
    { LPARRAY(s_gs4_g20_sectors) },
    { LPARRAY(s_gs4_g21_sectors) },
    { LPARRAY(s_gs4_g22_sectors) },
    { LPARRAY(s_gs4_g23_sectors) },
    { LPARRAY(s_gs4_g24_sectors) },
    { LPARRAY(s_gs4_g25_sectors) },
    { LPARRAY(s_gs4_g26_sectors) },
    { LPARRAY(s_gs4_g27_sectors) },
    { LPARRAY(s_gs4_g28_sectors) },
    { LPARRAY(s_gs4_g29_sectors) },
};

static const struct GroundLink s_gs4_links[] = { /* 0x8197968 */
    /* link   0 */ { { /*x*/  50, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/   0, /*y*/   9, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  53, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  88, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   4 */ { { /*x*/  61, /*y*/  33, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  53, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   6 */ { { /*x*/  56, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   7 */ { { /*x*/  59, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/  60, /*y*/  29, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/  63, /*y*/  31, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/  50, /*y*/  25, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  11 */ { { /*x*/  37, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  12 */ { { /*x*/  36, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  13 */ { { /*x*/  39, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  14 */ { { /*x*/  22, /*y*/  18, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  15 */ { { /*x*/  53, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  16 */ { { /*x*/  57, /*y*/  29, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  17 */ { { /*x*/  57, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  18 */ { { /*x*/  63, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  19 */ { { /*x*/  74, /*y*/  12, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs4 = { LPARRAY(s_gs4_groups), s_gs4_links }; /* 0x8197a08 */
