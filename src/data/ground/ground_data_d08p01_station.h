










static const struct ScriptCommand s_gs193_g0_s0_station_sref_script[] = { /* 0x8242bb8 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(5, /* to label */ 0),
    EXECUTE_STATION(12, 0, 0),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(193),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 11, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    CALL_STATION(  3,  0),
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
    BGM_SWITCH(102),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs193_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs193_g0_s0_station_sref_script }; /* 0x8242e54 */

static const struct ScriptCommand s_gs193_g0_s0_obj0_dlg2[] = { /* 0x8242e60 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_AND_WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs193_g0_s1_lives0_dlg0[] = { /* 0x8242e80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s1_lives1_dlg0[] = { /* 0x8242ec0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s2_lives0_dlg0[] = { /* 0x8242f00 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s2_lives1_dlg0[] = { /* 0x8242f40 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s3_lives0_dlg0[] = { /* 0x8242f80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s3_lives1_dlg0[] = { /* 0x8242fc0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s4_lives0_dlg0[] = { /* 0x8243000 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s4_lives1_dlg0[] = { /* 0x8243030 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs193_g0_s5_obj0_dlg2[] = { /* 0x8243060 */
    DEBUGINFO,
    JUMP_SCRIPT(WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs193_g0_s5_obj1_dlg2[] = { /* 0x8243080 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs193_g1_s0_station_sref_script[] = { /* 0x82430a0 */
    DEBUGINFO,
    SELECT_MAP(193),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(24),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x02, 0x00,  0x0000,  0x0000000a,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs193_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs193_g1_s0_station_sref_script }; /* 0x8243130 */

static const struct ScriptCommand s_gs193_g1_s0_lives0_dlg0[] = { /* 0x824313c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(30),
    WAIT(120),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew!\nWe sure came a long way out.")),
    VARIANT_DEFAULT(_(" Whew.\nWe've sure traveled a long way.")),
    BGM_SWITCH(102),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But I was thinking...\nWhile we were on the way...")),
    VARIANT_DEFAULT(_(" But while we were moving,\nI couldn't help thinking...")),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So many places are hit\nby the natural disasters...")),
    VARIANT(/* == */  1, _(" I bet there are many\nPokémon that need help.")),
    VARIANT(/* == */  1, _(" I'd really like to get back to\ndoing our rescue work...")),
    VARIANT_DEFAULT(_(" All sorts of places have\nbeen affected by the natural disasters.")),
    VARIANT_DEFAULT(_(" I'm sure many Pokémon are\nsuffering because of the calamities.")),
    VARIANT_DEFAULT(_(" I wish we could get back to\ndoing our rescue work...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Sorry, I shouldn't complain.\nWe have to get away now, period.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh? I hear voices...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(20),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" I think they went this way.") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" They can't get away.\nNot from all of us.") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" We have to get rid of $n0\nquickly...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whoa!\nThey're catching up to us already?")),
    VARIANT(/* == */  1, _(" $n0, we have to\nroll.")),
    VARIANT_DEFAULT(_(" Aww, no!\nAre they catching up to us?")),
    VARIANT_DEFAULT(_(" $n0, we'd better\ngo.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs193_g1_s0_lives1_dlg0[] = { /* 0x824389c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x02,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x91, 0x02,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0x91, 0x02,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x91, 0x02,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs193_g2_s0_station_sref_script[] = { /* 0x8243a1c */
    DEBUGINFO,
    SELECT_MAP(193),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(102),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION(  3,  0),
    RET,
};

static const struct ScriptRef s_gs193_g2_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs193_g2_s0_station_sref_script }; /* 0x8243aac */

static const struct ScriptCommand s_gs193_g2_s0_lives0_dlg0[] = { /* 0x8243ab8 */
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
    VARIANT(/* == */  1, _(" I think we got cocky and\ncareless, $n0.")),
    VARIANT(/* == */  1, _(" Wonder what happened to\nthe Pokémon chasing us?\nAre they in the dungeon?")),
    VARIANT(/* == */  1, _(" Well, running into them\nwould be bad trouble.\nLet's get through this...and fast.")),
    VARIANT_DEFAULT(_(" I guess we got a little\ncareless, $n0.")),
    VARIANT_DEFAULT(_(" I wonder what became of\nthe Pokémon chasing us?\nAre they in the dungeon?")),
    VARIANT_DEFAULT(_(" We sure don't want to run\ninto them.\nLet's get through this quickly.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs193_g2_s0_lives1_dlg0[] = { /* 0x8243e64 */
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

static const struct ScriptCommand s_gs193_g3_s0_station_sref_script[] = { /* 0x8243f34 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs193_g3_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs193_g3_s0_station_sref_script }; /* 0x8243f64 */

static const struct ScriptCommand s_gs193_g3_s0_lives0_dlg1[] = { /* 0x8243f70 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    JUMP_SCRIPT(LIVES_MOVE_NORMAL),
};

static const struct ScriptCommand s_gs193_g3_s0_lives0_dlg2[] = { /* 0x8243fb0 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 3, 1),
    HALT,
};

static const struct ScriptCommand s_gs193_g3_s0_evt0_sref_script[] = { /* 0x8243fe0 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 3, 1),
    HALT,
};

static const struct ScriptRef s_gs193_g3_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs193_g3_s0_evt0_sref_script }; /* 0x8244010 */

static const struct ScriptCommand s_gs193_g3_s1_station_sref_script[] = { /* 0x824401c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    CANCEL_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs193_g3_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs193_g3_s1_station_sref_script }; /* 0x824406c */

static const struct ScriptCommand s_gs193_g3_s1_lives0_dlg0[] = { /* 0x8244078 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x8e, 0x01,  0x0000,  0x00000022,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hey, $n0.\nAre you all ready?")),
    VARIANT_DEFAULT(_(" Hi, $n0.\nAre you ready?")),
    CHOICE(/* label */  0, _("All set!")),
    CHOICE(/* label */  1, _("Not yet.")),
  LABEL(1), /* = 0x01 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right.\nWe'll go when you're ready.")),
    VARIANT_DEFAULT(_(" OK.\nLet's go when you're ready.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _(" Which way should we go?")),
    CHOICE(/* label */  2, _("Lapis Cave.")),
    CHOICE(/* label */  3, _("Rock Path.")),
    JUMP_LABEL(1),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 4),
    COND_EQUAL(3, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 4),
    COND_EQUAL(5, /* to label */ 4),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x23, 0x00,  0x0046,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0046,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
  LABEL(5), /* = 0x05 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e,  0x0000000a,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
  LABEL(3), /* = 0x03 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CJUMP_UNK_C8(34),
    COND_EQUAL(2, /* to label */ 6),
    COND_EQUAL(3, /* to label */ 6),
    COND_EQUAL(4, /* to label */ 6),
    COND_EQUAL(5, /* to label */ 6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x0046,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x0046,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
  LABEL(7), /* = 0x07 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x06, 0x00,  0x001e,  0x0000004e,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const struct ScriptCommand s_gs193_g3_s1_lives1_dlg0[] = { /* 0x8244648 */
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
    COND_EQUAL(6, /* to label */ 0),
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs193_g4_s0_station_sref_script[] = { /* 0x8244768 */
    DEBUGINFO,
    SELECT_MAP(193),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(102),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION(  3,  0),
    RET,
};

static const struct ScriptRef s_gs193_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs193_g4_s0_station_sref_script }; /* 0x82447f8 */

static const struct ScriptCommand s_gs193_g4_s0_lives0_dlg0[] = { /* 0x8244804 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x20,  0x0100,  0x00000007,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
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
    VARIANT(/* == */  1, _(" If we want to move on,\nI think our only choice is the #CDLapis Cave#R.")),
    VARIANT(/* == */  1, _(" $n0, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" ............#W\nI guess that path we took just loops back\nto where it started.")),
    VARIANT_DEFAULT(_(" It looks like we have to go\nthrough the #CDLapis Cave#R to move on.")),
    VARIANT_DEFAULT(_(" $n0, let's do our\nbest!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs193_g4_s0_lives1_dlg0[] = { /* 0x8244bb4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0100,  0x00000007,  0x00000000, NULL },
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

static const struct ScriptCommand s_gs193_g5_s0_station_sref_script[] = { /* 0x8244c94 */
    DEBUGINFO,
    SELECT_MAP(193),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(102),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION(  3,  0),
    RET,
};

static const struct ScriptRef s_gs193_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs193_g5_s0_station_sref_script }; /* 0x8244d24 */

static const struct ScriptCommand s_gs193_g5_s0_lives0_dlg0[] = { /* 0x8244d30 */
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

static const struct ScriptCommand s_gs193_g5_s0_lives1_dlg0[] = { /* 0x8244f58 */
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

static const struct GroundLivesData s_gs193_g0_s0_lives[] = { /* 0x8245028 */
    /*  0 */ { 144,   0,   0,   0, {  10,  21, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs193_g0_s1_lives[] = { /* 0x8245040 */
    /*  0 */ {   0,   2,   0,   0, {   7,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   3,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g0_s2_lives[] = { /* 0x8245070 */
    /*  0 */ {   0,   0,   0,   0, {  34,  21, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  34,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g0_s3_lives[] = { /* 0x82450a0 */
    /*  0 */ {   0,   2,   0,   0, {   7,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   3,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g0_s4_lives[] = { /* 0x82450d0 */
    /*  0 */ {   0,   2,   0,   0, {   7,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   3,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs193_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g0_s5_lives[] = { /* 0x8245100 */
    /*  0 */ { 144,   0,   0,   0, {  10,  21, 0, CPOS_HALFTILE }, {} },
    /*  1 */ { 145,   0,   0,   0, {   8,  31, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs193_g1_s0_lives[] = { /* 0x8245130 */
    /*  0 */ {   0,   2,   0,   0, {   3,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {   8,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g2_s0_lives[] = { /* 0x8245160 */
    /*  0 */ {   0,   2,   0,   0, {  22,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  27,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g3_s0_lives[] = { /* 0x8245190 */
    /*  0 */ {  34,   0,   0,   0, {  27,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs193_g3_s0_lives0_dlg1,
        [2] = s_gs193_g3_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs193_g3_s1_lives[] = { /* 0x82451a8 */
    /*  0 */ {   0,   2,   0,   0, {  23,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g3_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  27,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g3_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g4_s0_lives[] = { /* 0x82451d8 */
    /*  0 */ {   0,   2,   0,   0, {  26,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  33,  20, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g4_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs193_g5_s0_lives[] = { /* 0x8245208 */
    /*  0 */ {   0,   2,   0,   0, {  22,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  27,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs193_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs193_g0_s0_objs[] = { /* 0x8245238 */
    /*  0 */ {   4,   0,   4,   2, {  10,  22, 0, 0 }, {
        [2] = s_gs193_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs193_g0_s5_objs[] = { /* 0x8245250 */
    /*  0 */ {   4,   0,   4,   2, {  10,  22, 0, 0 }, {
        [2] = s_gs193_g0_s5_obj0_dlg2,
    } },
    /*  1 */ {   4,   0,   4,   3, {   8,  31, 0, CPOS_HALFTILE }, {
        [2] = s_gs193_g0_s5_obj1_dlg2,
    } },
};

static const struct GroundEffectData s_gs193_g1_s0_effs[] = { /* 0x8245280 */
    /*  0 */ {   0,   0,   1,   1, {  27,  25, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs193_g2_s0_effs[] = { /* 0x824528c */
    /*  0 */ {   0,   0,   1,   1, {  24,  24, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs193_g4_s0_effs[] = { /* 0x8245298 */
    /*  0 */ {   0,   0,   1,   1, {  24,  24, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs193_g5_s0_effs[] = { /* 0x82452a4 */
    /*  0 */ {   0,   0,   1,   1, {  24,  24, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs193_g3_s0_evts[] = { /* 0x82452b0 */
    /*  0 */ {  12,   3,   0,   0, {  28,  16, 0, 0 }, &s_gs193_g3_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82452bc */
    &s_gs193_g0_s0_station_sref,
    &s_gs193_g1_s0_station_sref,
    &s_gs193_g2_s0_station_sref,
    &s_gs193_g3_s0_station_sref,
    &s_gs193_g3_s1_station_sref,
    &s_gs193_g4_s0_station_sref,
    &s_gs193_g5_s0_station_sref,
};

static const struct GroundScriptSector s_gs193_g0_sectors[] = { /* 0x82452d8 */
    { LPARRAY(s_gs193_g0_s0_lives), LPARRAY(s_gs193_g0_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[0], },
    { LPARRAY(s_gs193_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs193_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs193_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs193_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs193_g0_s5_lives), LPARRAY(s_gs193_g0_s5_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs193_g1_sectors[] = { /* 0x82453c8 */
    { LPARRAY(s_gs193_g1_s0_lives), 0,NULL, LPARRAY(s_gs193_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs193_g2_sectors[] = { /* 0x82453f0 */
    { LPARRAY(s_gs193_g2_s0_lives), 0,NULL, LPARRAY(s_gs193_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs193_g3_sectors[] = { /* 0x8245418 */
    { LPARRAY(s_gs193_g3_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs193_g3_s0_evts), 1,&sStationScripts[3], },
    { LPARRAY(s_gs193_g3_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs193_g4_sectors[] = { /* 0x8245468 */
    { LPARRAY(s_gs193_g4_s0_lives), 0,NULL, LPARRAY(s_gs193_g4_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs193_g5_sectors[] = { /* 0x8245490 */
    { LPARRAY(s_gs193_g5_s0_lives), 0,NULL, LPARRAY(s_gs193_g5_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptGroup s_gs193_groups[] = { /* 0x82454b8 */
    { LPARRAY(s_gs193_g0_sectors) },
    { LPARRAY(s_gs193_g1_sectors) },
    { LPARRAY(s_gs193_g2_sectors) },
    { LPARRAY(s_gs193_g3_sectors) },
    { LPARRAY(s_gs193_g4_sectors) },
    { LPARRAY(s_gs193_g5_sectors) },
};

static const struct GroundLink s_gs193_links[] = { /* 0x82454e8 */
    /* link   0 */ { { /*x*/  25, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  29, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  34, /*y*/  17, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs193 = { LPARRAY(s_gs193_groups), s_gs193_links }; /* 0x8245500 */
