









static const struct ScriptCommand s_gs165_g0_s0_station_sref_script[] = { /* 0x82185a0 */
    DEBUGINFO,
    SELECT_MAP(165),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs165_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs165_g0_s0_station_sref_script }; /* 0x821860c */

static const struct ScriptCommand s_gs165_g1_s0_station_sref_script[] = { /* 0x8218618 */
    DEBUGINFO,
    BGM_SWITCH(24),
    { 0x23, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(165),
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Across fields of fire...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+But throughout it all,\n#+$n0's team kept\n#+their heads held high.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Without a complaint,\n#+they marched on.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs165_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs165_g1_s0_station_sref_script }; /* 0x8218828 */



static const struct ScriptCommand s_gs165_g1_s0_lives0_dlg0[] = { /* 0x8218834 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Nature's gone savage\nhere too...")),
    VARIANT(/* == */  1, _(" The forest fires are still\nburning out of control...")),
    VARIANT_DEFAULT(_(" The environment is out\nof control here too...")),
    VARIANT_DEFAULT(_(" The forest fire is still\nraging...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0064,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x80,  0x00cc,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs165_g1_s0_lives1_dlg0[] = { /* 0x8218a34 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x00cc,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x08,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x80,  0x00cc,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs165_g1_s0_lives[] = { /* 0x8218af4 */
    /*  0 */ {   0,   2,   0,   0, {   6,  12, 0, CPOS_HALFTILE }, {
        [0] = s_gs165_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {   1,  12, 0, CPOS_HALFTILE }, {
        [0] = s_gs165_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs165_g1_s0_effs[] = { /* 0x8218b24 */
    /*  0 */ {   0,   0,   1,   1, {  16,  11, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8218b30 */
    &s_gs165_g0_s0_station_sref,
    &s_gs165_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs165_g0_sectors[] = { /* 0x8218b38 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs165_g1_sectors[] = { /* 0x8218b60 */
    { LPARRAY(s_gs165_g1_s0_lives), 0,NULL, LPARRAY(s_gs165_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs165_groups[] = { /* 0x8218b88 */
    { LPARRAY(s_gs165_g0_sectors) },
    { LPARRAY(s_gs165_g1_sectors) },
};

static const struct GroundLink s_gs165_links[] = { /* 0x8218b98 */
    /* link   0 */ { { /*x*/  18, /*y*/  12, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  14, /*y*/  12, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs165 = { LPARRAY(s_gs165_groups), s_gs165_links }; /* 0x8218ba8 */
