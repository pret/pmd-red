







static const struct ScriptCommand s_gs6_g0_s0_station_sref_script[] = { /* 0x8198e20 */
    DEBUGINFO,
    SELECT_MAP(6),
    JUMP_LABEL(0),
  LABEL(0), /* = 0x00 */
    CALL_STATION(  1,  0),
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    CJUMP_VAR(START_MODE),
    COND_EQUAL(12, /* to label */ 2),
    COND_EQUAL(11, /* to label */ 2),
    COND_EQUAL(10, /* to label */ 3),
    COND_EQUAL(9, /* to label */ 4),
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 5),
    COND_EQUAL(7, /* to label */ 6),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(7),
  LABEL(2), /* = 0x02 */
    EXECUTE_SUBSTATION(-1, 4, 0),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    RET,
  LABEL(3), /* = 0x03 */
    EXECUTE_SUBSTATION(-1, 3, 0),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    RET,
  LABEL(4), /* = 0x04 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    { 0x3b, 0x0d,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 8),
    EXECUTE_SUBSTATION(-1, 2, 0),
    RET,
  LABEL(8), /* = 0x08 */
    EXECUTE_SUBSTATION(-1, 5, 0),
    RET,
  LABEL(7), /* = 0x07 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    BGM_SWITCH(7),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs6_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs6_g0_s0_station_sref_script }; /* 0x81990ec */

static const struct ScriptCommand s_gs6_g0_s0_evt0_sref_script[] = { /* 0x81990f8 */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs6_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs6_g0_s0_evt0_sref_script }; /* 0x8199128 */

static const struct ScriptCommand s_gs6_g0_s1_lives0_dlg0[] = { /* 0x8199134 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs6_g0_s1_lives1_dlg0[] = { /* 0x8199174 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs6_g0_s2_lives0_dlg0[] = { /* 0x81991b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs6_g0_s2_lives1_dlg0[] = { /* 0x81991f4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs6_g0_s3_evt0_sref_script[] = { /* 0x8199234 */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000054,  0x00000000, NULL },
    HALT,
    JUMPIF_EQUAL(WARP_LOCK, 0, /* to label */ 0),
    JUMP_LABEL(0),
    CALL_SCRIPT(EVENT_DIVIDE_WARP_LOCK_FUNC),
    RET,
  LABEL(0), /* = 0x00 */
    { 0x06, 0x00,  0x001e, -0x00000001,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 2),
    HALT,
  LABEL(2), /* = 0x02 */
    RET,
};

static const struct ScriptRef s_gs6_g0_s3_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs6_g0_s3_evt0_sref_script }; /* 0x8199304 */


static const struct ScriptCommand s_gs6_g1_s0_station_sref_script[] = { /* 0x8199310 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(10, /* to label */ 0),
    CANCEL_EVENTS(-1, -1),
    SELECT_ENTITIES(-1, 1),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    CANCEL_EVENTS(-1, -1),
    SELECT_ENTITIES(-1, 0),
    RET_DIRECT,
};

static const struct ScriptRef s_gs6_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs6_g1_s0_station_sref_script }; /* 0x81993a0 */

static const struct ScriptCommand s_gs6_g1_s0_lives0_dlg1[] = { /* 0x81993ac */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    JUMP_SCRIPT(MOVE_PLAZA_SLEEP),
};

