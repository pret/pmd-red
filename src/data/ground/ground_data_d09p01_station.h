


















static const struct ScriptCommand s_gs195_g0_s0_station_sref_script[] = { /* 0x8245cc8 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(5, /* to label */ 0),
    EXECUTE_STATION(12, 0, 0),
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
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 12, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 11, /* to label */ 6),
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
    BGM_SWITCH(25),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs195_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs195_g0_s0_station_sref_script }; /* 0x8245f84 */

static const struct ScriptCommand s_gs195_g0_s0_obj0_dlg2[] = { /* 0x8245f90 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_AND_WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs195_g0_s1_lives0_dlg0[] = { /* 0x8245fb0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s1_lives1_dlg0[] = { /* 0x8245ff0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s2_lives0_dlg0[] = { /* 0x8246030 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s2_lives1_dlg0[] = { /* 0x8246070 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s3_lives0_dlg0[] = { /* 0x82460b0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s3_lives1_dlg0[] = { /* 0x82460f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s4_lives0_dlg0[] = { /* 0x8246130 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s4_lives1_dlg0[] = { /* 0x8246160 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs195_g0_s5_obj0_dlg2[] = { /* 0x8246190 */
    DEBUGINFO,
    JUMP_SCRIPT(WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs195_g0_s5_obj1_dlg2[] = { /* 0x82461b0 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs195_g1_s0_station_sref_script[] = { /* 0x82461d0 */
    DEBUGINFO,
    BGM_STOP,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    WAIT(4),
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Darn it!\nWhere'd they go?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" They had to go this way!\nKeep your eyes open!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Rooooooaaaar!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(503),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Tromp, tromp, tromp, tromp, tromp!") },
    WAIT(120),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("........................") },
    WAIT(120),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ............") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ........................") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...I think...#W\nThey're gone.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(25),
    { 0x3b, 0x3a,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs195_g1_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs195_g1_s0_station_sref_script }; /* 0x82464f8 */



static const struct ScriptCommand s_gs195_g1_s0_eff0_script[] = { /* 0x8246504 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs195_g1_s0_lives0_dlg0[] = { /* 0x8246544 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew.\nI think we gave them the slip.")),
    VARIANT_DEFAULT(_(" Whew.\nI think we managed to evade them.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But...#W\nThere's no point hiding out here.")),
    VARIANT_DEFAULT(_(" But...#W\nThere isn't any point hiding here.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We have to get over this\nmountain to get away.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0, we need to\nroll as soon as we're ready.")),
    VARIANT_DEFAULT(_(" Let's go as soon as we're\nready, $n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs195_g1_s0_lives1_dlg0[] = { /* 0x824696c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x014c,  0x00000003,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(15),
    { 0x6b, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs195_g2_s0_station_sref_script[] = { /* 0x8246acc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs195_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs195_g2_s0_station_sref_script }; /* 0x8246afc */

static const struct ScriptCommand s_gs195_g2_s0_lives0_dlg2[] = { /* 0x8246b08 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptCommand s_gs195_g2_s0_evt0_sref_script[] = { /* 0x8246b38 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptRef s_gs195_g2_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs195_g2_s0_evt0_sref_script }; /* 0x8246b68 */

static const struct ScriptCommand s_gs195_g2_s1_station_sref_script[] = { /* 0x8246b74 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    CANCEL_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs195_g2_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs195_g2_s1_station_sref_script }; /* 0x8246bc4 */

static const struct ScriptCommand s_gs195_g2_s1_lives0_dlg0[] = { /* 0x8246bd0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x8e, 0x01,  0x0000,  0x00000022,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" $n0, are you ready\nto roll?")),
    VARIANT_DEFAULT(_(" $n0, are you\nready?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("*Not yet.")),
  LABEL(3), /* = 0x03 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll wait while you get ready.")),
    VARIANT(/* == */  1, _(" Other Pokémon are\nwandering about, so make it quick.")),
    VARIANT_DEFAULT(_(" I'll be waiting while you get\nready.")),
    VARIANT_DEFAULT(_(" Try to be quick.\nOther Pokémon are out looking for us.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
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
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 7),
    COND_EQUAL(3, /* to label */ 7),
    COND_EQUAL(5, /* to label */ 7),
    WAIT(20),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    WAIT(20),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
  LABEL(8), /* = 0x08 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e,  0x0000000b,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
  LABEL(6), /* = 0x06 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sure thing!\nLet's roll on out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 9),
    COND_EQUAL(3, /* to label */ 9),
    COND_EQUAL(5, /* to label */ 9),
    WAIT(20),
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    WAIT(20),
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
  LABEL(10), /* = 0x0a */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x06, 0x00,  0x001e,  0x0000004e,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
};




static const struct ScriptCommand s_gs195_g2_s1_lives1_dlg0[] = { /* 0x8247300 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(0),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(7, /* to label */ 0),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000006,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs195_g3_s0_station_sref_script[] = { /* 0x8247450 */
    DEBUGINFO,
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(25),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs195_g3_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs195_g3_s0_station_sref_script }; /* 0x82474e0 */

static const struct ScriptCommand s_gs195_g3_s0_lives0_dlg0[] = { /* 0x82474ec */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...#W\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...#W\nWe couldn't break through...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(463),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x08,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Ssh!#W\nSomeone's coming.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Where are they?\n$n0 and that sidekick.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Do you think they tried getting over\nMt. Blaze?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" No, that's impossible.#W\nNobody could ever get past it.") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" They should be around here still.\nKeep looking!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Rooooooaaaar!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(503),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Tromp, tromp, tromp, tromp, tromp!") },
    WAIT(120),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("........................") },
    WAIT(120),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ............") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ........................") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...Whew.") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll have to get over this\nmountain to get away from them.")),
    VARIANT_DEFAULT(_(" If we're going to get away,\nwe'll have to go over the mountain.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};



static const struct ScriptCommand s_gs195_g3_s0_lives1_dlg0[] = { /* 0x8247b14 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0200,  0x00000009,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000009,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs195_g4_s0_station_sref_script[] = { /* 0x8247c94 */
    DEBUGINFO,
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(25),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs195_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs195_g4_s0_station_sref_script }; /* 0x8247d24 */

static const struct ScriptCommand s_gs195_g4_s0_lives0_dlg0[] = { /* 0x8247d30 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What the...?#W\nIsn't this where we started from?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#W\nI guess that path just loops back to the\nstart.")),
    VARIANT(/* == */  1, _(" If we want to move on,\nI think our only choice is #CDMt. Blaze#R.")),
    VARIANT(/* == */  1, _(" $n0, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" ............#W\nI guess that path we took just loops back\nto where it started.")),
    VARIANT_DEFAULT(_(" It looks like we have to go\nover #CDMt. Blaze#R to move on.")),
    VARIANT_DEFAULT(_(" $n0, let's do our\nbest!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs195_g4_s0_lives1_dlg0[] = { /* 0x82480b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs195_g5_s0_station_sref_script[] = { /* 0x8248194 */
    DEBUGINFO,
    SELECT_MAP(195),
    SELECT_WEATHER(13),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(25),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs195_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs195_g5_s0_station_sref_script }; /* 0x8248224 */

static const struct ScriptCommand s_gs195_g5_s0_lives0_dlg0[] = { /* 0x8248230 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...#W\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...#W\nWe couldn't break through...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We have to get through this\nfast, or they'll catch up to us.")),
    VARIANT(/* == */  1, _(" $n0, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" If we don't get through here\nfast, they'll catch up to us.")),
    VARIANT_DEFAULT(_(" $n0, let's do our\nbest!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs195_g5_s0_lives1_dlg0[] = { /* 0x8248458 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
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

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82487bc */
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

/*extern*/ const struct GroundScriptHeader gGroundScript_gs195 = { LPARRAY(s_gs195_groups), s_gs195_links }; /* 0x8248a40 */
