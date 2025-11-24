







static const struct ScriptCommand s_gs212_g0_s0_station_sref_script[] = { /* 0x8264834 */
    DEBUGINFO_O(10),
    SELECT_MAP(212),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs212_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs212_g0_s0_station_sref_script }; /* 0x82648a0 */

static const struct ScriptCommand s_gs212_g1_s0_station_sref_script[] = { /* 0x82648ac */
    DEBUGINFO_O(19),
    SELECT_MAP(212),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_IN_THE_DEPTHS_OF_THE_PIT),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs212_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs212_g1_s0_station_sref_script }; /* 0x826494c */

static const struct ScriptCommand s_gs212_g1_s0_eff0_script[] = { /* 0x8264958 */
    DEBUGINFO_O(34),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x000000ab,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s0_obj0_dlg0[] = { /* 0x8264998 */
    DEBUGINFO_O(41),
    CAMERA_END_PAN,
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s0_lives0_dlg0[] = { /* 0x82649c8 */
    DEBUGINFO_O(47),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(497),
    ALERT_CUE(7),
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00fa7d7d, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00fa7d7d, NULL },
    WAIT_FANFARE2(497),
    WAIT(20),
    FANFARE_PLAY2(497),
    ALERT_CUE(7),
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00550000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00550000, NULL },
    WAIT_FANFARE2(497),
    WAIT(20),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Gwooooooh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    MSG_NPC(2, _(" Urghgh...{WAIT_PRESS}\nI... I lost...")),
    MSG_NPC(2, _(" You...{WAIT_PRESS}\nWhat do you wish?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    WALK_RELATIVE(256, 0, -24),
    WAIT(60),
    ALERT_CUE(6),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000018, NULL },
    ALERT_CUE(7),
    MSG_NPC(2, _(" ...Wh-what?! This is...\nthe {COLOR GREEN_I}Clear Wing{RESET}...")),
    MSG_NPC(2, _(" ...I understand now.{WAIT_PRESS}\nTo meet that Pokémon...")),
    MSG_NPC(2, _(" ............{WAIT_PRESS}Stand aside.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    BGM_FADEOUT(30),
    ALERT_CUE(7),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    AWAIT_CUE(5),
    SELECT_OBJECTS(1, 1),
    AWAIT_CUE(5),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000004,  0x00550000, NULL },
    WAIT(1),
    { 0x27, 0x01,  0x0005,  0x00000004,  0x00550000, NULL },
    WAIT(10),
    SELECT_ANIMATION(2),
    ALERT_CUE(8),
    MSG_INSTANT(_("{CENTER_ALIGN}Entei's fiery blast made\n{CENTER_ALIGN}the {COLOR GREEN_I}Clear Wing{RESET} flare!")),
    MSG_INSTANT(_("{CENTER_ALIGN}The {COLOR GREEN_I}Clear Wing{RESET}...{WAIT_PRESS}\n{CENTER_ALIGN}transformed into the {COLOR GREEN_I}Red Wing{RESET}!")),
    TEXTBOX_CLEAR,
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(10),
    FANFARE_PLAY2(507),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    CANCEL_EFFECTS(1, 0),
    CANCEL_OBJECTS(1, 1),
    SELECT_EFFECTS(1, 1),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    WAIT_FANFARE2(507),
    BGM_SWITCH(MUS_IN_THE_DEPTHS_OF_THE_PIT),
    WAIT(60),
    MSG_NPC(2, _(" Take this and go west!")),
    MSG_NPC(2, _(" There, you will find\nthe {COLOR YELLOW_D}Lightning Field{RESET}.")),
    MSG_NPC(2, _(" You will know your path\nthere!")),
    MSG_NPC(2, _(" Now go!\nTo the {COLOR YELLOW_D}Lightning Field{RESET}!")),
    TEXTBOX_CLEAR,
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(20),
    CANCEL_EFFECTS(1, 1),
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(212),
    MSG_INSTANT(_("{CENTER_ALIGN}{NAME_0} received\n{CENTER_ALIGN}the {COLOR GREEN_I}Red Wing{RESET}.")),
    WAIT_FANFARE1(212),
    TEXTBOX_CLEAR,
    WAIT(20),
    MSG_INSTANT(_("{CENTER_ALIGN}And...")),
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Lightning Field{RESET}!")),
    WAIT_FANFARE1(205),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};






static const struct ScriptCommand s_gs212_g1_s0_lives1_dlg0[] = { /* 0x826518c */
    DEBUGINFO_O(144),
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
    FANFARE_PLAY2(663),
    { 0x56, 0x00,  0x0000,  0x0000004e,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT_FANFARE2(663),
    SELECT_ANIMATION(22),
    WAIT(30),
    FANFARE_PLAY2(653),
    ALERT_CUE(5),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s1_eff0_script[] = { /* 0x826539c */
    DEBUGINFO_O(180),
    { 0x56, 0x00,  0x0000,  0x000000ac,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs212_g1_s1_obj0_dlg0[] = { /* 0x82653cc */
    DEBUGINFO_O(186),
    { 0x56, 0x00,  0x0000,  0x0000004c,  0x00000000, NULL },
    WAIT(10),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    FANFARE_PLAY2(739),
    { 0x56, 0x00,  0x0000,  0x0000013d,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT_FANFARE2(739),
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
