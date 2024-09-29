







static const struct ScriptCommand s_gs202_g0_s0_station_sref_script[] = { /* 0x82556a0 */
    DEBUGINFO,
    SELECT_MAP(202),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 14, /* to label */ 0),
    COND(JUDGE_GT, 17, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
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
    BGM_SWITCH(115),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs202_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs202_g0_s0_station_sref_script }; /* 0x825592c */

static const struct ScriptCommand s_gs202_g0_s0_evt0_sref_script[] = { /* 0x8255938 */
    DEBUGINFO,
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Keep going?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    JUMPIF_ARRAY(RESCUE_SCENARIO_JOB_LIST, 29, /* to label */ 2),
    { 0x02, 0x00,  0x001e,  0x00000010,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
  LABEL(2), /* = 0x02 */
    { 0x02, 0x00,  0x001e,  0x00000026,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const struct ScriptRef s_gs202_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs202_g0_s0_evt0_sref_script }; /* 0x8255a64 */

static const struct ScriptCommand s_gs202_g0_s0_evt1_sref_script[] = { /* 0x8255a70 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(5, /* to label */ 0),
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the rescue team base?")),
    CHOICE(/* label */  1, _("Yes.")),
    CHOICE(/* label */  2, _("*No.")),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(30),
    { 0x23, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER4_FUNC),
    SET_DUNGEON_RES(/* result */ 10, /* enter */ -1),
    EXECUTE_STATION(12, 4, 0),
    HALT,
  LABEL(0), /* = 0x00 */
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the entrance?")),
    CHOICE(/* label */  3, _("Yes.")),
    CHOICE(/* label */  4, _("*No.")),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(END_TALK),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x01, 0x00,  0x001e,  0x000000c9,  0x00000000, NULL },
    HALT,
};

static const struct ScriptRef s_gs202_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs202_g0_s0_evt1_sref_script }; /* 0x8255c38 */

static const struct ScriptCommand s_gs202_g0_s0_obj0_dlg2[] = { /* 0x8255c44 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs202_g0_s1_lives0_dlg0[] = { /* 0x8255c64 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g0_s1_lives1_dlg0[] = { /* 0x8255ca4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g0_s3_lives0_dlg0[] = { /* 0x8255ce4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g0_s3_lives1_dlg0[] = { /* 0x8255d24 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g0_s4_lives0_dlg0[] = { /* 0x8255d64 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g0_s4_lives1_dlg0[] = { /* 0x8255d94 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs202_g1_s0_station_sref_script[] = { /* 0x8255dc4 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 202),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 202),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    JUMPIF_EQUAL(SCENARIO_MAIN, 14, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    SELECT_MAP(202),
    CALL_STATION(  2,  0),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(115),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs202_g1_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs202_g1_s0_station_sref_script }; /* 0x8255ef4 */

static const struct ScriptCommand s_gs202_g1_s0_lives0_dlg0[] = { /* 0x8255f00 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...#W\nWell, that didn't go well.")),
    VARIANT_DEFAULT(_(" Hmm...#W\nThat didn't work out...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we didn't have far to\ngo!")),
    VARIANT(/* == */  1, _(" Let's storm our way to the\ntop this time, $n0!")),
    VARIANT_DEFAULT(_(" But we were very close!")),
    VARIANT_DEFAULT(_(" Let's be sure to reach the\npeak this time, $n0!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    RET,
};


static const struct ScriptCommand s_gs202_g1_s0_lives1_dlg0[] = { /* 0x82561ac */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs202_g2_s0_station_sref_script[] = { /* 0x825628c */
    DEBUGINFO,
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs202_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs202_g2_s0_station_sref_script }; /* 0x82562bc */
static const struct GroundLivesData s_gs202_g0_s0_lives[] = { /* 0x82562c8 */
    /*  0 */ { 145,   0,   0,   0, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs202_g0_s1_lives[] = { /* 0x82562e0 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs202_g0_s3_lives[] = { /* 0x8256310 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs202_g0_s4_lives[] = { /* 0x8256340 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs202_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs202_g1_s0_lives[] = { /* 0x8256370 */
    /*  0 */ {   0,   0,   0,   0, {  30,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs202_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  27,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs202_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs202_g0_s0_objs[] = { /* 0x82563a0 */
    /*  0 */ {   4,   0,   4,   3, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs202_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs202_g1_s0_effs[] = { /* 0x82563b8 */
    /*  0 */ {   0,   0,   1,   1, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs202_g0_s0_evts[] = { /* 0x82563c4 */
    /*  0 */ {  15,   3,   0,   0, {  21,  12, 0, 0 }, &s_gs202_g0_s0_evt0_sref },
    /*  1 */ {  15,   3,   0,   0, {  21,  42, 0, 0 }, &s_gs202_g0_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82563dc */
    &s_gs202_g0_s0_station_sref,
    &s_gs202_g1_s0_station_sref,
    &s_gs202_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs202_g0_sectors[] = { /* 0x82563e8 */
    { LPARRAY(s_gs202_g0_s0_lives), LPARRAY(s_gs202_g0_s0_objs), 0,NULL, LPARRAY(s_gs202_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs202_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs202_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs202_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs202_g1_sectors[] = { /* 0x82564b0 */
    { LPARRAY(s_gs202_g1_s0_lives), 0,NULL, LPARRAY(s_gs202_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs202_g2_sectors[] = { /* 0x82564d8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs202_groups[] = { /* 0x8256500 */
    { LPARRAY(s_gs202_g0_sectors) },
    { LPARRAY(s_gs202_g1_sectors) },
    { LPARRAY(s_gs202_g2_sectors) },
};

static const struct GroundLink s_gs202_links[] = { /* 0x8256518 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs202 = { LPARRAY(s_gs202_groups), s_gs202_links }; /* 0x8256520 */
