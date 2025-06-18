







static const struct ScriptCommand s_gs214_g0_s0_station_sref_script[] = { /* 0x82664d0 */
    DEBUGINFO,
    SELECT_MAP(214),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs214_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs214_g0_s0_station_sref_script }; /* 0x826653c */

static const struct ScriptCommand s_gs214_g1_s0_station_sref_script[] = { /* 0x8266548 */
    DEBUGINFO,
    SELECT_MAP(214),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs214_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs214_g1_s0_station_sref_script }; /* 0x82665e8 */

static const struct ScriptCommand s_gs214_g1_s0_eff0_script[] = { /* 0x82665f4 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs214_g1_s0_eff1_script[] = { /* 0x8266624 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000ad,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs214_g1_s0_lives0_dlg0[] = { /* 0x8266664 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00005077, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00005077, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00005077, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00005077, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Gwoooooooh!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" I have lost...")),
    MSG_NPC(2, _(" I admit it.\nYou are strong.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000018, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" This!{WAIT_PRESS}\nThe {COLOR GREEN_I}Sunset Wing{RESET}!")),
    MSG_NPC(2, _(" ...I see.{WAIT_PRESS}\nYou came seeking the mirage Pokémon...")),
    MSG_NPC(2, _(" ...{WAIT_PRESS}Step back.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    BGM_FADEOUT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Kyuuuuuuuuhn!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_OBJECTS(1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x00,  0x0005,  0x00000004,  0x00005077, NULL },
    { 0x27, 0x01,  0x0005,  0x00000004,  0x00005077, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The north wind swirled\n{CENTER_ALIGN}around the {COLOR GREEN_I}Sunset Wing{RESET}!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The {COLOR GREEN_I}Sunset Wing{RESET}...{WAIT_PRESS}\n{CENTER_ALIGN}transformed into the {COLOR GREEN_I}Rainbow Wing{RESET}!") },
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(10),
    FANFARE_PLAY2(507),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    CANCEL_EFFECTS(1, 0),
    CANCEL_OBJECTS(1, 1),
    SELECT_EFFECTS(1, 1),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    { 0xe2, 0x00,  0x01fb,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(114),
    WAIT(60),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Glittering in the seven colors\n{CENTER_ALIGN}of the rainbow, this wing is\n{CENTER_ALIGN}beautiful beyond description!") },
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(2, _(" This {COLOR GREEN_I}Rainbow Wing{RESET}...")),
    MSG_NPC(2, _(" It is the key to meeting\nthe mirage Pokémon.")),
    MSG_NPC(2, _(" Take this wing...")),
    MSG_NPC(2, _(" Take it to the mountain so\nhigh that its peak is obscured by clouds.")),
    MSG_NPC(2, _(" Yes...\nTake it to {COLOR YELLOW_D}Mt. Faraway{RESET}!")),
    MSG_NPC(2, _(" The mirage Pokémon is at\nits peak!")),
    TEXTBOX_CLEAR,
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(20),
    CANCEL_EFFECTS(1, 1),
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(212),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_0} received\n{CENTER_ALIGN}the {COLOR GREEN_I}Rainbow Wing{RESET}.") },
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(20),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}And...") },
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}{COLOR YELLOW_D}Mt. Faraway{RESET}!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs214_g1_s0_lives1_dlg0[] = { /* 0x8266f30 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000008, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(664),
    { 0x56, 0x00,  0x0000,  0x00000053,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x0298,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs214_g1_s1_obj0_dlg0[] = { /* 0x8267150 */
    DEBUGINFO,
    FANFARE_PLAY2(631),
    { 0x56, 0x00,  0x0000,  0x00000170,  0x00000000, NULL },
    WAIT(10),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000056,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    FANFARE_PLAY2(661),
    WAIT(20),
    FANFARE_PLAY2(661),
    WAIT(20),
    FANFARE_STOP2(661),
    WAIT(15),
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    HALT,
};

static const struct ScriptCommand s_gs214_g1_s1_eff0_script[] = { /* 0x8267280 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000000ae,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs214_g1_s0_lives[] = { /* 0x82672b0 */
    /*  0 */ {   0,   4,   0,   0, {  22,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs214_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 118,   0,   0,   0, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs214_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs214_g1_s1_objs[] = { /* 0x82672e0 */
    /*  0 */ {  67,   0,   2,   2, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs214_g1_s1_obj0_dlg0,
    } },
};

static const struct GroundEffectData s_gs214_g1_s0_effs[] = { /* 0x82672f8 */
    /*  0 */ {   0,   0,   1,   1, {  22,  21, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs214_g1_s0_eff0_script },
    /*  1 */ {   5,   0,   1,   1, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs214_g1_s0_eff1_script },
};

static const struct GroundEffectData s_gs214_g1_s1_effs[] = { /* 0x8267310 */
    /*  0 */ {   5,   0,   1,   1, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs214_g1_s1_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826731c */
    &s_gs214_g0_s0_station_sref,
    &s_gs214_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs214_g0_sectors[] = { /* 0x8267324 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs214_g1_sectors[] = { /* 0x826734c */
    { LPARRAY(s_gs214_g1_s0_lives), 0,NULL, LPARRAY(s_gs214_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { 0,NULL, LPARRAY(s_gs214_g1_s1_objs), LPARRAY(s_gs214_g1_s1_effs), 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs214_groups[] = { /* 0x826739c */
    { LPARRAY(s_gs214_g0_sectors) },
    { LPARRAY(s_gs214_g1_sectors) },
};

static const struct GroundLink s_gs214_links[] = { /* 0x82673ac */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs214 = { LPARRAY(s_gs214_groups), s_gs214_links }; /* 0x82673b4 */
