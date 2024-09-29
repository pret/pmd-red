







static const struct ScriptCommand s_gs215_g0_s0_station_sref_script[] = { /* 0x82673c8 */
    DEBUGINFO,
    SELECT_MAP(215),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs215_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs215_g0_s0_station_sref_script }; /* 0x8267434 */

static const struct ScriptCommand s_gs215_g1_s0_station_sref_script[] = { /* 0x8267440 */
    DEBUGINFO,
    SELECT_MAP(215),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs215_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs215_g1_s0_station_sref_script }; /* 0x82674c0 */

static const struct ScriptCommand s_gs215_g1_s0_lives0_dlg0[] = { /* 0x82674cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Gwoooooooh!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I have lost...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I admit it.\nYou are strong.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" This!#W\nThe #CISunset Wing#R!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...I see.#W\nYou came seeking the mirage Pokémon...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" ...#WStep back.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Kyuuuuuuuuhn!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The north wind swirled\n#+around the #CISunset Wing#R!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The #CISunset Wing#R...#W\n#+transformed into the #CIRainbow Wing#R!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Glittering in the seven colors\n#+of the rainbow, this wing is\n#+beautiful beyond description!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" This #CIRainbow Wing#R...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" It is the key to meeting\nthe mirage Pokémon.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Take this wing...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Take it to the mountain so\nhigh that its peak is obscured by clouds.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yes...\nTake it to #CDMt. Faraway#R!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" The mirage Pokémon is at\nits peak!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n0 received\n#+the #CIRainbow Wing#R.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+And...") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Gained access to\n#+#CDMt. Faraway#R!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs215_g1_s0_lives1_dlg0[] = { /* 0x82679c8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs215_g1_s0_lives[] = { /* 0x8267a08 */
    /*  0 */ {   0,   4,   0,   0, {  35,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs215_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 119,   0,   0,   0, {  35,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs215_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs215_g1_s0_effs[] = { /* 0x8267a38 */
    /*  0 */ {   0,   0,   1,   1, {  35,  29, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8267a44 */
    &s_gs215_g0_s0_station_sref,
    &s_gs215_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs215_g0_sectors[] = { /* 0x8267a4c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs215_g1_sectors[] = { /* 0x8267a74 */
    { LPARRAY(s_gs215_g1_s0_lives), 0,NULL, LPARRAY(s_gs215_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs215_groups[] = { /* 0x8267a9c */
    { LPARRAY(s_gs215_g0_sectors) },
    { LPARRAY(s_gs215_g1_sectors) },
};

static const struct GroundLink s_gs215_links[] = { /* 0x8267aac */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs215 = { LPARRAY(s_gs215_groups), s_gs215_links }; /* 0x8267ab4 */
