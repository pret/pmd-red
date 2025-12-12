







static const struct ScriptCommand s_gs205_g0_s0_station_sref_script[] = { /* 0x825dccc */
    DEBUGINFO_O(10),
    SELECT_MAP(MAP_MAGMA_CAVERN_MID),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_GT, 17, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 4),
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
    BGM_SWITCH(MUS_MAGMA_CAVERN),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs205_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs205_g0_s0_station_sref_script }; /* 0x825dee8 */

static const struct ScriptCommand s_gs205_g0_s0_evt0_sref_script[] = { /* 0x825def4 */
    DEBUGINFO_O(46),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Keep going?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    TEXTBOX_CLEAR,
    BGM_FADEOUT(60),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_MAGMA_CAVERN_PIT),
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const ScriptRef s_gs205_g0_s0_evt0_sref = { GETOUT_NORMAL, SCRIPT_TYPE_02, NULL, s_gs205_g0_s0_evt0_sref_script }; /* 0x825dfd0 */

static const struct ScriptCommand s_gs205_g0_s0_evt1_sref_script[] = { /* 0x825dfdc */
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
    EXECUTE_STATION(MAP_TEAM_BASE_INSIDE, 4, 0),
    HALT,
};

static const ScriptRef s_gs205_g0_s0_evt1_sref = { GETOUT_NORMAL, SCRIPT_TYPE_02, NULL, s_gs205_g0_s0_evt1_sref_script }; /* 0x825e0dc */

static const struct ScriptCommand s_gs205_g0_s0_obj0_dlg2[] = { /* 0x825e0e8 */
    DEBUGINFO_O(82),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs205_g0_s1_lives0_dlg0[] = { /* 0x825e108 */
    DEBUGINFO_O(87),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g0_s1_lives1_dlg0[] = { /* 0x825e148 */
    DEBUGINFO_O(94),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g0_s3_lives0_dlg0[] = { /* 0x825e188 */
    DEBUGINFO_O(101),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g0_s3_lives1_dlg0[] = { /* 0x825e1c8 */
    DEBUGINFO_O(108),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g0_s4_lives0_dlg0[] = { /* 0x825e208 */
    DEBUGINFO_O(115),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g0_s4_lives1_dlg0[] = { /* 0x825e238 */
    DEBUGINFO_O(121),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs205_g1_s0_station_sref_script[] = { /* 0x825e268 */
    DEBUGINFO_O(127),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MAGMA_CAVERN_MID),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MAGMA_CAVERN_MID),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_MAGMA_CAVERN_MID),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_MAGMA_CAVERN),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const ScriptRef s_gs205_g1_s0_station_sref = { EVENT_STATION, SCRIPT_TYPE_07, NULL, s_gs205_g1_s0_station_sref_script }; /* 0x825e338 */

static const struct ScriptCommand s_gs205_g1_s0_lives0_dlg0[] = { /* 0x825e344 */
    DEBUGINFO_O(145),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...{WAIT_PRESS}\nWell, that didn't go well.")),
    VARIANT_DEFAULT(_(" Hmm...{WAIT_PRESS}\nThat didn't work out...")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we didn't have far to\ngo!{WAIT_PRESS}\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" But we were very close!{WAIT_PRESS}\nLet's keep trying our best!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs205_g1_s0_lives1_dlg0[] = { /* 0x825e570 */
    DEBUGINFO_O(170),
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

static const struct GroundLivesData s_gs205_g0_s0_lives[] = { /* 0x825e620 */
    /*  0 */ { 145,   0,   0,   0, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs205_g0_s1_lives[] = { /* 0x825e638 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs205_g0_s3_lives[] = { /* 0x825e668 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs205_g0_s4_lives[] = { /* 0x825e698 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs205_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs205_g1_s0_lives[] = { /* 0x825e6c8 */
    /*  0 */ {   0,   2,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs205_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   6,   0,   0, {  26,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs205_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs205_g0_s0_objs[] = { /* 0x825e6f8 */
    /*  0 */ {   4,   0,   4,   3, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs205_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs205_g1_s0_effs[] = { /* 0x825e710 */
    /*  0 */ {   0,   0,   1,   1, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs205_g0_s0_evts[] = { /* 0x825e71c */
    /*  0 */ {  15,   3,   0,   0, {  21,  12, 0, 0 }, &s_gs205_g0_s0_evt0_sref },
    /*  1 */ {  15,   3,   0,   0, {  21,  42, 0, 0 }, &s_gs205_g0_s0_evt1_sref },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x825e734 */
    &s_gs205_g0_s0_station_sref,
    &s_gs205_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs205_g0_sectors[] = { /* 0x825e73c */
    { LPARRAY(s_gs205_g0_s0_lives), LPARRAY(s_gs205_g0_s0_objs), 0,NULL, LPARRAY(s_gs205_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs205_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs205_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs205_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs205_g1_sectors[] = { /* 0x825e804 */
    { LPARRAY(s_gs205_g1_s0_lives), 0,NULL, LPARRAY(s_gs205_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs205_groups[] = { /* 0x825e82c */
    { LPARRAY(s_gs205_g0_sectors) },
    { LPARRAY(s_gs205_g1_sectors) },
};

static const struct GroundLink s_gs205_links[] = { /* 0x825e83c */
    {},
};

const GroundScriptHeader gGroundScript_gs205 = { LPARRAY(s_gs205_groups), s_gs205_links }; /* 0x825e844 */
