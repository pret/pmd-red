







static const struct ScriptCommand s_gs208_g0_s0_station_sref_script[] = { /* 0x826150c */
    DEBUGINFO,
    SELECT_MAP(208),
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
    BGM_SWITCH(22),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs208_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs208_g0_s0_station_sref_script }; /* 0x8261728 */

static const struct ScriptCommand s_gs208_g0_s0_evt0_sref_script[] = { /* 0x8261734 */
    DEBUGINFO,
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Keep going?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x02, 0x00,  0x001e,  0x00000014,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 1),
    HALT,
};

static const struct ScriptRef s_gs208_g0_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs208_g0_s0_evt0_sref_script }; /* 0x8261810 */

static const struct ScriptCommand s_gs208_g0_s0_evt1_sref_script[] = { /* 0x826181c */
    DEBUGINFO,
    ASK1(FALSE, /*default*/ 0, /* speaker */ -1, _("Return to the rescue team base?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("*No.")),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(30),
    { 0x23, 0x01, -0x0001,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER4_FUNC),
    SET_DUNGEON_RES(/* result */ 10, /* enter */ -1),
    EXECUTE_STATION(12, 4, 0),
    HALT,
};

static const struct ScriptRef s_gs208_g0_s0_evt1_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs208_g0_s0_evt1_sref_script }; /* 0x826191c */

static const struct ScriptCommand s_gs208_g0_s0_obj0_dlg2[] = { /* 0x8261928 */
    DEBUGINFO,
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs208_g0_s1_lives0_dlg0[] = { /* 0x8261948 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g0_s1_lives1_dlg0[] = { /* 0x8261988 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g0_s3_lives0_dlg0[] = { /* 0x82619c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g0_s3_lives1_dlg0[] = { /* 0x8261a08 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g0_s4_lives0_dlg0[] = { /* 0x8261a48 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g0_s4_lives1_dlg0[] = { /* 0x8261a78 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs208_g1_s0_station_sref_script[] = { /* 0x8261aa8 */
    DEBUGINFO,
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 208),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 208),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    SELECT_MAP(208),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(22),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    SELECT_EVENTS(0, 0),
    RET,
};

static const struct ScriptRef s_gs208_g1_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs208_g1_s0_station_sref_script }; /* 0x8261b78 */

static const struct ScriptCommand s_gs208_g1_s0_lives0_dlg0[] = { /* 0x8261b84 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hmm...#W\nWell, that didn't go well.")),
    VARIANT_DEFAULT(_(" Hmm...#W\nThat didn't work out...")),
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But we didn't have far to\ngo!#W\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" But we were very close!#W\nLet's keep trying our best!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs208_g1_s0_lives1_dlg0[] = { /* 0x8261dc0 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00001000,  0x00000000, NULL },
    RET,
};

static const struct GroundLivesData s_gs208_g0_s0_lives[] = { /* 0x8261e70 */
    /*  0 */ { 145,   0,   0,   0, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs208_g0_s1_lives[] = { /* 0x8261e88 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs208_g0_s3_lives[] = { /* 0x8261eb8 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs208_g0_s4_lives[] = { /* 0x8261ee8 */
    /*  0 */ {   0,   4,   0,   0, {  28,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  28,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs208_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs208_g1_s0_lives[] = { /* 0x8261f18 */
    /*  0 */ {   0,   2,   0,   0, {  31,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs208_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {   7,   6,   0,   0, {  26,  38, 0, CPOS_HALFTILE }, {
        [0] = s_gs208_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs208_g0_s0_objs[] = { /* 0x8261f48 */
    /*  0 */ {   4,   0,   4,   3, {  28,  28, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [2] = s_gs208_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundEffectData s_gs208_g1_s0_effs[] = { /* 0x8261f60 */
    /*  0 */ {   0,   0,   1,   1, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEventData s_gs208_g0_s0_evts[] = { /* 0x8261f6c */
    /*  0 */ {  15,   3,   0,   0, {  21,  12, 0, 0 }, &s_gs208_g0_s0_evt0_sref },
    /*  1 */ {  15,   3,   0,   0, {  21,  42, 0, 0 }, &s_gs208_g0_s0_evt1_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8261f84 */
    &s_gs208_g0_s0_station_sref,
    &s_gs208_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs208_g0_sectors[] = { /* 0x8261f8c */
    { LPARRAY(s_gs208_g0_s0_lives), LPARRAY(s_gs208_g0_s0_objs), 0,NULL, LPARRAY(s_gs208_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs208_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs208_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs208_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs208_g1_sectors[] = { /* 0x8262054 */
    { LPARRAY(s_gs208_g1_s0_lives), 0,NULL, LPARRAY(s_gs208_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs208_groups[] = { /* 0x826207c */
    { LPARRAY(s_gs208_g0_sectors) },
    { LPARRAY(s_gs208_g1_sectors) },
};

static const struct GroundLink s_gs208_links[] = { /* 0x826208c */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs208 = { LPARRAY(s_gs208_groups), s_gs208_links }; /* 0x8262094 */
