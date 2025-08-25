









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
    AWAIT_CUE(3),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs182_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs182_g1_s0_station_sref_script }; /* 0x823221c */

static const struct ScriptCommand s_gs182_g1_s0_lives0_dlg0[] = { /* 0x8232228 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    ALERT_CUE(3),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    WAIT(15),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So, this is it...\n{COLOR YELLOW_D}Mt. Steel{RESET}...")),
    VARIANT(/* == */  1, _(" {NAME_3}'s been taken\nto the peak here...")),
    VARIANT_DEFAULT(_(" Here we are...\n{COLOR YELLOW_D}Mt. Steel{RESET}...")),
    VARIANT_DEFAULT(_(" So, {NAME_3} was\nwhisked to its peak...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" That's right!")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 1),
    WAIT(15),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(60),
    { 0x2d, 0x0a,  0x0000,  0x00000002,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" The peak is {VALUE_0}F!\nThank you for helping! Farewell!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(60),
    ALERT_CUE(6),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ......{WAIT_PRESS}\nWell, I guess we go...")),
    VARIANT_DEFAULT(_(" ......{WAIT_PRESS}\nUh... Let's go.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT(45),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs182_g1_s0_lives1_dlg0[] = { /* 0x82326cc */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    CALL_SCRIPT(SWEAT_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs182_g1_s1_lives0_dlg0[] = { /* 0x823282c */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    { 0x57, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs182_g2_s0_station_sref_script[] = { /* 0x823290c */
    DEBUGINFO,
    SELECT_MAP(182),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(120),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs182_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs182_g2_s0_station_sref_script }; /* 0x823297c */

static const struct ScriptCommand s_gs182_g2_s0_lives0_dlg0[] = { /* 0x8232988 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000042,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000044,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    ALERT_CUE(3),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    WAIT(15),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We'll take another shot at\n{COLOR YELLOW_D}Mt. Steel{RESET}.")),
    VARIANT(/* == */  1, _(" We'll rescue {NAME_3}\nno matter what it takes!")),
    VARIANT_DEFAULT(_(" We have to make another\nattempt at {COLOR YELLOW_D}Mt. Steel{RESET}.")),
    VARIANT_DEFAULT(_(" Whatever it takes,\nlet's rescue {NAME_3}!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    MSG_NPC(-1, _(" That's the spirit!")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 1),
    WAIT(15),
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    CALL_SCRIPT(SHOCK_FUNC),
    WAIT(60),
    { 0x2d, 0x0a,  0x0000,  0x00000002,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" The peak is {VALUE_0}F!\nThank you for helping! Farewell!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(60),
    ALERT_CUE(6),
    FANFARE_PLAY2(470),
    CALL_SCRIPT(SWEAT_FUNC),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000022,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ......{WAIT_PRESS}\nWell, here we go...")),
    VARIANT_DEFAULT(_(" ......{WAIT_PRESS}\nUh... Let's go.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    WAIT(45),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs182_g2_s0_lives1_dlg0[] = { /* 0x8232e30 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ROTATE(4, 10, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    CALL_SCRIPT(SWEAT_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE(4, 10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs182_g2_s1_lives0_dlg0[] = { /* 0x8232fc0 */
    DEBUGINFO,
    { 0x57, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(454),
    SELECT_ANIMATION(22),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    FANFARE_PLAY2(486),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
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