static const struct ScriptCommand s_gs6_g1_s0_lives0_dlg2[] = { /* 0x81993dc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x06, 0x00,  0x001e, -0x00000001,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 0),
    BGM_FADEOUT(30),
    HALT,
  LABEL(0), /* = 0x00 */
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs6_g1_s0_lives0_dlg3[] = { /* 0x819947c */
    DEBUGINFO,
    CALL_SCRIPT(INIT_PLAZA_SLEEP_TALK_FUNC),
    JUMPIF_SCENARIOCHECK(4, /* to label */ 0),
    { 0x8e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(LIVES_REPLY),
};

static const struct ScriptCommand s_gs6_g1_s0_evt0_sref_script[] = { /* 0x81994ec */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000054,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs6_g1_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs6_g1_s0_evt0_sref_script }; /* 0x819951c */

static const struct ScriptCommand s_gs6_g1_s1_evt0_sref_script[] = { /* 0x8199528 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+There appears to be no one inside.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............!#W\n#+There is a notice posted in the back.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Under Construction - Keep Out\n#+- Makuhita Dojo -") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptRef s_gs6_g1_s1_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs6_g1_s1_evt0_sref_script }; /* 0x8199640 */

static const struct ScriptCommand s_gs6_g2_s0_station_sref_script[] = { /* 0x819964c */
    DEBUGINFO,
    SELECT_MAP(6),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs6_g2_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs6_g2_s0_station_sref_script }; /* 0x81996ec */

static const struct ScriptCommand s_gs6_g2_s0_lives0_dlg0[] = { /* 0x81996f8 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x3c, 0x25,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 0),
    COND_EQUAL(3, /* to label */ 0),
    COND_EQUAL(4, /* to label */ 0),
    COND_EQUAL(5, /* to label */ 0),
    JUMP_LABEL(5),
  LABEL(0), /* = 0x00 */
    { 0x3c, 0x2c,  0x0000,  0x00000049,  0x00000000, NULL },
  LABEL(5), /* = 0x05 */
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};





static const struct ScriptCommand s_gs6_g2_s0_lives1_dlg0[] = { /* 0x8199848 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g2_s0_lives2_dlg0[] = { /* 0x81998c8 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(INIT_PLAZA_SLEEP_TALK_FUNC),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g3_s0_station_sref_script[] = { /* 0x8199938 */
    DEBUGINFO,
    SELECT_MAP(6),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs6_g3_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs6_g3_s0_station_sref_script }; /* 0x81999d8 */

static const struct ScriptCommand s_gs6_g3_s0_lives0_dlg0[] = { /* 0x81999e4 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x3c, 0x26,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g3_s0_lives1_dlg0[] = { /* 0x8199a94 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g3_s0_lives2_dlg0[] = { /* 0x8199b14 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(INIT_PLAZA_SLEEP_TALK_FUNC),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g4_s0_station_sref_script[] = { /* 0x8199b84 */
    DEBUGINFO,
    SELECT_MAP(6),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs6_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs6_g4_s0_station_sref_script }; /* 0x8199c24 */

static const struct ScriptCommand s_gs6_g4_s0_lives0_dlg0[] = { /* 0x8199c30 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x3c, 0x26,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g4_s0_lives1_dlg0[] = { /* 0x8199ce0 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g4_s0_lives2_dlg0[] = { /* 0x8199d60 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(INIT_PLAZA_SLEEP_TALK_FUNC),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g5_s0_station_sref_script[] = { /* 0x8199dd0 */
    DEBUGINFO,
    SELECT_MAP(6),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs6_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs6_g5_s0_station_sref_script }; /* 0x8199e70 */

static const struct ScriptCommand s_gs6_g5_s0_lives0_dlg0[] = { /* 0x8199e7c */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x3c, 0x27,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g5_s0_lives1_dlg0[] = { /* 0x8199f2c */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs6_g5_s0_lives2_dlg0[] = { /* 0x8199fac */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(INIT_PLAZA_SLEEP_TALK_FUNC),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs6_g0_s1_lives[] = { /* 0x819a01c */
    /*  0 */ {   0,   0,   0,   0, {  45,   9, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  45,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs6_g0_s2_lives[] = { /* 0x819a04c */
    /*  0 */ {   0,   0,   0,   0, {  34,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  34,  30, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs6_g1_s0_lives[] = { /* 0x819a07c */
    /*  0 */ {  84,   0,   0,   0, {  30,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [1] = s_gs6_g1_s0_lives0_dlg1,
        [2] = s_gs6_g1_s0_lives0_dlg2,
        [3] = s_gs6_g1_s0_lives0_dlg3,
    } },
};

static const struct GroundLivesData s_gs6_g2_s0_lives[] = { /* 0x819a094 */
    /*  0 */ {   0,   6,   0,   0, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  38,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  84,   2,   0,   0, {  30,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs6_g2_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs6_g3_s0_lives[] = { /* 0x819a0dc */
    /*  0 */ {   0,   6,   0,   0, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  38,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  84,   2,   0,   0, {  30,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs6_g3_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs6_g4_s0_lives[] = { /* 0x819a124 */
    /*  0 */ {   0,   6,   0,   0, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  38,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g4_s0_lives1_dlg0,
    } },
    /*  2 */ {  84,   2,   0,   0, {  30,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs6_g4_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs6_g5_s0_lives[] = { /* 0x819a16c */
    /*  0 */ {   0,   6,   0,   0, {  34,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  38,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs6_g5_s0_lives1_dlg0,
    } },
    /*  2 */ {  84,   2,   0,   0, {  30,  31, 0, CPOS_HALFTILE }, {
        [0] = s_gs6_g5_s0_lives2_dlg0,
    } },
};

static const struct GroundEventData s_gs6_g0_s0_evts[] = { /* 0x819a1b4 */
    /*  0 */ {  16,   6,   0,   0, {  38,   0, 0, 0 }, &s_gs6_g0_s0_evt0_sref },
};

static const struct GroundEventData s_gs6_g0_s3_evts[] = { /* 0x819a1c0 */
    /*  0 */ {   3,   3,   0,   0, {  33,  26, 0, 0 }, &s_gs6_g0_s3_evt0_sref },
};

static const struct GroundEventData s_gs6_g1_s0_evts[] = { /* 0x819a1cc */
    /*  0 */ {   3,   3,   0,   0, {  33,  26, 0, 0 }, &s_gs6_g1_s0_evt0_sref },
};

static const struct GroundEventData s_gs6_g1_s1_evts[] = { /* 0x819a1d8 */
    /*  0 */ {   3,   3,   0,   0, {  33,  26, 0, 0 }, &s_gs6_g1_s1_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x819a1e4 */
    &s_gs6_g0_s0_station_sref,
    &s_gs6_g1_s0_station_sref,
    &s_gs6_g2_s0_station_sref,
    &s_gs6_g3_s0_station_sref,
    &s_gs6_g4_s0_station_sref,
    &s_gs6_g5_s0_station_sref,
};

static const struct GroundScriptSector s_gs6_g0_sectors[] = { /* 0x819a1fc */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs6_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs6_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs6_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs6_g0_s3_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs6_g1_sectors[] = { /* 0x819a29c */
    { LPARRAY(s_gs6_g1_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs6_g1_s0_evts), 1,&sStationScripts[1], },
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs6_g1_s1_evts), 0,NULL, },
};

static const struct GroundScriptSector s_gs6_g2_sectors[] = { /* 0x819a2ec */
    { LPARRAY(s_gs6_g2_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs6_g3_sectors[] = { /* 0x819a314 */
    { LPARRAY(s_gs6_g3_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs6_g4_sectors[] = { /* 0x819a33c */
    { LPARRAY(s_gs6_g4_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs6_g5_sectors[] = { /* 0x819a364 */
    { LPARRAY(s_gs6_g5_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptGroup s_gs6_groups[] = { /* 0x819a38c */
    { LPARRAY(s_gs6_g0_sectors) },
    { LPARRAY(s_gs6_g1_sectors) },
    { LPARRAY(s_gs6_g2_sectors) },
    { LPARRAY(s_gs6_g3_sectors) },
    { LPARRAY(s_gs6_g4_sectors) },
    { LPARRAY(s_gs6_g5_sectors) },
};

static const struct GroundLink s_gs6_links[] = { /* 0x819a3bc */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs6 = { LPARRAY(s_gs6_groups), s_gs6_links }; /* 0x819a3c4 */
