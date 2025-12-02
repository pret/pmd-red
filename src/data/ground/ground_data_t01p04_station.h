













static const struct ScriptCommand s_gs5_g0_s0_station_sref_script[] = { /* 0x8197a1c */
    DEBUGINFO_O(16),
    SELECT_MAP(5),
    JUMP_LABEL(0),
  LABEL(0), /* = 0x00 */
    CALL_STATION(  1,  0),
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    CJUMP_VAR(START_MODE),
    COND_EQUAL(STARTMODE_DUNGEON_LOST, /* to label */ 2),
    COND_EQUAL(STARTMODE_11, /* to label */ 2),
    COND_EQUAL(STARTMODE_10, /* to label */ 3),
    COND_EQUAL(STARTMODE_DUNGEON_WON, /* to label */ 4),
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
    BGM_SWITCH(MUS_POKEMON_SQUARE),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs5_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs5_g0_s0_station_sref_script }; /* 0x8197c28 */


static const struct ScriptCommand s_gs5_g0_s0_evt0_sref_script[] = { /* 0x8197c34 */
    DEBUGINFO_O(52),
    { 0x01, 0x00, -0x0001,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const ScriptRef s_gs5_g0_s0_evt0_sref = { GETOUT_NORMAL, SCRIPT_TYPE_02, NULL, s_gs5_g0_s0_evt0_sref_script }; /* 0x8197c64 */

static const struct ScriptCommand s_gs5_g0_s1_lives0_dlg0[] = { /* 0x8197c70 */
    DEBUGINFO_O(60),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs5_g0_s1_lives1_dlg0[] = { /* 0x8197cb0 */
    DEBUGINFO_O(67),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs5_g1_s0_station_sref_script[] = { /* 0x8197cf0 */
    DEBUGINFO_O(74),
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 0),
    CANCEL_EVENTS(-1, -1),
    SELECT_ENTITIES(-1, -1),
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const ScriptRef s_gs5_g1_s0_station_sref = { STATION_CONTROL, SCRIPT_TYPE_08, NULL, s_gs5_g1_s0_station_sref_script }; /* 0x8197d50 */

static const struct ScriptCommand s_gs5_g1_s0_lives0_dlg2[] = { /* 0x8197d5c */
    DEBUGINFO_O(85),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_FRIEND_RESCUE, 0, 0),
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
    DEBUGINFO_O(102),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_THANK_YOU_MAIL, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs5_g1_s0_lives2_dlg2[] = { /* 0x8197e9c */
    DEBUGINFO_O(111),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_PPO_HELP_COUNTER, 0, 0),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_gs5_g1_s0_obj0_dlg2[] = { /* 0x8197efc */
    DEBUGINFO_O(120),
    { 0x21, 0x00,  0x0000,  0x00000032,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_station_sref_script[] = { /* 0x8197f2c */
    DEBUGINFO_O(126),
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_POKEMON_SQUARE),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const ScriptRef s_gs5_g2_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs5_g2_s0_station_sref_script }; /* 0x8197fdc */

static const struct ScriptCommand s_gs5_g2_s0_lives0_dlg0[] = { /* 0x8197fe8 */
    DEBUGINFO_O(142),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_1D, 0, 0),
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_lives1_dlg0[] = { /* 0x8198098 */
    DEBUGINFO_O(156),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g2_s0_lives2_dlg0[] = { /* 0x8198118 */
    DEBUGINFO_O(167),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs5_g3_s0_station_sref_script[] = { /* 0x8198178 */
    DEBUGINFO_O(176),
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER2_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_POKEMON_SQUARE),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const ScriptRef s_gs5_g3_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs5_g3_s0_station_sref_script }; /* 0x8198228 */

static const struct ScriptCommand s_gs5_g3_s0_lives0_dlg0[] = { /* 0x8198234 */
    DEBUGINFO_O(192),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x09,  0x0002,  0x0000002f,  0x00000000, NULL },
    { 0x3b, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    MSG_NPC(2, _(" Oh! Welcome back!{WAIT_PRESS}\nThe rescue...{WAIT_PRESS}went badly, I see...")),
    MSG_NPC(2, _(" But that wasn't the final\nchance! Don't give up!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
  LABEL(0), /* = 0x00 */
    MSG_NPC(2, _(" Oh! Welcome back!{WAIT_PRESS}\nThe rescue...{WAIT_PRESS}went badly, I see...")),
    MSG_NPC(2, _(" I'm terribly sorry, but you\nmay not go on that rescue again...")),
    MSG_NPC(2, _(" Please inform your friend\nthat, regrettably, the friend rescue\nmission ended in failure.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs5_g3_s0_lives1_dlg0[] = { /* 0x81984bc */
    DEBUGINFO_O(218),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g4_s0_station_sref_script[] = { /* 0x819853c */
    DEBUGINFO_O(229),
    SELECT_MAP(5),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    CALL_STATION(  1,  0),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_POKEMON_SQUARE),
    { 0x22, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  1,  0),
    SELECT_EVENTS(0, 0),
    RET,
};

static const ScriptRef s_gs5_g4_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs5_g4_s0_station_sref_script }; /* 0x81985ec */

static const struct ScriptCommand s_gs5_g4_s0_lives0_dlg0[] = { /* 0x81985f8 */
    DEBUGINFO_O(245),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    { 0x2d, 0x09,  0x0002,  0x0000002f,  0x00000000, NULL },
    { 0x3b, 0x0c,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    MSG_NPC(2, _(" Oh! Welcome back!{WAIT_PRESS}\nThe rescue...{WAIT_PRESS}went badly, I see...")),
    MSG_NPC(2, _(" But that wasn't the final\nchance! Don't give up!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
  LABEL(0), /* = 0x00 */
    MSG_NPC(2, _(" Oh! Welcome back!{WAIT_PRESS}\nThe rescue...{WAIT_PRESS}went badly, I see...")),
    MSG_NPC(2, _(" I'm terribly sorry, but you\nmay not go on that rescue again...")),
    MSG_NPC(2, _(" Please inform your friend\nthat, regrettably, the friend rescue\nmission ended in failure.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs5_g4_s0_lives1_dlg0[] = { /* 0x8198768 */
    DEBUGINFO_O(271),
    { 0x4f, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs5_g5_s0_station_sref_script[] = { /* 0x81987e8 */
    DEBUGINFO_O(282),
    SELECT_MAP(5),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_INTRO),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const ScriptRef s_gs5_g5_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs5_g5_s0_station_sref_script }; /* 0x8198868 */

static const struct ScriptCommand s_gs5_g5_s0_eff0_script[] = { /* 0x8198874 */
    DEBUGINFO_O(295),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WAIT(1),
    WALK_GRID(128, 0),
    CAMERA_END_PAN,
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs5_g5_s0_lives0_dlg0[] = { /* 0x81988f4 */
    DEBUGINFO_O(306),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    WAIT(60),
    SELECT_ANIMATION(5),
    WAIT(30),
    ALERT_CUE(6),
    WAIT(30),
    { 0x68, 0x00,  0x0080,  0x00000020,  0x00000000, NULL },
    ALERT_CUE(4),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0080,  0x00000002,  0x00000000, NULL },
    ROTATE_TO(8, DIR_TRANS_10, DIRECTION_EAST),
    { 0x80, 0x00,  0x0100,  0x00000003,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x80, 0x00,  0x0100,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs5_g5_s0_lives1_dlg0[] = { /* 0x8198a24 */
    DEBUGINFO_O(328),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE_TO(8, DIR_TRANS_10, DIRECTION_WEST),
    HALT,
};

static const struct ScriptCommand s_gs5_g5_s0_lives2_dlg0[] = { /* 0x8198a84 */
    DEBUGINFO_O(337),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    WALK_GRID(256, 5),
    ALERT_CUE(5),
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

static const ScriptRef * const (sStationScripts[]) = { /* 0x8198c7c */
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

const GroundScriptHeader gGroundScript_gs5 = { LPARRAY(s_gs5_groups), s_gs5_links }; /* 0x8198e0c */
