







static const struct ScriptCommand s_gs211_g0_s0_station_sref_script[] = { /* 0x8264158 */
    DEBUGINFO,
    SELECT_MAP(211),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs211_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs211_g0_s0_station_sref_script }; /* 0x82641c4 */

static const struct ScriptCommand s_gs211_g1_s0_station_sref_script[] = { /* 0x82641d0 */
    DEBUGINFO,
    SELECT_MAP(211),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(10),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs211_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs211_g1_s0_station_sref_script }; /* 0x8264250 */

static const struct ScriptCommand s_gs211_g1_s0_lives0_dlg0[] = { /* 0x826425c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_NPC(2, _(" Gwooooooooooh!{WAIT_PRESS}\n...H-how dare you!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" How...{WAIT_PRESS}\nHow did this happen...?")),
    MSG_NPC(2, _(" But regardless, you have\nwon.{WAIT_PRESS}\nLet me hear your wish.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" ...Hm?! This...{WAIT_PRESS}\nThis is the {COLOR GREEN_I}Red Wing{RESET}...")),
    MSG_NPC(2, _(" ............{WAIT_PRESS}You...{WAIT_PRESS}\nStand back!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Raikou's thunderbolt\n{CENTER_ALIGN}electrified the {COLOR GREEN_I}Red Wing{RESET}!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The {COLOR GREEN_I}Red Wing{RESET}...{WAIT_PRESS}\n{CENTER_ALIGN}transformed into\n{CENTER_ALIGN}the {COLOR GREEN_I}Sunset Wing{RESET}!") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Its subtle gradation of yellow\n{CENTER_ALIGN}to red is a truly beauteous sight!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Go northeast!")),
    MSG_NPC(2, _(" To a place called the\n{COLOR YELLOW_D}Northwind Field{RESET}.")),
    MSG_NPC(2, _(" You will find a Pokémon\nthere named Suicune.")),
    MSG_NPC(2, _(" If you are lucky enough to\nmeet Suicune...")),
    MSG_NPC(2, _(" Perhaps your wish will\ncome true!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY(212),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_0} received\n{CENTER_ALIGN}the {COLOR GREEN_I}Sunset Wing{RESET}.") },
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}And...") },
    FANFARE_PLAY(205),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Northwind Field{RESET}!") },
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs211_g1_s0_lives1_dlg0[] = { /* 0x8264734 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs211_g1_s0_lives[] = { /* 0x8264774 */
    /*  0 */ {   0,   4,   0,   0, {  34,  42, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs211_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 133,   0,   0,   0, {  34,  37, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs211_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs211_g1_s0_effs[] = { /* 0x82647a4 */
    /*  0 */ {   0,   0,   1,   1, {  34,  39, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x82647b0 */
    &s_gs211_g0_s0_station_sref,
    &s_gs211_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs211_g0_sectors[] = { /* 0x82647b8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs211_g1_sectors[] = { /* 0x82647e0 */
    { LPARRAY(s_gs211_g1_s0_lives), 0,NULL, LPARRAY(s_gs211_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs211_groups[] = { /* 0x8264808 */
    { LPARRAY(s_gs211_g0_sectors) },
    { LPARRAY(s_gs211_g1_sectors) },
};

static const struct GroundLink s_gs211_links[] = { /* 0x8264818 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs211 = { LPARRAY(s_gs211_groups), s_gs211_links }; /* 0x8264820 */
