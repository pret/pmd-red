









static const struct ScriptCommand s_gs194_g0_s0_station_sref_script[] = { /* 0x8245514 */
    DEBUGINFO,
    SELECT_MAP(194),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs194_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs194_g0_s0_station_sref_script }; /* 0x8245580 */

static const struct ScriptCommand s_gs194_g1_s0_station_sref_script[] = { /* 0x824558c */
    DEBUGINFO,
    SELECT_MAP(194),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Stop right there!\nDon't let them get away!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sure. Like we're really\ngoing to wait because they said so.")),
    VARIANT_DEFAULT(_(" They expect us to stop and\nwait for them?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs194_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs194_g1_s0_station_sref_script }; /* 0x8245728 */



static const struct ScriptCommand s_gs194_g1_s0_lives0_dlg0[] = { /* 0x8245734 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0099,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(45),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Whew...\nWe finally got through that cave.")),
    VARIANT(/* == */  1, _(" Where are the Pokémon\nwho are chasing us?")),
    VARIANT_DEFAULT(_(" Whew!\nFinally, we made it through that cave.")),
    VARIANT_DEFAULT(_(" Where's the Pokémon mob\nthat's after us?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Hey, look! There they are!\nOver there!") },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Catch $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Whoa! Here they come!\nRun!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};




static const struct ScriptCommand s_gs194_g1_s0_lives1_dlg0[] = { /* 0x8245ab0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs194_g1_s0_lives[] = { /* 0x8245c00 */
    /*  0 */ {   0,   0,   0,   0, {  10,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs194_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  12,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs194_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs194_g1_s0_effs[] = { /* 0x8245c30 */
    /*  0 */ {   0,   0,   1,   1, {  17,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8245c3c */
    &s_gs194_g0_s0_station_sref,
    &s_gs194_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs194_g0_sectors[] = { /* 0x8245c44 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs194_g1_sectors[] = { /* 0x8245c6c */
    { LPARRAY(s_gs194_g1_s0_lives), 0,NULL, LPARRAY(s_gs194_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs194_groups[] = { /* 0x8245c94 */
    { LPARRAY(s_gs194_g0_sectors) },
    { LPARRAY(s_gs194_g1_sectors) },
};

static const struct GroundLink s_gs194_links[] = { /* 0x8245ca4 */
    /* link   0 */ { { /*x*/  15, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  19, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs194 = { LPARRAY(s_gs194_groups), s_gs194_links }; /* 0x8245cb4 */
