











static const struct ScriptCommand s_gs185_g0_s0_station_sref_script[] = { /* 0x8234c90 */
    DEBUGINFO,
    SELECT_MAP(185),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs185_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs185_g0_s0_station_sref_script }; /* 0x8234cfc */

static const struct ScriptCommand s_gs185_g1_s0_station_sref_script[] = { /* 0x8234d08 */
    DEBUGINFO,
    SELECT_MAP(185),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs185_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs185_g1_s0_station_sref_script }; /* 0x8234d88 */

static const struct ScriptCommand s_gs185_g1_s0_lives0_dlg0[] = { /* 0x8234d94 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005e,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0e,  0x0003,  0x00000043,  0x00000000, NULL },
    { 0x34, 0x00,  0x0003,  0x00000000,  0x00000000, _(" Owowowow...#W\nYou'll pay for this!\nDon't you forget it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x03,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, those pests are gone.\nLet's find $n2.")),
    VARIANT_DEFAULT(_(" No one should hold us back\nnow. Let's find $n2.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Um, excuse me...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x0002,  0x0000005e,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01d1,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0002,  0x00000000, -0x00000003, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Did you maybe come looking\nfor me?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" You must be $n2.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Let's get you home.\nCaterpie was worried about you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(16),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Yay!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I was scared, so I kept my\nshell hardened...and waited and waited.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Thank you!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs185_g1_s0_lives1_dlg0[] = { /* 0x823531c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x0002,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x93, 0x04,  0x0001,  0x0000005e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000005,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives2_dlg0[] = { /* 0x82353ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SMILE_START_FUNC),
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(455),
    CALL_SCRIPT(SMILE_END_FUNC),
    WAIT(10),
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    WAIT(16),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives3_dlg0[] = { /* 0x823550c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000047,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01c9,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000001,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives4_dlg0[] = { /* 0x82355ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000002,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives5_dlg0[] = { /* 0x823565c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0200,  0x00000003,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives6_dlg0[] = { /* 0x82356cc */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives7_dlg0[] = { /* 0x823576c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x08,  0x000a,  0x00000006,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x0000005e,  0x00000000, NULL },
    { 0xe3, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives8_dlg0[] = { /* 0x823580c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs185_g1_s0_lives9_dlg0[] = { /* 0x823583c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs185_g1_s0_lives[] = { /* 0x823586c */
    /*  0 */ {   0,   4,   0,   0, {  32,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  37,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  94,   0,   0,   0, {  34,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  91,   0,   0,   0, {  34,  24, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives3_dlg0,
    } },
    /*  4 */ {  92,   0,   0,   0, {  39,  28, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives4_dlg0,
    } },
    /*  5 */ {  93,   0,   0,   0, {  30,  28, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives5_dlg0,
    } },
    /*  6 */ {  10,   4,   0,   0, {  33,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives6_dlg0,
    } },
    /*  7 */ {  11,   4,   0,   0, {  36,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives7_dlg0,
    } },
    /*  8 */ {  12,   4,   0,   0, {  30,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives8_dlg0,
    } },
    /*  9 */ {  13,   4,   0,   0, {  39,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs185_g1_s0_lives9_dlg0,
    } },
};

static const struct GroundEffectData s_gs185_g1_s0_effs[] = { /* 0x823595c */
    /*  0 */ {   0,   0,   1,   1, {  34,  30, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8235968 */
    &s_gs185_g0_s0_station_sref,
    &s_gs185_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs185_g0_sectors[] = { /* 0x8235970 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs185_g1_sectors[] = { /* 0x8235998 */
    { LPARRAY(s_gs185_g1_s0_lives), 0,NULL, LPARRAY(s_gs185_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs185_groups[] = { /* 0x82359c0 */
    { LPARRAY(s_gs185_g0_sectors) },
    { LPARRAY(s_gs185_g1_sectors) },
};

static const struct GroundLink s_gs185_links[] = { /* 0x82359d0 */
    /* link   0 */ { { /*x*/  34, /*y*/  30, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  13, /*y*/  24, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  13, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  14, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs185 = { LPARRAY(s_gs185_groups), s_gs185_links }; /* 0x82359f0 */
