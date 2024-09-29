











static const struct ScriptCommand s_gs12_g0_s0_station_sref_script[] = { /* 0x81e1954 */
    DEBUGINFO,
    SELECT_MAP(12),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 3, /* to label */ 0),
    COND(JUDGE_EQ, 18, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    EXECUTE_STATION(-1, 16, 1),
    RET,
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 4),
    COND(JUDGE_LE, 2, /* to label */ 5),
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    EXECUTE_STATION(-1, 45, 0),
    RET,
  LABEL(5), /* = 0x05 */
    EXECUTE_STATION(-1, 46, 1),
    RET,
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(START_MODE),
    COND_EQUAL(1, /* to label */ 6),
    COND_EQUAL(2, /* to label */ 7),
    COND_EQUAL(12, /* to label */ 8),
    COND_EQUAL(11, /* to label */ 8),
    COND_EQUAL(10, /* to label */ 9),
    COND_EQUAL(9, /* to label */ 10),
    JUMP_LABEL(6),
  LABEL(7), /* = 0x07 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(9, /* to label */ 11),
    COND_EQUAL(10, /* to label */ 11),
    COND_EQUAL(11, /* to label */ 11),
    COND_EQUAL(12, /* to label */ 6),
    COND_EQUAL(13, /* to label */ 6),
    COND_EQUAL(14, /* to label */ 6),
    JUMP_LABEL(11),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(12),
  LABEL(8), /* = 0x08 */
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(-1, 7, 0),
    RET,
  LABEL(10), /* = 0x0a */
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(-1, 8, 0),
    RET,
  LABEL(9), /* = 0x09 */
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER2_FUNC),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(-1, 7, 0),
    RET,
  LABEL(11), /* = 0x0b */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(12),
  LABEL(12), /* = 0x0c */
    BGM_SWITCH(1),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs12_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs12_g0_s0_station_sref_script }; /* 0x81e1da4 */

static const struct ScriptCommand s_gs12_g0_s0_evt0_sref_script[] = { /* 0x81e1db0 */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000009,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs12_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs12_g0_s0_evt0_sref_script }; /* 0x81e1de0 */

