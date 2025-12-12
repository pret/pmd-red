








static const struct ScriptCommand s_gs207_g0_s0_station_sref_script[] = { /* 0x825ff68 */
    DEBUGINFO_O(11),
    SELECT_MAP(MAP_SKY_TOWER_ENTRY),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs207_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs207_g0_s0_station_sref_script }; /* 0x825ffd4 */

static const struct ScriptCommand s_gs207_g1_s0_station_sref_script[] = { /* 0x825ffe0 */
    DEBUGINFO_O(20),
    BGM_FADEOUT(30),
    WAIT(60),
    SELECT_MAP(MAP_SKY_TOWER_ENTRY),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_SKY_TOWER),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const ScriptRef s_gs207_g1_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs207_g1_s0_station_sref_script }; /* 0x8260080 */

static const struct ScriptCommand s_gs207_g1_s0_lives0_dlg0[] = { /* 0x826008c */
    DEBUGINFO_O(35),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(48),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    FANFARE_PLAY2(509),
    ALERT_CUE(6),
    ALERT_CUE(7),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    FANFARE_PLAY2(510),
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Ouch...{WAIT_PRESS}\nWhere are we?")),
    VARIANT_DEFAULT(_(" Owowow...{WAIT_PRESS}\nWhere are we?")),
    TEXTBOX_CLEAR,
    WAIT(20),
    ALERT_CUE(6),
    ALERT_CUE(7),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x0000000c),
    MSG_NPC(1, _(" Wah!\n{NAME_0}, this is cool!{WAIT_PRESS}\nWe're on clouds!")),
    TEXTBOX_CLEAR,
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    ALERT_CUE(7),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" Oh, wow!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" {NAME_0}, look up there!")),
    TEXTBOX_CLEAR,
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    ALERT_CUE(7),
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs207_g1_s0_lives1_dlg0[] = { /* 0x8260458 */
    DEBUGINFO_O(91),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(48),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002c,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    WAIT(30),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(49),
    { 0x84, 0x00,  0x0080, -0x00000018,  0x00000000, NULL },
    WAIT(20),
    SELECT_ANIMATION(2),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(30),
    { 0x84, 0x00,  0x0080,  0x00000018,  0x00000010, NULL },
    ALERT_CUE(5),
    WAIT(20),
    FANFARE_PLAY2(457),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    WAIT(30),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    WAIT(15),
    FANFARE_PLAY2(458),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x84, 0x00,  0x0099,  0x00000000, -0x00000010, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs207_g1_s0_lives2_dlg0[] = { /* 0x8260738 */
    DEBUGINFO_O(140),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c8,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(10),
    SELECT_ANIMATION(2),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTHWEST),
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs207_g2_s0_station_sref_script[] = { /* 0x82608a8 */
    DEBUGINFO_O(166),
    SELECT_MAP(MAP_SKY_TOWER_ENTRY),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_SKY_TOWER),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_SKY_TOWER),
    RET,
};

static const ScriptRef s_gs207_g2_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs207_g2_s0_station_sref_script }; /* 0x8260928 */

static const struct ScriptCommand s_gs207_g2_s0_lives0_dlg0[] = { /* 0x8260934 */
    DEBUGINFO_O(179),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000006c,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It must be at the very top...")),
    VARIANT(/* == */  1, _(" That must be where\n{NAME_2} is...")),
    VARIANT_DEFAULT(_(" It's at the top of this\ntower...")),
    VARIANT_DEFAULT(_(" That's where {NAME_2}\nis...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}!\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" {NAME_0}!\nLet's do our best on the climb!")),
    TEXTBOX_CLEAR,
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    ALERT_CUE(7),
    WALK_GRID(179, 0),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs207_g2_s0_lives1_dlg0[] = { /* 0x8260b8c */
    DEBUGINFO_O(208),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g2_s0_lives2_dlg0[] = { /* 0x8260c3c */
    DEBUGINFO_O(222),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g3_s0_station_sref_script[] = { /* 0x8260cac */
    DEBUGINFO_O(232),
    SELECT_MAP(MAP_SKY_TOWER_ENTRY),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_SKY_TOWER),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_SKY_TOWER),
    RET,
};

static const ScriptRef s_gs207_g3_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs207_g3_s0_station_sref_script }; /* 0x8260d2c */

static const struct ScriptCommand s_gs207_g3_s0_lives0_dlg0[] = { /* 0x8260d38 */
    DEBUGINFO_O(245),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(48),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(509),
    ALERT_CUE(6),
    ALERT_CUE(7),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    WAIT(60),
    ALERT_CUE(6),
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right.\nWe're up in the sky again.")),
    VARIANT_DEFAULT(_(" OK.\nHere we are in the sky again.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's storm our way to\nthe top floor!")),
    VARIANT_DEFAULT(_(" Let's head for the top!\nThis is it!")),
    TEXTBOX_CLEAR,
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    ALERT_CUE(7),
    WALK_GRID(179, 0),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs207_g3_s0_lives1_dlg0[] = { /* 0x826104c */
    DEBUGINFO_O(288),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(48),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x00000088,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs207_g3_s0_lives2_dlg0[] = { /* 0x82611dc */
    DEBUGINFO_O(316),
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c8,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(15),
    { 0x70, 0x00,  0x0a00,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000c,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(7),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(179, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs207_g1_s0_lives[] = { /* 0x826131c */
    /*  0 */ {   0,   6,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   6,   0,   0, {  25,  24, CPOS_HALFTILE, 0 }, {
        [0] = s_gs207_g1_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs207_g2_s0_lives[] = { /* 0x8261364 */
    /*  0 */ {   0,   4,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  25,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g2_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs207_g3_s0_lives[] = { /* 0x82613ac */
    /*  0 */ {   0,   0,   0,   0, {  28,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   0,   0,   0, {  25,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs207_g3_s0_lives2_dlg0,
    } },
};

static const struct GroundEffectData s_gs207_g1_s0_effs[] = { /* 0x82613f4 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs207_g2_s0_effs[] = { /* 0x8261400 */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs207_g3_s0_effs[] = { /* 0x826140c */
    /*  0 */ {   0,   0,   1,   1, {  25,  16, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x8261418 */
    &s_gs207_g0_s0_station_sref,
    &s_gs207_g1_s0_station_sref,
    &s_gs207_g2_s0_station_sref,
    &s_gs207_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs207_g0_sectors[] = { /* 0x8261428 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs207_g1_sectors[] = { /* 0x8261450 */
    { LPARRAY(s_gs207_g1_s0_lives), 0,NULL, LPARRAY(s_gs207_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs207_g2_sectors[] = { /* 0x8261478 */
    { LPARRAY(s_gs207_g2_s0_lives), 0,NULL, LPARRAY(s_gs207_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs207_g3_sectors[] = { /* 0x82614a0 */
    { LPARRAY(s_gs207_g3_s0_lives), 0,NULL, LPARRAY(s_gs207_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs207_groups[] = { /* 0x82614c8 */
    { LPARRAY(s_gs207_g0_sectors) },
    { LPARRAY(s_gs207_g1_sectors) },
    { LPARRAY(s_gs207_g2_sectors) },
    { LPARRAY(s_gs207_g3_sectors) },
    {},
};

static const struct GroundLink s_gs207_links[] = { /* 0x82614f0 */
    /* link   0 */ { { /*x*/  25, /*y*/  12, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

const GroundScriptHeader gGroundScript_gs207 = { LPARRAY(s_gs207_groups), s_gs207_links }; /* 0x82614f8 */
