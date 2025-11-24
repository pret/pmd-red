












static const struct ScriptCommand s_gs183_g0_s0_station_sref_script[] = { /* 0x8233258 */
    DEBUGINFO_O(15),
    SELECT_MAP(183),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs183_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs183_g0_s0_station_sref_script }; /* 0x82332c4 */

static const struct ScriptCommand s_gs183_g1_s0_station_sref_script[] = { /* 0x82332d0 */
    DEBUGINFO_O(24),
    SELECT_MAP(183),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_IN_THE_DEPTHS_OF_THE_PIT),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs183_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs183_g1_s0_station_sref_script }; /* 0x8233350 */

static const struct ScriptCommand s_gs183_g1_s0_eff0_script[] = { /* 0x823335c */
    DEBUGINFO_O(37),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    CAMERA_INIT_PAN,
    { 0x89, 0x1c,  0x0100,  0x00000004,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs183_g1_s0_lives0_dlg0[] = { /* 0x82333ec */
    DEBUGINFO_O(49),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Grr... I can't keep up!{WAIT_PRESS}\nI'll flee for now!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    WAIT(90),
    ALERT_CUE(4),
    ALERT_CUE(6),
    WAIT(5),
    WALK_RELATIVE(256, 0, -24),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey!\nWe sent {NAME_3} packing!")),
    VARIANT(/* == */  1, _(" You're safe now.\nCome on down!")),
    VARIANT_DEFAULT(_(" Hey there!\nWe chased {NAME_3} off!")),
    VARIANT_DEFAULT(_(" It's OK now.\nCome down over here.")),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000041),
    MSG_NPC(2, _(" I can't...\nI'm too scared to move...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK, no sweat.{WAIT_PRESS}\nWe'll go to you. Just wait.")),
    VARIANT_DEFAULT(_(" OK, no problem.{WAIT_PRESS}\nWe'll come to you. Just wait.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" ...Whoa.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wow. This is some cliff...\nI can't see the bottom.")),
    VARIANT_DEFAULT(_(" Sheesh! Look at this cliff...\nI can't see the bottom.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_NPC(1, _(" {NAME_0}, what'll\nwe do?\nWe can't get across this.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 1),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(-1, _(" BZBZBZZ!")),
    ALERT_CUE(6),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! It's those {NAME_4}\nfrom that rescue!")),
    VARIANT_DEFAULT(_(" Oh, hi!\nYou're the {NAME_4} we saved!")),
    TEXTBOX_CLEAR,
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, 2, 0),
    MSG_NPC(4, _(" WE GOT WORD OF THIS.{WAIT_PRESS}\nWE CAN RESCUE DIGLETT FROM THE\nSKY. BZBZBZZ!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" HOLD ON TO US TIGHT.\nBZBZBZZZ!")),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, -2, 0),
    MSG_NPC(4, _(" DON'T BE SCARED.\nWE WON'T MAKE THE MISTAKE OF\nZAPPING YOU. BZBZBZZT!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};








static const struct ScriptCommand s_gs183_g1_s0_lives1_dlg0[] = { /* 0x8233bec */
    DEBUGINFO_O(137),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 0, -24),
    AWAIT_CUE(6),
    WALK_GRID(128, 0),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x62, 0x00,  0x0080,  0x00000000,  0x00000008, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    WALK_RELATIVE(128, 0, -8),
    SELECT_ANIMATION(40),
    FANFARE_PLAY2(463),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s0_lives2_dlg0[] = { /* 0x8233d8c */
    DEBUGINFO_O(166),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    SELECT_ANIMATION(9),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s0_lives3_dlg0[] = { /* 0x8233e3c */
    DEBUGINFO_O(180),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    FANFARE_PLAY2(459),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000045,  0x00000000, NULL },
    ALERT_CUE(5),
    END_DELETE,
};

static const struct ScriptCommand s_gs183_g1_s1_lives0_dlg0[] = { /* 0x8233eec */
    DEBUGINFO_O(194),
    WARP_WAYPOINT(0, 2),
    { 0x60, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(483),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WALK_GRID(128, 4),
    CMD_UNK_93(4, DIR_TRANS_10, 68),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    WALK_RELATIVE(76, 0, -16),
    CMD_UNK_93(4, DIR_TRANS_10, 68),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s1_lives1_dlg0[] = { /* 0x823405c */
    DEBUGINFO_O(220),
    WARP_WAYPOINT(0, 1),
    { 0x60, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    AWAIT_CUE(8),
    WALK_GRID(128, 3),
    CMD_UNK_93(4, DIR_TRANS_10, 68),
    AWAIT_CUE(8),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    WALK_RELATIVE(76, 0, -16),
    CMD_UNK_93(4, DIR_TRANS_10, 68),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs183_g1_s0_lives[] = { /* 0x823418c */
    /*  0 */ {   0,   4,   0,   0, {  26,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  68,   0,   0,   0, {  28,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  69,   0,   0,   0, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs183_g1_s1_lives[] = { /* 0x82341ec */
    /*  0 */ {  61,   0,   0,   0, {  27,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s1_lives0_dlg0,
    } },
    /*  1 */ {  62,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s1_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs183_g1_s0_effs[] = { /* 0x823421c */
    /*  0 */ {   0,   0,   1,   1, {  28,  39, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs183_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8234228 */
    &s_gs183_g0_s0_station_sref,
    &s_gs183_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs183_g0_sectors[] = { /* 0x8234230 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs183_g1_sectors[] = { /* 0x8234258 */
    { LPARRAY(s_gs183_g1_s0_lives), 0,NULL, LPARRAY(s_gs183_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs183_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs183_groups[] = { /* 0x82342a8 */
    { LPARRAY(s_gs183_g0_sectors) },
    { LPARRAY(s_gs183_g1_sectors) },
};

static const struct GroundLink s_gs183_links[] = { /* 0x82342b8 */
    /* link   0 */ { { /*x*/  29, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  30, /*y*/  32, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  27, /*y*/  32, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  31, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  26, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs183 = { LPARRAY(s_gs183_groups), s_gs183_links }; /* 0x82342e0 */
