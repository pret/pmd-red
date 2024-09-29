













































































































































static const struct ScriptCommand s_gs9_g0_s0_station_sref_script[] = { /* 0x819ad18 */
    DEBUGINFO,
    SELECT_MAP(9),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 2, /* to label */ 0),
    COND(JUDGE_EQ, 3, /* to label */ 1),
    COND(JUDGE_EQ, 4, /* to label */ 2),
    COND(JUDGE_EQ, 5, /* to label */ 3),
    COND(JUDGE_EQ, 6, /* to label */ 4),
    COND(JUDGE_EQ, 7, /* to label */ 5),
    COND(JUDGE_EQ, 8, /* to label */ 6),
    COND(JUDGE_EQ, 9, /* to label */ 7),
    COND(JUDGE_EQ, 10, /* to label */ 8),
    COND(JUDGE_EQ, 11, /* to label */ 9),
    COND(JUDGE_LT, 15, /* to label */ 10),
    COND(JUDGE_EQ, 15, /* to label */ 11),
    COND(JUDGE_EQ, 16, /* to label */ 12),
    COND(JUDGE_EQ, 18, /* to label */ 13),
    JUMP_LABEL(14),
  LABEL(0), /* = 0x00 */
    JUMP_LABEL(10),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 4, /* to label */ 15),
    COND_EQUAL(5, /* to label */ 16),
    JUMP_LABEL(17),
  LABEL(15), /* = 0x0f */
    JUMP_SCRIPT(EVENT_M01E02A_L002),
  LABEL(16), /* = 0x10 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    CALL_STATION( 19,  0),
    JUMP_LABEL(10),
  LABEL(17), /* = 0x11 */
    CALL_STATION( 22,  0),
    JUMP_LABEL(10),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 18),
    COND_EQUAL(4, /* to label */ 19),
    COND_EQUAL(5, /* to label */ 20),
    JUMP_LABEL(10),
  LABEL(18), /* = 0x12 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    CALL_STATION( 24,  0),
    JUMP_LABEL(10),
  LABEL(19), /* = 0x13 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 21),
    JUMP_LABEL(10),
  LABEL(21), /* = 0x15 */
    JUMP_SCRIPT(EVENT_M01E02B_L004),
  LABEL(20), /* = 0x14 */
    JUMP_SCRIPT(EVENT_M01E02B_L004B),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 10),
    COND_EQUAL(2, /* to label */ 22),
    COND(JUDGE_LE, 5, /* to label */ 10),
    COND_EQUAL(6, /* to label */ 23),
    COND(JUDGE_LE, 7, /* to label */ 10),
    COND_EQUAL(8, /* to label */ 24),
    CALL_STATION( 32,  0),
    JUMP_LABEL(10),
  LABEL(22), /* = 0x16 */
    JUMP_SCRIPT(EVENT_M01E03A_L002),
  LABEL(23), /* = 0x17 */
    JUMP_SCRIPT(EVENT_M01E03A_L005),
  LABEL(24), /* = 0x18 */
    JUMP_SCRIPT(EVENT_M01E03A_L007),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 25),
    COND_EQUAL(2, /* to label */ 26),
    CALL_STATION( 37,  0),
    JUMP_LABEL(10),
  LABEL(25), /* = 0x19 */
    JUMP_LABEL(10),
  LABEL(26), /* = 0x1a */
    JUMP_SCRIPT(EVENT_M01E04A_L002),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 27),
    COND_EQUAL(2, /* to label */ 28),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(27), /* = 0x1b */
    CALL_STATION( 37,  0),
    JUMP_LABEL(10),
  LABEL(28), /* = 0x1c */
    JUMP_SCRIPT(EVENT_M01E04B_L002),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 29),
    COND_EQUAL(2, /* to label */ 30),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(29), /* = 0x1d */
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(30), /* = 0x1e */
    JUMP_SCRIPT(EVENT_M01E05A_L002),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 31),
    COND_EQUAL(2, /* to label */ 32),
  LABEL(31), /* = 0x1f */
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(32), /* = 0x20 */
    JUMP_SCRIPT(EVENT_M01E05B_L002),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 33),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(33), /* = 0x21 */
    JUMP_SCRIPT(EVENT_M01E06A_L002),
  LABEL(9), /* = 0x09 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 5),
    CALL_STATION( 50,  0),
    JUMP_LABEL(10),
  LABEL(11), /* = 0x0b */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 34),
    COND_EQUAL(4, /* to label */ 35),
    COND_EQUAL(6, /* to label */ 36),
    COND_EQUAL(8, /* to label */ 37),
    COND_EQUAL(9, /* to label */ 38),
    COND_EQUAL(10, /* to label */ 39),
    CALL_STATION( 56,  0),
    JUMP_LABEL(10),
  LABEL(34), /* = 0x22 */
    JUMP_SCRIPT(EVENT_M01E09A_L002),
  LABEL(35), /* = 0x23 */
    JUMP_SCRIPT(EVENT_M01E09A_L004),
  LABEL(36), /* = 0x24 */
    JUMP_SCRIPT(EVENT_M01E09A_L006),
  LABEL(37), /* = 0x25 */
    JUMP_SCRIPT(EVENT_M01E09A_L008),
  LABEL(38), /* = 0x26 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 6),
    CALL_STATION( 61,  0),
    JUMP_LABEL(10),
  LABEL(39), /* = 0x27 */
    JUMP_SCRIPT(EVENT_M01E09A_L010),
  LABEL(12), /* = 0x0c */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 40),
    COND_EQUAL(3, /* to label */ 41),
    CALL_STATION( 66,  0),
    JUMP_LABEL(10),
  LABEL(40), /* = 0x28 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 7),
    CALL_STATION( 64,  0),
    JUMP_LABEL(10),
  LABEL(41), /* = 0x29 */
    JUMP_SCRIPT(EVENT_M01E10A_L003),
  LABEL(13), /* = 0x0d */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 42),
    CALL_STATION( 70,  0),
    JUMP_LABEL(10),
  LABEL(42), /* = 0x2a */
    JUMP_SCRIPT(EVENT_M02E01A_L002),
  LABEL(14), /* = 0x0e */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 5, /* to label */ 43),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 54, 0, /* to label */ 44),
    CALL_STATION(  3,  0),
    JUMP_LABEL(10),
  LABEL(43), /* = 0x2b */
    JUMP_SCRIPT(EVENT_S09E01A_L004),
  LABEL(44), /* = 0x2c */
    JUMP_SCRIPT(EVENT_S09E01B_L001),
  LABEL(10), /* = 0x0a */
    CJUMP_VAR(DUNGEON_RESULT),
    COND_EQUAL(4, /* to label */ 45),
    COND_EQUAL(5, /* to label */ 46),
    CJUMP_VAR(START_MODE),
    COND_EQUAL(1, /* to label */ 47),
    COND_EQUAL(3, /* to label */ 48),
    COND_EQUAL(2, /* to label */ 49),
    COND_EQUAL(4, /* to label */ 45),
    COND_EQUAL(5, /* to label */ 46),
    COND_EQUAL(9, /* to label */ 46),
    COND_EQUAL(10, /* to label */ 46),
    JUMP_LABEL(47),
  LABEL(49), /* = 0x31 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 50),
    COND_EQUAL(2, /* to label */ 50),
    COND_EQUAL(3, /* to label */ 50),
    COND_EQUAL(4, /* to label */ 50),
    COND_EQUAL(5, /* to label */ 50),
    COND_EQUAL(6, /* to label */ 50),
    COND_EQUAL(7, /* to label */ 50),
    COND_EQUAL(8, /* to label */ 50),
    COND_EQUAL(12, /* to label */ 51),
    COND_EQUAL(13, /* to label */ 51),
    COND_EQUAL(14, /* to label */ 51),
    COND_EQUAL(178, /* to label */ 46),
    JUMP_LABEL(45),
  LABEL(47), /* = 0x2f */
    SELECT_LIVES(0, 5),
    JUMP_LABEL(52),
  LABEL(48), /* = 0x30 */
    SELECT_LIVES(0, 6),
    JUMP_LABEL(52),
  LABEL(50), /* = 0x32 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(52),
  LABEL(45), /* = 0x2d */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    SELECT_LIVES(0, 2),
    JUMP_LABEL(52),
  LABEL(46), /* = 0x2e */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    SELECT_LIVES(0, 3),
    JUMP_LABEL(52),
  LABEL(51), /* = 0x33 */
    CJUMP_VAR(DUNGEON_RESULT),
    COND_EQUAL(4, /* to label */ 45),
    COND_EQUAL(5, /* to label */ 46),
    COND_EQUAL(12, /* to label */ 53),
    COND_EQUAL(11, /* to label */ 53),
    COND_EQUAL(10, /* to label */ 54),
    COND_EQUAL(9, /* to label */ 54),
    COND_EQUAL(6, /* to label */ 54),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    SELECT_LIVES(0, 4),
    JUMP_LABEL(52),
  LABEL(52), /* = 0x34 */
    WAIT(0),
    JUMP_LABEL(56),
  LABEL(55), /* = 0x37 */
    SELECT_ENTITIES(0, 7),
  LABEL(56), /* = 0x38 */
    BGM_SWITCH(1),
    JUMP_SCRIPT(COMMON_ENTER),
  LABEL(53), /* = 0x35 */
    JUMPIF_SCENARIOCHECK(8, /* to label */ 57),
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(1, /* to label */ 58),
    COND_EQUAL(2, /* to label */ 59),
    COND_EQUAL(4, /* to label */ 60),
    COND_EQUAL(6, /* to label */ 61),
    COND_EQUAL(7, /* to label */ 62),
    COND_EQUAL(9, /* to label */ 63),
    COND_EQUAL(17, /* to label */ 64),
    COND_EQUAL(19, /* to label */ 65),
  LABEL(57), /* = 0x39 */
    EXECUTE_SUBSTATION(9, 5, 0),
    RET,
  LABEL(58), /* = 0x3a */
    EXECUTE_SUBSTATION(9, 21, 0),
    RET,
  LABEL(59), /* = 0x3b */
    EXECUTE_SUBSTATION(9, 27, 0),
    RET,
  LABEL(60), /* = 0x3c */
    EXECUTE_SUBSTATION(9, 33, 0),
    RET,
  LABEL(61), /* = 0x3d */
    EXECUTE_SUBSTATION(9, 38, 0),
    RET,
  LABEL(62), /* = 0x3e */
    EXECUTE_SUBSTATION(9, 42, 0),
    RET,
  LABEL(63), /* = 0x3f */
    EXECUTE_SUBSTATION(9, 44, 0),
    RET,
  LABEL(64), /* = 0x40 */
    EXECUTE_SUBSTATION(9, 63, 0),
    RET,
  LABEL(65), /* = 0x41 */
    EXECUTE_SUBSTATION(9, 67, 0),
    RET,
  LABEL(54), /* = 0x36 */
    EXECUTE_SUBSTATION(9, 7, 0),
    RET,
};

static const struct ScriptRef s_gs9_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs9_g0_s0_station_sref_script }; /* 0x819bec8 */


static const struct ScriptCommand s_gs9_g0_s0_evt0_sref_script[] = { /* 0x819bed4 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 4, 3, /* to label */ 0),
    { 0x01, 0x00, -0x0001,  0x00000001,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, 22, 1),
    HALT,
};

static const struct ScriptRef s_gs9_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g0_s0_evt0_sref_script }; /* 0x819bf44 */

static const struct ScriptCommand s_gs9_g0_s0_evt1_sref_script[] = { /* 0x819bf50 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_MAIN, 4, 3, /* to label */ 0),
    JUMPIF_SCENARIOCHECK(4, /* to label */ 1),
  LABEL(2), /* = 0x02 */
    { 0x3b, 0x12,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 3),
    { 0x3c, 0x16,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(-2, /* to label */ 3),
    COND_EQUAL(-1, /* to label */ 4),
    COND_EQUAL(0, /* to label */ 4),
    HALT,
  LABEL(3), /* = 0x03 */
    { 0x03, 0x00,  0x001e,  0x00000001,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 4),
    HALT,
  LABEL(4), /* = 0x04 */
    RET,
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, 22, 2),
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF(JUDGE_LE, FRIEND_SUM, 2, /* to label */ 2),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This will be a dangerous journey.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'd better leave without telling\nthe others.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g0_s0_evt1_sref_script }; /* 0x819c174 */

static const struct ScriptCommand s_gs9_g0_s0_evt2_sref_script[] = { /* 0x819c180 */
    DEBUGINFO,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    JUMPIF_EQUAL(WARP_LOCK, 5, /* to label */ 1),
    JUMPIF_EQUAL(WARP_LOCK, 6, /* to label */ 2),
    JUMPIF_EQUAL(WARP_LOCK, 7, /* to label */ 3),
    JUMP_LABEL(0),
    CALL_SCRIPT(EVENT_DIVIDE_WARP_LOCK_FUNC),
    RET,
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 18, 3, /* to label */ 5),
    { 0x04, 0x00,  0x001e, -0x00000001,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 6),
    HALT,
  LABEL(6), /* = 0x06 */
    RET,
  LABEL(1), /* = 0x01 */
    EXECUTE_STATION(-1, 50, 3),
    HALT,
  LABEL(2), /* = 0x02 */
    EXECUTE_STATION(-1, 61, 1),
    HALT,
  LABEL(3), /* = 0x03 */
    EXECUTE_STATION(-1, 64, 1),
    HALT,
  LABEL(5), /* = 0x05 */
    EXECUTE_STATION(9, 71, 0),
    HALT,
};

static const struct ScriptRef s_gs9_g0_s0_evt2_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g0_s0_evt2_sref_script }; /* 0x819c330 */


static const struct ScriptCommand s_gs9_g0_s0_evt3_sref_script[] = { /* 0x819c33c */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x0000000c,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs9_g0_s0_evt3_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g0_s0_evt3_sref_script }; /* 0x819c36c */

static const struct ScriptCommand s_gs9_g0_s0_obj0_dlg2[] = { /* 0x819c378 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CJUMP_DIR_TO_LINK(0),
    COND_EQUAL(0, /* to label */ 0),
    JUMPIF_SCENE_EQ(SCENARIO_SUB7, 49, 1, /* to label */ 1),
  LABEL(2), /* = 0x02 */
    { 0x3c, 0x21,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There is a warning tag\n#+on the side of the Mailbox.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+- Open the Mailbox at the front -") },
    JUMP_SCRIPT(END_TALK),
    EXECUTE_FUNCTION(EVENT_S01E02A_L001),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x3b, 0x08,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 2),
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+<Pokémon News>\n#+= Extra! =") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Buried Relic Discovered!") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Mystery ruin\n#+found underground!") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Its site had been hidden by the crater\n#+of a meteor strike in ancient times.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The Buried Relic is thought to date\n#+back beyond recorded history.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There are rumors of treasures...") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+And perhaps even Pokémon\n#+that lived in ancient times.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The Buried Relic is the main\n#+topic in Pokémon Square.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB7, 49,  2),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g0_s0_obj2_dlg2[] = { /* 0x819c748 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("\n          ← Friend Areas") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENARIOCHECK(4, /* to label */ 0),
  LABEL(1), /* = 0x01 */
    { 0x3c, 0x16,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(-2, /* to label */ 2),
    COND_EQUAL(-1, /* to label */ 2),
    COND_EQUAL(0, /* to label */ 2),
    HALT,
  LABEL(2), /* = 0x02 */
    { 0xe4, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_LE, FRIEND_SUM, 2, /* to label */ 1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This will be a dangerous journey.") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("I'd better leave without telling\nthe others.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g0_s0_obj3_dlg0[] = { /* 0x819c8f4 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(29, /* to label */ 0),
    JUMPIF_ARRAY(EVENT_B01P01, 2, /* to label */ 0),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g0_s0_obj4_dlg0[] = { /* 0x819c974 */
    DEBUGINFO,
    JUMPIF_ARRAY(EVENT_B01P01, 0, /* to label */ 0),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g0_s0_obj5_dlg0[] = { /* 0x819c9e4 */
    DEBUGINFO,
    JUMPIF_ARRAY(EVENT_B01P01, 1, /* to label */ 0),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g0_s0_obj6_dlg0[] = { /* 0x819ca54 */
    DEBUGINFO,
    JUMPIF_ARRAY(EVENT_B01P01, 3, /* to label */ 0),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g0_s1_lives0_dlg0[] = { /* 0x819cac4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s1_lives1_dlg0[] = { /* 0x819cb04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s2_lives0_dlg0[] = { /* 0x819cb44 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s2_lives1_dlg0[] = { /* 0x819cb84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s3_lives0_dlg0[] = { /* 0x819cbc4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s3_lives1_dlg0[] = { /* 0x819cc04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s4_lives0_dlg0[] = { /* 0x819cc44 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s4_lives1_dlg0[] = { /* 0x819cc84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s5_lives0_dlg0[] = { /* 0x819ccc4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s5_lives1_dlg0[] = { /* 0x819cd04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s6_lives0_dlg0[] = { /* 0x819cd44 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s6_lives1_dlg0[] = { /* 0x819cd74 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g0_s7_lives0_dlg2[] = { /* 0x819cda4 */
    DEBUGINFO,
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
  LABEL(0), /* = 0x00 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _("The rescue team base can be changed.")),
    CHOICE(/* label */  1, _("Change level")),
    CHOICE(/* label */  2, _("Change type")),
    CHOICE(/* label */  3, _("Placement of fixtures")),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("Farewell") },
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _("The rescue team base's level can\nbe changed.")),
    CHOICE(/* label */  4, _("Change to level 1")),
    CHOICE(/* label */  5, _("Change to level 2")),
    CHOICE(/* label */  6, _("Change to level 3")),
    JUMP_LABEL(0),
  LABEL(4), /* = 0x04 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to level 1.") },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 0),
    JUMP_LABEL(7),
  LABEL(5), /* = 0x05 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to level 2.") },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 1),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to level 3.") },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 2),
    JUMP_LABEL(7),
  LABEL(2), /* = 0x02 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _("The rescue team base's type can\nbe changed.")),
    CHOICE(/* label */  8, _("Change to rescue team base 7 〜")),
    CHOICE(/* label */  9, _("Change to rescue team base 1")),
    CHOICE(/* label */ 10, _("Change to rescue team base 2")),
    CHOICE(/* label */ 11, _("Change to rescue team base 3")),
    CHOICE(/* label */ 12, _("Change to rescue team base 4")),
    CHOICE(/* label */ 13, _("Change to rescue team base 5")),
    CHOICE(/* label */ 14, _("Change to rescue team base 6")),
    JUMP_LABEL(0),
  LABEL(9), /* = 0x09 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 1.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 0),
    JUMP_LABEL(7),
  LABEL(10), /* = 0x0a */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 2.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 1),
    JUMP_LABEL(7),
  LABEL(11), /* = 0x0b */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 3.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 2),
    JUMP_LABEL(7),
  LABEL(12), /* = 0x0c */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 4.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 3),
    JUMP_LABEL(7),
  LABEL(13), /* = 0x0d */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 5.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 4),
    JUMP_LABEL(7),
  LABEL(14), /* = 0x0e */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 6.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 5),
    JUMP_LABEL(7),
  LABEL(8), /* = 0x08 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _("The rescue team base's type will\nbe changed.")),
    CHOICE(/* label */ 15, _("Change to rescue team base 14 〜")),
    CHOICE(/* label */ 16, _("Change to rescue team base 7")),
    CHOICE(/* label */ 17, _("Change to rescue team base 8")),
    CHOICE(/* label */ 18, _("Change to rescue team base 9")),
    CHOICE(/* label */ 19, _("Change to rescue team base 10")),
    CHOICE(/* label */ 20, _("Change to rescue team base 11")),
    CHOICE(/* label */ 21, _("Change to rescue team base 12")),
    JUMP_LABEL(0),
  LABEL(16), /* = 0x10 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 7.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 6),
    JUMP_LABEL(7),
  LABEL(17), /* = 0x11 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 8.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 7),
    JUMP_LABEL(7),
  LABEL(18), /* = 0x12 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 9.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 8),
    JUMP_LABEL(7),
  LABEL(19), /* = 0x13 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 10.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 9),
    JUMP_LABEL(7),
  LABEL(20), /* = 0x14 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 11.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 10),
    JUMP_LABEL(7),
  LABEL(21), /* = 0x15 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team\nbase 12.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 11),
    JUMP_LABEL(7),
  LABEL(15), /* = 0x0f */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _("The rescue team base's type will\nbe changed.")),
    CHOICE(/* label */  2, _("Change to rescue team base 1 〜")),
    CHOICE(/* label */ 22, _("Change to rescue team base 13")),
    CHOICE(/* label */ 23, _("Change to rescue team base 14")),
    CHOICE(/* label */ 24, _("Change to rescue team base 15")),
    CHOICE(/* label */ 25, _("Change to rescue team base 16")),
    JUMP_LABEL(0),
  LABEL(22), /* = 0x16 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team base 13.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 12),
    JUMP_LABEL(7),
  LABEL(23), /* = 0x17 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team base 14.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 13),
    JUMP_LABEL(7),
  LABEL(24), /* = 0x18 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team base 15.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 14),
    JUMP_LABEL(7),
  LABEL(25), /* = 0x19 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("It will be changed to rescue team base 16.") },
    UPDATE_VARINT(CALC_SET, BASE_KIND, 15),
    JUMP_LABEL(7),
  LABEL(3), /* = 0x03 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("Fixtures will be placed.") },
    SET_ARRAYVAL(EVENT_B01P01,  0,  1),
    SET_ARRAYVAL(EVENT_B01P01,  1,  1),
    SET_ARRAYVAL(EVENT_B01P01,  2,  1),
    SET_ARRAYVAL(EVENT_B01P01,  3,  1),
    JUMP_LABEL(7),
  LABEL(7), /* = 0x07 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    { 0x01, 0x00, -0x0001,  0x00000009,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g1_s0_station_sref_script[] = { /* 0x819dcc8 */
    DEBUGINFO,
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 2, /* to label */ 0),
    COND(JUDGE_EQ, 3, /* to label */ 1),
    COND(JUDGE_EQ, 4, /* to label */ 2),
    COND(JUDGE_EQ, 5, /* to label */ 3),
    COND(JUDGE_EQ, 6, /* to label */ 4),
    COND(JUDGE_EQ, 7, /* to label */ 5),
    COND(JUDGE_EQ, 8, /* to label */ 6),
    COND(JUDGE_EQ, 9, /* to label */ 7),
    COND(JUDGE_EQ, 10, /* to label */ 8),
    COND(JUDGE_EQ, 11, /* to label */ 9),
    COND(JUDGE_LT, 15, /* to label */ 10),
    COND(JUDGE_EQ, 15, /* to label */ 11),
    COND(JUDGE_EQ, 16, /* to label */ 12),
    COND(JUDGE_EQ, 18, /* to label */ 13),
    JUMP_LABEL(14),
  LABEL(0), /* = 0x00 */
    JUMP_LABEL(10),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 15),
    COND_EQUAL(3, /* to label */ 16),
    JUMP_LABEL(17),
  LABEL(15), /* = 0x0f */
    JUMP_LABEL(10),
  LABEL(16), /* = 0x10 */
    CALL_STATION( 19,  0),
    JUMP_LABEL(10),
  LABEL(17), /* = 0x11 */
    CALL_STATION( 22,  0),
    JUMP_LABEL(10),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 18),
    COND_EQUAL(4, /* to label */ 19),
    COND_EQUAL(5, /* to label */ 20),
    JUMP_LABEL(10),
  LABEL(18), /* = 0x12 */
    CALL_STATION( 24,  0),
    JUMP_LABEL(10),
  LABEL(19), /* = 0x13 */
    JUMP_LABEL(10),
    JUMP_LABEL(10),
  LABEL(20), /* = 0x14 */
    JUMP_LABEL(10),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 10),
    COND_EQUAL(2, /* to label */ 22),
    COND(JUDGE_LE, 5, /* to label */ 10),
    COND_EQUAL(6, /* to label */ 23),
    COND(JUDGE_LE, 7, /* to label */ 10),
    COND_EQUAL(8, /* to label */ 24),
    CALL_STATION( 32,  0),
    JUMP_LABEL(10),
  LABEL(22), /* = 0x16 */
    JUMP_LABEL(10),
  LABEL(23), /* = 0x17 */
    JUMP_LABEL(10),
  LABEL(24), /* = 0x18 */
    JUMP_LABEL(10),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 25),
    COND_EQUAL(2, /* to label */ 26),
    CALL_STATION( 37,  0),
    JUMP_LABEL(10),
  LABEL(25), /* = 0x19 */
    JUMP_LABEL(10),
  LABEL(26), /* = 0x1a */
    JUMP_LABEL(10),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 27),
    COND_EQUAL(2, /* to label */ 28),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(27), /* = 0x1b */
    CALL_STATION( 37,  0),
    JUMP_LABEL(10),
  LABEL(28), /* = 0x1c */
    JUMP_LABEL(10),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 29),
    COND_EQUAL(2, /* to label */ 30),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(29), /* = 0x1d */
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(30), /* = 0x1e */
    JUMP_LABEL(10),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 1, /* to label */ 31),
    COND_EQUAL(2, /* to label */ 32),
  LABEL(31), /* = 0x1f */
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(32), /* = 0x20 */
    JUMP_LABEL(10),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 33),
    CALL_STATION( 41,  0),
    JUMP_LABEL(10),
  LABEL(33), /* = 0x21 */
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    CALL_STATION( 50,  0),
    JUMP_LABEL(10),
  LABEL(11), /* = 0x0b */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 34),
    COND_EQUAL(4, /* to label */ 35),
    COND_EQUAL(6, /* to label */ 36),
    COND_EQUAL(8, /* to label */ 37),
    COND_EQUAL(9, /* to label */ 38),
    COND_EQUAL(10, /* to label */ 39),
    CALL_STATION( 56,  0),
    JUMP_LABEL(10),
  LABEL(34), /* = 0x22 */
    JUMP_LABEL(10),
  LABEL(35), /* = 0x23 */
    JUMP_LABEL(10),
  LABEL(36), /* = 0x24 */
    JUMP_LABEL(10),
  LABEL(37), /* = 0x25 */
    JUMP_LABEL(10),
  LABEL(38), /* = 0x26 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    CALL_STATION( 61,  0),
    JUMP_LABEL(10),
  LABEL(39), /* = 0x27 */
    JUMP_LABEL(10),
  LABEL(12), /* = 0x0c */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 40),
    COND_EQUAL(3, /* to label */ 41),
    CALL_STATION( 66,  0),
    JUMP_LABEL(10),
  LABEL(40), /* = 0x28 */
    CALL_STATION( 64,  0),
    JUMP_LABEL(10),
  LABEL(41), /* = 0x29 */
    JUMP_LABEL(10),
  LABEL(13), /* = 0x0d */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 42),
    CALL_STATION( 70,  0),
    JUMP_LABEL(10),
  LABEL(42), /* = 0x2a */
    JUMP_LABEL(10),
  LABEL(14), /* = 0x0e */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 5, /* to label */ 43),
    CALL_STATION(  3,  0),
    JUMP_LABEL(10),
  LABEL(43), /* = 0x2b */
    JUMP_LABEL(10),
  LABEL(10), /* = 0x0a */
    WAIT(0),
    JUMP_LABEL(46),
  LABEL(45), /* = 0x2d */
    SELECT_ENTITIES(0, 7),
  LABEL(46), /* = 0x2e */
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g1_s0_station_sref_script }; /* 0x819e758 */



static const struct ScriptCommand s_gs9_g1_s1_lives0_dlg2[] = { /* 0x819e764 */
    DEBUGINFO,
    JUMP_SCRIPT(UNIT_TALK),
};

static const struct ScriptCommand s_gs9_g1_s1_lives1_dlg2[] = { /* 0x819e784 */
    DEBUGINFO,
    JUMP_SCRIPT(UNIT_TALK),
};

static const struct ScriptCommand s_gs9_g1_s1_lives2_dlg2[] = { /* 0x819e7a4 */
    DEBUGINFO,
    JUMP_SCRIPT(UNIT_TALK),
};

static const struct ScriptCommand s_gs9_g1_s1_lives3_dlg2[] = { /* 0x819e7c4 */
    DEBUGINFO,
    JUMP_SCRIPT(UNIT_TALK),
};

static const struct ScriptCommand s_gs9_g2_s0_station_sref_script[] = { /* 0x819e7e4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMPIF_ARRAY(EVENT_B01P01, 3, /* to label */ 0),
    { 0x3b, 0x0f,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    SET_ARRAYVAL(EVENT_B01P01,  3,  1),
    SELECT_ENTITIES(-1, 2),
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g2_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g2_s0_station_sref_script }; /* 0x819e8b4 */

static const struct ScriptCommand s_gs9_g2_s0_eff0_script[] = { /* 0x819e8c0 */
    DEBUGINFO,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g2_s1_lives0_dlg0[] = { /* 0x819e920 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(501),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Clunk!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g2_s1_eff0_script[] = { /* 0x819eaf4 */
    DEBUGINFO,
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g2_s2_obj0_dlg0[] = { /* 0x819eb44 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g3_s0_station_sref_script[] = { /* 0x819eb84 */
    DEBUGINFO,
    JUMP_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g3_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g3_s0_station_sref_script }; /* 0x819ebb4 */

static const struct ScriptCommand s_gs9_g4_s0_station_sref_script[] = { /* 0x819ebc0 */
    DEBUGINFO,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_0(SCENARIO_SUB2),
    COND(JUDGE_EQ, 33, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB2, 33, 1, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    SELECT_ENTITIES(80, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB1, 29, 1, /* to label */ 5),
    JUMPIF_EQUAL(SCENARIO_SUB1, 30, /* to label */ 6),
    JUMP_LABEL(7),
  LABEL(5), /* = 0x05 */
    SELECT_ENTITIES(73, 0),
    RET_DIRECT,
  LABEL(6), /* = 0x06 */
    SELECT_ENTITIES(77, 0),
    RET_DIRECT,
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 18, 0, /* to label */ 8),
    RET_DIRECT,
  LABEL(8), /* = 0x08 */
    RET_DIRECT,
    JUMPIF_SCENE_GT(SCENARIO_SUB3, 36, 1, /* to label */ 10),
    SELECT_ENTITIES(10, 0),
  LABEL(10), /* = 0x0a */
    JUMPIF_SCENE_GT(SCENARIO_SUB4, 38, 0, /* to label */ 12),
    SELECT_ENTITIES(11, 0),
  LABEL(12), /* = 0x0c */
    JUMPIF_SCENE_GT(SCENARIO_SUB5, 44, 1, /* to label */ 14),
    SELECT_ENTITIES(12, 0),
  LABEL(14), /* = 0x0e */
    JUMPIF_SCENE_GT(SCENARIO_SUB6, 46, 1, /* to label */ 16),
    SELECT_ENTITIES(13, 0),
  LABEL(16), /* = 0x10 */
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, 0, /* to label */ 18),
    SELECT_ENTITIES(14, 0),
  LABEL(18), /* = 0x12 */
    JUMPIF_SCENE_GT(SCENARIO_SUB8, 51, 0, /* to label */ 20),
    SELECT_ENTITIES(15, 0),
  LABEL(20), /* = 0x14 */
    JUMPIF_SCENE_GT(SCENARIO_SUB9, 53, 0, /* to label */ 22),
    SELECT_ENTITIES(16, 0),
  LABEL(22), /* = 0x16 */
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g4_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g4_s0_station_sref_script }; /* 0x819eee0 */









static const struct ScriptCommand s_gs9_g5_s0_station_sref_script[] = { /* 0x819eeec */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    JUMPIF_SCENARIOCHECK(8, /* to label */ 0),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 1),
  LABEL(1), /* = 0x01 */
    SELECT_EVENTS(0, 0),
    CALL_STATION(  4,  0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_STATION(  8,  0),
    RET,
};

static const struct ScriptRef s_gs9_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g5_s0_station_sref_script }; /* 0x819f03c */

