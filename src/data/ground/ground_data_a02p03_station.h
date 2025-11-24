









static const struct ScriptCommand s_gs166_g0_s0_station_sref_script[] = { /* 0x8218bbc */
    DEBUGINFO_O(12),
    SELECT_MAP(166),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs166_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs166_g0_s0_station_sref_script }; /* 0x8218c28 */

static const struct ScriptCommand s_gs166_g1_s0_station_sref_script[] = { /* 0x8218c34 */
    DEBUGINFO_O(21),
    SELECT_MAP(166),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs166_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs166_g1_s0_station_sref_script }; /* 0x8218ca4 */

static const struct ScriptCommand s_gs166_g1_s0_lives0_dlg0[] = { /* 0x8218cb0 */
    DEBUGINFO_O(33),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    WALK_GRID(512, 0),
    WAIT(15),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    BGM_FADEOUT(60),
    WAIT(20),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_NPC(1, _(" Gasp... Gasp...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Oh, no! Look!")),
    TEXTBOX_CLEAR,
    BGM_SWITCH(MUS_THE_MOUNTAIN_OF_FIRE),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_EAST),
    WAIT(20),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs166_g1_s0_lives1_dlg0[] = { /* 0x8218e38 */
    DEBUGINFO_O(59),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(512, 1),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_WEST),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_EAST),
    WAIT(20),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    HALT,
};

static const struct ScriptCommand s_gs166_g2_s0_station_sref_script[] = { /* 0x8218f08 */
    DEBUGINFO_O(75),
    SELECT_MAP(166),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    MSG_NPC(-1, _(" Look at them go!\nThey're running for Mt. Blaze!")),
    MSG_NPC(-1, _(" Are they insane?\nMt. Blaze is doomed desolation!")),
    MSG_NPC(-1, _(" No one's ever come this far\nbefore!")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" I don't wanna go anywhere like that.")),
    TEXTBOX_CLEAR,
    WAIT(15),
    MSG_NPC(-1, _(" It can't be helped.\nOnly those brave enough will give chase!")),
    TEXTBOX_CLEAR,
    BGM_FADEOUT(90),
    WAIT(120),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs166_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs166_g2_s0_station_sref_script }; /* 0x8219150 */


static const struct ScriptCommand s_gs166_g2_s0_lives0_dlg0[] = { /* 0x821915c */
    DEBUGINFO_O(102),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" It... It's a mountain of fire!")),
    TEXTBOX_CLEAR,
    WAIT(20),
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_NPC(1, _(" Look at all that lava\npouring from the crater...")),
    MSG_NPC(1, _(" Can we even make it\nthrough there?")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" But they're catching up to\nus...")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_SOUTHEAST),
    PORTRAIT_REP(0x0001, 0x00000005),
    MSG_NPC(1, _(" What'll we do,\n{NAME_0}?")),
    TEXTBOX_CLEAR,
    WAIT(45),
    MSG_NPC(-1, _(" Look! There they are!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    MSG_NPC(-1, _(" Get them!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000002),
    MSG_NPC(1, _(" There's no choice now!")),
    MSG_NPC(1, _(" Let's go, {NAME_0}!")),
    TEXTBOX_CLEAR,
    { 0x23, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    WAIT(5),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};



static const struct ScriptCommand s_gs166_g2_s0_lives1_dlg0[] = { /* 0x821952c */
    DEBUGINFO_O(151),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_11, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ROTATE_TO(4, DIR_TRANS_11, DIRECTION_WEST),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_11, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs166_g1_s0_lives[] = { /* 0x821964c */
    /*  0 */ {   0,   2,   0,   0, {  14,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  18,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs166_g2_s0_lives[] = { /* 0x821967c */
    /*  0 */ {   0,   2,   0,   0, {  28,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  32,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs166_g1_s0_effs[] = { /* 0x82196ac */
    /*  0 */ {   0,   0,   1,   1, {  30,  28, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs166_g2_s0_effs[] = { /* 0x82196b8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  28, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82196c4 */
    &s_gs166_g0_s0_station_sref,
    &s_gs166_g1_s0_station_sref,
    &s_gs166_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs166_g0_sectors[] = { /* 0x82196d0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs166_g1_sectors[] = { /* 0x82196f8 */
    { LPARRAY(s_gs166_g1_s0_lives), 0,NULL, LPARRAY(s_gs166_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs166_g2_sectors[] = { /* 0x8219720 */
    { LPARRAY(s_gs166_g2_s0_lives), 0,NULL, LPARRAY(s_gs166_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs166_groups[] = { /* 0x8219748 */
    { LPARRAY(s_gs166_g0_sectors) },
    { LPARRAY(s_gs166_g1_sectors) },
    { LPARRAY(s_gs166_g2_sectors) },
};

static const struct GroundLink s_gs166_links[] = { /* 0x8219760 */
    /* link   0 */ { { /*x*/  28, /*y*/  25, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  32, /*y*/  27, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs166 = { LPARRAY(s_gs166_groups), s_gs166_links }; /* 0x8219770 */
