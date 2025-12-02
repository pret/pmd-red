
static const struct ScriptCommand s_gs198_g0_s0_station_sref_script[] = { /* 0x824bbfc */
    DEBUGINFO_O(11),
    JUMPIF_SCENARIOCHECK(QUEST_UNK5, /* to label */ 0),
    EXECUTE_STATION(MAP_TEAM_BASE_INSIDE, 0, 0),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 13, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    CALL_STATION(  2,  0),
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
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs198_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs198_g0_s0_station_sref_script }; /* 0x824beb8 */

static const struct ScriptCommand s_gs198_g0_s0_obj0_dlg2[] = { /* 0x824bec4 */
    DEBUGINFO_O(57),
    JUMP_SCRIPT(SAVE_AND_WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs198_g0_s1_lives0_dlg0[] = { /* 0x824bee4 */
    DEBUGINFO_O(62),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s1_lives1_dlg0[] = { /* 0x824bf24 */
    DEBUGINFO_O(69),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s2_lives0_dlg0[] = { /* 0x824bf64 */
    DEBUGINFO_O(76),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s2_lives1_dlg0[] = { /* 0x824bfa4 */
    DEBUGINFO_O(83),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s3_lives0_dlg0[] = { /* 0x824bfe4 */
    DEBUGINFO_O(90),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s3_lives1_dlg0[] = { /* 0x824c024 */
    DEBUGINFO_O(97),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs198_g0_s4_lives0_dlg0[] = { /* 0x824c094 */
    DEBUGINFO_O(107),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s4_lives1_dlg0[] = { /* 0x824c0c4 */
    DEBUGINFO_O(113),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs198_g0_s5_obj0_dlg2[] = { /* 0x824c0f4 */
    DEBUGINFO_O(119),
    JUMP_SCRIPT(WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs198_g0_s5_obj1_dlg2[] = { /* 0x824c114 */
    DEBUGINFO_O(124),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs198_g1_s0_station_sref_script[] = { /* 0x824c134 */
    DEBUGINFO_O(129),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs198_g1_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs198_g1_s0_station_sref_script }; /* 0x824c204 */

static const struct ScriptCommand s_gs198_g1_s0_eff0_script[] = { /* 0x824c210 */
    DEBUGINFO_O(147),
    CAMERA_END_PAN,
    CAMERA_INIT_PAN,
    { 0x89, 0xc8,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs198_g1_s0_lives0_dlg0[] = { /* 0x824c290 */
    DEBUGINFO_O(158),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...So, we do have to get\nthrough this, huh?")),
    VARIANT_DEFAULT(_(" OK.\nWe don't have a choice--we have to\nget through this place.")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(0),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's going to be awfully cold.\nIt's not anywhere I really want to go...")),
    VARIANT_DEFAULT(_(" It will be horribly cold.\nI'd rather not go if I didn't have to...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But there's no point in us\nsticking around here forever...")),
    VARIANT(/* == */  1, _(" We can only go forward!{WAIT_PRESS}\nWe'll just have to go for it and get\nthrough this, {NAME_0}!")),
    VARIANT_DEFAULT(_(" But hiding out in this area\nisn't the answer either...")),
    VARIANT_DEFAULT(_(" We can only go forward.{WAIT_PRESS}\nWe'll just have to keep our spirits up\nand keep going, {NAME_0}!")),
    TEXTBOX_CLEAR,
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_WEST),
    WAIT(10),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};


static const struct ScriptCommand s_gs198_g1_s0_lives1_dlg0[] = { /* 0x824c670 */
    DEBUGINFO_O(188),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_EAST),
    HALT,
};

static const struct ScriptCommand s_gs198_g2_s0_station_sref_script[] = { /* 0x824c6d0 */
    DEBUGINFO_O(197),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const ScriptRef s_gs198_g2_s0_station_sref = { STATION_CONTROL, SCRIPT_TYPE_08, NULL, s_gs198_g2_s0_station_sref_script }; /* 0x824c700 */

static const struct ScriptCommand s_gs198_g2_s0_lives0_dlg2[] = { /* 0x824c70c */
    DEBUGINFO_O(205),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptCommand s_gs198_g2_s0_evt0_sref_script[] = { /* 0x824c73c */
    DEBUGINFO_O(211),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const ScriptRef s_gs198_g2_s0_evt0_sref = { GETOUT_NORMAL, SCRIPT_TYPE_02, NULL, s_gs198_g2_s0_evt0_sref_script }; /* 0x824c76c */

static const struct ScriptCommand s_gs198_g2_s1_station_sref_script[] = { /* 0x824c778 */
    DEBUGINFO_O(219),
    SELECT_ENTITIES(-1, 1),
    CANCEL_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    RET,
};

static const ScriptRef s_gs198_g2_s1_station_sref = { EVENT_WAKEUP, SCRIPT_TYPE_07, NULL, s_gs198_g2_s1_station_sref_script }; /* 0x824c7c8 */

static const struct ScriptCommand s_gs198_g2_s1_lives0_dlg0[] = { /* 0x824c7d4 */
    DEBUGINFO_O(229),
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
    VARIANT(/* == */  1, _(" Hah? Not yet?")),
    VARIANT(/* == */  1, _(" All right.\nI'll wait till you're ready.")),
    VARIANT_DEFAULT(_(" Huh? Not yet?")),
    VARIANT_DEFAULT(_(" OK.\nI'll wait while you get ready.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _(" Which way should we go?")),
    CHOICE(/* label */  5, _("Frosty Forest.")),
    CHOICE(/* label */  6, _("Snow Path.")),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll on out!")),
    VARIANT(/* == */  1, _(" It's freezing cold, but let's\ngive it our best!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    VARIANT_DEFAULT(_(" It's going to be freezing\ncold, but let's try our best!")),
    TEXTBOX_CLEAR,
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 7),
    COND_EQUAL(3, /* to label */ 7),
    COND_EQUAL(5, /* to label */ 7),
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0032,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    BGM_FADEOUT(120),
    CAMERA_PAN(128, 0),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0040,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    BGM_FADEOUT(120),
    CAMERA_PAN(179, 0),
  LABEL(8), /* = 0x08 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e,  0x0000000d,  0x00000000, NULL },
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
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0032,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    BGM_FADEOUT(120),
    CAMERA_PAN(128, 0),
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0040,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    BGM_FADEOUT(120),
    CAMERA_PAN(192, 0),
  LABEL(10), /* = 0x0a */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x06, 0x00,  0x001e,  0x0000004f,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
};




static const struct ScriptCommand s_gs198_g2_s1_lives1_dlg0[] = { /* 0x824cea4 */
    DEBUGINFO_O(315),
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
    CAMERA_PAN(128, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(192, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs198_g3_s0_station_sref_script[] = { /* 0x824cfe4 */
    DEBUGINFO_O(338),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs198_g3_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs198_g3_s0_station_sref_script }; /* 0x824d0b4 */

static const struct ScriptCommand s_gs198_g3_s0_lives0_dlg0[] = { /* 0x824d0c0 */
    DEBUGINFO_O(356),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...{WAIT_PRESS}\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nWe couldn't break through...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is a tough place...")),
    VARIANT_DEFAULT(_(" This is as tough as we\nexpected...")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But let's give it our best\nand get through this, {NAME_0}!")),
    VARIANT_DEFAULT(_(" But let's keep trying our\nbest and get through this, {NAME_0}!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};


static const struct ScriptCommand s_gs198_g3_s0_lives1_dlg0[] = { /* 0x824d364 */
    DEBUGINFO_O(385),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_EAST),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs198_g4_s0_station_sref_script[] = { /* 0x824d424 */
    DEBUGINFO_O(400),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs198_g4_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs198_g4_s0_station_sref_script }; /* 0x824d4f4 */

static const struct ScriptCommand s_gs198_g4_s0_lives0_dlg0[] = { /* 0x824d500 */
    DEBUGINFO_O(418),
    SELECT_ANIMATION(8),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    SELECT_ANIMATION(2),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_WEST),
    WAIT(30),
    { 0x2d, 0x09,  0x0002,  0x00000066,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmmm...{WAIT_PRESS}\nWell, that didn't go well.")),
    VARIANT_DEFAULT(_(" Hmm...{WAIT_PRESS}\nWe didn't do well at all...")),
    TEXTBOX_CLEAR,
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That {NAME_2}...\nHe's one tough customer.")),
    VARIANT(/* == */  1, _(" But why aren't we allowed\nto go into this forest?")),
    VARIANT(/* == */  1, _(" ...It doesn't matter anyway.\nLet's give it our best, {NAME_0}!")),
    VARIANT_DEFAULT(_(" That Pokémon,\n{NAME_2}, is pretty tough.")),
    VARIANT_DEFAULT(_(" But why are we forbidden\nfrom entering this forest?")),
    VARIANT_DEFAULT(_(" It makes no difference.\n{NAME_0}, let's try our best!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};


static const struct ScriptCommand s_gs198_g4_s0_lives1_dlg0[] = { /* 0x824d834 */
    DEBUGINFO_O(448),
    SELECT_ANIMATION(8),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    SELECT_ANIMATION(2),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_EAST),
    HALT,
};

static const struct ScriptCommand s_gs198_g5_s0_station_sref_script[] = { /* 0x824d8a4 */
    DEBUGINFO_O(458),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs198_g5_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs198_g5_s0_station_sref_script }; /* 0x824d974 */

static const struct ScriptCommand s_gs198_g5_s0_lives0_dlg0[] = { /* 0x824d980 */
    DEBUGINFO_O(476),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" What the...?{WAIT_PRESS}\nIsn't this where we started from?!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(468),
    ALERT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............{WAIT_PRESS}\nI guess that path just loops back to the\nstart.")),
    VARIANT(/* == */  1, _(" If we want to move on,\nI think our only choice is the {COLOR YELLOW_D}Frosty\nForest{RESET}.")),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" ............{WAIT_PRESS}\nI guess that path we took just loops back\nto where it started.")),
    VARIANT_DEFAULT(_(" It looks like we have to get\nthrough the {COLOR YELLOW_D}Frosty Forest{RESET} to move on.")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's do our\nbest!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs198_g5_s0_lives1_dlg0[] = { /* 0x824dd18 */
    DEBUGINFO_O(510),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0080,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    CMD_UNK_E5(5, 0),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs198_g6_s0_station_sref_script[] = { /* 0x824ddf8 */
    DEBUGINFO_O(527),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_FROSTY_FOREST_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_FROSTY_FOREST_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_ESCAPE_THROUGH_THE_SNOW),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const ScriptRef s_gs198_g6_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs198_g6_s0_station_sref_script }; /* 0x824dec8 */

static const struct ScriptCommand s_gs198_g6_s0_lives0_dlg0[] = { /* 0x824ded4 */
    DEBUGINFO_O(545),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    AWAIT_CUE(5),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...{WAIT_PRESS}\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nWe couldn't break through...")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is one harsh place,\nbut let's bear down and get through,\n{NAME_0}!")),
    VARIANT_DEFAULT(_(" This is a harsh place,\nso let's do our best to get through,\n{NAME_0}!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs198_g6_s0_lives1_dlg0[] = { /* 0x824e0f8 */
    DEBUGINFO_O(573),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct GroundLivesData s_gs198_g0_s0_lives[] = { /* 0x824e1c8 */
    /*  0 */ { 144,   0,   0,   0, {   7,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs198_g0_s1_lives[] = { /* 0x824e1e0 */
    /*  0 */ {   0,   4,   0,   0, {  17,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  17,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g0_s2_lives[] = { /* 0x824e210 */
    /*  0 */ {   0,   0,   0,   0, {  17,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  17,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g0_s3_lives[] = { /* 0x824e240 */
    /*  0 */ {   0,   4,   0,   0, {  17,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  17,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g0_s4_lives[] = { /* 0x824e270 */
    /*  0 */ {   0,   4,   0,   0, {  17,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  17,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs198_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g0_s5_lives[] = { /* 0x824e2a0 */
    /*  0 */ { 144,   0,   0,   0, {   7,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  1 */ { 145,   0,   0,   0, {  23,  35, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs198_g1_s0_lives[] = { /* 0x824e2d0 */
    /*  0 */ {   0,   4,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  15,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g2_s0_lives[] = { /* 0x824e300 */
    /*  0 */ {  34,   6,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [2] = s_gs198_g2_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs198_g2_s1_lives[] = { /* 0x824e318 */
    /*  0 */ {   0,   6,   0,   0, {  15,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g2_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g2_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g3_s0_lives[] = { /* 0x824e348 */
    /*  0 */ {   0,   0,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  15,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g3_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g4_s0_lives[] = { /* 0x824e378 */
    /*  0 */ {   0,   6,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  15,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g4_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g5_s0_lives[] = { /* 0x824e3a8 */
    /*  0 */ {   0,   6,   0,   0, {  19,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  15,  30, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs198_g6_s0_lives[] = { /* 0x824e3d8 */
    /*  0 */ {   0,   6,   0,   0, {  19,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g6_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  15,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs198_g6_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs198_g0_s0_objs[] = { /* 0x824e408 */
    /*  0 */ {   4,   0,   4,   2, {   8,  32, 0, 0 }, {
        [2] = s_gs198_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs198_g0_s5_objs[] = { /* 0x824e420 */
    /*  0 */ {   4,   0,   4,   2, {   8,  32, 0, 0 }, {
        [2] = s_gs198_g0_s5_obj0_dlg2,
    } },
    /*  1 */ {   4,   0,   4,   3, {  23,  35, 0, CPOS_HALFTILE }, {
        [2] = s_gs198_g0_s5_obj1_dlg2,
    } },
};

static const struct GroundEffectData s_gs198_g1_s0_effs[] = { /* 0x824e450 */
    /*  0 */ {   0,   0,   1,   1, {  17,   9, 0, CPOS_HALFTILE }, s_gs198_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs198_g3_s0_effs[] = { /* 0x824e45c */
    /*  0 */ {   0,   0,   1,   1, {  17,  33, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs198_g4_s0_effs[] = { /* 0x824e468 */
    /*  0 */ {   0,   0,   1,   1, {  17,  33, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs198_g5_s0_effs[] = { /* 0x824e474 */
    /*  0 */ {   0,   0,   1,   1, {  17,  33, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs198_g6_s0_effs[] = { /* 0x824e480 */
    /*  0 */ {   0,   0,   1,   1, {  17,  33, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs198_g2_s0_evts[] = { /* 0x824e48c */
    /*  0 */ {   4,   3,   0,   0, {  15,  27, 0, 0 }, &s_gs198_g2_s0_evt0_sref },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x824e498 */
    &s_gs198_g0_s0_station_sref,
    &s_gs198_g1_s0_station_sref,
    &s_gs198_g2_s0_station_sref,
    &s_gs198_g2_s1_station_sref,
    &s_gs198_g3_s0_station_sref,
    &s_gs198_g4_s0_station_sref,
    &s_gs198_g5_s0_station_sref,
    &s_gs198_g6_s0_station_sref,
};

static const struct GroundScriptSector s_gs198_g0_sectors[] = { /* 0x824e4b8 */
    { LPARRAY(s_gs198_g0_s0_lives), LPARRAY(s_gs198_g0_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[0], },
    { LPARRAY(s_gs198_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs198_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs198_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs198_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs198_g0_s5_lives), LPARRAY(s_gs198_g0_s5_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs198_g1_sectors[] = { /* 0x824e5a8 */
    { LPARRAY(s_gs198_g1_s0_lives), 0,NULL, LPARRAY(s_gs198_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs198_g2_sectors[] = { /* 0x824e5d0 */
    { LPARRAY(s_gs198_g2_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs198_g2_s0_evts), 1,&sStationScripts[2], },
    { LPARRAY(s_gs198_g2_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs198_g3_sectors[] = { /* 0x824e620 */
    { LPARRAY(s_gs198_g3_s0_lives), 0,NULL, LPARRAY(s_gs198_g3_s0_effs), 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs198_g4_sectors[] = { /* 0x824e648 */
    { LPARRAY(s_gs198_g4_s0_lives), 0,NULL, LPARRAY(s_gs198_g4_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs198_g5_sectors[] = { /* 0x824e670 */
    { LPARRAY(s_gs198_g5_s0_lives), 0,NULL, LPARRAY(s_gs198_g5_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs198_g6_sectors[] = { /* 0x824e698 */
    { LPARRAY(s_gs198_g6_s0_lives), 0,NULL, LPARRAY(s_gs198_g6_s0_effs), 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptGroup s_gs198_groups[] = { /* 0x824e6c0 */
    { LPARRAY(s_gs198_g0_sectors) },
    { LPARRAY(s_gs198_g1_sectors) },
    { LPARRAY(s_gs198_g2_sectors) },
    { LPARRAY(s_gs198_g3_sectors) },
    { LPARRAY(s_gs198_g4_sectors) },
    { LPARRAY(s_gs198_g5_sectors) },
    { LPARRAY(s_gs198_g6_sectors) },
};

static const struct GroundLink s_gs198_links[] = { /* 0x824e6f8 */
    /* link   0 */ { { /*x*/  17, /*y*/  27, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

const GroundScriptHeader gGroundScript_gs198 = { LPARRAY(s_gs198_groups), s_gs198_links }; /* 0x824e700 */