static const struct ScriptCommand s_gs9_g5_s0_lives0_dlg0[] = { /* 0x819f048 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0.")),
    VARIANT(/* == */  1, _(" We blew it yesterday,\nso let's get it right this time.")),
    VARIANT_DEFAULT(_(" Good morning, $n0.")),
    VARIANT_DEFAULT(_(" We failed yesterday,\nso let's try harder this time.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g5_s0_lives1_dlg0[] = { /* 0x819f1cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g5_s1_lives0_dlg0[] = { /* 0x819f20c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g6_s0_station_sref_script[] = { /* 0x819f26c */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    JUMPIF_EQUAL(PARTNER1_KIND, 0, /* to label */ 0),
    { 0x3b, 0x13,  0x0004,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    SELECT_ENTITIES(-1, 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    SELECT_ENTITIES(-1, 2),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g6_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g6_s0_station_sref_script }; /* 0x819f39c */


static const struct ScriptCommand s_gs9_g6_s1_lives0_dlg0[] = { /* 0x819f3a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We did good today.#W\nLet's knock off and call it a night.")),
    VARIANT(/* == */  1, _(" See you tomorrow!")),
    VARIANT_DEFAULT(_(" Didn't we do good today?#W\nLet's call it a night and get some rest.")),
    VARIANT_DEFAULT(_(" OK, see you tomorrow!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g6_s1_lives1_dlg0[] = { /* 0x819f554 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g6_s2_lives0_dlg0[] = { /* 0x819f594 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("That was good work today.\nI should get some rest.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g7_s0_station_sref_script[] = { /* 0x819f668 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    JUMPIF_SCENARIOCHECK(8, /* to label */ 0),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 1),
  LABEL(1), /* = 0x01 */
    SELECT_EVENTS(0, 0),
    CALL_STATION(  4,  0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_STATION(  8,  0),
    RET,
};

static const struct ScriptRef s_gs9_g7_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g7_s0_station_sref_script }; /* 0x819f7b8 */

static const struct ScriptCommand s_gs9_g7_s0_lives0_dlg0[] = { /* 0x819f7c4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Good morning, $n0.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g7_s0_lives1_dlg0[] = { /* 0x819f854 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g7_s1_lives0_dlg0[] = { /* 0x819f894 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g8_s0_station_sref_script[] = { /* 0x819f8f4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0x3b, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs9_g8_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g8_s0_station_sref_script }; /* 0x819f9a4 */

static const struct ScriptCommand s_gs9_g8_s0_lives0_dlg0[] = { /* 0x819f9b0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g8_s0_lives1_dlg0[] = { /* 0x819fa40 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g9_s0_lives0_dlg2[] = { /* 0x819fac0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 1-2\n\"Team Flag\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB1, 31,  1),
    { 0xae, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    CANCEL_ENTITIES(9, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g10_s0_lives0_dlg2[] = { /* 0x819fbf0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 3\n\"Meteor Cave\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S03E01A_L001),
    HALT,
};


static const struct ScriptCommand s_gs9_g11_s0_lives0_dlg2[] = { /* 0x819fcfc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 4\n\"Rainbow Wing\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 38,  1),
    CANCEL_ENTITIES(11, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g12_s0_lives0_dlg2[] = { /* 0x819fe08 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 5\n\"The Toughest Pokémon\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S05E01A_L001),
    HALT,
};


static const struct ScriptCommand s_gs9_g13_s0_lives0_dlg2[] = { /* 0x819ff1c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 6\n\"Latios and Latias\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S06E01A_L001),
    HALT,
};


static const struct ScriptCommand s_gs9_g14_s0_lives0_dlg2[] = { /* 0x81a002c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 1-2\n\"Buried Relic\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    SCENARIO_CALC(SCENARIO_SUB7, 49,  1),
    { 0xae, 0x01,  0x001b,  0x00000000,  0x00000000, NULL },
    CANCEL_ENTITIES(14, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g15_s0_lives0_dlg2[] = { /* 0x81a013c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 8\n\"Wish Cave\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S08E01A_L001),
    CANCEL_ENTITIES(15, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g16_s0_lives0_dlg2[] = { /* 0x81a0244 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3( TRUE, /*default*/ 0, /* speaker */ -1, _("Trigger sub-scenario 9\n\"Gengar and Gardevoir\"?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S09E01A_L001),
    CANCEL_ENTITIES(16, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g17_s0_station_sref_script[] = { /* 0x81a0358 - PART 1 0:18:53-0:22:13 - First base cutscene */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0004,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    WAIT(60),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And that is how") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+$n0 and $n1\n#+began their careers together") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+as a rescue team.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g17_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g17_s0_station_sref_script }; /* 0x81a0500 */


static const struct ScriptCommand s_gs9_g17_s0_eff0_script[] = { /* 0x81a050c - PART 1 0:18:58-0:19:03 - Possibly the camera scroll? WAIT timing seems to match */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    WAIT(70),
    { 0x6b, 0x00,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g17_s0_lives0_dlg0[] = { /* 0x81a05ac - PART 1 0:18:53-0:22:03 - Player */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000007,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Well, this is the place...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(SMILE_START_FUNC),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(20),
    { 0x2e, 0x15,  0x0000,  0x0000000b,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Wow!)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I can't explain, but I'm happy!)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I'm a human being, but I like this place.\nI feel weirdly happy!)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(It might be an instinct thing for\nPokémon...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Maybe this is what it feels like to want\nto wag your tail...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(It doesn't matter! I'm happy!)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Maybe I feel that way because I'm\n$m0!)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh? $n0.\nI can tell you're impressed.")),
    VARIANT(/* == */  1, _(" I thought you'd like it.\nI figured you'd find this an easy place\nto live, $n0.")),
    VARIANT_DEFAULT(_(" Oh, $n0.\nYou're impressed, aren't you?")),
    VARIANT_DEFAULT(_(" I thought so.\nI thought this would make a good place\nfor you to live, $n0.")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" In fact, I was sure that\nyou'd like it.")),
    VARIANT_DEFAULT(_(" I was sure you would\nlike it.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is your #C5Mailbox#R.#W\nThis is where you'll get mail from\nother Pokémon.")),
    VARIANT_DEFAULT(_(" This is your #C5Mailbox#R.#W\nThey deliver mail from Pokémon here.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You know that fissure\n$n2 fell into?")),
    VARIANT(/* == */  1, _(" There've been other\nnatural disasters like that all of a sudden.")),
    VARIANT(/* == */  1, _(" A lot of Pokémon out there\nare hurting from those disasters.")),
    VARIANT(/* == */  1, _(" I want to help Pokémon like\nthat.")),
    VARIANT(/* == */  1, _(" I want to help make\nthis a safer place for Pokémon.")),
    VARIANT(/* == */  1, _(" And, uh...#W\nI think you're capable after seeing\nhow you did rescuing $n2.")),
    VARIANT(/* == */  1, _(" How would you like to form\na rescue team with me?")),
    VARIANT(/* == */  3, _(" Just like the fissure\n$n2 fell into...")),
    VARIANT(/* == */  3, _(" There have been all sorts\nof natural disasters recently.")),
    VARIANT(/* == */  3, _(" Many Pokémon are suffering\nfrom these natural disasters.")),
    VARIANT(/* == */  3, _(" I want to do good.\nI want to help Pokémon like that.")),
    VARIANT(/* == */  3, _(" I want to help make the\nworld a safer place for Pokémon.")),
    VARIANT(/* == */  3, _(" So, um...#W\nWell, I saw how good you were when\nwe rescued $n2...")),
    VARIANT(/* == */  3, _(" Would you like to form\na rescue team with me?")),
    VARIANT_DEFAULT(_(" You know, just like the\nfissure $n2 fell into...")),
    VARIANT_DEFAULT(_(" For some reason, there have\nbeen many natural disasters lately.")),
    VARIANT_DEFAULT(_(" Because of those disasters,\nmany Pokémon are suffering.")),
    VARIANT_DEFAULT(_(" I want to help Pokémon in\nthese tough times.")),
    VARIANT_DEFAULT(_(" I want to help change things\nso all the Pokémon can live in peace.")),
    VARIANT_DEFAULT(_(" So, uh...#W\nWell, I liked how you handled yourself\nwhen we rescued $n2.")),
    VARIANT_DEFAULT(_(" Would you like to join me\non a rescue team?")),
  LABEL(4), /* = 0x04 */
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" $n0, I think we'd\nmake the world's greatest rescue team.\nHow about it?")),
    VARIANT(/* == */  3, _(" I think we could become\nthe world's number-one rescue team,\n$n0. What do you think?")),
    VARIANT_DEFAULT(_(" $n0, with you,\nI think we could even become the world's\nbest rescue team. How about it?")),
    CHOICE(/* label */  6, _("Form a rescue team.")),
    CHOICE(/* label */  7, _("Refuse.")),
  LABEL(7), /* = 0x07 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    SELECT_LIVES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(30, 1),
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah? Oh, no, come on!")),
    VARIANT(/* == */  3, _(" Huh?! Oh, no, please!")),
    VARIANT_DEFAULT(_(" Huh?! Oh, but...")),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0, I'm positive\nwe'd make a first-class rescue team!")),
    VARIANT(/* == */  3, _(" But, $n0!\nI'm sure that we would make a first-class\nrescue team together!")),
    VARIANT_DEFAULT(_(" $n0, I'm sure\nthat the two of us would make a\nfirst-class rescue team.")),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" So come on, I'm begging you.\nLet's form a rescue team, you and me.")),
    VARIANT(/* == */  3, _(" Please?\nWill you please form a rescue team\nwith me?")),
    VARIANT_DEFAULT(_(" So, come on now.\nLet's form a rescue team together.")),
    CHOICE(/* label */  6, _("Form a rescue team.")),
    CHOICE(/* label */  7, _("Refuse.")),
    JUMP_LABEL(4),
  LABEL(6), /* = 0x06 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    SELECT_LIVES(-1, 3),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK! That's done it!")),
    VARIANT(/* == */  1, _(" Starting right now, me and\nyou, $n0, we're partners in\nour rescue team! I'm counting on you!")),
    VARIANT(/* == */  3, _(" OK! Done deal!")),
    VARIANT(/* == */  3, _(" From now on, $n0,\nwe're partners in our rescue team!\nI'm so glad you joined!")),
    VARIANT_DEFAULT(_(" Perfect! That's it, then!")),
    VARIANT_DEFAULT(_(" We're partners in our\nrescue team from now on, $n0!\nGlad to have you on board!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" The team's name...\nActually, I haven't thought of one yet.")),
    VARIANT(/* == */  1, _(" Hey, $n0.\nWhat do you think would be a good name?")),
    VARIANT(/* == */  3, _(" The team's name is...\nI haven't decided on one.")),
    VARIANT(/* == */  3, _(" Listen, $n0.\nWhat would be a good name for us?")),
    VARIANT_DEFAULT(_(" The team name...\nWell, I don't have one yet.")),
    VARIANT_DEFAULT(_(" So, $n0.\nWhat do you think would be a good\nname for us?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xb0, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  3,  0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x39,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" #C5$t#R!#W\nYeah... That's a good name! It suits us!")),
    VARIANT_DEFAULT(_(" #C5$t#R!#W\nI like it! It's a good name!\nIt's perfect for us!")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Rescue Team\n#C5$t#R!#W\nWe begin tomorrow! Let's do it!")),
    VARIANT_DEFAULT(_(" Rescue Team\n$t#R!#W\nLet's do good starting tomorrow!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x06,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};










static const struct ScriptCommand s_gs9_g17_s0_lives1_dlg0[] = { /* 0x81a1e94 - PART 1 0:18:53-0:20:11 - Partner */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x0000000a,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xda, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    { 0xf2, 0x00,  0x0039,  0x00000000,  0x00000000, _("SWITCH MENU RESULT CANCEL\n") },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0xf2, 0x00,  0x0039,  0x00000000,  0x00000000, _("SWITCH MENU RESULT 1\n") },
    HALT,
  LABEL(1), /* = 0x01 */
    { 0xf2, 0x00,  0x0039,  0x00000000,  0x00000000, _("SWITCH MENU RESULT 2\n") },
    HALT,
};

static const struct ScriptCommand s_gs9_g17_s2_lives0_dlg0[] = { /* 0x81a20f0 - PART 1 0:20:11-0:20:39 - Partner - refused Rescue Team question */
    DEBUGINFO,
    BGM_FADEOUT(5),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    FANFARE_PLAY2(473),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(60),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g17_s3_lives0_dlg0[] = { /* 0x81a21b0 - PART 1 0:20:40-0:22:03 - Partner - accepted Rescue Team question */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g18_s0_station_sref_script[] = { /* 0x81a22b0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION( 19,  0),
    RET,
};

static const struct ScriptRef s_gs9_g18_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g18_s0_station_sref_script }; /* 0x81a2390 */

static const struct ScriptCommand s_gs9_g18_s0_eff0_script[] = { /* 0x81a239c */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g18_s0_lives0_dlg0[] = { /* 0x81a23fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000003c,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x0000003f,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...Hunh?! Oh, no!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(468),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hahaha, sorry!#W\nI was so excited, I've been waiting out\nhere since dawn...")),
    VARIANT(/* == */  1, _(" I guess I just fell asleep!")),
    VARIANT(/* == */  3, _(" Ahaha, sorry!#W\nI was so excited about today, I've been\nwaiting here since dawn...")),
    VARIANT(/* == */  3, _(" I must have fallen asleep.")),
    VARIANT_DEFAULT(_(" Hahaha, sorry!#W\nI was so excited, I came out here at\ndawn to wait for you.")),
    VARIANT_DEFAULT(_(" I must have snoozed off.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Anyway...#W\nOur rescue team officially begins!\nLet's do this right!")),
    VARIANT_DEFAULT(_(" Anyway...#W\nToday marks the start of our rescue team!\nLet's always do our best!")),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ......")),
    VARIANT_DEFAULT(_(" ......")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............")),
    VARIANT_DEFAULT(_(" ............")),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...So, anyway...\nWe don't have any job offers yet...\nHahahaha...")),
    VARIANT_DEFAULT(_(" ...But, anyway...\nWe don't have any job offers yet...\nHahahaha...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, yeah!#W\nMaybe there's something in the Mailbox...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x6b, 0x00,  0x0100,  0x0000000e,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x3b, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n1 checked the Mailbox.") },
    FANFARE_PLAY(213),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The Mailbox contained\n#+a #C5Rescue Team Starter Set#R!") },
    { 0xe1, 0x00,  0x00d5,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I knew it'd be there!#W\nIt's the #C5Rescue Team Starter Set#R!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You always get one when\nyou start a rescue team.")),
    VARIANT_DEFAULT(_(" They always give you one\nif you start a rescue team.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n1 opened\n#+the #C5Rescue Team Starter Set#R.") },
    FANFARE_PLAY(213),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There was\n#+a #C5Rescue Team Badge#R inside!") },
    { 0xe1, 0x00,  0x00d5,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(213),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There was a #C5Toolbox#R inside!") },
    { 0xe1, 0x00,  0x00d5,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(213),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There was also an issue of\n#+#C5Pokémon News#R inside!") },
    { 0xe1, 0x00,  0x00d5,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yeah!#W\nThere's all sorts of good stuff in it!")),
    VARIANT_DEFAULT(_(" Yes!#W\nThere are some good things here!")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This #C5Rescue Team Badge#R...#W\nIt's proof that you're in a rescue team.")),
    VARIANT(/* == */  1, _(" This #C5Toolbox#R too...#W\nYou can use it for keeping items that you\nfind in dungeons.")),
    VARIANT(/* == */  1, _(" I'll put the stuff that\nButterfree gave us in here.\nMight as well put it to good use.")),
    VARIANT(/* == */  1, _(" But items are really useful.\nLet's use them on our adventures.")),
    VARIANT(/* == */  1, _(" And we have here a copy of\nthe #C5Pokémon News#R.#W\nIt has useful information for rescuers.")),
    VARIANT(/* == */  1, _(" I'll leave the #C5Pokémon News#R\nin the Mailbox.\nYou should read it later.")),
    VARIANT_DEFAULT(_(" First off,\nthe #C5Rescue Team Badge#R.#W\nIt shows that we're a rescue team.")),
    VARIANT_DEFAULT(_(" This is a #C5Toolbox#R.#W\nYou use it for carrying items you find in\ndungeons.")),
    VARIANT_DEFAULT(_(" Let's put the stuff\nButterfree gave us in here for now.")),
    VARIANT_DEFAULT(_(" Items are very useful,\nso let's use them on our adventures.")),
    VARIANT_DEFAULT(_(" And finally, a copy of\nthe #C5Pokémon News#R.#W\nIt's useful for rescue teams.")),
    VARIANT_DEFAULT(_(" I'll put the #C5Pokémon News#R\nin the Mailbox.\nYou should read it later on.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" And, let's see...#W\nIs there any other mail...?#W\nDid we miss anything?")),
    VARIANT_DEFAULT(_(" Anything else?#W\nIs there any other mail...?#W\nMaybe not?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n1 checked the Mailbox.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But the Mailbox was empty.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" OK, so there isn't any\nmail for us after all...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If there were any rescue\njobs, we would be getting mail, but...") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I guess no one knows us\nbecause we just started this team.\nHahaha...")),
    VARIANT_DEFAULT(_(" Nobody knows about us\nsince we're so new a team, I guess.\nHahaha...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    FANFARE_PLAY2(451),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh? What's up?")),
    VARIANT_DEFAULT(_(" Oh?\nI wonder what it could be.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};










static const struct ScriptCommand s_gs9_g18_s0_lives1_dlg0[] = { /* 0x81a3a10 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(482),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    { 0x93, 0x08,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000c,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000c,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000d,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000d,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000c,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000c,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000b,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000000b,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x04,  0x000a,  0x0000000f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g18_s0_lives2_dlg0[] = { /* 0x81a3ef0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(501),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Clunk!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g19_s0_station_sref_script[] = { /* 0x81a40b0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g19_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g19_s0_station_sref_script }; /* 0x81a40e0 */

static const struct ScriptCommand s_gs9_g19_s0_lives0_dlg0[] = { /* 0x81a40ec */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g19_s0_lives0_dlg2[] = { /* 0x81a411c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Maybe this is it...")),
    VARIANT(/* == */  1, _(" $n0, how about\nchecking your Mailbox?")),
    VARIANT_DEFAULT(_(" Could this be...?")),
    VARIANT_DEFAULT(_(" $n0, will you\ncheck the Mailbox, please?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g19_s0_obj0_dlg2[] = { /* 0x81a4254 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CJUMP_DIR_TO_LINK(0),
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 checked the Mailbox.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_STATION(-1, 20, 0),
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There is a warning tag\n#+on the side of the Mailbox.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+- Open the Mailbox at the front -") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g19_s0_evt0_sref_script[] = { /* 0x81a4350 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 19, 1),
    HALT,
};

static const struct ScriptRef s_gs9_g19_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g19_s0_evt0_sref_script }; /* 0x81a4380 */

static const struct ScriptCommand s_gs9_g19_s1_station_sref_script[] = { /* 0x81a438c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    CANCEL_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs9_g19_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g19_s1_station_sref_script }; /* 0x81a43ec */

static const struct ScriptCommand s_gs9_g19_s1_lives0_dlg0[] = { /* 0x81a43f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0, aren't\nyou going to check the Mailbox?")),
    VARIANT_DEFAULT(_(" $n0, please check\nthe Mailbox.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g19_s1_lives1_dlg0[] = { /* 0x81a4504 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g19_s1_lives1_dlg2[] = { /* 0x81a4574 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Oh, hey!\nAre you all ready to roll?")),
    VARIANT_DEFAULT(_(" OK!\nAre you all ready?")),
    CHOICE(/* label */  1, _("All set!")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, all right.\nI'll wait here until you're ready.")),
    VARIANT(/* == */  1, _(" Give me a shout when you're\nready.\nWe'll get going then.")),
    VARIANT_DEFAULT(_(" Oh, OK.\nI'll wait until you're all set.")),
    VARIANT_DEFAULT(_(" Tell me when you're\nready.#W\nWe'll leave right away then.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    EXECUTE_FUNCTION(EVENT_M01E07A_L002),
    HALT,
};


static const struct ScriptCommand s_gs9_g20_s0_station_sref_script[] = { /* 0x81a47dc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xaf, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  3,  6),
    { 0x04, 0x00,  0x001e,  0x00000001,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g20_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g20_s0_station_sref_script }; /* 0x81a484c */

static const struct ScriptCommand s_gs9_g20_s0_eff0_script[] = { /* 0x81a4858 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g20_s0_lives0_dlg0[] = { /* 0x81a48c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000036,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000003c,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x0000003f,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Maybe it's a rescue job\nrequest?!#W\nCome on, what's it say?")),
    VARIANT_DEFAULT(_(" Maybe it's a rescue job\noffer!#W\nWhat does it say?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x1e,  0x0000,  0x00000022,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 read the letter.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("“BZZ BZZ BZZ!") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  I HEARD ABOUT YOU FROM CATERPIE.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  PLEASE. WE NEED YOUR HELP.\n  MAGNEMITE IS IN TROUBLE.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  A STRANGE ELECTROMAGNETIC WAVE\n  FLOWED THROUGH A DUNGEON...") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  AND IT STUCK TOGETHER MAGNEMITE\n  AND MAGNEMITE...") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  THAT ISN'T ENOUGH TO FORM\n  A MAGNETON. IT'S NOT COMPLETE\n  THE WAY IT IS NOW.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  PLEASE. WE NEED HELP. BZZ BZZ BZZ.\n\n  FROM MAGNEMITE'S FRIEND”") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" What do you think?\nShould we go for it?")),
    VARIANT_DEFAULT(_(" What do you think?\nDo you think we should go?")),
    CHOICE(/* label */  3, _("Yes! Let's go!")),
    CHOICE(/* label */  4, _("Let's not go.")),
  LABEL(4), /* = 0x04 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_STOP,
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_SWITCH(1),
    WAIT(30),
    { 0x2e, 0x0f,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah? Why?")),
    VARIANT_DEFAULT(_(" Huh? Why?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" It's our very first job?\nLet's do it!")),
    VARIANT_DEFAULT(_(" It's our first job!\nLet's go!")),
    CHOICE(/* label */  3, _("Yes! Let's go!")),
    CHOICE(/* label */  4, _("Let's not go.")),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's what I want to hear!\nLet's do this right!")),
    VARIANT_DEFAULT(_(" That's the spirit!\nLet's do our best!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs9_g20_s0_lives1_dlg0[] = { /* 0x81a50ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g20_s1_lives0_dlg0[] = { /* 0x81a512c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(473),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g20_s2_lives0_dlg0[] = { /* 0x81a51fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g21_s0_station_sref_script[] = { /* 0x81a529c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g21_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g21_s0_station_sref_script }; /* 0x81a536c */

static const struct ScriptCommand s_gs9_g21_s0_lives0_dlg0[] = { /* 0x81a5378 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000003c,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Morning, $n0.") },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We sure loused up on\n$n2's rescue yesterday.")),
    VARIANT_DEFAULT(_(" We failed $n2's\nrescue badly yesterday, didn't we?")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's get it done right today!")),
    VARIANT_DEFAULT(_(" Let's try to get it right\ntoday!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g21_s0_lives1_dlg0[] = { /* 0x81a55ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000060, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g22_s0_station_sref_script[] = { /* 0x81a564c */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g22_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g22_s0_station_sref_script }; /* 0x81a566c */

static const struct ScriptCommand s_gs9_g22_s1_station_sref_script[] = { /* 0x81a5678 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET,
};

static const struct ScriptRef s_gs9_g22_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g22_s1_station_sref_script }; /* 0x81a56a8 */

static const struct ScriptCommand s_gs9_g22_s1_lives0_dlg0[] = { /* 0x81a56b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0!\nThe dungeon isn't that way.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" #CDThunderwave Cave#R is\nover this way!")),
    VARIANT_DEFAULT(_(" #CDThunderwave Cave#R is \nout this way.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's go rescue Magnemite\nalready!")),
    VARIANT_DEFAULT(_(" We have to hurry.\nMagnemite's waiting to be rescued!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g22_s1_lives1_dlg0[] = { /* 0x81a5930 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x08,  0x000a,  0x00000011,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g22_s2_station_sref_script[] = { /* 0x81a5a40 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET,
};

static const struct ScriptRef s_gs9_g22_s2_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g22_s2_station_sref_script }; /* 0x81a5a70 */

static const struct ScriptCommand s_gs9_g22_s2_lives0_dlg0[] = { /* 0x81a5a7c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0!\nThe dungeon isn't that way.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" #CDThunderwave Cave#R is\nover this way!")),
    VARIANT_DEFAULT(_(" #CDThunderwave Cave#R is \nout this way.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's go rescue Magnemite\nalready!")),
    VARIANT_DEFAULT(_(" We have to hurry.\nMagnemite's waiting to be rescued!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g22_s2_lives1_dlg0[] = { /* 0x81a5c1c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x95, 0x08,  0x000a,  0x00000011,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g23_s0_station_sref_script[] = { /* 0x81a5d2c */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g23_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g23_s0_station_sref_script }; /* 0x81a5dcc */

static const struct ScriptCommand s_gs9_g23_s0_lives0_dlg0[] = { /* 0x81a5dd8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Boy, I'm sure glad our\nrescue went well today.")),
    VARIANT(/* == */  3, _(" I'm so glad our rescue\nmission went so well today.")),
    VARIANT_DEFAULT(_(" I'm glad our rescue mission\nwent well today.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I have to admit, since\nthat was our first job as a rescue team...")),
    VARIANT(/* == */  1, _(" I was really nervous.")),
    VARIANT(/* == */  1, _(" I'm wiped out.\nI'll go home and get some sleep.")),
    VARIANT(/* == */  1, _(" Let's do this again\ntomorrow.\nSee you.")),
    VARIANT(/* == */  3, _(" I need to confess.\nSince that was our first job as a rescue\nteam...")),
    VARIANT(/* == */  3, _(" I was really, really nervous.")),
    VARIANT(/* == */  3, _(" I can't believe how tired\nI am.\nI'm going to go home and get some sleep.")),
    VARIANT(/* == */  3, _(" Let's do good again\ntomorrow.\nSee you!")),
    VARIANT_DEFAULT(_(" Actually, since this was our\nfirst job as a proper rescue team...")),
    VARIANT_DEFAULT(_(" I was really tense and\nnervous.")),
    VARIANT_DEFAULT(_(" I'm exhausted now.\nI've got to go get some sleep.")),
    VARIANT_DEFAULT(_(" Let's keep up our good work\ntomorrow.\nSee you.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x0a,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g23_s0_lives1_dlg0[] = { /* 0x81a62e8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000012,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g24_s0_station_sref_script[] = { /* 0x81a6348 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g24_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g24_s0_station_sref_script }; /* 0x81a6378 */

static const struct ScriptCommand s_gs9_g24_s0_obj0_dlg2[] = { /* 0x81a6384 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CJUMP_DIR_TO_LINK(0),
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 checked the Mailbox.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But there was no mail seeking\n#+help from the rescue team.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_STATION(-1, 25, 0),
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There is a warning tag\n#+on the side of the Mailbox.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+- Open the Mailbox at the front -") },
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g24_s0_evt0_sref_script[] = { /* 0x81a64b4 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 24, 1),
    HALT,
};

static const struct ScriptRef s_gs9_g24_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g24_s0_evt0_sref_script }; /* 0x81a64e4 */

static const struct ScriptCommand s_gs9_g24_s1_station_sref_script[] = { /* 0x81a64f0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    CANCEL_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs9_g24_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g24_s1_station_sref_script }; /* 0x81a6550 */

static const struct ScriptCommand s_gs9_g24_s1_lives0_dlg0[] = { /* 0x81a655c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oops!#W\nI'd better check the Mailbox.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g25_s0_station_sref_script[] = { /* 0x81a6614 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_M01E02B_L002),
    RET,
};

static const struct ScriptRef s_gs9_g25_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g25_s0_station_sref_script }; /* 0x81a6684 */

static const struct ScriptCommand s_gs9_g25_s0_eff0_script[] = { /* 0x81a6690 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g25_s0_lives0_dlg0[] = { /* 0x81a6700 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nYou're up early.")),
    VARIANT_DEFAULT(_(" Good morning, $n0!\nAren't you up early?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh!\nYou checked the Mailbox, did you?")),
    VARIANT_DEFAULT(_(" Oh!\nSo, you checked the Mailbox.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...So, what's the word?\nWere there any rescue jobs for us?")),
    VARIANT_DEFAULT(_(" ...So, was there anything?\nWere there any rescue requests?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?\nIt was empty?!")),
    VARIANT_DEFAULT(_(" Huh?\nEmpty?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Awww...\nWell, I guess so.")),
    VARIANT(/* == */  1, _(" After all, we only just\nstarted up...")),
    VARIANT(/* == */  3, _(" Hmm...\nI guess so.")),
    VARIANT(/* == */  3, _(" After all, we've only just\nbegun.")),
    VARIANT_DEFAULT(_(" Hmm...\nI suppose so.")),
    VARIANT_DEFAULT(_(" We've only started, after\nall.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, no point moping.\nLet's go check Pokémon Square.")),
    VARIANT(/* == */  1, _(" I think there will be jobs\nposted at the #C5Pelipper Post Office#R.")),
    VARIANT(/* == */  1, _(" Pokémon Square's over\nthis way.\nLet's go.")),
    VARIANT(/* == */  3, _(" Oh, well.\nWe should go to Pokémon Square.")),
    VARIANT(/* == */  3, _(" We should check the\n#C5Pelipper#R #C5Post Office#R.\nI think they'll have jobs posted.")),
    VARIANT(/* == */  3, _(" Pokémon Square is over\nhere.\nLet's go.")),
    VARIANT_DEFAULT(_(" Well, too bad.\nWant to go to Pokémon Square?")),
    VARIANT_DEFAULT(_(" I think if we go to the\n#C5Pelipper#R #C5Post Office#R, there'll be jobs\nposted.")),
    VARIANT_DEFAULT(_(" Pokémon Square's over\nthis way.\nLet's go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(150),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x000000a0,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g25_s0_lives1_dlg0[] = { /* 0x81a6f34 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000013,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000015,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x000000a0,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g26_s0_station_sref_script[] = { /* 0x81a7064 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g26_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g26_s0_station_sref_script }; /* 0x81a7134 */

static const struct ScriptCommand s_gs9_g26_s0_lives0_dlg0[] = { /* 0x81a7140 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!")),
    VARIANT_DEFAULT(_(" Good morning, $n0!")),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#WHah?!")),
    VARIANT_DEFAULT(_(" ............#WHuh?!")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Someone just asked you to\ngo out on a rescue?")),
    VARIANT_DEFAULT(_(" You were just asked to go\non a rescue mission?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Yes!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000004, NULL },
    WAIT(60),
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Our child, $n3,\nwas kidnapped!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" He was taken to #CDMt. Steel#R's\nsummit!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please, we need your help!#W\nBye-bye!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...#WI see...#W\nI guess we'd better go...")),
    VARIANT_DEFAULT(_(" ...#WUh, OK...#W\nLet's go...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g26_s0_lives1_dlg0[] = { /* 0x81a7614 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000060, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g26_s1_lives0_dlg0[] = { /* 0x81a7744 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g27_s0_station_sref_script[] = { /* 0x81a7834 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g27_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g27_s0_station_sref_script }; /* 0x81a7904 */

static const struct ScriptCommand s_gs9_g27_s0_lives0_dlg0[] = { /* 0x81a7910 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0.")),
    VARIANT(/* == */  1, _(" We blew it yesterday.\nLet's save that little guy today for sure.")),
    VARIANT_DEFAULT(_(" Good morning, $n0.")),
    VARIANT_DEFAULT(_(" We couldn't do it yesterday,\nso let's be sure to do this rescue today.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g27_s0_lives1_dlg0[] = { /* 0x81a7ab4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000060, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g28_s0_station_sref_script[] = { /* 0x81a7b54 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(103),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g28_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g28_s0_station_sref_script }; /* 0x81a7bf4 */

static const struct ScriptCommand s_gs9_g28_s0_eff0_script[] = { /* 0x81a7c00 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000019,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g28_s0_lives0_dlg0[] = { /* 0x81a7c70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0005,  0x00000043,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ohhh...\nI was very scared.") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Maybe because I was\nsomewhere up so high...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" My feet feel like they're\nstill walking on air...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" (Feet...?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0f,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" (HE HAS THEM? FEET?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, well, you're safe now.\nGood thing, huh?")),
    VARIANT_DEFAULT(_(" Well, you're safe now.\nThat's what counts.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes.\nThank you very much.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Oh! You've been rescued!\nGreat! Great!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah? What was that?#W\nWho said that?")),
    VARIANT_DEFAULT(_(" Huh? What was that?#W\nAm I hearing voices?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Whoops! You can't see us?#W\nThat's terribly rude of us!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hello. $n4 here.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh! Papa!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" $n2!\nYou had us worried!\nYou're not hurt?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Nope!\nIt was scary, but I'm all right.#W\nIt's all thanks to $n0's team.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Thank you for everything.\nYou're heroes.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" If you want to thank\nanyone, thank our $n3 friends.")),
    VARIANT(/* == */  1, _(" We couldn't have done this\nrescue on our own, right?")),
    VARIANT(/* == */  3, _(" Please thank our\n$n3 friends.")),
    VARIANT(/* == */  3, _(" We couldn't have done this\nrescue by ourselves.")),
    VARIANT_DEFAULT(_(" You should be thanking our\n$n3 friends.")),
    VARIANT_DEFAULT(_(" This rescue was impossible\nfor us to do on our own.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Oh, how rude of us!\nThank you so much!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" NO, NO.#W\nIT WAS THE ONLY THING TO DO.#W\nAND...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" HOW BOTH OUR EVOLVED\nFORMS ARE JOINED TRIOS...#W\nI FELT A CERTAIN KINSHIP.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" AFTER ALL, POKéMON MUST\nHELP EACH OTHER.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" I'm impressed.\nSincerely, thank you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0f,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We must be going.\n$n0.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" $n1.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0b,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" Thank you.") },
    { 0x2e, 0x0b,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Farewell!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x3c, 0x2b,  0x0000,  0x00000006,  0x00000001, NULL },
    { 0x3c, 0x2c,  0x0000,  0x00000014,  0x00000001, NULL },
    { 0x3c, 0x2c,  0x0000,  0x00000049,  0x00000001, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(80),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" WE'LL BE ON OUR WAY\nTOO...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wait a sec!\nHold on!")),
    VARIANT_DEFAULT(_(" Oh, wait!\nDon't go away!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" WHAT IS IT?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Listen, um...#W\nHow would you like to join us?")),
    VARIANT(/* == */  3, _(" Um...#W\nWould you like to join our team?")),
    VARIANT_DEFAULT(_(" Uh...#W\nWould you like to join our team?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" JOIN YOUR TEAM?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Yes.#W\nWe couldn't have done the last job\nif you weren't around, $n3.") },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I thought we would need\nmore help for doing rescues in the future.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hey, $n0.\nYou think so too, right?")),
    VARIANT_DEFAULT(_(" $n0, don't you\nthink so too?")),
    CHOICE(/* label */ 27, _("Yes! More members needed!")),
    CHOICE(/* label */ 28, _("We don't need any help.")),
  LABEL(28), /* = 0x1c */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hah? Why?!\nDon't you want more members?")),
    VARIANT_DEFAULT(_(" Huh? Why?!\nDon't you want more members?")),
    CHOICE(/* label */ 29, _("Just joking!")),
    CHOICE(/* label */ 30, _("Two is plenty.")),
  LABEL(29), /* = 0x1d */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sheesh!\nDon't joke around like that!\nIt's not funny!")),
    VARIANT_DEFAULT(_(" Aww, sheesh.\nDon't joke around.\nIt's not funny.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    JUMP_LABEL(27),
  LABEL(30), /* = 0x1e */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we couldn't have saved\nDiglett by ourselves, right?")),
    VARIANT(/* == */  1, _(" If the $n3 pair\nweren't there to airlift Diglett out,\nwe would've been stuck.")),
    VARIANT(/* == */  1, _(" Or, are you trying to tell\nme that you could've pulled off that\nrescue yourself, $n0?")),
    VARIANT(/* == */  3, _(" But we couldn't have\nrescued Diglett on our own.")),
    VARIANT(/* == */  3, _(" If it weren't for the two\n$n3 to fly Diglett out, we\nwould have been stuck.")),
    VARIANT(/* == */  3, _(" Or, $n0, are you\nsaying that you could have done that\nrescue?")),
    VARIANT_DEFAULT(_(" But, you know, we couldn't\nhave rescued Diglett just by ourselves.")),
    VARIANT_DEFAULT(_(" If it weren't for the two\n$n3 that flew Diglett out,\nwe would have been helpless.")),
    VARIANT_DEFAULT(_(" Or, $n0, you're\nsaying that you could have done that\nrescue by yourself?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" $n0, do you have\na special ability that'd let you do that?")),
    VARIANT(/* == */  3, _(" Do you have some special\nability that would make you say that,\n$n0?")),
    VARIANT_DEFAULT(_(" $n0, do you have\nsome special ability that would let\nyou do that?")),
    CHOICE(/* label */ 32, _("My body stretches.")),
    CHOICE(/* label */ 32, _("I can fly.")),
  LABEL(32), /* = 0x20 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Really? You're serious?#W\n...So how about showing me?")),
    VARIANT_DEFAULT(_(" Oh, really?!#W\n...Can you show us?")),
    CHOICE(/* label */ 33, _("Sorry, I can't...")),
    CHOICE(/* label */ 33, _("I just can't...")),
  LABEL(33), /* = 0x21 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What the...?\nWhat, you were just joshing me?!\nSheesh!")),
    VARIANT(/* == */  3, _(" Now, look here!\nWere you just making fun of me?!")),
    VARIANT_DEFAULT(_(" Aww!\nWere you just making fun of me?!\nSheesh!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
  LABEL(27), /* = 0x1b */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, come on! How about it?")),
    VARIANT(/* == */  1, _(" Join our rescue team!\nWhat do you say?")),
    VARIANT(/* == */  3, _(" So, will you?")),
    VARIANT(/* == */  3, _(" Will you join our rescue\nteam?")),
    VARIANT_DEFAULT(_(" So, how about it?")),
    VARIANT_DEFAULT(_(" Will you join us as members\nof our rescue team?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" RESCUE TEAM...#W\nTHAT SOUNDS FUN! BZZ BZZ BZZ!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" ...BUT...IF YOU NEED US\nTO RUSH OVER TO RESCUES...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" WE NEED SOMEWHERE TO\nLIVE CLOSE BY.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" IS THERE ANYWHERE WE\nCAN LIVE IN THIS AREA?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...Ummm...well...") },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" OH...\nTHERE ISN'T...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" TOO BAD.#W\nSORRY, BUT WE CAN'T JOIN YOU.#W\nSEE YOU! BZZ BZZ BZZ!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" That is too bad.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I guess we need somewhere\nPokémon can live if we want them to\njoin the rescue team...")),
    VARIANT_DEFAULT(_(" It looks like we need to\nfind places for Pokémon to live if we\nwant some to join our rescue team...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I know!#W\nLet's go out to #C5Pokémon Square#R\ntomorrow.")),
    VARIANT(/* == */  1, _(" There's this interesting\nshop called the #C5Wigglytuff Club#R.")),
    VARIANT(/* == */  1, _(" It wasn't open the other\nday when we went to the square.#W\nIt might be open tomorrow, though.")),
    VARIANT(/* == */  1, _(" The shop is next to\n#C5Felicity Bank#R.#W\nUsually, #C6Wigglytuff#R is there.")),
    VARIANT(/* == */  1, _(" We might be able to get\nsome useful information there.")),
    VARIANT(/* == */  1, _(" All right, so that's what\nwe'll do tomorrow.#W\nWe'll go down to Pokémon Square.")),
    VARIANT(/* == */  3, _(" Oh, I know!#W\nWe should go out to #C5Pokémon Square#R\ntomorrow.")),
    VARIANT(/* == */  3, _(" There's an interesting\nshop called the #C5Wigglytuff Club#R.")),
    VARIANT(/* == */  3, _(" There wasn't anyone when\nwe went to the square the other day.#W\nIt might be open tomorrow, though.")),
    VARIANT(/* == */  3, _(" The shop is beside\n#C5Felicity Bank#R.#W\n#C6Wigglytuff#R is usually there.")),
    VARIANT(/* == */  3, _(" We might get some useful\ninformation there.")),
    VARIANT(/* == */  3, _(" So that's tomorrow.#W\nWe'll go to Pokémon Square!")),
    VARIANT_DEFAULT(_(" I know!#W\nLet's go out to #C5Pokémon Square#R\ntomorrow.")),
    VARIANT_DEFAULT(_(" There's an interesting\nplace called the #C5Wigglytuff Club#R.")),
    VARIANT_DEFAULT(_(" It wasn't open the other\nday when we went to the square.#W\nIt should be open tomorrow, though.")),
    VARIANT_DEFAULT(_(" It's next door to \n#C5Felicity Bank#R.#W\n#C6Wigglytuff#R is usually there every day.")),
    VARIANT_DEFAULT(_(" We may be able to get\nsome information.")),
    VARIANT_DEFAULT(_(" OK, that's what we'll do\ntomorrow.#W\nWe'll go to Pokémon Square.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

































static const struct ScriptCommand s_gs9_g28_s0_lives1_dlg0[] = { /* 0x81aa778 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    FANFARE_PLAY2(482),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    FANFARE_PLAY2(473),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(472),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g28_s0_lives2_dlg0[] = { /* 0x81aac28 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000044,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g28_s0_lives3_dlg0[] = { /* 0x81aade8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000003c,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6b, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g28_s0_lives4_dlg0[] = { /* 0x81ab198 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT_RANDOM(10, 20),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000003c,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CJUMP_VAR(EVENT_LOCAL),
    COND_EQUAL(0, /* to label */ 0),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000018,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g28_s1_lives0_dlg0[] = { /* 0x81ab488 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x00000042,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g29_s0_station_sref_script[] = { /* 0x81ab648 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g29_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g29_s0_station_sref_script }; /* 0x81ab6c8 */

static const struct ScriptCommand s_gs9_g29_s0_lives0_dlg0[] = { /* 0x81ab6d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000009,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Morning, $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Ahaha!\nWhat's with that dazed and confused look?\nYou look half asleep!")),
    VARIANT_DEFAULT(_(" Ahaha!\nWhat's the matter?\nYou haven't woken up yet?")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Hah?#W\nYou've been having weird dreams?")),
    VARIANT(/* == */  1, _(" What sort of weird\ndreams?")),
    VARIANT_DEFAULT(_(" ...Oh?#W\nYou've been having strange dreams?")),
    VARIANT_DEFAULT(_(" What was strange about\nthem?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 told $n1\n#+about the dreams.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmmm, uh-huh...")),
    VARIANT(/* == */  1, _(" $n0, you said\nyou're really a human, right?")),
    VARIANT(/* == */  1, _(" So I was thinking...")),
    VARIANT(/* == */  1, _(" Maybe those dreams have\nsomething to do with how you became\na Pokémon?")),
    VARIANT_DEFAULT(_(" Hmmm, OK...")),
    VARIANT_DEFAULT(_(" $n0, you said\nyou're actually a human, right?")),
    VARIANT_DEFAULT(_(" So maybe...")),
    VARIANT_DEFAULT(_(" Those dreams have some\nconnection to how you became a Pokémon,\n$n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So let me ask you,\n$n0.\nWhat are you thinking?")),
    VARIANT(/* == */  1, _(" Do you want to go back to\nbeing a human?")),
    VARIANT_DEFAULT(_(" By the way, $n0.\nWhat do you want to do?")),
    VARIANT_DEFAULT(_(" Do you want to turn back\ninto a human?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x2e, 0x0f,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...It's true...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I haven't thought about it much, but...)") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ 0, _("(Do I want to become a human again?)")),
    CHOICE(/* label */  5, _("I'm not sure...")),
    CHOICE(/* label */  6, _("I want to be a human again.")),
  LABEL(6), /* = 0x06 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, OK.")),
    VARIANT_DEFAULT(_(" Oh, OK.")),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I guess that's only natural.")),
    VARIANT(/* == */  1, _(" If you were a human\nto begin with, it's only natural that\nyou'd want to go back to being one.")),
    VARIANT_DEFAULT(_(" Well, I suppose so.")),
    VARIANT_DEFAULT(_(" Since you were a human to\nbegin with, it's only natural that you\nwould want to go back to being one.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, tell me.\nWhat sort of a human being were you,\n$n0?")),
    VARIANT_DEFAULT(_(" Anyway, when you were\na human, what kind of person were you,\n$n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(When I was a human...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Huh? What was I like when I was\na human, anyway...?)") },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe2, 0x00,  0x01d6,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0000,  0x00000005,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(............#W\nNope. I can't remember a thing...)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, wow.\nSo you forgot everything?")),
    VARIANT(/* == */  1, _(" Well, that's all right.\nYou can take your time remembering.")),
    VARIANT(/* == */  1, _(" But you know,\n$n0? I'm positive that you\nwere a good human being.")),
    VARIANT(/* == */  3, _(" Oh, no, you've forgotten?")),
    VARIANT(/* == */  3, _(" It's OK.\nThere's no rush to remember.")),
    VARIANT(/* == */  3, _(" But, $n0?\nI can't picture you as anything but\na good human.")),
    VARIANT_DEFAULT(_(" Oh, wow, you've forgotten?")),
    VARIANT_DEFAULT(_(" That's OK.\nThere's no rush to remember anything.")),
    VARIANT_DEFAULT(_(" But this is you,\n$n0. I'm sure you were a good\nhuman being.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    JUMP_LABEL(9),
  LABEL(5), /* = 0x05 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh? What's wrong?\nYou can't decide?")),
    VARIANT(/* == */  3, _(" Huh? What's the matter?\nHaving trouble deciding?")),
    VARIANT_DEFAULT(_(" Huh? What's wrong?\nIs this a dilemma for you?")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, I guess so!\nIt's a lot more fun hanging around\nwith me!")),
    VARIANT(/* == */  3, _(" Well, maybe so.\nIt must be more fun for you to be\nhere with me!")),
    VARIANT_DEFAULT(_(" Well, I hope so!\nIt sure must be more fun to be here\nwith me!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(60),
  LABEL(9), /* = 0x09 */
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Anyway, I promised we'd\ngo to Pokémon Square today.")),
    VARIANT(/* == */  1, _(" Remember?\nWe're supposed to go ask about how we\ncan add members to our team.")),
    VARIANT(/* == */  1, _(" Let's roll, already.")),
    VARIANT_DEFAULT(_(" Anyway, we were supposed\nto go to Pokémon Square today.")),
    VARIANT_DEFAULT(_(" Do you remember?\nWe need to get information on how we\ncan add members to the rescue team.")),
    VARIANT_DEFAULT(_(" Let's get going.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001b,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs9_g29_s0_lives1_dlg0[] = { /* 0x81aca18 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001a,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001b,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g30_s0_station_sref_script[] = { /* 0x81acb68 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(60, 1),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g30_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g30_s0_station_sref_script }; /* 0x81acc48 */

static const struct ScriptCommand s_gs9_g30_s0_eff0_script[] = { /* 0x81acc54 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x3c,  0x0180,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001d,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g30_s0_lives0_dlg0[] = { /* 0x81acd04 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning!\nLet's keep up our good work today!")),
    VARIANT_DEFAULT(_(" Good morning!\nLet's do good again today!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Is this the place?\nWhere that team named #C5$t#R\nis based?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_SWITCH(10),
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" There's nothing here.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Depressing, isn't it.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x05,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000000, -0x00000003, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!\nWho'd run a rescue team from a dump\nlike this? Unbelievable.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's with you?")),
    VARIANT_DEFAULT(_(" Who are you people?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Oh!#W\nOver there. A Mailbox〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x0000005b,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kekeh, yeah!\nCheck it out!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whoa, hey!\nWhat do you think you're doing?")),
    VARIANT_DEFAULT(_(" Now wait a second!\nWhat do you think you're doing?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Yessss!\nRescue job offers!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Oo-la-la!\nIsn't that rather tasty〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0f,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We'll have them all.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey!#W\nThose rescue jobs were meant for us!")),
    VARIANT(/* == */  1, _(" Don't butt in!")),
    VARIANT(/* == */  3, _(" Wait a second!#W\nThose belong to us!")),
    VARIANT(/* == */  3, _(" Don't butt in!")),
    VARIANT_DEFAULT(_(" Stop!#W\nThose were meant for us!")),
    VARIANT_DEFAULT(_(" Don't butt in!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!#W\nIt doesn't matter who does it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000043,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We're a rescue team too,\nI'll have you know〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0003,  0x00000042,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" ...But all we ever get up\nto is no good.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wanna know how it works?#W\nIf we have the cover of a rescue team,\nwe can get away with so much more!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000043,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We have our eyes on\nworld domination〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wha...#W\nWorld domination?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kekeh!\nYou heard right!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That's why we're raking in\nthe cash and adding to our gang!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The world will be ours!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The rescue team of evil!\nTeam #C5Meanies#R is who we are!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" See you around!\nKekeh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! Wait!")),
    VARIANT_DEFAULT(_(" Now wait a second!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...They took off.#W\nWhat a bunch of creeps.")),
    VARIANT(/* == */  3, _(" ...They're gone.#W\nWhat a horrible bunch.")),
    VARIANT_DEFAULT(_(" ...They took off.#W\nWhat an unbelievable bunch.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000006,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wah!\nThis is empty!")),
    VARIANT_DEFAULT(_(" Oh, no!\nIt is empty!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(473),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x6b, 0x00,  0x0200,  0x0000001f,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Those guys cleaned us out!")),
    VARIANT_DEFAULT(_(" They took everything!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x06,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We lucked out!\nPelipper's brought us some more mail!")),
    VARIANT(/* == */  1, _(" We can go back to rescuing.")),
    VARIANT_DEFAULT(_(" We're in luck!\nPelipper delivered some mail!")),
    VARIANT_DEFAULT(_(" We can go on rescue\nmissions again with this.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But those guys...\nThey're not getting away with anything\nthe next time I see them.")),
    VARIANT_DEFAULT(_(" But those guys...\nThey'd better not try anything if we\nsee them again.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x9d, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};





















static const struct ScriptCommand s_gs9_g30_s0_lives1_dlg0[] = { /* 0x81ae20c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001a,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000005, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(1),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe2, 0x00,  0x01c9,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe2, 0x00,  0x01ca,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(473),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(20),
    { 0xe2, 0x00,  0x01d9,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(10),
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x90, 0x01,  0x0000,  0x0000001c,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g30_s0_lives2_dlg0[] = { /* 0x81ae61c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001e,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000001f,  0x00000000, NULL },
    { 0x90, 0x01,  0x0000,  0x0000001c,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000020,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g30_s0_lives3_dlg0[] = { /* 0x81ae78c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000021,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000022,  0x00000000, NULL },
    { 0x90, 0x01,  0x0000,  0x0000001c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000023,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g30_s0_lives4_dlg0[] = { /* 0x81ae8ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000024,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000025,  0x00000000, NULL },
    { 0x90, 0x01,  0x0000,  0x0000001c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000026,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g30_s0_lives5_dlg0[] = { /* 0x81aea0c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    FANFARE_PLAY2(451),
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(501),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Clunk! Clunk!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g31_s0_station_sref_script[] = { /* 0x81aec4c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION( 32,  0),
    BGM_FADEIN(60, 1),
    RET,
};

static const struct ScriptRef s_gs9_g31_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g31_s0_station_sref_script }; /* 0x81aed3c */

static const struct ScriptCommand s_gs9_g31_s0_eff0_script[] = { /* 0x81aed48 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x18,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g31_s0_lives0_dlg0[] = { /* 0x81aee18 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nLet's keep up our good work today!")),
    VARIANT_DEFAULT(_("")),
    VARIANT_DEFAULT(_(" Good morning, $n0!\nLet's do good again today!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" $n0!\n$n1!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hunh? Who's that?")),
    VARIANT_DEFAULT(_(" Huh?\nWho was that?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x84, 0x00,  0x0100,  0x00000010,  0x0000001e, NULL },
    { 0x93, 0x04,  0x000a,  0x00000036,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, if it isn't $n5!\nLong time no see!")),
    VARIANT_DEFAULT(_(" Oh, $n5?\nHow have you been?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" Please!#W\nPlease help my friend!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's wrong?")),
    VARIANT_DEFAULT(_(" What's the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" I was playing with my\nfriend Metapod...") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" But Metapod got lost in the\nwoods...\nHe's still lost out there...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Oh, I see, I see!\nThat does sound bad!\nKekeke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(10),
    WAIT(16),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! Not you again!")),
    VARIANT_DEFAULT(_(" Hey! What do you think\nyou're doing?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Have no fear!\nWe're here to save your chum Metapod.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey!\n$n5 came to us for help!")),
    VARIANT(/* == */  3, _(" Wait a second!\n$n5 was asking us to help!")),
    VARIANT_DEFAULT(_(" Hold on!\n$n5 came to us for help!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!\nYou think you can do this rescue with\nyour amateur-level skills?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What?!")),
    VARIANT_DEFAULT(_(" What did you say?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It doesn't matter who does\nthe rescuing, see?") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The guy that does the\nrescuing gets to be the hero.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Listen, $n5.\nHow about we do this?") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" How about you give the\nreward to the team that brings back your\nchum first?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0f,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" But I...#W\nI don't have any money...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh, don't you worry about\nthat, my little friend!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm sure we can persuade\nyour parents to reward us with interest\nafterward, kekeh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh, yeah.#W\nYou can even join our team.\nThere's an offer you can't refuse.") },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" When you join us, \n$n5, we'll let you be a big wheel\nin Team #C5Meanies#R, kekekeke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That's the deal,\n$n1.\nThe first to rescue wins!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Come on, move!\nLet's get this done, already!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    BGM_FADEOUT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x15,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" ...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Don't worry.\nWe'll save your friend first.")),
    VARIANT(/* == */  3, _(" Don't worry about a thing.\nWe'll rescue your friend first.")),
    VARIANT_DEFAULT(_(" Don't worry.\nWe'll save your friend first.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!#W\nLet's roll, and quick!")),
    VARIANT_DEFAULT(_(" $n0!#W\nLet's get going!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


















static const struct ScriptCommand s_gs9_g31_s0_lives1_dlg0[] = { /* 0x81b002c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000001a,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000003, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000036,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0100, -0x00000008,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000036,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0xe2, 0x00,  0x01c9,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g31_s0_lives2_dlg0[] = { /* 0x81b02dc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x24,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x08,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000020,  0x00000000, NULL },
    WAIT(32),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(28),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g31_s0_lives3_dlg0[] = { /* 0x81b04bc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x24,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000023,  0x00000000, NULL },
    WAIT(60),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g31_s0_lives4_dlg0[] = { /* 0x81b057c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x24,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000026,  0x00000000, NULL },
    WAIT(60),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g31_s0_lives5_dlg0[] = { /* 0x81b063c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000027,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005b,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000004, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g32_s0_station_sref_script[] = { /* 0x81b07ac */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g32_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g32_s0_station_sref_script }; /* 0x81b07dc */

static const struct ScriptCommand s_gs9_g32_s0_lives0_dlg0[] = { /* 0x81b07e8 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g32_s0_lives0_dlg2[] = { /* 0x81b0818 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...What should I do?#W\nI don't have any money, and...") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I don't want to join those\n#C5Meanies#R...") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Please, $n0,\nhelp us...") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g33_s0_station_sref_script[] = { /* 0x81b0924 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g33_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g33_s0_station_sref_script }; /* 0x81b09f4 */

static const struct ScriptCommand s_gs9_g33_s0_lives0_dlg0[] = { /* 0x81b0a00 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0.")),
    VARIANT(/* == */  1, _(" We bungled it yesterday.\nWe've got to get it right today.")),
    VARIANT_DEFAULT(_(" Good morning, $n0.")),
    VARIANT_DEFAULT(_(" We came up short\nyesterday, so let's be sure to do things\nright today.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g33_s0_lives1_dlg0[] = { /* 0x81b0b8c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g34_s0_station_sref_script[] = { /* 0x81b0bec */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(103),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0x23, 0x01,  0x005a,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g34_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g34_s0_station_sref_script }; /* 0x81b0c8c */

static const struct ScriptCommand s_gs9_g34_s0_lives0_dlg0[] = { /* 0x81b0c98 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" This is great!\nWelcome back, $n3!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Thank you, $n2!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" And thank you,\n$n1 and $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But I don't have any money...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's OK, OK!\nWe don't need a reward.")),
    VARIANT_DEFAULT(_(" Oh, no, no.\nWe don't need a reward.")),
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's just great to see\nthat $n3 is back safe and sound.")),
    VARIANT_DEFAULT(_(" We're happy to see that\n$n3 is back safe and sound.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#W\nCool...") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You're even more cool\nthan I thought!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I want to go on rescues\nwhen I grow up!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hahaha!\nThat'd be awesome!\nGo for it!")),
    VARIANT_DEFAULT(_(" Hahaha!\nThat would be great!\nChase that dream!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I have an idea!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0, how about we\ndo something right here?")),
    VARIANT(/* == */  1, _(" Why don't we make\na properly impressive rescue team base?")),
    VARIANT(/* == */  3, _(" $n0, why don't\nwe do something right here??")),
    VARIANT(/* == */  3, _(" We should make a proper\nrescue team base here.\nSomething impressive.")),
    VARIANT_DEFAULT(_(" $n0, we should\ndo something with this place.")),
    VARIANT_DEFAULT(_(" We should make a proper\nrescue team base here.\nSomething impressive.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That's cool!\nA rescue team base is cool!") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(4),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I want to work here when\nI grow up!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Me too! Me too!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Haha!\nThat's settled, then!")),
    VARIANT_DEFAULT(_(" Haha!\nThat's what we'll do!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's make sure we build\nourselves a proper rescue team base!")),
    VARIANT(/* == */  3, _(" Let's be sure to build\nour own rescue team base!")),
    VARIANT_DEFAULT(_(" Let's work hard and build\nour own rescue team base!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" $n0 and\n$n1, thank you again!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" See you around.\nTake care going home!")),
    VARIANT_DEFAULT(_(" OK, bye!\nBe careful going home.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sigh...\nWell, we ended up working for free,\nbut that had to be done.")),
    VARIANT_DEFAULT(_(" Sigh...\nWell, we ended up working for free,\nbut that was the right thing to do.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" And we got to show\nGengar's team a thing or two, so it's all\ngood!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'm just beat today.\nLet's keep up our good work tomorrow!\nSee you!")),
    VARIANT_DEFAULT(_(" That was a tiring day.#W\nLet's do some more good tomorrow!\nSee you!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};












static const struct ScriptCommand s_gs9_g34_s0_lives1_dlg0[] = { /* 0x81b1da4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_STOP2(465),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g34_s0_lives2_dlg0[] = { /* 0x81b2054 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005e,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_STOP2(470),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(20),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(5),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000028,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g34_s0_lives3_dlg0[] = { /* 0x81b2384 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000036,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000028,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g35_s0_station_sref_script[] = { /* 0x81b24b4 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g35_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g35_s0_station_sref_script }; /* 0x81b2534 */

static const struct ScriptCommand s_gs9_g35_s0_lives0_dlg0[] = { /* 0x81b2540 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0, morning!\nLet's keep up our good work today!")),
    VARIANT_DEFAULT(_(" $n0, good morning!\nLet's do good again today!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Umm... Hello?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh? Who could that be?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Umm... Is rescue team\n#C5$t#R here?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" That's right...#W Huh?#W\nWait, aren't you...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs9_g35_s1_lives0_dlg0[] = { /* 0x81b2854 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000002b,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(70),
    { 0x86, 0x00,  0x00cc,  0x0000002c,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g35_s2_lives0_dlg0[] = { /* 0x81b2944 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6b, 0x00,  0x0100,  0x0000002d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g36_s0_station_sref_script[] = { /* 0x81b29c4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    SELECT_EVENTS(0, 0),
    CALL_STATION( 37,  0),
    RET,
};

static const struct ScriptRef s_gs9_g36_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g36_s0_station_sref_script }; /* 0x81b2aa4 */

static const struct ScriptCommand s_gs9_g36_s0_lives0_dlg0[] = { /* 0x81b2ab0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000055,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I remember now!#W\nYou're the $n2 in Pokémon\nSquare.")),
    VARIANT(/* == */  1, _(" We saw $n3's\nteam accepting your rescue job.")),
    VARIANT(/* == */  3, _(" I remember!#W\nYou're the $n2 in Pokémon\nSquare.")),
    VARIANT(/* == */  3, _(" We saw $n3\nagreeing to do your rescue job.")),
    VARIANT_DEFAULT(_(" I remember now!#W\n$n2, we saw you in Pokémon\nSquare.")),
    VARIANT_DEFAULT(_(" We watched $n3\nagreeing to take on your rescue job.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes.#W\nBut, $n3...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" He hasn't come back yet\nfrom the rescue mission.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    BGM_SWITCH(9),
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Are you serious?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Our friend $n2 got\nwedged between some rocks.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We $n2 can go\nanywhere if we can catch a wind, but...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Even though the skies are\nfilled with thunderclouds, for some\nodd reason, the winds haven't blown.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(469),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Not even a breeze?#W\nThat is strange...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0002,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" $n3's leafy fans\ncan whip up powerful winds.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We thought $n3's\nwind would be able to dislodge our friend,\nbut...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But $n3 hasn't\ncome back...")),
    VARIANT(/* == */  1, _(" It doesn't sound like that\ntough of a rescue...#W\nThat is weird...")),
    VARIANT_DEFAULT(_(" But $n3 hasn't\nreturned...?")),
    VARIANT_DEFAULT(_(" It doesn't sound like all\nthat challenging of a rescue mission...#W\nIt is strange...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    WAIT(150),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x0c,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(40),
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh?#W\nThat's the spirit, $n0.#W\nYour look says you won't need to be asked.")),
    VARIANT_DEFAULT(_(" Oh?#W That's the spirit,\n$n0.#W\nYour expression tells me you're ready.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's it, then!\nWe'll go look for them!")),
    VARIANT(/* == */  3, _(" OK!\nWe'll go look for them!")),
    VARIANT_DEFAULT(_(" OK, then!\nWe'll go look for them!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" R-really?\nThank you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Leave it to us!")),
    VARIANT_DEFAULT(_(" No problem!\nYou can count on us!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's get to it,\n$n0!")),
    VARIANT_DEFAULT(_(" Let's go, $n0!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};










static const struct ScriptCommand s_gs9_g36_s0_lives1_dlg0[] = { /* 0x81b3680 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g36_s0_lives2_dlg0[] = { /* 0x81b37f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g37_s0_station_sref_script[] = { /* 0x81b38a0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g37_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g37_s0_station_sref_script }; /* 0x81b38d0 */

static const struct ScriptCommand s_gs9_g37_s0_lives0_dlg0[] = { /* 0x81b38dc */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g37_s0_lives0_dlg2[] = { /* 0x81b390c */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" My friend is stuck in\na place called #CDSilent Chasm#R.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I hate to burden you,\nbut you're our only hope...") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g38_s0_station_sref_script[] = { /* 0x81b39f0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g38_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g38_s0_station_sref_script }; /* 0x81b3ac0 */

static const struct ScriptCommand s_gs9_g38_s0_lives0_dlg0[] = { /* 0x81b3acc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning!#W\nLet's try to get things right today!")),
    VARIANT_DEFAULT(_(" Good morning!#W\nLet's do our best like always!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g38_s0_lives1_dlg0[] = { /* 0x81b3c24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g39_s0_station_sref_script[] = { /* 0x81b3c84 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g39_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g39_s0_station_sref_script }; /* 0x81b3d24 */

static const struct ScriptCommand s_gs9_g39_s0_eff0_script[] = { /* 0x81b3d30 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x24,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x1e,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g39_s0_lives0_dlg0[] = { /* 0x81b3de0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yay! Saved!\nI'm so happy!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" But even though I'm safe,\nShiftry is in trouble...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Tell us.\nWhat went down, exactly?")),
    VARIANT_DEFAULT(_(" Please tell us.\nExactly what happened?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" ...Yes...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Shiftry whipped up winds\nwith his fans...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" And released me from\nbetween the rocks.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" But those winds tore\na thundercloud in two...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" And that was when that\nmonster appeared in the sky.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That monster...#W\nIt said it was Zapdos or something.")),
    VARIANT_DEFAULT(_(" That monster...#W\nIt said it was Zapdos...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    BGM_FADEOUT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Did you say Zapdos?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(466),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n4!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(64),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    BGM_SWITCH(114),
    { 0x2e, 0x10,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Zapdos...#W\nIt's one of the legendary bird Pokémon.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" I heard it had been\nsleeping for a long time...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" So Shiftry woke it up?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" No.#W\nShiftry's winds were only the trigger.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" To begin with, the absence\nof winds there was unnatural.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" It must have been caused\nby the rash of natural disasters recently.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Zapdos is enraged from\nhaving been awoken from its sleep.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Shiftry must be saved.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" But Zapdos won't be easy.#W\nIts electric attacks are wicked nasty.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" I know that.#W\nWe will need to be cautious.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll go too!\nWe'll go help Shiftry!")),
    VARIANT(/* == */  3, _(" We'll go too!\nWe'll go help Shiftry!")),
    VARIANT_DEFAULT(_(" We'll go too!\nWe'll go help Shiftry!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x10,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" What?!#W\nThat is dangerous!") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Zapdos is powerful.#W\nIt will be too much for your skill level.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, now!\nWe're not that wimpy!")),
    VARIANT(/* == */  3, _(" Wait a second!\nWe're not that weak!")),
    VARIANT_DEFAULT(_(" Hey!\nWe're not that weak!")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" And we're not afraid of no\nZapdos!#W\nIsn't that right, $n0?!")),
    VARIANT_DEFAULT(_(" Besides, Zapdos doesn't\nscare us.#W\nRight, $n0?")),
    CHOICE(/* label */ 15, _("Yup! I'm not scared!")),
    CHOICE(/* label */ 16, _("Owowow... My stomach!")),
  LABEL(15), /* = 0x0f */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0006,  0x00000000,  0x00000000, _(" Have you ever been hit\nwith an electric blast?") },
    { 0x2e, 0x15,  0x0006, -0x00000002,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 6, _(" It'll leave you stunned and\nshaking!")),
    CHOICE(/* label */ 18, _("No problem!")),
    CHOICE(/* label */ 16, _("Owowow... My stomach!")),
  LABEL(18), /* = 0x12 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" Zapdos is wickedly tough!") },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 5, _(" It might gobble you up for\na snack!\nCan you face that?")),
    CHOICE(/* label */ 20, _("I'm not scared!")),
    CHOICE(/* label */ 16, _("Owowow... My stomach!")),
  LABEL(20), /* = 0x14 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We're a rescue team too!")),
    VARIANT(/* == */  1, _(" We want to help Shiftry!")),
    VARIANT(/* == */  3, _(" We're a rescue team too!")),
    VARIANT(/* == */  3, _(" We want to help Shiftry!")),
    VARIANT_DEFAULT(_(" We're a rescue team too!")),
    VARIANT_DEFAULT(_(" We want to help Shiftry!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(21),
  LABEL(16), /* = 0x10 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    FANFARE_PLAY2(457),
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0x54, 0x00,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" No problem!#W\nMy partner always puts on this act.")),
    VARIANT(/* == */  1, _(" Always faking these\nstomachaches...\nIt's a big headache, I tell you!")),
    VARIANT(/* == */  3, _(" No problem!#W\n$n0 always puts on this act.")),
    VARIANT(/* == */  3, _(" Always faking a\nstomachache...\nIt gets to be annoying.")),
    VARIANT_DEFAULT(_(" No problem!#W\n$n0 always does this act.")),
    VARIANT_DEFAULT(_(" It's always a fake\nstomachache.\nIt bugs me a little.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We're a rescue team too!")),
    VARIANT(/* == */  1, _(" We want to help Shiftry!")),
    VARIANT(/* == */  3, _(" We're a rescue team too!")),
    VARIANT(/* == */  3, _(" We want to help Shiftry!")),
    VARIANT_DEFAULT(_(" We're a rescue team too!")),
    VARIANT_DEFAULT(_(" We want to help Shiftry!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(21), /* = 0x15 */
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0x2e, 0x10,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ......") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Fine.#W\nI see that you have courage.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Yes!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x10,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Our two teams should make\nour ways separately through #CDMt. Thunder#R.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We will go when we have\ngeared up for battle.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Knowing how strong our\nopponent is, we have no choice but to\nbe cautious.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" You should make way for\n#CDMt. Thunder#R only when you are fully\nprepared.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Our objective is to rescue\nShiftry!\nLet us find success!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yes!\nI'm getting stoked for this!")),
    VARIANT_DEFAULT(_(" Yes!\nI'm getting excited over this!")),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!\nLet's give it our best, partner!")),
    VARIANT(/* == */  3, _(" $n0!\nLet's do good!")),
    VARIANT_DEFAULT(_(" $n0!\nLet's do our best!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};





















static const struct ScriptCommand s_gs9_g39_s0_lives1_dlg0[] = { /* 0x81b56f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 0),
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000007,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g39_s0_lives2_dlg0[] = { /* 0x81b59c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g39_s0_lives3_dlg0[] = { /* 0x81b5b60 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g39_s0_lives4_dlg0[] = { /* 0x81b5c80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x58,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g39_s0_lives5_dlg0[] = { /* 0x81b5da0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x58,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100, -0x00000005,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g39_s0_lives6_dlg0[] = { /* 0x81b5ea0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x58,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100, -0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g40_s0_station_sref_script[] = { /* 0x81b5f60 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g40_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g40_s0_station_sref_script }; /* 0x81b6030 */

static const struct ScriptCommand s_gs9_g40_s0_lives0_dlg0[] = { /* 0x81b603c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000055,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nGet a good night's sleep?")),
    VARIANT_DEFAULT(_(" Good morning, $n0!\nDid you sleep well?")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So now...#W\nWe're supposed to be rescuing Shiftry at\n#CDMt. Thunder#R, right?")),
    VARIANT(/* == */  1, _(" But Alakazam said we should\nbe prepared before going...")),
    VARIANT(/* == */  1, _(" What do you think?#W\nWe can go off to #CDMt. Thunder#R right away,\nor we can put it off. It's your choice.")),
    VARIANT(/* == */  1, _(" But whatever we do today,\nlet's give it our best like always!")),
    VARIANT_DEFAULT(_(" OK...#W\nWe should be heading to #CDMt. Thunder#R to\ndo the Shiftry rescue, right?")),
    VARIANT_DEFAULT(_(" But Alakazam said that we\nshould be properly prepared before we\ntry...")),
    VARIANT_DEFAULT(_(" What should we do?#W\nWe can go to #CDMt. Thunder#R right now\nor later. It's up to you.")),
    VARIANT_DEFAULT(_(" But anyway, let's do our\nbest like always!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g40_s0_lives1_dlg0[] = { /* 0x81b64a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x60,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g41_s0_station_sref_script[] = { /* 0x81b6528 */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g41_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g41_s0_station_sref_script }; /* 0x81b6548 */

static const struct ScriptCommand s_gs9_g42_s0_station_sref_script[] = { /* 0x81b6554 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g42_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g42_s0_station_sref_script }; /* 0x81b6624 */

static const struct ScriptCommand s_gs9_g42_s0_lives0_dlg0[] = { /* 0x81b6630 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning!#W\nLet's keep giving it our best!")),
    VARIANT_DEFAULT(_(" Good morning!#W\nLet's do our best like always!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g42_s0_lives1_dlg0[] = { /* 0x81b6750 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g43_s0_station_sref_script[] = { /* 0x81b67b0 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g43_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g43_s0_station_sref_script }; /* 0x81b6880 */

static const struct ScriptCommand s_gs9_g43_s0_eff0_script[] = { /* 0x81b688c */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x28,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g43_s0_lives0_dlg0[] = { /* 0x81b690c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0, morning!")),
    VARIANT(/* == */  1, _(" I did a little checking\naround yesterday.")),
    VARIANT(/* == */  1, _(" The #C5Hill of the Ancients#R\nis in the #CDGreat Canyon#R.")),
    VARIANT(/* == */  1, _(" So let's roll!\nOff we go to the #CDGreat Canyon#R!")),
    VARIANT_DEFAULT(_(" $n0, good morning!")),
    VARIANT_DEFAULT(_(" Yesterday, I did some\nchecking around.")),
    VARIANT_DEFAULT(_(" It turns out that the\n#C5Hill of the Ancients#R is apparently in\nthe #CDGreat Canyon#R.")),
    VARIANT_DEFAULT(_(" We should go there right\naway!\nOff to the #CDGreat Canyon#R!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Huh? What's up with you?")),
    VARIANT_DEFAULT(_(" Huh? What's the matter?")),
    CHOICE(/* label */  1, _("Listen, $n1.")),
    CHOICE(/* label */  2, _("It's OK, it's nothing.")),
  LABEL(1), /* = 0x01 */
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?")),
    VARIANT_DEFAULT(_(" Huh?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?")),
    VARIANT(/* == */  1, _(" Didn't you want to ask me\nsomething?")),
    VARIANT(/* == */  3, _(" Huh?")),
    VARIANT(/* == */  3, _(" Weren't you going to ask\nme something?")),
    VARIANT_DEFAULT(_(" Huh?")),
    VARIANT_DEFAULT(_(" Weren't you about to ask\nme something?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" So what's the matter?\nGet it off your chest.")),
    VARIANT(/* == */  3, _(" What's wrong?\nDon't you want to talk about it?")),
    VARIANT_DEFAULT(_(" What's the matter?\nGo on, say it.")),
    CHOICE(/* label */  4, _("Why do you try so hard?")),
    CHOICE(/* label */  4, _("Why are you so happy?")),
  LABEL(3), /* = 0x03 */
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" What's that?")),
    VARIANT_DEFAULT(_(" Huh?")),
    CHOICE(/* label */  4, _("Why do you try so hard?")),
    CHOICE(/* label */  4, _("Why are you so happy?")),
  LABEL(4), /* = 0x04 */
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  3, _(" Why...?#W\nYou need to ask me that?")),
    VARIANT_DEFAULT(_(" Why...?#W\nWhat, you need to ask?")),
    CHOICE(/* label */  6, _("It's not for you...")),
    CHOICE(/* label */  7, _("It's for someone else...")),
  LABEL(6), /* = 0x06 */
    { 0x2e, 0x02,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, sure.")),
    VARIANT(/* == */  1, _(" It lets me try harder to do\nmy best because it's not about me.")),
    VARIANT(/* == */  1, _(" You and me--we're friends,\nright, $n0?")),
    VARIANT(/* == */  3, _(" That's why.")),
    VARIANT(/* == */  3, _(" Because it's not about me,\nI can try that much harder to do my best.")),
    VARIANT(/* == */  3, _(" We're friends, aren't we,\n$n0?")),
    VARIANT_DEFAULT(_(" You said it.")),
    VARIANT_DEFAULT(_(" It lets me try harder to do\nmy best because it's not about me.")),
    VARIANT_DEFAULT(_(" We're friends, aren't we,\n$n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I want to do my best\nbecause it's for you, $n0.")),
    VARIANT(/* == */  3, _(" I want to do my best\nbecause it's for you, $n0.")),
    VARIANT_DEFAULT(_(" I want to do my best\nbecause it's for you, $n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    { 0x2e, 0x02,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" For someone else?\nNow that's cold.")),
    VARIANT(/* == */  1, _(" You and me--we're friends,\nright, $n0?")),
    VARIANT(/* == */  3, _(" For someone else?\nNow isn't that cold?")),
    VARIANT(/* == */  3, _(" We're friends, aren't we,\n$n0?")),
    VARIANT_DEFAULT(_(" Someone else?\nCome on, what do you think I am?")),
    VARIANT_DEFAULT(_(" We're friends, aren't we,\n$n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I want to do my best\nbecause it's for you, $n0.")),
    VARIANT(/* == */  3, _(" I want to do my best\nbecause it's for you, $n0.")),
    VARIANT_DEFAULT(_(" I want to do my best\nbecause it's for you, $n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's what it's about.\nSo anyway, let's give it our best as\nusual!")),
    VARIANT_DEFAULT(_(" That's what this is about.\nSo, as always, let's try our best to \ndo well!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};



static const struct ScriptCommand s_gs9_g43_s0_lives1_dlg0[] = { /* 0x81b7674 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000002e,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x0000002f,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    FANFARE_STOP2(463),
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g44_s0_station_sref_script[] = { /* 0x81b77e4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g44_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g44_s0_station_sref_script }; /* 0x81b78b4 */

static const struct ScriptCommand s_gs9_g44_s0_lives0_dlg0[] = { /* 0x81b78c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!")),
    VARIANT(/* == */  1, _(" Like always, let's give\nit our best!")),
    VARIANT_DEFAULT(_(" Good morning, $n0!")),
    VARIANT_DEFAULT(_(" Let's do our best like we\nalways do!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g44_s0_lives1_dlg0[] = { /* 0x81b7a14 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g45_s0_station_sref_script[] = { /* 0x81b7a74 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g45_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g45_s0_station_sref_script }; /* 0x81b7b44 */

static const struct ScriptCommand s_gs9_g45_s0_lives0_dlg0[] = { /* 0x81b7b50 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000061,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!")),
    VARIANT(/* == */  1, _(" Let's keep doing our best...#W\nActually, I need to ask you something.")),
    VARIANT_DEFAULT(_(" Good morning, $n0!")),
    VARIANT_DEFAULT(_(" Let's keep on doing good...#W\nActually, I want to ask you something.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Remember what\n$n3 said yesterday?#W\nDoes it bother you?")),
    VARIANT_DEFAULT(_(" What do you think about\nwhat $n3 said yesterday?#W\nDoes it bother you?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("No.")),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yeah, I guess so.\nIt would bother you too, $n0.")),
    VARIANT(/* == */  1, _(" He said that there is a link\nbetween the world's balance being upset\nand how you became a Pokémon...")),
    VARIANT(/* == */  1, _(" And how the upset balance\nis causing natural disasters...")),
    VARIANT(/* == */  1, _(" And, worst of all, he said\nhow our world will be ruined if the\nbalance isn't restored.")),
    VARIANT_DEFAULT(_(" Yes, I guess you would be\nconcerned too, $n0.")),
    VARIANT_DEFAULT(_(" There's supposed to be\na link between the world's balance being\nupset and how you became a Pokémon...")),
    VARIANT_DEFAULT(_(" And because of the world's\nupset balance, natural disasters have been\noccurring...")),
    VARIANT_DEFAULT(_(" And more than anything,\nhe said that the world will be ruined\nif the balance isn't restored...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?!\nIt doesn't have anything to do with you?!")),
    VARIANT(/* == */  1, _(" $n0!\nThat's not funny!")),
    VARIANT(/* == */  1, _(" The world might be\ndestroyed!")),
    VARIANT(/* == */  1, _(" And how you became a\nPokémon, $n0...\nThat's all supposed to be related!")),
    VARIANT_DEFAULT(_(" Huh?!\nIt doesn't concern you?!")),
    VARIANT_DEFAULT(_(" $n0!\nDon't joke around--it's not funny!")),
    VARIANT_DEFAULT(_(" The world might be\ndestroyed!")),
    VARIANT_DEFAULT(_(" And how you became a\nPokémon, $n0...\nThat's all supposed to be related!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh!\n...I get it.")),
    VARIANT(/* == */  1, _(" On second thought, you must\nbe more worried than I am,\n$n0...")),
    VARIANT(/* == */  1, _(" You're in the middle of this.\nOf course you're worried...")),
    VARIANT(/* == */  1, _(" Sorry, $n0.\nI wasn't thinking.")),
    VARIANT(/* == */  3, _(" Oh!\n...I understand now.")),
    VARIANT(/* == */  3, _(" How stupid of me...\nOf course you would be more worried\nthan I am, $n0...")),
    VARIANT(/* == */  3, _(" You're involved in all of\nthis.\nIt's only natural you'd be worried...")),
    VARIANT(/* == */  3, _(" Sorry, $n0.\nIt was inconsiderate of me.")),
    VARIANT_DEFAULT(_(" Oh!\n...I get it.")),
    VARIANT_DEFAULT(_(" I wasn't thinking.\nYou should be more worried than I am,\n$n0...")),
    VARIANT_DEFAULT(_(" You're in the middle of this.\nOf course you're worried...")),
    VARIANT_DEFAULT(_(" I'm sorry, $n0.\nI should have realized...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x02,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n3 said the world\nwill be destroyed if nothing's done...")),
    VARIANT_DEFAULT(_(" $n3 said that the\nworld will be ruined if nothing is done...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I want to do something...#W\nBut I don't really get it...")),
    VARIANT(/* == */  1, _(" Tell me.\nThe world's balance...#W\nWhat is that?")),
    VARIANT_DEFAULT(_(" I want to do something...#W\nBut there's something I don't understand.")),
    VARIANT_DEFAULT(_(" So, uh...\nThe world's balance...#W\nWhat is it?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" $n0, do you know?\nWhat the world's balance is?")),
    CHOICE(/* label */  3, _("Of course.")),
    CHOICE(/* label */  4, _("Don't know.")),
    CLEAR_ARRAY(EVENT_LOCAL),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, really?!#W\n$n0, you know?!")),
    VARIANT_DEFAULT(_(" Oh, really?!#W\n$n0, you know?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CLEAR_ARRAY(EVENT_LOCAL),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" So, what is it?\nWhat is the world's balance?")),
    VARIANT_DEFAULT(_(" Please, tell me.\nWhat is the world's balance?")),
    CHOICE(/* label */  5, _("It's in space.")),
    CHOICE(/* label */  6, _("Sorry. I don't know.")),
  LABEL(5), /* = 0x05 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    FANFARE_PLAY2(473),
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    WAIT(100),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" In space...?#W\nLike where the stars and the moon are?\nThat space?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...\nI'm getting even more confused here...")),
    VARIANT_DEFAULT(_(" Hmm...\nI'm getting even more confused...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CLEAR_ARRAY(EVENT_LOCAL),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" So, the world's balance is\nwhere out in space?")),
    VARIANT_DEFAULT(_(" OK, so where exactly in\nspace is the world's balance?")),
    CHOICE(/* label */  7, _("If you go, you'll see.")),
    CHOICE(/* label */  6, _("Sorry. I don't know.")),
  LABEL(7), /* = 0x07 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?!#W\nGo out to space?!")),
    VARIANT_DEFAULT(_(" Huh?!#W\nGo out to space?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CLEAR_ARRAY(EVENT_LOCAL),
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" How are we supposed to do\nthat?!")),
    VARIANT_DEFAULT(_(" And how do we go out to\nspace?!")),
    CHOICE(/* label */  8, _("Fly there.")),
    CHOICE(/* label */  9, _("On guts.")),
  LABEL(8), /* = 0x08 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah?!\nNo way! I can't fly!")),
    VARIANT(/* == */  3, _(" Huh?!\nHow am I supposed to fly?!")),
    VARIANT_DEFAULT(_(" Huh?!\nI can't fly!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    SELECT_LIVES(-1, 1),
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! $n2!")),
    VARIANT(/* == */  1, _(" You came at the right time!#W\nWe want you to carry us out to space...")),
    VARIANT(/* == */  3, _(" Oh! $n2!")),
    VARIANT(/* == */  3, _(" You came at the right time!#W\nI was wondering if you could carry us\nout to space...")),
    VARIANT_DEFAULT(_(" Oh! $n2!")),
    VARIANT_DEFAULT(_(" Just who we need!#W\nYou see, we're wondering if you could\ncarry us to space...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" No way!\nNot a chance!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000003,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" ........................")),
    CHOICE(/* label */ 10, _("It appears to be impossible...")),
    CHOICE(/* label */ 10, _("It's impossible, after all...")),
  LABEL(10), /* = 0x0a */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What is it with you?!\nGoofing around like that!")),
    VARIANT(/* == */  1, _(" Think a little more before\nyou say anything!")),
    VARIANT_DEFAULT(_(" What's wrong with you?!\nSaying all these ridiculous things!")),
    VARIANT_DEFAULT(_(" I wish you'd be more\nconsiderate before making jokes!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, you don't know anything\nat all, $n0...")),
    VARIANT_DEFAULT(_(" So, you don't know either,\n$n0...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(11),
  LABEL(9), /* = 0x09 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    WAIT(100),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What do you mean, guts?!")),
    VARIANT(/* == */  1, _(" If that's all it took, we\nwouldn't be talking about it!")),
    VARIANT_DEFAULT(_(" What are you saying?!\nGuts?!")),
    VARIANT_DEFAULT(_(" If that's all it took,\nnone of this would be necessary!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, you don't know anything\nat all, $n0...")),
    VARIANT_DEFAULT(_(" So, you don't know either,\n$n0...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(11),
  LABEL(6), /* = 0x06 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What?!\nThat's really lame!")),
    VARIANT(/* == */  1, _(" Cut it out!")),
    VARIANT_DEFAULT(_(" Sheesh!\nThat is so lame!")),
    VARIANT_DEFAULT(_(" Don't joke around like that!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...But, yeah, I guess it's\nimpossible to tell what it is...")),
    VARIANT_DEFAULT(_(" ...But I guess it isn't\npossible to know what it is...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(11),
  LABEL(4), /* = 0x04 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...OK.#W\nYeah, I guess so.\nIt'd be impossible to know.")),
    VARIANT_DEFAULT(_(" ...OK.#W\nI guess so. You wouldn't know.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(11), /* = 0x0b */
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I don't have a clue what\nthe world's balance is about...")),
    VARIANT(/* == */  1, _(" Honest, I don't know what\nto do...")),
    VARIANT_DEFAULT(_(" I can't imagine what the\nworld's balance is about...")),
    VARIANT_DEFAULT(_(" To be honest, I don't know\nwhat we should do...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I guess we'll just have to\ndo what we can.")),
    VARIANT(/* == */  1, _(" One thing at a time...")),
    VARIANT(/* == */  3, _(" Well, I guess we'll have to\nkeep doing what we can.")),
    VARIANT(/* == */  3, _(" One thing at a time...")),
    VARIANT_DEFAULT(_(" I guess we'll just have to\ndo what we can.")),
    VARIANT_DEFAULT(_(" One thing at a time...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g45_s0_lives1_dlg0[] = { /* 0x81b9ee8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000002e,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 0),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 2),
    FANFARE_PLAY2(463),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 4),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 4),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 5),
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(471),
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(2),
  LABEL(5), /* = 0x05 */
    FANFARE_PLAY2(471),
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(4), /* = 0x04 */
    FANFARE_PLAY2(471),
    CALL_SCRIPT(ANGRY_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(2), /* = 0x02 */
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g45_s1_lives0_dlg0[] = { /* 0x81ba378 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    FANFARE_PLAY2(451),
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g46_s0_station_sref_script[] = { /* 0x81ba5b8 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    RET,
};

static const struct ScriptRef s_gs9_g46_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g46_s0_station_sref_script }; /* 0x81ba658 */

static const struct ScriptCommand s_gs9_g46_s0_lives0_dlg0[] = { /* 0x81ba664 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000061,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x2e, 0x03,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'm sorry.\nSorry for wanting to go home before\ngetting the job done.")),
    VARIANT(/* == */  1, _(" But I just can't get into it.")),
    VARIANT(/* == */  1, _(" I guess it's because I heard\nthat story.\nAhahaha...")),
    VARIANT(/* == */  1, _(" I'm going to call it a day\nand get some sleep.")),
    VARIANT(/* == */  1, _(" I'll see you tomorrow.")),
    VARIANT_DEFAULT(_(" I'm sorry.\nFor wanting to go home before we're done.")),
    VARIANT_DEFAULT(_(" But I just can't seem to\nget motivated.")),
    VARIANT_DEFAULT(_(" I guess it's because I heard\nthat story.\nAhahaha...")),
    VARIANT_DEFAULT(_(" I'll go home and try to get\nsome sleep.")),
    VARIANT_DEFAULT(_(" I'll see you tomorrow.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(160),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x0c,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0001,  0x00000007,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!\nSorry!")),
    VARIANT(/* == */  3, _(" $n0!\nSorry!")),
    VARIANT_DEFAULT(_(" $n0!\nSorry!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I started doubting you\na little, $n0...")),
    VARIANT(/* == */  3, _(" I started doubting you\na little, $n0...")),
    VARIANT_DEFAULT(_(" I started doubting you\na little, $n0...")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But I've made up my mind.")),
    VARIANT(/* == */  1, _(" I'm going to believe in you,\n$n0.")),
    VARIANT(/* == */  1, _(" Because you're my friend,\n$n0.\nAn important friend.")),
    VARIANT(/* == */  1, _(" Yes, a really important...#W\nfriend...")),
    VARIANT(/* == */  3, _(" I'm not going to worry\nanymore.")),
    VARIANT(/* == */  3, _(" I believe in you,\n$n0.")),
    VARIANT(/* == */  3, _(" Because...\nYou're a friend like no other,\n$n0.")),
    VARIANT(/* == */  3, _(" You're an invaluable...#W\nfriend...")),
    VARIANT_DEFAULT(_(" But I'm not going to worry\nanymore.")),
    VARIANT_DEFAULT(_(" I believe in you,\n$n0.")),
    VARIANT_DEFAULT(_(" Because you're a friend\nlike no other, $n0.")),
    VARIANT_DEFAULT(_(" You're a friend...#W\nLike I'd never get again...")),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right, $n0!\nLet's get back to doing our best tomorrow!")),
    VARIANT(/* == */  3, _(" OK, $n0!\nLet's try our best to do well tomorrow!")),
    VARIANT_DEFAULT(_(" OK, $n0!\nLet's do our best tomorrow like always!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(150),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g46_s0_lives1_dlg0[] = { /* 0x81baf28 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0080,  0x00000030,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000031,  0x00000000, NULL },
    WAIT(90),
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000032,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g47_s0_station_sref_script[] = { /* 0x81bb078 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g47_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g47_s0_station_sref_script }; /* 0x81bb148 */

static const struct ScriptCommand s_gs9_g47_s0_lives0_dlg0[] = { /* 0x81bb154 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000009,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Morning, $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Huh?#W\nYou look pale.\nWhat's up with you?")),
    VARIANT_DEFAULT(_(" ...Oh?#W\nYou look pale.\nIs something the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, anyway.\nLet's give it our best like always!")),
    VARIANT_DEFAULT(_(" Well, anyway.\nAs always, let's try to do our best!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, yeah!") },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" When I was on the way\nhere, I think there was a commotion at\nPokémon Square.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I wonder if something\nhappened...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g47_s0_lives1_dlg0[] = { /* 0x81bb4d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000060, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g48_s0_station_sref_script[] = { /* 0x81bb5b0 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g48_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g48_s0_station_sref_script }; /* 0x81bb620 */

static const struct ScriptCommand s_gs9_g48_s0_eff0_script[] = { /* 0x81bb62c */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x00b3,  0x00000014,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0080, -0x00000018,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g48_s0_lives0_dlg0[] = { /* 0x81bb6cc */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0006,  0x00000063,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0007,  0x00000052,  0x00000000, NULL },
    { 0x59, 0x00,  0x00a0,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6a, 0x00,  0x0300, -0x000000a0,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(150),
    { 0x2e, 0x14,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Gasp, gasp...#W\nWow, that was a real shock!") },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x0002,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I never expected everyone\nto attack us like that.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But, hey, $n0.")),
    VARIANT_DEFAULT(_(" But listen, $n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Why didn't you say anything?")),
    VARIANT(/* == */  1, _(" Why didn't you say it's not\nyou?!")),
    VARIANT_DEFAULT(_(" Why didn't you say anything?")),
    VARIANT_DEFAULT(_(" Why didn't you argue that\nit's not you?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Why didn't you say you're\nnot the human that appears in the legend\nof $n6?")),
    VARIANT_DEFAULT(_(" You should have said you're\nnot the human that appears in the legend\nof $n6!")),
    CHOICE(/* label */  1, _("...Listen, $n1.")),
    CHOICE(/* label */  1, _("...Hey, $n1.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
  LABEL(1), /* = 0x01 */
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hah?\nWhat's up?")),
    VARIANT_DEFAULT(_(" Huh?\nWhat is it?")),
    CHOICE(/* label */  2, _("Want to end the team?")),
    CHOICE(/* label */  3, _("I'm tired of this...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
  LABEL(2), /* = 0x02 */
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-what's the matter now?\nWhat are you saying all of a sudden?")),
    VARIANT(/* == */  1, _(" Give up our rescue team?#W\nThat doesn't sound like you, $n0.")),
    VARIANT(/* == */  1, _(" What's up with that?")),
    VARIANT_DEFAULT(_(" Wh-what's the matter?\nWhat makes you say that all of a sudden?")),
    VARIANT_DEFAULT(_(" Give up on our rescue\nteam?#W\nIt's not like you to say that, $n0.")),
    VARIANT_DEFAULT(_(" Is something the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
  LABEL(3), /* = 0x03 */
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hah? You're tired?\nWhat are you saying?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0800,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(473),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Hah?#W\nYou're saying you don't deserve to be on\nour rescue team?!")),
    VARIANT(/* == */  1, _(" What's wrong with you?!#W\nWhy are you saying that?!")),
    VARIANT(/* == */  1, _(" It's not like you at all,\n$n0!#W\nWhat happened to you?!")),
    VARIANT_DEFAULT(_(" ...Huh?!#W\nYou don't think you deserve to be on our\nrescue team?!")),
    VARIANT_DEFAULT(_(" What's wrong?!#W\nWhat makes you say that?!")),
    VARIANT_DEFAULT(_(" That doesn't sound like you\nat all, $n0.#W\nTell me, what's the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
  LABEL(4), /* = 0x04 */
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0800,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ............#WHuh?\nYou had a dream?") },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" And $n7 appeared\nin it?") },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...And that made you think\nthat maybe you were that human after\nall...") },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ...So that's what it is.\nThat's what happened...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0!")),
    VARIANT(/* == */  1, _(" That doesn't mean you\nremembered what you were like as\na human, does it?")),
    VARIANT(/* == */  1, _(" So you don't know what\nactually happened!")),
    VARIANT(/* == */  3, _(" Listen, $n0!")),
    VARIANT(/* == */  3, _(" You didn't remember\nwhat you were like as a human being,\ndid you?")),
    VARIANT(/* == */  3, _(" So you don't know what\nreally happened.")),
    VARIANT_DEFAULT(_(" Listen, $n0.")),
    VARIANT_DEFAULT(_(" Did your dream make\nyou remember what you were like as a\nhuman being?")),
    VARIANT_DEFAULT(_(" Since it didn't, you don't\nknow what really happened.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I...#W\nYou know that I believe in you,\n$n0, right?")),
    VARIANT(/* == */  1, _(" So...")),
    VARIANT(/* == */  3, _(" I...#W\nI believe in you, $n0.\nYou know that, right?")),
    VARIANT(/* == */  3, _(" So...")),
    VARIANT_DEFAULT(_(" I...#W\nI have faith in you, $n0.\nYou know that?")),
    VARIANT_DEFAULT(_(" So...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    WAIT(90),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" After that scene in\nPokémon Square...#W\nWe held a town meeting...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" On what we must do to\nsave the world...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" And we arrived at a\nconsensus.#W\nWe must get rid of you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(9),
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-what did you say?!")),
    VARIANT_DEFAULT(_(" You're kidding!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I was incredulous too...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I had hoped it would not\ncome to this, but...#W\nIt is unfortunate.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We will...\nDefeat you with all our might!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x62, 0x00,  0x0080, -0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" (W-we're fighting here...?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We will give you tonight.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Pack your supplies and get\nout of here.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Come tomorrow, rescue\nteams of all sorts will take up the chase...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" And attack you without\nhesitation.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" And not just you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Anyone that goes with\n$n0 will be considered an enemy.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The trackers will attack\nwithout mercy.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That goes for us too.\nWe will join the hunt to be rid of you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Against all odds, you must\nrun.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Run, run...#W\nAnd survive.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You must run till you\nuncover the truth.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000008,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n2...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" There will be no mercy\nthe next time we meet.#W\nFarewell.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x93, 0x0a,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0...")),
    VARIANT(/* == */  1, _(" In their own way,\n$n2's team believes in you too.")),
    VARIANT(/* == */  1, _(" Didn't I say this before?")),
    VARIANT(/* == */  1, _(" I'm not going to doubt you\nanymore.")),
    VARIANT(/* == */  1, _(" Whatever happens, I'll\nalways believe in you, $n0.")),
    VARIANT(/* == */  1, _(" I won't be scared, even if\nother rescue teams attack us.")),
    VARIANT(/* == */  3, _(" $n0...")),
    VARIANT(/* == */  3, _(" Did you see?\n$n2's team has faith in you too.")),
    VARIANT(/* == */  3, _(" I said this before, didn't I?")),
    VARIANT(/* == */  3, _(" I'm not going to worry\nanymore.")),
    VARIANT(/* == */  3, _(" Whatever happens, I have\nfaith in you, $n0.")),
    VARIANT(/* == */  3, _(" Even if other rescue teams\nstalk us, I won't be scared.")),
    VARIANT_DEFAULT(_(" $n0...")),
    VARIANT_DEFAULT(_(" In their own way,\n$n2's team has faith in you too.")),
    VARIANT_DEFAULT(_(" Didn't I say this before?")),
    VARIANT_DEFAULT(_(" I'm not going to worry\nanymore.")),
    VARIANT_DEFAULT(_(" Whatever happens, I'll\nalways have faith in you, $n0.")),
    VARIANT_DEFAULT(_(" Even if we're attacked\nby other rescue teams, I won't be\nscared.")),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So what's all this about\nnot believing in yourself, $n0?")),
    VARIANT(/* == */  3, _(" So what are we supposed to\ndo if you don't have faith in yourself,\n$n0?")),
    VARIANT_DEFAULT(_(" What good will it do if\nyou don't believe in yourself,\n$n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 2),
    WAIT(1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" $n0.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x0a,  0x000a,  0x00000036,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n5...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" $n0...\nI made a promise, remember?") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" That we would make a\nrescue team base here.") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" That I would join your\nrescue team when I grew up.") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" $n0...\nDon't give up.") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" You're a hero to me,\n$n0.") },
    { 0x34, 0x00,  0x0005,  0x00000000,  0x00000000, _(" I believe in you too,\n$n0.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" So, what do you say,\n$n0?")),
    CHOICE(/* label */ 18, _("OK! I won't give up!")),
    CHOICE(/* label */ 18, _("I'm over it! No giving up!")),
  LABEL(18), /* = 0x12 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(7),
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's right!\nThat's the spirit!\nThat's what I wanted to hear!")),
    VARIANT(/* == */  1, _(" That's the $n0 we\nall know!")),
    VARIANT(/* == */  3, _(" Exactly!\nThat's the spirit!\nThat's more like it!")),
    VARIANT(/* == */  3, _(" That's what we expect from\nour $n0!")),
    VARIANT_DEFAULT(_(" Yeah!\nThat's right!\nThat's more like it!")),
    VARIANT_DEFAULT(_(" That's what we expect from\nour $n0!")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll have to leave here for\nnow...")),
    VARIANT(/* == */  1, _(" But we're going to come\nback, make no mistake!")),
    VARIANT(/* == */  1, _(" We're going to find the\ntruth!")),
    VARIANT(/* == */  3, _(" We'll have to leave for\nthe time being...")),
    VARIANT(/* == */  3, _(" But we're going to come\nback for sure!")),
    VARIANT(/* == */  3, _(" And we'll bring the truth\nback with us!")),
    VARIANT_DEFAULT(_(" We'll have to leave for\nthe time being...")),
    VARIANT_DEFAULT(_(" But let's be sure to come\nback!")),
    VARIANT_DEFAULT(_(" And we'll bring the truth\nback with us!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEOUT(90),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};















static const struct ScriptCommand s_gs9_g48_s0_lives1_dlg0[] = { /* 0x81bddd8 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x00a0,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6a, 0x00,  0x0300, -0x000000a0,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(30),
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000058,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(464),
    { 0x56, 0x00,  0x0000,  0x00000058,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x004c, -0x00000008, -0x00000010, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x62, 0x00,  0x0080, -0x00000004,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x06,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x06,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x06,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x06,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x0a,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g48_s1_lives0_dlg0[] = { /* 0x81be318 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0064,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x00cc, -0x00000064,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x00cc, -0x00000010,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(497),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x62, 0x00,  0x004c,  0x00000008,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0099,  0x000000a0,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g48_s1_lives1_dlg0[] = { /* 0x81be4f8 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0064,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x00cc, -0x00000064,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x004c, -0x00000010,  0x00000008, NULL },
    FANFARE_PLAY2(497),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x004c,  0x00000008,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0099,  0x000000a0, -0x00000010, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g48_s1_lives2_dlg0[] = { /* 0x81be618 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0064,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x00cc, -0x00000064,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x004c, -0x00000010, -0x00000008, NULL },
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x004c,  0x00000008,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0099,  0x000000a0,  0x00000010, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g48_s2_lives0_dlg0[] = { /* 0x81be728 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x59, 0x00,  0x0064,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0080, -0x00000028,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100, -0x00000050,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0x93, 0x05,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g49_s0_station_sref_script[] = { /* 0x81be908 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    BGM_STOP,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(9),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next dawn...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION( 50,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g49_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g49_s0_station_sref_script }; /* 0x81bea5c */


static const struct ScriptCommand s_gs9_g49_s0_lives0_dlg0[] = { /* 0x81bea68 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nIt's early, but I guessed you would be up!")),
    VARIANT_DEFAULT(_(" Morning, $n0!#W\nIt's early, but of course you'd be up by\nnow!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Are you ready to roll?")),
    VARIANT_DEFAULT(_(" Are you ready to leave?")),
    CHOICE(/* label */  2, _("All set!")),
    CHOICE(/* label */  3, _("*Not yet.")),
  LABEL(3), /* = 0x03 */
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right, I'll wait while\nyou get ready.")),
    VARIANT(/* == */  1, _(" Tell me when you're set.#W\nWe'll roll out then.")),
    VARIANT_DEFAULT(_(" Oh, OK.\nI'll wait while you get ready.")),
    VARIANT_DEFAULT(_(" Tell me when you're\nready.#W\nLet's leave then.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(2), /* = 0x02 */
    EXECUTE_FUNCTION(EVENT_M01E07A_L002),
    HALT,
};



static const struct ScriptCommand s_gs9_g49_s0_lives1_dlg0[] = { /* 0x81bedfc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000033,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g50_s0_station_sref_script[] = { /* 0x81bee7c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(-1, 1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g50_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g50_s0_station_sref_script }; /* 0x81beebc */

static const struct ScriptCommand s_gs9_g50_s0_lives0_dlg0[] = { /* 0x81beec8 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g50_s0_lives0_dlg2[] = { /* 0x81beef8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hey!\nYou all ready to go?")),
    VARIANT_DEFAULT(_(" Oh!\nAre you ready to go?")),
    CHOICE(/* label */  1, _("All set!")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right. I'll wait while\nyou get ready.")),
    VARIANT(/* == */  1, _(" Tell me when you're set.#W\nWe'll roll out then.")),
    VARIANT_DEFAULT(_(" Oh, OK.\nI'll wait while you get ready.")),
    VARIANT_DEFAULT(_(" Tell me when you're\nready.#W\nLet's leave then.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    EXECUTE_FUNCTION(EVENT_M01E07A_L002),
    HALT,
};


static const struct ScriptCommand s_gs9_g50_s1_evt0_sref_script[] = { /* 0x81bf0b0 */
    DEBUGINFO,
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 11, 2, /* to label */ 0),
    EXECUTE_STATION(-1, 50, 2),
    HALT,
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptRef s_gs9_g50_s1_evt0_sref = { 57, 7, NULL /* NORMAL_EVENT */, s_gs9_g50_s1_evt0_sref_script }; /* 0x81bf110 */

static const struct ScriptCommand s_gs9_g50_s2_station_sref_script[] = { /* 0x81bf11c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 11,  3),
    RET,
};

static const struct ScriptRef s_gs9_g50_s2_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g50_s2_station_sref_script }; /* 0x81bf17c */

static const struct ScriptCommand s_gs9_g50_s2_lives0_dlg0[] = { /* 0x81bf188 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Are you going to the\nsquare?")),
    VARIANT(/* == */  1, _(" Be careful if you are.\nThere are other Pokémon in the square.")),
    VARIANT(/* == */  1, _(" It's still early, so I think\neveryone's still asleep, but...")),
    VARIANT(/* == */  1, _(" But make sure you don't\nwake anyone up.")),
    VARIANT_DEFAULT(_(" Are you going out to\nPokémon Square?")),
    VARIANT_DEFAULT(_(" There are other Pokémon in\nthe square, so be really careful.")),
    VARIANT_DEFAULT(_(" It's still early, so I think\neveryone will still be asleep...")),
    VARIANT_DEFAULT(_(" But be sure not to wake\nanyone up.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g50_s2_lives1_dlg0[] = { /* 0x81bf44c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g50_s2_lives1_dlg2[] = { /* 0x81bf4bc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hey!\nYou all ready to go?")),
    VARIANT_DEFAULT(_(" Oh!\nAre you ready to go?")),
    CHOICE(/* label */  1, _("All set!")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right, I'll wait while\nyou get ready.")),
    VARIANT(/* == */  1, _(" Tell me when you're set.#W\nWe'll roll out then.")),
    VARIANT_DEFAULT(_(" Oh, OK.\nI'll wait while you get ready.")),
    VARIANT_DEFAULT(_(" Tell me when you're\nready.#W\nLet's leave then.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    EXECUTE_FUNCTION(EVENT_M01E07A_L002),
    HALT,
};


static const struct ScriptCommand s_gs9_g50_s3_station_sref_script[] = { /* 0x81bf5ec */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs9_g50_s3_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g50_s3_station_sref_script }; /* 0x81bf63c */

static const struct ScriptCommand s_gs9_g50_s3_lives0_dlg0[] = { /* 0x81bf648 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x0b,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g50_s3_lives1_dlg0[] = { /* 0x81bf708 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g51_s0_station_sref_script[] = { /* 0x81bf778 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g51_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g51_s0_station_sref_script }; /* 0x81bf7c8 */

static const struct ScriptCommand s_gs9_g51_s0_lives0_dlg0[] = { /* 0x81bf7d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000058,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yep!\nLooks like we're all set.")),
    VARIANT(/* == */  1, _(" From now on, we're\nfugitives.")),
    VARIANT(/* == */  3, _(" Yup.\nI guess we're ready to go.")),
    VARIANT(/* == */  3, _(" From now on, we're\nfugitives.")),
    VARIANT_DEFAULT(_(" Yup.\nLooks like we're ready.")),
    VARIANT_DEFAULT(_(" From now on, we're\nfugitives.")),
    JUMPIF(JUDGE_LE, FRIEND_SUM, 2, /* to label */ 1),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is going to be one\nrough trip...")),
    VARIANT(/* == */  1, _(" I want to keep our team\nmembers out of all this...")),
    VARIANT(/* == */  1, _(" Let's not tell our friends...#W\nAnd we'll go, just you and me.")),
    VARIANT(/* == */  3, _(" I'm sure that this will be a\ndangerous journey...")),
    VARIANT(/* == */  3, _(" I don't want to get our team\nmembers involved in this...")),
    VARIANT(/* == */  3, _(" Let's not tell them...#W\nWe should go by ourselves.")),
    VARIANT_DEFAULT(_(" This is going to be a\ndangerous trip...")),
    VARIANT_DEFAULT(_(" I don't want to get our team\nmembers involved...")),
    VARIANT_DEFAULT(_(" Let's not tell them...#W\nWe'll just leave by ourselves.")),
  LABEL(1), /* = 0x01 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You know what we have\nto do, right?")),
    VARIANT(/* == */  1, _(" We've got to run and keep\nrunning from the rescue teams chasing us.")),
    VARIANT(/* == */  3, _(" We have to run from the\nrescue teams stalking us.")),
    VARIANT(/* == */  3, _(" We have to keep running\nbecause we can't afford to be caught.")),
    VARIANT_DEFAULT(_(" We have to get away from\nthe rescue teams hunting us.")),
    VARIANT_DEFAULT(_(" We have to get away at\nall cost.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_SWITCH(24),
    { 0x2e, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...Yes. We have to escape.)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Like $n2 said that time...)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x5f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs9_g51_s0_lives1_dlg0[] = { /* 0x81bfe94 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x5f, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g52_s0_station_sref_script[] = { /* 0x81bfee4 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(24),
    { 0x27, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x000e,  0x0000001e,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g52_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g52_s0_station_sref_script }; /* 0x81bff64 */

static const struct ScriptCommand s_gs9_g52_s0_lives0_dlg0[] = { /* 0x81bff70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00, -0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Against all odds, you must\nrun.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Run, run...#W\nAnd survive.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You must run till you\nuncover the truth.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g52_s0_lives1_dlg0[] = { /* 0x81c0040 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00, -0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g52_s0_lives2_dlg0[] = { /* 0x81c0090 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g52_s0_lives3_dlg0[] = { /* 0x81c00f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g52_s0_lives4_dlg0[] = { /* 0x81c0130 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s0_station_sref_script[] = { /* 0x81c0170 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(24),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g53_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g53_s0_station_sref_script }; /* 0x81c01f0 */

static const struct ScriptCommand s_gs9_g53_s0_eff0_script[] = { /* 0x81c01fc */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x28,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x18,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xf0,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xa0,  0x0100,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g53_s0_lives0_dlg0[] = { /* 0x81c02fc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Yes...\nWho am I?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Until I discover that truth, I have to\nrun and survive.)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Even if it means going to the edge\nof this world...)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK!\nLet's roll out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's get going!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000034,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x0000000b,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Caterpie! And Metapod too!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, and even Jumpluff!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Wow, I'm glad!\nWe made it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0006,  0x00000000,  0x00000000, _(" We wanted to see you off,\n$n0.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" M-me too!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(30),
    FANFARE_PLAY2(454),
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000001,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(30),
    { 0x2e, 0x0d,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Good morning.\nIt's me, Diglett.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" I wanted to send you off\ntoo.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000008,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Everyone...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" It's a letter.\n$n0, can you read it?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000039,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 began reading the letter.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("“Take care!\n  It's farewell, but only for now.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  Until the day I can deliver mail\n  to you again...") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("  I'll always be waiting.") },
    { 0x35, 0x00, -0x0001,  0x00000000,  0x00000000, _("    - The wandering postal carrier,\n              Pelipper -”") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x0000000b,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Even Pelipper...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000008,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Sniff...\nEveryone, thank you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" The other Pokémon will\nbe waking up soon.") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" You have to go!\nHurry!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Yup.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0!\nLet's go! Hit the road!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xe0,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2b, 0x00,  0x0000, -0x00000001, -0x00000001, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK! Thanks!")),
    VARIANT(/* == */  1, _(" We'll be back!\nCount on it!")),
    VARIANT(/* == */  1, _(" Until then, you guys be\ngood!")),
    VARIANT(/* == */  3, _(" Yup! Thank you!")),
    VARIANT(/* == */  3, _(" We'll be back!\nThat's for certain!")),
    VARIANT(/* == */  3, _(" Until then, take care!")),
    VARIANT_DEFAULT(_(" Yup! Thank you!")),
    VARIANT_DEFAULT(_(" We'll be back!\nThat's for sure!")),
    VARIANT_DEFAULT(_(" Take care until then!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x78,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};















static const struct ScriptCommand s_gs9_g53_s0_lives1_dlg0[] = { /* 0x81c1318 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x5e, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(12),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000044,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x0a,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x0a,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0080, -0x00000004,  0x00000004, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(25),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000003a,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100, -0x00000008,  0x00000008, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xe0,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x78,  0x0100,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s0_lives2_dlg0[] = { /* 0x81c1678 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000035,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(22),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000003b,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2b, 0x00,  0x0000,  0x0000003c,  0x0000003c, NULL },
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Take care!") },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2b, 0x00,  0x0000, -0x00000001, -0x00000001, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s0_lives3_dlg0[] = { /* 0x81c1904 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000036,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    WAIT(4),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000044,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000003c,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s0_lives4_dlg0[] = { /* 0x81c1a94 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    FANFARE_PLAY2(451),
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(501),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Clunk!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g53_s0_lives5_dlg0[] = { /* 0x81c1d74 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000037,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(12),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000044,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(25),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000003d,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(110),
    { 0x2b, 0x00,  0x0000,  0x00000050,  0x00000050, NULL },
    { 0x2e, 0x0b,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0006,  0x00000000,  0x00000000, _(" We'll be waiting for both\nof you to return!") },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2b, 0x00,  0x0000, -0x00000001, -0x00000001, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s0_lives6_dlg0[] = { /* 0x81c2004 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x40,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x00000038,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    WAIT(8),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000044,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g53_s2_lives0_dlg0[] = { /* 0x81c2174 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g55_s0_station_sref_script[] = { /* 0x81c22c4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g55_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g55_s0_station_sref_script }; /* 0x81c23b4 */

static const struct ScriptCommand s_gs9_g55_s0_lives0_dlg0[] = { /* 0x81c23c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0.\nGet a good night's sleep?")),
    VARIANT_DEFAULT(_(" Good morning, $n0.\nDid you sleep well?")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK, we're back in the\nrescue team business!")),
    VARIANT_DEFAULT(_(" All right!\nWe'll get right back into doing\nrescues.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    SELECT_ENTITIES(-1, 1),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Flap! Flap!") },
    WAIT(5),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000b,  0x00000037,  0x00000000, NULL },
    WAIT(100),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x93, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n2's brought us\nmail already, too.")),
    VARIANT_DEFAULT(_(" And look, $n2 is\nbringing us mail already.")),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's give it our best like\nwe always used to, $n0!")),
    VARIANT_DEFAULT(_(" Let's try to do our best like\nwe always did, $n0!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};



static const struct ScriptCommand s_gs9_g55_s0_lives1_dlg0[] = { /* 0x81c2858 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000003e,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000b,  0x00000037,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g55_s1_lives0_dlg0[] = { /* 0x81c2958 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000030,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x6b, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0x91, 0x1e,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x68, 0x00,  0x0100,  0x00000008,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(501),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Clunk! Clunk!") },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(451),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000030,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x1e,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    FANFARE_STOP2(451),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g56_s0_station_sref_script[] = { /* 0x81c2b28 */
    DEBUGINFO,
    JUMP_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g56_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g56_s0_station_sref_script }; /* 0x81c2b58 */

static const struct ScriptCommand s_gs9_g57_s0_station_sref_script[] = { /* 0x81c2b64 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g57_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g57_s0_station_sref_script }; /* 0x81c2c44 */

static const struct ScriptCommand s_gs9_g57_s0_lives0_dlg0[] = { /* 0x81c2c50 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Good morning, $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Hunh? What's up?\nIs something wrong?")),
    VARIANT_DEFAULT(_(" ...Huh? What's the matter?\nIs something wrong?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, right!#W\nThat earthquake earlier!")),
    VARIANT(/* == */  1, _(" $n0, you're\nworried the same way I am.\nI should've known, $n0.")),
    VARIANT(/* == */  1, _(" Alakazam's team hasn't come\nback yet...")),
    VARIANT(/* == */  1, _(" And they say Groudon is\nwickedly strong, so yeah, it is a bit\nworrying...")),
    VARIANT(/* == */  1, _(" But, then again, Alakazam's\nbunch is tough, too.\nThey should be OK...")),
    VARIANT(/* == */  1, _(" Well, we did leave Groudon\nup to Alakazam...")),
    VARIANT(/* == */  1, _(" So we can't do much of\nanything but wait for them to come back.")),
    VARIANT(/* == */  3, _(" Oh, right!#W\nThat earthquake earlier!")),
    VARIANT(/* == */  3, _(" $n0, you're\nworried about the same thing I am.\nI should have guessed, $n0.")),
    VARIANT(/* == */  3, _(" Alakazam's team still hasn't\ncome back...")),
    VARIANT(/* == */  3, _(" People say that Groudon is\nvery powerful, so I am a little worried...")),
    VARIANT(/* == */  3, _(" But Alakazam's team is also\nvery strong.\nThey must be OK.")),
    VARIANT(/* == */  3, _(" Anyway, we agreed to let\nAlakazam handle Groudon.")),
    VARIANT(/* == */  3, _(" So we'll just have to wait\nfor them to come back.")),
    VARIANT_DEFAULT(_(" Oh, I get it!#W\nThat earthquake earlier!")),
    VARIANT_DEFAULT(_(" $n0, you're\nworried about the same thing I am.\nI should've guessed, $n0.")),
    VARIANT_DEFAULT(_(" Alakazam's team hasn't come\nback yet...")),
    VARIANT_DEFAULT(_(" They say that Groudon is\npowerful.\nThat has me a little worried.")),
    VARIANT_DEFAULT(_(" But Alakazam's team is\ntough too.\nThey should be fine.")),
    VARIANT_DEFAULT(_(" Anyway, we agreed to let\nAlakazam deal with Groudon.")),
    VARIANT_DEFAULT(_(" We don't have any choice.\nWe have to wait for them to come back.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We've got to do what we\ncan do.")),
    VARIANT(/* == */  1, _(" So let's give it our best\nfor our rescue team!")),
    VARIANT(/* == */  3, _(" We'll just have to keep on\ndoing what we can do.")),
    VARIANT(/* == */  3, _(" So let's do our best with\nthe rescue team!")),
    VARIANT_DEFAULT(_(" We have to do what we can\nfor our part.")),
    VARIANT_DEFAULT(_(" So let's do our best with\nthe rescue team!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g57_s0_lives1_dlg0[] = { /* 0x81c35ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g58_s0_station_sref_script[] = { /* 0x81c36ac */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g58_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g58_s0_station_sref_script }; /* 0x81c372c */

static const struct ScriptCommand s_gs9_g58_s0_eff0_script[] = { /* 0x81c3738 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g58_s0_lives0_dlg0[] = { /* 0x81c37c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, already awake,\n$n0?")),
    VARIANT(/* == */  1, _(" There was another\nearthquake earlier, right?")),
    VARIANT(/* == */  1, _(" There've been so many...\nI can't get a decent night's sleep.")),
    VARIANT_DEFAULT(_(" Oh, hi!\nYou're up early, $n0.")),
    VARIANT_DEFAULT(_(" Did you notice the\nearthquake earlier?")),
    VARIANT_DEFAULT(_(" It's hard to get decent sleep\nwhen there are so many earthquakes.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hey!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(15),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000003f,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n2.#W\nWhat's up?")),
    VARIANT_DEFAULT(_(" Oh, $n2.#W\nWhat's the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We need you at the square!\nEveryone's gathering there.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Is there something wrong?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm not really sure...\nShiftry's calling everyone out.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" He's getting the other rescue\nteams to come.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0, let's go!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x20,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x60,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};









static const struct ScriptCommand s_gs9_g58_s0_lives1_dlg0[] = { /* 0x81c3df4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x20,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x60,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g58_s1_lives0_dlg0[] = { /* 0x81c3f14 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000040,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000041,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000040,  0x00000000, NULL },
    { 0x89, 0x60,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g59_s0_station_sref_script[] = { /* 0x81c4014 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 9),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    CALL_STATION(  4,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g59_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g59_s0_station_sref_script }; /* 0x81c40f4 */

static const struct ScriptCommand s_gs9_g59_s0_lives0_dlg0[] = { /* 0x81c4100 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000068,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I wish we could've gone too,\nbut that's just too bad.")),
    VARIANT(/* == */  1, _(" We'll let $n2's\nteam take care of things underground.")),
    VARIANT(/* == */  1, _(" We'll keep giving it our\nbest in our rescue work.")),
    VARIANT(/* == */  3, _(" I wish we could have gone\ntoo, but that can't be helped.")),
    VARIANT(/* == */  3, _(" $n2's team can\ntake care of things underground.")),
    VARIANT(/* == */  3, _(" And we'll keep doing the best\nwe can in our rescue work.")),
    VARIANT_DEFAULT(_(" I wish we could have gone\ntoo, but there's nothing we can do about\nthat.")),
    VARIANT_DEFAULT(_(" $n2's team can\ntake care of things underground.")),
    VARIANT_DEFAULT(_(" We'll keep doing the best we\ncan in our rescue work.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g59_s0_lives1_dlg0[] = { /* 0x81c444c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g60_s0_station_sref_script[] = { /* 0x81c44ac */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    CALL_STATION( 61,  0),
    RET,
};

static const struct ScriptRef s_gs9_g60_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g60_s0_station_sref_script }; /* 0x81c458c */

static const struct ScriptCommand s_gs9_g60_s0_eff0_script[] = { /* 0x81c4598 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g60_s0_lives0_dlg0[] = { /* 0x81c45d8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005b,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We got held up by the\ntrouble we had with $n2.")),
    VARIANT(/* == */  1, _(" But now, we're finally\ngoing off to the underground dungeon.")),
    VARIANT(/* == */  1, _(" I know we're not leaving\ntill tomorrow, but I'm, like, buzzing with\nexcitement.")),
    VARIANT(/* == */  1, _(" We should spend today\ngetting ready.")),
    VARIANT(/* == */  1, _(" Let me know when you're\nready to roll.")),
    VARIANT_DEFAULT(_(" We were held up by that\ntrouble with $n2...")),
    VARIANT_DEFAULT(_(" But now, we're getting the\nchance to go to the underground dungeon.")),
    VARIANT_DEFAULT(_(" We're not leaving until\ntomorrow, but I'm jumpy with anticipation.")),
    VARIANT_DEFAULT(_(" Let's spend today getting\nready for the dungeon.")),
    VARIANT_DEFAULT(_(" Let me know when you're\nall ready to go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g60_s0_lives1_dlg0[] = { /* 0x81c4994 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g61_s0_station_sref_script[] = { /* 0x81c49f4 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    JUMP_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g61_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g61_s0_station_sref_script }; /* 0x81c4a34 */

static const struct ScriptCommand s_gs9_g61_s0_lives0_dlg0[] = { /* 0x81c4a40 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g61_s0_lives0_dlg2[] = { /* 0x81c4a70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Oh, hey!\nAre you all ready to roll?")),
    VARIANT_DEFAULT(_(" OK!\nAre you all ready?")),
    CHOICE(/* label */  1, _("All set!")),
    CHOICE(/* label */  2, _("*Not yet.")),
  LABEL(2), /* = 0x02 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, all right.\nI'll wait here until you're ready.")),
    VARIANT(/* == */  1, _(" Give me a shout when you're\nready.")),
    VARIANT_DEFAULT(_(" Oh, OK.\nI'll wait until you're all set.")),
    VARIANT_DEFAULT(_(" Tell me when you're\nready.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nAll set!")),
    VARIANT(/* == */  1, _(" We should get a good night's\nsleep, then.")),
    VARIANT(/* == */  1, _(" We'll roll out tomorrow!")),
    VARIANT_DEFAULT(_(" OK!\nAll set!")),
    VARIANT_DEFAULT(_(" We should both get\na good night's sleep.")),
    VARIANT_DEFAULT(_(" And we'll set out tomorrow!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    EXECUTE_FUNCTION(EVENT_M01E09A_L009),
    HALT,
};


static const struct ScriptCommand s_gs9_g61_s1_station_sref_script[] = { /* 0x81c4d58 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs9_g61_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g61_s1_station_sref_script }; /* 0x81c4da8 */

static const struct ScriptCommand s_gs9_g61_s1_lives0_dlg0[] = { /* 0x81c4db4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g61_s1_lives1_dlg0[] = { /* 0x81c4e54 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g62_s0_station_sref_script[] = { /* 0x81c4ec4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g62_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g62_s0_station_sref_script }; /* 0x81c4f94 */

static const struct ScriptCommand s_gs9_g62_s0_eff0_script[] = { /* 0x81c4fa0 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x89, 0x40,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g62_s0_lives0_dlg0[] = { /* 0x81c5060 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning, $n0!\nGet a good night's sleep?")),
    VARIANT_DEFAULT(_(" Good morning, $n0!\nDid you sleep well?")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is it!#W\nLet's give it our best and rescue\n$n2!")),
    VARIANT_DEFAULT(_(" OK, this is it!#W\nLet's do our best and save $n2's\nteam!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEOUT(150),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x89, 0x40,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x2e, 0x0f,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Gardevoir said...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(She will tell me everything when this\nadventure is over...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Is going underground the adventure\nshe meant...?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Will she tell me if we rescue Alakazam's\nteam...?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey.")),
    VARIANT_DEFAULT(_(" Hello!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What, are you stunned?\nLet's go, already!")),
    VARIANT_DEFAULT(_(" Are you asleep still?\nLet's get going!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    CALL_SCRIPT(NOTICE_FUNC),
    BGM_SWITCH(1),
    { 0x89, 0x48,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g62_s0_lives1_dlg0[] = { /* 0x81c5538 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xa0,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g63_s0_station_sref_script[] = { /* 0x81c55d8 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g63_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g63_s0_station_sref_script }; /* 0x81c56a8 */

static const struct ScriptCommand s_gs9_g63_s0_lives0_dlg0[] = { /* 0x81c56b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#W\nWe didn't do well, did we?")),
    VARIANT_DEFAULT(_(" ............#W\nWe didn't do very well, did we?")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we knew that it would\nbe a tough dungeon.\nWe don't need to get down on ourselves.")),
    VARIANT(/* == */  1, _(" Other rescue teams should\nbe trying to get through the underground\ndungeon.")),
    VARIANT(/* == */  1, _(" We should go to the square.\nWe might be able to get some information.")),
    VARIANT_DEFAULT(_(" But we knew that it would\nbe a very challenging dungeon.\nWe shouldn't be discouraged.")),
    VARIANT_DEFAULT(_(" Other rescue teams should\nhave gone underground too.")),
    VARIANT_DEFAULT(_(" We might be able to get\nsome information if we go to the square.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g63_s0_lives1_dlg0[] = { /* 0x81c5a54 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g64_s0_station_sref_script[] = { /* 0x81c5ab4 */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g64_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g64_s0_station_sref_script }; /* 0x81c5ad4 */

static const struct ScriptCommand s_gs9_g64_s1_station_sref_script[] = { /* 0x81c5ae0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    RET,
};

static const struct ScriptRef s_gs9_g64_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g64_s1_station_sref_script }; /* 0x81c5b30 */

static const struct ScriptCommand s_gs9_g64_s1_lives0_dlg0[] = { /* 0x81c5b3c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Whoops.\nI'd better get packed to leave.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g65_s0_station_sref_script[] = { /* 0x81c5bf8 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g65_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g65_s0_station_sref_script }; /* 0x81c5cc8 */

static const struct ScriptCommand s_gs9_g65_s0_lives0_dlg0[] = { /* 0x81c5cd4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning!\nGet a good night's sleep?")),
    VARIANT(/* == */  1, _(" This is it!#W\nLet's roll, $n0!\nTo the sky we go!")),
    VARIANT_DEFAULT(_(" Good morning!\nDid you sleep well?")),
    VARIANT_DEFAULT(_(" This is it!#W\nLet's go, $n0!\nWe're off to the sky!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs9_g65_s0_lives1_dlg0[] = { /* 0x81c5eb4 */
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

static const struct ScriptCommand s_gs9_g66_s0_station_sref_script[] = { /* 0x81c5f44 */
    DEBUGINFO,
    JUMP_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g66_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g66_s0_station_sref_script }; /* 0x81c5f74 */

static const struct ScriptCommand s_gs9_g67_s0_station_sref_script[] = { /* 0x81c5f80 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g67_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g67_s0_station_sref_script }; /* 0x81c6050 */

static const struct ScriptCommand s_gs9_g67_s0_lives0_dlg0[] = { /* 0x81c605c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Morning!")),
    VARIANT(/* == */  1, _(" Even while we do this,\nthat falling star is coming closer and\ncloser...")),
    VARIANT(/* == */  1, _(" The #CDSky Tower#R is one harsh\nplace...")),
    VARIANT(/* == */  1, _(" But I'm not giving up!")),
    VARIANT(/* == */  1, _(" Let's give it our best,\n$n0!")),
    VARIANT(/* == */  3, _(" Good morning!")),
    VARIANT(/* == */  3, _(" Even now, that falling star\nis getting closer and closer...")),
    VARIANT(/* == */  3, _(" The #CDSky Tower#R is incredibly\nharsh too...")),
    VARIANT(/* == */  3, _(" But I'm not giving up!")),
    VARIANT(/* == */  3, _(" Let's keep doing our best,\n$n0!")),
    VARIANT_DEFAULT(_(" Good morning!")),
    VARIANT_DEFAULT(_(" That falling star is coming\ncloser and closer even now...")),
    VARIANT_DEFAULT(_(" The #CDSky Tower#R is also very\nchallenging...")),
    VARIANT_DEFAULT(_(" But I'm not giving up!")),
    VARIANT_DEFAULT(_(" Let's keep doing our best,\n$n0!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g67_s0_lives1_dlg0[] = { /* 0x81c63e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g68_s0_station_sref_script[] = { /* 0x81c6444 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    { 0x27, 0x01,  0x000d,  0x0000001e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(0),
    { 0x28, 0x01,  0x000d,  0x00000023,  0x00000000, NULL },
    WAIT(90),
    RET,
  LABEL(0), /* = 0x00 */
    { 0x28, 0x01,  0x000d,  0x00000078,  0x00000000, NULL },
    WAIT(80),
    RET,
};

static const struct ScriptRef s_gs9_g68_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g68_s0_station_sref_script }; /* 0x81c6514 */

static const struct ScriptCommand s_gs9_g68_s0_eff0_script[] = { /* 0x81c6520 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000042,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x004c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g68_s0_lives0_dlg0[] = { /* 0x81c65e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x59, 0x00,  0x00c8,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(150),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(80),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00, -0x00c8,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x78,  0x004c,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_LABEL(0),
    WAIT(100),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_LABEL(0),
    { 0x6b, 0x00,  0x0100,  0x00000043,  0x00000000, NULL },
    WAIT(140),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives1_dlg0[] = { /* 0x81c68e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x002d,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x0a,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0012,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(20),
    { 0x89, 0x28,  0x004c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x28,  0x004c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000044,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_eff1_script[] = { /* 0x81c6a20 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0012,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g68_s0_lives2_dlg0[] = { /* 0x81c6a60 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    { 0x89, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives3_dlg0[] = { /* 0x81c6be0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(NOTICE_FUNC),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(40),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(35),
    { 0x89, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(45),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives4_dlg0[] = { /* 0x81c6dc0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x91, 0x0c,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    WAIT(40),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(20),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(20),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(45),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives5_dlg0[] = { /* 0x81c6fc0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(7),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    { 0x91, 0x0c,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(40),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(40),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(35),
    { 0x6b, 0x00,  0x0100,  0x00000045,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives6_dlg0[] = { /* 0x81c7170 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(25),
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x89, 0x20,  0x0080,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(35),
    { 0x6b, 0x00,  0x0100,  0x00000047,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives7_dlg0[] = { /* 0x81c72a0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x6b, 0x00,  0x00cc,  0x00000048,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives8_dlg0[] = { /* 0x81c73e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0080, -0x00000008,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    { 0x6b, 0x00,  0x0100,  0x00000049,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(45),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(45),
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives9_dlg0[] = { /* 0x81c7630 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x08,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    WAIT(20),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    { 0x6b, 0x00,  0x0100,  0x00000046,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives10_dlg0[] = { /* 0x81c77c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x06,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(70),
    { 0x89, 0x28,  0x0080,  0x00000002,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives11_dlg0[] = { /* 0x81c7940 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0c,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x0c,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x89, 0x08,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x91, 0x0c,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_lives12_dlg0[] = { /* 0x81c7b10 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x91, 0x0c,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    WAIT(35),
    { 0x89, 0x0c,  0x0100,  0x00000005,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g68_s0_eff2_script[] = { /* 0x81c7cb0 */
    DEBUGINFO,
    { 0x59, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0003,  0x000001b7,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0003,  0x00000180,  0x00000000, NULL },
    WAIT(100),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0003,  0x00000181,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0010,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000aa,  0x00000000, NULL },
    WAIT(90),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000a9,  0x00000000, NULL },
    WAIT(70),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a8,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x000000a7,  0x00000000, NULL },
    WAIT(30),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g69_s0_station_sref_script[] = { /* 0x81c8040 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g69_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g69_s0_station_sref_script }; /* 0x81c80b0 */

static const struct ScriptCommand s_gs9_g69_s0_eff0_script[] = { /* 0x81c80bc */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g69_s0_lives0_dlg0[] = { /* 0x81c817c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x15,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x18,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, hi, $n2 and\n$n3.#W\nWhat's the matter?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It's Snubbull!#W\nThere's something weird going on!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Snubbull is weird...?#W\nWeird, how?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" He looks completely\ndifferent...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0!\nLet's go to the square!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x89, 0x50,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};







static const struct ScriptCommand s_gs9_g69_s0_lives1_dlg0[] = { /* 0x81c8584 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x18,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x86, 0x00,  0x0100,  0x0000004a,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x48,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g69_s0_lives2_dlg0[] = { /* 0x81c86f4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x40,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x89, 0x40,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x68,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g69_s0_lives3_dlg0[] = { /* 0x81c8804 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x89, 0x48,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x89, 0x38,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x68,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g70_s0_station_sref_script[] = { /* 0x81c88e4 */
    DEBUGINFO,
    JUMP_STATION(  4,  0),
    RET,
};

static const struct ScriptRef s_gs9_g70_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g70_s0_station_sref_script }; /* 0x81c8914 */

static const struct ScriptCommand s_gs9_g71_s0_station_sref_script[] = { /* 0x81c8920 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    EXECUTE_FUNCTION(EVENT_M02E01A_L003),
    HALT,
};

static const struct ScriptRef s_gs9_g71_s0_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g71_s0_station_sref_script }; /* 0x81c8990 */

static const struct ScriptCommand s_gs9_g71_s0_lives0_dlg0[] = { /* 0x81c899c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, yeah, $n0!\nHang on a second!")),
    VARIANT(/* == */  1, _(" There's something I wanted\nto bounce off you before we go to any\ndungeon.")),
    VARIANT(/* == */  3, _(" Oh, yeah, $n0!\nHold on a second!")),
    VARIANT(/* == */  3, _(" There's something I wanted\nto discuss before we go to a dungeon.")),
    VARIANT_DEFAULT(_(" Oh, yeah, $n0!\nWait a second!")),
    VARIANT_DEFAULT(_(" There's something I wanted\nto talk over with you before we go to\na dungeon.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g71_s0_lives1_dlg0[] = { /* 0x81c8c24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g72_s0_station_sref_script[] = { /* 0x81c8ca4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    CALL_STATION(  4,  0),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g72_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g72_s0_station_sref_script }; /* 0x81c8d84 */

static const struct ScriptCommand s_gs9_g72_s0_lives0_dlg0[] = { /* 0x81c8d90 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You know how we always\nwent into dungeons, me and you,\n$n0?")),
    VARIANT(/* == */  1, _(" But I think we're going to\nbe facing even more different types of\ndungeons from now on.")),
    VARIANT(/* == */  1, _(" With just us two, I think\nwe might have some tough times.")),
    VARIANT(/* == */  1, _(" So, this is what I was\nthinking...")),
    VARIANT(/* == */  1, _(" Instead of just us two,\nwe should let our team members do more.")),
    VARIANT(/* == */  1, _(" For instance, how about\npicking different rescue team leaders\nand members to go to dungeons?")),
    VARIANT(/* == */  1, _(" Depending on the dungeon,\nwe might not even get to go anymore...")),
    VARIANT(/* == */  1, _(" But that way, we could have\ndifferent types of Pokémon go in.\nI think that'd be good for us.")),
    VARIANT(/* == */  3, _(" You know how we always\ngo to dungeons together, $n0?")),
    VARIANT(/* == */  3, _(" But from now on, I expect\nto be seeing different types of dungeons.")),
    VARIANT(/* == */  3, _(" With just us, I think there\nwill be times when we find it tough going.")),
    VARIANT(/* == */  3, _(" So, this is my idea.")),
    VARIANT(/* == */  3, _(" Instead of just us, we\nshould be delegating more to the whole\nteam.")),
    VARIANT(/* == */  3, _(" How about we make it\npossible to pick different leaders and\nmembers for rescue teams?")),
    VARIANT(/* == */  3, _(" I think there will even be\ntimes we don't go on rescues, depending\non the dungeon.")),
    VARIANT(/* == */  3, _(" But I think that will let us\nmount rescues with Pokémon of different\ntypes. It will make the team better.")),
    VARIANT_DEFAULT(_(" You know how we always\ngo to dungeons together, $n0?")),
    VARIANT_DEFAULT(_(" But I think we'll be seeing\nall sorts of different dungeons from\nnow on...")),
    VARIANT_DEFAULT(_(" I think some of them will\nbe tough even for us.")),
    VARIANT_DEFAULT(_(" So, I have an idea.")),
    VARIANT_DEFAULT(_(" Instead of us running things\nall the time, we should let the team as\na whole do it.")),
    VARIANT_DEFAULT(_(" How about we change things\nso we can pick the leader and members\nto go into dungeons?")),
    VARIANT_DEFAULT(_(" That might mean we won't\nbe going on rescues to certain dungeons...")),
    VARIANT_DEFAULT(_(" But that will let us handle\nrescues better by having more Pokémon\ntypes available.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" What do you say?#W\n$n0, do you think it would be\ngood if we could make anyone the leader?")),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" What do you say?#W\n$n0, do you think it would be\ngood if we could make anyone the leader?")),
    VARIANT(/* == */  3, _(" Do you like the idea?#W\n$n0, do you think it'd be good\nto be able to freely choose leaders?")),
    VARIANT_DEFAULT(_(" Do you like the idea?#W\n$n0, do you think it'd be good to\nbe able to freely choose leaders?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hah? Why?")),
    VARIANT(/* == */  1, _(" Even up to now, we had\nsome tough times against enemies\nthat could hit our weak points, right?")),
    VARIANT(/* == */  1, _(" In times like that, it's\nbetter to go with different types of\nPokémon.")),
    VARIANT(/* == */  3, _(" Huh? Why?")),
    VARIANT(/* == */  3, _(" Even up to now, we had\ndifficulties against opponents that\nhad type advantages over us.")),
    VARIANT(/* == */  3, _(" It would be a lot more\neffective to go with different types\nof Pokémon, wouldn't it?")),
    VARIANT_DEFAULT(_(" Huh? Why?")),
    VARIANT_DEFAULT(_(" Even up to now, we've\nfaced tight situations where we had\ntype disadvantages, right?")),
    VARIANT_DEFAULT(_(" Don't you think it would be\nbetter if different types of Pokémon\nwent in instead of us?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Right, $n0?#W\nIt's better to be able to change leaders\nand members in any way, agreed?")),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Right, $n0?#W\nIt's better to be able to change leaders\nand members in any way, agreed?")),
    VARIANT(/* == */  3, _(" Right, $n0?#W\nYou agree that it'd be better if we could\nfreely choose team leaders and members?")),
    VARIANT_DEFAULT(_(" Right, $n0?#W\nYou agree that it'd be better if we could\nfreely choose team leaders and members?")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yeah, that's right!#W\nYou think so too, $n0!")),
    VARIANT(/* == */  1, _(" OK! That's settled!#W\nWe'll make it so we can choose the\nPokémon going into dungeons from now on.")),
    VARIANT_DEFAULT(_(" Yup, that's right!#W\nI thought you'd agree, $n0!")),
    VARIANT_DEFAULT(_(" OK! New rule!#W\nWe can now freely pick the Pokémon that\nare going into dungeons.")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is how we should\npick a rescue team's leader.")),
    VARIANT_DEFAULT(_(" I think this is how we\nshould pick the leader of a team going\ninto a dungeon.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" In its Friend Area, face the\nteam member you want to make the leader,\nthen select #C6Make Leader#R on the menu.")),
    VARIANT(/* == */  1, _(" That Pokémon will be the\nteam leader from then on.\nWe should do that before dungeons.")),
    VARIANT(/* == */  1, _(" Oh, there's one more thing.")),
    VARIANT(/* == */  1, _(" Let's also make it so\nthe leader can go to dungeons alone\nif it wants.")),
    VARIANT(/* == */  1, _(" Don't forget!#W To pick a\nleader,#W go to them in their Friend Area...#W\nand select #C6Make Leader#R.")),
    VARIANT(/* == */  1, _(" Let's get in the habit of\ngoing out to Friend Areas and picking\na leader before leaving for a dungeon.")),
    VARIANT_DEFAULT(_(" In its Friend Area, face the\nteam member you want as the leader,\nthen select #C6Make Leader#R on the menu.")),
    VARIANT_DEFAULT(_(" That will make the Pokémon\nthe team leader.\nWe should do that before every dungeon.")),
    VARIANT_DEFAULT(_(" One more thing.")),
    VARIANT_DEFAULT(_(" We should make it so\na team leader can go into a dungeon\nalone if it wants.")),
    VARIANT_DEFAULT(_(" Anyway...#W To choose the\nleader of a dungeon-bound team...#W\nIn a Friend Area, use...#W #C6Make Leader#R.")),
    VARIANT_DEFAULT(_(" We should always choose\nthe team leader in its Friend Area\nbefore sending the team to any dungeon.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g72_s0_lives1_dlg0[] = { /* 0x81ca410 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g72_s1_lives0_dlg0[] = { /* 0x81ca470 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g72_s2_lives0_dlg0[] = { /* 0x81ca500 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g73_s0_evt0_sref_script[] = { /* 0x81ca580 */
    DEBUGINFO,
    EXECUTE_STATION(-1, 74, 0),
    HALT,
};

static const struct ScriptRef s_gs9_g73_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs9_g73_s0_evt0_sref_script }; /* 0x81ca5b0 */

static const struct ScriptCommand s_gs9_g74_s0_station_sref_script[] = { /* 0x81ca5bc */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 0),
    CANCEL_ENTITIES(73, 0),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S01E01A_L001),
    RET,
};

static const struct ScriptRef s_gs9_g74_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g74_s0_station_sref_script }; /* 0x81ca61c */

static const struct ScriptCommand s_gs9_g74_s0_eff0_script[] = { /* 0x81ca628 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g74_s0_lives0_dlg0[] = { /* 0x81ca698 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Uh...#W Um...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000004b,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Um...#W\nI'm Wynaut, and this is...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x03,  0x0003,  0x0000006e,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000006e,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We have a notice on the\nBulletin Board outside the Pelipper Post\nOffice.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please look at it for me.\nPlease, please.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!!!#W") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please help me.#W\nI have to go now.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What was that?\nWhat just happened?")),
    VARIANT(/* == */  1, _(" That little Pokémon...#W\nWhat was the boy called? Wynaut?")),
    VARIANT(/* == */  1, _(" He wanted us to check the\nBulletin Board at the Pelipper Post Office.")),
    VARIANT(/* == */  1, _(" Maybe those two have a\nproblem or something...")),
    VARIANT(/* == */  1, _(" And they put up a rescue\njob notice on the Bulletin Board.")),
    VARIANT(/* == */  1, _(" There's only one way to\nfind out.#W Let's go to the Pelipper Post\nOffice and check the Bulletin Board.")),
    VARIANT_DEFAULT(_(" What was that?\nWhat was that all about?")),
    VARIANT_DEFAULT(_(" That little Pokémon...#W\nDid the boy say he was Wynaut?")),
    VARIANT_DEFAULT(_(" I think he wanted us to look\nat the Bulletin Board at the Pelipper Post\nOffice.")),
    VARIANT_DEFAULT(_(" Maybe Wynaut and his\nfriend have a problem on their hands...")),
    VARIANT_DEFAULT(_(" So, they may have a help-\nwanted notice on the Bulletin Board.")),
    VARIANT_DEFAULT(_(" Only one thing to do.#W\nLet's go check the Pelipper Post Office's\nBulletin Board.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};



static const struct ScriptCommand s_gs9_g74_s0_lives1_dlg0[] = { /* 0x81cb178 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000004c,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01d6,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g74_s0_lives2_dlg0[] = { /* 0x81cb3a8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000004d,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000004e,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000052,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000004f,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g74_s0_lives3_dlg0[] = { /* 0x81cb508 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000050,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000052,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000051,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g75_s0_station_sref_script[] = { /* 0x81cb768 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    RET,
};

static const struct ScriptRef s_gs9_g75_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g75_s0_station_sref_script }; /* 0x81cb7f8 */

static const struct ScriptCommand s_gs9_g75_s0_eff0_script[] = { /* 0x81cb804 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000053,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000054,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g75_s0_lives0_dlg0[] = { /* 0x81cb8b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0003, -0x00000002,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Just like we promised,\nwe punished that gang of $n4.")),
    VARIANT(/* == */  1, _(" I'm hoping that they'll\nsmarten up and settle down.")),
    VARIANT_DEFAULT(_(" Like we promised, we\nshowed the $n4 gang they\nshouldn't monkey around.")),
    VARIANT_DEFAULT(_(" That should teach them not\nto be so wild.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Everyone, thank you for\neverything, really.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes, we're filled with\ngratitude!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" This is our thanks.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(203),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0's team received\n#+a peeled #C4Chestnut#R as their reward.") },
    { 0xe1, 0x00,  0x00cb,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" ..................#W\nThis...#W\nA peeled Chestnut?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes. It's a peeled Chestnut.#W\nYou see, we...") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Don't have any money.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" So we can only give you\na Chestnut as our reward.#W\nAre you unhappy?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Uh... No, no...#W\nWe're OK with this.")),
    VARIANT(/* == */  1, _(" Peeled Chestnuts are\ndelicious...")),
    VARIANT(/* == */  3, _(" Uh... No, no...#W\nWe're not upset.")),
    VARIANT(/* == */  3, _(" I mean, peeled Chestnuts\nare tasty...")),
    VARIANT_DEFAULT(_(" Um... No. No...#W\nWe're fine with this.")),
    VARIANT_DEFAULT(_(" Peeled Chestnuts are\ndelicious...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I like them! Hahahaha!\n(Though I wish we did get some money...)")),
    VARIANT(/* == */  3, _(" I love them! Hahahaha!\n(Some money would have been nice, but...)")),
    VARIANT_DEFAULT(_(" I think they're great!\nHahahaha!\n(A little money would have been nice...)")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe2, 0x00,  0x01d6,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hey, you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(1),
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x2e, 0x0f,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Aww, no, the $n4\ngang!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Did those goons...")),
    VARIANT(/* == */  1, _(" Did they follow us here\nfor revenge?")),
    VARIANT_DEFAULT(_(" That $n4 gang...")),
    VARIANT_DEFAULT(_(" Did they chase us here to\nget us back?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(10),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" That's right, you!") },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" You got lucky!\nYou don't mess with us!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We're not gonna lose this\ntime!\nWe'll pulverize you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Mukkeeeeh!\nCrush them!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    BGM_STOP,
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Whoa!\nL-look at that!") },
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Ch-Chestnut!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" It is!\nIt's a peeled Chestnut!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001, -0x00000001, -0x00000004, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-what?")),
    VARIANT_DEFAULT(_(" Wh-what?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Whisper, whisper...") },
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Mutter, mutter...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's going on?")),
    VARIANT_DEFAULT(_(" What are they doing?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" They look like...#W\nThey're having a discussion.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What is this all about?")),
    VARIANT_DEFAULT(_(" What's going on?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(30, 1),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ...Uh, listen.#W\nYou got something we want...") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" That peeled Chestnut you\nhave...#W\nCan we have it?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We, uh...#W\nLove peeled Chestnuts!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Like, we love them so much,\nwe can't think of a life without Chestnuts!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Why don't you just go get\nChestnuts on your own?")),
    VARIANT_DEFAULT(_(" Can't you just get Chestnuts\nby yourselves?")),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" You know how Chestnuts\nhave that spiky shell?") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Trying to peel that spiky\nshell... It hurts.#W\nAnd we end up losing our tempers!") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" That's why we're asking.\nGive us that peeled Chestnut.#W\nWe'll do whatever you want.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hmmm...\n$n0, what do you think?") },
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Should we give our peeled\nChestnut to the $n4 gang?")),
    CHOICE(/* label */ 15, _("Yes.")),
    CHOICE(/* label */ 16, _("No.")),
  LABEL(16), /* = 0x10 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    WAIT(2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" What?!\nYou won't give it up for us?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Who do you think you are?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Mukkeeeeeh!\nGet them!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x01,  0x0000,  0x00000059,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+$n0 was suddenly attacked\n#+by the $n4 gang!") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+However...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The $n4 gang was weak.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(10),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x8b, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0200, -0x00000010, -0x00000010, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0500,  0x00000008,  0x00000008, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Ow, ow, ow...") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ...W-we lost...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(30, 1),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ...Maybe we can't do this...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" You have to understand.\nWe love peeled Chestnuts.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Please?\nWe'll do anything you want if you'll just\ngive us your peeled Chestnut...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001, -0x00000001, -0x00000004, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hmmm...\n$n0, what do you think?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" The $n4 are saying\nthey'll do anything we want.") },
    WAIT(10),
    ASK3( TRUE, /*default*/ -1, /* speaker */ 1, _(" Should we give our peeled\nChestnut to the $n4 gang?")),
    CHOICE(/* label */ 15, _("Yes.")),
    CHOICE(/* label */ 16, _("No.")),
  LABEL(15), /* = 0x0f */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0x8b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 2),
    WAIT(2),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001, -0x00000001, -0x00000004, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0003, -0x00000002,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I know!#W\nHey, $n4 gang, how are you guys\nwith physical labor?")),
    VARIANT_DEFAULT(_(" I know!#W\nListen, $n4 gang, how are you\nwith physical labor?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Physical labor?\nYou mean muscle work?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We have muscles...#W\nBut we don't like work.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" But if it's for that\npeeled Chestnut...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK!\nThen this is what we'll do!")),
    VARIANT(/* == */  1, _(" We're aiming to rebuild\nour rescue team base so it will be more\nimpressive than this.")),
    VARIANT(/* == */  3, _(" OK!\nThis is what we'll do!")),
    VARIANT(/* == */  3, _(" You see, we want to make\nthis rescue team base more impressive.")),
    VARIANT_DEFAULT(_(" OK!\nThis is what we'll do!")),
    VARIANT_DEFAULT(_(" We were going to make\nour rescue team base something more\nimpressive than this.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Rescue team base?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You got it!#W\nOur rescue team base!")),
    VARIANT(/* == */  1, _(" If you'd help us build our\nrescue team base, we could give you this\npeeled Chestnut!")),
    VARIANT(/* == */  1, _(" What do you say?")),
    VARIANT_DEFAULT(_(" That's right!#W\nOur rescue team base!")),
    VARIANT_DEFAULT(_(" If you would help us with\nthe building of our rescue team base,\nwe could give you this peeled Chestnut!")),
    VARIANT_DEFAULT(_(" How does that sound?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Whisper, whisper...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Mutter, mutter...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" OK.\nWe'll help!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Really?#W\nYou'll help us?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Yeah.\nLeave it to us!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We'll carry in the materials\nand get the place built. Double-quick!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ...In return...#W\nHand over that peeled Chestnut.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0007,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" Me too!\nI'll help too!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" I'll spit silk for gluing\nthings together!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'll help too!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I felt bad because we only\nhad a peeled Chestnut for your reward.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!!!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000b,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Sniff...\nThanks, everyone!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" OK!#W\nLet's get a move on!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" OK!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" OK!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    WAIT(80),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};































static const struct ScriptCommand s_gs9_g75_s0_lives1_dlg0[] = { /* 0x81ce8cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(1),
    { 0x91, 0x08,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(468),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d4,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x02,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives2_dlg0[] = { /* 0x81cea9c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x61, 0x00,  0x0200,  0x00000128,  0x00000138, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    { 0x91, 0x08,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x08,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000055,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives3_dlg0[] = { /* 0x81cee3c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x61, 0x00,  0x0200,  0x00000100,  0x00000138, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    { 0x91, 0x08,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x08,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000056,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives4_dlg0[] = { /* 0x81cf1ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000057,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000058,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    { 0x63, 0x00,  0x0040,  0x00000057,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives5_dlg0[] = { /* 0x81cf33c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005a,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005b,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    { 0x63, 0x00,  0x0040,  0x0000005a,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives6_dlg0[] = { /* 0x81cf49c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005d,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(30),
    { 0x63, 0x00,  0x0040,  0x0000005c,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s0_lives7_dlg0[] = { /* 0x81cf60c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0180,  0x0000005e,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000060,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0011,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s1_lives0_dlg0[] = { /* 0x81cf72c */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x58, 0x01,  0x0000,  0x00000148,  0x00000168, NULL },
    { 0x8b, 0x01,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000010, -0x00000010, NULL },
    { 0x54, 0x00,  0x0029,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0a00, -0x00000010,  0x00000010, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(1),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s1_lives1_dlg0[] = { /* 0x81cf94c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(472),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000058,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x01,  0x0000,  0x00000061,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    { 0x63, 0x00,  0x0100,  0x00000059,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x63, 0x00,  0x0100,  0x00000057,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s1_lives2_dlg0[] = { /* 0x81cfacc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005b,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x5b, 0x01,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s1_lives3_dlg0[] = { /* 0x81cfbec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000005d,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x01,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x58, 0x01,  0x0000,  0x00000130,  0x00000180, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x62, 0x00,  0x0200,  0x00000010, -0x00000010, NULL },
    WAIT(40),
    FANFARE_PLAY2(497),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x63, 0x00,  0x0100,  0x0000005c,  0x00000000, NULL },
    WAIT(10),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s2_lives0_dlg0[] = { /* 0x81cfd9c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s2_lives1_dlg0[] = { /* 0x81cff1c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s2_lives2_dlg0[] = { /* 0x81cffdc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000062,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g75_s2_lives3_dlg0[] = { /* 0x81d009c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000063,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000064,  0x00000000, NULL },
    { 0x91, 0x01,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_station_sref_script[] = { /* 0x81d018c */
    DEBUGINFO,
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(9),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And so...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Construction work began on\n#+the rescue team base of") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+$n0's team\n#+$t.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Several days later...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_FADEIN(60, 1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs9_g76_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g76_s0_station_sref_script }; /* 0x81d0340 */


static const struct ScriptCommand s_gs9_g76_s0_eff0_script[] = { /* 0x81d034c */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000066,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x86, 0x00,  0x0200,  0x00000067,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000068,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g76_s0_lives0_dlg0[] = { /* 0x81d041c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Whew...#W\nOur base is coming along quickly.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We owe everyone for this.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(80),
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" But there's still lots to do.") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" We still have difficult\nthings to do.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yeah...#W But we're getting\nclose, right, $n4 gang?#W\n...#WHah?")),
    VARIANT_DEFAULT(_(" That's true.#W But we're\ngetting close, right, $n4 gang?#W\n...#WHuh?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Look!\nOver there!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000069,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000006a,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What's up with you guys?")),
    VARIANT_DEFAULT(_(" What's the matter?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" We need to keep working.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0004, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Don't wanna.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(20),
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" This work's too boring!#W\nHow do you expect us to keep going?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0c,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Yeah, that's right.\nI don't wanna do this anymore.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We might change our minds\nif you get us more peeled Chestnuts.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...What is it with these\nguys...?")),
    VARIANT_DEFAULT(_(" ...What is this about?")),
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" We just can't be bothered.\nWe need peeled Chestnuts to motivate us.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Problem, $n0.")),
    VARIANT(/* == */  1, _(" It looks like the\n$n4 gang won't work unless\nwe get them another peeled Chestnut.")),
    VARIANT(/* == */  1, _(" I guess we have to find\nmore peeled Chestnuts and give them to\nthe $n4 gang.")),
    VARIANT_DEFAULT(_(" We have a problem,\n$n0.")),
    VARIANT_DEFAULT(_(" I don't think the\n$n4 gang will work unless\nwe get them another peeled Chestnut.")),
    VARIANT_DEFAULT(_(" I guess we'll have to give\nthe $n4 gang any peeled\nChestnuts that we find.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};










static const struct ScriptCommand s_gs9_g76_s0_lives1_dlg0[] = { /* 0x81d11b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(5),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(1),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000006b,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000006c,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives2_dlg0[] = { /* 0x81d1408 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000073,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000074,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000075,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives3_dlg0[] = { /* 0x81d1578 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000070,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000071,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000072,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives4_dlg0[] = { /* 0x81d17f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives5_dlg0[] = { /* 0x81d1888 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x01,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives6_dlg0[] = { /* 0x81d1918 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g76_s0_lives7_dlg0[] = { /* 0x81d1998 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000007,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100, -0x00000010,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x6b, 0x00,  0x00cc,  0x0000006d,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000006e,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000006f,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s0_station_sref_script[] = { /* 0x81d1b28 */
    DEBUGINFO,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB1, 30, /* to label */ 1),
    RET_DIRECT,
  LABEL(1), /* = 0x01 */
    SELECT_ENTITIES(-1, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs9_g77_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs9_g77_s0_station_sref_script }; /* 0x81d1bb8 */

static const struct ScriptCommand s_gs9_g77_s0_lives0_dlg0[] = { /* 0x81d1bc4 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g77_s0_lives0_dlg2[] = { /* 0x81d1bf4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_HASITEM(ITEM_CHESTNUT, /* to label */ 0),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hunh?\nDid you bring us a peeled Chestnut?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What?!\nYou don't have any?!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Then we can't work!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If you want us to renovate\nyour rescue team base, bring us \na Chestnut. A peeled one!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We see peeled #CIChestnuts#R\nsometimes in #CDUproar Forest#R.\nWe want them out of the shell.") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};


static const struct ScriptCommand s_gs9_g77_s0_lives1_dlg0[] = { /* 0x81d1df4 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g77_s0_lives1_dlg2[] = { /* 0x81d1e24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_HASITEM(ITEM_CHESTNUT, /* to label */ 0),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hunh?\nDid you bring us a peeled Chestnut?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What?!\nYou don't have any?!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Then we can't work!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If you want us to renovate\nyour rescue team base, bring us \na Chestnut. A peeled one!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We see #CIChestnuts#R\nsometimes in #CDUproar Forest#R.\nWe want them out of the shell.") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};


static const struct ScriptCommand s_gs9_g77_s0_lives2_dlg0[] = { /* 0x81d1f5c */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g77_s0_lives2_dlg2[] = { /* 0x81d1f8c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF_HASITEM(ITEM_CHESTNUT, /* to label */ 0),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hunh?\nDid you bring us a peeled Chestnut?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What?!\nYou don't have any?!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Then we can't work!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If you want us to renovate\nyour rescue team base, bring us \na Chestnut. A peeled one!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We see #CIChestnuts#R\nsometimes in #CDUproar Forest#R.\nWe want them out of the shell.") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    EXECUTE_STATION(-1, -1, 1),
    HALT,
};


static const struct ScriptCommand s_gs9_g77_s0_lives3_dlg0[] = { /* 0x81d206c */
    DEBUGINFO,
    RET,
};

static const struct ScriptCommand s_gs9_g77_s0_lives3_dlg2[] = { /* 0x81d208c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We're going to work hard!\nWe'll finish the rescue team base!") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g77_s0_lives4_dlg2[] = { /* 0x81d2130 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000041,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g77_s0_lives4_dlg3[] = { /* 0x81d21f0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_END_TALK_FUNC),
    RET,
};

static const struct ScriptCommand s_gs9_g77_s1_station_sref_script[] = { /* 0x81d22c0 */
    DEBUGINFO,
    SELECT_ENTITIES(-1, 1),
    RET,
};

static const struct ScriptRef s_gs9_g77_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs9_g77_s1_station_sref_script }; /* 0x81d22f0 */

static const struct ScriptCommand s_gs9_g77_s1_eff0_script[] = { /* 0x81d22fc */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000053,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000054,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g77_s1_lives0_dlg0[] = { /* 0x81d23bc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMPIF_EQUAL(PARTNER1_KIND, 0, /* to label */ 1),
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Huh?\nDid you bring us a peeled Chestnut?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh!\nA Chestnut!\nWe want a peeled Chestnut!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    ASK3( TRUE, /*default*/ -1, /* speaker */ 2, _(" Come on, give it to us!\nWe'll work hard for it.")),
    CHOICE(/* label */  3, _("Give.")),
    CHOICE(/* label */  4, _("Don't give.")),
  LABEL(4), /* = 0x04 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 2),
    WAIT(2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" What?!\nYou won't give it up for us?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Who do you think you are?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Mukkeeeeeh!\nGet them!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+$n0 was suddenly attacked\n#+by the $n2 gang!") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+However...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The $n2 gang was weak.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ow, ow, ow...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...W-we lost...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    BGM_FADEIN(30, 1),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 peeled the spiny shell\n#+and handed the peeled Chestnut over.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    SELECT_ENTITIES(-1, 3),
    WAIT(1),
    { 0x2e, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes!\nA peeled Chestnut!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" All right, you layabouts!\nGet it together! Chop, chop!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Why don't you quit lounging\naround yourself?!\nGet moving!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We'll get hustling on\nrenovating your rescue team base!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" We'll carry in the materials\nand get the place built. Double-quick!#W\nYou just wait!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_ADVANCE(SCENARIO_SUB1, /*unused*/ 30),
    REMOVE_ITEMSTACK(ITEM_CHESTNUT),
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 30, 2, /* to label */ 7),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And so...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Supplied with another peeled Chestnut,\n#+the $n2 gang got motivated...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And returned to work on\n#+the rescue team base's renovation.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+As a result...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The rescue team base's completion\n#+moved a little closer.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(8), /* = 0x08 */
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_S01E01C_L001),
    HALT,
};





static const struct ScriptCommand s_gs9_g77_s1_lives1_dlg0[] = { /* 0x81d3084 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g77_s1_lives2_dlg0[] = { /* 0x81d3104 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s1_lives3_dlg0[] = { /* 0x81d3164 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s1_lives4_dlg0[] = { /* 0x81d31c4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s2_lives0_dlg0[] = { /* 0x81d3224 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6f, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s2_lives1_dlg0[] = { /* 0x81d3314 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6f, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s2_lives2_dlg0[] = { /* 0x81d33e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x6f, 0x08,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s3_lives0_dlg0[] = { /* 0x81d34b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s3_lives1_dlg0[] = { /* 0x81d35a4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x91, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g77_s3_lives2_dlg0[] = { /* 0x81d3694 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x08,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_station_sref_script[] = { /* 0x81d3774 */
    DEBUGINFO,
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(9),
    { 0x2d, 0x09,  0x0000,  0x0000006f,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And so...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Supplied with another peeled Chestnut,\n#+the $n0 gang got motivated...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And returned to work on\n#+the rescue team base's renovation.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And finally...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The rescue team base was completed!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2d, 0x09,  0x0000,  0x0000006f,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+As a result of everyone's desperate\n#+efforts to stop the $n0 gang...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The rescue team base was saved.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+As for the $n4 gang, they\n#+promised to keep from rampaging...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+In return for more peeled Chestnuts,\n#+they returned to their forest.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And that is how...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The chaotic renovation of\n#+the rescue team base came to an end.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CANCEL_ENTITIES(-1, 0),
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs9_g78_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g78_s0_station_sref_script }; /* 0x81d3b78 */



static const struct ScriptCommand s_gs9_g78_s0_eff0_script[] = { /* 0x81d3b84 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000076,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000077,  0x00000000, NULL },
    BGM_STOP,
    WAIT(20),
    FANFARE_PLAY(201),
    { 0xe1, 0x00,  0x00c9,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEIN(120, 1),
    { 0x6b, 0x00,  0x0100,  0x00000076,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000078,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives0_dlg0[] = { /* 0x81d3cc4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sniff...#W\nFinally...#W\nThis day has finally come...")),
    VARIANT_DEFAULT(_(" Sniff...#W\nFinally...#W\nThis day has finally arrived...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!\nIt's finally finished!")),
    VARIANT(/* == */  1, _(" Our... #C5$t#R's\nrescue team base!")),
    VARIANT(/* == */  3, _(" $n0!\nIt's finally ready!")),
    VARIANT(/* == */  3, _(" Our... #C5$t#R's\nrescue team base!")),
    VARIANT_DEFAULT(_(" $n0!\nIt's ready! Finally!")),
    VARIANT_DEFAULT(_(" Our... #C5$t#R's\nrescue team base!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sniff... This is so cool.#W\nI can stare at it forever! Our rescue team\nbase is so cool.")),
    VARIANT_DEFAULT(_(" Sniff... It's so cool.#W\nEvery time I take a look at our rescue\nteam base, I only see coolness.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" The way it looks like you\nis a nice touch, $n0!")),
    VARIANT_DEFAULT(_(" Its resemblance to you\nis a nice touch, $n0!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0007,  0x00000000,  0x00000000, _(" We all worked very hard!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It was very hard, but it\nwas worth it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Wobbuffet!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x15,  0x0001,  0x0000000a,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Sniff... Everyone...#W\nThank you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0b,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0004, -0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Say, there.#W\nThere's something I want to ask...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" If this rescue team base is\nfinished...") },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Does that maybe mean...#W\nYou won't bring us peeled Chestnuts\nanymore?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hahaha!\nWell, what do you think?")),
    VARIANT(/* == */  1, _(" We don't need to keep\nworking on the base anymore.")),
    VARIANT(/* == */  1, _(" To our $n4 gang!#W\nThanks for everything!")),
    VARIANT_DEFAULT(_(" Hahaha!\nOf course!")),
    VARIANT_DEFAULT(_(" We're finished with work\non our rescue team base.")),
    VARIANT_DEFAULT(_(" To our $n4 gang!#W\nSincerely, thank you for everything!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x10,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0004, -0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ............") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0c,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ........................") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" ....................................") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0004,  0x00000000,  0x00000000, _(" Ukkeeeeeeeeh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CLEAR_ARRAY(EVENT_LOCAL),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wh-what?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(10),
    { 0xe5, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whoa, whoa, whoa!\nWhat are you doing?!\nStop that!")),
    VARIANT_DEFAULT(_(" Waah! What are you doing?!\nStop that!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0180,  0x00000000, -0x00000030, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(20),
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};










static const struct ScriptCommand s_gs9_g78_s0_lives1_dlg0[] = { /* 0x81d4d24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0002,  0x00000007,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x0a,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(10),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(10),
    { 0x91, 0x06,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0180, -0x00000010, -0x00000040, NULL },
    { 0x6b, 0x00,  0x0100,  0x0000007a,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000079,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(100),
    { 0x54, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000004, NULL },
    WAIT(30),
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000004, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives2_dlg0[] = { /* 0x81d5054 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(5),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(70),
    { 0x6b, 0x00,  0x0100,  0x0000007e,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives3_dlg0[] = { /* 0x81d5184 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(10),
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x6a, 0x00,  0x0200, -0x00000020,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000038, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives4_dlg0[] = { /* 0x81d52f4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(472),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe2, 0x00,  0x01d8,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000007b,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(702),
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(24),
    FANFARE_PLAY2(610),
    { 0xe2, 0x00,  0x0262,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(702),
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(24),
    FANFARE_PLAY2(610),
    { 0xe2, 0x00,  0x0262,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    FANFARE_FADEOUT2(100, 702),
    FANFARE_FADEOUT2(100, 610),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000004, NULL },
    WAIT(30),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000004, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives5_dlg0[] = { /* 0x81d5644 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000007c,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives6_dlg0[] = { /* 0x81d5854 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000007c,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x0000007d,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    HALT,
};

static const struct ScriptCommand s_gs9_g78_s0_lives7_dlg0[] = { /* 0x81d5a84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(5),
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x06,  0x000a,  0x00000072,  0x00000000, NULL },
    WAIT(80),
    { 0x6b, 0x00,  0x00cc,  0x0000007f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g79_s0_station_sref_script[] = { /* 0x81d5b94 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs9_g79_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g79_s0_station_sref_script }; /* 0x81d5c34 */

static const struct ScriptCommand s_gs9_g79_s0_eff0_script[] = { /* 0x81d5c40 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000080,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200,  0x00000000, -0x00000074, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x89, 0xa8,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0x89, 0x48,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g79_s0_lives0_dlg0[] = { /* 0x81d5d20 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Thank you so much.\nYou saved me from great peril.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's cool, $n2.#W\nBut why'd you run away?")),
    VARIANT(/* == */  1, _(" Your letter said something\nabout not wanting to be a grown-up, but...")),
    VARIANT_DEFAULT(_(" No problem, $n2.#W\nBut what made you run away in the first\nplace?")),
    VARIANT_DEFAULT(_(" Your letter said something\nabout not wanting to become an adult...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That is...") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Look, there he is!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Yeah, I see him.\nWe've got to get him back quick!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001, -0x00000001, -0x00000004, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" More $n2?#W\nTwo of them, even...")),
    VARIANT_DEFAULT(_(" More $n2?#W\nTwo of them...")),
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n2.#W\nWho are those guys?")),
    VARIANT_DEFAULT(_(" Hey, $n2.#W\nWhat do they want?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" They're...#W\nMy friends.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Now, come with us.#W\nThe grown-up ritual is ready for you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Quit fighting this.\nHave the paw print applied without a fuss.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0c,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" N-no!") },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If I have to get that\npaw print on my back...#W\nI'd rather not become a grown-up!") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What is that?#W\nThis grown-up ritual?")),
    VARIANT_DEFAULT(_(" What was that?#W\nWhat grown-up ritual?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" It is a custom among us $m2.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" When we reach a certain age, they\nmark our backs with paw prints to show\nwe are grown-ups.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" They do that by taking the\nfront paw...#W\nand pushing doooooowwnn on the back...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I can't live with anything\nso tasteless.") },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000003,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I have dreams of creating\ngreat art, so I have certain standards\nfor design that I swear by.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...I know!#W\nI have decided!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I shall join $n0's\nrescue team!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I will participate in your\nrescue activities!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" So...\nI won't return to the pack!#W\nThis is where I will dedicate myself!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x2e, 0x02,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Is... Is that so?\nThen there is nothing we can do.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" We will inform our elders of your\ndecision.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" We wish you luck in your new career\nas a rescuer.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, wow...\nThat's one pushy way of getting a job.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" But, that's OK.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Welcome to the team!#W\nWe expect your best, $n2!")),
    VARIANT_DEFAULT(_(" You're on the team now!#W\nWe expect your best, $n2!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes!\nThank you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" One thing I am good at is\ndrawing and painting.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" For example...#W\nLet me see...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ah, how about that?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_LIVES(79, 1),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000081,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Observe, the design of that\nflag.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I could perhaps redesign\nthe flag?") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If you wish to alter the\nflag's design, you must tell me, please.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x1d,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 16),
    FANFARE_PLAY(204),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n2 joined the rescue team!") },
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x3b, 0x1e,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to $n2?")),
    CHOICE(/* label */ 17, _("*Yes")),
    CHOICE(/* label */ 18, _("No")),
  LABEL(17), /* = 0x11 */
    { 0x3d, 0x00,  0x0000, -0x00000001,  0x00000000, NULL },
  LABEL(18), /* = 0x12 */
    { 0x3b, 0x1f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB1, 32,  3),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I will find my own place\nin the #C4Sky Blue Plains#R.\nUntil then...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
  LABEL(16), /* = 0x10 */
    SCENARIO_CALC(SCENARIO_SUB1, 32,  2),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...But wait! I see that\nmy Friend Area is full...#W\nThis is most unfortunate.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I could join your rescue\nteam if there were room for me in the\n#C4Sky Blue Plains#R...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please speak with me\nagain then.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};

















static const struct ScriptCommand s_gs9_g79_s0_lives1_dlg0[] = { /* 0x81d764c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    WAIT(20),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe2, 0x00,  0x01d5,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000070, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g79_s0_lives2_dlg0[] = { /* 0x81d797c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200, -0x00000010,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0200, -0x00000010,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000010,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x91, 0x08,  0x0001,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x08,  0x0002,  0x00000001,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x08,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0200,  0x00000000,  0x00000020, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(1),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(20),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000081,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g79_s0_lives3_dlg0[] = { /* 0x81d7dcc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000020, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000058, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    WAIT(5),
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100, -0x00000004,  0x00000000, NULL },
    WAIT(60),
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000050, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g79_s0_lives4_dlg0[] = { /* 0x81d7fbc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x01,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000010, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000068, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    WAIT(30),
    { 0x62, 0x00,  0x0100, -0x00000004,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(35),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x0001,  0x00000004,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000050, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g79_s1_lives0_dlg0[] = { /* 0x81d81ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    HALT,
};

static const struct ScriptCommand s_gs9_g80_s0_lives0_dlg1[] = { /* 0x81d825c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000200,  0x00000000, NULL },
    { 0x51, 0x00,  0x0083,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(MOVE_RANDOM),
};

static const struct ScriptCommand s_gs9_g80_s0_lives0_dlg2[] = { /* 0x81d829c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Pshehehehehe!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" That Lombre... He amuses\nme so!\nPshehehehehe!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, long time no see.\nYou are well?") },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" You see, I have heard about\nLombre's tale.\nIt is too funny.") },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I have heard that Lombre\nalmost drowned at sea!") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" But that Lombre--he lives\nin water! How very pathetic!\nPshehehehehe!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 33, 2, /* to label */ 1),
    SCENARIO_CALC(SCENARIO_SUB2, 33,  2),
  LABEL(1), /* = 0x01 */
    SELECT_LIVES(80, 0),
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g80_s0_lives0_dlg3[] = { /* 0x81d8594 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g81_s0_station_sref_script[] = { /* 0x81d86b4 */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(9),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+The next morning...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g81_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g81_s0_station_sref_script }; /* 0x81d87cc */

static const struct ScriptCommand s_gs9_g81_s0_lives0_dlg0[] = { /* 0x81d87d8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hi, $n2, long time!#W\nYou're here to visit us?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" After all that's happened...")),
    VARIANT(/* == */  3, _(" After everything that\nwe went through...")),
    VARIANT_DEFAULT(_(" After everything that\nwe went through...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n2, you must be\ninterested in our adventures!\nHahahaha!")),
    VARIANT(/* == */  3, _(" $n2, you must be\ninterested in our achievements!\nHahahaha!")),
    VARIANT_DEFAULT(_(" $n2, you must be\nintrigued by our achievements!\nHahahaha!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x2e, 0x0b,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kwaaaaaah!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Wrong!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Shopping in Pokémon\nSquare is what I came to do.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I come here only because\nit is on the way...\nThis is not very important.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(470),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh...\nIs that all...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hey, $n2!") },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Oh, hey!\nThere you are!") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Didn't know you'd be here.\nYou had me looking, $n2.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" What is it?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Well, to the northeast of\n#CDMt. Thunder#R...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" There's a gigantic cave!") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" There wasn't anything like\nthat there before, hey?") },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" So, I figured $n2\nwould know something...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    WAIT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kwaaaah!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe5, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I shall call it...#W\nThe #CDMeteor Cave#R.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x00,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" #CDMeteor Cave#R?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It was when Rayquaza\ndestroyed the falling star...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Its pieces broken, they\nscattered across the skies.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" One tumbled to earth.\nIt fell into a mountain, and made the\ncavern you speak of.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Say, $n3.")),
    VARIANT_DEFAULT(_(" Um, $n3.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Did you explore inside the\n#CDMeteor Cave#R?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0d,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Uh, yeah...#W\nJust a little...") },
    { 0x2e, 0x0d,  0x0003,  0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" But the place was crawling\nwith these weird things...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" It freaked me out.\nI couldn't stay there long...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000a,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Ahaha!\nWho would've thought it?\n$n3's kind of cowardly!")),
    VARIANT_DEFAULT(_(" Hahaha!\nSurprise, surprise!\n$n3's kind of cowardly!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0003,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" What's that?!") },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Hey, you, $n1.#W\nIf you were to see that dungeon, you'd be\nintimidated too!") },
    { 0x2e, 0x15,  0x0003,  0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" I've never seen anything\nlike it before...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" There were downright\nbizarre things in there that I'm not\nsure were even Pokémon.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" $n2, do you have\nany idea what are in that place?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...I draw a blank.#W\nI do not know...") },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" However...#W\nThat cavern. The collision that caused \nit had to be enormous.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If there were things that\nsurvived the crash...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Perhaps...\nOf this world they may not be.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" You mean...#W\nThey came from that falling star?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Perhaps that is so...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0.\nWe should go investigate.#W\nThe #CDMeteor Cave#R.")),
    VARIANT_DEFAULT(_(" $n0.\nWant to go investigate?#W\nThe #CDMeteor Cave#R.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    BGM_STOP,
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The rescue team gained\n#+access to the #CDMeteor Cave#R!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



















static const struct ScriptCommand s_gs9_g81_s0_lives1_dlg0[] = { /* 0x81d9bb4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000061,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g81_s0_lives2_dlg0[] = { /* 0x81d9e14 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(474),
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x000a,  0x00000068,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(474),
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g81_s0_lives3_dlg0[] = { /* 0x81da054 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000084,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005e,  0x00000000, NULL },
    WAIT(60),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe5, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs9_g82_s0_station_sref_script[] = { /* 0x81da204 */
    DEBUGINFO,
    SELECT_MAP(9),
    BGM_STOP,
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g82_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g82_s0_station_sref_script }; /* 0x81da284 */

static const struct ScriptCommand s_gs9_g83_s0_station_sref_script[] = { /* 0x81da290 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs9_g83_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g83_s0_station_sref_script }; /* 0x81da310 */

static const struct ScriptCommand s_gs9_g83_s0_eff1_script[] = { /* 0x81da31c */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    UPDATE_VARINT(CALC_ADD, EVENT_LOCAL, 1),
    { 0x56, 0x00,  0x0000,  0x00000063,  0x00000000, NULL },
    { 0x62, 0x00,  0x0800, -0x00000008,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 30, /* to label */ 1),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g83_s0_lives0_dlg0[] = { /* 0x81da3bc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000003, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Whooooooosh!") },
    { 0x6a, 0x00,  0x0200,  0x00000000,  0x00000050, NULL },
    WAIT(60),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0000,  0x0000000c,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...This sound...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Something's coming closer?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Whoooooooooooooooooooooooshhh!") },
    WAIT(20),
    FANFARE_STOP2(508),
    FANFARE_PLAY2(779),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x91, 0x04,  0x0001,  0x00000003,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 30, /* to label */ 2),
    JUMP_LABEL(1),
  LABEL(2), /* = 0x02 */
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x6a, 0x00,  0x0200,  0x00000000,  0x00000028, NULL },
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    { 0x2e, 0x07,  0x0000,  0x00000004,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Wh-what was that...?#W\nWhat just happened?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Something huge flew by at an incredible\nspeed...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It seemed to be going...\nToward the mountain range in the north?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............#W\nYawwwwwn...\nStill sleepy...") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("It's still early.\nI'll catch a little more sleep...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0099,  0x00000000, -0x00000028, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0099,  0x00000000, -0x00000028, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g83_s0_lives1_dlg0[] = { /* 0x81da88c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x1400, -0x00000078,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x1400, -0x00000078,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g84_s0_station_sref_script[] = { /* 0x81da91c */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g84_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g84_s0_station_sref_script }; /* 0x81da9bc */

static const struct ScriptCommand s_gs9_g84_s0_lives0_dlg0[] = { /* 0x81da9c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0003,  0x00000002,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0003,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" $n2!#W\nYou're safe! Yesssss!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x0e,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm so sorry, $n3.#W\nThat dungeon--it was too much for me.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Thank you for saving me.#W\nI appreciate it〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x15,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ow, ow, ow...#W\nMy body--it hurts all over even now...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000004,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...But that dungeon...\nWhat is it about it?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" They say it makes a wish\ncome true. So, I went...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But it was very hard in\nthere--most terribly so!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kiiih!\nI never want to go again!\nSuch a terrible place!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" At first, I made an SOS Call\nbecause I did not want to lose this...") },
    { 0x2e, 0x15,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But I will give it to you.#W\nHere! Your reward for my rescue〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    WAIT(30),
    { 0x3c, 0x2c,  0x0000,  0x00000036,  0x00000000, NULL },
    WAIT(30),
    JUMP_LABEL(4),
  LABEL(4), /* = 0x04 */
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" They say if you take that\nstone to the #CDWish Cave#R...\nTo its very depths...") },
    { 0x2e, 0x15,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Wonder of wonders!#W\nA wish--it comes true!") },
    { 0x2e, 0x15,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You see〜♪\nA rich reward, won't you agree?") },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" However...#W\nIf you lose that #CIWish Stone#R on\nthe way, the wish cannot come true.") },
    { 0x2e, 0x15,  0x0002,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" For me, it was impossible.\nBut you must try〜♪") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};





static const struct ScriptCommand s_gs9_g84_s0_lives1_dlg0[] = { /* 0x81db1f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x0002,  0x0000005c,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x0002,  0x0000005c,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(ANGRY_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(ANGRY_END_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000,  0x00000020, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000020, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g84_s0_lives1_dlg2[] = { /* 0x81db3d8 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" They say if you take that\nWish Stone to the Wish Cave...\nTo its very depths...") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wonder of wonders!#W\nA wish--it comes true!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" You see〜♪\nA rich reward, won't you agree?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" However...#W\nIf you lose that #CIWish Stone#R on\nthe way, the wish cannot come true.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" For me, it was impossible.\nBut you must try〜♪") },
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g84_s0_lives2_dlg0[] = { /* 0x81db4b8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(60),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g84_s0_lives2_dlg2[] = { /* 0x81db5e8 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I give up too.\nI'll live with my weak chin.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Well, just give it a try\nand make that wish come true!") },
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g85_s0_station_sref_script[] = { /* 0x81db6b4 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs9_g85_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g85_s0_station_sref_script }; /* 0x81db734 */

static const struct ScriptCommand s_gs9_g85_s0_lives0_dlg0[] = { /* 0x81db740 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n2 is our newest\nfriend!#W\nGlad to have you with us!")),
    VARIANT_DEFAULT(_(" From now on, $n2\nis our friend!#W\nGlad to meet you!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The latest recruit to\n#+Team #C5$t#R!") },
    FANFARE_PLAY(204),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n2 joined\n#+the rescue team!") },
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x2a,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 2),
    COND_EQUAL(1, /* to label */ 2),
    WAIT(10),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+And more!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The Friend Area\n#+#CH$h#R was obtained!") },
    FANFARE_PLAY(212),
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(2), /* = 0x02 */
    { 0x3b, 0x2b,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Give a nickname to $n2?")),
    CHOICE(/* label */  3, _("*Yes.")),
    CHOICE(/* label */  4, _("No.")),
  LABEL(3), /* = 0x03 */
    { 0x3d, 0x00,  0x0000, -0x00000001,  0x00000000, NULL },
  LABEL(4), /* = 0x04 */
    { 0x3b, 0x2c,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs9_g85_s0_lives1_dlg0[] = { /* 0x81dba98 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g85_s0_lives2_dlg0[] = { /* 0x81dbad8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g86_s0_station_sref_script[] = { /* 0x81dbb18 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    SELECT_ENTITIES(-1, 1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(87, 0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g86_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g86_s0_station_sref_script }; /* 0x81dbc08 */

static const struct ScriptCommand s_gs9_g86_s0_lives0_dlg0[] = { /* 0x81dbc14 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kekeh!\nLate riser!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Like always, slow to rise,\naren't you, Team #C5$t#R! Kekeke!") },
    { 0x2e, 0x15,  0x0002,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...Tchah!#W\nBut that's not what I came here to say.\nNot today.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It irks me to say this, but...#W\nI need your help.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Can you take me up\n#CDMt. Freeze#R?") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I tried going up over and\nover, but...#W Keh...\nIt's steep and harsh...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ninetales is up on\n#CDMt. Freeze#R.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I've got to see Ninetales.\nI'm prepared to do whatever it takes.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" That's why I'm asking you.#W\nTake me up #CDMt. Freeze#R.")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    WAIT(4),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keke! That's settled!\nYou have my trust!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
  LABEL(3), /* = 0x03 */
    { 0x2e, 0x15,  0x0002,  0x00000043,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!\nYeah, I saw that coming!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm the fool here for even\nbelieving in you lot.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Who needs your help?\nI'll be seeing you around!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    SELECT_ENTITIES(-1, 3),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#W\nI'd like to say that, but I need your help.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I've got to see Ninetales.\nI'm prepared to do whatever it takes.") },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" That's why I'm asking you.#W\nTake me up #CDMt. Freeze#R!")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(4), /* = 0x04 */
    WAIT(10),
    BGM_STOP,
    FANFARE_PLAY(204),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n2 can now tag\n#+along with the rescue team!") },
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The only place I want to go\nis #CDMt. Freeze#R.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm not about to tag along\nif you're going to other dungeons.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'll only tag along when you\ngo off to #CDMt. Freeze#R. Keke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g86_s1_lives0_dlg0[] = { /* 0x81dc418 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g86_s2_lives0_dlg0[] = { /* 0x81dc458 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g86_s3_lives0_dlg0[] = { /* 0x81dc4d8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0080,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x91, 0x06,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0x89, 0x18,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g87_s0_lives0_dlg2[] = { /* 0x81dc588 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" The only place I want to go\nis #CDMt. Freeze#R.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'm not about to tag along\nif you're going to other dungeons.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'll only tag along when you\ngo off to #CDMt. Freeze#R. Keke!") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g88_s0_station_sref_script[] = { /* 0x81dc618 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g88_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g88_s0_station_sref_script }; /* 0x81dc6b8 */

static const struct ScriptCommand s_gs9_g88_s0_lives0_dlg0[] = { /* 0x81dc6c4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keke!\nYou did good today.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Next, we go to that\n#CDMurky Cave#R place...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" That sounds like another\nchallenging place, so I'll need your\nhelp still! Keke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs9_g88_s0_lives1_dlg0[] = { /* 0x81dc828 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g88_s0_lives1_dlg2[] = { /* 0x81dc878 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" They say, if you take that\nWish Stone to the Wish Cave...\nTo its very depths...") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wonder of wonders!#W\nA wish--it comes true!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" You see〜♪\nA rich reward, won't you agree?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" However...#W\nIf you lose that #CIWish Stone#R on\nthe way, the wish cannot come true.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" For me, it was impossible.\nBut you must try〜♪") },
    JUMP_SCRIPT(END_TALK),
};


static const struct ScriptCommand s_gs9_g89_s0_station_sref_script[] = { /* 0x81dc95c */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(90, 0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs9_g89_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs9_g89_s0_station_sref_script }; /* 0x81dca3c */

static const struct ScriptCommand s_gs9_g89_s0_lives0_dlg0[] = { /* 0x81dca48 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kekeh!\nLate riser!") },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" It's the #CDMurky Cave#R next.#W\nI'll need your help for that.")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(2), /* = 0x02 */
    WAIT(4),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keke! Then, we'll go!\nTo the #CDMurky Cave#R!") },
    { 0x2e, 0x15,  0x0002,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Gardevoir's physical form...\nThat's where it is.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" For my sake, Gardevoir...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...Nah, that's not important.#W\nI just feel like going! Keke!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...OK, go there for me!\nTo the #CDMurky Cave#R!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
  LABEL(3), /* = 0x03 */
    { 0x2e, 0x15,  0x0002,  0x00000043,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!\nIs that right.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" See you around!\nKeke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#W\nI thought that, but I need your help.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I have to go to the\n#CDMurky Cave#R.\nI'm prepared to do whatever it takes.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" When I get there, I...") },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    ASK3(FALSE, /*default*/ -1, /* speaker */ 2, _(" It doesn't matter.\nI just need your help.#W\nTake me to the #CDMurky Cave#R!")),
    CHOICE(/* label */  2, _("Yes.")),
    CHOICE(/* label */  3, _("No.")),
  LABEL(4), /* = 0x04 */
    WAIT(10),
    BGM_STOP,
    FANFARE_PLAY(204),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n2 can now tag\n#+along with the rescue team!") },
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(1),
    WAIT(30),
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The only place I want to go\nis the #CDMurky Cave#R.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm not about to tag along\nif you're going to other dungeons.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'll only tag along when you\ngo off to the #CDMurky Cave#R. Keke!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};




static const struct ScriptCommand s_gs9_g89_s0_lives1_dlg0[] = { /* 0x81dd114 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g89_s1_lives0_dlg0[] = { /* 0x81dd154 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g89_s2_lives0_dlg0[] = { /* 0x81dd224 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0080,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x91, 0x06,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(30),
    { 0x89, 0x18,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs9_g90_s0_lives0_dlg2[] = { /* 0x81dd2d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" The only place I want to go\nis the #CDMurky Cave#R.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'm not about to tag along\nif you're going to other dungeons.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I'll only tag along when you\ngo off to the #CDMurky Cave#R. Keke!") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs9_g91_s0_station_sref_script[] = { /* 0x81dd364 */
    DEBUGINFO,
    SELECT_MAP(9),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(5),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs9_g91_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs9_g91_s0_station_sref_script }; /* 0x81dd404 */

static const struct ScriptCommand s_gs9_g91_s0_lives0_dlg0[] = { /* 0x81dd410 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x0e,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Thank you so much...#W\nMy curse has been lifted.") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" You did this for me, even\nthough I had never met you before...#W\nI have no idea how to thank you...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" From the bottom of my\nheart...") },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Thank you so very much for\nsaving me.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x03,  0x0002,  0x00000044,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#W\nGood for you, $n3.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Hey, $n0.\nThanks for getting me through this.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" This is my thanks.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x3c, 0x2c,  0x0000,  0x00000009,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Adios.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    BGM_FADEOUT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Oh, wait, please!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" What is it now?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Your name...#W\nPlease, what is your name?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Keh!") },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The name's $n2.#W\nGlad to meet you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0003,  0x00000041,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" My name is $n3.#W\nI am also glad to meet you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};










static const struct ScriptCommand s_gs9_g91_s0_lives1_dlg0[] = { /* 0x81dd9c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x18,  0x0100,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x28,  0x0080,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs9_g91_s0_lives2_dlg0[] = { /* 0x81ddad8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct GroundLivesData s_gs9_g0_s1_lives[] = { /* 0x81ddb58 */
    /*  0 */ {   0,   6,   0,   0, {  61,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  64,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s2_lives[] = { /* 0x81ddb88 */
    /*  0 */ {   0,   2,   0,   0, {   8,  46, 0, 0 }, {
        [0] = s_gs9_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   2,   0,   0, {   5,  46, 0, 0 }, {
        [0] = s_gs9_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s3_lives[] = { /* 0x81ddbb8 */
    /*  0 */ {   0,   4,   0,   0, {  34,  62, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  64, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s4_lives[] = { /* 0x81ddbe8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  34,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s5_lives[] = { /* 0x81ddc18 */
    /*  0 */ {   0,   4,   0,   0, {  34,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s5_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s5_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s6_lives[] = { /* 0x81ddc48 */
    /*  0 */ {   0,   4,   0,   0, {  34,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s6_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g0_s6_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g0_s7_lives[] = { /* 0x81ddc78 */
    /*  0 */ {  51,   0,   0,   0, {  63,  40, 0, 0 }, {
        [2] = s_gs9_g0_s7_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g1_s1_lives[] = { /* 0x81ddc90 */
    /*  0 */ {  10,   0,   0,   0, {  30,  49, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g1_s1_lives0_dlg2,
    } },
    /*  1 */ {  11,   0,   0,   0, {  30,  52, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g1_s1_lives1_dlg2,
    } },
    /*  2 */ {  12,   0,   0,   0, {  27,  49, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g1_s1_lives2_dlg2,
    } },
    /*  3 */ {  13,   0,   0,   0, {  27,  52, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g1_s1_lives3_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g2_s1_lives[] = { /* 0x81ddcf0 */
    /*  0 */ {  55,   4,   0,   0, {  54,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g2_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g5_s0_lives[] = { /* 0x81ddd08 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g5_s1_lives[] = { /* 0x81ddd38 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g5_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g6_s1_lives[] = { /* 0x81ddd50 */
    /*  0 */ {   0,   2,   0,   0, {  32,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g6_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  37,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g6_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g6_s2_lives[] = { /* 0x81ddd80 */
    /*  0 */ {   0,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g6_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g7_s0_lives[] = { /* 0x81ddd98 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g7_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g7_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g7_s1_lives[] = { /* 0x81dddc8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g7_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g8_s0_lives[] = { /* 0x81ddde0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g8_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g8_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g9_s0_lives[] = { /* 0x81dde10 */
    /*  0 */ { 124,   0,   0,   0, {  27,  37, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g9_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g10_s0_lives[] = { /* 0x81dde28 */
    /*  0 */ { 134,   0,   0,   0, {  46,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g10_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g11_s0_lives[] = { /* 0x81dde40 */
    /*  0 */ { 115,   0,   0,   0, {  49,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g11_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g12_s0_lives[] = { /* 0x81dde58 */
    /*  0 */ { 120,   0,   0,   0, {  52,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g12_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g13_s0_lives[] = { /* 0x81dde70 */
    /*  0 */ {  70,   0,   0,   0, {  55,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g13_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g14_s0_lives[] = { /* 0x81dde88 */
    /*  0 */ { 128,   0,   0,   0, {  58,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g14_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g15_s0_lives[] = { /* 0x81ddea0 */
    /*  0 */ { 123,   0,   0,   0, {  61,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g15_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g16_s0_lives[] = { /* 0x81ddeb8 */
    /*  0 */ {  82,   0,   0,   0, {  64,  39, 0, CPOS_HALFTILE }, {
        [2] = s_gs9_g16_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g17_s0_lives[] = { /* 0x81dded0 */
    /*  0 */ {   0,   4,   0,   0, {  34,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g17_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  37,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g17_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g17_s2_lives[] = { /* 0x81ddf00 */
    /*  0 */ {  34,   0,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g17_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g17_s3_lives[] = { /* 0x81ddf18 */
    /*  0 */ {  34,   0,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g17_s3_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g18_s0_lives[] = { /* 0x81ddf30 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g18_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g18_s0_lives1_dlg0,
    } },
    /*  2 */ {  55,   4,   0,   0, {  54,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g18_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g19_s0_lives[] = { /* 0x81ddf78 */
    /*  0 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g19_s0_lives0_dlg0,
        [2] = s_gs9_g19_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g19_s1_lives[] = { /* 0x81ddf90 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g19_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g19_s1_lives1_dlg0,
        [2] = s_gs9_g19_s1_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g20_s0_lives[] = { /* 0x81ddfc0 */
    /*  0 */ {   0,   4,   0,   0, {  31,  36, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g20_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g20_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g20_s1_lives[] = { /* 0x81ddff0 */
    /*  0 */ {  34,   0,   0,   0, {  34,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g20_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g20_s2_lives[] = { /* 0x81de008 */
    /*  0 */ {  34,   0,   0,   0, {  34,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g20_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g21_s0_lives[] = { /* 0x81de020 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g21_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g21_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g22_s1_lives[] = { /* 0x81de050 */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g22_s1_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g22_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g22_s2_lives[] = { /* 0x81de080 */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g22_s2_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {   8,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g22_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g23_s0_lives[] = { /* 0x81de0b0 */
    /*  0 */ {   0,   2,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g23_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  37,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g23_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g24_s1_lives[] = { /* 0x81de0e0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g24_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g25_s0_lives[] = { /* 0x81de0f8 */
    /*  0 */ {   0,   2,   0,   0, {  31,  36, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g25_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  34,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g25_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g26_s0_lives[] = { /* 0x81de128 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g26_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g26_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g26_s1_lives[] = { /* 0x81de158 */
    /*  0 */ {  66,   0,   0,   0, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g26_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g27_s0_lives[] = { /* 0x81de170 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g27_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g27_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g28_s0_lives[] = { /* 0x81de1a0 */
    /*  0 */ {   0,   4,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s0_lives1_dlg0,
    } },
    /*  2 */ {  68,   0,   0,   0, {  32,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s0_lives2_dlg0,
    } },
    /*  3 */ {  61,   0,   0,   0, {  36,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s0_lives3_dlg0,
    } },
    /*  4 */ {  62,   0,   0,   0, {  34,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g28_s1_lives[] = { /* 0x81de218 */
    /*  0 */ {  66,   0,   0,   0, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g28_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g29_s0_lives[] = { /* 0x81de230 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g29_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g29_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g30_s0_lives[] = { /* 0x81de260 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives1_dlg0,
    } },
    /*  2 */ {  91,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives2_dlg0,
    } },
    /*  3 */ {  92,   4,   0,   0, {  37,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives3_dlg0,
    } },
    /*  4 */ {  93,   4,   0,   0, {  31,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives4_dlg0,
    } },
    /*  5 */ {  55,   6,   0,   0, {  54,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g30_s0_lives5_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g31_s0_lives[] = { /* 0x81de2f0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives1_dlg0,
    } },
    /*  2 */ {  91,   2,   0,   0, {  34,  49, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives2_dlg0,
    } },
    /*  3 */ {  92,   2,   0,   0, {  37,  49, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives3_dlg0,
    } },
    /*  4 */ {  93,   2,   0,   0, {  31,  49, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives4_dlg0,
    } },
    /*  5 */ {  54,   2,   0,   0, {  34,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g31_s0_lives5_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g32_s0_lives[] = { /* 0x81de380 */
    /*  0 */ {  54,   4,   0,   0, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g32_s0_lives0_dlg0,
        [2] = s_gs9_g32_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g33_s0_lives[] = { /* 0x81de398 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g33_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g33_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g34_s0_lives[] = { /* 0x81de3c8 */
    /*  0 */ {   0,   4,   0,   0, {  32,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g34_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g34_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   0,   0,   0, {  32,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g34_s0_lives2_dlg0,
    } },
    /*  3 */ {  94,   0,   0,   0, {  36,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g34_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g35_s0_lives[] = { /* 0x81de428 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g35_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g35_s1_lives[] = { /* 0x81de440 */
    /*  0 */ {  34,   6,   0,   0, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g35_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g35_s2_lives[] = { /* 0x81de458 */
    /*  0 */ {  78,   4,   0,   0, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g35_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g36_s0_lives[] = { /* 0x81de470 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g36_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   7,   0,   0, {  37,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g36_s0_lives1_dlg0,
    } },
    /*  2 */ {  78,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g36_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g37_s0_lives[] = { /* 0x81de4b8 */
    /*  0 */ {  78,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g37_s0_lives0_dlg0,
        [2] = s_gs9_g37_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g38_s0_lives[] = { /* 0x81de4d0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g38_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g38_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g39_s0_lives[] = { /* 0x81de500 */
    /*  0 */ {   0,   4,   0,   0, {  33,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives1_dlg0,
    } },
    /*  2 */ {  78,   0,   0,   0, {  33,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives2_dlg0,
    } },
    /*  3 */ {  95,   0,   0,   0, {  36,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives3_dlg0,
    } },
    /*  4 */ {  88,   6,   0,   0, {  52,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives4_dlg0,
    } },
    /*  5 */ {  90,   6,   0,   0, {  54,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives5_dlg0,
    } },
    /*  6 */ {  89,   6,   0,   0, {  54,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g39_s0_lives6_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g40_s0_lives[] = { /* 0x81de5a8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g40_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g40_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g42_s0_lives[] = { /* 0x81de5d8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g42_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g42_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g43_s0_lives[] = { /* 0x81de608 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g43_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g43_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g44_s0_lives[] = { /* 0x81de638 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g44_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g44_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g45_s0_lives[] = { /* 0x81de668 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g45_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g45_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g45_s1_lives[] = { /* 0x81de698 */
    /*  0 */ {  55,   0,   0,   0, {  54,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g45_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g46_s0_lives[] = { /* 0x81de6b0 */
    /*  0 */ {   0,   2,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g46_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g46_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g47_s0_lives[] = { /* 0x81de6e0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g47_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g47_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g48_s0_lives[] = { /* 0x81de710 */
    /*  0 */ {   0,   2,   0,   0, {  34,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  38,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g48_s1_lives[] = { /* 0x81de740 */
    /*  0 */ {  88,   6,   0,   0, {  42,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s1_lives0_dlg0,
    } },
    /*  1 */ {  89,   6,   0,   0, {  43,  45, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s1_lives1_dlg0,
    } },
    /*  2 */ {  90,   6,   0,   0, {  43,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s1_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g48_s2_lives[] = { /* 0x81de788 */
    /*  0 */ {  54,   6,   0,   0, {  42,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g48_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g49_s0_lives[] = { /* 0x81de7a0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g49_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g49_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g50_s0_lives[] = { /* 0x81de7d0 */
    /*  0 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g50_s0_lives0_dlg0,
        [2] = s_gs9_g50_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g50_s2_lives[] = { /* 0x81de7e8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g50_s2_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g50_s2_lives1_dlg0,
        [2] = s_gs9_g50_s2_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g50_s3_lives[] = { /* 0x81de818 */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g50_s3_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g50_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g51_s0_lives[] = { /* 0x81de848 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g51_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g51_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g52_s0_lives[] = { /* 0x81de878 */
    /*  0 */ {   0,   2,   0,   0, {  34,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g52_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   1,   0,   0, {  37,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g52_s0_lives1_dlg0,
    } },
    /*  2 */ {  88,   6,   0,   0, {  41,  43, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g52_s0_lives2_dlg0,
    } },
    /*  3 */ {  89,   6,   0,   0, {  42,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g52_s0_lives3_dlg0,
    } },
    /*  4 */ {  90,   6,   0,   0, {  42,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g52_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g53_s0_lives[] = { /* 0x81de8f0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   4,   0,   0, {  37,  45, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives2_dlg0,
    } },
    /*  3 */ {  94,   4,   0,   0, {  33,  45, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives3_dlg0,
    } },
    /*  4 */ {  55,   0,   0,   0, {  54,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives4_dlg0,
    } },
    /*  5 */ {  78,   4,   0,   0, {  34,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives5_dlg0,
    } },
    /*  6 */ {  95,   4,   0,   0, {  36,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s0_lives6_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g53_s2_lives[] = { /* 0x81de998 */
    /*  0 */ {  68,   0,   0,   0, {  39,  33, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g53_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g55_s0_lives[] = { /* 0x81de9b0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g55_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g55_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g55_s1_lives[] = { /* 0x81de9e0 */
    /*  0 */ {  55,   4,   0,   0, {  54,  33, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g55_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g57_s0_lives[] = { /* 0x81de9f8 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g57_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g57_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g58_s0_lives[] = { /* 0x81dea28 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g58_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g58_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g58_s1_lives[] = { /* 0x81dea58 */
    /*  0 */ {  77,   4,   0,   0, {  52,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g58_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g59_s0_lives[] = { /* 0x81dea70 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g59_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g59_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g60_s0_lives[] = { /* 0x81deaa0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g60_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g60_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g61_s0_lives[] = { /* 0x81dead0 */
    /*  0 */ {  34,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g61_s0_lives0_dlg0,
        [2] = s_gs9_g61_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g61_s1_lives[] = { /* 0x81deae8 */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g61_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g61_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g62_s0_lives[] = { /* 0x81deb18 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g62_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g62_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g63_s0_lives[] = { /* 0x81deb48 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g63_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g63_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g64_s1_lives[] = { /* 0x81deb78 */
    /*  0 */ {   0,   2,   0,   0, {   5,  40, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g64_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g65_s0_lives[] = { /* 0x81deb90 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g65_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g65_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g67_s0_lives[] = { /* 0x81debc0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g67_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g67_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g68_s0_lives[] = { /* 0x81debf0 */
    /*  0 */ {   0,   4,   0,   0, {  34,  51, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  34,  36, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g68_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   3,   0,   0, {  32,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives2_dlg0,
    } },
    /*  3 */ {  94,   5,   0,   0, {  36,  39, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g68_s0_lives3_dlg0,
    } },
    /*  4 */ {  78,   5,   0,   0, {  38,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives4_dlg0,
    } },
    /*  5 */ {  95,   5,   0,   0, {  40,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives5_dlg0,
    } },
    /*  6 */ {  80,   5,   0,   0, {  25,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives6_dlg0,
    } },
    /*  7 */ {  79,   0,   0,   0, {  28,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives7_dlg0,
    } },
    /*  8 */ {  77,   6,   0,   0, {  38,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives8_dlg0,
    } },
    /*  9 */ {  85,   2,   0,   0, {  44,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives9_dlg0,
    } },
    /* 10 */ {  88,   6,   0,   0, {  34,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives10_dlg0,
    } },
    /* 11 */ {  89,   0,   0,   0, {  30,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives11_dlg0,
    } },
    /* 12 */ {  90,   1,   0,   0, {  38,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g68_s0_lives12_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g69_s0_lives[] = { /* 0x81ded28 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g69_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  34,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g69_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   4,   0,   0, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g69_s0_lives2_dlg0,
    } },
    /*  3 */ {  94,   4,   0,   0, {  37,  45, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g69_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g71_s0_lives[] = { /* 0x81ded88 */
    /*  0 */ {   0,   0,   0,   0, {  34,  62, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g71_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   0,   0,   0, {  34,  64, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g71_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g72_s0_lives[] = { /* 0x81dedb8 */
    /*  0 */ {   0,   6,   0,   0, {  37,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g72_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   2,   0,   0, {  32,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g72_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g72_s1_lives[] = { /* 0x81dede8 */
    /*  0 */ {   7,   2,   0,   0, {  32,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g72_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g72_s2_lives[] = { /* 0x81dee00 */
    /*  0 */ {   7,   2,   0,   0, {  32,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g72_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g74_s0_lives[] = { /* 0x81dee18 */
    /*  0 */ {   0,   6,   0,   0, {  34,  46, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g74_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  34,  43, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g74_s0_lives1_dlg0,
    } },
    /*  2 */ { 109,   6,   0,   0, {  57,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g74_s0_lives2_dlg0,
    } },
    /*  3 */ { 110,   6,   0,   0, {  60,  43, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g74_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g75_s0_lives[] = { /* 0x81dee78 */
    /*  0 */ {   0,   4,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives1_dlg0,
    } },
    /*  2 */ { 109,   0,   0,   0, {  36,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives2_dlg0,
    } },
    /*  3 */ { 110,   0,   0,   0, {  32,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives3_dlg0,
    } },
    /*  4 */ { 112,   4,   0,   0, {  34,  57, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives4_dlg0,
    } },
    /*  5 */ { 113,   4,   0,   0, {  32,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives5_dlg0,
    } },
    /*  6 */ { 114,   4,   0,   0, {  36,  60, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives6_dlg0,
    } },
    /*  7 */ {  54,   0,   0,   0, {  53,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s0_lives7_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g75_s1_lives[] = { /* 0x81def38 */
    /*  0 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s1_lives0_dlg0,
    } },
    /*  1 */ { 112,   4,   0,   0, {  34,  48, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s1_lives1_dlg0,
    } },
    /*  2 */ { 113,   4,   0,   0, {  32,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s1_lives2_dlg0,
    } },
    /*  3 */ { 114,   4,   0,   0, {  36,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s1_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g75_s2_lives[] = { /* 0x81def98 */
    /*  0 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s2_lives0_dlg0,
    } },
    /*  1 */ { 112,   4,   0,   0, {  34,  48, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s2_lives1_dlg0,
    } },
    /*  2 */ { 113,   4,   0,   0, {  32,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s2_lives2_dlg0,
    } },
    /*  3 */ { 114,   4,   0,   0, {  36,  50, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g75_s2_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g76_s0_lives[] = { /* 0x81deff8 */
    /*  0 */ {   0,   4,   0,   0, {  37,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  35,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives1_dlg0,
    } },
    /*  2 */ { 109,   4,   0,   0, {  32,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives2_dlg0,
    } },
    /*  3 */ { 110,   3,   0,   0, {  29,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives3_dlg0,
    } },
    /*  4 */ { 112,   0,   0,   0, {  24,  45, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g76_s0_lives4_dlg0,
    } },
    /*  5 */ { 113,   0,   0,   0, {  24,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives5_dlg0,
    } },
    /*  6 */ { 114,   0,   0,   0, {  27,  43, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g76_s0_lives6_dlg0,
    } },
    /*  7 */ {  54,   5,   0,   0, {  39,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g76_s0_lives7_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g77_s0_lives[] = { /* 0x81df0b8 */
    /*  0 */ { 112,   0,   0,   0, {  23,  43, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g77_s0_lives0_dlg0,
        [2] = s_gs9_g77_s0_lives0_dlg2,
    } },
    /*  1 */ { 113,   0,   0,   0, {  24,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s0_lives1_dlg0,
        [2] = s_gs9_g77_s0_lives1_dlg2,
    } },
    /*  2 */ { 114,   0,   0,   0, {  27,  41, CPOS_HALFTILE, 0 }, {
        [0] = s_gs9_g77_s0_lives2_dlg0,
        [2] = s_gs9_g77_s0_lives2_dlg2,
    } },
    /*  3 */ { 109,   2,   0,   0, {  29,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s0_lives3_dlg0,
        [2] = s_gs9_g77_s0_lives3_dlg2,
    } },
    /*  4 */ { 110,   6,   0,   0, {  43,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs9_g77_s0_lives4_dlg2,
        [3] = s_gs9_g77_s0_lives4_dlg3,
    } },
};

static const struct GroundLivesData s_gs9_g77_s1_lives[] = { /* 0x81df130 */
    /*  0 */ {   0,   4,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s1_lives1_dlg0,
    } },
    /*  2 */ { 112,   0,   0,   0, {  23,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s1_lives2_dlg0,
    } },
    /*  3 */ { 113,   0,   0,   0, {  24,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s1_lives3_dlg0,
    } },
    /*  4 */ { 114,   0,   0,   0, {  27,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s1_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g77_s2_lives[] = { /* 0x81df1a8 */
    /*  0 */ { 112,   4,   0,   0, {  23,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s2_lives0_dlg0,
    } },
    /*  1 */ { 113,   4,   0,   0, {  24,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s2_lives1_dlg0,
    } },
    /*  2 */ { 114,   4,   0,   0, {  27,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s2_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g77_s3_lives[] = { /* 0x81df1f0 */
    /*  0 */ { 112,   4,   0,   0, {  22,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s3_lives0_dlg0,
    } },
    /*  1 */ { 113,   4,   0,   0, {  24,  39, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s3_lives1_dlg0,
    } },
    /*  2 */ { 114,   4,   0,   0, {  27,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g77_s3_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g78_s0_lives[] = { /* 0x81df238 */
    /*  0 */ {   0,   4,   0,   0, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  38,  43, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives1_dlg0,
    } },
    /*  2 */ { 109,   4,   0,   0, {  37,  47, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives2_dlg0,
    } },
    /*  3 */ { 110,   4,   0,   0, {  40,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives3_dlg0,
    } },
    /*  4 */ { 112,   4,   0,   0, {  31,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives4_dlg0,
    } },
    /*  5 */ { 113,   4,   0,   0, {  28,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives5_dlg0,
    } },
    /*  6 */ { 114,   4,   0,   0, {  30,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives6_dlg0,
    } },
    /*  7 */ {  54,   4,   0,   0, {  34,  46, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g78_s0_lives7_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g79_s0_lives[] = { /* 0x81df2f8 */
    /*  0 */ {   1,   4,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s0_lives1_dlg0,
    } },
    /*  2 */ { 124,   0,   0,   0, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s0_lives2_dlg0,
    } },
    /*  3 */ { 126,   4,   0,   0, {  32,  63, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s0_lives3_dlg0,
    } },
    /*  4 */ { 125,   4,   0,   0, {  36,  63, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g79_s1_lives[] = { /* 0x81df370 */
    /*  0 */ { 124,   0,   0,   0, {  25,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g79_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g80_s0_lives[] = { /* 0x81df388 */
    /*  0 */ {  93,   0,   0,   0, {  63,  45, 0, CPOS_HALFTILE }, {
        [1] = s_gs9_g80_s0_lives0_dlg1,
        [2] = s_gs9_g80_s0_lives0_dlg2,
        [3] = s_gs9_g80_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs9_g81_s0_lives[] = { /* 0x81df3a0 */
    /*  0 */ {   1,   4,   0,   0, {  32,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g81_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g81_s0_lives1_dlg0,
    } },
    /*  2 */ {  97,   0,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g81_s0_lives2_dlg0,
    } },
    /*  3 */ { 104,   6,   0,   0, {  52,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g81_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g83_s0_lives[] = { /* 0x81df400 */
    /*  0 */ {  33,   0,   0,   0, {  34,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g83_s0_lives0_dlg0,
    } },
    /*  1 */ { 121,   6,   0,   0, {  54,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g83_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g84_s0_lives[] = { /* 0x81df430 */
    /*  0 */ {   0,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g84_s0_lives0_dlg0,
    } },
    /*  1 */ {  93,   0,   0,   0, {  31,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g84_s0_lives1_dlg0,
        [2] = s_gs9_g84_s0_lives1_dlg2,
    } },
    /*  2 */ {  92,   0,   0,   0, {  37,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g84_s0_lives2_dlg0,
        [2] = s_gs9_g84_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g85_s0_lives[] = { /* 0x81df478 */
    /*  0 */ {  33,   4,   0,   0, {  37,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g85_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs9_g85_s0_lives1_dlg0,
    } },
    /*  2 */ {  32,   0,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g85_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g86_s0_lives[] = { /* 0x81df4c0 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g86_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g86_s1_lives[] = { /* 0x81df4d8 */
    /*  0 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g86_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g86_s2_lives[] = { /* 0x81df4f0 */
    /*  0 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g86_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g86_s3_lives[] = { /* 0x81df508 */
    /*  0 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g86_s3_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g87_s0_lives[] = { /* 0x81df520 */
    /*  0 */ {  91,   0,   0,   0, {  25,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs9_g87_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g88_s0_lives[] = { /* 0x81df538 */
    /*  0 */ {   0,   4,   0,   0, {  34,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g88_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   0,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g88_s0_lives1_dlg0,
        [2] = s_gs9_g88_s0_lives1_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g89_s0_lives[] = { /* 0x81df568 */
    /*  0 */ {   0,   0,   0,   0, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g89_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g89_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g89_s1_lives[] = { /* 0x81df598 */
    /*  0 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g89_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g89_s2_lives[] = { /* 0x81df5b0 */
    /*  0 */ {  91,   4,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g89_s2_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs9_g90_s0_lives[] = { /* 0x81df5c8 */
    /*  0 */ {  91,   0,   0,   0, {  25,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs9_g90_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs9_g91_s0_lives[] = { /* 0x81df5e0 */
    /*  0 */ {   0,   4,   0,   0, {  31,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g91_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  37,  44, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g91_s0_lives1_dlg0,
    } },
    /*  2 */ {  82,   0,   0,   0, {  34,  40, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs9_g91_s0_lives2_dlg0,
    } },
};

static const struct GroundObjectData s_gs9_g0_s0_objs[] = { /* 0x81df628 */
    /*  0 */ {  13,   0,   3,   4, {  31,  34, CPOS_HALFTILE, 0 }, {
        [2] = s_gs9_g0_s0_obj0_dlg2,
    } },
    /*  1 */ {  26,   0,   4,   3, {  27,  16, 0, CPOS_HALFTILE }, {} },
    /*  2 */ {  15,   0,   3,   2, {   8,  42, CPOS_HALFTILE, 0 }, {
        [2] = s_gs9_g0_s0_obj2_dlg2,
    } },
    /*  3 */ {  65,   0,   2,   2, {  50,  33, 0, 0 }, {
        [0] = s_gs9_g0_s0_obj3_dlg0,
    } },
    /*  4 */ {  62,   0,   2,   2, {  54,  34, 0, 0 }, {
        [0] = s_gs9_g0_s0_obj4_dlg0,
    } },
    /*  5 */ {  63,   0,   2,   2, {  63,  32, 0, 0 }, {
        [0] = s_gs9_g0_s0_obj5_dlg0,
    } },
    /*  6 */ {  64,   0,   2,   2, {  59,  34, 0, 0 }, {
        [0] = s_gs9_g0_s0_obj6_dlg0,
    } },
};

static const struct GroundObjectData s_gs9_g2_s2_objs[] = { /* 0x81df6d0 */
    /*  0 */ {  64,   0,   2,   2, {  59,  34, 0, 0 }, {
        [0] = s_gs9_g2_s2_obj0_dlg0,
    } },
};

static const struct GroundObjectData s_gs9_g19_s0_objs[] = { /* 0x81df6e8 */
    /*  0 */ {  13,   0,   3,   4, {  31,  34, CPOS_HALFTILE, 0 }, {
        [2] = s_gs9_g19_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs9_g24_s0_objs[] = { /* 0x81df700 */
    /*  0 */ {  13,   0,   3,   4, {  31,  34, CPOS_HALFTILE, 0 }, {
        [2] = s_gs9_g24_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs9_g2_s0_effs[] = { /* 0x81df718 */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g2_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g2_s1_effs[] = { /* 0x81df724 */
    /*  0 */ {   2,   4,   1,   1, {  54,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g2_s1_eff0_script },
};

static const struct GroundEffectData s_gs9_g5_s0_effs[] = { /* 0x81df730 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g6_s0_effs[] = { /* 0x81df73c */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g7_s0_effs[] = { /* 0x81df748 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g17_s0_effs[] = { /* 0x81df754 */
    /*  0 */ {   0,   0,   1,   1, {  34,  38, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g17_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g18_s0_effs[] = { /* 0x81df760 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g18_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g20_s0_effs[] = { /* 0x81df76c */
    /*  0 */ {   0,   0,   1,   1, {  34,  36, 0, CPOS_HALFTILE }, s_gs9_g20_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g21_s0_effs[] = { /* 0x81df778 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g23_s0_effs[] = { /* 0x81df784 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g25_s0_effs[] = { /* 0x81df790 */
    /*  0 */ {   0,   0,   1,   1, {  34,  36, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g25_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g26_s0_effs[] = { /* 0x81df79c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g27_s0_effs[] = { /* 0x81df7a8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g28_s0_effs[] = { /* 0x81df7b4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g28_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g29_s0_effs[] = { /* 0x81df7c0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g30_s0_effs[] = { /* 0x81df7cc */
    /*  0 */ {   0,   0,   1,   1, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g30_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g31_s0_effs[] = { /* 0x81df7d8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g31_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g33_s0_effs[] = { /* 0x81df7e4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g34_s0_effs[] = { /* 0x81df7f0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g35_s0_effs[] = { /* 0x81df7fc */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g36_s0_effs[] = { /* 0x81df808 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g38_s0_effs[] = { /* 0x81df814 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g39_s0_effs[] = { /* 0x81df820 */
    /*  0 */ {   0,   0,   1,   1, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g39_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g40_s0_effs[] = { /* 0x81df82c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g42_s0_effs[] = { /* 0x81df838 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g43_s0_effs[] = { /* 0x81df844 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g43_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g44_s0_effs[] = { /* 0x81df850 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g45_s0_effs[] = { /* 0x81df85c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g46_s0_effs[] = { /* 0x81df868 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g47_s0_effs[] = { /* 0x81df874 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g48_s0_effs[] = { /* 0x81df880 */
    /*  0 */ {   0,   0,   1,   1, {  36,  44, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g48_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g49_s0_effs[] = { /* 0x81df88c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g52_s0_effs[] = { /* 0x81df898 */
    /*  0 */ {   0,   0,   1,   1, {  39,  44, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g53_s0_effs[] = { /* 0x81df8a4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g53_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g55_s0_effs[] = { /* 0x81df8b0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g57_s0_effs[] = { /* 0x81df8bc */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g58_s0_effs[] = { /* 0x81df8c8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g58_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g59_s0_effs[] = { /* 0x81df8d4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g60_s0_effs[] = { /* 0x81df8e0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g60_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g62_s0_effs[] = { /* 0x81df8ec */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g62_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g63_s0_effs[] = { /* 0x81df8f8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g65_s0_effs[] = { /* 0x81df904 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g67_s0_effs[] = { /* 0x81df910 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g68_s0_effs[] = { /* 0x81df91c */
    /*  0 */ {   0,   0,   1,   1, {  34,  22, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g68_s0_eff0_script },
    /*  1 */ {   5,   0,   1,   1, {  34,  37, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g68_s0_eff1_script },
    /*  2 */ {   4,   0,   1,   1, {  34,  51, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g68_s0_eff2_script },
};

static const struct GroundEffectData s_gs9_g69_s0_effs[] = { /* 0x81df940 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g69_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g72_s0_effs[] = { /* 0x81df94c */
    /*  0 */ {   0,   0,   1,   1, {  34,  41, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g74_s0_effs[] = { /* 0x81df958 */
    /*  0 */ {   0,   0,   1,   1, {  34,  45, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g74_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g75_s0_effs[] = { /* 0x81df964 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g75_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g76_s0_effs[] = { /* 0x81df970 */
    /*  0 */ {   0,   0,   1,   1, {  34,   8, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g76_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g77_s1_effs[] = { /* 0x81df97c */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g77_s1_eff0_script },
};

static const struct GroundEffectData s_gs9_g78_s0_effs[] = { /* 0x81df988 */
    /*  0 */ {   0,   0,   1,   1, {  34,  48, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g78_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g79_s0_effs[] = { /* 0x81df994 */
    /*  0 */ {   0,   0,   1,   1, {  34,  43, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs9_g79_s0_eff0_script },
};

static const struct GroundEffectData s_gs9_g81_s0_effs[] = { /* 0x81df9a0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g82_s0_effs[] = { /* 0x81df9ac */
    /*  0 */ {   0,   0,   1,   1, {  34,  28, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g83_s0_effs[] = { /* 0x81df9b8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
    /*  1 */ {   5,   0,   1,   1, {  49,  40, 0, CPOS_HALFTILE }, s_gs9_g83_s0_eff1_script },
};

static const struct GroundEffectData s_gs9_g84_s0_effs[] = { /* 0x81df9d0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g85_s0_effs[] = { /* 0x81df9dc */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g86_s0_effs[] = { /* 0x81df9e8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g88_s0_effs[] = { /* 0x81df9f4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g89_s0_effs[] = { /* 0x81dfa00 */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs9_g91_s0_effs[] = { /* 0x81dfa0c */
    /*  0 */ {   0,   0,   1,   1, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs9_g0_s0_evts[] = { /* 0x81dfa18 */
    /*  0 */ {   3,  12,   0,   0, {  66,  37, 0, 0 }, &s_gs9_g0_s0_evt0_sref },
    /*  1 */ {   3,  12,   0,   0, {   0,  39, 0, 0 }, &s_gs9_g0_s0_evt1_sref },
    /*  2 */ {  23,   3,   0,   0, {  24,  66, 0, 0 }, &s_gs9_g0_s0_evt2_sref },
    /*  3 */ {   3,   3,   0,   0, {  33,  24, 0, 0 }, &s_gs9_g0_s0_evt3_sref },
};

static const struct GroundEventData s_gs9_g19_s0_evts[] = { /* 0x81dfa48 */
    /*  0 */ {  15,   3,   0,   0, {  27,  39, 0, 0 }, &s_gs9_g19_s0_evt0_sref },
};

static const struct GroundEventData s_gs9_g24_s0_evts[] = { /* 0x81dfa54 */
    /*  0 */ {  15,   3,   0,   0, {  27,  39, 0, 0 }, &s_gs9_g24_s0_evt0_sref },
};

static const struct GroundEventData s_gs9_g50_s1_evts[] = { /* 0x81dfa60 */
    /*  0 */ {   9,   3,   0,   0, {  30,  36, 0, 0 }, &s_gs9_g50_s1_evt0_sref },
};

static const struct GroundEventData s_gs9_g73_s0_evts[] = { /* 0x81dfa6c */
    /*  0 */ {  15,   3,   0,   0, {  27,  39, 0, 0 }, &s_gs9_g73_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81dfa78 */
    &s_gs9_g0_s0_station_sref,
    &s_gs9_g1_s0_station_sref,
    &s_gs9_g2_s0_station_sref,
    &s_gs9_g3_s0_station_sref,
    &s_gs9_g4_s0_station_sref,
    &s_gs9_g5_s0_station_sref,
    &s_gs9_g6_s0_station_sref,
    &s_gs9_g7_s0_station_sref,
    &s_gs9_g8_s0_station_sref,
    &s_gs9_g17_s0_station_sref,
    &s_gs9_g18_s0_station_sref,
    &s_gs9_g19_s0_station_sref,
    &s_gs9_g19_s1_station_sref,
    &s_gs9_g20_s0_station_sref,
    &s_gs9_g21_s0_station_sref,
    &s_gs9_g22_s0_station_sref,
    &s_gs9_g22_s1_station_sref,
    &s_gs9_g22_s2_station_sref,
    &s_gs9_g23_s0_station_sref,
    &s_gs9_g24_s0_station_sref,
    &s_gs9_g24_s1_station_sref,
    &s_gs9_g25_s0_station_sref,
    &s_gs9_g26_s0_station_sref,
    &s_gs9_g27_s0_station_sref,
    &s_gs9_g28_s0_station_sref,
    &s_gs9_g29_s0_station_sref,
    &s_gs9_g30_s0_station_sref,
    &s_gs9_g31_s0_station_sref,
    &s_gs9_g32_s0_station_sref,
    &s_gs9_g33_s0_station_sref,
    &s_gs9_g34_s0_station_sref,
    &s_gs9_g35_s0_station_sref,
    &s_gs9_g36_s0_station_sref,
    &s_gs9_g37_s0_station_sref,
    &s_gs9_g38_s0_station_sref,
    &s_gs9_g39_s0_station_sref,
    &s_gs9_g40_s0_station_sref,
    &s_gs9_g41_s0_station_sref,
    &s_gs9_g42_s0_station_sref,
    &s_gs9_g43_s0_station_sref,
    &s_gs9_g44_s0_station_sref,
    &s_gs9_g45_s0_station_sref,
    &s_gs9_g46_s0_station_sref,
    &s_gs9_g47_s0_station_sref,
    &s_gs9_g48_s0_station_sref,
    &s_gs9_g49_s0_station_sref,
    &s_gs9_g50_s0_station_sref,
    &s_gs9_g50_s2_station_sref,
    &s_gs9_g50_s3_station_sref,
    &s_gs9_g51_s0_station_sref,
    &s_gs9_g52_s0_station_sref,
    &s_gs9_g53_s0_station_sref,
    &s_gs9_g55_s0_station_sref,
    &s_gs9_g56_s0_station_sref,
    &s_gs9_g57_s0_station_sref,
    &s_gs9_g58_s0_station_sref,
    &s_gs9_g59_s0_station_sref,
    &s_gs9_g60_s0_station_sref,
    &s_gs9_g61_s0_station_sref,
    &s_gs9_g61_s1_station_sref,
    &s_gs9_g62_s0_station_sref,
    &s_gs9_g63_s0_station_sref,
    &s_gs9_g64_s0_station_sref,
    &s_gs9_g64_s1_station_sref,
    &s_gs9_g65_s0_station_sref,
    &s_gs9_g66_s0_station_sref,
    &s_gs9_g67_s0_station_sref,
    &s_gs9_g68_s0_station_sref,
    &s_gs9_g69_s0_station_sref,
    &s_gs9_g70_s0_station_sref,
    &s_gs9_g71_s0_station_sref,
    &s_gs9_g72_s0_station_sref,
    &s_gs9_g74_s0_station_sref,
    &s_gs9_g75_s0_station_sref,
    &s_gs9_g76_s0_station_sref,
    &s_gs9_g77_s0_station_sref,
    &s_gs9_g77_s1_station_sref,
    &s_gs9_g78_s0_station_sref,
    &s_gs9_g79_s0_station_sref,
    &s_gs9_g81_s0_station_sref,
    &s_gs9_g82_s0_station_sref,
    &s_gs9_g83_s0_station_sref,
    &s_gs9_g84_s0_station_sref,
    &s_gs9_g85_s0_station_sref,
    &s_gs9_g86_s0_station_sref,
    &s_gs9_g88_s0_station_sref,
    &s_gs9_g89_s0_station_sref,
    &s_gs9_g91_s0_station_sref,
};

static const struct GroundScriptSector s_gs9_g0_sectors[] = { /* 0x81dfbd8 */
    { 0,NULL, LPARRAY(s_gs9_g0_s0_objs), 0,NULL, LPARRAY(s_gs9_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs9_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s5_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s6_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g0_s7_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g1_sectors[] = { /* 0x81dfd18 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs9_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g2_sectors[] = { /* 0x81dfd68 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs9_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
    { LPARRAY(s_gs9_g2_s1_lives), 0,NULL, LPARRAY(s_gs9_g2_s1_effs), 0,NULL, 0,NULL, },
    { 0,NULL, LPARRAY(s_gs9_g2_s2_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g3_sectors[] = { /* 0x81dfde0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs9_g4_sectors[] = { /* 0x81dfe08 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs9_g5_sectors[] = { /* 0x81dfe30 */
    { LPARRAY(s_gs9_g5_s0_lives), 0,NULL, LPARRAY(s_gs9_g5_s0_effs), 0,NULL, 1,&sStationScripts[5], },
    { LPARRAY(s_gs9_g5_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g6_sectors[] = { /* 0x81dfe80 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs9_g6_s0_effs), 0,NULL, 1,&sStationScripts[6], },
    { LPARRAY(s_gs9_g6_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g6_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g7_sectors[] = { /* 0x81dfef8 */
    { LPARRAY(s_gs9_g7_s0_lives), 0,NULL, LPARRAY(s_gs9_g7_s0_effs), 0,NULL, 1,&sStationScripts[7], },
    { LPARRAY(s_gs9_g7_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g8_sectors[] = { /* 0x81dff48 */
    { LPARRAY(s_gs9_g8_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[8], },
};

static const struct GroundScriptSector s_gs9_g9_sectors[] = { /* 0x81dff70 */
    { LPARRAY(s_gs9_g9_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g10_sectors[] = { /* 0x81dff98 */
    { LPARRAY(s_gs9_g10_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g11_sectors[] = { /* 0x81dffc0 */
    { LPARRAY(s_gs9_g11_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g12_sectors[] = { /* 0x81dffe8 */
    { LPARRAY(s_gs9_g12_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g13_sectors[] = { /* 0x81e0010 */
    { LPARRAY(s_gs9_g13_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g14_sectors[] = { /* 0x81e0038 */
    { LPARRAY(s_gs9_g14_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g15_sectors[] = { /* 0x81e0060 */
    { LPARRAY(s_gs9_g15_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g16_sectors[] = { /* 0x81e0088 */
    { LPARRAY(s_gs9_g16_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g17_sectors[] = { /* 0x81e00b0 */
    { LPARRAY(s_gs9_g17_s0_lives), 0,NULL, LPARRAY(s_gs9_g17_s0_effs), 0,NULL, 1,&sStationScripts[9], },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g17_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g17_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g18_sectors[] = { /* 0x81e0150 */
    { LPARRAY(s_gs9_g18_s0_lives), 0,NULL, LPARRAY(s_gs9_g18_s0_effs), 0,NULL, 1,&sStationScripts[10], },
};

static const struct GroundScriptSector s_gs9_g19_sectors[] = { /* 0x81e0178 */
    { LPARRAY(s_gs9_g19_s0_lives), LPARRAY(s_gs9_g19_s0_objs), 0,NULL, LPARRAY(s_gs9_g19_s0_evts), 1,&sStationScripts[11], },
    { LPARRAY(s_gs9_g19_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[12], },
};

static const struct GroundScriptSector s_gs9_g20_sectors[] = { /* 0x81e01c8 */
    { LPARRAY(s_gs9_g20_s0_lives), 0,NULL, LPARRAY(s_gs9_g20_s0_effs), 0,NULL, 1,&sStationScripts[13], },
    { LPARRAY(s_gs9_g20_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g20_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g21_sectors[] = { /* 0x81e0240 */
    { LPARRAY(s_gs9_g21_s0_lives), 0,NULL, LPARRAY(s_gs9_g21_s0_effs), 0,NULL, 1,&sStationScripts[14], },
};

static const struct GroundScriptSector s_gs9_g22_sectors[] = { /* 0x81e0268 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[15], },
    { LPARRAY(s_gs9_g22_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[16], },
    { LPARRAY(s_gs9_g22_s2_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[17], },
};

static const struct GroundScriptSector s_gs9_g23_sectors[] = { /* 0x81e02e0 */
    { LPARRAY(s_gs9_g23_s0_lives), 0,NULL, LPARRAY(s_gs9_g23_s0_effs), 0,NULL, 1,&sStationScripts[18], },
};

static const struct GroundScriptSector s_gs9_g24_sectors[] = { /* 0x81e0308 */
    { 0,NULL, LPARRAY(s_gs9_g24_s0_objs), 0,NULL, LPARRAY(s_gs9_g24_s0_evts), 1,&sStationScripts[19], },
    { LPARRAY(s_gs9_g24_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[20], },
};

static const struct GroundScriptSector s_gs9_g25_sectors[] = { /* 0x81e0358 */
    { LPARRAY(s_gs9_g25_s0_lives), 0,NULL, LPARRAY(s_gs9_g25_s0_effs), 0,NULL, 1,&sStationScripts[21], },
};

static const struct GroundScriptSector s_gs9_g26_sectors[] = { /* 0x81e0380 */
    { LPARRAY(s_gs9_g26_s0_lives), 0,NULL, LPARRAY(s_gs9_g26_s0_effs), 0,NULL, 1,&sStationScripts[22], },
    { LPARRAY(s_gs9_g26_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g27_sectors[] = { /* 0x81e03d0 */
    { LPARRAY(s_gs9_g27_s0_lives), 0,NULL, LPARRAY(s_gs9_g27_s0_effs), 0,NULL, 1,&sStationScripts[23], },
};

static const struct GroundScriptSector s_gs9_g28_sectors[] = { /* 0x81e03f8 */
    { LPARRAY(s_gs9_g28_s0_lives), 0,NULL, LPARRAY(s_gs9_g28_s0_effs), 0,NULL, 1,&sStationScripts[24], },
    { LPARRAY(s_gs9_g28_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g29_sectors[] = { /* 0x81e0448 */
    { LPARRAY(s_gs9_g29_s0_lives), 0,NULL, LPARRAY(s_gs9_g29_s0_effs), 0,NULL, 1,&sStationScripts[25], },
};

static const struct GroundScriptSector s_gs9_g30_sectors[] = { /* 0x81e0470 */
    { LPARRAY(s_gs9_g30_s0_lives), 0,NULL, LPARRAY(s_gs9_g30_s0_effs), 0,NULL, 1,&sStationScripts[26], },
};

static const struct GroundScriptSector s_gs9_g31_sectors[] = { /* 0x81e0498 */
    { LPARRAY(s_gs9_g31_s0_lives), 0,NULL, LPARRAY(s_gs9_g31_s0_effs), 0,NULL, 1,&sStationScripts[27], },
};

static const struct GroundScriptSector s_gs9_g32_sectors[] = { /* 0x81e04c0 */
    { LPARRAY(s_gs9_g32_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[28], },
};

static const struct GroundScriptSector s_gs9_g33_sectors[] = { /* 0x81e04e8 */
    { LPARRAY(s_gs9_g33_s0_lives), 0,NULL, LPARRAY(s_gs9_g33_s0_effs), 0,NULL, 1,&sStationScripts[29], },
};

static const struct GroundScriptSector s_gs9_g34_sectors[] = { /* 0x81e0510 */
    { LPARRAY(s_gs9_g34_s0_lives), 0,NULL, LPARRAY(s_gs9_g34_s0_effs), 0,NULL, 1,&sStationScripts[30], },
};

static const struct GroundScriptSector s_gs9_g35_sectors[] = { /* 0x81e0538 */
    { LPARRAY(s_gs9_g35_s0_lives), 0,NULL, LPARRAY(s_gs9_g35_s0_effs), 0,NULL, 1,&sStationScripts[31], },
    { LPARRAY(s_gs9_g35_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g35_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g36_sectors[] = { /* 0x81e05b0 */
    { LPARRAY(s_gs9_g36_s0_lives), 0,NULL, LPARRAY(s_gs9_g36_s0_effs), 0,NULL, 1,&sStationScripts[32], },
};

static const struct GroundScriptSector s_gs9_g37_sectors[] = { /* 0x81e05d8 */
    { LPARRAY(s_gs9_g37_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[33], },
};

static const struct GroundScriptSector s_gs9_g38_sectors[] = { /* 0x81e0600 */
    { LPARRAY(s_gs9_g38_s0_lives), 0,NULL, LPARRAY(s_gs9_g38_s0_effs), 0,NULL, 1,&sStationScripts[34], },
};

static const struct GroundScriptSector s_gs9_g39_sectors[] = { /* 0x81e0628 */
    { LPARRAY(s_gs9_g39_s0_lives), 0,NULL, LPARRAY(s_gs9_g39_s0_effs), 0,NULL, 1,&sStationScripts[35], },
};

static const struct GroundScriptSector s_gs9_g40_sectors[] = { /* 0x81e0650 */
    { LPARRAY(s_gs9_g40_s0_lives), 0,NULL, LPARRAY(s_gs9_g40_s0_effs), 0,NULL, 1,&sStationScripts[36], },
};

static const struct GroundScriptSector s_gs9_g41_sectors[] = { /* 0x81e0678 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[37], },
};

static const struct GroundScriptSector s_gs9_g42_sectors[] = { /* 0x81e06a0 */
    { LPARRAY(s_gs9_g42_s0_lives), 0,NULL, LPARRAY(s_gs9_g42_s0_effs), 0,NULL, 1,&sStationScripts[38], },
};

static const struct GroundScriptSector s_gs9_g43_sectors[] = { /* 0x81e06c8 */
    { LPARRAY(s_gs9_g43_s0_lives), 0,NULL, LPARRAY(s_gs9_g43_s0_effs), 0,NULL, 1,&sStationScripts[39], },
};

static const struct GroundScriptSector s_gs9_g44_sectors[] = { /* 0x81e06f0 */
    { LPARRAY(s_gs9_g44_s0_lives), 0,NULL, LPARRAY(s_gs9_g44_s0_effs), 0,NULL, 1,&sStationScripts[40], },
};

static const struct GroundScriptSector s_gs9_g45_sectors[] = { /* 0x81e0718 */
    { LPARRAY(s_gs9_g45_s0_lives), 0,NULL, LPARRAY(s_gs9_g45_s0_effs), 0,NULL, 1,&sStationScripts[41], },
    { LPARRAY(s_gs9_g45_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g46_sectors[] = { /* 0x81e0768 */
    { LPARRAY(s_gs9_g46_s0_lives), 0,NULL, LPARRAY(s_gs9_g46_s0_effs), 0,NULL, 1,&sStationScripts[42], },
};

static const struct GroundScriptSector s_gs9_g47_sectors[] = { /* 0x81e0790 */
    { LPARRAY(s_gs9_g47_s0_lives), 0,NULL, LPARRAY(s_gs9_g47_s0_effs), 0,NULL, 1,&sStationScripts[43], },
};

static const struct GroundScriptSector s_gs9_g48_sectors[] = { /* 0x81e07b8 */
    { LPARRAY(s_gs9_g48_s0_lives), 0,NULL, LPARRAY(s_gs9_g48_s0_effs), 0,NULL, 1,&sStationScripts[44], },
    { LPARRAY(s_gs9_g48_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g48_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g49_sectors[] = { /* 0x81e0830 */
    { LPARRAY(s_gs9_g49_s0_lives), 0,NULL, LPARRAY(s_gs9_g49_s0_effs), 0,NULL, 1,&sStationScripts[45], },
};

static const struct GroundScriptSector s_gs9_g50_sectors[] = { /* 0x81e0858 */
    { LPARRAY(s_gs9_g50_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[46], },
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs9_g50_s1_evts), 0,NULL, },
    { LPARRAY(s_gs9_g50_s2_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[47], },
    { LPARRAY(s_gs9_g50_s3_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[48], },
};

static const struct GroundScriptSector s_gs9_g51_sectors[] = { /* 0x81e08f8 */
    { LPARRAY(s_gs9_g51_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[49], },
};

static const struct GroundScriptSector s_gs9_g52_sectors[] = { /* 0x81e0920 */
    { LPARRAY(s_gs9_g52_s0_lives), 0,NULL, LPARRAY(s_gs9_g52_s0_effs), 0,NULL, 1,&sStationScripts[50], },
};

static const struct GroundScriptSector s_gs9_g53_sectors[] = { /* 0x81e0948 */
    { LPARRAY(s_gs9_g53_s0_lives), 0,NULL, LPARRAY(s_gs9_g53_s0_effs), 0,NULL, 1,&sStationScripts[51], },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g53_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g55_sectors[] = { /* 0x81e09c0 */
    { LPARRAY(s_gs9_g55_s0_lives), 0,NULL, LPARRAY(s_gs9_g55_s0_effs), 0,NULL, 1,&sStationScripts[52], },
    { LPARRAY(s_gs9_g55_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g56_sectors[] = { /* 0x81e0a10 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[53], },
};

static const struct GroundScriptSector s_gs9_g57_sectors[] = { /* 0x81e0a38 */
    { LPARRAY(s_gs9_g57_s0_lives), 0,NULL, LPARRAY(s_gs9_g57_s0_effs), 0,NULL, 1,&sStationScripts[54], },
};

static const struct GroundScriptSector s_gs9_g58_sectors[] = { /* 0x81e0a60 */
    { LPARRAY(s_gs9_g58_s0_lives), 0,NULL, LPARRAY(s_gs9_g58_s0_effs), 0,NULL, 1,&sStationScripts[55], },
    { LPARRAY(s_gs9_g58_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g59_sectors[] = { /* 0x81e0ab0 */
    { LPARRAY(s_gs9_g59_s0_lives), 0,NULL, LPARRAY(s_gs9_g59_s0_effs), 0,NULL, 1,&sStationScripts[56], },
};

static const struct GroundScriptSector s_gs9_g60_sectors[] = { /* 0x81e0ad8 */
    { LPARRAY(s_gs9_g60_s0_lives), 0,NULL, LPARRAY(s_gs9_g60_s0_effs), 0,NULL, 1,&sStationScripts[57], },
};

static const struct GroundScriptSector s_gs9_g61_sectors[] = { /* 0x81e0b00 */
    { LPARRAY(s_gs9_g61_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[58], },
    { LPARRAY(s_gs9_g61_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[59], },
};

static const struct GroundScriptSector s_gs9_g62_sectors[] = { /* 0x81e0b50 */
    { LPARRAY(s_gs9_g62_s0_lives), 0,NULL, LPARRAY(s_gs9_g62_s0_effs), 0,NULL, 1,&sStationScripts[60], },
};

static const struct GroundScriptSector s_gs9_g63_sectors[] = { /* 0x81e0b78 */
    { LPARRAY(s_gs9_g63_s0_lives), 0,NULL, LPARRAY(s_gs9_g63_s0_effs), 0,NULL, 1,&sStationScripts[61], },
};

static const struct GroundScriptSector s_gs9_g64_sectors[] = { /* 0x81e0ba0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[62], },
    { LPARRAY(s_gs9_g64_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[63], },
};

static const struct GroundScriptSector s_gs9_g65_sectors[] = { /* 0x81e0bf0 */
    { LPARRAY(s_gs9_g65_s0_lives), 0,NULL, LPARRAY(s_gs9_g65_s0_effs), 0,NULL, 1,&sStationScripts[64], },
};

static const struct GroundScriptSector s_gs9_g66_sectors[] = { /* 0x81e0c18 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[65], },
};

static const struct GroundScriptSector s_gs9_g67_sectors[] = { /* 0x81e0c40 */
    { LPARRAY(s_gs9_g67_s0_lives), 0,NULL, LPARRAY(s_gs9_g67_s0_effs), 0,NULL, 1,&sStationScripts[66], },
};

static const struct GroundScriptSector s_gs9_g68_sectors[] = { /* 0x81e0c68 */
    { LPARRAY(s_gs9_g68_s0_lives), 0,NULL, LPARRAY(s_gs9_g68_s0_effs), 0,NULL, 1,&sStationScripts[67], },
};

static const struct GroundScriptSector s_gs9_g69_sectors[] = { /* 0x81e0c90 */
    { LPARRAY(s_gs9_g69_s0_lives), 0,NULL, LPARRAY(s_gs9_g69_s0_effs), 0,NULL, 1,&sStationScripts[68], },
};

static const struct GroundScriptSector s_gs9_g70_sectors[] = { /* 0x81e0cb8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[69], },
};

static const struct GroundScriptSector s_gs9_g71_sectors[] = { /* 0x81e0ce0 */
    { LPARRAY(s_gs9_g71_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[70], },
};

static const struct GroundScriptSector s_gs9_g72_sectors[] = { /* 0x81e0d08 */
    { LPARRAY(s_gs9_g72_s0_lives), 0,NULL, LPARRAY(s_gs9_g72_s0_effs), 0,NULL, 1,&sStationScripts[71], },
    { LPARRAY(s_gs9_g72_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g72_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g73_sectors[] = { /* 0x81e0d80 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs9_g73_s0_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g74_sectors[] = { /* 0x81e0da8 */
    { LPARRAY(s_gs9_g74_s0_lives), 0,NULL, LPARRAY(s_gs9_g74_s0_effs), 0,NULL, 1,&sStationScripts[72], },
};

static const struct GroundScriptSector s_gs9_g75_sectors[] = { /* 0x81e0dd0 */
    { LPARRAY(s_gs9_g75_s0_lives), 0,NULL, LPARRAY(s_gs9_g75_s0_effs), 0,NULL, 1,&sStationScripts[73], },
    { LPARRAY(s_gs9_g75_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g75_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g76_sectors[] = { /* 0x81e0e48 */
    { LPARRAY(s_gs9_g76_s0_lives), 0,NULL, LPARRAY(s_gs9_g76_s0_effs), 0,NULL, 1,&sStationScripts[74], },
};

static const struct GroundScriptSector s_gs9_g77_sectors[] = { /* 0x81e0e70 */
    { LPARRAY(s_gs9_g77_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[75], },
    { LPARRAY(s_gs9_g77_s1_lives), 0,NULL, LPARRAY(s_gs9_g77_s1_effs), 0,NULL, 1,&sStationScripts[76], },
    { LPARRAY(s_gs9_g77_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g77_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g78_sectors[] = { /* 0x81e0f10 */
    { LPARRAY(s_gs9_g78_s0_lives), 0,NULL, LPARRAY(s_gs9_g78_s0_effs), 0,NULL, 1,&sStationScripts[77], },
};

static const struct GroundScriptSector s_gs9_g79_sectors[] = { /* 0x81e0f38 */
    { LPARRAY(s_gs9_g79_s0_lives), 0,NULL, LPARRAY(s_gs9_g79_s0_effs), 0,NULL, 1,&sStationScripts[78], },
    { LPARRAY(s_gs9_g79_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g80_sectors[] = { /* 0x81e0f88 */
    { LPARRAY(s_gs9_g80_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g81_sectors[] = { /* 0x81e0fb0 */
    { LPARRAY(s_gs9_g81_s0_lives), 0,NULL, LPARRAY(s_gs9_g81_s0_effs), 0,NULL, 1,&sStationScripts[79], },
};

static const struct GroundScriptSector s_gs9_g82_sectors[] = { /* 0x81e0fd8 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs9_g82_s0_effs), 0,NULL, 1,&sStationScripts[80], },
};

static const struct GroundScriptSector s_gs9_g83_sectors[] = { /* 0x81e1000 */
    { LPARRAY(s_gs9_g83_s0_lives), 0,NULL, LPARRAY(s_gs9_g83_s0_effs), 0,NULL, 1,&sStationScripts[81], },
};

static const struct GroundScriptSector s_gs9_g84_sectors[] = { /* 0x81e1028 */
    { LPARRAY(s_gs9_g84_s0_lives), 0,NULL, LPARRAY(s_gs9_g84_s0_effs), 0,NULL, 1,&sStationScripts[82], },
};

static const struct GroundScriptSector s_gs9_g85_sectors[] = { /* 0x81e1050 */
    { LPARRAY(s_gs9_g85_s0_lives), 0,NULL, LPARRAY(s_gs9_g85_s0_effs), 0,NULL, 1,&sStationScripts[83], },
};

static const struct GroundScriptSector s_gs9_g86_sectors[] = { /* 0x81e1078 */
    { LPARRAY(s_gs9_g86_s0_lives), 0,NULL, LPARRAY(s_gs9_g86_s0_effs), 0,NULL, 1,&sStationScripts[84], },
    { LPARRAY(s_gs9_g86_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g86_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g86_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g87_sectors[] = { /* 0x81e1118 */
    { LPARRAY(s_gs9_g87_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g88_sectors[] = { /* 0x81e1140 */
    { LPARRAY(s_gs9_g88_s0_lives), 0,NULL, LPARRAY(s_gs9_g88_s0_effs), 0,NULL, 1,&sStationScripts[85], },
};

static const struct GroundScriptSector s_gs9_g89_sectors[] = { /* 0x81e1168 */
    { LPARRAY(s_gs9_g89_s0_lives), 0,NULL, LPARRAY(s_gs9_g89_s0_effs), 0,NULL, 1,&sStationScripts[86], },
    { LPARRAY(s_gs9_g89_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs9_g89_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g90_sectors[] = { /* 0x81e11e0 */
    { LPARRAY(s_gs9_g90_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs9_g91_sectors[] = { /* 0x81e1208 */
    { LPARRAY(s_gs9_g91_s0_lives), 0,NULL, LPARRAY(s_gs9_g91_s0_effs), 0,NULL, 1,&sStationScripts[87], },
};

static const struct GroundScriptGroup s_gs9_groups[] = { /* 0x81e1230 */
    { LPARRAY(s_gs9_g0_sectors) },
    { LPARRAY(s_gs9_g1_sectors) },
    { LPARRAY(s_gs9_g2_sectors) },
    { LPARRAY(s_gs9_g3_sectors) },
    { LPARRAY(s_gs9_g4_sectors) },
    { LPARRAY(s_gs9_g5_sectors) },
    { LPARRAY(s_gs9_g6_sectors) },
    { LPARRAY(s_gs9_g7_sectors) },
    { LPARRAY(s_gs9_g8_sectors) },
    { LPARRAY(s_gs9_g9_sectors) },
    { LPARRAY(s_gs9_g10_sectors) },
    { LPARRAY(s_gs9_g11_sectors) },
    { LPARRAY(s_gs9_g12_sectors) },
    { LPARRAY(s_gs9_g13_sectors) },
    { LPARRAY(s_gs9_g14_sectors) },
    { LPARRAY(s_gs9_g15_sectors) },
    { LPARRAY(s_gs9_g16_sectors) },
    { LPARRAY(s_gs9_g17_sectors) },
    { LPARRAY(s_gs9_g18_sectors) },
    { LPARRAY(s_gs9_g19_sectors) },
    { LPARRAY(s_gs9_g20_sectors) },
    { LPARRAY(s_gs9_g21_sectors) },
    { LPARRAY(s_gs9_g22_sectors) },
    { LPARRAY(s_gs9_g23_sectors) },
    { LPARRAY(s_gs9_g24_sectors) },
    { LPARRAY(s_gs9_g25_sectors) },
    { LPARRAY(s_gs9_g26_sectors) },
    { LPARRAY(s_gs9_g27_sectors) },
    { LPARRAY(s_gs9_g28_sectors) },
    { LPARRAY(s_gs9_g29_sectors) },
    { LPARRAY(s_gs9_g30_sectors) },
    { LPARRAY(s_gs9_g31_sectors) },
    { LPARRAY(s_gs9_g32_sectors) },
    { LPARRAY(s_gs9_g33_sectors) },
    { LPARRAY(s_gs9_g34_sectors) },
    { LPARRAY(s_gs9_g35_sectors) },
    { LPARRAY(s_gs9_g36_sectors) },
    { LPARRAY(s_gs9_g37_sectors) },
    { LPARRAY(s_gs9_g38_sectors) },
    { LPARRAY(s_gs9_g39_sectors) },
    { LPARRAY(s_gs9_g40_sectors) },
    { LPARRAY(s_gs9_g41_sectors) },
    { LPARRAY(s_gs9_g42_sectors) },
    { LPARRAY(s_gs9_g43_sectors) },
    { LPARRAY(s_gs9_g44_sectors) },
    { LPARRAY(s_gs9_g45_sectors) },
    { LPARRAY(s_gs9_g46_sectors) },
    { LPARRAY(s_gs9_g47_sectors) },
    { LPARRAY(s_gs9_g48_sectors) },
    { LPARRAY(s_gs9_g49_sectors) },
    { LPARRAY(s_gs9_g50_sectors) },
    { LPARRAY(s_gs9_g51_sectors) },
    { LPARRAY(s_gs9_g52_sectors) },
    { LPARRAY(s_gs9_g53_sectors) },
    {},
    { LPARRAY(s_gs9_g55_sectors) },
    { LPARRAY(s_gs9_g56_sectors) },
    { LPARRAY(s_gs9_g57_sectors) },
    { LPARRAY(s_gs9_g58_sectors) },
    { LPARRAY(s_gs9_g59_sectors) },
    { LPARRAY(s_gs9_g60_sectors) },
    { LPARRAY(s_gs9_g61_sectors) },
    { LPARRAY(s_gs9_g62_sectors) },
    { LPARRAY(s_gs9_g63_sectors) },
    { LPARRAY(s_gs9_g64_sectors) },
    { LPARRAY(s_gs9_g65_sectors) },
    { LPARRAY(s_gs9_g66_sectors) },
    { LPARRAY(s_gs9_g67_sectors) },
    { LPARRAY(s_gs9_g68_sectors) },
    { LPARRAY(s_gs9_g69_sectors) },
    { LPARRAY(s_gs9_g70_sectors) },
    { LPARRAY(s_gs9_g71_sectors) },
    { LPARRAY(s_gs9_g72_sectors) },
    { LPARRAY(s_gs9_g73_sectors) },
    { LPARRAY(s_gs9_g74_sectors) },
    { LPARRAY(s_gs9_g75_sectors) },
    { LPARRAY(s_gs9_g76_sectors) },
    { LPARRAY(s_gs9_g77_sectors) },
    { LPARRAY(s_gs9_g78_sectors) },
    { LPARRAY(s_gs9_g79_sectors) },
    { LPARRAY(s_gs9_g80_sectors) },
    { LPARRAY(s_gs9_g81_sectors) },
    { LPARRAY(s_gs9_g82_sectors) },
    { LPARRAY(s_gs9_g83_sectors) },
    { LPARRAY(s_gs9_g84_sectors) },
    { LPARRAY(s_gs9_g85_sectors) },
    { LPARRAY(s_gs9_g86_sectors) },
    { LPARRAY(s_gs9_g87_sectors) },
    { LPARRAY(s_gs9_g88_sectors) },
    { LPARRAY(s_gs9_g89_sectors) },
    { LPARRAY(s_gs9_g90_sectors) },
    { LPARRAY(s_gs9_g91_sectors) },
};

static const struct GroundLink s_gs9_links[] = { /* 0x81e1510 */
    /* link   0 */ { { /*x*/  31, /*y*/  36, /*flags*/ CPOS_HALFTILE|CPOS_CURRENT, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  31, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  31, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  31, /*y*/  35, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  16, /*y*/  35, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  34, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   6 */ { { /*x*/  34, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   7 */ { { /*x*/  34, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/  37, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/  37, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/  34, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  11 */ { { /*x*/  34, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  12 */ { { /*x*/  34, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  13 */ { { /*x*/  31, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  14 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  15 */ { { /*x*/  31, /*y*/  34, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 3 },
    /* link  16 */ { { /*x*/  34, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  17 */ { { /*x*/  34, /*y*/  66, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  18 */ { { /*x*/  15, /*y*/  46, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  19 */ { { /*x*/  34, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  20 */ { { /*x*/  50, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  21 */ { { /*x*/  50, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  22 */ { { /*x*/  38, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  23 */ { { /*x*/  34, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  24 */ { { /*x*/  34, /*y*/  55, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  25 */ { { /*x*/  34, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  26 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  27 */ { { /*x*/  34, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  28 */ { { /*x*/  31, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  29 */ { { /*x*/  34, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  30 */ { { /*x*/  34, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  31 */ { { /*x*/  34, /*y*/  35, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  32 */ { { /*x*/  34, /*y*/  54, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  33 */ { { /*x*/  37, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  34 */ { { /*x*/  37, /*y*/  37, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  35 */ { { /*x*/  37, /*y*/  54, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  36 */ { { /*x*/  31, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  37 */ { { /*x*/  31, /*y*/  37, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  38 */ { { /*x*/  31, /*y*/  54, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  39 */ { { /*x*/  34, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  40 */ { { /*x*/  51, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  41 */ { { /*x*/  36, /*y*/  46, /*flags*/ CPOS_CURRENT, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  42 */ { { /*x*/   1, /*y*/  46, /*flags*/ 0, CPOS_CURRENT }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  43 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  44 */ { { /*x*/  37, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  45 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  46 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  47 */ { { /*x*/  34, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  48 */ { { /*x*/  33, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  49 */ { { /*x*/  25, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  50 */ { { /*x*/  12, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  51 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  52 */ { { /*x*/  37, /*y*/  32, /*flags*/ 0, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  53 */ { { /*x*/  36, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  54 */ { { /*x*/  34, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  55 */ { { /*x*/  33, /*y*/  37, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  56 */ { { /*x*/  37, /*y*/  37, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  57 */ { { /*x*/  31, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  58 */ { { /*x*/  34, /*y*/  34, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  59 */ { { /*x*/  38, /*y*/  35, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  60 */ { { /*x*/  35, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  61 */ { { /*x*/  35, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  62 */ { { /*x*/  34, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  63 */ { { /*x*/  37, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  64 */ { { /*x*/  35, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  65 */ { { /*x*/  35, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  66 */ { { /*x*/  34, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  67 */ { { /*x*/  34, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  68 */ { { /*x*/  34, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  69 */ { { /*x*/  38, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  70 */ { { /*x*/  40, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  71 */ { { /*x*/  33, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  72 */ { { /*x*/  31, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  73 */ { { /*x*/  34, /*y*/  39, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  74 */ { { /*x*/  37, /*y*/  31, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  75 */ { { /*x*/  34, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  76 */ { { /*x*/  34, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  77 */ { { /*x*/  42, /*y*/  43, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  78 */ { { /*x*/  38, /*y*/  46, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  79 */ { { /*x*/  34, /*y*/  65, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  80 */ { { /*x*/  38, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  81 */ { { /*x*/  34, /*y*/  63, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  82 */ { { /*x*/  38, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  83 */ { { /*x*/  34, /*y*/  59, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  84 */ { { /*x*/  34, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  85 */ { { /*x*/  36, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  86 */ { { /*x*/  32, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  87 */ { { /*x*/  34, /*y*/  48, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  88 */ { { /*x*/  34, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  89 */ { { /*x*/  28, /*y*/  42, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  90 */ { { /*x*/  32, /*y*/  50, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  91 */ { { /*x*/  32, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  92 */ { { /*x*/  36, /*y*/  50, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  93 */ { { /*x*/  36, /*y*/  47, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  94 */ { { /*x*/  41, /*y*/  44, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  95 */ { { /*x*/  36, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  96 */ { { /*x*/  34, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  97 */ { { /*x*/  28, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  98 */ { { /*x*/  28, /*y*/  44, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  99 */ { { /*x*/  36, /*y*/  48, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 100 */ { { /*x*/  40, /*y*/  44, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 101 */ { { /*x*/  39, /*y*/  46, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 102 */ { { /*x*/  34, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 103 */ { { /*x*/  24, /*y*/  43, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 104 */ { { /*x*/  29, /*y*/  43, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 105 */ { { /*x*/  37, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 106 */ { { /*x*/  32, /*y*/  45, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 107 */ { { /*x*/  35, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 108 */ { { /*x*/  30, /*y*/  43, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 109 */ { { /*x*/  36, /*y*/  31, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 110 */ { { /*x*/  36, /*y*/  41, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 111 */ { { /*x*/  34, /*y*/  43, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 112 */ { { /*x*/  34, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 113 */ { { /*x*/  34, /*y*/  36, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 114 */ { { /*x*/  33, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 115 */ { { /*x*/  34, /*y*/  31, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 116 */ { { /*x*/  34, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 117 */ { { /*x*/  32, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 118 */ { { /*x*/  34, /*y*/  44, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 119 */ { { /*x*/  34, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 120 */ { { /*x*/  34, /*y*/  31, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 121 */ { { /*x*/  34, /*y*/  29, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 122 */ { { /*x*/  36, /*y*/  32, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 123 */ { { /*x*/  34, /*y*/  27, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 124 */ { { /*x*/  34, /*y*/  34, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 125 */ { { /*x*/  42, /*y*/  22, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 126 */ { { /*x*/  36, /*y*/  30, /*flags*/ CPOS_HALFTILE, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 127 */ { { /*x*/  36, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 128 */ { { /*x*/  34, /*y*/  60, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 129 */ { { /*x*/  34, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 130 */ { { /*x*/  25, /*y*/  29, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link 131 */ { { /*x*/  48, /*y*/  41, /*flags*/ 0, 0 }, /*w*/ 17, /*h*/  7, /*ret*/ 3, /*?*/ 2 },
    /* link 132 */ { { /*x*/  40, /*y*/  42, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link 133 */ { { /*x*/  37, /*y*/  40, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs9 = { LPARRAY(s_gs9_groups), s_gs9_links }; /* 0x81e1940 */
