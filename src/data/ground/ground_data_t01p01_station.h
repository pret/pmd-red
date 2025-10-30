

























































































































































static const struct ScriptCommand s_gs1_g0_s0_station_sref_script[] = { /* 0x8138268 */
    DEBUGINFO_O(156),
    SELECT_MAP(1),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_LT, 4, /* to label */ 0),
    COND(JUDGE_EQ, 4, /* to label */ 1),
    COND(JUDGE_EQ, 5, /* to label */ 2),
    COND(JUDGE_EQ, 6, /* to label */ 3),
    COND(JUDGE_EQ, 7, /* to label */ 4),
    COND(JUDGE_EQ, 8, /* to label */ 5),
    COND(JUDGE_EQ, 9, /* to label */ 6),
    COND(JUDGE_EQ, 10, /* to label */ 7),
    COND(JUDGE_EQ, 11, /* to label */ 8),
    COND(JUDGE_LT, 15, /* to label */ 0),
    COND(JUDGE_EQ, 15, /* to label */ 9),
    COND(JUDGE_EQ, 16, /* to label */ 10),
    COND(JUDGE_LT, 18, /* to label */ 11),
    COND(JUDGE_EQ, 18, /* to label */ 12),
    JUMP_LABEL(13),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 14),
    JUMP_LABEL(15),
  LABEL(14), /* = 0x0e */
    CALL_STATION(  7,  0),
    JUMP_LABEL(0),
  LABEL(15), /* = 0x0f */
    CALL_STATION(  7,  0),
    JUMP_LABEL(0),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 16),
    COND(JUDGE_LE, 3, /* to label */ 17),
    COND_EQUAL(4, /* to label */ 18),
    CALL_STATION( 11,  0),
    JUMP_LABEL(0),
  LABEL(16), /* = 0x10 */
    CALL_STATION(  7,  0),
    JUMP_LABEL(0),
  LABEL(17), /* = 0x11 */
    CALL_STATION(  8,  0),
    JUMP_LABEL(0),
  LABEL(18), /* = 0x12 */
    CALL_STATION(  8,  0),
    SELECT_ENTITIES(8, 2),
    JUMP_LABEL(0),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 19),
    CALL_STATION( 13,  0),
    JUMP_LABEL(0),
  LABEL(19), /* = 0x13 */
    CALL_STATION( 11,  0),
    JUMP_LABEL(0),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 20),
    CALL_STATION( 14,  0),
    JUMP_LABEL(0),
  LABEL(20), /* = 0x14 */
    CALL_STATION( 13,  0),
    JUMP_LABEL(0),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 21),
    CALL_STATION( 15,  0),
    JUMP_LABEL(0),
  LABEL(21), /* = 0x15 */
    CALL_STATION( 14,  0),
    JUMP_LABEL(0),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 22),
    COND(JUDGE_LE, 3, /* to label */ 23),
    COND(JUDGE_LE, 5, /* to label */ 24),
    JUMP_LABEL(0),
  LABEL(22), /* = 0x16 */
    CALL_STATION( 15,  0),
    JUMP_LABEL(0),
  LABEL(23), /* = 0x17 */
    CALL_STATION( 16,  0),
    JUMP_LABEL(0),
  LABEL(24), /* = 0x18 */
    CALL_STATION( 18,  0),
    JUMP_LABEL(0),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 25),
    JUMP_LABEL(0),
  LABEL(25), /* = 0x19 */
    JUMP_SCRIPT(EVENT_M01E06A_L003),
  LABEL(8), /* = 0x08 */
    CALL_STATION( 22,  0),
    JUMP_LABEL(0),
  LABEL(9), /* = 0x09 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 3, /* to label */ 26),
    COND(JUDGE_LE, 5, /* to label */ 27),
    COND(JUDGE_LE, 7, /* to label */ 28),
    COND(JUDGE_LE, 11, /* to label */ 29),
    JUMP_LABEL(30),
  LABEL(26), /* = 0x1a */
    CALL_STATION( 24,  0),
    JUMP_LABEL(0),
  LABEL(27), /* = 0x1b */
    CALL_STATION( 25,  0),
    JUMP_LABEL(0),
  LABEL(28), /* = 0x1c */
    CALL_STATION( 27,  0),
    JUMP_LABEL(0),
  LABEL(29), /* = 0x1d */
    CALL_STATION( 29,  0),
    JUMP_LABEL(0),
  LABEL(30), /* = 0x1e */
    CALL_STATION( 30,  0),
    JUMP_LABEL(0),
  LABEL(10), /* = 0x0a */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 31),
    COND(JUDGE_LE, 4, /* to label */ 32),
    JUMP_LABEL(33),
  LABEL(31), /* = 0x1f */
    CALL_STATION( 34,  0),
    JUMP_LABEL(0),
  LABEL(32), /* = 0x20 */
    CALL_STATION( 35,  0),
    JUMP_LABEL(0),
  LABEL(33), /* = 0x21 */
    CALL_STATION( 36,  0),
    JUMP_LABEL(0),
  LABEL(11), /* = 0x0b */
    CALL_STATION( 36,  0),
    JUMP_LABEL(0),
  LABEL(12), /* = 0x0c */
    CALL_STATION( 38,  0),
    JUMP_LABEL(0),
  LABEL(13), /* = 0x0d */
    CALL_STATION(  1,  0),
    JUMP_LABEL(0),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 34),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 35),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 36),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 36),
    JUMP_LABEL(34),
  LABEL(36), /* = 0x24 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(9, /* to label */ 37),
    COND_EQUAL(10, /* to label */ 37),
    COND_EQUAL(11, /* to label */ 37),
    COND_EQUAL(15, /* to label */ 37),
    COND_EQUAL(16, /* to label */ 37),
    COND_EQUAL(17, /* to label */ 37),
    COND_EQUAL(2, /* to label */ 38),
    COND_EQUAL(3, /* to label */ 38),
    COND_EQUAL(4, /* to label */ 39),
    COND_EQUAL(6, /* to label */ 40),
    JUMP_LABEL(37),
  LABEL(34), /* = 0x22 */
    SELECT_LIVES(0, 7),
    JUMP_LABEL(41),
  LABEL(35), /* = 0x23 */
    SELECT_LIVES(0, 8),
    JUMP_LABEL(41),
  LABEL(37), /* = 0x25 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(41),
  LABEL(38), /* = 0x26 */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(41),
  LABEL(39), /* = 0x27 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(41),
  LABEL(40), /* = 0x28 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(41),
  LABEL(41), /* = 0x29 */
    BGM_SWITCH(7),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs1_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs1_g0_s0_station_sref_script }; /* 0x8138db4 */

static const struct ScriptCommand s_gs1_g0_s0_evt0_sref_script[] = { /* 0x8138dc0 */
    DEBUGINFO_O(339),
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 9, 5, /* to label */ 0),
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 1),
    JUMPIF_EQUAL(WARP_LOCK, 3, /* to label */ 2),
    JUMPIF_EQUAL(WARP_LOCK, 4, /* to label */ 3),
    JUMP_LABEL(1),
    CALL_SCRIPT(EVENT_DIVIDE_WARP_LOCK_FUNC),
    RET,
  LABEL(1), /* = 0x01 */
    { 0x01, 0x00, -0x0001,  0x00000009,  0x00000000, NULL },
    HALT,
  LABEL(2), /* = 0x02 */
    EXECUTE_STATION(-1, 7, 1),
    HALT,
  LABEL(3), /* = 0x03 */
    EXECUTE_STATION(-1, 8, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, 19, 0),
    HALT,
};

static const struct ScriptRef s_gs1_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs1_g0_s0_evt0_sref_script }; /* 0x8138f00 */


static const struct ScriptCommand s_gs1_g0_s0_evt1_sref_script[] = { /* 0x8138f0c */
    DEBUGINFO_O(365),
    { 0x01, 0x00, -0x0001,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs1_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs1_g0_s0_evt1_sref_script }; /* 0x8138f3c */

static const struct ScriptCommand s_gs1_g0_s0_evt2_sref_script[] = { /* 0x8138f48 */
    DEBUGINFO_O(373),
    { 0x01, 0x00, -0x0001,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs1_g0_s0_evt2_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs1_g0_s0_evt2_sref_script }; /* 0x8138f78 */

static const struct ScriptCommand s_gs1_g0_s0_evt3_sref_script[] = { /* 0x8138f84 */
    DEBUGINFO_O(381),
    { 0x01, 0x00, -0x0001,  0x00000006,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs1_g0_s0_evt3_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs1_g0_s0_evt3_sref_script }; /* 0x8138fb4 */

static const struct ScriptCommand s_gs1_g0_s0_obj0_dlg2[] = { /* 0x8138fc0 */
    DEBUGINFO_O(389),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_INSTANT(_("{CENTER_ALIGN}Welcome!\n{CENTER_ALIGN}The fun and bustling Pokémon Square!")),
    MSG_INSTANT(_("Whiscash Pond ↑\n                 Pelipper Post Office →")),
    TEXTBOX_CLEAR,
    ALERT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s0_obj1_dlg2[] = { /* 0x81390c0 */
    DEBUGINFO_O(401),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_INSTANT(_("{CENTER_ALIGN}↑\n{CENTER_ALIGN}Whiscash Pond")),
    TEXTBOX_CLEAR,
    ALERT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s0_obj2_dlg2[] = { /* 0x8139158 */
    DEBUGINFO_O(412),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_INSTANT(_("\n{CENTER_ALIGN}Pelipper Post Office →")),
    TEXTBOX_CLEAR,
    ALERT_CUE(2),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s1_lives0_dlg0[] = { /* 0x81391f4 */
    DEBUGINFO_O(423),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s1_lives1_dlg0[] = { /* 0x8139234 */
    DEBUGINFO_O(430),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s2_lives0_dlg0[] = { /* 0x8139274 */
    DEBUGINFO_O(437),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s2_lives1_dlg0[] = { /* 0x81392b4 */
    DEBUGINFO_O(444),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s3_lives0_dlg0[] = { /* 0x81392f4 */
    DEBUGINFO_O(451),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s3_lives1_dlg0[] = { /* 0x8139334 */
    DEBUGINFO_O(458),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s4_lives0_dlg0[] = { /* 0x8139374 */
    DEBUGINFO_O(465),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s4_lives1_dlg0[] = { /* 0x81393b4 */
    DEBUGINFO_O(472),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s7_lives0_dlg0[] = { /* 0x81393f4 */
    DEBUGINFO_O(479),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s7_lives1_dlg0[] = { /* 0x8139434 */
    DEBUGINFO_O(486),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s8_lives0_dlg0[] = { /* 0x8139474 */
    DEBUGINFO_O(493),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g0_s8_lives1_dlg0[] = { /* 0x81394a4 */
    DEBUGINFO_O(499),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g1_s0_station_sref_script[] = { /* 0x81394d4 */
    DEBUGINFO_O(505),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g1_s0_station_sref_script }; /* 0x8139514 */

static const struct ScriptCommand s_gs1_g1_s0_lives0_dlg2[] = { /* 0x8139520 */
    DEBUGINFO_O(514),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives1_dlg2[] = { /* 0x8139580 */
    DEBUGINFO_O(523),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives2_dlg2[] = { /* 0x81395e0 */
    DEBUGINFO_O(532),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives3_dlg2[] = { /* 0x8139640 */
    DEBUGINFO_O(541),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives4_dlg2[] = { /* 0x81396a0 */
    DEBUGINFO_O(550),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives5_dlg2[] = { /* 0x8139700 */
    DEBUGINFO_O(559),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives6_dlg2[] = { /* 0x8139760 */
    DEBUGINFO_O(568),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" What's your rescue rank?\nHow high'd you get it?")),
    MSG_NPC(1, _(" We're still Normal Rank.{WAIT_PRESS}\nWe're trying, but...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives7_dlg2[] = { /* 0x8139840 */
    DEBUGINFO_O(578),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" It sounds like the natural\ndisasters were interfering with our ability\nto evolve.")),
    MSG_NPC(1, _(" I think the timing's right.{WAIT_PRESS}\nI should think about evolving...")),
    MSG_NPC(1, _(" But when I evolve...{WAIT_PRESS}\nI become a {COLOR CYAN_M}Ludicolo{RESET}...")),
    MSG_NPC(1, _(" You know? \n{COLOR CYAN_M}Ludicolo{RESET} is a carefree Pokémon.")),
    MSG_NPC(1, _(" I don't know about having\nmy personality become carefree...{WAIT_PRESS}\nWhat do you think? Huh?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives8_dlg2[] = { /* 0x8139a3c */
    DEBUGINFO_O(591),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000050,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I've given up on trying to\nturn back into {POKEMON_2}.")),
    MSG_NPC(1, _(" From now on, I'm living as\n{POKEMON_1}.\nPleased to meet you.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives9_dlg2[] = { /* 0x8139b2c */
    DEBUGINFO_O(602),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Our team got the Gold Rank,\nbut...")),
    MSG_NPC(1, _(" I think the rescue ranks go\nhigher than that.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives10_dlg2[] = { /* 0x8139bf4 */
    DEBUGINFO_O(612),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I wonder what's higher than\nthe Gold Rank?{WAIT_PRESS}\nI can't imagine it.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives11_dlg2[] = { /* 0x8139c9c */
    DEBUGINFO_O(621),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" For many years, countless\nPokémon have served on rescue teams.")),
    MSG_NPC(1, _(" Many have engraved\ntheir names in glory.")),
    MSG_NPC(1, _(" But if anyone asks\nabout the greatest of them all...{WAIT_PRESS}\nThere is but one hero.")),
    MSG_NPC(1, _(" It's Lucario...{WAIT_PRESS}\nwhose exploits as a rescue leader are the\nstuff of legend.")),
    MSG_NPC(1, _(" I aspire to become like\nLucario.")),
    MSG_NPC(1, _(" To become even closer to\nLucario's greatness...\nThat is my goal and my dream.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives12_dlg2[] = { /* 0x8139ef4 */
    DEBUGINFO_O(637),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" KEEP UP YOUR RESCUE\nWORK! BZBZBZZZ!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g1_s0_lives13_dlg2[] = { /* 0x8139f7c */
    DEBUGINFO_O(646),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" YOUR TEAM HAS MY\nSUPPORT! BZBZBZZT!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g2_s0_station_sref_script[] = { /* 0x813a004 */
    DEBUGINFO_O(655),
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 19, -1, /* to label */ 6),
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(4, /* to label */ 2),
    JUMPIF_SCENE_EQ(SCENARIO_SUB4, 38, 1, /* to label */ 3),
  LABEL(2), /* = 0x02 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB4, 43, 0, /* to label */ 4),
    JUMPIF_SCENE_EQ(SCENARIO_SUB4, 43, 1, /* to label */ 4),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 3, /* to label */ 5),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 4, /* to label */ 5),
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 2, /* to label */ 6),
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, -1, /* to label */ 6),
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 4, /* to label */ 7),
    JUMPIF_SUM(JUDGE_LT, EVENT_S07E01, 11, /* to label */ 7),
  LABEL(6), /* = 0x06 */
    CLEAR_ARRAY(EVENT_LOCAL),
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 32, 2, /* to label */ 9),
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    SELECT_ENTITIES(39, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(10),
  LABEL(10), /* = 0x0a */
    CJUMP_SCENARIO_0(SCENARIO_SUB2),
    COND(JUDGE_EQ, 33, /* to label */ 12),
    COND(JUDGE_EQ, 34, /* to label */ 13),
    JUMP_LABEL(14),
  LABEL(12), /* = 0x0c */
    JUMPIF_SCENE_EQ(SCENARIO_SUB2, 33, 2, /* to label */ 15),
    JUMP_LABEL(14),
  LABEL(15), /* = 0x0f */
    SELECT_ENTITIES(40, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(14),
  LABEL(13), /* = 0x0d */
    JUMPIF_SCENE_EQ(SCENARIO_SUB2, 34, 1, /* to label */ 16),
    JUMP_LABEL(14),
  LABEL(16), /* = 0x10 */
    SELECT_ENTITIES(41, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(14),
  LABEL(14), /* = 0x0e */
    JUMPIF_SCENE_LT(SCENARIO_SUB4, 38, 2, /* to label */ 19),
    JUMPIF_SCENE_LT(SCENARIO_SUB4, 43, 0, /* to label */ 20),
    JUMP_LABEL(19),
  LABEL(3), /* = 0x03 */
    SELECT_ENTITIES(42, 0),
    RET_DIRECT,
  LABEL(20), /* = 0x14 */
    SELECT_ENTITIES(44, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(19),
  LABEL(4), /* = 0x04 */
    SELECT_ENTITIES(45, 0),
    RET_DIRECT,
  LABEL(19), /* = 0x13 */
    JUMP_LABEL(22),
  LABEL(7), /* = 0x07 */
    SELECT_ENTITIES(50, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(6),
  LABEL(22), /* = 0x16 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 55, 2, /* to label */ 24),
    JUMP_LABEL(25),
  LABEL(5), /* = 0x05 */
    SELECT_ENTITIES(51, 0),
    RET_DIRECT,
  LABEL(24), /* = 0x18 */
    SELECT_ENTITIES(52, 0),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    JUMP_LABEL(25),
  LABEL(25), /* = 0x19 */
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 19, -1, /* to label */ 26),
    JUMPIF(JUDGE_NE, EVENT_LOCAL, 0, /* to label */ 26),
    { 0x3b, 0x33,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 27),
    WAIT(0),
    JUMP_LABEL(26),
  LABEL(28), /* = 0x1c */
    SELECT_ENTITIES(3, 0),
    JUMP_LABEL(26),
  LABEL(27), /* = 0x1b */
    CJUMP_RANDOM(2),
    COND_EQUAL(0, /* to label */ 29),
    COND_EQUAL(1, /* to label */ 30),
  LABEL(29), /* = 0x1d */
    SELECT_ENTITIES(4, 0),
    JUMP_LABEL(26),
  LABEL(30), /* = 0x1e */
    SELECT_ENTITIES(5, 0),
    JUMP_LABEL(26),
  LABEL(26), /* = 0x1a */
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g2_s0_station_sref_script }; /* 0x813a604 */








static const struct ScriptCommand s_gs1_g3_s0_lives0_dlg2[] = { /* 0x813a610 */
    DEBUGINFO_O(763),
    SELECT_ANIMATION(2),
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _(" Activate the subevent \"Munchlax\"?")),
    CHOICE(/* label */  1, _("Activate Type 1")),
    CHOICE(/* label */  2, _("Activate Type 2")),
    CHOICE(/* label */  3, _("*Cancel")),
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    CANCEL_ENTITIES(3, 0),
    SELECT_ENTITIES(4, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    TEXTBOX_CLEAR,
    CANCEL_ENTITIES(3, 0),
    SELECT_ENTITIES(5, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g4_s0_lives0_dlg1[] = { /* 0x813a7a0 */
    DEBUGINFO_O(787),
    SELECT_ANIMATION(1),
    WALK_GRID(256, 0),
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x11,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 1),
    { 0x3b, 0x15,  0x0000,  0x00000020,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 2),
  LABEL(1), /* = 0x01 */
    WALK_RELATIVE(128, -1, 0),
    CJUMP_DIR_TO_LINK(1),
    COND_EQUAL(6, /* to label */ 0),
    WALK_GRID(128, 2),
    END_DELETE,
  LABEL(2), /* = 0x02 */
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s0_lives0_dlg2[] = { /* 0x813a8b0 */
    DEBUGINFO_O(807),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" ....................................")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g4_s1_station_sref_script[] = { /* 0x813a938 */
    DEBUGINFO_O(816),
    { 0xb2, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 3),
    SELECT_ENTITIES(1, 0),
    RET,
};

static const struct ScriptRef s_gs1_g4_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g4_s1_station_sref_script }; /* 0x813a9a8 */

static const struct ScriptCommand s_gs1_g4_s1_lives0_dlg0[] = { /* 0x813a9b4 */
    DEBUGINFO_O(828),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    AWAIT_CUE(5),
    FANFARE_PLAY2(515),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Grrruummmmmbbbbblle...!") },
    WAIT(60),
    TEXTBOX_CLEAR,
    WAIT(1),
    FANFARE_PLAY2(465),
    SELECT_ENTITIES(-1, 2),
    ALERT_CUE(6),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(2, _(" ....................................\n................................................\n................................................")),
    MSG_NPC(2, _(" ...Belly...rumbling...{WAIT_PRESS}\nHungry...")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs1_g4_s1_lives1_dlg0[] = { /* 0x813ac3c */
    DEBUGINFO_O(859),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g4_s1_lives2_dlg0[] = { /* 0x813acdc */
    DEBUGINFO_O(872),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x3c,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives0_dlg0[] = { /* 0x813ad6c */
    DEBUGINFO_O(884),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives1_dlg0[] = { /* 0x813adcc */
    DEBUGINFO_O(893),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives2_dlg0[] = { /* 0x813ae2c */
    DEBUGINFO_O(902),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives3_dlg0[] = { /* 0x813ae8c */
    DEBUGINFO_O(911),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives4_dlg0[] = { /* 0x813aeec */
    DEBUGINFO_O(920),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives5_dlg0[] = { /* 0x813af4c */
    DEBUGINFO_O(929),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives6_dlg0[] = { /* 0x813afac */
    DEBUGINFO_O(938),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives7_dlg0[] = { /* 0x813b00c */
    DEBUGINFO_O(947),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives8_dlg0[] = { /* 0x813b06c */
    DEBUGINFO_O(956),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s2_lives9_dlg0[] = { /* 0x813b0cc */
    DEBUGINFO_O(965),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s3_lives0_dlg0[] = { /* 0x813b12c */
    DEBUGINFO_O(974),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    RET,
};

static const struct ScriptCommand s_gs1_g4_s3_lives0_dlg1[] = { /* 0x813b16c */
    DEBUGINFO_O(981),
    SELECT_ANIMATION(1),
    WALK_GRID(128, 2),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g4_s3_lives0_dlg2[] = { /* 0x813b1ac */
    DEBUGINFO_O(988),
    CLEAR_ARRAY(EVENT_LOCAL),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" Munchlax hungry...{WAIT_PRESS}\nYou have food?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("No.")),
  LABEL(1), /* = 0x01 */
    PORTRAIT_REP(0x0001, 0x00000042),
    MSG_NPC(1, _(" R-really?!")),
    PORTRAIT_REP(0x0001, 0x00000041),
    MSG_NPC(1, _(" What kind food?!\nShow Munchlax! Show, show!")),
    SPECIAL_TEXT(SPECIAL_TEXT_TOOL_BOX, 0, 0),
    COND_EQUAL(-1, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    ALERT_CUE(6),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000045),
    MSG_NPC(1, _(" ...Nnnnn?{WAIT_PRESS}\nOh... Don't have food...")),
    MSG_NPC(1, _(" Munchlax feel sad...{WAIT_PRESS}\nMunchlax go now.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(6),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} gave Munchlax\n{CENTER_ALIGN}one {COLOR GREEN_I}{MOVE_ITEM_0}{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000041),
    MSG_NPC(1, _(" Th-this {COLOR GREEN_I}{MOVE_ITEM_0}{RESET}!{WAIT_PRESS}\nM-Munchlax big favorite!")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    FANFARE_PLAY2(516),
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("Munch, munch, munch, munch, munch,\nmunch, munch, munch, munch, munch,\nmunch, munch, munch, munch, munch...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("Munch, munch, munch, munch, munch,\nmunch, munch, munch, munch, munch,\nmunch, munch, munch, munch, munch...") },
    FANFARE_STOP2(516),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000044),
    MSG_NPC(1, _(" Nnnnnnnnn!{WAIT_PRESS}\nDeeeeelicious!")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000043),
    MSG_NPC(1, _(" Munchlax satisfied!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" ............{WAIT_PRESS}\nYou, good to Munchlax.")),
    MSG_NPC(1, _(" Munchlax say thank you\nwith this.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_2C, 43, 0),
    WAIT(30),
    MSG_NPC(1, _(" Munchlax go now.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 4),
    RET,
};





static const struct ScriptCommand s_gs1_g4_s3_lives0_dlg3[] = { /* 0x813b7d8 */
    DEBUGINFO_O(1058),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 0),
    AWAIT_CUE(2),
    WAIT(12),
    RET,
  LABEL(0), /* = 0x00 */
    AWAIT_CUE(6),
    { 0x8b, 0x0a,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    WAIT(10),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs1_g4_s4_lives0_dlg1[] = { /* 0x813b948 */
    DEBUGINFO_O(1084),
    SELECT_ANIMATION(1),
    WALK_GRID(256, 2),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g4_s4_lives0_dlg2[] = { /* 0x813b988 */
    DEBUGINFO_O(1091),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000044),
    MSG_NPC(1, _(" ............{WAIT_PRESS}\nYou, good to Munchlax.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g5_s0_lives0_dlg1[] = { /* 0x813b9e8 */
    DEBUGINFO_O(1100),
    SELECT_ANIMATION(1),
    WALK_GRID(256, 4),
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x11,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 1),
    { 0x3b, 0x15,  0x0000,  0x00000040,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 2),
  LABEL(1), /* = 0x01 */
    WALK_RELATIVE(256, -1, 0),
    CJUMP_DIR_TO_LINK(5),
    COND_EQUAL(6, /* to label */ 0),
    WALK_GRID(256, 6),
    END_DELETE,
  LABEL(2), /* = 0x02 */
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s0_lives0_dlg2[] = { /* 0x813baf8 */
    DEBUGINFO_O(1120),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" ........................")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g5_s1_station_sref_script[] = { /* 0x813bb74 */
    DEBUGINFO_O(1129),
    { 0xb2, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    SELECT_LIVES(-1, 1),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 3),
    SELECT_ENTITIES(1, 0),
    RET,
};

static const struct ScriptRef s_gs1_g5_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g5_s1_station_sref_script }; /* 0x813bbe4 */

static const struct ScriptCommand s_gs1_g5_s1_lives0_dlg0[] = { /* 0x813bbf0 */
    DEBUGINFO_O(1141),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    AWAIT_CUE(5),
    FANFARE_PLAY2(400),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Flump!") },
    AWAIT_CUE(5),
    FANFARE_PLAY2(900),
    SELECT_OBJECTS(-1, 1),
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    WAIT(1),
    FANFARE_PLAY2(465),
    SELECT_ENTITIES(-1, 2),
    ALERT_CUE(6),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000045),
    MSG_NPC(2, _(" ....................................")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs1_g5_s1_lives1_dlg0[] = { /* 0x813be18 */
    DEBUGINFO_O(1178),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g5_s1_lives2_dlg0[] = { /* 0x813beb8 */
    DEBUGINFO_O(1191),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(19),
    WAIT(4),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(8),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    WAIT(10),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj0_dlg0[] = { /* 0x813bfc8 */
    DEBUGINFO_O(1211),
    SELECT_ANIMATION(8),
    { 0x5d, 0x00,  0x0000,  0x0000007f,  0x00000000, NULL },
    WALK_RELATIVE(512, -32, 0),
    WALK_RELATIVE(256, -8, 0),
    WALK_RELATIVE(128, -2, 0),
    { 0x52, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000040,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g5_s1_obj0_dlg1[] = { /* 0x813c058 */
    DEBUGINFO_O(1223),
    SELECT_ANIMATION(8),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj0_dlg2[] = { /* 0x813c088 */
    DEBUGINFO_O(1229),
    FANFARE_PLAY2(330),
    CANCEL_OBJECTS(-1, 1),
    EXECUTE_STATION(-1, -1, 4),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj1_dlg0[] = { /* 0x813c0d8 */
    DEBUGINFO_O(1237),
    SELECT_ANIMATION(8),
    { 0x5d, 0x00,  0x0000,  0x0000007f,  0x00000000, NULL },
    { 0x84, 0x00,  0x0200, -0x00000018, -0x00000004, NULL },
    { 0x84, 0x00,  0x0100, -0x00000008, -0x00000002, NULL },
    { 0x84, 0x00,  0x0080, -0x00000002, -0x00000001, NULL },
    { 0x52, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000040,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g5_s1_obj1_dlg1[] = { /* 0x813c168 */
    DEBUGINFO_O(1249),
    SELECT_ANIMATION(8),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj1_dlg2[] = { /* 0x813c198 */
    DEBUGINFO_O(1255),
    FANFARE_PLAY2(330),
    CANCEL_OBJECTS(-1, 1),
    EXECUTE_STATION(-1, -1, 4),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj2_dlg0[] = { /* 0x813c1e8 */
    DEBUGINFO_O(1263),
    SELECT_ANIMATION(8),
    { 0x5d, 0x00,  0x0000,  0x0000007f,  0x00000000, NULL },
    { 0x84, 0x00,  0x0200, -0x00000018,  0x00000004, NULL },
    { 0x84, 0x00,  0x0100, -0x00000008,  0x00000002, NULL },
    { 0x84, 0x00,  0x0080, -0x00000002,  0x00000001, NULL },
    { 0x52, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000040,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g5_s1_obj2_dlg1[] = { /* 0x813c278 */
    DEBUGINFO_O(1275),
    SELECT_ANIMATION(8),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s1_obj2_dlg2[] = { /* 0x813c2a8 */
    DEBUGINFO_O(1281),
    FANFARE_PLAY2(330),
    CANCEL_OBJECTS(-1, 1),
    EXECUTE_STATION(-1, -1, 4),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives0_dlg0[] = { /* 0x813c2f8 */
    DEBUGINFO_O(1289),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives1_dlg0[] = { /* 0x813c358 */
    DEBUGINFO_O(1298),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives2_dlg0[] = { /* 0x813c3b8 */
    DEBUGINFO_O(1307),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives3_dlg0[] = { /* 0x813c418 */
    DEBUGINFO_O(1316),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives4_dlg0[] = { /* 0x813c478 */
    DEBUGINFO_O(1325),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives5_dlg0[] = { /* 0x813c4d8 */
    DEBUGINFO_O(1334),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives6_dlg0[] = { /* 0x813c538 */
    DEBUGINFO_O(1343),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives7_dlg0[] = { /* 0x813c598 */
    DEBUGINFO_O(1352),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives8_dlg0[] = { /* 0x813c5f8 */
    DEBUGINFO_O(1361),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s2_lives9_dlg0[] = { /* 0x813c658 */
    DEBUGINFO_O(1370),
    SELECT_ANIMATION(2),
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s3_lives0_dlg1[] = { /* 0x813c6b8 */
    DEBUGINFO_O(1379),
    { 0x53, 0x00,  0x0000,  0x00000008,  0x00000000, NULL },
    SELECT_ANIMATION(1),
    WALK_RELATIVE(64, -36, 0),
    CANCEL_OBJECTS(-1, 1),
    WAIT(30),
    WALK_GRID(128, 6),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g5_s3_lives0_dlg2[] = { /* 0x813c738 */
    DEBUGINFO_O(1390),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" ........................")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g5_s4_station_sref_script[] = { /* 0x813c798 */
    DEBUGINFO_O(1399),
    SELECT_ENTITIES(-1, -1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g5_s4_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g5_s4_station_sref_script }; /* 0x813c7d8 */

static const struct ScriptCommand s_gs1_g5_s4_lives0_dlg0[] = { /* 0x813c7e4 */
    DEBUGINFO_O(1408),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    { 0x93, 0x08,  0x000a,  0x0000007f,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000000),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" ............{WAIT_PRESS}Hey.{WAIT_PRESS}\nThat belong to Munchlax.{WAIT_PRESS}\nMunchlax want back.")),
    CHOICE(/* label */  1, _("Return it.")),
    CHOICE(/* label */  2, _("Keep it.")),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    WAIT(20),
    FANFARE_PLAY2(333),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} returned\n{CENTER_ALIGN}the {COLOR GREEN_I}Apple{RESET} to Munchlax.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000044),
    MSG_NPC(2, _(" R-really?!")),
    MSG_NPC(2, _(" Really, you give food back\nto Munchlax?")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0002, 0x00000042),
    MSG_NPC(2, _(" Snivel...\nMunchlax feel all squishy inside...")),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" ............{WAIT_PRESS}\nYou honest and nice.\nMunchlax like.")),
    MSG_NPC(2, _(" Munchlax say thank you\nwith this.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_2C, 43, 0),
    WAIT(30),
    MSG_NPC(2, _(" Munchlax go now.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
  LABEL(2), /* = 0x02 */
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    WAIT(30),
    PORTRAIT_REP(0x0002, 0x00000045),
    MSG_NPC(2, _(" Nnnnnnnnnnnn!{WAIT_PRESS}\nNnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nMunchlax sad...")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(20),
    MSG_NPC(2, _(" ..................{WAIT_PRESS}\nMeanie...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    SELECT_ENTITIES(-1, 6),
    { 0x3b, 0x34,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};





static const struct ScriptCommand s_gs1_g5_s4_lives1_dlg0[] = { /* 0x813cd90 */
    DEBUGINFO_O(1480),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g5_s4_lives2_dlg0[] = { /* 0x813cdf0 */
    DEBUGINFO_O(1489),
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00, -0x0001,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    { 0xda, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
  LABEL(0), /* = 0x00 */
    HALT,
  LABEL(1), /* = 0x01 */
    AWAIT_CUE(7),
    { 0x8b, 0x0a,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(32),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(24),
    WAIT(30),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    WAIT(30),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x95, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    SELECT_ANIMATION(33),
    { 0x53, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    WALK_RELATIVE(128, 32, 0),
  LABEL(2), /* = 0x02 */
    { 0x3b, 0x15,  0x0000,  0x00000040,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 3),
    WALK_RELATIVE(128, 4, 0),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    { 0x54, 0x00,  0x0800,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    WAIT(10),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x95, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(10),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g5_s5_lives0_dlg1[] = { /* 0x813d100 */
    DEBUGINFO_O(1541),
    SELECT_ANIMATION(1),
    WALK_GRID(256, 6),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g5_s5_lives0_dlg2[] = { /* 0x813d140 */
    DEBUGINFO_O(1548),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" ............{WAIT_PRESS}\nYou, good to Munchlax.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g5_s6_lives0_dlg1[] = { /* 0x813d190 */
    DEBUGINFO_O(1556),
    SELECT_ANIMATION(33),
    WALK_GRID(256, 3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g5_s6_lives0_dlg2[] = { /* 0x813d1d0 */
    DEBUGINFO_O(1563),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT_REP(0x0001, 0x00000045),
    MSG_NPC(1, _(" ..................{WAIT_PRESS}\nMeanie...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g6_s0_station_sref_script[] = { /* 0x813d240 */
    DEBUGINFO_O(1573),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_TEAM_BASE),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(7, 0),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs1_g6_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs1_g6_s0_station_sref_script }; /* 0x813d310 */

static const struct ScriptCommand s_gs1_g6_s0_eff0_script[] = { /* 0x813d31c */
    DEBUGINFO_O(1591),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    CAMERA_PAN(512, 9),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(512, 10),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(512, 11),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(512, 12),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(512, 13),
    CAMERA_END_PAN,
    WAIT(1),
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g6_s0_lives0_dlg0[] = { /* 0x813d45c */
    DEBUGINFO_O(1614),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WALK_GRID(128, 7),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" This is Pokémon Square.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's the {COLOR CYAN}Kecleon Shop{RESET}.{WAIT_PRESS}\nYou can buy and sell items there.")),
    VARIANT_DEFAULT(_(" That's the {COLOR CYAN}Kecleon Shop{RESET}.{WAIT_PRESS}\nYou can buy and sell items there.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's {COLOR CYAN}Felicity Bank{RESET}.")),
    VARIANT(/* == */  1, _(" You can save your money\nthere.")),
    VARIANT_DEFAULT(_(" That's {COLOR CYAN}Felicity Bank{RESET}.")),
    VARIANT_DEFAULT(_(" You can save your money\nthere.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is the\n{COLOR CYAN}Gulpin Link Shop{RESET}.{WAIT_PRESS}\nGulpin will link moves for you.")),
    VARIANT(/* == */  1, _(" Hah?{WAIT_PRESS} What's linking?{WAIT_PRESS}\nWell, if you link moves...{WAIT_PRESS}\nYou can use them at the same time.")),
    VARIANT(/* == */  1, _(" If you need details, you'd\nbe better off asking Gulpin.")),
    VARIANT(/* == */  3, _(" This is the\n{COLOR CYAN}Gulpin Link Shop{RESET}.{WAIT_PRESS}\nGulpin can link moves for you.")),
    VARIANT(/* == */  3, _(" Huh?{WAIT_PRESS} What's linking?{WAIT_PRESS}\nWell, if you link moves...{WAIT_PRESS}\nYou can use them at the same time.")),
    VARIANT(/* == */  3, _(" You should just ask Gulpin\nfor details.")),
    VARIANT_DEFAULT(_(" This is the\n{COLOR CYAN}Gulpin Link Shop{RESET}.{WAIT_PRESS}\nGulpin can link moves for you.")),
    VARIANT_DEFAULT(_(" Huh?{WAIT_PRESS} What's linking?{WAIT_PRESS}\nWell, if you link moves...{WAIT_PRESS}\nYou can use them at the same time.")),
    VARIANT_DEFAULT(_(" I think you should ask Gulpin\nif you want to know more.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is {COLOR CYAN}Kangaskhan Storage{RESET}.\nStore items here so they'll never be\nlost.")),
    VARIANT(/* == */  1, _(" If you have important\nitems, you should store them before you\nhead out to a dungeon.")),
    VARIANT_DEFAULT(_(" This is {COLOR CYAN}Kangaskhan Storage{RESET}.\nIf you store items here, they'll never go\nmissing.")),
    VARIANT_DEFAULT(_(" You should store important\nitems here before you go out on any\ndungeon adventure.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" How do you like it?\nThe shops are useful, huh?")),
    VARIANT_DEFAULT(_(" What do you think?\nThe businesses here help us.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, yeah, there's also the\n{COLOR CYAN}Pelipper Post Office{RESET}.\nIt's straight ahead past here.")),
    VARIANT_DEFAULT(_(" Oh, and there's also the\n{COLOR CYAN}Pelipper Post Office{RESET}.\nThat's up past here.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'm sure you can get\ninformation on rescue jobs there.")),
    VARIANT(/* == */  1, _(" So, let's start with a visit\nto the {COLOR CYAN}Pelipper Post Office{RESET}.")),
    VARIANT(/* == */  3, _(" I think we can get rescue-\njob information there.")),
    VARIANT(/* == */  3, _(" So, how about we go to\nthe {COLOR CYAN}Pelipper Post Office{RESET} first?")),
    VARIANT_DEFAULT(_(" I think we can get some\ninformation on rescue jobs.")),
    VARIANT_DEFAULT(_(" Let's first go to the\n{COLOR CYAN}Pelipper Post Office{RESET}.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};


static const struct ScriptCommand s_gs1_g6_s0_lives1_dlg0[] = { /* 0x813df88 */
    DEBUGINFO_O(1694),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    WALK_GRID(128, 8),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x8e, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    { 0x8e, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs1_g7_s0_station_sref_script[] = { /* 0x813e0f8 */
    DEBUGINFO_O(1720),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g7_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g7_s0_station_sref_script }; /* 0x813e128 */

static const struct ScriptCommand s_gs1_g7_s0_lives0_dlg2[] = { /* 0x813e134 */
    DEBUGINFO_O(1728),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives1_dlg2[] = { /* 0x813e194 */
    DEBUGINFO_O(1737),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives2_dlg2[] = { /* 0x813e1f4 */
    DEBUGINFO_O(1746),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives3_dlg2[] = { /* 0x813e254 */
    DEBUGINFO_O(1755),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives4_dlg2[] = { /* 0x813e2b4 */
    DEBUGINFO_O(1764),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives5_dlg1[] = { /* 0x813e314 */
    DEBUGINFO_O(1773),
    { 0x51, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g7_s0_lives5_dlg2[] = { /* 0x813e354 */
    DEBUGINFO_O(1780),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I don't know why, but\nthere've been many natural disasters\nlately.")),
    MSG_NPC(1, _(" A lot of Pokémon have gone\nwild and violent because the disasters\nscared them...")),
    MSG_NPC(1, _(" It's a mean world out there.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives6_dlg1[] = { /* 0x813e494 */
    DEBUGINFO_O(1791),
    { 0x51, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g7_s0_lives6_dlg2[] = { /* 0x813e4d4 */
    DEBUGINFO_O(1798),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" There was a forest fire not\nlong ago.\nIt was terrible.")),
    MSG_NPC(1, _(" Luckily, Blastoise and\nFeraligatr were able to douse it quickly...")),
    MSG_NPC(1, _(" But it could have been much\nworse if they were slower getting\nthere.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives7_dlg2[] = { /* 0x813e61c */
    DEBUGINFO_O(1809),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Pardon?\nOh, the {COLOR CYAN}Pelipper Post Office{RESET}?")),
    MSG_NPC(1, _(" The {COLOR CYAN}Pelipper Post Office{RESET}\nwould be...")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Straight down this path.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" It's out at the cape.\nYou can't miss it.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g7_s0_lives7_dlg3[] = { /* 0x813e794 */
    DEBUGINFO_O(1825),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 11, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    CALL_SCRIPT(WAIT_END_TALK_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g7_s1_station_sref_script[] = { /* 0x813e844 */
    DEBUGINFO_O(1839),
    SELECT_ENTITIES(-1, -1),
    RET,
};

static const struct ScriptRef s_gs1_g7_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g7_s1_station_sref_script }; /* 0x813e874 */

static const struct ScriptCommand s_gs1_g7_s1_lives0_dlg0[] = { /* 0x813e880 */
    DEBUGINFO_O(1847),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Huh?\nAre you going home already?")),
    TEXTBOX_CLEAR,
    { 0x93, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We haven't gone to the\n{COLOR CYAN}Pelipper Post Office{RESET} yet?")),
    VARIANT(/* == */  1, _(" You can go home after we\ngo to the {COLOR CYAN}Pelipper Post Office{RESET}.")),
    VARIANT_DEFAULT(_(" We haven't gone to the\n{COLOR CYAN}Pelipper Post Office{RESET} yet.")),
    VARIANT_DEFAULT(_(" Let's go to the {COLOR CYAN}Pelipper\nPost Office{RESET} at least.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};


static const struct ScriptCommand s_gs1_g7_s1_lives1_dlg0[] = { /* 0x813ead4 */
    DEBUGINFO_O(1871),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g8_s0_station_sref_script[] = { /* 0x813eb54 */
    DEBUGINFO_O(1882),
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 5, 4, /* to label */ 0),
    CANCEL_LIVES(8, 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(-1, -1),
  LABEL(1), /* = 0x01 */
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g8_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g8_s0_station_sref_script }; /* 0x813ebd4 */

static const struct ScriptCommand s_gs1_g8_s0_lives0_dlg2[] = { /* 0x813ebe0 */
    DEBUGINFO_O(1895),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives1_dlg2[] = { /* 0x813ec40 */
    DEBUGINFO_O(1904),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives2_dlg2[] = { /* 0x813eca0 */
    DEBUGINFO_O(1913),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives3_dlg2[] = { /* 0x813ed00 */
    DEBUGINFO_O(1922),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives4_dlg2[] = { /* 0x813ed60 */
    DEBUGINFO_O(1931),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives5_dlg2[] = { /* 0x813edc0 */
    DEBUGINFO_O(1940),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 5, 4, /* to label */ 0),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, 9, 0),
    HALT,
};

static const struct ScriptCommand s_gs1_g8_s0_lives6_dlg1[] = { /* 0x813ee60 */
    DEBUGINFO_O(1953),
    { 0x51, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s0_lives6_dlg2[] = { /* 0x813eea0 */
    DEBUGINFO_O(1960),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" There've been so many\nnatural disasters lately...")),
    MSG_NPC(1, _(" More Pokémon are starting\ntheir own rescue teams.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s0_lives7_dlg1[] = { /* 0x813ef7c */
    DEBUGINFO_O(1970),
    { 0x51, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s0_lives7_dlg2[] = { /* 0x813efbc */
    DEBUGINFO_O(1977),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004f,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, my gosh, the forest fire\na while back was simply awful.")),
    MSG_NPC(1, _(" I hightailed it out of there!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s1_station_sref_script[] = { /* 0x813f0a0 */
    DEBUGINFO_O(1988),
    SELECT_ENTITIES(-1, -1),
    RET,
};

static const struct ScriptRef s_gs1_g8_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g8_s1_station_sref_script }; /* 0x813f0d0 */

static const struct ScriptCommand s_gs1_g8_s1_lives0_dlg0[] = { /* 0x813f0dc */
    DEBUGINFO_O(1996),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Huh?\nYou want to go home already?")),
    TEXTBOX_CLEAR,
    { 0x93, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    MSG_NPC(1, _(" We're already here.\nLet me show you around a bit more.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s1_lives1_dlg0[] = { /* 0x813f23c */
    DEBUGINFO_O(2015),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives0_dlg0[] = { /* 0x813f2bc */
    DEBUGINFO_O(2026),
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives1_dlg0[] = { /* 0x813f2ec */
    DEBUGINFO_O(2032),
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives2_dlg0[] = { /* 0x813f31c */
    DEBUGINFO_O(2038),
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives3_dlg0[] = { /* 0x813f34c */
    DEBUGINFO_O(2044),
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives4_dlg0[] = { /* 0x813f37c */
    DEBUGINFO_O(2050),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives5_dlg0[] = { /* 0x813f3bc */
    DEBUGINFO_O(2057),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives6_dlg0[] = { /* 0x813f3fc */
    DEBUGINFO_O(2064),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives7_dlg0[] = { /* 0x813f44c */
    DEBUGINFO_O(2072),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    RET,
};

static const struct ScriptCommand s_gs1_g8_s2_lives8_dlg2[] = { /* 0x813f49c */
    DEBUGINFO_O(2080),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s2_lives9_dlg2[] = { /* 0x813f4fc */
    DEBUGINFO_O(2089),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g8_s2_evt0_sref_script[] = { /* 0x813f55c */
    DEBUGINFO_O(2098),
    EXECUTE_STATION(-1, 10, 0),
    HALT,
};

static const struct ScriptRef s_gs1_g8_s2_evt0_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs1_g8_s2_evt0_sref_script }; /* 0x813f58c */

static const struct ScriptCommand s_gs1_g9_s0_station_sref_script[] = { /* 0x813f598 */
    DEBUGINFO_O(2106),
    SELECT_ENTITIES(-1, -1),
    AWAIT_CUE(3),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  4),
    CANCEL_LIVES(8, 0),
    SELECT_ENTITIES(8, 2),
    RET,
};

static const struct ScriptRef s_gs1_g9_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g9_s0_station_sref_script }; /* 0x813f608 */

static const struct ScriptCommand s_gs1_g9_s0_lives0_dlg0[] = { /* 0x813f614 */
    DEBUGINFO_O(2118),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(6),
    WALK_GRID(256, 18),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(2, _(" Friends are my treasures!\nWelcome to {NAME_2} Club--a circle\nof friends! ")),
    MSG_NPC(2, _(" ...Oh?{WAIT_PRESS}\nIs this your first visit here?")),
    MSG_NPC(2, _(" ...Oh, I get it!{WAIT_PRESS}\nYou started a rescue team too, didn't you?")),
    MSG_NPC(2, _(" You've come to the right\nplace!{WAIT_PRESS} I sell Friend Areas to add\nmembers to your rescue team.")),
    MSG_NPC(2, _(" Since you're here for the\nvery first time, I'll give you two Friend\nAreas for free!")),
    MSG_NPC(2, _(" Let's do it!{WAIT_PRESS}\nWigglytuff〜♪ Wigglytuff〜♪{WAIT_PRESS}\nLet's be friends... Taaaaaaah!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(603),
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0xe2, 0x00,  0x025b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(206),
    { 0x3b, 0x17,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Congratulations!{WAIT_PRESS}\nYou can go to the {COLOR GREEN_H}Wild Plains{RESET} now.")),
    MSG_NPC(2, _(" You can also go to the\n{COLOR GREEN_H}Mist-Rise Forest{RESET}.")),
    MSG_NPC(2, _(" Now you can recruit\nPokémon that live in these two Friend\nAreas.")),
    MSG_NPC(2, _(" How do you recruit new\nmembers?{WAIT_PRESS} Well, if you're fighting\nPokémon that live in a Friend Area...")),
    MSG_NPC(2, _(" Sometimes, they will come\nto admire you as a friend.")),
    MSG_NPC(2, _(" In that case, they may ask\nto join your team.{WAIT_PRESS}\nJust keep trying!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    SELECT_ENTITIES(-1, 1),
    WAIT(1),
    WAIT(15),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" BZBZBZZT!{WAIT_PRESS}\nIF YOU'RE GIVING FRIEND AREAS AWAY...")),
    MSG_NPC(3, _(" CAN YOU ALSO GIVE MY\nFRIENDS ACCESS TO THE {COLOR GREEN_H}POWER PLANT{RESET}\nFRIEND AREA?")),
    MSG_NPC(3, _(" I ALSO WANT TO JOIN\nTHEIR RESCUE TEAM.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" OK! Gotcha!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    MSG_NPC(2, _(" I'm giving it away today!{WAIT_PRESS}\nWigglytuff〜♪ Wigglytuff〜♪{WAIT_PRESS}\nLet's be friends... Taaaaaaah!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(603),
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x28, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0x27, 0x01,  0x0005,  0x00000002,  0x00808010, NULL },
    { 0xe2, 0x00,  0x025b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(206),
    MSG_NPC(2, _(" Congratulations!{WAIT_PRESS}\nYou can go to the {COLOR GREEN_H}Power Plant{RESET} now.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    ALERT_CUE(9),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000041),
    MSG_NPC(4, _(" YES!\nNOW I CAN JOIN THEIR TEAM!")),
    MSG_NPC(4, _(" YAY! BZBZBZZT!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(8),
    ALERT_CUE(9),
    WAIT(15),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ROTATE(4, 10, DIRECTION_WEST),
    PORTRAIT_REP(0x0003, 0x00000000),
    MSG_NPC(3, _(" SORRY.{WAIT_PRESS}\nI KNOW MY FRIEND TURNED DOWN YOUR\nOFFER TO JOIN YOUR TEAM YESTERDAY...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" BUT AFTER MULLING IT\nOVER ALL LAST NIGHT...")),
    MSG_NPC(3, _(" MY FRIEND DEVELOPED AN\nOVERWHELMING DESIRE TO BECOME YOUR\nTEAM MEMBER.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" I APOLOGIZE, BUT COULD\nYOU ALLOW MY FRIEND TO JOIN YOUR\nRESCUE TEAM?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Oh, wow!{WAIT_PRESS}\nDon't forget, we were the ones that asked\nyour friend to join us.")),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" So, yes, that'd be awesome!\nGlad to have your friend on board!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0003, 0x00000041),
    MSG_NPC(3, _(" ALL RIGHT!\nGOOD ON YOU! BZBZBZZ!")),
    MSG_NPC(3, _(" DO YOUR BEST, AND TRY\nNOT TO HINDER YOUR RESCUE\nTEAMMATES! BZBZBZZT!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    PORTRAIT_REP(0x0004, 0x00000041),
    MSG_NPC(4, _(" YEAH! I'LL DO MY BEST!")),
    MSG_NPC(4, _(" YAY, BZBZBZZ!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY(204),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_4} became a team member!")),
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0x3b, 0x18,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to {NAME_4}?")),
    CHOICE(/* label */  0, _("*Yes.")),
    CHOICE(/* label */  1, _("No.")),
  LABEL(0), /* = 0x00 */
    RENAME_ALLY(-1),
  LABEL(1), /* = 0x01 */
    { 0x3b, 0x19,  0x0004,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    WAIT(30),
    ALERT_CUE(8),
    ALERT_CUE(9),
    WAIT(10),
    PORTRAIT_REP(0x0004, 0x00000000),
    MSG_NPC(4, _(" I'LL BE RESTING UP IN THE\n{COLOR GREEN_H}POWER PLANT{RESET} FRIEND AREA.")),
    MSG_NPC(4, _(" IF YOU WANT ME ALONG\nFOR A RESCUE, COME GET ME AT THE\n{COLOR GREEN_H}POWER PLANT{RESET}.")),
    MSG_NPC(4, _(" OK! BZBZBZZ!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    MSG_NPC(2, _(" You can go to your Friend\nAreas by taking the left path from your\nrescue team base.")),
    MSG_NPC(2, _(" There's a sign on the path\nto the left of your rescue team base,\nso you shouldn't have any trouble.")),
    MSG_NPC(2, _(" That's all the giveaways\ntoday!{WAIT_PRESS} If you want more Friend Areas,\nyou'll have to buy them now.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs1_g9_s0_lives1_dlg0[] = { /* 0x81408d0 */
    DEBUGINFO_O(2273),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(256, 19),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    WAIT(7),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(6),
    WAIT(5),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g9_s0_lives2_dlg0[] = { /* 0x8140a10 */
    DEBUGINFO_O(2296),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs1_g9_s0_lives2_dlg2[] = { /* 0x8140ae0 */
    DEBUGINFO_O(2312),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 5, 4, /* to label */ 0),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_MAIN,  5,  4),
    CANCEL_LIVES(8, 0),
    SELECT_ENTITIES(8, 2),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g9_s1_lives0_dlg0[] = { /* 0x8140ba0 */
    DEBUGINFO_O(2327),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    WALK_GRID(384, 20),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_START_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(8),
    { 0x89, 0x10,  0x0080,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(SMILE_START_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(8),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x88,  0x0100,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g9_s1_lives1_dlg0[] = { /* 0x8140dc0 */
    DEBUGINFO_O(2364),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    WALK_GRID(384, 21),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(7),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    CALL_SCRIPT(SMILE_START_FUNC),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(9),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x88,  0x0100,  0x00000006,  0x00000000, NULL },
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s0_station_sref_script[] = { /* 0x8140f60 */
    DEBUGINFO_O(2393),
    SELECT_ENTITIES(-1, 0),
    CANCEL_ENTITIES(8, 0),
    BGM_SWITCH(7),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 1),
    ALERT_CUE(5),
    AWAIT_CUE(3),
    SELECT_ENTITIES(-1, 2),
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    EXECUTE_FUNCTION(EVENT_M01E03A_L003),
    RET,
};

static const struct ScriptRef s_gs1_g10_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g10_s0_station_sref_script }; /* 0x8141040 */

static const struct ScriptCommand s_gs1_g10_s0_eff0_script[] = { /* 0x814104c */
    DEBUGINFO_O(2412),
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_INIT_PAN,
    { 0x89, 0x28,  0x0200,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x89, 0x28,  0x0200,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x89, 0x28,  0x0200,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x89, 0x20,  0x0300,  0x00000006,  0x00000000, NULL },
    AWAIT_CUE(4),
    { 0x89, 0x30,  0x0200,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x88, 0x00,  0x0400,  0x00000059,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x88, 0x00,  0x0100,  0x0000005a,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x88, 0x00,  0x0100,  0x00000058,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WAIT(30),
    WALK_DIRECT(240, 27),
    AWAIT_CUE(4),
    { 0x89, 0x18,  0x0100,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x88, 0x00,  0x0180,  0x0000005b,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s0_lives2_dlg0[] = { /* 0x81412bc */
    DEBUGINFO_O(2454),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000004),
    MSG_NPC(1, _(" Huh? What's going on over\nthere?{WAIT_PRESS}\nThere seems to be a commotion.")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(120),
    ALERT_CUE(4),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 22),
    { 0x93, 0x04,  0x000b,  0x0000004e,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(30),
    AWAIT_CUE(5),
    WAIT(15),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000041),
    MSG_NPC(2, _(" Please help my friend!\nPlease, I need help!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Forget it.\nWe're not about to work for that.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" But my friend needs a gust\nof wind! Please!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, what's up?")),
    VARIANT_DEFAULT(_(" Hi, what's going on?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Huh? That scene there?")),
    MSG_NPC(4, _(" {NAME_2}'s begging for\na rescue mission, but not finding any luck.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" See that guy?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(4),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x2e, 0x00,  0x0004, -0x00000002,  0x00000000, NULL },
    MSG_NPC(4, _(" There, the one in the middle\nwith the pointy nose.")),
    MSG_NPC(4, _(" He's a Pokémon named\n{POKEMON_3}.\nHe's got his own rescue team.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(9),
    ROTATE(4, 2, DIRECTION_SOUTH),
    ALERT_CUE(6),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" But his team's greedy.\nThey don't work unless they get paid\nroyally.")),
    MSG_NPC(4, _(" {NAME_2}'s been begging\nfor help, but...{WAIT_PRESS}\nI feel sorry for that poor Pokémon.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(9),
    ALERT_CUE(6),
    MSG_NPC(-1, _(" Wait!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    WAIT(4),
    ALERT_CUE(4),
    ALERT_CUE(8),
    ALERT_CUE(7),
    ALERT_CUE(13),
    ALERT_CUE(14),
    WAIT(20),
    { 0x93, 0x04,  0x000b,  0x00000058,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(6),
    WAIT(1),
    ALERT_CUE(9),
    WAIT(70),
    ALERT_CUE(8),
    ALERT_CUE(13),
    ALERT_CUE(14),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0003, 0x00000041),
    MSG_NPC(3, _(" Oh! Wh-what do you want?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" Oh! It's {NAME_5}!")),
    MSG_NPC(-1, _(" That's {NAME_5}?!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(10),
    ALERT_CUE(7),
    ALERT_CUE(13),
    ALERT_CUE(14),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" Hey. Rather coldhearted,\naren't you?")),
    MSG_NPC(5, _(" To save {NAME_2}'s\nfriend, a strong wind is needed.")),
    MSG_NPC(5, _(" Your leafy fans can whip up\npowerful winds.")),
    MSG_NPC(5, _(" It's an easy matter for you.{WAIT_PRESS}\nHelp that Pokémon out.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_FLIP, 0x0003, 0x00000041),
    MSG_NPC(3, _(" Grr...{WAIT_PRESS}\nTch! OK, we'll do it.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    ALERT_CUE(13),
    ALERT_CUE(14),
    AWAIT_CUE(5),
    WAIT(60),
    ALERT_CUE(13),
    ALERT_CUE(14),
    MSG_NPC(-1, _(" Wow...")),
    MSG_NPC(-1, _(" That {NAME_3} agreed without\nany argument...")),
    TEXTBOX_CLEAR,
    WAIT(20),
    BGM_FADEIN(80, 7),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, who are those guys?")),
    VARIANT_DEFAULT(_(" Say, who are they?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" What? You don't know?!\nIt's {NAME_5}'s team!")),
    MSG_NPC(4, _(" They're the most famous\nrescue team around these parts.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(9),
    WAIT(5),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(6),
    WAIT(20),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    { 0x2e, 0x00,  0x0004, -0x00000002,  0x00000000, NULL },
    MSG_NPC(4, _(" That's {NAME_6}.{WAIT_PRESS}\nHis Flamethrower can melt mountains!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" That's {NAME_7}.{WAIT_PRESS}\nHe takes great pride in his armored\nbody and amazing strength.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" And that's the leader,\n{NAME_5}.")),
    MSG_NPC(4, _(" {NAME_5} doesn't like\nphysical attacks.\nHe fights with his psychic powers.")),
    MSG_NPC(4, _(" He's endowed with an\namazing brain and an IQ of 5,000.")),
    MSG_NPC(4, _(" Apparently, he's memorized\neverything that's happened in the world.")),
    MSG_NPC(4, _(" {NAME_5} does all the\ncommanding in the team.{WAIT_PRESS}\nHe's clearly in charge.")),
    TEXTBOX_CLEAR,
    WAIT(16),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Th-thank you.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_LEFT_, 0x0005, 0x00000000),
    MSG_NPC(5, _(" No need for thanks.\nIt is only natural that you get help.")),
    MSG_NPC(5, _(" If anyone turns you down\nagain, come see me.\nTake care.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    WAIT(1),
    ALERT_CUE(7),
    ALERT_CUE(4),
    ALERT_CUE(12),
    ALERT_CUE(11),
    ALERT_CUE(10),
    ALERT_CUE(13),
    ALERT_CUE(14),
    WAIT(46),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("{COLOR YELLOW}{SPEECH_BUBBLE}{RESET}: C-cool...") },
    WAIT(60),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("{COLOR YELLOW}{SPEECH_BUBBLE}{RESET}: I wouldn't expect less from a Gold\nRank rescue team.") },
    WAIT(40),
    ROTATE(10, 11, DIRECTION_EAST),
    ALERT_CUE(6),
    ALERT_CUE(9),
    WAIT(70),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(30),
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0005, 0x00000000),
    MSG_NPC(5, _(" ...!")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(10),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(9),
    ALERT_CUE(7),
    WAIT(24),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Wah! What's wrong?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(12),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" What's up?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" ......{WAIT_PRESS}\nIt's fine. Nothing.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    WAIT(64),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0005, 0x00000000),
    MSG_NPC(5, _(" Let's go.")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    WAIT(94),
    WAIT(30),
    ALERT_CUE(9),
    BGM_FADEIN(60, 7),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Whew!\nThat was scary! Sheesh!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0001, 0x0000000b),
    MSG_NPC(1, _(" ...C-cool...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew, {NAME_0}...{WAIT_PRESS}\nThat's what we've got to become.")),
    VARIANT(/* == */  1, _(" Let's get more members and\nmake our rescue team first-class!")),
    VARIANT(/* == */  3, _(" Whew, {NAME_0}!{WAIT_PRESS}\nWe need to become like them!")),
    VARIANT(/* == */  3, _(" Let's recruit more members\nand make our rescue team first-class!")),
    VARIANT_DEFAULT(_(" Whew, {NAME_0}!{WAIT_PRESS}\nWe need to become like them!")),
    VARIANT_DEFAULT(_(" Let's recruit more members\nand make our rescue team first-class!")),
    TEXTBOX_CLEAR,
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    { 0x2d, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT, 0x0005, 0x00000000),
    WAIT(32),
    MSG_NPC(-1, _(" Not if I can help it!\nKekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    AWAIT_CUE(5),
    BGM_FADEOUT(120),
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};

























static const struct ScriptCommand s_gs1_g10_s0_lives3_dlg0[] = { /* 0x8142cf4 */
    DEBUGINFO_O(2759),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x0000004e,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 23),
    { 0x8e, 0x01,  0x0000,  0x0000004e,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_SOUTH),
    AWAIT_CUE(6),
    WAIT(3),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(10, 2, DIRECTION_EAST),
    AWAIT_CUE(6),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(6),
    { 0x90, 0x20,  0x0000,  0x0000001c,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s0_lives4_dlg0[] = { /* 0x8142f64 */
    DEBUGINFO_O(2801),
    SELECT_ANIMATION(3),
    { 0x2d, 0x07,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    AWAIT_CUE(14),
    { 0x93, 0x04,  0x000b,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_SOUTH),
    AWAIT_CUE(14),
    CALL_SCRIPT(SHOCK_FUNC),
    ROTATE(1, 1, DIRECTION_WEST),
    { 0x61, 0x00,  0x0400,  0x00000230,  0x00000108, NULL },
    WAIT(30),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(14),
    ROTATE(4, 2, DIRECTION_SOUTH),
    AWAIT_CUE(14),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(14),
    WAIT(150),
    ROTATE(8, 2, DIRECTION_SOUTHEAST),
    WAIT(60),
    ROTATE(4, 2, DIRECTION_EAST),
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s0_lives5_dlg0[] = { /* 0x8143104 */
    DEBUGINFO_O(2830),
    SELECT_ANIMATION(3),
    { 0x2d, 0x07,  0x0009,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_WEST),
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_NORTHWEST),
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_NORTH),
    AWAIT_CUE(14),
    WAIT(10),
    AWAIT_CUE(14),
    ROTATE(4, 11, DIRECTION_NORTH),
    AWAIT_CUE(14),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(14),
    WAIT(150),
    ROTATE(8, 1, DIRECTION_NORTHEAST),
    WAIT(60),
    ROTATE(4, 1, DIRECTION_EAST),
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s0_lives6_dlg0[] = { /* 0x8143254 */
    DEBUGINFO_O(2854),
    SELECT_ANIMATION(3),
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(13),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    AWAIT_CUE(13),
    ROTATE(4, 11, DIRECTION_SOUTH),
    AWAIT_CUE(13),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(65),
    ROTATE(1, 2, DIRECTION_EAST),
    { 0x61, 0x00,  0x0400,  0x000001d0,  0x00000108, NULL },
    WAIT(30),
    ROTATE(4, 2, DIRECTION_NORTH),
    AWAIT_CUE(13),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(13),
    ROTATE(4, 2, DIRECTION_SOUTHEAST),
    AWAIT_CUE(13),
    WAIT(120),
    ROTATE(4, 2, DIRECTION_EAST),
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s0_lives7_dlg0[] = { /* 0x81433e4 */
    DEBUGINFO_O(2882),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    AWAIT_CUE(7),
    AWAIT_CUE(7),
    AWAIT_CUE(7),
    { 0x89, 0x10,  0x0200,  0x00000006,  0x00000000, NULL },
    { 0x89, 0x10,  0x0100,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(13),
    ALERT_CUE(14),
    WAIT(48),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x89, 0x08,  0x0100,  0x00000003,  0x00000000, NULL },
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    WAIT(50),
    ROTATE(4, 11, DIRECTION_EAST),
    WAIT(70),
    { 0x89, 0x30,  0x0100,  0x00000002,  0x00000000, NULL },
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s0_lives8_dlg0[] = { /* 0x8143574 */
    DEBUGINFO_O(2910),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x8e, 0x01,  0x0000,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(8),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    FANFARE_STOP2(465),
    AWAIT_CUE(8),
    ROTATE(4, 11, DIRECTION_EAST),
    FANFARE_PLAY2(468),
    WAIT(48),
    ROTATE(4, 11, DIRECTION_WEST),
    WAIT(40),
    ROTATE(4, 11, DIRECTION_NORTHWEST),
    FANFARE_PLAY2(468),
    WAIT(40),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    FANFARE_PLAY2(468),
    WAIT(40),
    FANFARE_STOP2(468),
    ROTATE(4, 11, DIRECTION_WEST),
    WAIT(16),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WAIT(1),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(460, 24),
    WAIT(1),
    ALERT_CUE(7),
    WALK_GRID(460, 24),
    WAIT(32),
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s0_lives9_dlg0[] = { /* 0x81437d4 */
    DEBUGINFO_O(2951),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    { 0x8e, 0x01,  0x0000,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x62, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(460, 25),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s0_lives10_dlg0[] = { /* 0x8143884 */
    DEBUGINFO_O(2965),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    { 0x8e, 0x01,  0x0000,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x62, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(460, 25),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s0_lives11_dlg0[] = { /* 0x8143934 */
    DEBUGINFO_O(2979),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x8e, 0x01,  0x0000,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x0002,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 11, DIRECTION_NORTH),
    AWAIT_CUE(9),
    WAIT(3),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(9),
    { 0x8e, 0x01,  0x0000,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x8e, 0x01,  0x0000,  0x00000004,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x8e, 0x01,  0x0000,  0x00000058,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(10, 1, DIRECTION_EAST),
    AWAIT_CUE(9),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(9),
    HALT,
};

static const struct ScriptCommand s_gs1_g10_s1_lives0_dlg0[] = { /* 0x8143b44 */
    DEBUGINFO_O(3015),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    WALK_GRID(256, 26),
    AWAIT_CUE(10),
    { 0x89, 0x0f,  0x0100,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(10),
    WAIT(30),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_DIRECT(240, 27),
    AWAIT_CUE(10),
    FANFARE_PLAY2(466),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    WAIT(10),
    AWAIT_CUE(10),
    ROTATE(4, 2, DIRECTION_WEST),
    AWAIT_CUE(10),
    { 0x8e, 0x10,  0x0000,  0x00000059,  0x00000000, NULL },
    WAIT(16),
    { 0x8e, 0x10,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT(16),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    WALK_DIRECT(128, 28),
    WAIT(128),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s1_lives1_dlg0[] = { /* 0x8143d14 */
    DEBUGINFO_O(3047),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    WALK_GRID(256, 29),
    AWAIT_CUE(11),
    WAIT(30),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_DIRECT(240, 30),
    AWAIT_CUE(11),
    WAIT(5),
    { 0x8e, 0x10,  0x0000,  0x00000058,  0x00000000, NULL },
    WAIT(16),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    WAIT(5),
    FANFARE_STOP2(469),
    AWAIT_CUE(11),
    WALK_DIRECT(136, 31),
    WAIT(136),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s1_lives2_dlg0[] = { /* 0x8143e74 */
    DEBUGINFO_O(3072),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    WALK_GRID(256, 32),
    AWAIT_CUE(12),
    WAIT(30),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_DIRECT(240, 33),
    AWAIT_CUE(12),
    { 0x8e, 0x10,  0x0000,  0x00000058,  0x00000000, NULL },
    WAIT(16),
    AWAIT_CUE(12),
    WALK_DIRECT(136, 34),
    WAIT(136),
    AWAIT_CUE(3),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g10_s2_lives0_dlg0[] = { /* 0x8143f74 */
    DEBUGINFO_O(3091),
    SELECT_ANIMATION(2),
    { 0x2d, 0x01,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(10, 10, DIRECTION_SOUTH),
    WAIT(10),
    SELECT_ANIMATION(24),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    WAIT(20),
    ALERT_CUE(5),
    WAIT(20),
    WALK_DIRECT(140, 35),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g11_s0_station_sref_script[] = { /* 0x8144064 */
    DEBUGINFO_O(3109),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g11_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g11_s0_station_sref_script }; /* 0x8144094 */

static const struct ScriptCommand s_gs1_g11_s0_lives0_dlg2[] = { /* 0x81440a0 */
    DEBUGINFO_O(3117),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives1_dlg2[] = { /* 0x8144100 */
    DEBUGINFO_O(3126),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives2_dlg2[] = { /* 0x8144160 */
    DEBUGINFO_O(3135),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives3_dlg2[] = { /* 0x81441c0 */
    DEBUGINFO_O(3144),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives4_dlg2[] = { /* 0x8144220 */
    DEBUGINFO_O(3153),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives5_dlg2[] = { /* 0x8144280 */
    DEBUGINFO_O(3162),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives6_dlg1[] = { /* 0x81442e0 */
    DEBUGINFO_O(3171),
    { 0x51, 0x00,  0x0024,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g11_s0_lives6_dlg2[] = { /* 0x8144320 */
    DEBUGINFO_O(3178),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004d,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Alakazam and his sidekicks\nwere sure cool before.")),
    MSG_NPC(1, _(" That's how a real hero has\nto carry himself.")),
    MSG_NPC(1, _(" By the way...{WAIT_PRESS}\nApparently, it's been impossible for us to\nevolve lately.")),
    MSG_NPC(1, _(" You know how we Pokémon\nevolve if the conditions are right?")),
    MSG_NPC(1, _(" But for some reason, we\nhaven't been able to evolve at all.")),
    MSG_NPC(1, _(" It's rumored that the natural\ndisasters are to blame, but...{WAIT_PRESS}\nI wonder what's going on.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives7_dlg1[] = { /* 0x8144578 */
    DEBUGINFO_O(3193),
    SELECT_ANIMATION(1),
    { 0x8b, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g11_s0_lives7_dlg2[] = { /* 0x81445b8 */
    DEBUGINFO_O(3200),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Did you know that a new\ntraining gym--I think they called it\na dojo--opened in town?")),
    MSG_NPC(1, _(" You know how many rescue\nteams started up? To deal with all\nthe natural disasters?")),
    MSG_NPC(1, _(" There was a group of\nconcerned Pokémon...{WAIT_PRESS}\nThey wanted to support rescue teams.")),
    MSG_NPC(1, _(" So they got together and\nbuilt the dojo.")),
    MSG_NPC(1, _(" You can find the dojo easily.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" From here, it's just straight\ndown this path.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" If you have a rescue team\ntoo, I highly recommend you pay the dojo\na visit.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g11_s0_lives7_dlg3[] = { /* 0x8144888 */
    DEBUGINFO_O(3219),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 11, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    CALL_SCRIPT(WAIT_END_TALK_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g11_s0_lives8_dlg2[] = { /* 0x8144938 */
    DEBUGINFO_O(3233),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Alakazam's team has the\nGold Rank. Isn't that awesome?")),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" You have a rescue team too,\ndon't you?{WAIT_PRESS}\nWhat's your rank?")),
    CHOICE(/* label */  0, _("Nothing special.")),
    CHOICE(/* label */  1, _("Gold Rank.")),
  LABEL(0), /* = 0x00 */
    MSG_NPC(1, _(" I guess that's true.")),
    MSG_NPC(1, _(" It might be rude to say it...{WAIT_PRESS}\nbut you obviously look like you really are\nnothing special.")),
    MSG_NPC(1, _(" It just goes to show how\nawesome Alakazam's team is!")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_NPC(1, _(" What?!\nYou're Gold Rank too?!")),
    MSG_NPC(1, _(" ......{WAIT_PRESS}\nI'm not falling for a lie like that.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g12_s0_station_sref_script[] = { /* 0x8144bf0 */
    DEBUGINFO_O(3253),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    FANFARE_PLAY(0),
    { 0x27, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    AWAIT_CUE(3),
    FANFARE_STOP(0),
    { 0x28, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g12_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g12_s0_station_sref_script }; /* 0x8144c80 */

static const struct ScriptCommand s_gs1_g12_s0_lives0_dlg0[] = { /* 0x8144c8c */
    DEBUGINFO_O(3267),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0000, 0x00000041),
    MSG_NPC(0, _(" Please help my friend!\nPlease, I need help!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Forget it.\nWe're not about to work for that.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(0, _(" But my friend needs a gust\nof wind! Please!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs1_g12_s0_lives1_dlg0[] = { /* 0x8144d9c */
    DEBUGINFO_O(3290),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives2_dlg0[] = { /* 0x8144ddc */
    DEBUGINFO_O(3297),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives3_dlg0[] = { /* 0x8144e0c */
    DEBUGINFO_O(3303),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives4_dlg0[] = { /* 0x8144e3c */
    DEBUGINFO_O(3309),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives5_dlg0[] = { /* 0x8144e6c */
    DEBUGINFO_O(3315),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives6_dlg0[] = { /* 0x8144e9c */
    DEBUGINFO_O(3321),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives7_dlg0[] = { /* 0x8144ecc */
    DEBUGINFO_O(3327),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives8_dlg0[] = { /* 0x8144efc */
    DEBUGINFO_O(3333),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g12_s0_lives9_dlg0[] = { /* 0x8144f2c */
    DEBUGINFO_O(3339),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g13_s0_station_sref_script[] = { /* 0x8144f5c */
    DEBUGINFO_O(3345),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g13_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g13_s0_station_sref_script }; /* 0x8144f8c */

static const struct ScriptCommand s_gs1_g13_s0_lives0_dlg2[] = { /* 0x8144f98 */
    DEBUGINFO_O(3353),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives1_dlg2[] = { /* 0x8144ff8 */
    DEBUGINFO_O(3362),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives2_dlg2[] = { /* 0x8145058 */
    DEBUGINFO_O(3371),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives3_dlg2[] = { /* 0x81450b8 */
    DEBUGINFO_O(3380),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives4_dlg2[] = { /* 0x8145118 */
    DEBUGINFO_O(3389),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives5_dlg2[] = { /* 0x8145178 */
    DEBUGINFO_O(3398),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives6_dlg1[] = { /* 0x81451d8 */
    DEBUGINFO_O(3407),
    { 0x51, 0x00,  0x0026,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g13_s0_lives6_dlg2[] = { /* 0x8145218 */
    DEBUGINFO_O(3414),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We heard.{WAIT_PRESS}\nShiftry hasn't returned?")),
    MSG_NPC(1, _(" I wonder...\nDid Shiftry maybe just run off?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g13_s0_lives7_dlg1[] = { /* 0x81452e0 */
    DEBUGINFO_O(3424),
    { 0x51, 0x00,  0x0025,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g13_s0_lives7_dlg2[] = { /* 0x8145320 */
    DEBUGINFO_O(3431),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm afraid Shiftry's team is\nalways about the money.")),
    MSG_NPC(1, _(" They went out on that\nrescue only because Alakazam told them\nto...")),
    MSG_NPC(1, _(" I don't think they were\nvery enthusiastic about it.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_station_sref_script[] = { /* 0x8145458 */
    DEBUGINFO_O(3442),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g14_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g14_s0_station_sref_script }; /* 0x8145488 */

static const struct ScriptCommand s_gs1_g14_s0_lives0_dlg2[] = { /* 0x8145494 */
    DEBUGINFO_O(3450),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives1_dlg2[] = { /* 0x81454f4 */
    DEBUGINFO_O(3459),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives2_dlg2[] = { /* 0x8145554 */
    DEBUGINFO_O(3468),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives3_dlg2[] = { /* 0x81455b4 */
    DEBUGINFO_O(3477),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives4_dlg2[] = { /* 0x8145614 */
    DEBUGINFO_O(3486),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives5_dlg2[] = { /* 0x8145674 */
    DEBUGINFO_O(3495),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives6_dlg1[] = { /* 0x81456d4 */
    DEBUGINFO_O(3504),
    { 0x51, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g14_s0_lives6_dlg2[] = { /* 0x8145714 */
    DEBUGINFO_O(3511),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Shiftry was abducted?\nThat's shocking news!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives7_dlg1[] = { /* 0x81457a4 */
    DEBUGINFO_O(3520),
    { 0x51, 0x00,  0x0027,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g14_s0_lives7_dlg2[] = { /* 0x81457e4 */
    DEBUGINFO_O(3527),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Is that right...\nShiftry was taken away to {COLOR YELLOW_D}Mt. Thunder{RESET}...")),
    MSG_NPC(1, _(" I wonder what that place is\nlike?{WAIT_PRESS}\nIt sounds rather horrible.")),
    MSG_NPC(1, _(" Oh? Me?{WAIT_PRESS}\nI couldn't possibly go rescue him.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives8_dlg1[] = { /* 0x8145914 */
    DEBUGINFO_O(3538),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g14_s0_lives8_dlg2[] = { /* 0x8145944 */
    DEBUGINFO_O(3544),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000050,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000004e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000001),
    MSG_NPC(2, _(" I'm glad to see you're\nback safe.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Thank you.\nBut Shiftry is in trouble now...")),
    MSG_NPC(3, _(" Shiftry came and rescued\nme...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000001),
    MSG_NPC(3, _(" I hope he is safe...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives9_dlg1[] = { /* 0x8145ae4 */
    DEBUGINFO_O(3564),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g14_s0_lives9_dlg2[] = { /* 0x8145b14 */
    DEBUGINFO_O(3570),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000050,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000004e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000001),
    MSG_NPC(2, _(" I'm glad to see you're\nback safe.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Thank you.\nBut Shiftry is in trouble now...")),
    MSG_NPC(3, _(" Shiftry came and rescued\nme...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000001),
    MSG_NPC(3, _(" I hope he is safe...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g14_s0_lives10_dlg1[] = { /* 0x8145c24 */
    DEBUGINFO_O(3590),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g14_s0_lives10_dlg2[] = { /* 0x8145c54 */
    DEBUGINFO_O(3596),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000050,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000004e,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000001),
    MSG_NPC(2, _(" I'm glad to see you're\nback safe.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Thank you.\nBut Shiftry is in trouble now...")),
    MSG_NPC(3, _(" Shiftry came and rescued\nme...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000001),
    MSG_NPC(3, _(" I hope he is safe...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_station_sref_script[] = { /* 0x8145d64 */
    DEBUGINFO_O(3616),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g15_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g15_s0_station_sref_script }; /* 0x8145d94 */

static const struct ScriptCommand s_gs1_g15_s0_lives0_dlg2[] = { /* 0x8145da0 */
    DEBUGINFO_O(3624),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives1_dlg2[] = { /* 0x8145e00 */
    DEBUGINFO_O(3633),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives2_dlg2[] = { /* 0x8145e60 */
    DEBUGINFO_O(3642),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives3_dlg2[] = { /* 0x8145ec0 */
    DEBUGINFO_O(3651),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives4_dlg2[] = { /* 0x8145f20 */
    DEBUGINFO_O(3660),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives5_dlg2[] = { /* 0x8145f80 */
    DEBUGINFO_O(3669),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives6_dlg1[] = { /* 0x8145fe0 */
    DEBUGINFO_O(3678),
    { 0x51, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g15_s0_lives6_dlg2[] = { /* 0x8146020 */
    DEBUGINFO_O(3685),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004d,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Xatu?{WAIT_PRESS} I wouldn't know.{WAIT_PRESS}\nThere's really a Pokémon named that?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives7_dlg1[] = { /* 0x81460d8 */
    DEBUGINFO_O(3695),
    { 0x51, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g15_s0_lives7_dlg2[] = { /* 0x8146118 */
    DEBUGINFO_O(3702),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004f,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I must say, I'm very\nimpressed.")),
    MSG_NPC(1, _(" Your team is surprisingly\ncourageous. It casts you in a new light!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives8_dlg2[] = { /* 0x8146204 */
    DEBUGINFO_O(3713),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm glad that Shiftry is\nsafe.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g15_s0_lives9_dlg2[] = { /* 0x8146288 */
    DEBUGINFO_O(3722),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_0}, your team is\nfantastic!")),
    MSG_NPC(1, _(" It's shocking to hear that\nyou've beaten Zapdos!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_station_sref_script[] = { /* 0x8146350 */
    DEBUGINFO_O(3732),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g16_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g16_s0_station_sref_script }; /* 0x8146380 */

static const struct ScriptCommand s_gs1_g16_s0_lives0_dlg2[] = { /* 0x814638c */
    DEBUGINFO_O(3740),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_lives1_dlg2[] = { /* 0x81463ec */
    DEBUGINFO_O(3749),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_lives2_dlg2[] = { /* 0x814644c */
    DEBUGINFO_O(3758),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_lives3_dlg2[] = { /* 0x81464ac */
    DEBUGINFO_O(3767),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_lives4_dlg2[] = { /* 0x814650c */
    DEBUGINFO_O(3776),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_lives5_dlg2[] = { /* 0x814656c */
    DEBUGINFO_O(3785),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g16_s0_evt0_sref_script[] = { /* 0x81465cc */
    DEBUGINFO_O(3794),
    EXECUTE_STATION(-1, 17, 0),
    HALT,
};

static const struct ScriptRef s_gs1_g16_s0_evt0_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs1_g16_s0_evt0_sref_script }; /* 0x81465fc */

static const struct ScriptCommand s_gs1_g17_s0_station_sref_script[] = { /* 0x8146608 */
    DEBUGINFO_O(3802),
    SELECT_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    SELECT_ENTITIES(18, 0),
    CANCEL_ENTITIES(16, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  4),
    RET,
};

static const struct ScriptRef s_gs1_g17_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g17_s0_station_sref_script }; /* 0x8146678 */

static const struct ScriptCommand s_gs1_g17_s0_eff0_script[] = { /* 0x8146684 */
    DEBUGINFO_O(3814),
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0180,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    CAMERA_END_PAN,
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g17_s0_lives0_dlg0[] = { /* 0x8146704 */
    DEBUGINFO_O(3825),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0005,  0x00000062,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0006,  0x00000063,  0x00000000, NULL },
    WAIT(30),
    { 0x93, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?{WAIT_PRESS}\nWhat are those guys talking about?")),
    VARIANT_DEFAULT(_(" Huh?{WAIT_PRESS}\nWhat are they chatting about?")),
    TEXTBOX_CLEAR,
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(4),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    MSG_NPC(2, _(" Yeah, I'm kind of shocked.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" I always thought it was\nonly a legend.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" But could it be true?{WAIT_PRESS}\nI'm having a hard time believing it...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    WALK_GRID(256, 45),
    WALK_GRID(256, 43),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, what's up?")),
    VARIANT_DEFAULT(_(" Hi, what's happening?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Well, you know the\n{COLOR GREEN}{NAME_6} legend{RESET}?\nThat old story?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 16, 0),
    ROTATE(8, 1, DIRECTION_SOUTHEAST),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_NPC(1, _(" The {NAME_6} legend?{WAIT_PRESS}\nWhat's that?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(8),
    MSG_NPC(2, _(" What, you don't know?")),
    MSG_NPC(2, _(" You know, it's that old\nfairy tale.")),
    MSG_NPC(2, _(" How you'll get cursed if you\never grab one of Ninetales's tails.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" All this time, everyone\nthought it was just a legend.")),
    ALERT_CUE(6),
    MSG_NPC(4, _(" But lately, it's been rumored\nthat maybe it really happened.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Well, it is still a mere\nrumor.")),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    MSG_NPC(3, _(" I wouldn't put too much\nstock in that story if I were you.")),
    MSG_NPC(3, _(" Personally, I don't believe\nin rumors of that sort.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" If you want to know more\nabout the {NAME_6} legend...")),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    MSG_NPC(2, _(" You should go see a\nPokémon named {NAME_5}.\nHe knows the story well.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    MSG_NPC(2, _(" {NAME_5} is uh...{WAIT_PRESS}\nYou know, in his pond.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTH),
    WAIT(60),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_TOP_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" You should visit him if you\nwant to know more.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs1_g17_s0_lives1_dlg0[] = { /* 0x8147160 */
    DEBUGINFO_O(3932),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(464),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 44),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 16, 0),
    ROTATE(8, 2, DIRECTION_NORTHEAST),
    WAIT(20),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTH),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g17_s0_lives2_dlg0[] = { /* 0x8147330 */
    DEBUGINFO_O(3964),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(30),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(7),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE(4, 1, DIRECTION_WEST),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g17_s0_lives3_dlg0[] = { /* 0x81474c0 */
    DEBUGINFO_O(3992),
    SELECT_ANIMATION(2),
    { 0x8b, 0x01,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g17_s0_lives4_dlg0[] = { /* 0x8147590 */
    DEBUGINFO_O(4008),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE(4, 2, DIRECTION_WEST),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g18_s0_station_sref_script[] = { /* 0x8147620 */
    DEBUGINFO_O(4020),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g18_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g18_s0_station_sref_script }; /* 0x8147650 */

static const struct ScriptCommand s_gs1_g18_s0_lives0_dlg2[] = { /* 0x814765c */
    DEBUGINFO_O(4028),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives1_dlg2[] = { /* 0x81476bc */
    DEBUGINFO_O(4037),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives2_dlg2[] = { /* 0x814771c */
    DEBUGINFO_O(4046),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives3_dlg2[] = { /* 0x814777c */
    DEBUGINFO_O(4055),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives4_dlg2[] = { /* 0x81477dc */
    DEBUGINFO_O(4064),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives5_dlg2[] = { /* 0x814783c */
    DEBUGINFO_O(4073),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives6_dlg2[] = { /* 0x814789c */
    DEBUGINFO_O(4082),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Whiscash is in the pond just\nnorth of here.")),
    MSG_NPC(1, _(" You should visit him if you\nwant to chat.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives7_dlg2[] = { /* 0x8147968 */
    DEBUGINFO_O(4092),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Well, it is still a mere\nrumor.")),
    MSG_NPC(1, _(" I don't put any stock in\nrumors like that...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g18_s0_lives8_dlg2[] = { /* 0x8147a08 */
    DEBUGINFO_O(4102),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I always thought it was\nonly a legend.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g19_s0_station_sref_script[] = { /* 0x8147a68 */
    DEBUGINFO_O(4111),
    SELECT_ENTITIES(-1, -1),
    AWAIT_CUE(3),
    BGM_FADEOUT(45),
    { 0x23, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    EXECUTE_FUNCTION(EVENT_M01E05B_L005),
    HALT,
};

static const struct ScriptRef s_gs1_g19_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g19_s0_station_sref_script }; /* 0x8147ae8 */

static const struct ScriptCommand s_gs1_g19_s0_lives0_dlg0[] = { /* 0x8147af4 */
    DEBUGINFO_O(4124),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    WAIT(1),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Listen, {NAME_0}.")),
    VARIANT_DEFAULT(_(" ...Say, {NAME_0}.")),
    TEXTBOX_CLEAR,
    ROTATE(4, 2, DIRECTION_EAST),
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000005),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Want to knock\noff for today?\nI can't seem to get into it...")),
    VARIANT_DEFAULT(_(" Want to call it a day now?\nI can't seem to get motivated today...")),
    TEXTBOX_CLEAR,
    WAIT(45),
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs1_g19_s0_lives1_dlg0[] = { /* 0x8147cf0 */
    DEBUGINFO_O(4148),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g20_s0_station_sref_script[] = { /* 0x8147d50 */
    DEBUGINFO_O(4157),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_STOP,
    ALERT_CUE(4),
    { 0x22, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0x23, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x22, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0x23, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x22, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    ALERT_CUE(6),
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g20_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g20_s0_station_sref_script }; /* 0x8147ea0 */

static const struct ScriptCommand s_gs1_g20_s0_eff0_script[] = { /* 0x8147eac */
    DEBUGINFO_O(4183),
    WARP_WAYPOINT(0, 46),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WALK_DIRECT(180, 47),
    AWAIT_CUE(4),
    { 0xe5, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WARP_WAYPOINT(0, 48),
    { 0x6c, 0xb4,  0x0100,  0x00000031,  0x00000000, NULL },
    AWAIT_CUE(4),
    { 0xe5, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WARP_WAYPOINT(0, 50),
    { 0x62, 0x00,  0x0100, -0x00000050,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g20_s0_lives0_dlg0[] = { /* 0x8147f8c */
    DEBUGINFO_O(4200),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    WALK_RELATIVE(128, 80, 0),
    ALERT_CUE(6),
    FANFARE_PLAY2(469),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_NPC(1, _(" Huh?")),
    TEXTBOX_CLEAR,
    ROTATE(5, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(6),
    WAIT(20),
    ROTATE(10, 1, DIRECTION_EAST),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" The town's atmosphere\nfeels different somehow...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Maybe something's happened.")),
    MSG_NPC(1, _(" {NAME_0}, let's check\nit out!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(3),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 120, 0),
    HALT,
};


static const struct ScriptCommand s_gs1_g20_s0_lives1_dlg0[] = { /* 0x81481f8 */
    DEBUGINFO_O(4235),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(128, 80, 0),
    AWAIT_CUE(6),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 72, 0),
    ROTATE(5, 10, DIRECTION_NORTH),
    WAIT(15),
    ROTATE(5, 1, DIRECTION_SOUTH),
    WAIT(15),
    ROTATE(5, 10, DIRECTION_EAST),
    WAIT(15),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 120, 0),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs1_g21_s0_station_sref_script[] = { /* 0x8148378 */
    DEBUGINFO_O(4262),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_STOP,
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g21_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g21_s0_station_sref_script }; /* 0x81483f8 */

static const struct ScriptCommand s_gs1_g21_s0_eff0_script[] = { /* 0x8148404 */
    DEBUGINFO_O(4275),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WALK_RELATIVE(256, 34, 0),
    AWAIT_CUE(4),
    WAIT(30),
    WALK_GRID(512, 51),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_DIRECT(5, 58),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g21_s0_lives0_dlg0[] = { /* 0x81484d4 */
    DEBUGINFO_O(4291),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0007,  0x00000061,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0008,  0x00000052,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_RELATIVE(256, 70, 0),
    WAIT(30),
    FANFARE_PLAY2(464),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Look!\nWhy's everyone gathered over there?")),
    VARIANT_DEFAULT(_(" Look!\nWhy is everyone gathered together?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, what's up?")),
    VARIANT_DEFAULT(_(" Hi, what's going on?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0005, 0x00000001),
    MSG_NPC(5, _(" Let me tell you, I was\namazed!{WAIT_PRESS}\nIt really was true!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What are you talking about?")),
    VARIANT_DEFAULT(_(" What was true?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0005, 0x00000000),
    MSG_NPC(5, _(" The Ninetales legend!")),
    MSG_NPC(5, _(" I never believed the\nrumors, so you can bet I was shocked\nto learn the truth!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" {NAME_0}, {NAME_1}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    ALERT_CUE(6),
    FANFARE_PLAY2(463),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000036,  0x00000000, NULL },
    MSG_NPC(1, _(" Oh, hi, {NAME_3}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(10),
    { 0x93, 0x0a,  0x000a,  0x00000036,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000001),
    MSG_NPC(1, _(" Even you came out,\n{NAME_3}?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Yes.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" Ssh!{WAIT_PRESS} Quiet.")),
    MSG_NPC(6, _(" That guy there's telling us.\nKeep it down.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(11),
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?{WAIT_PRESS}\nWho's doing the talking?")),
    VARIANT_DEFAULT(_(" Huh?{WAIT_PRESS} Who's talking?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" I-it's...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(10),
    ALERT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    ALERT_CUE(4),
    WAIT(30),
    ALERT_CUE(7),
    ALERT_CUE(11),
    WAIT(10),
    ALERT_CUE(8),
    ALERT_CUE(10),
    WAIT(10),
    ALERT_CUE(6),
    WALK_DIRECT(150, 55),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(473),
    ALERT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Ge-{NAME_2}?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    BGM_SWITCH(9),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" ...So I went up to the\n{COLOR CYAN}Hill of the Ancients{RESET}.")),
    MSG_NPC(2, _(" And that's where I saw it!\nIt was shocking stuff, I tell you!\nKekeh!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Shocking stuff?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" This certain Pokémon was\ngetting advice from {NAME_7}.")),
    PORTRAIT_REP(0x0002, 0x00000004),
    MSG_NPC(2, _(" That Pokémon...\nIt looks like an ordinary Pokémon...")),
    PORTRAIT_REP(0x0002, 0x00000006),
    MSG_NPC(2, _(" But get this!{WAIT_PRESS}\nIt was originally a human!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    CALL_LABEL(15),
    FANFARE_PLAY2(464),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000022,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" What?!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" It really existed...\nA human that turned into a Pokémon.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT_REP(0x0002, 0x00000004),
    MSG_NPC(2, _(" There's more.\n{NAME_7} told the human...")),
    MSG_NPC(2, _(" That how the human became\na Pokémon has a lot to do with how\nthe world's balance is upset.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Wait a second...{WAIT_PRESS}\nThat's exactly like the Ninetales legend!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Kekeh!\nDon't be too shocked yet.\nThere's more.")),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000004),
    MSG_NPC(2, _(" You all know how there've\nbeen many natural disasters, correct?")),
    MSG_NPC(2, _(" According to {NAME_7},\nthose disasters are caused by the world's\nbalance being upset.")),
    MSG_NPC(2, _(" And if the world's balance\nisn't restored soon...")),
    PORTRAIT_REP(0x0002, 0x00000006),
    MSG_NPC(2, _(" The unthinkable will happen\nto the world! That's what Xatu said!\nKekeh!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    CALL_LABEL(15),
    FANFARE_PLAY2(473),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    MSG_NPC(4, _(" Wh-what?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0005, 0x00000001),
    MSG_NPC(5, _(" The world...{WAIT_PRESS}\nThe unthinkable's going to happen?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(6, _(" What are we to do?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0001, 0x00000003),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That Gengar...!{WAIT_PRESS}\nHe's getting everyone worked up...")),
    VARIANT_DEFAULT(_(" That Gengar...!{WAIT_PRESS}\nHe's deliberately working everyone up...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Now, now, people.{WAIT_PRESS}\nThere's no need to panic.")),
    MSG_NPC(2, _(" Why, I think there's a way\nwe can do something about this.\nKekeh!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(16),
    ALERT_CUE(17),
    FANFARE_PLAY2(465),
    WAIT(60),
    MSG_NPC(6, _(" Wh-what can we do?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    MSG_NPC(2, _(" Oh, it's quite simple,\nactually.")),
    MSG_NPC(2, _(" If the world's balance is\nupset by a human becoming a Pokémon...")),
    PORTRAIT_REP(0x0002, 0x00000001),
    MSG_NPC(2, _(" Then, if that human is\ngone, then everything should return\nto normal, correct?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    WAIT(15),
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Th-that's true!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_LEFT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" When you put it that way...\nmaybe you're right.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Kekeh!\nAnd that human is the rotten coward\nthat abandoned {NAME_8}, correct?")),
    ALERT_CUE(9),
    ALERT_CUE(11),
    PORTRAIT_REP(0x0002, 0x00000004),
    MSG_NPC(2, _(" I don't think the human can\ncomplain about anything if we get\nrid of it.")),
    TEXTBOX_CLEAR,
    BGM_STOP,
    ALERT_CUE(7),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Isn't that right,\n{NAME_0}?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    AWAIT_CUE(5),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    CALL_LABEL(15),
    FANFARE_PLAY2(473),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    CLEAR_ARRAY(EVENT_LOCAL),
    ALERT_CUE(6),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Wha...{WAIT_PRESS} What?!{WAIT_PRESS}\nIt... It can't be!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    MSG_NPC(5, _(" Y-you...{WAIT_PRESS}\nYou were that human?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" Is that true?\nHey!")),
    TEXTBOX_CLEAR,
    BGM_SWITCH(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" W-w-whoa...{WAIT_PRESS}\nThis is, like...\nWe can explain...")),
    VARIANT_DEFAULT(_(" W-w-wait...{WAIT_PRESS}\nThis is, like...\nThere's a good explanation for...")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(11),
    ALERT_CUE(6),
    MSG_NPC(6, _(" We're not asking you.\nWe're asking {NAME_0}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(11),
    AWAIT_CUE(5),
    MSG_NPC(6, _(" Hey! {NAME_0}!\nSo what is it?!")),
    { 0x2e, 0x15,  0x0006, -0x00000002,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 6, _(" Are you really the human\nthat was in the legend?")),
    CHOICE(/* label */ 35, _("..................")),
    CHOICE(/* label */ 35, _("..................")),
    TEXTBOX_CLEAR,
    WAIT(10),
  LABEL(35), /* = 0x23 */
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_NPC(1, _(" {NAME_0}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" {NAME_0}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000001),
    MSG_NPC(2, _(" Kekekekekekeh!\nLooks like you have nothing to say\nin your defense, {NAME_0}!")),
    AWAIT_CUE(5),
    WAIT(15),
    ALERT_CUE(7),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" That's how it is, fellow\nPokémon.")),
    AWAIT_CUE(5),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    CALL_LABEL(15),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(60),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000001),
    MSG_NPC(2, _(" Let's get rid of\n{NAME_0} and regain peace.\nKekekekekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    CALL_LABEL(15),
    WAIT(60),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    CALL_LABEL(15),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Wh-what?")),
    VARIANT(/* == */  1, _(" E-everyone, hold up.\nWhat's with you?{WAIT_PRESS}\nWhat are you going to do?")),
    VARIANT_DEFAULT(_(" ...Wh-what?")),
    VARIANT_DEFAULT(_(" E-everyone, what's gotten\ninto you?{WAIT_PRESS}\nWhat are you going to do?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE(5, 2, DIRECTION_NORTH),
    WAIT(15),
    ROTATE(5, 1, DIRECTION_SOUTH),
    WAIT(15),
    ROTATE(5, 2, DIRECTION_EAST),
    { 0x62, 0x00,  0x004c, -0x00000008,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" {NAME_0}, forgive me!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    WAIT(20),
    ALERT_CUE(8),
    ALERT_CUE(6),
    { 0x8b, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(497),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    WAIT(60),
    SELECT_ANIMATION(2),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wah! What the...?!")),
    VARIANT_DEFAULT(_(" Wah! What are you doing?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Waaaaah!{WAIT_PRESS}\n{NAME_0}, run!")),
    TEXTBOX_CLEAR,
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x02,  0x000a,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(7),
    CALL_LABEL(15),
    WAIT(15),
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WALK_RELATIVE(768, -120, 0),
    WAIT(30),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Serves them right!\nKekekekeh!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
  LABEL(15), /* = 0x0f */
    ALERT_CUE(12),
    ALERT_CUE(13),
    ALERT_CUE(14),
    ALERT_CUE(15),
    ALERT_CUE(16),
    ALERT_CUE(17),
    RET_DIRECT,
    HALT,
};








































static const struct ScriptCommand s_gs1_g21_s0_lives1_dlg0[] = { /* 0x814a970 */
    DEBUGINFO_O(4726),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    WALK_RELATIVE(256, 80, 0),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 24, 0),
    WAIT(15),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(6),
    ROTATE(5, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    { 0x93, 0x0a,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_DIRECT(150, 54),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(15),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    AWAIT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(6),
  LABEL(0), /* = 0x00 */
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_SOUTH),
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    WAIT(15),
    WALK_RELATIVE(256, 16, 0),
    { 0x93, 0x05,  0x000a,  0x00000050,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(6),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    { 0x62, 0x00,  0x004c, -0x00000008, -0x00000008, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    ROTATE(2, 2, DIRECTION_NORTH),
    WAIT(15),
    { 0x62, 0x00,  0x004c, -0x00000008,  0x00000008, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x02,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    CALL_SCRIPT(SHOCK_FUNC),
    WALK_GRID(512, 55),
    ROTATE(2, 10, DIRECTION_EAST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(2, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WAIT(15),
    WALK_RELATIVE(768, -120, 0),
    HALT,
};

static const struct ScriptCommand s_gs1_g21_s0_lives2_dlg0[] = { /* 0x814aee0 */
    DEBUGINFO_O(4816),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_START_FUNC),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(7),
    { 0x93, 0x05,  0x000a,  0x0000004d,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(5, 10, DIRECTION_SOUTH),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(10, 10, DIRECTION_SOUTHWEST),
    SELECT_ANIMATION(2),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_START_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(6, 1, DIRECTION_WEST),
    WAIT(15),
    ROTATE(6, 2, DIRECTION_EAST),
    WAIT(15),
    ROTATE(6, 10, DIRECTION_SOUTH),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(5, 10, DIRECTION_SOUTHWEST),
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x004c,  0x00000000, -0x00000010, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(5, 10, DIRECTION_WEST),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs1_g21_s0_lives3_dlg0[] = { /* 0x814b1e0 */
    DEBUGINFO_O(4867),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WALK_GRID(256, 61),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x0a,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WALK_GRID(128, 62),
    WALK_GRID(128, 53),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(4),
    COND_EQUAL(0, /* to label */ 2),
    COND_EQUAL(1, /* to label */ 3),
    COND_EQUAL(2, /* to label */ 4),
    COND_EQUAL(3, /* to label */ 5),
  LABEL(2), /* = 0x02 */
    ROTATE(5, 10, DIRECTION_NORTH),
    JUMP_LABEL(6),
  LABEL(3), /* = 0x03 */
    ROTATE(5, 10, DIRECTION_NORTHEAST),
    JUMP_LABEL(6),
  LABEL(4), /* = 0x04 */
    ROTATE(5, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(6),
  LABEL(5), /* = 0x05 */
    ROTATE(5, 10, DIRECTION_EAST),
    JUMP_LABEL(6),
  LABEL(6), /* = 0x06 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    AWAIT_CUE(8),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ROTATE(5, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(8, 2, DIRECTION_NORTHWEST),
    ROTATE(8, 1, DIRECTION_NORTHEAST),
    ROTATE(8, 2, DIRECTION_NORTH),
    AWAIT_CUE(8),
    { 0x8b, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0080, -0x00000010,  0x00000010, NULL },
    WAIT(30),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(15),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g21_s0_lives4_dlg0[] = { /* 0x814b6a0 */
    DEBUGINFO_O(4946),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(9),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(4),
    COND_EQUAL(0, /* to label */ 3),
    COND_EQUAL(1, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 5),
    COND_EQUAL(3, /* to label */ 6),
  LABEL(3), /* = 0x03 */
    ROTATE(5, 10, DIRECTION_NORTH),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    ROTATE(5, 10, DIRECTION_SOUTHWEST),
    JUMP_LABEL(7),
  LABEL(5), /* = 0x05 */
    ROTATE(5, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    ROTATE(5, 10, DIRECTION_WEST),
    JUMP_LABEL(7),
  LABEL(7), /* = 0x07 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(9),
    { 0x93, 0x05,  0x000a,  0x00000050,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WALK_GRID(128, 57),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WALK_DIRECT(30, 55),
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x62, 0x00,  0x0080,  0x00000018,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(9),
    { 0x62, 0x00,  0x004c,  0x00000008,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(15),
    { 0x62, 0x00,  0x0300, -0x00000030,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs1_g21_s0_lives5_dlg0[] = { /* 0x814bad0 */
    DEBUGINFO_O(5017),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(10),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(15),
    WALK_GRID(204, 59),
    ALERT_CUE(5),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    SELECT_ANIMATION(4),
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x0002,  0x00000036,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000036,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    WALK_GRID(128, 60),
    WALK_GRID(128, 56),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(4),
    COND_EQUAL(0, /* to label */ 3),
    COND_EQUAL(1, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 5),
    COND_EQUAL(3, /* to label */ 6),
  LABEL(3), /* = 0x03 */
    ROTATE(5, 10, DIRECTION_EAST),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    ROTATE(5, 10, DIRECTION_SOUTHEAST),
    JUMP_LABEL(7),
  LABEL(5), /* = 0x05 */
    ROTATE(5, 10, DIRECTION_SOUTH),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    ROTATE(5, 10, DIRECTION_SOUTHWEST),
    JUMP_LABEL(7),
  LABEL(7), /* = 0x07 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    AWAIT_CUE(10),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x004c, -0x00000008,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x62, 0x00,  0x004c,  0x00000000,  0x00000008, NULL },
    AWAIT_CUE(10),
    ROTATE(5, 1, DIRECTION_WEST),
    WAIT(15),
    { 0x62, 0x00,  0x0200, -0x00000008,  0x00000008, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs1_g21_s0_lives6_dlg0[] = { /* 0x814bfb0 */
    DEBUGINFO_O(5099),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x93, 0x02,  0x000a,  0x00000022,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    CALL_SCRIPT(ANGRY_END_FUNC),
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    WALK_GRID(128, 52),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(11),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(4),
    COND_EQUAL(0, /* to label */ 3),
    COND_EQUAL(1, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 5),
    COND_EQUAL(3, /* to label */ 6),
  LABEL(3), /* = 0x03 */
    ROTATE(5, 10, DIRECTION_NORTH),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    ROTATE(5, 10, DIRECTION_NORTHEAST),
    JUMP_LABEL(7),
  LABEL(5), /* = 0x05 */
    ROTATE(5, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    ROTATE(5, 10, DIRECTION_WEST),
    JUMP_LABEL(7),
  LABEL(7), /* = 0x07 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    WAIT(30),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    WALK_RELATIVE(76, -24, 0),
    { 0x8b, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(7),
    AWAIT_CUE(11),
    { 0x62, 0x00,  0x004c, -0x00000008,  0x00000000, NULL },
    AWAIT_CUE(11),
    ROTATE(5, 2, DIRECTION_WEST),
    WAIT(15),
    { 0x62, 0x00,  0x0200, -0x00000008, -0x00000008, NULL },
    HALT,
};


static const struct ScriptCommand s_gs1_g21_s0_lives7_dlg0[] = { /* 0x814c4b0 */
    DEBUGINFO_O(5183),
    SELECT_ANIMATION(2),
    AWAIT_CUE(12),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(12),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(6, 2, DIRECTION_SOUTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(6, 1, DIRECTION_WEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_LABEL(2),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_LABEL(2),
    WALK_RELATIVE(128, -64, -8),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_LABEL(2),
    WALK_RELATIVE(768, -16, 8),
    AWAIT_CUE(12),
  LABEL(2), /* = 0x02 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g21_s0_lives8_dlg0[] = { /* 0x814c770 */
    DEBUGINFO_O(5230),
    SELECT_ANIMATION(2),
    AWAIT_CUE(13),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(13),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(6, 1, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(6, 2, DIRECTION_WEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_LABEL(2),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_LABEL(2),
    WALK_RELATIVE(128, -24, -8),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_LABEL(2),
    { 0x62, 0x00,  0x0300, -0x00000008,  0x00000000, NULL },
    AWAIT_CUE(13),
  LABEL(2), /* = 0x02 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g21_s0_lives9_dlg0[] = { /* 0x814ca30 */
    DEBUGINFO_O(5277),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(14),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    { 0x62, 0x00,  0x0080,  0x00000000, -0x00000010, NULL },
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    { 0x62, 0x00,  0x0080,  0x00000000,  0x00000010, NULL },
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(2), /* = 0x02 */
    { 0x62, 0x00,  0x0080,  0x00000000,  0x00000010, NULL },
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_LABEL(3),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_LABEL(3),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_LABEL(3),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_LABEL(3),
    WALK_RELATIVE(128, -32, 0),
    WALK_RELATIVE(128, -32, 24),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(14),
    CALL_LABEL(3),
    { 0x62, 0x00,  0x0100, -0x00000020,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(14),
  LABEL(3), /* = 0x03 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g21_s0_lives10_dlg0[] = { /* 0x814cd40 */
    DEBUGINFO_O(5329),
    SELECT_ANIMATION(2),
    AWAIT_CUE(15),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(15),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    SELECT_ANIMATION(3),
    { 0x70, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(15),
    CALL_LABEL(2),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(15),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(15),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(15),
    CALL_LABEL(2),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(15),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(15),
  LABEL(2), /* = 0x02 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g21_s0_lives11_dlg0[] = { /* 0x814cfe0 */
    DEBUGINFO_O(5374),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(16),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(16),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(15),
    { 0x93, 0x04,  0x000a,  0x00000047,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    AWAIT_CUE(16),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(16),
    CALL_LABEL(0),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(16),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(16),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(16),
    WAIT(15),
    WALK_RELATIVE(76, -24, -16),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(16),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x00000047,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(16),
  LABEL(0), /* = 0x00 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g21_s0_lives12_dlg0[] = { /* 0x814d270 */
    DEBUGINFO_O(5418),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(17),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(17),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(15),
    { 0x93, 0x04,  0x000a,  0x00000046,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    AWAIT_CUE(17),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(17),
    CALL_LABEL(0),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(17),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(17),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(17),
    WAIT(30),
    WALK_RELATIVE(76, -16, -8),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(17),
    CALL_LABEL(0),
    { 0x93, 0x04,  0x000a,  0x00000046,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(17),
  LABEL(0), /* = 0x00 */
    WAIT_RANDOM(0, 30),
    RET_DIRECT,
    RET,
};

static const struct ScriptCommand s_gs1_g22_s0_station_sref_script[] = { /* 0x814d4f0 */
    DEBUGINFO_O(5461),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g22_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g22_s0_station_sref_script }; /* 0x814d520 */

static const struct ScriptCommand s_gs1_g22_s0_lives0_dlg1[] = { /* 0x814d52c */
    DEBUGINFO_O(5469),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives0_dlg2[] = { /* 0x814d54c */
    DEBUGINFO_O(5474),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives0_dlg3[] = { /* 0x814d5cc */
    DEBUGINFO_O(5485),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g22_s0_lives1_dlg1[] = { /* 0x814d5fc */
    DEBUGINFO_O(5491),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives1_dlg2[] = { /* 0x814d61c */
    DEBUGINFO_O(5496),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives1_dlg3[] = { /* 0x814d69c */
    DEBUGINFO_O(5507),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g22_s0_lives2_dlg1[] = { /* 0x814d6cc */
    DEBUGINFO_O(5513),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives2_dlg2[] = { /* 0x814d6ec */
    DEBUGINFO_O(5518),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives2_dlg3[] = { /* 0x814d76c */
    DEBUGINFO_O(5529),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g22_s0_lives3_dlg1[] = { /* 0x814d79c */
    DEBUGINFO_O(5535),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives3_dlg2[] = { /* 0x814d7bc */
    DEBUGINFO_O(5540),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives3_dlg3[] = { /* 0x814d83c */
    DEBUGINFO_O(5551),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g22_s0_lives4_dlg1[] = { /* 0x814d86c */
    DEBUGINFO_O(5557),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives4_dlg2[] = { /* 0x814d88c */
    DEBUGINFO_O(5562),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives4_dlg3[] = { /* 0x814d90c */
    DEBUGINFO_O(5573),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g22_s0_lives5_dlg1[] = { /* 0x814d93c */
    DEBUGINFO_O(5579),
    JUMP_SCRIPT(MOVE_SLEEP),
};

static const struct ScriptCommand s_gs1_g22_s0_lives5_dlg2[] = { /* 0x814d95c */
    DEBUGINFO_O(5584),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT, 0x0000, 0x00000000),
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g22_s0_lives5_dlg3[] = { /* 0x814d9dc */
    DEBUGINFO_O(5595),
    SELECT_ANIMATION(6),
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs1_g23_s0_station_sref_script[] = { /* 0x814da0c */
    DEBUGINFO_O(5601),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(1),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}Meanwhile, back in\n{CENTER_ALIGN}Pokémon Square...")),
    TEXTBOX_CLEAR,
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs1_g23_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g23_s0_station_sref_script }; /* 0x814db38 */


static const struct ScriptCommand s_gs1_g23_s0_eff0_script[] = { /* 0x814db44 */
    DEBUGINFO_O(5623),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    CAMERA_INIT_PAN,
    { 0x89, 0x20,  0x0100,  0x00000006,  0x00000000, NULL },
    AWAIT_CUE(4),
    { 0x89, 0x1c,  0x0100,  0x00000002,  0x00000000, NULL },
    AWAIT_CUE(4),
    { 0x89, 0x40,  0x0099,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g23_s0_lives0_dlg0[] = { /* 0x814dc14 */
    DEBUGINFO_O(5639),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(472),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Kekeh!\nYou lot!")),
    MSG_NPC(2, _(" Why aren't you out there\nhunting down {NAME_0}'s team?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(8),
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000000),
    MSG_NPC(4, _(" That's easy for you to say...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(10),
    MSG_NPC(4, _(" It's too much for us...")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" They say {NAME_0}'s\nteam has gone way far out there.")),
    MSG_NPC(5, _(" If we went, the best we\ncould hope for is maybe the Lapis Cave.")),
    TEXTBOX_CLEAR,
    WAIT(4),
    ALERT_CUE(8),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, -1, 0),
    MSG_NPC(3, _(" I joined the chase...")),
    MSG_NPC(3, _(" But they fled into Mt. Blaze.")),
    MSG_NPC(3, _(" For the life of me, I can't\ngo in there.\nAnd that's where I lost their trail.")),
    MSG_NPC(3, _(" I'm a Grass type, see.{WAIT_PRESS}\nFire doesn't agree with me at all.")),
    MSG_NPC(3, _(" I don't know what became\nof {NAME_0}'s team after that.")),
    MSG_NPC(3, _(" ...But those fugitives...\nTo think they would risk Mt. Blaze...")),
    MSG_NPC(3, _(" They've grown up tough!\nI can't keep up!")),
    ALERT_CUE(8),
    PORTRAIT_REP(0x0003, 0x00000042),
    MSG_NPC(3, _(" Hahaha!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP, 0x0002, 0x00000043),
    MSG_NPC(2, _(" Kekeh!\nWhat a spineless lot you are!\nTch!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000041),
    MSG_NPC(4, _(" You're so full of big talk!\nWhat about your team, Gengar?")),
    MSG_NPC(4, _(" You just hang around in the\nsquare and don't do a thing.")),
    MSG_NPC(4, _(" Walk the talk.\nYou guys go.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" We're out of that picture.\nKekeh!")),
    MSG_NPC(2, _(" Our role is to receive word\nabout {NAME_0}'s demise.\nKekekekekeh!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT_REP(0x0004, 0x00000000),
    MSG_NPC(4, _(" Tch!\nJust appointed yourself that...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" Oh, my gosh! Oh, my goodness!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(13),
    WAIT(15),
    ALERT_CUE(12),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" {NAME_7}, what's\nthe word?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(12),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0007, 0x00000042),
    MSG_NPC(7, _(" {NAME_0}...\n{NAME_0} is...")),
    TEXTBOX_CLEAR,
    WAIT(4),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" Oh! Finally!\nWe're finally rid of {NAME_0}!\nKekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(12),
    PORTRAIT_REP(0x0007, 0x00000045),
    MSG_NPC(7, _(" No!{WAIT_PRESS}\nIt's the opposite!")),
    MSG_NPC(7, _(" {NAME_0} is back!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(463),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000046),
    MSG_NPC(2, _(" Kekeh?!\nWhat did you say?!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(12),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    WAIT(50),
    ALERT_CUE(6),
    ALERT_CUE(16),
    WALK_GRID(256, 63),
    AWAIT_CUE(5),
    WAIT(30),
    FANFARE_PLAY2(465),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000042),
    PORTRAIT_POS(3, 0, -1),
    MSG_NPC(3, _(" H-hey! Over there...")),
    WAIT(4),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0006, 0x00000042),
    PORTRAIT_POS(6, -2, 0),
    MSG_NPC(6, _(" ...{NAME_0}!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000000),
    PORTRAIT_POS(5, 1, 0),
    MSG_NPC(5, _(" Th-they're back...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(6),
    ALERT_CUE(16),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WALK_GRID(256, 64),
    AWAIT_CUE(5),
    WAIT(30),
    BGM_SWITCH(7),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000001),
    MSG_NPC(1, _(" Hi, everyone!\nWe're back!")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Whew!\nWe finally made it back.\nWe've been gone for so long...")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's good to be back in the\nsquare again, {NAME_0}.")),
    VARIANT_DEFAULT(_(" It feels kind of nostalgic\nto be back in the square, {NAME_0}.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Hey, {NAME_1}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000003),
    { 0x93, 0x01,  0x000b,  0x0000005b,  0x00000000, NULL },
    MSG_NPC(1, _(" Hm! Oh, it's you,\n{NAME_2}.\nIt's been a while.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0002, 0x00000044),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" (Kekeh! What's with that\nsmug confidence?)") },
    ALERT_CUE(7),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" (Kekeh! Maybe...)\n") },
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_2}!{WAIT_PRESS}\nYou spewed all sorts of trumped up\ngarbage, didn't you?!")),
    VARIANT(/* == */  1, _(" {NAME_0} had nothing to\ndo with it!")),
    VARIANT(/* == */  1, _(" {NAME_0} was innocent!")),
    VARIANT_DEFAULT(_(" {NAME_2}!{WAIT_PRESS}\nEverything you said was completely\nwrong!")),
    VARIANT_DEFAULT(_(" {NAME_0} had nothing to\ndo with it!")),
    VARIANT_DEFAULT(_(" {NAME_0} was innocent!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(463),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT_REP(0x0002, 0x00000046),
    MSG_NPC(2, _(" Ugege?!")),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, 1, 0),
    MSG_NPC(4, _(" Wh-what?!")),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000042),
    PORTRAIT_POS(3, -1, 0),
    MSG_NPC(3, _(" Is that true?!")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You bet.\nWe met Ninetales and found out.")),
    VARIANT(/* == */  1, _(" {NAME_0} isn't the human\nfrom that legend.")),
    VARIANT(/* == */  1, _(" We came back when we\nfound that out.")),
    VARIANT_DEFAULT(_(" Yup.\nWe met Ninetales and asked.")),
    VARIANT_DEFAULT(_(" {NAME_0} isn't the human\nfrom the legend.")),
    VARIANT_DEFAULT(_(" We're back because we\ndiscovered the truth.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Ugegegegegegegeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    WAIT(60),
    FANFARE_PLAY2(470),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Kekeh! W-wait a second!{WAIT_PRESS}\nYou can't be trusted yet.")),
    MSG_NPC(2, _(" If you're going to make that\nclaim, let's see some proof.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_NPC(1, _(" P-proof?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    WAIT(45),
    PORTRAIT_REP(0x0002, 0x00000041),
    MSG_NPC(2, _(" That's right.\nSome hard evidence! Kekeh!")),
    MSG_NPC(2, _(" Let's see some proof!\nCome on, out with it!")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_NPC(1, _(" Proof...{WAIT_PRESS}\nWe don't have any proof...")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(470),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Kekekekekekeh!{WAIT_PRESS}\nIt's too bad you don't have proof!")),
    MSG_NPC(2, _(" You came back for us so\nwe could get rid of you easier!\nHow conveniently foolish! Kekekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" Now, fellow Pokémon.{WAIT_PRESS}\nHere's your chance to get rid of\n{NAME_0}! Kekekekekeh!")),
    TEXTBOX_CLEAR,
    WAIT(90),
    FANFARE_PLAY2(468),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WAIT(180),
    PORTRAIT_REP(0x0002, 0x00000044),
    MSG_NPC(2, _(" ............{WAIT_PRESS}Kekeh?!{WAIT_PRESS}\nWhat's wrong, everyone?\nDon't you want to be rid of {NAME_0}?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(11),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE(4, 11, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_LEFT_, 0x0006, 0x00000000),
    MSG_NPC(6, _(" I...{WAIT_PRESS}\nI always believed in {NAME_0}!")),
    ALERT_CUE(11),
    MSG_NPC(6, _(" You don't fool me!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(468),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000046),
    MSG_NPC(2, _(" Ugeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0003, 0x00000000),
    MSG_NPC(3, _(" ...I...\nI'm out.")),
    MSG_NPC(3, _(" I was saved by\n{NAME_0}'s team before.")),
    MSG_NPC(3, _(" I joined the chase with a\nheavy heart because of your urging...")),
    MSG_NPC(3, _(" But I simply can't think\nof {NAME_0} being bad in any way.")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(455),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0002, 0x00000046),
    MSG_NPC(2, _(" Ugegegeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000041),
    MSG_NPC(4, _(" I've heard enough too!\nI believe {NAME_0}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" Yeah, that's right!\nWho needs proof?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WAIT(60),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000046),
    MSG_NPC(2, _(" Ugegegegegege!")),
    TEXTBOX_CLEAR,
    WAIT(45),
    PORTRAIT_REP(0x0001, 0x00000008),
    MSG_NPC(1, _(" E-everyone...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    SELECT_ENTITIES(-1, 1),
    ALERT_CUE(6),
    ALERT_CUE(16),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(13),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(15),
    WAIT(15),
    TEXTBOX_AUTO_PRESS(210, 210),
    { 0x2e, 0x03,  0x0009, -0x00000002,  0x00000000, NULL },
    MSG_NPC(9, _(" Extra! Extra!\nRead all about it!")),
    TEXTBOX_CLEAR2,
    TEXTBOX_AUTO_PRESS(-1, -1),
    ROTATE(10, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(5),
    WAIT(20),
    ROTATE(8, 10, DIRECTION_EAST),
    AWAIT_CUE(5),
    WAIT(90),
    FANFARE_PLAY2(468),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0008, 0x00000000),
    MSG_NPC(8, _(" What?\nWhat is this?")),
    TEXTBOX_CLEAR,
    WAIT(4),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0007, 0x00000000),
    MSG_NPC(7, _(" ......{WAIT_PRESS}\nIt looks like a newspaper...\nDoesn't it?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" OK, I'll read it aloud.\nLet's see...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(30),
    MSG_LETTER(_("{CENTER_ALIGN}<Pokémon News>\n{CENTER_ALIGN}= EXTRA =")),
    MSG_LETTER(_("{CENTER_ALIGN} \n{CENTER_ALIGN}{NAME_0} Innocent!")),
    MSG_LETTER(_("{CENTER_ALIGN}{NAME_0} met with Ninetales under\n{CENTER_ALIGN}the watchful eye of Alakazam...")),
    MSG_LETTER(_("{CENTER_ALIGN}...And proved that it had nothing to\n{CENTER_ALIGN}do with the human in the legend.")),
    MSG_LETTER(_("{CENTER_ALIGN}As a result, Gengar's claims were\n{CENTER_ALIGN}found to be malicious lies.")),
    MSG_LETTER(_("{CENTER_ALIGN}-End-")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(470),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WAIT(30),
    MSG_NPC(2, _(" Ugegegegegegegegegegegeh!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0004, 0x00000041),
    PORTRAIT_POS(4, 2, 0),
    MSG_NPC(4, _(" You rotten...")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(455),
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WAIT(30),
    MSG_NPC(2, _(" Gegegeh!\nR-run!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(12),
    ALERT_CUE(13),
    WAIT(10),
    ALERT_CUE(6),
    ALERT_CUE(16),
    ROTATE(4, 11, DIRECTION_NORTH),
    WAIT(80),
    FANFARE_PLAY2(471),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Stop, you liar!\nYou conned us!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    WAIT(180),
    ALERT_CUE(4),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(16),
    { 0x93, 0x08,  0x000b,  0x00000036,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" Welcome back!")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000009),
    MSG_NPC(1, _(" Yup! It's good to be back!{WAIT_PRESS}\nWe're back like we promised.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0006, 0x00000042),
    MSG_NPC(6, _(" ...Sniffle...")),
    MSG_NPC(6, _(" I'm so glad...{WAIT_PRESS}\n{NAME_0} isn't suspected anymore...")),
    TEXTBOX_CLEAR,
    MSG_NPC(1, _(" Yup, I'm glad too.")),
    MSG_NPC(1, _(" We won't have to keep\nrunning from everyone anymore.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right, {NAME_0}.")),
    VARIANT(/* == */  1, _(" We're both worn out.\nI'm going to get some sleep.")),
    VARIANT(/* == */  1, _(" Our rescue team is back\nin business tomorrow!{WAIT_PRESS}\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" {NAME_0}.")),
    VARIANT_DEFAULT(_(" We're both exhausted.\nI'm going to get some sleep.")),
    VARIANT_DEFAULT(_(" Our rescue team gets\nrevived tomorrow!{WAIT_PRESS}\nLet's try to do our best!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};













































static const struct ScriptCommand s_gs1_g23_s0_lives1_dlg0[] = { /* 0x8150a08 */
    DEBUGINFO_O(6162),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 65),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_GRID(256, 66),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(SWEAT_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x00000036,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(210),
    ROTATE(10, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(12, 10, DIRECTION_NORTH),
    WAIT(45),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(4, 11, DIRECTION_NORTH),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000036,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives2_dlg0[] = { /* 0x8150cb8 */
    DEBUGINFO_O(6208),
    SELECT_ANIMATION(2),
    AWAIT_CUE(16),
    WALK_GRID(256, 67),
    AWAIT_CUE(16),
    WALK_GRID(256, 68),
    AWAIT_CUE(16),
    WAIT(220),
    ROTATE(12, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(16),
    WAIT(45),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(16),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(16),
    WAIT(5),
    { 0x93, 0x08,  0x000a,  0x00000036,  0x00000000, NULL },
    AWAIT_CUE(16),
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives3_dlg0[] = { /* 0x8150de8 */
    DEBUGINFO_O(6230),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    AWAIT_CUE(7),
    WAIT(6),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(ANGRY_END_FUNC),
    FANFARE_PLAY2(472),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x08,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000b,  0x0000005d,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(65),
    WALK_GRID(153, 72),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    AWAIT_CUE(7),
    { 0x89, 0x08,  0x0100,  0x00000007,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0x7e, 0x00,  0x0100,  0x00000008, -0x00000008, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 11, DIRECTION_SOUTH),
    WAIT(15),
    ROTATE(4, 11, DIRECTION_SOUTHEAST),
    WAIT(30),
    ROTATE(4, 11, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(QUESTION_FUNC),
    WAIT(1),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x08,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(180),
    ROTATE(12, 10, DIRECTION_NORTH),
    AWAIT_CUE(7),
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    WAIT(20),
    { 0x62, 0x00,  0x0100,  0x00000000, -0x0000000c, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(7),
    { 0x89, 0x40,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives4_dlg0[] = { /* 0x81513c8 */
    DEBUGINFO_O(6327),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(10),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(8),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x0000005d,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(140),
    ROTATE(10, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    WAIT(15),
    ROTATE(10, 10, DIRECTION_NORTH),
    WAIT(20),
    ROTATE(10, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    { 0x89, 0x10,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 11, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x89, 0x38,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives5_dlg0[] = { /* 0x81516e8 */
    DEBUGINFO_O(6380),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000b,  0x00000050,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(ANGRY_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WAIT(2),
    { 0x93, 0x3c,  0x000b,  0x0000005d,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(2),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(62),
    WALK_GRID(153, 71),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(2),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(9),
    WAIT(5),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(8),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(160),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(9),
    WAIT(12),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_NORTH),
    AWAIT_CUE(9),
    { 0x89, 0x30,  0x0099,  0x00000004,  0x00000000, NULL },
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    ALERT_CUE(17),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    SELECT_ANIMATION(2),
    ROTATE(4, 10, DIRECTION_NORTH),
    FANFARE_PLAY2(471),
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(45),
    CALL_SCRIPT(ANGRY_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WAIT(10),
    { 0x89, 0x38,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives6_dlg0[] = { /* 0x8151b48 */
    DEBUGINFO_O(6453),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(5),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(2),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(6),
    ROTATE(4, 11, DIRECTION_WEST),
    WAIT(60),
    ROTATE(4, 11, DIRECTION_NORTHWEST),
    AWAIT_CUE(10),
    WAIT(8),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(10),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(8),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(150),
    ROTATE(12, 10, DIRECTION_NORTH),
    AWAIT_CUE(10),
    { 0x89, 0x06,  0x0100,  0x00000005,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    WAIT(20),
    { 0x89, 0x38,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives7_dlg0[] = { /* 0x8151e18 */
    DEBUGINFO_O(6501),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    WAIT(8),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    ROTATE(4, 11, DIRECTION_WEST),
    WAIT(45),
    ROTATE(4, 11, DIRECTION_NORTH),
    AWAIT_CUE(11),
    WAIT(8),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    WAIT(60),
    WALK_GRID(153, 69),
    ROTATE(4, 11, DIRECTION_NORTHWEST),
    AWAIT_CUE(11),
    WAIT(5),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(11),
    WAIT(2),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    WAIT(2),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    { 0x89, 0x08,  0x0100,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(200),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(11),
    WAIT(13),
    ROTATE(10, 10, DIRECTION_NORTHEAST),
    WAIT(10),
    ROTATE(10, 10, DIRECTION_NORTH),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(11),
    { 0x89, 0x08,  0x0080,  0x00000003,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x89, 0x18,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0x89, 0x05,  0x0080,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives8_dlg0[] = { /* 0x81521a8 */
    DEBUGINFO_O(6561),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    WALK_GRID(512, 73),
    ALERT_CUE(5),
    AWAIT_CUE(12),
    { 0x93, 0x04,  0x000b,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(12),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(12),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(12),
    WAIT(55),
    WALK_GRID(153, 74),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    WAIT(5),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(12),
    WAIT(2),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(12),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(12),
    ROTATE(4, 11, DIRECTION_EAST),
    WAIT(45),
    ROTATE(4, 11, DIRECTION_SOUTH),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    AWAIT_CUE(12),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(12),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(12),
    ROTATE(4, 11, DIRECTION_SOUTHEAST),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(12),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(12),
    WAIT(30),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(230),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT(120),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(12),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(12),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(12),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x40,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s0_lives9_dlg0[] = { /* 0x81525b8 */
    DEBUGINFO_O(6629),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x0000005d,  0x00000000, NULL },
    WAIT(45),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    AWAIT_CUE(13),
    WAIT(5),
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(13),
    WAIT(45),
    ROTATE(4, 11, DIRECTION_SOUTHWEST),
    AWAIT_CUE(13),
    { 0x93, 0x08,  0x000b,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(13),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(13),
    ROTATE(4, 11, DIRECTION_WEST),
    WAIT(45),
    ROTATE(4, 11, DIRECTION_SOUTH),
    WAIT(10),
    CALL_SCRIPT(QUESTION_FUNC),
    AWAIT_CUE(13),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(13),
    ROTATE(4, 11, DIRECTION_SOUTHEAST),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000b,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(13),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(13),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(215),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(13),
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE(10, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(13),
    ROTATE(4, 11, DIRECTION_SOUTHEAST),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(13),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(13),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(13),
    WAIT(15),
    { 0x89, 0x40,  0x0200,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g23_s1_lives0_dlg0[] = { /* 0x8152988 */
    DEBUGINFO_O(6693),
    { 0x2d, 0x07,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x8b, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x8b, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    FANFARE_STOP2(451),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g23_s1_eff0_script[] = { /* 0x8152a68 */
    DEBUGINFO_O(6710),
    AWAIT_CUE(15),
    WAIT(344),
    ALERT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(16),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(11),
    ALERT_CUE(13),
    ALERT_CUE(17),
    { 0x56, 0x00,  0x0000,  0x00000065,  0x00000000, NULL },
    WAIT(288),
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000066,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(15),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g23_s1_eff1_script[] = { /* 0x8152ba8 */
    DEBUGINFO_O(6733),
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    AWAIT_CUE(17),
    WAIT(328),
    { 0x56, 0x00,  0x0000,  0x000001be,  0x00000000, NULL },
    AWAIT_CUE(17),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g24_s0_station_sref_script[] = { /* 0x8152c28 */
    DEBUGINFO_O(6744),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g24_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g24_s0_station_sref_script }; /* 0x8152c68 */

static const struct ScriptCommand s_gs1_g24_s0_lives0_dlg2[] = { /* 0x8152c74 */
    DEBUGINFO_O(6753),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  0,  1),
    MSG_NPC(1, _(" I'm so sorry.")),
    MSG_NPC(1, _(" I was fully convinced of\nyour guilt, {NAME_0}.")),
    MSG_NPC(1, _(" But I am glad to hear\nyou are free from that cloud of\nsuspicion〜♪")),
    MSG_NPC(1, _(" I'll never give you my\nbusiness again!{WAIT_PRESS}\nI hope you won't say that.")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives1_dlg2[] = { /* 0x8152e2c */
    DEBUGINFO_O(6770),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  1,  1),
    EXECUTE_STATION(-1, 24, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives2_dlg2[] = { /* 0x8152edc */
    DEBUGINFO_O(6784),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  2,  1),
    MSG_NPC(1, _(" I do apologize.{WAIT_PRESS}\nHow could one run a bank without\ntrusting clients?")),
    MSG_NPC(1, _(" I promise to satisfy all\nyour banking needs from now on.\nI hope you'll stay.")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives3_dlg2[] = { /* 0x8153034 */
    DEBUGINFO_O(6799),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  3,  1),
    MSG_NPC(1, _(" I doubted you too!\nI do so apologize!")),
    MSG_NPC(1, _(" If you could wipe the slate\nclean, I will do my best to serve your\nlinking needs!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives4_dlg2[] = { /* 0x8153174 */
    DEBUGINFO_O(6814),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  4,  1),
    MSG_NPC(1, _(" I expected this.")),
    MSG_NPC(1, _(" I thought there had to\nbe a mistake.")),
    MSG_NPC(1, _(" I mean, look at you.\nYou don't look like the sort who can be\nup to no good.")),
    MSG_NPC(1, _(" I'll keep looking after your\nthings, dears! You can always count on me!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives5_dlg2[] = { /* 0x8153334 */
    DEBUGINFO_O(6831),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  5,  1),
    MSG_NPC(1, _(" I believed in you,\n{NAME_0}!")),
    MSG_NPC(1, _(" Because you're my friend!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives6_dlg1[] = { /* 0x8153430 */
    DEBUGINFO_O(6846),
    { 0x51, 0x00,  0x004f,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s0_lives6_dlg2[] = { /* 0x8153470 */
    DEBUGINFO_O(6853),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We got conned by Gengar...{WAIT_PRESS}\nI'm sorry.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives7_dlg1[] = { /* 0x81534fc */
    DEBUGINFO_O(6862),
    { 0x51, 0x00,  0x004e,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s0_lives7_dlg2[] = { /* 0x815353c */
    DEBUGINFO_O(6869),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm truly sorry for what\nhappened.{WAIT_PRESS}\nSorry for suspecting you.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives8_dlg1[] = { /* 0x81535e0 */
    DEBUGINFO_O(6878),
    { 0x51, 0x00,  0x004d,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_RANDOM),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s0_lives8_dlg2[] = { /* 0x8153620 */
    DEBUGINFO_O(6885),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" ...So, what became of\nAlakazam's team?\nDid they head underground?")),
    MSG_NPC(1, _(" Groudon...{WAIT_PRESS}\nThe mythical Pokémon...")),
    MSG_NPC(1, _(" It is rather worrying...{WAIT_PRESS}\nBut I suppose it is Alakazam's team.\nThey should be fine.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s0_lives9_dlg2[] = { /* 0x8153768 */
    DEBUGINFO_O(6896),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Aww. No...\nI thought you were completely guilty.")),
    MSG_NPC(1, _(" I'm sorry you had to go\nthrough such a miserable time.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s1_station_sref_script[] = { /* 0x8153848 */
    DEBUGINFO_O(6906),
    SELECT_LIVES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g24_s1_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g24_s1_station_sref_script }; /* 0x8153888 */

static const struct ScriptCommand s_gs1_g24_s1_lives0_dlg0[] = { /* 0x8153894 */
    DEBUGINFO_O(6915),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" I am so sorry!")),
    MSG_NPC(3, _(" I was convinced that\n{NAME_0} had to be the one.")),
    MSG_NPC(3, _(" I'm very ashamed that I\ntreated a valuable customer with such\ndisdain and suspicion...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" It isn't just you, my brother.{WAIT_PRESS}\nI am guilty of the same.")),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" B-Brother...{WAIT_PRESS}\nSniffle... My brother...")),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" We both promise, we will\nnot repeat the same mistake.")),
    MSG_NPC(3, _(" I will do my best to obtain\neven better Technical Machines and Orbs.\nI hope for your continued patronage!")),
    ALERT_CUE(3),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    TEXTBOX_CLEAR,
    SELECT_LIVES(-1, 0),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s1_lives1_dlg0[] = { /* 0x8153bf4 */
    DEBUGINFO_O(6945),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g24_s1_lives2_dlg0[] = { /* 0x8153c34 */
    DEBUGINFO_O(6952),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s1_lives2_dlg2[] = { /* 0x8153cd4 */
    DEBUGINFO_O(6965),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  0,  1),
    MSG_NPC(1, _(" I'm so sorry.")),
    MSG_NPC(1, _(" I was fully convinced of\nyour guilt, {NAME_0}.")),
    MSG_NPC(1, _(" But I am glad to hear\nyou are free from that cloud of\nsuspicion〜♪")),
    MSG_NPC(1, _(" I'll never give you my\nbusiness again!{WAIT_PRESS}\nI hope you won't say that.")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g24_s1_lives3_dlg0[] = { /* 0x8153db4 */
    DEBUGINFO_O(6982),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    RET,
};

static const struct ScriptCommand s_gs1_g24_s1_lives3_dlg2[] = { /* 0x8153e64 */
    DEBUGINFO_O(6996),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_2N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_2N,  1,  1),
    EXECUTE_STATION(-1, 24, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_station_sref_script[] = { /* 0x8153f14 */
    DEBUGINFO_O(7010),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g25_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g25_s0_station_sref_script }; /* 0x8153f54 */

static const struct ScriptCommand s_gs1_g25_s0_lives0_dlg2[] = { /* 0x8153f60 */
    DEBUGINFO_O(7019),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives1_dlg2[] = { /* 0x8153fc0 */
    DEBUGINFO_O(7028),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives2_dlg2[] = { /* 0x8154020 */
    DEBUGINFO_O(7037),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives3_dlg2[] = { /* 0x8154080 */
    DEBUGINFO_O(7046),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives4_dlg2[] = { /* 0x81540e0 */
    DEBUGINFO_O(7055),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives5_dlg2[] = { /* 0x8154140 */
    DEBUGINFO_O(7064),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives6_dlg1[] = { /* 0x81541a0 */
    DEBUGINFO_O(7073),
    { 0x51, 0x00,  0x0052,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g25_s0_lives6_dlg2[] = { /* 0x81541e0 */
    DEBUGINFO_O(7080),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" That quake was\nsomething else!")),
    MSG_NPC(1, _(" It caught me by surprise.\nI almost drowned in the pond!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives7_dlg1[] = { /* 0x81542ac */
    DEBUGINFO_O(7090),
    { 0x51, 0x00,  0x0051,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g25_s0_lives7_dlg2[] = { /* 0x81542ec */
    DEBUGINFO_O(7097),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, wasn't it shocking?!")),
    MSG_NPC(1, _(" That earthquake was\nterrible!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives8_dlg1[] = { /* 0x815439c */
    DEBUGINFO_O(7107),
    { 0x51, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_RANDOM),
    RET,
};

static const struct ScriptCommand s_gs1_g25_s0_lives8_dlg2[] = { /* 0x81543dc */
    DEBUGINFO_O(7114),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" What's that?\nHas Alakazam's team returned?")),
    MSG_NPC(1, _(" I'm not sure...{WAIT_PRESS}\nI haven't seen them around the square.")),
    MSG_NPC(1, _(" I don't think Alakazam's\nteam has come back.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g25_s0_lives9_dlg2[] = { /* 0x8154500 */
    DEBUGINFO_O(7125),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" That earthquake here\nwas wicked...")),
    MSG_NPC(1, _(" If it can happen here,\nwill more serious natural disasters\ncome to the square?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g26_s0_station_sref_script[] = { /* 0x81545e8 */
    DEBUGINFO_O(7135),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_STOP,
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g26_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g26_s0_station_sref_script }; /* 0x8154678 */

static const struct ScriptCommand s_gs1_g26_s0_eff0_script[] = { /* 0x8154684 */
    DEBUGINFO_O(7149),
    { 0x59, 0x00, -0x0040,  0x00000000,  0x00000000, NULL },
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WALK_RELATIVE(256, 64, 0),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_RELATIVE(256, -64, 0),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_RELATIVE(256, 64, 0),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_RELATIVE(256, -64, 0),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g26_s0_lives0_dlg0[] = { /* 0x8154794 */
    DEBUGINFO_O(7169),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0008,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0009,  0x00000067,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(7),
    WALK_GRID(256, 83),
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Wow!\nLook at all the Pokémon!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Looks like they sent out\nto a lot of rescue teams for help.")),
    MSG_NPC(2, _(" I've seen some pretty\nfamous leaders from faraway places.")),
    MSG_NPC(2, _(" That {NAME_3}...\nI wonder what he's planning to do with\nall these rescue teams?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(60),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, 0, -1),
    MSG_NPC(3, _(" Can I get everyone's\nattention here?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(3, _(" I, uh...{WAIT_PRESS}\nIt's not my style to get up in front of\neveryone like this, and...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(3, _(" ...Sorry.\nThis isn't the time for that!")),
    BGM_SWITCH(10),
    PORTRAIT_REP(0x0003, 0x00000001),
    MSG_NPC(3, _(" There's big trouble!{WAIT_PRESS}\n{NAME_8}'s team went underground...")),
    MSG_NPC(3, _(" But they haven't returned!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(20),
    FANFARE_PLAY2(473),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    WAIT(90),
    MSG_NPC(-1, _(" Wh-what?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" Is that true?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0003, 0x00000000),
    MSG_NPC(3, _(" Yes, unfortunately.")),
    MSG_NPC(3, _(" {NAME_8} led his team\nunderground to quell {NAME_9}...")),
    MSG_NPC(3, _(" And that's it.\nWe haven't heard anything from them.")),
    MSG_NPC(3, _(" To be honest...{WAIT_PRESS}\nWe have no idea what became of them.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    WAIT(90),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    MSG_NPC(-1, _(" No idea?{WAIT_PRESS}\nHow is that possible?!{WAIT_PRESS}\nThis is {NAME_8} you're talking about?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" But they haven't come back.\nThat's for real!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    MSG_NPC(-1, _(" That's right...\nAnd it sounds as if {NAME_9} is out of\nour league...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" What? It's that tough?\nThis Pokémon named {NAME_9}?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    MSG_NPC(-1, _(" Why don't you go underground and\nsee for yourself?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" Hunh?!\nYou've gotta be kidding me!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    MSG_NPC(-1, _(" There's magma flowing everywhere\nunderground.{WAIT_PRESS}\nI'd burn up if I went anywhere like that!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Quiet, please! Be quiet!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(60),
    MSG_NPC(3, _(" There's no denying that\nit is dangerous underground.")),
    MSG_NPC(3, _(" It's not a place where just\nanyone can go.")),
    MSG_NPC(3, _(" That's why I asked so many\nrescue teams to gather today.")),
    MSG_NPC(3, _(" I propose that a special\nteam be formed by choosing the best of\nthe best.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(20),
    WAIT(60),
    MSG_NPC(3, _(" Who will step forward?!")),
    MSG_NPC(3, _(" Who among us will be the\nheroes to take on the challenges\nunderground?!")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(150),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(5),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}.\nThis is some chance. Let's go for it.")),
    VARIANT_DEFAULT(_(" Say, {NAME_0}.\nThis is a great opportunity. Let's go.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    { 0x62, 0x00,  0x0100, -0x00000010,  0x00000000, NULL },
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Don't bother, you guys.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's with you?\nCan you get out of the way?")),
    VARIANT_DEFAULT(_(" What's with you?\nCan you step aside?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" You guys have gotten a lot\ntougher, that's for sure, but...")),
    MSG_NPC(2, _(" There's plenty of tougher\nPokémon out there.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    WAIT(30),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Will no one step forward?!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(120),
    ALERT_CUE(9),
    MSG_NPC(-1, _(" I'll go.")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(8),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(60),
    BGM_SWITCH(7),
    MSG_NPC(-1, _(" Whoa!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    MSG_NPC(-1, _(" It's B-{NAME_4}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" You mean...\n{COLOR CYAN}Team Hydro{RESET}'s roughneck {NAME_4}?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" Those waterspouts on his back can\nrocket water so fast that it punches\nthrough thick iron plates!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, 0, 1),
    MSG_NPC(4, _(" It's rumored {NAME_9}\nis a Ground type.")),
    MSG_NPC(4, _(" I am a Water type.\nStrong against the Ground type.")),
    MSG_NPC(4, _(" My Hydro Pump will put\n{NAME_9} down in one shot.")),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_NPC(-1, _(" I'll join the party too.")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(9),
    ALERT_CUE(11),
    ALERT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(-1, _(" Woohoo! It's {NAME_5}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    MSG_NPC(-1, _(" She's {COLOR CYAN}Team Constrictor{RESET}'s leader.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" She's known for persistent and\nclingy attacks.{WAIT_PRESS} She ensnares foes with\nher tentacles, then head-butts them!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" She'd be nasty to face in any battle\nof endurance.")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0005, 0x00000000),
    PORTRAIT_POS(5, 0, -1),
    MSG_NPC(5, _(" Darlings, when I see a tough\nPokémon, I want to tangle with them.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" Say, how about not forgetting about\nme?")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(-1, _(" Wow! {NAME_6}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    MSG_NPC(-1, _(" He's the most brutal out of {COLOR CYAN}Team\nRumblerock{RESET}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" His body is rock hard.\nHe's supposed to be able to withstand\nhuge explosions without taking damage.")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0006, 0x00000000),
    PORTRAIT_POS(6, 0, 1),
    MSG_NPC(6, _(" If {NAME_9}'s awakened\nunderground, that suits me fine.")),
    MSG_NPC(6, _(" I'll use my Rock Throw to\nkeep it buried underground.")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    WAIT(30),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    ALERT_CUE(15),
    WAIT(30),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Oh, {NAME_4}!\n{NAME_5}! And {NAME_6}!")),
    MSG_NPC(3, _(" No one could complain\nabout your selection.")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(60),
    MSG_NPC(3, _(" We will have these three\nrescuers head underground!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    MSG_NPC(-1, _(" Yeah! Good choice!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" You're representing us!\nMake us proud!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Let's go!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(20),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(7),
    WALK_GRID(256, 84),
    WALK_GRID(256, 85),
    ROTATE(4, 10, DIRECTION_EAST),
    ROTATE(30, 2, DIRECTION_WEST),
    AWAIT_CUE(5),
    MSG_NPC(-1, _(" Win it for us!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(-1, _(" Save {NAME_8}'s team!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    MSG_NPC(2, _(" See?\nThey look pretty tough, eh?")),
    MSG_NPC(2, _(" Let them handle things.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK...\nI guess we can't say anything,\n{NAME_0}.")),
    VARIANT_DEFAULT(_(" Hmmm...\nIt can't be helped, {NAME_0}.")),
    TEXTBOX_CLEAR,
    WAIT(60),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};


























static const struct ScriptCommand s_gs1_g26_s0_lives1_dlg0[] = { /* 0x8156884 */
    DEBUGINFO_O(7518),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 86),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000010, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(15),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(6),
    WAIT(30),
    WALK_GRID(256, 84),
    WALK_GRID(256, 87),
    ROTATE(4, 10, DIRECTION_EAST),
    ROTATE(20, 2, DIRECTION_WEST),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives2_dlg0[] = { /* 0x8156c44 */
    DEBUGINFO_O(7581),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WALK_GRID(256, 88),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    WALK_RELATIVE(256, 0, 8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(7),
    WALK_GRID(256, 89),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(30),
    ROTATE(30, 10, DIRECTION_WEST),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WALK_RELATIVE(256, 0, 16),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(7),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives3_dlg0[] = { /* 0x8156eb4 */
    DEBUGINFO_O(7623),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    WAIT(5),
    ROTATE(8, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    AWAIT_CUE(8),
    HALT,
};




static const struct ScriptCommand s_gs1_g26_s0_lives4_dlg0[] = { /* 0x81570c4 */
    DEBUGINFO_O(7662),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(3),
    COND_EQUAL(0, /* to label */ 3),
    COND_EQUAL(1, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 5),
  LABEL(3), /* = 0x03 */
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    JUMP_LABEL(6),
  LABEL(4), /* = 0x04 */
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    JUMP_LABEL(6),
  LABEL(5), /* = 0x05 */
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(6),
  LABEL(6), /* = 0x06 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(7), /* = 0x07 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 8),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 8),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(7),
  LABEL(8), /* = 0x08 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_RELATIVE(76, 8, 0),
    AWAIT_CUE(9),
    WALK_GRID(76, 90),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
  LABEL(9), /* = 0x09 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 9),
    AWAIT_CUE(9),
  LABEL(10), /* = 0x0a */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 10),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(30),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(30),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_GRID(256, 91),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs1_g26_s0_lives5_dlg0[] = { /* 0x81575e4 */
    DEBUGINFO_O(7748),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(3),
    COND_EQUAL(0, /* to label */ 2),
    COND_EQUAL(1, /* to label */ 3),
    COND_EQUAL(2, /* to label */ 4),
  LABEL(2), /* = 0x02 */
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    JUMP_LABEL(5),
  LABEL(3), /* = 0x03 */
    ROTATE(4, 10, DIRECTION_SOUTH),
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    ROTATE(4, 10, DIRECTION_WEST),
  LABEL(5), /* = 0x05 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(6), /* = 0x06 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    ROTATE(8, 2, DIRECTION_SOUTH),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    ROTATE(8, 1, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(6),
  LABEL(7), /* = 0x07 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(10),
  LABEL(8), /* = 0x08 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 8),
    AWAIT_CUE(10),
    WALK_GRID(76, 92),
    ROTATE(4, 10, DIRECTION_EAST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(10),
  LABEL(9), /* = 0x09 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 9),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(30),
    WALK_GRID(256, 91),
    AWAIT_CUE(10),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives6_dlg0[] = { /* 0x8157a64 */
    DEBUGINFO_O(7823),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(3),
    COND_EQUAL(0, /* to label */ 2),
    COND_EQUAL(1, /* to label */ 3),
    COND_EQUAL(2, /* to label */ 4),
  LABEL(2), /* = 0x02 */
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    JUMP_LABEL(5),
  LABEL(3), /* = 0x03 */
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
  LABEL(5), /* = 0x05 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(6), /* = 0x06 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    ROTATE(8, 2, DIRECTION_WEST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    ROTATE(8, 1, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(6),
  LABEL(7), /* = 0x07 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(11),
  LABEL(8), /* = 0x08 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 8),
    AWAIT_CUE(11),
  LABEL(9), /* = 0x09 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 9),
    AWAIT_CUE(11),
    WALK_GRID(76, 93),
    ROTATE(4, 10, DIRECTION_EAST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(60),
    WALK_GRID(256, 91),
    AWAIT_CUE(11),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives7_dlg0[] = { /* 0x8157ee4 */
    DEBUGINFO_O(7898),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    CJUMP_RANDOM(3),
    COND_EQUAL(0, /* to label */ 2),
    COND_EQUAL(1, /* to label */ 3),
    COND_EQUAL(2, /* to label */ 4),
  LABEL(2), /* = 0x02 */
    ROTATE(8, 1, DIRECTION_NORTHEAST),
    JUMP_LABEL(5),
  LABEL(3), /* = 0x03 */
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    ROTATE(8, 2, DIRECTION_SOUTHWEST),
  LABEL(5), /* = 0x05 */
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_WEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(6), /* = 0x06 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 6),
    AWAIT_CUE(20),
  LABEL(7), /* = 0x07 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    AWAIT_CUE(20),
  LABEL(8), /* = 0x08 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 8),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(9), /* = 0x09 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 9),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives8_dlg0[] = { /* 0x8158324 */
    DEBUGINFO_O(7969),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives9_dlg0[] = { /* 0x8158684 */
    DEBUGINFO_O(8026),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(8, 10, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(4), /* = 0x04 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 4),
    AWAIT_CUE(20),
  LABEL(5), /* = 0x05 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 5),
    AWAIT_CUE(20),
  LABEL(6), /* = 0x06 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 6),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(7), /* = 0x07 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives10_dlg0[] = { /* 0x8158a44 */
    DEBUGINFO_O(8089),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives11_dlg0[] = { /* 0x8158da4 */
    DEBUGINFO_O(8146),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives12_dlg0[] = { /* 0x8159104 */
    DEBUGINFO_O(8203),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_NORTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_NORTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives13_dlg0[] = { /* 0x8159464 */
    DEBUGINFO_O(8260),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    WALK_GRID(128, 95),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives14_dlg0[] = { /* 0x8159804 */
    DEBUGINFO_O(8321),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives15_dlg0[] = { /* 0x8159b04 */
    DEBUGINFO_O(8372),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT_RANDOM(0, 60),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_NORTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    WAIT_RANDOM(0, 60),
    ROTATE(4, 10, DIRECTION_NORTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    AWAIT_CUE(20),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 2),
    AWAIT_CUE(15),
    CAMERA_PAN(256, 94),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g26_s0_lives16_dlg0[] = { /* 0x8159e94 */
    DEBUGINFO_O(8432),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(4), /* = 0x04 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 4),
    AWAIT_CUE(20),
  LABEL(5), /* = 0x05 */
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    WAIT(60),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 5),
    AWAIT_CUE(20),
  LABEL(6), /* = 0x06 */
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    WAIT(60),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 6),
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 120),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(7), /* = 0x07 */
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 7),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g27_s0_station_sref_script[] = { /* 0x815a254 */
    DEBUGINFO_O(8495),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g27_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g27_s0_station_sref_script }; /* 0x815a294 */

static const struct ScriptCommand s_gs1_g27_s0_lives0_dlg2[] = { /* 0x815a2a0 */
    DEBUGINFO_O(8504),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives1_dlg2[] = { /* 0x815a300 */
    DEBUGINFO_O(8513),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives2_dlg2[] = { /* 0x815a360 */
    DEBUGINFO_O(8522),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives3_dlg2[] = { /* 0x815a3c0 */
    DEBUGINFO_O(8531),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives4_dlg2[] = { /* 0x815a420 */
    DEBUGINFO_O(8540),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives5_dlg2[] = { /* 0x815a480 */
    DEBUGINFO_O(8549),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives6_dlg1[] = { /* 0x815a4e0 */
    DEBUGINFO_O(8558),
    { 0x51, 0x00,  0x0062,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_BOY),
    RET,
};

static const struct ScriptCommand s_gs1_g27_s0_lives6_dlg2[] = { /* 0x815a520 */
    DEBUGINFO_O(8565),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You bet I'm worried about\nAlakazam's team...{WAIT_PRESS}\nBut Blastoise and company are tough.")),
    MSG_NPC(1, _(" Don't you worry now.\nThey'll get the job done.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives7_dlg1[] = { /* 0x815a620 */
    DEBUGINFO_O(8575),
    { 0x51, 0x00,  0x0061,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_GIRL),
    RET,
};

static const struct ScriptCommand s_gs1_g27_s0_lives7_dlg2[] = { /* 0x815a660 */
    DEBUGINFO_O(8582),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" There have been so many\nearthquakes...{WAIT_PRESS}\nI can't get a decent night's sleep!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives8_dlg1[] = { /* 0x815a714 */
    DEBUGINFO_O(8591),
    { 0x51, 0x00,  0x0060,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(MOVE_RANDOM),
    RET,
};

static const struct ScriptCommand s_gs1_g27_s0_lives8_dlg2[] = { /* 0x815a754 */
    DEBUGINFO_O(8598),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We agreed to let Blastoise's\ncrew handle this situation.\nLet's give them some time.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g27_s0_lives9_dlg2[] = { /* 0x815a810 */
    DEBUGINFO_O(8607),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You know how we've had\nso many earthquakes lately?")),
    MSG_NPC(1, _(" Are they signs that\nsomething a lot worse is coming?{WAIT_PRESS}\nI shudder to think!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g28_s0_station_sref_script[] = { /* 0x815a904 */
    DEBUGINFO_O(8617),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_STOP,
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs1_g28_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g28_s0_station_sref_script }; /* 0x815a9a4 */

static const struct ScriptCommand s_gs1_g28_s0_eff0_script[] = { /* 0x815a9b0 */
    DEBUGINFO_O(8632),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WALK_GRID(256, 112),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(256, 113),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    CAMERA_PAN(256, 112),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_GRID(256, 114),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WALK_GRID(256, 112),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g28_s0_lives0_dlg0[] = { /* 0x815aae0 */
    DEBUGINFO_O(8654),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0008,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0009,  0x00000067,  0x00000000, NULL },
    ALERT_CUE(6),
    WALK_GRID(256, 99),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_2}!")),
    VARIANT(/* == */  1, _(" What's up here?")),
    VARIANT_DEFAULT(_(" Oh! {NAME_2}!")),
    VARIANT_DEFAULT(_(" What's going on here?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hey, {NAME_1}.\nW-well...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ...You should just go see\nfor yourself...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(6),
    WALK_GRID(256, 100),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(5),
    BGM_SWITCH(9),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Look!\nIt's {NAME_5}!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_3}!{WAIT_PRESS}\nWhat's going on here?!")),
    VARIANT_DEFAULT(_(" {NAME_3}!{WAIT_PRESS}\nWhat happened here?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, 0, -1),
    MSG_NPC(3, _(" ............{WAIT_PRESS}\nThey were wiped out...{WAIT_PRESS}\nIn the underground dungeon...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    MSG_NPC(1, _(" You're kidding!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000003),
    PORTRAIT_POS(5, 0, 1),
    MSG_NPC(5, _(" Groan... That place...{WAIT_PRESS}\nIt's rough, seriously...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0006, 0x00000000),
    PORTRAIT_POS(6, 0, -1),
    MSG_NPC(6, _(" ...We couldn't get far\nenough to even see {NAME_9}...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(8),
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0007, 0x00000000),
    PORTRAIT_POS(7, 0, 1),
    MSG_NPC(7, _(" I don't want to ever go\nback to a place that bad...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    WAIT(60),
    ALERT_CUE(8),
    WAIT(30),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    MSG_NPC(3, _(" ...It appears the dungeon\nunderground...{WAIT_PRESS}\nis far worse than we'd imagined...")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(60),
    WAIT(60),
    BGM_SWITCH(10),
    MSG_NPC(-1, _(" Kekekekekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(13),
    ALERT_CUE(8),
    ALERT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(5),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" What fools.{WAIT_PRESS}\nThat's what you get for trying the\nimpossible.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_RIGHT, 0x0001, 0x00000003),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Ge-{NAME_4}!")),
    VARIANT(/* == */  1, _(" Why don't you shut up?!{WAIT_PRESS}\nThis is about saving {NAME_8}'s team.\nWe have to try!")),
    VARIANT_DEFAULT(_(" Ge-{NAME_4}!")),
    VARIANT_DEFAULT(_(" What are you saying?!{WAIT_PRESS}\nIt's only expected that we try. This is for\nsaving {NAME_8}'s team.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(13),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Kekeh!\nYou really find thinking hard, don't you?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT_FLIP, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Even they look smart\ncompared to you.")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(20),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    WAIT(30),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    WAIT(60),
    MSG_NPC(-1, _(" It's too much...\nEven {NAME_5} went down...")),
    MSG_NPC(-1, _(" It's gotta be awful tough.")),
    MSG_NPC(-1, _(" Who'd want to go into a dungeon that\ndangerous?")),
    MSG_NPC(-1, _(" There's no way. I can't go.{WAIT_PRESS}\nI burn too easily.")),
    MSG_NPC(-1, _(" I can't take earthquakes.")),
    MSG_NPC(-1, _(" It'd be like going and knowing full\nwell we'd get wiped...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0001, 0x00000005),
    MSG_NPC(1, _(" ...E-everyone...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" You see?\nEven they finally seem to understand\ntheir situation. Kekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" I...{WAIT_PRESS}\nMy leafy fans would burn up...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    WAIT(15),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x00000005),
    PORTRAIT_POS(1, -2, 0),
    MSG_NPC(1, _(" E-even {NAME_3}...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT_FLIP, 0x0001, 0x00000000),
    MSG_NPC(4, _(" Kekeh! Get over it!\nDon't expect to be rewarded just because\nyou tried!")),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Sometimes, it's better to\nwise up and give up!")),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000001),
    MSG_NPC(4, _(" ............Huh?{WAIT_PRESS}\nDid I say something profound?\nKekekekekekekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0001, 0x00000005),
    MSG_NPC(1, _(" Urf...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    BGM_FADEOUT(150),
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}...\nI don't know anymore...")),
    VARIANT(/* == */  1, _(" What should we do?")),
    VARIANT(/* == */  1, _(" Even if it's impossible...")),
    VARIANT(/* == */  3, _(" {NAME_0}...\nI don't know anymore...")),
    VARIANT(/* == */  3, _(" What should we do?")),
    VARIANT(/* == */  3, _(" Even if it's the impossible...")),
    VARIANT_DEFAULT(_(" {NAME_0}...\nI don't know anymore...")),
    VARIANT_DEFAULT(_(" What should we do?")),
    VARIANT_DEFAULT(_(" Even if it's the impossible...")),
    TEXTBOX_CLEAR,
  LABEL(17), /* = 0x11 */
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" Should we still\ntry to rescue {NAME_8}?")),
    CHOICE(/* label */ 18, _("Let's go!")),
    CHOICE(/* label */ 19, _("Let's not.")),
  LABEL(19), /* = 0x13 */
    MSG_NPC(1, _(" ...{WAIT_PRESS}Really...?{WAIT_PRESS}\nYou honestly think we shouldn't go?")),
    TEXTBOX_CLEAR,
    JUMP_LABEL(17),
  LABEL(18), /* = 0x12 */
    PORTRAIT_REP(0x0001, 0x0000000b),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...{WAIT_PRESS}Yes...{WAIT_PRESS}\nYeah, you're right.")),
    VARIANT(/* == */  1, _(" All right, {NAME_0}!")),
    VARIANT_DEFAULT(_(" ...{WAIT_PRESS}Yes...{WAIT_PRESS}\nI think so too.")),
    VARIANT_DEFAULT(_(" OK, {NAME_0}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    BGM_SWITCH(7),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Everyone, listen!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(20),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    AWAIT_CUE(5),
    WAIT(15),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    WAIT(60),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We're going!\nTo rescue {NAME_8}'s team!")),
    VARIANT(/* == */  3, _(" We're going!\nTo rescue {NAME_8}'s team!")),
    VARIANT_DEFAULT(_(" We're going!\nTo rescue {NAME_8}'s team!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    ALERT_CUE(20),
    FANFARE_PLAY2(465),
    WAIT(30),
    MSG_NPC(-1, _(" Wha-what?!")),
    MSG_NPC(-1, _(" What did they say?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0004, 0x00000006),
    MSG_NPC(4, _(" Ugegege?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(20),
    AWAIT_CUE(5),
    MSG_NPC(-1, _(" Hey, who are they?")),
    MSG_NPC(-1, _(" Can't say I know them...")),
    MSG_NPC(-1, _(" It's {COLOR CYAN}Team {TEAM_NAME}{RESET}.{WAIT_PRESS}\nThey're well known around these parts.")),
    MSG_NPC(-1, _(" {COLOR CYAN}Team {TEAM_NAME}{RESET}...?{WAIT_PRESS}\nYou mean the lot that were suspected of\ninvolvement in the Ninetales legend?")),
    MSG_NPC(-1, _(" I heard about that!{WAIT_PRESS}\nWeren't they living like fugitives until\nrecently?")),
    MSG_NPC(-1, _(" Can they handle it?{WAIT_PRESS}\nThey don't look very tough.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sure, the rescue might be\ntoo much for us to handle.")),
    VARIANT(/* == */  3, _(" Yes, the rescue might be too\nmuch of a challenge for us.")),
    VARIANT_DEFAULT(_(" It's true--the rescue might\nbe too much for us to handle.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But...{WAIT_PRESS}\nwe're still a rescue team.")),
    VARIANT(/* == */  1, _(" I wanted to help Pokémon\nthat were suffering from the natural\ndisasters...")),
    VARIANT(/* == */  1, _(" That's why we started up\nour rescue team!")),
    VARIANT(/* == */  3, _(" But...{WAIT_PRESS}\nEven so, we're still a rescue team.")),
    VARIANT(/* == */  3, _(" To help Pokémon suffering\nfrom the natural disasters...")),
    VARIANT(/* == */  3, _(" That's why we started up\nour rescue team!")),
    VARIANT_DEFAULT(_(" But...{WAIT_PRESS}\nwe're still a rescue team.")),
    VARIANT_DEFAULT(_(" To help Pokémon suffering\nfrom the natural disasters...")),
    VARIANT_DEFAULT(_(" That's why we started up\nour rescue team!")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's why I want to\nrescue {NAME_8}'s team more than\nanything.")),
    VARIANT(/* == */  1, _(" Never giving up...\nThat's what {COLOR CYAN}Team {TEAM_NAME}{RESET} takes\npride in!")),
    VARIANT(/* == */  3, _(" That's why I want to rescue\n{NAME_8}'s team, even if it's risky.")),
    VARIANT(/* == */  3, _(" Never giving up...\nThat's where {COLOR CYAN}Team {TEAM_NAME}{RESET} stakes\nits pride!")),
    VARIANT_DEFAULT(_(" That's why I want to\nrescue {NAME_8}'s team more than\nanything.")),
    VARIANT_DEFAULT(_(" Never giving up...\nThat's where {COLOR CYAN}Team {TEAM_NAME}{RESET} stakes\nits pride!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000003),
    MSG_NPC(4, _(" ............{WAIT_PRESS}Keh.{WAIT_PRESS} Kekekeh!{WAIT_PRESS}\nYou really aren't very bright, are you?")),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT_FLIP, 0x0004, 0x00000000),
    MSG_NPC(4, _(" Why don't you do like\neveryone else and wise up?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, 0, -1),
    MSG_NPC(3, _(" ...No.\n{NAME_1} is right.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(20),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x0001,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000003),
    MSG_NPC(4, _(" ...Ugeh?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(20),
    WAIT(60),
    MSG_NPC(-1, _(" ...That's right.\nI wasn't thinking straight...out of fear.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(5),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT_FLIP, 0x0004, 0x00000006),
    MSG_NPC(4, _(" ...Ugegegeh?")),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_NPC(-1, _(" We all forgot the most important\nthing. We are rescue teams.")),
    MSG_NPC(-1, _(" ...Pride...")),
    MSG_NPC(-1, _(" We have it too!\nPride as rescuers!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000006),
    MSG_NPC(4, _(" Ugegegegeh!\nHave you lost your senses?!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000003),
    MSG_NPC(4, _(" Why would you listen to\nthat clown and, worse, be persuaded?")),
    WAIT(15),
    ALERT_CUE(20),
    PORTRAIT_REP(0x0004, 0x00000002),
    MSG_NPC(4, _(" Why go if you're facing\ncertain defeat?!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    PORTRAIT_REP(0x0005, 0x00000000),
    MSG_NPC(5, _(" Is that so...?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(9),
    ALERT_CUE(20),
    { 0x93, 0x04,  0x0001,  0x00000068,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(5, _(" ...We've only failed once.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x0000000b),
    MSG_NPC(1, _(" {NAME_5}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" ...This is no time to be\nlying around!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0004, 0x00000006),
    MSG_NPC(4, _(" Ugegeh!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    MSG_NPC(6, _(" Yes, no more wallowing in\nwoe-is-me self-pity.")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(12),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    MSG_NPC(7, _(" If we give up, that's how\nit ends. Not for me.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x0000000b),
    MSG_NPC(1, _(" {NAME_6}!\nAnd {NAME_7} too!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000003),
    MSG_NPC(4, _(" Ugegegeh!\nYou lot, that wasn't the tune you\nwere whistling just a little...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" Aye, that's right!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    MSG_NPC(-1, _(" There've got to be ways we can\nget through!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTH),
    MSG_NPC(-1, _(" If we all pull together, we'll be sure\nto find a way!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    MSG_NPC(-1, _(" We'll conquer the dungeon by\nhaving all the rescue teams cooperate!")),
    WAIT(30),
    ALERT_CUE(20),
    MSG_NPC(-1, _(" Wrooooooooaaaar!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Ugegegegegegegegeh!{WAIT_PRESS}\nAre you dreaming?!")),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(20),
    ALERT_CUE(8),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Don't say I didn't warn you\nwhen you get into a world of pain!\nUgegegegeh!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(16),
    ALERT_CUE(9),
    ALERT_CUE(6),
    ROTATE(10, 10, DIRECTION_NORTH),
    AWAIT_CUE(5),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(30),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(5),
    ALERT_CUE(20),
    WAIT(60),
    MSG_NPC(5, _(" Thank you, {NAME_1}.")),
    MSG_NPC(5, _(" You stopped us from\nthrowing away the most important thing\nwe have--pride.")),
    MSG_NPC(5, _(" My thanks from all of us.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(15),
    ALERT_CUE(20),
    WAIT(60),
    MSG_NPC(5, _(" Everyone!{WAIT_PRESS}\nIt's time to get to work!")),
    MSG_NPC(5, _(" Let's show them what we\nrescue teams are really about!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(20),
    MSG_NPC(-1, _(" Wrooooooaaaaar!")),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(3),
    HALT,
};







































static const struct ScriptCommand s_gs1_g28_s0_lives1_dlg0[] = { /* 0x815dbb8 */
    DEBUGINFO_O(9193),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 101),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WAIT(30),
    WALK_GRID(256, 102),
    WALK_GRID(256, 103),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    FANFARE_PLAY2(464),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    FANFARE_PLAY2(463),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(5),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x0002,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(8, 1, DIRECTION_NORTH),
    WAIT(30),
    ROTATE(8, 2, DIRECTION_SOUTHEAST),
    WAIT(30),
    ROTATE(8, 1, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(8, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_SOUTH),
    WAIT(15),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x0002,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x0002,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(6),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives2_dlg0[] = { /* 0x815e298 */
    DEBUGINFO_O(9306),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(8),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(8),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives3_dlg0[] = { /* 0x815e488 */
    DEBUGINFO_O(9340),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WALK_GRID(256, 104),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_GRID(256, 105),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(30),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(4, 2, DIRECTION_EAST),
    WAIT(15),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    WAIT(15),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(30),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000069,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000006a,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 1, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 2, DIRECTION_SOUTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_GRID(768, 106),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives4_dlg0[] = { /* 0x815eaa8 */
    DEBUGINFO_O(9441),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives5_dlg0[] = { /* 0x815ebb8 */
    DEBUGINFO_O(9461),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    AWAIT_CUE(11),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives6_dlg0[] = { /* 0x815ec78 */
    DEBUGINFO_O(9476),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(22),
    AWAIT_CUE(12),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(12),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives7_dlg0[] = { /* 0x815ed38 */
    DEBUGINFO_O(9491),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x0001,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    WAIT(60),
    { 0x93, 0x04,  0x0001,  0x00000022,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives8_dlg0[] = { /* 0x815f118 */
    DEBUGINFO_O(9556),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives9_dlg0[] = { /* 0x815f428 */
    DEBUGINFO_O(9608),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(8, 10, DIRECTION_SOUTH),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    WALK_GRID(128, 107),
    ROTATE(4, 10, DIRECTION_SOUTH),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    WALK_GRID(128, 108),
    ROTATE(4, 10, DIRECTION_SOUTH),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    WALK_GRID(128, 109),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT(30),
    WALK_GRID(76, 110),
    { 0x93, 0x04,  0x000a,  0x0000008e,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000008e,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(16),
    { 0x62, 0x00,  0x0100, -0x00000010,  0x00000000, NULL },
  LABEL(2), /* = 0x02 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 2),
    AWAIT_CUE(20),
    WALK_RELATIVE(128, 16, 0),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives10_dlg0[] = { /* 0x815f928 */
    DEBUGINFO_O(9691),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g28_s0_lives11_dlg0[] = { /* 0x815fc58 */
    DEBUGINFO_O(9745),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(8, 10, DIRECTION_SOUTH),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    SELECT_ANIMATION(4),
    WAIT_RANDOM(60, 120),
    SELECT_ANIMATION(2),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_SOUTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(4), /* = 0x04 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives12_dlg0[] = { /* 0x8160158 */
    DEBUGINFO_O(9828),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_EAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 1),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    WAIT_RANDOM(15, 90),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 3),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    WAIT_RANDOM(15, 90),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTH),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(4), /* = 0x04 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 4),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives13_dlg0[] = { /* 0x8160588 */
    DEBUGINFO_O(9898),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_EAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives14_dlg0[] = { /* 0x8160898 */
    DEBUGINFO_O(9950),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(30),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    { 0x93, 0x08,  0x000a,  0x00000088,  0x00000000, NULL },
    WAIT(30),
    WALK_GRID(128, 111),
    SELECT_ANIMATION(4),
    ALERT_CUE(5),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000088,  0x00000000, NULL },
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(16),
    { 0x62, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g28_s0_lives15_dlg0[] = { /* 0x8160c78 */
    DEBUGINFO_O(10015),
    SELECT_ANIMATION(2),
    AWAIT_CUE(13),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000010, NULL },
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    WALK_RELATIVE(256, -16, 16),
    WALK_RELATIVE(256, -8, 0),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000055,  0x00000000, NULL },
    AWAIT_CUE(20),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    SELECT_ANIMATION(4),
    AWAIT_CUE(20),
    WAIT(30),
    SELECT_ANIMATION(2),
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
  LABEL(0), /* = 0x00 */
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    WAIT(15),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(20),
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    WAIT_RANDOM(30, 90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(20),
    HALT,
    SELECT_ANIMATION(2),
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_station_sref_script[] = { /* 0x8161008 */
    DEBUGINFO_O(10075),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g29_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g29_s0_station_sref_script }; /* 0x8161048 */

static const struct ScriptCommand s_gs1_g29_s0_lives0_dlg2[] = { /* 0x8161054 */
    DEBUGINFO_O(10084),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  0,  1),
    MSG_NPC(1, _(" Oh, my goodness, yes!\n{NAME_2}'s talk was such an\ninspiration!")),
    MSG_NPC(1, _(" It has stoked a raging fire\nin our hearts!")),
    MSG_NPC(1, _(" I will keep bringing in fine\nmerchandise!{WAIT_PRESS} This, I do for you!{WAIT_PRESS}\nSo...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives1_dlg2[] = { /* 0x81611f0 */
    DEBUGINFO_O(10101),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  1,  1),
    EXECUTE_STATION(-1, 29, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives2_dlg2[] = { /* 0x81612a0 */
    DEBUGINFO_O(10115),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  2,  1),
    MSG_NPC(1, _(" Aren't you remarkable?{WAIT_PRESS}\nYour money will be jealously guarded,\nso feel secure on your outings!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives3_dlg2[] = { /* 0x81613b4 */
    DEBUGINFO_O(10129),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  3,  1),
    MSG_NPC(1, _(" {NAME_2}'s words struck\nme deeply.")),
    MSG_NPC(1, _(" You can count on me for all\nyour move-linking needs!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives4_dlg2[] = { /* 0x81614e0 */
    DEBUGINFO_O(10145),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  4,  1),
    MSG_NPC(1, _(" Dear, I wasn't wrong about\nyou at all.")),
    MSG_NPC(1, _(" I always thought you weren't\nthe ordinary sort.")),
    MSG_NPC(1, _(" I'll keep your valuables\nunder my watchful eye! You can go out and\nfight without worrying about them!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives5_dlg2[] = { /* 0x816167c */
    DEBUGINFO_O(10161),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  5,  1),
    MSG_NPC(1, _(" I'll do my best to get more\nFriend Areas!")),
    MSG_NPC(1, _(" Because {NAME_0}'s team\nare my friends!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives6_dlg0[] = { /* 0x8161794 */
    DEBUGINFO_O(10176),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives6_dlg2[] = { /* 0x81617c4 */
    DEBUGINFO_O(10182),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000004d,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000068,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" What's it like?\nThis {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" It was teeming with tough\nPokémon, that's for sure.")),
    MSG_NPC(3, _(" I'm strong against fire...{WAIT_PRESS}\nbut that place is special.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives7_dlg0[] = { /* 0x8161948 */
    DEBUGINFO_O(10199),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives7_dlg2[] = { /* 0x8161978 */
    DEBUGINFO_O(10205),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000004d,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000068,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(2, _(" What's it like?\nThis {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" It was teeming with tough\nPokémon, that's for sure.")),
    MSG_NPC(3, _(" I'm strong against fire...{WAIT_PRESS}\nbut that place is special.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives8_dlg0[] = { /* 0x8161a58 */
    DEBUGINFO_O(10222),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives8_dlg2[] = { /* 0x8161a88 */
    DEBUGINFO_O(10228),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000004f,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000069,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" The {COLOR YELLOW_D}Magma Cavern{RESET}...\nAbove all, there were many Fire-type\nPokémon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Fire-type Pokémon...{WAIT_PRESS}\nI think they would burn me up in no time...")),
    MSG_NPC(2, _(" But, no!{WAIT_PRESS}\nI mustn't make excuses for myself!")),
    MSG_NPC(2, _(" Now is the time for each\nand every one of us to make a stand!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives9_dlg0[] = { /* 0x8161c7c */
    DEBUGINFO_O(10246),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives9_dlg2[] = { /* 0x8161cac */
    DEBUGINFO_O(10252),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000004f,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000069,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" The {COLOR YELLOW_D}Magma Cavern{RESET}...\nAbove all, there were many Fire-type\nPokémon.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Fire-type Pokémon...{WAIT_PRESS}\nI think they would burn me up in no time...")),
    MSG_NPC(2, _(" But, no!{WAIT_PRESS}\nI mustn't make excuses for myself!")),
    MSG_NPC(2, _(" Now is the time for each\nand every one of us to make a stand!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives10_dlg0[] = { /* 0x8161d9c */
    DEBUGINFO_O(10270),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives10_dlg2[] = { /* 0x8161dcc */
    DEBUGINFO_O(10276),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000055,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000006a,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Oi, you lot shouldn't go.")),
    MSG_NPC(3, _(" The {COLOR YELLOW_D}Magma Cavern{RESET} is\nalive with flames. You'll be burned up!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" We can't do that!{WAIT_PRESS}\nWe are a rescue team too.\nWe can't stand by idly!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives11_dlg0[] = { /* 0x8161f5c */
    DEBUGINFO_O(10293),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s0_lives11_dlg2[] = { /* 0x8161f8c */
    DEBUGINFO_O(10299),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000055,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000006a,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_LEFT_, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Oi, you lot shouldn't go.")),
    MSG_NPC(3, _(" The {COLOR YELLOW_D}Magma Cavern{RESET} is\nalive with flames. You'll be burned up!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" We can't do that!{WAIT_PRESS}\nWe are a rescue team too.\nWe can't stand by idly!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s0_lives12_dlg2[] = { /* 0x816206c */
    DEBUGINFO_O(10316),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Several rescue teams have\nalready left for the {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    MSG_NPC(1, _(" {NAME_0}, you guys take\ncare, too.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s1_station_sref_script[] = { /* 0x8162144 */
    DEBUGINFO_O(10326),
    SELECT_LIVES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g29_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g29_s1_station_sref_script }; /* 0x8162184 */

static const struct ScriptCommand s_gs1_g29_s1_lives0_dlg0[] = { /* 0x8162190 */
    DEBUGINFO_O(10335),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" {NAME_1}'s words\nshook me up with inspiration!")),
    MSG_NPC(3, _(" Especially the part about\ntaking pride...{WAIT_PRESS} That made me...{WAIT_PRESS}\nIt left me choked up...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" It isn't just you, my brother.{WAIT_PRESS}\nI am likewise inspired beyond words.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" B-Brother...{WAIT_PRESS}\nSniffle... My brother...")),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" I will do my best to obtain\neven better Technical Machines and Orbs.")),
    MSG_NPC(3, _(" All with the pride of a\nmerchant!")),
    ALERT_CUE(3),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    TEXTBOX_CLEAR,
    SELECT_LIVES(-1, 0),
    RET,
};

static const struct ScriptCommand s_gs1_g29_s1_lives1_dlg0[] = { /* 0x81624a0 */
    DEBUGINFO_O(10367),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g29_s1_lives2_dlg0[] = { /* 0x81624e0 */
    DEBUGINFO_O(10374),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    RET,
};

static const struct ScriptCommand s_gs1_g29_s1_lives2_dlg2[] = { /* 0x8162580 */
    DEBUGINFO_O(10387),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  0,  1),
    MSG_NPC(1, _(" Oh, my goodness, yes!\n{NAME_2}'s talk was such an\ninspiration!")),
    MSG_NPC(1, _(" It has stoked a raging fire\nin our hearts!")),
    MSG_NPC(1, _(" I will keep bringing in fine\nmerchandise!{WAIT_PRESS} This, I do for you!{WAIT_PRESS}\nSo...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g29_s1_lives3_dlg0[] = { /* 0x8162660 */
    DEBUGINFO_O(10404),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    RET,
};

static const struct ScriptCommand s_gs1_g29_s1_lives3_dlg2[] = { /* 0x8162710 */
    DEBUGINFO_O(10418),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  1,  1),
    EXECUTE_STATION(-1, 29, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_station_sref_script[] = { /* 0x81627c0 */
    DEBUGINFO_O(10432),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g30_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g30_s0_station_sref_script }; /* 0x8162800 */

static const struct ScriptCommand s_gs1_g30_s0_lives0_dlg2[] = { /* 0x816280c */
    DEBUGINFO_O(10441),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  0,  1),
    MSG_NPC(1, _(" Oh, my goodness, yes!\n{NAME_2}'s talk was such an\ninspiration!")),
    MSG_NPC(1, _(" It has stoked a raging fire\nin our hearts!")),
    MSG_NPC(1, _(" I will keep bringing in fine\nmerchandise!{WAIT_PRESS} This, I do for you!{WAIT_PRESS}\nSo...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives1_dlg0[] = { /* 0x81628ec */
    DEBUGINFO_O(10458),
    RET,
};

static const struct ScriptCommand s_gs1_g30_s0_lives1_dlg2[] = { /* 0x816290c */
    DEBUGINFO_O(10463),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  1,  1),
    EXECUTE_STATION(-1, 30, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives2_dlg2[] = { /* 0x81629bc */
    DEBUGINFO_O(10477),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  2,  1),
    MSG_NPC(1, _(" Aren't you remarkable?{WAIT_PRESS}\nYour money will be jealously guarded,\nso feel secure on your outings!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives3_dlg2[] = { /* 0x8162a6c */
    DEBUGINFO_O(10491),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  3,  1),
    MSG_NPC(1, _(" {NAME_2}'s words struck\nme deeply.")),
    MSG_NPC(1, _(" You can count on me for all\nyour move-linking needs!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives4_dlg2[] = { /* 0x8162b3c */
    DEBUGINFO_O(10507),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  4,  1),
    MSG_NPC(1, _(" Dears, I wasn't wrong about\nyou at all.")),
    MSG_NPC(1, _(" I always thought you weren't\nthe ordinary sort.")),
    MSG_NPC(1, _(" I'll keep your valuables\nunder my watchful eye! You can go out and\nfight without worrying about them!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives5_dlg2[] = { /* 0x8162c3c */
    DEBUGINFO_O(10523),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  5,  1),
    MSG_NPC(1, _(" I'll do my best to get more\nFriend Areas!")),
    MSG_NPC(1, _(" Because {NAME_0}'s team\nare my friends!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives6_dlg0[] = { /* 0x8162cfc */
    DEBUGINFO_O(10538),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g30_s0_lives6_dlg2[] = { /* 0x8162d2c */
    DEBUGINFO_O(10544),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000068,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000069,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x0000006a,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0005,  0x0000006b,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0005, -0x00000002,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(3, _(" We got wiped again...{WAIT_PRESS}\nFifteen times now we have been to that\ninfernal {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Why does this keep\nhappening?{WAIT_PRESS}\nWe can't be that weak!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" Maybe we're just lacking\nthe will to win.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" The will to win?{WAIT_PRESS}\nThat's it! This is about willpower!\nI didn't realize!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Darlings, we will will\nourselves to win, and we will win!")),
    MSG_NPC(3, _(" Let's take it down! Groudon!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" Hoorah!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives7_dlg0[] = { /* 0x8163090 */
    DEBUGINFO_O(10577),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g30_s0_lives7_dlg2[] = { /* 0x81630c0 */
    DEBUGINFO_O(10583),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000068,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000069,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x0000006a,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0005,  0x0000006b,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0005, -0x00000002,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(3, _(" We got wiped again...{WAIT_PRESS}\nFifteen times now we have been to that\ninfernal {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Why does this keep\nhappening?{WAIT_PRESS}\nWe can't be that weak!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" Maybe we're just lacking\nthe will to win.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" The will to win?{WAIT_PRESS}\nThat's it! This is about willpower!\nI didn't realize!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Darlings, we will will\nourselves to win, and we will win!")),
    MSG_NPC(3, _(" Let's take it down! Groudon!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" Hoorah!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives8_dlg0[] = { /* 0x81632a0 */
    DEBUGINFO_O(10616),
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g30_s0_lives8_dlg2[] = { /* 0x81632d0 */
    DEBUGINFO_O(10622),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000068,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000069,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x0000006a,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0005,  0x0000006b,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0005, -0x00000002,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(3, _(" We got wiped again...{WAIT_PRESS}\nFifteen times now we have been to that\ninfernal {COLOR YELLOW_D}Magma Cavern{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Why does this keep\nhappening?{WAIT_PRESS}\nWe can't be that weak!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" Maybe we're just lacking\nthe will to win.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" The will to win?{WAIT_PRESS}\nThat's it! This is about willpower!\nI didn't realize!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Darlings, we will will\nourselves to win, and we will win!")),
    MSG_NPC(3, _(" Let's take it down! Groudon!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" Hoorah!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives9_dlg1[] = { /* 0x81634b0 */
    DEBUGINFO_O(10655),
  LABEL(0), /* = 0x00 */
    SELECT_ANIMATION(5),
    WALK_RELATIVE(256, -16, 0),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(90),
    WALK_RELATIVE(256, 16, 0),
    WAIT(90),
    WALK_RELATIVE(256, 16, 0),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(90),
    WALK_RELATIVE(256, -16, 0),
    WAIT(90),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_gs1_g30_s0_lives9_dlg2[] = { /* 0x81635b0 */
    DEBUGINFO_O(10674),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I ventured into the {COLOR YELLOW_D}Magma\nCavern{RESET}, but...")),
    MSG_NPC(1, _(" I got nowhere.{WAIT_PRESS}\nI got KO'd and kicked out as soon as I\nwent in...")),
    MSG_NPC(1, _(" But I won't give up!\nNot ever!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives10_dlg2[] = { /* 0x81636d0 */
    DEBUGINFO_O(10685),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" It's tough for us to get\nvery deep in there...")),
    MSG_NPC(1, _(" But it helps that other\nrescue teams give us information about\nwhat's underground.")),
    MSG_NPC(1, _(" However...{WAIT_PRESS}\nWhatever became of Alakazam?")),
    MSG_NPC(1, _(" If he had fallen in\na dungeon, he would've been\nexpelled back here...")),
    MSG_NPC(1, _(" Since he hasn't returned,\ndoes it mean he's still in the dungeon?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives11_dlg2[] = { /* 0x81638c0 */
    DEBUGINFO_O(10698),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I talked to other rescue\nteams.")),
    MSG_NPC(1, _(" They all say the {COLOR YELLOW_D}Magma\nCavern{RESET} goes very deep.")),
    MSG_NPC(1, _(" I wonder exactly how deep\nit goes?")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s0_lives12_dlg2[] = { /* 0x81639bc */
    DEBUGINFO_O(10709),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I overheard some rescue\nteam Pokémon earlier.")),
    MSG_NPC(1, _(" They say it's very taxing\nbecause it's so easy to get burns there.")),
    MSG_NPC(1, _(" Please be careful of burns,\n{NAME_0}.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s1_station_sref_script[] = { /* 0x8163ad8 */
    DEBUGINFO_O(10720),
    SELECT_LIVES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g30_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g30_s1_station_sref_script }; /* 0x8163b18 */

static const struct ScriptCommand s_gs1_g30_s1_lives0_dlg0[] = { /* 0x8163b24 */
    DEBUGINFO_O(10729),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" {NAME_1}'s words\nshook me up with inspiration!")),
    MSG_NPC(3, _(" Especially the part about\ntaking pride...{WAIT_PRESS} That made me...{WAIT_PRESS}\nIt left me choked up...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" It isn't just you, my brother.{WAIT_PRESS}\nI am likewise inspired beyond words.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" B-Brother...{WAIT_PRESS}\nSniffle... My brother...")),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" I will do my best to obtain\neven better Technical Machines and Orbs.")),
    MSG_NPC(3, _(" All with the pride of a\nmerchant!")),
    ALERT_CUE(3),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    TEXTBOX_CLEAR,
    SELECT_LIVES(-1, 0),
    RET,
};

static const struct ScriptCommand s_gs1_g30_s1_lives1_dlg0[] = { /* 0x8163cf4 */
    DEBUGINFO_O(10761),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g30_s1_lives2_dlg0[] = { /* 0x8163d34 */
    DEBUGINFO_O(10768),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    RET,
};

static const struct ScriptCommand s_gs1_g30_s1_lives2_dlg2[] = { /* 0x8163dd4 */
    DEBUGINFO_O(10781),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  0,  1),
    MSG_NPC(1, _(" Oh, my goodness, yes!\n{NAME_2}'s talk was such an\ninspiration!")),
    MSG_NPC(1, _(" It has stoked a raging fire\nin our hearts!")),
    MSG_NPC(1, _(" I will keep bringing in fine\nmerchandise!{WAIT_PRESS} This, I do for you!{WAIT_PRESS}\nSo...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g30_s1_lives3_dlg0[] = { /* 0x8163eb4 */
    DEBUGINFO_O(10798),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    RET,
};

static const struct ScriptCommand s_gs1_g30_s1_lives3_dlg2[] = { /* 0x8163f64 */
    DEBUGINFO_O(10812),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E09A_8N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E09A_8N,  1,  1),
    EXECUTE_STATION(-1, 30, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g31_s0_station_sref_script[] = { /* 0x8164014 */
    DEBUGINFO_O(10826),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(1),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}And in the square...")),
    TEXTBOX_CLEAR,
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x28, 0x01,  0x0005,  0x00000014,  0x00ffffff, NULL },
    WAIT(20),
    RET,
};

static const struct ScriptRef s_gs1_g31_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g31_s0_station_sref_script }; /* 0x816412c */


static const struct ScriptCommand s_gs1_g31_s0_eff0_script[] = { /* 0x8164138 */
    DEBUGINFO_O(10848),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    CAMERA_INIT_PAN,
    WALK_GRID(256, 115),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g31_s0_lives0_dlg0[] = { /* 0x81641b8 */
    DEBUGINFO_O(10859),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_NPC(2, _(" Is {NAME_0}'s team\nalmost here?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    PORTRAIT(PLACEMENT_TOP_FLIP, 0x0003, 0x00000000),
    PORTRAIT_POS(3, -1, 0),
    MSG_NPC(3, _(" Look!\nHere they come!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    WAIT(20),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" It's true, darlings!")),
    TEXTBOX_CLEAR,
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Let's go!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    WAIT(90),
    ALERT_CUE(20),
    ALERT_CUE(6),
    ALERT_CUE(13),
    ALERT_CUE(15),
    ALERT_CUE(16),
    WALK_GRID(204, 116),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(12),
    WAIT(30),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000042),
    MSG_NPC(4, _(" Great work!\nGreat work, {NAME_0}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_RIGHT, 0x0007, 0x00000000),
    MSG_NPC(7, _(" You really took down that\nGroudon?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(6, _(" Darlings, it's fantastic!{WAIT_PRESS}\nYou have won me over!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Whoa!\nW-wait a second!")),
    MSG_NPC(1, _(" How does everyone know\nabout what happened underground?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0003, 0x00000000),
    PORTRAIT_POS(3, 1, 0),
    MSG_NPC(3, _(" Pelipper spread the word\nwith an extra edition of the Pokémon\nNews.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" You bunch became stronger\nthan I expected!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(7, _(" You can be proud of it!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" You lot did great!{WAIT_PRESS}\nWhy don't we team up sometime?\nGahahahaha!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    MSG_NPC(8, _(" You've earned everyone's\nrespect now.")),
    MSG_NPC(8, _(" Your {COLOR CYAN}Team {TEAM_NAME}{RESET}\nis a first-class rescue team.")),
    MSG_NPC(8, _(" Take pride in that.{WAIT_PRESS}\n{NAME_1}, {NAME_0}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT(5),
    PORTRAIT_REP(0x0001, 0x00000008),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sniff... Sniffle...{WAIT_PRESS}\n{NAME_0}!{WAIT_PRESS} This is great!")),
    VARIANT(/* == */  1, _(" All the work we put in...\nIt was all worth it!")),
    VARIANT(/* == */  3, _(" Sniff... Sniffle...{WAIT_PRESS}\n{NAME_0}!{WAIT_PRESS} I can't believe it!")),
    VARIANT(/* == */  3, _(" Everything we experienced...\nIt was all worthwhile!")),
    VARIANT_DEFAULT(_(" Sniff... Sniffle...{WAIT_PRESS}\n{NAME_0}!{WAIT_PRESS} This is great!")),
    VARIANT_DEFAULT(_(" Every bit of our effort...\nIt was all worthwhile!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" Would you look at that?{WAIT_PRESS}\nI didn't think someone that could take down\nGroudon'd be such a crybaby! Gahahahaha!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(20),
    ALERT_CUE(10),
    ALERT_CUE(7),
    WAIT(90),
    ALERT_CUE(20),
    ALERT_CUE(10),
    ALERT_CUE(7),
    BGM_FADEOUT(30),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(60),
    FANFARE_PLAY2(468),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Huh?{WAIT_PRESS} What was that?")),
    MSG_NPC(2, _(" I thought I heard something\njust for a moment...{WAIT_PRESS}\nDid I just imagine it?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(15),
    ALERT_CUE(16),
    ALERT_CUE(20),
    WAIT(60),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(60),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    MSG_NPC(3, _(" No. I heard it too.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(6, _(" Me too.{WAIT_PRESS}\nEven now, I hear it...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(7, _(" Someone talking?{WAIT_PRESS}\n...Not sure.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(12),
    ALERT_CUE(15),
    ALERT_CUE(16),
    ALERT_CUE(20),
    WAIT(60),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(60),
    { 0x2d, 0x09,  0x0009,  0x00000061,  0x00000000, NULL },
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_NORTH),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Th-this voice...{WAIT_PRESS}\nI remember this voice.")),
    VARIANT(/* == */  1, _(" This voice...{WAIT_PRESS} I think...{WAIT_PRESS}\nThat's it! It's {NAME_9}!")),
    VARIANT_DEFAULT(_(" Th-this voice...{WAIT_PRESS}\nI've heard it before.")),
    VARIANT_DEFAULT(_(" This voice...{WAIT_PRESS} I'm sure...{WAIT_PRESS}\nThat's it! It's {NAME_9}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    MSG_NPC(8, _(" {NAME_9}?{WAIT_PRESS}\nAh, that's it! Telepathy!")),
    MSG_NPC(8, _(" {NAME_9} is calling out\nto us using telepathy!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(30),
    BGM_SWITCH(19),
    { 0x2e, 0x00,  0x0009, -0x00000002,  0x00000000, NULL },
    MSG_NPC(9, _(" ...To all Pokémon!\nCalling all Pokémon!")),
    MSG_NPC(9, _(" Terrible, it is!{WAIT_PRESS}\nFrom the sky...{WAIT_PRESS} Falls a star...")),
    TEXTBOX_CLEAR,
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};















static const struct ScriptCommand s_gs1_g31_s0_lives1_dlg0[] = { /* 0x8165464 */
    DEBUGINFO_O(11075),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(204, 117),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WAIT(3),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(6),
    WAIT(5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_EAST),
    AWAIT_CUE(6),
    WAIT(5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives2_dlg0[] = { /* 0x8165654 */
    DEBUGINFO_O(11109),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(7),
    WALK_GRID(256, 123),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(7),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives3_dlg0[] = { /* 0x8165794 */
    DEBUGINFO_O(11132),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WALK_GRID(256, 121),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    WALK_RELATIVE(128, -8, 8),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(12, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(10),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    ROTATE(12, 10, DIRECTION_NORTHWEST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives4_dlg0[] = { /* 0x8165964 */
    DEBUGINFO_O(11164),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(9),
    WALK_GRID(256, 122),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(9),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WAIT(5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(9),
    WAIT(5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(9),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives5_dlg0[] = { /* 0x8165ab4 */
    DEBUGINFO_O(11188),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    WALK_GRID(256, 124),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(10),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(10),
    ROTATE(8, 10, DIRECTION_SOUTH),
    WAIT(45),
    ROTATE(8, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    ROTATE(8, 10, DIRECTION_SOUTH),
    WAIT(45),
    ROTATE(8, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives6_dlg0[] = { /* 0x8165c34 */
    DEBUGINFO_O(11215),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    WALK_GRID(256, 125),
    AWAIT_CUE(11),
    ROTATE(8, 10, DIRECTION_NORTH),
    WAIT(50),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    ROTATE(8, 10, DIRECTION_NORTH),
    WAIT(50),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives7_dlg0[] = { /* 0x8165d94 */
    DEBUGINFO_O(11240),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(12),
    WALK_GRID(256, 126),
    AWAIT_CUE(12),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(12),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(12),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(12),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives8_dlg0[] = { /* 0x8165ea4 */
    DEBUGINFO_O(11260),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(13),
    WALK_GRID(204, 118),
    AWAIT_CUE(13),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives9_dlg0[] = { /* 0x8165f34 */
    DEBUGINFO_O(11272),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(15),
    WALK_GRID(204, 119),
    AWAIT_CUE(15),
    ROTATE(12, 10, DIRECTION_NORTHWEST),
    WAIT(45),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(15),
    ROTATE(12, 10, DIRECTION_NORTHWEST),
    WAIT(45),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(15),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives10_dlg0[] = { /* 0x8166034 */
    DEBUGINFO_O(11291),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(16),
    WALK_GRID(204, 120),
    AWAIT_CUE(16),
    ROTATE(12, 10, DIRECTION_SOUTHWEST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(16),
    ROTATE(12, 10, DIRECTION_SOUTHWEST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_EAST),
    AWAIT_CUE(16),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives11_dlg0[] = { /* 0x8166134 */
    DEBUGINFO_O(11310),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WALK_GRID(256, 132),
    AWAIT_CUE(20),
    WAIT(5),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(20),
    WAIT(10),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_NORTHEAST),
    AWAIT_CUE(20),
    WAIT(10),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_NORTH),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives12_dlg0[] = { /* 0x81662a4 */
    DEBUGINFO_O(11336),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(45),
    WALK_GRID(256, 134),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(20),
    WAIT(3),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(20),
    WAIT(5),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_NORTH),
    AWAIT_CUE(20),
    WAIT(5),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_WEST),
    WAIT(15),
    ROTATE(12, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives13_dlg0[] = { /* 0x8166474 */
    DEBUGINFO_O(11368),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(30),
    WALK_GRID(256, 133),
    AWAIT_CUE(20),
    WAIT(6),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(20),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    WAIT(45),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(20),
    ROTATE(8, 10, DIRECTION_SOUTHEAST),
    WAIT(45),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives14_dlg0[] = { /* 0x81665d4 */
    DEBUGINFO_O(11393),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WALK_GRID(256, 128),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    WAIT(5),
    AWAIT_CUE(20),
    WAIT(7),
    ROTATE(12, 10, DIRECTION_WEST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(20),
    WAIT(7),
    ROTATE(12, 10, DIRECTION_WEST),
    WAIT(30),
    ROTATE(12, 10, DIRECTION_SOUTH),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives15_dlg0[] = { /* 0x8166724 */
    DEBUGINFO_O(11417),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(30),
    WALK_GRID(256, 129),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives16_dlg0[] = { /* 0x81667f4 */
    DEBUGINFO_O(11433),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WALK_GRID(256, 127),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives17_dlg0[] = { /* 0x81668b4 */
    DEBUGINFO_O(11448),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(45),
    WALK_GRID(256, 130),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(20),
    WAIT(2),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(20),
    WAIT(3),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives18_dlg0[] = { /* 0x81669d4 */
    DEBUGINFO_O(11469),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(20),
    WAIT(60),
    WALK_GRID(256, 131),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_START_FUNC),
    AWAIT_CUE(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(20),
    WAIT(12),
    ROTATE(12, 10, DIRECTION_EAST),
    WAIT(20),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(20),
    WAIT(12),
    ROTATE(12, 10, DIRECTION_EAST),
    WAIT(20),
    ROTATE(8, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(20),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives19_dlg0[] = { /* 0x8166b54 */
    DEBUGINFO_O(11496),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives19_dlg2[] = { /* 0x8166b84 */
    DEBUGINFO_O(11502),
    RET,
};

static const struct ScriptCommand s_gs1_g31_s0_lives20_dlg0[] = { /* 0x8166ba4 */
    DEBUGINFO_O(11507),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g31_s0_lives20_dlg2[] = { /* 0x8166bd4 */
    DEBUGINFO_O(11513),
    RET,
};

static const struct ScriptCommand s_gs1_g32_s0_station_sref_script[] = { /* 0x8166bf4 */
    DEBUGINFO_O(11518),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(19),
    { 0x27, 0x00,  0x0005,  0x00000020,  0x00ffffff, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g32_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g32_s0_station_sref_script }; /* 0x8166c74 */

static const struct ScriptCommand s_gs1_g32_s0_lives0_dlg0[] = { /* 0x8166c80 */
    DEBUGINFO_O(11531),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_NPC(8, _(" {NAME_9}.{WAIT_PRESS}\nTell us.")),
    MSG_NPC(8, _(" Can the falling star be\nstopped?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x2d, 0x09,  0x0007,  0x0000006c,  0x00000000, NULL },
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(30),
    { 0x2e, 0x00,  0x0009, -0x00000002,  0x00000000, NULL },
    MSG_NPC(9, _(" ............{WAIT_PRESS}There is a way.")),
    MSG_NPC(9, _(" ...To prevent collision,\nthere is but one solution.")),
    MSG_NPC(9, _(" You must ask {NAME_7}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" {NAME_7}?{WAIT_PRESS}\nWhat might that be?")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(30),
    MSG_NPC(9, _(" A Pokémon, living far above\nus in the sky.\nLegendary, it is.")),
    MSG_NPC(9, _(" {NAME_7} must be asked\nto destroy the star from the sky.")),
    MSG_NPC(9, _(" However...{WAIT_PRESS}\nFar, far up in the sky lives {NAME_7}.\nKnown by few and seen by none.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(8, _(" The sky...{WAIT_PRESS}\nHow are we to go there?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(30),
    MSG_NPC(9, _(" {NAME_8} and I\namplify our Teleport together...")),
    MSG_NPC(9, _(" And send Pokémon to the\nsky.")),
    MSG_NPC(9, _(" However...{WAIT_PRESS}\nThe sky is a world above the clouds.")),
    MSG_NPC(9, _(" What will become of the\nPokémon sent to the sky?{WAIT_PRESS}\nEven I can guess nothing...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_FLIP, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Then, we'll do it!{WAIT_PRESS}\nWe'll go!")),
    VARIANT(/* == */  3, _(" Then, we'll do it!{WAIT_PRESS}\nWe'll go!")),
    VARIANT_DEFAULT(_(" Then, we'll do it!{WAIT_PRESS}\nWe'll go!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(8, _(" I also...{WAIT_PRESS}\nI thought there could be none but you...")),
    MSG_NPC(8, _(" But...{WAIT_PRESS} Are you sure?{WAIT_PRESS}\nThere's no telling what you would find\nin that world above the clouds.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We expect danger!")),
    VARIANT(/* == */  1, _(" It's my wish that all\nPokémon can live in peace.")),
    VARIANT(/* == */  3, _(" We expect danger!")),
    VARIANT(/* == */  3, _(" It's my wish that all\nPokémon can live in peace.")),
    VARIANT_DEFAULT(_(" We expect danger!")),
    VARIANT_DEFAULT(_(" It's my wish that all\nPokémon can live in peace.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(487),
    { 0x28, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0001,  0x0000000f,  0x00ffffff, NULL },
    WAIT(30),
    MSG_NPC(9, _(" {NAME_1}, {NAME_0}.{WAIT_PRESS}\nDo you hear?{WAIT_PRESS} This is {NAME_9}.")),
    MSG_NPC(9, _(" Discuss we will,\n{NAME_8} and I, about how our\nTeleport can be amplified.")),
    MSG_NPC(9, _(" Departure, it is tomorrow.{WAIT_PRESS}\nRest you should until then.")),
    MSG_NPC(9, _(" Last word.{WAIT_PRESS}\nDangerous will be your adventure...{WAIT_PRESS}\nBut fail, you must not. Surpass yourselves.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" No problem!\nWe'll be fine!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}!\nLet's get it done!")),
    VARIANT_DEFAULT(_(" Right, {NAME_0}?\nLet's get it done!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};












static const struct ScriptCommand s_gs1_g32_s0_lives1_dlg0[] = { /* 0x8167744 */
    DEBUGINFO_O(11636),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives2_dlg0[] = { /* 0x8167814 */
    DEBUGINFO_O(11652),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives3_dlg0[] = { /* 0x8167854 */
    DEBUGINFO_O(11659),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00, -0x0008,  0x00000008,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives4_dlg0[] = { /* 0x81678a4 */
    DEBUGINFO_O(11667),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives5_dlg0[] = { /* 0x81678e4 */
    DEBUGINFO_O(11674),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives6_dlg0[] = { /* 0x8167924 */
    DEBUGINFO_O(11681),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives7_dlg0[] = { /* 0x8167964 */
    DEBUGINFO_O(11688),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives8_dlg0[] = { /* 0x81679a4 */
    DEBUGINFO_O(11695),
    SELECT_ANIMATION(5),
    WAIT(1),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives9_dlg0[] = { /* 0x8167a04 */
    DEBUGINFO_O(11704),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives10_dlg0[] = { /* 0x8167a34 */
    DEBUGINFO_O(11710),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives11_dlg0[] = { /* 0x8167a64 */
    DEBUGINFO_O(11716),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives12_dlg0[] = { /* 0x8167aa4 */
    DEBUGINFO_O(11723),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives13_dlg0[] = { /* 0x8167ae4 */
    DEBUGINFO_O(11730),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives14_dlg0[] = { /* 0x8167b24 */
    DEBUGINFO_O(11737),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives15_dlg0[] = { /* 0x8167b64 */
    DEBUGINFO_O(11744),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives16_dlg0[] = { /* 0x8167ba4 */
    DEBUGINFO_O(11751),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives17_dlg0[] = { /* 0x8167be4 */
    DEBUGINFO_O(11758),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g32_s0_lives18_dlg0[] = { /* 0x8167c24 */
    DEBUGINFO_O(11765),
    SELECT_ANIMATION(2),
    AWAIT_CUE(20),
    HALT,
};

static const struct ScriptCommand s_gs1_g33_s0_station_sref_script[] = { /* 0x8167c64 */
    DEBUGINFO_O(11772),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_TEAM_BASE),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(0, 0),
    CALL_STATION( 34,  0),
    BGM_SWITCH(19),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g33_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs1_g33_s0_station_sref_script }; /* 0x8167d34 */

static const struct ScriptCommand s_gs1_g33_s0_lives0_dlg0[] = { /* 0x8167d40 */
    DEBUGINFO_O(11790),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs1_g34_s0_station_sref_script[] = { /* 0x8167d80 */
    DEBUGINFO_O(11797),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs1_g34_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g34_s0_station_sref_script }; /* 0x8167db0 */

static const struct ScriptCommand s_gs1_g34_s0_lives0_dlg2[] = { /* 0x8167dbc */
    DEBUGINFO_O(11805),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}.")),
    VARIANT_DEFAULT(_(" {NAME_0}.")),
    TEXTBOX_CLEAR,
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Are you all ready for\nthe sky?")),
    VARIANT_DEFAULT(_(" Are you all ready for\nthe sky?")),
    CHOICE(/* label */  2, _("All set!")),
    CHOICE(/* label */  3, _("Not yet.")),
  LABEL(3), /* = 0x03 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right.")),
    VARIANT(/* == */  1, _(" Give me a shout when you're\nall set to go to the sky.")),
    VARIANT_DEFAULT(_(" OK.")),
    VARIANT_DEFAULT(_(" Just tell me when you're\nready to go to the sky.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Great!\nLooks like you're all set to roll!")),
    VARIANT(/* == */  1, _(" We leave tomorrow.")),
    VARIANT(/* == */  1, _(" Let's get plenty of rest\ntonight and get set for tomorrow.")),
    VARIANT(/* == */  1, _(" Tomorrow!{WAIT_PRESS}\nLet's give it everything we've got,\n{NAME_0}!")),
    VARIANT_DEFAULT(_(" Yup!\nLooks like we're ready to go!")),
    VARIANT_DEFAULT(_(" We leave tomorrow.")),
    VARIANT_DEFAULT(_(" So let's get plenty of rest\nfor tomorrow.")),
    VARIANT_DEFAULT(_(" Tomorrow!{WAIT_PRESS}\nLet's give it everything we can,\n{NAME_0}!")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(150),
    { 0x23, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(180),
    EXECUTE_FUNCTION(EVENT_M01E10A_L002),
    HALT,
};



static const struct ScriptCommand s_gs1_g34_s0_lives1_dlg2[] = { /* 0x8168208 */
    DEBUGINFO_O(11846),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  0,  1),
    MSG_NPC(1, _(" We hope you'll succeed!\nPlease don't give up!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives2_dlg2[] = { /* 0x81682ec */
    DEBUGINFO_O(11860),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  1,  1),
    MSG_NPC(1, _(" I also hope for your\nsuccess. Fight!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives3_dlg2[] = { /* 0x81683c4 */
    DEBUGINFO_O(11874),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  2,  1),
    MSG_NPC(1, _(" {NAME_0}, you're our\none hope!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives4_dlg2[] = { /* 0x8168494 */
    DEBUGINFO_O(11888),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  3,  1),
    MSG_NPC(1, _(" I'm rooting for your\nsuccess, {NAME_0}!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives5_dlg2[] = { /* 0x816856c */
    DEBUGINFO_O(11902),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  4,  1),
    MSG_NPC(1, _(" You'll do fine!{WAIT_PRESS}\nI'm sure you'll find success!\nHave confidence in yourselves!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives6_dlg2[] = { /* 0x8168674 */
    DEBUGINFO_O(11916),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_1N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_1N,  5,  1),
    MSG_NPC(1, _(" I don't know what sort of\nPokémon Rayquaza is...")),
    MSG_NPC(1, _(" But with you, I know it can\nbecome a friend!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives7_dlg2[] = { /* 0x8168798 */
    DEBUGINFO_O(11931),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Everything depends on you!\nDon't fail!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives8_dlg2[] = { /* 0x8168824 */
    DEBUGINFO_O(11940),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Darlings, I can't begin to\nimagine a world above the clouds...{WAIT_PRESS}\nThe best of luck!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives9_dlg2[] = { /* 0x81688dc */
    DEBUGINFO_O(11949),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Rayquaza is a legendary\nPokémon, isn't that right?")),
    MSG_NPC(1, _(" Getting to it sounds difficult\nenough...\nBut you can't fail!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives10_dlg2[] = { /* 0x81689c4 */
    DEBUGINFO_O(11959),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" If anyone can do it, it's you!\nKeep your faith!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives11_dlg2[] = { /* 0x8168a5c */
    DEBUGINFO_O(11968),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" This is getting heavy!")),
    MSG_NPC(1, _(" But I have this feeling\nthat you can do it.{WAIT_PRESS}\nWe need you to win!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives12_dlg2[] = { /* 0x8168b28 */
    DEBUGINFO_O(11978),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I will wait for you.")),
    MSG_NPC(1, _(" {NAME_0}, I'm sure that\nyou will succeed and come back.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives13_dlg2[] = { /* 0x8168be8 */
    DEBUGINFO_O(11988),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I will set out to confer\nwith Xatu.")),
    MSG_NPC(1, _(" You leave tomorrow.\nPrepare for your journey before then.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives14_dlg2[] = { /* 0x8168cbc */
    DEBUGINFO_O(11998),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I'm throwing in my lot with\n{COLOR CYAN}Team {TEAM_NAME}{RESET}!")),
    MSG_NPC(1, _(" Get out there and save\nthe world!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g34_s0_lives15_dlg2[] = { /* 0x8168d80 */
    DEBUGINFO_O(12008),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You can do it!{WAIT_PRESS}\nYou can stop the star from falling!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_station_sref_script[] = { /* 0x8168e18 */
    DEBUGINFO_O(12017),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g35_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g35_s0_station_sref_script }; /* 0x8168e58 */

static const struct ScriptCommand s_gs1_g35_s0_lives0_dlg2[] = { /* 0x8168e64 */
    DEBUGINFO_O(12026),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  0,  1),
    MSG_NPC(1, _(" I see you're heading out\nsoon.\nThe best of luck!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives1_dlg2[] = { /* 0x8168f48 */
    DEBUGINFO_O(12040),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  1,  1),
    MSG_NPC(1, _(" Ah, you're leaving?\nGood luck!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives2_dlg2[] = { /* 0x816901c */
    DEBUGINFO_O(12054),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  2,  1),
    MSG_NPC(1, _(" {NAME_0}, don't let us\ndown!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives3_dlg2[] = { /* 0x81690ec */
    DEBUGINFO_O(12068),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  3,  1),
    MSG_NPC(1, _(" I'm rooting for you!\nGo get 'em, {NAME_0}!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives4_dlg2[] = { /* 0x81691cc */
    DEBUGINFO_O(12082),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  4,  1),
    MSG_NPC(1, _(" This is it, isn't it?\nMake us proud!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives5_dlg2[] = { /* 0x81692a8 */
    DEBUGINFO_O(12096),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_3N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_3N,  5,  1),
    MSG_NPC(1, _(" Are you heading out now?\nDon't give up!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives6_dlg2[] = { /* 0x8169384 */
    DEBUGINFO_O(12110),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You're going, hey?\nBuckle down and get it done!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives7_dlg2[] = { /* 0x816941c */
    DEBUGINFO_O(12119),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_0}, take care,\ndarling.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives8_dlg2[] = { /* 0x816949c */
    DEBUGINFO_O(12128),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I can't even imagine what's\nup in the sky, but be brave!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives9_dlg2[] = { /* 0x816953c */
    DEBUGINFO_O(12137),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Go with care!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives10_dlg2[] = { /* 0x81695ac */
    DEBUGINFO_O(12146),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Oh, yeah. Leaving soon?")),
    MSG_NPC(1, _(" Give it your best shot!\nDon't you lose!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives11_dlg2[] = { /* 0x8169664 */
    DEBUGINFO_O(12156),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You guys can do it for sure!\nThere's nothing to worry about!")),
    MSG_NPC(1, _(" Go with confidence!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives12_dlg2[] = { /* 0x816972c */
    DEBUGINFO_O(12166),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Go for it! Take care!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives13_dlg2[] = { /* 0x81697a4 */
    DEBUGINFO_O(12175),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" WE CAME TO WISH YOU\nWELL TOO! BZBZBZZZT!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g35_s0_lives14_dlg2[] = { /* 0x8169830 */
    DEBUGINFO_O(12184),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" SAVE THE WORLD!\nBZBZBZZ!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_station_sref_script[] = { /* 0x81698ac */
    DEBUGINFO_O(12193),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g36_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g36_s0_station_sref_script }; /* 0x81698ec */

static const struct ScriptCommand s_gs1_g36_s0_lives0_dlg2[] = { /* 0x81698f8 */
    DEBUGINFO_O(12202),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  0,  1),
    MSG_NPC(1, _(" You still have everything\nto prove!\nThe best of luck!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives1_dlg2[] = { /* 0x81699e0 */
    DEBUGINFO_O(12216),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  1,  1),
    MSG_NPC(1, _(" {NAME_0}, I'm certain\nthat you will succeed!\nGood luck!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives2_dlg2[] = { /* 0x8169ac8 */
    DEBUGINFO_O(12230),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  2,  1),
    MSG_NPC(1, _(" It must be difficult, but\ndon't let us down!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives3_dlg2[] = { /* 0x8169bac */
    DEBUGINFO_O(12244),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  3,  1),
    MSG_NPC(1, _(" You're not finished yet!\nI hope I can serve you in good stead!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives4_dlg2[] = { /* 0x8169ca0 */
    DEBUGINFO_O(12258),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  4,  1),
    MSG_NPC(1, _(" I know you too well.")),
    MSG_NPC(1, _(" You're not about to ever\ngive up!")),
    MSG_NPC(1, _(" Your fight's only begun!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives5_dlg2[] = { /* 0x8169dcc */
    DEBUGINFO_O(12274),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M01E10A_5N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M01E10A_5N,  5,  1),
    MSG_NPC(1, _(" Everyone hopes you reach\nRayquaza.\nKeep it up!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives6_dlg2[] = { /* 0x8169eac */
    DEBUGINFO_O(12288),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" From failure comes success.\nKeep your faith!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives7_dlg2[] = { /* 0x8169f3c */
    DEBUGINFO_O(12297),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Darling, you've only begun.{WAIT_PRESS}\n{NAME_0}, keep your chin up!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives8_dlg2[] = { /* 0x8169fdc */
    DEBUGINFO_O(12306),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Huh? There's a tower of\nclouds in the sky?!{WAIT_PRESS}\nIt exists? Amazing!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives9_dlg2[] = { /* 0x816a084 */
    DEBUGINFO_O(12315),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I know exactly how gutsy\nyou are.")),
    MSG_NPC(1, _(" This is just a setback!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives10_dlg2[] = { /* 0x816a134 */
    DEBUGINFO_O(12325),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Go for it!\nDon't you lose!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives11_dlg2[] = { /* 0x816a1b4 */
    DEBUGINFO_O(12334),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You'll be fine!\nGo with confidence!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives12_dlg2[] = { /* 0x816a23c */
    DEBUGINFO_O(12343),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Get it done the next time!\nKeep at it!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives13_dlg2[] = { /* 0x816a2c4 */
    DEBUGINFO_O(12352),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" IT'S NOT OVER YET!\nBZBZBZZ!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g36_s0_lives14_dlg2[] = { /* 0x816a344 */
    DEBUGINFO_O(12361),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" THE TIME IS NOW!\nSAVE THE WORLD! BZBZBZZ!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g37_s0_station_sref_script[] = { /* 0x816a3d0 */
    DEBUGINFO_O(12370),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(240),
    { 0x23, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs1_g37_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g37_s0_station_sref_script }; /* 0x816a440 */

static const struct ScriptCommand s_gs1_g37_s0_eff0_script[] = { /* 0x816a44c */
    DEBUGINFO_O(12382),
    CAMERA_INIT_PAN,
    WALK_GRID(153, 135),
    HALT,
};

static const struct ScriptCommand s_gs1_g38_s0_station_sref_script[] = { /* 0x816a48c */
    DEBUGINFO_O(12389),
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs1_g38_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs1_g38_s0_station_sref_script }; /* 0x816a4cc */

static const struct ScriptCommand s_gs1_g38_s0_lives0_dlg2[] = { /* 0x816a4d8 */
    DEBUGINFO_O(12398),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  0,  1),
    MSG_NPC(1, _(" Yes! You did it,\n{NAME_0}!")),
    MSG_NPC(1, _(" Now that peace has been\nrestored, I can sell my wares with\npeace of mind.")),
    MSG_NPC(1, _(" Thank you so much!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives1_dlg2[] = { /* 0x816a628 */
    DEBUGINFO_O(12414),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  1,  1),
    EXECUTE_STATION(-1, 38, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives2_dlg2[] = { /* 0x816a6d8 */
    DEBUGINFO_O(12428),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 2, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  2,  1),
    MSG_NPC(1, _(" Peace has returned!\nThank you, {NAME_0}!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives3_dlg2[] = { /* 0x816a7b0 */
    DEBUGINFO_O(12442),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 3, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  3,  1),
    MSG_NPC(1, _(" Thank you so much!\nI can keep my shop running, thanks to you!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives4_dlg2[] = { /* 0x816a8a4 */
    DEBUGINFO_O(12456),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 4, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  4,  1),
    MSG_NPC(1, _(" You did it! Good for you!\nThat is so cool!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives5_dlg2[] = { /* 0x816a980 */
    DEBUGINFO_O(12470),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  5,  1),
    MSG_NPC(1, _(" It's peaceful again!\nThank you! I never expected less from\nyou, my friend!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives6_dlg2[] = { /* 0x816aa80 */
    DEBUGINFO_O(12484),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You guys were amazing...{WAIT_PRESS}\nTruly, you've impressed me.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives7_dlg2[] = { /* 0x816ab1c */
    DEBUGINFO_O(12493),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" You've done it,\n{NAME_0}!\nYou're the greatest! Really!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives8_dlg2[] = { /* 0x816abb8 */
    DEBUGINFO_O(12502),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" {NAME_0}! {NAME_2}!\nYou both hung in there! Great job!")),
    MSG_NPC(1, _(" ...But you're still not up to\nour caliber!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives9_dlg2[] = { /* 0x816ac98 */
    DEBUGINFO_O(12513),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We're here now because\nyou succeeded! You have my thanks!")),
    MSG_NPC(1, _(" ...Of course, we did our bit\nto help too!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives10_dlg2[] = { /* 0x816ad78 */
    DEBUGINFO_O(12523),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" THANK YOU, BZBZBZZ!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives11_dlg2[] = { /* 0x816adf0 */
    DEBUGINFO_O(12532),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" AWESOME! AWESOME!\nBZBZBZZZT!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives12_dlg2[] = { /* 0x816ae70 */
    DEBUGINFO_O(12541),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We will soon be departing\nthe area.")),
    MSG_NPC(1, _(" Sincerely, thank you for\nall the help and kindness you've given us.")),
    MSG_NPC(1, _(" {NAME_0} and\n{NAME_2}, please do take care!")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s0_lives13_dlg2[] = { /* 0x816af9c */
    DEBUGINFO_O(12553),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" We will soon be leaving\nthis area.")),
    MSG_NPC(1, _(" We Jumpluff travel the\nworld, carried wherever the winds will\ntake us.")),
    MSG_NPC(1, _(" {NAME_0} and\n{NAME_2}, we owe so much to you.")),
    MSG_NPC(1, _(" Thank you for everything.{WAIT_PRESS}\nMay we meet again.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s1_station_sref_script[] = { /* 0x816b104 */
    DEBUGINFO_O(12566),
    SELECT_LIVES(-1, 1),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g38_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g38_s1_station_sref_script }; /* 0x816b144 */

static const struct ScriptCommand s_gs1_g38_s1_lives0_dlg0[] = { /* 0x816b150 */
    DEBUGINFO_O(12575),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    WAIT(1),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" I'm all shaken up with\nemotion!")),
    MSG_NPC(3, _(" Knowing that the square will\nbe safe...{WAIT_PRESS} That made me...{WAIT_PRESS}\nIt left me choked up...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" It isn't just you, my brother.{WAIT_PRESS}\nI am likewise overcome with joy.")),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" B-Brother...{WAIT_PRESS}\nSniffle... My brother...")),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" {NAME_0} and\n{NAME_1}...{WAIT_PRESS}\nWe only have gratitude for you.")),
    MSG_NPC(3, _(" Thank you ever so much!")),
    ALERT_CUE(3),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    RET,
};

static const struct ScriptCommand s_gs1_g38_s1_lives1_dlg0[] = { /* 0x816b424 */
    DEBUGINFO_O(12606),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(7),
    SELECT_ANIMATION(4),
    RET,
};

static const struct ScriptCommand s_gs1_g38_s1_lives1_dlg2[] = { /* 0x816b4d4 */
    DEBUGINFO_O(12620),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  0,  1),
    MSG_NPC(1, _(" Oh, my, you've outdone\nyourself, {NAME_0}!")),
    MSG_NPC(1, _(" Because peace has been\nrestored, I may go about securely in my\nbusiness.")),
    MSG_NPC(1, _(" Thank you ever so much!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g38_s1_lives2_dlg0[] = { /* 0x816b620 */
    DEBUGINFO_O(12636),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WAIT(30),
    SELECT_ANIMATION(4),
    RET,
};

static const struct ScriptCommand s_gs1_g38_s1_lives2_dlg2[] = { /* 0x816b6f0 */
    DEBUGINFO_O(12652),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_M02E01A_2N, 1, /* to label */ 0),
    SET_ARRAYVAL(EVENT_M02E01A_2N,  1,  1),
    EXECUTE_STATION(-1, 38, 1),
    HALT,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g39_s0_lives0_dlg2[] = { /* 0x816b7a0 */
    DEBUGINFO_O(12666),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" Have you made room so\nI may join your rescue team?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("No.")),
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x1d,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 2),
    MSG_NPC(1, _(" Thank you!")),
    FANFARE_PLAY(204),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_1} \n{CENTER_ALIGN}became a member!")),
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    { 0x3b, 0x1e,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to {NAME_1}?")),
    CHOICE(/* label */  3, _("*Yes.")),
    CHOICE(/* label */  4, _("No.")),
  LABEL(3), /* = 0x03 */
    RENAME_ALLY(-1),
  LABEL(4), /* = 0x04 */
    { 0x3b, 0x1f,  0x0000,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    SCENARIO_CALC(SCENARIO_SUB1, 32,  3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    CANCEL_ENTITIES(39, -1),
    WAIT(30),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    MSG_NPC(1, _(" Yes!\nThank you!")),
    MSG_NPC(1, _(" ...But there appears to be\nno room for me in my Friend Area...{WAIT_PRESS}\nHow disappointing...")),
    MSG_NPC(1, _(" I would be able to join your\nrescue team if there were less Pokémon\nin {COLOR GREEN}Sky Blue Plains{RESET}...")),
    MSG_NPC(1, _(" Please let me know then.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_NPC(1, _(" Oh, I see...")),
    MSG_NPC(1, _(" There still is no room for\nme in the Friend Area I must go to...\nHow disappointing...")),
    MSG_NPC(1, _(" I would be able to join your\nrescue team if there were less Pokémon\nin {COLOR GREEN}Sky Blue Plains{RESET}...")),
    MSG_NPC(1, _(" Please let me know then.")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g40_s0_lives0_dlg0[] = { /* 0x816bc04 */
    DEBUGINFO_O(12711),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g40_s0_lives0_dlg2[] = { /* 0x816bc34 */
    DEBUGINFO_O(12717),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    WAIT(1),
    ALERT_CUE(6),
    WAIT(30),
    MSG_NPC(1, _(" Huh? What's that?{WAIT_PRESS}\n...Oh, you mean what happened at sea?")),
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_NPC(1, _(" I wasn't drowning!{WAIT_PRESS}\nSheesh, they're making up stories about\nme!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000000),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Want to know what really\nhappened?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(3), /* = 0x03 */
    ALERT_CUE(6),
    MSG_NPC(1, _(" Tch! Fine, then!\nHumph!")),
    RESET_ARRAY(EVENT_LOCAL),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" See, I went out to the sea\nto frolic a while back.")),
    MSG_NPC(1, _(" You know?{WAIT_PRESS}\nI was trying that Dive thing.")),
    PORTRAIT_REP(0x0001, 0x00000003),
    MSG_NPC(1, _(" So, I was having fun\ngoing underwater...{WAIT_PRESS}\nAnd I got washed out to sea a bit.")),
    MSG_NPC(1, _(" All of a sudden, these\nwicked clouds rolled in...")),
    MSG_NPC(1, _(" And before I knew it, there\nwas a full-blown storm raging!")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" There's more!{WAIT_PRESS}\nA dungeon appeared in the sea!")),
    MSG_NPC(1, _(" I was shocked witless!\nI got out of there fast!")),
    MSG_NPC(1, _(" But who'd've guessed it?\nA dungeon in a stormy sea!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    SELECT_ANIMATION(5),
    WAIT(45),
    SELECT_ANIMATION(2),
    WAIT(30),
    FANFARE_PLAY2(468),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Huh?{WAIT_PRESS}\nYou want to know more about that\ndungeon in the sea?")),
    MSG_NPC(1, _(" I vamoosed it out of there,\nso I can't tell you much...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    WAIT(60),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    WAIT(30),
    MSG_NPC(1, _(" I know!{WAIT_PRESS}\nMaybe Whiscash would know something.")),
    MSG_NPC(1, _(" Yeah, that'd be best.\nGo talk to Whiscash.")),
    TEXTBOX_CLEAR,
    RESET_ARRAY(EVENT_LOCAL),
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 33, 3, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB2, 33,  3),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(END_TALK),
};



static const struct ScriptCommand s_gs1_g40_s0_lives0_dlg3[] = { /* 0x816c390 */
    DEBUGINFO_O(12784),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x0000005e,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x92, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x92, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
  LABEL(0), /* = 0x00 */
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(2),
    WAIT(12),
    RET,
};

static const struct ScriptCommand s_gs1_g41_s0_lives0_dlg0[] = { /* 0x816c510 */
    DEBUGINFO_O(12811),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g41_s0_lives0_dlg2[] = { /* 0x816c540 */
    DEBUGINFO_O(12817),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I have heard of a weather\nanomaly afflicting a certain sea.")),
    MSG_NPC(1, _(" They say a whirlpool\nstretches from sea to sky in a\ncolossal tornado.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" It is said to be near the\n{COLOR GREEN}Legendary Island{RESET} Friend Area.")),
    MSG_NPC(1, _(" It hasn't caused any damage\nso far as I know...{WAIT_PRESS}\nBut it does concern me.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    MSG_NPC(1, _(" The {COLOR GREEN}Legendary Island{RESET}\nbelongs to your team.")),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Will you travel to the\n{COLOR GREEN}Legendary Island{RESET} and observe what is\ntaking place?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(3), /* = 0x03 */
    MSG_NPC(1, _(" Feeling contrary today?{WAIT_PRESS}\nWe need your help, please.")),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Will you travel to the\n{COLOR GREEN}Legendary Island{RESET} and observe what is\ntaking place?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    MSG_NPC(1, _(" Ah, good.\nYou accept the job.")),
    MSG_NPC(1, _(" I hope for the best from\nyou.")),
    TEXTBOX_CLEAR,
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 34, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB2, 34,  2),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(END_TALK),
};



static const struct ScriptCommand s_gs1_g41_s0_lives0_dlg3[] = { /* 0x816c958 */
    DEBUGINFO_O(12854),
    { 0x52, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x8d, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(2),
    WAIT(12),
    RET,
};

static const struct ScriptCommand s_gs1_g42_s0_lives0_dlg2[] = { /* 0x816ca38 */
    DEBUGINFO_O(12871),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004d,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_NPC(1, _(" It's cool and all that it's\npeaceful, but...")),
    MSG_NPC(1, _(" There's also been no\nexcitement. It's a little sad.")),
    MSG_NPC(1, _(" I wish there was some\npizzazz to spice things up...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives1_dlg0[] = { /* 0x816cb70 */
    DEBUGINFO_O(12883),
    CANCEL_ENTITIES(1, 0),
    RET,
};

static const struct ScriptCommand s_gs1_g42_s0_lives1_dlg2[] = { /* 0x816cba0 */
    DEBUGINFO_O(12889),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x0000004f,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_NPC(1, _(" Good morning.")),
    MSG_NPC(1, _(" Ahh... Another refreshing\nday...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives2_dlg2[] = { /* 0x816cc54 */
    DEBUGINFO_O(12900),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives3_dlg2[] = { /* 0x816ccb4 */
    DEBUGINFO_O(12909),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives4_dlg2[] = { /* 0x816cd14 */
    DEBUGINFO_O(12918),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives5_dlg2[] = { /* 0x816cd74 */
    DEBUGINFO_O(12927),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_lives6_dlg2[] = { /* 0x816cdd4 */
    DEBUGINFO_O(12936),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g42_s0_evt0_sref_script[] = { /* 0x816ce34 */
    DEBUGINFO_O(12945),
    EXECUTE_STATION(-1, 43, 0),
    HALT,
};

static const struct ScriptRef s_gs1_g42_s0_evt0_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs1_g42_s0_evt0_sref_script }; /* 0x816ce64 */

static const struct ScriptCommand s_gs1_g43_s0_station_sref_script[] = { /* 0x816ce70 */
    DEBUGINFO_O(12953),
    SELECT_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    WAIT(10),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S04E01A_L001),
    RET,
};

static const struct ScriptRef s_gs1_g43_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g43_s0_station_sref_script }; /* 0x816cef0 */

static const struct ScriptCommand s_gs1_g43_s0_eff0_script[] = { /* 0x816cefc */
    DEBUGINFO_O(12966),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(4),
    WALK_RELATIVE(512, -256, 0),
    HALT,
};

static const struct ScriptCommand s_gs1_g43_s0_lives0_dlg0[] = { /* 0x816cf4c */
    DEBUGINFO_O(12974),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT_FLIP, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Oh?")),
    MSG_NPC(3, _(" Who is that? Over there.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Never seen it before.{WAIT_PRESS}\nIt's not from around these parts.")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(120),
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(20),
    ALERT_CUE(4),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    { 0x58, 0x01,  0x0000,  0x000001c0,  0x00000138, NULL },
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    MSG_NPC(-1, _(" No more...{WAIT_PRESS}\nI can't walk anymore...")),
    MSG_NPC(-1, _(" I'm falling down...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Goodness!{WAIT_PRESS}\nIt needs help!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    ALERT_CUE(8),
    ALERT_CUE(7),
    ALERT_CUE(6),
    WALK_RELATIVE(460, -160, 0),
    HALT,
};





static const struct ScriptCommand s_gs1_g43_s0_lives1_dlg0[] = { /* 0x816d2cc */
    DEBUGINFO_O(13025),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(6),
    { 0x58, 0x01,  0x0000,  0x000001d0,  0x00000150, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(460, -200, 0),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g43_s0_lives2_dlg0[] = { /* 0x816d39c */
    DEBUGINFO_O(13041),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_WEST),
    WAIT(10),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x58, 0x01,  0x0000,  0x000001f0,  0x00000138, NULL },
    AWAIT_CUE(7),
    WALK_RELATIVE(460, -200, 0),
    HALT,
};

static const struct ScriptCommand s_gs1_g43_s0_lives3_dlg0[] = { /* 0x816d48c */
    DEBUGINFO_O(13059),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ROTATE(4, 10, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x58, 0x01,  0x0000,  0x000001f0,  0x00000150, NULL },
    AWAIT_CUE(8),
    WALK_RELATIVE(460, -200, 0),
    HALT,
};

static const struct ScriptCommand s_gs1_g43_s0_lives4_dlg0[] = { /* 0x816d56c */
    DEBUGINFO_O(13076),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WAIT(20),
    SELECT_ANIMATION(5),
    WALK_RELATIVE(256, 8, -8),
    WAIT(60),
    WALK_RELATIVE(256, 8, 8),
    WAIT(60),
    WALK_RELATIVE(256, 8, -8),
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    WAIT(45),
    WALK_RELATIVE(256, 8, 8),
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    WAIT(45),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    FANFARE_PLAY2(809),
    { 0x54, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    ROTATE(1, 10, DIRECTION_SOUTH),
    WAIT(10),
    { 0xe2, 0x00,  0x0329,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    FANFARE_PLAY2(510),
    WAIT(60),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs1_g44_s0_lives0_dlg2[] = { /* 0x816d78c */
    DEBUGINFO_O(13113),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000073,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000001),
    MSG_NPC(1, _(" I...{WAIT_PRESS}\nI've given up on ever seeing the mirage\nPokémon...")),
    MSG_NPC(1, _(" I...{WAIT_PRESS}\nI've reached the limit of my endurance...")),
    MSG_NPC(1, _(" I'm as tired as tired can\nbe...")),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs1_g45_s0_lives0_dlg2[] = { /* 0x816d8b4 */
    DEBUGINFO_O(13125),
    EXECUTE_STATION(-1, 45, 1),
    HALT,
};

static const struct ScriptCommand s_gs1_g45_s1_station_sref_script[] = { /* 0x816d8e4 */
    DEBUGINFO_O(13131),
    SELECT_ENTITIES(-1, -1),
    AWAIT_CUE(3),
    SCENARIO_CALC(SCENARIO_SUB4, 43,  2),
    RET,
};

static const struct ScriptRef s_gs1_g45_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs1_g45_s1_station_sref_script }; /* 0x816d934 */

static const struct ScriptCommand s_gs1_g45_s1_lives0_dlg0[] = { /* 0x816d940 */
    DEBUGINFO_O(13141),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Wh-wh-wh-what?!")),
    MSG_NPC(2, _(" You've seen the mirage\nPokémon?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Wh-wh-what sort of a\nPokémon was it?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" ...I see.")),
    MSG_NPC(2, _(" ............I see, I see.")),
    MSG_NPC(2, _(" ...Ah... Understood.\nSo, it is named Ho-Oh...")),
    MSG_NPC(2, _(" Ah, I see indeed!{WAIT_PRESS}\nTruly!{WAIT_PRESS} Truly, I envy you!")),
    { 0x3b, 0x23,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 1),
    COND_EQUAL(1, /* to label */ 1),
    MSG_NPC(2, _(" ...Wait!{WAIT_PRESS} Huh?!{WAIT_PRESS}\nYou are!{WAIT_PRESS} You are the one-and-only Ho-Oh?!")),
    ALERT_CUE(7),
    AWAIT_CUE(5),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x3b, 0x23,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(2, /* to label */ 2),
    MSG_NPC(2, _(" Wroooooooah!")),
    MSG_NPC(2, _(" I...{WAIT_PRESS} You...{WAIT_PRESS}\nYou've made me open my eyes!")),
    MSG_NPC(2, _(" Well, they still look googly,\nbut still...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" The lesson is: we mustn't\never give up!")),
    MSG_NPC(2, _(" Because if you give up,\nthat's when it ends!")),
    MSG_NPC(2, _(" Thank you!{WAIT_PRESS}\nYou have inspired me to resume my\ntravels!")),
    MSG_NPC(2, _(" I will again travel the\nworld to find rare Pokémon, perhaps even\nbefore you.{WAIT_PRESS} Farewell!")),
    TEXTBOX_CLEAR,
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Waaaaaaaaaaaah!")),
    MSG_NPC(2, _(" My head...{WAIT_PRESS} Is spinning...{WAIT_PRESS}\nMy head's spinning...{WAIT_PRESS} Waaaaaah!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" I'm so sorry I keeled over\nlike that...")),
    MSG_NPC(2, _(" And you even came to my\naid when I was down...{WAIT_PRESS}\nThank you...")),
    MSG_NPC(2, _(" But I...{WAIT_PRESS}\nI'm feeling overcome by emotion.")),
    MSG_NPC(2, _(" Never...{WAIT_PRESS}\nNever did I expect to meet the mirage\nPokémon...")),
    MSG_NPC(2, _(" I feel giddily elated...")),
    MSG_NPC(2, _(" The lesson is we mustn't\never give up!")),
    MSG_NPC(2, _(" Because if you give up,\nthat's when it ends!")),
    MSG_NPC(2, _(" Thank you!{WAIT_PRESS}\nYou have inspired me to resume my\ntravels!")),
    MSG_NPC(2, _(" My meeting you...\nIt will be a memory I will cherish\nforever!")),
    MSG_NPC(2, _(" I will keep the memory...{WAIT_PRESS}\nin a special place deep in my heart!{WAIT_PRESS}\nFarewell!")),
    TEXTBOX_CLEAR,
  LABEL(3), /* = 0x03 */
    ALERT_CUE(7),
    { 0x52, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    WALK_RELATIVE(256, -32, 0),
    { 0x8e, 0x0f,  0x000a,  0x00000073,  0x00000000, NULL },
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_SOUTH),
    AWAIT_CUE(5),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs1_g45_s1_lives1_dlg0[] = { /* 0x816e32c */
    DEBUGINFO_O(13229),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(4),
    WAIT(60),
    { 0x54, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x3b, 0x23,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(1, /* to label */ 0),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(20),
    ALERT_CUE(5),
    AWAIT_CUE(7),
  LABEL(0), /* = 0x00 */
    SELECT_ANIMATION(4),
    WAIT(60),
    { 0x54, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(762),
    SELECT_ANIMATION(17),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe2, 0x00,  0x02fa,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(510),
    WAIT(60),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x3b, 0x23,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(2, /* to label */ 1),
    SELECT_ANIMATION(4),
    WAIT(80),
    SELECT_ANIMATION(2),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    FANFARE_PLAY2(473),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe2, 0x00,  0x01d9,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(4),
    WAIT(80),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    FANFARE_PLAY2(510),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
  LABEL(2), /* = 0x02 */
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(20),
    SELECT_ANIMATION(5),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(30),
    WALK_RELATIVE(256, 8, 16),
    ALERT_CUE(5),
    WAIT(60),
    WALK_RELATIVE(256, -8, 16),
    WAIT(60),
    WALK_RELATIVE(256, 8, 16),
    WAIT(60),
    WALK_RELATIVE(256, -8, 16),
    WAIT(60),
    WALK_RELATIVE(256, 8, 16),
    ROTATE(4, 10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    WAIT(30),
    WALK_RELATIVE(256, -8, 16),
    WAIT(60),
    WALK_RELATIVE(256, 8, 16),
    ROTATE(4, 10, DIRECTION_SOUTH),
    WAIT(30),
    WALK_RELATIVE(256, -8, 16),
    WAIT(30),
    WALK_RELATIVE(256, 8, 16),
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g46_s0_station_sref_script[] = { /* 0x816e8bc */
    DEBUGINFO_O(13321),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_TEAM_BASE),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs1_g46_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g46_s0_station_sref_script }; /* 0x816e97c */

static const struct ScriptCommand s_gs1_g46_s0_eff0_script[] = { /* 0x816e988 */
    DEBUGINFO_O(13338),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WALK_RELATIVE(256, -32, 0),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g46_s0_lives0_dlg0[] = { /* 0x816e9f8 */
    DEBUGINFO_O(13348),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0005, 0x00000001),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" ...I've always wondered...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(15),
    MSG_NPC(3, _(" Who would be the most\npowerful Pokémon of all?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" What, there's someone\nbesides Rayquaza?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Is that it?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Well, sheesh, Rayquaza\ndestroyed a star!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    MSG_NPC(5, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(10),
    MSG_NPC(2, _(" Who else but Rayquaza\nwould be able to do that?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    MSG_NPC(5, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" But there's Groudon.\nIsn't that tough?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Is that true?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Why, even Alakazam's team\ncouldn't defeat it!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    MSG_NPC(5, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(10),
    MSG_NPC(3, _(" Legend has it that Groudon\nshaped continents.\nIt's an incredible Pokémon!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    MSG_NPC(5, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    TEXTBOX_CLEAR,
    WAIT(30),
    WALK_GRID(256, 137),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Hey, you came along at\nthe right time.")),
    MSG_NPC(2, _(" We're having a little\nargument about who the most powerful\nPokémon happens to be.")),
    MSG_NPC(2, _(" {NAME_0}, what do you\nthink?")),
    TEXTBOX_CLEAR,
    ASK3( TRUE, /*default*/ -1, /* speaker */ 2, _(" Who do you think is the\nmost powerful Pokémon?")),
    CHOICE(/* label */  5, _("Rayquaza.")),
    CHOICE(/* label */  6, _("Groudon.")),
    CHOICE(/* label */  7, _("Me.")),
  LABEL(5), /* = 0x05 */
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Oh, yeah?\n{NAME_0}, you think so too?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0002, 0x00000002),
    MSG_NPC(2, _(" Yeah, you bet it is!{WAIT_PRESS}\nRayquaza is the toughest!")),
    TEXTBOX_CLEAR,
    JUMP_LABEL(8),
  LABEL(6), /* = 0x06 */
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 2),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Ah, yes!\n{NAME_0}! Isn't that right!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Groudon is the most\npowerful when all's said and done!")),
    TEXTBOX_CLEAR,
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 3),
    FANFARE_PLAY2(470),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0003, 0x00000001),
    PORTRAIT(PLACEMENT_LEFT_FLIP, 0x0004, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_LEFT_FLIP, 0x0005, 0x00000000),
    MSG_NPC(2, _("....................................")),
    MSG_NPC(3, _("...................................")),
    MSG_NPC(4, _("....................................")),
    MSG_NPC(5, _("....................................")),
    MSG_LETTER(_("...............................................................\n...............................................................\n...............................................................")),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_NPC(2, _(" ...{WAIT_PRESS}Well, uh...{WAIT_PRESS}\nI know you want to become tougher, but...")),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_NPC(3, _(" I hope you never give up\nchasing your dreams.")),
    TEXTBOX_CLEAR,
    WAIT(10),
  LABEL(8), /* = 0x08 */
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0003, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0004, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0005, 0x00000001),
    WAIT(60),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    WAIT(30),
    MSG_NPC(4, _(" ...Um...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    WAIT(60),
    MSG_NPC(4, _(" I heard this story...")),
    MSG_NPC(4, _(" Somewhere in the world is\na Pokémon that was made for fighting.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" A Pokémon...{WAIT_PRESS}\nmade for fighting?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" Yup.")),
    MSG_NPC(4, _(" They say it has so much\nfighting power...")),
    MSG_NPC(4, _(" All it can think of is\ndefeating anything it meets.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    PORTRAIT_REP(0x0003, 0x00000001),
    MSG_NPC(3, _(" Th-that's rather a savage\nPokémon! I shudder to think...")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Where might such a horrid\nPokémon be now?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" Rumors say...{WAIT_PRESS}\nit is storing its power...")),
    MSG_NPC(4, _(" They say it is sleeping in\na dungeon somewhere...")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(60),
    WAIT(30),
    MSG_NPC(-1, _(" That rumor...{WAIT_PRESS}\nIt's true...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    BGM_SWITCH(9),
    ALERT_CUE(11),
    ALERT_CUE(12),
    WAIT(120),
    { 0x62, 0x00,  0x0080,  0x00000010,  0x00000000, NULL },
    AWAIT_CUE(5),
    MSG_NPC(2, _(" {NAME_6}...{WAIT_PRESS}\nAnd {NAME_7}...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" Oh my gosh!\nWhat happened to you?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" They're hurt bad...{WAIT_PRESS}\nWhat exactly happened?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0006, 0x00000003),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0007, 0x00000003),
    MSG_NPC(7, _(" Urgh...{WAIT_PRESS}\nIt's what that {NAME_4} was saying...")),
    MSG_NPC(7, _(" ...We were wiped out by\nthat Pokémon...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(473),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    MSG_NPC(2, _(" Wh-what did you say?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(6, _(" Grgh... There's no mistake...{WAIT_PRESS}\nIt said it was born to fight...")),
    MSG_NPC(6, _(" ...But that Pokémon's\npower...{WAIT_PRESS}\nThere was nothing fake about it...")),
    MSG_NPC(6, _(" ...It really was the most\npowerful...{WAIT_PRESS}\n...Gfah!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    FANFARE_PLAY2(473),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    MSG_NPC(2, _(" Ch-{NAME_6}!\nAre you OK?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    WAIT(60),
    MSG_NPC(7, _(" There is a cave...\nfar in the west...{WAIT_PRESS}\nIt's there...")),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    MSG_NPC(7, _(" I never want...{WAIT_PRESS}\nto go back again...{WAIT_PRESS} Gfwoh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(12),
    AWAIT_CUE(5),
    FANFARE_PLAY2(473),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    MSG_NPC(3, _(" Oh, my gosh!\nBlastoise went down, too!{WAIT_PRESS}\nThey need help now!")),
    MSG_NPC(3, _(" I'll go get someone!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    WAIT(60),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    PORTRAIT(PLACEMENT_TOP_RIGHT_FLIP, 0x0005, 0x00000000),
    MSG_NPC(2, _(" ...Wow, it really exists...{WAIT_PRESS}\nA Pokémon that tough...")),
    ALERT_CUE(9),
    ALERT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    MSG_NPC(2, _(" ...But, you know?{WAIT_PRESS}\nSo we now know that Pokémon is in the\n{COLOR YELLOW_D}Western Cave{RESET}...")),
    MSG_NPC(2, _(" I still don't feel like going\nout there...")),
    MSG_NPC(2, _(" Going anywhere like that'd\nbe too scary by half!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" I'm scared too...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    AWAIT_CUE(5),
    ALERT_CUE(10),
    PORTRAIT_REP(0x0005, 0x00000001),
    MSG_NPC(5, _(" Wobbuffet!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}The cave shunned\n{CENTER_ALIGN}by all out of fear...")),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR YELLOW_D}Western Cave{RESET}\n{CENTER_ALIGN}is now open for exploration!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    ALERT_CUE(3),
    AWAIT_CUE(5),
    RET,
};





















static const struct ScriptCommand s_gs1_g46_s0_lives1_dlg0[] = { /* 0x817094c */
    DEBUGINFO_O(13701),
    END_DELETE,
    RET,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g46_s0_lives2_dlg0[] = { /* 0x81709ac */
    DEBUGINFO_O(13710),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    CALL_SCRIPT(SWEAT_FUNC),
    ALERT_CUE(5),
  LABEL(3), /* = 0x03 */
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    AWAIT_CUE(7),
    WALK_GRID(256, 138),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(7),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    RET,
};

static const struct ScriptCommand s_gs1_g46_s0_lives3_dlg0[] = { /* 0x8170d6c */
    DEBUGINFO_O(13773),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    AWAIT_CUE(8),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
  LABEL(0), /* = 0x00 */
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    CALL_SCRIPT(SWEAT_FUNC),
  LABEL(3), /* = 0x03 */
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    AWAIT_CUE(8),
    SELECT_ANIMATION(9),
    WAIT(60),
    SELECT_ANIMATION(2),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    AWAIT_CUE(8),
    WALK_GRID(256, 139),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(8),
    WALK_GRID(768, 140),
    WALK_GRID(768, 141),
    END_DELETE,
};

static const struct ScriptCommand s_gs1_g46_s0_lives4_dlg0[] = { /* 0x817113c */
    DEBUGINFO_O(13837),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
  LABEL(0), /* = 0x00 */
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    CALL_SCRIPT(SWEAT_FUNC),
  LABEL(3), /* = 0x03 */
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(9),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(9),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(9),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(9),
    RET,
};

static const struct ScriptCommand s_gs1_g46_s0_lives5_dlg0[] = { /* 0x817145c */
    DEBUGINFO_O(13890),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000004f,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(10),
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    COND_EQUAL(3, /* to label */ 2),
  LABEL(0), /* = 0x00 */
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    CALL_SCRIPT(SWEAT_FUNC),
  LABEL(3), /* = 0x03 */
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000059,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000004d,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x93, 0x04,  0x000a,  0x0000006d,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    RET,
};

static const struct ScriptCommand s_gs1_g46_s0_lives6_dlg0[] = { /* 0x817197c */
    DEBUGINFO_O(13975),
    SELECT_ANIMATION(32),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    { 0x6c, 0x78,  0x004c,  0x0000008e,  0x00000000, NULL },
    WAIT_RANDOM(30, 60),
    { 0x6c, 0x78,  0x004c,  0x0000008e,  0x00000000, NULL },
    WAIT_RANDOM(30, 60),
    WALK_GRID(76, 142),
    { 0x54, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    SELECT_ANIMATION(25),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    WAIT(25),
    FANFARE_PLAY2(400),
    { 0xe2, 0x00,  0x0190,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    HALT,
};

static const struct ScriptCommand s_gs1_g46_s0_lives7_dlg0[] = { /* 0x8171aac */
    DEBUGINFO_O(13997),
    SELECT_ANIMATION(33),
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x6c, 0xb4,  0x004c,  0x0000008f,  0x00000000, NULL },
    WAIT_RANDOM(30, 60),
    { 0x6c, 0x78,  0x004c,  0x0000008f,  0x00000000, NULL },
    WAIT_RANDOM(30, 60),
    WALK_GRID(76, 143),
    { 0x54, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(12),
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(400),
    { 0xe2, 0x00,  0x0190,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(12),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_station_sref_script[] = { /* 0x8171bec */
    DEBUGINFO_O(14020),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_TEAM_BASE),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(7),
    { 0x22, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs1_g47_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g47_s0_station_sref_script }; /* 0x8171cdc */

static const struct ScriptCommand s_gs1_g47_s0_eff0_script[] = { /* 0x8171ce8 */
    DEBUGINFO_O(14040),
    AWAIT_CUE(4),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    CAMERA_END_PAN,
    ALERT_CUE(5),
    RET,
};

static const struct ScriptCommand s_gs1_g47_s0_lives0_dlg0[] = { /* 0x8171d48 */
    DEBUGINFO_O(14049),
    CAMERA_INIT_PAN,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WALK_RELATIVE(256, 80, 0),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}.\nEveryone's gathered around.")),
    VARIANT_DEFAULT(_(" Look, {NAME_0}.\nEveryone's gathered around.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(4),
    ALERT_CUE(6),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000001),
    MSG_NPC(2, _(" Aiyiyi...\nI do not deserve this! I am outraged!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    WALK_GRID(256, 145),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's up, folks?")),
    VARIANT_DEFAULT(_(" What's up, everyone?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Up? Up? Up?!\nHow could it be up, I ask you!")),
    MSG_NPC(2, _(" My beautiful shop...\nMy fine wares were stolen from me!")),
    ALERT_CUE(6),
    FANFARE_PLAY2(465),
    { 0x56, 0x00,  0x0000,  0x00000146,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Many, many TMs are simply\ngone! Spirited away!\nDark clouds fill my heart!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" My bank wasn't hit, but...{WAIT_PRESS}\nThese are frightening times.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    MSG_NPC(1, _(" Is the storage OK?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(10),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" No problem.{WAIT_PRESS}\nNothing gets stolen from under my eye.")),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0005, 0x00000001),
    MSG_NPC(5, _(" This mama's not about to\nmake a stupid mistake like that! Kakakah!")),
    ALERT_CUE(10),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000001),
    MSG_NPC(2, _(" You're insinuating...{WAIT_PRESS}\nthat we were robbed for being careless?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    ROTATE(4, 1, DIRECTION_EAST),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" Now wait.")),
    WAIT(10),
    MSG_NPC(6, _(" Tell me, Kecleon.{WAIT_PRESS}\nYou saw...this thief?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Hmm...?{WAIT_PRESS}\nNo, not very clearly, I didn't.")),
    MSG_NPC(2, _(" When I saw it, it had\nalready taken off...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    MSG_NPC(6, _(" Taken off?{WAIT_PRESS}\nYou mean it flew away?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Yes.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" It flew off in yonder\ndirection, yes.")),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" At tremendous speed\ntoo.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    MSG_NPC(6, _(" The yonder direction...{WAIT_PRESS}\nThat would be the Northern Range...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    MSG_NPC(6, _(" It's impossible to determine\nwhat the thief is...")),
    MSG_NPC(6, _(" So we'll need to investigate\nthis matter properly.")),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_TOP_LEFT_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Yes. I beg for justice.{WAIT_PRESS}\nMy business faces ruination.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTH),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}.\nWant to go check it out?")),
    VARIANT_DEFAULT(_(" {NAME_0}.\nWant to look into this?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0}'s team took on\n{CENTER_ALIGN}the case of pursuing the burglar\n{CENTER_ALIGN}that struck Kecleon's shop.")),
    MSG_INSTANT(_("{CENTER_ALIGN}The burglar's alleged\n{CENTER_ALIGN}getaway spot...")),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR YELLOW_D}Northern Range{RESET}\n{CENTER_ALIGN}is now open for investigation!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};
















static const struct ScriptCommand s_gs1_g47_s0_lives1_dlg0[] = { /* 0x8172b68 */
    DEBUGINFO_O(14204),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    WALK_RELATIVE(256, 80, 0),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x8e, 0x01,  0x0000,  0x00000001,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    AWAIT_CUE(6),
    WALK_GRID(256, 144),
    FANFARE_PLAY2(468),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x00000146,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(1, 10, DIRECTION_NORTH),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_lives2_dlg0[] = { /* 0x8172d68 */
    DEBUGINFO_O(14239),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_NORTH),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_lives3_dlg0[] = { /* 0x8172de8 */
    DEBUGINFO_O(14250),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(60),
    ROTATE(4, 1, DIRECTION_SOUTH),
    WAIT(60),
    CALL_SCRIPT(ANGRY_END_FUNC),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    WALK_RELATIVE(512, -16, 0),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_NORTH),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_EAST),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d5,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    WAIT(10),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_EAST),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_WEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_lives4_dlg0[] = { /* 0x8173008 */
    DEBUGINFO_O(14287),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    ROTATE(4, 2, DIRECTION_NORTH),
    AWAIT_CUE(9),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(9),
    ROTATE(4, 1, DIRECTION_NORTH),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_lives5_dlg0[] = { /* 0x81730a8 */
    DEBUGINFO_O(14300),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    ROTATE(3, 1, DIRECTION_SOUTH),
    AWAIT_CUE(10),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(10),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(10),
    ROTATE(4, 2, DIRECTION_SOUTH),
    HALT,
};

static const struct ScriptCommand s_gs1_g47_s0_lives6_dlg0[] = { /* 0x8173188 */
    DEBUGINFO_O(14317),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100, -0x00000008,  0x00000000, NULL },
    AWAIT_CUE(11),
    WALK_RELATIVE(256, -8, 24),
    ALERT_CUE(5),
    ROTATE(4, 1, DIRECTION_WEST),
    AWAIT_CUE(11),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(11),
    ROTATE(4, 1, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    ROTATE(4, 2, DIRECTION_WEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_station_sref_script[] = { /* 0x81732b8 */
    DEBUGINFO_O(14339),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(7),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs1_g48_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g48_s0_station_sref_script }; /* 0x8173358 */

static const struct ScriptCommand s_gs1_g48_s0_eff0_script[] = { /* 0x8173364 */
    DEBUGINFO_O(14354),
    CAMERA_END_PAN,
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_lives0_dlg0[] = { /* 0x8173394 */
    DEBUGINFO_O(14360),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Look! He's waking up!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0005, 0x00000000),
    PORTRAIT_POS(5, -1, 0),
    MSG_NPC(5, _(" ...Wh-where...?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is Pokémon Square.")),
    VARIANT(/* == */  1, _(" You passed out in the\n{COLOR YELLOW_D}Northern Range{RESET}, so we brought you back\nwith us.")),
    VARIANT_DEFAULT(_(" This is Pokémon Square.")),
    VARIANT_DEFAULT(_(" You fainted in the {COLOR YELLOW_D}Northern\nRange{RESET}, so we brought you back here.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000001),
    MSG_NPC(2, _(" You! How dare you steal\nmy fine selection of quality merchandise!")),
    MSG_NPC(2, _(" You had better be prepared\nfor harsh justice!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, -3, 1),
    MSG_NPC(4, _(" Now wait.{WAIT_PRESS}\nThere must be a good reason for this.")),
    MSG_NPC(4, _(" We should at least hear\nthat.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(5, _(" ...!{WAIT_PRESS} That's right!\nI have to get my sister...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    MSG_NPC(5, _(" Ggh! This wound!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    MSG_NPC(4, _(" You're injured.\nYou can't fly for now.")),
    MSG_NPC(4, _(" Tell me, how do you justify\nwhat you've done?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    BGM_SWITCH(114),
    WAIT(60),
    MSG_NPC(5, _(" I have a younger sister.\nHer name is Latias.")),
    MSG_NPC(5, _(" Latias...{WAIT_PRESS}\nCrashed somewhere in the {COLOR YELLOW_D}Pitfall Valley{RESET}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0004, 0x00000000),
    MSG_NPC(4, _(" What?!{WAIT_PRESS}\nThe {COLOR YELLOW_D}Pitfall Valley{RESET}?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...What is that?{WAIT_PRESS}\nWhat's the {COLOR YELLOW_D}Pitfall Valley{RESET}?")),
    VARIANT_DEFAULT(_(" ...What is that?{WAIT_PRESS}\nWhat is the {COLOR YELLOW_D}Pitfall Valley{RESET}?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" It is near the {COLOR YELLOW_D}Northern\nRange{RESET}.")),
    MSG_NPC(2, _(" They say that anyone so\nunlucky to fall into the {COLOR YELLOW_D}Pitfall Valley{RESET}...{WAIT_PRESS}\nwill never again emerge.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(6),
    MSG_NPC(5, _(" Latias and I were flying\nover the Northern Range.")),
    MSG_NPC(5, _(" When suddenly, what\nappeared to be a meteorite struck\nLatias on the wing...")),
    MSG_NPC(5, _(" Her wing shattered by the\nblow, Latias tumbled down into the\ndepths of the {COLOR YELLOW_D}Pitfall Valley{RESET}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" A meteorite?!")),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    MSG_NPC(1, _(" {NAME_0}!{WAIT_PRESS}\nDo you think maybe that it's a chunk of\nthe blown-up meteor?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    MSG_NPC(5, _(" I went to the {COLOR YELLOW_D}Pitfall Valley{RESET}\nin hopes of rescuing my sister, but...")),
    MSG_NPC(5, _(" I made little headway...\nI wasn't up to the task...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0004, 0x00000000),
    MSG_NPC(4, _(" So that drove you to steal\nTechnical Machines...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(5, _(" Yes.{WAIT_PRESS}\nI intended to make amends after I saved\nmy sister...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    MSG_NPC(5, _(" But that doesn't mean I can\nget away with thievery.{WAIT_PRESS}\nIt was wrong, and I'm sorry.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    WAIT(60),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" Oh... Oh, my!{WAIT_PRESS}\nIt is not a problem! Not a problem at all!")),
    MSG_NPC(2, _(" For a reason so compelling,\nit can't be helped. Hahaha.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(6),
    ALERT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" However...{WAIT_PRESS}\nEven if you were to plumb the depths of\n{COLOR YELLOW_D}Pitfall Valley{RESET}...")),
    MSG_NPC(4, _(" What would you do then?")),
    MSG_NPC(4, _(" The nether regions of the\n{COLOR YELLOW_D}Pitfall Valley{RESET} are a void...")),
    MSG_NPC(4, _(" You will wander forever,\nneither falling...{WAIT_PRESS}nor living...{WAIT_PRESS}\nWhat then?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    PORTRAIT_REP(0x0005, 0x00000000),
    MSG_NPC(5, _(" ............{WAIT_PRESS}\nSo much time has passed since my sister\ncrashed.")),
    MSG_NPC(5, _(" Latias hasn't been able to\nclimb out of the depths.\nShe is all alone down there.")),
    MSG_NPC(5, _(" Even if I end up like her,\nunable to escape...{WAIT_PRESS}\nTwo would be better than one.")),
    MSG_NPC(5, _(" Latias wouldn't have to\nbe so alone...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" How foolish...{WAIT_PRESS}\nDo you think Latias wishes for that?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But...{WAIT_PRESS}\nIt's a place you can never escape, right?")),
    VARIANT(/* == */  1, _(" How are we supposed to pull\noff a rescue from a place like that...?")),
    VARIANT_DEFAULT(_(" But...{WAIT_PRESS}\nIt's a place you can't escape, isn't it?")),
    VARIANT_DEFAULT(_(" I don't see how we could\ndo a rescue in a place like that...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" No...{WAIT_PRESS} There is...{WAIT_PRESS}\nThere is but one possible way...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    ALERT_CUE(7),
    ALERT_CUE(6),
    ALERT_CUE(8),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    ROTATE(4, 1, DIRECTION_EAST),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" You can?!{WAIT_PRESS}\nHow?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    MSG_NPC(4, _(" You already have the means\nin your possession.")),
    MSG_NPC(4, _(" The {COLOR GREEN_I}Teleport Gem{RESET}.{WAIT_PRESS}\nUse that.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_NPC(1, _(" The {COLOR GREEN_I}Teleport Gem{RESET}?{WAIT_PRESS}\nThe one we used to get up to the sky\nwhere Rayquaza lives?")),
    MSG_NPC(1, _(" But it got broken in the\nfalling star's explosion.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(4, _(" While it is unlikely to\ncarry you to the sky again, it should\nbe able to carry you a shorter distance.")),
    MSG_NPC(4, _(" If you were to use the\n{COLOR GREEN_I}Teleport Gem{RESET} from deep within the {COLOR YELLOW_D}Pitfall\nValley{RESET}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000009),
    MSG_NPC(1, _(" That's it!{WAIT_PRESS}\nIf we did that, we could escape with\nLatias!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}!{WAIT_PRESS}\nThis is a rescue that only we can do!")),
    VARIANT(/* == */  1, _(" Let's get out there and\nhelp Latias!")),
    VARIANT(/* == */  3, _(" {NAME_0}!{WAIT_PRESS}\nThis is a rescue that only we can do!")),
    VARIANT(/* == */  3, _(" Let's go get Latias!")),
    VARIANT_DEFAULT(_(" {NAME_0}!{WAIT_PRESS}\nThis is a rescue that only we can do!")),
    VARIANT_DEFAULT(_(" Let's go rescue Latias!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    BGM_STOP,
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Pitfall Valley{RESET}!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};





























static const struct ScriptCommand s_gs1_g48_s0_lives1_dlg0[] = { /* 0x8174e1c */
    DEBUGINFO_O(14606),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d5,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_lives2_dlg0[] = { /* 0x817500c */
    DEBUGINFO_O(14640),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_NORTHWEST),
    AWAIT_CUE(8),
    CALL_SCRIPT(SHOCK_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_lives3_dlg0[] = { /* 0x81750cc */
    DEBUGINFO_O(14655),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(1),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    WAIT(10),
    WALK_RELATIVE(256, 0, -8),
    CALL_SCRIPT(ANGRY_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(7),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(7),
    WAIT(30),
    FANFARE_PLAY2(468),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    WAIT(20),
    FANFARE_PLAY2(468),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    WAIT(30),
    ROTATE(4, 2, DIRECTION_NORTH),
    FANFARE_PLAY2(457),
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_lives4_dlg0[] = { /* 0x817534c */
    DEBUGINFO_O(14698),
    SELECT_ANIMATION(2),
    { 0x62, 0x00,  0x0500, -0x00000008,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
    WALK_RELATIVE(512, -40, 0),
    ROTATE(4, 2, DIRECTION_SOUTH),
    AWAIT_CUE(9),
    ROTATE(4, 1, DIRECTION_NORTH),
    AWAIT_CUE(9),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    WALK_RELATIVE(256, 24, 0),
    ROTATE(4, 2, DIRECTION_SOUTHWEST),
    AWAIT_CUE(9),
    WALK_RELATIVE(256, -24, 0),
    ROTATE(4, 1, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE(4, 2, DIRECTION_SOUTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g48_s0_lives5_dlg0[] = { /* 0x81754ac */
    DEBUGINFO_O(14723),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(6),
    AWAIT_CUE(10),
    SELECT_ANIMATION(4),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(10),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    BGM_STOP,
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    FANFARE_PLAY2(475),
    { 0x54, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01db,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    FANFARE_PLAY2(682),
    { 0xe2, 0x00,  0x02aa,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    SELECT_ANIMATION(25),
    AWAIT_CUE(10),
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(30),
    { 0x54, 0x00,  0x001d,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    SELECT_ANIMATION(25),
    AWAIT_CUE(10),
    { 0x54, 0x00,  0x001d,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    CALL_SCRIPT(SHOCK_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs1_g49_s0_station_sref_script[] = { /* 0x817576c */
    DEBUGINFO_O(14770),
    SELECT_MAP(1),
    SELECT_ENTITIES(-1, 0),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs1_g49_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs1_g49_s0_station_sref_script }; /* 0x81757ec */

static const struct ScriptCommand s_gs1_g49_s0_lives0_dlg0[] = { /* 0x81757f8 */
    DEBUGINFO_O(14783),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(7),
    WAIT(30),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" {NAME_6}!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0006, 0x00000000),
    MSG_NPC(6, _(" Latios!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000001),
    MSG_NPC(5, _(" You're safe!\nThis is incredible...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0006, 0x00000000),
    MSG_NPC(6, _(" I'm sorry...\nI caused you so much worry...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Oh, this is great...\nIt's so touching... Sniffle...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(8),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_RIGHT, 0x0005, 0x00000000),
    MSG_NPC(5, _(" My sister is safe, all\nthanks to you.")),
    MSG_NPC(5, _(" To be honest, I came close\nto giving up...")),
    MSG_NPC(5, _(" But we're back together\nagain...{WAIT_PRESS}\nIt's happiness beyond words...")),
    PORTRAIT_REP(0x0005, 0x00000001),
    MSG_NPC(5, _(" We owe you so much\ngratitude! Thank you!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000009),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, now, that's OK.{WAIT_PRESS}\nIt's even a little embarrassing when you\nput it that way, hahaha!")),
    VARIANT_DEFAULT(_(" It's OK, really.{WAIT_PRESS}\nWhen you put it that way, it's even a little\nembarrassing. Hahaha.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0005, 0x00000000),
    MSG_NPC(5, _(" However...\nWe have no money or any other way of\nrepaying your kindness.")),
    MSG_NPC(5, _(" So, and it's the least we\ncan do...{WAIT_PRESS}\nMay we join your rescue team?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Huh...?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0006, 0x00000000),
    MSG_NPC(6, _(" We would like to join {COLOR CYAN}Team\n{TEAM_NAME}{RESET} and help with your rescue\nwork.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    AWAIT_CUE(5),
    MSG_NPC(5, _(" Would that work?{WAIT_PRESS}\nWould you be willing to accept us on\nyour rescue team?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" {NAME_0}, what do you\nsay?{WAIT_PRESS}\nShould we let Latios and Latias join?")),
    VARIANT_DEFAULT(_(" {NAME_0}, what should\nwe do?{WAIT_PRESS}\nDo we let Latios and Latias join?")),
    CHOICE(/* label */ 10, _("Yes.")),
    CHOICE(/* label */ 11, _("No.")),
    TEXTBOX_CLEAR,
    WAIT(10),
  LABEL(11), /* = 0x0b */
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    FANFARE_PLAY2(455),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Huh?\nYou're really sure about that?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000005),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" They're volunteering!\nDon't you think we should let them join?")),
    CHOICE(/* label */ 10, _("Accept.")),
    CHOICE(/* label */ 13, _("No, forget it.")),
    TEXTBOX_CLEAR,
    WAIT(10),
  LABEL(13), /* = 0x0d */
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(455),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    WAIT(60),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000000),
    MSG_NPC(4, _(" It is you who decides.\nThe outcome is of no concern to me.")),
    MSG_NPC(4, _(" However...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    MSG_NPC(4, _(" Latios and Latias are\nPokémon so rarely seen that they are\nconsidered mythical.")),
    MSG_NPC(4, _(" If you part ways with them\nnow, you may never see them again.")),
    MSG_NPC(4, _(" Strike that.\nYou will never again see them.")),
    MSG_NPC(4, _(" Even knowing that...{WAIT_PRESS}\nEven if you would never see them again,\nyou will still not accept them?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ROTATE(4, 1, DIRECTION_SOUTH),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}, think good\nand hard about this.")),
    VARIANT_DEFAULT(_(" {NAME_0}, give it good\nthought.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Should we let Latios and\nLatias join?")),
    VARIANT_DEFAULT(_(" Do we let Latios and Latias\njoin?")),
    CHOICE(/* label */ 10, _("Yes.")),
    CHOICE(/* label */ 11, _("No.")),
  LABEL(10), /* = 0x0a */
    TEXTBOX_CLEAR,
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    ALERT_CUE(10),
    ALERT_CUE(11),
    AWAIT_CUE(5),
    ALERT_CUE(7),
    ALERT_CUE(8),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000009),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Done deal!")),
    VARIANT(/* == */  1, _(" You're our fellow members\nfrom now on! Welcome aboard!")),
    VARIANT_DEFAULT(_(" Done!")),
    VARIANT_DEFAULT(_(" You're our fellow members\nfrom now on. Great to have you!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    ALERT_CUE(11),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    PORTRAIT_REP(0x0005, 0x00000001),
    MSG_NPC(5, _(" Thanks for having us!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0006, 0x00000001),
    MSG_NPC(6, _(" Delighted to join!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_INSTANT(_("{CENTER_ALIGN}And thus...")),
    MSG_INSTANT(_("{CENTER_ALIGN}{COLOR CYAN}Team {TEAM_NAME}{RESET} was\n{CENTER_ALIGN}joined by {NAME_5} and {NAME_6}!")),
    BGM_STOP,
    FANFARE_PLAY(204),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_5} and {NAME_6}\n{CENTER_ALIGN}became team members!")),
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    { 0x3b, 0x24,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to {NAME_5}?")),
    CHOICE(/* label */ 17, _("*Yes.")),
    CHOICE(/* label */ 18, _("No.")),
  LABEL(17), /* = 0x11 */
    RENAME_ALLY(-1),
  LABEL(18), /* = 0x12 */
    { 0x3b, 0x25,  0x0000,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    { 0x3b, 0x26,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to {NAME_6}?")),
    CHOICE(/* label */ 19, _("*Yes.")),
    CHOICE(/* label */ 20, _("No.")),
  LABEL(19), /* = 0x13 */
    RENAME_ALLY(-1),
  LABEL(20), /* = 0x14 */
    { 0x3b, 0x27,  0x0000,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};















static const struct ScriptCommand s_gs1_g49_s0_lives1_dlg0[] = { /* 0x8176dcc */
    DEBUGINFO_O(15024),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    AWAIT_CUE(6),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(6),
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTH),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    ROTATE(4, 1, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    HALT,
};


static const struct ScriptCommand s_gs1_g49_s0_lives2_dlg0[] = { /* 0x817708c */
    DEBUGINFO_O(15072),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    SELECT_ANIMATION(9),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(7),
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(7),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_SOUTHEAST),
    AWAIT_CUE(7),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(7),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    ROTATE(4, 2, DIRECTION_SOUTH),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    HALT,
};


static const struct ScriptCommand s_gs1_g49_s0_lives3_dlg0[] = { /* 0x817725c */
    DEBUGINFO_O(15105),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(8),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(8),
    ROTATE(4, 2, DIRECTION_SOUTHEAST),
    AWAIT_CUE(8),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(8),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    ROTATE(4, 2, DIRECTION_SOUTH),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    HALT,
};


static const struct ScriptCommand s_gs1_g49_s0_lives4_dlg0[] = { /* 0x817742c */
    DEBUGINFO_O(15138),
    SELECT_ANIMATION(2),
    { 0x62, 0x00,  0x0500, -0x00000008,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(9),
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(9),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    WALK_RELATIVE(256, -16, 0),
    AWAIT_CUE(9),
    { 0x62, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(9),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    ROTATE(4, 2, DIRECTION_SOUTHWEST),
    HALT,
};


static const struct ScriptCommand s_gs1_g49_s0_lives5_dlg0[] = { /* 0x817755c */
    DEBUGINFO_O(15161),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    SELECT_ANIMATION(22),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    WALK_RELATIVE(256, -16, 0),
    WAIT(30),
    SELECT_ANIMATION(23),
    WAIT(60),
    WALK_RELATIVE(256, -8, 0),
    SELECT_ANIMATION(24),
    AWAIT_CUE(10),
    SELECT_ANIMATION(2),
    WALK_RELATIVE(256, -8, 8),
    ROTATE(4, 1, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x62, 0x00,  0x0200, -0x00000008,  0x00000000, NULL },
    ROTATE(4, 1, DIRECTION_NORTH),
    SELECT_ANIMATION(17),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    WAIT(10),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTHEAST),
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_EAST),
    { 0x62, 0x00,  0x0100,  0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTHEAST),
    { 0x62, 0x00,  0x0100,  0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTH),
    { 0x62, 0x00,  0x0100,  0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTHWEST),
    { 0x62, 0x00,  0x0100,  0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_WEST),
    { 0x62, 0x00,  0x0100, -0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTHWEST),
    { 0x62, 0x00,  0x0100, -0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x62, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
    ROTATE(4, 2, DIRECTION_WEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g49_s0_lives6_dlg0[] = { /* 0x817785c */
    DEBUGINFO_O(15212),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(11),
    SELECT_ANIMATION(22),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    WALK_RELATIVE(256, 16, 0),
    WAIT(30),
    SELECT_ANIMATION(23),
    WAIT(60),
    SELECT_ANIMATION(24),
    ALERT_CUE(5),
    AWAIT_CUE(11),
    SELECT_ANIMATION(2),
    WALK_RELATIVE(256, 0, -16),
    ROTATE(4, 2, DIRECTION_WEST),
    AWAIT_CUE(11),
    ROTATE(4, 2, DIRECTION_SOUTH),
    FANFARE_PLAY2(455),
    SELECT_ANIMATION(17),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    AWAIT_CUE(11),
    { 0x62, 0x00,  0x0100,  0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTHWEST),
    { 0x62, 0x00,  0x0100,  0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_WEST),
    FANFARE_PLAY2(457),
    { 0x62, 0x00,  0x0100, -0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTHWEST),
    { 0x62, 0x00,  0x0100, -0x00000008,  0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTH),
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_NORTHEAST),
    { 0x62, 0x00,  0x0100, -0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_EAST),
    FANFARE_PLAY2(457),
    { 0x62, 0x00,  0x0100,  0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTHEAST),
    { 0x62, 0x00,  0x0100,  0x00000008, -0x00000008, NULL },
    ROTATE(1, 1, DIRECTION_SOUTH),
    AWAIT_CUE(11),
    ROTATE(4, 1, DIRECTION_WEST),
    HALT,
};

static const struct ScriptCommand s_gs1_g50_s0_lives0_dlg2[] = { /* 0x8177b2c */
    DEBUGINFO_O(15260),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SET_ARRAYVAL(EVENT_S07E01,  0,  1),
    MSG_NPC(1, _(" Hey, have you heard?\nAbout the {COLOR YELLOW_D}Buried Relic{RESET}.")),
    MSG_NPC(1, _(" They're rumoring that there\nare treasures in there.")),
    MSG_NPC(1, _(" And they say the treasures\naren't just lying around on the ground.")),
    MSG_NPC(1, _(" Know what they're saying?{WAIT_PRESS}\nThey're saying that treasures are even\nembedded in the walls!")),
    MSG_NPC(1, _(" If you knock down the walls,\nthere might be treasures galore!{WAIT_PRESS}\nSounds really enticing, eh?")),
    MSG_NPC(1, _(" I think Shiftry knows where\nthe {COLOR YELLOW_D}Buried Relic{RESET} is.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives1_dlg2[] = { /* 0x8177da0 */
    DEBUGINFO_O(15276),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SET_ARRAYVAL(EVENT_S07E01,  1,  1),
    MSG_NPC(1, _(" I heard rumors that\nPokémon from ancient times live in the\n{COLOR YELLOW_D}Buried Relic{RESET}.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives2_dlg2[] = { /* 0x8177e60 */
    DEBUGINFO_O(15287),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SET_ARRAYVAL(EVENT_S07E01,  2,  1),
    MSG_NPC(1, _(" I've heard that there are\ntreasures to be found in the relic.{WAIT_PRESS}\nI wonder how much is true?")),
    MSG_NPC(1, _(" But, I must admit...{WAIT_PRESS}\nI do get a certain thrill from it!")),
    MSG_NPC(1, _(" I guess there's a sense of\ndrama and adventure about it.")),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives3_dlg0[] = { /* 0x8177fcc */
    DEBUGINFO_O(15300),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    SELECT_ANIMATION(1),
    { 0x8b, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g50_s0_lives3_dlg2[] = { /* 0x817803c */
    DEBUGINFO_O(15310),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SET_ARRAYVAL(EVENT_S07E01,  4,  1),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" What's that?\nWhere is the {COLOR YELLOW_D}Buried Relic{RESET}?")),
    MSG_NPC(1, _(" The {COLOR YELLOW_D}Buried Relic{RESET} is deep\nin the jungle to the southeast.")),
    MSG_NPC(1, _(" Are you dreaming about\nthe treasures too?")),
    ALERT_CUE(6),
    MSG_NPC(1, _(" Kukukuh...{WAIT_PRESS} Me too!{WAIT_PRESS}\nBest of luck, compadre!")),
    TEXTBOX_CLEAR,
    AWAIT_CUE(5),
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, 2, /* to label */ 1),
    WAIT(30),
    MSG_INSTANT(_("{CENTER_ALIGN}Leaving aside the disturbing fact that\n{CENTER_ALIGN}{NAME_1} made them compadres...")),
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0}'s team gained\n{CENTER_ALIGN}access to the {COLOR YELLOW_D}Buried Relic{RESET}!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, 2, /* to label */ 1),
    { 0xaf, 0x01,  0x001b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB7, 49,  3),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
};



static const struct ScriptCommand s_gs1_g50_s0_lives3_dlg3[] = { /* 0x8178340 */
    DEBUGINFO_O(15342),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs1_g50_s0_lives4_dlg2[] = { /* 0x8178410 */
    DEBUGINFO_O(15358),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 5, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01,  5,  1),
    MSG_NPC(1, _(" It seems talk of the relic\nis on everyone's lips today!")),
    MSG_NPC(1, _(" If you find any\ntreasures, please do sell them to me.")),
    MSG_NPC(1, _(" And now...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_GREEN_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives5_dlg2[] = { /* 0x8178564 */
    DEBUGINFO_O(15375),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 6, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01,  6,  1),
    MSG_NPC(1, _(" Oh, isn't it exciting?{WAIT_PRESS}\nWhy, I wouldn't mind closing up the shop\nso I could go treasure hunting!")),
    MSG_NPC(1, _(" And now...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_PURPLE_KECLEON_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives6_dlg2[] = { /* 0x8178690 */
    DEBUGINFO_O(15391),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 7, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01,  7,  1),
    MSG_NPC(1, _(" If you find a fortune in the\nrelic, save it here with me!")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_BANK, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives7_dlg2[] = { /* 0x8178780 */
    DEBUGINFO_O(15406),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 8, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01,  8,  1),
    MSG_NPC(1, _(" I wonder what kinds of\nfriends are in the {COLOR YELLOW_D}Buried Relic{RESET}?")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives8_dlg2[] = { /* 0x8178870 */
    DEBUGINFO_O(15421),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 9, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01,  9,  1),
    MSG_NPC(1, _(" You're going too, aren't you?\nTo the {COLOR YELLOW_D}Buried Relic{RESET}.")),
    MSG_NPC(1, _(" This mama's behind you all\nthe way! Go for it!")),
    MSG_NPC(1, _(" OK...")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_STORAGE_WITH_DIALOG, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g50_s0_lives9_dlg2[] = { /* 0x81789bc */
    DEBUGINFO_O(15438),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_ARRAY(EVENT_S07E01, 10, /* to label */ 0),
    SET_ARRAYVAL(EVENT_S07E01, 10,  1),
    MSG_NPC(1, _(" What treasures can be\nfound in the {COLOR YELLOW_D}Buried Relic{RESET}, I wonder?")),
    MSG_NPC(1, _(" It makes me drool thinking\nwhat I could swallow in a place like that.")),
    TEXTBOX_CLEAR,
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_LINK_SHOP, 0, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g51_s0_lives0_dlg2[] = { /* 0x8178b08 */
    DEBUGINFO_O(15454),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I think Gengar headed off\nto {COLOR YELLOW_D}Mt. Freeze{RESET}.")),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000044),
    MSG_NPC(1, _(" I have heard it is a place\nthat is very difficult.{WAIT_PRESS}\nWill he be OK?")),
    SCENARIO_CALC(SCENARIO_SUB9, 53,  4),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g51_s0_lives1_dlg2[] = { /* 0x8178c10 */
    DEBUGINFO_O(15467),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" Gengar wants to meet with\nNinetales. That's what I think.")),
    MSG_NPC(1, _(" What he means to do when\nhe does meet...I don't know.")),
    SCENARIO_CALC(SCENARIO_SUB9, 53,  4),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs1_g52_s0_lives0_dlg2[] = { /* 0x8178d0c */
    DEBUGINFO_O(15479),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_NPC(1, _(" I have done a lot of\nthinking...")),
    MSG_NPC(1, _(" I would like to join {COLOR CYAN}Team \n{TEAM_NAME}{RESET} and help on rescues.")),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" Please, may I become\na member?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    { 0x3b, 0x30,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 4),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000041),
    MSG_NPC(1, _(" Thank you!{WAIT_PRESS}\nI promise to do my best for the team!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY(204),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_1} became the\n{CENTER_ALIGN}rescue team's newest member!")),
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0x3b, 0x31,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to {NAME_1}?")),
    CHOICE(/* label */  6, _("*Yes.")),
    CHOICE(/* label */  7, _("No.")),
  LABEL(6), /* = 0x06 */
    RENAME_ALLY(-1),
  LABEL(7), /* = 0x07 */
    { 0x3b, 0x32,  0x0000,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    SCENARIO_CALC(SCENARIO_SUB9, 55,  3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    CANCEL_ENTITIES(52, -1),
    WAIT(30),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(4), /* = 0x04 */
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000041),
    MSG_NPC(1, _(" Yes!\nThank you!")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" ...However, there seems to\nbe no space for me in my Friend Area...{WAIT_PRESS}\nThis is disappointing...")),
    MSG_NPC(1, _(" I could join your rescue\nteam if there were less Pokémon in\n{COLOR GREEN}Sky Blue Plains{RESET}...")),
    MSG_NPC(1, _(" Please tell me then.")),
    TEXTBOX_CLEAR,
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    PORTRAIT_REP(0x0001, 0x00000042),
    MSG_NPC(1, _(" ...I see.{WAIT_PRESS}\nThis is disappointing...")),
    TEXTBOX_CLEAR,
    JUMP_SCRIPT(END_TALK),
};

static const struct GroundLivesData s_gs1_g0_s1_lives[] = { /* 0x8179214 */
    /*  0 */ {   0,   2,   0,   0, {   8,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   5,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g0_s2_lives[] = { /* 0x8179244 */
    /*  0 */ {   0,   0,   0,   0, {  64,   9, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  64,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g0_s3_lives[] = { /* 0x8179274 */
    /*  0 */ {   0,   6,   0,   0, { 112,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, { 115,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g0_s4_lives[] = { /* 0x81792a4 */
    /*  0 */ {   0,   4,   0,   0, {  66,  83, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  66,  85, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g0_s7_lives[] = { /* 0x81792d4 */
    /*  0 */ {   0,   0,   0,   0, {  64,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s7_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  64,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s7_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g0_s8_lives[] = { /* 0x8179304 */
    /*  0 */ {   0,   0,   0,   0, {   8,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s8_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {   5,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g0_s8_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g1_s0_lives[] = { /* 0x8179334 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives5_dlg2,
    } },
    /*  6 */ {  85,   7,   0,   0, {  69,  36, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives6_dlg2,
    } },
    /*  7 */ {  77,   5,   0,   0, {  71,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives7_dlg2,
    } },
    /*  8 */ {  81,   0,   0,   0, {  58,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives8_dlg2,
    } },
    /*  9 */ {  89,   2,   0,   0, {  57,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives9_dlg2,
    } },
    /* 10 */ {  90,   6,   0,   0, {  61,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives10_dlg2,
    } },
    /* 11 */ {  88,   0,   0,   0, {  90,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives11_dlg2,
    } },
    /* 12 */ {  61,   0,   0,   0, {  58,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives12_dlg2,
    } },
    /* 13 */ {  62,   0,   0,   0, {  61,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g1_s0_lives13_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g3_s0_lives[] = { /* 0x8179484 */
    /*  0 */ { 127,   0,   0,   0, { 109,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g3_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g4_s0_lives[] = { /* 0x817949c */
    /*  0 */ { 127,   0,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g4_s0_lives0_dlg1,
        [2] = s_gs1_g4_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g4_s1_lives[] = { /* 0x81794b4 */
    /*  0 */ {   0,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s1_lives1_dlg0,
    } },
    /*  2 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s1_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g4_s2_lives[] = { /* 0x81794fc */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives0_dlg0,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives1_dlg0,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives2_dlg0,
    } },
    /*  3 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives3_dlg0,
    } },
    /*  4 */ {  85,   7,   0,   0, {  69,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives4_dlg0,
    } },
    /*  5 */ {  77,   5,   0,   0, {  71,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives5_dlg0,
    } },
    /*  6 */ {  81,   0,   0,   0, {  58,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives6_dlg0,
    } },
    /*  7 */ {  89,   2,   0,   0, {  57,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives7_dlg0,
    } },
    /*  8 */ {  90,   6,   0,   0, {  61,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives8_dlg0,
    } },
    /*  9 */ {  88,   0,   0,   0, {  90,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s2_lives9_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g4_s3_lives[] = { /* 0x81795ec */
    /*  0 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g4_s3_lives0_dlg0,
        [1] = s_gs1_g4_s3_lives0_dlg1,
        [2] = s_gs1_g4_s3_lives0_dlg2,
        [3] = s_gs1_g4_s3_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs1_g4_s4_lives[] = { /* 0x8179604 */
    /*  0 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g4_s4_lives0_dlg1,
        [2] = s_gs1_g4_s4_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g5_s0_lives[] = { /* 0x817961c */
    /*  0 */ { 127,   0,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g5_s0_lives0_dlg1,
        [2] = s_gs1_g5_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g5_s1_lives[] = { /* 0x8179634 */
    /*  0 */ {   0,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_lives1_dlg0,
    } },
    /*  2 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g5_s2_lives[] = { /* 0x817967c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives0_dlg0,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives1_dlg0,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives2_dlg0,
    } },
    /*  3 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives3_dlg0,
    } },
    /*  4 */ {  85,   7,   0,   0, {  69,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives4_dlg0,
    } },
    /*  5 */ {  77,   5,   0,   0, {  71,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives5_dlg0,
    } },
    /*  6 */ {  81,   0,   0,   0, {  58,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives6_dlg0,
    } },
    /*  7 */ {  89,   2,   0,   0, {  57,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives7_dlg0,
    } },
    /*  8 */ {  90,   6,   0,   0, {  61,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives8_dlg0,
    } },
    /*  9 */ {  88,   0,   0,   0, {  90,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s2_lives9_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g5_s3_lives[] = { /* 0x817976c */
    /*  0 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g5_s3_lives0_dlg1,
        [2] = s_gs1_g5_s3_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g5_s4_lives[] = { /* 0x8179784 */
    /*  0 */ {   0,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, { 115,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s4_lives1_dlg0,
    } },
    /*  2 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s4_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g5_s5_lives[] = { /* 0x81797cc */
    /*  0 */ { 127,   6,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g5_s5_lives0_dlg1,
        [2] = s_gs1_g5_s5_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g5_s6_lives[] = { /* 0x81797e4 */
    /*  0 */ { 127,   2,   0,   0, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g5_s6_lives0_dlg1,
        [2] = s_gs1_g5_s6_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g6_s0_lives[] = { /* 0x81797fc */
    /*  0 */ {   0,   2,   0,   0, {   5,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g6_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g6_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g7_s0_lives[] = { /* 0x817982c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives4_dlg2,
    } },
    /*  5 */ {  77,   0,   0,   0, {  60,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g7_s0_lives5_dlg1,
        [2] = s_gs1_g7_s0_lives5_dlg2,
    } },
    /*  6 */ {  79,   3,   0,   0, {  62,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g7_s0_lives6_dlg1,
        [2] = s_gs1_g7_s0_lives6_dlg2,
    } },
    /*  7 */ {  80,   6,   0,   0, {  69,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g7_s0_lives7_dlg2,
        [3] = s_gs1_g7_s0_lives7_dlg3,
    } },
};

static const struct GroundLivesData s_gs1_g7_s1_lives[] = { /* 0x81798ec */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g7_s1_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g7_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g8_s0_lives[] = { /* 0x817991c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  75,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g8_s0_lives6_dlg1,
        [2] = s_gs1_g8_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   0,   0,   0, {  65,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g8_s0_lives7_dlg1,
        [2] = s_gs1_g8_s0_lives7_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g8_s1_lives[] = { /* 0x81799dc */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s1_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g8_s2_lives[] = { /* 0x8179a0c */
    /*  0 */ {  78,   6,   0,   0, {  70,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives0_dlg0,
    } },
    /*  1 */ {  85,   2,   0,   0, {  65,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives1_dlg0,
    } },
    /*  2 */ {  86,   2,   0,   0, {  62,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives2_dlg0,
    } },
    /*  3 */ {  87,   2,   0,   0, {  62,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives3_dlg0,
    } },
    /*  4 */ {  77,   6,   0,   0, {  75,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives4_dlg0,
    } },
    /*  5 */ {  79,   4,   0,   0, {  65,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives5_dlg0,
    } },
    /*  6 */ {  54,   0,   0,   0, {  62,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives6_dlg0,
    } },
    /*  7 */ {  80,   0,   0,   0, {  66,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g8_s2_lives7_dlg0,
    } },
    /*  8 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s2_lives8_dlg2,
    } },
    /*  9 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g8_s2_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g9_s0_lives[] = { /* 0x8179afc */
    /*  0 */ {   0,   4,   0,   0, {  97,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g9_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  97,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g9_s0_lives1_dlg0,
    } },
    /*  2 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g9_s0_lives2_dlg0,
        [2] = s_gs1_g9_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g9_s1_lives[] = { /* 0x8179b44 */
    /*  0 */ {  61,   6,   0,   0, {  79,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g9_s1_lives0_dlg0,
    } },
    /*  1 */ {  62,   6,   0,   0, {  77,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g9_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g10_s0_lives[] = { /* 0x8179b74 */
    /*  0 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  1 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  2 */ {   0,   6,   0,   0, {  79,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives2_dlg0,
    } },
    /*  3 */ {   7,   2,   0,   0, {  79,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives3_dlg0,
    } },
    /*  4 */ {  80,   0,   0,   0, {  66,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives4_dlg0,
    } },
    /*  5 */ {  79,   4,   0,   0, {  65,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives5_dlg0,
    } },
    /*  6 */ {  54,   0,   0,   0, {  62,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives6_dlg0,
    } },
    /*  7 */ {  78,   6,   0,   0, {  70,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives7_dlg0,
    } },
    /*  8 */ {  85,   2,   0,   0, {  65,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives8_dlg0,
    } },
    /*  9 */ {  86,   6,   0,   0, {  62,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives9_dlg0,
    } },
    /* 10 */ {  87,   2,   0,   0, {  62,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives10_dlg0,
    } },
    /* 11 */ {  77,   6,   0,   0, {  75,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s0_lives11_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g10_s1_lives[] = { /* 0x8179c94 */
    /*  0 */ {  88,   2,   0,   0, {  47,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s1_lives0_dlg0,
    } },
    /*  1 */ {  89,   2,   0,   0, {  44,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s1_lives1_dlg0,
    } },
    /*  2 */ {  90,   2,   0,   0, {  44,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s1_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g10_s2_lives[] = { /* 0x8179cdc */
    /*  0 */ {  91,   4,   0,   0, {  62,  60, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g10_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g11_s0_lives[] = { /* 0x8179cf4 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  57,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g11_s0_lives6_dlg1,
        [2] = s_gs1_g11_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   6,   0,   0, {  67,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g11_s0_lives7_dlg1,
        [2] = s_gs1_g11_s0_lives7_dlg2,
        [3] = s_gs1_g11_s0_lives7_dlg3,
    } },
    /*  8 */ {  80,   0,   0,   0, {  68,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g11_s0_lives8_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g12_s0_lives[] = { /* 0x8179dcc */
    /*  0 */ {  78,   6,   0,   0, {  70,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives0_dlg0,
    } },
    /*  1 */ {  85,   2,   0,   0, {  65,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives1_dlg0,
    } },
    /*  2 */ {  86,   2,   0,   0, {  62,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives2_dlg0,
    } },
    /*  3 */ {  87,   2,   0,   0, {  62,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives3_dlg0,
    } },
    /*  4 */ {  77,   6,   0,   0, {  75,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives4_dlg0,
    } },
    /*  5 */ {  80,   0,   0,   0, {  66,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives5_dlg0,
    } },
    /*  6 */ {  79,   4,   0,   0, {  65,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives6_dlg0,
    } },
    /*  7 */ {  54,   0,   0,   0, {  62,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives7_dlg0,
    } },
    /*  8 */ {   0,   6,   0,   0, {  76,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives8_dlg0,
    } },
    /*  9 */ {  34,   6,   0,   0, {  76,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g12_s0_lives9_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g13_s0_lives[] = { /* 0x8179ebc */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g13_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  77,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g13_s0_lives6_dlg1,
        [2] = s_gs1_g13_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   0,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g13_s0_lives7_dlg1,
        [2] = s_gs1_g13_s0_lives7_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g14_s0_lives[] = { /* 0x8179f7c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g14_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  77,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g14_s0_lives6_dlg1,
        [2] = s_gs1_g14_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   0,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g14_s0_lives7_dlg1,
        [2] = s_gs1_g14_s0_lives7_dlg2,
    } },
    /*  8 */ {  80,   0,   0,   0, {  59,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g14_s0_lives8_dlg1,
        [2] = s_gs1_g14_s0_lives8_dlg2,
    } },
    /*  9 */ {  78,   3,   0,   0, {  57,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g14_s0_lives9_dlg1,
        [2] = s_gs1_g14_s0_lives9_dlg2,
    } },
    /* 10 */ {  95,   5,   0,   0, {  61,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g14_s0_lives10_dlg1,
        [2] = s_gs1_g14_s0_lives10_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g15_s0_lives[] = { /* 0x817a084 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   2,   0,   0, {  70,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g15_s0_lives6_dlg1,
        [2] = s_gs1_g15_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   6,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g15_s0_lives7_dlg1,
        [2] = s_gs1_g15_s0_lives7_dlg2,
    } },
    /*  8 */ {  78,   0,   0,   0, {  57,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives8_dlg2,
    } },
    /*  9 */ {  95,   0,   0,   0, {  61,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g15_s0_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g16_s0_lives[] = { /* 0x817a174 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g16_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   2,   0,   0, {  63,  40, 0, 0 }, {} },
    /*  7 */ {  79,   7,   0,   0, {  67,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  8 */ {  80,   5,   0,   0, {  67,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs1_g17_s0_lives[] = { /* 0x817a24c */
    /*  0 */ {   0,   2,   0,   0, {  46,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g17_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {  41,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g17_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   2,   0,   0, {  63,  40, 0, 0 }, {
        [0] = s_gs1_g17_s0_lives2_dlg0,
    } },
    /*  3 */ {  79,   7,   0,   0, {  67,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g17_s0_lives3_dlg0,
    } },
    /*  4 */ {  80,   5,   0,   0, {  67,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g17_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g18_s0_lives[] = { /* 0x817a2c4 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g18_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   2,   0,   0, {  63,  40, 0, 0 }, {
        [2] = s_gs1_g18_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   7,   0,   0, {  67,  38, 0, 0 }, {
        [2] = s_gs1_g18_s0_lives7_dlg2,
    } },
    /*  8 */ {  80,   5,   0,   0, {  67,  42, 0, 0 }, {
        [2] = s_gs1_g18_s0_lives8_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g19_s0_lives[] = { /* 0x817a39c */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g19_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g19_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g20_s0_lives[] = { /* 0x817a3cc */
    /*  0 */ {   0,   2,   0,   0, {   7,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g20_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {   4,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g20_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g21_s0_lives[] = { /* 0x817a3fc */
    /*  0 */ {   0,   2,   0,   0, {  34,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  34,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives1_dlg0,
    } },
    /*  2 */ {  91,   0,   0,   0, {  65,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives2_dlg0,
    } },
    /*  3 */ {  54,   3,   0,   0, {  60,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives3_dlg0,
    } },
    /*  4 */ {  77,   5,   0,   0, {  69,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives4_dlg0,
    } },
    /*  5 */ {  79,   3,   0,   0, {  59,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives5_dlg0,
    } },
    /*  6 */ {  80,   3,   0,   0, {  61,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives6_dlg0,
    } },
    /*  7 */ {  72,   7,   0,   0, {  70,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives7_dlg0,
    } },
    /*  8 */ {  75,   5,   0,   0, {  71,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives8_dlg0,
    } },
    /*  9 */ {  73,   6,   0,   0, {  77,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives9_dlg0,
    } },
    /* 10 */ {  76,   4,   0,   0, {  63,  48, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives10_dlg0,
    } },
    /* 11 */ {  70,   6,   0,   0, {  72,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives11_dlg0,
    } },
    /* 12 */ {  71,   6,   0,   0, {  72,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g21_s0_lives12_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g22_s0_lives[] = { /* 0x817a534 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives0_dlg1,
        [2] = s_gs1_g22_s0_lives0_dlg2,
        [3] = s_gs1_g22_s0_lives0_dlg3,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives1_dlg1,
        [2] = s_gs1_g22_s0_lives1_dlg2,
        [3] = s_gs1_g22_s0_lives1_dlg3,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives2_dlg1,
        [2] = s_gs1_g22_s0_lives2_dlg2,
        [3] = s_gs1_g22_s0_lives2_dlg3,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives3_dlg1,
        [2] = s_gs1_g22_s0_lives3_dlg2,
        [3] = s_gs1_g22_s0_lives3_dlg3,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives4_dlg1,
        [2] = s_gs1_g22_s0_lives4_dlg2,
        [3] = s_gs1_g22_s0_lives4_dlg3,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g22_s0_lives5_dlg1,
        [2] = s_gs1_g22_s0_lives5_dlg2,
        [3] = s_gs1_g22_s0_lives5_dlg3,
    } },
};

static const struct GroundLivesData s_gs1_g23_s0_lives[] = { /* 0x817a5c4 */
    /*  0 */ {   0,   2,   0,   0, {  43,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  43,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives1_dlg0,
    } },
    /*  2 */ {  83,   2,   0,   0, {  40,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives2_dlg0,
    } },
    /*  3 */ {  91,   0,   0,   0, {  65,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives3_dlg0,
    } },
    /*  4 */ {  85,   6,   0,   0, {  70,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives4_dlg0,
    } },
    /*  5 */ {  77,   4,   0,   0, {  65,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives5_dlg0,
    } },
    /*  6 */ {  80,   5,   0,   0, {  70,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives6_dlg0,
    } },
    /*  7 */ {  54,   3,   0,   0, {  60,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives7_dlg0,
    } },
    /*  8 */ {  93,   2,   0,   0, {  46,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives8_dlg0,
    } },
    /*  9 */ {  92,   1,   0,   0, {  62,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g23_s0_lives9_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g23_s1_lives[] = { /* 0x817a6b4 */
    /*  0 */ {  55,   0,   0,   0, {  65,  44, CPOS_HALFTILE, 0 }, {
        [0] = s_gs1_g23_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g24_s0_lives[] = { /* 0x817a6cc */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   5,   0,   0, {  70,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g24_s0_lives6_dlg1,
        [2] = s_gs1_g24_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   3,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g24_s0_lives7_dlg1,
        [2] = s_gs1_g24_s0_lives7_dlg2,
    } },
    /*  8 */ {  85,   6,   0,   0, {  65,  36, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g24_s0_lives8_dlg1,
        [2] = s_gs1_g24_s0_lives8_dlg2,
    } },
    /*  9 */ {  80,   0,   0,   0, {  68,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g24_s0_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g24_s1_lives[] = { /* 0x817a7bc */
    /*  0 */ {   0,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g24_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g24_s1_lives1_dlg0,
    } },
    /*  2 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g24_s1_lives2_dlg0,
        [2] = s_gs1_g24_s1_lives2_dlg2,
    } },
    /*  3 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g24_s1_lives3_dlg0,
        [2] = s_gs1_g24_s1_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g25_s0_lives[] = { /* 0x817a81c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  70,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g25_s0_lives6_dlg1,
        [2] = s_gs1_g25_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   0,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g25_s0_lives7_dlg1,
        [2] = s_gs1_g25_s0_lives7_dlg2,
    } },
    /*  8 */ {  85,   0,   0,   0, {  65,  36, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g25_s0_lives8_dlg1,
        [2] = s_gs1_g25_s0_lives8_dlg2,
    } },
    /*  9 */ {  80,   0,   0,   0, {  68,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g25_s0_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g26_s0_lives[] = { /* 0x817a90c */
    /*  0 */ {   0,   2,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  35,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   2,   0,   0, {  38,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives2_dlg0,
    } },
    /*  3 */ {  85,   6,   0,   0, {  76,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives3_dlg0,
    } },
    /*  4 */ { 104,   2,   0,   0, {  63,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives4_dlg0,
    } },
    /*  5 */ { 105,   1,   0,   0, {  69,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives5_dlg0,
    } },
    /*  6 */ { 106,   3,   0,   0, {  67,  45, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives6_dlg0,
    } },
    /*  7 */ { 135,   1,   0,   0, {  64,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives7_dlg0,
    } },
    /*  8 */ { 136,   1,   0,   0, {  61,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives8_dlg0,
    } },
    /*  9 */ { 137,   2,   0,   0, {  60,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives9_dlg0,
    } },
    /* 10 */ { 138,   1,   0,   0, {  65,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives10_dlg0,
    } },
    /* 11 */ { 139,   2,   0,   0, {  64,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives11_dlg0,
    } },
    /* 12 */ { 140,   3,   0,   0, {  63,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives12_dlg0,
    } },
    /* 13 */ { 141,   2,   0,   0, {  60,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives13_dlg0,
    } },
    /* 14 */ { 142,   2,   0,   0, {  67,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives14_dlg0,
    } },
    /* 15 */ { 143,   2,   0,   0, {  68,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives15_dlg0,
    } },
    /* 16 */ {  79,   3,   0,   0, {  70,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g26_s0_lives16_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g27_s0_lives[] = { /* 0x817aaa4 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   0,   0,   0, {  72,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g27_s0_lives6_dlg1,
        [2] = s_gs1_g27_s0_lives6_dlg2,
    } },
    /*  7 */ {  79,   0,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g27_s0_lives7_dlg1,
        [2] = s_gs1_g27_s0_lives7_dlg2,
    } },
    /*  8 */ {  85,   0,   0,   0, {  62,  36, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g27_s0_lives8_dlg1,
        [2] = s_gs1_g27_s0_lives8_dlg2,
    } },
    /*  9 */ {  80,   0,   0,   0, {  68,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g27_s0_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g28_s0_lives[] = { /* 0x817ab94 */
    /*  0 */ {   0,   2,   0,   0, {  41,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  41,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives1_dlg0,
    } },
    /*  2 */ {  85,   6,   0,   0, {  76,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives2_dlg0,
    } },
    /*  3 */ {  91,   0,   0,   0, {  64,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives3_dlg0,
    } },
    /*  4 */ { 104,   6,   0,   0, {  72,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives4_dlg0,
    } },
    /*  5 */ { 105,   6,   0,   0, {  72,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives5_dlg0,
    } },
    /*  6 */ { 106,   5,   0,   0, {  72,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives6_dlg0,
    } },
    /*  7 */ {  77,   2,   0,   0, {  57,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives7_dlg0,
    } },
    /*  8 */ {  79,   3,   0,   0, {  66,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives8_dlg0,
    } },
    /*  9 */ { 136,   1,   0,   0, {  61,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives9_dlg0,
    } },
    /* 10 */ { 137,   2,   0,   0, {  60,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives10_dlg0,
    } },
    /* 11 */ { 139,   2,   0,   0, {  64,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives11_dlg0,
    } },
    /* 12 */ { 140,   3,   0,   0, {  63,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives12_dlg0,
    } },
    /* 13 */ { 141,   2,   0,   0, {  60,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives13_dlg0,
    } },
    /* 14 */ { 142,   1,   0,   0, {  68,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives14_dlg0,
    } },
    /* 15 */ { 143,   2,   0,   0, {  64,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g28_s0_lives15_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g29_s0_lives[] = { /* 0x817ad14 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives5_dlg2,
    } },
    /*  6 */ {  77,   2,   0,   0, {  62,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives6_dlg0,
        [2] = s_gs1_g29_s0_lives6_dlg2,
    } },
    /*  7 */ { 104,   6,   0,   0, {  65,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives7_dlg0,
        [2] = s_gs1_g29_s0_lives7_dlg2,
    } },
    /*  8 */ {  79,   2,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives8_dlg0,
        [2] = s_gs1_g29_s0_lives8_dlg2,
    } },
    /*  9 */ { 105,   6,   0,   0, {  62,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives9_dlg0,
        [2] = s_gs1_g29_s0_lives9_dlg2,
    } },
    /* 10 */ {  85,   2,   0,   0, {  65,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives10_dlg0,
        [2] = s_gs1_g29_s0_lives10_dlg2,
    } },
    /* 11 */ { 106,   6,   0,   0, {  68,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s0_lives11_dlg0,
        [2] = s_gs1_g29_s0_lives11_dlg2,
    } },
    /* 12 */ {  80,   0,   0,   0, {  68,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g29_s0_lives12_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g29_s1_lives[] = { /* 0x817ae4c */
    /*  0 */ {   0,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s1_lives1_dlg0,
    } },
    /*  2 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s1_lives2_dlg0,
        [2] = s_gs1_g29_s1_lives2_dlg2,
    } },
    /*  3 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g29_s1_lives3_dlg0,
        [2] = s_gs1_g29_s1_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g30_s0_lives[] = { /* 0x817aeac */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s0_lives1_dlg0,
        [2] = s_gs1_g30_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives5_dlg2,
    } },
    /*  6 */ { 104,   0,   0,   0, {  65,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s0_lives6_dlg0,
        [2] = s_gs1_g30_s0_lives6_dlg2,
    } },
    /*  7 */ { 105,   3,   0,   0, {  62,  42, 0, 0 }, {
        [0] = s_gs1_g30_s0_lives7_dlg0,
        [2] = s_gs1_g30_s0_lives7_dlg2,
    } },
    /*  8 */ { 106,   5,   0,   0, {  68,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s0_lives8_dlg0,
        [2] = s_gs1_g30_s0_lives8_dlg2,
    } },
    /*  9 */ {  79,   0,   0,   0, {  59,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs1_g30_s0_lives9_dlg1,
        [2] = s_gs1_g30_s0_lives9_dlg2,
    } },
    /* 10 */ {  85,   0,   0,   0, {  57,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives10_dlg2,
    } },
    /* 11 */ {  80,   0,   0,   0, {  68,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives11_dlg2,
    } },
    /* 12 */ {  78,   0,   0,   0, {  69,  14, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g30_s0_lives12_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g30_s1_lives[] = { /* 0x817afe4 */
    /*  0 */ {   0,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  61,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s1_lives1_dlg0,
    } },
    /*  2 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s1_lives2_dlg0,
        [2] = s_gs1_g30_s1_lives2_dlg2,
    } },
    /*  3 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g30_s1_lives3_dlg0,
        [2] = s_gs1_g30_s1_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g31_s0_lives[] = { /* 0x817b044 */
    /*  0 */ {   0,   2,   0,   0, {  46,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  46,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   4,   0,   0, {  82,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives2_dlg0,
    } },
    /*  3 */ {  54,   6,   0,   0, {  78,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives3_dlg0,
    } },
    /*  4 */ {  85,   0,   0,   0, {  82,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives4_dlg0,
    } },
    /*  5 */ { 104,   7,   0,   0, {  89,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives5_dlg0,
    } },
    /*  6 */ { 105,   6,   0,   0, {  90,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives6_dlg0,
    } },
    /*  7 */ { 106,   5,   0,   0, {  87,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives7_dlg0,
    } },
    /*  8 */ {  88,   2,   0,   0, {  41,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives8_dlg0,
    } },
    /*  9 */ {  89,   2,   0,   0, {  40,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives9_dlg0,
    } },
    /* 10 */ {  90,   2,   0,   0, {  40,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives10_dlg0,
    } },
    /* 11 */ { 143,   3,   0,   0, {  56,  50, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives11_dlg0,
    } },
    /* 12 */ { 135,   4,   0,   0, {  75,  54, 0, 0 }, {
        [0] = s_gs1_g31_s0_lives12_dlg0,
    } },
    /* 13 */ { 137,   4,   0,   0, {  67,  54, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives13_dlg0,
    } },
    /* 14 */ {  79,   0,   0,   0, {  62,  26, 0, 0 }, {
        [0] = s_gs1_g31_s0_lives14_dlg0,
    } },
    /* 15 */ { 136,   0,   0,   0, {  65,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives15_dlg0,
    } },
    /* 16 */ { 140,   0,   0,   0, {  66,  26, 0, 0 }, {
        [0] = s_gs1_g31_s0_lives16_dlg0,
    } },
    /* 17 */ { 141,   0,   0,   0, {  60,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives17_dlg0,
    } },
    /* 18 */ { 142,   0,   0,   0, {  68,  21, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives18_dlg0,
    } },
    /* 19 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives19_dlg0,
        [2] = s_gs1_g31_s0_lives19_dlg2,
    } },
    /* 20 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g31_s0_lives20_dlg0,
        [2] = s_gs1_g31_s0_lives20_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g32_s0_lives[] = { /* 0x817b23c */
    /*  0 */ {   0,   6,   0,   0, {  63,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  63,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   5,   0,   0, {  67,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives2_dlg0,
    } },
    /*  3 */ {  54,   7,   0,   0, {  68,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives3_dlg0,
    } },
    /*  4 */ {  85,   6,   0,   0, {  70,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives4_dlg0,
    } },
    /*  5 */ { 104,   6,   0,   0, {  72,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives5_dlg0,
    } },
    /*  6 */ { 105,   6,   0,   0, {  72,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives6_dlg0,
    } },
    /*  7 */ { 106,   5,   0,   0, {  70,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives7_dlg0,
    } },
    /*  8 */ {  88,   2,   0,   0, {  59,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives8_dlg0,
    } },
    /*  9 */ {  89,   2,   0,   0, {  58,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives9_dlg0,
    } },
    /* 10 */ {  90,   2,   0,   0, {  58,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives10_dlg0,
    } },
    /* 11 */ { 143,   4,   0,   0, {  60,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives11_dlg0,
    } },
    /* 12 */ { 135,   5,   0,   0, {  71,  45, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives12_dlg0,
    } },
    /* 13 */ { 137,   4,   0,   0, {  65,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives13_dlg0,
    } },
    /* 14 */ {  79,   0,   0,   0, {  62,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives14_dlg0,
    } },
    /* 15 */ { 136,   0,   0,   0, {  63,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives15_dlg0,
    } },
    /* 16 */ { 140,   0,   0,   0, {  66,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives16_dlg0,
    } },
    /* 17 */ { 141,   1,   0,   0, {  58,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives17_dlg0,
    } },
    /* 18 */ { 142,   7,   0,   0, {  70,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g32_s0_lives18_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g33_s0_lives[] = { /* 0x817b404 */
    /*  0 */ {   0,   0,   0,   0, {  65,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g33_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g34_s0_lives[] = { /* 0x817b41c */
    /*  0 */ {  34,   0,   0,   0, {  65,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives0_dlg2,
    } },
    /*  1 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives1_dlg2,
    } },
    /*  2 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives2_dlg2,
    } },
    /*  3 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives3_dlg2,
    } },
    /*  4 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives4_dlg2,
    } },
    /*  5 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives5_dlg2,
    } },
    /*  6 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives6_dlg2,
    } },
    /*  7 */ { 104,   6,   0,   0, {  72,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives7_dlg2,
    } },
    /*  8 */ { 105,   6,   0,   0, {  72,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives8_dlg2,
    } },
    /*  9 */ { 106,   4,   0,   0, {  64,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives9_dlg2,
    } },
    /* 10 */ {  85,   6,   0,   0, {  70,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives10_dlg2,
    } },
    /* 11 */ {  77,   5,   0,   0, {  59,  47, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives11_dlg2,
    } },
    /* 12 */ {  54,   1,   0,   0, {  56,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives12_dlg2,
    } },
    /* 13 */ {  88,   1,   0,   0, {  60,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives13_dlg2,
    } },
    /* 14 */ {  89,   1,   0,   0, {  56,  35, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives14_dlg2,
    } },
    /* 15 */ {  90,   1,   0,   0, {  59,  31, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g34_s0_lives15_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g35_s0_lives[] = { /* 0x817b59c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives5_dlg2,
    } },
    /*  6 */ { 104,   7,   0,   0, {  71,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives6_dlg2,
    } },
    /*  7 */ { 105,   6,   0,   0, {  73,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives7_dlg2,
    } },
    /*  8 */ { 106,   0,   0,   0, {  68,  31, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives8_dlg2,
    } },
    /*  9 */ {  85,   5,   0,   0, {  71,  45, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives9_dlg2,
    } },
    /* 10 */ {  77,   0,   0,   0, {  58,  36, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives10_dlg2,
    } },
    /* 11 */ {  89,   3,   0,   0, {  59,  46, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives11_dlg2,
    } },
    /* 12 */ {  90,   4,   0,   0, {  62,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives12_dlg2,
    } },
    /* 13 */ {  61,   1,   0,   0, {  61,  28, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives13_dlg2,
    } },
    /* 14 */ {  62,   1,   0,   0, {  59,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g35_s0_lives14_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g36_s0_lives[] = { /* 0x817b704 */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives5_dlg2,
    } },
    /*  6 */ { 104,   7,   0,   0, {  71,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives6_dlg2,
    } },
    /*  7 */ { 105,   2,   0,   0, {  58,  20, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives7_dlg2,
    } },
    /*  8 */ { 106,   1,   0,   0, {  61,  18, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives8_dlg2,
    } },
    /*  9 */ {  85,   6,   0,   0, {  68,  34, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives9_dlg2,
    } },
    /* 10 */ {  77,   5,   0,   0, {  71,  45, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives10_dlg2,
    } },
    /* 11 */ {  89,   1,   0,   0, {  59,  46, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives11_dlg2,
    } },
    /* 12 */ {  90,   5,   0,   0, {  62,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives12_dlg2,
    } },
    /* 13 */ {  61,   0,   0,   0, {  57,  36, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives13_dlg2,
    } },
    /* 14 */ {  62,   0,   0,   0, {  60,  36, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g36_s0_lives14_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g37_s0_lives[] = { /* 0x817b86c */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {} },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {} },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs1_g38_s0_lives[] = { /* 0x817b8fc */
    /*  0 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives0_dlg2,
    } },
    /*  1 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives1_dlg2,
    } },
    /*  2 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives2_dlg2,
    } },
    /*  3 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives3_dlg2,
    } },
    /*  4 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives4_dlg2,
    } },
    /*  5 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives5_dlg2,
    } },
    /*  6 */ {  85,   7,   0,   0, {  69,  36, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives6_dlg2,
    } },
    /*  7 */ {  77,   0,   0,   0, {  90,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives7_dlg2,
    } },
    /*  8 */ {  89,   0,   0,   0, {  57,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives8_dlg2,
    } },
    /*  9 */ {  90,   0,   0,   0, {  61,  33, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives9_dlg2,
    } },
    /* 10 */ {  61,   0,   0,   0, {  58,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives10_dlg2,
    } },
    /* 11 */ {  62,   0,   0,   0, {  61,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives11_dlg2,
    } },
    /* 12 */ {  95,   2,   0,   0, {  60,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives12_dlg2,
    } },
    /* 13 */ {  78,   6,   0,   0, {  64,  43, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g38_s0_lives13_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g38_s1_lives[] = { /* 0x817ba4c */
    /*  0 */ {   0,   0,   0,   0, {  35,  25, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g38_s1_lives0_dlg0,
    } },
    /*  1 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g38_s1_lives1_dlg0,
        [2] = s_gs1_g38_s1_lives1_dlg2,
    } },
    /*  2 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g38_s1_lives2_dlg0,
        [2] = s_gs1_g38_s1_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g39_s0_lives[] = { /* 0x817ba94 */
    /*  0 */ { 124,   0,   0,   0, {  60,  11, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g39_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g40_s0_lives[] = { /* 0x817baac */
    /*  0 */ {  77,   5,   0,   0, {  71,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g40_s0_lives0_dlg0,
        [2] = s_gs1_g40_s0_lives0_dlg2,
        [3] = s_gs1_g40_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs1_g41_s0_lives[] = { /* 0x817bac4 */
    /*  0 */ {  88,   0,   0,   0, {  68,  27, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g41_s0_lives0_dlg0,
        [2] = s_gs1_g41_s0_lives0_dlg2,
        [3] = s_gs1_g41_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs1_g42_s0_lives[] = { /* 0x817badc */
    /*  0 */ {  77,   0,   0,   0, {  65,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives0_dlg2,
    } },
    /*  1 */ {  79,   0,   0,   0, {  65,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g42_s0_lives1_dlg0,
        [2] = s_gs1_g42_s0_lives1_dlg2,
    } },
    /*  2 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives2_dlg2,
    } },
    /*  3 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives3_dlg2,
    } },
    /*  4 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives4_dlg2,
    } },
    /*  5 */ {  76,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives5_dlg2,
    } },
    /*  6 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g42_s0_lives6_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g43_s0_lives[] = { /* 0x817bb84 */
    /*  0 */ {   0,   2,   0,   0, {  70,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g43_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  70,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g43_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   6,   0,   0, {  65,  38, 0, 0 }, {
        [0] = s_gs1_g43_s0_lives2_dlg0,
    } },
    /*  3 */ {  79,   0,   0,   0, {  65,  37, 0, 0 }, {
        [0] = s_gs1_g43_s0_lives3_dlg0,
    } },
    /*  4 */ { 115,   2,   0,   0, {  29,  41, 0, 0 }, {
        [0] = s_gs1_g43_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g44_s0_lives[] = { /* 0x817bbfc */
    /*  0 */ { 115,   0,   0,   0, {  70,  20, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g44_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g45_s0_lives[] = { /* 0x817bc14 */
    /*  0 */ { 115,   0,   0,   0, {  70,  20, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g45_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g45_s1_lives[] = { /* 0x817bc2c */
    /*  0 */ {   0,   2,   0,   0, {  46,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g45_s1_lives0_dlg0,
    } },
    /*  1 */ { 115,   2,   0,   0, {  26,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g45_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g46_s0_lives[] = { /* 0x817bc5c */
    /*  0 */ {   1,   2,   0,   0, {  46,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g46_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {  55,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g46_s0_lives1_dlg0,
    } },
    /*  2 */ {  77,   7,   0,   0, {  67,  38, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives2_dlg0,
    } },
    /*  3 */ {  79,   5,   0,   0, {  67,  43, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives3_dlg0,
    } },
    /*  4 */ { 109,   3,   0,   0, {  63,  43, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives4_dlg0,
    } },
    /*  5 */ { 110,   1,   0,   0, {  63,  38, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives5_dlg0,
    } },
    /*  6 */ {  89,   2,   0,   0, {  42,  42, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives6_dlg0,
    } },
    /*  7 */ { 104,   2,   0,   0, {  39,  39, 0, 0 }, {
        [0] = s_gs1_g46_s0_lives7_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g47_s0_lives[] = { /* 0x817bd1c */
    /*  0 */ {   1,   2,   0,   0, {  39,  41, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  43,  41, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives1_dlg0,
    } },
    /*  2 */ {  70,   5,   0,   0, {  67,  44, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives2_dlg0,
    } },
    /*  3 */ {  71,   4,   0,   0, {  65,  40, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives3_dlg0,
    } },
    /*  4 */ {  72,   3,   0,   0, {  63,  44, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives4_dlg0,
    } },
    /*  5 */ {  75,   1,   0,   0, {  63,  37, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives5_dlg0,
    } },
    /*  6 */ {  88,   7,   0,   0, {  68,  37, 0, 0 }, {
        [0] = s_gs1_g47_s0_lives6_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g48_s0_lives[] = { /* 0x817bdc4 */
    /*  0 */ {   1,   3,   0,   0, {  60,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   3,   0,   0, {  62,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives1_dlg0,
    } },
    /*  2 */ {  70,   5,   0,   0, {  68,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives2_dlg0,
    } },
    /*  3 */ {  71,   4,   0,   0, {  65,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives3_dlg0,
    } },
    /*  4 */ {  88,   5,   0,   0, {  71,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives4_dlg0,
    } },
    /*  5 */ { 121,   0,   0,   0, {  65,  39, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g48_s0_lives5_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g49_s0_lives[] = { /* 0x817be54 */
    /*  0 */ {   1,   2,   0,   0, {  59,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g49_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  59,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g49_s0_lives1_dlg0,
    } },
    /*  2 */ {  70,   0,   0,   0, {  63,  35, 0, 0 }, {
        [0] = s_gs1_g49_s0_lives2_dlg0,
    } },
    /*  3 */ {  71,   0,   0,   0, {  67,  35, 0, 0 }, {
        [0] = s_gs1_g49_s0_lives3_dlg0,
    } },
    /*  4 */ {  88,   7,   0,   0, {  71,  37, 0, 0 }, {
        [0] = s_gs1_g49_s0_lives4_dlg0,
    } },
    /*  5 */ { 121,   6,   0,   0, {  69,  41, 0, 0 }, {
        [0] = s_gs1_g49_s0_lives5_dlg0,
    } },
    /*  6 */ { 122,   2,   0,   0, {  62,  41, 0, 0 }, {
        [0] = s_gs1_g49_s0_lives6_dlg0,
    } },
};

static const struct GroundLivesData s_gs1_g50_s0_lives[] = { /* 0x817befc */
    /*  0 */ {  77,   0,   0,   0, {  71,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives0_dlg2,
    } },
    /*  1 */ {  81,   4,   0,   0, {  58,  44, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives1_dlg2,
    } },
    /*  2 */ {  79,   4,   0,   0, {  59,  47, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives2_dlg2,
    } },
    /*  3 */ {  85,   2,   0,   0, {  61,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs1_g50_s0_lives3_dlg0,
        [2] = s_gs1_g50_s0_lives3_dlg2,
        [3] = s_gs1_g50_s0_lives3_dlg3,
    } },
    /*  4 */ {  70,   0,   0,   0, {  36,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives4_dlg2,
    } },
    /*  5 */ {  71,   0,   0,   0, {  39,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives5_dlg2,
    } },
    /*  6 */ {  72,   0,   0,   0, {  82,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives6_dlg2,
    } },
    /*  7 */ {  73,   0,   0,   0, {  97,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives7_dlg2,
    } },
    /*  8 */ {  75,   0,   0,   0, {  41,  61, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives8_dlg2,
    } },
    /*  9 */ {  74,   0,   0,   0, {  82,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs1_g50_s0_lives9_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g51_s0_lives[] = { /* 0x817bfec */
    /*  0 */ {  93,   2,   0,   0, {  61,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g51_s0_lives0_dlg2,
    } },
    /*  1 */ {  92,   6,   0,   0, {  65,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g51_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs1_g52_s0_lives[] = { /* 0x817c01c */
    /*  0 */ {  82,   6,   0,   0, {  65,  48, 0, CPOS_HALFTILE }, {
        [2] = s_gs1_g52_s0_lives0_dlg2,
    } },
};

static const struct GroundObjectData s_gs1_g0_s0_objs[] = { /* 0x817c034 */
    /*  0 */ {  15,   0,   3,   2, {  13,  37, CPOS_HALFTILE, 0 }, {
        [2] = s_gs1_g0_s0_obj0_dlg2,
    } },
    /*  1 */ {  15,   0,   3,   2, {  68,  10, CPOS_HALFTILE, 0 }, {
        [2] = s_gs1_g0_s0_obj1_dlg2,
    } },
    /*  2 */ {  15,   0,   3,   2, { 114,  36, CPOS_HALFTILE, 0 }, {
        [2] = s_gs1_g0_s0_obj2_dlg2,
    } },
};

static const struct GroundObjectData s_gs1_g5_s1_objs[] = { /* 0x817c07c */
    /*  0 */ {  66,   0,   2,   2, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_obj0_dlg0,
        [1] = s_gs1_g5_s1_obj0_dlg1,
        [2] = s_gs1_g5_s1_obj0_dlg2,
    } },
    /*  1 */ {  66,   0,   2,   2, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_obj1_dlg0,
        [1] = s_gs1_g5_s1_obj1_dlg1,
        [2] = s_gs1_g5_s1_obj1_dlg2,
    } },
    /*  2 */ {  66,   0,   2,   2, { 115,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs1_g5_s1_obj2_dlg0,
        [1] = s_gs1_g5_s1_obj2_dlg1,
        [2] = s_gs1_g5_s1_obj2_dlg2,
    } },
};

static const struct GroundEffectData s_gs1_g6_s0_effs[] = { /* 0x817c0c4 */
    /*  0 */ {   0,   0,   1,   1, {  15,  39, 0, CPOS_HALFTILE }, s_gs1_g6_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g10_s0_effs[] = { /* 0x817c0d0 */
    /*  0 */ {   0,   0,   1,   1, {  66,  40, 0, CPOS_HALFTILE }, s_gs1_g10_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g12_s0_effs[] = { /* 0x817c0dc */
    /*  0 */ {   0,   0,   1,   1, {  66,  40, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs1_g17_s0_effs[] = { /* 0x817c0e8 */
    /*  0 */ {   0,   0,   1,   1, {  64,  40, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs1_g17_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g20_s0_effs[] = { /* 0x817c0f4 */
    /*  0 */ {   0,   0,   1,   1, {  11,  40, 0, CPOS_HALFTILE }, s_gs1_g20_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g21_s0_effs[] = { /* 0x817c100 */
    /*  0 */ {   0,   0,   1,   1, {  43,  42, 0, CPOS_HALFTILE }, s_gs1_g21_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g23_s0_effs[] = { /* 0x817c10c */
    /*  0 */ {   0,   0,   1,   1, {  66,  42, 0, CPOS_HALFTILE }, s_gs1_g23_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g23_s1_effs[] = { /* 0x817c118 */
    /*  0 */ {   5,   0,   1,   1, {  66,  41, 0, CPOS_HALFTILE }, s_gs1_g23_s1_eff0_script },
    /*  1 */ {   5,   0,   1,   1, {  66,  41, 0, CPOS_HALFTILE }, s_gs1_g23_s1_eff1_script },
};

static const struct GroundEffectData s_gs1_g26_s0_effs[] = { /* 0x817c130 */
    /*  0 */ {   0,   0,   1,   1, {  65,  42, 0, CPOS_HALFTILE }, s_gs1_g26_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g28_s0_effs[] = { /* 0x817c13c */
    /*  0 */ {   0,   0,   1,   1, {  53,  42, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs1_g28_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g31_s0_effs[] = { /* 0x817c148 */
    /*  0 */ {   0,   0,   1,   1, {  84,  40, 0, CPOS_HALFTILE }, s_gs1_g31_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g32_s0_effs[] = { /* 0x817c154 */
    /*  0 */ {   0,   0,   1,   1, {  65,  40, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs1_g37_s0_effs[] = { /* 0x817c160 */
    /*  0 */ {   0,   0,   1,   1, {  23,  34, 0, CPOS_HALFTILE }, s_gs1_g37_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g43_s0_effs[] = { /* 0x817c16c */
    /*  0 */ {   0,   0,   1,   1, {  69,  40, 0, CPOS_HALFTILE }, s_gs1_g43_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g46_s0_effs[] = { /* 0x817c178 */
    /*  0 */ {   0,   0,   1,   1, {  64,  42, 0, 0 }, s_gs1_g46_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g47_s0_effs[] = { /* 0x817c184 */
    /*  0 */ {   0,   0,   1,   1, {  65,  41, 0, 0 }, s_gs1_g47_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g48_s0_effs[] = { /* 0x817c190 */
    /*  0 */ {   0,   0,   1,   1, {  65,  44, 0, 0 }, s_gs1_g48_s0_eff0_script },
};

static const struct GroundEffectData s_gs1_g49_s0_effs[] = { /* 0x817c19c */
    /*  0 */ {   0,   0,   1,   1, {  64,  41, CPOS_HALFTILE, 0 }, NULL },
};

static const struct GroundEventData s_gs1_g0_s0_evts[] = { /* 0x817c1a8 */
    /*  0 */ {   3,  12,   0,   0, {   0,  35, 0, 0 }, &s_gs1_g0_s0_evt0_sref },
    /*  1 */ {  15,   6,   0,   0, {  57,   0, 0, 0 }, &s_gs1_g0_s0_evt1_sref },
    /*  2 */ {   3,  12,   0,   0, { 117,  34, 0, 0 }, &s_gs1_g0_s0_evt2_sref },
    /*  3 */ {   9,   3,   0,   0, {  63,  87, 0, 0 }, &s_gs1_g0_s0_evt3_sref },
};

static const struct GroundEventData s_gs1_g8_s2_evts[] = { /* 0x817c1d8 */
    /*  0 */ {   3,   9,   0,   0, {  75,  35, 0, 0 }, &s_gs1_g8_s2_evt0_sref },
};

static const struct GroundEventData s_gs1_g16_s0_evts[] = { /* 0x817c1e4 */
    /*  0 */ {   6,   9,   0,   0, {  47,  36, 0, 0 }, &s_gs1_g16_s0_evt0_sref },
};

static const struct GroundEventData s_gs1_g42_s0_evts[] = { /* 0x817c1f0 */
    /*  0 */ {   6,   9,   0,   0, {  71,  35, 0, 0 }, &s_gs1_g42_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x817c1fc */
    &s_gs1_g0_s0_station_sref,
    &s_gs1_g1_s0_station_sref,
    &s_gs1_g2_s0_station_sref,
    &s_gs1_g4_s1_station_sref,
    &s_gs1_g5_s1_station_sref,
    &s_gs1_g5_s4_station_sref,
    &s_gs1_g6_s0_station_sref,
    &s_gs1_g7_s0_station_sref,
    &s_gs1_g7_s1_station_sref,
    &s_gs1_g8_s0_station_sref,
    &s_gs1_g8_s1_station_sref,
    &s_gs1_g9_s0_station_sref,
    &s_gs1_g10_s0_station_sref,
    &s_gs1_g11_s0_station_sref,
    &s_gs1_g12_s0_station_sref,
    &s_gs1_g13_s0_station_sref,
    &s_gs1_g14_s0_station_sref,
    &s_gs1_g15_s0_station_sref,
    &s_gs1_g16_s0_station_sref,
    &s_gs1_g17_s0_station_sref,
    &s_gs1_g18_s0_station_sref,
    &s_gs1_g19_s0_station_sref,
    &s_gs1_g20_s0_station_sref,
    &s_gs1_g21_s0_station_sref,
    &s_gs1_g22_s0_station_sref,
    &s_gs1_g23_s0_station_sref,
    &s_gs1_g24_s0_station_sref,
    &s_gs1_g24_s1_station_sref,
    &s_gs1_g25_s0_station_sref,
    &s_gs1_g26_s0_station_sref,
    &s_gs1_g27_s0_station_sref,
    &s_gs1_g28_s0_station_sref,
    &s_gs1_g29_s0_station_sref,
    &s_gs1_g29_s1_station_sref,
    &s_gs1_g30_s0_station_sref,
    &s_gs1_g30_s1_station_sref,
    &s_gs1_g31_s0_station_sref,
    &s_gs1_g32_s0_station_sref,
    &s_gs1_g33_s0_station_sref,
    &s_gs1_g34_s0_station_sref,
    &s_gs1_g35_s0_station_sref,
    &s_gs1_g36_s0_station_sref,
    &s_gs1_g37_s0_station_sref,
    &s_gs1_g38_s0_station_sref,
    &s_gs1_g38_s1_station_sref,
    &s_gs1_g43_s0_station_sref,
    &s_gs1_g45_s1_station_sref,
    &s_gs1_g46_s0_station_sref,
    &s_gs1_g47_s0_station_sref,
    &s_gs1_g48_s0_station_sref,
    &s_gs1_g49_s0_station_sref,
};

static const struct GroundScriptSector s_gs1_g0_sectors[] = { /* 0x817c2c8 */
    { 0,NULL, LPARRAY(s_gs1_g0_s0_objs), 0,NULL, LPARRAY(s_gs1_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs1_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g0_s7_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g0_s8_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g1_sectors[] = { /* 0x817c430 */
    { LPARRAY(s_gs1_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs1_g2_sectors[] = { /* 0x817c458 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs1_g3_sectors[] = { /* 0x817c480 */
    { LPARRAY(s_gs1_g3_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g4_sectors[] = { /* 0x817c4a8 */
    { LPARRAY(s_gs1_g4_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g4_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
    { LPARRAY(s_gs1_g4_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g4_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g4_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g5_sectors[] = { /* 0x817c570 */
    { LPARRAY(s_gs1_g5_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g5_s1_lives), LPARRAY(s_gs1_g5_s1_objs), 0,NULL, 0,NULL, 1,&sStationScripts[4], },
    { LPARRAY(s_gs1_g5_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g5_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g5_s4_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[5], },
    { LPARRAY(s_gs1_g5_s5_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g5_s6_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g6_sectors[] = { /* 0x817c688 */
    { LPARRAY(s_gs1_g6_s0_lives), 0,NULL, LPARRAY(s_gs1_g6_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs1_g7_sectors[] = { /* 0x817c6b0 */
    { LPARRAY(s_gs1_g7_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[7], },
    { LPARRAY(s_gs1_g7_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[8], },
};

static const struct GroundScriptSector s_gs1_g8_sectors[] = { /* 0x817c700 */
    { LPARRAY(s_gs1_g8_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[9], },
    { LPARRAY(s_gs1_g8_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[10], },
    { LPARRAY(s_gs1_g8_s2_lives), 0,NULL, 0,NULL, LPARRAY(s_gs1_g8_s2_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g9_sectors[] = { /* 0x817c778 */
    { LPARRAY(s_gs1_g9_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[11], },
    { LPARRAY(s_gs1_g9_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g10_sectors[] = { /* 0x817c7c8 */
    { LPARRAY(s_gs1_g10_s0_lives), 0,NULL, LPARRAY(s_gs1_g10_s0_effs), 0,NULL, 1,&sStationScripts[12], },
    { LPARRAY(s_gs1_g10_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g10_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g11_sectors[] = { /* 0x817c840 */
    { LPARRAY(s_gs1_g11_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[13], },
};

static const struct GroundScriptSector s_gs1_g12_sectors[] = { /* 0x817c868 */
    { LPARRAY(s_gs1_g12_s0_lives), 0,NULL, LPARRAY(s_gs1_g12_s0_effs), 0,NULL, 1,&sStationScripts[14], },
};

static const struct GroundScriptSector s_gs1_g13_sectors[] = { /* 0x817c890 */
    { LPARRAY(s_gs1_g13_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[15], },
};

static const struct GroundScriptSector s_gs1_g14_sectors[] = { /* 0x817c8b8 */
    { LPARRAY(s_gs1_g14_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[16], },
};

static const struct GroundScriptSector s_gs1_g15_sectors[] = { /* 0x817c8e0 */
    { LPARRAY(s_gs1_g15_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[17], },
};

static const struct GroundScriptSector s_gs1_g16_sectors[] = { /* 0x817c908 */
    { LPARRAY(s_gs1_g16_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs1_g16_s0_evts), 1,&sStationScripts[18], },
};

static const struct GroundScriptSector s_gs1_g17_sectors[] = { /* 0x817c930 */
    { LPARRAY(s_gs1_g17_s0_lives), 0,NULL, LPARRAY(s_gs1_g17_s0_effs), 0,NULL, 1,&sStationScripts[19], },
};

static const struct GroundScriptSector s_gs1_g18_sectors[] = { /* 0x817c958 */
    { LPARRAY(s_gs1_g18_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[20], },
};

static const struct GroundScriptSector s_gs1_g19_sectors[] = { /* 0x817c980 */
    { LPARRAY(s_gs1_g19_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[21], },
};

static const struct GroundScriptSector s_gs1_g20_sectors[] = { /* 0x817c9a8 */
    { LPARRAY(s_gs1_g20_s0_lives), 0,NULL, LPARRAY(s_gs1_g20_s0_effs), 0,NULL, 1,&sStationScripts[22], },
};

static const struct GroundScriptSector s_gs1_g21_sectors[] = { /* 0x817c9d0 */
    { LPARRAY(s_gs1_g21_s0_lives), 0,NULL, LPARRAY(s_gs1_g21_s0_effs), 0,NULL, 1,&sStationScripts[23], },
};

static const struct GroundScriptSector s_gs1_g22_sectors[] = { /* 0x817c9f8 */
    { LPARRAY(s_gs1_g22_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[24], },
};

static const struct GroundScriptSector s_gs1_g23_sectors[] = { /* 0x817ca20 */
    { LPARRAY(s_gs1_g23_s0_lives), 0,NULL, LPARRAY(s_gs1_g23_s0_effs), 0,NULL, 1,&sStationScripts[25], },
    { LPARRAY(s_gs1_g23_s1_lives), 0,NULL, LPARRAY(s_gs1_g23_s1_effs), 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g24_sectors[] = { /* 0x817ca70 */
    { LPARRAY(s_gs1_g24_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[26], },
    { LPARRAY(s_gs1_g24_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[27], },
};

static const struct GroundScriptSector s_gs1_g25_sectors[] = { /* 0x817cac0 */
    { LPARRAY(s_gs1_g25_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[28], },
};

static const struct GroundScriptSector s_gs1_g26_sectors[] = { /* 0x817cae8 */
    { LPARRAY(s_gs1_g26_s0_lives), 0,NULL, LPARRAY(s_gs1_g26_s0_effs), 0,NULL, 1,&sStationScripts[29], },
};

static const struct GroundScriptSector s_gs1_g27_sectors[] = { /* 0x817cb10 */
    { LPARRAY(s_gs1_g27_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[30], },
};

static const struct GroundScriptSector s_gs1_g28_sectors[] = { /* 0x817cb38 */
    { LPARRAY(s_gs1_g28_s0_lives), 0,NULL, LPARRAY(s_gs1_g28_s0_effs), 0,NULL, 1,&sStationScripts[31], },
};

static const struct GroundScriptSector s_gs1_g29_sectors[] = { /* 0x817cb60 */
    { LPARRAY(s_gs1_g29_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[32], },
    { LPARRAY(s_gs1_g29_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[33], },
};

static const struct GroundScriptSector s_gs1_g30_sectors[] = { /* 0x817cbb0 */
    { LPARRAY(s_gs1_g30_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[34], },
    { LPARRAY(s_gs1_g30_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[35], },
};

static const struct GroundScriptSector s_gs1_g31_sectors[] = { /* 0x817cc00 */
    { LPARRAY(s_gs1_g31_s0_lives), 0,NULL, LPARRAY(s_gs1_g31_s0_effs), 0,NULL, 1,&sStationScripts[36], },
};

static const struct GroundScriptSector s_gs1_g32_sectors[] = { /* 0x817cc28 */
    { LPARRAY(s_gs1_g32_s0_lives), 0,NULL, LPARRAY(s_gs1_g32_s0_effs), 0,NULL, 1,&sStationScripts[37], },
};

static const struct GroundScriptSector s_gs1_g33_sectors[] = { /* 0x817cc50 */
    { LPARRAY(s_gs1_g33_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[38], },
};

static const struct GroundScriptSector s_gs1_g34_sectors[] = { /* 0x817cc78 */
    { LPARRAY(s_gs1_g34_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[39], },
};

static const struct GroundScriptSector s_gs1_g35_sectors[] = { /* 0x817cca0 */
    { LPARRAY(s_gs1_g35_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[40], },
};

static const struct GroundScriptSector s_gs1_g36_sectors[] = { /* 0x817ccc8 */
    { LPARRAY(s_gs1_g36_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[41], },
};

static const struct GroundScriptSector s_gs1_g37_sectors[] = { /* 0x817ccf0 */
    { LPARRAY(s_gs1_g37_s0_lives), 0,NULL, LPARRAY(s_gs1_g37_s0_effs), 0,NULL, 1,&sStationScripts[42], },
};

static const struct GroundScriptSector s_gs1_g38_sectors[] = { /* 0x817cd18 */
    { LPARRAY(s_gs1_g38_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[43], },
    { LPARRAY(s_gs1_g38_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[44], },
};

static const struct GroundScriptSector s_gs1_g39_sectors[] = { /* 0x817cd68 */
    { LPARRAY(s_gs1_g39_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g40_sectors[] = { /* 0x817cd90 */
    { LPARRAY(s_gs1_g40_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g41_sectors[] = { /* 0x817cdb8 */
    { LPARRAY(s_gs1_g41_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g42_sectors[] = { /* 0x817cde0 */
    { LPARRAY(s_gs1_g42_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs1_g42_s0_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g43_sectors[] = { /* 0x817ce08 */
    { LPARRAY(s_gs1_g43_s0_lives), 0,NULL, LPARRAY(s_gs1_g43_s0_effs), 0,NULL, 1,&sStationScripts[45], },
};

static const struct GroundScriptSector s_gs1_g44_sectors[] = { /* 0x817ce30 */
    { LPARRAY(s_gs1_g44_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g45_sectors[] = { /* 0x817ce58 */
    { LPARRAY(s_gs1_g45_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs1_g45_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[46], },
};

static const struct GroundScriptSector s_gs1_g46_sectors[] = { /* 0x817cea8 */
    { LPARRAY(s_gs1_g46_s0_lives), 0,NULL, LPARRAY(s_gs1_g46_s0_effs), 0,NULL, 1,&sStationScripts[47], },
};

static const struct GroundScriptSector s_gs1_g47_sectors[] = { /* 0x817ced0 */
    { LPARRAY(s_gs1_g47_s0_lives), 0,NULL, LPARRAY(s_gs1_g47_s0_effs), 0,NULL, 1,&sStationScripts[48], },
};

static const struct GroundScriptSector s_gs1_g48_sectors[] = { /* 0x817cef8 */
    { LPARRAY(s_gs1_g48_s0_lives), 0,NULL, LPARRAY(s_gs1_g48_s0_effs), 0,NULL, 1,&sStationScripts[49], },
};

static const struct GroundScriptSector s_gs1_g49_sectors[] = { /* 0x817cf20 */
    { LPARRAY(s_gs1_g49_s0_lives), 0,NULL, LPARRAY(s_gs1_g49_s0_effs), 0,NULL, 1,&sStationScripts[50], },
};

static const struct GroundScriptSector s_gs1_g50_sectors[] = { /* 0x817cf48 */
    { LPARRAY(s_gs1_g50_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g51_sectors[] = { /* 0x817cf70 */
    { LPARRAY(s_gs1_g51_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs1_g52_sectors[] = { /* 0x817cf98 */
    { LPARRAY(s_gs1_g52_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs1_groups[] = { /* 0x817cfc0 */
    { LPARRAY(s_gs1_g0_sectors) },
    { LPARRAY(s_gs1_g1_sectors) },
    { LPARRAY(s_gs1_g2_sectors) },
    { LPARRAY(s_gs1_g3_sectors) },
    { LPARRAY(s_gs1_g4_sectors) },
    { LPARRAY(s_gs1_g5_sectors) },
    { LPARRAY(s_gs1_g6_sectors) },
    { LPARRAY(s_gs1_g7_sectors) },
    { LPARRAY(s_gs1_g8_sectors) },
    { LPARRAY(s_gs1_g9_sectors) },
    { LPARRAY(s_gs1_g10_sectors) },
    { LPARRAY(s_gs1_g11_sectors) },
    { LPARRAY(s_gs1_g12_sectors) },
    { LPARRAY(s_gs1_g13_sectors) },
    { LPARRAY(s_gs1_g14_sectors) },
    { LPARRAY(s_gs1_g15_sectors) },
    { LPARRAY(s_gs1_g16_sectors) },
    { LPARRAY(s_gs1_g17_sectors) },
    { LPARRAY(s_gs1_g18_sectors) },
    { LPARRAY(s_gs1_g19_sectors) },
    { LPARRAY(s_gs1_g20_sectors) },
    { LPARRAY(s_gs1_g21_sectors) },
    { LPARRAY(s_gs1_g22_sectors) },
    { LPARRAY(s_gs1_g23_sectors) },
    { LPARRAY(s_gs1_g24_sectors) },
    { LPARRAY(s_gs1_g25_sectors) },
    { LPARRAY(s_gs1_g26_sectors) },
    { LPARRAY(s_gs1_g27_sectors) },
    { LPARRAY(s_gs1_g28_sectors) },
    { LPARRAY(s_gs1_g29_sectors) },
    { LPARRAY(s_gs1_g30_sectors) },
    { LPARRAY(s_gs1_g31_sectors) },
    { LPARRAY(s_gs1_g32_sectors) },
    { LPARRAY(s_gs1_g33_sectors) },
    { LPARRAY(s_gs1_g34_sectors) },
    { LPARRAY(s_gs1_g35_sectors) },
    { LPARRAY(s_gs1_g36_sectors) },
    { LPARRAY(s_gs1_g37_sectors) },
    { LPARRAY(s_gs1_g38_sectors) },
    { LPARRAY(s_gs1_g39_sectors) },
    { LPARRAY(s_gs1_g40_sectors) },
    { LPARRAY(s_gs1_g41_sectors) },
    { LPARRAY(s_gs1_g42_sectors) },
    { LPARRAY(s_gs1_g43_sectors) },
    { LPARRAY(s_gs1_g44_sectors) },
    { LPARRAY(s_gs1_g45_sectors) },
    { LPARRAY(s_gs1_g46_sectors) },
    { LPARRAY(s_gs1_g47_sectors) },
    { LPARRAY(s_gs1_g48_sectors) },
    { LPARRAY(s_gs1_g49_sectors) },
    { LPARRAY(s_gs1_g50_sectors) },
    { LPARRAY(s_gs1_g51_sectors) },
    { LPARRAY(s_gs1_g52_sectors) },
};

static const struct GroundLink s_gs1_links[] = { /* 0x817d168 */
    /* link   0 */ { { /*x*/  90, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  30, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/   2, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/ 117, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   4 */ { { /*x*/  70, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   5 */ { { /*x*/  59, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   6 */ { { /*x*/   2, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   7 */ { { /*x*/  12, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/  14, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/  37, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/  82, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  11 */ { { /*x*/  82, /*y*/  61, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  12 */ { { /*x*/  41, /*y*/  61, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  13 */ { { /*x*/  14, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  14 */ { { /*x*/  56, /*y*/  42, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
    /* link  15 */ { { /*x*/  56, /*y*/  30, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/  9, /*ret*/ 3, /*?*/ 2 },
    /* link  16 */ { { /*x*/  68, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  8, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  17 */ { { /*x*/  56, /*y*/  42, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
    /* link  18 */ { { /*x*/  97, /*y*/  37, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  19 */ { { /*x*/  97, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  20 */ { { /*x*/  93, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  21 */ { { /*x*/  93, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  22 */ { { /*x*/  76, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  23 */ { { /*x*/  76, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  24 */ { { /*x*/  65, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  25 */ { { /*x*/  62, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  26 */ { { /*x*/  58, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  27 */ { { /*x*/  83, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  28 */ { { /*x*/ 101, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  29 */ { { /*x*/  56, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  30 */ { { /*x*/  86, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  31 */ { { /*x*/  98, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  32 */ { { /*x*/  56, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  33 */ { { /*x*/  86, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  34 */ { { /*x*/  99, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  35 */ { { /*x*/  49, /*y*/  65, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  36 */ { { /*x*/  56, /*y*/  42, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
    /* link  37 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  8, /*ret*/ 3, /*?*/ 2 },
    /* link  38 */ { { /*x*/  67, /*y*/  33, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  39 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  8, /*ret*/ 3, /*?*/ 2 },
    /* link  40 */ { { /*x*/  67, /*y*/  33, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  41 */ { { /*x*/  68, /*y*/  33, /*flags*/ 0, 0 }, /*w*/  8, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  42 */ { { /*x*/  56, /*y*/  42, /*flags*/ 0, 0 }, /*w*/ 12, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
    /* link  43 */ { { /*x*/  58, /*y*/  37, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  44 */ { { /*x*/  58, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  45 */ { { /*x*/  56, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  46 */ { { /*x*/  94, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  47 */ { { /*x*/  94, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  48 */ { { /*x*/  35, /*y*/  62, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  49 */ { { /*x*/  87, /*y*/  62, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  50 */ { { /*x*/  26, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  51 */ { { /*x*/  65, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  52 */ { { /*x*/  65, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  53 */ { { /*x*/  61, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  54 */ { { /*x*/  59, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  55 */ { { /*x*/  59, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  56 */ { { /*x*/  60, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  57 */ { { /*x*/  65, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  58 */ { { /*x*/  61, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  59 */ { { /*x*/  51, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  60 */ { { /*x*/  57, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  61 */ { { /*x*/  51, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  62 */ { { /*x*/  57, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  63 */ { { /*x*/  50, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  64 */ { { /*x*/  60, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  65 */ { { /*x*/  50, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  66 */ { { /*x*/  60, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  67 */ { { /*x*/  47, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  68 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  69 */ { { /*x*/  63, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  70 */ { { /*x*/  63, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  71 */ { { /*x*/  66, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  72 */ { { /*x*/  66, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  73 */ { { /*x*/  60, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  74 */ { { /*x*/  59, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  75 */ { { /*x*/  65, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  76 */ { { /*x*/  39, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  77 */ { { /*x*/  55, /*y*/  29, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  9, /*ret*/ 3, /*?*/ 2 },
    /* link  78 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  8, /*ret*/ 3, /*?*/ 2 },
    /* link  79 */ { { /*x*/  68, /*y*/  33, /*flags*/ 0, 0 }, /*w*/ 10, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  80 */ { { /*x*/  55, /*y*/  29, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  9, /*ret*/ 3, /*?*/ 2 },
    /* link  81 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  8, /*ret*/ 3, /*?*/ 2 },
    /* link  82 */ { { /*x*/  68, /*y*/  33, /*flags*/ 0, 0 }, /*w*/ 10, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  83 */ { { /*x*/  57, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  84 */ { { /*x*/  57, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  85 */ { { /*x*/  60, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  86 */ { { /*x*/  54, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  87 */ { { /*x*/  57, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  88 */ { { /*x*/  57, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  89 */ { { /*x*/  57, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  90 */ { { /*x*/  72, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  91 */ { { /*x*/  35, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  92 */ { { /*x*/  72, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  93 */ { { /*x*/  72, /*y*/  43, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  94 */ { { /*x*/  67, /*y*/  45, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  95 */ { { /*x*/  59, /*y*/  46, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  96 */ { { /*x*/  55, /*y*/  29, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  9, /*ret*/ 3, /*?*/ 2 },
    /* link  97 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 11, /*h*/  8, /*ret*/ 3, /*?*/ 2 },
    /* link  98 */ { { /*x*/  68, /*y*/  33, /*flags*/ 0, 0 }, /*w*/ 10, /*h*/ 13, /*ret*/ 3, /*?*/ 2 },
    /* link  99 */ { { /*x*/  53, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 100 */ { { /*x*/  67, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 101 */ { { /*x*/  53, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 102 */ { { /*x*/  64, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 103 */ { { /*x*/  67, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 104 */ { { /*x*/  64, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 105 */ { { /*x*/  64, /*y*/  38, /*flags*/ CPOS_CURRENT, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 106 */ { { /*x*/  64, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 107 */ { { /*x*/  62, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 108 */ { { /*x*/  58, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 109 */ { { /*x*/  60, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 110 */ { { /*x*/  62, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 111 */ { { /*x*/  65, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 112 */ { { /*x*/  65, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 113 */ { { /*x*/  62, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 114 */ { { /*x*/  70, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 115 */ { { /*x*/  65, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 116 */ { { /*x*/  63, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 117 */ { { /*x*/  63, /*y*/  39, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 118 */ { { /*x*/  59, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 119 */ { { /*x*/  58, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 120 */ { { /*x*/  58, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 121 */ { { /*x*/  68, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 122 */ { { /*x*/  70, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 123 */ { { /*x*/  67, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 124 */ { { /*x*/  72, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 125 */ { { /*x*/  72, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 126 */ { { /*x*/  70, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 127 */ { { /*x*/  66, /*y*/  34, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 128 */ { { /*x*/  62, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 129 */ { { /*x*/  63, /*y*/  32, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 130 */ { { /*x*/  58, /*y*/  34, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 131 */ { { /*x*/  70, /*y*/  33, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 132 */ { { /*x*/  60, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 133 */ { { /*x*/  65, /*y*/  46, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 134 */ { { /*x*/  71, /*y*/  45, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 135 */ { { /*x*/  59, /*y*/  34, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 136 */ { { /*x*/  65, /*y*/  20, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 137 */ { { /*x*/  59, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 138 */ { { /*x*/  59, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 139 */ { { /*x*/  59, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 140 */ { { /*x*/  67, /*y*/  44, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 141 */ { { /*x*/  67, /*y*/  59, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 142 */ { { /*x*/  56, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 143 */ { { /*x*/  57, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 144 */ { { /*x*/  60, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 145 */ { { /*x*/  60, /*y*/  38, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs1 = { LPARRAY(s_gs1_groups), s_gs1_links }; /* 0x817d5f8 */
