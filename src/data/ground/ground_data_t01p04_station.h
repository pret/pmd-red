













static const struct ScriptCommand s_gs5_g0_s0_station_sref_script[] = { /* 0x8197a1c */
    DEBUGINFO,
    SELECT_MAP(5),
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
    SELECT_LIVES(0, 1),
    JUMP_LABEL(6),
  LABEL(2), /* = 0x02 */
    EXECUTE_SUBSTATION(-1, 4, 0),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    RET,
  LABEL(3), /* = 0x03 */
    EXECUTE_SUBSTATION(-1, 3, 0),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    RET,
  LABEL(4), /* = 0x04 */
    EXECUTE_SUBSTATION(-1, 2, 0),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    RET,
  LABEL(6), /* = 0x06 */
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    BGM_SWITCH(7),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs5_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs5_g0_s0_station_sref_script }; /* 0x8197c28 */


static const struct ScriptCommand s_gs5_g0_s0_evt0_sref_script[] = { /* 0x8197c34 */
    DEBUGINFO,
    { 0x01, 0x00, -0x0001,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs5_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs5_g0_s0_evt0_sref_script }; /* 0x8197c64 */

static const struct ScriptCommand s_gs5_g0_s1_lives0_dlg0[] = { /* 0x8197c70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs5_g0_s1_lives1_dlg0[] = { /* 0x8197cb0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs5_g1_s0_station_sref_script[] = { /* 0x8197cf0 */
    DEBUGINFO,
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 0),
    CANCEL_EVENTS(-1, -1),
    SELECT_ENTITIES(-1, -1),
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptRef s_gs5_g1_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs5_g1_s0_station_sref_script }; /* 0x8197d50 */

