







static const struct ScriptCommand s_gs212_g0_s0_station_sref_script[] = { /* 0x8264834 */
    DEBUGINFO,
    SELECT_MAP(212),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs212_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs212_g0_s0_station_sref_script }; /* 0x82648a0 */

static const struct ScriptCommand s_gs212_g1_s0_station_sref_script[] = { /* 0x82648ac */
    DEBUGINFO,
    SELECT_MAP(212),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs212_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs212_g1_s0_station_sref_script }; /* 0x826494c */

static const struct ScriptCommand s_gs212_g1_s0_eff0_script[] = { /* 0x8264958 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000ab,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s0_obj0_dlg0[] = { /* 0x8264998 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s0_lives0_dlg0[] = { /* 0x82649c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00fa7d7d, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00fa7d7d, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00550000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00550000, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Gwooooooh!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Urghgh...{WAIT_PRESS}\nI... I lost...")),
    MSG_NPC(2, _(" You...{WAIT_PRESS}\nWhat do you wish?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000018, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" ...Wh-what?! This is...\nthe {COLOR GREEN_I}Clear Wing{RESET}...")),
    MSG_NPC(2, _(" ...I understand now.{WAIT_PRESS}\nTo meet that Pokémon...")),
    MSG_NPC(2, _(" ............{WAIT_PRESS}Stand aside.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    BGM_FADEOUT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_OBJECTS(1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000004,  0x00550000, NULL },
    WAIT(1),
    { 0x27, 0x01,  0x0005,  0x00000004,  0x00550000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Entei's fiery blast made\n{CENTER_ALIGN}the {COLOR GREEN_I}Clear Wing{RESET} flare!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The {COLOR GREEN_I}Clear Wing{RESET}...{WAIT_PRESS}\n{CENTER_ALIGN}transformed into the {COLOR GREEN_I}Red Wing{RESET}!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(10),
    FANFARE_PLAY2(507),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    CANCEL_EFFECTS(1, 0),
    CANCEL_OBJECTS(1, 1),
    SELECT_EFFECTS(1, 1),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    { 0xe2, 0x00,  0x01fb,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(114),
    WAIT(60),
    MSG_NPC(2, _(" Take this and go west!")),
    MSG_NPC(2, _(" There, you will find\nthe {COLOR YELLOW_D}Lightning Field{RESET}.")),
    MSG_NPC(2, _(" You will know your path\nthere!")),
    MSG_NPC(2, _(" Now go!\nTo the {COLOR YELLOW_D}Lightning Field{RESET}!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(20),
    CANCEL_EFFECTS(1, 1),
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(212),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_0} received\n{CENTER_ALIGN}the {COLOR GREEN_I}Red Wing{RESET}.") },
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}And...") },
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Lightning Field{RESET}!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs212_g1_s0_lives1_dlg0[] = { /* 0x826518c */
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
    WAIT(30),
    FANFARE_PLAY2(663),
    { 0x56, 0x00,  0x0000,  0x0000004e,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x0297,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(653),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s1_eff0_script[] = { /* 0x826539c */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000000ac,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s1_obj0_dlg0[] = { /* 0x82653cc */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000004c,  0x00000000, NULL },
    WAIT(10),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    FANFARE_PLAY2(739),
    { 0x56, 0x00,  0x0000,  0x0000013d,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x02e3,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(0),
  LABEL(1), /* = 0x01 */
    FANFARE_STOP2(739),
    { 0x56, 0x00,  0x0000,  0x0000013d,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 2),
    JUMP_LABEL(1),
  LABEL(2), /* = 0x02 */
    HALT,
};

static const struct GroundLivesData s_gs212_g1_s0_lives[] = { /* 0x826551c */
    /*  0 */ {   0,   4,   0,   0, {  22,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs212_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 116,   0,   0,   0, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs212_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs212_g1_s0_objs[] = { /* 0x826554c */
    /*  0 */ {   0,   0,   1,   1, {  22,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs212_g1_s0_obj0_dlg0,
    } },
};

static const struct GroundObjectData s_gs212_g1_s1_objs[] = { /* 0x8265564 */
    /*  0 */ {  67,   0,   2,   2, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs212_g1_s1_obj0_dlg0,
    } },
};

static const struct GroundEffectData s_gs212_g1_s0_effs[] = { /* 0x826557c */
    /*  0 */ {   5,   0,   1,   1, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs212_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs212_g1_s1_effs[] = { /* 0x8265588 */
    /*  0 */ {   5,   0,   1,   1, {  22,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs212_g1_s1_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8265594 */
    &s_gs212_g0_s0_station_sref,
    &s_gs212_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs212_g0_sectors[] = { /* 0x826559c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs212_g1_sectors[] = { /* 0x82655c4 */
    { LPARRAY(s_gs212_g1_s0_lives), LPARRAY(s_gs212_g1_s0_objs), LPARRAY(s_gs212_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { 0,NULL, LPARRAY(s_gs212_g1_s1_objs), LPARRAY(s_gs212_g1_s1_effs), 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs212_groups[] = { /* 0x8265614 */
    { LPARRAY(s_gs212_g0_sectors) },
    { LPARRAY(s_gs212_g1_sectors) },
};

static const struct GroundLink s_gs212_links[] = { /* 0x8265624 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs212 = { LPARRAY(s_gs212_groups), s_gs212_links }; /* 0x826562c */
