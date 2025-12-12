
static const struct ScriptCommand s_gs195_g0_s0_station_sref_script[] = { /* 0x8245cc8 */
    DEBUGINFO_O(21),
    JUMPIF_SCENARIOCHECK(QUEST_UNK5, /* to label */ 0),
    EXECUTE_STATION(MAP_TEAM_BASE_INSIDE, 0, 0),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(195),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 12, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_ENTITIES(2, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, STARTMODE_10, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_LOST, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, STARTMODE_11, /* to label */ 6),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 7),
    JUMP_LABEL(7),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(8),
  LABEL(4), /* = 0x04 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(8),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    BGM_SWITCH(MUS_MT_BLAZE),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs195_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs195_g0_s0_station_sref_script }; /* 0x8245f84 */

static const struct ScriptCommand s_gs195_g0_s0_obj0_dlg2[] = { /* 0x8245f90 */
    DEBUGINFO_O(67),
    JUMP_SCRIPT(SAVE_AND_WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs195_g0_s1_lives0_dlg0[] = { /* 0x8245fb0 */
    DEBUGINFO_O(72),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s1_lives1_dlg0[] = { /* 0x8245ff0 */
    DEBUGINFO_O(79),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s2_lives0_dlg0[] = { /* 0x8246030 */
    DEBUGINFO_O(86),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s2_lives1_dlg0[] = { /* 0x8246070 */
    DEBUGINFO_O(93),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s3_lives0_dlg0[] = { /* 0x82460b0 */
    DEBUGINFO_O(100),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s3_lives1_dlg0[] = { /* 0x82460f0 */
    DEBUGINFO_O(107),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s4_lives0_dlg0[] = { /* 0x8246130 */
    DEBUGINFO_O(114),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s4_lives1_dlg0[] = { /* 0x8246160 */
    DEBUGINFO_O(120),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s5_obj0_dlg2[] = { /* 0x8246190 */
    DEBUGINFO_O(126),
    JUMP_SCRIPT(WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs195_g0_s5_obj1_dlg2[] = { /* 0x82461b0 */
    DEBUGINFO_O(131),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs195_g1_s0_station_sref_script[] = { /* 0x82461d0 */
    DEBUGINFO_O(136),
    BGM_STOP,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    WAIT(4),
    WAIT(30),
    MSG_NPC(-1, _(" Darn it!\nWhere'd they go?")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" They had to go this way!\nKeep your eyes open!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" Rooooooaaaar!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    FANFARE_PLAY2(503),
    MSG_OVERHEARD(_("Tromp, tromp, tromp, tromp, tromp!")),
    WAIT(120),
    MSG_OVERHEARD(_("........................")),
    WAIT(120),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_NPC(1, _(" ............")),
    MSG_NPC(1, _(" ........................")),
    MSG_NPC(1, _(" ...I think...{WAIT_PRESS}\nThey're gone.")),
    TEXTBOX_CLEAR,
    BGM_SWITCH(MUS_MT_BLAZE),
    { 0x3b, 0x3a,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs195_g1_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs195_g1_s0_station_sref_script }; /* 0x82464f8 */



static const struct ScriptCommand s_gs195_g1_s0_eff0_script[] = { /* 0x8246504 */
    DEBUGINFO_O(178),
    CAMERA_END_PAN,
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs195_g1_s0_lives0_dlg0[] = { /* 0x8246544 */
    DEBUGINFO_O(185),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    WAIT(1),
    WALK_GRID(256, 0),
    WALK_GRID(256, 1),
    WAIT(30),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    WALK_GRID(256, 2),
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_SOUTH),
    WAIT(20),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew.\nI think we gave them the slip.")),
    VARIANT_DEFAULT(_(" Whew.\nI think we managed to evade them.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But...{WAIT_PRESS}\nThere's no point hiding out here.")),
    VARIANT_DEFAULT(_(" But...{WAIT_PRESS}\nThere isn't any point hiding here.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTH),
    MSG_NPC(1, _(" We have to get over this\nmountain to get away.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    WAIT(10),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}, we need to\nroll as soon as we're ready.")),
    VARIANT_DEFAULT(_(" Let's go as soon as we're\nready, {NAME_0}.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};


static const struct ScriptCommand s_gs195_g1_s0_lives1_dlg0[] = { /* 0x824696c */
    DEBUGINFO_O(235),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(332, 3),
    WALK_GRID(256, 4),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(15),
    WALK_GRID(256, 5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTH),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs195_g2_s0_station_sref_script[] = { /* 0x8246acc */
    DEBUGINFO_O(260),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const ScriptRef s_gs195_g2_s0_station_sref = { STATION_CONTROL, SCRIPT_TYPE_08, NULL, s_gs195_g2_s0_station_sref_script }; /* 0x8246afc */

static const struct ScriptCommand s_gs195_g2_s0_lives0_dlg2[] = { /* 0x8246b08 */
    DEBUGINFO_O(268),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptCommand s_gs195_g2_s0_evt0_sref_script[] = { /* 0x8246b38 */
    DEBUGINFO_O(274),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const ScriptRef s_gs195_g2_s0_evt0_sref = { GETOUT_NORMAL, SCRIPT_TYPE_02, NULL, s_gs195_g2_s0_evt0_sref_script }; /* 0x8246b68 */

static const struct ScriptCommand s_gs195_g2_s1_station_sref_script[] = { /* 0x8246b74 */
    DEBUGINFO_O(282),
    SELECT_ENTITIES(-1, 1),
    CANCEL_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    RET,
};

static const ScriptRef s_gs195_g2_s1_station_sref = { EVENT_WAKEUP, SCRIPT_TYPE_07, NULL, s_gs195_g2_s1_station_sref_script }; /* 0x8246bc4 */

static const struct ScriptCommand s_gs195_g2_s1_lives0_dlg0[] = { /* 0x8246bd0 */
    DEBUGINFO_O(292),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CMD_UNK_8E(1, DIR_TRANS_NONE, 34),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" {NAME_0}, are you ready\nto roll?")),
    VARIANT_DEFAULT(_(" {NAME_0}, are you\nready?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("*Not yet.")),
  LABEL(3), /* = 0x03 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll wait while you get ready.")),
    VARIANT(/* == */  1, _(" Other Pokémon are\nwandering about, so make it quick.")),
    VARIANT_DEFAULT(_(" I'll be waiting while you get\nready.")),
    VARIANT_DEFAULT(_(" Try to be quick.\nOther Pokémon are out looking for us.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _(" Which way should we go?")),
    CHOICE(/* label */  5, _("Mt. Blaze.")),
    CHOICE(/* label */  6, _("Rock Path.")),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll on out!")),
    VARIANT(/* == */  1, _(" It looks like one wicked\nplace, but let's give it our best!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    VARIANT_DEFAULT(_(" It sounds very rough,\nbut let's try our best!")),
    TEXTBOX_CLEAR,
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 7),
    COND_EQUAL(3, /* to label */ 7),
    COND_EQUAL(5, /* to label */ 7),
    WAIT(20),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    WALK_GRID(153, 6),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    WAIT(20),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(15),
    WALK_GRID(153, 6),
  LABEL(8), /* = 0x08 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e,  0x0000000b,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
  LABEL(6), /* = 0x06 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sure thing!\nLet's roll on out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    TEXTBOX_CLEAR,
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 9),
    COND_EQUAL(3, /* to label */ 9),
    COND_EQUAL(5, /* to label */ 9),
    WAIT(20),
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    WALK_GRID(153, 6),
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    WAIT(20),
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(15),
    WALK_GRID(153, 6),
  LABEL(10), /* = 0x0a */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x06, 0x00,  0x001e,  0x0000004e,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
};




static const struct ScriptCommand s_gs195_g2_s1_lives1_dlg0[] = { /* 0x8247300 */
    DEBUGINFO_O(380),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CMD_UNK_8E(1, DIR_TRANS_NONE, 0),
    AWAIT_CUE(6),
    CJUMP_UNK_C8(0),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(7, /* to label */ 0),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(153, 6),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_NORTHWEST),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(153, 6),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs195_g3_s0_station_sref_script[] = { /* 0x8247450 */
    DEBUGINFO_O(404),
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_BLAZE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs195_g3_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs195_g3_s0_station_sref_script }; /* 0x82474e0 */

static const struct ScriptCommand s_gs195_g3_s0_lives0_dlg0[] = { /* 0x82474ec */
    DEBUGINFO_O(418),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...{WAIT_PRESS}\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nWe couldn't break through...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(463),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Ssh!{WAIT_PRESS}\nSomeone's coming.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    CAMERA_PAN(512, 7),
    WALK_GRID(512, 8),
    WAIT(30),
    MSG_NPC(-1, _(" Where are they?\n{NAME_0} and that sidekick.")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" Do you think they tried getting over\nMt. Blaze?")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" No, that's impossible.{WAIT_PRESS}\nNobody could ever get past it.")),
    MSG_NPC(-1, _(" They should be around here still.\nKeep looking!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" Rooooooaaaar!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    FANFARE_PLAY2(503),
    MSG_OVERHEARD(_("Tromp, tromp, tromp, tromp, tromp!")),
    WAIT(120),
    MSG_OVERHEARD(_("........................")),
    WAIT(120),
    TEXTBOX_CLEAR,
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000000),
    MSG_NPC(1, _(" ............")),
    MSG_NPC(1, _(" ........................")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    WAIT(15),
    WALK_GRID(512, 7),
    WALK_GRID(256, 2),
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_SOUTHWEST),
    WAIT(20),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000000),
    MSG_NPC(1, _(" ...Whew.")),
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll have to get over this\nmountain to get away from them.")),
    VARIANT_DEFAULT(_(" If we're going to get away,\nwe'll have to go over the mountain.")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};



static const struct ScriptCommand s_gs195_g3_s0_lives1_dlg0[] = { /* 0x8247b14 */
    DEBUGINFO_O(492),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CAMERA_PAN(512, 9),
    WALK_GRID(512, 10),
    AWAIT_CUE(6),
    WALK_GRID(512, 9),
    WALK_GRID(256, 5),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs195_g4_s0_station_sref_script[] = { /* 0x8247c94 */
    DEBUGINFO_O(519),
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_BLAZE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs195_g4_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs195_g4_s0_station_sref_script }; /* 0x8247d24 */

static const struct ScriptCommand s_gs195_g4_s0_lives0_dlg0[] = { /* 0x8247d30 */
    DEBUGINFO_O(533),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" What the...?{WAIT_PRESS}\nIsn't this where we started from?!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(468),
    ALERT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............{WAIT_PRESS}\nI guess that path just loops back to the\nstart.")),
    VARIANT(/* == */  1, _(" If we want to move on,\nI think our only choice is {COLOR YELLOW_D}Mt. Blaze{RESET}.")),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" ............{WAIT_PRESS}\nI guess that path we took just loops back\nto where it started.")),
    VARIANT_DEFAULT(_(" It looks like we have to go\nover {COLOR YELLOW_D}Mt. Blaze{RESET} to move on.")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's do our\nbest!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs195_g4_s0_lives1_dlg0[] = { /* 0x82480b4 */
    DEBUGINFO_O(567),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    CMD_UNK_E5(5, 0),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_SPINRIGHT1, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs195_g5_s0_station_sref_script[] = { /* 0x8248194 */
    DEBUGINFO_O(584),
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_BLAZE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs195_g5_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs195_g5_s0_station_sref_script }; /* 0x8248224 */

static const struct ScriptCommand s_gs195_g5_s0_lives0_dlg0[] = { /* 0x8248230 */
    DEBUGINFO_O(598),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...{WAIT_PRESS}\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nWe couldn't break through...")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We have to get through this\nfast, or they'll catch up to us.")),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" If we don't get through here\nfast, they'll catch up to us.")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's do our\nbest!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs195_g5_s0_lives1_dlg0[] = { /* 0x8248458 */
    DEBUGINFO_O(627),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_SPINRIGHT1, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct GroundLivesData s_gs195_g0_s0_lives[] = { /* 0x8248528 */
    /*  0 */ { 144,   0,   0,   0, {  28,  30, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs195_g0_s1_lives[] = { /* 0x8248540 */
    /*  0 */ {   0,   4,   0,   0, {  22,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g0_s2_lives[] = { /* 0x8248570 */
    /*  0 */ {   0,   0,   0,   0, {  22,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  22,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g0_s3_lives[] = { /* 0x82485a0 */
    /*  0 */ {   0,   4,   0,   0, {  22,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g0_s4_lives[] = { /* 0x82485d0 */
    /*  0 */ {   0,   4,   0,   0, {  22,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  22,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs195_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g0_s5_lives[] = { /* 0x8248600 */
    /*  0 */ { 144,   0,   0,   0, {  28,  30, 0, CPOS_HALFTILE }, {} },
    /*  1 */ { 145,   0,   0,   0, {  28,  35, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs195_g1_s0_lives[] = { /* 0x8248630 */
    /*  0 */ {   0,   3,   0,   0, {   3,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   3,   0,   0, {   4,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g2_s0_lives[] = { /* 0x8248660 */
    /*  0 */ {  34,   0,   0,   0, {  24,  26, 0, CPOS_HALFTILE }, {
        [2] = s_gs195_g2_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs195_g2_s1_lives[] = { /* 0x8248678 */
    /*  0 */ {   0,   2,   0,   0, {  21,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g2_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g2_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g3_s0_lives[] = { /* 0x82486a8 */
    /*  0 */ {   0,   2,   0,   0, {  21,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g3_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g4_s0_lives[] = { /* 0x82486d8 */
    /*  0 */ {   0,   2,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g4_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs195_g5_s0_lives[] = { /* 0x8248708 */
    /*  0 */ {   0,   2,   0,   0, {  21,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs195_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs195_g0_s0_objs[] = { /* 0x8248738 */
    /*  0 */ {   4,   0,   4,   3, {  28,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs195_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs195_g0_s5_objs[] = { /* 0x8248750 */
    /*  0 */ {   4,   0,   4,   3, {  28,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs195_g0_s5_obj0_dlg2,
    } },
    /*  1 */ {   4,   0,   4,   3, {  28,  35, 0, CPOS_HALFTILE }, {
        [2] = s_gs195_g0_s5_obj1_dlg2,
    } },
};

static const struct GroundEffectData s_gs195_g1_s0_effs[] = { /* 0x8248780 */
    /*  0 */ {   0,   0,   1,   1, {  22,  25, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs195_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs195_g3_s0_effs[] = { /* 0x824878c */
    /*  0 */ {   0,   0,   1,   1, {  22,  25, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs195_g4_s0_effs[] = { /* 0x8248798 */
    /*  0 */ {   0,   0,   1,   1, {  22,  25, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs195_g5_s0_effs[] = { /* 0x82487a4 */
    /*  0 */ {   0,   0,   1,   1, {  22,  25, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs195_g2_s0_evts[] = { /* 0x82487b0 */
    /*  0 */ {  12,   3,   0,   0, {  17,  19, 0, 0 }, &s_gs195_g2_s0_evt0_sref },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x82487bc */
    &s_gs195_g0_s0_station_sref,
    &s_gs195_g1_s0_station_sref,
    &s_gs195_g2_s0_station_sref,
    &s_gs195_g2_s1_station_sref,
    &s_gs195_g3_s0_station_sref,
    &s_gs195_g4_s0_station_sref,
    &s_gs195_g5_s0_station_sref,
};

static const struct GroundScriptSector s_gs195_g0_sectors[] = { /* 0x82487d8 */
    { LPARRAY(s_gs195_g0_s0_lives), LPARRAY(s_gs195_g0_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[0], },
    { LPARRAY(s_gs195_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs195_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs195_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs195_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs195_g0_s5_lives), LPARRAY(s_gs195_g0_s5_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs195_g1_sectors[] = { /* 0x82488c8 */
    { LPARRAY(s_gs195_g1_s0_lives), 0,NULL, LPARRAY(s_gs195_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs195_g2_sectors[] = { /* 0x82488f0 */
    { LPARRAY(s_gs195_g2_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs195_g2_s0_evts), 1,&sStationScripts[2], },
    { LPARRAY(s_gs195_g2_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs195_g3_sectors[] = { /* 0x8248940 */
    { LPARRAY(s_gs195_g3_s0_lives), 0,NULL, LPARRAY(s_gs195_g3_s0_effs), 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs195_g4_sectors[] = { /* 0x8248968 */
    { LPARRAY(s_gs195_g4_s0_lives), 0,NULL, LPARRAY(s_gs195_g4_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs195_g5_sectors[] = { /* 0x8248990 */
    { LPARRAY(s_gs195_g5_s0_lives), 0,NULL, LPARRAY(s_gs195_g5_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptGroup s_gs195_groups[] = { /* 0x82489b8 */
    { LPARRAY(s_gs195_g0_sectors) },
    { LPARRAY(s_gs195_g1_sectors) },
    { LPARRAY(s_gs195_g2_sectors) },
    { LPARRAY(s_gs195_g3_sectors) },
    { LPARRAY(s_gs195_g4_sectors) },
    { LPARRAY(s_gs195_g5_sectors) },
};

static const struct GroundLink s_gs195_links[] = { /* 0x82489e8 */
    /* link   0 */ { { /*x*/  11, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  17, /*y*/  30, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  21, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  15, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   4 */ { { /*x*/  21, /*y*/  29, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   5 */ { { /*x*/  24, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   6 */ { { /*x*/  22, /*y*/  20, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   7 */ { { /*x*/  11, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   8 */ { { /*x*/   3, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   9 */ { { /*x*/  15, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  10 */ { { /*x*/   4, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

const GroundScriptHeader gGroundScript_gs195 = { LPARRAY(s_gs195_groups), s_gs195_links }; /* 0x8248a40 */
