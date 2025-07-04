












static const struct ScriptCommand s_gs183_g0_s0_station_sref_script[] = { /* 0x8233258 */
    DEBUGINFO,
    SELECT_MAP(183),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs183_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs183_g0_s0_station_sref_script }; /* 0x82332c4 */

static const struct ScriptCommand s_gs183_g1_s0_station_sref_script[] = { /* 0x82332d0 */
    DEBUGINFO,
    SELECT_MAP(183),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs183_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs183_g1_s0_station_sref_script }; /* 0x8233350 */

static const struct ScriptCommand s_gs183_g1_s0_eff0_script[] = { /* 0x823335c */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x1c,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs183_g1_s0_lives0_dlg0[] = { /* 0x82333ec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Grr... I can't keep up!{WAIT_PRESS}\nI'll flee for now!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey!\nWe sent {NAME_3} packing!")),
    VARIANT(/* == */  1, _(" You're safe now.\nCome on down!")),
    VARIANT_DEFAULT(_(" Hey there!\nWe chased {NAME_3} off!")),
    VARIANT_DEFAULT(_(" It's OK now.\nCome down over here.")),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000041),
    MSG_NPC(2, _(" I can't...\nI'm too scared to move...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" OK, no sweat.{WAIT_PRESS}\nWe'll go to you. Just wait.")),
    VARIANT_DEFAULT(_(" OK, no problem.{WAIT_PRESS}\nWe'll come to you. Just wait.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(1, _(" ...Whoa.")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wow. This is some cliff...\nI can't see the bottom.")),
    VARIANT_DEFAULT(_(" Sheesh! Look at this cliff...\nI can't see the bottom.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_NPC(1, _(" {NAME_0}, what'll\nwe do?\nWe can't get across this.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 1),
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0004, 0x00000000),
    MSG_NPC(-1, _(" BZBZBZZ!")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey! It's those {NAME_4}\nfrom that rescue!")),
    VARIANT_DEFAULT(_(" Oh, hi!\nYou're the {NAME_4} we saved!")),
    TEXTBOX_CLEAR,
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, 2, 0),
    MSG_NPC(4, _(" WE GOT WORD OF THIS.{WAIT_PRESS}\nWE CAN RESCUE DIGLETT FROM THE\nSKY. BZBZBZZ!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(4, _(" HOLD ON TO US TIGHT.\nBZBZBZZZ!")),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0004, 0x00000000),
    PORTRAIT_POS(4, -2, 0),
    MSG_NPC(4, _(" DON'T BE SCARED.\nWE WON'T MAKE THE MISTAKE OF\nZAPPING YOU. BZBZBZZT!")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs183_g1_s0_lives1_dlg0[] = { /* 0x8233bec */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0100,  0x00000000, -0x00000018, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0080,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x62, 0x00,  0x0080,  0x00000000,  0x00000008, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x0080,  0x00000000, -0x00000008, NULL },
    { 0x54, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(463),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000a,  0x00000004,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s0_lives2_dlg0[] = { /* 0x8233d8c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s0_lives3_dlg0[] = { /* 0x8233e3c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(459),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000045,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs183_g1_s1_lives0_dlg0[] = { /* 0x8233eec */
    DEBUGINFO,
    { 0x5b, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(483),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0080,  0x00000004,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000044,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x004c,  0x00000000, -0x00000010, NULL },
    { 0x93, 0x04,  0x000a,  0x00000044,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs183_g1_s1_lives1_dlg0[] = { /* 0x823405c */
    DEBUGINFO,
    { 0x5b, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x0000005a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0080,  0x00000003,  0x00000000, NULL },
    { 0x93, 0x04,  0x000a,  0x00000044,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x6a, 0x00,  0x004c,  0x00000000, -0x00000010, NULL },
    { 0x93, 0x04,  0x000a,  0x00000044,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs183_g1_s0_lives[] = { /* 0x823418c */
    /*  0 */ {   0,   4,   0,   0, {  26,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  41, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  68,   0,   0,   0, {  28,  26, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  69,   0,   0,   0, {  28,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs183_g1_s1_lives[] = { /* 0x82341ec */
    /*  0 */ {  61,   0,   0,   0, {  27,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s1_lives0_dlg0,
    } },
    /*  1 */ {  62,   0,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs183_g1_s1_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs183_g1_s0_effs[] = { /* 0x823421c */
    /*  0 */ {   0,   0,   1,   1, {  28,  39, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs183_g1_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8234228 */
    &s_gs183_g0_s0_station_sref,
    &s_gs183_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs183_g0_sectors[] = { /* 0x8234230 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs183_g1_sectors[] = { /* 0x8234258 */
    { LPARRAY(s_gs183_g1_s0_lives), 0,NULL, LPARRAY(s_gs183_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs183_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs183_groups[] = { /* 0x82342a8 */
    { LPARRAY(s_gs183_g0_sectors) },
    { LPARRAY(s_gs183_g1_sectors) },
};

static const struct GroundLink s_gs183_links[] = { /* 0x82342b8 */
    /* link   0 */ { { /*x*/  29, /*y*/  36, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  30, /*y*/  32, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  27, /*y*/  32, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  31, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  26, /*y*/  28, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs183 = { LPARRAY(s_gs183_groups), s_gs183_links }; /* 0x82342e0 */