static const struct ScriptCommand s_gs5_g1_s0_lives0_dlg2[] = { /* 0x8197d5c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x3c, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x05, 0x00,  0x001e,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    BGM_FADEOUT(30),
    HALT,
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs5_g1_s0_lives1_dlg2[] = { /* 0x8197e3c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x3c, 0x1e,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs5_g1_s0_lives2_dlg2[] = { /* 0x8197e9c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x3c, 0x1f,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs5_g1_s0_obj0_dlg2[] = { /* 0x8197efc */
    DEBUGINFO,
    { 0x21, 0x00,  0x0000,  0x00000032,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_station_sref_script[] = { /* 0x8197f2c */
    DEBUGINFO,
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs5_g2_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs5_g2_s0_station_sref_script }; /* 0x8197fdc */

static const struct ScriptCommand s_gs5_g2_s0_lives0_dlg0[] = { /* 0x8197fe8 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x3c, 0x1d,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_lives1_dlg0[] = { /* 0x8198098 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_lives2_dlg0[] = { /* 0x8198118 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g3_s0_station_sref_script[] = { /* 0x8198178 */
    DEBUGINFO,
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER2_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs5_g3_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs5_g3_s0_station_sref_script }; /* 0x8198228 */

static const struct ScriptCommand s_gs5_g3_s0_lives0_dlg0[] = { /* 0x8198234 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x09,  0x0002,  0x0000002f,  0x00000000, NULL },
    { 0x3b, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh! Welcome back!#W\nThe rescue...#Wwent badly, I see...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But that wasn't the final\nchance! Don't give up!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh! Welcome back!#W\nThe rescue...#Wwent badly, I see...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm terribly sorry, but you\nmay not go on that rescue again...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please inform your friend\nthat, regrettably, the friend rescue\nmission ended in failure.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g3_s0_lives1_dlg0[] = { /* 0x81984bc */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g4_s0_station_sref_script[] = { /* 0x819853c */
    DEBUGINFO,
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(7),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs5_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs5_g4_s0_station_sref_script }; /* 0x81985ec */

static const struct ScriptCommand s_gs5_g4_s0_lives0_dlg0[] = { /* 0x81985f8 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x09,  0x0002,  0x0000002f,  0x00000000, NULL },
    { 0x3b, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh! Welcome back!#W\nThe rescue...#Wwent badly, I see...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But that wasn't the final\nchance! Don't give up!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Oh! Welcome back!#W\nThe rescue...#Wwent badly, I see...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I'm terribly sorry, but you\nmay not go on that rescue again...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Please inform your friend\nthat, regrettably, the friend rescue\nmission ended in failure.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g4_s0_lives1_dlg0[] = { /* 0x8198768 */
    DEBUGINFO,
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g5_s0_station_sref_script[] = { /* 0x81987e8 */
    DEBUGINFO,
    SELECT_MAP(5),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(40),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs5_g5_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs5_g5_s0_station_sref_script }; /* 0x8198868 */

static const struct ScriptCommand s_gs5_g5_s0_eff0_script[] = { /* 0x8198874 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x6b, 0x00,  0x0080,  0x00000000,  0x00000000, NULL },
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs5_g5_s0_lives0_dlg0[] = { /* 0x81988f4 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x68, 0x00,  0x0080,  0x00000020,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0080,  0x00000002,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000002,  0x00000000, NULL },
    { 0x80, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs5_g5_s0_lives1_dlg0[] = { /* 0x8198a24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs5_g5_s0_lives2_dlg0[] = { /* 0x8198a84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000005,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs5_g0_s1_lives[] = { /* 0x8198ae4 */
    /*  0 */ {   0,   4,   0,   0, {  33,  44, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,  46, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs5_g1_s0_lives[] = { /* 0x8198b14 */
    /*  0 */ {  47,   0,   0,   0, {  31,  32, 0, CPOS_HALFTILE }, {
        [2] = s_gs5_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  48,   0,   0,   0, {  38,  32, 0, CPOS_HALFTILE }, {
        [2] = s_gs5_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  50,   6,   0,   0, {  49,  38, 0, 0 }, {
        [2] = s_gs5_g1_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs5_g2_s0_lives[] = { /* 0x8198b5c */
    /*  0 */ {   0,   4,   0,   0, {  31,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  47,   0,   0,   0, {  31,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g2_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs5_g3_s0_lives[] = { /* 0x8198ba4 */
    /*  0 */ {   0,   4,   0,   0, {  31,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g3_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs5_g4_s0_lives[] = { /* 0x8198bd4 */
    /*  0 */ {   0,   4,   0,   0, {  31,  36, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g4_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs5_g5_s0_lives[] = { /* 0x8198c04 */
    /*  0 */ {  56,   0,   0,   0, {  31,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  57,   0,   0,   0, {  38,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g5_s0_lives1_dlg0,
    } },
    /*  2 */ {  36,   4,   0,   0, {  31,  47, 0, CPOS_HALFTILE }, {
        [0] = s_gs5_g5_s0_lives2_dlg0,
    } },
};

static const struct GroundObjectData s_gs5_g1_s0_objs[] = { /* 0x8198c4c */
    /*  0 */ {   4,   0,   3,   3, {  46,  38, CPOS_HALFTILE, 0 }, {
        [2] = s_gs5_g1_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs5_g5_s0_effs[] = { /* 0x8198c64 */
    /*  0 */ {   0,   0,   1,   1, {  34,  34, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs5_g5_s0_eff0_script },
};

static const struct GroundEventData s_gs5_g0_s0_evts[] = { /* 0x8198c70 */
    /*  0 */ {   8,   3,   0,   0, {  29,  48, 0, 0 }, &s_gs5_g0_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8198c7c */
    &s_gs5_g0_s0_station_sref,
    &s_gs5_g1_s0_station_sref,
    &s_gs5_g2_s0_station_sref,
    &s_gs5_g3_s0_station_sref,
    &s_gs5_g4_s0_station_sref,
    &s_gs5_g5_s0_station_sref,
};

static const struct GroundScriptSector s_gs5_g0_sectors[] = { /* 0x8198c94 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs5_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs5_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs5_g1_sectors[] = { /* 0x8198ce4 */
    { LPARRAY(s_gs5_g1_s0_lives), LPARRAY(s_gs5_g1_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs5_g2_sectors[] = { /* 0x8198d0c */
    { LPARRAY(s_gs5_g2_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs5_g3_sectors[] = { /* 0x8198d34 */
    { LPARRAY(s_gs5_g3_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs5_g4_sectors[] = { /* 0x8198d5c */
    { LPARRAY(s_gs5_g4_s0_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs5_g5_sectors[] = { /* 0x8198d84 */
    { LPARRAY(s_gs5_g5_s0_lives), 0,NULL, LPARRAY(s_gs5_g5_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptGroup s_gs5_groups[] = { /* 0x8198dac */
    { LPARRAY(s_gs5_g0_sectors) },
    { LPARRAY(s_gs5_g1_sectors) },
    { LPARRAY(s_gs5_g2_sectors) },
    { LPARRAY(s_gs5_g3_sectors) },
    { LPARRAY(s_gs5_g4_sectors) },
    { LPARRAY(s_gs5_g5_sectors) },
};

static const struct GroundLink s_gs5_links[] = { /* 0x8198ddc */
    /* link   0 */ { { /*x*/  34, /*y*/  17, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  31, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  31, /*y*/  23, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  33, /*y*/  18, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  40, /*y*/  14, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  31, /*y*/  37, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs5 = { LPARRAY(s_gs5_groups), s_gs5_links }; /* 0x8198e0c */
