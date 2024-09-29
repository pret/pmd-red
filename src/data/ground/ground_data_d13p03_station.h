







static const struct ScriptCommand s_gs209_g0_s0_station_sref_script[] = { /* 0x82620a8 */
    DEBUGINFO,
    SELECT_MAP(209),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs209_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs209_g0_s0_station_sref_script }; /* 0x8262114 */

static const struct ScriptCommand s_gs209_g1_s0_station_sref_script[] = { /* 0x8262120 */
    DEBUGINFO,
    SELECT_MAP(209),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(26),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    FANFARE_FADEOUT2(16, 512),
    RET,
};

static const struct ScriptRef s_gs209_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs209_g1_s0_station_sref_script }; /* 0x82621b0 */

static const struct ScriptCommand s_gs209_g1_s0_eff0_script[] = { /* 0x82621bc */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0500,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs209_g1_s0_lives0_dlg0[] = { /* 0x826223c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gyaaaaaaaaaaaaaaaah!") },
    WAIT(30),
    FANFARE_PLAY2(493),
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(20),
    FANFARE_PLAY2(493),
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(120),
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(848),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002, -0x00000002,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Gwaargh!") },
    WAIT(90),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x0000001e,  0x00ffffff, NULL },
    WAIT(30),
    FANFARE_PLAY2(512),
    { 0x27, 0x00,  0x0005,  0x00000010,  0x00ffffff, NULL },
    { 0x97, 0x00,  0x0002,  0x00000005,  0x00000002, NULL },
    WAIT(40),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000001, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(60),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-wh-what?! Quake?!#W\nIt can't be!")),
    VARIANT(/* == */  1, _(" We're up on clouds...")),
    VARIANT_DEFAULT(_(" Wh-wh-what?!\nAn earthquake?!#W\nIt's not possible!")),
    VARIANT_DEFAULT(_(" We're on top of clouds...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" These are shock waves!#W\nAnd they're huge!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's it! I get it now!#W\nLook straight up, $n2!")),
    VARIANT_DEFAULT(_(" That's it! I got it!#W\nLook straight up, $n2!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};





static const struct ScriptCommand s_gs209_g1_s0_lives1_dlg0[] = { /* 0x826282c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives2_dlg0[] = { /* 0x826290c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives3_dlg0[] = { /* 0x82629ac */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives4_dlg0[] = { /* 0x8262a4c */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(652),
    { 0x97, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(8),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(672),
    { 0x62, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100, -0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100, -0x00000001,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(672),
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(774),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0x36, 0x00, -0x0001,  0x00000000,  0x00000000, _("Gyaaaaaaaaaaaaaah!") },
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(90),
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0018,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(517),
    { 0x28, 0x01,  0x0005,  0x00000004,  0x00ffffff, NULL },
    WAIT(3),
    { 0x27, 0x00,  0x0005,  0x00000004,  0x00ffffff, NULL },
    { 0x54, 0x00,  0x0019,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_station_sref_script[] = { /* 0x8262e10 */
    DEBUGINFO,
    SELECT_MAP(209),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(26),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000001, NULL },
    WAIT(15),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x00000010,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs209_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs209_g2_s0_station_sref_script }; /* 0x8262eb0 */

static const struct ScriptCommand s_gs209_g2_s0_eff0_script[] = { /* 0x8262ebc */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x14,  0x0500,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs209_g2_s0_lives0_dlg0[] = { /* 0x8262f4c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" What is that?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's a shooting star!\nAnd it's gigantic!")),
    VARIANT(/* == */  1, _(" It's going to destroy\nthe world if it isn't stopped!")),
    VARIANT_DEFAULT(_(" It's a shooting star!\nAnd it's enormous!")),
    VARIANT_DEFAULT(_(" It will destroy the world\nif it continues on its path!")),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's why we came,\n$n2. We need you to destroy\nthat falling star!")),
    VARIANT(/* == */  3, _(" That's why we came,\n$n2.\nPlease, destroy the falling star!")),
    VARIANT_DEFAULT(_(" That's why we came,\n$n2.\nPlease, destroy the falling star!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...So, that is why...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yes! Hurry!\nDestroy it!")),
    VARIANT_DEFAULT(_(" Yes!\nPlease hurry and destroy it!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ............#WBefore I try...#W\nI need to know your resolve.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The star has come too close.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" If I were to loose my\nHyper Beam here...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" You would not escape\nunscathed!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So what?!#W\nWe knew that right from the start!")),
    VARIANT_DEFAULT(_(" So?!#W\nWe accepted that from the start!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Well said!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    FANFARE_PLAY2(664),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Take charge of your destiny!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(513),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs209_g2_s0_lives1_dlg0[] = { /* 0x8263660 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives2_dlg0[] = { /* 0x82636a0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives3_dlg0[] = { /* 0x82636e0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives4_dlg0[] = { /* 0x8263720 */
    DEBUGINFO,
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0018,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_eff1_script[] = { /* 0x8263860 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000006f,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000070,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000, -0x0000001a,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x00000133,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000134,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_station_sref_script[] = { /* 0x8263980 */
    DEBUGINFO,
    SELECT_MAP(209),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(26),
    { 0x97, 0x00,  0x0002,  0x00000005,  0x00000002, NULL },
    WAIT(15),
    { 0x27, 0x00,  0x0005,  0x00000010,  0x00ffffff, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(60),
    { 0x28, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    WAIT(120),
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2b, 0x00,  0x0000, -0x00000001, -0x00000001, NULL },
    WAIT(240),
    RET,
};

static const struct ScriptRef s_gs209_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs209_g3_s0_station_sref_script }; /* 0x8263a70 */

static const struct ScriptCommand s_gs209_g3_s0_lives0_dlg0[] = { /* 0x8263a7c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(30),
    { 0x2b, 0x00,  0x0000,  0x0000000f,  0x0000000f, NULL },
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Waaaaaaaaaaaaaaaaaah!") },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs209_g3_s0_lives1_dlg0[] = { /* 0x8263b44 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives2_dlg0[] = { /* 0x8263b84 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives3_dlg0[] = { /* 0x8263bb4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives4_dlg0[] = { /* 0x8263be4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_eff1_script[] = { /* 0x8263c24 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000134,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs209_g1_s0_lives[] = { /* 0x8263c54 */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g1_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs209_g2_s0_lives[] = { /* 0x8263ccc */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g2_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs209_g3_s0_lives[] = { /* 0x8263d44 */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g3_s0_lives4_dlg0,
    } },
};

static const struct GroundEffectData s_gs209_g1_s0_effs[] = { /* 0x8263dbc */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs209_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs209_g2_s0_effs[] = { /* 0x8263dc8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs209_g2_s0_eff0_script },
    /*  1 */ {   4,   4,   1,   1, {  35,  31, 0, 0 }, s_gs209_g2_s0_eff1_script },
};

static const struct GroundEffectData s_gs209_g3_s0_effs[] = { /* 0x8263de0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
    /*  1 */ {   3,   0,   1,   1, {  35,  28, 0, 0 }, s_gs209_g3_s0_eff1_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8263df8 */
    &s_gs209_g0_s0_station_sref,
    &s_gs209_g1_s0_station_sref,
    &s_gs209_g2_s0_station_sref,
    &s_gs209_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs209_g0_sectors[] = { /* 0x8263e08 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs209_g1_sectors[] = { /* 0x8263e30 */
    { LPARRAY(s_gs209_g1_s0_lives), 0,NULL, LPARRAY(s_gs209_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs209_g2_sectors[] = { /* 0x8263e58 */
    { LPARRAY(s_gs209_g2_s0_lives), 0,NULL, LPARRAY(s_gs209_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs209_g3_sectors[] = { /* 0x8263e80 */
    { LPARRAY(s_gs209_g3_s0_lives), 0,NULL, LPARRAY(s_gs209_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs209_groups[] = { /* 0x8263ea8 */
    { LPARRAY(s_gs209_g0_sectors) },
    { LPARRAY(s_gs209_g1_sectors) },
    { LPARRAY(s_gs209_g2_sectors) },
    { LPARRAY(s_gs209_g3_sectors) },
};

static const struct GroundLink s_gs209_links[] = { /* 0x8263ec8 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs209 = { LPARRAY(s_gs209_groups), s_gs209_links }; /* 0x8263ed0 */
