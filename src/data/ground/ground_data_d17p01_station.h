







static const struct ScriptCommand s_gs213_g0_s0_station_sref_script[] = { /* 0x8265640 */
    DEBUGINFO,
    SELECT_MAP(213),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs213_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs213_g0_s0_station_sref_script }; /* 0x82656ac */

static const struct ScriptCommand s_gs213_g1_s0_station_sref_script[] = { /* 0x82656b8 */
    DEBUGINFO,
    SELECT_MAP(213),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs213_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs213_g1_s0_station_sref_script }; /* 0x8265758 */

static const struct ScriptCommand s_gs213_g1_s0_eff0_script[] = { /* 0x8265764 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000ac,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s0_obj0_dlg0[] = { /* 0x82657a4 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s0_lives0_dlg0[] = { /* 0x82657d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00707000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00707000, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(497),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00505000, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00505000, NULL },
    { 0xe2, 0x00,  0x01f1,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0d,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(685),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Gwooooooooooh!#W\n...H-how dare you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" How...#W\nHow did this happen...?") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" But regardless, you have\nwon.#W\nLet me hear your wish.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000018, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...Hm?! This...#W\nThis is the #CIRed Wing#R...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#WYou...#W\nStand back!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x62, 0x00,  0x0100,  0x00000000,  0x00000008, NULL },
    BGM_FADEOUT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    SELECT_OBJECTS(1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x28, 0x00,  0x0005,  0x00000003,  0x00505000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    WAIT(1),
    { 0x27, 0x01,  0x0005,  0x00000003,  0x00505000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Raikou's thunderbolt\n#+electrified the #CIRed Wing#R!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The #CIRed Wing#R...#W\n#+transformed into\n#+the #CISunset Wing#R!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
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
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Its subtle gradation of yellow\n#+to red is a truly beauteous sight!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Go northeast!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" To a place called the\n#CDNorthwind Field#R.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You will find a Pokémon\nthere named Suicune.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If you are lucky enough to\nmeet Suicune...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Perhaps your wish will\ncome true!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    WAIT(20),
    CANCEL_EFFECTS(1, 1),
    WAIT(20),
    BGM_STOP,
    FANFARE_PLAY(212),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 received\n#+the #CISunset Wing#R.") },
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+And...") },
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Gained access to\n#+the #CDNorthwind Field#R!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs213_g1_s0_lives1_dlg0[] = { /* 0x826604c */
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
    FANFARE_PLAY2(708),
    { 0x56, 0x00,  0x0000,  0x00000062,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x02c4,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(479),
    { 0xe2, 0x00,  0x01df,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s1_eff0_script[] = { /* 0x826626c */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000000ad,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs213_g1_s1_obj0_dlg0[] = { /* 0x826629c */
    DEBUGINFO,
    FANFARE_PLAY2(662),
    { 0x56, 0x00,  0x0000,  0x000000b1,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x000000b2,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 1),
    FANFARE_PLAY2(726),
    { 0xe2, 0x00,  0x02d6,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(726),
    WAIT(45),
    { 0xe2, 0x00,  0x02d6,  0x00000000,  0x00000000, NULL },
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

/*extern*/ const struct GroundScriptHeader gGroundScript_gs213 = { LPARRAY(s_gs213_groups), s_gs213_links }; /* 0x82664bc */
