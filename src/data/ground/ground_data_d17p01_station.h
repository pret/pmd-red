







static const struct ScriptCommand s_gs213_g0_s0_station_sref_script[] = { /* 0x8265640 */
    DEBUGINFO_O(10),
    SELECT_MAP(213),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs213_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs213_g0_s0_station_sref_script }; /* 0x82656ac */

static const struct ScriptCommand s_gs213_g1_s0_station_sref_script[] = { /* 0x82656b8 */
    DEBUGINFO_O(19),
    SELECT_MAP(213),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_IN_THE_DEPTHS_OF_THE_PIT),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs213_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs213_g1_s0_station_sref_script }; /* 0x8265758 */

static const struct ScriptCommand s_gs213_g1_s0_eff0_script[] = { /* 0x8265764 */
    DEBUGINFO_O(34),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x000000ac,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s0_obj0_dlg0[] = { /* 0x82657a4 */
    DEBUGINFO_O(41),
    CAMERA_END_PAN,
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s0_lives0_dlg0[] = { /* 0x82657d4 */
    DEBUGINFO_O(47),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(497),
    ALERT_CUE(7),
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00707000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00707000, NULL },
    WAIT_FANFARE2(497),
    WAIT(20),
    FANFARE_PLAY2(497),
    ALERT_CUE(7),
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00505000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00505000, NULL },
    WAIT_FANFARE2(497),
    WAIT(20),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT_MIDTOP_FLIP, 0x0002, 0x00000000),
    FANFARE_PLAY2(685),
    MSG_NPC(2, _(" Gwooooooooooh!{WAIT_PRESS}\n...H-how dare you!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    MSG_NPC(2, _(" How...{WAIT_PRESS}\nHow did this happen...?")),
    MSG_NPC(2, _(" But regardless, you have\nwon.{WAIT_PRESS}\nLet me hear your wish.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    WALK_RELATIVE(256, 0, -24),
    WAIT(60),
    ALERT_CUE(6),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000018, NULL },
    ALERT_CUE(7),
    MSG_NPC(2, _(" ...Hm?! This...{WAIT_PRESS}\nThis is the {COLOR GREEN_I}Red Wing{RESET}...")),
    MSG_NPC(2, _(" ............{WAIT_PRESS}You...{WAIT_PRESS}\nStand back!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    BGM_FADEOUT(30),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    SELECT_OBJECTS(1, 1),
    AWAIT_CUE(5),
    WAIT(10),
    { 0x28, 0x00,  0x0005,  0x00000003,  0x00505000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(1),
    { 0x27, 0x01,  0x0005,  0x00000003,  0x00505000, NULL },
    ALERT_CUE(8),
    MSG_INSTANT(_("{CENTER_ALIGN}Raikou's thunderbolt\n{CENTER_ALIGN}electrified the {COLOR GREEN_I}Red Wing{RESET}!")),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR GREEN_I}Red Wing{RESET}...{WAIT_PRESS}\n{CENTER_ALIGN}transformed into\n{CENTER_ALIGN}the {COLOR GREEN_I}Sunset Wing{RESET}!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(10),
    FANFARE_PLAY2(507),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    CANCEL_EFFECTS(1, 0),
    CANCEL_OBJECTS(1, 1),
    SELECT_EFFECTS(1, 1),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    WAIT_FANFARE2(507),
    BGM_SWITCH(MUS_IN_THE_DEPTHS_OF_THE_PIT),
    WAIT(60),
    MSG_INSTANT(_("{CENTER_ALIGN}Its subtle gradation of yellow\n{CENTER_ALIGN}to red is a truly beauteous sight!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(2, _(" Go northeast!")),
    MSG_NPC(2, _(" To a place called the\n{COLOR YELLOW_D}Northwind Field{RESET}.")),
    MSG_NPC(2, _(" You will find a Pokémon\nthere named Suicune.")),
    MSG_NPC(2, _(" If you are lucky enough to\nmeet Suicune...")),
    MSG_NPC(2, _(" Perhaps your wish will\ncome true!")),
    TEXTBOX_CLEAR,
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(20),
    CANCEL_EFFECTS(1, 1),
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(212),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} received\n{CENTER_ALIGN}the {COLOR GREEN_I}Sunset Wing{RESET}.")),
    WAIT_FANFARE1(212),
    TEXTBOX_CLEAR,
    WAIT(20),
    MSG_INSTANT(_("{CENTER_ALIGN}And...")),
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Northwind Field{RESET}!")),
    WAIT_FANFARE1(205),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};






static const struct ScriptCommand s_gs213_g1_s0_lives1_dlg0[] = { /* 0x826604c */
    DEBUGINFO_O(146),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    WAIT(10),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    AWAIT_CUE(7),
    SELECT_ANIMATION(19),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT_FANFARE2(465),
    AWAIT_CUE(7),
    SELECT_ANIMATION(9),
    WAIT(30),
    FANFARE_PLAY2(708),
    { 0x56, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT_FANFARE2(708),
    SELECT_ANIMATION(22),
    WAIT(15),
    FANFARE_PLAY2(479),
    WAIT_FANFARE2(479),
    ALERT_CUE(5),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s1_eff0_script[] = { /* 0x826626c */
    DEBUGINFO_O(183),
    { 0x56, 0x00,  0x0000,  0x000000ad,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s1_obj0_dlg0[] = { /* 0x826629c */
    DEBUGINFO_O(189),
    FANFARE_PLAY2(662),
    { 0x56, 0x00,  0x0000,  0x000000b1,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x000000b2,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    FANFARE_PLAY2(726),
    WAIT_FANFARE2(726),
    FANFARE_PLAY2(726),
    WAIT(45),
    WAIT_FANFARE2(726),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    HALT,
};

static const struct GroundLivesData s_gs213_g1_s0_lives[] = { /* 0x82663ac */
    /*  0 */ {   0,   4,   0,   0, {  22,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs213_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 117,   0,   0,   0, {  22,  14, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs213_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs213_g1_s0_objs[] = { /* 0x82663dc */
    /*  0 */ {   0,   0,   1,   1, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs213_g1_s0_obj0_dlg0,
    } },
};

static const struct GroundObjectData s_gs213_g1_s1_objs[] = { /* 0x82663f4 */
    /*  0 */ {  67,   0,   2,   2, {  22,  14, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs213_g1_s1_obj0_dlg0,
    } },
};

static const struct GroundEffectData s_gs213_g1_s0_effs[] = { /* 0x826640c */
    /*  0 */ {   5,   0,   1,   1, {  22,  14, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs213_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs213_g1_s1_effs[] = { /* 0x8266418 */
    /*  0 */ {   5,   0,   1,   1, {  22,  14, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs213_g1_s1_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8266424 */
    &s_gs213_g0_s0_station_sref,
    &s_gs213_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs213_g0_sectors[] = { /* 0x826642c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs213_g1_sectors[] = { /* 0x8266454 */
    { LPARRAY(s_gs213_g1_s0_lives), LPARRAY(s_gs213_g1_s0_objs), LPARRAY(s_gs213_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { 0,NULL, LPARRAY(s_gs213_g1_s1_objs), LPARRAY(s_gs213_g1_s1_effs), 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs213_groups[] = { /* 0x82664a4 */
    { LPARRAY(s_gs213_g0_sectors) },
    { LPARRAY(s_gs213_g1_sectors) },
};

static const struct GroundLink s_gs213_links[] = { /* 0x82664b4 */
    {},
};

const GroundScriptHeader gGroundScript_gs213 = { LPARRAY(s_gs213_groups), s_gs213_links }; /* 0x82664bc */
