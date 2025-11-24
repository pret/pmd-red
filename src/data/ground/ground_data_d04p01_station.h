









static const struct ScriptCommand s_gs184_g0_s0_station_sref_script[] = { /* 0x82342f4 */
    DEBUGINFO_O(12),
    SELECT_MAP(MAP_SINISTER_WOODS_ENTRY),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs184_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs184_g0_s0_station_sref_script }; /* 0x8234360 */

static const struct ScriptCommand s_gs184_g1_s0_station_sref_script[] = { /* 0x823436c */
    DEBUGINFO_O(21),
    SELECT_MAP(MAP_SINISTER_WOODS_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_SINISTER_WOODS),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_SINISTER_WOODS),
    RET,
};

static const struct ScriptRef s_gs184_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs184_g1_s0_station_sref_script }; /* 0x82343ec */

static const struct ScriptCommand s_gs184_g1_s0_lives0_dlg0[] = { /* 0x82343f8 */
    DEBUGINFO_O(34),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005e,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x0000005b,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    WAIT(20),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is it.\n{NAME_2} is lost in these woods.")),
    VARIANT(/* == */  1, _(" {NAME_3}'s crew\nshould have a head start on us.")),
    VARIANT(/* == */  1, _(" We'd better hurry.")),
    VARIANT(/* == */  3, _(" This is it.\n{NAME_2} is lost somewhere in these\nwoods.")),
    VARIANT(/* == */  3, _(" {NAME_3}'s gang should\nalready be here.")),
    VARIANT(/* == */  3, _(" We ought to hurry.")),
    VARIANT_DEFAULT(_(" This must be it.\n{NAME_2} is lost somewhere in these\nwoods.")),
    VARIANT_DEFAULT(_(" {NAME_3}'s gang should\nbe in there already.")),
    VARIANT_DEFAULT(_(" We need to hurry.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(384, 0),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs184_g1_s0_lives1_dlg0[] = { /* 0x8234714 */
    DEBUGINFO_O(66),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(384, 1),
    HALT,
};

static const struct ScriptCommand s_gs184_g2_s0_station_sref_script[] = { /* 0x82347a4 */
    DEBUGINFO_O(78),
    SELECT_MAP(MAP_SINISTER_WOODS_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_SINISTER_WOODS),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_SINISTER_WOODS),
    RET,
};

static const struct ScriptRef s_gs184_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs184_g2_s0_station_sref_script }; /* 0x8234824 */

static const struct ScriptCommand s_gs184_g2_s0_lives0_dlg0[] = { /* 0x8234830 */
    DEBUGINFO_O(91),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000005b,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's move it, {NAME_0}!")),
    VARIANT(/* == */  1, _(" Even while we're dawdling\nhere, {NAME_2}'s team...")),
    VARIANT(/* == */  1, _(" Hurry! Chop, chop!")),
    VARIANT(/* == */  3, _(" Let's hurry, {NAME_0}!")),
    VARIANT(/* == */  3, _(" While we're stuck\nback here, {NAME_2}'s gang will be...")),
    VARIANT(/* == */  3, _(" We have to hurry!")),
    VARIANT_DEFAULT(_(" Let's hustle, {NAME_0}!")),
    VARIANT_DEFAULT(_(" We're still stuck back here\nwhile {NAME_2}'s gang is...")),
    VARIANT_DEFAULT(_(" Come on, hurry!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(384, 0),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs184_g2_s0_lives1_dlg0[] = { /* 0x8234ae8 */
    DEBUGINFO_O(119),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(384, 1),
    HALT,
};

static const struct GroundLivesData s_gs184_g1_s0_lives[] = { /* 0x8234b58 */
    /*  0 */ {   0,   4,   0,   0, {  26,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs184_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  30,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs184_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs184_g2_s0_lives[] = { /* 0x8234b88 */
    /*  0 */ {   0,   2,   0,   0, {  26,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs184_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  30,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs184_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs184_g1_s0_effs[] = { /* 0x8234bb8 */
    /*  0 */ {   0,   0,   1,   1, {  28,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs184_g2_s0_effs[] = { /* 0x8234bc4 */
    /*  0 */ {   0,   0,   1,   1, {  28,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8234bd0 */
    &s_gs184_g0_s0_station_sref,
    &s_gs184_g1_s0_station_sref,
    &s_gs184_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs184_g0_sectors[] = { /* 0x8234bdc */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs184_g1_sectors[] = { /* 0x8234c04 */
    { LPARRAY(s_gs184_g1_s0_lives), 0,NULL, LPARRAY(s_gs184_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs184_g2_sectors[] = { /* 0x8234c2c */
    { LPARRAY(s_gs184_g2_s0_lives), 0,NULL, LPARRAY(s_gs184_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs184_groups[] = { /* 0x8234c54 */
    { LPARRAY(s_gs184_g0_sectors) },
    { LPARRAY(s_gs184_g1_sectors) },
    { LPARRAY(s_gs184_g2_sectors) },
};

static const struct GroundLink s_gs184_links[] = { /* 0x8234c6c */
    /* link   0 */ { { /*x*/  26, /*y*/   9, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  30, /*y*/   9, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

const GroundScriptHeader gGroundScript_gs184 = { LPARRAY(s_gs184_groups), s_gs184_links }; /* 0x8234c7c */
