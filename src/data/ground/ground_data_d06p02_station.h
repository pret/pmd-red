







static const struct ScriptCommand s_gs189_g0_s0_station_sref_script[] = { /* 0x8239e50 */
    DEBUGINFO_O(10),
    SELECT_MAP(MAP_MT_THUNDER_MID),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_GT, 17, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 4),
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 5),
    JUMP_LABEL(5),
  LABEL(2), /* = 0x02 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(6),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(6),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(6),
  LABEL(6), /* = 0x06 */
    BGM_SWITCH(111),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs189_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs189_g0_s0_station_sref_script }; /* 0x823a06c */

static const struct ScriptCommand s_gs189_g0_s0_evt0_sref_script[] = { /* 0x823a078 */
    DEBUGINFO_O(46),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Would you like to go on?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    TEXTBOX_CLEAR,
    BGM_FADEOUT(60),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_MT_THUNDER_PEAK),
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const struct ScriptRef s_gs189_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs189_g0_s0_evt0_sref_script }; /* 0x823a164 */

static const struct ScriptCommand s_gs189_g0_s0_evt1_sref_script[] = { /* 0x823a170 */
    DEBUGINFO_O(63),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the rescue team base?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    TEXTBOX_CLEAR,
    BGM_FADEOUT(30),
    { 0x23, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER4_FUNC),
    SET_DUNGEON_RES(/* result */ 10, /* enter */ -1),
    EXECUTE_STATION(12, 4, 0),
    HALT,
};

static const struct ScriptRef s_gs189_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs189_g0_s0_evt1_sref_script }; /* 0x823a270 */

static const struct ScriptCommand s_gs189_g0_s0_obj0_dlg2[] = { /* 0x823a27c */
    DEBUGINFO_O(82),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs189_g0_s1_lives0_dlg0[] = { /* 0x823a29c */
    DEBUGINFO_O(87),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g0_s1_lives1_dlg0[] = { /* 0x823a2dc */
    DEBUGINFO_O(94),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g0_s3_lives0_dlg0[] = { /* 0x823a31c */
    DEBUGINFO_O(101),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g0_s3_lives1_dlg0[] = { /* 0x823a35c */
    DEBUGINFO_O(108),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g0_s4_lives0_dlg0[] = { /* 0x823a39c */
    DEBUGINFO_O(115),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g0_s4_lives1_dlg0[] = { /* 0x823a3cc */
    DEBUGINFO_O(121),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs189_g1_s0_station_sref_script[] = { /* 0x823a3fc */
    DEBUGINFO_O(127),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_THUNDER_MID),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_THUNDER_MID),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_MT_THUNDER_MID),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(111),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs189_g1_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs189_g1_s0_station_sref_script }; /* 0x823a4cc */

static const struct ScriptCommand s_gs189_g1_s0_lives0_dlg0[] = { /* 0x823a4d8 */
    DEBUGINFO_O(145),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...{WAIT_PRESS}\nThings didn't go right for us...")),
    VARIANT_DEFAULT(_(" Hmm...{WAIT_PRESS}\nThings didn't turn out in our favor...")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we should be getting\nclose.{WAIT_PRESS}\nLet's keep going hard at it!")),
    VARIANT_DEFAULT(_(" But we shouldn't be far.{WAIT_PRESS}\nLet's keep doing our best!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs189_g1_s0_lives1_dlg0[] = { /* 0x823a72c */
    DEBUGINFO_O(171),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs189_g0_s0_lives[] = { /* 0x823a7dc */
    /*  0 */ { 145,   0,   0,   0, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs189_g0_s1_lives[] = { /* 0x823a7f4 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs189_g0_s3_lives[] = { /* 0x823a824 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs189_g0_s4_lives[] = { /* 0x823a854 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs189_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs189_g1_s0_lives[] = { /* 0x823a884 */
    /*  0 */ {   0,   2,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs189_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   6,   0,   0, {  26,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs189_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs189_g0_s0_objs[] = { /* 0x823a8b4 */
    /*  0 */ {   4,   0,   4,   3, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs189_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs189_g1_s0_effs[] = { /* 0x823a8cc */
    /*  0 */ {   0,   0,   1,   1, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs189_g0_s0_evts[] = { /* 0x823a8d8 */
    /*  0 */ {  15,   3,   0,   0, {  21,  12, 0, 0 }, &s_gs189_g0_s0_evt0_sref },
    /*  1 */ {  15,   3,   0,   0, {  21,  42, 0, 0 }, &s_gs189_g0_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x823a8f0 */
    &s_gs189_g0_s0_station_sref,
    &s_gs189_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs189_g0_sectors[] = { /* 0x823a8f8 */
    { LPARRAY(s_gs189_g0_s0_lives), LPARRAY(s_gs189_g0_s0_objs), 0,NULL, LPARRAY(s_gs189_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs189_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs189_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs189_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs189_g1_sectors[] = { /* 0x823a9c0 */
    { LPARRAY(s_gs189_g1_s0_lives), 0,NULL, LPARRAY(s_gs189_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs189_groups[] = { /* 0x823a9e8 */
    { LPARRAY(s_gs189_g0_sectors) },
    { LPARRAY(s_gs189_g1_sectors) },
};

static const struct GroundLink s_gs189_links[] = { /* 0x823a9f8 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs189 = { LPARRAY(s_gs189_groups), s_gs189_links }; /* 0x823aa00 */
