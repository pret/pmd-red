








static const struct ScriptCommand s_gs207_g0_s0_station_sref_script[] = { /* 0x825ff68 */
    DEBUGINFO,
    SELECT_MAP(207),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs207_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs207_g0_s0_station_sref_script }; /* 0x825ffd4 */

static const struct ScriptCommand s_gs207_g1_s0_station_sref_script[] = { /* 0x825ffe0 */
    DEBUGINFO,
    BGM_FADEOUT(30),
    WAIT(60),
    SELECT_MAP(207),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(22),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs207_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs207_g1_s0_station_sref_script }; /* 0x8260080 */

static const struct ScriptCommand s_gs207_g1_s0_lives0_dlg0[] = { /* 0x826008c */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0030,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    FANFARE_PLAY2(509),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    FANFARE_PLAY2(510),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x02,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Ouch...#W\nWhere are we?")),
    VARIANT_DEFAULT(_(" Owowow...#W\nWhere are we?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Wah!\n$n0, this is cool!#W\nWe're on clouds!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000007,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, wow!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" $n0, look up there!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs207_g1_s0_lives1_dlg0[] = { /* 0x8260458 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0030,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    WAIT(30),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0031,  0x00000000,  0x00000000, NULL },
    { 0x84, 0x00,  0x0080, -0x00000018,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(30),
    { 0x84, 0x00,  0x0080,  0x00000018,  0x00000010, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(30),
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x84, 0x00,  0x0099,  0x00000000, -0x00000010, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g1_s0_lives2_dlg0[] = { /* 0x8260738 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c8,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g2_s0_station_sref_script[] = { /* 0x82608a8 */
    DEBUGINFO,
    SELECT_MAP(207),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(22),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x02, 0x00,  0x001e,  0x00000013,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs207_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs207_g2_s0_station_sref_script }; /* 0x8260928 */

static const struct ScriptCommand s_gs207_g2_s0_lives0_dlg0[] = { /* 0x8260934 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000006c,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It must be at the very top...")),
    VARIANT(/* == */  1, _(" That must be where\n$n2 is...")),
    VARIANT_DEFAULT(_(" It's at the top of this\ntower...")),
    VARIANT_DEFAULT(_(" That's where $n2\nis...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" $n0!\nLet's do our best on the climb!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs207_g2_s0_lives1_dlg0[] = { /* 0x8260b8c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g2_s0_lives2_dlg0[] = { /* 0x8260c3c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g3_s0_station_sref_script[] = { /* 0x8260cac */
    DEBUGINFO,
    SELECT_MAP(207),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(22),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x02, 0x00,  0x001e,  0x00000013,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs207_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs207_g3_s0_station_sref_script }; /* 0x8260d2c */

static const struct ScriptCommand s_gs207_g3_s0_lives0_dlg0[] = { /* 0x8260d38 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0030,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(509),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right.\nWe're up in the sky again.")),
    VARIANT_DEFAULT(_(" OK.\nHere we are in the sky again.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000006,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's storm our way to\nthe top floor!")),
    VARIANT_DEFAULT(_(" Let's head for the top!\nThis is it!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs207_g3_s0_lives1_dlg0[] = { /* 0x826104c */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0030,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g3_s0_lives2_dlg0[] = { /* 0x82611dc */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c8,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs207_g1_s0_lives[] = { /* 0x826131c */
    /*  0 */ {   0,   6,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   6,   0,   0, {  25,  24, CPOS_HALFTILE, 0 }, {
        [0] = s_gs207_g1_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs207_g2_s0_lives[] = { /* 0x8261364 */
    /*  0 */ {   0,   4,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  25,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs207_g3_s0_lives[] = { /* 0x82613ac */
    /*  0 */ {   0,   0,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   0,   0,   0, {  25,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives2_dlg0,
    } },
};

static const struct GroundEffectData s_gs207_g1_s0_effs[] = { /* 0x82613f4 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs207_g2_s0_effs[] = { /* 0x8261400 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs207_g3_s0_effs[] = { /* 0x826140c */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8261418 */
    &s_gs207_g0_s0_station_sref,
    &s_gs207_g1_s0_station_sref,
    &s_gs207_g2_s0_station_sref,
    &s_gs207_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs207_g0_sectors[] = { /* 0x8261428 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs207_g1_sectors[] = { /* 0x8261450 */
    { LPARRAY(s_gs207_g1_s0_lives), 0,NULL, LPARRAY(s_gs207_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs207_g2_sectors[] = { /* 0x8261478 */
    { LPARRAY(s_gs207_g2_s0_lives), 0,NULL, LPARRAY(s_gs207_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs207_g3_sectors[] = { /* 0x82614a0 */
    { LPARRAY(s_gs207_g3_s0_lives), 0,NULL, LPARRAY(s_gs207_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs207_groups[] = { /* 0x82614c8 */
    { LPARRAY(s_gs207_g0_sectors) },
    { LPARRAY(s_gs207_g1_sectors) },
    { LPARRAY(s_gs207_g2_sectors) },
    { LPARRAY(s_gs207_g3_sectors) },
    {},
};

static const struct GroundLink s_gs207_links[] = { /* 0x82614f0 */
    /* link   0 */ { { /*x*/  25, /*y*/  12, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs207 = { LPARRAY(s_gs207_groups), s_gs207_links }; /* 0x82614f8 */