static const struct ScriptCommand s_gs12_g0_s0_evt1_sref_script[] = { /* 0x81e1dec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3a, 0x00,  0x0000,  0x00000000, -0x00000001, _("Would you like to save your adventure?") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_START_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_END_FUNC),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptRef s_gs12_g0_s0_evt1_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs12_g0_s0_evt1_sref_script }; /* 0x81e1ee4 */

static const struct ScriptCommand s_gs12_g0_s0_obj0_dlg0[] = { /* 0x81e1ef0 */
    DEBUGINFO,
    JUMPIF(JUDGE_GE, BASE_LEVEL, 2, /* to label */ 0),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptCommand s_gs12_g0_s0_obj0_dlg2[] = { /* 0x81e1f40 */
    DEBUGINFO,
    CJUMP_DIR_TO_LINK(0),
    COND_EQUAL(4, /* to label */ 0),
    COND_EQUAL(5, /* to label */ 1),
    COND_EQUAL(6, /* to label */ 2),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    CJUMP_DIRECTION,
    COND_EQUAL(4, /* to label */ 3),
    COND_EQUAL(5, /* to label */ 3),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    CJUMP_DIRECTION,
    COND_EQUAL(4, /* to label */ 3),
    COND_EQUAL(5, /* to label */ 3),
    COND_EQUAL(6, /* to label */ 3),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    CJUMP_DIRECTION,
    COND_EQUAL(5, /* to label */ 3),
    COND_EQUAL(6, /* to label */ 3),
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    EXECUTE_STATION(-1, 1, 0),
    HALT,
};

static const struct ScriptCommand s_gs12_g0_s1_lives0_dlg0[] = { /* 0x81e20d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g0_s1_lives1_dlg0[] = { /* 0x81e2110 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g0_s2_lives0_dlg0[] = { /* 0x81e2150 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g0_s2_lives1_dlg0[] = { /* 0x81e2190 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g1_s0_station_sref_script[] = { /* 0x81e21d0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(WORLD_MAP_POINT),
    RET,
};

static const struct ScriptRef s_gs12_g1_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs12_g1_s0_station_sref_script }; /* 0x81e2220 */

static const struct ScriptCommand s_gs12_g1_s0_lives0_dlg0[] = { /* 0x81e222c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g1_s0_lives1_dlg0[] = { /* 0x81e226c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5f, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g1_s1_station_sref_script[] = { /* 0x81e22ac */
    DEBUGINFO,
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    SELECT_EVENTS(0, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g1_s1_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g1_s1_station_sref_script }; /* 0x81e230c */

static const struct ScriptCommand s_gs12_g1_s1_lives0_dlg0[] = { /* 0x81e2318 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g1_s1_lives1_dlg0[] = { /* 0x81e2368 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5e, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs12_g2_s0_station_sref_script[] = { /* 0x81e23b8 */
    DEBUGINFO,
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_STOP,
    { 0x27, 0x01,  0x000d,  0x0000003c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x000d,  0x0000003c,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g2_s0_station_sref_script }; /* 0x81e2438 */

static const struct ScriptCommand s_gs12_g2_s0_lives0_dlg0[] = { /* 0x81e2444 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g3_s0_station_sref_script[] = { /* 0x81e24a4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 6, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    SELECT_MAP(12),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g3_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g3_s0_station_sref_script }; /* 0x81e25fc */

static const struct ScriptCommand s_gs12_g3_s0_lives0_dlg0[] = { /* 0x81e2608 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g4_s0_station_sref_script[] = { /* 0x81e2688 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 6, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g4_s0_station_sref_script }; /* 0x81e2758 */

static const struct ScriptCommand s_gs12_g4_s0_lives0_dlg0[] = { /* 0x81e2764 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g5_s0_station_sref_script[] = { /* 0x81e27e4 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    SELECT_MAP(12),
    SELECT_ENTITIES(0, 2),
    SELECT_EVENTS(0, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g5_s0_station_sref_script }; /* 0x81e2874 */

static const struct ScriptCommand s_gs12_g6_s0_station_sref_script[] = { /* 0x81e2880 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g6_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g6_s0_station_sref_script }; /* 0x81e29c0 */

static const struct ScriptCommand s_gs12_g6_s0_lives0_dlg0[] = { /* 0x81e29cc */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g7_s0_station_sref_script[] = { /* 0x81e2a4c */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g7_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g7_s0_station_sref_script }; /* 0x81e2b0c */

static const struct ScriptCommand s_gs12_g7_s0_lives0_dlg0[] = { /* 0x81e2b18 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g8_s0_station_sref_script[] = { /* 0x81e2b98 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 6, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g8_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g8_s0_station_sref_script }; /* 0x81e2c68 */

static const struct ScriptCommand s_gs12_g8_s0_lives0_dlg0[] = { /* 0x81e2c74 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g9_s0_station_sref_script[] = { /* 0x81e2d14 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    CANCEL_LIVES(9, 0),
    SELECT_LIVES(9, 1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    RET,
};

static const struct ScriptRef s_gs12_g9_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g9_s0_station_sref_script }; /* 0x81e2e54 */

static const struct ScriptCommand s_gs12_g9_s0_eff0_script[] = { /* 0x81e2e60 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000028, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g9_s0_lives0_dlg0[] = { /* 0x81e2ec0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Wh-where...?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's $n0's house.")),
    VARIANT(/* == */  1, _(" It also happens to be our\nrescue team's base.")),
    VARIANT(/* == */  3, _(" It's $n0's house.")),
    VARIANT(/* == */  3, _(" It's also our rescue team's\nbase.")),
    VARIANT_DEFAULT(_(" It's $n0's house.")),
    VARIANT_DEFAULT(_(" It's also our rescue team's\nbase.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Oh!\n...Did you maybe rescue me?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Th-thank you...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hahaha, don't worry about it.\nNo need for thanks.")),
    VARIANT(/* == */  1, _(" But forget that...#W\nWhat happened to you?")),
    VARIANT_DEFAULT(_(" Hahaha, it's OK.\nThere's no need for thanks.")),
    VARIANT_DEFAULT(_(" Rather than that...#W\nWhat happened?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Y-yes...") },
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002, -0x00000001,  0x00000000, NULL },
    { 0x2d, 0x03,  0x0002,  0x00000073,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm named Spinda.") },
    { 0x2d, 0x09,  0x0002,  0x00000073,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I like to travel.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I've been traveling all over\nseeing the sights and other Pokémon.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It was on my travels that\nI heard rumors of a mirage Pokémon...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" A mirage Pokémon?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes! That!#W\nIsn't it exciting?") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ever since then, I've been\ntraveling all over in hopes of seeing\nthe mirage Pokémon...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But I've had no luck...#W\nFinally, I became dizzy from fatigue...#W\nAnd I must have passed out.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I...#W\nI'm giving up on my quest...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm simply worn out...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hold up a second!#W\nAre you sure you want to give up that\neasily?")),
    VARIANT_DEFAULT(_(" Wait a second!#W\nAre you sure you won't regret giving up\nthat easily?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But I...#W\nI've reached my physical limit...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If I push myself any\nfurther, I will collapse again.\nIt's not good for my health...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...Please, I want you to\nhave this.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    BGM_STOP,
    FANFARE_PLAY(212),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n1 received something\n#+from $n2.") },
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    SELECT_EFFECTS(9, 1),
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What is this?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It's a...#W\n#CIClear Wing#R...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Clear Wing?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes.#W\nI found it on my travels.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It's a wing of some sort.\nIt's transparent, but...#W\nIf you hold it up like this...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CANCEL_EFFECTS(9, 1),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" See? Depending on the light,\nit takes on many different colors.") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CANCEL_EFFECTS(9, 2),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" At first I thought it\nwas just pretty to look at...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But after checking around,\nit appears to be related to the mirage\nPokémon somehow.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But I couldn't learn anything\nbeyond that.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...Sniff...\nIt's very disappointing, but I'm giving up...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, are you OK?#W\nYou still look wobbly on your feet.")),
    VARIANT_DEFAULT(_(" Wait, are you OK?#W\nYou're still unsteady on your feet.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh, no.\nWhen I walk, I always totter.#W\nBye.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" #C4Clear Wing#R, huh...#W\nI don't have a clue what this is all about...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But you are interested in\nthe mirage Pokémon, right?")),
    VARIANT(/* == */  1, _(" For something like this,\nXatu'd be the one to ask.")),
    VARIANT(/* == */  1, _(" Xatu should be at the peak\nof the #CDGreat Canyon#R.")),
    VARIANT(/* == */  1, _(" We should go out there.\nTo the #CDGreat Canyon#R!")),
    VARIANT_DEFAULT(_(" But the mirage Pokémon\ndoes interest you, right?")),
    VARIANT_DEFAULT(_(" I think Xatu is the one to\nask for something like this.")),
    VARIANT_DEFAULT(_(" Xatu should be at the peak\nof the #CDGreat Canyon#R.")),
    VARIANT_DEFAULT(_(" We should go!\nTo the #CDGreat Canyon#R!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


















static const struct ScriptCommand s_gs12_g9_s0_lives1_dlg0[] = { /* 0x81e4480 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d5,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200,  0x00000000, -0x00000018, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d5,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000028, NULL },
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g9_s0_lives2_dlg0[] = { /* 0x81e4720 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    WAIT(20),
    FANFARE_PLAY2(812),
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(510),
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000010, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    SELECT_EFFECTS(9, 2),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000020, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    WAIT(30),
    { 0x6a, 0x00,  0x0100, -0x00000020,  0x00000010, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6a, 0x00,  0x0100,  0x00000040,  0x00000010, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6a, 0x00,  0x0100, -0x00000020,  0x00000018, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000010,  0x00000010, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    WAIT(60),
    { 0x6a, 0x00,  0x0100, -0x00000010,  0x00000010, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000010, NULL },
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs12_g9_s1_eff0_script[] = { /* 0x81e4e10 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000000ab,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g9_s1_lives0_dlg0[] = { /* 0x81e4e40 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x58, 0x01,  0x0000,  0x000000f0,  0x00000120, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptCommand s_gs12_g9_s2_eff0_script[] = { /* 0x81e4ed0 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000000ab,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g10_s0_station_sref_script[] = { /* 0x81e4f00 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+No...\n#+Morning, but only by time...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+A time so early in the morning\n#+that everyone is still in bed...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g10_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g10_s0_station_sref_script }; /* 0x81e5070 */


static const struct ScriptCommand s_gs12_g10_s0_lives0_dlg0[] = { /* 0x81e507c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("........................") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(508),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gggwwooooooooooooaahhhhh!") },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(20),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0000,  0x0000000c,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Wha...#W What is it?!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("What...#W\nWhat's happening outside?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200,  0x00000000,  0x00000020, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200,  0x00000000,  0x00000040, NULL },
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs12_g11_s0_station_sref_script[] = { /* 0x81e52bc */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Several hours later...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0000, -0x00000002,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#W\nHey...")),
    VARIANT(/* == */  1, _(" Hey, $n0.")),
    VARIANT(/* == */  1, _(" ...$n0, wake up!\nGet up already!")),
    VARIANT_DEFAULT(_(" ............#W\nHey...")),
    VARIANT_DEFAULT(_(" Hey, $n0.")),
    VARIANT_DEFAULT(_(" $n0, wake up!\nCome on, wake up!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs12_g11_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g11_s0_station_sref_script }; /* 0x81e551c */


static const struct ScriptCommand s_gs12_g11_s0_lives0_dlg0[] = { /* 0x81e5528 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You're finally awake,\n$n0?")),
    VARIANT(/* == */  1, _(" Sounds like there's a big\nruckus going on at the square.")),
    VARIANT(/* == */  1, _(" Let's go check it out!")),
    VARIANT_DEFAULT(_(" $n0, are you\nawake?")),
    VARIANT_DEFAULT(_(" There's some sort of a\ncommotion down at the square.")),
    VARIANT_DEFAULT(_(" Let's take a look!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000050, NULL },
    HALT,
};


static const struct ScriptCommand s_gs12_g11_s0_lives1_dlg0[] = { /* 0x81e5718 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000050, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g12_s0_station_sref_script[] = { /* 0x81e5778 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs12_g12_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g12_s0_station_sref_script }; /* 0x81e5878 */

static const struct ScriptCommand s_gs12_g12_s0_lives0_dlg0[] = { /* 0x81e5884 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000020,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0!\nGreat news!")),
    VARIANT(/* == */  1, _(" $n2 wants to\njoin us!")),
    VARIANT_DEFAULT(_(" Listen, $n0!\nI've got great news!")),
    VARIANT_DEFAULT(_(" $n2 wants to\njoin us!")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I saw $n2 outside\nlooking dazed, so I went and said hello.")),
    VARIANT(/* == */  1, _(" It turns out that it was\nsuddenly blown here by gusting winds!")),
    VARIANT_DEFAULT(_(" I saw $n2 outside\nlooking stunned, so I introduced myself.")),
    VARIANT_DEFAULT(_(" It says it was blown here\nby a sudden gust of wind!")),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It doesn't seem to have any\nidea why it would even end up here.")),
    VARIANT_DEFAULT(_(" It doesn't seem to know\nwhy it would end up here.")),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...But since it's here, it\nfigures it must be for a good reason,\nso it wants to join us!")),
    VARIANT_DEFAULT(_(" ...But since it's here, it\ndecided that it must be for a good reason.\nAnd so it wants to join us!")),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" What do you think?\nShould we let $n2 join?")),
    VARIANT_DEFAULT(_(" What should we do?\nShould we let $n2 join?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK! That's settled!")),
    VARIANT_DEFAULT(_(" Great!\nThat's that!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?! Are you sure?\nThat Pokémon came to us...")),
    VARIANT_DEFAULT(_(" Huh?! You're sure of that?\nThat Pokémon volunteered to join...")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let me ask you again.#W\nBut this is the last time.")),
    VARIANT_DEFAULT(_(" Let me make sure.#W\nAnd I won't ask you again.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" What do you think?\nShould we let $n2 join?")),
    VARIANT_DEFAULT(_(" What should we do?\nShould we let $n2 join?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  5, _("No.")),
  LABEL(5), /* = 0x05 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 2),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right...\nIt's disappointing, but that's the way\nit goes.")),
    VARIANT_DEFAULT(_(" OK...\nIt's disappointing, but it can't be helped.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll go tell $n2 no.")),
    VARIANT_DEFAULT(_(" I'll let $n2 know\nhe hasn't been accepted.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x3b, 0x2c,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs12_g12_s0_lives1_dlg0[] = { /* 0x81e6294 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(1, /* to label */ 1),
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(1), /* = 0x01 */
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 2),
  LABEL(2), /* = 0x02 */
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000064, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g13_s0_station_sref_script[] = { /* 0x81e6474 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs12_g13_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g13_s0_station_sref_script }; /* 0x81e6574 */

static const struct ScriptCommand s_gs12_g13_s0_lives0_dlg0[] = { /* 0x81e6580 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0!\nGreat news!")),
    VARIANT(/* == */  1, _(" Team #C5$t#R's\nrescue rank went up!")),
    VARIANT_DEFAULT(_(" Listen, $n0!\nI've got great news!")),
    VARIANT_DEFAULT(_(" Team #C5$t#R's\nrescue rank went up!")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I saw Pelipper outside\nlooking dazed, so I went and said hello.")),
    VARIANT(/* == */  1, _(" It turns out, he was\nsuddenly blown here by gusting winds!")),
    VARIANT_DEFAULT(_(" I saw Pelipper outside\nlooking stunned, so I chatted with him.")),
    VARIANT_DEFAULT(_(" Pelipper says he was blown\nhere by a sudden gust of wind!")),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" He doesn't seem to have any\nidea why he would even end up here.")),
    VARIANT_DEFAULT(_(" He doesn't seem to know\nwhy he would end up here.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" See, Pelipper was supposed\nto be making a delivery.")),
    VARIANT(/* == */  1, _(" He was on his way to\na different rescue team with a crest\nused to signify a higher rescue rank.")),
    VARIANT_DEFAULT(_(" Pelipper was on his way to\nanother rescue team.")),
    VARIANT_DEFAULT(_(" He was supposed to take\nthem their new crest showing that\nthey'd gone up in rescue rank.")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But since he ended up here,\nhe figures it must be for a good reason.\nWe're getting the rescue rank crest!")),
    VARIANT(/* == */  1, _(" Isn't that awesome?!#W\nIt's kind of unfair, but...#W\nWell, so what?")),
    VARIANT_DEFAULT(_(" But since he ended up here,\nhe thinks it must be for a good reason.\nWe're getting that new rescue rank crest!")),
    VARIANT_DEFAULT(_(" It's awesome!#W\nI guess it's kind of unfair, but...#W\nWell, anyway!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I've never said no to a gift!")),
    VARIANT_DEFAULT(_(" If it's a gift, we have\nto accept!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Team #C5$t#R's\n#+rescue rank went up!") },
    FANFARE_PLAY(201),
    { 0xe1, 0x00,  0x00c9,  0x00000000,  0x00000000, NULL },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x2e,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 2),
    { 0xe3, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(2), /* = 0x02 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs12_g13_s0_lives1_dlg0[] = { /* 0x81e6dd0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g14_s0_station_sref_script[] = { /* 0x81e6ec0 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs12_g14_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g14_s0_station_sref_script }; /* 0x81e6fc0 */

static const struct ScriptCommand s_gs12_g14_s0_lives0_dlg0[] = { /* 0x81e6fcc */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0!\nGreat news!")),
    VARIANT(/* == */  1, _(" The Rescue Organization\nsent us a cash reward!")),
    VARIANT(/* == */  1, _(" I don't have a clue why\nthey'd send us this, but...")),
    VARIANT(/* == */  1, _(" Who am I to complain?")),
    VARIANT_DEFAULT(_(" Listen, $n0!\nI've got great news!")),
    VARIANT_DEFAULT(_(" The Rescue Organization\nsent us some reward money!")),
    VARIANT_DEFAULT(_(" I don't have the foggiest\nnotion why they'd send it...")),
    VARIANT_DEFAULT(_(" But why worry about it?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I never turn down\nsomeone's generosity!")),
    VARIANT_DEFAULT(_(" If they're in a giving mood,\nwe shouldn't refuse!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x3c, 0x2b,  0x0000,  0x00000009,  0x00000064, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g14_s0_lives1_dlg0[] = { /* 0x81e7334 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g15_s0_station_sref_script[] = { /* 0x81e7424 - PART 1 0:22:25-0:22:53 - First day cutscene */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    WAIT(90),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION( 16,  0),
    RET,
};

static const struct ScriptRef s_gs12_g15_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g15_s0_station_sref_script }; /* 0x81e7554 */


static const struct ScriptCommand s_gs12_g15_s0_lives0_dlg0[] = { /* 0x81e7560 - PART 1 0:22:30-0:22:53 - Player */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...I'm still the same.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("The way I look...\nI'm still $m0.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("But why would I be transformed\ninto a Pokémon?") },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0x2e, 0x00,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nHmm... I don't understand this at all...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("........................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nI feel groggy and sleepy...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Not feeling well...#W\nI need more sleep...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g16_s0_station_sref_script[] = { /* 0x81e77c4 - PART 1 0:22:53 - First day, setup playable state */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs12_g16_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs12_g16_s0_station_sref_script }; /* 0x81e77f4 */

static const struct ScriptCommand s_gs12_g16_s0_evt0_sref_script[] = { /* 0x81e7800 - Likely door event/nearby trigger */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Now, I only want to sleep...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'll rest in bed...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g16_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs12_g16_s0_evt0_sref_script }; /* 0x81e78b8 */


static const struct ScriptCommand s_gs12_g16_s0_evt1_sref_script[] = { /* 0x81e78c4 - PART 1 0:22:53-0:23:04 - Bed, sleep trigger */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3a, 0x00,  0x0000,  0x00000000, -0x00000001, _("Would you like to save your adventure?") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_STOP,
    CALL_SCRIPT(SAVE_START_FUNC),
    SCENARIO_CALC(SCENARIO_MAIN,  3,  3),
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_WAIT_FUNC),
    EXECUTE_FUNCTION(EVENT_M01E02A_L001C),
    HALT,
};

static const struct ScriptRef s_gs12_g16_s0_evt1_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs12_g16_s0_evt1_sref_script }; /* 0x81e79a4 */

static const struct ScriptCommand s_gs12_g16_s1_station_sref_script[] = { /* 0x81e79b0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs12_g16_s1_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g16_s1_station_sref_script }; /* 0x81e7a80 */

static const struct ScriptCommand s_gs12_g16_s1_lives0_dlg0[] = { /* 0x81e7a8c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g17_s0_station_sref_script[] = { /* 0x81e7b0c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g17_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g17_s0_station_sref_script }; /* 0x81e7bdc */

static const struct ScriptCommand s_gs12_g17_s0_lives0_dlg0[] = { /* 0x81e7be8 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oof...#W\nI'm feeling refreshed!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I still look like a Pokémon, but...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh, that's right.#W That Pokémon...#W\nI think it was $n1?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("We made a promise to form a rescue\nteam together...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I wonder what $n1 is doing?#W\nI should go out.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g18_s0_station_sref_script[] = { /* 0x81e7e1c */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g18_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g18_s0_station_sref_script }; /* 0x81e7f2c */

static const struct ScriptCommand s_gs12_g18_s0_lives0_dlg0[] = { /* 0x81e7f38 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g19_s0_station_sref_script[] = { /* 0x81e7fb8 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g19_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g19_s0_station_sref_script }; /* 0x81e8088 */

static const struct ScriptCommand s_gs12_g19_s0_lives0_dlg0[] = { /* 0x81e8094 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I think I dreamt something...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("But I can't quite remember what that\ndream was about...") },
    { 0x2e, 0x15,  0x0000,  0x00000009,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh, well.\nToday's another day of rescues!") },
    { 0x2e, 0x15,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I wonder if I have any mail?\nBetter check the Mailbox.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g20_s0_station_sref_script[] = { /* 0x81e8268 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    SELECT_MAP(12),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g20_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g20_s0_station_sref_script }; /* 0x81e8388 */

static const struct ScriptCommand s_gs12_g20_s0_lives0_dlg0[] = { /* 0x81e8394 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x00000045,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Uhh... Hello?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    WAIT(60),
    FANFARE_PLAY2(468),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(468),
    { 0x92, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    WAIT(30),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hello? Uhh...\nYou are $n0...#W Aren't you?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(468),
    { 0x92, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(468),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(468),
    { 0x92, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    { 0x92, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Oh! You can't see us, of course!#W\nHow very rude of us!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    SELECT_ENTITIES(-1, 1),
    WAIT(20),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEIN(60, 1),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" We're pleased to meet you.\nWe are $n2.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Last night, during the\nearthquake...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Our child $n3 was\nattacked...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" He was whisked away to\nthe peak of a tall mountain.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We couldn't possibly climb\nsomewhere so high up...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That is why we must call\nupon you for your help, $n0.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" $n3 was abducted\nby a Pokémon named $n4.") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It's a vilely vicious ruffian!\nPlease do be careful.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please, we need your help!#W\nWe must go!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...That was so sudden, there was no time\nto even say no...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It's too bad. I'd better go.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs12_g20_s1_lives0_dlg0[] = { /* 0x81e8ac8 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x91, 0x0a,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(8),
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs12_g21_s0_station_sref_script[] = { /* 0x81e8c38 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g21_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g21_s0_station_sref_script }; /* 0x81e8d48 */

static const struct ScriptCommand s_gs12_g21_s0_lives0_dlg0[] = { /* 0x81e8d54 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g22_s0_station_sref_script[] = { /* 0x81e8de4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    SELECT_MAP(12),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g22_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g22_s0_station_sref_script }; /* 0x81e8f24 */

static const struct ScriptCommand s_gs12_g22_s0_lives0_dlg0[] = { /* 0x81e8f30 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g23_s0_station_sref_script[] = { /* 0x81e8fb0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    SELECT_MAP(12),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g23_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g23_s0_station_sref_script }; /* 0x81e90f0 */

static const struct ScriptCommand s_gs12_g23_s0_lives0_dlg0[] = { /* 0x81e90fc */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g24_s0_station_sref_script[] = { /* 0x81e917c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g24_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g24_s0_station_sref_script }; /* 0x81e92bc */

static const struct ScriptCommand s_gs12_g24_s0_lives0_dlg0[] = { /* 0x81e92c8 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g25_s0_station_sref_script[] = { /* 0x81e9348 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g25_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g25_s0_station_sref_script }; /* 0x81e9408 */

static const struct ScriptCommand s_gs12_g25_s0_lives0_dlg0[] = { /* 0x81e9414 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g26_s0_station_sref_script[] = { /* 0x81e9494 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g26_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g26_s0_station_sref_script }; /* 0x81e95d4 */

static const struct ScriptCommand s_gs12_g26_s0_lives0_dlg0[] = { /* 0x81e95e0 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g27_s0_station_sref_script[] = { /* 0x81e9660 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g27_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g27_s0_station_sref_script }; /* 0x81e9720 */

static const struct ScriptCommand s_gs12_g27_s0_lives0_dlg0[] = { /* 0x81e972c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g28_s0_station_sref_script[] = { /* 0x81e97ac */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g28_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g28_s0_station_sref_script }; /* 0x81e98ec */

static const struct ScriptCommand s_gs12_g28_s0_lives0_dlg0[] = { /* 0x81e98f8 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g29_s0_station_sref_script[] = { /* 0x81e9978 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g29_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g29_s0_station_sref_script }; /* 0x81e9a38 */

static const struct ScriptCommand s_gs12_g29_s0_lives0_dlg0[] = { /* 0x81e9a44 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g30_s0_station_sref_script[] = { /* 0x81e9ac4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g30_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g30_s0_station_sref_script }; /* 0x81e9c04 */

static const struct ScriptCommand s_gs12_g30_s0_lives0_dlg0[] = { /* 0x81e9c10 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g31_s0_station_sref_script[] = { /* 0x81e9c90 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g31_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g31_s0_station_sref_script }; /* 0x81e9d50 */

static const struct ScriptCommand s_gs12_g31_s0_lives0_dlg0[] = { /* 0x81e9d5c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g32_s0_station_sref_script[] = { /* 0x81e9ddc */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g32_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g32_s0_station_sref_script }; /* 0x81e9f1c */

static const struct ScriptCommand s_gs12_g32_s0_lives0_dlg0[] = { /* 0x81e9f28 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g33_s0_station_sref_script[] = { /* 0x81e9fa8 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g33_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g33_s0_station_sref_script }; /* 0x81ea088 */

static const struct ScriptCommand s_gs12_g33_s0_lives0_dlg0[] = { /* 0x81ea094 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000062,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_DOWN_FUNC),
    WAIT(45),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nWhat a strange dream...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It's the dream I always have, but it was\nclearer than it was before...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I think I finally learned who that\nPokémon was...") },
    FANFARE_PLAY2(464),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("That's it!#W\n$n2!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It was $n2!") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Yesterday, $n3 said...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs12_g34_s0_station_sref_script[] = { /* 0x81ea2d8 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_STOP,
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    BGM_SWITCH(1),
    RET,
};

static const struct ScriptRef s_gs12_g34_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g34_s0_station_sref_script }; /* 0x81ea3b8 */

static const struct ScriptCommand s_gs12_g34_s0_lives0_dlg0[] = { /* 0x81ea3c4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(30),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Maybe...#W\nMaybe, I...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Maybe I was the human who was\n$n2's partner...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Maybe I was the one that abandoned\n$n2 when she was cursed...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Maybe that's why I turned into\na Pokémon...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g35_s0_station_sref_script[] = { /* 0x81ea5a4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g35_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g35_s0_station_sref_script }; /* 0x81ea6e4 */

static const struct ScriptCommand s_gs12_g35_s0_lives0_dlg0[] = { /* 0x81ea6f0 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g36_s0_station_sref_script[] = { /* 0x81ea770 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g36_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g36_s0_station_sref_script }; /* 0x81ea850 */

static const struct ScriptCommand s_gs12_g36_s0_lives0_dlg0[] = { /* 0x81ea85c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(30),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nThere was an earthquake...#W\nWasn't there...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I think I had that dream again...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I think I spoke with Gardevoir...#W\nShe said something important...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(464),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("That's it!#W\nShe did say something!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs12_g37_s0_station_sref_script[] = { /* 0x81eaa5c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, -1),
    BGM_STOP,
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    BGM_SWITCH(1),
    RET,
};

static const struct ScriptRef s_gs12_g37_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g37_s0_station_sref_script }; /* 0x81eab3c */

static const struct ScriptCommand s_gs12_g37_s0_lives0_dlg0[] = { /* 0x81eab48 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(466),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("$n2 knows!#W\nShe knows why I became a Pokémon.") },
    { 0x2e, 0x02,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("She also said something about a role...#W\nWhat did she mean by that?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g38_s0_station_sref_script[] = { /* 0x81eaca0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g38_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g38_s0_station_sref_script }; /* 0x81eadd0 */

static const struct ScriptCommand s_gs12_g38_s0_lives0_dlg0[] = { /* 0x81eaddc */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(10),
    FANFARE_PLAY2(453),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    WAIT(30),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x2e, 0x02,  0x0000,  0x0000000c,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh, wow, another earthquake...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    FANFARE_FADEOUT2(60, 453),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0x2e, 0x15,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nI guess it settled down...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _(".......There've been a lot of earthquakes\nlately...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs12_g39_s0_station_sref_script[] = { /* 0x81eb014 */
    DEBUGINFO,
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g39_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g39_s0_station_sref_script }; /* 0x81eb0f4 */

static const struct ScriptCommand s_gs12_g39_s0_lives0_dlg0[] = { /* 0x81eb100 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(10),
    FANFARE_PLAY2(453),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    WAIT(30),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x2e, 0x02,  0x0000,  0x0000000c,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh? Another earthquake...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    FANFARE_FADEOUT2(60, 453),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x15,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("There've been so many quakes lately...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I wonder when they'll settle down...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0!\nThere's a commotion down at the square!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" A lot of Pokémon have\nalready gathered there.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Let's go to the square right\nnow!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x89, 0x50,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs12_g39_s1_lives0_dlg0[] = { /* 0x81eb468 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0200,  0x00000004,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g40_s0_station_sref_script[] = { /* 0x81eb528 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g40_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g40_s0_station_sref_script }; /* 0x81eb668 */

static const struct ScriptCommand s_gs12_g40_s0_lives0_dlg0[] = { /* 0x81eb674 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g41_s0_station_sref_script[] = { /* 0x81eb6f4 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g41_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g41_s0_station_sref_script }; /* 0x81eb824 */

static const struct ScriptCommand s_gs12_g41_s0_lives0_dlg0[] = { /* 0x81eb830 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g42_s0_station_sref_script[] = { /* 0x81eb8b0 */
    DEBUGINFO,
    SELECT_MAP(12),
    { 0x3b, 0x48,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    { 0x27, 0x01,  0x000d,  0x0000003c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    FANFARE_FADEOUT2(90, 484),
    { 0x28, 0x01,  0x000d,  0x0000003c,  0x00000000, NULL },
    { 0x3b, 0x48,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs12_g42_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs12_g42_s0_station_sref_script }; /* 0x81eb950 */

static const struct ScriptCommand s_gs12_g42_s0_lives0_dlg0[] = { /* 0x81eb95c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" How do you like Dream\nEater?#W\nHorrible, isn't it? Keke!") },
    { 0x2e, 0x02,  0x0001,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" But who would've thought\nyou were also human before...#W\nDidn't expect that.") },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" But who cares?\nSomeone like that's sure to be some\nlowlife. Keke!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'll expose you yet!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'll expose what's in your\nheart with Dream Eater! Kekeke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    FANFARE_PLAY2(464),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hm?!#W\nSomething's coming!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(484),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What? What is that light?#W\nIt's coming closer?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs12_g42_s0_lives1_dlg0[] = { /* 0x81ebd04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x06,  0x000a,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x06,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x06,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x62, 0x00,  0x0080,  0x00000000,  0x0000000a, NULL },
    WAIT(30),
    { 0x89, 0x40,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g42_s0_eff1_script[] = { /* 0x81ebe54 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000010a,  0x00000000, NULL },
    { 0x84, 0x00,  0x0066, -0x00000030,  0x00000040, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x84, 0x00,  0x004c, -0x00000048,  0x00000010, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs12_g43_s0_station_sref_script[] = { /* 0x81ebee4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g43_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g43_s0_station_sref_script }; /* 0x81ec024 */

static const struct ScriptCommand s_gs12_g43_s0_lives0_dlg0[] = { /* 0x81ec030 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g44_s0_station_sref_script[] = { /* 0x81ec0b0 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs12_g44_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g44_s0_station_sref_script }; /* 0x81ec170 */

static const struct ScriptCommand s_gs12_g44_s0_lives0_dlg0[] = { /* 0x81ec17c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g45_s0_station_sref_script[] = { /* 0x81ec1fc */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000037,  0x00000000, NULL },
    BGM_STOP,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(12),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Due to $n0 and\n#+$n1's heroic actions...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+the falling star was destroyed...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+and peace returned to\n#+the world of Pokémon.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+But that did not put an end\n#+to the natural calamities.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Natural disasters still occurred,\n#+but much less often.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Needless to say,\n#+$t's rescue activities") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+continued as if nothing had changed.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Several mornings later...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x39,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x3a,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(46, 0),
    RET,
};

static const struct ScriptRef s_gs12_g45_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g45_s0_station_sref_script }; /* 0x81ec590 */

static const struct ScriptCommand s_gs12_g45_s0_lives0_dlg0[] = { /* 0x81ec59c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nDid you just get up?")),
    VARIANT(/* == */  1, _(" I just went by the Pelipper\nPost Office.")),
    VARIANT(/* == */  1, _(" There were still rescue jobs\nposted on the Bulletin Board.")),
    VARIANT(/* == */  1, _(" Even though it's peaceful\nagain, lots of Pokémon still need helping.")),
    VARIANT(/* == */  1, _(" $n0!#W\nLet's keep on giving it our best like\nalways!")),
    VARIANT_DEFAULT(_(" Good morning, $n0!\nDid you just wake up?")),
    VARIANT_DEFAULT(_(" I went by the Pelipper Post\nOffice earlier.")),
    VARIANT_DEFAULT(_(" The Bulletin Board was still\ncovered with rescue jobs.")),
    VARIANT_DEFAULT(_(" Even though it's peaceful\nagain, many Pokémon still need our help.")),
    VARIANT_DEFAULT(_(" $n0!#W\nLet's keep on doing our best as always!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g45_s0_lives1_dlg0[] = { /* 0x81ec950 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x60,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g46_s0_station_sref_script[] = { /* 0x81ec9e0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs12_g46_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs12_g46_s0_station_sref_script }; /* 0x81eca10 */

static const struct ScriptCommand s_gs12_g46_s0_evt0_sref_script[] = { /* 0x81eca1c */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000009,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs12_g46_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs12_g46_s0_evt0_sref_script }; /* 0x81eca4c */

static const struct ScriptCommand s_gs12_g46_s0_evt1_sref_script[] = { /* 0x81eca58 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3a, 0x00,  0x0000,  0x00000000, -0x00000001, _("Would you like to save the game?") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_START_FUNC),
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_END_FUNC),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptRef s_gs12_g46_s0_evt1_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs12_g46_s0_evt1_sref_script }; /* 0x81ecb2c */

static const struct ScriptCommand s_gs12_g46_s1_station_sref_script[] = { /* 0x81ecb38 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(12),
    SELECT_ENTITIES(0, 2),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs12_g46_s1_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs12_g46_s1_station_sref_script }; /* 0x81ecbf8 */

static const struct ScriptCommand s_gs12_g46_s1_lives0_dlg0[] = { /* 0x81ecc04 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!")),
    VARIANT(/* == */  1, _(" Let's keep on giving it our\nbest for our rescue team!")),
    VARIANT_DEFAULT(_(" Good morning, $n0!")),
    VARIANT_DEFAULT(_(" Let's keep doing our best\nfor our rescue team!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs12_g46_s1_lives1_dlg0[] = { /* 0x81ecdd0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x60,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs12_g0_s1_lives[] = { /* 0x81ece60 */
    /*  0 */ {   0,   4,   0,   0, {  30,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g0_s2_lives[] = { /* 0x81ece90 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g1_s0_lives[] = { /* 0x81ecec0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g1_s1_lives[] = { /* 0x81ecef0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g1_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g1_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g2_s0_lives[] = { /* 0x81ecf20 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g2_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g3_s0_lives[] = { /* 0x81ecf38 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g3_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g4_s0_lives[] = { /* 0x81ecf50 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g4_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g6_s0_lives[] = { /* 0x81ecf68 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g6_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g7_s0_lives[] = { /* 0x81ecf80 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g7_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g8_s0_lives[] = { /* 0x81ecf98 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g8_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g9_s0_lives[] = { /* 0x81ecfb0 */
    /*  0 */ {   1,   4,   0,   0, {  28,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g9_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g9_s0_lives1_dlg0,
    } },
    /*  2 */ { 115,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g9_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g9_s1_lives[] = { /* 0x81ecff8 */
    /*  0 */ {   0,   4,   0,   0, {  28,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g9_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g10_s0_lives[] = { /* 0x81ed010 */
    /*  0 */ {   1,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g10_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g11_s0_lives[] = { /* 0x81ed028 */
    /*  0 */ {   1,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g11_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g11_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g12_s0_lives[] = { /* 0x81ed058 */
    /*  0 */ {   1,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g12_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  48, 0, 0 }, {
        [0] = s_gs12_g12_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g13_s0_lives[] = { /* 0x81ed088 */
    /*  0 */ {   1,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g13_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  48, 0, 0 }, {
        [0] = s_gs12_g13_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g14_s0_lives[] = { /* 0x81ed0b8 */
    /*  0 */ {   1,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g14_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  48, 0, 0 }, {
        [0] = s_gs12_g14_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g15_s0_lives[] = { /* 0x81ed0e8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g15_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g16_s1_lives[] = { /* 0x81ed100 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g16_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g17_s0_lives[] = { /* 0x81ed118 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g17_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g18_s0_lives[] = { /* 0x81ed130 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g18_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g19_s0_lives[] = { /* 0x81ed148 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g19_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g20_s0_lives[] = { /* 0x81ed160 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g20_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g20_s1_lives[] = { /* 0x81ed178 */
    /*  0 */ {  66,   0,   0,   0, {  30,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g20_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g21_s0_lives[] = { /* 0x81ed190 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g21_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g22_s0_lives[] = { /* 0x81ed1a8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g22_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g23_s0_lives[] = { /* 0x81ed1c0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g23_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g24_s0_lives[] = { /* 0x81ed1d8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g24_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g25_s0_lives[] = { /* 0x81ed1f0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g25_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g26_s0_lives[] = { /* 0x81ed208 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g26_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g27_s0_lives[] = { /* 0x81ed220 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g27_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g28_s0_lives[] = { /* 0x81ed238 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g28_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g29_s0_lives[] = { /* 0x81ed250 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g29_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g30_s0_lives[] = { /* 0x81ed268 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g30_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g31_s0_lives[] = { /* 0x81ed280 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g31_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g32_s0_lives[] = { /* 0x81ed298 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g32_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g33_s0_lives[] = { /* 0x81ed2b0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g33_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g34_s0_lives[] = { /* 0x81ed2c8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g34_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g35_s0_lives[] = { /* 0x81ed2e0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g35_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g36_s0_lives[] = { /* 0x81ed2f8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g36_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g37_s0_lives[] = { /* 0x81ed310 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g37_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g38_s0_lives[] = { /* 0x81ed328 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g38_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g39_s0_lives[] = { /* 0x81ed340 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g39_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g39_s1_lives[] = { /* 0x81ed358 */
    /*  0 */ {  34,   4,   0,   0, {  30,  48, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g39_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g40_s0_lives[] = { /* 0x81ed370 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g40_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g41_s0_lives[] = { /* 0x81ed388 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g41_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g42_s0_lives[] = { /* 0x81ed3a0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g42_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  30,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g42_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g43_s0_lives[] = { /* 0x81ed3d0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g43_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g44_s0_lives[] = { /* 0x81ed3e8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g44_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g45_s0_lives[] = { /* 0x81ed400 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g45_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  30,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g45_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs12_g46_s1_lives[] = { /* 0x81ed430 */
    /*  0 */ {   0,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g46_s1_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  30,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs12_g46_s1_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs12_g0_s0_objs[] = { /* 0x81ed460 */
    /*  0 */ {  17,   0,   8,   8, {  20,  29, 0, 0 }, {
        [0] = s_gs12_g0_s0_obj0_dlg0,
        [2] = s_gs12_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs12_g2_s0_effs[] = { /* 0x81ed478 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g3_s0_effs[] = { /* 0x81ed484 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g4_s0_effs[] = { /* 0x81ed490 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g6_s0_effs[] = { /* 0x81ed49c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g7_s0_effs[] = { /* 0x81ed4a8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g8_s0_effs[] = { /* 0x81ed4b4 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g9_s0_effs[] = { /* 0x81ed4c0 */
    /*  0 */ {   0,   0,   1,   1, {  30,  32, 0, CPOS_HALFTILE }, s_gs12_g9_s0_eff0_script },
};

static const struct GroundEffectData s_gs12_g9_s1_effs[] = { /* 0x81ed4cc */
    /*  0 */ {   5,   0,   1,   1, {  30,  30, 0, CPOS_HALFTILE }, s_gs12_g9_s1_eff0_script },
};

static const struct GroundEffectData s_gs12_g9_s2_effs[] = { /* 0x81ed4d8 */
    /*  0 */ {   5,   0,   1,   1, {  28,  27, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs12_g9_s2_eff0_script },
};

static const struct GroundEffectData s_gs12_g10_s0_effs[] = { /* 0x81ed4e4 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g11_s0_effs[] = { /* 0x81ed4f0 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g12_s0_effs[] = { /* 0x81ed4fc */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g13_s0_effs[] = { /* 0x81ed508 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g14_s0_effs[] = { /* 0x81ed514 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g15_s0_effs[] = { /* 0x81ed520 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g16_s1_effs[] = { /* 0x81ed52c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g17_s0_effs[] = { /* 0x81ed538 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g18_s0_effs[] = { /* 0x81ed544 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g19_s0_effs[] = { /* 0x81ed550 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g20_s0_effs[] = { /* 0x81ed55c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g21_s0_effs[] = { /* 0x81ed568 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g22_s0_effs[] = { /* 0x81ed574 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g23_s0_effs[] = { /* 0x81ed580 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g24_s0_effs[] = { /* 0x81ed58c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g25_s0_effs[] = { /* 0x81ed598 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g26_s0_effs[] = { /* 0x81ed5a4 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g27_s0_effs[] = { /* 0x81ed5b0 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g28_s0_effs[] = { /* 0x81ed5bc */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g29_s0_effs[] = { /* 0x81ed5c8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g30_s0_effs[] = { /* 0x81ed5d4 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g31_s0_effs[] = { /* 0x81ed5e0 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g32_s0_effs[] = { /* 0x81ed5ec */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g33_s0_effs[] = { /* 0x81ed5f8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g34_s0_effs[] = { /* 0x81ed604 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g35_s0_effs[] = { /* 0x81ed610 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g36_s0_effs[] = { /* 0x81ed61c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g37_s0_effs[] = { /* 0x81ed628 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g38_s0_effs[] = { /* 0x81ed634 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g39_s0_effs[] = { /* 0x81ed640 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g40_s0_effs[] = { /* 0x81ed64c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g41_s0_effs[] = { /* 0x81ed658 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g42_s0_effs[] = { /* 0x81ed664 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
    /*  1 */ {   4,   0,   1,   1, {  45,  17, 0, CPOS_HALFTILE }, s_gs12_g42_s0_eff1_script },
};

static const struct GroundEffectData s_gs12_g43_s0_effs[] = { /* 0x81ed67c */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g44_s0_effs[] = { /* 0x81ed688 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g45_s0_effs[] = { /* 0x81ed694 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs12_g46_s1_effs[] = { /* 0x81ed6a0 */
    /*  0 */ {   0,   0,   1,   1, {  30,  34, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs12_g0_s0_evts[] = { /* 0x81ed6ac */
    /*  0 */ {   6,   3,   0,   0, {  27,  48, 0, 0 }, &s_gs12_g0_s0_evt0_sref },
    /*  1 */ {   6,   3,   0,   0, {  27,  28, 0, 0 }, &s_gs12_g0_s0_evt1_sref },
};

static const struct GroundEventData s_gs12_g16_s0_evts[] = { /* 0x81ed6c4 */
    /*  0 */ {   6,   3,   0,   0, {  27,  48, 0, 0 }, &s_gs12_g16_s0_evt0_sref },
    /*  1 */ {   6,   3,   0,   0, {  27,  28, 0, 0 }, &s_gs12_g16_s0_evt1_sref },
};

static const struct GroundEventData s_gs12_g46_s0_evts[] = { /* 0x81ed6dc */
    /*  0 */ {   6,   3,   0,   0, {  27,  48, 0, 0 }, &s_gs12_g46_s0_evt0_sref },
    /*  1 */ {   6,   3,   0,   0, {  27,  28, 0, 0 }, &s_gs12_g46_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81ed6f4 */
    &s_gs12_g0_s0_station_sref,
    &s_gs12_g1_s0_station_sref,
    &s_gs12_g1_s1_station_sref,
    &s_gs12_g2_s0_station_sref,
    &s_gs12_g3_s0_station_sref,
    &s_gs12_g4_s0_station_sref,
    &s_gs12_g5_s0_station_sref,
    &s_gs12_g6_s0_station_sref,
    &s_gs12_g7_s0_station_sref,
    &s_gs12_g8_s0_station_sref,
    &s_gs12_g9_s0_station_sref,
    &s_gs12_g10_s0_station_sref,
    &s_gs12_g11_s0_station_sref,
    &s_gs12_g12_s0_station_sref,
    &s_gs12_g13_s0_station_sref,
    &s_gs12_g14_s0_station_sref,
    &s_gs12_g15_s0_station_sref,
    &s_gs12_g16_s0_station_sref,
    &s_gs12_g16_s1_station_sref,
    &s_gs12_g17_s0_station_sref,
    &s_gs12_g18_s0_station_sref,
    &s_gs12_g19_s0_station_sref,
    &s_gs12_g20_s0_station_sref,
    &s_gs12_g21_s0_station_sref,
    &s_gs12_g22_s0_station_sref,
    &s_gs12_g23_s0_station_sref,
    &s_gs12_g24_s0_station_sref,
    &s_gs12_g25_s0_station_sref,
    &s_gs12_g26_s0_station_sref,
    &s_gs12_g27_s0_station_sref,
    &s_gs12_g28_s0_station_sref,
    &s_gs12_g29_s0_station_sref,
    &s_gs12_g30_s0_station_sref,
    &s_gs12_g31_s0_station_sref,
    &s_gs12_g32_s0_station_sref,
    &s_gs12_g33_s0_station_sref,
    &s_gs12_g34_s0_station_sref,
    &s_gs12_g35_s0_station_sref,
    &s_gs12_g36_s0_station_sref,
    &s_gs12_g37_s0_station_sref,
    &s_gs12_g38_s0_station_sref,
    &s_gs12_g39_s0_station_sref,
    &s_gs12_g40_s0_station_sref,
    &s_gs12_g41_s0_station_sref,
    &s_gs12_g42_s0_station_sref,
    &s_gs12_g43_s0_station_sref,
    &s_gs12_g44_s0_station_sref,
    &s_gs12_g45_s0_station_sref,
    &s_gs12_g46_s0_station_sref,
    &s_gs12_g46_s1_station_sref,
};

static const struct GroundScriptSector s_gs12_g0_sectors[] = { /* 0x81ed7bc */
    { 0,NULL, LPARRAY(s_gs12_g0_s0_objs), 0,NULL, LPARRAY(s_gs12_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs12_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs12_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs12_g1_sectors[] = { /* 0x81ed834 */
    { LPARRAY(s_gs12_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs12_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs12_g2_sectors[] = { /* 0x81ed884 */
    { LPARRAY(s_gs12_g2_s0_lives), 0,NULL, LPARRAY(s_gs12_g2_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs12_g3_sectors[] = { /* 0x81ed8ac */
    { LPARRAY(s_gs12_g3_s0_lives), 0,NULL, LPARRAY(s_gs12_g3_s0_effs), 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs12_g4_sectors[] = { /* 0x81ed8d4 */
    { LPARRAY(s_gs12_g4_s0_lives), 0,NULL, LPARRAY(s_gs12_g4_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs12_g5_sectors[] = { /* 0x81ed8fc */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs12_g6_sectors[] = { /* 0x81ed924 */
    { LPARRAY(s_gs12_g6_s0_lives), 0,NULL, LPARRAY(s_gs12_g6_s0_effs), 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptSector s_gs12_g7_sectors[] = { /* 0x81ed94c */
    { LPARRAY(s_gs12_g7_s0_lives), 0,NULL, LPARRAY(s_gs12_g7_s0_effs), 0,NULL, 1,&sStationScripts[8], },
};

static const struct GroundScriptSector s_gs12_g8_sectors[] = { /* 0x81ed974 */
    { LPARRAY(s_gs12_g8_s0_lives), 0,NULL, LPARRAY(s_gs12_g8_s0_effs), 0,NULL, 1,&sStationScripts[9], },
};

static const struct GroundScriptSector s_gs12_g9_sectors[] = { /* 0x81ed99c */
    { LPARRAY(s_gs12_g9_s0_lives), 0,NULL, LPARRAY(s_gs12_g9_s0_effs), 0,NULL, 1,&sStationScripts[10], },
    { LPARRAY(s_gs12_g9_s1_lives), 0,NULL, LPARRAY(s_gs12_g9_s1_effs), 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, LPARRAY(s_gs12_g9_s2_effs), 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs12_g10_sectors[] = { /* 0x81eda14 */
    { LPARRAY(s_gs12_g10_s0_lives), 0,NULL, LPARRAY(s_gs12_g10_s0_effs), 0,NULL, 1,&sStationScripts[11], },
};

static const struct GroundScriptSector s_gs12_g11_sectors[] = { /* 0x81eda3c */
    { LPARRAY(s_gs12_g11_s0_lives), 0,NULL, LPARRAY(s_gs12_g11_s0_effs), 0,NULL, 1,&sStationScripts[12], },
};

static const struct GroundScriptSector s_gs12_g12_sectors[] = { /* 0x81eda64 */
    { LPARRAY(s_gs12_g12_s0_lives), 0,NULL, LPARRAY(s_gs12_g12_s0_effs), 0,NULL, 1,&sStationScripts[13], },
};

static const struct GroundScriptSector s_gs12_g13_sectors[] = { /* 0x81eda8c */
    { LPARRAY(s_gs12_g13_s0_lives), 0,NULL, LPARRAY(s_gs12_g13_s0_effs), 0,NULL, 1,&sStationScripts[14], },
};

static const struct GroundScriptSector s_gs12_g14_sectors[] = { /* 0x81edab4 */
    { LPARRAY(s_gs12_g14_s0_lives), 0,NULL, LPARRAY(s_gs12_g14_s0_effs), 0,NULL, 1,&sStationScripts[15], },
};

static const struct GroundScriptSector s_gs12_g15_sectors[] = { /* 0x81edadc */
    { LPARRAY(s_gs12_g15_s0_lives), 0,NULL, LPARRAY(s_gs12_g15_s0_effs), 0,NULL, 1,&sStationScripts[16], },
};

static const struct GroundScriptSector s_gs12_g16_sectors[] = { /* 0x81edb04 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs12_g16_s0_evts), 1,&sStationScripts[17], },
    { LPARRAY(s_gs12_g16_s1_lives), 0,NULL, LPARRAY(s_gs12_g16_s1_effs), 0,NULL, 1,&sStationScripts[18], },
};

static const struct GroundScriptSector s_gs12_g17_sectors[] = { /* 0x81edb54 */
    { LPARRAY(s_gs12_g17_s0_lives), 0,NULL, LPARRAY(s_gs12_g17_s0_effs), 0,NULL, 1,&sStationScripts[19], },
};

static const struct GroundScriptSector s_gs12_g18_sectors[] = { /* 0x81edb7c */
    { LPARRAY(s_gs12_g18_s0_lives), 0,NULL, LPARRAY(s_gs12_g18_s0_effs), 0,NULL, 1,&sStationScripts[20], },
};

static const struct GroundScriptSector s_gs12_g19_sectors[] = { /* 0x81edba4 */
    { LPARRAY(s_gs12_g19_s0_lives), 0,NULL, LPARRAY(s_gs12_g19_s0_effs), 0,NULL, 1,&sStationScripts[21], },
};

static const struct GroundScriptSector s_gs12_g20_sectors[] = { /* 0x81edbcc */
    { LPARRAY(s_gs12_g20_s0_lives), 0,NULL, LPARRAY(s_gs12_g20_s0_effs), 0,NULL, 1,&sStationScripts[22], },
    { LPARRAY(s_gs12_g20_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs12_g21_sectors[] = { /* 0x81edc1c */
    { LPARRAY(s_gs12_g21_s0_lives), 0,NULL, LPARRAY(s_gs12_g21_s0_effs), 0,NULL, 1,&sStationScripts[23], },
};

static const struct GroundScriptSector s_gs12_g22_sectors[] = { /* 0x81edc44 */
    { LPARRAY(s_gs12_g22_s0_lives), 0,NULL, LPARRAY(s_gs12_g22_s0_effs), 0,NULL, 1,&sStationScripts[24], },
};

static const struct GroundScriptSector s_gs12_g23_sectors[] = { /* 0x81edc6c */
    { LPARRAY(s_gs12_g23_s0_lives), 0,NULL, LPARRAY(s_gs12_g23_s0_effs), 0,NULL, 1,&sStationScripts[25], },
};

static const struct GroundScriptSector s_gs12_g24_sectors[] = { /* 0x81edc94 */
    { LPARRAY(s_gs12_g24_s0_lives), 0,NULL, LPARRAY(s_gs12_g24_s0_effs), 0,NULL, 1,&sStationScripts[26], },
};

static const struct GroundScriptSector s_gs12_g25_sectors[] = { /* 0x81edcbc */
    { LPARRAY(s_gs12_g25_s0_lives), 0,NULL, LPARRAY(s_gs12_g25_s0_effs), 0,NULL, 1,&sStationScripts[27], },
};

static const struct GroundScriptSector s_gs12_g26_sectors[] = { /* 0x81edce4 */
    { LPARRAY(s_gs12_g26_s0_lives), 0,NULL, LPARRAY(s_gs12_g26_s0_effs), 0,NULL, 1,&sStationScripts[28], },
};

static const struct GroundScriptSector s_gs12_g27_sectors[] = { /* 0x81edd0c */
    { LPARRAY(s_gs12_g27_s0_lives), 0,NULL, LPARRAY(s_gs12_g27_s0_effs), 0,NULL, 1,&sStationScripts[29], },
};

static const struct GroundScriptSector s_gs12_g28_sectors[] = { /* 0x81edd34 */
    { LPARRAY(s_gs12_g28_s0_lives), 0,NULL, LPARRAY(s_gs12_g28_s0_effs), 0,NULL, 1,&sStationScripts[30], },
};

static const struct GroundScriptSector s_gs12_g29_sectors[] = { /* 0x81edd5c */
    { LPARRAY(s_gs12_g29_s0_lives), 0,NULL, LPARRAY(s_gs12_g29_s0_effs), 0,NULL, 1,&sStationScripts[31], },
};

static const struct GroundScriptSector s_gs12_g30_sectors[] = { /* 0x81edd84 */
    { LPARRAY(s_gs12_g30_s0_lives), 0,NULL, LPARRAY(s_gs12_g30_s0_effs), 0,NULL, 1,&sStationScripts[32], },
};

static const struct GroundScriptSector s_gs12_g31_sectors[] = { /* 0x81eddac */
    { LPARRAY(s_gs12_g31_s0_lives), 0,NULL, LPARRAY(s_gs12_g31_s0_effs), 0,NULL, 1,&sStationScripts[33], },
};

static const struct GroundScriptSector s_gs12_g32_sectors[] = { /* 0x81eddd4 */
    { LPARRAY(s_gs12_g32_s0_lives), 0,NULL, LPARRAY(s_gs12_g32_s0_effs), 0,NULL, 1,&sStationScripts[34], },
};

static const struct GroundScriptSector s_gs12_g33_sectors[] = { /* 0x81eddfc */
    { LPARRAY(s_gs12_g33_s0_lives), 0,NULL, LPARRAY(s_gs12_g33_s0_effs), 0,NULL, 1,&sStationScripts[35], },
};

static const struct GroundScriptSector s_gs12_g34_sectors[] = { /* 0x81ede24 */
    { LPARRAY(s_gs12_g34_s0_lives), 0,NULL, LPARRAY(s_gs12_g34_s0_effs), 0,NULL, 1,&sStationScripts[36], },
};

static const struct GroundScriptSector s_gs12_g35_sectors[] = { /* 0x81ede4c */
    { LPARRAY(s_gs12_g35_s0_lives), 0,NULL, LPARRAY(s_gs12_g35_s0_effs), 0,NULL, 1,&sStationScripts[37], },
};

static const struct GroundScriptSector s_gs12_g36_sectors[] = { /* 0x81ede74 */
    { LPARRAY(s_gs12_g36_s0_lives), 0,NULL, LPARRAY(s_gs12_g36_s0_effs), 0,NULL, 1,&sStationScripts[38], },
};

static const struct GroundScriptSector s_gs12_g37_sectors[] = { /* 0x81ede9c */
    { LPARRAY(s_gs12_g37_s0_lives), 0,NULL, LPARRAY(s_gs12_g37_s0_effs), 0,NULL, 1,&sStationScripts[39], },
};

static const struct GroundScriptSector s_gs12_g38_sectors[] = { /* 0x81edec4 */
    { LPARRAY(s_gs12_g38_s0_lives), 0,NULL, LPARRAY(s_gs12_g38_s0_effs), 0,NULL, 1,&sStationScripts[40], },
};

static const struct GroundScriptSector s_gs12_g39_sectors[] = { /* 0x81edeec */
    { LPARRAY(s_gs12_g39_s0_lives), 0,NULL, LPARRAY(s_gs12_g39_s0_effs), 0,NULL, 1,&sStationScripts[41], },
    { LPARRAY(s_gs12_g39_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs12_g40_sectors[] = { /* 0x81edf3c */
    { LPARRAY(s_gs12_g40_s0_lives), 0,NULL, LPARRAY(s_gs12_g40_s0_effs), 0,NULL, 1,&sStationScripts[42], },
};

static const struct GroundScriptSector s_gs12_g41_sectors[] = { /* 0x81edf64 */
    { LPARRAY(s_gs12_g41_s0_lives), 0,NULL, LPARRAY(s_gs12_g41_s0_effs), 0,NULL, 1,&sStationScripts[43], },
};

static const struct GroundScriptSector s_gs12_g42_sectors[] = { /* 0x81edf8c */
    { LPARRAY(s_gs12_g42_s0_lives), 0,NULL, LPARRAY(s_gs12_g42_s0_effs), 0,NULL, 1,&sStationScripts[44], },
};

static const struct GroundScriptSector s_gs12_g43_sectors[] = { /* 0x81edfb4 */
    { LPARRAY(s_gs12_g43_s0_lives), 0,NULL, LPARRAY(s_gs12_g43_s0_effs), 0,NULL, 1,&sStationScripts[45], },
};

static const struct GroundScriptSector s_gs12_g44_sectors[] = { /* 0x81edfdc */
    { LPARRAY(s_gs12_g44_s0_lives), 0,NULL, LPARRAY(s_gs12_g44_s0_effs), 0,NULL, 1,&sStationScripts[46], },
};

static const struct GroundScriptSector s_gs12_g45_sectors[] = { /* 0x81ee004 */
    { LPARRAY(s_gs12_g45_s0_lives), 0,NULL, LPARRAY(s_gs12_g45_s0_effs), 0,NULL, 1,&sStationScripts[47], },
};

static const struct GroundScriptSector s_gs12_g46_sectors[] = { /* 0x81ee02c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs12_g46_s0_evts), 1,&sStationScripts[48], },
    { LPARRAY(s_gs12_g46_s1_lives), 0,NULL, LPARRAY(s_gs12_g46_s1_effs), 0,NULL, 1,&sStationScripts[49], },
};

static const struct GroundScriptGroup s_gs12_groups[] = { /* 0x81ee07c */
    { LPARRAY(s_gs12_g0_sectors) },
    { LPARRAY(s_gs12_g1_sectors) },
    { LPARRAY(s_gs12_g2_sectors) },
    { LPARRAY(s_gs12_g3_sectors) },
    { LPARRAY(s_gs12_g4_sectors) },
    { LPARRAY(s_gs12_g5_sectors) },
    { LPARRAY(s_gs12_g6_sectors) },
    { LPARRAY(s_gs12_g7_sectors) },
    { LPARRAY(s_gs12_g8_sectors) },
    { LPARRAY(s_gs12_g9_sectors) },
    { LPARRAY(s_gs12_g10_sectors) },
    { LPARRAY(s_gs12_g11_sectors) },
    { LPARRAY(s_gs12_g12_sectors) },
    { LPARRAY(s_gs12_g13_sectors) },
    { LPARRAY(s_gs12_g14_sectors) },
    { LPARRAY(s_gs12_g15_sectors) },
    { LPARRAY(s_gs12_g16_sectors) },
    { LPARRAY(s_gs12_g17_sectors) },
    { LPARRAY(s_gs12_g18_sectors) },
    { LPARRAY(s_gs12_g19_sectors) },
    { LPARRAY(s_gs12_g20_sectors) },
    { LPARRAY(s_gs12_g21_sectors) },
    { LPARRAY(s_gs12_g22_sectors) },
    { LPARRAY(s_gs12_g23_sectors) },
    { LPARRAY(s_gs12_g24_sectors) },
    { LPARRAY(s_gs12_g25_sectors) },
    { LPARRAY(s_gs12_g26_sectors) },
    { LPARRAY(s_gs12_g27_sectors) },
    { LPARRAY(s_gs12_g28_sectors) },
    { LPARRAY(s_gs12_g29_sectors) },
    { LPARRAY(s_gs12_g30_sectors) },
    { LPARRAY(s_gs12_g31_sectors) },
    { LPARRAY(s_gs12_g32_sectors) },
    { LPARRAY(s_gs12_g33_sectors) },
    { LPARRAY(s_gs12_g34_sectors) },
    { LPARRAY(s_gs12_g35_sectors) },
    { LPARRAY(s_gs12_g36_sectors) },
    { LPARRAY(s_gs12_g37_sectors) },
    { LPARRAY(s_gs12_g38_sectors) },
    { LPARRAY(s_gs12_g39_sectors) },
    { LPARRAY(s_gs12_g40_sectors) },
    { LPARRAY(s_gs12_g41_sectors) },
    { LPARRAY(s_gs12_g42_sectors) },
    { LPARRAY(s_gs12_g43_sectors) },
    { LPARRAY(s_gs12_g44_sectors) },
    { LPARRAY(s_gs12_g45_sectors) },
    { LPARRAY(s_gs12_g46_sectors) },
};

static const struct GroundLink s_gs12_links[] = { /* 0x81ee1f4 */
    /* link   0 */ { { /*x*/  17, /*y*/  26, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 3 },
    /* link   1 */ { { /*x*/  30, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  30, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  30, /*y*/  35, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs12 = { LPARRAY(s_gs12_groups), s_gs12_links }; /* 0x81ee214 */
