









static const struct ScriptCommand s_gs182_g0_s0_station_sref_script[] = { /* 0x8232124 */
    DEBUGINFO,
    SELECT_MAP(182),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs182_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs182_g0_s0_station_sref_script }; /* 0x8232190 */

static const struct ScriptCommand s_gs182_g1_s0_station_sref_script[] = { /* 0x823219c */
    DEBUGINFO,
    SELECT_MAP(182),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(120),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs182_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs182_g1_s0_station_sref_script }; /* 0x823221c */

static const struct ScriptCommand s_gs182_g1_s0_lives0_dlg0[] = { /* 0x8232228 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000064, NULL },
    WAIT(15),
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, this is it...\n#CDMt. Steel#R...")),
    VARIANT(/* == */  1, _(" $n3's been taken\nto the peak here...")),
    VARIANT_DEFAULT(_(" Here we are...\n#CDMt. Steel#R...")),
    VARIANT_DEFAULT(_(" So, $n3 was\nwhisked to its peak...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" That's right!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(60),
    { 0x2d, 0x0a,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The peak is $d0F!\nThank you for helping! Farewell!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ......#W\nWell, I guess we go...")),
    VARIANT_DEFAULT(_(" ......#W\nUh... Let's go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(45),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs182_g1_s0_lives1_dlg0[] = { /* 0x82326cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000064, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs182_g1_s1_lives0_dlg0[] = { /* 0x823282c */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs182_g2_s0_station_sref_script[] = { /* 0x823290c */
    DEBUGINFO,
    SELECT_MAP(182),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(120),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs182_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs182_g2_s0_station_sref_script }; /* 0x823297c */

static const struct ScriptCommand s_gs182_g2_s0_lives0_dlg0[] = { /* 0x8232988 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000064, NULL },
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll take another shot at\n#CDMt. Steel#R.")),
    VARIANT(/* == */  1, _(" We'll rescue $n3\nno matter what it takes!")),
    VARIANT_DEFAULT(_(" We have to make another\nattempt at #CDMt. Steel#R.")),
    VARIANT_DEFAULT(_(" Whatever it takes,\nlet's rescue $n3!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" That's the spirit!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 1),
    WAIT(15),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(60),
    { 0x2d, 0x0a,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The peak is $d0F!\nThank you for helping! Farewell!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000004,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ......#W\nWell, here we go...")),
    VARIANT_DEFAULT(_(" ......#W\nUh... Let's go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    WAIT(45),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000001,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs182_g2_s0_lives1_dlg0[] = { /* 0x8232e30 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000064, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SWEAT_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00b3,  0x00000001,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs182_g2_s1_lives0_dlg0[] = { /* 0x8232fc0 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    { 0x54, 0x00,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(486),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct GroundLivesData s_gs182_g1_s0_lives[] = { /* 0x82330a0 */
    /*  0 */ {   0,   2,   0,   0, {  20,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs182_g1_s1_lives[] = { /* 0x82330d0 */
    /*  0 */ {  66,   0,   0,   0, {  22,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g1_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs182_g2_s0_lives[] = { /* 0x82330e8 */
    /*  0 */ {   0,   2,   0,   0, {  20,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  24,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs182_g2_s1_lives[] = { /* 0x8233118 */
    /*  0 */ {  66,   0,   0,   0, {  22,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs182_g2_s1_lives0_dlg0,
    } },
};

static const struct GroundEffectData s_gs182_g1_s0_effs[] = { /* 0x8233130 */
    /*  0 */ {   0,   0,   1,   1, {  22,  23, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs182_g2_s0_effs[] = { /* 0x823313c */
    /*  0 */ {   0,   0,   1,   1, {  22,  23, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8233148 */
    &s_gs182_g0_s0_station_sref,
    &s_gs182_g1_s0_station_sref,
    &s_gs182_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs182_g0_sectors[] = { /* 0x8233154 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs182_g1_sectors[] = { /* 0x823317c */
    { LPARRAY(s_gs182_g1_s0_lives), 0,NULL, LPARRAY(s_gs182_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs182_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs182_g2_sectors[] = { /* 0x82331cc */
    { LPARRAY(s_gs182_g2_s0_lives), 0,NULL, LPARRAY(s_gs182_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
    { LPARRAY(s_gs182_g2_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs182_groups[] = { /* 0x823321c */
    { LPARRAY(s_gs182_g0_sectors) },
    { LPARRAY(s_gs182_g1_sectors) },
    { LPARRAY(s_gs182_g2_sectors) },
};

static const struct GroundLink s_gs182_links[] = { /* 0x8233234 */
    /* link   0 */ { { /*x*/  22, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  22, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs182 = { LPARRAY(s_gs182_groups), s_gs182_links }; /* 0x8233244 */
