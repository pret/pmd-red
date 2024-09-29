









static const struct ScriptCommand s_gs166_g0_s0_station_sref_script[] = { /* 0x8218bbc */
    DEBUGINFO,
    SELECT_MAP(166),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs166_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs166_g0_s0_station_sref_script }; /* 0x8218c28 */

static const struct ScriptCommand s_gs166_g1_s0_station_sref_script[] = { /* 0x8218c34 */
    DEBUGINFO,
    SELECT_MAP(166),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs166_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs166_g1_s0_station_sref_script }; /* 0x8218ca4 */

static const struct ScriptCommand s_gs166_g1_s0_lives0_dlg0[] = { /* 0x8218cb0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    BGM_FADEOUT(60),
    WAIT(20),
    { 0x2e, 0x02,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Gasp... Gasp...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Oh, no! Look!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(38),
    { 0x91, 0x04,  0x000b,  0x00000002,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs166_g1_s0_lives1_dlg0[] = { /* 0x8218e38 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000001,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(455),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs166_g2_s0_station_sref_script[] = { /* 0x8218f08 */
    DEBUGINFO,
    SELECT_MAP(166),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Look at them go!\nThey're running for Mt. Blaze!") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Are they insane?\nMt. Blaze is doomed desolation!") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" No one's ever come this far\nbefore!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" I don't wanna go anywhere like that.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" It can't be helped.\nOnly those brave enough will give chase!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(90),
    WAIT(120),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs166_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs166_g2_s0_station_sref_script }; /* 0x8219150 */


static const struct ScriptCommand s_gs166_g2_s0_lives0_dlg0[] = { /* 0x821915c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x02,  0x0001,  0x0000000c,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" It... It's a mountain of fire!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Look at all that lava\npouring from the crater...") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Can we even make it\nthrough there?") },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" But they're catching up to\nus...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" What'll we do,\n$n0?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Look! There they are!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Get them!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" There's no choice now!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Let's go, $n0!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs166_g2_s0_lives1_dlg0[] = { /* 0x821952c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0x91, 0x04,  0x000b,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x50,  0x0200,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs166_g1_s0_lives[] = { /* 0x821964c */
    /*  0 */ {   0,   2,   0,   0, {  14,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  18,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs166_g2_s0_lives[] = { /* 0x821967c */
    /*  0 */ {   0,   2,   0,   0, {  28,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  32,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs166_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs166_g1_s0_effs[] = { /* 0x82196ac */
    /*  0 */ {   0,   0,   1,   1, {  30,  28, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs166_g2_s0_effs[] = { /* 0x82196b8 */
    /*  0 */ {   0,   0,   1,   1, {  30,  28, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82196c4 */
    &s_gs166_g0_s0_station_sref,
    &s_gs166_g1_s0_station_sref,
    &s_gs166_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs166_g0_sectors[] = { /* 0x82196d0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs166_g1_sectors[] = { /* 0x82196f8 */
    { LPARRAY(s_gs166_g1_s0_lives), 0,NULL, LPARRAY(s_gs166_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs166_g2_sectors[] = { /* 0x8219720 */
    { LPARRAY(s_gs166_g2_s0_lives), 0,NULL, LPARRAY(s_gs166_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs166_groups[] = { /* 0x8219748 */
    { LPARRAY(s_gs166_g0_sectors) },
    { LPARRAY(s_gs166_g1_sectors) },
    { LPARRAY(s_gs166_g2_sectors) },
};

static const struct GroundLink s_gs166_links[] = { /* 0x8219760 */
    /* link   0 */ { { /*x*/  28, /*y*/  25, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  32, /*y*/  27, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs166 = { LPARRAY(s_gs166_groups), s_gs166_links }; /* 0x8219770 */
