










static const struct ScriptCommand s_gs188_g0_s0_station_sref_script[] = { /* 0x8239178 */
    DEBUGINFO,
    SELECT_MAP(188),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs188_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs188_g0_s0_station_sref_script }; /* 0x82391e4 */

static const struct ScriptCommand s_gs188_g1_s0_station_sref_script[] = { /* 0x82391f0 */
    DEBUGINFO,
    SELECT_MAP(188),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(111),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x02, 0x00,  0x0000,  0x00000007,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs188_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs188_g1_s0_station_sref_script }; /* 0x8239280 */

static const struct ScriptCommand s_gs188_g1_s0_eff0_script[] = { /* 0x823928c */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs188_g1_s0_lives0_dlg0[] = { /* 0x82392cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000060,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0004,  0x00000055,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This must be the foot of\n#CDMt. Thunder#R...")),
    VARIANT(/* == */  1, _(" I wonder if $n3's\nteam is already on the way...")),
    VARIANT_DEFAULT(_(" This is the foot of\n#CDMt. Thunder#R.")),
    VARIANT_DEFAULT(_(" I wonder...\nIs $n3's team already on\ntheir way?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n2, huh...#W\nIt sounds really tough.")),
    VARIANT_DEFAULT(_(" $n2...#W\nIt sounds very tough...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Brr... I'm shaking...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But I can't be spooked\nby this.")),
    VARIANT(/* == */  1, _(" Our mission is to rescue\n$n4.")),
    VARIANT(/* == */  1, _(" $n0, let's give it\nour best!")),
    VARIANT(/* == */  3, _(" I shouldn't get all scared\nnow!")),
    VARIANT(/* == */  3, _(" Our objective is to rescue\n$n4.")),
    VARIANT(/* == */  3, _(" $n0, let's do our\nbest!")),
    VARIANT_DEFAULT(_(" I can't be scared now.")),
    VARIANT_DEFAULT(_(" Our objective is simple.\nWe're rescuing $n4.")),
    VARIANT_DEFAULT(_(" $n0, let's try\nour best!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs188_g1_s0_lives1_dlg0[] = { /* 0x8239824 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(8),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs188_g2_s0_station_sref_script[] = { /* 0x8239954 */
    DEBUGINFO,
    SELECT_MAP(188),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(111),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x02, 0x00,  0x0000,  0x00000007,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs188_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs188_g2_s0_station_sref_script }; /* 0x82399e4 */

static const struct ScriptCommand s_gs188_g2_s0_eff0_script[] = { /* 0x82399f0 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs188_g2_s0_lives0_dlg0[] = { /* 0x8239a30 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000055,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" $n0!\nThis time, we're gonna rescue\n$n2!")),
    VARIANT(/* == */  1, _(" Let's give it our best!")),
    VARIANT_DEFAULT(_(" $n0!\nWe'll rescue $n2 this time for\nsure!")),
    VARIANT_DEFAULT(_(" Let's work hard at it!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs188_g2_s0_lives1_dlg0[] = { /* 0x8239c48 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    WAIT(8),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs188_g1_s0_lives[] = { /* 0x8239d08 */
    /*  0 */ {   0,   2,   0,   0, {  23,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  27,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs188_g2_s0_lives[] = { /* 0x8239d38 */
    /*  0 */ {   0,   2,   0,   0, {  23,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  27,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs188_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs188_g1_s0_effs[] = { /* 0x8239d68 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs188_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs188_g2_s0_effs[] = { /* 0x8239d74 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs188_g2_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8239d80 */
    &s_gs188_g0_s0_station_sref,
    &s_gs188_g1_s0_station_sref,
    &s_gs188_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs188_g0_sectors[] = { /* 0x8239d8c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs188_g1_sectors[] = { /* 0x8239db4 */
    { LPARRAY(s_gs188_g1_s0_lives), 0,NULL, LPARRAY(s_gs188_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs188_g2_sectors[] = { /* 0x8239ddc */
    { LPARRAY(s_gs188_g2_s0_lives), 0,NULL, LPARRAY(s_gs188_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs188_groups[] = { /* 0x8239e04 */
    { LPARRAY(s_gs188_g0_sectors) },
    { LPARRAY(s_gs188_g1_sectors) },
    { LPARRAY(s_gs188_g2_sectors) },
    {},
};

static const struct GroundLink s_gs188_links[] = { /* 0x8239e24 */
    /* link   0 */ { { /*x*/  23, /*y*/  18, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  27, /*y*/  18, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  25, /*y*/  11, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs188 = { LPARRAY(s_gs188_groups), s_gs188_links }; /* 0x8239e3c */
