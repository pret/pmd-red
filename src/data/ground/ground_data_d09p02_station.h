







static const struct ScriptCommand s_gs196_g0_s0_station_sref_script[] = { /* 0x8248a54 */
    DEBUGINFO_O(10),
    SELECT_MAP(MAP_MT_BLAZE_MID),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 12, /* to label */ 0),
    COND(JUDGE_GT, 17, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 5),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 6),
    JUMP_LABEL(6),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(7),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(7),
  LABEL(7), /* = 0x07 */
    BGM_SWITCH(MUS_MT_BLAZE),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs196_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs196_g0_s0_station_sref_script }; /* 0x8248cc0 */

static const struct ScriptCommand s_gs196_g0_s0_evt0_sref_script[] = { /* 0x8248ccc */
    DEBUGINFO_O(51),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Keep going?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    TEXTBOX_CLEAR,
    BGM_FADEOUT(60),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_MT_BLAZE_PEAK),
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const struct ScriptRef s_gs196_g0_s0_evt0_sref = { GETOUT_NORMAL, 2, NULL, s_gs196_g0_s0_evt0_sref_script }; /* 0x8248da8 */

static const struct ScriptCommand s_gs196_g0_s0_evt1_sref_script[] = { /* 0x8248db4 */
    DEBUGINFO_O(68),
    JUMPIF_SCENARIOCHECK(QUEST_UNK5, /* to label */ 0),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the rescue team base?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*No.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    BGM_FADEOUT(30),
    { 0x23, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER4_FUNC),
    SET_DUNGEON_RES(/* result */ 10, /* enter */ -1),
    EXECUTE_STATION(MAP_TEAM_BASE_INSIDE, 4, 0),
    HALT,
  LABEL(0), /* = 0x00 */
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the entrance?")),
    CHOICE(/* label */  3, _("Yes.")),
    CHOICE(/* label */  4, _("*No.")),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    TEXTBOX_CLEAR,
    { 0x01, 0x00,  0x001e,  0x000000c3,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs196_g0_s0_evt1_sref = { GETOUT_NORMAL, 2, NULL, s_gs196_g0_s0_evt1_sref_script }; /* 0x8248f7c */

static const struct ScriptCommand s_gs196_g0_s0_obj0_dlg2[] = { /* 0x8248f88 */
    DEBUGINFO_O(98),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs196_g0_s1_lives0_dlg0[] = { /* 0x8248fa8 */
    DEBUGINFO_O(103),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g0_s1_lives1_dlg0[] = { /* 0x8248fe8 */
    DEBUGINFO_O(110),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g0_s3_lives0_dlg0[] = { /* 0x8249028 */
    DEBUGINFO_O(117),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g0_s3_lives1_dlg0[] = { /* 0x8249068 */
    DEBUGINFO_O(124),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g0_s4_lives0_dlg0[] = { /* 0x82490a8 */
    DEBUGINFO_O(131),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g0_s4_lives1_dlg0[] = { /* 0x82490d8 */
    DEBUGINFO_O(137),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs196_g1_s0_station_sref_script[] = { /* 0x8249108 */
    DEBUGINFO_O(143),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_BLAZE_MID),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_BLAZE_MID),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(MAP_MT_BLAZE_MID),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MT_BLAZE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs196_g1_s0_station_sref = { EVENT_STATION , 7, NULL, s_gs196_g1_s0_station_sref_script }; /* 0x82491d8 */

static const struct ScriptCommand s_gs196_g1_s0_lives0_dlg0[] = { /* 0x82491e4 */
    DEBUGINFO_O(161),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...{WAIT_PRESS}\nWell, that didn't go well.")),
    VARIANT_DEFAULT(_(" Hmm...{WAIT_PRESS}\nThat didn't work out...")),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we almost made it.{WAIT_PRESS}\nLet's give it our best again!")),
    VARIANT_DEFAULT(_(" But we came close.{WAIT_PRESS}\nLet's keep doing our best!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    ALERT_CUE(6),
    RET,
};

static const struct ScriptCommand s_gs196_g1_s0_lives1_dlg0[] = { /* 0x8249404 */
    DEBUGINFO_O(186),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs196_g0_s0_lives[] = { /* 0x82494c4 */
    /*  0 */ { 145,   0,   0,   0, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs196_g0_s1_lives[] = { /* 0x82494dc */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs196_g0_s3_lives[] = { /* 0x824950c */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs196_g0_s4_lives[] = { /* 0x824953c */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs196_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs196_g1_s0_lives[] = { /* 0x824956c */
    /*  0 */ {   0,   2,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs196_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   6,   0,   0, {  26,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs196_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs196_g0_s0_objs[] = { /* 0x824959c */
    /*  0 */ {   4,   0,   4,   3, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs196_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs196_g1_s0_effs[] = { /* 0x82495b4 */
    /*  0 */ {   0,   0,   1,   1, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs196_g0_s0_evts[] = { /* 0x82495c0 */
    /*  0 */ {  15,   3,   0,   0, {  21,  12, 0, 0 }, &s_gs196_g0_s0_evt0_sref },
    /*  1 */ {  15,   3,   0,   0, {  21,  42, 0, 0 }, &s_gs196_g0_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82495d8 */
    &s_gs196_g0_s0_station_sref,
    &s_gs196_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs196_g0_sectors[] = { /* 0x82495e0 */
    { LPARRAY(s_gs196_g0_s0_lives), LPARRAY(s_gs196_g0_s0_objs), 0,NULL, LPARRAY(s_gs196_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs196_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs196_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs196_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs196_g1_sectors[] = { /* 0x82496a8 */
    { LPARRAY(s_gs196_g1_s0_lives), 0,NULL, LPARRAY(s_gs196_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs196_groups[] = { /* 0x82496d0 */
    { LPARRAY(s_gs196_g0_sectors) },
    { LPARRAY(s_gs196_g1_sectors) },
};

static const struct GroundLink s_gs196_links[] = { /* 0x82496e0 */
    {},
};

const GroundScriptHeader gGroundScript_gs196 = { LPARRAY(s_gs196_groups), s_gs196_links }; /* 0x82496e8 */
